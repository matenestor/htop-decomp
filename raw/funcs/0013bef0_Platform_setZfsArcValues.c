/* Platform_setZfsArcValues @ 0013bef0 size 438 */

/* DWARF original prototype: void Platform_setZfsArcValues(Meter * this) */

void Platform_setZfsArcValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  UsersTable *pUVar5;

  pMVar1 = this->host;
  uVar2 = pMVar1[2].usedSwap;
  pdVar3 = this->values;
  this->total = (double)pMVar1[2].availableMem;
  uVar4 = pMVar1[2].cachedSwap;
  *pdVar3 = (double)uVar2;
  uVar2._0_4_ = pMVar1[2].activeCPUs;
  uVar2._4_4_ = pMVar1[2].existingCPUs;
  pdVar3[1] = (double)uVar4;
  pUVar5 = pMVar1[2].usersTable;
  pdVar3[2] = (double)uVar2;
  uVar4._0_4_ = pMVar1[2].htopUserId;
  uVar4._4_4_ = pMVar1[2].maxUserId;
  pdVar3[3] = (double)pUVar5;
  pdVar3[4] = (double)uVar4;
  this->curItems = '\x05';
  uVar2 = pMVar1[2].totalSwap;
  if (-1 < (long)uVar2) {
    pdVar3[5] = (double)(long)uVar2;
    return;
  }
  pdVar3[5] = (double)uVar2;
  return;
}

