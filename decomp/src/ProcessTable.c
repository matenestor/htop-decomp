#include "htop.h"

/* ProcessTable_getProcess @ 0x122fc0 */

void ProcessTable_getProcess(long param_1,uint param_2,undefined1 *param_3,undefined *param_4)

{
  ulong uVar1;
  uint *a4;
  long lVar2;
  uint *a3;
  ulong a2;
  undefined4 in_register_00000034;
  ulong a1;

  a1 = CONCAT44(in_register_00000034,param_2);
  uVar1 = **(ulong **)(param_1 + 0x18);
  a4 = (uint *)(*(ulong **)(param_1 + 0x18))[1];
  a2 = (ulong)param_2 % uVar1;
  a3 = a4 + a2 * 6;
  if (*(long *)(a3 + 4) != 0) {
    a1 = 0;
    do {
      while( true ) {
        if (param_2 == *a3) {
          *param_3 = 1;
          return;
        }
        if (*(ulong *)(a3 + 2) < a1) goto LAB_0012303a;
        a2 = a2 + 1;
        if (uVar1 != a2) break;
        a2 = 0;
        a1 = a1 + 1;
        a3 = a4;
        if (*(long *)(a4 + 4) == 0) goto LAB_0012303a;
      }
      a1 = a1 + 1;
      a3 = a4 + a2 * 6;
    } while (*(long *)(a3 + 4) != 0);
  }
LAB_0012303a:
  *param_3 = 0;
  lVar2 = (*(code *)param_4)(*(long *)(param_1 + 0x20),a1,a2,(long)a3,(long)a4,param_1);
  *(uint *)(lVar2 + 0x10) = param_2;
  return;
}


/* ProcessTable_init @ 0x12cff0 */

