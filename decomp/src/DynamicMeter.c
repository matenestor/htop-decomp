#include "htop.h"

/* DynamicMeter_init @ 0x114060 */

void DynamicMeter_init(Meter_3 *meter)

{
  return;
}


/* DynamicMeter_updateValues_lto_priv_0 @ 0x114270 */

void DynamicMeter_updateValues_lto_priv_0(void)

{
  return;
}


/* DynamicMeter_display @ 0x114280 */

void DynamicMeter_display(Meter_ *cast,RichString *out)

{
  return;
}


/* DynamicMeter_getCaption @ 0x114290 */

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


/* DynamicMeters_new @ 0x116070 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

Hashtable_2 * DynamicMeters_new(void)

{
  return (Hashtable_2 *)0x0;
}


/* DynamicMeter_search @ 0x116d50 */

_Bool DynamicMeter_search(Hashtable_2 *dynamics,char *name,uint *key)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  HashtableItem *pHVar1;
  int iVar2;
  HashtableItem *pHVar3;
  uint uVar4;

                    /* Unresolved local var: size_t i@[???] */
  if ((dynamics == (Hashtable_2 *)0x0) || (dynamics->size == 0)) {
    (*(_Bool (*))(__fp - 0x39)) = false;
    uVar4 = 0;
  }
  else {
    pHVar3 = dynamics->buckets;
    (*(_Bool (*))(__fp - 0x39)) = false;
    uVar4 = 0;
    pHVar1 = pHVar3 + dynamics->size;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
                    /* Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator_conflict1 * iter@[???] */
      if ((pHVar3->value != (char *)0x0) && (iVar2 = strcmp(name,pHVar3->value), iVar2 == 0)) {
        (*(_Bool (*))(__fp - 0x39)) = true;
        uVar4 = pHVar3->key;
      }
      pHVar3 = pHVar3 + 1;
    } while (pHVar3 != pHVar1);
  }
  if (key != (uint *)0x0) {
    *key = uVar4;
  }
  return (*(_Bool (*))(__fp - 0x39));
}


/* DynamicMeter_lookup @ 0x116de0 */

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


/* DynamicMeters_delete @ 0x1174e0 */

void DynamicMeters_delete(Hashtable *param_1)

{
  if (param_1 != (Hashtable *)0x0) {
    Hashtable_clear(param_1);
    free(param_1->buckets);
    free(param_1);
    return;
  }
  return;
}


/* DynamicMeter_getUiName @ 0x11c510 */

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
            xSnprintf(name,length,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),va0_00);
            return;
          }
                    /* Unresolved local var: int len@[???] */
          sVar5 = strlen(__s);
          va0 = (int)sVar5;
          if ((2 < va0) && (__s[(long)va0 + -2] == ':')) {
            va0 = va0 + -2;
          }
          xSnprintf(name,length,((char *)(long)&DAT_001474a5 /* "%.*s" */),va0,__s);
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

