/* TasksMeter_updateValues @ 0012e840 size 155 */

/* DWARF original prototype: void TasksMeter_updateValues(Meter * this) */

void TasksMeter_updateValues(Meter *this)

{
  uint va0;
  uint uVar1;
  uint uVar2;
  uint va1;
  uint uVar3;
  double *pdVar4;
  Table *pTVar5;

  pdVar4 = this->values;
  pTVar5 = this->host->processTable;
  va0 = this->host->activeCPUs;
  uVar1 = *(uint *)((long)&pTVar5[1].displayList + 4);
  uVar2 = *(uint *)&pTVar5[1].displayList;
  va1 = *(uint *)&pTVar5[1].rows;
  uVar3 = *(uint *)((long)&pTVar5[1].rows + 4);
  if (uVar3 < va0) {
    va0 = uVar3;
  }
  *pdVar4 = (double)uVar1;
  pdVar4[1] = (double)uVar2;
  pdVar4[2] = (double)(va1 - (uVar1 + uVar2));
  pdVar4[3] = (double)va0;
  this->total = (double)va1;
  xSnprintf(this->txtBuffer,0x100,((char *)0x148c2b /* "%u/%u" */),va0,va1);
  return;
}

