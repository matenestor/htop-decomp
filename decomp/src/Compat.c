#include "htop.h"

/* Compat_faccessat @ 0x116080 */

int Compat_faccessat(int param_1,char *param_2,int param_3,int param_4)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  int iVar1;
  int *piVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  piVar2 = __errno_location();
  *piVar2 = 0;
  iVar1 = faccessat(param_1,param_2,param_3,param_4);
  if ((iVar1 != 0) && (*piVar2 == 0x16)) {
    if ((param_1 == -100) && (param_3 == 0)) {
      if (param_4 == 0) {
        iVar1 = stat(param_2,&(*(struct stat *)(__fp - 0xd8)));
      }
      else {
        iVar1 = lstat(param_2,&(*(struct stat *)(__fp - 0xd8)));
      }
    }
    else {
      iVar1 = -1;
    }
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Compat_fstatat @ 0x116140 */

void Compat_fstatat(int param_1,undefined8 param_2,char *param_3,struct stat *param_4,int param_5)

{
  fstatat(param_1,param_3,param_4,param_5);
  return;
}


/* Compat_readlinkat @ 0x116160 */

void Compat_readlinkat(int param_1,undefined8 param_2,char *param_3,char *param_4,size_t param_5)

{
  readlinkat(param_1,param_3,param_4,param_5);
  return;
}


/* FUN_00116180 @ 0x116180 */

undefined8 FUN_00116180(char *param_1,char *param_2)

{
  int iVar1;
  size_t __n;
  undefined4 extraout_var;

  __n = strlen(param_2);
  iVar1 = strncmp(param_1,param_2,__n);
  return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
}


/* Compat_readlink @ 0x11c300 */

void Compat_readlink(ulong param_1,void *param_2,char *param_3,size_t param_4)

{
  undefined1 __frame[0x2108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x20c8;
  ssize_t sVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf((*(char (*)[32])(__fp - 0x2078)),0x20,((char *)(long)&s__proc_self_fd__d_00147480 /* "/proc/self/fd/%d" */),(int)param_1);
  sVar1 = readlink((*(char (*)[32])(__fp - 0x2078)),(*(char (*)[4104])(__fp - 0x1048)),0x1000);
  if (-1 < sVar1) {
    (*(char (*)[4104])(__fp - 0x1048))[sVar1] = '\0';
    xSnprintf((*(char (*)[4112])(__fp - 0x2058)),0x1001,((char *)(long)&s__s__s_00147491 /* "%s/%s" */),(*(char (*)[4104])(__fp - 0x1048)),param_2);
    readlink((*(char (*)[4112])(__fp - 0x2058)),param_3,param_4);
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011c3e0 @ 0x11c3e0 */

void FUN_0011c3e0(long param_1)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  int iVar1;
  char *pcVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (*(int *)(param_1 + 0x24) == 0) {
    pcVar2 = *(char **)(param_1 + 0x18);
    if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,((char *)(long)&DAT_00147497 /* "Avg" */)), iVar1 == 0)) goto LAB_0011c469;
    free(pcVar2);
    pcVar2 = strdup(((char *)(long)&DAT_00147497 /* "Avg" */));
  }
  else {
    if (*(uint *)(*(long **)(param_1 + 0x10) + 0xf) < 2) goto LAB_0011c469;
    xSnprintf((*(char (*)[10])(__fp - 0x3a)),10,((char *)(long)&DAT_0014749b /* "%3u" */),
              *(int *)(param_1 + 0x24) -
              (uint)(*(char *)(**(long **)(param_1 + 0x10) + 0x50) == '\0'));
    pcVar2 = *(char **)(param_1 + 0x18);
    if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,(*(char (*)[10])(__fp - 0x3a))), iVar1 == 0)) goto LAB_0011c469;
    free(pcVar2);
    pcVar2 = strdup((*(char (*)[10])(__fp - 0x3a)));
  }
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *(char **)(param_1 + 0x18) = pcVar2;
LAB_0011c469:
  if ((*(long *)(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_0011c4d0 @ 0x11c4d0 */

void FUN_0011c4d0(long *param_1,char *param_2,ulong param_3)

{
  if (*(int *)((long)param_1 + 0x24) != 0) {
    xSnprintf(param_2,param_3,((char *)(long)&DAT_0014749f /* "%s %u" */),*(void **)(*param_1 + 0x78),*(int *)((long)param_1 + 0x24));
    return;
  }
  xSnprintf(param_2,param_3,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),*(void **)(*param_1 + 0x78));
  return;
}


/* FUN_0011c510 @ 0x11c510 */

void FUN_0011c510(long param_1,char *param_2,ulong param_3)

{
  ulong *puVar1;
  ulong uVar2;
  uint *puVar3;
  char *__s;
  uint *puVar4;
  size_t sVar5;
  int va0;
  ulong uVar6;
  ulong uVar7;
  void *va0_00;

  puVar1 = *(ulong **)(**(long **)(param_1 + 0x10) + 0x20);
  uVar2 = *puVar1;
  puVar3 = (uint *)puVar1[1];
  uVar7 = (ulong)*(uint *)(param_1 + 0x24) % uVar2;
  va0_00 = *(void **)(puVar3 + uVar7 * 6 + 4);
  if (va0_00 != (void *)0x0) {
    uVar6 = 0;
    puVar4 = puVar3 + uVar7 * 6;
    do {
      while( true ) {
        if (*(uint *)(param_1 + 0x24) == *puVar4) {
          __s = *(char **)((long)va0_00 + 0x20);
          if (__s == (char *)0x0) {
            xSnprintf(param_2,param_3,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),va0_00);
            return;
          }
          sVar5 = strlen(__s);
          va0 = (int)sVar5;
          if ((2 < va0) && (__s[(long)va0 + -2] == ':')) {
            va0 = va0 + -2;
          }
          xSnprintf(param_2,param_3,((char *)(long)&DAT_001474a5 /* "%.*s" */),va0,__s);
          return;
        }
        if (*(ulong *)(puVar4 + 2) < uVar6) {
          return;
        }
        uVar7 = uVar7 + 1;
        if (uVar2 != uVar7) break;
        uVar7 = 0;
        uVar6 = uVar6 + 1;
        va0_00 = *(void **)(puVar3 + 4);
        puVar4 = puVar3;
        if (va0_00 == (void *)0x0) {
          return;
        }
      }
      uVar6 = uVar6 + 1;
      puVar4 = puVar3 + uVar7 * 6;
      va0_00 = *(void **)(puVar4 + 4);
    } while (va0_00 != (void *)0x0);
  }
  return;
}


/* FUN_0011c630 @ 0x11c630 */

undefined8
FUN_0011c630(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  undefined8 *puVar7;
  uint uVar8;
  ulong uVar9;
  long extraout_RDX;
  long extraout_RDX_00;
  long *plVar10;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long lVar11;
  undefined8 uVar12;

  plVar2 = *(long **)(param_1 + 0x26f0);
  if ((int)(*(long **)(param_1 + 0x20))[3] < 1) {
    return 2;
  }
  lVar11 = *(long *)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8);
  if (lVar11 == 0) {
    return 2;
  }
  uVar1 = *(uint *)(lVar11 + 0x10);
  uVar8 = uVar1 & 0xffff;
  uVar9 = (ulong)uVar8;
  iVar5 = (int)uVar1 >> 0x10;
  if (param_2 == 0x6c) {
LAB_0011c7b8:
    plVar3 = (long *)**(long **)(param_1 + 0x2700);
    plVar10 = *(long **)*plVar2;
    plVar6 = Meter_new(plVar2[1],uVar8,*(long *)(Platform_meterTypes + (long)iVar5 * 8),uVar9,
                       param_r8,param_r9);
    Vector_set(plVar10,(int)plVar10[3],(long)plVar6,uVar9,param_r8,param_r9);
    puVar7 = Meter_toListItem(plVar6,0,extraout_RDX_01,uVar9,param_r8,param_r9);
    Panel_add((long)plVar3,(long)puVar7,extraout_RDX_02,uVar9,param_r8,param_r9);
    plVar10 = (long *)plVar3[4];
    lVar11 = 0;
    uVar9 = (ulong)*(uint *)(plVar10 + 3);
    iVar5 = *(uint *)(plVar10 + 3) - 1;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    *(int *)(plVar3 + 5) = iVar5;
    if (*(code **)(*plVar3 + 0x20) != (code *)0x0) {
      lVar11 = 0xffffffff;
      (**(code **)(*plVar3 + 0x20))((long)plVar3,0xffffffff,(long)plVar10,uVar9,param_r8,param_r9);
      plVar10 = (long *)plVar3[4];
      uVar9 = (ulong)*(uint *)(plVar10 + 3);
    }
    *(undefined1 *)(plVar3 + 0x4e1) = 1;
    if (0 < (int)uVar9) {
      uVar9 = (ulong)(int)plVar3[5];
      lVar4 = *(long *)(*plVar10 + uVar9 * 8);
      if (lVar4 != 0) {
        *(undefined1 *)(lVar4 + 0x14) = 1;
      }
    }
    lVar4 = LONG_0015c0c0;
    *(undefined4 *)(plVar3 + 0x4db) = 10;
    plVar3[10] = lVar4;
    uVar12 = 1;
  }
  else {
    if (param_2 < 0x6d) {
      if (param_2 == 0x4c) goto LAB_0011c7b8;
      if (param_2 < 0x4d) {
        if ((param_2 != 10) && (param_2 != 0xd)) {
          return 2;
        }
      }
      else if (param_2 != 0x52) {
        return 2;
      }
    }
    else {
      if (param_2 == 0x10d) goto LAB_0011c7b8;
      if (param_2 < 0x10e) {
        if (param_2 != 0x72) {
          return 2;
        }
      }
      else if ((param_2 != 0x10e) && (param_2 != 0x157)) {
        return 2;
      }
    }
    plVar3 = *(long **)(*(long *)(param_1 + 0x2700) + -8 + *(long *)(param_1 + 0x26f8) * 8);
    plVar10 = *(long **)(*plVar2 + (ulong)((int)*(long *)(param_1 + 0x26f8) - 1) * 8);
    plVar6 = Meter_new(plVar2[1],uVar8,*(long *)(Platform_meterTypes + (long)iVar5 * 8),uVar9,
                       param_r8,param_r9);
    Vector_set(plVar10,(int)plVar10[3],(long)plVar6,uVar9,param_r8,param_r9);
    puVar7 = Meter_toListItem(plVar6,0,extraout_RDX,uVar9,param_r8,param_r9);
    Panel_add((long)plVar3,(long)puVar7,extraout_RDX_00,uVar9,param_r8,param_r9);
    plVar10 = (long *)plVar3[4];
    lVar11 = 0;
    uVar9 = (ulong)*(uint *)(plVar10 + 3);
    iVar5 = *(uint *)(plVar10 + 3) - 1;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    *(int *)(plVar3 + 5) = iVar5;
    if (*(code **)(*plVar3 + 0x20) != (code *)0x0) {
      lVar11 = 0xffffffff;
      (**(code **)(*plVar3 + 0x20))((long)plVar3,0xffffffff,(long)plVar10,uVar9,param_r8,param_r9);
      plVar10 = (long *)plVar3[4];
      uVar9 = (ulong)*(uint *)(plVar10 + 3);
    }
    *(undefined1 *)(plVar3 + 0x4e1) = 1;
    if (0 < (int)uVar9) {
      uVar9 = (ulong)(int)plVar3[5];
      lVar4 = *(long *)(*plVar10 + uVar9 * 8);
      if (lVar4 != 0) {
        *(undefined1 *)(lVar4 + 0x14) = 1;
      }
    }
    lVar4 = LONG_0015c0c0;
    *(undefined4 *)(plVar3 + 0x4db) = 10;
    plVar3[10] = lVar4;
    uVar12 = 0x1040080;
  }
  lVar4 = **(long **)(param_1 + 0x26e8);
  plVar3 = (long *)(lVar4 + 0x78);
  *plVar3 = *plVar3 + 1;
  *(undefined1 *)(lVar4 + 0x74) = 1;
  Header_calculateHeight(plVar2);
  Header_updateData(plVar2,lVar11,extraout_RDX_03,uVar9,param_r8,param_r9);
  Header_draw(plVar2,lVar11,extraout_RDX_04,uVar9,param_r8,param_r9);
  ScreenManager_resize(*(int **)(param_1 + 0x26e0));
  return uVar12;
}


