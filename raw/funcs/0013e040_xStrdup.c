/* xStrdup @ 0013e040 size 25 */

char * xStrdup(char *str)

{
  char *pcVar1;

  pcVar1 = strdup(str);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

