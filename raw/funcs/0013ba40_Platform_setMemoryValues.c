/* Platform_setMemoryValues @ 0013ba40 size 577 */

/* DWARF original prototype: void Platform_setMemoryValues(Meter * this) */

void Platform_setMemoryValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  memory_t mVar5;
  double dVar6;
  double dVar7;

  pMVar1 = this->host;
  uVar2 = pMVar1->usedMem;
  pdVar3 = this->values;
  this->total = (double)pMVar1->totalMem;
  dVar6 = (double)uVar2;
  uVar2 = pMVar1->sharedMem;
  uVar4 = pMVar1->buffersMem;
  pdVar3[2] = 0.0;
  *pdVar3 = dVar6;
  pdVar3[1] = (double)uVar2;
  uVar2 = pMVar1->cachedMem;
  pdVar3[3] = (double)uVar4;
  uVar4 = pMVar1->availableMem;
  pdVar3[4] = (double)uVar2;
  mVar5 = pMVar1[2].cachedMem;
  pdVar3[5] = (double)uVar4;
  if (((int)mVar5 != 0) && (Running_containerized == false)) {
                    /* Unresolved local var: ulonglong shrinkableSize@[???] */
    dVar7 = 0.0;
    if (pMVar1[2].sharedMem < pMVar1[2].totalSwap) {
      dVar7 = (double)(pMVar1[2].totalSwap - pMVar1[2].sharedMem);
      dVar6 = dVar6 - dVar7;
    }
    *pdVar3 = dVar6;
    pdVar3[4] = (double)uVar2 + dVar7;
    pdVar3[5] = (double)uVar4 + dVar7;
  }
  if (pMVar1[3].settings != (Settings__2 *)0x0 || pMVar1[3].realtime.tv_sec != 0) {
    dVar6 = (double)pMVar1[3].settings;
    *pdVar3 = *pdVar3 - dVar6;
    pdVar3[2] = dVar6 + 0.0;
  }
  return;
}

