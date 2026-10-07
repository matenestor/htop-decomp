/* NumberItem_get @ 00121f80 size 20 */

/* DWARF original prototype: wchar_t NumberItem_get(NumberItem * this) */

wchar_t NumberItem_get(NumberItem *this)

{
  if (this->ref != (wchar_t *)0x0) {
    return *this->ref;
  }
  return this->value;
}

