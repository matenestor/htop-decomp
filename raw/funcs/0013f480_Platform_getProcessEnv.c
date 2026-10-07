/* Platform_getProcessEnv @ 0013f480 size 304 */

char * Platform_getProcessEnv(pid_t pid)

{
  long lVar1;
  FILE_2 *__stream;
  void *__ptr;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  void *__ptr_00;
  ulong __size;
  long in_FS_OFFSET;
  char procname [128];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf(procname,0x80,((char *)0x149be4 /* "/proc/%d/environ" */),pid);
  __stream = fopen(procname,((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    uVar2 = 0;
    uVar4 = 0;
    __size = 0;
    __ptr_00 = (void *)0x0;
    do {
      __size = __size + 0x1000;
                    /* Unresolved local var: void * data@[???] */
      uVar4 = uVar4 + uVar2;
      __ptr = realloc(__ptr_00,__size);
      if (__ptr == (void *)0x0) {
        free(__ptr_00);
                    /* WARNING: Subroutine does not return */
        fail();
      }
                    /* Unresolved local var: size_t sz@[???] */
      uVar2 = __size;
      if (__size <= uVar4) {
        uVar2 = uVar4;
      }
      uVar2 = __fread_chk((void *)((long)__ptr + uVar4),uVar2 - uVar4,1,__size - uVar4,__stream);
      __ptr_00 = __ptr;
    } while (0 < (long)uVar2);
    fclose(__stream);
    if (uVar2 == 0) {
                    /* Unresolved local var: void * data@[???] */
      pcVar3 = realloc(__ptr,uVar4 + 2);
      if (pcVar3 == (char *)0x0) {
        free(__ptr);
                    /* WARNING: Subroutine does not return */
        fail();
      }
      (pcVar3 + uVar4)[0] = '\0';
      (pcVar3 + uVar4)[1] = '\0';
      goto LAB_0013f564;
    }
    free(__ptr);
  }
  pcVar3 = (char *)0x0;
LAB_0013f564:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

