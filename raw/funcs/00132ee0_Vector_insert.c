/* Vector_insert @ 00132ee0 size 157 */

/* DWARF original prototype: void Vector_insert(Vector * this, wchar_t idx, void * data_) */

void Vector_insert(Vector *this,wchar_t idx,void *data_)

{
  wchar_t wVar1;
  Object **ptr;
  wchar_t wVar2;

  wVar2 = this->items;
  if (wVar2 <= idx) {
    idx = wVar2;
  }
  wVar1 = this->arraySize;
                    /* Unresolved local var: wchar_t oldSize@[???] */
  ptr = this->array;
  if (wVar1 < wVar2 + L'\x01') {
    wVar2 = wVar2 + L'\x01' + this->growthRate;
    this->arraySize = wVar2;
    ptr = xReallocArrayZero(ptr,(long)wVar1,(long)wVar2,8);
    this->array = ptr;
    wVar2 = this->items;
  }
  if (idx < wVar2) {
    memmove(ptr + (long)idx + 1,ptr + idx,(long)(wVar2 - idx) << 3);
    ptr = this->array;
    wVar2 = this->items;
  }
  ptr[idx] = data_;
  this->items = wVar2 + L'\x01';
  return;
}

