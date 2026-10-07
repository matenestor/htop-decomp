/* MemorySwapMeter_updateMode @ 00121500 size 110 */

/* DWARF original prototype: void MemorySwapMeter_updateMode(Meter * this, wchar_t mode) */

void MemorySwapMeter_updateMode(Meter *this,wchar_t mode)

{
  long *plVar1;
  wchar_t wVar2;

  plVar1 = this->meterData;
  this->mode = mode;
  Meter_setMode((Meter *)*plVar1,mode);
  Meter_setMode((Meter *)plVar1[1],mode);
  wVar2 = Meter_modes[*(int *)(plVar1[1] + 0x20)]->h;
  if (Meter_modes[*(int *)(plVar1[1] + 0x20)]->h < Meter_modes[*(int *)(*plVar1 + 0x20)]->h) {
    wVar2 = Meter_modes[*(int *)(*plVar1 + 0x20)]->h;
  }
  this->h = wVar2;
  return;
}

