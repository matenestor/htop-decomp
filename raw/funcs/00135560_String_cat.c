/* String_cat @ 00135560 size 153 */

char * String_cat(char *s1,char *s2)

{
  size_t p2;
  size_t p2_00;
  char *p0;
  size_t __size;

  p2 = strlen(s1);
  p2_00 = strlen(s2);
  __size = p2 + p2_00 + 1;
                    /* Unresolved local var: void * data@[???] */
  p0 = malloc(__size);
  if (p0 != (char *)0x0) {
    __memcpy_chk(p0,s1,p2,__size);
    if (__size < p2) {
      __size = p2;
    }
    __memcpy_chk(p0 + p2,s2,p2_00,__size - p2);
    p0[p2 + p2_00] = '\0';
    return p0;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

