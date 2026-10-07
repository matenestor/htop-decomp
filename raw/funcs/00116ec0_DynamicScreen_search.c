/* DynamicScreen_search @ 00116ec0 size 136 */

_Bool DynamicScreen_search(Hashtable_2 *screens,char *name,ht_key_t *key)

{
  HashtableItem *pHVar1;
  int iVar2;
  HashtableItem *pHVar3;
  ht_key_t hVar4;
  _Bool local_39;

                    /* Unresolved local var: size_t i@[???] */
  if ((screens == (Hashtable_2 *)0x0) || (screens->size == 0)) {
    local_39 = false;
    hVar4 = 0;
  }
  else {
    pHVar3 = screens->buckets;
    local_39 = false;
    hVar4 = 0;
    pHVar1 = pHVar3 + screens->size;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
                    /* Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator.conflict1 * iter@[???] */
      if ((pHVar3->value != (char *)0x0) && (iVar2 = strcmp(name,pHVar3->value), iVar2 == 0)) {
        local_39 = true;
        hVar4 = pHVar3->key;
      }
      pHVar3 = pHVar3 + 1;
    } while (pHVar3 != pHVar1);
  }
  if (key != (ht_key_t *)0x0) {
    *key = hVar4;
  }
  return local_39;
}

