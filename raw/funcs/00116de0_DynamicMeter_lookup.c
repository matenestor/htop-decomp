/* DynamicMeter_lookup @ 00116de0 size 107 */

char * DynamicMeter_lookup(Hashtable_2 *dynamics,uint key)

{
  HashtableItem *pHVar1;
  HashtableItem *pHVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;

                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  pHVar1 = dynamics->buckets;
  uVar4 = (ulong)key % dynamics->size;
  pcVar5 = pHVar1[uVar4].value;
  if (pcVar5 != (char *)0x0) {
    uVar3 = 0;
    pHVar2 = pHVar1 + uVar4;
    do {
      while( true ) {
        if (key == pHVar2->key) {
          return pcVar5;
        }
        if (pHVar2->probe < uVar3) {
          return (char *)0x0;
        }
        uVar4 = uVar4 + 1;
        if (dynamics->size != uVar4) break;
        uVar4 = 0;
        uVar3 = uVar3 + 1;
        pcVar5 = pHVar1->value;
        pHVar2 = pHVar1;
        if (pcVar5 == (char *)0x0) {
          return (char *)0x0;
        }
      }
      uVar3 = uVar3 + 1;
      pHVar2 = pHVar1 + uVar4;
      pcVar5 = pHVar2->value;
    } while (pcVar5 != (char *)0x0);
  }
  return (char *)0x0;
}

