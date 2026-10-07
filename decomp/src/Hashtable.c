#include "htop.h"

/* Hashtable_get @ 0x1159a0 */

long Hashtable_get(ulong *param_1,uint param_2)

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
        if (*puVar2 == param_2) {
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


/* Hashtable_foreach @ 0x115ba0 */

void Hashtable_foreach(ulong *param_1,undefined *param_2,long param_3,long param_rcx,long param_r8,
                      long param_r9)

{
  uint *puVar1;
  long a1;
  ulong uVar2;

  if (*param_1 != 0) {
    uVar2 = 0;
    do {
      puVar1 = (uint *)(param_1[1] + uVar2 * 0x18);
      a1 = *(long *)(puVar1 + 4);
      if (a1 != 0) {
        (*(code *)param_2)((ulong)*puVar1,a1,param_3,param_rcx,param_r8,param_r9);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_1);
    return;
  }
  return;
}


/* Hashtable_clear @ 0x117400 */

void Hashtable_clear(ulong *param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;

  uVar1 = *param_1;
  if (((char)param_1[3] != '\0') && (uVar1 != 0)) {
    uVar2 = 0;
    do {
      uVar3 = uVar2 + 1;
      free(*(void **)(param_1[1] + uVar2 * 0x18 + 0x10));
      uVar1 = *param_1;
      uVar2 = uVar3;
    } while (uVar3 < uVar1);
  }
  memset((void *)param_1[1],0,uVar1 * 0x18);
  param_1[2] = 0;
  return;
}


/* Hashtable_delete @ 0x117470 */

void Hashtable_delete(ulong *param_1)

{
  Hashtable_clear(param_1);
  free((void *)param_1[1]);
  free(param_1);
  return;
}


/* Hashtable_new @ 0x1180a0 */

ulong * Hashtable_new(ulong param_1,undefined1 param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  void *pvVar3;
  ulong __nmemb;

  puVar1 = malloc(0x20);
  if (puVar1 != (ulong *)0x0) {
    puVar1[2] = 0;
    puVar2 = &DAT_0014d120;
    if (param_1 != 0) {
      do {
        __nmemb = *puVar2;
        if (__nmemb == 0xffffffffffffffff) break;
        if (param_1 <= __nmemb) {
          *puVar1 = __nmemb;
          if (0xaaaaaaaaaaaaaaa < __nmemb) goto LAB_0011814a;
          goto LAB_001180f5;
        }
        puVar2 = puVar2 + 1;
      } while (puVar2 != (ulong *)&DAT_0014d238);
                    /* WARNING: Subroutine does not return */
      CRT_fatalError(((char *)(long)&s_Hashtable__no_prime_found_001471e8 /* "Hashtable: no prime found" */));
    }
    *puVar1 = 0xd;
    __nmemb = 0xd;
LAB_001180f5:
    pvVar3 = calloc(__nmemb,0x18);
    if (pvVar3 != (void *)0x0) {
      puVar1[1] = (ulong)pvVar3;
      *(undefined1 *)(puVar1 + 3) = param_2;
      return puVar1;
    }
  }
LAB_0011814a:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00118160 @ 0x118160 */

void FUN_00118160(ulong *param_1,ulong param_2)

{
  ulong uVar1;
  uint *__ptr;
  ulong *puVar2;
  void *pvVar3;
  uint *puVar4;
  ulong uVar5;

  puVar2 = &DAT_0014d120;
  do {
    uVar5 = *puVar2;
    if (uVar5 == 0xffffffffffffffff) break;
    if (param_2 <= uVar5) {
      uVar1 = *param_1;
      if (uVar1 == uVar5) {
        return;
      }
      *param_1 = uVar5;
      __ptr = (uint *)param_1[1];
      if (uVar5 < 0xaaaaaaaaaaaaaab) {
        pvVar3 = calloc(uVar5,0x18);
        if (pvVar3 != (void *)0x0) {
          param_1[1] = (ulong)pvVar3;
          param_1[2] = 0;
          if (uVar1 != 0) {
            uVar5 = 0;
            puVar4 = __ptr;
            do {
              if (*(void **)(puVar4 + 4) != (void *)0x0) {
                FUN_00114570(param_1,*puVar4,*(void **)(puVar4 + 4));
              }
              uVar5 = uVar5 + 1;
              puVar4 = puVar4 + 6;
            } while (uVar1 != uVar5);
          }
          free(__ptr);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 != (ulong *)&DAT_0014d238);
                    /* WARNING: Subroutine does not return */
  CRT_fatalError(((char *)(long)&s_Hashtable__no_prime_found_001471e8 /* "Hashtable: no prime found" */));
}


/* Hashtable_setSize @ 0x118260 */

void Hashtable_setSize(ulong *param_1,ulong param_2)

{
  if (param_2 <= param_1[2]) {
    return;
  }
  FUN_00118160(param_1,param_2);
  return;
}


/* Hashtable_put @ 0x118280 */

void Hashtable_put(ulong *param_1,uint param_2,void *param_3)

{
  ulong uVar1;

  uVar1 = *param_1;
  if (uVar1 * 7 < param_1[2] * 10) {
    if ((long)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      CRT_fatalError(((char *)(long)&s_Hashtable__size_overflow_00147202 /* "Hashtable: size overflow" */));
    }
    if (param_1[2] < uVar1 * 2) {
      FUN_00118160(param_1,uVar1 * 2);
    }
  }
  FUN_00114570(param_1,param_2,param_3);
  return;
}


/* Hashtable_remove @ 0x118300 */

void * Hashtable_remove(ulong *param_1,uint param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  void *__ptr;
  void *pvVar11;

  uVar7 = *param_1;
  uVar10 = param_1[1];
  uVar8 = (ulong)param_2 % uVar7;
  puVar6 = (uint *)(uVar10 + uVar8 * 0x18);
  __ptr = *(void **)(puVar6 + 4);
  if (__ptr != (void *)0x0) {
    uVar9 = 0;
    do {
      if (*puVar6 == param_2) {
        pvVar11 = __ptr;
        if ((char)param_1[3] != '\0') {
          pvVar11 = (void *)0x0;
          free(__ptr);
          uVar10 = param_1[1];
          uVar7 = *param_1;
        }
        uVar9 = (uVar8 + 1) % uVar7;
        puVar1 = (undefined8 *)(uVar10 + uVar9 * 0x18);
        lVar3 = puVar1[2];
        goto joined_r0x001183a0;
      }
      if (*(ulong *)(puVar6 + 2) < uVar9) {
        uVar9 = param_1[2];
        __ptr = (void *)0x0;
        goto LAB_00118417;
      }
      uVar9 = uVar9 + 1;
      uVar8 = (uVar8 + 1) % uVar7;
      puVar6 = (uint *)(uVar10 + uVar8 * 0x18);
      __ptr = *(void **)(puVar6 + 4);
    } while (__ptr != (void *)0x0);
  }
  uVar9 = param_1[2];
LAB_00118417:
  if ((uVar9 * 8 < uVar7) && (uVar9 < uVar7 / 3)) {
    FUN_00118160(param_1,uVar7 / 3);
  }
  return __ptr;
joined_r0x001183a0:
  uVar5 = uVar9;
  if (lVar3 == 0) goto LAB_001183ff;
  lVar3 = puVar1[1];
  puVar2 = (undefined8 *)(uVar10 + uVar8 * 0x18);
  if (lVar3 == 0) goto LAB_001183ff;
  uVar4 = puVar1[1];
  *puVar2 = *puVar1;
  puVar2[1] = uVar4;
  uVar4 = puVar1[2];
  puVar2[1] = lVar3 + -1;
  puVar2[2] = uVar4;
  uVar9 = (uVar5 + 1) % uVar7;
  puVar1 = (undefined8 *)(uVar10 + uVar9 * 0x18);
  lVar3 = puVar1[2];
  uVar8 = uVar5;
  goto joined_r0x001183a0;
LAB_001183ff:
  uVar9 = param_1[2];
  *(undefined8 *)(uVar10 + 0x10 + uVar8 * 0x18) = 0;
  uVar9 = uVar9 - 1;
  param_1[2] = uVar9;
  __ptr = pvVar11;
  goto LAB_00118417;
}

