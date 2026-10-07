#!/usr/bin/env python3
"""Turn the raw Ghidra export (raw/) into a buildable C tree (decomp/)."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(__file__))
from patches import PATCHES  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW = os.path.join(ROOT, "raw")
OUT = os.path.join(ROOT, "decomp")
OVR = os.path.join(ROOT, "tools", "overrides")
BINARY = os.path.join(ROOT, "htop")
IMAGE_BASE = 0x100000
DATA_SECTIONS = [".rodata", ".data.rel.ro", ".data", ".bss"]
# symbols provided again by the C runtime of the rebuilt binary
CRT_DATA = {"_IO_stdin_used", "__dso_handle", "__TMC_END__", "completed.0", "__data_start", "data_start"}
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def read(path):
    with open(path) as f:
        return f.read()


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as f:
        f.write(text)


def sections():
    out = subprocess.run(["readelf", "-SW", BINARY], capture_output=True, text=True, check=True).stdout
    secs = {}
    for m in re.finditer(r"\]\s+(\S+)\s+\S+\s+([0-9a-f]{16})\s+[0-9a-f]+\s+([0-9a-f]+)", out):
        secs[m.group(1)] = (int(m.group(2), 16) + IMAGE_BASE, int(m.group(3), 16))
    return secs


def sec_sym(name):
    return "__sec" + name.replace(".", "_")


SOURCE_ROOT = "/usr/src/htop-3.3.0-4build1/"
SOURCE_OF = {}  # function -> original source file (from DWARF line info), relative to the source root


def load_functions():
    funcs = []
    for line in read(os.path.join(RAW, "functions.tsv")).splitlines():
        addr, name, size, kind, src = line.split("\t")
        funcs.append((int(addr, 16), name, kind))
        SOURCE_OF[name] = src[len(SOURCE_ROOT):] if src.startswith(SOURCE_ROOT) else os.path.basename(src)
    return funcs


def load_thunks():
    """(addr, name, target) of jump-thunks between internal functions."""
    out = []
    for line in read(os.path.join(RAW, "thunks.tsv")).splitlines():
        addr, name, target, kind = line.split("\t")
        if kind == "int" and not name.startswith("_INIT"):
            out.append((int(addr, 16), name, target))
    return out


RENAMED = {}  # Ghidra label -> valid C identifier


def load_globals():
    labels = {}  # name -> (section, addr, decl)
    for line in read(os.path.join(RAW, "globals.tsv")).splitlines():
        parts = line.split("\t")
        sec, addr, name, decl = parts[0], int(parts[1], 16), parts[2], parts[3]
        if name in CRT_DATA or "+" in name:
            continue
        if not IDENT.match(name):
            new = re.sub(r"\W", "_", name)
            if not IDENT.match(new):
                continue
            RENAMED[name] = new
            decl = decl.replace(name, new)
            name = new
        labels[name] = (sec, addr, decl)
    return labels


def module_of(funcs):
    """Group functions by their original source file; static inline functions from a header go to <header>_inline.c."""
    mods = {}
    for addr, name, kind in funcs:
        src = SOURCE_OF.get(name) or "unknown.c"
        if src.endswith(".h"):
            src = src[:-2] + "_inline.c"
        mods.setdefault(src[:-2], []).append((addr, name))
    return mods


TEXT_LO, TEXT_HI = 0x1138a0, 0x146d2a
# "push return address" stores Ghidra emits once it loses track of the stack pointer (VLAs)
RA_STORE = re.compile(r"^\s*\*\((?:undefined8 \*|undefined \*\*|code \*\*)\)\([^;]*\+ -(?:8|0x[0-9a-f]+)\) = "
                      r"(0x[0-9a-f]+|&?(?:UNK|LAB|FUN)_[0-9a-f]+|[A-Za-z_]\w*);\n", re.M)
# any store of a code address that is not a function (a pushed return address)
RA_STORE_ANY = re.compile(r"^\s*[^=;\n]+ = (?:\([\w *]+\))?&(?:UNK|LAB)_([0-9a-f]+);\n", re.M)
RA_STORE_IDX = re.compile(r"^\s*\w+\[-1\] = (?:\([\w *]+\))?(0x[0-9a-f]+|&?(?:UNK|LAB|FUN)_[0-9a-f]+);\n", re.M)
PARTIAL = re.compile(r"\b([A-Za-z_]\w*(?:\[\w+\])?(?:(?:\.|->)[A-Za-z_]\w*(?:\[\w+\])?)*)\._(\d+)_(\d+)_")
PART_T = {1: "uchar", 2: "ushort", 4: "uint", 8: "ulong", 16: "undefined16"}
VLA_SIZE = 0x100000


def ra_store(m):
    v = m.group(1)
    if v.startswith("0x"):
        return "" if TEXT_LO <= int(v, 16) < TEXT_HI else m.group(0)
    return "" if "code **" in m.group(0) or v.startswith(("&UNK_", "&LAB_", "FUN_")) else m.group(0)


def partial(m):
    var, off, size = m.group(1), int(m.group(2)), int(m.group(3))
    t = PART_T.get(size, "ulong")
    return f"(*({t} *)((char *)&{var} + {off}))"


FRAMES = {}  # function -> {stack variable: offset below the entry stack pointer}


def load_frames():
    for line in read(os.path.join(RAW, "frames.tsv")).splitlines():
        func, var, off, size = line.split("\t")
        if int(off) < 0:
            FRAMES.setdefault(func, {})[var] = -int(off)


def emulate_frame(name, code):
    """Put all stack variables in one byte array at their original offsets (from frames.tsv).

    Overlapping views of the same stack slot then alias as in the binary, and stack-pointer
    arithmetic (alloca/VLA) stays inside memory the function owns.
    """
    # alloca/VLA (stack probe loop) or raw stack addresses: reserve room below the locals
    vla = "0xfffffffffffff000" in code or "&stack0x" in code
    frame = FRAMES.get(name, {})
    start = code.find("\n{\n") + 3
    m = re.compile(r"\n[ \t]*\n").search(code, start)
    end = m.start() + 1 if m else len(code)
    head = code[start:end].split("\n")
    vars_ = {}
    keep = []
    for line in head:
        decl = line.strip()
        names = [n for n in re.findall(r"[A-Za-z_]\w*", decl) if n in frame]
        if decl.endswith(";") and "=" not in decl and len(names) == 1:
            n = names[0]
            vars_[n] = (re.sub(rf"\b{n}\b", "(*)", decl[:-1], count=1), frame[n])
        else:
            keep.append(line)
    # "_name": Ghidra's wider view of the slot of stack variable "name"
    for n in set(re.findall(r"(?<![\w.>])_(\w+)\b", code[end:])):
        if n in frame and "_" + n not in vars_:
            vars_["_" + n] = ("undefined8 (*)", frame[n])
    if not vars_ and not vla and "stack0x" not in code:
        return code
    code = code[:start] + "\n".join(keep) + code[end:]
    # entry %rsp is 8 mod 16, keep that so stack slots have their original alignment
    fs = ((max([off for _, off in vars_.values()] + [0]) + 0x40 + 15) & ~15) + 8
    if vla:
        fs += VLA_SIZE
    decl = f"  undefined1 __frame[{fs + 0x40:#x}] __attribute__((aligned(16)));\n  undefined1 *__fp = __frame + {fs:#x};\n"
    code = re.sub(r"\n\{\n", "\n{\n" + decl, code, count=1)
    for n, (ptr_t, off) in sorted(vars_.items(), key=lambda kv: -len(kv[0])):
        expr = f"(*({ptr_t})(__fp - {off:#x}))"
        code = re.sub(rf"(?<![\w.>]){re.escape(n)}\b", lambda _: expr, code)
    code = re.sub(r"&stack0x([0-9a-f]{16})", lambda m: f"(__fp - {(1 << 64) - int(m.group(1), 16):#x})", code)
    # stack slot without a variable: SUBxy values are y bytes wide, anything else 8
    code = re.sub(r"^(\s*)stack0x([0-9a-f]{16}) = (SUB\d(\d+)\(.*);$",
                  lambda m: f"{m.group(1)}{{ ulong __v = {m.group(3)}; __builtin_memcpy(__fp - "
                            f"{(1 << 64) - int(m.group(2), 16):#x}, &__v, {m.group(4)}); }}", code, flags=re.M)
    code = re.sub(r"\bstack0x([0-9a-f]{16})\b",
                  lambda m: f"(*(undefined8 *)(__fp - {(1 << 64) - int(m.group(1), 16):#x}))", code)
    return code


class AddrResolver:
    """Map absolute addresses of the original image to symbol expressions."""

    def __init__(self, secs, labels, funcs, thunks):
        import bisect
        self.bisect = bisect
        self.funcs = {a: n for a, n, _ in funcs}
        self.funcs.update({a: n for a, n, _ in thunks})
        self.secs = [(secs[s][0], secs[s][0] + secs[s][1], s) for s in DATA_SECTIONS]
        self.labels = sorted((addr, name) for name, (sec, addr, decl) in labels.items())
        self.keys = [a for a, _ in self.labels]

    def __call__(self, v):
        if v in self.funcs:
            return f"(long){self.funcs[v]}"
        for lo, hi, s in self.secs:
            if lo <= v < hi:
                i = self.bisect.bisect_right(self.keys, v) - 1
                if i >= 0 and self.labels[i][0] == v:
                    return f"(long)&{self.labels[i][1]}"
                return f"(long)({sec_sym(s)} + {v - lo:#x})"
        return None


ADDR_CONST = re.compile(r"\"(?:[^\"\\\n]|\\.)*\"|'(?:[^'\\\n]|\\.)*'|(?<![\w.])0x(1[0-9a-f]{5})\b")


ROUND_STMT = re.compile(r"(\w+) = \((double|float)\)\(((?:(?!;\n).)*?(?:0x3ff0000000000000|0x3f800000)(?:(?!;\n).)*?)\);\n", re.S)


def rounding(m):
    """GCC's inline floor/ceil (no SSE4.1) uses bit masks Ghidra prints as numeric casts."""
    dst, t, body = m.groups()
    body = re.sub(r"\s+", " ", body)
    v = re.search(rf"\({t}\)\((?:long|int)\)(\w+)", body)
    if not v:
        return m.group(0)
    v = v.group(1)
    it = "long" if t == "double" else "int"
    if f"{v} < ({t})({it}){v}" in body:
        fn = "floor"
    elif f"({t})({it}){v} < {v}" in body:
        fn = "ceil"
    else:
        return m.group(0)
    return f"{dst} = __builtin_{fn}{'f' if t == 'float' else ''}({v});\n"


