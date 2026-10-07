/* String_startsWith @ 00116180 size 49 */

_Bool String_startsWith(char *s,char *match)

{
  int iVar1;
  size_t __n;

  __n = strlen(match);
  iVar1 = strncmp(s,match,__n);
  return iVar1 == 0;
}

