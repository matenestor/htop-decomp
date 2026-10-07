/* CheckItem_set @ 00120860 size 22 */

/* DWARF original prototype: void CheckItem_set(CheckItem * this, _Bool value) */

void CheckItem_set(CheckItem *this,_Bool value)

{
  if (this->ref != (_Bool *)0x0) {
    *this->ref = value;
    return;
  }
  this->value = value;
  return;
}

