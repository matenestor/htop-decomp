/* Platform_getLoadAverage @ 0013b480 size 206 */

void Platform_getLoadAverage(double *one,double *five,double *fifteen)

{
  int iVar1;
  FILE_2 *__stream;
  long in_FS_OFFSET;
  double scanFifteen;
  double scanFive;
  double scanOne;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)0x1499d7 /* "/proc/loadavg" */),((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)0x1499e5 /* "%lf %lf %lf" */),&scanOne,&scanFive,&scanFifteen);
    fclose(__stream);
    if (iVar1 == 3) {
      *one = scanOne;
      *five = scanFive;
      goto LAB_0013b509;
    }
  }
  scanFifteen = NAN;
  *one = NAN;
  *five = NAN;
LAB_0013b509:
  *fifteen = scanFifteen;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

