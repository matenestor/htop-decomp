#include "htop.h"

/* Vector_remove @ 0x12de20 */

long * Vector_remove(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                    long param_r9)

{
  long *__dest;
  char cVar1;
  long *a0;
  long a3;
  int iVar2;
  undefined4 in_register_00000034;
  void *__src;

  __src = (void *)CONCAT44(in_register_00000034,param_2);
  a3 = *param_1;
  __dest = (long *)(a3 + (long)param_2 * 8);
  iVar2 = (int)param_1[3] + -1;
  a0 = (long *)*__dest;
  *(int *)(param_1 + 3) = iVar2;
  if (param_2 < iVar2) {
    __src = (void *)(a3 + 8 + (long)param_2 * 8);
    memmove(__dest,__src,(long)(iVar2 - param_2) << 3);
    a3 = *param_1;
    iVar2 = (int)param_1[3];
  }
  cVar1 = *(char *)((long)param_1 + 0x24);
  *(undefined8 *)(a3 + (long)iVar2 * 8) = 0;
  if (cVar1 == '\0') {
    return a0;
  }
  (**(code **)(*a0 + 0x10))((long)a0,(long)__src,(long)iVar2,a3,param_r8,param_r9);
  return (long *)0x0;
}


/* Vector_moveUp @ 0x12dfa0 */

void Vector_moveUp(long *param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;

  if (param_2 != 0) {
    puVar1 = (undefined8 *)(*param_1 + -8 + (long)param_2 * 8);
    uVar3 = *puVar1;
    puVar2 = (undefined8 *)(*param_1 + -8 + (long)param_2 * 8);
    *puVar2 = puVar1[1];
    puVar2[1] = uVar3;
  }
  return;
}


/* Vector_softRemove @ 0x12e220 */

long * Vector_softRemove(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                        long param_r9)

{
  long *plVar1;
  long *a0;
  undefined4 in_register_00000034;

  plVar1 = (long *)(*param_1 + (long)param_2 * 8);
  a0 = (long *)*plVar1;
  if (a0 == (long *)0x0) {
    return (long *)0x0;
  }
  *plVar1 = 0;
  *(int *)(param_1 + 4) = (int)param_1[4] + 1;
  if ((param_2 < *(int *)((long)param_1 + 0x1c)) || (*(int *)((long)param_1 + 0x1c) < 0)) {
    *(int *)((long)param_1 + 0x1c) = param_2;
  }
  if (*(char *)((long)param_1 + 0x24) == '\0') {
    return a0;
  }
  (**(code **)(*a0 + 0x10))
            ((long)a0,CONCAT44(in_register_00000034,param_2),*a0,param_rcx,param_r8,param_r9);
  return (long *)0x0;
}


/* Vector_quickSortCustomCompare @ 0x12e280 */

void Vector_quickSortCustomCompare
               (long *param_1,undefined *param_2,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  FUN_0012d260(*param_1,0,(int)param_1[3] + -1,param_2,param_r8,param_r9);
  return;
}


/* Vector_delete @ 0x12e330 */

void Vector_delete(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                  long param_r9)

{
  long *a0;
  void *__ptr;
  ulong a2;
  ulong extraout_RDX;
  long lVar1;

  __ptr = (void *)*param_1;
  if ((*(char *)((long)param_1 + 0x24) != '\0') &&
     (a2 = (ulong)*(uint *)(param_1 + 3), 0 < (int)*(uint *)(param_1 + 3))) {
    lVar1 = 0;
    do {
      a0 = *(long **)((long)__ptr + lVar1 * 8);
      if (a0 != (long *)0x0) {
        (**(code **)(*a0 + 0x10))((long)a0,param_rsi,a2,param_rcx,param_r8,param_r9);
        __ptr = (void *)*param_1;
        a2 = extraout_RDX;
      }
      lVar1 = lVar1 + 1;
    } while ((int)lVar1 < (int)param_1[3]);
  }
  free(__ptr);
  free(param_1);
  return;
}


/* Vector_prune @ 0x12e3c0 */

