/* OctoColCPUsMeter_draw @ 001141d0 size 15 */

/* DWARF original prototype: void OctoColCPUsMeter_draw(Meter * this, wchar_t x, wchar_t y, wchar_t
   w) */

void OctoColCPUsMeter_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  CPUMeterCommonDraw(this,x,y,w,L'\b');
  return;
}

