/* Panel_splice @ 0012c3b0 size 35 */

/* DWARF original prototype: void Panel_splice(Panel * this, Vector * from) */

void Panel_splice(Panel *this,Vector *from)

{
  Vector_splice(this->items,from);
  this->needsRedraw = true;
  return;
}

