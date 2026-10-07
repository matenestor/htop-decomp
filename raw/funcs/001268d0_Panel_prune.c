/* Panel_prune @ 001268d0 size 50 */

/* DWARF original prototype: void Panel_prune(Panel * this) */

void Panel_prune(Panel *this)

{
  Vector_prune(this->items);
  this->scrollV = L'\0';
  this->selected = L'\0';
  this->oldSelected = L'\0';
  this->needsRedraw = true;
  return;
}

