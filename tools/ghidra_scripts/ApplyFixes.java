// Fixes applied after analysis (with the DWARF debug info loaded), before ExportC:
// type cleanup, "this" pointer types, C-safe names, library prototypes, per-call printf/scanf
// signatures and signatures for untyped indirect calls.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.data.ParameterDefinitionImpl;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class ApplyFixes extends GhidraScript {
    File dir;

    @Override public void run() throws Exception {
        dir = getSourceFile().getParentFile().getParentFile().getFile(false);
        mergeTypes();
        namePadding();
        retypeThis();
        sanitizeNames();
        externProtos();
        formatOverrides();
        indirectCalls();
    }

    static DataType strip(DataType d) {
        while (d instanceof TypeDef) d = ((TypeDef) d).getBaseDataType();
        return d;
    }

    // ---- DWARF gives one copy of each type per compile unit, sometimes only an empty forward
    // declaration. Exported C has one namespace, so keep one type per name: replace empty or
    // equivalent copies by the full one, rename genuinely different ones.
    static boolean empty(DataType d) {
        return d.isNotYetDefined() || d.getLength() <= 0
            || (d instanceof Composite && ((Composite) d).getNumComponents() == 0);
    }

    void mergeTypes() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Map<String, List<DataType>> byName = new TreeMap<>();
        Iterator<DataType> it = dtm.getAllDataTypes();
        while (it.hasNext()) {
            DataType d = it.next();
            if (d instanceof Pointer || d instanceof Array || d instanceof BuiltInDataType) continue;
            byName.computeIfAbsent(d.getName(), k -> new ArrayList<>()).add(d);
        }
        int replaced = 0, renamed = 0;
        for (Map.Entry<String, List<DataType>> e : byName.entrySet()) {
            List<DataType> ds = e.getValue();
            if (ds.size() < 2) continue;
            DataType best = null;
            for (DataType d : ds)
                if (!empty(d) && (best == null || d.getLength() > best.getLength())) best = d;
            if (best == null) best = ds.get(0);
            int k = 2;
            for (DataType d : ds) {
                if (d == best) continue;
                try {
                    boolean same = d.getClass() == best.getClass()
                        && (d.isEquivalent(best) || d instanceof ghidra.program.model.data.Enum);
                    if (empty(d) || same) {
                        dtm.replaceDataType(d, best, false);
                        replaced++;
                        continue;
                    }
                    d.setName(e.getKey() + "_" + k++);
                    renamed++;
                } catch (Exception ex) {
                    println("type " + d.getPathName() + ": " + ex.getMessage());
                }
            }
        }
        println("types merged " + replaced + ", renamed " + renamed);
    }

    // ---- the decompiler names accesses to struct padding field_0xNN; give those bytes real
    // members so the exported struct definitions have them (same layout: they fill holes)
    void namePadding() throws Exception {
        int n = 0;
        Iterator<Structure> it = currentProgram.getDataTypeManager().getAllStructures();
        List<Structure> all = new ArrayList<>();
        while (it.hasNext()) all.add(it.next());
        for (Structure st : all) {
            if (st.isNotYetDefined()) continue;
            if (st.isPackingEnabled()) {
                // explicit layout: offsets stay, alignment padding becomes undefined filler
                int len = st.getLength(), align = st.getAlignment();
                st.setPackingEnabled(false);
                if (st.getLength() != len) { println("layout changed: " + st.getPathName()); continue; }
                st.setExplicitMinimumAlignment(align);
            }
            for (DataTypeComponent c : st.getComponents()) {
                if (c.getDataType() != DataType.DEFAULT) continue;
                st.replaceAtOffset(c.getOffset(), ByteDataType.dataType, 1,
                    "field_0x" + Integer.toHexString(c.getOffset()), null);
                n++;
            }
        }
        println("padding bytes named " + n);
    }

    // ---- htop methods take a base pointer ("Object* cast") and immediately cast it
    // ("Meter* this = (Meter*)cast"); the cast is free, so the decompiler accesses Meter fields
    // through the Object*. Give the parameter the derived type so fields print as cast->field.
    // Parameters named "this" make Ghidra use __thiscall with an untyped auto-parameter; those
    // get an ordinary typed first parameter. tools/this_types.tsv comes from tools/dwarf_this.py.
    void retypeThis() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Map<String, Function> byName = new HashMap<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            String n = f.getName();
            if (n.contains(".")) n = n.substring(0, n.indexOf('.'));
            byName.putIfAbsent(n, f);
        }
        int n = 0;
        for (String line : Files.readAllLines(new File(dir, "this_types.tsv").toPath())) {
            String[] p = line.split("\t");
            Function f = byName.get(p[0]);
            if (f == null) continue;
            List<DataType> found = new ArrayList<>();
            dtm.findDataTypes(p[2], found);
            DataType st = null;
            for (DataType d : found) if (d instanceof Structure || d instanceof TypeDef) { st = d; break; }
            if (st == null) { println("no struct " + p[2]); continue; }
            if (p[3].equals("param") && "__thiscall".equals(f.getCallingConventionName())) {
                List<Variable> ps = new ArrayList<>();
                ps.add(new ParameterImpl("this", new PointerDataType(st), currentProgram));
                for (Parameter q : f.getParameters())
                    if (!q.isAutoParameter()) ps.add(new ParameterImpl(q.getName(), q.getDataType(), currentProgram));
                boolean va = f.hasVarArgs();
                f.updateFunction("__stdcall", f.getReturn(), ps,
                    Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                f.setVarArgs(va);
                n++;
                continue;
            }
            int i = Integer.parseInt(p[1]);
            if (f.getParameterCount() <= i) continue;
            f.getParameter(i).setDataType(new PointerDataType(st), SourceType.USER_DEFINED);
            n++;
        }
        println("retyped this-parameters " + n);
    }

    // ---- C-safe, unique, global names: DWARF/LTO gives "x.lto_priv.0", "anon_unknown.dwarf_1b6d::x"
    // and several functions with the same name (split-off parts of a function)
    void sanitizeNames() throws Exception {
        SymbolTable st = currentProgram.getSymbolTable();
        Namespace global = currentProgram.getGlobalNamespace();
        Set<String> blocks = new HashSet<>(Arrays.asList(".text", ".rodata", ".data.rel.ro", ".data", ".bss"));
        List<Symbol> syms = new ArrayList<>();
        List<Symbol> bogus = new ArrayList<>();
        for (Symbol s : st.getAllSymbols(false)) {
            ghidra.program.model.mem.MemoryBlock b = currentProgram.getMemory().getBlock(s.getAddress());
            if (s.isExternal() || b == null || !blocks.contains(b.getName())) {
                // versioned names copied from the debug file onto imports ("cur_term@NCURSES6_...")
                if (s.getSymbolType() == SymbolType.LABEL && s.getName().contains("@")) bogus.add(s);
                if (s.getSymbolType() == SymbolType.FUNCTION && s.getName().contains("@")) {
                    Function f = getFunctionAt(s.getAddress());
                    if (f != null && f.isThunk()) {
                        try {
                            s.setName(f.getThunkedFunction(true).getName(), SourceType.ANALYSIS);
                        } catch (Exception e) {
                            println("thunk " + s.getName() + ": " + e.getMessage());
                        }
                    }
                }
                continue;
            }
            SymbolType t = s.getSymbolType();
            if (t != SymbolType.FUNCTION && t != SymbolType.LABEL) continue;
            // code labels stay; data labels (also function statics) and functions get global names
            if (t == SymbolType.LABEL && getInstructionAt(s.getAddress()) != null) continue;
            syms.add(s);
        }
        for (Symbol s : bogus) s.delete();
        println("deleted " + bogus.size() + " versioned import labels");
        // bigger functions keep the plain name
        syms.sort(Comparator.comparingLong((Symbol s) -> {
            Function f = getFunctionAt(s.getAddress());
            return f == null ? 0 : -f.getBody().getNumAddresses();
        }).thenComparing(Symbol::getAddress));
        Map<String, Address> used = new HashMap<>();
        int renamed = 0;
        for (Symbol s : syms) {
            String n = s.getName().replaceAll("@.*", "").replaceAll("[^A-Za-z0-9_]", "_");
            if (s.getAddress().equals(used.get(n))) {
                // same name at the same address (ELF and DWARF symbol): one is enough
                if (s.getSymbolType() == SymbolType.LABEL) {
                    if (s.isPrimary())
                        for (Symbol o : st.getSymbols(s.getAddress()))
                            if (o != s && o.getSymbolType() == SymbolType.LABEL) o.setPrimary();
                    s.delete();
                }
                continue;
            }
            if (used.containsKey(n)) n = n + "_" + Long.toHexString(s.getAddress().getOffset());
            used.put(n, s.getAddress());
            if (!n.equals(s.getName()) || s.getParentNamespace() != global) {
                try {
                    s.setNameAndNamespace(n, global, s.getSource());
                    renamed++;
                } catch (Exception e) {
                    println("cannot rename " + s.getName(true) + ": " + e.getMessage());
                }
            }
        }
        println("renamed " + renamed + " symbols");
    }

    // ---- prototypes for imported functions without a known signature (tools/extern_protos.h)
    void externProtos() throws Exception {
        java.util.regex.Pattern proto = java.util.regex.Pattern.compile("^(.+?)\\b(\\w+)\\((.*)\\);$");
        Map<String, Function> ext = new HashMap<>();
        for (Function f : currentProgram.getFunctionManager().getExternalFunctions()) ext.put(f.getName(), f);
        int n = 0;
        for (String line : Files.readAllLines(new File(dir, "extern_protos.h").toPath())) {
            java.util.regex.Matcher m = proto.matcher(line.trim());
            if (!m.matches() || !ext.containsKey(m.group(2))) continue;
            Function f = ext.get(m.group(2));
            List<Variable> ps = new ArrayList<>();
            boolean varargs = false;
            int i = 0;
            for (String a : m.group(3).split(",")) {
                a = a.trim();
                if (a.equals("void") || a.isEmpty()) continue;
                if (a.equals("...")) { varargs = true; continue; }
                String t = a.replaceAll("\\b\\w+$", "").trim();
                ps.add(new ParameterImpl("p" + i++, ctype(t), currentProgram));
            }
            f.updateFunction(null, new ReturnParameterImpl(ctype(m.group(1).trim()), currentProgram), ps,
                Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            f.setVarArgs(varargs);
            n++;
        }
        println("extern prototypes " + n);
    }

    DataType ctype(String t) {
        t = t.replace(" *", "*").trim();
        int stars = 0;
        while (t.endsWith("*")) { stars++; t = t.substring(0, t.length() - 1).trim(); }
        DataType d;
        switch (t) {
            case "void": d = VoidDataType.dataType; break;
            case "char": d = CharDataType.dataType; break;
            case "unsigned char": d = UnsignedCharDataType.dataType; break;
            case "short": d = ShortDataType.dataType; break;
            case "int": d = IntegerDataType.dataType; break;
            case "unsigned int": d = UnsignedIntegerDataType.dataType; break;
            case "long": d = LongDataType.dataType; break;
            case "unsigned long": d = UnsignedLongDataType.dataType; break;
            default: throw new IllegalArgumentException("type " + t);
        }
        for (int i = 0; i < stars; i++) d = new PointerDataType(d);
        return d;
    }

    // ---- per-call signatures for printf/scanf-style calls, from the format string
    static final String[] INT_REGS = {"RDI", "RSI", "RDX", "RCX", "R8", "R9"};
    static final Map<String, Integer> FMT = new HashMap<>();
    static {
        FMT.put("snprintf", 2); FMT.put("__snprintf_chk", 4); FMT.put("__printf_chk", 1);
        FMT.put("__fprintf_chk", 2); FMT.put("__isoc23_sscanf", 1); FMT.put("__isoc23_fscanf", 1);
        FMT.put("xSnprintf", 2); FMT.put("xAsprintf", 1); FMT.put("InfoScreen_drawTitled", 1);
    }
    static final java.util.regex.Pattern CONV = java.util.regex.Pattern.compile(
        "%(?:%|[-+ #0'I]*(\\*|\\d+)?(?:\\.(\\*|\\d*))?(hh|h|ll|l|L|q|j|z|t)?(\\[\\^?\\]?[^\\]]*\\]|[diouxXeEfFgGaAcspnm]))");

    List<DataType> formatArgs(String fmt, boolean scanf) {
        List<DataType> out = new ArrayList<>();
        DataType ptr = new PointerDataType(VoidDataType.dataType);
        java.util.regex.Matcher m = CONV.matcher(fmt);
        while (m.find()) {
            if (m.group().equals("%%") || "m".equals(m.group(4))) continue;
            if (scanf) {
                if (!m.group().startsWith("%*")) out.add(ptr);
                continue;
            }
            if ("*".equals(m.group(1))) out.add(IntegerDataType.dataType);
            if ("*".equals(m.group(2))) out.add(IntegerDataType.dataType);
            String len = m.group(3) == null ? "" : m.group(3);
            char c = m.group(4).charAt(0);
            if ("eEfFgGaA".indexOf(c) >= 0) out.add(len.equals("L") ? LongDoubleDataType.dataType : DoubleDataType.dataType);
            else if ("spn".indexOf(c) >= 0) out.add(ptr);
            else if (len.equals("l") || len.equals("ll") || len.equals("q") || len.equals("j") || len.equals("z") || len.equals("t"))
                out.add(LongDataType.dataType);
            else out.add(IntegerDataType.dataType);
        }
        return out;
    }

    // all constant values a varnode can have (through copies, casts, pointer adds and phi nodes)
    Set<Long> constants(ghidra.program.model.pcode.Varnode v, int depth) {
        if (v == null || depth > 8) return null;
        if (v.isConstant()) return new HashSet<>(Collections.singleton(v.getOffset()));
        ghidra.program.model.pcode.PcodeOp d = v.getDef();
        if (d == null) return null;
        switch (d.getOpcode()) {
            case ghidra.program.model.pcode.PcodeOp.COPY:
            case ghidra.program.model.pcode.PcodeOp.CAST:
                return constants(d.getInput(0), depth + 1);
            case ghidra.program.model.pcode.PcodeOp.PTRSUB:
            case ghidra.program.model.pcode.PcodeOp.INT_ADD: {
                Set<Long> a = constants(d.getInput(0), depth + 1), b = constants(d.getInput(1), depth + 1);
                if (a == null || b == null) return null;
                Set<Long> out = new HashSet<>();
                for (long x : a) for (long y : b) out.add(x + y);
                return out;
            }
            case ghidra.program.model.pcode.PcodeOp.MULTIEQUAL: {
                Set<Long> out = new HashSet<>();
                for (ghidra.program.model.pcode.Varnode in : d.getInputs()) {
                    Set<Long> c = constants(in, depth + 1);
                    if (c == null) return null;
                    out.addAll(c);
                }
                return out;
            }
        }
        return null;
    }

    Long leaBefore(Address call, String reg) {
        Instruction ins = getInstructionAt(call);
        for (int i = 0; i < 16 && ins != null; i++) {
            ins = ins.getPrevious();
            if (ins == null) return null;
            for (Object o : ins.getResultObjects()) {
                if (o instanceof ghidra.program.model.lang.Register
                        && ((ghidra.program.model.lang.Register) o).getBaseRegister().getName().equals(reg)) {
                    if (!ins.getMnemonicString().equals("LEA")) return null;
                    for (Reference r : ins.getReferencesFrom())
                        if (r.getReferenceType().isData()) return r.getToAddress().getOffset();
                    return null;
                }
            }
        }
        return null;
    }

    String cstring(long a) throws Exception {
        Address fa = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(a);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 4096; i++) {
            byte b = getByte(fa.add(i));
            if (b == 0) break;
            sb.append((char) (b & 0xff));
        }
        return sb.toString();
    }

    void formatOverrides() throws Exception {
        ghidra.app.decompiler.DecompInterface ifc = new ghidra.app.decompiler.DecompInterface();
        ifc.openProgram(currentProgram);
        int n = 0, failed = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isThunk() || f.isExternal()) continue;
            boolean calls = false;
            for (Function c : f.getCalledFunctions(monitor)) {
                Function t = c.isThunk() ? c.getThunkedFunction(true) : c;
                if (FMT.containsKey(t.getName())) calls = true;
            }
            if (!calls) continue;
            ghidra.app.decompiler.DecompileResults r = ifc.decompileFunction(f, 120, monitor);
            if (r == null || r.getHighFunction() == null) continue;
            Iterator<ghidra.program.model.pcode.PcodeOpAST> ops = r.getHighFunction().getPcodeOps();
            while (ops.hasNext()) {
                ghidra.program.model.pcode.PcodeOpAST op = ops.next();
                if (op.getOpcode() != ghidra.program.model.pcode.PcodeOp.CALL) continue;
                Function c = getFunctionAt(op.getInput(0).getAddress());
                if (c == null) continue;
                Function t = c.isThunk() ? c.getThunkedFunction(true) : c;
                Integer fi = FMT.get(t.getName());
                if (fi == null) continue;
                Set<Long> cs = op.getNumInputs() > fi + 1 ? constants(op.getInput(fi + 1), 0) : null;
                Address callAddr = op.getSeqnum().getTarget();
                boolean scanf = t.getName().contains("scanf");
                List<DataType> va = null;
                if (cs != null) {
                    for (long a : cs) {
                        List<DataType> l;
                        try { l = formatArgs(cstring(a), scanf); } catch (Exception e) { va = null; break; }
                        if (va == null) va = l;
                        else if (!va.toString().equals(l.toString())) { va = null; break; }
                    }
                }
                if (va == null) {
                    // fall back to the instruction that loads the format register right before the call
                    Long a = leaBefore(callAddr, INT_REGS[fi]);
                    if (a != null) va = formatArgs(cstring(a), scanf);
                }
                if (va == null) { println("format not constant at " + callAddr + " in " + f.getName()); failed++; continue; }
                List<ParameterDefinition> args = new ArrayList<>();
                ParameterDefinition[] fixed = t.getSignature().getArguments();
                if (fixed.length <= fi) { println("no format parameter in " + t.getPrototypeString(false, false)); failed++; continue; }
                for (int i = 0; i <= fi; i++) args.add(fixed[i]);
                int k = 0;
                for (DataType d : va) args.add(new ParameterDefinitionImpl("va" + k++, d, null));
                FunctionDefinitionDataType sig = new FunctionDefinitionDataType(t.getName() + "_" + callAddr);
                sig.setReturnType(t.getReturnType());
                sig.setArguments(args.toArray(new ParameterDefinition[0]));
                ghidra.program.model.pcode.HighFunctionDBUtil.writeOverride(f, callAddr, sig);
                n++;
            }
        }
        ifc.dispose();
        println("format overrides " + n + ", not constant " + failed);
    }

    // ---- indirect calls: virtual calls go through the base class (ObjectClass*), so the pointer
    // type often has too few parameters or none, and Ghidra drops arguments set in other blocks.
    // Pass all six integer argument registers; extra arguments are harmless.
    void indirectCalls() throws Exception {
        FunctionDefinitionDataType sig = new FunctionDefinitionDataType("indirect_call");
        ParameterDefinition[] ps = new ParameterDefinition[6];
        for (int i = 0; i < 6; i++) ps[i] = new ParameterDefinitionImpl("a" + i, LongDataType.dataType, null);
        sig.setArguments(ps);
        sig.setReturnType(LongDataType.dataType);
        ghidra.app.decompiler.DecompInterface ifc = new ghidra.app.decompiler.DecompInterface();
        ifc.openProgram(currentProgram);
        int n = 0, typed = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isThunk() || f.isExternal()) continue;
            ghidra.app.decompiler.DecompileResults r = ifc.decompileFunction(f, 120, monitor);
            if (r == null || r.getHighFunction() == null) continue;
            Iterator<ghidra.program.model.pcode.PcodeOpAST> ops = r.getHighFunction().getPcodeOps();
            while (ops.hasNext()) {
                ghidra.program.model.pcode.PcodeOpAST op = ops.next();
                if (op.getOpcode() != ghidra.program.model.pcode.PcodeOp.CALLIND) continue;
                ghidra.program.model.pcode.HighVariable hv = op.getInput(0).getHigh();
                DataType t = hv == null ? null : strip(hv.getDataType());
                FunctionDefinitionDataType call = sig;
                if (t instanceof Pointer && strip(((Pointer) t).getDataType()) instanceof FunctionDefinition) {
                    // typed, but the type may be the base class's slot (klass[1].delete is really
                    // MeterClass.updateMode): keep the typed parameters, pad to six registers
                    FunctionDefinition fd = (FunctionDefinition) strip(((Pointer) t).getDataType());
                    List<ParameterDefinition> args = new ArrayList<>(Arrays.asList(fd.getArguments()));
                    boolean flt = false;
                    for (ParameterDefinition a : args) if (strip(a.getDataType()) instanceof AbstractFloatDataType) flt = true;
                    if (flt || fd.hasVarArgs() || args.size() >= 6) { typed++; continue; }
                    while (args.size() < 6) args.add(new ParameterDefinitionImpl("a" + args.size(), LongDataType.dataType, null));
                    call = new FunctionDefinitionDataType(fd.getName() + "_padded");
                    call.setArguments(args.toArray(new ParameterDefinition[0]));
                    call.setReturnType(fd.getReturnType());
                }
                ghidra.program.model.pcode.HighFunctionDBUtil.writeOverride(f, op.getSeqnum().getTarget(), call);
                n++;
            }
        }
        ifc.dispose();
        println("indirect call overrides " + n + " (" + typed + " calls with float/vararg/full signatures kept)");
    }
}
