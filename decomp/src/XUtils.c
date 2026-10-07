#include "htop.h"

/* fail @ 0x1300c0 */

void fail(void)

{
  CRT_done();
                    /* WARNING: Subroutine does not return */
  abort();
}


/* xRealloc @ 0x1300e0 */

void xRealloc(void *param_1,size_t param_2)

{
  void *pvVar1;

  pvVar1 = realloc(param_1,param_2);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  free(param_1);
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xMalloc @ 0x130110 */

void xMalloc(size_t param_1)

{
  void *pvVar1;

  pvVar1 = malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00130130 @ 0x130130 */

void FUN_00130130(int *param_1,int param_2)

{
  int *__dest;
  int iVar1;
  long lVar2;
  void *pvVar3;
  void *pvVar4;
  long lVar5;
  size_t sVar6;
  long lVar7;

  iVar1 = *param_1;
  if (param_2 < 0x15e) {
    lVar5 = (long)param_2;
    lVar7 = *(long *)(param_1 + 2);
    lVar2 = lVar5 * 0x1c;
    if (iVar1 < 0x15e) {
      *(undefined16 *)(*(undefined1 (*) [16])(lVar7 + lVar2)) = (undefined16)0x0;
      *(undefined16 *)(*(undefined1 (*) [16])(lVar7 + 0xc + lVar2)) = (undefined16)0x0;
      goto LAB_00130187;
    }
    if (iVar1 != 0x15e) goto LAB_00130248;
  }
  else {
    if (0x15e < iVar1) {
      pvVar3 = *(void **)(param_1 + 2);
      if (param_2 != 0x15e) {
        sVar6 = (long)(param_2 + 1) * 0x1c;
        pvVar4 = realloc(pvVar3,sVar6);
        if (pvVar4 == (void *)0x0) {
          free(pvVar3);
          goto LAB_001302f7;
        }
        *(void **)(param_1 + 2) = pvVar4;
        *(undefined16 *)(*(undefined1 (*) [16])((long)pvVar4 + (sVar6 - 0x1c))) = (undefined16)0x0;
        *(undefined16 *)(*(undefined1 (*) [16])((long)pvVar4 + (sVar6 - 0x10))) = (undefined16)0x0;
        goto LAB_00130187;
      }
      lVar5 = 0x15e;
LAB_00130248:
      pvVar3 = *(void **)(param_1 + 2);
      __dest = param_1 + 4;
      memcpy(__dest,pvVar3,lVar5 * 0x1c);
      free(pvVar3);
      *(int **)(param_1 + 2) = __dest;
      *(undefined16 *)(*(undefined1 (*) [16])(__dest + lVar5 * 7)) = (undefined16)0x0;
      *(undefined16 *)(*(undefined1 (*) [16])(param_1 + lVar5 * 7 + 7)) = (undefined16)0x0;
      goto LAB_00130187;
    }
    if (param_2 != 0x15e) {
      sVar6 = (long)(param_2 + 1) * 0x1c;
      pvVar3 = malloc(sVar6);
      if (pvVar3 == (void *)0x0) {
LAB_001302f7:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      *(void **)(param_1 + 2) = pvVar3;
      __memcpy_chk(pvVar3,param_1 + 4,(long)iVar1 * 0x1c,sVar6);
      *(undefined16 *)(*(undefined1 (*) [16])((long)pvVar3 + (sVar6 - 0x1c))) = (undefined16)0x0;
      *(undefined16 *)(*(undefined1 (*) [16])((long)pvVar3 + (sVar6 - 0x10))) = (undefined16)0x0;
      goto LAB_00130187;
    }
    lVar7 = *(long *)(param_1 + 2);
    lVar2 = 0x2648;
  }
  *(undefined16 *)(*(undefined1 (*) [16])(lVar7 + lVar2)) = (undefined16)0x0;
  *(undefined16 *)(*(undefined1 (*) [16])(lVar7 + 0xc + lVar2)) = (undefined16)0x0;
LAB_00130187:
  *param_1 = param_2;
  return;
}


/* xCalloc @ 0x132160 */

void * xCalloc(ulong param_1,size_t param_2)

{
  undefined16 auVar1;
  undefined16 auVar2;
  void *pvVar3;

  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = param_2;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = param_1;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    pvVar3 = calloc(param_1,param_2);
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xReallocArray @ 0x1328c0 */

void xReallocArray(void *param_1,ulong param_2,ulong param_3)

{
  undefined16 auVar1;
  undefined16 auVar2;
  void *pvVar3;

  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = param_3;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = param_2;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    pvVar3 = realloc(param_1,SUB168(auVar1 * auVar2,0));
    if (pvVar3 != (void *)0x0) {
      return;
    }
    free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xMallocArray @ 0x132e10 */

void xMallocArray(ulong param_1,ulong param_2)

{
  undefined16 auVar1;
  undefined16 auVar2;
  void *pvVar3;

  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = param_2;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = param_1;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    pvVar3 = malloc(SUB168(auVar1 * auVar2,0));
    if (pvVar3 != (void *)0x0) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xReallocArrayZero @ 0x132e40 */

void * xReallocArrayZero(void *param_1,ulong param_2,ulong param_3,ulong param_4)

{
  undefined16 auVar1;
  undefined16 auVar2;
  size_t __size;
  void *pvVar3;
  ulong uVar4;

  if (param_2 == param_3) {
    return param_1;
  }
  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = param_3;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = param_4;
  __size = SUB168(auVar1 * auVar2,0);
  if (SUB168(auVar1 * auVar2,8) == 0) {
    pvVar3 = realloc(param_1,__size);
    if (pvVar3 != (void *)0x0) {
      if (param_3 <= param_2) {
        return pvVar3;
      }
      uVar4 = param_2 * param_4;
      if (__size <= uVar4) {
        __size = uVar4;
      }
      __memset_chk((void *)(uVar4 + (long)pvVar3),0,(param_3 - param_2) * param_4,__size - uVar4);
      return pvVar3;
    }
    free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xReadfile @ 0x13ac50 */

long xReadfile(char *param_1,undefined1 *param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  int *piVar3;

  iVar1 = open(param_1,0);
  if (-1 < iVar1) {
    lVar2 = FUN_0013a450(iVar1,param_2,param_3);
    return lVar2;
  }
  piVar3 = __errno_location();
  return (long)-*piVar3;
}


/* xReadfileat @ 0x13ac90 */

long xReadfileat(int param_1,char *param_2,undefined1 *param_3,ulong param_4)

{
  int iVar1;
  long lVar2;
  int *piVar3;

  iVar1 = openat(param_1,param_2,0);
  if (-1 < iVar1) {
    lVar2 = FUN_0013a450(iVar1,param_3,param_4);
    return lVar2;
  }
  piVar3 = __errno_location();
  return (long)-*piVar3;
}


/* full_write @ 0x13acd0 */

long full_write(int param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  int *piVar2;
  long lVar3;

  if (param_3 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = 0;
    do {
      while( true ) {
        sVar1 = write(param_1,param_2,param_3);
        if (-1 < sVar1) break;
        piVar2 = __errno_location();
        if (*piVar2 != 4) {
          return sVar1;
        }
      }
      if (sVar1 == 0) {
        return lVar3;
      }
      lVar3 = lVar3 + sVar1;
      param_2 = (void *)((long)param_2 + sVar1);
      param_3 = param_3 - sVar1;
    } while (param_3 != 0);
  }
  return lVar3;
}


/* compareRealNumbers @ 0x13ad50 */

int compareRealNumbers(double param_1,double param_2)

{
  int iVar1;

  iVar1 = (uint)(param_2 < param_1) - (uint)(param_1 < param_2);
  if (iVar1 == 0) {
    iVar1 = (uint)!NAN(param_1) - (uint)!NAN(param_2);
  }
  return iVar1;
}


/* sumPositiveValues @ 0x13ad80 */

double sumPositiveValues(double *param_1,long param_2)

{
  double *pdVar1;
  double dVar2;

  if (param_2 != 0) {
    dVar2 = 0.0;
    pdVar1 = param_1 + param_2;
    do {
      if (0.0 < *param_1) {
        dVar2 = dVar2 + *param_1;
      }
      param_1 = param_1 + 1;
    } while (param_1 != pdVar1);
    return dVar2;
  }
  return 0.0;
}


/* xAsprintf @ 0x13cb00 */
void xAsprintf(char **strp,char *fmt,...)

{
  __builtin_va_list ap;
  int n;

  __builtin_va_start(ap,fmt);
  n = vasprintf(strp,fmt,ap);
  __builtin_va_end(ap);
  if ((n < 0) || (*strp == (char *)0x0)) {
    fail();
  }
}

/* xSnprintf @ 0x13cbe0 */
int xSnprintf(char *buf,ulong len,char *fmt,...)

{
  __builtin_va_list ap;
  int n;

  __builtin_va_start(ap,fmt);
  n = vsnprintf(buf,len,fmt,ap);
  __builtin_va_end(ap);
  if ((n < 0) || ((ulong)(long)n >= len)) {
    fail();
  }
  return n;
}

/* xStrdup @ 0x13e040 */

void xStrdup(char *param_1)

{
  char *pcVar1;

  pcVar1 = strdup(param_1);
  if (pcVar1 != (char *)0x0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* free_and_xStrdup @ 0x13e060 */

void free_and_xStrdup(undefined8 *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = (char *)*param_1;
  if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,param_2), iVar1 == 0)) {
    return;
  }
  free(pcVar2);
  pcVar2 = strdup(param_2);
  if (pcVar2 != (char *)0x0) {
    *param_1 = pcVar2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xStrndup @ 0x13e0c0 */

void xStrndup(char *param_1,size_t param_2)

{
  char *pcVar1;

  pcVar1 = strndup(param_1,param_2);
  if (pcVar1 != (char *)0x0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

