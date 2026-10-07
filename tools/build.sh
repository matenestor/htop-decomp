#!/bin/sh
# Regenerate decomp/ from raw/, fix the type errors the compiler reports, build, print an error summary.
set -e
cd "$(dirname "$0")/.."
python3 tools/gen.py "$@"
python3 tools/fix_errors.py
touch decomp/.generated
cd decomp
make -k -j"$(nproc)" > build.log 2>&1 || true
echo "errors: $(grep -c 'error:' build.log)"
grep 'error:' build.log | sed -E 's/^[^:]+:[0-9]+:[0-9]+: //; s/‘[^’]*’/X/g' | sort | uniq -c | sort -rn | head -25
