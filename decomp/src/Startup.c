#include "htop.h"

/* FUN_001138f0 @ 0x1138f0 */

/* WARNING: Removing unreachable block (ram,0x00113903) */
/* WARNING: Removing unreachable block (ram,0x0011390f) */

void FUN_001138f0(void)

{
  return;
}


/* FUN_00113920 @ 0x113920 */

/* WARNING: Removing unreachable block (ram,0x00113944) */
/* WARNING: Removing unreachable block (ram,0x00113950) */

void FUN_00113920(void)

{
  return;
}


/* FUN_001139b0 @ 0x1139b0 */

void FUN_001139b0(long param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  long *plVar5;

  plVar5 = *(long **)(param_1 + 0x20);
  *(undefined1 *)(param_2 + 0x1d) = 1;
  iVar4 = (int)plVar5[3];
  if (0 < iVar4) {
    plVar5 = (long *)*plVar5;
    iVar2 = *(int *)(param_2 + 0x10);
    plVar1 = plVar5 + iVar4;
    do {
      lVar3 = *plVar5;
      if (*(char *)(lVar3 + 0x1d) == '\0') {
        iVar4 = *(int *)(lVar3 + 0x14);
        if (iVar4 == *(int *)(lVar3 + 0x10)) {
          iVar4 = *(int *)(lVar3 + 0x18);
        }
        if (iVar2 == iVar4) {
          FUN_001139b0(param_1,lVar3);
        }
      }
      plVar5 = plVar5 + 1;
    } while (plVar1 != plVar5);
    return;
  }
  return;
}


/* FUN_00113a20 @ 0x113a20 */

undefined8 FUN_00113a20(undefined8 *param_1)

{
  long lVar1;

  lVar1 = *(long *)(*(long *)*param_1 + 0x40);
  if ((*(char *)(lVar1 + 0x35) == '\0') && (*(char *)(lVar1 + 0x34) != '\0')) {
    *(undefined4 *)(lVar1 + 0x30) = 1;
    *(undefined4 *)(lVar1 + 0x28) = 1;
    return 0x4d;
  }
  *(undefined4 *)(lVar1 + 0x2c) = 1;
  *(undefined4 *)(lVar1 + 0x24) = 1;
  *(undefined1 *)(lVar1 + 0x34) = 0;
  return 0x4d;
}


/* FUN_00113a70 @ 0x113a70 */

undefined8 FUN_00113a70(undefined8 *param_1)

{
  long lVar1;

  lVar1 = *(long *)(*(long *)*param_1 + 0x40);
  if ((*(char *)(lVar1 + 0x35) == '\0') && (*(char *)(lVar1 + 0x34) != '\0')) {
    *(undefined4 *)(lVar1 + 0x30) = 0x30;
    *(undefined4 *)(lVar1 + 0x28) = 0xffffffff;
    return 0x4d;
  }
  *(undefined4 *)(lVar1 + 0x2c) = 0x30;
  *(undefined4 *)(lVar1 + 0x24) = 0xffffffff;
  *(undefined1 *)(lVar1 + 0x34) = 0;
  return 0x4d;
}


/* FUN_00113ac0 @ 0x113ac0 */

undefined8 FUN_00113ac0(undefined8 *param_1)

{
  long lVar1;

  lVar1 = *(long *)(*(long *)*param_1 + 0x40);
  if ((*(char *)(lVar1 + 0x35) == '\0') && (*(char *)(lVar1 + 0x34) != '\0')) {
    *(undefined4 *)(lVar1 + 0x30) = 0x2f;
    *(undefined4 *)(lVar1 + 0x28) = 0xffffffff;
    return 0x4d;
  }
  *(undefined4 *)(lVar1 + 0x2c) = 0x2f;
  *(undefined4 *)(lVar1 + 0x24) = 0xffffffff;
  *(undefined1 *)(lVar1 + 0x34) = 0;
  return 0x4d;
}


/* FUN_00113b10 @ 0x113b10 */

undefined8 FUN_00113b10(undefined8 *param_1)

{
  long lVar1;

  lVar1 = *(long *)(*(long *)*param_1 + 0x40);
  if ((*(char *)(lVar1 + 0x35) == '\0') && (*(char *)(lVar1 + 0x34) != '\0')) {
    *(undefined4 *)(lVar1 + 0x30) = 0x32;
    *(undefined4 *)(lVar1 + 0x28) = 0xffffffff;
    return 0x4d;
  }
  *(undefined4 *)(lVar1 + 0x2c) = 0x32;
  *(undefined4 *)(lVar1 + 0x24) = 0xffffffff;
  *(undefined1 *)(lVar1 + 0x34) = 0;
  return 0x4d;
}


/* FUN_00113b60 @ 0x113b60 */

