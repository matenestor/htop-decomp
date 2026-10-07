/* Hashtable_new @ 001180a0 size 183 */

Hashtable * Hashtable_new(size_t size,_Bool owner)

{
  Hashtable *pHVar1;
  uint64_t *puVar2;
  HashtableItem *pHVar3;
  ulong __nmemb;

                    /* Unresolved local var: void * data@[???] */
  pHVar1 = malloc(0x20);
  if (pHVar1 != (Hashtable *)0x0) {
    pHVar1->items = 0;
    puVar2 = OEISprimes;
    if (size != 0) {
      do {
        __nmemb = *puVar2;
        if (__nmemb == 0xffffffffffffffff) break;
        if (size <= __nmemb) {
          pHVar1->size = __nmemb;
          if (0xaaaaaaaaaaaaaaa < __nmemb) goto LAB_0011814a;
          goto LAB_001180f5;
        }
                    /* Unresolved local var: size_t i@[???] */
        puVar2 = puVar2 + 1;
      } while (puVar2 != (uint64_t *)&DAT_0014d238);
                    /* WARNING: Subroutine does not return */
      CRT_fatalError(((char *)0x1471e8 /* "Hashtable: no prime found" */));
    }
    pHVar1->size = 0xd;
                    /* Unresolved local var: void * data@[???] */
    __nmemb = 0xd;
LAB_001180f5:
    pHVar3 = calloc(__nmemb,0x18);
    if (pHVar3 != (HashtableItem *)0x0) {
      pHVar1->buckets = pHVar3;
      pHVar1->owner = owner;
      return pHVar1;
    }
  }
LAB_0011814a:
                    /* WARNING: Subroutine does not return */
  fail();
}

