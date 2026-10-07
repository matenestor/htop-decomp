#!/bin/sh
# Re-run Ghidra: "full" re-imports and re-analyses, otherwise only re-applies fixes and re-exports.
cd "$(dirname "$0")/.."
export JAVA_HOME=${JAVA_HOME:-$HOME/tools/jdk-21.0.12.1+1}
GHIDRA=${GHIDRA:-$HOME/tools/ghidra_12.1.4_PUBLIC}
PROJ=${PROJ:-$HOME/tools/ghidra-projects/htop}
mkdir -p "$PROJ"
rm -rf raw
if [ "$1" = full ]; then
  "$GHIDRA/support/analyzeHeadless" "$PROJ" htop -import debug/htop -overwrite -scriptPath tools/ghidra_scripts \
    -preScript PreAnalysis.java -postScript ApplyFixes.java -postScript ExportC.java "$PWD/raw" > ghidra.log 2>&1
else
  "$GHIDRA/support/analyzeHeadless" "$PROJ" htop -process htop -noanalysis -scriptPath tools/ghidra_scripts \
    -postScript ApplyFixes.java -postScript ExportC.java "$PWD/raw" > ghidra.log 2>&1
fi
grep -E 'ERROR REPORT|Exception|ApplyFixes|ExportC' ghidra.log | grep -vE 'format not constant|no format parameter'
