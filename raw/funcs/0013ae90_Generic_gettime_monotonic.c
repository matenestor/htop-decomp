/* Generic_gettime_monotonic @ 0013ae90 size 112 */

void Generic_gettime_monotonic(uint64_t *msec)

{
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  long in_FS_OFFSET;
  timespec ts;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = clock_gettime(1,(timespec_2 *)&ts);
  uVar3 = 0;
  if (iVar2 == 0) {
    uVar3 = (ulong)ts.tv_nsec / 1000000 + ts.tv_sec * 1000;
  }
  *msec = uVar3;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

