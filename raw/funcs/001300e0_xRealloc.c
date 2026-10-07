/* xRealloc @ 001300e0 size 45 */

void * xRealloc(void *ptr,size_t size)

{
  void *pvVar1;

  pvVar1 = realloc(ptr,size);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
  free(ptr);
                    /* WARNING: Subroutine does not return */
  fail();
}

