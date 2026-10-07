/* NumberItem_toggle @ 00122040 size 55 */

/* DWARF original prototype: void NumberItem_toggle(NumberItem * this) */

void NumberItem_toggle(NumberItem *this)

{
  wchar_t *pwVar1;

  pwVar1 = this->ref;
  if (pwVar1 == (wchar_t *)0x0) {
    if (this->max <= this->value) {
      this->value = this->min;
      return;
    }
    this->value = this->value + L'\x01';
    return;
  }
  if (this->max <= *pwVar1) {
    *pwVar1 = this->min;
    return;
  }
  *pwVar1 = *pwVar1 + L'\x01';
  return;
}

