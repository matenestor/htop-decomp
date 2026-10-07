/* Process_setPriority @ 00122f10 size 106 */

/* DWARF original prototype: _Bool Process_setPriority(Process * this, wchar_t priority) */

_Bool Process_setPriority(Process *this,wchar_t priority)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = getpriority(PRIO_PROCESS,(this->super).id);
  iVar2 = setpriority(PRIO_PROCESS,(this->super).id,priority);
  if (iVar2 == 0) {
    iVar3 = getpriority(PRIO_PROCESS,(this->super).id);
    if (iVar1 != iVar3) {
      this->nice = (long)priority;
      return true;
    }
  }
  return iVar2 == 0;
}

