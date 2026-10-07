/* DynamicMeter_getUiName @ 0011c510 size 250 */

/* DWARF original prototype: void DynamicMeter_getUiName(Meter * this, char * name, size_t length)
    */

void DynamicMeter_getUiName(Meter *this,char *name,size_t length)

{
  Hashtable_2 *pHVar1;
  ulong uVar2;
  HashtableItem *pHVar3;
  char *__s;
  HashtableItem *pHVar4;
  size_t sVar5;
  int va0;
  ulong uVar6;
  ulong uVar7;
  void *va0_00;

                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  pHVar1 = this->host->settings->dynamicMeters;
  uVar2 = pHVar1->size;
  pHVar3 = pHVar1->buckets;
  uVar7 = (ulong)this->param % uVar2;
  va0_00 = pHVar3[uVar7].value;
  if (va0_00 != (void *)0x0) {
    uVar6 = 0;
    pHVar4 = pHVar3 + uVar7;
    do {
      while( true ) {
        if (this->param == pHVar4->key) {
                    /* Unresolved local var: char * uiName@[???] */
          __s = *(char **)((long)va0_00 + 0x20);
          if (__s == (char *)0x0) {
            xSnprintf(name,length,((char *)0x147626 /* "%s" */),va0_00);
            return;
          }
                    /* Unresolved local var: wchar_t len@[???] */
          sVar5 = strlen(__s);
          va0 = (int)sVar5;
          if ((2 < va0) && (__s[(long)va0 + -2] == ':')) {
            va0 = va0 + -2;
          }
          xSnprintf(name,length,((char *)0x1474a5 /* "%.*s" */),va0,__s);
          return;
        }
        if (pHVar4->probe < uVar6) {
          return;
        }
        uVar7 = uVar7 + 1;
        if (uVar2 != uVar7) break;
        uVar7 = 0;
        uVar6 = uVar6 + 1;
        va0_00 = pHVar3->value;
        pHVar4 = pHVar3;
        if (va0_00 == (void *)0x0) {
          return;
        }
      }
      uVar6 = uVar6 + 1;
      pHVar4 = pHVar3 + uVar7;
      va0_00 = pHVar4->value;
    } while (va0_00 != (void *)0x0);
  }
  return;
}

