/* LinuxProcess_updateIOPriority @ 0013b240 size 48 */

IOPriority LinuxProcess_updateIOPriority(LinuxProcess_ *p)

{
  long lVar1;

  lVar1 = syscall(0xfc,1,(ulong)(uint)(p->super).super.id);
  p->ioPriority = (IOPriority)lVar1;
  return (IOPriority)lVar1;
}

