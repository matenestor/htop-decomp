/* Vector_moveDown @ 0012e6c0 size 37 */

/* DWARF original prototype: void Vector_moveDown(Vector * this, wchar_t idx) */

void Vector_moveDown(Vector *this,wchar_t idx)

{
  Object **ppOVar1;
  Object *pOVar2;

  if (this->items + L'\xffffffff' != idx) {
    ppOVar1 = this->array + idx;
    pOVar2 = *ppOVar1;
    *ppOVar1 = ppOVar1[1];
    ppOVar1[1] = pOVar2;
  }
  return;
}