void ProcessTable_init(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  void *pvVar2;
  ulong *puVar3;

  puVar1 = malloc(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)((long)puVar1 + 0x14) = 10;
    pvVar2 = calloc(10,8);
    if (pvVar2 != (void *)0x0) {
      *puVar1 = pvVar2;
      *(undefined4 *)(puVar1 + 2) = 10;
      puVar1[1] = param_2;
      *(undefined1 *)((long)puVar1 + 0x24) = 1;
      puVar1[3] = 0xffffffff00000000;
      *(undefined4 *)(puVar1 + 4) = 0;
      *(undefined8 **)(param_1 + 8) = puVar1;
      puVar1 = malloc(0x28);
      if (puVar1 != (undefined8 *)0x0) {
        *(undefined4 *)((long)puVar1 + 0x14) = 10;
        pvVar2 = calloc(10,8);
        if (pvVar2 != (void *)0x0) {
          puVar1[1] = param_2;
          puVar1[3] = 0xffffffff00000000;
          *(undefined8 **)(param_1 + 0x10) = puVar1;
          *puVar1 = pvVar2;
          *(undefined4 *)(puVar1 + 2) = 10;
          *(undefined1 *)((long)puVar1 + 0x24) = 0;
          *(undefined4 *)(puVar1 + 4) = 0;
          puVar3 = Hashtable_new(200,0);
          *(undefined1 *)(param_1 + 0x30) = 1;
          *(ulong **)(param_1 + 0x18) = puVar3;
          *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
          *(undefined8 *)(param_1 + 0x20) = param_3;
          *(undefined8 *)(param_1 + 0x40) = param_4;
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ProcessTable_done @ 0x12d110 */

void ProcessTable_done(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                      long param_r9)

{
  ulong *__ptr;
  long extraout_RDX;
  long extraout_RDX_00;

  __ptr = *(ulong **)(param_1 + 0x18);
  Hashtable_clear(__ptr);
  free((void *)__ptr[1]);
  free(__ptr);
  Vector_delete(*(long **)(param_1 + 0x10),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  Vector_delete(*(long **)(param_1 + 8),param_rsi,extraout_RDX_00,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0012d160 @ 0x12d160 */

void FUN_0012d160(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;

  plVar1 = *(long **)(param_1 + 0x20);
  plVar6 = *(long **)(param_1 + 8);
  lVar2 = *plVar1;
  iVar4 = (int)plVar6[3] + -1;
  if (-1 < iVar4) {
    lVar7 = (long)iVar4 << 3;
    do {
      lVar3 = *(long *)(*plVar6 + lVar7);
      Process_makeCommandStr(lVar3,lVar2);
      if (*(uint *)((long)plVar1 + 0x8c) < *(uint *)(lVar3 + 0x60)) {
        *(uint *)((long)plVar1 + 0x8c) = *(uint *)(lVar3 + 0x60);
      }
      iVar5 = iVar4 + -1;
      Table_cleanupRow(param_1,lVar3,iVar4,param_rcx,param_r8,param_r9);
      lVar7 = lVar7 + -8;
      plVar6 = *(long **)(param_1 + 8);
      iVar4 = iVar5;
    } while (iVar5 != -1);
  }
  Vector_compact(plVar6);
  return;
}


/* ProcessTable_new @ 0x143ba0 */

undefined8 * ProcessTable_new(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  void *pvVar4;
  ulong *puVar5;

  puVar2 = calloc(1,0x78);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = ProcessTable_class;
    puVar3 = malloc(0x28);
    if (puVar3 != (undefined8 *)0x0) {
      *(undefined4 *)((long)puVar3 + 0x14) = 10;
      pvVar4 = calloc(10,8);
      if (pvVar4 != (void *)0x0) {
        *puVar3 = pvVar4;
        *(undefined4 *)(puVar3 + 2) = 10;
        *(undefined1 *)((long)puVar3 + 0x24) = 1;
        puVar3[1] = LinuxProcess_class;
        puVar3[3] = 0xffffffff00000000;
        *(undefined4 *)(puVar3 + 4) = 0;
        puVar2[1] = puVar3;
        puVar3 = malloc(0x28);
        if (puVar3 != (undefined8 *)0x0) {
          *(undefined4 *)((long)puVar3 + 0x14) = 10;
          pvVar4 = calloc(10,8);
          if (pvVar4 != (void *)0x0) {
            *puVar3 = pvVar4;
            puVar3[3] = 0xffffffff00000000;
            puVar2[2] = puVar3;
            *(undefined4 *)(puVar3 + 2) = 10;
            puVar3[1] = LinuxProcess_class;
            *(undefined1 *)((long)puVar3 + 0x24) = 0;
            *(undefined4 *)(puVar3 + 4) = 0;
            puVar5 = Hashtable_new(200,0);
            puVar2[4] = param_1;
            puVar2[3] = puVar5;
            puVar2[8] = param_2;
            *(undefined1 *)(puVar2 + 6) = 1;
            *(undefined4 *)((long)puVar2 + 0x34) = 0xffffffff;
            FUN_0013e910((long)puVar2);
            iVar1 = access(((char *)(long)&s__proc_self_smaps_rollup_0014a066 /* "/proc/self/smaps_rollup" */),4);
            *(bool *)(puVar2 + 0xc) = iVar1 == 0;
            return puVar2;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ProcessTable_delete @ 0x143d00 */

void ProcessTable_delete(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                        long param_r9)

{
  ulong *__ptr;
  long *__ptr_00;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar1;
  void *__ptr_01;

  __ptr = *(ulong **)((long)param_1 + 0x18);
  Hashtable_clear(__ptr);
  free((void *)__ptr[1]);
  free(__ptr);
  Vector_delete(*(long **)((long)param_1 + 0x10),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  Vector_delete(*(long **)((long)param_1 + 8),param_rsi,extraout_RDX_00,param_rcx,param_r8,param_r9)
  ;
  __ptr_00 = *(long **)((long)param_1 + 0x58);
  if (__ptr_00 != (long *)0x0) {
    __ptr_01 = (void *)*__ptr_00;
    if (__ptr_01 != (void *)0x0) {
      lVar1 = 0x18;
      do {
        free(__ptr_01);
        __ptr_00 = *(long **)((long)param_1 + 0x58);
        __ptr_01 = *(void **)((long)__ptr_00 + lVar1);
        lVar1 = lVar1 + 0x18;
      } while (__ptr_01 != (void *)0x0);
    }
    free(__ptr_00);
  }
  if (*(void **)((long)param_1 + 0x68) != (void *)0x0) {
    nl_close(*(void **)((long)param_1 + 0x68));
    nl_socket_free(*(void **)((long)param_1 + 0x68));
  }
  free(param_1);
  return;
}


/* FUN_00143db0 @ 0x143db0 */

undefined8 FUN_00143db0(long param_1,int param_2)

{
  undefined1 __frame[0x1178] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1138;
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  char *pcVar7;
  ssize_t sVar8;
  size_t sVar9;
  undefined8 uVar10;
  int *piVar11;
  int iVar12;
  ulong uVar13;
  char *pcVar14;
  ulong uVar15;
  int iVar16;
  int iVar17;
  char cVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar22;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = openat(param_2,((char *)(long)(__sec_rodata + 0x2306) /* "cmdline" */),0);
  if (iVar2 < 0) {
    piVar11 = __errno_location();
    uVar5 = (ulong)-*piVar11;
  }
  else {
    uVar5 = FUN_0013a450(iVar2,(*(char (*)[4104])(__fp - 0x1048)),0x1001);
  }
  if (0 < (long)uVar5) {
    uVar13 = 1;
    bVar1 = false;
    bVar22 = false;
    iVar2 = 0;
    uVar15 = 0;
    iVar3 = 0;
    do {
      iVar12 = (int)uVar15;
      pcVar7 = (char *)((long)(*(struct stat *)(__fp - 0x10d8)).__unused + uVar13 + 0x17);
      iVar16 = (int)uVar13 + -1;
      cVar18 = *pcVar7;
      if (cVar18 == '\0') {
        *pcVar7 = '\n';
        if (iVar3 == 0) {
          iVar3 = iVar16;
        }
LAB_00143e4a:
        iVar12 = (int)uVar15;
      }
      else {
        if (iVar3 == 0) {
          if (cVar18 < '!') {
            if (cVar18 == '\n') {
              bVar1 = true;
              iVar3 = iVar16;
            }
            else {
              bVar1 = true;
              iVar2 = iVar16;
            }
          }
          else {
            iVar2 = iVar16;
            if (cVar18 == '/') {
              uVar15 = uVar13 & 0xffffffff;
            }
          }
          goto LAB_00143e4a;
        }
        if (cVar18 < '!') {
          bVar1 = true;
          bVar22 = true;
          if (cVar18 != '\n') {
            iVar2 = iVar16;
          }
          goto LAB_00143e4a;
        }
        bVar22 = true;
        iVar2 = iVar16;
      }
      if (uVar5 == uVar13) goto LAB_00143e90;
      uVar13 = uVar13 + 1;
    } while( true );
  }
  uVar10 = 0;
  goto LAB_00144138;
LAB_00143e90:
  iVar16 = iVar2 + 1;
  pcVar7 = (*(char (*)[4104])(__fp - 0x1048));
  (*(char (*)[4104])(__fp - 0x1048))[iVar16] = '\0';
  if ((bVar22) || (!bVar1)) {
LAB_00143ff0:
    iVar2 = iVar16;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
  else {
    uVar5 = (ulong)(*(undefined8 *)(__fp - 0x10e8)) >> 0x20;
    (*(undefined8 *)(__fp - 0x10e8)) = (char *)CONCAT44((int)uVar5,iVar16);
    (*(int * *)(__fp - 0x10e0)) = __errno_location();
    *(*(int * *)(__fp - 0x10e0)) = 0;
    iVar3 = faccessat(-100,pcVar7,0,0x100);
    iVar16 = (int)(*(undefined8 *)(__fp - 0x10e8));
    if (iVar3 != 0) {
      if (*(*(int * *)(__fp - 0x10e0)) == 0x16) {
        iVar3 = lstat(pcVar7,&(*(struct stat *)(__fp - 0x10d8)));
        iVar16 = (int)(*(undefined8 *)(__fp - 0x10e8));
        if (iVar3 == 0) goto LAB_00143f26;
      }
      iVar17 = 0;
      iVar3 = 0;
      pcVar14 = pcVar7;
      iVar20 = 0;
      (*(undefined8 *)(__fp - 0x10e8)) = pcVar7;
      iVar19 = 0;
      do {
        cVar18 = *pcVar14;
        iVar21 = iVar20 + 1;
        iVar12 = iVar19;
        if (cVar18 < '!') {
          if (iVar3 == 0) {
            *pcVar14 = '\0';
            *(*(int * *)(__fp - 0x10e0)) = 0;
            iVar4 = faccessat(-100,(*(undefined8 *)(__fp - 0x10e8)),0,0x100);
            if ((iVar4 == 0) ||
               ((*(*(int * *)(__fp - 0x10e0)) == 0x16 && (iVar4 = lstat((*(undefined8 *)(__fp - 0x10e8)),&(*(struct stat *)(__fp - 0x10d8))), iVar4 == 0)))) {
              cVar18 = '\n';
              iVar3 = iVar20;
            }
            *pcVar14 = cVar18;
            if (iVar17 == 0) {
              iVar17 = iVar19;
            }
          }
          else {
            *pcVar14 = '\n';
          }
        }
        else if ((iVar3 == 0) && (iVar12 = iVar21, cVar18 != '/')) {
          if (cVar18 == '\\') {
            if ((iVar19 != 0) && (iVar12 = iVar19, (*(char (*)[4104])(__fp - 0x1048))[iVar19 + -1] == '\\')) {
              iVar12 = iVar21;
            }
          }
          else {
            iVar12 = iVar19;
            if (((cVar18 == ':') && (pcVar14[1] != '/')) && (pcVar14[1] != '\\')) {
              iVar3 = iVar20;
            }
          }
        }
        pcVar14 = pcVar14 + 1;
        iVar20 = iVar21;
        iVar19 = iVar12;
      } while (iVar21 <= iVar2);
      if (iVar3 == 0) {
        iVar12 = 0;
        do {
          if ((*pcVar7 < '!') && (*pcVar7 = '\n', iVar3 == 0)) {
            iVar3 = iVar12;
          }
          iVar12 = iVar12 + 1;
          pcVar7 = pcVar7 + 1;
        } while (iVar12 <= iVar2);
        pcVar7 = (*(undefined8 *)(__fp - 0x10e8));
        iVar12 = iVar17;
        if (iVar17 < iVar3) goto LAB_00143ff0;
      }
      else {
        pcVar7 = (*(undefined8 *)(__fp - 0x10e8));
        iVar2 = iVar3;
        if (iVar12 < iVar3) goto LAB_00143ff7;
      }
    }
LAB_00143f26:
    iVar12 = 0;
    iVar2 = iVar16;
  }
LAB_00143ff7:
  Process_updateCmdline(param_1,pcVar7,iVar12,iVar2);
  iVar2 = openat(param_2,((char *)(long)&DAT_0014a07e /* "comm" */),0);
  if (iVar2 < 0) {
    piVar11 = __errno_location();
    pcVar14 = *(char **)(param_1 + 0x90);
    lVar6 = (long)-*piVar11;
    if (lVar6 < 1) goto LAB_0014417b;
LAB_00144041:
    *(undefined1 *)((long)(*(struct stat *)(__fp - 0x10d8)).__unused + lVar6 + 0x17) = 0;
    if ((pcVar14 == (char *)0x0) || (iVar2 = strcmp(pcVar14,pcVar7), iVar2 != 0)) {
      free(pcVar14);
      pcVar7 = strdup(pcVar7);
      if (pcVar7 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
        fail();
      }
      *(char **)(param_1 + 0x90) = pcVar7;
      *(undefined8 *)(param_1 + 0x110) = 0;
    }
  }
  else {
    lVar6 = FUN_0013a450(iVar2,pcVar7,0x1001);
    pcVar14 = *(char **)(param_1 + 0x90);
    if (0 < lVar6) goto LAB_00144041;
LAB_0014417b:
    if (pcVar14 != (char *)0x0) {
      free(pcVar14);
      *(undefined8 *)(param_1 + 0x90) = 0;
      *(undefined8 *)(param_1 + 0x110) = 0;
    }
  }
  sVar8 = readlinkat(param_2,((char *)(long)(__sec_rodata + 0x2289) /* "exe" */),(char *)&(*(struct stat *)(__fp - 0x10d8)),0x80);
  if (sVar8 < 1) {
    if (*(void **)(param_1 + 0x98) != (void *)0x0) {
      free(*(void **)(param_1 + 0x98));
      *(undefined1 *)(param_1 + 0xac) = 0;
      *(undefined8 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0xa8) = 0;
      *(undefined8 *)(param_1 + 0x110) = 0;
    }
  }
  else {
    pcVar7 = *(char **)(param_1 + 0x98);
    *(undefined1 *)((long)(*(struct stat *)(__fp - 0x10d8)).__unused + sVar8 + -0x78) = 0;
    if (((pcVar7 == (char *)0x0) || (*(char *)(param_1 + 0xac) != '\0')) ||
       (iVar2 = strcmp((char *)&(*(struct stat *)(__fp - 0x10d8)),pcVar7), iVar2 != 0)) {
      sVar9 = strlen((char *)&(*(struct stat *)(__fp - 0x10d8)));
      if (10 < sVar9) {
        cVar18 = *(char *)(param_1 + 0xac);
        iVar2 = strcmp((char *)((long)&(*(struct stat *)(__fp - 0x10d8)) + (sVar9 - 10)),((char *)(long)&s__deleted__0014898b /* " (deleted)" */));
        bVar22 = iVar2 == 0;
        *(bool *)(param_1 + 0xac) = bVar22;
        if (bVar22) {
          *(undefined1 *)((long)&(*(undefined8 *)(__fp - 0x10e8)) + sVar9 + 6) = 0;
        }
        if ((bool)cVar18 != bVar22) {
          *(undefined8 *)(param_1 + 0x110) = 0;
        }
      }
      Process_updateExe(param_1,(char *)&(*(struct stat *)(__fp - 0x10d8)));
    }
  }
  uVar10 = 1;
LAB_00144138:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001443c0 @ 0x1443c0 */

undefined8
FUN_001443c0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  byte bVar1;
  uint uVar2;
  long *plVar3;
  bool bVar4;
  long *__ptr;
  long lVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  long extraout_RDX;
  long *plVar10;
  byte bVar11;
  uint uVar12;

  if (CHAR____0015c0d9 == '\0') {
    plVar10 = *(long **)(param_1[1] + 0x20);
    if ((0 < (int)plVar10[3]) &&
       (lVar5 = *(long *)(*plVar10 + (long)*(int *)(param_1[1] + 0x28) * 8), lVar5 != 0)) {
      __ptr = IOPriorityPanel_new(*(uint *)(lVar5 + 0x1e8));
      uVar9 = 1;
      plVar10 = __ptr;
      lVar5 = Action_pickFromVector(param_1,(long)__ptr,0x14,'\x01',param_r8,param_r9);
      if (lVar5 != 0) {
        uVar2 = *(uint *)((long *)__ptr[4] + 3);
        uVar9 = (ulong)uVar2;
        uVar12 = 0;
        if ((0 < (int)uVar2) &&
           (lVar5 = *(long *)(*(long *)__ptr[4] + (long)(int)__ptr[5] * 8), uVar12 = 0, lVar5 != 0))
        {
          uVar12 = *(uint *)(lVar5 + 0x10);
        }
        plVar3 = (long *)param_1[1];
        plVar7 = (long *)plVar3[4];
        if (0 < (int)plVar7[3]) {
          lVar5 = 0;
          bVar4 = true;
          bVar11 = 0;
          do {
            lVar8 = *(long *)(*plVar7 + lVar5 * 8);
            bVar1 = *(byte *)(lVar8 + 0x1d);
            param_r8 = (long)bVar1;
            if (bVar1 != 0) {
              uVar9 = (ulong)uVar12;
              syscall(0xfb,1,(ulong)*(uint *)(lVar8 + 0x10));
              plVar10 = (long *)0x1;
              lVar6 = syscall(0xfc,1,(ulong)*(uint *)(lVar8 + 0x10));
              *(uint *)(lVar8 + 0x1e8) = (uint)lVar6;
              bVar4 = (bool)(bVar4 & uVar12 == (uint)lVar6);
              plVar7 = (long *)plVar3[4];
              bVar11 = bVar1;
            }
            lVar5 = lVar5 + 1;
          } while ((int)lVar5 < (int)plVar7[3]);
          if ((bVar11 != 1) && (0 < (int)plVar7[3])) {
            lVar5 = *(long *)(*plVar7 + (long)(int)plVar3[5] * 8);
            plVar10 = plVar3;
            if (lVar5 != 0) {
              uVar9 = (ulong)uVar12;
              syscall(0xfb,1,(ulong)*(uint *)(lVar5 + 0x10));
              plVar10 = (long *)0x1;
              lVar8 = syscall(0xfc,1,(ulong)*(uint *)(lVar5 + 0x10));
              *(uint *)(lVar5 + 0x1e8) = (uint)lVar8;
              bVar4 = (bool)(bVar4 & uVar12 == (uint)lVar8);
            }
          }
          if (!bVar4) {
            beep();
          }
        }
      }
      free((void *)__ptr[7]);
      Vector_delete((long *)__ptr[4],(long)plVar10,extraout_RDX,uVar9,param_r8,param_r9);
      FunctionBar_delete((int *)__ptr[0xb]);
      if (0x15e < (int)__ptr[0xc]) {
        free((void *)__ptr[0xd]);
      }
      free(__ptr);
      return 0x61;
    }
  }
  return 0;
}


/* FUN_001445e0 @ 0x1445e0 */

void FUN_001445e0(long param_1,int *param_2)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  uint uVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)&s__5_2lf___0014a083 /* "%5.2lf%% " */),**(double **)(param_1 + 0x160));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x160),(*(char (*)[24])(__fp - 0x58)),uVar1);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)&s__5_2lf___0014a083 /* "%5.2lf%% " */),*(double *)(*(long *)(param_1 + 0x160) + 8));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x164),(*(char (*)[24])(__fp - 0x58)),uVar1);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)&s__5_2lf___0014a083 /* "%5.2lf%% " */),*(double *)(*(long *)(param_1 + 0x160) + 0x10));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x168),(*(char (*)[24])(__fp - 0x58)),uVar1);
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001446f0 @ 0x1446f0 */