PD_OPS = {"divpd": "/", "mulpd": "*", "addpd": "+", "subpd": "-"}


def packed_double(code):
    """X = divpd(A,B) on lanes set by A._0_8_ = a0; ... : write the lanes as scalar expressions.
    The lane values are bit copies of doubles, which C partial accesses cannot express."""
    lanes = {}
    for m in re.finditer(r"^\s*(auVar\d+)\._(0|8)_8_ = (\w+);$", code, re.M):
        lanes[(m.group(1), m.group(2))] = m.group(3)
    out = []
    result = {}
    for line in code.split("\n"):
        m = re.match(r"^\s*(auVar\d+)\._(0|8)_8_ = (\w+);$", line)
        if m:
            continue
        m = re.match(r"^\s*(auVar\d+) = (divpd|mulpd|addpd|subpd)\((auVar\d+),(auVar\d+)\);$", line)
        if m:
            x, op, a, b = m.groups()
            for lane in "08":
                result[(x, lane)] = f"({lanes[(a, lane)]} {PD_OPS[op]} {lanes[(b, lane)]})"
            continue
        for (x, lane), expr in result.items():
            line = line.replace(f"{x}._{lane}_8_", expr)
        out.append(line)
    return "\n".join(out)


ESCAPES = {"0": 0, "a": 7, "b": 8, "t": 9, "n": 10, "v": 11, "f": 12, "r": 13, "\\": 92, "'": 39, '"': 34}


