/* Panel_insert @ 00129b20 size 35 */

/* DWARF original prototype: void Panel_insert(Panel * this, wchar_t i, Object * o) */

void Panel_insert(Panel *this,wchar_t i,Object *o)

{
  Vector_insert(this->items,i,o);
  this->needsRedraw = true;
  return;
}

