/* SwapMeter_updateValues @ 0012f890 size 145 */

/* DWARF original prototype: void SwapMeter_updateValues(Meter * this) */

void SwapMeter_updateValues(Meter *this)

{
  double *pdVar1;
  wchar_t wVar2;
  ulong uVar3;

  pdVar1 = this->values;
  pdVar1[1] = NAN;
  pdVar1[2] = NAN;
  Platform_setSwapValues(this);
  wVar2 = Meter_humanUnit(this->txtBuffer,*pdVar1,0x100);
  if (L'\xffffffff' < wVar2) {
    uVar3 = (ulong)wVar2;
    if ((uVar3 < 0x100) && (uVar3 != 0xff)) {
      (this->txtBuffer + uVar3)[0] = '/';
      (this->txtBuffer + uVar3)[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar3 + 1,this->total,0xff - uVar3);
      return;
    }
  }
  return;
}

