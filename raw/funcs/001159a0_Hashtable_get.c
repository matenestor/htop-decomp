/* Hashtable_get @ 001159a0 size 107 */

/* DWARF original prototype: void * Hashtable_get(Hashtable * this, ht_key_t key) */

void * Hashtable_get(Hashtable *this,ht_key_t key)

{
  HashtableItem *pHVar1;
  HashtableItem *pHVar2;
  ulong uVar3;
  ulong uVar4;
  void *pvVar5;

  pHVar1 = this->buckets;
  uVar4 = (ulong)key % this->size;
  pvVar5 = pHVar1[uVar4].value;
  if (pvVar5 != (void *)0x0) {
    uVar3 = 0;
    pHVar2 = pHVar1 + uVar4;
    do {
      while( true ) {
        if (pHVar2->key == key) {
          return pvVar5;
        }
        if (pHVar2->probe < uVar3) {
          return (void *)0x0;
        }
        uVar4 = uVar4 + 1;
        if (this->size != uVar4) break;
        uVar4 = 0;
        uVar3 = uVar3 + 1;
        pvVar5 = pHVar1->value;
        pHVar2 = pHVar1;
        if (pvVar5 == (void *)0x0) {
          return (void *)0x0;
        }
      }
      uVar3 = uVar3 + 1;
      pHVar2 = pHVar1 + uVar4;
      pvVar5 = pHVar2->value;
    } while (pvVar5 != (void *)0x0);
  }
  return (void *)0x0;
}

