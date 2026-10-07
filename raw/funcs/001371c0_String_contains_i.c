/* String_contains_i @ 001371c0 size 292 */

_Bool String_contains_i(char *s1,char *s2,_Bool multi)

{
  char *pcVar1;
  char **__ptr;
  size_t sVar2;
  char **ppcVar3;
  long in_FS_OFFSET;
  _Bool _Var4;
  size_t nNeedles;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((!multi) || (pcVar1 = strchr(s2,0x7c), pcVar1 == (char *)0x0)) {
    pcVar1 = strcasestr(s1,s2);
    _Var4 = pcVar1 != (char *)0x0;
    goto LAB_00137291;
  }
                    /* Unresolved local var: char * * needles@[???] */
  __ptr = String_split(s2,'|',&nNeedles);
                    /* Unresolved local var: size_t i@[???] */
  if (nNeedles == 0) {
    if (__ptr != (char **)0x0) goto LAB_001372b8;
  }
  else {
    sVar2 = 0;
    do {
      pcVar1 = strcasestr(s1,__ptr[sVar2]);
      if (pcVar1 != (char *)0x0) {
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
        _Var4 = true;
        goto LAB_00137291;
      }
      sVar2 = sVar2 + 1;
    } while (sVar2 != nNeedles);
LAB_001372b8:
                    /* Unresolved local var: size_t i@[???] */
    pcVar1 = *__ptr;
    ppcVar3 = __ptr;
    while (pcVar1 != (char *)0x0) {
      ppcVar3 = ppcVar3 + 1;
      free(pcVar1);
      pcVar1 = *ppcVar3;
    }
    free(__ptr);
  }
  _Var4 = false;
LAB_00137291:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

