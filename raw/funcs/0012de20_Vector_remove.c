/* Vector_remove @ 0012de20 size 117 */

/* DWARF original prototype: Object * Vector_remove(Vector * this, wchar_t idx) */

Object * Vector_remove(Vector *this,wchar_t idx)

{
  _Bool _Var1;
  Object *pOVar2;
  Object **a3;
  wchar_t wVar3;
  undefined4 in_register_00000034;
  Object **__src;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: Object * removed@[???] */
  __src = (Object **)CONCAT44(in_register_00000034,idx);
  a3 = this->array;
                    /* Unresolved local var: Object * removed@[???] */
  wVar3 = this->items + L'\xffffffff';
  pOVar2 = a3[idx];
  this->items = wVar3;
  if (idx < wVar3) {
    __src = a3 + (long)idx + 1;
    memmove(a3 + idx,__src,(long)(wVar3 - idx) << 3);
    a3 = this->array;
    wVar3 = this->items;
  }
  _Var1 = this->owner;
  a3[wVar3] = (Object *)0x0;
  if (_Var1 == false) {
    return pOVar2;
  }
  (*pOVar2->klass->delete)(pOVar2,(long)__src,(long)wVar3,(long)a3,in_R8,in_R9);
  return (Object *)0x0;
}

