/* String_freeArray @ 0012e100 size 62 */

void String_freeArray(char **s)

{
  char *__ptr;
  char **ppcVar1;

  if (s != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
    __ptr = *s;
    ppcVar1 = s;
    while (__ptr != (char *)0x0) {
      ppcVar1 = ppcVar1 + 1;
      free(__ptr);
      __ptr = *ppcVar1;
    }
    free(s);
    return;
  }
  return;
}

