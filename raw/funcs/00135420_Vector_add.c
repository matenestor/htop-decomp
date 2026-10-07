/* Vector_add @ 00135420 size 148 */

/* DWARF original prototype: void Vector_add(Vector * this, void * data_) */

void Vector_add(Vector *this,void *data_)

{
  wchar_t wVar1;
  Object *pOVar2;
  Object **ppOVar3;
  long a3;
  wchar_t wVar4;
  size_t prevmemb;
  long in_R8;
  long in_R9;
  wchar_t wVar5;

  wVar1 = this->items;
                    /* Unresolved local var: Object * data@[???] */
  prevmemb = (size_t)this->arraySize;
                    /* Unresolved local var: wchar_t oldSize@[???] */
  ppOVar3 = this->array;
  wVar5 = wVar1 + L'\x01';
                    /* Unresolved local var: Object * removed@[???] */
  if (this->arraySize < wVar5) {
    a3 = 8;
    wVar4 = this->growthRate + wVar5;
    this->arraySize = wVar4;
    ppOVar3 = xReallocArrayZero(ppOVar3,prevmemb,(long)wVar4,8);
    this->array = ppOVar3;
    if (wVar1 < this->items) {
      ppOVar3 = ppOVar3 + wVar1;
      if ((this->owner != false) && (pOVar2 = *ppOVar3, pOVar2 != (Object *)0x0)) {
        (*pOVar2->klass->delete)(pOVar2,prevmemb,(long)pOVar2->klass,a3,in_R8,in_R9);
        ppOVar3 = this->array + wVar1;
      }
      goto LAB_0013545e;
    }
  }
  this->items = wVar5;
  ppOVar3 = ppOVar3 + wVar1;
LAB_0013545e:
  *ppOVar3 = data_;
  return;
}

