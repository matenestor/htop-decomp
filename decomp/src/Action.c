#include "htop.h"

/* Action_follow @ 0x113f20 */

undefined8 Action_follow(long *param_1)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;

  lVar1 = param_1[1];
  uVar3 = 0xffffffff;
  if ((0 < (int)(*(long **)(lVar1 + 0x20))[3]) &&
     (lVar2 = *(long *)(**(long **)(lVar1 + 0x20) + (long)*(int *)(lVar1 + 0x28) * 8), lVar2 != 0))
  {
    uVar3 = *(undefined4 *)(lVar2 + 0x10);
  }
  *(undefined4 *)(*(long *)(*param_1 + 0xa8) + 0x34) = uVar3;
  *(undefined4 *)(lVar1 + 0x26d8) = 10;
  return 8;
}


/* FUN_00113f70 @ 0x113f70 */

undefined8 FUN_00113f70(long param_1)

{
  byte *pbVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;

  lVar3 = *(long *)(param_1 + 8);
  iVar2 = (int)(*(long **)(lVar3 + 0x20))[3];
  if (0 < iVar2) {
    iVar5 = *(int *)(lVar3 + 0x28);
    lVar4 = *(long *)(**(long **)(lVar3 + 0x20) + (long)iVar5 * 8);
    if (lVar4 != 0) {
      pbVar1 = (byte *)(lVar4 + 0x1d);
      *pbVar1 = *pbVar1 ^ 1;
      iVar5 = iVar5 + 1;
      if (iVar5 < 0) {
        *(undefined4 *)(lVar3 + 0x28) = 0;
        *(undefined1 *)(lVar3 + 0x48) = 1;
        return 0;
      }
      if (iVar5 < iVar2) {
        *(int *)(lVar3 + 0x28) = iVar5;
        return 0;
      }
      *(undefined1 *)(lVar3 + 0x48) = 1;
      *(int *)(lVar3 + 0x28) = iVar2 + -1;
    }
  }
  return 0;
}


/* FUN_00113fd0 @ 0x113fd0 */

undefined8 FUN_00113fd0(long param_1)

{
  *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) ^ 1;
  return 0x21;
}


/* FUN_00113fe0 @ 0x113fe0 */

undefined8 FUN_00113fe0(long param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long *plVar4;

  plVar4 = *(long **)(*(long *)(param_1 + 8) + 0x20);
  iVar2 = (int)plVar4[3];
  if (0 < iVar2) {
    plVar4 = (long *)*plVar4;
    plVar1 = plVar4 + iVar2;
    do {
      lVar3 = *plVar4;
      plVar4 = plVar4 + 1;
      *(undefined1 *)(lVar3 + 0x1d) = 0;
    } while (plVar4 != plVar1);
  }
  return 1;
}


/* FUN_00114020 @ 0x114020 */

undefined8 FUN_00114020(long param_1)

{
  long lVar1;
  long lVar2;

  lVar1 = *(long *)(param_1 + 8);
  if ((0 < (int)(*(long **)(lVar1 + 0x20))[3]) &&
     (lVar2 = *(long *)(**(long **)(lVar1 + 0x20) + (long)*(int *)(lVar1 + 0x28) * 8), lVar2 != 0))
  {
    FUN_001139b0(lVar1,lVar2);
    return 0;
  }
  return 0;
}


/* FUN_00114060 @ 0x114060 */

void FUN_00114060(void)

{
  return;
}


/* FUN_00114070 @ 0x114070 */

void FUN_00114070(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long *plVar1;
  byte bVar2;
  uint uVar3;
  long *a0;
  ulong uVar4;
  ulong a3;
  ulong a2;
  ulong extraout_RDX;
  long *plVar5;

  plVar5 = *(long **)((uint *)param_1[0x2e] + 2);
  uVar3 = *(uint *)param_1[0x2e];
  a3 = (ulong)(int)uVar3;
  bVar2 = **(byte **)(*param_1 + 0x70);
  a2 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar4 = (ulong)(uVar3 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar3 >> 1);
    if (bVar2 != 0x52) {
      uVar4 = a3;
    }
  }
  if (0 < (int)uVar4) {
    plVar1 = plVar5 + uVar4;
    do {
      a0 = (long *)*plVar5;
      plVar5 = plVar5 + 1;
      (**(code **)(*a0 + 0x38))((long)a0,param_rsi,a2,a3,param_r8,param_r9);
      a2 = extraout_RDX;
    } while (plVar1 != plVar5);
  }
  return;
}


/* FUN_001140e0 @ 0x1140e0 */

void FUN_001140e0(long *param_1,int param_2,int param_3,int param_4,int param_5,long param_r9)

{
  long *plVar1;
  long a0;
  long lVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_register_00000084;
  int iVar8;
  int iVar9;
  ulong uVar10;

  plVar1 = *(long **)((uint *)param_1[0x2e] + 2);
  uVar6 = *(uint *)param_1[0x2e];
  if (**(char **)(*param_1 + 0x70) == 'L') {
    uVar6 = uVar6 + 1 >> 1;
  }
  else if (**(char **)(*param_1 + 0x70) == 'R') {
    uVar6 = uVar6 >> 1;
  }
  uVar7 = (param_4 - param_5) / param_5 + 1;
  iVar8 = param_4 - param_5 * uVar7;
  iVar9 = (int)((uVar6 - 1) + param_5) / param_5;
  if (0 < (int)uVar6) {
    uVar10 = 0;
    do {
      a0 = plVar1[uVar10];
      lVar2 = (long)iVar9;
      uVar3 = (ulong)(uint)((int)uVar10 >> 0x1f) << 0x20 | uVar10 & 0xffffffff;
      iVar4 = (int)((long)uVar3 / lVar2);
      iVar5 = iVar4;
      if (iVar8 < iVar4) {
        iVar5 = iVar8;
      }
      uVar10 = uVar10 + 1;
      (**(code **)(a0 + 8))
                (a0,(ulong)(iVar4 * uVar7 + param_2 + iVar5),
                 (ulong)(uint)((int)((long)uVar3 % lVar2) * *(int *)(*plVar1 + 0x48) + param_3),
                 (ulong)uVar7,CONCAT44(in_register_00000084,param_5),param_r9);
    } while ((long)(int)uVar6 != uVar10);
  }
  return;
}


