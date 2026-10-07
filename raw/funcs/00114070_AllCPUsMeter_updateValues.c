/* AllCPUsMeter_updateValues @ 00114070 size 94 */

/* DWARF original prototype: void AllCPUsMeter_updateValues(Meter * this) */

void AllCPUsMeter_updateValues(Meter *this)

{
  long *plVar1;
  byte bVar2;
  uint uVar3;
  long *a0;
  ulong uVar4;
  ulong a3;
  ulong a2;
  ulong extraout_RDX;
  long *plVar5;
  long in_RSI;
  long in_R8;
  long in_R9;

  plVar5 = *(long **)((long)this->meterData + 8);
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  uVar3 = *(uint *)this->meterData;
  a3 = (ulong)(int)uVar3;
  bVar2 = (byte)*(uchar *)(this->super).klass[3].delete;
  a2 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar4 = (ulong)(uVar3 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar3 >> 1);
    if (bVar2 != 0x52) {
      uVar4 = a3;
    }
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (0 < (int)uVar4) {
    plVar1 = plVar5 + uVar4;
    do {
      a0 = (long *)*plVar5;
      plVar5 = plVar5 + 1;
      (**(code **)(*a0 + 0x38))((long)a0,in_RSI,a2,a3,in_R8,in_R9);
      a2 = extraout_RDX;
    } while (plVar1 != plVar5);
  }
  return;
}

