/* Panel_remove @ 001220c0 size 163 */

/* DWARF original prototype: Object * Panel_remove(Panel * this, wchar_t i) */

Object * Panel_remove(Panel *this,wchar_t i)

{
  _Bool _Var1;
  Vector *pVVar2;
  Object *pOVar3;
  Object **a3;
  wchar_t wVar4;
  undefined4 in_register_00000034;
  Object **__src;
  long in_R8;
  long in_R9;
  Object *pOVar5;

                    /* Unresolved local var: Object * removed@[???] */
  __src = (Object **)CONCAT44(in_register_00000034,i);
  pVVar2 = this->items;
  this->needsRedraw = true;
  a3 = pVVar2->array;
  wVar4 = pVVar2->items + L'\xffffffff';
                    /* Unresolved local var: Object * removed@[???] */
  pOVar3 = a3[i];
  pVVar2->items = wVar4;
  if (i < wVar4) {
    __src = a3 + (long)i + 1;
    memmove(a3 + i,__src,(long)(wVar4 - i) << 3);
    a3 = pVVar2->array;
    wVar4 = pVVar2->items;
  }
  _Var1 = pVVar2->owner;
  a3[wVar4] = (Object *)0x0;
  pOVar5 = pOVar3;
  if (_Var1 != false) {
    pOVar5 = (Object *)0x0;
    (*pOVar3->klass->delete)(pOVar3,(long)__src,(long)wVar4,(long)a3,in_R8,in_R9);
  }
  wVar4 = this->selected;
  if ((L'\0' < wVar4) && (this->items->items <= wVar4)) {
    this->selected = wVar4 + L'\xffffffff';
  }
  return pOVar5;
}

