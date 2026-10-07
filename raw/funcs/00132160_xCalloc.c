/* xCalloc @ 00132160 size 33 */

void * xCalloc(size_t nmemb,size_t size)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  void *pvVar3;

  auVar1._8_8_ = 0;
  auVar1._0_8_ = size;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = nmemb;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    pvVar3 = calloc(nmemb,size);
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

