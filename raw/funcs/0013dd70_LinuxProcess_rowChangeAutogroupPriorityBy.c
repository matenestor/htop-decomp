/* LinuxProcess_rowChangeAutogroupPriorityBy @ 0013dd70 size 12 */

_Bool LinuxProcess_rowChangeAutogroupPriorityBy(Process_ *super,Arg delta)

{
  _Bool _Var1;

  _Var1 = LinuxProcess_changeAutogroupPriorityBy((Process_3 *)(ulong)(uint)(super->super).id,delta);
  return _Var1;
}

