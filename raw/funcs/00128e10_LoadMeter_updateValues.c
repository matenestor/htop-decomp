/* LoadMeter_updateValues @ 00128e10 size 204 */

/* DWARF original prototype: void LoadMeter_updateValues(Meter * this) */

void LoadMeter_updateValues(Meter *this)

{
  double dVar1;
  uint uVar2;
  wchar_t *pwVar3;
  long in_FS_OFFSET;
  double dVar4;
  double fifteen;
  double five;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  Platform_getLoadAverage(this->values,&five,&fifteen);
  dVar4 = 1.0;
  pwVar3 = ((char *)0x14dbac /* L"\x14" */);
  dVar1 = *this->values;
  if (1.0 <= dVar1) {
    uVar2 = this->host->activeCPUs;
    dVar4 = (double)uVar2;
    pwVar3 = ((char *)0x14dba8 /* L"\x15" */);
    if (dVar4 <= dVar1) {
      dVar4 = (double)(uVar2 * 2);
      pwVar3 = ((char *)0x14dba4 /* L"\x10" */);
    }
  }
  this->curAttributes = pwVar3;
  this->total = dVar4;
  xSnprintf(this->txtBuffer,0x100,((char *)0x14885e /* "%.2f" */),*this->values);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

