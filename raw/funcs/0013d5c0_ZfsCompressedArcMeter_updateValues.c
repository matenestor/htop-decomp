/* ZfsCompressedArcMeter_updateValues @ 0013d5c0 size 289 */

/* DWARF original prototype: void ZfsCompressedArcMeter_updateValues(Meter * this) */

void ZfsCompressedArcMeter_updateValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double dVar3;
  double dVar4;

                    /* Unresolved local var: LinuxMachine * lhost@[???] */
  pMVar1 = this->host;
  if (*(int *)((long)&pMVar1[2].cachedMem + 4) == 0) {
    dVar4 = (double)pMVar1[2].totalSwap;
    dVar3 = dVar4;
  }
  else {
    if ((long)pMVar1[2].tableCount < 0) {
      uVar2._0_4_ = pMVar1[2].userId;
      uVar2._4_1_ = pMVar1[2].field_0x94;
      uVar2._5_1_ = pMVar1[2].field_0x95;
      uVar2._6_1_ = pMVar1[2].field_0x96;
      uVar2._7_1_ = pMVar1[2].field_0x97;
    }
    else {
      uVar2._0_4_ = pMVar1[2].userId;
      uVar2._4_1_ = pMVar1[2].field_0x94;
      uVar2._5_1_ = pMVar1[2].field_0x95;
      uVar2._6_1_ = pMVar1[2].field_0x96;
      uVar2._7_1_ = pMVar1[2].field_0x97;
    }
    dVar3 = (double)pMVar1[2].tableCount;
    if ((long)uVar2 < 0) {
      dVar4 = (double)uVar2;
    }
    else {
      dVar4 = (double)(long)uVar2;
    }
  }
  this->total = dVar3;
  *this->values = dVar4;
  if (0.0 < dVar4) {
    xSnprintf(this->txtBuffer,0x100,((char *)0x149b79 /* "%.2f:1" */),this->total / dVar4);
    return;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x1474de /* "N/A" */));
  return;
}

