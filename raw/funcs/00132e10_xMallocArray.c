/* xMallocArray @ 00132e10 size 36 */

void * xMallocArray(size_t nmemb,size_t size)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  void *pvVar3;

  auVar1._8_8_ = 0;
  auVar1._0_8_ = size;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = nmemb;
  if (SUB168(auVar1 * auVar2,8) == 0) {
                    /* Unresolved local var: void * data@[???] */
    pvVar3 = malloc(SUB168(auVar1 * auVar2,0));
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

