#!/usr/bin/env python3
"""Compile decomp/ and rewrite the spots where Ghidra's type propagation produced invalid C.

The decompiler sometimes gives a variable a base-class or wrong pointer type (inlined casts are
free in the binary). The compiler pinpoints those places; each is rewritten as a reinterpretation
of the same bits, which is what the machine code does:
  called object is not a function      (*X)(..)        -> (*(code *)(X))(..)
  too many arguments (padded call)     (*X)(..)        -> (*(code *)(X))(..)
  invalid use of void expression       (T)(*f)(..)     -> (T)(*(code *)f)(..)
  struct assigned a scalar             S = v;          -> *(__typeof__(v) *)&S = v;
  pointer used as double               (double)pXVar1  -> *(double *)&pXVar1
  function pointer indexed             f[n]            -> ((char *)f)[n]  (Ghidra: code is bytes)
Repeats until the build has no fixable errors left.
"""
import os
import re
import subprocess
import sys

DECOMP = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "decomp")
ERR = re.compile(r"^(src/[^:]+):(\d+):(\d+): error: (.*)$")


def matching(text, i):
    """index of the bracket closing the one at text[i]"""
    depth = 0
    for j in range(i, len(text)):
        if text[j] in "([":
            depth += 1
        elif text[j] in ")]":
            depth -= 1
            if depth == 0:
                return j
    return -1


def fix_call(line, col):
    i = col - 1
    if line[i:i + 1] != "*" or line[i - 1:i] != "(":
        return None
    close = matching(line, i - 1)
    if close < 0:
        return None
    return line[:i - 1] + f"(*(code *)({line[i + 1:close]}))" + line[close + 1:]


def fix_void_call(line, col):
    new = re.sub(r"(\([\w ]+\**\))\(\*(\w+)\)\(", r"\1(*(code *)\2)(", line, count=1)
    return new if new != line else None


def fix_struct_assign(line, col):
    m = re.match(r"^(\s*)(.+?) = (.+);$", line)
    if not m:
        return None
    lhs, rhs = m.group(2), m.group(3)
    c = re.match(r"^\((\w+)\)(\(.*\))$", rhs)  # (StructType)(expr)
    if c:
        rhs = c.group(2)
    return f"{m.group(1)}*(__typeof__({rhs}) *)&({lhs}) = {rhs};"


def fix_ptr_double(line, col):
    new = re.sub(r"\(double\)(p[A-Z]\w*Var\d+(?:\[[^\]]*\])?(?:(?:\.|->)\w+(?:\[[^\]]*\])?)*)",
                 r"*(double *)&\1", line)
    return new if new != line else None


def fix_subscript(line, col):
    i = col - 1
    if line[i:i + 1] != "[":
        return None
    m = re.search(r"([A-Za-z_]\w*)$", line[:i])
    if not m:
        return None
    return line[:m.start()] + f"((char *){m.group(1)})" + line[i:]


FIXES = [
    ("subscripted value is pointer to function", fix_subscript),
    ("called object is not a function or function pointer", fix_call),
    ("too many arguments to function", fix_call),
    ("invalid use of void expression", fix_void_call),
    ("incompatible types when assigning to type", fix_struct_assign),
    ("conversion to non-scalar type requested", fix_struct_assign),
    ("pointer value used where a floating-point was expected", fix_ptr_double),
]


def build():
    r = subprocess.run(["make", "-k", f"-j{os.cpu_count()}"], cwd=DECOMP, capture_output=True, text=True)
    return r.stdout + r.stderr


def main():
    total = 0
    for _ in range(10):
        log = build()
        edits = {}
        for line in log.splitlines():
            m = ERR.match(line)
            if not m:
                continue
            path, ln, col, msg = m.group(1), int(m.group(2)), int(m.group(3)), m.group(4)
            for key, fn in FIXES:
                if msg.startswith(key):
                    edits.setdefault(path, {}).setdefault(ln, (col, fn))
        applied = 0
        for path, lines in edits.items():
            full = os.path.join(DECOMP, path)
            src = open(full).read().split("\n")
            for ln, (col, fn) in lines.items():
                new = fn(src[ln - 1], col)
                if new and new != src[ln - 1]:
                    src[ln - 1] = new
                    applied += 1
            open(full, "w").write("\n".join(src))
        total += applied
        if not applied:
            break
    print(f"fixed {total} type errors")


if __name__ == "__main__":
    main()
