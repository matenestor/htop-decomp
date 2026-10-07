// Export decompiled functions, prototypes, types and a byte-exact data image.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.reloc.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportC extends GhidraScript {
    static final String[] DATA_SECTIONS = {".rodata", ".data.rel.ro", ".data", ".bss"};
    static final Set<String> SKIP = new HashSet<>(Arrays.asList(
        "_init", "_fini", "_start", "entry", "deregister_tm_clones", "register_tm_clones",
        "__do_global_dtors_aux", "frame_dummy", "_INIT_0", "_FINI_0"));

    @Override public void run() throws Exception {
        File out = new File(getScriptArgs()[0]);
        out.mkdirs();
        new File(out, "funcs").mkdirs();
        Listing listing = currentProgram.getListing();
        SymbolTable st = currentProgram.getSymbolTable();
        Memory mem = currentProgram.getMemory();

        // --- types
        try (PrintWriter w = new PrintWriter(new File(out, "types.h"))) {
            DataTypeManager dtm = currentProgram.getDataTypeManager();
            new DataTypeWriter(dtm, w).write(dtm, monitor);
        }

        // --- functions
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        ifc.setOptions(opts);
        ifc.toggleCCode(true);
        ifc.toggleSyntaxTree(true);
        ifc.setSimplificationStyle("decompile");
        ifc.openProgram(currentProgram);

        // pass 1: commit decompiler-inferred types of untyped globals so all functions agree
        AddressSet dataSet = new AddressSet();
        for (String secName : DATA_SECTIONS) {
            MemoryBlock b = mem.getBlock(secName);
            dataSet.addRange(b.getStart(), b.getEnd());
        }
        // pass 0: give referenced but untyped globals the width the instructions access them with
        int sized = 0;
        ReferenceManager rm0 = currentProgram.getReferenceManager();
        for (AddressIterator ai = rm0.getReferenceDestinationIterator(dataSet, true); ai.hasNext();) {
            Address a = ai.next();
            Data d = listing.getDataAt(a);
            if (d != null && d.isDefined()) continue;
            int size = 0;
            for (Reference ref : getReferencesTo(a)) {
                Instruction ins = listing.getInstructionAt(ref.getFromAddress());
                if (ins == null) continue;
                for (ghidra.program.model.pcode.PcodeOp op : ins.getPcode()) {
                    for (int i = -1; i < op.getNumInputs(); i++) {
                        ghidra.program.model.pcode.Varnode v = i < 0 ? op.getOutput() : op.getInput(i);
                        if (v != null && v.isAddress() && v.getAddress().equals(a)) size = Math.max(size, v.getSize());
                    }
                }
            }
            if (size < 2 || size > 8) continue;
            try {
                DataUtilities.createData(currentProgram, a, Undefined.getUndefinedDataType(size), -1,
                    DataUtilities.ClearDataMode.CHECK_FOR_SPACE);
                sized++;
            } catch (Exception e) { }
        }
        println("pass0 sized " + sized + " globals");

        int created = 0;
        for (FunctionIterator fi = listing.getFunctions(true); fi.hasNext();) {
            Function f = fi.next();
            if (f.isThunk() || f.isExternal()) continue;
            DecompileResults r = ifc.decompileFunction(f, 300, monitor);
            if (r == null || r.getHighFunction() == null) continue;
            Iterator<ghidra.program.model.pcode.HighSymbol> hi = r.getHighFunction().getGlobalSymbolMap().getSymbols();
            while (hi.hasNext()) {
                ghidra.program.model.pcode.HighSymbol hs = hi.next();
                if (hs.getStorage() == null || !hs.getStorage().isMemoryStorage()) continue;
                Address a = hs.getStorage().getMinAddress();
                if (!dataSet.contains(a)) continue;
                Data d = listing.getDataAt(a);
                if (d != null && d.isDefined() && !Undefined.isUndefined(d.getDataType())) continue;
                ghidra.program.model.pcode.HighVariable hv = hs.getHighVariable();
                DataType dt = hv != null ? hv.getDataType() : hs.getDataType();
                if (dt == null || dt.getLength() <= 0 || Undefined.isUndefined(dt)) continue;
                try {
                    DataUtilities.createData(currentProgram, a, dt, -1, DataUtilities.ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
                    created++;
                } catch (Exception e) { }
            }
        }
        println("pass1 created " + created + " global types");

        PrintWriter protos = new PrintWriter(new File(out, "protos.h"));
        PrintWriter ext = new PrintWriter(new File(out, "externs.h"));
        PrintWriter index = new PrintWriter(new File(out, "functions.tsv"));
        PrintWriter thunks = new PrintWriter(new File(out, "thunks.tsv"));
        PrintWriter frames = new PrintWriter(new File(out, "frames.tsv"));
        FunctionIterator it = listing.getFunctions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            String name = f.getName();
            if (f.isExternal()) continue;
            if (f.isThunk()) {
                MemoryBlock tb = mem.getBlock(f.getEntryPoint());
                Function t = f.getThunkedFunction(true);
                if (tb != null && tb.getName().equals(".text"))
                    thunks.println(f.getEntryPoint() + "\t" + name + "\t" + t.getName() + "\t" + (t.isExternal() ? "ext" : "int"));
                continue;
            }
            MemoryBlock b = mem.getBlock(f.getEntryPoint());
            if (b == null || !b.getName().equals(".text") || SKIP.contains(name)) continue;
            DecompileResults r = ifc.decompileFunction(f, 300, monitor);
            String code;
            String sig;
            if (r == null || !r.decompileCompleted() || r.getDecompiledFunction() == null) {
                code = "/* DECOMPILE FAILED: " + (r == null ? "" : r.getErrorMessage()) + " */\n";
                sig = "/* failed */ void " + name + "(void);";
            } else {
                code = printC(r.getCCodeMarkup());
                // stack variables and their frame offsets, for the frame emulation in tools/gen.py
                Iterator<ghidra.program.model.pcode.HighSymbol> ls = r.getHighFunction().getLocalSymbolMap().getSymbols();
                while (ls.hasNext()) {
                    ghidra.program.model.pcode.HighSymbol hs = ls.next();
                    if (hs.isParameter() || hs.getStorage() == null || !hs.getStorage().isStackStorage()) continue;
                    frames.println(name + "\t" + hs.getName() + "\t" + hs.getStorage().getStackOffset() + "\t" + hs.getSize());
                }
                sig = r.getDecompiledFunction().getSignature();
            }
            protos.println(sig);
            try (PrintWriter w = new PrintWriter(new File(out, "funcs/" + f.getEntryPoint() + "_" + name + ".c"))) {
                w.println("/* " + name + " @ " + f.getEntryPoint() + " size " + f.getBody().getNumAddresses() + " */");
                w.print(code);
            }
            String src = "";
            List<ghidra.program.model.sourcemap.SourceMapEntry> se =
                currentProgram.getSourceFileManager().getSourceMapEntries(f.getEntryPoint());
            if (!se.isEmpty()) src = se.get(0).getSourceFile().getPath();
            index.println(f.getEntryPoint() + "\t" + name + "\t" + f.getBody().getNumAddresses()
                + "\t" + (f.getSymbol().getSource() == SourceType.IMPORTED ? "named" : "anon") + "\t" + src);
        }
        index.close();
        thunks.close();
        frames.close();
        protos.close();

        // external prototypes
        FunctionIterator ex = listing.getExternalFunctions();
        while (ex.hasNext()) {
            Function f = ex.next();
            ext.println(f.getSignature().getPrototypeString(true) + ";");
        }
        for (Symbol s : st.getExternalSymbols()) {
            if (s.getSymbolType() == SymbolType.LABEL) ext.println("/* extdata */ " + s.getName());
        }
        ext.close();

        // --- data image
        TreeMap<Long, String> labels = new TreeMap<>();
        Map<Long, Long> relocs = new HashMap<>();
        RelocationTable rt = currentProgram.getRelocationTable();
        Iterator<Relocation> ri = rt.getRelocations();
        while (ri.hasNext()) {
            Relocation rel = ri.next();
            if (rel.getType() != 8) continue; // R_X86_64_RELATIVE
            long[] v = rel.getValues();
            byte[] bytes = new byte[8];
            mem.getBytes(rel.getAddress(), bytes);
            long tgt = 0;
            for (int i = 7; i >= 0; i--) tgt = (tgt << 8) | (bytes[i] & 0xff);
            relocs.put(rel.getAddress().getOffset(), tgt);
        }
        PrintWriter gl = new PrintWriter(new File(out, "globals.tsv"));
        ReferenceManager rm = currentProgram.getReferenceManager();
        for (String secName : DATA_SECTIONS) {
            MemoryBlock b = mem.getBlock(secName);
            AddressSet set = new AddressSet(b.getStart(), b.getEnd());
            TreeSet<Address> addrs = new TreeSet<>();
            AddressIterator ai = rm.getReferenceDestinationIterator(set, true);
            while (ai.hasNext()) addrs.add(ai.next());
            DataIterator di = listing.getDefinedData(set, true);
            while (di.hasNext()) addrs.add(di.next().getAddress());
            SymbolIterator si = st.getSymbols(set, SymbolType.LABEL, true);
            while (si.hasNext()) addrs.add(si.next().getAddress());
            for (Long t : relocs.values()) {
                Address a = b.getStart().getNewAddress(t);
                if (set.contains(a)) addrs.add(a);
            }
            for (Address a : addrs) {
                Symbol s = st.getPrimarySymbol(a);
                String name = s == null ? "L_" + a : s.getName();
                Data d = listing.getDataAt(a);
                String decl = d == null ? "" : cdecl(d.getDataType(), name, d.getLength());
                gl.println(secName + "\t" + a + "\t" + name + "\t" + decl);
            }
        }
        PrintWriter rl = new PrintWriter(new File(out, "relocs.tsv"));
        for (Map.Entry<Long, Long> e : relocs.entrySet()) {
            Address t = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(e.getValue());
            Function f = listing.getFunctionAt(t);
            Symbol ps = st.getPrimarySymbol(t);
            MemoryBlock tb = mem.getBlock(t);
            rl.println(Long.toHexString(e.getKey()) + "\t" + Long.toHexString(e.getValue()) + "\t"
                + (tb == null ? "?" : tb.getName()) + "\t" + (f != null ? "FUNC:" + f.getName() : (ps == null ? "" : ps.getName())));
        }
        gl.close();
        rl.close();

        // raw section bytes
        for (String secName : DATA_SECTIONS) {
            MemoryBlock b = mem.getBlock(secName);
            try (FileOutputStream fo = new FileOutputStream(new File(out, "sec" + secName + ".bin"))) {
                if (b.isInitialized()) {
                    byte[] buf = new byte[(int) b.getSize()];
                    b.getBytes(b.getStart(), buf);
                    fo.write(buf);
                }
            }
            println(secName + " " + b.getStart() + " " + b.getSize());
        }
    }

    String cdecl(DataType dt, String name, int len) {
        if (dt instanceof TypeDef && ((TypeDef) dt).getBaseDataType() instanceof Pointer
            && dt.getName().equals("pointer")) return "code *" + name;
        if (dt instanceof Array) {
            Array a = (Array) dt;
            return cdecl(a.getDataType(), name + "[" + a.getNumElements() + "]", a.getElementLength());
        }
        if (dt instanceof Pointer) {
            DataType p = ((Pointer) dt).getDataType();
            if (p == null || p instanceof VoidDataType) return "code *" + name;
            String inner = "*" + name;
            if (p instanceof Array || p instanceof FunctionDefinition) inner = "(" + inner + ")";
            return cdecl(p, inner, 0);
        }
        if (dt instanceof FunctionDefinition) {
            FunctionDefinition f = (FunctionDefinition) dt;
            StringBuilder sb = new StringBuilder();
            ParameterDefinition[] ps = f.getArguments();
            for (int i = 0; i < ps.length; i++) {
                if (i > 0) sb.append(", ");
                sb.append(cdecl(ps[i].getDataType(), "", 0).trim());
            }
            if (f.hasVarArgs()) sb.append(ps.length > 0 ? ", ..." : "...");
            if (ps.length == 0 && !f.hasVarArgs()) sb.append("void");
            return cdecl(f.getReturnType(), name + "(" + sb + ")", 0);
        }
        String n = dt.getDisplayName();
        if (dt instanceof AbstractStringDataType || n.equals("string") || n.equals("TerminatedCString"))
            return "char " + name + "[" + Math.max(len, 1) + "]";
        if (n.equals("unicode") || n.equals("unicode32")) return "unsigned int " + name + "[" + Math.max(len / 4, 1) + "]";
        if (dt instanceof Structure) n = "struct " + n;
        if (dt instanceof Union) n = "union " + n;
        return n + " " + name;
    }

    // Print the decompiled function from its token tree. String literals become the address they were
    // read from (with the text as a comment): Ghidra prints any pointer to string-looking bytes as a
    // literal, also pointers into tables, and a fresh literal would not be at that address.
    String printC(ClangTokenGroup g) {
        List<ClangNode> nodes = new ArrayList<>();
        g.flatten(nodes);
        StringBuilder sb = new StringBuilder();
        for (ClangNode n : nodes) {
            if (n instanceof ClangBreak) {
                sb.append("\n");
                for (int i = 0; i < ((ClangBreak) n).getIndent(); i++) sb.append(' ');
                continue;
            }
            ClangToken t = (ClangToken) n;
            String text = t.getText();
            // a load through a function pointer reads data (Ghidra's "code" is bytes); in C it
            // would give the function itself, so read through an integer pointer of the load's size
            if (t instanceof ClangOpToken && text.equals("*") && t.getPcodeOp() != null
                    && t.getPcodeOp().getOpcode() == ghidra.program.model.pcode.PcodeOp.LOAD) {
                ghidra.program.model.pcode.PcodeOp op = t.getPcodeOp();
                ghidra.program.model.pcode.HighVariable hv = op.getInput(1).getHigh();
                DataType pt = hv == null ? null : hv.getDataType();
                while (pt instanceof TypeDef) pt = ((TypeDef) pt).getBaseDataType();
                if (pt instanceof Pointer) {
                    DataType target = ((Pointer) pt).getDataType();
                    while (target instanceof TypeDef) target = ((TypeDef) target).getBaseDataType();
                    if (target instanceof FunctionDefinition) {
                        String[] it = {"", "uchar", "ushort", "", "uint", "", "", "", "ulong"};
                        int sz = op.getOutput().getSize();
                        if (sz <= 8 && !it[sz].isEmpty()) text = "*(" + it[sz] + " *)";
                    }
                }
            }
            if (t instanceof ClangVariableToken && (text.startsWith("\"") || text.startsWith("L\"")
                    || text.startsWith("u\"") || text.startsWith("U\""))) {
                ghidra.program.model.pcode.Varnode v = ((ClangVariableToken) t).getVarnode();
                if (v != null && v.isConstant() && v.getSize() == 8) {
                    String c = text.replace("*/", "*\\/");
                    text = "((char *)0x" + Long.toHexString(v.getOffset()) + " /* " + c + " */)";
                }
            }
            sb.append(text);
        }
        return sb.toString().replaceAll("[ \t]+\n", "\n") + "\n";
    }
}