void FUN_001446f0(long param_1,int *param_2)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  uint uVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (**(double **)(param_1 + 0x160) <= 0.0) {
    RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_001470dd /* " " */));
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x14),((char *)(long)&s_Compression_Unavailable_0014a0b2 /* "Compression Unavailable" */));
      return;
    }
  }
  else {
    Meter_humanUnit(*(double *)(param_1 + 0x168),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Uncompressed__0014a08d /* " Uncompressed, " */));
    Meter_humanUnit(**(double **)(param_1 + 0x160),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Compressed__0014a09d /* " Compressed, " */));
    if (0.0 < **(double **)(param_1 + 0x160)) {
      uVar1 = xSnprintf((*(char (*)[56])(__fp - 0x68)),0x32,((char *)(long)&s___2f_1_00149b79 /* "%.2f:1" */),
                        *(double *)(param_1 + 0x168) / **(double **)(param_1 + 0x160));
    }
    else {
      uVar1 = xSnprintf((*(char (*)[56])(__fp - 0x68)),0x32,((char *)(long)&DAT_001474de /* "N/A" */));
    }
    RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x18c),(*(char (*)[56])(__fp - 0x68)),uVar1);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Ratio_0014a0ab /* " Ratio" */));
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001448c0 @ 0x1448c0 */

void FUN_001448c0(int *param_1,long param_2)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  char *__s1;
  long in_FS_OFFSET = (long)__fake_fs;

  __s1 = *(char **)(param_2 + 8);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (__s1 == (char *)0x0) {
    lVar3 = 0x40;
    __s1 = ((char *)(long)&DAT_001474de /* "N/A" */);
  }
  else {
    iVar1 = strcmp(__s1,((char *)(long)(__sec_rodata + 0x2149) /* "running" */));
    lVar3 = 0x50;
    if (iVar1 != 0) {
      iVar1 = strcmp(__s1,((char *)(long)&s_degraded_0014a0ca /* "degraded" */));
      lVar3 = (-(ulong)(iVar1 == 0) & 0xffffffffffffffec) + 0x54;
    }
  }
  RichString_writeAscii(param_1,*(uint *)(CRT_colors + lVar3),__s1);
  RichString_appendAscii(param_1,*(uint *)(CRT_colors + 0x38),((char *)(long)(__sec_rodata + 0x30db) /* " (" */));
  if (*(int *)(param_2 + 0x10) == -1) {
    uVar2 = 1;
    (*(char (*)[24])(__fp - 0x58))[0] = '?';
    (*(char (*)[24])(__fp - 0x58))[1] = '\0';
LAB_0014495f:
    uVar4 = *(uint *)(CRT_colors + 0x40);
  }
  else {
    uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),*(int *)(param_2 + 0x10));
    if (*(int *)(param_2 + 0x10) == 0) {
      uVar4 = *(uint *)(CRT_colors + 0x3c);
    }
    else {
      if (*(int *)(param_2 + 0x10) == -1) goto LAB_0014495f;
      uVar4 = *(uint *)(CRT_colors + 0x4c);
    }
  }
  RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
  RichString_appendAscii(param_1,*(uint *)(CRT_colors + 0x38),((char *)(long)(__sec_rodata + 0x17c2) /* "/" */));
  if (*(int *)(param_2 + 0x18) == -1) {
    (*(char (*)[24])(__fp - 0x58))[0] = '?';
    (*(char (*)[24])(__fp - 0x58))[1] = '\0';
    uVar2 = 1;
LAB_001449a5:
    uVar4 = *(uint *)(CRT_colors + 0x40);
  }
  else {
    uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),*(int *)(param_2 + 0x18));
    if (*(int *)(param_2 + 0x18) == 0) {
      uVar4 = *(uint *)(CRT_colors + 0x4c);
    }
    else {
      if (*(int *)(param_2 + 0x18) == -1) goto LAB_001449a5;
      uVar4 = *(uint *)(CRT_colors + 0x3c);
    }
  }
  RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
  RichString_appendAscii(param_1,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_failed____0014a0d3 /* " failed) (" */));
  if (*(int *)(param_2 + 0x1c) == -1) {
    uVar2 = 1;
    (*(char (*)[24])(__fp - 0x58))[0] = '?';
    (*(char (*)[24])(__fp - 0x58))[1] = '\0';
LAB_001449e8:
    uVar4 = *(uint *)(CRT_colors + 0x40);
  }
  else {
    uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),*(int *)(param_2 + 0x1c));
    if (*(int *)(param_2 + 0x1c) == 0) {
      uVar4 = *(uint *)(CRT_colors + 0x3c);
    }
    else {
      if (*(int *)(param_2 + 0x1c) == -1) goto LAB_001449e8;
      uVar4 = *(uint *)(CRT_colors + 0x4c);
    }
  }
  RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
  RichString_appendAscii(param_1,*(uint *)(CRT_colors + 0x38),((char *)(long)(__sec_rodata + 0x17c2) /* "/" */));
  if (*(int *)(param_2 + 0x14) == -1) {
    uVar2 = 1;
    (*(char (*)[24])(__fp - 0x58))[0] = '?';
    (*(char (*)[24])(__fp - 0x58))[1] = '\0';
  }
  else {
    uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),*(int *)(param_2 + 0x14));
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar4 = *(uint *)(CRT_colors + 0x4c);
      goto LAB_00144a2a;
    }
    if (*(int *)(param_2 + 0x14) != -1) {
      uVar4 = *(uint *)(CRT_colors + 0x3c);
      goto LAB_00144a2a;
    }
  }
  uVar4 = *(uint *)(CRT_colors + 0x40);
LAB_00144a2a:
  RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
  RichString_appendAscii(param_1,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_jobs__0014a0de /* " jobs)" */));
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00144bd0 @ 0x144bd0 */

void FUN_00144bd0(undefined8 param_1,int *param_2)

{
  FUN_001448c0(param_2,(long)&DAT_0015d840);
  return;
}


/* FUN_00144bf0 @ 0x144bf0 */

void FUN_00144bf0(undefined8 param_1,int *param_2)

{
  FUN_001448c0(param_2,(long)&DAT_0015d860);
  return;
}


/* FUN_00144c10 @ 0x144c10 */

/* WARNING: Type propagation algorithm not settling */

void FUN_00144c10(long param_1,int param_2,long *param_3,char *param_4,long param_5)

