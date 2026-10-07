/* Platform_getMaxPid @ 0013b560 size 120 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pid_t Platform_getMaxPid(void)

{
  FILE_2 *__stream;
  long in_FS_OFFSET;
  pid_t maxPid;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  maxPid = 0x3fffff;
  __stream = fopen(((char *)0x148869 /* "/proc/sys/kernel/pid_max" */),((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    __isoc23_fscanf(__stream,((char *)0x14978b /* "%32d" */),&maxPid);
    fclose(__stream);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return maxPid;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

