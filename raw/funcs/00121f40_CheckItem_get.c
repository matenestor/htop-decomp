/* CheckItem_get @ 00121f40 size 22 */

/* DWARF original prototype: _Bool CheckItem_get(CheckItem * this) */

_Bool CheckItem_get(CheckItem *this)

{
  if (this->ref != (_Bool *)0x0) {
    return *this->ref;
  }
  return this->value;
}

