/* ProcessTable_iterateEntries @ 001200d0 size 175 */

void ProcessTable_iterateEntries(ProcessTable_ *super)

{
  LinuxMachine_2 *lhost;
  long lVar1;
  wchar_t fd;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET;
  bool bVar4;
  char buf [16];

                    /* Unresolved local var: LinuxProcessTable * this@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???]
                       Unresolved local var: LinuxMachine * lhost@[???]
                       Unresolved local var: openat_arg_t rootFd@[???] */
  bVar4 = false;
  lhost = (LinuxMachine_2 *)(super->super).host;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((((lhost->super).settings)->ss->flags & 0x80000) != 0) {
                    /* Unresolved local var: wchar_t fd@[???] */
    fd = open(((char *)0x14c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
    if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
      piVar3 = __errno_location();
      lVar2 = (long)-*piVar3;
    }
    else {
      lVar2 = readfd_internal(fd,buf,0x10);
    }
    bVar4 = false;
    if (-1 < lVar2) {
      bVar4 = buf[0] == '1';
    }
  }
  *(bool *)((long)&super[1].super.rows + 1) = bVar4;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    LinuxProcessTable_recurseProcTree
              ((LinuxProcessTable *)super,-100,lhost,((char *)0x149a78 /* "/proc" */),(Process_2 *)0x0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

