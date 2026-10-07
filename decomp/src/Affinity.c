#include "htop.h"

/* Affinity_delete @ 0x115b60 */

void Affinity_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 0x10));
  free(param_1);
  return;
}


/* Affinity_rowGet @ 0x115b90 */

void Affinity_rowGet(long param_1,long param_2)

{
  FUN_00140160(*(__pid_t *)(param_1 + 0x10),param_2);
  return;
}


/* Affinity_rowSet @ 0x115fc0 */

undefined8 Affinity_rowSet(long param_1,long param_2)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 extraout_var;
  long lVar5;
  __cpu_mask *p_Var6;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x10)) = *(long *)(in_FS_OFFSET + 0x28);
  p_Var6 = (*(__cpu_mask (*)[17])(__fp - 0x98));
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *p_Var6 = 0;
    p_Var6 = p_Var6 + 1;
  }
  if (*(uint *)(param_2 + 0xc) != 0) {
    puVar4 = *(uint **)(param_2 + 0x10);
    puVar1 = puVar4 + *(uint *)(param_2 + 0xc);
    do {
      uVar2 = *puVar4;
      if (uVar2 < 0x400) {
        p_Var6 = (*(__cpu_mask (*)[17])(__fp - 0x98)) + (uVar2 >> 6);
        *p_Var6 = *p_Var6 | 1L << ((byte)uVar2 & 0x3f);
      }
      puVar4 = puVar4 + 1;
    } while (puVar4 != puVar1);
  }
  iVar3 = sched_setaffinity(*(__pid_t *)(param_1 + 0x10),8,(cpu_set_t *)(*(__cpu_mask (*)[17])(__fp - 0x98)));
  if ((*(long *)(__fp - 0x10)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return CONCAT71((int7)(CONCAT44(extraout_var,iVar3) >> 8),iVar3 == 0);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Affinity_new @ 0x117af0 */

undefined8 * Affinity_new(undefined8 param_1)

{
  undefined8 *puVar1;
  void *pvVar2;

  puVar1 = calloc(1,0x18);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 1) = 8;
    pvVar2 = calloc(8,4);
    if (pvVar2 != (void *)0x0) {
      puVar1[2] = pvVar2;
      *puVar1 = param_1;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Affinity_add @ 0x117b50 */

void Affinity_add(long param_1,undefined4 param_2)

{
  uint uVar1;
  void *__ptr;
  void *pvVar2;

  uVar1 = *(uint *)(param_1 + 0xc);
  __ptr = *(void **)(param_1 + 0x10);
  pvVar2 = __ptr;
  if (uVar1 == *(uint *)(param_1 + 8)) {
    *(uint *)(param_1 + 8) = uVar1 * 2;
    pvVar2 = realloc(__ptr,(ulong)(uVar1 * 2) * 4);
    if (pvVar2 == (void *)0x0) {
      free(__ptr);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(void **)(param_1 + 0x10) = pvVar2;
    uVar1 = *(uint *)(param_1 + 0xc);
  }
  *(undefined4 *)((long)pvVar2 + (ulong)uVar1 * 4) = param_2;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return;
}

