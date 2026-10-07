/* HugePageMeter_updateValues @ 001406e0 size 416 */

/* DWARF original prototype: void HugePageMeter_updateValues(Meter * this) */

void HugePageMeter_updateValues(Meter *this)

{
  Machine *pMVar1;
  double *pdVar2;
  char *pcVar3;
  ulong uVar4;
  wchar_t wVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;

  pMVar1 = this->host;
  this->total = (double)pMVar1[1].totalMem;
  uVar9 = 0;
  pdVar2 = this->values;
                    /* Unresolved local var: uint i@[???] */
  HugePageMeter_active_labels[1] = (char *)0x0;
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: memory_t value@[???] */
  HugePageMeter_active_labels[0] = ((char *)0x148889 /* " used:" */);
  lVar6 = 0;
  *pdVar2 = 0.0;
  pdVar2[1] = NAN;
  HugePageMeter_active_labels[2] = (char *)0x0;
  HugePageMeter_active_labels[3] = (char *)0x0;
  pdVar2[2] = NAN;
  pdVar2[3] = NAN;
  uVar8 = 0;
  do {
    uVar4 = *(ulong *)((long)&pMVar1[1].usedMem + lVar6);
    uVar7 = uVar8;
    if (uVar4 != 0xffffffffffffffff) {
      uVar9 = uVar9 + uVar4;
      pcVar3 = *(char **)((long)HugePageMeter_labels + lVar6);
      uVar7 = uVar8 + 1;
      pdVar2[uVar8] = (double)uVar4;
      HugePageMeter_active_labels[uVar8] = pcVar3;
      if (uVar7 == 4) break;
    }
    lVar6 = lVar6 + 8;
    uVar8 = uVar7;
  } while (lVar6 != 0xc0);
  wVar5 = Meter_humanUnit(this->txtBuffer,(double)uVar9,0x100);
  if (L'\xffffffff' < wVar5) {
    uVar9 = (ulong)wVar5;
    if ((uVar9 < 0x100) && (uVar9 != 0xff)) {
      pcVar3 = this->txtBuffer + uVar9;
      pcVar3[0] = '/';
      pcVar3[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar9 + 1,this->total,0xff - uVar9);
      return;
    }
  }
  return;
}

