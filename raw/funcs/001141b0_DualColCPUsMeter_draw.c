/* DualColCPUsMeter_draw @ 001141b0 size 15 */

/* DWARF original prototype: void DualColCPUsMeter_draw(Meter * this, wchar_t x, wchar_t y, wchar_t
   w) */

void DualColCPUsMeter_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  CPUMeterCommonDraw(this,x,y,w,L'\x02');
  return;
}

