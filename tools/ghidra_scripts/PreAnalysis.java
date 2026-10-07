// Before auto-analysis: analyzer options. Signatures come from the DWARF debug info.
import ghidra.app.script.GhidraScript;

public class PreAnalysis extends GhidraScript {
    @Override public void run() throws Exception {
        // printf/scanf call signatures are set by ApplyFixes.java (Ghidra's analyzer miscounts some formats)
        setAnalysisOption(currentProgram, "Variadic Function Signature Override", "false");
    }
}
