/* DynamicMeter_search @ 00116d50 size 136 */

_Bool DynamicMeter_search(Hashtable_2 *dynamics,char *name,uint *key)

{
  HashtableItem *pHVar1;
  int iVar2;
  HashtableItem *pHVar3;
  uint uVar4;
  _Bool local_39;

                    /* Unresolved local var: size_t i@[???] */
  if ((dynamics == (Hashtable_2 *)0x0) || (dynamics->size == 0)) {
    local_39 = false;
    uVar4 = 0;
  }
  else {
    pHVar3 = dynamics->buckets;
    local_39 = false;
    uVar4 = 0;
    pHVar1 = pHVar3 + dynamics->size;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
                    /* Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator.conflict1 * iter@[???] */
      if ((pHVar3->value != (char *)0x0) && (iVar2 = strcmp(name,pHVar3->value), iVar2 == 0)) {
        local_39 = true;
        uVar4 = pHVar3->key;
      }
      pHVar3 = pHVar3 + 1;
    } while (pHVar3 != pHVar1);
  }
  if (key != (uint *)0x0) {
    *key = uVar4;
  }
  return local_39;
}