/* FUN_001141b0 @ 0x1141b0 */

void FUN_001141b0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  FUN_001140e0(param_1,param_2,param_3,param_4,2,param_r9);
  return;
}


/* FUN_001141c0 @ 0x1141c0 */

void FUN_001141c0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  FUN_001140e0(param_1,param_2,param_3,param_4,4,param_r9);
  return;
}


/* FUN_001141d0 @ 0x1141d0 */

void FUN_001141d0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  FUN_001140e0(param_1,param_2,param_3,param_4,8,param_r9);
  return;
}


/* FUN_001141e0 @ 0x1141e0 */

void FUN_001141e0(long *param_1,uint param_2,int param_3,uint param_4,long param_r8,long param_r9)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;

  plVar2 = *(long **)((uint *)param_1[0x2e] + 2);
  uVar1 = *(uint *)param_1[0x2e];
  if (**(char **)(*param_1 + 0x70) == 'L') {
    uVar3 = (ulong)(uVar1 + 1 >> 1);
  }
  else {
    uVar3 = (ulong)(uVar1 >> 1);
    if (**(char **)(*param_1 + 0x70) != 'R') {
      uVar3 = (long)(int)uVar1;
    }
  }
  if (0 < (int)uVar3) {
    plVar4 = plVar2;
    do {
      plVar5 = plVar4 + 1;
      (**(code **)(*plVar4 + 8))
                (*plVar4,(ulong)param_2,(ulong)(uint)param_3,(ulong)param_4,param_r8,param_r9);
      param_3 = param_3 + *(int *)(*plVar4 + 0x48);
      plVar4 = plVar5;
    } while (plVar5 != plVar2 + uVar3);
  }
  return;
}


/* FUN_00114270 @ 0x114270 */

void FUN_00114270(void)

{
  return;
}


/* FUN_00114280 @ 0x114280 */

void FUN_00114280(void)

{
  return;
}


/* FUN_00114290 @ 0x114290 */

long FUN_00114290(long param_1)

{
  ulong *puVar1;
  ulong uVar2;
  uint *puVar3;
  uint *puVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;

  puVar1 = *(ulong **)(**(long **)(param_1 + 0x10) + 0x20);
  uVar2 = *puVar1;
  puVar3 = (uint *)puVar1[1];
  uVar7 = (ulong)*(uint *)(param_1 + 0x24) % uVar2;
  lVar8 = *(long *)(puVar3 + uVar7 * 6 + 4);
  if (lVar8 != 0) {
    uVar6 = 0;
    puVar4 = puVar3 + uVar7 * 6;
    do {
      while( true ) {
        if (*(uint *)(param_1 + 0x24) == *puVar4) {
          lVar5 = *(long *)(lVar8 + 0x20);
          if (*(long *)(lVar8 + 0x20) == 0) {
            lVar5 = lVar8;
          }
          return lVar5;
        }
        if (*(ulong *)(puVar4 + 2) < uVar6) goto LAB_0011430b;
        uVar7 = uVar7 + 1;
        if (uVar2 != uVar7) break;
        uVar7 = 0;
        uVar6 = uVar6 + 1;
        lVar8 = *(long *)(puVar3 + 4);
        puVar4 = puVar3;
        if (lVar8 == 0) goto LAB_0011430b;
      }
      uVar6 = uVar6 + 1;
      puVar4 = puVar3 + uVar7 * 6;
      lVar8 = *(long *)(puVar4 + 4);
    } while (lVar8 != 0);
  }
LAB_0011430b:
  return *(long *)(param_1 + 0x18);
}


/* FUN_00114320 @ 0x114320 */

