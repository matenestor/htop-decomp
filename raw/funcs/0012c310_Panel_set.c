/* Panel_set @ 0012c310 size 146 */

/* DWARF original prototype: void Panel_set(Panel * this, wchar_t i, Object * o) */

void Panel_set(Panel *this,wchar_t i,Object *o)

{
  Vector *pVVar1;
  Object *pOVar2;
  Object **ppOVar3;
  long in_RCX;
  wchar_t wVar4;
  size_t prevmemb;
  long in_R8;
  long in_R9;
  wchar_t wVar5;

                    /* Unresolved local var: Object * data@[???] */
  wVar5 = i + L'\x01';
  pVVar1 = this->items;
  prevmemb = (size_t)pVVar1->arraySize;
                    /* Unresolved local var: wchar_t oldSize@[???] */
  ppOVar3 = pVVar1->array;
  if (pVVar1->arraySize < wVar5) {
    in_RCX = 8;
    wVar4 = pVVar1->growthRate + wVar5;
    pVVar1->arraySize = wVar4;
    ppOVar3 = xReallocArrayZero(ppOVar3,prevmemb,(long)wVar4,8);
    pVVar1->array = ppOVar3;
  }
                    /* Unresolved local var: Object * removed@[???] */
  ppOVar3 = ppOVar3 + i;
  if (i < pVVar1->items) {
    if ((pVVar1->owner != false) && (pOVar2 = *ppOVar3, pOVar2 != (Object *)0x0)) {
      (*pOVar2->klass->delete)(pOVar2,prevmemb,(long)pOVar2->klass,in_RCX,in_R8,in_R9);
      ppOVar3 = pVVar1->array + i;
    }
  }
  else {
    pVVar1->items = wVar5;
  }
  *ppOVar3 = o;
  return;
}

