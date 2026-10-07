/* CPUMeterCommonInit @ 0011c8e0 size 321 */

/* DWARF original prototype: void CPUMeterCommonInit(Meter * this, wchar_t ncol) */

void CPUMeterCommonInit(Meter *this,wchar_t ncol)

{
  long *plVar1;
  byte bVar2;
  Meter_3 *a0;
  uint *puVar3;
  long *a3;
  MeterMode *pMVar4;
  ulong a2;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  uint uVar5;
  undefined4 in_register_00000034;
  ulong a1;
  long in_R8;
  long in_R9;
  uint uVar6;
  long *plVar7;

                    /* Unresolved local var: uint cpus@[???]
                       Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: Meter * * meters@[???]
                       Unresolved local var: wchar_t start@[???]
                       Unresolved local var: wchar_t count@[???]
                       Unresolved local var: wchar_t h@[???] */
  a1 = CONCAT44(in_register_00000034,ncol);
  puVar3 = this->meterData;
  uVar6 = this->host->existingCPUs;
  if (puVar3 == (uint *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    puVar3 = malloc(0x10);
    if (puVar3 == (uint *)0x0) {
LAB_0011ca3b:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->meterData = puVar3;
                    /* Unresolved local var: void * data@[???] */
    a1 = 8;
    *puVar3 = uVar6;
    a3 = calloc((ulong)uVar6,8);
    if (a3 == (long *)0x0) goto LAB_0011ca3b;
    *(long **)(puVar3 + 2) = a3;
  }
  else {
    a3 = *(long **)(puVar3 + 2);
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
    uVar6 = *puVar3;
  }
  bVar2 = (byte)*(uchar *)(this->super).klass[3].delete;
  a2 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar6 = uVar6 + 1 >> 1;
  }
  else if (bVar2 == 0x52) {
    uVar5 = uVar6 + 1;
    uVar6 = uVar6 >> 1;
    uVar5 = uVar5 >> 1;
    goto LAB_0011c935;
  }
  uVar5 = 0;
LAB_0011c935:
                    /* Unresolved local var: wchar_t i@[???] */
  if (0 < (int)uVar6) {
    plVar1 = a3 + (int)uVar6;
    plVar7 = a3;
    do {
      uVar5 = uVar5 + 1;
      a0 = (Meter_3 *)*plVar7;
      if (a0 == (Meter_3 *)0x0) {
        a1 = (ulong)uVar5;
        a0 = Meter_new((Machine_2 *)this->host,uVar5,&CPUMeter_class);
        *plVar7 = (long)a0;
        a2 = extraout_RDX_00;
      }
      plVar7 = plVar7 + 1;
      (*(a0->super).klass[1].extends)((long)a0,a1,a2,(long)a3,in_R8,in_R9);
      a2 = extraout_RDX;
    } while (plVar7 != plVar1);
  }
  if (this->mode == L'\0') {
    this->mode = L'\x01';
    pMVar4 = &BarMeterMode;
  }
  else {
    pMVar4 = Meter_modes[this->mode];
  }
  this->h = (((uVar6 - 1) + ncol) / ncol) * pMVar4->h;
  return;
}

