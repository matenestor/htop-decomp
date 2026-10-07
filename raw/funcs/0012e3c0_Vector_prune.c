/* Vector_prune @ 0012e3c0 size 106 */

/* DWARF original prototype: void Vector_prune(Vector * this) */

void Vector_prune(Vector *this)

{
  Object *pOVar1;
  Object **__s;
  long in_RCX;
  ulong a2;
  ulong extraout_RDX;
  long lVar2;
  long in_RSI;
  long in_R8;
  long in_R9;

  __s = this->array;
                    /* Unresolved local var: wchar_t i@[???] */
  if ((this->owner != false) && (a2 = (ulong)(uint)this->items, L'\0' < this->items)) {
    lVar2 = 0;
    do {
      pOVar1 = __s[lVar2];
      if (pOVar1 != (Object *)0x0) {
        (*pOVar1->klass->delete)(pOVar1,in_RSI,a2,in_RCX,in_R8,in_R9);
        __s = this->array;
        a2 = extraout_RDX;
      }
      lVar2 = lVar2 + 1;
    } while ((wchar_t)lVar2 < this->items);
  }
  this->dirty_count = L'\0';
  this->items = L'\0';
  this->dirty_index = L'\xffffffff';
  memset(__s,0,(long)this->arraySize << 3);
  return;
}

