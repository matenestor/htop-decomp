/* Platform_setZramValues @ 0013be10 size 197 */

/* DWARF original prototype: void Platform_setZramValues(Meter * this) */

void Platform_setZramValues(Meter *this)

{
  Machine *pMVar1;
  Table *pTVar2;
  double *pdVar3;
  ulong uVar4;
  double dVar5;

  pMVar1 = this->host;
  pTVar2 = pMVar1[2].activeTable;
  this->total = (double)pMVar1[2].tables;
  dVar5 = (double)pTVar2;
  uVar4 = (long)pMVar1[2].processTable - (long)pTVar2;
  if (-1 < (long)uVar4) {
    pdVar3 = this->values;
    *pdVar3 = dVar5;
    pdVar3[1] = (double)(long)uVar4;
    return;
  }
  pdVar3 = this->values;
  *pdVar3 = dVar5;
  pdVar3[1] = (double)uVar4;
  return;
}

