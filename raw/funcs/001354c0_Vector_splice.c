/* Vector_splice @ 001354c0 size 143 */

/* DWARF original prototype: void Vector_splice(Vector * this, Vector * from) */

void Vector_splice(Vector *this,Vector *from)

{
  wchar_t wVar1;
  wchar_t wVar2;
  Object **ppOVar3;
  long lVar4;
  Object **ppOVar5;
  wchar_t wVar6;

  wVar1 = this->items;
  wVar2 = this->arraySize;
  wVar6 = from->items + wVar1;
  if (wVar2 < wVar6) {
                    /* Unresolved local var: wchar_t oldSize@[???] */
    wVar6 = wVar6 + this->growthRate;
    this->arraySize = wVar6;
    ppOVar5 = xReallocArrayZero(this->array,(long)wVar2,(long)wVar6,8);
    wVar6 = from->items + this->items;
    this->array = ppOVar5;
  }
  this->items = wVar6;
                    /* Unresolved local var: wchar_t j@[???] */
  wVar2 = from->items;
  if (L'\0' < wVar2) {
    ppOVar5 = this->array;
    ppOVar3 = from->array;
    lVar4 = 0;
    do {
      *(undefined8 *)((long)ppOVar5 + lVar4 + (long)wVar1 * 8) =
           *(undefined8 *)((long)ppOVar3 + lVar4);
      lVar4 = lVar4 + 8;
    } while ((long)wVar2 * 8 != lVar4);
  }
  return;
}

