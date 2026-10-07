/* Panel_get @ 00120840 size 19 */

/* DWARF original prototype: Object * Panel_get(Panel * this, wchar_t i) */

Object * Panel_get(Panel *this,wchar_t i)

{
  return this->items->array[i];
}