/* FUN_0011c8e0 @ 0x11c8e0 */

void FUN_0011c8e0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined8 *puVar1;
  byte bVar2;
  long *a0;
  uint *puVar3;
  undefined8 *a3;
  undefined **ppuVar4;
  ulong a2;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  uint uVar5;
  undefined4 in_register_00000034;
  ulong a1;
  uint uVar6;
  undefined8 *puVar7;

  a1 = CONCAT44(in_register_00000034,param_2);
  puVar3 = (uint *)param_1[0x2e];
  uVar6 = *(uint *)(param_1[2] + 0x7c);
  if (puVar3 == (uint *)0x0) {
    puVar3 = malloc(0x10);
    if (puVar3 == (uint *)0x0) {
LAB_0011ca3b:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    param_1[0x2e] = (long)puVar3;
    a1 = 8;
    *puVar3 = uVar6;
    a3 = calloc((ulong)uVar6,8);
    if (a3 == (undefined8 *)0x0) goto LAB_0011ca3b;
    *(undefined8 **)(puVar3 + 2) = a3;
  }
  else {
    a3 = *(undefined8 **)(puVar3 + 2);
    uVar6 = *puVar3;
  }
  bVar2 = **(byte **)(*param_1 + 0x70);
  a2 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar6 = uVar6 + 1 >> 1;
  }
  else if (bVar2 == 0x52) {
    uVar5 = uVar6 + 1;
    uVar6 = uVar6 >> 1;
    uVar5 = uVar5 >> 1;
    goto LAB_0011c935;
  }
  uVar5 = 0;
