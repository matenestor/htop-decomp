/* Vector_take @ 0012e4d0 size 90 */

/* DWARF original prototype: Object * Vector_take(Vector * this, wchar_t idx) */

Object * Vector_take(Vector *this,wchar_t idx)

{
  Object *pOVar1;
  Object **ppOVar2;
  wchar_t wVar3;

  ppOVar2 = this->array;
  wVar3 = this->items + L'\xffffffff';
  pOVar1 = ppOVar2[idx];
  this->items = wVar3;
  if (idx < wVar3) {
    memmove(ppOVar2 + idx,ppOVar2 + (long)idx + 1,(long)(wVar3 - idx) << 3);
    ppOVar2 = this->array;
    wVar3 = this->items;
  }
  ppOVar2[wVar3] = (Object *)0x0;
  return pOVar1;
}