void FUN_00114320(long *param_1,int param_2,int param_3,long param_rcx,long param_r8)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  undefined8 *puVar1;
  uint uVar2;
  code *a5;
  long lVar3;
  uint uVar4;
  ulong a3;
  undefined8 *extraout_RDX;
  undefined8 *a2;
  undefined8 *extraout_RDX_00;
  long lVar5;
  long *a0;
  undefined8 *puVar6;

  (*(uint *)(__fp - 0x3c)) = *(uint *)param_1[0x2e];
  a2 = *(undefined8 **)((uint *)param_1[0x2e] + 2);
  *(int *)(param_1 + 4) = param_2;
  uVar2 = *(uint *)(*(long *)(Meter_modes + (long)param_2 * 8) + 0x10);
  if (**(char **)(*param_1 + 0x70) == 'L') {
    uVar4 = uVar2;
    (*(uint *)(__fp - 0x3c)) = (*(uint *)(__fp - 0x3c)) + 1 >> 1;
  }
  else {
    uVar4 = (*(uint *)(__fp - 0x3c)) >> 1;
    if (**(char **)(*param_1 + 0x70) == 'R') {
      (*(uint *)(__fp - 0x3c)) = uVar4;
    }
  }
  a3 = (ulong)uVar4;
  if (0 < (int)(*(uint *)(__fp - 0x3c))) {
    puVar1 = a2 + (int)(*(uint *)(__fp - 0x3c));
    puVar6 = a2;
    do {
      while( true ) {
        a0 = (long *)*puVar6;
        if (0 < param_2) break;
        lVar5 = *a0;
        a3 = 1;
        if (param_2 != 0) {
          a3 = (ulong)(uint)param_2;
        }
        uVar4 = (uint)a3;
        if (*(int *)(lVar5 + 0x58) == 0) goto LAB_001143b9;
LAB_00114401:
        puVar6 = puVar6 + 1;
        free((void *)a0[8]);
        a0[8] = 0;
        a0[7] = 0;
        lVar5 = **(long **)(Meter_modes + (long)(int)uVar4 * 8);
        lVar3 = (*(long **)(Meter_modes + (long)(int)uVar4 * 8))[2];
        *(uint *)(a0 + 4) = uVar4;
        a0[1] = lVar5;
        *(int *)(a0 + 9) = (int)lVar3;
        a2 = extraout_RDX_00;
        if (puVar1 == puVar6) goto LAB_00114449;
      }
      while (param_2 == (int)a0[4]) {
        puVar6 = puVar6 + 1;
        if (puVar1 == puVar6) goto LAB_00114449;
        a0 = (long *)*puVar6;
      }
      lVar5 = *a0;
      uVar4 = param_2;
      if (*(int *)(lVar5 + 0x58) != 0) goto LAB_00114401;
LAB_001143b9:
      a5 = *(code **)(lVar5 + 0x30);
      a0[1] = *(long *)(lVar5 + 0x40);
      if (a5 != (code *)0x0) {
        (*a5)((long)a0,(ulong)uVar4,(long)a2,a3,param_r8,(long)a5);
        a2 = extraout_RDX;
      }
      puVar6 = puVar6 + 1;
      *(uint *)(a0 + 4) = uVar4;
    } while (puVar1 != puVar6);
  }
LAB_00114449:
  *(uint *)(param_1 + 9) = ((int)(((*(uint *)(__fp - 0x3c)) - 1) + param_3) / param_3) * uVar2;
  return;
}


/* FUN_001144a0 @ 0x1144a0 */

void FUN_001144a0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8)

{
  FUN_00114320(param_1,param_2,1,param_rcx,param_r8);
  return;
}


/* FUN_001144b0 @ 0x1144b0 */

void FUN_001144b0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8)

{
  FUN_00114320(param_1,param_2,2,param_rcx,param_r8);
  return;
}


/* FUN_001144c0 @ 0x1144c0 */

void FUN_001144c0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8)

{
  FUN_00114320(param_1,param_2,4,param_rcx,param_r8);
  return;
}


/* FUN_001144d0 @ 0x1144d0 */

void FUN_001144d0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8)

{
  FUN_00114320(param_1,param_2,8,param_rcx,param_r8);
  return;
}


/* FUN_001144e0 @ 0x1144e0 */

void FUN_001144e0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined8 *puVar1;
  byte bVar2;
  uint uVar3;
  uint *__ptr;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong extraout_RDX;
  undefined8 *__ptr_00;

  __ptr = (uint *)param_1[0x2e];
  __ptr_00 = *(undefined8 **)(__ptr + 2);
  uVar3 = *__ptr;
  uVar6 = (ulong)(int)uVar3;
  bVar2 = **(byte **)(*param_1 + 0x70);
  uVar7 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar5 = (ulong)(uVar3 + 1 >> 1);
  }
  else {
    uVar5 = (ulong)(uVar3 >> 1);
    if (bVar2 != 0x52) {
      uVar5 = uVar6;
    }
  }
  if (0 < (int)uVar5) {
    puVar1 = __ptr_00 + uVar5;
    do {
      plVar4 = (long *)*__ptr_00;
      __ptr_00 = __ptr_00 + 1;
      Meter_delete(plVar4,param_rsi,uVar7,uVar6,param_r8,param_r9);
      uVar7 = extraout_RDX;
    } while (__ptr_00 != puVar1);
    __ptr_00 = *(undefined8 **)(__ptr + 2);
  }
  free(__ptr_00);
  free(__ptr);
  return;
}


/* FUN_00114570 @ 0x114570 */

void FUN_00114570(ulong *param_1,uint param_2,void *param_3)

{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  void *__ptr;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;

  uVar9 = (ulong)param_2;
  uVar8 = 0;
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar6 = uVar9 % uVar3;
  lVar7 = uVar6 * 0x18;
  puVar1 = (uint *)(uVar4 + lVar7);
  __ptr = *(void **)(puVar1 + 4);
  while( true ) {
    if (__ptr == (void *)0x0) {
      param_1[2] = param_1[2] + 1;
      *puVar1 = param_2;
      *(ulong *)(puVar1 + 2) = uVar8;
      *(void **)(puVar1 + 4) = param_3;
      return;
    }
    uVar2 = *puVar1;
    if (uVar2 == (uint)uVar9) break;
    uVar5 = *(ulong *)(puVar1 + 2);
    if (uVar5 < uVar8) {
      *puVar1 = (uint)uVar9;
      *(ulong *)(puVar1 + 2) = uVar8;
      *(void **)(puVar1 + 4) = param_3;
      uVar8 = uVar5;
      uVar9 = (ulong)uVar2;
      param_3 = __ptr;
    }
    param_2 = (uint)uVar9;
    uVar8 = uVar8 + 1;
    uVar6 = (uVar6 + 1) % uVar3;
    lVar7 = uVar6 * 0x18;
    puVar1 = (uint *)(uVar4 + lVar7);
    __ptr = *(void **)(puVar1 + 4);
  }
  if ((__ptr == param_3) || ((char)param_1[3] == '\0')) {
    *(void **)(uVar4 + 0x10 + lVar7) = param_3;
  }
  else {
    free(__ptr);
    *(void **)(param_1[1] + 0x10 + lVar7) = param_3;
  }
  return;
}


