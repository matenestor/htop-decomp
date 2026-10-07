#include "htop.h"

/* DynamicColumn_name @ 0x116060 */

char * DynamicColumn_name(uint key)

{
  return (char *)0x0;
}


/* DynamicColumn_done @ 0x116be0 */

/* DWARF original prototype: void DynamicColumn_done(DynamicColumn * this) */

void DynamicColumn_done(DynamicColumn *this)

{
  free(this->heading);
  free(this->caption);
  free(this->description);
  return;
}


/* DynamicColumn_search @ 0x116c10 */

DynamicColumn_2 * DynamicColumn_search(Hashtable_2 *dynamics,char *name,uint *key)

{
  HashtableItem *pHVar1;
  DynamicColumn_2 *__s2;
  int iVar2;
  HashtableItem *pHVar3;
  DynamicColumn_2 *pDVar4;
  uint uVar5;

  if (dynamics == (Hashtable_2 *)0x0) {
    pDVar4 = (DynamicColumn_2 *)0x0;
    uVar5 = 0;
  }
  else {
                    /* Unresolved local var: size_t i@[???] */
    if (dynamics->size == 0) {
      uVar5 = 0;
      pDVar4 = (DynamicColumn_2 *)0x0;
    }
    else {
      pHVar3 = dynamics->buckets;
      uVar5 = 0;
      pDVar4 = (DynamicColumn_2 *)0x0;
      pHVar1 = pHVar3 + dynamics->size;
      do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
        __s2 = pHVar3->value;
        if (__s2 != (DynamicColumn_2 *)0x0) {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: DynamicIterator_conflict * iter@[???] */
          iVar2 = strcmp(name,__s2->name);
          if (iVar2 == 0) {
            uVar5 = pHVar3->key;
            pDVar4 = __s2;
          }
        }
        pHVar3 = pHVar3 + 1;
      } while (pHVar3 != pHVar1);
    }
  }
  if (key != (uint *)0x0) {
    *key = uVar5;
  }
  return pDVar4;
}


/* DynamicColumn_lookup @ 0x116cc0 */

DynamicColumn_2 * DynamicColumn_lookup(Hashtable_2 *dynamics,uint key)

{
  HashtableItem *pHVar1;
  HashtableItem *pHVar2;
  ulong uVar3;
  ulong uVar4;
  DynamicColumn_2 *pDVar5;

                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  pHVar1 = dynamics->buckets;
  uVar4 = (ulong)key % dynamics->size;
  pDVar5 = pHVar1[uVar4].value;
  if (pDVar5 != (DynamicColumn_2 *)0x0) {
    uVar3 = 0;
    pHVar2 = pHVar1 + uVar4;
    do {
      while( true ) {
        if (key == pHVar2->key) {
          return pDVar5;
        }
        if (pHVar2->probe < uVar3) {
          return (DynamicColumn_2 *)0x0;
        }
        uVar4 = uVar4 + 1;
        if (dynamics->size != uVar4) break;
        uVar4 = 0;
        uVar3 = uVar3 + 1;
        pDVar5 = pHVar1->value;
        pHVar2 = pHVar1;
        if (pDVar5 == (DynamicColumn_2 *)0x0) {
          return (DynamicColumn_2 *)0x0;
        }
      }
      uVar3 = uVar3 + 1;
      pHVar2 = pHVar1 + uVar4;
      pDVar5 = pHVar2->value;
    } while (pDVar5 != (DynamicColumn_2 *)0x0);
  }
  return (DynamicColumn_2 *)0x0;
}


/* DynamicColumn_writeField @ 0x116d40 */

_Bool DynamicColumn_writeField(Process_2 *proc,RichString *str,uint key)

{
  return false;
}


/* DynamicColumns_delete @ 0x1174a0 */

void DynamicColumns_delete(Hashtable_2 *dynamics)

{
  if (dynamics != (Hashtable_2 *)0x0) {
    Hashtable_clear(dynamics);
    free(dynamics->buckets);
    free(dynamics);
    return;
  }
  return;
}


/* DynamicColumns_new @ 0x117dd0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

Hashtable_2 * DynamicColumns_new(void)

{
  Hashtable_2 *pHVar1;
  HashtableItem *pHVar2;

                    /* Unresolved local var: Hashtable * this@[???]
                       Unresolved local var: void * data@[???] */
  pHVar1 = malloc(0x20);
  if (pHVar1 != (Hashtable_2 *)0x0) {
    pHVar1->items = 0;
                    /* Unresolved local var: void * data@[???] */
    pHVar1->size = 0xd;
    pHVar2 = calloc(0xd,0x18);
    if (pHVar2 != (HashtableItem *)0x0) {
      pHVar1->buckets = pHVar2;
      pHVar1->owner = true;
      return pHVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