def wide_literal(m):
    """int constants printed as wide chars (Ghidra merged int with wchar_t): L'\xffffffff' -> -1"""
    body = m.group(1)
    if body.startswith("\\x"):
        v = int(body[2:], 16)
        return str(v - (1 << 32) if v >= 1 << 31 else v)
    if body.startswith("\\") and body[1:] in ESCAPES:
        return str(ESCAPES[body[1:]])
    if len(body) == 1:
        # printable ASCII stays a char constant; anything else (L'𪌀' is 172800) is its code point
        return f"'{body}'" if 32 <= ord(body) < 127 and body != "\\" else str(ord(body))
    return m.group(0)


def clean_function(name, code, resolve):
    for old, new in RENAMED.items():
        if old in code:
            code = code.replace(old, new)
    if name in PATCHES:
        for old, new, *mode in PATCHES[name]:
            if mode == ["re"]:
                code, n = re.subn(old, new, code, flags=re.M)
            else:
                n = code.count(old)
                code = code.replace(old, new)
            if n == 0:
                print(f"warning: patch for {name} does not apply: {old!r}", file=sys.stderr)
    code = code.replace("long in_FS_OFFSET;", "long in_FS_OFFSET = (long)__fake_fs;")
    if re.search(r"\b(divpd|mulpd|addpd|subpd)\(", code):
        code = packed_double(code)
    code = ROUND_STMT.sub(rounding, code)
    code = RA_STORE.sub(ra_store, code)
    code = RA_STORE_IDX.sub(ra_store, code)
    code = RA_STORE_ANY.sub(lambda m: "" if TEXT_LO <= int(m.group(1), 16) < TEXT_HI else m.group(0), code)
    # stack-clash probe of a large fixed frame: keep only the loop's final pointer values
    code = re.sub(r"^  (\w+) = &stack0x[0-9a-f]+;\n  do \{\n    (\w+) = \1;\n"
                  r"    \*\(undefined8 \*\)\(\2 \+ -0x1000\) = \*\(undefined8 \*\)\(\2 \+ -0x1000\);\n"
                  r"    \1 = \2 \+ -0x1000;\n  \} while \(\2 \+ -0x1000 != (\w+)\);\n",
                  r"  \1 = (undefined1 *)\3;\n  \2 = (undefined1 *)\3 + 0x1000;\n", code, flags=re.M)
    # VLA functions: the stack-pointer stand-in must point at memory this function owns
    # 16-byte SSE values
    code = re.sub(r"undefined1 (auVar\d+) \[16\];", r"undefined16 \1;", code)
    code = code.replace("(undefined1  [16])", "(undefined16)")
    arrptr = "|".join(set(re.findall(r"undefined1 \(\*(\w+)\) \[16\][;,)]", code))) or "(?!)"
    code = re.sub(rf"^(\s*)(\*(?:{arrptr})|(?:{arrptr})\[\d+\]|\*\(undefined1 \(\*\) \[16\]\)[^=;]*?) = (?!=)",
                  r"\1*(undefined16 *)(\2) = ", code, flags=re.M)
    code = re.sub(rf"^(\s*auVar\d+ = )(\*(?:{arrptr})|(?:{arrptr})\[\d+\]|\*\(undefined1 \(\*\) \[16\]\)[^;]*);",
                  r"\1*(undefined16 *)(\2);", code, flags=re.M)
    # whole-value assignment to a local array
    arrays = "|".join(set(re.findall(r"^  [\w ]+?\**(\w+) \[\d+\];$", code, re.M))) or "(?!)"
    code = re.sub(rf"^(\s*)({arrays}) = (?!=)(.*);$", r"\1ASSIGN_ARR(\2, \3);", code, flags=re.M)
    code = re.sub(r"L'(\\x[0-9a-f]+|\\.|[^'\\])'", wide_literal, code)
    code = PARTIAL.sub(partial, code)
    code = re.sub(r"\b\w+::(\w+)", r"\1", code)  # Ghidra namespaces (switch tables)
    # Ghidra's 1-byte "code" type used as a value (not code *): a char
    code = re.sub(r"\bcode (?=[A-Za-z_])", "char ", code)
    code = code.replace("(code)", "(char)")
    # union Arg { int i; void *v; } built from a constant
    code = re.sub(r"\(Arg\)(-?0x[0-9a-f]+|-?\d+)\b", r"((Arg){.i = (int)\1})", code)
    code = re.sub(r"\(Arg\)([A-Za-z_][\w.]*(?:->\w+)*)", r"((Arg){.v = (void *)(\1)})", code)
    # union Arg used as an integer
    unions = set(re.findall(r"\bArg (\w+)[;,)]", code)) | {"AVar\\d+"}
    code = re.sub(r"\((long|ulong|int|uint)\)(" + "|".join(sorted(unions)) + r")\b(?!\.)", r"*(\1 *)&\2", code)
    code = re.sub(r"\b(auVar\d+)\[(\w+)\]", r"(*(uchar *)((char *)&\1 + \2))", code)
    # all stack variables live in one array at their original offsets: Ghidra often splits
    # buffers into scalars, and only the original layout keeps them contiguous
    code = emulate_frame(name, code)

    def addr(m):
        if not m.group(1):
            return m.group(0)
        r = resolve(int(m.group(1), 16))
        return r if r else m.group(0)
    code = ADDR_CONST.sub(addr, code)
    return code


