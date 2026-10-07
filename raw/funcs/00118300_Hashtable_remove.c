/* Hashtable_remove @ 00118300 size 367 */

/* DWARF original prototype: void * Hashtable_remove(Hashtable * this, ht_key_t key) */

void * Hashtable_remove(Hashtable *this,ht_key_t key)

{
  HashtableItem *pHVar1;
  size_t sVar2;
  ulong uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  HashtableItem *pHVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  HashtableItem *pHVar12;
  size_t sVar13;
  void *pvVar14;
  void *pvVar15;

  uVar9 = this->size;
  pHVar12 = this->buckets;
  uVar10 = (ulong)key % uVar9;
  pHVar8 = pHVar12 + uVar10;
  pvVar14 = pHVar8->value;
  if (pvVar14 != (void *)0x0) {
    uVar11 = 0;
    do {
      if (pHVar8->key == key) {
                    /* Unresolved local var: size_t next@[???] */
        pvVar15 = pvVar14;
        if (this->owner != false) {
          pvVar15 = (void *)0x0;
          free(pvVar14);
          pHVar12 = this->buckets;
          uVar9 = this->size;
        }
        uVar11 = (uVar10 + 1) % uVar9;
        pHVar8 = pHVar12 + uVar11;
        pvVar14 = pHVar8->value;
        goto joined_r0x001183a0;
      }
      if (pHVar8->probe < uVar11) {
        sVar13 = this->items;
        pvVar14 = (void *)0x0;
        goto LAB_00118417;
      }
      uVar11 = uVar11 + 1;
      uVar10 = (uVar10 + 1) % uVar9;
      pHVar8 = pHVar12 + uVar10;
      pvVar14 = pHVar8->value;
    } while (pvVar14 != (void *)0x0);
  }
  sVar13 = this->items;
LAB_00118417:
                    /* Unresolved local var: size_t newSize@[???]
                       Unresolved local var: HashtableItem * oldBuckets@[???]
                       Unresolved local var: size_t oldSize@[???] */
  if ((sVar13 * 8 < uVar9) && (sVar13 < uVar9 / 3)) {
    Hashtable_setSize(this,uVar9 / 3);
  }
  return pvVar14;
joined_r0x001183a0:
  uVar3 = uVar11;
  if (pvVar14 == (void *)0x0) goto LAB_001183ff;
  sVar13 = pHVar8->probe;
  pHVar1 = pHVar12 + uVar10;
  if (sVar13 == 0) goto LAB_001183ff;
  bVar4 = pHVar8->field_0x4;
  bVar5 = pHVar8->field_0x5;
  bVar6 = pHVar8->field_0x6;
  bVar7 = pHVar8->field_0x7;
  sVar2 = pHVar8->probe;
  pHVar1->key = pHVar8->key;
  pHVar1->field_0x4 = bVar4;
  pHVar1->field_0x5 = bVar5;
  pHVar1->field_0x6 = bVar6;
  pHVar1->field_0x7 = bVar7;
  pHVar1->probe = sVar2;
  pvVar14 = pHVar8->value;
  pHVar1->probe = sVar13 - 1;
  pHVar1->value = pvVar14;
  uVar11 = (uVar3 + 1) % uVar9;
  pHVar8 = pHVar12 + uVar11;
  pvVar14 = pHVar8->value;
  uVar10 = uVar3;
  goto joined_r0x001183a0;
LAB_001183ff:
  sVar13 = this->items;
  pHVar12[uVar10].value = (void *)0x0;
  sVar13 = sVar13 - 1;
  this->items = sVar13;
  pvVar14 = pvVar15;
  goto LAB_00118417;
}

