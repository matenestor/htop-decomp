#include "htop.h"

/* DynamicScreen_done @ 0x116e70 */

void DynamicScreen_done(long param_1)

{
  free(*(void **)(param_1 + 0x28));
  free(*(void **)(param_1 + 0x30));
  free(*(void **)(param_1 + 0x20));
  free(*(void **)(param_1 + 0x38));
  free(*(void **)(param_1 + 0x40));
  return;
}


/* DynamicScreen_search @ 0x116ec0 */

undefined1 DynamicScreen_search(long *param_1,char *param_2,undefined4 *param_3)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;

  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    (*(undefined1 *)(__fp - 0x39)) = 0;
    uVar4 = 0;
  }
  else {
    puVar3 = (undefined4 *)param_1[1];
    (*(undefined1 *)(__fp - 0x39)) = 0;
    uVar4 = 0;
    puVar1 = puVar3 + *param_1 * 6;
    do {
      if ((*(char **)(puVar3 + 4) != (char *)0x0) &&
         (iVar2 = strcmp(param_2,*(char **)(puVar3 + 4)), iVar2 == 0)) {
        (*(undefined1 *)(__fp - 0x39)) = 1;
        uVar4 = *puVar3;
      }
      puVar3 = puVar3 + 6;
    } while (puVar3 != puVar1);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar4;
  }
  return (*(undefined1 *)(__fp - 0x39));
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

