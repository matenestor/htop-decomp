#include "htop.h"

/* DynamicScreens_new @ 0x116e60 */

undefined8 DynamicScreens_new(void)

{
  return 0;
}


/* DynamicScreens_delete @ 0x117520 */

void DynamicScreens_delete(ulong *param_1)

{
  if (param_1 != (ulong *)0x0) {
    Hashtable_clear(param_1);
    free((void *)param_1[1]);
    free(param_1);
    return;
  }
  return;
}


/* FUN_00117560 @ 0x117560 */

void FUN_00117560(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* FUN_001175c0 @ 0x1175c0 */

void FUN_001175c0(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 8));
  free(*(void **)((long)param_1 + 0x10));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  free(param_1);
  return;
}


/* FUN_00117600 @ 0x117600 */

void FUN_00117600(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar1;
  long extraout_RDX_01;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  lVar1 = extraout_RDX_00;
  if (0x15e < *(int *)((long)param_1 + 0x60)) {
    free(*(void **)((long)param_1 + 0x68));
    *(long *)((long)param_1 + 0x68) = (long)param_1 + 0x70;
    lVar1 = extraout_RDX_01;
  }
  Vector_delete(*(long **)((long)param_1 + 0x26f0),param_rsi,lVar1,param_rcx,param_r8,param_r9);
  free(param_1);
  return;
}


/* FUN_00117670 @ 0x117670 */

void FUN_00117670(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (0x15e < *(int *)((long)param_1 + 0x60)) {
    free(*(void **)((long)param_1 + 0x68));
  }
  free(*(void **)((long)param_1 + 0x2700));
  free(param_1);
  return;
}


/* FUN_001176d0 @ 0x1176d0 */

void FUN_001176d0(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* FUN_00117730 @ 0x117730 */

void FUN_00117730(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* FUN_00117790 @ 0x117790 */

void FUN_00117790(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}

