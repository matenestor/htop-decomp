/* xReallocArrayZero @ 00132e40 size 150 */

void * xReallocArrayZero(void *ptr,size_t prevmemb,size_t newmemb,size_t size)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  size_t __size;
  void *pvVar3;
  ulong uVar4;

  if (prevmemb == newmemb) {
    return ptr;
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = newmemb;
                    /* Unresolved local var: void * ret@[???] */
  auVar2._8_8_ = 0;
  auVar2._0_8_ = size;
  __size = SUB168(auVar1 * auVar2,0);
  if (SUB168(auVar1 * auVar2,8) == 0) {
                    /* Unresolved local var: void * data@[???] */
    pvVar3 = realloc(ptr,__size);
    if (pvVar3 != (void *)0x0) {
      if (newmemb <= prevmemb) {
        return pvVar3;
      }
      uVar4 = prevmemb * size;
      if (__size <= uVar4) {
        __size = uVar4;
      }
      __memset_chk((void *)(uVar4 + (long)pvVar3),0,(newmemb - prevmemb) * size,__size - uVar4);
      return pvVar3;
    }
    free(ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

