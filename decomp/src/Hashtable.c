#include "htop.h"

/* insert @ 0x114570 */

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


/* Hashtable_get @ 0x1159a0 */

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


/* Hashtable_foreach @ 0x115ba0 */

/* DWARF original prototype: void Hashtable_foreach(Hashtable * this, Hashtable_PairFunction f, void
   * userData) */

void Hashtable_foreach(Hashtable *this,Hashtable_PairFunction f,void *userData)

{
  void *pvVar1;
  long in_RCX;
  ulong uVar2;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: size_t i@[???] */
  if (this->size != 0) {
    uVar2 = 0;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
      pvVar1 = this->buckets[uVar2].value;
      if (pvVar1 != (void *)0x0) {
        (*(code *)(f))(this->buckets[uVar2].key,pvVar1,userData,in_RCX,in_R8,in_R9);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < this->size);
    return;
  }
  return;
}


/* Hashtable_clear @ 0x117400 */

/* DWARF original prototype: void Hashtable_clear(Hashtable * this) */

void Hashtable_clear(Hashtable *this)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;

                    /* Unresolved local var: size_t i@[???] */
  uVar1 = this->size;
  if ((this->owner != false) && (uVar1 != 0)) {
    uVar2 = 0;
    do {
      uVar3 = uVar2 + 1;
      free(this->buckets[uVar2].value);
      uVar1 = this->size;
      uVar2 = uVar3;
    } while (uVar3 < uVar1);
  }
  memset(this->buckets,0,uVar1 * 0x18);
  this->items = 0;
  return;
}


/* Hashtable_delete @ 0x117470 */

/* DWARF original prototype: void Hashtable_delete(Hashtable * this) */

void Hashtable_delete(Hashtable *this)

{
  Hashtable_clear(this);
  free(this->buckets);
  free(this);
  return;
}


/* Hashtable_new @ 0x1180a0 */

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
      CRT_fatalError(((char *)(long)&s_Hashtable__no_prime_found_001471e8 /* "Hashtable: no prime found" */));
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


/* Hashtable_setSize @ 0x118160 */

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
  CRT_fatalError(((char *)(long)&s_Hashtable__no_prime_found_001471e8 /* "Hashtable: no prime found" */));
}


/* Hashtable_setSize_118260 @ 0x118260 */

/* DWARF original prototype: void Hashtable_setSize(Hashtable * this, size_t size) */

void __thiscall Hashtable_setSize_118260(void *this,size_t size)

{
  if (size <= *(ulong *)((long)this + 0x10)) {
    return;
  }
  Hashtable_setSize(this,size);
  return;
}


/* Hashtable_put @ 0x118280 */

/* DWARF original prototype: void Hashtable_put(Hashtable * this, ht_key_t key, void * value) */

void Hashtable_put(Hashtable *this,ht_key_t key,void *value)

{
  size_t sVar1;

  sVar1 = this->size;
  if (sVar1 * 7 < this->items * 10) {
    if ((long)sVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      CRT_fatalError(((char *)(long)&s_Hashtable__size_overflow_00147202 /* "Hashtable: size overflow" */));
    }
                    /* Unresolved local var: size_t newSize@[???]
                       Unresolved local var: HashtableItem * oldBuckets@[???]
                       Unresolved local var: size_t oldSize@[???] */
    if (this->items < sVar1 * 2) {
      Hashtable_setSize(this,sVar1 * 2);
    }
  }
  insert(this,key,value);
  return;
}


/* Hashtable_remove @ 0x118300 */

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

