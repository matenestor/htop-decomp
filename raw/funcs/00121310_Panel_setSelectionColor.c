/* Panel_setSelectionColor @ 00121310 size 11 */

/* DWARF original prototype: void Panel_setSelectionColor(Panel * this, ColorElements colorId) */

void Panel_setSelectionColor(Panel *this,ColorElements colorId)

{
  this->selectionColorId = colorId;
  return;
}

