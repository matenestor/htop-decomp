/* SingleColCPUsMeter_draw @ 001141e0 size 137 */

/* DWARF original prototype: void SingleColCPUsMeter_draw(Meter * this, wchar_t x, wchar_t y,
   wchar_t w) */

void SingleColCPUsMeter_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  char cVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  long in_R8;
  long in_R9;

  plVar3 = *(long **)((long)this->meterData + 8);
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  uVar2 = *(uint *)this->meterData;
  cVar1 = (char)*(uchar *)(this->super).klass[3].delete;
  if (cVar1 == 'L') {
    uVar4 = (ulong)(uVar2 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar2 >> 1);
    if (cVar1 != 'R') {
      uVar4 = (long)(int)uVar2;
    }
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (0 < (int)uVar4) {
    plVar5 = plVar3;
    do {
      plVar6 = plVar5 + 1;
      (**(code **)(*plVar5 + 8))(*plVar5,(ulong)(uint)x,(ulong)(uint)y,(ulong)(uint)w,in_R8,in_R9);
      y = y + *(int *)(*plVar5 + 0x48);
      plVar5 = plVar6;
    } while (plVar6 != plVar3 + uVar4);
  }
  return;
}