/* FUN_00114650 @ 0x114650 */

char FUN_00114650(undefined8 *param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  byte bVar7;
  char cVar8;

  cVar8 = '\0';
  if ((CHAR____0015c0d9 == '\0') &&
     (cVar8 = '\0', *(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0)) {
    lVar2 = param_1[1];
    plVar5 = *(long **)(lVar2 + 0x20);
    if (0 < (int)plVar5[3]) {
      lVar6 = 0;
      bVar7 = 1;
      cVar8 = '\0';
      do {
        lVar3 = *(long *)(*plVar5 + lVar6 * 8);
        cVar1 = *(char *)(lVar3 + 0x1d);
        if (cVar1 != '\0') {
          bVar4 = FUN_00122f10(lVar3,*(int *)(lVar3 + 200) + -1);
          bVar7 = bVar7 & bVar4;
          plVar5 = *(long **)(lVar2 + 0x20);
          cVar8 = cVar1;
        }
        lVar6 = lVar6 + 1;
      } while ((int)lVar6 < (int)plVar5[3]);
      if (((cVar8 != '\x01') && (0 < (int)plVar5[3])) &&
         (lVar2 = *(long *)(*plVar5 + (long)*(int *)(lVar2 + 0x28) * 8), lVar2 != 0)) {
        bVar4 = FUN_00122f10(lVar2,*(int *)(lVar2 + 200) + -1);
        bVar7 = bVar7 & bVar4;
      }
      if (bVar7 == 0) {
        beep();
      }
    }
  }
  return cVar8;
}


/* FUN_00114740 @ 0x114740 */

char FUN_00114740(undefined8 *param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  byte bVar7;
  char cVar8;

  cVar8 = '\0';
  if ((CHAR____0015c0d9 == '\0') &&
     (cVar8 = '\0', *(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0)) {
    lVar2 = param_1[1];
    plVar5 = *(long **)(lVar2 + 0x20);
    if (0 < (int)plVar5[3]) {
      lVar6 = 0;
      bVar7 = 1;
      cVar8 = '\0';
      do {
        lVar3 = *(long *)(*plVar5 + lVar6 * 8);
        cVar1 = *(char *)(lVar3 + 0x1d);
        if (cVar1 != '\0') {
          bVar4 = FUN_00122f10(lVar3,*(int *)(lVar3 + 200) + 1);
          bVar7 = bVar7 & bVar4;
          plVar5 = *(long **)(lVar2 + 0x20);
          cVar8 = cVar1;
        }
        lVar6 = lVar6 + 1;
      } while ((int)lVar6 < (int)plVar5[3]);
      if (((cVar8 != '\x01') && (0 < (int)plVar5[3])) &&
         (lVar2 = *(long *)(*plVar5 + (long)*(int *)(lVar2 + 0x28) * 8), lVar2 != 0)) {
        bVar4 = FUN_00122f10(lVar2,*(int *)(lVar2 + 200) + 1);
        bVar7 = bVar7 & bVar4;
      }
      if (bVar7 == 0) {
        beep();
      }
    }
  }
  return cVar8;
}


/* FUN_00114830 @ 0x114830 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00114830(void)

{
  wclear(_stdscr);
  return 0x23;
}


/* FUN_00114850 @ 0x114850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00114850(undefined8 *param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  char *pcVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;

  iVar8 = 0;
  wclear(_stdscr);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x11c));
  if (1 < _LINES) {
    do {
      iVar3 = wmove(_stdscr,iVar8,0);
      if (iVar3 != -1) {
        whline(_stdscr,0x20,_COLS);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < _LINES + -1);
  }
  iVar8 = wmove(_stdscr,0,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_htop_3_3_0____C__2004_2019_Hisha_0014a288 /* "htop 3.3.0 - (C) 2004-2019 Hisham Muhammad. (C) 2020-2024 htop dev team." */),-1);
  }
  iVar8 = wmove(_stdscr,1,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x32d8) /* "Released under the GNU GPLv2+. See \'man\' page for more info." */),-1);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  iVar8 = wmove(_stdscr,3,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_CPU_usage_bar__0014702c /* "CPU usage bar: " */),-1);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  waddnstr(_stdscr,((char *)(long)&DAT_0014703c /* "[" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&DAT_00149c0c /* "" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 300));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x217) /* "low" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x130));
  waddnstr(_stdscr,((char *)(long)&s_normal_0014703e /* "normal" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x134));
  waddnstr(_stdscr,((char *)(long)&s_kernel_00147045 /* "kernel" */),-1);
  if (*(char *)(*(long *)*param_1 + 0x51) == '\0') {
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 0x148));
    waddnstr(_stdscr,((char *)(long)&s_guest_0014705b /* "guest" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    pcVar7 = ((char *)(long)&DAT_001470cc /* "                  " */);
  }
  else {
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 0x13c));
    waddnstr(_stdscr,((char *)(long)&DAT_00147051 /* "irq" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 0x140));
    waddnstr(_stdscr,((char *)(long)&DAT_0014704c /* "soft-irq" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 0x144));
    waddnstr(_stdscr,((char *)(long)&s_steal_00147055 /* "steal" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 0x148));
    waddnstr(_stdscr,((char *)(long)&s_guest_0014705b /* "guest" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 0x138));
    waddnstr(_stdscr,((char *)(long)&s_io_wait_00147061 /* "io-wait" */),-1);
    wattrset(_stdscr,*(int *)(CRT_colors + 4));
    pcVar7 = ((char *)(long)&DAT_001470dd /* " " */);
  }
  waddnstr(_stdscr,pcVar7,-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xc0));
  waddnstr(_stdscr,((char *)(long)&s_used__00147069 /* "used%" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  waddnstr(_stdscr,((char *)(long)&DAT_00149a61 /* "]" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  iVar8 = wmove(_stdscr,4,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Memory_bar__0014706f /* "Memory bar:    " */),-1);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  waddnstr(_stdscr,((char *)(long)&DAT_0014703c /* "[" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&DAT_00149c0c /* "" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xcc));
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xdc));
  waddnstr(_stdscr,((char *)(long)&s_shared_00147084 /* "shared" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xe0));
  waddnstr(_stdscr,((char *)(long)&s_compressed_0014708b /* "compressed" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xd4));
  waddnstr(_stdscr,((char *)(long)&s_buffers_00147096 /* "buffers" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xd8));
  waddnstr(_stdscr,((char *)(long)&s_cache_0014709e /* "cache" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&DAT_001470d4 /* "          " */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xc0));
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xc0));
  waddnstr(_stdscr,((char *)(long)&s_total_001470a4 /* "total" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  waddnstr(_stdscr,((char *)(long)&DAT_00149a61 /* "]" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  iVar8 = wmove(_stdscr,5,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Swap_bar__001470aa /* "Swap bar:      " */),-1);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  waddnstr(_stdscr,((char *)(long)&DAT_0014703c /* "[" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&DAT_00149c0c /* "" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x68));
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x6c));
  waddnstr(_stdscr,((char *)(long)&s_cache_0014709e /* "cache" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x70));
  waddnstr(_stdscr,((char *)(long)&s_frontswap_001470ba /* "frontswap" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&DAT_001470c4 /* "                          " */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xc0));
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xc0));
  waddnstr(_stdscr,((char *)(long)&s_total_001470a4 /* "total" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  waddnstr(_stdscr,((char *)(long)&DAT_00149a61 /* "]" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  iVar8 = wmove(_stdscr,7,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Type_and_layout_of_header_meters_0014a318 /* "Type and layout of header meters are configurable in the setup screen." */),-1);
  }
  if ((CRT_colorScheme == 1) && (iVar8 = wmove(_stdscr,8,0), iVar8 != -1)) {
    waddnstr(_stdscr,((char *)(long)&s_In_monochrome__meters_display_as_0014a360 /* "In monochrome, meters display as different chars, in order: |#*@$%&." */),-1);
  }
  iVar8 = wmove(_stdscr,9,0);
  if (iVar8 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Process_state__001470df /* "Process state: " */),-1);
  }
  pbVar9 = &DAT_00156388;
  iVar8 = 0;
  pcVar7 = ((char *)(long)&s____00147018 /* "      #: " */);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x8c));
  waddnstr(_stdscr,((char *)(long)&DAT_001471ab /* "R" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&s___running__001470ef /* ": running; " */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x78));
  waddnstr(_stdscr,((char *)(long)&DAT_0014716d /* "S" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&s___sleeping__001470fb /* ": sleeping; " */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x8c));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x2e7a) /* "t" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&s___traced_stopped__00147108 /* ": traced/stopped; " */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x90));
  waddnstr(_stdscr,((char *)(long)&DAT_00149691 /* "Z" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&s___zombie__0014711b /* ": zombie; " */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 0x90));
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x1783) /* "D" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  waddnstr(_stdscr,((char *)(long)&s___disk_sleep_00147126 /* ": disk sleep" */),-1);
  wattrset(_stdscr,*(int *)(CRT_colors + 4));
  cVar1 = CHAR____0015c0d9;
  do {
    iVar3 = iVar8 + 0xb;
    bVar6 = cVar1 & *pbVar9;
    if (bVar6 == 0) {
      wattrset(_stdscr,*(int *)(CRT_colors + 4));
      iVar4 = wmove(_stdscr,iVar3,10);
      if (iVar4 != -1) {
        waddnstr(_stdscr,*(char **)(pbVar9 + 8),-1);
      }
      iVar4 = *(int *)(CRT_colors + 0x11c);
    }
    else {
      wattrset(_stdscr,*(int *)(CRT_colors + 0x120));
      iVar4 = wmove(_stdscr,iVar3,10);
      if (iVar4 != -1) {
        waddnstr(_stdscr,*(char **)(pbVar9 + 8),-1);
      }
      iVar4 = *(int *)(CRT_colors + 0x120);
    }
    wattrset(_stdscr,iVar4);
    iVar4 = wmove(_stdscr,iVar3,1);
    if (iVar4 != -1) {
      waddnstr(_stdscr,pcVar7,-1);
    }
    iVar4 = strcmp(pcVar7,((char *)(long)&s_H__00147133 /* "      H: " */));
    lVar2 = CRT_colors;
    if (iVar4 == 0) {
      if (bVar6 == 0) {
        iVar4 = *(int *)(CRT_colors + 0xa8);
      }
      else {
        iVar4 = *(int *)(CRT_colors + 0x120);
      }
      wattrset(_stdscr,iVar4);
      iVar3 = wmove(_stdscr,iVar3,0x21);
joined_r0x001152ab:
      if (iVar3 != -1) {
        waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x2b7) /* "threads" */),-1);
      }
    }
    else {
      iVar4 = strcmp(pcVar7,((char *)(long)&s_K__0014713d /* "      K: " */));
      if (iVar4 == 0) {
        if (bVar6 == 0) {
          iVar4 = *(int *)(lVar2 + 0xa8);
        }
        else {
          iVar4 = *(int *)(lVar2 + 0x120);
        }
        wattrset(_stdscr,iVar4);
        iVar3 = wmove(_stdscr,iVar3,0x1b);
        goto joined_r0x001152ab;
      }
    }
    pcVar7 = *(char **)(pbVar9 + 0x10);
    pbVar9 = pbVar9 + 0x18;
    iVar8 = iVar8 + 1;
    if (pcVar7 == (char *)0x0) {
      pcVar10 = ((char *)(long)&DAT_001561a8 /* "" */);
      pcVar7 = ((char *)(long)&s_S_Tab__00147022 /* "  S-Tab: " */);
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 0xb;
        if ((*pcVar10 == '\0') || (cVar1 == '\0')) {
          wattrset(_stdscr,*(int *)(CRT_colors + 0x11c));
          iVar5 = wmove(_stdscr,iVar4,0x2b);
          if (iVar5 != -1) {
            waddnstr(_stdscr,pcVar7,-1);
          }
          iVar5 = *(int *)(CRT_colors + 4);
        }
        else {
          wattrset(_stdscr,*(int *)(CRT_colors + 0x120));
          iVar5 = wmove(_stdscr,iVar4,0x2b);
          if (iVar5 != -1) {
            waddnstr(_stdscr,pcVar7,-1);
          }
          iVar5 = *(int *)(CRT_colors + 0x120);
        }
        wattrset(_stdscr,iVar5);
        iVar4 = wmove(_stdscr,iVar4,0x34);
        if (iVar4 != -1) {
          waddnstr(_stdscr,*(char **)(pcVar10 + 8),-1);
        }
        pcVar7 = *(char **)(pcVar10 + 0x10);
        pcVar10 = pcVar10 + 0x18;
        iVar3 = iVar3 + 1;
      } while (pcVar7 != (char *)0x0);
      wattrset(_stdscr,*(int *)(CRT_colors + 0x11c));
      if (iVar8 <= iVar3) {
        iVar8 = iVar3;
      }
      iVar8 = wmove(_stdscr,iVar8 + 0xc,0);
      if (iVar8 != -1) {
        waddnstr(_stdscr,((char *)(long)&s_Press_any_key_to_return__00147147 /* "Press any key to return." */),-1);
      }
      wattrset(_stdscr,*(int *)(CRT_colors + 4));
      wrefresh(_stdscr);
      nocbreak();
      cbreak();
      nodelay(_stdscr,0);
      wgetch(_stdscr);
      halfdelay(*PTR_0015c0d0);
      wclear(_stdscr);
      return 0x2b;
    }
  } while( true );
}