{
  undefined1 __frame[0x6a8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x668;
  char *pcVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  long lVar7;
  long lVar8;
  uint *puVar9;
  long lVar10;
  long *plVar11;
  undefined1 *puVar12;
  byte bVar13;
  char cVar14;
  int __fd;
  int __fd_00;
  int iVar15;
  uint uVar16;
  int iVar17;
  DIR *__dirp;
  dirent *pdVar18;
  ulong uVar19;
  uint *puVar20;
  long lVar21;
  ulong uVar22;
  char *pcVar23;
  FILE *pFVar24;
  long lVar25;
  ulong uVar26;
  undefined8 uVar27;
  char *pcVar28;
  undefined8 *p4;
  struct stat *psVar29;
  void *pvVar30;
  void *pvVar31;
  size_t sVar32;
  char *pcVar33;
  byte *pbVar34;
  int *piVar35;
  long *plVar36;
  uint uVar37;
  ulong uVar38;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  struct stat *psVar39;
  long extraout_RDX_02;
  long extraout_RDX_03;
  uint uVar40;
  undefined8 *va3;
  byte *pbVar41;
  uint va1;
  tm *ptVar42;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar43;
  float fVar44;
  double dVar45;
  double dVar46;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar7 = *param_3;
  lVar8 = *(long *)(lVar7 + 0x40);
  *(int *)(param_1 + 0x4c) = (int)param_3[0x19];
  __fd = openat(param_2,param_4,0x30000);
  if (__fd < 0) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else {
    __dirp = fdopendir(__fd);
    if (__dirp == (DIR *)0x0) {
      if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
        close(__fd);
        return;
      }
    }
    else {
      cVar2 = *(char *)(lVar7 + 0x59);
      cVar3 = *(char *)(lVar7 + 0x5b);
      cVar4 = *(char *)(lVar7 + 0x5a);
LAB_00144cd6:
      pdVar18 = readdir(__dirp);
      if (pdVar18 != (dirent *)0x0) {
        if ((pdVar18->d_type & 0xfb) == 0) {
          cVar5 = pdVar18->d_name[0];
          pcVar23 = pdVar18->d_name;
          if (cVar5 == '.') {
            cVar5 = pdVar18->d_name[1];
            pcVar23 = pdVar18->d_name + 1;
          }
          if ((((((byte)(cVar5 - 0x30U) < 10) &&
                (uVar19 = __isoc23_strtoul(pcVar23,(char **)(*(struct stat * (*)[8])(__fp - 0x5a8)),10),
                uVar19 - 1 < 0xfffffffffffffffe)) && ((char)(*(struct stat * (*)[8])(__fp - 0x5a8))[0]->st_dev == '\0')) &&
              ((uVar40 = (uint)uVar19, param_5 == 0 || (uVar40 != *(uint *)(param_5 + 0x10))))) &&
             (__fd_00 = openat(__fd,pdVar18->d_name,0x30000), -1 < __fd_00)) {
            uVar26 = **(ulong **)(param_1 + 0x18);
            puVar9 = (uint *)(*(ulong **)(param_1 + 0x18))[1];
            uVar19 = (uVar19 & 0xffffffff) % uVar26;
            puVar20 = puVar9 + uVar19 * 6;
            p4 = *(undefined8 **)(puVar20 + 4);
            if (p4 != (undefined8 *)0x0) {
              uVar38 = 0;
              do {
                if (uVar40 == *puVar20) {
                  if (param_5 == 0) {
                    *(uint *)((long)p4 + 0x14) = uVar40;
                    uVar16 = uVar40;
                  }
                  else {
                    uVar16 = *(uint *)(param_5 + 0x10);
                    *(uint *)((long)p4 + 0x14) = uVar16;
                  }
                  *(bool *)((long)p4 + 0x4d) = uVar16 != *(uint *)(p4 + 2);
                  FUN_00144c10(param_1,__fd_00,param_3,((char *)(long)&DAT_0014a1aa /* "task" */),(long)p4);
                  if ((cVar2 != '\0') && (*(char *)((long)p4 + 0x4c) != '\0')) {
                    *(undefined1 *)((long)p4 + 0x21) = 1;
                    *(undefined1 *)((long)p4 + 0x1e) = 0;
                    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
                    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
                    close(__fd_00);
                    goto LAB_00144cd6;
                  }
                  (*(undefined8 * *)(__fp - 0x608)) = p4;
                  if (cVar3 == '\0') {
                    if ((cVar4 == '\0') || (*(char *)((long)p4 + 0x4e) == '\0')) {
                      uVar16 = *(uint *)(lVar8 + 0x20);
                      goto LAB_00144f02;
                    }
                  }
                  else {
                    if (*(char *)((long)p4 + 0x4d) != '\0') {
                      *(undefined1 *)((long)p4 + 0x21) = 1;
                      *(undefined1 *)((long)p4 + 0x1e) = 0;
                      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
                      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
                      close(__fd_00);
                      goto LAB_00144cd6;
                    }
                    if ((cVar4 == '\0') || (*(char *)((long)p4 + 0x4e) == '\0')) {
                      ptVar42 = (tm *)0x0;
                      if ((*(byte *)(lVar8 + 0x20) & 1) == 0) goto LAB_00145140;
                      (*(long *)(__fp - 0x5f8)) = p4[1];
                      goto LAB_00145a8a;
                    }
                  }
                  *(undefined1 *)((long)p4 + 0x21) = 1;
                  *(undefined1 *)((long)p4 + 0x1e) = 0;
                  close(__fd_00);
                  goto LAB_00144cd6;
                }
                if (*(ulong *)(puVar20 + 2) < uVar38) break;
                uVar19 = uVar19 + 1;
                if (uVar26 == uVar19) {
                  uVar19 = 0;
                  puVar20 = puVar9;
                }
                else {
                  puVar20 = puVar9 + uVar19 * 6;
                }
                p4 = *(undefined8 **)(puVar20 + 4);
                uVar38 = uVar38 + 1;
              } while (p4 != (undefined8 *)0x0);
            }
            uVar27 = *(undefined8 *)(param_1 + 0x20);
            p4 = calloc(1,0x348);
            if (p4 == (undefined8 *)0x0) {
LAB_00145b91:
                    /* WARNING: Subroutine does not return */
              fail();
            }
            p4[1] = uVar27;
            *(undefined4 *)((long)p4 + 0x1d) = 0x1000100;
            *p4 = LinuxProcess_class;
            *(undefined1 *)((long)p4 + 0x21) = 0;
            *(undefined4 *)(p4 + 0x11) = 0xffffffff;
            *(undefined4 *)(p4 + 0xc) = 0xffffffff;
            *(uint *)(p4 + 2) = uVar40;
            if (param_5 == 0) {
              *(uint *)((long)p4 + 0x14) = uVar40;
              *(undefined1 *)((long)p4 + 0x4d) = 0;
            }
            else {
              uVar16 = *(uint *)(param_5 + 0x10);
              *(uint *)((long)p4 + 0x14) = uVar16;
              *(bool *)((long)p4 + 0x4d) = uVar40 != uVar16;
            }
            FUN_00144c10(param_1,__fd_00,param_3,((char *)(long)&DAT_0014a1aa /* "task" */),(long)p4);
            (*(undefined8 * *)(__fp - 0x608)) = (undefined8 *)0x0;
            uVar16 = *(uint *)(lVar8 + 0x20);
            if (cVar3 == '\0') {
LAB_00144f02:
              bVar13 = (*(byte *)((long)p4 + 0x4c) ^ 1) & param_5 == 0;
              ptVar42 = (tm *)(ulong)bVar13;
              if ((uVar16 & 1) != 0) {
                (*(long *)(__fp - 0x5f8)) = p4[1];
                (*(struct stat *)(__fp - 0x4d8)).st_dev = 0x6f69;
                (*(struct stat *)(__fp - 0x4d8)).st_ino = 0;
                (*(uint *)((char *)&(*(struct stat *)(__fp - 0x4d8)).st_nlink + 0)) = 0;
                if (bVar13 == 0) {
                  ptVar42 = (tm *)0x0;
                }
                else {
                  ptVar42 = (tm *)0x1;
                  xSnprintf((char *)&(*(struct stat *)(__fp - 0x4d8)),0x14,((char *)(long)&DAT_0014a0eb /* "task/%i/io" */),*(int *)(p4 + 2));
                }
                goto LAB_00144f7e;
              }
            }
            else {
              ptVar42 = (tm *)0x0;
              if ((uVar16 & 1) != 0) {
                (*(long *)(__fp - 0x5f8)) = p4[1];
LAB_00145a8a:
                ptVar42 = (tm *)0x0;
                (*(struct stat *)(__fp - 0x4d8)).st_dev = 0x6f69;
                (*(struct stat *)(__fp - 0x4d8)).st_ino = 0;
                (*(uint *)((char *)&(*(struct stat *)(__fp - 0x4d8)).st_nlink + 0)) = 0;
LAB_00144f7e:
                iVar15 = openat(__fd_00,(char *)&(*(struct stat *)(__fp - 0x4d8)),0);
                if (iVar15 < 0) {
                  piVar35 = __errno_location();
                  lVar21 = (long)-*piVar35;
                }
                else {
                  lVar21 = FUN_0013a450(iVar15,(undefined1 *)(*(struct stat (*)[7])(__fp - 0x448)),0x400);
                }
                uVar19 = *(ulong *)((*(long *)(__fp - 0x5f8)) + 0x18);
                if (lVar21 < 0) {
                  p4[0x53] = 0xffffffffffffffff;
                  p4[0x55] = 0x7ff8000000000000;
                  p4[0x56] = 0x7ff8000000000000;
                  *(undefined4 *)(p4 + 0x4d) = 0xffffffff;
                  *(undefined4 *)((long)p4 + 0x26c) = 0xffffffff;
                  *(undefined4 *)(p4 + 0x4e) = 0xffffffff;
                  *(undefined4 *)((long)p4 + 0x274) = 0xffffffff;
                  *(undefined4 *)(p4 + 0x4f) = 0xffffffff;
                  *(undefined4 *)((long)p4 + 0x27c) = 0xffffffff;
                  *(undefined4 *)(p4 + 0x50) = 0xffffffff;
                  *(undefined4 *)((long)p4 + 0x284) = 0xffffffff;
                  *(undefined4 *)(p4 + 0x51) = 0xffffffff;
                  *(undefined4 *)((long)p4 + 0x28c) = 0xffffffff;
                  *(undefined4 *)(p4 + 0x52) = 0xffffffff;
                  *(undefined4 *)((long)p4 + 0x294) = 0xffffffff;
                }
                else {
                  uVar26 = p4[0x51];
                  uVar38 = p4[0x52];
                  uVar22 = 0;
                  if ((ulong)p4[0x54] < uVar19) {
                    uVar22 = uVar19 - p4[0x54];
                  }
                  (*(struct stat * (*)[8])(__fp - 0x5a8))[0] = (*(struct stat (*)[7])(__fp - 0x448));
                  while (pcVar23 = strsep((char **)(*(struct stat * (*)[8])(__fp - 0x5a8)),((char *)(long)&DAT_00147506 /* "\n" */)), pcVar23 != (char *)0x0) {
                    cVar5 = *pcVar23;
                    if (cVar5 == 's') {
                      if ((pcVar23[4] == 'r') &&
                         (iVar15 = strncmp(pcVar23 + 1,((char *)(long)&s_yscr__0014a108 /* "yscr: " */),6), iVar15 == 0)) {
                        uVar19 = __isoc23_strtoull(pcVar23 + 7,(char **)0x0,10);
                        p4[0x4f] = uVar19;
                      }
                      else {
                        iVar15 = strncmp(pcVar23 + 1,((char *)(long)&s_yscw__0014a10f /* "yscw: " */),6);
                        if (iVar15 == 0) {
                          uVar19 = __isoc23_strtoull(pcVar23 + 7,(char **)0x0,10);
                          p4[0x50] = uVar19;
                        }
                      }
                    }
                    else if (cVar5 < 't') {
                      if (cVar5 == 'c') {
                        iVar15 = strncmp(pcVar23 + 1,((char *)(long)&s_ancelled_write_bytes__0014a116 /* "ancelled_write_bytes: " */),0x16);
                        if (iVar15 == 0) {
                          uVar19 = __isoc23_strtoull(pcVar23 + 0x17,(char **)0x0,10);
                          p4[0x53] = uVar19;
                        }
                      }
                      else if (cVar5 == 'r') {
                        if ((pcVar23[1] == 'c') &&
                           (iVar15 = strncmp(pcVar23 + 2,((char *)(long)&s_har__0014a0f6 /* "har: " */),5), iVar15 == 0)) {
                          uVar19 = __isoc23_strtoull(pcVar23 + 7,(char **)0x0,10);
                          p4[0x4d] = uVar19;
                        }
                        else {
                          iVar15 = strncmp(pcVar23 + 1,((char *)(long)&s_ead_bytes__0014a0fc /* "ead_bytes: " */),0xb);
                          if (iVar15 == 0) {
                            uVar19 = __isoc23_strtoull(pcVar23 + 0xc,(char **)0x0,10);
                            dVar45 = NAN;
                            p4[0x51] = uVar19;
                            if (uVar22 != 0) {
                              dVar45 = 0.0;
                              if (uVar26 < uVar19) {
                                dVar45 = (double)(uVar19 - uVar26) * 1000.0;
                              }
                              dVar45 = dVar45 / (double)uVar22;
                            }
                            p4[0x55] = dVar45;
                          }
                        }
                      }
                    }
                    else if (cVar5 == 'w') {
                      if ((pcVar23[1] == 'c') &&
                         (iVar15 = strncmp(pcVar23 + 2,((char *)(long)&s_har__0014a0f6 /* "har: " */),5), iVar15 == 0)) {
                        uVar19 = __isoc23_strtoull(pcVar23 + 7,(char **)0x0,10);
                        p4[0x4e] = uVar19;
                      }
                      else {
                        iVar15 = strncmp(pcVar23 + 1,((char *)(long)(__sec_rodata + 0x3120) /* "rite_bytes: " */),0xc);
                        if (iVar15 == 0) {
                          uVar19 = __isoc23_strtoull(pcVar23 + 0xd,(char **)0x0,10);
                          dVar45 = NAN;
                          p4[0x52] = uVar19;
                          if (uVar22 != 0) {
                            dVar45 = 0.0;
                            if (uVar38 < uVar19) {
                              dVar45 = (double)(uVar19 - uVar38) * 1000.0;
                            }
                            dVar45 = dVar45 / (double)uVar22;
                          }
                          p4[0x56] = dVar45;
                        }
                      }
                    }
                  }
                  uVar19 = *(ulong *)((*(long *)(__fp - 0x5f8)) + 0x18);
                }
                p4[0x54] = uVar19;
              }
            }
LAB_00145140:
            iVar15 = openat(__fd_00,((char *)(long)&s_statm_0014a12d /* "statm" */),0);
            if (-1 < iVar15) {
              pFVar24 = fdopen(iVar15,((char *)(long)&DAT_00147760 /* "r" */));
              if (pFVar24 == (FILE *)0x0) {
                close(iVar15);
              }
              else {
                va3 = p4 + 0x49;
                iVar15 = __isoc23_fscanf(pFVar24,((char *)(long)&s__ld__ld__ld__ld__ld__ld__ld_0014a133 /* "%ld %ld %ld %ld %ld %ld %ld" */),p4 + 0x1d,p4 + 0x1e,
                                         p4 + 0x44,va3,(*(undefined4 (*)[2])(__fp - 0x5b0)),p4 + 0x4a,(tm *)(*(struct stat * (*)[8])(__fp - 0x5a8)));
                fclose(pFVar24);
                if (iVar15 == 7) {
                  lVar25 = (long)*(int *)((long)param_3 + 0xc4);
                  cVar5 = *(char *)((long)p4 + 0xad);
                  p4[0x1d] = p4[0x1d] * lVar25;
                  lVar21 = p4[0x1e];
                  p4[0x1e] = lVar21 * lVar25;
                  p4[0x45] = lVar21 * lVar25 - lVar25 * p4[0x44];
                  uVar16 = *(uint *)(lVar8 + 0x20);
                  if (*(char *)((long)p4 + 0x4c) == '\0') {
                    if (*(char *)((long)p4 + 0x4d) != '\0') {
LAB_00145ae0:
                      if (param_5 == 0) goto LAB_00145ac4;
                      cVar14 = *(char *)(param_5 + 0xad);
                      uVar27 = *(undefined8 *)(param_5 + 600);
                      *(char *)((long)p4 + 0xad) = cVar14;
                      goto LAB_00145ad0;
                    }
                    if (((uVar16 & 0x10000) == 0) &&
                       ((((*(char *)(lVar7 + 0x5d) == '\0' || (*(char *)((long)p4 + 0xac) != '\0'))
                         || (uVar19 = p4[0x1b], (long)uVar19 < 1)) ||
                        ((uVar26 = *(ulong *)(p4[1] + 0x18) / 1000, uVar26 < uVar19 ||
                         (uVar26 - uVar19 < 0xb)))))) goto LAB_00145ac4;
                    lVar21 = param_3[3];
                    lVar25 = p4[0x66];
                    uVar16 = rand();
                    if ((ulong)(uVar16 & 0x7ff) < (ulong)(lVar21 - lVar25)) {
                      p4[0x66] = param_3[3];
                      cVar14 = *(char *)(lVar7 + 0x5d);
                      uVar16 = *(uint *)(lVar8 + 0x20);
                      *(undefined1 *)((long)p4 + 0xad) = 0;
                      (*(uint *)((char *)&(*(ulong *)(__fp - 0x620)) + 0)) = uVar16 & 0x10000;
                      iVar15 = openat(__fd_00,((char *)(long)&DAT_0014a0e6 /* "maps" */),0);
                      if (-1 < iVar15) {
                        pFVar24 = fdopen(iVar15,((char *)(long)&DAT_00147760 /* "r" */));
                        if (pFVar24 == (FILE *)0x0) {
                          close(iVar15);
                        }
                        else {
                          va3 = (undefined8 *)((ulong)uVar16 & 0x10000);
                          if ((uint)(*(ulong *)(__fp - 0x620)) == 0) {
                            (*(ulong * *)(__fp - 0x618)) = (ulong *)0x0;
                          }
                          else {
                            (*(ulong * *)(__fp - 0x618)) = Hashtable_new(0x40,1);
                          }
LAB_0014644c:
                          do {
                            do {
                              do {
                                do {
                                  do {
                                    do {
                                      do {
                                        do {
                                          do {
                                            pcVar23 = fgets((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x400,pFVar24);
                                            if (pcVar23 == (char *)0x0) {
                                              fclose(pFVar24);
                                              if ((uint)(*(ulong *)(__fp - 0x620)) != 0) {
                                                uVar19 = 0;
                                                if (*(*(ulong * *)(__fp - 0x618)) != 0) {
                                                  plVar36 = (long *)((*(ulong * *)(__fp - 0x618))[1] + 0x10);
                                                  uVar19 = 0;
                                                  do {
                                                    plVar11 = (long *)*plVar36;
                                                    if ((plVar11 != (long *)0x0) &&
                                                       ((char)plVar11[1] != '\0')) {
                                                      uVar19 = uVar19 + *plVar11;
                                                    }
                                                    plVar36 = plVar36 + 3;
                                                  } while (plVar36 !=
                                                           (long *)((*(ulong * *)(__fp - 0x618))[1] + 0x10 +
                                                                   *(*(ulong * *)(__fp - 0x618)) * 0x18));
                                                }
                                                Hashtable_clear((*(ulong * *)(__fp - 0x618)));
                                                free((void *)(*(ulong * *)(__fp - 0x618))[1]);
                                                free((*(ulong * *)(__fp - 0x618)));
                                                p4[0x4b] = uVar19 / (ulong)(long)(int)param_3[0x18];
                                              }
                                              goto LAB_00145310;
                                            }
                                            pcVar23 = strchr((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x2f);
                                          } while (pcVar23 == (char *)0x0);
                                          lVar21 = 0;
                                          psVar29 = (*(struct stat (*)[7])(__fp - 0x448));
                                          do {
                                            psVar39 = psVar29;
                                            bVar13 = (byte)psVar39->st_dev;
                                            if (((1 << (bVar13 & 0x1f) & 0x3ff007eU) == 0) ||
                                               (bVar13 < 0x30)) goto LAB_001464cd;
                                            uVar16 = bVar13 & 0xffffffdf;
                                            if (0x46 < uVar16) goto LAB_0014644c;
                                            lVar21 = lVar21 * 0x10 +
                                                     (ulong)(uVar16 - (-(uint)((bVar13 & 0x40) != 0)
                                                                      & 7) & 0xf);
                                            psVar29 = (struct stat *)((long)&psVar39->st_dev + 1);
                                          } while (psVar29 != (struct stat *)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_nlink);
                                          bVar13 = *(char *)((long)&psVar39->st_dev + 1);
                                          psVar39 = (struct stat *)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_nlink;
LAB_001464cd:
                                        } while (bVar13 != 0x2d);
                                        va3 = (undefined8 *)0x0;
                                        puVar12 = (undefined1 *)((long)&psVar39->st_nlink + 1);
                                        pbVar34 = (byte *)((long)&psVar39->st_dev + 1);
                                        do {
                                          pbVar41 = pbVar34;
                                          bVar13 = *pbVar41;
                                          if (((1 << (bVar13 & 0x1f) & 0x3ff007eU) == 0) ||
                                             (bVar13 < 0x30)) goto LAB_0014653b;
                                          uVar16 = bVar13 & 0xffffffdf;
                                          if (0x46 < uVar16) goto LAB_0014644c;
                                          va3 = (undefined8 *)
                                                ((long)va3 * 0x10 +
                                                (ulong)(uVar16 - (-(uint)((bVar13 & 0x40) != 0) & 7)
                                                       & 0xf));
                                          pbVar34 = pbVar41 + 1;
                                        } while (pbVar41 + 1 != puVar12);
                                        bVar13 = pbVar41[1];
                                        pbVar41 = puVar12;
LAB_0014653b:
                                      } while ((((bVar13 != 0x20) || (pbVar41[1] == 0)) ||
                                               (pbVar41[2] == 0)) ||
                                              (((bVar13 = pbVar41[3], bVar13 == 0 ||
                                                (pbVar41[4] == 0)) || (pbVar41[5] != 0x20))));
                                      pbVar34 = pbVar41 + 6;
                                      bVar6 = pbVar41[6];
                                      while (' ' < (char)bVar6) {
                                        pbVar41 = pbVar34 + 1;
                                        pbVar34 = pbVar34 + 1;
                                        bVar6 = *pbVar41;
                                      }
                                    } while (bVar6 != 0x20);
                                    pbVar41 = pbVar34 + 1;
                                    iVar15 = 0;
                                    do {
                                      bVar6 = *pbVar41;
                                      if ((((1 << (bVar6 & 0x1f) & 0x3ff007eU) == 0) ||
                                          (bVar6 < 0x30)) ||
                                         (uVar16 = bVar6 & 0xffffffdf, 0x46 < uVar16)) break;
                                      pbVar41 = pbVar41 + 1;
                                      iVar15 = iVar15 * 0x10 +
                                               (uVar16 - (-(uint)((bVar6 & 0x40) != 0) & 7) & 0xf);
                                    } while (pbVar41 != pbVar34 + 5);
                                  } while (*pbVar41 != 0x3a);
                                  pbVar34 = pbVar41 + 1;
                                  iVar17 = 0;
                                  do {
                                    bVar6 = *pbVar34;
                                    if ((((1 << (bVar6 & 0x1f) & 0x3ff007eU) == 0) || (bVar6 < 0x30)
                                        ) || (uVar16 = bVar6 & 0xffffffdf, 0x46 < uVar16)) break;
                                    pbVar34 = pbVar34 + 1;
                                    iVar17 = iVar17 * 0x10 +
                                             (uVar16 - (-(uint)((bVar6 & 0x40) != 0) & 7) & 0xf);
                                  } while (pbVar34 != pbVar41 + 5);
                                } while ((*pbVar34 != 0x20) || (iVar17 == 0 && iVar15 == 0));
                                pbVar41 = pbVar34 + 1;
                                lVar25 = 0;
                                do {
                                  bVar6 = *pbVar41;
                                  if (9 < (byte)(bVar6 - 0x30)) break;
                                  pbVar41 = pbVar41 + 1;
                                  lVar25 = lVar25 * 10 + (long)((char)bVar6 + -0x30);
                                } while (pbVar41 != pbVar34 + 0x15);
                              } while (lVar25 == 0);
                              if ((uint)(*(ulong *)(__fp - 0x620)) != 0) {
                                plVar36 = (long *)Hashtable_get((*(ulong * *)(__fp - 0x618)),(uint)lVar25);
                                if (plVar36 == (long *)0x0) {
                                  plVar36 = xCalloc(1,0x10);
                                  Hashtable_put((*(ulong * *)(__fp - 0x618)),(uint)lVar25,plVar36);
                                }
                                va3 = (undefined8 *)((long)va3 - lVar21);
                                *(byte *)(plVar36 + 1) = *(byte *)(plVar36 + 1) | bVar13 == 0x78;
                                *plVar36 = *plVar36 + (long)va3;
                              }
                            } while (((cVar14 == '\0') || (bVar13 != 0x78)) ||
                                    (*(char *)((long)p4 + 0xad) != '\0'));
                            for (; *pbVar41 == 0x20; pbVar41 = pbVar41 + 1) {
                            }
                          } while ((((*pbVar41 != 0x2f) ||
                                    (uVar27 = FUN_00116180((char *)pbVar41,((char *)(long)&s__memfd__0014a14f /* "/memfd:" */)),
                                    (char)uVar27 != '\0')) ||
                                   (iVar15 = strcmp((char *)pbVar41,((char *)(long)&s__dev_zero__deleted__0014a157 /* "/dev/zero (deleted)\n" */)),
                                   iVar15 == 0)) ||
                                  ((pcVar23 = strstr((char *)pbVar41,((char *)(long)(__sec_rodata + 0x3160) /* " (deleted)\n" */)),
                                   pcVar23 == (char *)0x0 ||
                                   (*(undefined1 *)((long)p4 + 0xad) = 1, (uint)(*(ulong *)(__fp - 0x620)) != 0))));
                          fclose(pFVar24);
                        }
                      }
                    }
LAB_00145310:
                    cVar14 = *(char *)((long)p4 + 0xad);
                    uVar16 = *(uint *)(lVar8 + 0x20);
                  }
                  else {
                    if (*(char *)((long)p4 + 0x4d) != '\0') goto LAB_00145ae0;
LAB_00145ac4:
                    *(undefined1 *)((long)p4 + 0xad) = 0;
                    cVar14 = '\0';
                    uVar27 = 0;
LAB_00145ad0:
                    p4[0x4b] = uVar27;
                  }
                  if (cVar5 != cVar14) {
                    p4[0x22] = 0;
                  }
                  if (((uVar16 & 0x2000) != 0) && (*(char *)((long)p4 + 0x4c) == '\0')) {
                    if (param_5 == 0) {
                      if ((uVar40 & 1) == UINT_0015d804) {
                        pcVar23 = ((char *)(long)&DAT_0014a0e5 /* "smaps" */);
                        if (*(char *)(param_1 + 0x60) != '\0') {
                          pcVar23 = ((char *)(long)(__sec_rodata + 0x3071) /* "smaps_rollup" */);
                        }
                        iVar15 = openat(__fd_00,pcVar23,0);
                        if (-1 < iVar15) {
                          pFVar24 = fdopen(iVar15,((char *)(long)&DAT_00147760 /* "r" */));
                          if (pFVar24 == (FILE *)0x0) {
                            close(iVar15);
                          }
                          else {
                            p4[0x48] = 0;
                            *(undefined16 *)(*(undefined1 (*) [16])(p4 + 0x46)) = (undefined16)0x0;
LAB_00146a1b:
                            pcVar23 = fgets((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x100,pFVar24);
                            if (pcVar23 != (char *)0x0) {
                              pcVar23 = strchr((char *)(*(struct stat (*)[7])(__fp - 0x448)),10);
                              if (pcVar23 == (char *)0x0) {
                                do {
                                  pcVar23 = fgets((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x100,pFVar24);
                                  if (pcVar23 == (char *)0x0) break;
                                  pcVar23 = strchr((char *)(*(struct stat (*)[7])(__fp - 0x448)),10);
                                } while (pcVar23 == (char *)0x0);
                              }
                              else if ((int)(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev == 0x3a737350) {
                                lVar21 = __isoc23_strtol((char *)((long)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev + 4),
                                                         (char **)0x0,10);
                                p4[0x46] = p4[0x46] + lVar21;
                              }
                              else if (((int)(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev == 0x70617753) &&
                                      ((*(uchar *)((char *)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev + 4)) == ':')) {
                                lVar21 = __isoc23_strtol((char *)((long)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev + 5),
                                                         (char **)0x0,10);
                                p4[0x47] = p4[0x47] + lVar21;
                              }
                              else if (CONCAT44((*(uint *)((char *)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev + 4)),(int)(*(struct stat (*)[7])(__fp - 0x448))[0].st_dev)
                                       == 0x3a73735070617753) {
                                lVar21 = __isoc23_strtol((char *)&(*(struct stat (*)[7])(__fp - 0x448))[0].st_ino,(char **)0x0,
                                                         10);
                                p4[0x48] = p4[0x48] + lVar21;
                              }
                              goto LAB_00146a1b;
                            }
                            fclose(pFVar24);
                          }
                        }
                      }
                      if (uVar40 == 1) {
                        UINT_0015d804 = (uint)(UINT_0015d804 == 0);
                      }
                    }
                    else {
                      p4[0x46] = *(undefined8 *)(param_5 + 0x230);
                    }
                  }
                  lVar21 = p4[0x40];
                  lVar25 = p4[10];
                  lVar10 = p4[0x41];
                  pcVar23 = (*(char (*)[144])(__fp - 0x568));
                  uVar27 = FUN_0013d700((long)p4,__fd_00,(long)param_3,(char)ptVar42,(*(char (*)[144])(__fp - 0x568)));
                  if ((char)uVar27 != '\0') {
                    if ((*(byte *)((long)p4 + 0x262) & 0x20) != 0) {
                      *(undefined1 *)((long)p4 + 0x4c) = 1;
                    }
                    if ((lVar25 != p4[10]) && (*(long *)(param_1 + 0x58) != 0)) {
                      free((void *)p4[0xb]);
                      uVar19 = p4[10];
                      plVar36 = *(long **)(param_1 + 0x58);
                      uVar40 = (uint)(uVar19 >> 0x20) & 0xfffff000 | (uint)(uVar19 >> 8) & 0xfff;
                      pcVar28 = (char *)(ulong)uVar40;
                      uVar16 = (uint)((uVar19 >> 0x14) << 8) | (uint)uVar19 & 0xff;
                      va3 = (undefined8 *)(ulong)uVar16;
                      if (*plVar36 != 0) {
                        do {
                          if (uVar40 < *(uint *)(plVar36 + 1)) break;
                          if (uVar40 <= *(uint *)(plVar36 + 1)) {
                            if (uVar16 < *(uint *)((long)plVar36 + 0xc)) break;
                            if (uVar16 <= *(uint *)(plVar36 + 2)) {
                              pcVar23 = pcVar28;
                              va1 = uVar16 - *(uint *)((long)plVar36 + 0xc);
                              do {
                                xAsprintf((char **)(*(struct stat * (*)[8])(__fp - 0x5a8)),((char *)(long)&s__s__d_0014a17b /* "%s/%d" */),(void *)*plVar36,va1);
                                iVar15 = stat((char *)(*(struct stat * (*)[8])(__fp - 0x5a8))[0],&(*(struct stat *)(__fp - 0x4d8)));
                                if (((iVar15 == 0) &&
                                    (uVar37 = (uint)((*(struct stat *)(__fp - 0x4d8)).st_rdev >> 8) & 0xfff,
                                    ptVar42 = (tm *)(ulong)uVar37,
                                    uVar40 == ((uint)((*(struct stat *)(__fp - 0x4d8)).st_rdev >> 0x20) & 0xfffff000 |
                                              uVar37))) &&
                                   (psVar29 = (*(struct stat * (*)[8])(__fp - 0x5a8))[0],
                                   uVar16 == ((uint)(((*(struct stat *)(__fp - 0x4d8)).st_rdev >> 0x14) << 8) |
                                             (uint)(*(struct stat *)(__fp - 0x4d8)).st_rdev & 0xff))) goto LAB_001455a5;
                                free((*(struct stat * (*)[8])(__fp - 0x5a8))[0]);
                                ptVar42 = (tm *)(ulong)va1;
                                xAsprintf((char **)(*(struct stat * (*)[8])(__fp - 0x5a8)),((char *)(long)&DAT_00148c18 /* "%s%d" */),(void *)*plVar36,va1);
                                iVar15 = stat((char *)(*(struct stat * (*)[8])(__fp - 0x5a8))[0],&(*(struct stat *)(__fp - 0x4d8)));
                                if (((iVar15 == 0) &&
                                    (uVar37 = (uint)((*(struct stat *)(__fp - 0x4d8)).st_rdev >> 8) & 0xfff,
                                    ptVar42 = (tm *)(ulong)uVar37,
                                    uVar40 == ((uint)((*(struct stat *)(__fp - 0x4d8)).st_rdev >> 0x20) & 0xfffff000 |
                                              uVar37))) &&
                                   (psVar29 = (*(struct stat * (*)[8])(__fp - 0x5a8))[0],
                                   uVar16 == ((uint)(((*(struct stat *)(__fp - 0x4d8)).st_rdev >> 0x14) << 8) |
                                             (uint)(*(struct stat *)(__fp - 0x4d8)).st_rdev & 0xff))) goto LAB_001455a5;
                                free((*(struct stat * (*)[8])(__fp - 0x5a8))[0]);
                                bVar43 = uVar16 != va1;
                                va1 = uVar16;
                              } while (bVar43);
                              iVar15 = stat((char *)*plVar36,&(*(struct stat *)(__fp - 0x4d8)));
                              if ((iVar15 == 0) && (uVar19 == (*(struct stat *)(__fp - 0x4d8)).st_rdev)) {
                                psVar29 = (struct stat *)strdup((char *)*plVar36);
                                pcVar23 = pcVar28;
                                if (psVar29 != (struct stat *)0x0) goto LAB_001455a5;
                                goto LAB_00145b91;
                              }
                            }
                          }
                          plVar36 = plVar36 + 3;
                        } while (*plVar36 != 0);
                      }
                      ptVar42 = (tm *)(ulong)uVar16;
                      xAsprintf((char **)(*(struct stat * (*)[8])(__fp - 0x5a8)),((char *)(long)&s__dev__u__u_0014a181 /* "/dev/%u:%u" */),uVar40,uVar16);
                      psVar29 = (*(struct stat * (*)[8])(__fp - 0x5a8))[0];
                      pcVar23 = pcVar28;
LAB_001455a5:
                      p4[0xb] = psVar29;
                    }
                    if ((*(byte *)(lVar8 + 0x21) & 1) != 0) {
                      lVar25 = syscall(0xfc,1,(ulong)*(uint *)(p4 + 2));
                      *(int *)(p4 + 0x3d) = (int)lVar25;
                    }
                    dVar45 = *(double *)&param_3[0x1b];
                    dVar46 = 0.0;
                    *(undefined4 *)((long)p4 + 0xb4) = 0x7fc00000;
                    if (dVar45 <= 0.0) {
                      fVar44 = NAN;
                    }
                    else {
                      if ((ulong)(lVar21 + lVar10) < (ulong)(p4[0x41] + p4[0x40])) {
                        uVar19 = (p4[0x41] + p4[0x40]) - (lVar21 + lVar10);
                        if ((long)uVar19 < 0) {
                          dVar46 = (double)uVar19;
                        }
                        else {
                          dVar46 = (double)(long)uVar19;
                        }
                      }
                      fVar44 = (float)((dVar46 / dVar45) * 100.0);
                      if ((float)*(uint *)(param_3 + 0xf) * 100.0 <= fVar44) {
                        fVar44 = (float)*(uint *)(param_3 + 0xf) * 100.0;
                      }
                      *(float *)((long)p4 + 0xb4) = fVar44;
                    }
                    *(float *)(p4 + 0x17) =
                         (float)(((double)(long)p4[0x1e] / (double)(ulong)param_3[6]) * 100.0);
                    Process_updateCPUFieldWidths(fVar44);
                    iVar15 = fstat(__fd_00,(*(struct stat (*)[7])(__fp - 0x448)));
                    if (iVar15 != -1) {
                      if (*(uint *)(p4 + 0xc) != (*(struct stat (*)[7])(__fp - 0x448))[0].st_uid) {
                        *(__uid_t *)(p4 + 0xc) = (*(struct stat (*)[7])(__fp - 0x448))[0].st_uid;
                        pcVar28 = UsersTable_getRef((long *)param_3[0x10],(*(struct stat (*)[7])(__fp - 0x448))[0].st_uid);
                        p4[0xd] = pcVar28;
                      }
                      uVar19 = FUN_00138ca0((long)p4,__fd_00);
                      bVar13 = (byte)uVar19;
                      if (bVar13 != 0) {
                        if ((*(undefined8 * *)(__fp - 0x608)) == (undefined8 *)0x0) {
                          if ((*(byte *)(lVar8 + 0x21) & 2) != 0) {
                            iVar15 = access(((char *)(long)&s__proc_vz_0014a18c /* "/proc/vz" */),4);
                            if ((iVar15 == 0) && (iVar15 = openat(__fd_00,((char *)(long)&s_status_00149730 /* "status" */),0), -1 < iVar15))
                            {
                              pFVar24 = fdopen(iVar15,((char *)(long)&DAT_00147760 /* "r" */));
                              if (pFVar24 != (FILE *)0x0) {
                                (*(ulong *)(__fp - 0x620)) = 0;
                                bVar6 = 0;
LAB_0014622f:
                                pcVar28 = fgets((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x100,pFVar24);
                                if (pcVar28 != (char *)0x0) {
                                  pcVar28 = strchr((char *)(*(struct stat (*)[7])(__fp - 0x448)),10);
                                  if (pcVar28 == (char *)0x0) {
                                    do {
                                      pcVar28 = fgets((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x100,pFVar24);
                                      if (pcVar28 == (char *)0x0) break;
                                      pcVar28 = strchr((char *)(*(struct stat (*)[7])(__fp - 0x448)),10);
                                    } while (pcVar28 == (char *)0x0);
                                  }
                                  else {
                                    pcVar28 = strchr((char *)(*(struct stat (*)[7])(__fp - 0x448)),0x3a);
                                    if (pcVar28 != (char *)0x0) {
                                      sVar32 = (long)pcVar28 - (long)(*(struct stat (*)[7])(__fp - 0x448));
                                      iVar15 = strncasecmp((char *)(*(struct stat (*)[7])(__fp - 0x448)),((char *)(long)&s_envID_0014a195 /* "envID" */),sVar32);
                                      if (iVar15 == 0) {
                                        iVar15 = 1;
                                      }
                                      else {
                                        iVar17 = strncasecmp((char *)(*(struct stat (*)[7])(__fp - 0x448)),((char *)(long)&DAT_0014a19b /* "VPid" */),sVar32);
                                        iVar15 = 2;
                                        if (iVar17 != 0) goto LAB_0014622f;
                                      }
                                      do {
                                        pcVar1 = pcVar28 + 1;
                                        pcVar28 = pcVar28 + 1;
                                        if (*pcVar1 == '\0') goto LAB_0014622f;
                                        pcVar33 = pcVar28;
                                      } while (*pcVar1 < '!');
                                      do {
                                        pcVar33 = pcVar33 + 1;
                                      } while (' ' < *pcVar33);
                                      if (pcVar28 != pcVar33) {
                                        *pcVar33 = '\0';
                                        if (iVar15 == 2) {
                                          uVar26 = __isoc23_strtoul(pcVar28,(char **)0x0,0);
                                          *(int *)(p4 + 0x58) = (int)uVar26;
                                          bVar6 = bVar13;
                                        }
                                        else {
                                          pcVar1 = (char *)p4[0x57];
                                          if (pcVar1 == (char *)0x0) {
                                            if (*pcVar28 != '\0') goto LAB_0014692d;
                                          }
                                          else {
                                            iVar15 = strcmp(pcVar28,pcVar1);
                                            if ((iVar15 != 0) &&
                                               (iVar15 = strcmp(pcVar1,pcVar28), iVar15 != 0)) {
LAB_0014692d:
                                              free(pcVar1);
                                              pcVar28 = strdup(pcVar28);
                                              if (pcVar28 == (char *)0x0) goto LAB_00145b91;
                                              p4[0x57] = pcVar28;
                                            }
                                          }
                                          (*(ulong *)(__fp - 0x620)) = uVar19 & 0xff;
                                        }
                                      }
                                    }
                                  }
                                  goto LAB_0014622f;
                                }
                                fclose(pFVar24);
                                if ((char)(*(ulong *)(__fp - 0x620)) == '\0') {
                                  free((void *)p4[0x57]);
                                  p4[0x57] = 0;
                                }
                                if (bVar6 == 0) {
                                  *(undefined4 *)(p4 + 0x58) = *(undefined4 *)(p4 + 2);
                                }
                                goto LAB_00145706;
                              }
                              close(iVar15);
                            }
                            free((void *)p4[0x57]);
                            p4[0x57] = 0;
                            *(undefined4 *)(p4 + 0x58) = *(undefined4 *)(p4 + 2);
                          }
LAB_00145706:
                          if (*(char *)((long)p4 + 0x4c) == '\0') {
                            uVar27 = FUN_00143db0((long)p4,__fd_00);
                            if ((char)uVar27 == '\0') {
                              sVar32 = strlen((*(char (*)[144])(__fp - 0x568)));
                              Process_updateCmdline((long)p4,(*(char (*)[144])(__fp - 0x568)),0,(int)sVar32);
                            }
                          }
                          else {
                            Process_updateCmdline((long)p4,(char *)0x0,0,0);
                          }
                          lVar21 = *(long *)(p4[1] + 8);
                          localtime_r(p4 + 0x1b,(tm *)(*(struct stat * (*)[8])(__fp - 0x5a8)));
                          pcVar28 = ((char *)(long)&DAT_0014876e /* "%R " */);
                          if (((long)p4[0x1b] < lVar21 + -0x1517f) &&
                             (pcVar28 = ((char *)(long)&DAT_00148778 /* " %Y " */), lVar21 + -0x1dfe1ff <= (long)p4[0x1b])) {
                            pcVar28 = ((char *)(long)&s__b_d_00148772 /* "%b%d " */);
                          }
                          ptVar42 = (tm *)(*(struct stat * (*)[8])(__fp - 0x5a8));
                          strftime((char *)(p4 + 0x1c),7,pcVar28,(tm *)(*(struct stat * (*)[8])(__fp - 0x5a8)));
                          plVar36 = *(long **)(param_1 + 8);
                          lVar21 = plVar36[3];
                          p4[6] = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x20);
                          Vector_set(plVar36,(int)lVar21,(long)p4,(long)ptVar42,(long)pcVar23,
                                     (long)va3);
                          Hashtable_put(*(ulong **)(param_1 + 0x18),*(uint *)(p4 + 2),p4);
                          lVar21 = extraout_RDX_00;
                        }
                        else {
                          lVar21 = extraout_RDX;
                          if ((*(char *)(lVar7 + 0x6b) != '\0') && (*(int *)(p4 + 0x21) != 0xb)) {
                            if (*(char *)((long)p4 + 0x4c) == '\0') {
                              uVar27 = FUN_00143db0((long)p4,__fd_00);
                              lVar21 = extraout_RDX_02;
                              if ((char)uVar27 == '\0') {
                                sVar32 = strlen((*(char (*)[144])(__fp - 0x568)));
                                ptVar42 = (tm *)(sVar32 & 0xffffffff);
                                Process_updateCmdline((long)p4,(*(char (*)[144])(__fp - 0x568)),0,(int)sVar32);
                                lVar21 = extraout_RDX_03;
                              }
                            }
                            else {
                              ptVar42 = (tm *)0x0;
                              Process_updateCmdline((long)p4,(char *)0x0,0,0);
                              lVar21 = extraout_RDX_01;
                            }
                          }
                        }
                        uVar40 = *(uint *)(lVar8 + 0x20);
                        if ((uVar40 & 0x800) != 0) {
                          FUN_0013ec40((long)p4,__fd_00,lVar21,(long)ptVar42,(long)pcVar23,(long)va3
                                      );
                          uVar40 = *(uint *)(lVar8 + 0x20);
                        }
                        if ((uVar40 & 0x40000) != 0) {
                          pvVar30 = *(void **)(param_1 + 0x68);
                          if (pvVar30 == (void *)0x0) {
                            pvVar30 = nl_socket_alloc();
                            *(void **)(param_1 + 0x68) = pvVar30;
                            if (pvVar30 != (void *)0x0) {
                              iVar15 = nl_connect(pvVar30,0x10);
                              if (-1 < iVar15) {
                                iVar15 = genl_ctrl_resolve(*(void **)(param_1 + 0x68),((char *)(long)&s_TASKSTATS_0014a1a0 /* "TASKSTATS" */));
                                *(int *)(param_1 + 0x70) = iVar15;
                              }
                              pvVar30 = *(void **)(param_1 + 0x68);
                              if (pvVar30 != (void *)0x0) goto LAB_00145ecc;
                            }
LAB_00146074:
                            *(undefined4 *)(p4 + 0x62) = 0x7fc00000;
                            p4[0x61] = 0x7fc000007fc00000;
                          }
                          else {
LAB_00145ecc:
                            iVar15 = nl_socket_modify_cb(pvVar30,0,3,FUN_0013a190,p4);
                            if ((iVar15 < 0) || (pvVar30 = nlmsg_alloc(), pvVar30 == (void *)0x0))
                            goto LAB_00146074;
                            pvVar31 = genlmsg_put(pvVar30,0,0,*(int *)(param_1 + 0x70),0,1,'\x01',
                                                  '\x0e');
                            if (pvVar31 == (void *)0x0) {
                              nlmsg_free(pvVar30);
                            }
                            iVar15 = nla_put_u32(pvVar30,1,*(uint *)(p4 + 2));
                            if (iVar15 < 0) {
                              nlmsg_free(pvVar30);
                            }
                            iVar15 = nl_send_sync(*(void **)(param_1 + 0x68),pvVar30);
                            if ((iVar15 < 0) ||
                               (iVar15 = nl_recvmsgs_default(*(void **)(param_1 + 0x68)), iVar15 < 0
                               )) goto LAB_00146074;
                          }
                          uVar40 = *(uint *)(lVar8 + 0x20);
                        }
                        if ((uVar40 & 0x1000) != 0) {
                          FUN_001390d0((long)p4,__fd_00);
                          uVar40 = *(uint *)(lVar8 + 0x20);
                        }
                        if ((uVar40 & 0x8000) != 0) {
                          FUN_0013f230((long)p4,__fd_00);
                          uVar40 = *(uint *)(lVar8 + 0x20);
                        }
                        if ((uVar40 & 2) != 0) {
                          FUN_0013f390((long)p4,__fd_00);
                          uVar40 = *(uint *)(lVar8 + 0x20);
                        }
                        if (((uVar40 & 0x80000) != 0) && (*(char *)(param_1 + 0x61) != '\0')) {
                          p4[0x67] = 0xffffffffffffffff;
                          iVar15 = openat(__fd_00,((char *)(long)(__sec_rodata + 0x2b96) /* "autogroup" */),0);
                          if (iVar15 < 0) {
                            piVar35 = __errno_location();
                            lVar21 = (long)-*piVar35;
                          }
                          else {
                            lVar21 = FUN_0013a450(iVar15,(undefined1 *)(*(struct stat (*)[7])(__fp - 0x448)),0x40);
                          }
                          if ((-1 < lVar21) &&
                             (iVar15 = __isoc23_sscanf((char *)(*(struct stat (*)[7])(__fp - 0x448)),((char *)(long)&s__autogroup__ld_nice__d_00149ba3 /* "/autogroup-%ld nice %d" */),
                                                       (tm *)(*(struct stat * (*)[8])(__fp - 0x5a8)),(*(undefined4 (*)[2])(__fp - 0x5b0))), iVar15 == 2)) {
                            p4[0x67] = (*(struct stat * (*)[8])(__fp - 0x5a8))[0];
                            *(undefined4 *)(p4 + 0x68) = (*(undefined4 (*)[2])(__fp - 0x5b0))[0];
                          }
                          uVar40 = *(uint *)(lVar8 + 0x20);
                        }
                        if ((uVar40 & 4) != 0) {
                          iVar15 = sched_getscheduler(*(__pid_t *)(p4 + 2));
                          *(int *)((long)p4 + 0x10c) = iVar15;
                        }
                        if (((p4[0x10] == 0) && ((*(char (*)[144])(__fp - 0x568))[0] != '\0')) &&
                           ((*(int *)(p4 + 0x21) == 0xb ||
                            ((*(char *)((long)p4 + 0x4c) != '\0' ||
                             (*(char *)(lVar7 + 0x58) != '\0')))))) {
                          sVar32 = strlen((*(char (*)[144])(__fp - 0x568)));
                          Process_updateCmdline((long)p4,(*(char (*)[144])(__fp - 0x568)),0,(int)sVar32);
                        }
                        *(undefined1 *)((long)p4 + 0x21) = 1;
                        close(__fd_00);
                        if ((cVar4 == '\0') || (*(char *)((long)p4 + 0x4e) == '\0')) {
                          if (*(char *)((long)p4 + 0x4c) == '\0') {
                            if (*(char *)((long)p4 + 0x4d) != '\0') {
                              *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
                            }
LAB_00145d92:
                            if (cVar3 != '\0') {
                              bVar13 = *(byte *)((long)p4 + 0x4d) ^ 1;
                            }
                          }
                          else {
                            *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
                            if (cVar2 == '\0') goto LAB_00145d92;
                            bVar13 = 0;
                          }
                          *(byte *)((long)p4 + 0x1e) = bVar13;
                          *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
                        }
                        else {
                          *(undefined1 *)((long)p4 + 0x1e) = 0;
                        }
                        goto LAB_00144cd6;
                      }
                    }
                  }
                }
              }
            }
            close(__fd_00);
            if ((*(undefined8 * *)(__fp - 0x608)) == (undefined8 *)0x0) {
              Process_delete(p4);
            }
          }
        }
        goto LAB_00144cd6;
      }
      if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
        closedir(__dirp);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ProcessTable_goThroughEntries @ 0x146c70 */

void ProcessTable_goThroughEntries(long param_1)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long *plVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar5;

  bVar5 = false;
  plVar1 = *(long **)(param_1 + 0x20);
  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(byte *)(*(long *)(*plVar1 + 0x40) + 0x22) & 8) != 0) {
    iVar2 = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
    if (iVar2 < 0) {
      piVar4 = __errno_location();
      lVar3 = (long)-*piVar4;
    }
    else {
      lVar3 = FUN_0013a450(iVar2,(*(char (*)[24])(__fp - 0x38)),0x10);
    }
    bVar5 = false;
    if (-1 < lVar3) {
      bVar5 = (*(char (*)[24])(__fp - 0x38))[0] == '1';
    }
  }
  *(bool *)(param_1 + 0x61) = bVar5;
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_00144c10(param_1,-100,plVar1,((char *)(long)&s__proc_00149a78 /* "/proc" */),0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

