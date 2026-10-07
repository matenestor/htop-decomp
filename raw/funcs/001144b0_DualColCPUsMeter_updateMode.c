/* DualColCPUsMeter_updateMode @ 001144b0 size 14 */

/* DWARF original prototype: void DualColCPUsMeter_updateMode(Meter * this, wchar_t mode) */

void DualColCPUsMeter_updateMode(Meter *this,wchar_t mode)

{
  CPUMeterCommonUpdateMode(this,mode,L'\x02');
  return;
}