void Vector_prune(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long *a0;
  void *__s;
  ulong a2;
  ulong extraout_RDX;
  long lVar1;

  __s = (void *)*param_1;
  if ((*(char *)((long)param_1 + 0x24) != '\0') &&
     (a2 = (ulong)*(uint *)(param_1 + 3), 0 < (int)*(uint *)(param_1 + 3))) {
    lVar1 = 0;
    do {
      a0 = *(long **)((long)__s + lVar1 * 8);
      if (a0 != (long *)0x0) {
        (**(code **)(*a0 + 0x10))((long)a0,param_rsi,a2,param_rcx,param_r8,param_r9);
        __s = (void *)*param_1;
        a2 = extraout_RDX;
      }
      lVar1 = lVar1 + 1;
    } while ((int)lVar1 < (int)param_1[3]);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[3] = -0x100000000;
  memset(__s,0,(long)(int)param_1[2] << 3);
  return;
}


/* Vector_insertionSort @ 0x12e430 */

void Vector_insertionSort
               (long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  long *plVar1;
  code *pcVar2;
  long a1;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  ulong extraout_RDX;
  ulong uVar7;
  ulong uVar8;

  plVar1 = (long *)*param_1;
  pcVar2 = *(code **)(param_1[1] + 0x18);
  uVar5 = (ulong)((int)param_1[3] - 1);
  if (1 < (int)param_1[3]) {
    uVar8 = 0;
    uVar6 = uVar5;
    do {
      a1 = plVar1[uVar8 + 1];
      uVar7 = uVar8;
      do {
        lVar3 = (*pcVar2)(plVar1[uVar7],a1,uVar6,param_rcx,param_r8,param_r9);
        uVar6 = extraout_RDX;
        if ((int)lVar3 < 1) {
          plVar4 = plVar1 + ((int)uVar7 + 1);
          break;
        }
        plVar1[uVar7 + 1] = plVar1[uVar7];
        uVar7 = uVar7 - 1;
        plVar4 = plVar1;
      } while ((int)uVar7 != -1);
      *plVar4 = a1;
      uVar8 = uVar8 + 1;
    } while (uVar5 != uVar8);
  }
  return;
}


/* Vector_take @ 0x12e4d0 */

undefined8 Vector_take(long *param_1,int param_2)

{
  undefined8 *__dest;
  undefined8 uVar1;
  long lVar2;
  int iVar3;

  lVar2 = *param_1;
  __dest = (undefined8 *)(lVar2 + (long)param_2 * 8);
  iVar3 = (int)param_1[3] + -1;
  uVar1 = *__dest;
  *(int *)(param_1 + 3) = iVar3;
  if (param_2 < iVar3) {
    memmove(__dest,(void *)(lVar2 + 8 + (long)param_2 * 8),(long)(iVar3 - param_2) << 3);
    lVar2 = *param_1;
    iVar3 = (int)param_1[3];
  }
  *(undefined8 *)(lVar2 + (long)iVar3 * 8) = 0;
  return uVar1;
}


/* Vector_compact @ 0x12e5f0 */

void Vector_compact(long *param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  long lVar6;

  if ((int)param_1[4] < 1) {
    return;
  }
  iVar3 = (int)param_1[3];
  iVar5 = *(int *)((long)param_1 + 0x1c);
  lVar1 = *param_1;
  if ((int)param_1[4] == 1) {
    lVar4 = (long)iVar5 * 8 + 8;
    memmove((void *)(lVar1 + -8 + lVar4),(void *)(lVar1 + lVar4),(long)((iVar3 - iVar5) + -1) << 3);
    iVar3 = (int)param_1[3];
    *(undefined8 *)(*param_1 + -8 + (long)iVar3 * 8) = 0;
  }
  else {
    if (iVar5 + 1 < iVar3) {
      lVar4 = (long)(iVar5 + 1);
      do {
        lVar2 = *(long *)(lVar1 + lVar4 * 8);
        if (lVar2 != 0) {
          lVar6 = (long)iVar5;
          iVar5 = iVar5 + 1;
          *(long *)(lVar1 + lVar6 * 8) = lVar2;
        }
        lVar4 = lVar4 + 1;
      } while ((int)lVar4 < iVar3);
    }
    memset((void *)(lVar1 + (long)iVar5 * 8),0,(long)(iVar3 - iVar5) << 3);
    iVar3 = (int)param_1[3];
  }
  *(int *)(param_1 + 3) = iVar3 - (int)param_1[4];
  *(undefined8 *)((long)param_1 + 0x1c) = 0xffffffff;
  return;
}


/* Vector_moveDown @ 0x12e6c0 */

void Vector_moveDown(long *param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;

  if ((int)param_1[3] + -1 != param_2) {
    puVar1 = (undefined8 *)(*param_1 + (long)param_2 * 8);
    uVar2 = *puVar1;
    *puVar1 = puVar1[1];
    puVar1[1] = uVar2;
  }
  return;
}


/* Vector_indexOf @ 0x12e6f0 */

ulong Vector_indexOf(long *param_1,long param_2,undefined *param_3,long param_rcx,long param_r8,
                    long param_r9)

{
  long lVar1;
  undefined *a2;
  undefined *extraout_RDX;
  ulong uVar2;

  if ((int)param_1[3] < 1) {
    return 0xffffffff;
  }
  uVar2 = 0;
  a2 = param_3;
  do {
    lVar1 = (*(code *)param_3)(param_2,*(long *)(*param_1 + uVar2 * 8),(long)a2,param_rcx,param_r8,
                               param_r9);
    if ((int)lVar1 == 0) {
      return uVar2 & 0xffffffff;
    }
    uVar2 = uVar2 + 1;
    a2 = extraout_RDX;
  } while ((int)uVar2 < (int)param_1[3]);
  return 0xffffffff;
}


/* Vector_new @ 0x132d60 */

undefined8 * Vector_new(undefined8 param_1,undefined1 param_2,int param_3)

{
  undefined8 *puVar1;
  void *pvVar2;
  size_t __nmemb;

  if (param_3 == -1) {
    puVar1 = malloc(0x28);
    if (puVar1 == (undefined8 *)0x0) goto LAB_00132e06;
    *(undefined4 *)((long)puVar1 + 0x14) = 10;
    param_3 = 10;
    __nmemb = 10;
  }
  else {
    puVar1 = malloc(0x28);
    if (puVar1 == (undefined8 *)0x0) goto LAB_00132e06;
    __nmemb = (size_t)param_3;
    *(int *)((long)puVar1 + 0x14) = param_3;
    if (__nmemb >> 0x3d != 0) goto LAB_00132e06;
  }
  pvVar2 = calloc(__nmemb,8);
  if (pvVar2 != (void *)0x0) {
    *puVar1 = pvVar2;
    *(int *)(puVar1 + 2) = param_3;
    puVar1[3] = 0xffffffff00000000;
    puVar1[1] = param_1;
    *(undefined1 *)((long)puVar1 + 0x24) = param_2;
    *(undefined4 *)(puVar1 + 4) = 0;
    return puVar1;
  }
LAB_00132e06:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Vector_insert @ 0x132ee0 */

void Vector_insert(undefined8 *param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;

  iVar3 = *(int *)(param_1 + 3);
  if (iVar3 <= param_2) {
    param_2 = iVar3;
  }
  iVar1 = *(int *)(param_1 + 2);
  pvVar2 = (void *)*param_1;
  if (iVar1 < iVar3 + 1) {
    iVar3 = iVar3 + 1 + *(int *)((long)param_1 + 0x14);
    *(int *)(param_1 + 2) = iVar3;
    pvVar2 = xReallocArrayZero(pvVar2,(long)iVar1,(long)iVar3,8);
    *param_1 = pvVar2;
    iVar3 = *(int *)(param_1 + 3);
  }
  if (param_2 < iVar3) {
    memmove((void *)((long)pvVar2 + (long)param_2 * 8 + 8),
            (void *)((long)pvVar2 + (long)param_2 * 8),(long)(iVar3 - param_2) << 3);
    pvVar2 = (void *)*param_1;
    iVar3 = *(int *)(param_1 + 3);
  }
  *(undefined8 *)((long)pvVar2 + (long)param_2 * 8) = param_3;
  *(int *)(param_1 + 3) = iVar3 + 1;
  return;
}


/* Vector_set @ 0x1330c0 */

void Vector_set(long *param_1,int param_2,long param_3,long param_rcx,long param_r8,long param_r9)

{
  long *a0;
  void *pvVar1;
  int iVar2;
  ulong a1;
  long *plVar3;
  int iVar4;

  iVar4 = param_2 + 1;
  a1 = (ulong)(int)param_1[2];
  pvVar1 = (void *)*param_1;
  if ((int)param_1[2] < iVar4) {
    param_rcx = 8;
    iVar2 = *(int *)((long)param_1 + 0x14) + iVar4;
    *(int *)(param_1 + 2) = iVar2;
    pvVar1 = xReallocArrayZero(pvVar1,a1,(long)iVar2,8);
    *param_1 = (long)pvVar1;
  }
  plVar3 = (long *)((long)pvVar1 + (long)param_2 * 8);
  if (param_2 < (int)param_1[3]) {
    if ((*(char *)((long)param_1 + 0x24) != '\0') && (a0 = (long *)*plVar3, a0 != (long *)0x0)) {
      (**(code **)(*a0 + 0x10))((long)a0,a1,*a0,param_rcx,param_r8,param_r9);
      plVar3 = (long *)(*param_1 + (long)param_2 * 8);
    }
  }
  else {
    *(int *)(param_1 + 3) = iVar4;
  }
  *plVar3 = param_3;
  return;
}


/* Vector_add @ 0x135420 */

void Vector_add(long *param_1,long param_2,long param_rdx,long param_rcx,long param_r8,long param_r9
               )

{
  int iVar1;
  long *a0;
  void *pvVar2;
  long a3;
  int iVar3;
  ulong a1;
  long *plVar4;
  long lVar5;
  int iVar6;

  iVar1 = (int)param_1[3];
  a1 = (ulong)(int)param_1[2];
  pvVar2 = (void *)*param_1;
  iVar6 = iVar1 + 1;
  lVar5 = (long)iVar1 * 8;
  if ((int)param_1[2] < iVar6) {
    a3 = 8;
    iVar3 = *(int *)((long)param_1 + 0x14) + iVar6;
    *(int *)(param_1 + 2) = iVar3;
    pvVar2 = xReallocArrayZero(pvVar2,a1,(long)iVar3,8);
    *param_1 = (long)pvVar2;
    if (iVar1 < (int)param_1[3]) {
      plVar4 = (long *)((long)pvVar2 + lVar5);
      if ((*(char *)((long)param_1 + 0x24) != '\0') && (a0 = (long *)*plVar4, a0 != (long *)0x0)) {
        (**(code **)(*a0 + 0x10))((long)a0,a1,*a0,a3,param_r8,param_r9);
        plVar4 = (long *)(*param_1 + lVar5);
      }
      goto LAB_0013545e;
    }
  }
  *(int *)(param_1 + 3) = iVar6;
  plVar4 = (long *)((long)pvVar2 + lVar5);
LAB_0013545e:
  *plVar4 = param_2;
  return;
}


/* Vector_splice @ 0x1354c0 */

void Vector_splice(long *param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  void *pvVar6;
  int iVar7;

  lVar3 = param_1[3];
  lVar4 = param_1[2];
  iVar7 = (int)param_2[3] + (int)lVar3;
  if ((int)lVar4 < iVar7) {
    iVar7 = iVar7 + *(int *)((long)param_1 + 0x14);
    *(int *)(param_1 + 2) = iVar7;
    pvVar6 = xReallocArrayZero((void *)*param_1,(long)(int)lVar4,(long)iVar7,8);
    iVar7 = (int)param_2[3] + (int)param_1[3];
    *param_1 = (long)pvVar6;
  }
  *(int *)(param_1 + 3) = iVar7;
  lVar4 = param_2[3];
  if (0 < (int)lVar4) {
    lVar1 = *param_1;
    lVar2 = *param_2;
    lVar5 = 0;
    do {
      *(undefined8 *)(lVar1 + (long)(int)lVar3 * 8 + lVar5) = *(undefined8 *)(lVar2 + lVar5);
      lVar5 = lVar5 + 8;
    } while ((long)(int)lVar4 * 8 != lVar5);
  }
  return;
}

