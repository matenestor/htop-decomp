#include "htop.h"

/* ScreenNameListItem_new @ 0x132410 */

undefined8 * ScreenNameListItem_new(char *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = ScreenNameListItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined4 *)(puVar1 + 2) = 0;
      *(undefined1 *)((long)puVar1 + 0x14) = 0;
      puVar1[3] = param_2;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00132480 @ 0x132480 */

void FUN_00132480(long param_1,uint param_2)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  undefined8 *__ptr;
  long lVar1;
  long lVar2;
  ulong *puVar3;
  void *pvVar4;
  char *pcVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  ulong __nmemb;
  undefined8 *puVar9;
  ulong *puVar10;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*)[2])(__fp - 0x40))[0] = *(long *)(in_FS_OFFSET + 0x28);
  (*(uint *)((char *)&(*(undefined8 *)(__fp - 0x48)) + 0)) = 3;
  uVar6 = 0;
  (*(uint *)((char *)&(*(undefined8 *)(__fp - 0x48)) + 4)) = (param_2 - 5 < 0x7c) + 3;
  if ((&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] != '\0') {
    do {
      lVar2 = *(long *)(param_1 + 0x10) + uVar6 * 0x18;
      __ptr = *(undefined8 **)(lVar2 + 8);
      if (__ptr != (undefined8 *)0x0) {
        pvVar4 = (void *)*__ptr;
        puVar9 = __ptr;
        while (pvVar4 != (void *)0x0) {
          puVar9 = puVar9 + 1;
          free(pvVar4);
          pvVar4 = (void *)*puVar9;
        }
        free(__ptr);
        lVar2 = *(long *)(param_1 + 0x10) + uVar6 * 0x18;
      }
      uVar6 = uVar6 + 1;
      free(*(void **)(lVar2 + 0x10));
    } while (uVar6 < (byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18]);
  }
  free(*(void **)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0xc) = 0;
  puVar3 = calloc(2,0x18);
  if (puVar3 == (ulong *)0x0) goto LAB_0013266f;
  *(ulong **)(param_1 + 0x10) = puVar3;
  plVar7 = &(*(undefined8 *)(__fp - 0x48));
  puVar10 = puVar3;
  do {
    __nmemb = (ulong)(int)*plVar7;
    uVar6 = (ulong)((int)*plVar7 + 1);
    if ((((0x1fffffffffffffff < uVar6) || (pvVar4 = calloc(uVar6,8), pvVar4 == (void *)0x0)) ||
        (puVar10[1] = (ulong)pvVar4, 0x3fffffffffffffff < __nmemb)) ||
       (pvVar4 = calloc(__nmemb,4), pvVar4 == (void *)0x0)) goto LAB_0013266f;
    puVar10[2] = (ulong)pvVar4;
    plVar7 = (long *)((long)plVar7 + 4);
    *puVar10 = __nmemb;
    puVar10 = puVar10 + 3;
  } while (plVar7 != (*(long (*)[2])(__fp - 0x40)));
  plVar7 = (long *)puVar3[1];
  if (param_2 < 0x81) {
    if (param_2 < 0x21) {
      if (param_2 < 0x11) {
        if (param_2 < 9) {
          if (param_2 < 5) {
            pcVar5 = strdup(((char *)(long)&s_AllCPUs_00147a94 /* "AllCPUs" */));
            goto joined_r0x001327ef;
          }
          pcVar5 = strdup(((char *)(long)&s_LeftCPUs_00147ad2 /* "LeftCPUs" */));
          if (pcVar5 == (char *)0x0) goto LAB_0013266f;
          *plVar7 = (long)pcVar5;
          plVar7 = *(long **)(*(long *)(param_1 + 0x10) + 0x20);
          **(undefined4 **)(*(long *)(param_1 + 0x10) + 0x10) = 1;
          pcVar5 = strdup(((char *)(long)&s_RightCPUs_00147ae6 /* "RightCPUs" */));
        }
        else {
          pcVar5 = strdup(((char *)(long)&s_LeftCPUs2_00147afb /* "LeftCPUs2" */));
          if (pcVar5 == (char *)0x0) goto LAB_0013266f;
          *plVar7 = (long)pcVar5;
          plVar7 = *(long **)(*(long *)(param_1 + 0x10) + 0x20);
          **(undefined4 **)(*(long *)(param_1 + 0x10) + 0x10) = 1;
          pcVar5 = strdup(((char *)(long)&s_RightCPUs2_00147b12 /* "RightCPUs2" */));
        }
      }
      else {
        pcVar5 = strdup(((char *)(long)&s_LeftCPUs4_00147b44 /* "LeftCPUs4" */));
        if (pcVar5 == (char *)0x0) goto LAB_0013266f;
        *plVar7 = (long)pcVar5;
        plVar7 = *(long **)(*(long *)(param_1 + 0x10) + 0x20);
        **(undefined4 **)(*(long *)(param_1 + 0x10) + 0x10) = 1;
        pcVar5 = strdup(((char *)(long)&s_RightCPUs4_00147b5b /* "RightCPUs4" */));
      }
    }
    else {
      pcVar5 = strdup(((char *)(long)&s_LeftCPUs8_00147b89 /* "LeftCPUs8" */));
      if (pcVar5 == (char *)0x0) goto LAB_0013266f;
      *plVar7 = (long)pcVar5;
      plVar7 = *(long **)(*(long *)(param_1 + 0x10) + 0x20);
      **(undefined4 **)(*(long *)(param_1 + 0x10) + 0x10) = 1;
      pcVar5 = strdup(((char *)(long)&s_RightCPUs8_00147ba1 /* "RightCPUs8" */));
    }
    if (pcVar5 == (char *)0x0) goto LAB_0013266f;
    *plVar7 = (long)pcVar5;
    lVar2 = *(long *)(param_1 + 0x10);
    lVar8 = 1;
    **(undefined4 **)(lVar2 + 0x28) = 1;
  }
  else {
    pcVar5 = strdup(((char *)(long)(__sec_rodata + 0x826) /* "CPU" */));
joined_r0x001327ef:
    if (pcVar5 == (char *)0x0) goto LAB_0013266f;
    *plVar7 = (long)pcVar5;
    lVar2 = *(long *)(param_1 + 0x10);
    lVar8 = 0;
    **(undefined4 **)(lVar2 + 0x10) = 1;
  }
  lVar2 = *(long *)(lVar2 + 8);
  pcVar5 = strdup(((char *)(long)&s_Memory_001479d0 /* "Memory" */));
  if (pcVar5 != (char *)0x0) {
    *(char **)(lVar2 + 8) = pcVar5;
    lVar2 = *(long *)(*(long *)(param_1 + 0x10) + 8);
    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x10) + 4) = 1;
    pcVar5 = strdup(((char *)(long)(__sec_rodata + 0x9c7) /* "Swap" */));
    if (pcVar5 != (char *)0x0) {
      *(char **)(lVar2 + 0x10) = pcVar5;
      lVar2 = lVar8 * 8;
      lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 0x20);
      *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x10) + 8) = 1;
      pcVar5 = strdup(((char *)(long)&s_Tasks_00147965 /* "Tasks" */));
      if (pcVar5 != (char *)0x0) {
        *(char **)(lVar1 + lVar2) = pcVar5;
        lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 0x20);
        *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x28) + lVar8 * 4) = 2;
        pcVar5 = strdup(((char *)(long)&s_LoadAverage_001479db /* "LoadAverage" */));
        if (pcVar5 != (char *)0x0) {
          *(char **)(lVar1 + 8 + lVar2) = pcVar5;
          lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 0x20);
          *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x28) + 4 + lVar8 * 4) = 2;
          pcVar5 = strdup(((char *)(long)&s_Uptime_00147955 /* "Uptime" */));
          if (pcVar5 != (char *)0x0) {
            *(char **)(lVar1 + 0x10 + lVar2) = pcVar5;
            *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x28) + 8 + lVar8 * 4) = 2;
            if ((*(long (*)[2])(__fp - 0x40))[0] != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
            return;
          }
        }
      }
    }
  }
LAB_0013266f:
                    /* WARNING: Subroutine does not return */
  fail();
}

