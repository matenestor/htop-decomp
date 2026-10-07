/* Process_rowChangePriorityBy @ 00122f80 size 27 */

_Bool Process_rowChangePriorityBy(Process_ *super,Arg delta)

{
  _Bool _Var1;

                    /* Unresolved local var: wchar_t old_prio@[???]
                       Unresolved local var: wchar_t err@[???] */
  if (readonly) {
    return false;
  }
  _Var1 = Process_setPriority(super,delta.i + (int)super->nice);
  return _Var1;
}

