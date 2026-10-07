/* LinuxProcess_isAutogroupEnabled @ 0013b2c0 size 112 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool LinuxProcess_isAutogroupEnabled(void)

{
  long lVar1;
  wchar_t fd;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET;
  char buf [16];

                    /* Unresolved local var: wchar_t fd@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  fd = open(((char *)0x14c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    piVar3 = __errno_location();
    lVar2 = (long)-*piVar3;
  }
  else {
    lVar2 = readfd_internal(fd,buf,0x10);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return -1 < lVar2 && buf[0] == '1';
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

