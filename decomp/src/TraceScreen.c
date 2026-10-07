#include "htop.h"

/* TraceScreen_forkTracer @ 0x12e8e0 */

undefined8 TraceScreen_forkTracer(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  __pid_t _Var2;
  FILE *pFVar3;
  undefined8 uVar4;
  undefined4 extraout_var;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(int (*)[2])(__fp - 0x60))[0] = 0;
  (*(int (*)[2])(__fp - 0x60))[1] = 0;
  iVar1 = pipe((*(int (*)[2])(__fp - 0x60)));
  if (iVar1 != -1) {
    iVar1 = fcntl((*(int (*)[2])(__fp - 0x60))[0],4,0x800);
    if (-1 < iVar1) {
      iVar1 = fcntl((*(int (*)[2])(__fp - 0x60))[1],4,0x800);
      if (-1 < iVar1) {
        _Var2 = fork();
        if (_Var2 != -1) {
          if (_Var2 == 0) {
            close((*(int (*)[2])(__fp - 0x60))[0]);
            dup2((*(int (*)[2])(__fp - 0x60))[1],1);
            dup2((*(int (*)[2])(__fp - 0x60))[1],2);
            close((*(int (*)[2])(__fp - 0x60))[1]);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x58)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x48)), (undefined16)0x0);
            iVar1 = xSnprintf((*(undefined1 (*)[16])(__fp - 0x58)),0x20,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),*(int *)(*(long *)(param_1 + 8) + 0x10));
            execlp(((char *)(long)(__sec_rodata + 0xff8) /* "strace" */),((char *)(long)(__sec_rodata + 0xff8) /* "strace" */),&DAT_00148c3c,&DAT_00148c38,&DAT_00148c35,&DAT_00148c31,
                   &DAT_001488f5,(*(undefined1 (*)[16])(__fp - 0x58)),0,CONCAT44(extraout_var,iVar1));
            write(2,((char *)(long)&s_Could_not_execute__strace___Plea_0014c6c0 /* "Could not execute \'strace\'. Please make sure it is available in your $PATH." */),
                  0x4b);
                    /* WARNING: Subroutine does not return */
            exit(0x7f);
          }
          pFVar3 = fdopen((*(int (*)[2])(__fp - 0x60))[0],((char *)(long)&DAT_00147760 /* "r" */));
          if (pFVar3 != (FILE *)0x0) {
            close((*(int (*)[2])(__fp - 0x60))[1]);
            *(__pid_t *)(param_1 + 0x2c) = _Var2;
            uVar4 = 1;
            *(FILE **)(param_1 + 0x30) = pFVar3;
            goto LAB_0012e9a2;
          }
        }
      }
    }
    close((*(int (*)[2])(__fp - 0x60))[1]);
    close((*(int (*)[2])(__fp - 0x60))[0]);
  }
  uVar4 = 0;
LAB_0012e9a2:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0012ea80 @ 0x12ea80 */

void FUN_0012ea80(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long extraout_RDX;

  iVar1 = (int)(*(long **)((long)param_1 + 0x20))[3];
  if (0 < iVar1) {
    plVar3 = (long *)**(long **)((long)param_1 + 0x20);
    param_rcx = (long)(plVar3 + iVar1);
    do {
      lVar2 = *plVar3;
      plVar3 = plVar3 + 1;
      *(undefined8 *)(lVar2 + 0x20) = 0;
    } while (plVar3 != (long *)param_rcx);
  }
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


/* FUN_0012eb10 @ 0x12eb10 */

void FUN_0012eb10(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
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


/* FUN_0012eb70 @ 0x12eb70 */

void FUN_0012eb70(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long extraout_RDX;

  iVar1 = (int)(*(long **)((long)param_1 + 0x20))[3];
  if (0 < iVar1) {
    plVar3 = (long *)**(long **)((long)param_1 + 0x20);
    param_rcx = (long)(plVar3 + iVar1);
    do {
      lVar2 = *plVar3;
      plVar3 = plVar3 + 1;
      *(undefined8 *)(lVar2 + 0x18) = 0;
    } while (plVar3 != (long *)param_rcx);
  }
  if (*(long *)((long)param_1 + 0x2720) != 0) {
    *(undefined8 *)(*(long *)((long)param_1 + 0x2720) + 8) = *(undefined8 *)((long)param_1 + 10000);
  }
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


/* TraceScreen_delete @ 0x12ec10 */

void TraceScreen_delete(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                       long param_r9)

{
  void *pvVar1;
  __pid_t _Var2;
  int *piVar3;
  long extraout_RDX;
  long extraout_RDX_00;

  if (0 < *(__pid_t *)((long)param_1 + 0x2c)) {
    kill(*(__pid_t *)((long)param_1 + 0x2c),0xf);
    do {
      param_rsi = 0;
      _Var2 = waitpid(*(__pid_t *)((long)param_1 + 0x2c),(int *)0x0,0);
      if (_Var2 != -1) break;
      piVar3 = __errno_location();
    } while (*piVar3 == 4);
  }
  if (*(FILE **)((long)param_1 + 0x30) != (FILE *)0x0) {
    fclose(*(FILE **)((long)param_1 + 0x30));
  }
  halfdelay(*PTR_0015c0d0);
  pvVar1 = *(void **)((long)param_1 + 0x10);
  free(*(void **)((long)pvVar1 + 0x38));
  Vector_delete(*(long **)((long)pvVar1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x58));
  if (0x15e < *(int *)((long)pvVar1 + 0x60)) {
    free(*(void **)((long)pvVar1 + 0x68));
  }
  free(pvVar1);
  pvVar1 = *(void **)((long)param_1 + 0x18);
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x88));
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x120));
  free(pvVar1);
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX_00,param_rcx,param_r8,
                param_r9);
  free(param_1);
  return;
}


/* TraceScreen_new @ 0x132bb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * TraceScreen_new(undefined8 param_1)

{
  undefined8 *puVar1;
  wint_t *pwVar2;
  void *pvVar3;

  puVar1 = calloc(1,0x40);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined1 *)(puVar1 + 5) = 1;
    *puVar1 = TraceScreen_class;
    pwVar2 = FunctionBar_new(&PTR_s_Search_00157d40,(long)&PTR_DAT_00157d00,(long)&DAT_0014e140);
    nocbreak();
    cbreak();
    nodelay(_stdscr,1);
    pvVar3 = (void *)InfoScreen_init((long)puVar1,param_1,pwVar2,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
    return pvVar3;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

