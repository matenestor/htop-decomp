/* Platform_getFileDescriptors @ 0013c450 size 279 */

void Platform_getFileDescriptors(double *used,double *max)

{
  int iVar1;
  FILE_2 *__stream;
  long in_FS_OFFSET;
  ulonglong v3;
  ulonglong v2;
  ulonglong v1;
  long local_30;

  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *used = NAN;
  *max = 65536.0;
  __stream = fopen(((char *)0x1499f1 /* "/proc/sys/fs/file-nr" */),((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)0x149a06 /* "%llu %llu %llu" */),&v1,&v2,&v3);
    if (iVar1 == 3) {
      if ((long)v1 < 0) {
        *used = (double)v1;
      }
      else {
        *used = (double)(long)v1;
      }
      *max = (double)v3;
    }
    fclose(__stream);
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

