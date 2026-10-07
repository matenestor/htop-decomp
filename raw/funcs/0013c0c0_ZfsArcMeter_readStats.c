/* ZfsArcMeter_readStats @ 0013c0c0 size 416 */

/* DWARF original prototype: void ZfsArcMeter_readStats(Meter * this, ZfsArcStats * stats) */

void ZfsArcMeter_readStats(Meter *this,ZfsArcStats *stats)

{
  ulong uVar1;
  double *pdVar2;
  ulong uVar3;

  uVar1 = stats->MFU;
  pdVar2 = this->values;
  this->total = (double)stats->max;
  uVar3 = stats->MRU;
  *pdVar2 = (double)uVar1;
  uVar1 = stats->anon;
  pdVar2[1] = (double)uVar3;
  uVar3 = stats->header;
  pdVar2[2] = (double)uVar1;
  uVar1 = stats->other;
  pdVar2[3] = (double)uVar3;
  pdVar2[4] = (double)uVar1;
  this->curItems = '\x05';
  uVar1 = stats->size;
  if (-1 < (long)uVar1) {
    pdVar2[5] = (double)(long)uVar1;
    return;
  }
  pdVar2[5] = (double)uVar1;
  return;
}

