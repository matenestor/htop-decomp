/* NumberItem_decrease @ 00121fa0 size 65 */

/* DWARF original prototype: void NumberItem_decrease(NumberItem * this) */

void NumberItem_decrease(NumberItem *this)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;

  pwVar2 = this->ref;
  wVar3 = this->max;
  if (pwVar2 == (wchar_t *)0x0) {
    wVar1 = this->value + L'\xffffffff';
    if (wVar3 < wVar1) {
      this->value = wVar3;
      return;
    }
    wVar3 = this->min;
    if (this->min <= wVar1) {
      wVar3 = wVar1;
    }
    this->value = wVar3;
    return;
  }
  wVar1 = *pwVar2 + L'\xffffffff';
  if (wVar3 < wVar1) {
    *pwVar2 = wVar3;
    return;
  }
  wVar3 = this->min;
  if (this->min <= wVar1) {
    wVar3 = wVar1;
  }
  *pwVar2 = wVar3;
  return;
}

