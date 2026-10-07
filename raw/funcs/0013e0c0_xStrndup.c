/* xStrndup @ 0013e0c0 size 25 */

char * xStrndup(char *str,size_t len)

{
  char *pcVar1;

  pcVar1 = strndup(str,len);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

