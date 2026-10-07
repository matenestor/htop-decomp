/* IOPriorityPanel_getIOPriority @ 0013af30 size 39 */

/* DWARF original prototype: IOPriority IOPriorityPanel_getIOPriority(Panel * this) */

IOPriority IOPriorityPanel_getIOPriority(Panel *this)

{
  Object *pOVar1;
  IOPriority IVar2;

  IVar2 = 0;
  if ((L'\0' < this->items->items) &&
     (pOVar1 = this->items->array[this->selected], IVar2 = 0, pOVar1 != (Object *)0x0)) {
    IVar2 = *(IOPriority *)&pOVar1[2].klass;
  }
  return IVar2;
}

