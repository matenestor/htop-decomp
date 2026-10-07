/* DynamicColumn_search @ 00116c10 size 151 */

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
                       Unresolved local var: DynamicIterator.conflict * iter@[???] */
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

