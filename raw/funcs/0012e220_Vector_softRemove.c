/* Vector_softRemove @ 0012e220 size 74 */

/* DWARF original prototype: Object * Vector_softRemove(Vector * this, wchar_t idx) */

Object * Vector_softRemove(Vector *this,wchar_t idx)

{
  Object *pOVar1;
  long in_RCX;
  undefined4 in_register_00000034;
  long in_R8;
  long in_R9;

  pOVar1 = this->array[idx];
  if (pOVar1 == (Object *)0x0) {
    return (Object *)0x0;
  }
  this->array[idx] = (Object *)0x0;
  this->dirty_count = this->dirty_count + L'\x01';
  if ((idx < this->dirty_index) || (this->dirty_index < L'\0')) {
    this->dirty_index = idx;
  }
  if (this->owner == false) {
    return pOVar1;
  }
  (*pOVar1->klass->delete)
            (pOVar1,CONCAT44(in_register_00000034,idx),(long)pOVar1->klass,in_RCX,in_R8,in_R9);
  return (Object *)0x0;
}

