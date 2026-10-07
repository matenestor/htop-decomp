/* SingleColCPUsMeter_updateMode @ 001144a0 size 14 */

/* DWARF original prototype: void SingleColCPUsMeter_updateMode(Meter * this, wchar_t mode) */

void SingleColCPUsMeter_updateMode(Meter *this,wchar_t mode)

{
  CPUMeterCommonUpdateMode(this,mode,L'\x01');
  return;
}