def gen_ghidra_h(types_h):
    defined = set(re.findall(r"typedef [^;]*?\b(\w+)\s*;", types_h))
    lines = ["/* Support definitions for Ghidra-decompiled C. */", "#pragma once", ""]
    base = {
        "undefined": "unsigned char", "undefined1": "unsigned char", "undefined2": "unsigned short",
        "undefined3": "unsigned int", "undefined4": "unsigned int", "undefined5": "unsigned long",
        "undefined6": "unsigned long", "undefined7": "unsigned long", "undefined8": "unsigned long",
        "undefined16": "unsigned __int128", "byte": "unsigned char", "sbyte": "signed char",
        "uchar": "unsigned char", "ushort": "unsigned short", "uint": "unsigned int", "ulong": "unsigned long",
        "longlong": "long long", "ulonglong": "unsigned long long", "word": "unsigned short",
        "dword": "unsigned int", "qword": "unsigned long", "float10": "long double",
        "uint3": "unsigned int", "uint5": "unsigned long", "uint6": "unsigned long", "uint7": "unsigned long",
        "int3": "int", "int5": "long", "int6": "long", "int7": "long", "uint16": "unsigned __int128",
        "int16": "__int128", "wchar32": "unsigned int", "wchar16": "unsigned short", "bool": "unsigned char",
        "size_t": "unsigned long", "ssize_t": "long",
    }
    for t, c in base.items():
        if t not in defined:
            # 16-byte values are SSE moves in the original, which allow any alignment
            align = " __attribute__((aligned(1)))" if "__int128" in c else ""
            lines.append(f"typedef {c} {t}{align};")
    lines += [
        "typedef long code();",
        "#define true 1",
        "#define false 0",
        "#define noreturn __attribute__((noreturn))",
        "#define __cdecl",
        "#define __stdcall",
        "#define __fastcall",
        "#define __thiscall",
        "extern long __fake_fs[16];",
        "",
    ]
    T = {1: "unsigned char", 2: "unsigned short", 3: "unsigned int", 4: "unsigned int",
         5: "unsigned long", 6: "unsigned long", 7: "unsigned long", 8: "unsigned long"}
    S = {1: "signed char", 2: "short", 3: "int", 4: "int", 5: "long", 6: "long", 7: "long", 8: "long"}
    for n in range(9, 17):
        T[n] = "unsigned __int128"
        S[n] = "__int128"

    def mask(n):
        return f"((({T[16]})1 << {8 * n}) - 1)" if n < 16 else f"(~({T[16]})0)"

    for x in range(1, 17):
        for y in range(1, 17):
            if x + y <= 16:
                lines.append(f"#define CONCAT{x}{y}(a,b) (({T[x + y]})((((({T[16]})(a)) & {mask(x)}) << {8 * y}) | ((({T[16]})(b)) & {mask(y)})))")
            lines.append(f"#define SUB{x}{y}(v,off) (({T[y]})((({T[16]})(v)) >> ((off) * 8)))")
            if y > x:
                lines.append(f"#define ZEXT{x}{y}(v) (({T[y]})({T[x]})(v))")
                lines.append(f"#define SEXT{x}{y}(v) (({S[y]})({S[x]})(v))")
    for n in (1, 2, 4, 8, 16):
        lines.append(f"#define CARRY{n}(a,b) (({T[n]})(({T[n]})(a) + ({T[n]})(b)) < ({T[n]})(a))")
        lines.append(f"#define SCARRY{n}(a,b) ({{ {S[n]} __r; __builtin_add_overflow(({S[n]})(a), ({S[n]})(b), &__r); }})")
        lines.append(f"#define SBORROW{n}(a,b) ({{ {S[n]} __r; __builtin_sub_overflow(({S[n]})(a), ({S[n]})(b), &__r); }})")
    lines += [
        "static const double NAN = __builtin_nan(\"\");",
        "static const double INFINITY = __builtin_inf();",
        "#define ASSIGN_ARR(dst, val) do { undefined16 __v = (undefined16)(val); "
        "__builtin_memcpy((dst), &__v, sizeof(dst) < 16 ? sizeof(dst) : 16); } while (0)",
        "#define builtin_strncpy(d,s,n) __builtin_strncpy((char *)(d),(s),(n))",
        "#define NAN(x) __builtin_isnan(x)",
        "#define ABS(x) __builtin_fabs(x)",
        "#define SQRT(x) __builtin_sqrt(x)",
        "#define ROUND(x) __builtin_round(x)",
        "#define TRUNC(x) ((long)(x))",
        "#define FLOOR(x) __builtin_floor(x)",
        "#define CEIL(x) __builtin_ceil(x)",
        "#define POPCOUNT(x) __builtin_popcountl(x)",
        "#define LZCOUNT(x) __builtin_clzl(x)",
        "",
        "int vsnprintf(char *, unsigned long, const char *, __builtin_va_list);",
        "int vasprintf(char **, const char *, __builtin_va_list);",
        "",
    ]
    return "\n".join(lines)


