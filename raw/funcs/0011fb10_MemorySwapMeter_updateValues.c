/* MemorySwapMeter_updateValues @ 0011fb10 size 47 */

/* DWARF original prototype: void MemorySwapMeter_updateValues(Meter * this) */

void MemorySwapMeter_updateValues(Meter *this)

{
  long *plVar1;
  long *a0;
  long in_RCX;
  long in_RDX;
  long a2;
  long in_RSI;
  long in_R8;
  long in_R9;

  plVar1 = this->meterData;
  a0 = (long *)*plVar1;
  (**(code **)(*a0 + 0x38))((long)a0,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
  plVar1 = (long *)plVar1[1];
                    /* WARNING: Could not recover jumptable at 0x0011fb3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar1 + 0x38))((long)plVar1,in_RSI,a2,in_RCX,in_R8,in_R9);
  return;
}

