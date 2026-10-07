/* insert @ 00114570 size 209 */

/* DWARF original prototype: void insert(Hashtable * this, ht_key_t key, void * value) */

void insert(Hashtable *this,ht_key_t key,void *value)

{
  HashtableItem *pHVar1;
  uint uVar2;
  ulong uVar3;
  HashtableItem *pHVar4;
  void *__ptr;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;

                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???] */
  uVar8 = (ulong)key;
  uVar7 = 0;
  uVar3 = this->size;
  pHVar4 = this->buckets;
  uVar6 = uVar8 % uVar3;
  pHVar1 = pHVar4 + uVar6;
  __ptr = pHVar1->value;
  while( true ) {
    if (__ptr == (void *)0x0) {
      this->items = this->items + 1;
      pHVar1->key = key;
      pHVar1->probe = uVar7;
      pHVar1->value = value;
      return;
    }
    uVar2 = pHVar1->key;
    if (uVar2 == (uint)uVar8) break;
    uVar5 = pHVar1->probe;
    if (uVar5 < uVar7) {
                    /* Unresolved local var: HashtableItem tmp@[???] */
      pHVar1->key = (uint)uVar8;
      pHVar1->probe = uVar7;
      pHVar1->value = value;
      uVar7 = uVar5;
      uVar8 = (ulong)uVar2;
      value = __ptr;
    }
    key = (ht_key_t)uVar8;
    uVar7 = uVar7 + 1;
    uVar6 = (uVar6 + 1) % uVar3;
    pHVar1 = pHVar4 + uVar6;
    __ptr = pHVar1->value;
  }
  if ((__ptr == value) || (this->owner == false)) {
    pHVar4[uVar6].value = value;
  }
  else {
    free(__ptr);
    this->buckets[uVar6].value = value;
  }
  return;
}

