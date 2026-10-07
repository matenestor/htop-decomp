/* QuadColCPUsMeter_draw @ 001141c0 size 15 */

/* DWARF original prototype: void QuadColCPUsMeter_draw(Meter * this, wchar_t x, wchar_t y, wchar_t
   w) */

void QuadColCPUsMeter_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  CPUMeterCommonDraw(this,x,y,w,L'\x04');
  return;
}

