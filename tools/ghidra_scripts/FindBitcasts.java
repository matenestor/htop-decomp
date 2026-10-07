// Debug helper: list CAST p-code ops that reinterpret between float and integer types.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import java.util.*;

public class FindBitcasts extends GhidraScript {
    @Override public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        int total = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isThunk() || f.isExternal()) continue;
            DecompileResults r = ifc.decompileFunction(f, 120, monitor);
            if (r == null || r.getHighFunction() == null) continue;
            Iterator<PcodeOpAST> it = r.getHighFunction().getPcodeOps();
            while (it.hasNext()) {
                PcodeOpAST op = it.next();
                if (op.getOpcode() != PcodeOp.CAST) continue;
                DataType in = op.getInput(0).getHigh().getDataType(), out = op.getOutput().getHigh().getDataType();
                boolean fin = in instanceof AbstractFloatDataType || (in instanceof TypeDef && ((TypeDef) in).getBaseDataType() instanceof AbstractFloatDataType);
                boolean fout = out instanceof AbstractFloatDataType || (out instanceof TypeDef && ((TypeDef) out).getBaseDataType() instanceof AbstractFloatDataType);
                if (fin != fout) {
                    println(f.getName() + " " + op.getSeqnum().getTarget() + " " + in.getName() + " -> " + out.getName());
                    total++;
                }
            }
        }
        println("total " + total);
    }
}
