/* String_readLine @ 001372f0 size 233 */

char * String_readLine(FILE *fd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  char *__ptr;

                    /* Unresolved local var: void * data@[???] */
  pcVar2 = malloc(0x401);
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0x401;
    uVar5 = 0x400;
    __ptr = pcVar2;
    while( true ) {
                    /* Unresolved local var: size_t sz@[???] */
      pcVar3 = __fgets_chk(pcVar2,uVar4,0x401,fd);
      if (pcVar3 == (char *)0x0) {
        free(__ptr);
        return (char *)0x0;
      }
                    /* Unresolved local var: char * ok@[???]
                       Unresolved local var: char * newLine@[???] */
      pcVar2 = strrchr(pcVar2,10);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
        return __ptr;
      }
      iVar1 = feof((FILE_2 *)fd);
      if (iVar1 != 0) {
        return __ptr;
      }
      uVar4 = uVar5 + 0x401;
                    /* Unresolved local var: void * data@[???] */
      pcVar3 = realloc(__ptr,uVar4);
      if (pcVar3 == (char *)0x0) break;
      pcVar2 = pcVar3 + uVar5;
      if (uVar4 < uVar5) {
        uVar4 = uVar5;
      }
      uVar4 = uVar4 - uVar5;
      uVar5 = uVar5 + 0x400;
      __ptr = pcVar3;
    }
    free(__ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