LAB_0011c935:
  if (0 < (int)uVar6) {
    puVar1 = a3 + (int)uVar6;
    puVar7 = a3;
    do {
      uVar5 = uVar5 + 1;
      a0 = (long *)*puVar7;
      if (a0 == (long *)0x0) {
        a1 = (ulong)uVar5;
        a0 = Meter_new(param_1[2],uVar5,(long)&CPUMeter_class,(long)a3,param_r8,param_r9);
        *puVar7 = a0;
        a2 = extraout_RDX_00;
      }
      puVar7 = puVar7 + 1;
      (**(code **)(*a0 + 0x20))((long)a0,a1,a2,(long)a3,param_r8,param_r9);
      a2 = extraout_RDX;
    } while (puVar7 != puVar1);
  }
  if ((int)param_1[4] == 0) {
    *(undefined4 *)(param_1 + 4) = 1;
    ppuVar4 = &PTR_FUN_0015bf00;
  }
  else {
    ppuVar4 = *(undefined ***)(Meter_modes + (long)(int)param_1[4] * 8);
  }
  *(int *)(param_1 + 9) = ((int)((uVar6 - 1) + param_2) / param_2) * *(int *)(ppuVar4 + 2);
  return;
}


/* FUN_0011ca40 @ 0x11ca40 */

