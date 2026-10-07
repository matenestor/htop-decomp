/* xMalloc @ 00130110 size 25 */

void * xMalloc(size_t size)

{
  void *pvVar1;

  pvVar1 = malloc(size);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

