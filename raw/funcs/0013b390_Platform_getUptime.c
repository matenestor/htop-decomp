/* Platform_getUptime @ 0013b390 size 227 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

wchar_t Platform_getUptime(void)

{
  int iVar1;
  wchar_t wVar2;
  FILE_2 *__stream;
  long in_FS_OFFSET;
  double dVar3;
  double uptime;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uptime = 0.0;
  __stream = fopen(((char *)0x1499c4 /* "/proc/uptime" */),((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
                    /* Unresolved local var: wchar_t n@[???] */
    iVar1 = __isoc23_fscanf(__stream,((char *)0x1499d1 /* "%64lf" */),&uptime);
    fclose(__stream);
    if (iVar1 < 1) {
      wVar2 = L'\0';
      goto LAB_0013b41d;
    }
  }
  dVar3 = uptime;
  if (ABS(uptime) < 4503599627370496.0) {
    dVar3 = (double)((ulong)((double)(long)uptime -
                            (double)(-(ulong)(uptime < (double)(long)uptime) & 0x3ff0000000000000))
                    | (ulong)uptime & 0x8000000000000000);
  }
  wVar2 = (wchar_t)dVar3;
LAB_0013b41d:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return wVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