def gen_externs():
    lines = ["/* Prototypes of imported library functions and data. */", "#pragma once", ""]
    seen = set()
    for line in read(os.path.join(RAW, "externs.h")).splitlines():
        if line.startswith("/* extdata */"):
            continue
        m = re.search(r"(\w+)\(", line)
        if not m or m.group(1) in seen:
            continue
        seen.add(m.group(1))
        if line.startswith("undefined "):
            # unknown signature: leave it unprototyped so any call compiles
            line = f"long {m.group(1)}();"
        lines.append(line)
    for name, decl in EXT_DATA.items():
        lines.append(f"extern {decl};")
        lines.append(f"#define _{name} {name}")
    return "\n".join(lines) + "\n"


EXT_DATA = {
    "stdscr": "void *stdscr", "cur_term": "void *cur_term", "COLS": "int COLS", "LINES": "int LINES",
    "COLORS": "int COLORS", "stderr": "void *stderr", "stdout": "void *stdout",
    "optarg": "char *optarg", "optind": "int optind",
}


def gen_data(secs, labels, funcs, thunks):
    func_at = {a: n for a, n, _ in funcs}
    func_at.update({a: t for a, n, t in thunks})
    relocs = {}
    for line in read(os.path.join(RAW, "relocs.tsv")).splitlines():
        at, tgt, *_ = line.split("\t")
        relocs[int(at, 16)] = int(tgt, 16)

    def target(t):
        if t in func_at:
            return func_at[t]
        for s in DATA_SECTIONS:
            start, size = secs[s]
            if start <= t < start + size:
                return f"{sec_sym(s)}+{t - start:#x}"
        sys.exit(f"relocation target {t:#x} is not a function or data")

    out = ["/* Data sections of the original binary, byte-exact, with pointers turned into symbols. */", ""]
    for s in DATA_SECTIONS:
        start, size = secs[s]
        flags = {".rodata": '"a"', ".data.rel.ro": '"aw"', ".data": '"aw"', ".bss": '"aw",@nobits'}[s]
        out.append(f".section {s},{flags}")
        out.append(".balign 64")
        out.append(f".globl {sec_sym(s)}")
        out.append(f"{sec_sym(s)}:")
        for name, (ls, addr, _) in sorted(labels.items(), key=lambda kv: kv[1][1]):
            if ls == s:
                out.append(f".globl {name}\n.set {name}, {sec_sym(s)}+{addr - start:#x}")
        if s == ".bss":
            out.append(f".zero {size}")
            continue
        data = open(os.path.join(RAW, f"sec{s}.bin"), "rb").read()
        assert len(data) == size, s
        i = 0
        pending = []
        while i < size:
            if start + i in relocs:
                if pending:
                    out.append(".byte " + ",".join(pending))
                    pending = []
                out.append(f".quad {target(relocs[start + i])}")
                i += 8
                continue
            pending.append(str(data[i]))
            if len(pending) == 32:
                out.append(".byte " + ",".join(pending))
                pending = []
            i += 1
        if pending:
            out.append(".byte " + ",".join(pending))
    out.append(".text")
    for _, name, target in thunks:
        if name != target:
            out.append(f".globl {name}\n.type {name},@function\n{name}:\n\tjmp {target}")
    out.append('.section .note.GNU-stack,"",@progbits')
    return "\n".join(out) + "\n"


