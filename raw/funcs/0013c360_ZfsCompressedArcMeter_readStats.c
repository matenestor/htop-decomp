/* ZfsCompressedArcMeter_readStats @ 0013c360 size 212 */

/* DWARF original prototype: void ZfsCompressedArcMeter_readStats(Meter * this, ZfsArcStats * stats)
    */

void ZfsCompressedArcMeter_readStats(Meter *this,ZfsArcStats *stats)

{
  double *pdVar1;
  ulong uVar2;
  double dVar3;

  pdVar1 = this->values;
  if (stats->isCompressed == L'\0') {
    uVar2 = stats->size;
    this->total = (double)uVar2;
    *pdVar1 = (double)uVar2;
    return;
  }
  if ((long)stats->uncompressed < 0) {
    uVar2 = stats->compressed;
  }
  else {
    uVar2 = stats->compressed;
  }
  dVar3 = (double)stats->uncompressed;
  if (-1 < (long)uVar2) {
    this->total = dVar3;
    *pdVar1 = (double)(long)uVar2;
    return;
  }
  this->total = dVar3;
  *pdVar1 = (double)uVar2;
  return;
}

