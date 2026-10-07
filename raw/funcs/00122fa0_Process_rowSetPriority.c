/* Process_rowSetPriority @ 00122fa0 size 21 */

_Bool Process_rowSetPriority(Process_ *super,wchar_t priority)

{
  _Bool _Var1;

                    /* Unresolved local var: wchar_t old_prio@[???]
                       Unresolved local var: wchar_t err@[???] */
  if (readonly) {
    return false;
  }
  _Var1 = Process_setPriority(super,priority);
  return _Var1;
}

