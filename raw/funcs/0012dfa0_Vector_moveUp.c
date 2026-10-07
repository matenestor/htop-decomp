/* Vector_moveUp @ 0012dfa0 size 35 */

/* DWARF original prototype: void Vector_moveUp(Vector * this, wchar_t idx) */

void Vector_moveUp(Vector *this,wchar_t idx)

{
  Object **ppOVar1;
  Object **ppOVar2;
  Object *pOVar3;

  if (idx != L'\0') {
                    /* Unresolved local var: Object * temp@[???] */
    ppOVar1 = this->array + (long)idx + -1;
    pOVar3 = *ppOVar1;
    ppOVar2 = this->array + (long)idx + -1;
    *ppOVar2 = ppOVar1[1];
    ppOVar2[1] = pOVar3;
  }
  return;
}

