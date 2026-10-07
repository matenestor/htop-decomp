/* OctoColCPUsMeter_updateMode @ 001144d0 size 14 */

/* DWARF original prototype: void OctoColCPUsMeter_updateMode(Meter * this, wchar_t mode) */

void OctoColCPUsMeter_updateMode(Meter *this,wchar_t mode)

{
  CPUMeterCommonUpdateMode(this,mode,L'\b');
  return;
}

