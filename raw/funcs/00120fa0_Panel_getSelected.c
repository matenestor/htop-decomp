/* Panel_getSelected @ 00120fa0 size 29 */

/* DWARF original prototype: Object * Panel_getSelected(Panel * this) */

Object * Panel_getSelected(Panel *this)

{
  Object *pOVar1;

  pOVar1 = (Object *)0x0;
  if (L'\0' < this->items->items) {
    pOVar1 = this->items->array[this->selected];
  }
  return pOVar1;
}