undefined8 FUN_00113b60(undefined8 *param_1)

{
  byte *pbVar1;
  long *plVar2;
  long lVar3;

  lVar3 = *(long *)*param_1;
  pbVar1 = (byte *)(lVar3 + 0x5a);
  *pbVar1 = *pbVar1 ^ 1;
  plVar2 = (long *)(lVar3 + 0x78);
  *plVar2 = *plVar2 + 1;
  return 0xf;
}


/* FUN_00113b80 @ 0x113b80 */

undefined8 FUN_00113b80(undefined8 *param_1)

{
  byte *pbVar1;
  long *plVar2;
  long lVar3;

  lVar3 = *(long *)*param_1;
  pbVar1 = (byte *)(lVar3 + 0x56);
  *pbVar1 = *pbVar1 ^ 1;
  plVar2 = (long *)(lVar3 + 0x78);
  *plVar2 = *plVar2 + 1;
  return 0xd;
}


/* FUN_00113ba0 @ 0x113ba0 */

undefined8 FUN_00113ba0(undefined8 *param_1)

{
  byte *pbVar1;
  long *plVar2;
  long lVar3;

  lVar3 = *(long *)*param_1;
  pbVar1 = (byte *)(lVar3 + 0x6a);
  *pbVar1 = *pbVar1 ^ 1;
  plVar2 = (long *)(lVar3 + 0x78);
  *plVar2 = *plVar2 + 1;
  return 0x4d;
}


/* FUN_00113bc0 @ 0x113bc0 */

undefined8 FUN_00113bc0(long *param_1)

{
  byte *pbVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;

  lVar4 = ((long *)*param_1)[0x15];
  lVar5 = *(long *)(*(long *)*param_1 + 0x40);
  pbVar1 = (byte *)(lVar5 + 0x34);
  *pbVar1 = *pbVar1 ^ 1;
  if (*(char *)(lVar5 + 0x36) == '\0') {
    iVar3 = (int)(*(long **)(lVar4 + 8))[3];
    if (0 < iVar3) {
      plVar6 = (long *)**(long **)(lVar4 + 8);
      plVar2 = plVar6 + iVar3;
      do {
        lVar5 = *plVar6;
        plVar6 = plVar6 + 1;
        *(undefined1 *)(lVar5 + 0x20) = 1;
      } while (plVar6 != plVar2);
      *(undefined1 *)(lVar4 + 0x30) = 1;
      return 0x6d;
    }
  }
  *(undefined1 *)(lVar4 + 0x30) = 1;
  return 0x6d;
}


/* FUN_00113c30 @ 0x113c30 */

undefined8 FUN_00113c30(long param_1)

{
  *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) ^ 1;
  return 0xe9;
}


/* FUN_00113c40 @ 0x113c40 */

undefined8 FUN_00113c40(long *param_1)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  int *piVar4;

  plVar1 = (long *)*param_1;
  lVar2 = *(long *)(*plVar1 + 0x40);
  if (*(char *)(lVar2 + 0x34) == '\0') {
    piVar4 = (int *)(lVar2 + 0x24);
    iVar3 = *(int *)(lVar2 + 0x24);
  }
  else {
    piVar4 = (int *)(lVar2 + 0x28);
    iVar3 = *(int *)(lVar2 + 0x28);
  }
  *piVar4 = ((iVar3 != 1) - 1) + (uint)(iVar3 != 1);
  *(undefined1 *)(plVar1[0x15] + 0x30) = 1;
  return 0x4d;
}


/* FUN_00113c90 @ 0x113c90 */

undefined8 FUN_00113c90(undefined8 *param_1)

{
  byte *pbVar1;
  long *plVar2;
  long lVar3;

  if (*(char *)(*(long *)(*(long *)*param_1 + 0x40) + 0x34) != '\0') {
    plVar2 = *(long **)(param_1[1] + 0x20);
    if ((0 < (int)plVar2[3]) &&
       (lVar3 = *(long *)(*plVar2 + (long)*(int *)(param_1[1] + 0x28) * 8), lVar3 != 0)) {
      pbVar1 = (byte *)(lVar3 + 0x20);
      *pbVar1 = *pbVar1 ^ 1;
      return 3;
    }
  }
  return 0;
}


/* FUN_00113ce0 @ 0x113ce0 */

