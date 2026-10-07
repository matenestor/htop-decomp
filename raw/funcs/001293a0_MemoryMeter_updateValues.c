/* MemoryMeter_updateValues @ 001293a0 size 200 */

/* DWARF original prototype: void MemoryMeter_updateValues(Meter * this) */

void MemoryMeter_updateValues(Meter *this)

{
  char *pcVar1;
  double *pdVar2;
  wchar_t wVar3;
  ulong uVar4;
  double value;

  pdVar2 = this->values;
  pdVar2[5] = NAN;
  pdVar2[1] = NAN;
  pdVar2[2] = NAN;
  Platform_setMemoryValues(this);
  this->curItems = '\x05';
  value = *pdVar2;
  if (0.0 < pdVar2[1]) {
    value = value + pdVar2[1];
  }
  if (0.0 < pdVar2[2]) {
    value = value + pdVar2[2];
  }
  wVar3 = Meter_humanUnit(this->txtBuffer,value,0x100);
  if (L'\xffffffff' < wVar3) {
    uVar4 = (ulong)wVar3;
    if ((uVar4 < 0x100) && (uVar4 != 0xff)) {
      pcVar1 = this->txtBuffer + uVar4;
      pcVar1[0] = '/';
      pcVar1[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar4 + 1,this->total,0xff - uVar4);
      return;
    }
  }
  return;
}

