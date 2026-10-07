/* Panel_add @ 0012a340 size 165 */

/* DWARF original prototype: void Panel_add(Panel * this, Object * o) */

void Panel_add(Panel *this,Object *o)

{
  wchar_t wVar1;
  Vector *pVVar2;
  Object *pOVar3;
  Object **ppOVar4;
  long a3;
  wchar_t wVar5;
  size_t prevmemb;
  wchar_t wVar6;
  long in_R9;

  pVVar2 = this->items;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
  wVar1 = pVVar2->items;
                    /* Unresolved local var: Object * data@[???] */
  prevmemb = (size_t)pVVar2->arraySize;
                    /* Unresolved local var: wchar_t oldSize@[???] */
  ppOVar4 = pVVar2->array;
  wVar6 = wVar1 + L'\x01';
                    /* Unresolved local var: Object * removed@[???] */
  if (pVVar2->arraySize < wVar6) {
    wVar5 = wVar6 + pVVar2->growthRate;
    a3 = 8;
    pVVar2->arraySize = wVar5;
    ppOVar4 = xReallocArrayZero(ppOVar4,prevmemb,(long)wVar5,8);
    pVVar2->array = ppOVar4;
    if (wVar1 < pVVar2->items) {
      ppOVar4 = ppOVar4 + wVar1;
      if ((pVVar2->owner != false) && (pOVar3 = *ppOVar4, pOVar3 != (Object *)0x0)) {
        (*pOVar3->klass->delete)(pOVar3,prevmemb,(long)pOVar3->klass,a3,(ulong)(uint)wVar6,in_R9);
        ppOVar4 = pVVar2->array + wVar1;
      }
      goto LAB_0012a381;
    }
  }
  pVVar2->items = wVar6;
  ppOVar4 = ppOVar4 + wVar1;
LAB_0012a381:
  *ppOVar4 = o;
  this->needsRedraw = true;
  return;
}

