/* LinuxProcess_rowSetIOPriority @ 0013b270 size 76 */

_Bool LinuxProcess_rowSetIOPriority(Process_ *super,Arg ioprio)

{
  long lVar1;

  syscall(0xfb,1,(ulong)(uint)(super->super).id,(ulong)ioprio.v & 0xffffffff);
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
  lVar1 = syscall(0xfc,1,(ulong)(uint)(super->super).id);
  *(wchar_t *)&super[1].super.super.klass = (wchar_t)lVar1;
  return ioprio.i == (wchar_t)lVar1;
}

