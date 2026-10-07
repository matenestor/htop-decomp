/* Platform_getPressureStall @ 0013ccc0 size 260 */

void Platform_getPressureStall(char *file,_Bool some,double *ten,double *sixty,double *threehundred)

{
  long lVar1;
  FILE_2 *__stream;
  long in_FS_OFFSET;
  char procname [128];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  *threehundred = 0.0;
  *sixty = 0.0;
  *ten = 0.0;
  xSnprintf(procname,0x80,((char *)0x149a90 /* "/proc/pressure/%s" */),file);
  __stream = fopen(procname,((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    *threehundred = NAN;
    *sixty = NAN;
    *ten = NAN;
  }
  else {
    __isoc23_fscanf(__stream,((char *)0x14cac0 /* "some avg10=%32lf avg60=%32lf avg300=%32lf total=%*f " */),ten,sixty,
                    threehundred);
    if (!some) {
      __isoc23_fscanf(__stream,((char *)0x14caf8 /* "full avg10=%32lf avg60=%32lf avg300=%32lf total=%*f " */),ten,sixty,
                      threehundred);
    }
    fclose(__stream);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