/* FUN_00115660 @ 0x115660 */

void FUN_00115660(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  tm *__tp;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  __tp = localtime_r((time_t *)(*(long *)(param_1 + 0x10) + 8),&(*(tm *)(__fp - 0x58)));
  **(double **)(param_1 + 0x160) = (double)(__tp->tm_hour * 0x3c + __tp->tm_min);
  strftime((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_00147166 /* "%H:%M:%S" */),__tp);
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001156e0 @ 0x1156e0 */

void FUN_001156e0(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  uint uVar2;
  tm *__tp;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined8 uVar3;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  __tp = localtime_r((time_t *)(*(long *)(param_1 + 0x10) + 8),&(*(tm *)(__fp - 0x58)));
  **(double **)(param_1 + 0x160) = (double)__tp->tm_yday;
  uVar2 = __tp->tm_year;
  iVar1 = uVar2 + 0x76c;
  if ((((uVar2 & 3) != 0) ||
      (uVar3 = 0x4076e00000000000,
      (iVar1 * -0x3d70a3d7 + 0x51eb850U >> 2 | uVar2 * 0x40000000) < 0x28f5c29)) &&
     (uVar3 = 0x4076e00000000000,
     0xa3d70a < (iVar1 * -0x3d70a3d7 + 0x51eb850U >> 4 | iVar1 * -0x70000000))) {
    uVar3 = 0x4076d00000000000;
  }
  *(undefined8 *)(param_1 + 0x168) = uVar3;
  strftime((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_00147160 /* "%F" */),__tp);
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001157c0 @ 0x1157c0 */

void FUN_001157c0(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  uint uVar2;
  tm *__tp;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined8 uVar3;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  __tp = localtime_r((time_t *)(*(long *)(param_1 + 0x10) + 8),&(*(tm *)(__fp - 0x58)));
  uVar2 = __tp->tm_year;
  iVar1 = uVar2 + 0x76c;
  if ((((uVar2 & 3) != 0) ||
      (uVar3 = 0x4076e00000000000,
      (iVar1 * -0x3d70a3d7 + 0x51eb850U >> 2 | uVar2 * 0x40000000) < 0x28f5c29)) &&
     (uVar3 = 0x4076e00000000000,
     0xa3d70a < (iVar1 * -0x3d70a3d7 + 0x51eb850U >> 4 | iVar1 * -0x70000000))) {
    uVar3 = 0x4076d00000000000;
  }
  *(undefined8 *)(param_1 + 0x168) = uVar3;
  **(double **)(param_1 + 0x160) = (double)__tp->tm_yday;
  strftime((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_00147163 /* "%F %H:%M:%S" */),__tp);
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001158a0 @ 0x1158a0 */

void FUN_001158a0(void)

{
  undefined1 __frame[0x8b8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x878;
  int p1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  p1 = backtrace((*(void * (*)[257])(__fp - 0x828)),0x100);
  backtrace_symbols_fd((*(void * (*)[257])(__fp - 0x828)),p1,2);
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Action_setUserOnly @ 0x115900 */

undefined8 Action_setUserOnly(char *param_1,__uid_t *param_2)

{
  passwd *ppVar1;

  ppVar1 = getpwnam(param_1);
  if (ppVar1 != (passwd *)0x0) {
    *param_2 = ppVar1->pw_uid;
    return 1;
  }
  *param_2 = 0xffffffff;
  return 0;
}


/* Action_setSortKey @ 0x115940 */

undefined8 Action_setSortKey(long param_1,int param_2)

{
  char cVar1;
  long lVar2;

  lVar2 = *(long *)(param_1 + 0x40);
  cVar1 = Process_fields[(long)param_2 * 0x20 + 0x1d];
  if ((*(char *)(lVar2 + 0x35) == '\0') && (*(char *)(lVar2 + 0x34) != '\0')) {
    *(int *)(lVar2 + 0x30) = param_2;
    *(uint *)(lVar2 + 0x28) = (-(uint)(cVar1 == '\0') & 2) - 1;
    return 0x4d;
  }
  *(int *)(lVar2 + 0x2c) = param_2;
  *(undefined1 *)(lVar2 + 0x34) = 0;
  *(uint *)(lVar2 + 0x24) = (-(uint)(cVar1 == '\0') & 2) - 1;
  return 0x4d;
}


/* Action_setScreenTab @ 0x115a20 */

undefined8 Action_setScreenTab(long *param_1,int param_2)

{
  uint uVar1;
  long *plVar2;
  undefined8 *puVar3;
  char cVar4;
  size_t sVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  int iVar9;
  uint uVar10;

  plVar2 = (long *)*param_1;
  lVar6 = *plVar2;
  uVar1 = *(uint *)(lVar6 + 0x38);
  if ((uVar1 != 0) && (1 < param_2)) {
    plVar8 = *(long **)(lVar6 + 0x30);
    uVar10 = 0;
    iVar9 = 2;
    do {
      puVar3 = (undefined8 *)*plVar8;
      sVar5 = strlen((char *)*puVar3);
      cVar4 = CHAR____0015c0d9;
      if (param_2 <= iVar9 + 1 + (int)sVar5) {
        *(uint *)(lVar6 + 0x3c) = uVar10;
        *(undefined8 **)(lVar6 + 0x40) = puVar3;
        lVar6 = puVar3[2];
        if (lVar6 == 0) {
          lVar6 = plVar2[0x16];
          puVar3[2] = lVar6;
          plVar2[0x15] = lVar6;
          if (cVar4 == '\0') goto LAB_00115b46;
        }
        else {
          plVar2[0x15] = lVar6;
          if ((cVar4 == '\0') && (lVar6 == plVar2[0x16])) {
LAB_00115b46:
            lVar6 = param_1[1];
            uVar7 = *(undefined8 *)(lVar6 + 0x26f8);
            goto LAB_00115aeb;
          }
        }
        lVar6 = param_1[1];
        uVar7 = *(undefined8 *)(lVar6 + 0x2700);
LAB_00115aeb:
        *(undefined8 *)(lVar6 + 0x58) = uVar7;
        *(undefined8 *)(*(long *)(lVar6 + 0x26e8) + 0x140) = uVar7;
        return 0x61;
      }
      iVar9 = iVar9 + 3 + (int)sVar5;
      uVar10 = uVar10 + 1;
      plVar8 = plVar8 + 1;
    } while ((uVar10 < uVar1) && (iVar9 <= param_2));
  }
  return 0;
}


/* Action_setBindings @ 0x115c90 */

void Action_setBindings(long param_1)

{
  *(code **)(param_1 + 0x230) = Action_follow;
  *(code **)(param_1 + 0x340) = FUN_00114850;
  *(code **)(param_1 + 0x150) = FUN_00119b50;
  *(code **)(param_1 + 0x158) = FUN_00113c90;
  *(code **)(param_1 + 0x218) = FUN_0011a860;
  *(code **)(param_1 + 0x170) = FUN_001185a0;
  *(code **)(param_1 + 0x178) = FUN_00119c50;
  *(code **)(param_1 + 0x100) = FUN_00113f70;
  *(code **)(param_1 + 0x1f0) = FUN_001185a0;
  *(code **)(param_1 + 0x1f8) = FUN_00114850;
  *(code **)(param_1 + 0x848) = FUN_00114850;
  *(code **)(param_1 + 0x850) = FUN_0011a860;
  *(code **)(param_1 + 0x160) = FUN_001185a0;
  *(code **)(param_1 + 0x168) = FUN_00113c90;
  *(code **)(param_1 + 0x240) = FUN_00119b20;
  *(code **)(param_1 + 0x248) = FUN_00113c40;
  *(code **)(param_1 + 0x118) = FUN_00113c30;
  *(code **)(param_1 + 0x268) = FUN_00113a70;
  *(code **)(param_1 + 0x270) = FUN_00113a20;
  *(code **)(param_1 + 600) = FUN_00119af0;
  *(code **)(param_1 + 0x278) = FUN_00113b60;
  *(code **)(param_1 + 0x280) = FUN_00113ac0;
  *(code **)(param_1 + 0x60) = FUN_00114830;
  *(code **)(param_1 + 0x2a8) = FUN_00113fe0;
  *(code **)(param_1 + 0x298) = FUN_0011a860;
  *(code **)(param_1 + 0x2a0) = FUN_00113b10;
  *(code **)(param_1 + 0x308) = FUN_0011b7a0;
  *(code **)(param_1 + 0x2c8) = FUN_00119cb0;
  *(code **)(param_1 + 0x2d0) = FUN_00113fd0;
  *(code **)(param_1 + 0x3f8) = FUN_00113ce0;
  *(code **)(param_1 + 0x2d8) = FUN_00114740;
  *(code **)(param_1 + 0x2e0) = FUN_00119bd0;
  *(code **)(param_1 + 0x318) = FUN_00114020;
  *(code **)(param_1 + 0x358) = FUN_0011a000;
  *(code **)(param_1 + 0x360) = FUN_0011a9d0;
  *(code **)(param_1 + 0x328) = FUN_0011abf0;
  *(code **)(param_1 + 0x368) = FUN_00113ba0;
  *(code **)(param_1 + 0x380) = FUN_00113b80;
  *(code **)(param_1 + 0x388) = FUN_00113f10;
  *(code **)(param_1 + 0x3a8) = FUN_0011a490;
  *(code **)(param_1 + 0x398) = FUN_0011aaf0;
  *(code **)(param_1 + 0x3a0) = FUN_00113bc0;
  *(code **)(param_1 + 0x2e8) = FUN_00114650;
  *(code **)(param_1 + 0x1e0) = FUN_001185a0;
  *(code **)(param_1 + 0x1e8) = FUN_00113c90;
  *(code **)(param_1 + 0x3b8) = FUN_0011ad20;
  *(code **)(param_1 + 0x3c0) = FUN_0011aa60;
  *(code **)(param_1 + 0x858) = FUN_00119c50;
  *(code **)(param_1 + 0x860) = FUN_00119bd0;
  *(code **)(param_1 + 0x8d0) = FUN_001189d0;
  *(code **)(param_1 + 0x868) = FUN_00113bc0;
  *(code **)(param_1 + 0x870) = FUN_001185a0;
  *(code **)(param_1 + 0x48) = FUN_00113d90;
  *(code **)(param_1 + 0x878) = FUN_00114650;
  *(code **)(param_1 + 0x880) = FUN_00114740;
  *(code **)(param_1 + 0x888) = FUN_0011a000;
  *(code **)(param_1 + 0x890) = FUN_00113f10;
  *(code **)(param_1 + 0x940) = FUN_00113c90;
  *(code **)(param_1 + 0x948) = FUN_00113e50;
  return;
}


/* Action_pickFromVector @ 0x1178f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
Action_pickFromVector
          (long *param_1,long param_2,int param_3,char param_4,long param_r8,long param_r9)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  uint uVar1;
  long lVar2;
  int *__ptr;
  undefined8 uVar3;
  long lVar4;
  long extraout_RDX;
  long lVar5;
  long extraout_RDX_00;
  long *plVar6;
  int iVar7;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar5 = *param_1;
  lVar2 = param_1[1];
  uVar1 = *(uint *)(lVar2 + 0xc);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __ptr = (int *)ScreenManager_new(param_1[2],lVar5,param_1,0);
  *(undefined1 *)(__ptr + 0x10) = 0;
  ScreenManager_insert(__ptr,param_2,param_3,*(int *)(*(long *)(__ptr + 4) + 0x18));
  ScreenManager_insert(__ptr,lVar2,-1,*(int *)(*(long *)(__ptr + 4) + 0x18));
  if (param_4 == '\0') {
    plVar6 = &(*(long *)(__fp - 0x48));
    lVar4 = 0;
    ScreenManager_run(__ptr,plVar6,&(*(uint *)(__fp - 0x4c)),0,param_r8,param_r9);
    (*(int *)(__fp - 0x60)) = -1;
    lVar5 = extraout_RDX;
  }
  else {
    (*(int *)(__fp - 0x60)) = -1;
    if ((0 < (int)(*(long **)(lVar2 + 0x20))[3]) &&
       (lVar4 = *(long *)(**(long **)(lVar2 + 0x20) + (long)*(int *)(lVar2 + 0x28) * 8), lVar4 != 0)
       ) {
      (*(int *)(__fp - 0x60)) = *(int *)(lVar4 + 0x10);
    }
    if (*(int *)(*(long *)(lVar5 + 0xa8) + 0x34) == -1) {
      plVar6 = &(*(long *)(__fp - 0x48));
      lVar4 = 0;
      *(int *)(*(long *)(lVar5 + 0xa8) + 0x34) = (*(int *)(__fp - 0x60));
      ScreenManager_run(__ptr,plVar6,&(*(uint *)(__fp - 0x4c)),0,param_r8,param_r9);
      lVar5 = *(long *)(lVar5 + 0xa8);
      *(undefined4 *)(lVar5 + 0x34) = 0xffffffff;
    }
    else {
      plVar6 = &(*(long *)(__fp - 0x48));
      lVar4 = 0;
      ScreenManager_run(__ptr,plVar6,&(*(uint *)(__fp - 0x4c)),0,param_r8,param_r9);
      lVar5 = extraout_RDX_00;
    }
  }
  Vector_delete(*(long **)(__ptr + 4),(long)plVar6,lVar5,lVar4,param_r8,param_r9);
  free(__ptr);
  *(uint *)(lVar2 + 0xc) = uVar1;
  *(undefined4 *)(lVar2 + 8) = 0;
  iVar7 = ~uVar1 + _LINES;
  *(undefined1 *)(lVar2 + 0x48) = 1;
  *(int *)(lVar2 + 0x14) = iVar7;
  *(undefined4 *)(lVar2 + 0x10) = _COLS;
  if (((*(long *)(__fp - 0x48)) == param_2) && ((*(uint *)(__fp - 0x4c)) == 0xd)) {
    if ((param_4 == '\0') ||
       (((0 < (int)(*(long **)(lVar2 + 0x20))[3] &&
         (lVar5 = *(long *)(**(long **)(lVar2 + 0x20) + (long)*(int *)(lVar2 + 0x28) * 8),
         lVar5 != 0)) && (*(int *)(lVar5 + 0x10) == (*(int *)(__fp - 0x60)))))) {
      if (0 < (int)(*(long **)(param_2 + 0x20))[3]) {
        uVar3 = *(undefined8 *)(**(long **)(param_2 + 0x20) + (long)*(int *)(param_2 + 0x28) * 8);
        goto LAB_00117a1a;
      }
    }
    else {
      beep();
    }
  }
  uVar3 = 0;
LAB_00117a1a:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

