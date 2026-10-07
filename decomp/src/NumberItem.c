#include "htop.h"

/* NumberItem_get @ 0x121f80 */

undefined4 NumberItem_get(long param_1)

{
  if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
    return **(undefined4 **)(param_1 + 0x18);
  }
  return *(undefined4 *)(param_1 + 0x20);
}


/* NumberItem_decrease @ 0x121fa0 */

void NumberItem_decrease(long param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;

  piVar2 = *(int **)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0x2c);
  if (piVar2 == (int *)0x0) {
    iVar1 = *(int *)(param_1 + 0x20) + -1;
    if (iVar3 < iVar1) {
      *(int *)(param_1 + 0x20) = iVar3;
      return;
    }
    iVar3 = *(int *)(param_1 + 0x28);
    if (*(int *)(param_1 + 0x28) <= iVar1) {
      iVar3 = iVar1;
    }
    *(int *)(param_1 + 0x20) = iVar3;
    return;
  }
  iVar1 = *piVar2 + -1;
  if (iVar3 < iVar1) {
    *piVar2 = iVar3;
    return;
  }
  iVar3 = *(int *)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x28) <= iVar1) {
    iVar3 = iVar1;
  }
  *piVar2 = iVar3;
  return;
}


/* NumberItem_increase @ 0x121ff0 */

void NumberItem_increase(long param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;

  piVar2 = *(int **)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0x2c);
  if (piVar2 == (int *)0x0) {
    iVar1 = *(int *)(param_1 + 0x20);
    if (iVar3 <= iVar1) {
      *(int *)(param_1 + 0x20) = iVar3;
      return;
    }
    iVar3 = *(int *)(param_1 + 0x28);
    if (*(int *)(param_1 + 0x28) <= iVar1) {
      iVar3 = iVar1 + 1;
    }
    *(int *)(param_1 + 0x20) = iVar3;
    return;
  }
  iVar1 = *piVar2;
  if (iVar3 <= iVar1) {
    *piVar2 = iVar3;
    return;
  }
  iVar3 = *(int *)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x28) <= iVar1) {
    iVar3 = iVar1 + 1;
  }
  *piVar2 = iVar3;
  return;
}


/* NumberItem_toggle @ 0x122040 */

void NumberItem_toggle(long param_1)

{
  int *piVar1;

  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 == (int *)0x0) {
    if (*(int *)(param_1 + 0x2c) <= *(int *)(param_1 + 0x20)) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x28);
      return;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    return;
  }
  if (*(int *)(param_1 + 0x2c) <= *piVar1) {
    *piVar1 = *(int *)(param_1 + 0x28);
    return;
  }
  *piVar1 = *piVar1 + 1;
  return;
}


/* NumberItem_newByRef @ 0x123dd0 */

undefined8 *
NumberItem_newByRef(char *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x30);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = NumberItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined4 *)(puVar1 + 4) = 0;
      puVar1[3] = param_2;
      *(undefined4 *)((long)puVar1 + 0x24) = param_3;
      *(undefined4 *)(puVar1 + 5) = param_4;
      *(undefined4 *)((long)puVar1 + 0x2c) = param_5;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* NumberItem_newByVal @ 0x123e60 */

undefined8 *
NumberItem_newByVal(char *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined8 *puVar2;
  char *pcVar3;

  puVar2 = malloc(0x30);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = NumberItem_class;
    pcVar3 = strdup(param_1);
    if (pcVar3 != (char *)0x0) {
      puVar2[1] = pcVar3;
      iVar1 = param_4;
      if (param_4 <= param_2) {
        iVar1 = param_2;
      }
      puVar2[3] = 0;
      if (param_5 < param_2) {
        iVar1 = param_5;
      }
      puVar2[4] = CONCAT44(param_3,iVar1);
      puVar2[5] = CONCAT44(param_5,param_4);
      return puVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

