/* free_and_xStrdup @ 0013e060 size 83 */

void free_and_xStrdup(char **ptr,char *str)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = *ptr;
  if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,str), iVar1 == 0)) {
    return;
  }
  free(pcVar2);
                    /* Unresolved local var: char * data@[???] */
  pcVar2 = strdup(str);
  if (pcVar2 != (char *)0x0) {
    *ptr = pcVar2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

