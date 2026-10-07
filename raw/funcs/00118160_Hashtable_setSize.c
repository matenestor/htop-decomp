/* Hashtable_setSize @ 00118160 size 237 */

/* DWARF original prototype: void Hashtable_setSize(Hashtable * this, size_t size) */

void Hashtable_setSize(Hashtable *this,size_t size)

{
  ulong uVar1;
  HashtableItem *__ptr;
  uint64_t *puVar2;
  HashtableItem *pHVar3;
  ulong uVar4;

                    /* Unresolved local var: size_t newSize@[???]
                       Unresolved local var: HashtableItem * oldBuckets@[???]
                       Unresolved local var: size_t oldSize@[???]
                       Unresolved local var: size_t i@[???] */
  puVar2 = OEISprimes;
  do {
    uVar4 = *puVar2;
    if (uVar4 == 0xffffffffffffffff) break;
    if (size <= uVar4) {
      uVar1 = this->size;
      if (uVar1 == uVar4) {
        return;
      }
                    /* Unresolved local var: void * data@[???] */
      this->size = uVar4;
      __ptr = this->buckets;
      if (uVar4 < 0xaaaaaaaaaaaaaab) {
        pHVar3 = calloc(uVar4,0x18);
        if (pHVar3 != (HashtableItem *)0x0) {
          this->buckets = pHVar3;
          this->items = 0;
                    /* Unresolved local var: size_t i@[???] */
          if (uVar1 != 0) {
            uVar4 = 0;
            pHVar3 = __ptr;
            do {
              if (pHVar3->value != (void *)0x0) {
                insert(this,pHVar3->key,pHVar3->value);
              }
              uVar4 = uVar4 + 1;
              pHVar3 = pHVar3 + 1;
            } while (uVar1 != uVar4);
          }
          free(__ptr);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 != (uint64_t *)&DAT_0014d238);
                    /* WARNING: Subroutine does not return */
  CRT_fatalError(((char *)0x1471e8 /* "Hashtable: no prime found" */));
}

