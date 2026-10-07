/* Panel_resize @ 00120fd0 size 15 */

/* DWARF original prototype: void Panel_resize(Panel * this, wchar_t w, wchar_t h) */

void Panel_resize(Panel *this,wchar_t w,wchar_t h)

{
  this->w = w;
  this->h = h;
  this->needsRedraw = true;
  return;
}

