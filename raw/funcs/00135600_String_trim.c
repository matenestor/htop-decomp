/* String_trim @ 00135600 size 118 */

char * String_trim(char *in)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  size_t __n;

  cVar1 = *in;
  if (1 < (byte)(cVar1 - 9U)) goto LAB_00135630;
  do {
    do {
      cVar1 = in[1];
      in = in + 1;
    } while ((byte)(cVar1 - 9U) < 2);
LAB_00135630:
  } while (cVar1 == ' ');
  sVar2 = strlen(in);
  do {
    while( true ) {
      __n = sVar2;
      if (__n == 0) goto LAB_00135665;
      cVar1 = in[__n - 1];
      sVar2 = __n - 1;
      if (cVar1 < '\v') break;
      if (cVar1 != ' ') goto LAB_00135665;
    }
  } while ('\b' < cVar1);
LAB_00135665:
                    /* Unresolved local var: char * data@[???] */
  pcVar3 = strndup(in,__n);
  if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  return pcVar3;
}

