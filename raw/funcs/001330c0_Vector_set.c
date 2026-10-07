/* Vector_set @ 001330c0 size 145 */

/* DWARF original prototype: void Vector_set(Vector * this, wchar_t idx, void * data_) */

void Vector_set(Vector *this,wchar_t idx,void *data_)

{
  Object *pOVar1;
  Object **ppOVar2;
  long in_RCX;
  wchar_t wVar3;
  size_t prevmemb;
  long in_R8;
  long in_R9;
  wchar_t wVar4;

  wVar4 = idx + L'\x01';
  prevmemb = (size_t)this->arraySize;
                    /* Unresolved local var: wchar_t oldSize@[???] */
  ppOVar2 = this->array;
  if (this->arraySize < wVar4) {
    in_RCX = 8;
    wVar3 = this->growthRate + wVar4;
    this->arraySize = wVar3;
    ppOVar2 = xReallocArrayZero(ppOVar2,prevmemb,(long)wVar3,8);
    this->array = ppOVar2;
  }
                    /* Unresolved local var: Object * removed@[???] */
  ppOVar2 = ppOVar2 + idx;
  if (idx < this->items) {
    if ((this->owner != false) && (pOVar1 = *ppOVar2, pOVar1 != (Object *)0x0)) {
      (*pOVar1->klass->delete)(pOVar1,prevmemb,(long)pOVar1->klass,in_RCX,in_R8,in_R9);
      ppOVar2 = this->array + idx;
    }
  }
  else {
    this->items = wVar4;
  }
  *ppOVar2 = data_;
  return;
}

