/* ProcessTable_goThroughEntries @ 00146c70 size 175 */

void ProcessTable_goThroughEntries(LinuxProcessTable_ *super)

{
  LinuxMachine_2 *lhost;
  long lVar1;
  wchar_t fd;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET;
  _Bool _Var4;
  char buf [16];

  _Var4 = false;
  lhost = (LinuxMachine_2 *)(super->super).super.host;
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
    _Var4 = false;
    if (-1 < lVar2) {
      _Var4 = buf[0] == '1';
    }
  }
  super->haveAutogroup = _Var4;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    LinuxProcessTable_recurseProcTree(super,-100,lhost,((char *)0x149a78 /* "/proc" */),(Process_2 *)0x0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

