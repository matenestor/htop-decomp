#!/bin/sh
# Fetch Ubuntu's debug symbols for ./htop and prepare debug/ for the Ghidra import.
set -e
cd "$(dirname "$0")/.."
BUILD_ID=dd044ee7403a7eaa2ca8614c0e027b8f2dcb2d3f
DDEB=htop-dbgsym_3.3.0-4build1_amd64.ddeb
mkdir -p debug
cd debug
[ -f "$DDEB" ] || curl -sSfO "http://ddebs.ubuntu.com/pool/main/h/htop/$DDEB"
rm -rf pkg && mkdir pkg && dpkg-deb -x "$DDEB" pkg
cp "pkg/usr/lib/debug/.build-id/${BUILD_ID%"${BUILD_ID#??}"}/${BUILD_ID#??}.debug" htop.debug
# Ghidra cannot read compressed sections or dwz partial units
objcopy --decompress-debug-sections htop.debug htop.debug.plain
python3 ../tools/fix_dwz.py htop.debug.plain "$BUILD_ID.debug"
rm htop.debug.plain
# copy of the binary whose debuglink CRC matches the patched debug file (code and data unchanged)
objcopy --remove-section .gnu_debuglink ../htop htop.tmp
objcopy --add-gnu-debuglink="$BUILD_ID.debug" htop.tmp htop
rm htop.tmp
python3 ../tools/dwarf_this.py "$BUILD_ID.debug" > ../tools/this_types.tsv
echo "debug/ ready"
