/* DynamicMeter_getCaption @ 00114290 size 134 */

/* DWARF original prototype: char * DynamicMeter_getCaption(Meter * this) */

char * DynamicMeter_getCaption(Meter *this)

{
  Hashtable_2 *pHVar1;
  ulong uVar2;
  HashtableItem *pHVar3;
  HashtableItem *pHVar4;
  char *pcVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;

                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  pHVar1 = this->host->settings->dynamicMeters;
  uVar2 = pHVar1->size;
  pHVar3 = pHVar1->buckets;
  uVar7 = (ulong)this->param % uVar2;
  pcVar8 = pHVar3[uVar7].value;
  if (pcVar8 != (char *)0x0) {
    uVar6 = 0;
    pHVar4 = pHVar3 + uVar7;
    do {
      while( true ) {
        if (this->param == pHVar4->key) {
          pcVar5 = *(char **)(pcVar8 + 0x20);
          if (*(char **)(pcVar8 + 0x20) == (char *)0x0) {
            pcVar5 = pcVar8;
          }
          return pcVar5;
        }
        if (pHVar4->probe < uVar6) goto LAB_0011430b;
        uVar7 = uVar7 + 1;
        if (uVar2 != uVar7) break;
        uVar7 = 0;
        uVar6 = uVar6 + 1;
        pcVar8 = pHVar3->value;
        pHVar4 = pHVar3;
        if (pcVar8 == (char *)0x0) goto LAB_0011430b;
      }
      uVar6 = uVar6 + 1;
      pHVar4 = pHVar3 + uVar7;
      pcVar8 = pHVar4->value;
    } while (pcVar8 != (char *)0x0);
  }
LAB_0011430b:
  return this->caption;
}

