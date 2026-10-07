#include "htop.h"

/* DynamicColumn_name @ 0x116060 */

undefined8 DynamicColumn_name(void)

{
  return 0;
}


/* DynamicColumn_done @ 0x116be0 */

void DynamicColumn_done(long param_1)

{
  free(*(void **)(param_1 + 0x20));
  free(*(void **)(param_1 + 0x28));
  free(*(void **)(param_1 + 0x30));
  return;
}


/* DynamicColumn_search @ 0x116c10 */

char * DynamicColumn_search(long *param_1,char *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  char *__s2;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;

  if (param_1 == (long *)0x0) {
    pcVar4 = (char *)0x0;
    uVar5 = 0;
  }
  else if (*param_1 == 0) {
    uVar5 = 0;
    pcVar4 = (char *)0x0;
  }
  else {
    puVar3 = (undefined4 *)param_1[1];
    uVar5 = 0;
    pcVar4 = (char *)0x0;
    puVar1 = puVar3 + *param_1 * 6;
    do {
      __s2 = *(char **)(puVar3 + 4);
      if (__s2 != (char *)0x0) {
        iVar2 = strcmp(param_2,__s2);
        if (iVar2 == 0) {
          uVar5 = *puVar3;
          pcVar4 = __s2;
        }
      }
      puVar3 = puVar3 + 6;
    } while (puVar3 != puVar1);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar5;
  }
  return pcVar4;
}


/* DynamicColumn_lookup @ 0x116cc0 */

long DynamicColumn_lookup(ulong *param_1,uint param_2)

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


/* DynamicColumn_writeField @ 0x116d40 */

undefined8 DynamicColumn_writeField(void)

{
  return 0;
}

