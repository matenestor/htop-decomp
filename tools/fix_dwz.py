#!/usr/bin/env python3
"""Relabel DWARF 5 partial units (made by dwz) as compile units so Ghidra's DWARF importer accepts them.

usage: fix_dwz.py IN.debug OUT.debug
Partial and compile units share the header layout; only the unit_type byte changes.
"""
import re
import subprocess
import sys

src, dst = sys.argv[1], sys.argv[2]
out = subprocess.run(["readelf", "-SW", src], capture_output=True, text=True).stdout
m = re.search(r"\]\s+\.debug_info\s+\S+\s+[0-9a-f]+\s+([0-9a-f]+)\s+([0-9a-f]+)", out)
off, size = int(m.group(1), 16), int(m.group(2), 16)
data = bytearray(open(src, "rb").read())
pos, end, units, fixed = off, off + size, 0, 0
while pos < end:
    length = int.from_bytes(data[pos:pos + 4], "little")
    hdr = 4
    if length == 0xffffffff:
        length = int.from_bytes(data[pos + 4:pos + 12], "little")
        hdr = 12
    version = int.from_bytes(data[pos + hdr:pos + hdr + 2], "little")
    if version == 5 and data[pos + hdr + 2] == 3:  # DW_UT_partial -> DW_UT_compile
        data[pos + hdr + 2] = 1
        fixed += 1
    units += 1
    pos += hdr + length
open(dst, "wb").write(data)
print(f"{units} units, {fixed} partial units relabelled")
