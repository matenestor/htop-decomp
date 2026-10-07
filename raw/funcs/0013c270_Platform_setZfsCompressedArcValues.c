/* Platform_setZfsCompressedArcValues @ 0013c270 size 228 */

/* DWARF original prototype: void Platform_setZfsCompressedArcValues(Meter * this) */

void Platform_setZfsCompressedArcValues(Meter *this)

{
  Machine *pMVar1;
  double *pdVar2;
  ulong uVar3;
  double dVar4;

  pMVar1 = this->host;
  pdVar2 = this->values;
  if (*(int *)((long)&pMVar1[2].cachedMem + 4) == 0) {
    uVar3 = pMVar1[2].totalSwap;
    this->total = (double)uVar3;
    *pdVar2 = (double)uVar3;
    return;
  }
  if ((long)pMVar1[2].tableCount < 0) {
    uVar3._0_4_ = pMVar1[2].userId;
    uVar3._4_1_ = pMVar1[2].field_0x94;
    uVar3._5_1_ = pMVar1[2].field_0x95;
    uVar3._6_1_ = pMVar1[2].field_0x96;
    uVar3._7_1_ = pMVar1[2].field_0x97;
  }
  else {
    uVar3._0_4_ = pMVar1[2].userId;
    uVar3._4_1_ = pMVar1[2].field_0x94;
    uVar3._5_1_ = pMVar1[2].field_0x95;
    uVar3._6_1_ = pMVar1[2].field_0x96;
    uVar3._7_1_ = pMVar1[2].field_0x97;
  }
  dVar4 = (double)pMVar1[2].tableCount;
  if (-1 < (long)uVar3) {
    this->total = dVar4;
    *pdVar2 = (double)(long)uVar3;
    return;
  }
  this->total = dVar4;
  *pdVar2 = (double)uVar3;
  return;
}

