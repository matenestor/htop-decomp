/* Panel_setCursorToSelection @ 00122090 size 32 */

/* DWARF original prototype: void Panel_setCursorToSelection(Panel * this) */

void Panel_setCursorToSelection(Panel *this)

{
  this->cursorY = ((this->selected + this->y) - this->scrollV) + L'\x01';
  this->cursorX = (this->selectedLen + this->x) - this->scrollH;
  return;
}

