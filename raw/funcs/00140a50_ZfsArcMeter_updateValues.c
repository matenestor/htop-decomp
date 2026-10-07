/* ZfsArcMeter_updateValues @ 00140a50 size 120 */

/* DWARF original prototype: void ZfsArcMeter_updateValues(Meter * this) */

void ZfsArcMeter_updateValues(Meter *this)

{
  wchar_t wVar1;
  ulong uVar2;

                    /* Unresolved local var: LinuxMachine * lhost@[???] */
  ZfsArcMeter_readStats(this,(ZfsArcStats *)&this->host[2].cachedMem);
  wVar1 = Meter_humanUnit(this->txtBuffer,this->values[5],0x100);
  if (L'\xffffffff' < wVar1) {
    uVar2 = (ulong)wVar1;
    if ((uVar2 < 0x100) && (uVar2 != 0xff)) {
      (this->txtBuffer + uVar2)[0] = '/';
      (this->txtBuffer + uVar2)[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar2 + 1,this->total,0xff - uVar2);
      return;
    }
  }
  return;
}

