/* QuadColCPUsMeter_updateMode @ 001144c0 size 14 */

/* DWARF original prototype: void QuadColCPUsMeter_updateMode(Meter * this, wchar_t mode) */

void QuadColCPUsMeter_updateMode(Meter *this,wchar_t mode)

{
  CPUMeterCommonUpdateMode(this,mode,L'\x04');
  return;
}

