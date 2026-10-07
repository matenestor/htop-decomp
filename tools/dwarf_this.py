#!/usr/bin/env python3
"""From the DWARF debug info, find the struct types of htop's "this" pointers. Prints
function<TAB>parameter index<TAB>type name<TAB>kind, where kind is
  cast:  the method receives a base-class pointer and casts it ("Meter* this = (Meter*)cast;")
  param: the parameter itself is named "this" (Ghidra turns that into an untyped __thiscall)

usage: dwarf_this.py FILE.debug > this_types.tsv
"""
import re
import subprocess
import sys

dump = subprocess.run(["readelf", "--debug-dump=info", "-wN", sys.argv[1]], capture_output=True, text=True).stdout

dies = {}      # offset -> {"tag":, "depth":, attrs..., "children": []}
stack = []
cur = None
die_re = re.compile(r"^ <(\d+)><([0-9a-f]+)>: Abbrev Number: \d+ \((DW_TAG_\w+)\)")
attr_re = re.compile(r"^\s+<[0-9a-f]+>\s+(DW_AT_\w+)\s*:\s*(.*)$")
for line in dump.splitlines():
    m = die_re.match(line)
    if m:
        depth, off, tag = int(m.group(1)), int(m.group(2), 16), m.group(3)
        cur = {"tag": tag, "children": []}
        dies[off] = cur
        del stack[depth:]
        if depth and stack:
            stack[-1]["children"].append(off)
        stack.append(cur)
        continue
    m = attr_re.match(line)
    if m and cur is not None:
        name, val = m.group(1), m.group(2).strip()
        ref = re.search(r"<0x([0-9a-f]+)>", val)
        if ref and name in ("DW_AT_type", "DW_AT_abstract_origin", "DW_AT_specification"):
            cur[name] = int(ref.group(1), 16)
        elif name == "DW_AT_name":
            cur[name] = val.split(": ")[-1].strip()


def origin(d):
    while d and "DW_AT_abstract_origin" in d:
        d = dies.get(d["DW_AT_abstract_origin"])
    return d


def strip(off):
    """follow typedef/const/volatile; return DIE offset"""
    for _ in range(16):
        d = dies.get(off)
        if not d or d["tag"] not in ("DW_TAG_typedef", "DW_TAG_const_type", "DW_TAG_volatile_type"):
            return off
        off = d.get("DW_AT_type")
    return off


def pointee_struct(type_off):
    d = dies.get(strip(type_off)) if type_off else None
    if not d or d["tag"] != "DW_TAG_pointer_type" or "DW_AT_type" not in d:
        return None
    s = strip(d["DW_AT_type"])
    return s if dies.get(s, {}).get("tag") == "DW_TAG_structure_type" else None


def pointee_name(type_off):
    """name of what a pointer type points to, preferring the typedef name (Panel over Panel_)"""
    d = dies.get(type_off)
    while d and d["tag"] in ("DW_TAG_typedef", "DW_TAG_const_type", "DW_TAG_volatile_type") and "DW_AT_name" not in d:
        d = dies.get(d.get("DW_AT_type"))
    if not d or d["tag"] != "DW_TAG_pointer_type" or "DW_AT_type" not in d:
        return None
    t = dies.get(d["DW_AT_type"])
    while t and t["tag"] in ("DW_TAG_const_type", "DW_TAG_volatile_type"):
        t = dies.get(t.get("DW_AT_type"))
    return t.get("DW_AT_name") if t else None


def struct_name(off):
    d = dies[off]
    if "DW_AT_name" in d:
        return d["DW_AT_name"]
    return None


def derives(s, base):
    """htop inheritance: the first member (super) is the base struct, recursively"""
    for _ in range(8):
        members = [c for c in dies[s]["children"] if dies[c]["tag"] == "DW_TAG_member"]
        if not members or "DW_AT_type" not in dies[members[0]]:
            return False
        t = strip(dies[members[0]]["DW_AT_type"])
        if t == base or (struct_name(t) and struct_name(t) == struct_name(base)):
            return True
        if dies.get(t, {}).get("tag") != "DW_TAG_structure_type":
            return False
        s = t
    return False


seen = set()
for off, d in dies.items():
    if d["tag"] != "DW_TAG_subprogram":
        continue
    o = origin(d)
    fname = (o or {}).get("DW_AT_name") or d.get("DW_AT_name")
    # constructors allocate "this" themselves
    if not fname or fname in seen or fname.endswith("_new"):
        continue
    src = o if o and o["children"] else d
    params = [c for c in src["children"] if dies[c]["tag"] == "DW_TAG_formal_parameter"]
    if params and dies[params[0]].get("DW_AT_name") == "this" and (fname, "param") not in seen:
        t = pointee_name(dies[params[0]].get("DW_AT_type"))
        if t:
            seen.add((fname, "param"))
            print(f"{fname}\t0\t{t}\tparam")
    # locals declared directly in the function whose struct derives from a parameter's struct
    hits = {}
    for v in src["children"]:
        if dies[v]["tag"] != "DW_TAG_variable":
            continue
        derived = pointee_struct(dies[v].get("DW_AT_type"))
        if derived is None or not struct_name(derived):
            continue
        for i, p in enumerate(params):
            base = pointee_struct(dies[p].get("DW_AT_type"))
            if base is not None and base != derived and derives(derived, base):
                hits.setdefault(i, set()).add(derived)
    # the parameter points to the most derived of these types (one that derives from all others)
    best = {}
    for i, ts in hits.items():
        top = [t for t in ts if all(t == u or derives(t, u) for u in ts)]
        if len(top) == 1:
            best[i] = struct_name(top[0])
    hits = best
    if hits:
        seen.add(fname)
        for i, t in sorted(hits.items()):
            print(f"{fname}\t{i}\t{t}\tcast")
