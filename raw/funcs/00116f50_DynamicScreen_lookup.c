/* DynamicScreen_lookup @ 00116f50 size 107 */

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

