/* Vector_delete @ 0012e330 size 82 */

/* DWARF original prototype: void Vector_delete(Vector * this) */

void Vector_delete(Vector *this)

{
  Object *pOVar1;
  Object **__ptr;
  long in_RCX;
  ulong a2;
  ulong extraout_RDX;
  long lVar2;
  long in_RSI;
  long in_R8;
  long in_R9;

  __ptr = this->array;
                    /* Unresolved local var: wchar_t i@[???] */
  if ((this->owner != false) && (a2 = (ulong)(uint)this->items, L'\0' < this->items)) {
    lVar2 = 0;
    do {
      pOVar1 = __ptr[lVar2];
      if (pOVar1 != (Object *)0x0) {
        (*pOVar1->klass->delete)(pOVar1,in_RSI,a2,in_RCX,in_R8,in_R9);
        __ptr = this->array;
        a2 = extraout_RDX;
      }
      lVar2 = lVar2 + 1;
    } while ((wchar_t)lVar2 < this->items);
  }
  free(__ptr);
  free(this);
  return;
}

