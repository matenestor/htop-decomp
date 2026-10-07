/* LoadAverageMeter_updateValues @ 00128d50 size 182 */

/* DWARF original prototype: void LoadAverageMeter_updateValues(Meter * this) */

void LoadAverageMeter_updateValues(Meter *this)

{
  uint uVar1;
  double *pdVar2;
  wchar_t *pwVar3;
  double dVar4;

  pdVar2 = this->values;
  Platform_getLoadAverage(pdVar2,pdVar2 + 1,pdVar2 + 2);
  pdVar2 = this->values;
  this->curItems = '\x01';
  pwVar3 = ((char *)0x14dbac /* L"\x14" */);
  dVar4 = 1.0;
  if (1.0 <= *pdVar2) {
    uVar1 = this->host->activeCPUs;
    dVar4 = (double)uVar1;
    pwVar3 = ((char *)0x14dba8 /* L"\x15" */);
    if (dVar4 <= *pdVar2) {
      dVar4 = (double)(uVar1 * 2);
      pwVar3 = ((char *)0x14dba4 /* L"\x10" */);
    }
  }
  this->curAttributes = pwVar3;
  this->total = dVar4;
  xSnprintf(this->txtBuffer,0x100,((char *)0x148854 /* "%.2f/%.2f/%.2f" */),*pdVar2,pdVar2[1],pdVar2[2]);
  return;
}

