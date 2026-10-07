/* Panel_move @ 001220b0 size 15 */

/* DWARF original prototype: void Panel_move(Panel * this, wchar_t x, wchar_t y) */

void Panel_move(Panel *this,wchar_t x,wchar_t y)

{
  this->x = x;
  this->y = y;
  this->needsRedraw = true;
  return;
}

