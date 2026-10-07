/* Platform_setSwapValues @ 0013bca0 size 326 */

/* DWARF original prototype: void Platform_setSwapValues(Meter * this) */

void Platform_setSwapValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  double dVar5;
  double dVar6;

  pMVar1 = this->host;
  uVar2 = pMVar1->usedSwap;
  pdVar3 = this->values;
  this->total = (double)pMVar1->totalSwap;
  dVar5 = (double)uVar2;
  uVar2 = pMVar1->cachedSwap;
  uVar4 = pMVar1[3].realtime.tv_sec;
  pdVar3[2] = 0.0;
  *pdVar3 = dVar5;
  pdVar3[1] = (double)uVar2;
  if (uVar4 != 0) {
    dVar6 = (double)uVar4;
    dVar5 = dVar5 - dVar6;
    *pdVar3 = dVar5;
    if (dVar5 < 0.0) {
      *pdVar3 = 0.0;
      pdVar3[1] = (double)uVar2 + dVar5;
    }
    pdVar3[2] = dVar6 + 0.0;
    return;
  }
  if (pMVar1[3].settings != (Settings__2 *)0x0) {
    *pdVar3 = dVar5;
    pdVar3[2] = 0.0;
    return;
  }
  return;
}

