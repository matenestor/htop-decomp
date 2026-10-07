#!/usr/bin/env python3
"""Report printf/scanf-style calls in decomp/src whose argument count does not match the format string."""
import glob
import re
import sys

# function -> index of the format argument
FMT_FUNCS = {"snprintf": 2, "__snprintf_chk": 4, "__printf_chk": 1, "__fprintf_chk": 2, "__isoc23_sscanf": 1,
             "__isoc23_fscanf": 1, "xSnprintf": 2, "xAsprintf": 1, "InfoScreen_drawTitled": 1, "__sprintf_chk": 3,
             "fprintf": 1, "printf": 0, "sprintf": 1, "__asprintf_chk": 2, "__dprintf_chk": 2}
CONV = re.compile(r"%(?:%|[-+ #0'I]*(\*|\d+)?(?:\.(\*|\d*))?(hh|h|ll|l|L|q|j|z|t)?(\[\^?\]?[^\]]*\]|[diouxXeEfFgGaAcspnm]))")


def nargs(fmt, scanf):
    n = 0
    for m in CONV.finditer(fmt):
        if m.group(0) == "%%" or m.group(4) == "m":
            continue
        if scanf:
            if not m.group(0).startswith("%*"):
                n += 1
            continue
        n += (m.group(1) == "*") + (m.group(2) == "*") + 1
    return n


def split_args(s):
    args, depth, cur, i, q = [], 0, "", 0, None
    while i < len(s):
        c = s[i]
        if q:
            cur += c
            if c == "\\":
                cur += s[i + 1]
                i += 1
            elif c == q:
                q = None
        elif c in "\"'":
            q = c
            cur += c
        elif c in "([{":
            depth += 1
            cur += c
        elif c in ")]}":
            if depth == 0:
                args.append(cur.strip())
                return args, i
            depth -= 1
            cur += c
        elif c == "," and depth == 0:
            args.append(cur.strip())
            cur = ""
        else:
            cur += c
        i += 1
    return None, i


bad = checked = 0
for path in sorted(glob.glob(sys.argv[1] + "/*.c")):
    src = open(path).read()
    for m in re.finditer(r"\b(" + "|".join(FMT_FUNCS) + r")\(", src):
        args, _ = split_args(src[m.end():])
        fi = FMT_FUNCS[m.group(1)]
        if not args or len(args) <= fi:
            continue
        lit = re.fullmatch(r'(?:\(\(char \*\)(?:0x[0-9a-f]+|\(long\)[^/]*) /\* )?"((?:[^"\\]|\\.)*)"(?: \*/\))?', args[fi])
        if not lit:
            continue
        checked += 1
        want = nargs(lit.group(1), "scanf" in m.group(1))
        have = len(args) - fi - 1
        if want != have:
            bad += 1
            line = src.count("\n", 0, m.start()) + 1
            print(f"{path}:{line}: {m.group(1)} {args[fi]} wants {want} got {have}")
print(f"{checked} calls checked, {bad} mismatched", file=sys.stderr)
