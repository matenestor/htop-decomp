/* NumberItem_increase @ 00121ff0 size 65 */

/* DWARF original prototype: void NumberItem_increase(NumberItem * this) */

void NumberItem_increase(NumberItem *this)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;

  pwVar2 = this->ref;
  wVar3 = this->max;
  if (pwVar2 == (wchar_t *)0x0) {
    wVar1 = this->value;
    if (wVar3 <= wVar1) {
      this->value = wVar3;
      return;
    }
    wVar3 = this->min;
    if (this->min <= wVar1) {
      wVar3 = wVar1 + L'\x01';
    }
    this->value = wVar3;
    return;
  }
  wVar1 = *pwVar2;
  if (wVar3 <= wVar1) {
    *pwVar2 = wVar3;
    return;
  }
  wVar3 = this->min;
  if (this->min <= wVar1) {
    wVar3 = wVar1 + L'\x01';
  }
  *pwVar2 = wVar3;
  return;
}