void FUN_0011ca40(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  FUN_0011c8e0(param_1,1,param_rdx,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0011ca50 @ 0x11ca50 */

void FUN_0011ca50(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  FUN_0011c8e0(param_1,2,param_rdx,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0011ca60 @ 0x11ca60 */

void FUN_0011ca60(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  FUN_0011c8e0(param_1,4,param_rdx,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0011ca70 @ 0x11ca70 */

void FUN_0011ca70(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  FUN_0011c8e0(param_1,8,param_rdx,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0011ca80 @ 0x11ca80 */

void FUN_0011ca80(long param_1)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  char *va1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  Platform_getBattery(&(*(double *)(__fp - 0x28)),&(*(int *)(__fp - 0x2c)));
  if ((*(double *)(__fp - 0x28)) < 0.0) {
    **(double **)(param_1 + 0x160) = NAN;
    xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_001474de /* "N/A" */));
  }
  else {
    **(double **)(param_1 + 0x160) = (*(double *)(__fp - 0x28));
    if ((*(int *)(__fp - 0x2c)) == 0) {
      va1 = ((char *)(long)&s__bat__001474d8 /* "(bat)" */);
      if (*(int *)(param_1 + 0x20) == 2) {
        va1 = ((char *)(long)&s__Running_on_battery__001474c2 /* " (Running on battery)" */);
      }
    }
    else {
      va1 = ((char *)(long)&DAT_00149c0c /* "" */);
      if (((*(int *)(__fp - 0x2c)) == 1) && (va1 = ((char *)(long)&s__A_C__001474bc /* "(A/C)" */), *(int *)(param_1 + 0x20) == 2)) {
        va1 = ((char *)(long)&s__Running_on_A_C__001474aa /* " (Running on A/C)" */);
      }
    }
    xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s___1f___s_001474e2 /* "%.1f%%%s" */),(*(double *)(__fp - 0x28)),va1);
  }
  if ((*(long *)(__fp - 0x20)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_0011cb80 @ 0x11cb80 */

void FUN_0011cb80(long param_1)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  void *pvVar2;
  undefined8 *puVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong va0;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar5 = *(long *)(param_1 + 0x26e0);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar6 = (ulong)(byte)(&DAT_00155fa0)[(long)*(int *)(*(long *)(lVar5 + 0x28) + 0x10) * 0x18];
  pvVar2 = malloc(uVar6 * 8);
  if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  plVar4 = *(long **)(param_1 + 0x26e8);
  lVar1 = *plVar4;
  if (uVar6 != 0) {
    uVar7 = 0;
    do {
      va0 = uVar7 + 1;
      xSnprintf((*(char (*)[40])(__fp - 0x68)),0x20,((char *)(long)&s_Column__zu_001474eb /* "Column %zu" */),va0);
      puVar3 = MetersPanel_new(lVar1,(*(char (*)[40])(__fp - 0x68)),*(long **)(**(long **)(param_1 + 0x26f0) + uVar7 * 8),
                               *(undefined8 *)(param_1 + 0x26e0));
      *(undefined8 **)((long)pvVar2 + uVar7 * 8) = puVar3;
      if (uVar7 != 0) {
        lVar5 = *(long *)((long)pvVar2 + uVar7 * 8 + -8);
        puVar3[0x4df] = lVar5;
        puVar3 = *(undefined8 **)((long)pvVar2 + uVar7 * 8);
        *(undefined8 **)(lVar5 + 0x2700) = puVar3;
      }
      ScreenManager_insert
                (*(int **)(param_1 + 0x26e0),(long)puVar3,0x14,
                 *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
      uVar7 = va0;
    } while (va0 != uVar6);
    lVar5 = *(long *)(param_1 + 0x26e0);
    plVar4 = *(long **)(param_1 + 0x26e8);
  }
  puVar3 = AvailableMetersPanel_new(plVar4,*(undefined8 *)(param_1 + 0x26f0),uVar6,pvVar2,lVar5);
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    ScreenManager_insert
              (*(int **)(param_1 + 0x26e0),(long)puVar3,-1,
               *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011cd00 @ 0x11cd00 */

void FUN_0011cd00(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;

  puVar3 = ScreensPanel_new(**(long **)(param_1 + 0x26e8));
  lVar1 = puVar3[0x4de];
  lVar2 = puVar3[0x4df];
  ScreenManager_insert
            (*(int **)(param_1 + 0x26e0),(long)puVar3,0x14,
             *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
  ScreenManager_insert
            (*(int **)(param_1 + 0x26e0),lVar1,0x14,
             *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
  ScreenManager_insert
            (*(int **)(param_1 + 0x26e0),lVar2,-1,
             *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
  return;
}


/* FUN_0011cd90 @ 0x11cd90 */

void FUN_0011cd90(long param_1)

{
  undefined8 *puVar1;

  puVar1 = HeaderOptionsPanel_new(**(undefined8 **)(param_1 + 0x26e8),*(long *)(param_1 + 0x26e0));
  ScreenManager_insert
            (*(int **)(param_1 + 0x26e0),(long)puVar1,-1,
             *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
  return;
}


/* FUN_0011cde0 @ 0x11cde0 */

undefined8
FUN_0011cde0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  uint uVar1;
  int iVar2;
  ushort **ppuVar3;
  undefined8 uVar4;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  int iVar5;
  undefined4 in_register_00000034;
  long a1;
  long lVar6;
  bool bVar7;

  a1 = CONCAT44(in_register_00000034,param_2);
  uVar1 = *(uint *)(param_1 + 5);
  if (param_2 != 0xe) {
    if (param_2 < 0xf) {
      if (param_2 == -1) goto LAB_0011ce18;
LAB_0011ced0:
      if (0xfd < param_2 - 1U) {
        return 2;
      }
      ppuVar3 = __ctype_b_loc();
      a1 = (long)param_2;
      if (-1 < (short)(*ppuVar3)[a1]) {
        return 2;
      }
      uVar4 = Panel_selectByTyping(param_1,param_2,(long)*ppuVar3,param_rcx,param_r8,param_r9);
      if ((int)uVar4 == 4) {
        return 2;
      }
      param_rdx = extraout_RDX_01;
      if ((int)uVar4 != 1) {
        return uVar4;
      }
      goto LAB_0011ce18;
    }
    if (param_2 != 0x106) {
      if (param_2 < 0x107) {
        if ((param_2 != 0x10) && (1 < param_2 - 0x102U)) goto LAB_0011ced0;
      }
      else if (param_2 < 0x154) {
        if (param_2 < 0x152) {
          return 2;
        }
      }
      else if (param_2 != 0x168) {
        return 2;
      }
    }
  }
  Panel_onKey((long)param_1,param_2);
  bVar7 = uVar1 == *(uint *)(param_1 + 5);
  param_rdx = extraout_RDX_00;
  uVar1 = *(uint *)(param_1 + 5);
  if (bVar7) {
    return 2;
  }
LAB_0011ce18:
  lVar6 = param_1[0x4dc];
  iVar2 = *(int *)(lVar6 + 0x20);
  if (1 < iVar2) {
    iVar5 = 1;
    while( true ) {
      a1 = 1;
      iVar5 = iVar5 + 1;
      ScreenManager_remove(lVar6,1,param_rdx,param_rcx,param_r8,param_r9);
      param_rdx = extraout_RDX;
      if (iVar5 == iVar2) break;
      lVar6 = param_1[0x4dc];
    }
  }
  if (uVar1 < 5) {
    (*(code *)(&PTR_FUN_00155f48)[(long)(int)uVar1 * 2])
              ((long)param_1,a1,param_rdx,param_rcx,param_r8,param_r9);
  }
  return 1;
}


/* FUN_0011cf50 @ 0x11cf50 */

undefined8
FUN_0011cf50(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  ushort **ppuVar7;
  undefined8 uVar8;
  byte bVar9;
  ulong uVar10;

  plVar5 = (long *)param_1[4];
  iVar3 = (int)param_1[5];
  iVar4 = (int)plVar5[3];
  if (0x128 < param_2) {
    if (param_2 != 0x14a) {
      if (param_2 < 0x14a) {
        return 2;
      }
      if ((param_2 != 0x157) && (param_2 != 0x199)) {
        return 2;
      }
      goto switchD_0011cf98_caseD_128;
    }
switchD_0011cf98_caseD_111:
    if (iVar3 < iVar4 + -1) {
      Panel_remove((long)param_1,iVar3,(long)plVar5,param_rcx,param_r8,param_r9);
    }
    goto LAB_0011d040;
  }
  if (param_2 < 0x102) {
    if (param_2 != 0x2d) {
      if (param_2 < 0x2e) {
        if (param_2 != 0xd) {
          if (param_2 == 0x2b) goto switchD_0011cf98_caseD_110;
          if (param_2 != 10) goto switchD_0011cf98_caseD_104;
        }
switchD_0011cf98_caseD_128:
        if (iVar4 + -1 <= iVar3) {
          return 2;
        }
        bVar9 = *(byte *)(param_1 + 0x4de) ^ 1;
        *(byte *)(param_1 + 0x4de) = bVar9;
        *(uint *)(param_1 + 0x4db) = bVar9 + 9;
        if ((0 < iVar4) && (lVar6 = *(long *)(*plVar5 + (long)iVar3 * 8), lVar6 != 0)) {
          *(byte *)(lVar6 + 0x14) = bVar9;
        }
        goto LAB_0011d040;
      }
      if (param_2 != 0x5b) {
        if (param_2 != 0x5d) goto switchD_0011cf98_caseD_104;
        goto switchD_0011cf98_caseD_110;
      }
    }
    goto switchD_0011cf98_caseD_10f;
  }
  uVar10 = (ulong)(param_2 - 0x102U);
  param_rcx = uVar10;
  if (param_2 - 0x102U < 0x27) {
    param_rcx = (long)&switchdataD_0014cd80 +
                (long)(int)(&switchdataD_0014cd80)[uVar10];
    switch(uVar10) {
    case 0:
      if ((char)param_1[0x4de] == '\0') {
        return 2;
      }
    case 0xe:
switchD_0011cf98_caseD_110:
      if (iVar3 < iVar4 + -2) {
        Panel_moveSelectedDown((long)param_1);
      }
      break;
    case 1:
      if ((char)param_1[0x4de] == '\0') {
        return 2;
      }
    case 0xd:
switchD_0011cf98_caseD_10f:
      if ((iVar3 < iVar4 + -1) && (iVar3 != 0)) {
        puVar1 = (undefined8 *)(*plVar5 + -8 + (long)iVar3 * 8);
        uVar8 = *puVar1;
        puVar2 = (undefined8 *)(*plVar5 + -8 + (long)iVar3 * 8);
        *puVar2 = puVar1[1];
        puVar2[1] = uVar8;
        if (0 < iVar3) {
          *(int *)(param_1 + 5) = iVar3 + -1;
        }
      }
      break;
    default:
      goto switchD_0011cf98_caseD_104;
    case 0xf:
      goto switchD_0011cf98_caseD_111;
    case 0x26:
      goto switchD_0011cf98_caseD_128;
    }
  }
  else {
switchD_0011cf98_caseD_104:
    if (0xfd < param_2 - 1U) {
      return 2;
    }
    ppuVar7 = __ctype_b_loc();
    if (-1 < (short)(*ppuVar7)[param_2]) {
      return 2;
    }
    uVar8 = Panel_selectByTyping(param_1,param_2,(long)*ppuVar7,param_rcx,param_r8,param_r9);
    if ((int)uVar8 == 4) {
      return 2;
    }
    if ((int)uVar8 != 1) {
      return uVar8;
    }
  }
LAB_0011d040:
  ColumnsPanel_update((long)param_1);
  return 1;
}

