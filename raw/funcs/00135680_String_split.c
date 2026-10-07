/* String_split @ 00135680 size 281 */

char ** String_split(char *s,char sep,size_t *n)

{
  void *__ptr;
  char *pcVar1;
  char *pcVar2;
  void *pvVar3;
  char **ppcVar4;
  size_t sVar5;
  size_t local_40;

                    /* Unresolved local var: void * data@[???] */
  __ptr = calloc(10,8);
  if (__ptr != (void *)0x0) {
    local_40 = 10;
    sVar5 = 0;
    while (pcVar1 = strchr(s,(int)sep), pcVar1 != (char *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pcVar2 = strndup(s,(long)pcVar1 - (long)s);
      if (pcVar2 == (char *)0x0) goto LAB_001357a3;
      *(char **)((long)__ptr + sVar5 * 8) = pcVar2;
      sVar5 = sVar5 + 1;
      pvVar3 = __ptr;
      if (local_40 == sVar5) {
        local_40 = local_40 + 10;
                    /* Unresolved local var: void * data@[???] */
        pvVar3 = realloc(__ptr,local_40 * 8);
        if (pvVar3 == (void *)0x0) goto LAB_0013579b;
      }
                    /* Unresolved local var: size_t size@[???] */
      s = s + ((long)pcVar1 - (long)s) + 1;
      __ptr = pvVar3;
    }
    if (*s != '\0') {
                    /* Unresolved local var: char * data@[???] */
      pcVar1 = strdup(s);
      if (pcVar1 == (char *)0x0) goto LAB_001357a3;
      *(char **)((long)__ptr + sVar5 * 8) = pcVar1;
      sVar5 = sVar5 + 1;
    }
                    /* Unresolved local var: void * data@[???] */
    ppcVar4 = realloc(__ptr,sVar5 * 8 + 8);
    if (ppcVar4 != (char **)0x0) {
      ppcVar4[sVar5] = (char *)0x0;
      if (n != (size_t *)0x0) {
        *n = sVar5;
      }
      return ppcVar4;
    }
LAB_0013579b:
    free(__ptr);
  }
LAB_001357a3:
                    /* WARNING: Subroutine does not return */
  fail();
}