undefined8
FUN_00113ce0(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  int iVar1;
  long *a0;
  long lVar2;
  long a2;
  long lVar3;
  int iVar4;

  if (*(char *)(*(long *)(*(long *)*param_1 + 0x40) + 0x34) != '\0') {
    a0 = (long *)param_1[1];
    iVar1 = (int)((long *)a0[4])[3];
    if (0 < iVar1) {
      lVar2 = *(long *)a0[4];
      lVar3 = *(long *)(lVar2 + (long)(int)a0[5] * 8);
      if (lVar3 != 0) {
        iVar4 = *(int *)(lVar3 + 0x14);
        if (iVar4 == *(int *)(lVar3 + 0x10)) {
          iVar4 = *(int *)(lVar3 + 0x18);
        }
        lVar3 = 0;
        while (a2 = *(long *)(lVar2 + lVar3 * 8), *(int *)(a2 + 0x10) != iVar4) {
          lVar3 = lVar3 + 1;
          if (lVar3 == iVar1) {
            return 0;
          }
        }
        *(undefined1 *)(a2 + 0x20) = 0;
        *(int *)(a0 + 5) = (int)lVar3;
        if (*(code **)(*a0 + 0x20) != (code *)0x0) {
          (**(code **)(*a0 + 0x20))((long)a0,0xffffffff,a2,(long)iVar1,(long)a0,param_r9);
          return 3;
        }
        return 3;
      }
    }
  }
  return 0;
}


/* FUN_00113d90 @ 0x113d90 */

undefined8 FUN_00113d90(long *param_1)

{
  long *plVar1;
  char cVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;

  plVar1 = (long *)*param_1;
  lVar3 = *plVar1;
  uVar4 = *(int *)(lVar3 + 0x3c) + 1;
  lVar6 = (ulong)uVar4 << 3;
  if (uVar4 == *(uint *)(lVar3 + 0x38)) {
    lVar6 = 0;
    uVar4 = 0;
  }
  *(uint *)(lVar3 + 0x3c) = uVar4;
  cVar2 = CHAR____0015c0d9;
  lVar6 = *(long *)(*(long *)(lVar3 + 0x30) + lVar6);
  *(long *)(lVar3 + 0x40) = lVar6;
  lVar3 = *(long *)(lVar6 + 0x10);
  if (lVar3 == 0) {
    lVar3 = plVar1[0x16];
    *(long *)(lVar6 + 0x10) = lVar3;
    plVar1[0x15] = lVar3;
    if (cVar2 == '\0') {
      lVar3 = param_1[1];
      uVar5 = *(undefined8 *)(lVar3 + 0x26f8);
      goto LAB_00113de5;
    }
  }
  else {
    plVar1[0x15] = lVar3;
    if ((cVar2 == '\0') && (lVar3 == plVar1[0x16])) {
      lVar3 = param_1[1];
      uVar5 = *(undefined8 *)(lVar3 + 0x26f8);
      goto LAB_00113de5;
    }
  }
  lVar3 = param_1[1];
  uVar5 = *(undefined8 *)(lVar3 + 0x2700);
LAB_00113de5:
  *(undefined8 *)(lVar3 + 0x58) = uVar5;
  *(undefined8 *)(*(long *)(lVar3 + 0x26e8) + 0x140) = uVar5;
  return 0x61;
}


/* FUN_00113e50 @ 0x113e50 */

undefined8 FUN_00113e50(long *param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  char cVar4;
  long lVar5;
  undefined8 uVar6;

  plVar2 = (long *)*param_1;
  lVar5 = *plVar2;
  iVar1 = *(int *)(lVar5 + 0x3c);
  if (iVar1 == 0) {
    iVar1 = *(int *)(lVar5 + 0x38);
  }
  *(uint *)(lVar5 + 0x3c) = iVar1 - 1U;
  cVar4 = CHAR____0015c0d9;
  lVar3 = *(long *)(*(long *)(lVar5 + 0x30) + (ulong)(iVar1 - 1U) * 8);
  *(long *)(lVar5 + 0x40) = lVar3;
  lVar5 = *(long *)(lVar3 + 0x10);
  if (lVar5 == 0) {
    lVar5 = plVar2[0x16];
    *(long *)(lVar3 + 0x10) = lVar5;
    plVar2[0x15] = lVar5;
    if (cVar4 == '\0') {
      lVar5 = param_1[1];
      uVar6 = *(undefined8 *)(lVar5 + 0x26f8);
      goto LAB_00113ea0;
    }
  }
  else {
    plVar2[0x15] = lVar5;
    if ((cVar4 == '\0') && (lVar5 == plVar2[0x16])) {
      lVar5 = param_1[1];
      uVar6 = *(undefined8 *)(lVar5 + 0x26f8);
      goto LAB_00113ea0;
    }
  }
  lVar5 = param_1[1];
  uVar6 = *(undefined8 *)(lVar5 + 0x2700);
LAB_00113ea0:
  *(undefined8 *)(lVar5 + 0x58) = uVar6;
  *(undefined8 *)(*(long *)(lVar5 + 0x26e8) + 0x140) = uVar6;
  return 0x61;
}


/* FUN_00113f10 @ 0x113f10 */

undefined8 FUN_00113f10(void)

{
  return 0x10;
}

