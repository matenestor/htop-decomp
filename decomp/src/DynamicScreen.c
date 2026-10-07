#include "htop.h"

/* DynamicScreens_new @ 0x116e60 */

undefined8 DynamicScreens_new(void)

{
  return 0;
}


/* DynamicScreen_done @ 0x116e70 */

/* DWARF original prototype: void DynamicScreen_done(DynamicScreen * this) */

void DynamicScreen_done(DynamicScreen *this)

{
  free(this->caption);
  free(this->fields);
  free(this->heading);
  free(this->sortKey);
  free(this->columnKeys);
  return;
}


/* DynamicScreen_search @ 0x116ec0 */

_Bool DynamicScreen_search(Hashtable_2 *screens,char *name,ht_key_t *key)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  HashtableItem *pHVar1;
  int iVar2;
  HashtableItem *pHVar3;
  ht_key_t hVar4;

                    /* Unresolved local var: size_t i@[???] */
  if ((screens == (Hashtable_2 *)0x0) || (screens->size == 0)) {
    (*(_Bool (*))(__fp - 0x39)) = false;
    hVar4 = 0;
  }
  else {
    pHVar3 = screens->buckets;
    (*(_Bool (*))(__fp - 0x39)) = false;
    hVar4 = 0;
    pHVar1 = pHVar3 + screens->size;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
                    /* Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator_conflict1 * iter@[???] */
      if ((pHVar3->value != (char *)0x0) && (iVar2 = strcmp(name,pHVar3->value), iVar2 == 0)) {
        (*(_Bool (*))(__fp - 0x39)) = true;
        hVar4 = pHVar3->key;
      }
      pHVar3 = pHVar3 + 1;
    } while (pHVar3 != pHVar1);
  }
  if (key != (ht_key_t *)0x0) {
    *key = hVar4;
  }
  return (*(_Bool (*))(__fp - 0x39));
}


/* DynamicScreen_lookup @ 0x116f50 */

long DynamicScreen_lookup(ulong *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;

  puVar1 = (uint *)param_1[1];
  uVar4 = (ulong)param_2 % *param_1;
  lVar5 = *(long *)(puVar1 + uVar4 * 6 + 4);
  if (lVar5 != 0) {
    uVar3 = 0;
    puVar2 = puVar1 + uVar4 * 6;
    do {
      while( true ) {
        if (param_2 == *puVar2) {
          return lVar5;
        }
        if (*(ulong *)(puVar2 + 2) < uVar3) {
          return 0;
        }
        uVar4 = uVar4 + 1;
        if (*param_1 != uVar4) break;
        uVar4 = 0;
        uVar3 = uVar3 + 1;
        lVar5 = *(long *)(puVar1 + 4);
        puVar2 = puVar1;
        if (lVar5 == 0) {
          return 0;
        }
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar1 + uVar4 * 6;
      lVar5 = *(long *)(puVar2 + 4);
    } while (lVar5 != 0);
  }
  return 0;
}


/* DynamicScreens_delete @ 0x117520 */

void DynamicScreens_delete(Hashtable *param_1)

{
  if (param_1 != (Hashtable *)0x0) {
    Hashtable_clear(param_1);
    free(param_1->buckets);
    free(param_1);
    return;
  }
  return;
}

