#include "htop.h"

/* String_startsWith @ 0x116180 */

_Bool String_startsWith(char *s,char *match)

{
  int iVar1;
  size_t __n;

  __n = strlen(match);
  iVar1 = strncmp(s,match,__n);
  return iVar1 == 0;
}

