/* Generic_gettime_realtime @ 0013add0 size 175 */

void Generic_gettime_realtime(timeval *tvp,uint64_t *msec)

{
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  long in_FS_OFFSET;
  timespec ts;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = clock_gettime(0,(timespec_2 *)&ts);
  if (iVar2 == 0) {
    tvp->tv_sec = ts.tv_sec;
    tvp->tv_usec = ts.tv_nsec / 1000;
    uVar3 = ts.tv_sec * 1000 + (ulong)ts.tv_nsec / 1000000;
  }
  else {
                    /* Unresolved local var: timespec ts@[???] */
    uVar3 = 0;
    tvp->tv_sec = 0;
    tvp->tv_usec = 0;
  }
  *msec = uVar3;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