def gen_globals(labels):
    lines = ["/* Declarations of the global data in data.S. */", "#pragma once", ""]
    lines += [f"extern char {sec_sym(s)}[];" for s in DATA_SECTIONS] + [""]
    for name, (sec, addr, decl) in sorted(labels.items(), key=lambda kv: kv[1][1]):
        lines.append(f"extern {decl or 'undefined ' + name}; /* {sec} {addr:#x} */")
    return "\n".join(lines) + "\n"


STAMP = os.path.join(OUT, ".generated")


def check_not_edited():
    """Refuse to overwrite decomp/ when files were changed by hand since the last generation."""
    if "--force" in sys.argv or not os.path.exists(STAMP):
        return
    t = os.path.getmtime(STAMP)
    edited = [os.path.join(d, f) for sub in ("src", "include") for d, _, fs in os.walk(os.path.join(OUT, sub))
              for f in fs if os.path.getmtime(os.path.join(d, f)) > t]
    if edited:
        sys.exit("decomp/ has hand edits (" + ", ".join(os.path.relpath(e, OUT) for e in edited[:5])
                 + "); regenerating would overwrite them. Use --force to do it anyway.")


def main():
    check_not_edited()
    secs = sections()
    funcs = load_functions()
    load_frames()
    thunks = load_thunks()
    labels = load_globals()
    types_h = read(os.path.join(RAW, "types.h"))
    # enums repeated per compile unit: keep each enumerator once
    seen_enumerators = set()

    def dedupe_enum(m):
        items = [i.strip() for i in m.group(2).split(",") if i.strip()]
        fresh = [i for i in items if i.split("=")[0].strip() not in seen_enumerators]
        seen_enumerators.update(i.split("=")[0].strip() for i in items)
        if not fresh:
            return f"typedef int {m.group(3)};"
        return f"typedef enum {m.group(1)} {{\n    " + ",\n    ".join(fresh) + f"\n}} {m.group(3)};"
    types_h = re.sub(r"typedef enum (\w+) \{(.*?)\} (\w+);", dedupe_enum, types_h, flags=re.S)
    # typedefs whose name is a C keyword (Ghidra's int/wchar_t merge, _Bool, __int128)
    types_h = re.sub(r"^typedef [^;]*\b(?:int|_Bool|__int128|char|short|long|double|float|void|signed|unsigned)\s*;\n",
                     "", types_h, flags=re.M)
    # struct typedefs named like a function (stat, statfs, sigaction): use "struct X" instead
    ext_funcs = set(re.findall(r"(\w+)\(", read(os.path.join(RAW, "externs.h"))))
    clash = {n for n in re.findall(r"typedef struct (\w+) \1\b", types_h) if n in ext_funcs}
    for n in clash:
        types_h = re.sub(rf"typedef struct {n} {n}, ", f"typedef struct {n} ", types_h)
        types_h = re.sub(rf"typedef struct {n} {n};", "", types_h)
    struct_fix = re.compile(r"\"(?:[^\"\\\n]|\\.)*\"|'(?:[^'\\\n]|\\.)*'|(?<!struct )\b("
                            + "|".join(sorted(clash)) + r")\b(?!\s*\()") if clash else None

    def fix_types(text):
        text = re.sub(r"\bwchar_t\b", "int", text)
        text = re.sub(r"^typedef int +int;\n", "", text, flags=re.M)
        text = re.sub(r"\b(\w+)\.conflict(\d*)\b", r"\1_conflict\2", text)  # Ghidra's renamed duplicates
        if not struct_fix:
            return text
        return struct_fix.sub(lambda m: f"struct {m.group(1)}" if m.group(1) else m.group(0), text)

    resolve = AddrResolver(secs, labels, funcs, thunks)

    # functions
    bodies = {}
    names = {n for _, n, _ in funcs}
    for f in os.listdir(os.path.join(RAW, "funcs")):
        addr, name = f[:-2].split("_", 1)
        ovr = os.path.join(OVR, name + ".c")
        code = read(ovr) if os.path.exists(ovr) else read(os.path.join(RAW, "funcs", f))
        bodies[name] = clean_function(name, fix_types(code), resolve)
    for name in os.listdir(OVR):
        if name[:-2] not in names:
            sys.exit(f"override for unknown function {name}")

    # labels referenced in code but unknown to Ghidra's symbol table
    ranges = {s: secs[s] for s in DATA_SECTIONS}
    by_addr = {}
    for n, (sec, a, decl) in labels.items():
        if decl:
            by_addr.setdefault(a, (n, decl))
    prefix_type = {"PTR": "code *", "BYTE": "byte ", "WORD": "word ", "DWORD": "dword ", "QWORD": "qword ",
                   "CHAR": "char ", "INT": "int ", "UINT": "uint ", "LONG": "long ", "ULONG": "ulong ",
                   "DOUBLE": "double ", "FLOAT": "float ", "BOOL": "bool "}
    for code in bodies.values():
        for ident in set(re.findall(r"\b([A-Za-z_]\w*_([0-9a-f]{8}))\b", code)):
            name, hexaddr = ident
            if name in labels or name in names or name.startswith(("LAB_", "switchD_", "caseD_")):
                continue
            a = int(hexaddr, 16)
            for s, (start, size) in ranges.items():
                if start <= a < start + size:
                    if a in by_addr:  # same address under another name: same type
                        old_name, decl = by_addr[a]
                        decl = re.sub(rf"\b{re.escape(old_name)}\b", name, decl)
                    else:
                        t = prefix_type.get(name.lstrip("_").split("_")[0])
                        decl = f"{t}{name}" if t else ""
                    labels[name] = (s, a, decl)

    import shutil
    shutil.rmtree(os.path.join(OUT, "src"), ignore_errors=True)
    shutil.rmtree(os.path.join(OUT, "build"), ignore_errors=True)
    write(os.path.join(OUT, "include", "ghidra.h"), gen_ghidra_h(types_h))
    write(os.path.join(OUT, "include", "types.h"), "#pragma once\n" + fix_types(types_h))
    write(os.path.join(OUT, "include", "externs.h"), fix_types(gen_externs()))
    write(os.path.join(OUT, "include", "globals.h"), fix_types(gen_globals(labels)))
    protos = fix_types(read(os.path.join(RAW, "protos.h")))
    # function types the decompiler names in casts (_func_int_FILE_ptr) but does not define;
    # Ghidra gives them size 1, so a pointer to one is indexed like a char *
    funcdefs = sorted(set(re.findall(r"\b_func_\w+", "\n".join(bodies.values()) + gen_globals(labels))))
    protos = "".join(f"typedef char {n};\n" for n in funcdefs) + "\n" + protos
    for _, name, target in thunks:
        m = re.search(rf"^(.*\b){target}(\(.*)$", protos, re.M)
        if name != target and name != "main" and m:
            protos += f"{m.group(1)}{name}{m.group(2)}  /* alias of {target} */\n"
    write(os.path.join(OUT, "include", "functions.h"),
          "/* Prototypes of all decompiled functions. */\n#pragma once\n\n" + protos)
    write(os.path.join(OUT, "include", "htop.h"),
          '#pragma once\n#include "types.h"\n#include "ghidra.h"\n#include "externs.h"\n'
          '#include "globals.h"\n#include "functions.h"\n')
    write(os.path.join(OUT, "src", "data.S"), gen_data(secs, labels, funcs, thunks))
    write(os.path.join(OUT, "src", "support.c"),
          '#include "htop.h"\n\n/* stands in for %fs: so the stack-protector reads in decompiled code work */\n'
          "long __fake_fs[16];\n")

    for mod, fs in module_of(funcs).items():
        parts = ['#include "htop.h"\n']
        for addr, name in sorted(fs):
            parts.append(f"/* {name} @ {addr:#x} */\n{bodies[name].split(chr(10), 1)[1] if bodies[name].startswith('/*') else bodies[name]}")
        write(os.path.join(OUT, "src", mod + ".c"), "\n".join(parts))
    write(STAMP, "generated by tools/gen.py\n")
    print(f"{len(bodies)} functions, {len(labels)} data labels")


if __name__ == "__main__":
    main()
