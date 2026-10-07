#include "htop.h"

/* Platform_setBindings @ 0x13b340 */

void Platform_setBindings(long param_1)

{
  *(code **)(param_1 + 0x348) = FUN_001443c0;
  *(code **)(param_1 + 0x3d8) = FUN_0013dee0;
  *(code **)(param_1 + 1000) = FUN_0013dd80;
  *(code **)(param_1 + 0x8d8) = FUN_0013dee0;
  *(code **)(param_1 + 0x8e0) = FUN_0013dd80;
  return;
}


/* Platform_getUptime @ 0x13b390 */

int Platform_getUptime(void)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  int iVar1;
  FILE *__stream;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar2;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(double *)(__fp - 0x28)) = 0.0;
  __stream = fopen(((char *)(long)&s__proc_uptime_001499c4 /* "/proc/uptime" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__64lf_001499d1 /* "%64lf" */),&(*(double *)(__fp - 0x28)));
    fclose(__stream);
    if (iVar1 < 1) {
      iVar1 = 0;
      goto LAB_0013b41d;
    }
  }
  dVar2 = (*(double *)(__fp - 0x28));
  if (ABS((*(double *)(__fp - 0x28))) < 4503599627370496.0) {
    dVar2 = __builtin_floor((*(double *)(__fp - 0x28)));
  }
  iVar1 = (int)dVar2;
LAB_0013b41d:
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getLoadAverage @ 0x13b480 */

void Platform_getLoadAverage(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  FILE *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_loadavg_001499d7 /* "/proc/loadavg" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__lf__lf__lf_001499e5 /* "%lf %lf %lf" */),&(*(undefined8 *)(__fp - 0x48)),&(*(undefined8 *)(__fp - 0x50)),&(*(undefined8 *)(__fp - 0x58)));
    fclose(__stream);
    if (iVar1 == 3) {
      *param_1 = (*(undefined8 *)(__fp - 0x48));
      *param_2 = (*(undefined8 *)(__fp - 0x50));
      goto LAB_0013b509;
    }
  }
  (*(undefined8 *)(__fp - 0x58)) = 0x7ff8000000000000;
  *param_1 = 0x7ff8000000000000;
  *param_2 = 0x7ff8000000000000;
LAB_0013b509:
  *param_3 = (*(undefined8 *)(__fp - 0x58));
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getMaxPid @ 0x13b560 */

undefined4 Platform_getMaxPid(void)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  FILE *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined4 *)(__fp - 0x24)) = 0x3fffff;
  __stream = fopen(((char *)(long)&s__proc_sys_kernel_pid_max_00148869 /* "/proc/sys/kernel/pid_max" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    __isoc23_fscanf(__stream,((char *)(long)&DAT_0014978b /* "%32d" */),&(*(undefined4 *)(__fp - 0x24)));
    fclose(__stream);
  }
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return (*(undefined4 *)(__fp - 0x24));
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_setCPUValues @ 0x13b5e0 */

double Platform_setCPUValues(long param_1,uint param_2)

{
  long lVar1;
  char cVar2;
  char cVar3;
  long lVar4;
  double *pdVar5;
  ulong uVar6;
  undefined16 auVar7;
  undefined16 auVar8;
  ulong uVar9;
  double *pdVar10;
  ulong uVar11;
  ulong uVar12;
  double dVar13;
  undefined16 auVar14;
  undefined16 auVar15;
  undefined16 auVar16;
  undefined16 auVar17;
  double dVar18;
  double dVar19;

  dVar18 = 1.0;
  lVar4 = **(long **)(param_1 + 0x10);
  lVar1 = (*(long **)(param_1 + 0x10))[0x1c] + (ulong)param_2 * 0xd8;
  uVar11 = *(ulong *)(lVar1 + 0x60);
  if (uVar11 == 0) {
LAB_0013b623:
    cVar2 = *(char *)(lVar1 + 0xd0);
    pdVar5 = *(double **)(param_1 + 0x160);
  }
  else {
    if (-1 < (long)uVar11) {
      dVar18 = (double)(long)uVar11;
      goto LAB_0013b623;
    }
    cVar2 = *(char *)(lVar1 + 0xd0);
    pdVar5 = *(double **)(param_1 + 0x160);
    dVar18 = (double)uVar11;
  }
  if (cVar2 == '\0') {
    *(undefined1 *)(param_1 + 0x50) = 0;
    return NAN;
  }
  uVar11 = *(ulong *)(lVar1 + 0x90);
  if ((long)uVar11 < 0) {
    uVar9 = *(ulong *)(lVar1 + 0x68);
    dVar13 = (double)uVar11;
    if (-1 < (long)uVar9) goto LAB_0013b665;
LAB_0013b7be:
    dVar19 = (double)uVar9;
  }
  else {
    dVar13 = (double)(long)uVar11;
    uVar9 = *(ulong *)(lVar1 + 0x68);
    if ((long)uVar9 < 0) goto LAB_0013b7be;
LAB_0013b665:
    dVar19 = (double)(long)uVar9;
  }
  cVar2 = *(char *)(lVar4 + 0x51);
  uVar11 = *(ulong *)(lVar1 + 0xb0);
  uVar9 = *(ulong *)(lVar1 + 0xb8);
  *pdVar5 = (dVar13 / dVar18) * 100.0;
  pdVar5[1] = (dVar19 / dVar18) * 100.0;
  if (cVar2 == '\0') {
    uVar6 = *(ulong *)(lVar1 + 0x78);
    if ((long)uVar6 < 0) {
      dVar13 = (double)uVar6;
      if (-1 < (long)(uVar11 + uVar9)) goto LAB_0013b83f;
LAB_0013b8ea:
      dVar19 = (double)(uVar11 + uVar9);
    }
    else {
      dVar13 = (double)(long)uVar6;
      if ((long)(uVar11 + uVar9) < 0) goto LAB_0013b8ea;
LAB_0013b83f:
      dVar19 = (double)(long)(uVar11 + uVar9);
    }
    uVar11 = 4;
    pdVar5[2] = (dVar13 / dVar18) * 100.0;
    pdVar5[3] = (dVar19 / dVar18) * 100.0;
    *(undefined1 *)(param_1 + 0x50) = 4;
LAB_0013b869:
    dVar13 = 0.0;
    pdVar10 = pdVar5;
    do {
      if (0.0 < *pdVar10) {
        dVar13 = dVar13 + *pdVar10;
      }
      pdVar10 = pdVar10 + 1;
    } while (pdVar5 + uVar11 != pdVar10);
    if (100.0 <= dVar13) {
      dVar13 = 100.0;
    }
    if (cVar2 == '\0') goto LAB_0013b8a4;
  }
  else {
    uVar6 = *(ulong *)(lVar1 + 0x70);
    if ((long)uVar6 < 0) {
      uVar12 = *(ulong *)(lVar1 + 0xa0);
      dVar13 = (double)uVar6;
      if (-1 < (long)uVar12) goto LAB_0013b6cb;
LAB_0013b93a:
      dVar19 = (double)uVar12;
    }
    else {
      dVar13 = (double)(long)uVar6;
      uVar12 = *(ulong *)(lVar1 + 0xa0);
      if ((long)uVar12 < 0) goto LAB_0013b93a;
LAB_0013b6cb:
      dVar19 = (double)(long)uVar12;
    }
    uVar6 = *(ulong *)(lVar1 + 0xa8);
    pdVar5[2] = (dVar13 / dVar18) * 100.0;
    pdVar5[3] = (dVar19 / dVar18) * 100.0;
    pdVar5[4] = ((double)uVar6 / dVar18) * 100.0;
    *(undefined1 *)(param_1 + 0x50) = 5;
    pdVar5[5] = ((double)uVar11 / dVar18) * 100.0;
    cVar3 = *(char *)(lVar4 + 0x6c);
    pdVar5[6] = ((double)uVar9 / dVar18) * 100.0;
    if (cVar3 != '\0') {
      *(undefined1 *)(param_1 + 0x50) = 7;
      uVar11 = 7;
      pdVar5[7] = ((double)*(ulong *)(lVar1 + 0x98) / dVar18) * 100.0;
      goto LAB_0013b869;
    }
    uVar11 = (ulong)*(byte *)(param_1 + 0x50);
    dVar13 = 0.0;
    pdVar5[7] = ((double)*(ulong *)(lVar1 + 0x98) / dVar18) * 100.0;
    if (uVar11 != 0) goto LAB_0013b869;
  }
  *(undefined1 *)(param_1 + 0x50) = 8;
LAB_0013b8a4:
  pdVar5[8] = *(double *)(lVar1 + 0xc0);
  pdVar5[9] = *(double *)(lVar1 + 200);
  return dVar13;
}


/* Platform_setMemoryValues @ 0x13ba40 */

void Platform_setMemoryValues(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  double *pdVar4;
  ulong uVar5;
  double dVar6;
  double dVar7;

  lVar2 = *(long *)(param_1 + 0x10);
  uVar3 = *(ulong *)(lVar2 + 0x38);
  pdVar4 = *(double **)(param_1 + 0x160);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(lVar2 + 0x30);
  dVar6 = (double)uVar3;
  uVar3 = *(ulong *)(lVar2 + 0x50);
  uVar5 = *(ulong *)(lVar2 + 0x40);
  pdVar4[2] = 0.0;
  *pdVar4 = dVar6;
  pdVar4[1] = (double)uVar3;
  uVar3 = *(ulong *)(lVar2 + 0x48);
  pdVar4[3] = (double)uVar5;
  uVar5 = *(ulong *)(lVar2 + 0x58);
  pdVar4[4] = (double)uVar3;
  iVar1 = *(int *)(lVar2 + 0x1b8);
  pdVar4[5] = (double)uVar5;
  if ((iVar1 != 0) && (Running_containerized == '\0')) {
    dVar7 = 0.0;
    if (*(ulong *)(lVar2 + 0x1c0) < *(ulong *)(lVar2 + 0x1d0)) {
      dVar7 = (double)(*(ulong *)(lVar2 + 0x1d0) - *(ulong *)(lVar2 + 0x1c0));
      dVar6 = dVar6 - dVar7;
    }
    *pdVar4 = dVar6;
    pdVar4[4] = (double)uVar3 + dVar7;
    pdVar4[5] = (double)uVar5 + dVar7;
  }
  if (*(ulong *)(lVar2 + 0x228) != 0 || *(long *)(lVar2 + 0x230) != 0) {
    dVar6 = (double)*(ulong *)(lVar2 + 0x228);
    *pdVar4 = *pdVar4 - dVar6;
    pdVar4[2] = dVar6 + 0.0;
  }
  return;
}


/* Platform_setSwapValues @ 0x13bca0 */

void Platform_setSwapValues(long param_1)

{
  long lVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  double dVar5;
  double dVar6;

  lVar1 = *(long *)(param_1 + 0x10);
  uVar2 = *(ulong *)(lVar1 + 0x68);
  pdVar3 = *(double **)(param_1 + 0x160);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(lVar1 + 0x60);
  dVar5 = (double)uVar2;
  uVar2 = *(ulong *)(lVar1 + 0x70);
  uVar4 = *(ulong *)(lVar1 + 0x230);
  pdVar3[2] = 0.0;
  *pdVar3 = dVar5;
  pdVar3[1] = (double)uVar2;
  if (uVar4 != 0) {
    dVar6 = (double)uVar4;
    dVar5 = dVar5 - dVar6;
    *pdVar3 = dVar5;
    if (dVar5 < 0.0) {
      *pdVar3 = 0.0;
      pdVar3[1] = (double)uVar2 + dVar5;
    }
    pdVar3[2] = dVar6 + 0.0;
    return;
  }
  if (*(long *)(lVar1 + 0x228) != 0) {
    *pdVar3 = dVar5;
    pdVar3[2] = 0.0;
    return;
  }
  return;
}


/* Platform_setZramValues @ 0x13be10 */

void Platform_setZramValues(long param_1)

{
  long lVar1;
  double *pdVar2;
  ulong uVar3;
  double dVar4;

  lVar1 = *(long *)(param_1 + 0x10);
  uVar3 = *(ulong *)(lVar1 + 0x218);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(lVar1 + 0x210);
  dVar4 = (double)uVar3;
  uVar3 = *(long *)(lVar1 + 0x220) - uVar3;
  if (-1 < (long)uVar3) {
    pdVar2 = *(double **)(param_1 + 0x160);
    *pdVar2 = dVar4;
    pdVar2[1] = (double)(long)uVar3;
    return;
  }
  pdVar2 = *(double **)(param_1 + 0x160);
  *pdVar2 = dVar4;
  pdVar2[1] = (double)uVar3;
  return;
}


/* Platform_setZfsArcValues @ 0x13bef0 */

void Platform_setZfsArcValues(long param_1)

{
  long lVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;

  lVar1 = *(long *)(param_1 + 0x10);
  uVar2 = *(ulong *)(lVar1 + 0x1d8);
  pdVar3 = *(double **)(param_1 + 0x160);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(lVar1 + 0x1c8);
  uVar4 = *(ulong *)(lVar1 + 0x1e0);
  *pdVar3 = (double)uVar2;
  uVar2 = *(ulong *)(lVar1 + 0x1e8);
  pdVar3[1] = (double)uVar4;
  uVar4 = *(ulong *)(lVar1 + 0x1f0);
  pdVar3[2] = (double)uVar2;
  uVar2 = *(ulong *)(lVar1 + 0x1f8);
  pdVar3[3] = (double)uVar4;
  pdVar3[4] = (double)uVar2;
  *(undefined1 *)(param_1 + 0x50) = 5;
  uVar2 = *(ulong *)(lVar1 + 0x1d0);
  if (-1 < (long)uVar2) {
    pdVar3[5] = (double)(long)uVar2;
    return;
  }
  pdVar3[5] = (double)uVar2;
  return;
}


/* Platform_setZfsCompressedArcValues @ 0x13c270 */

void Platform_setZfsCompressedArcValues(long param_1)

{
  long lVar1;
  double *pdVar2;
  ulong uVar3;
  double dVar4;

  lVar1 = *(long *)(param_1 + 0x10);
  pdVar2 = *(double **)(param_1 + 0x160);
  if (*(int *)(lVar1 + 0x1bc) == 0) {
    uVar3 = *(ulong *)(lVar1 + 0x1d0);
    *(double *)(param_1 + 0x168) = (double)uVar3;
    *pdVar2 = (double)uVar3;
    return;
  }
  if ((long)*(ulong *)(lVar1 + 0x208) < 0) {
    uVar3 = *(ulong *)(lVar1 + 0x200);
  }
  else {
    uVar3 = *(ulong *)(lVar1 + 0x200);
  }
  dVar4 = (double)*(ulong *)(lVar1 + 0x208);
  if (-1 < (long)uVar3) {
    *(double *)(param_1 + 0x168) = dVar4;
    *pdVar2 = (double)(long)uVar3;
    return;
  }
  *(double *)(param_1 + 0x168) = dVar4;
  *pdVar2 = (double)uVar3;
  return;
}


/* Platform_getFileDescriptors @ 0x13c450 */

void Platform_getFileDescriptors(double *param_1,double *param_2)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  int iVar1;
  FILE *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  *param_1 = NAN;
  *param_2 = 65536.0;
  __stream = fopen(((char *)(long)&s__proc_sys_fs_file_nr_001499f1 /* "/proc/sys/fs/file-nr" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__llu__llu__llu_00149a06 /* "%llu %llu %llu" */),&(*(ulong *)(__fp - 0x38)),(*(undefined1 (*)[8])(__fp - 0x40)),&(*(ulong *)(__fp - 0x48)));
    if (iVar1 == 3) {
      if ((long)(*(ulong *)(__fp - 0x38)) < 0) {
        *param_1 = (double)(*(ulong *)(__fp - 0x38));
      }
      else {
        *param_1 = (double)(long)(*(ulong *)(__fp - 0x38));
      }
      *param_2 = (double)(*(ulong *)(__fp - 0x48));
    }
    fclose(__stream);
  }
  if ((*(long *)(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Platform_getDiskIO @ 0x13c570 */

undefined8 Platform_getDiskIO(long *param_1)

{
  undefined1 __frame[0x248] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x208;
  char cVar1;
  int iVar2;
  FILE *__stream;
  char *pcVar3;
  size_t __n;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_diskstats_00149a15 /* "/proc/diskstats" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
    uVar5 = 0;
  }
  else {
    lVar6 = 0;
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x188)), (undefined16)0x0);
    (*(long *)(__fp - 0x1b8)) = 0;
    (*(long *)(__fp - 0x1b0)) = 0;
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x178)), (undefined16)0x0);
LAB_0013c600:
    pcVar3 = fgets((*(char (*)[264])(__fp - 0x148)),0x100,__stream);
    if (pcVar3 != (char *)0x0) {
      iVar2 = __isoc23_sscanf((*(char (*)[264])(__fp - 0x148)),((char *)(long)&s___d___d__31s___u___u__llu___u____0014ca50 /* "%*d %*d %31s %*u %*u %llu %*u %*u %*u %llu %*u %*u %llu" */),
                              &(*(undefined4 *)(__fp - 0x168)),&(*(long *)(__fp - 0x190)),&(*(long *)(__fp - 0x198)),&(*(long *)(__fp - 0x1a0)));
      if ((iVar2 == 4) &&
         ((((short)(*(undefined4 *)(__fp - 0x168)) != 0x6d64 || ((*(uchar *)((char *)&(*(undefined4 *)(__fp - 0x168)) + 2)) != '-')) && ((*(undefined4 *)(__fp - 0x168)) != 0x6d61727a))))
      {
        if ((*(undefined1 (*)[16])(__fp - 0x188))[0] != '\0') {
          __n = strlen((*(undefined1 (*)[16])(__fp - 0x188)));
          iVar2 = strncmp((char *)&(*(undefined4 *)(__fp - 0x168)),(*(undefined1 (*)[16])(__fp - 0x188)),__n);
          if (iVar2 == 0) goto LAB_0013c600;
        }
        lVar4 = 0;
        do {
          cVar1 = *(char *)((long)&(*(undefined4 *)(__fp - 0x168)) + lVar4);
          if (cVar1 == '\0') break;
          (*(undefined1 (*)[16])(__fp - 0x188))[lVar4] = cVar1;
          lVar4 = lVar4 + 1;
        } while (lVar4 != 0x1f);
        (*(undefined1 (*)[16])(__fp - 0x188))[lVar4] = 0;
        (*(long *)(__fp - 0x1b0)) = (*(long *)(__fp - 0x1b0)) + (*(long *)(__fp - 0x190));
        lVar6 = lVar6 + (*(long *)(__fp - 0x1a0));
        (*(long *)(__fp - 0x1b8)) = (*(long *)(__fp - 0x1b8)) + (*(long *)(__fp - 0x198));
      }
      goto LAB_0013c600;
    }
    fclose(__stream);
    param_1[2] = lVar6;
    *param_1 = (*(long *)(__fp - 0x1b0)) << 9;
    param_1[1] = (*(long *)(__fp - 0x1b8)) << 9;
    uVar5 = 1;
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


/* Platform_getNetworkIO @ 0x13c770 */

undefined8 Platform_getNetworkIO(undefined1 (*param_1) [16])

{
  undefined1 __frame[0x308] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2c8;
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  FILE *__stream;
  char *pcVar5;
  undefined8 uVar6;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_net_dev_00149a2e /* "/proc/net/dev" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
    uVar6 = 0;
  }
  else {
    *(undefined16 *)(*param_1) = (undefined16)0x0;
    *(undefined16 *)(param_1[1]) = (undefined16)0x0;
    while( true ) {
      pcVar5 = fgets((*(char (*)[520])(__fp - 0x238)),0x200,__stream);
      if (pcVar5 == (char *)0x0) break;
      iVar4 = __isoc23_sscanf((*(char (*)[520])(__fp - 0x238)),((char *)(long)&s__31s__llu__llu___u___u___u___u___0014ca88 /* "%31s %llu %llu %*u %*u %*u %*u %*u %*u %llu %llu" */),(*(int (*)[8])(__fp - 0x258))
                              ,&(*(long *)(__fp - 0x260)),&(*(long *)(__fp - 0x268)),&(*(long *)(__fp - 0x270)),&(*(long *)(__fp - 0x278)));
      if ((iVar4 == 5) && ((*(int (*)[8])(__fp - 0x258))[0] != 0x3a6f6c)) {
        lVar1 = *(long *)(param_1[1] + 8);
        lVar2 = *(long *)*param_1;
        lVar3 = *(long *)(*param_1 + 8);
        *(long *)param_1[1] = (*(long *)(__fp - 0x270)) + *(long *)param_1[1];
        *(long *)(param_1[1] + 8) = (*(long *)(__fp - 0x278)) + lVar1;
        *(long *)*param_1 = (*(long *)(__fp - 0x260)) + lVar2;
        *(long *)(*param_1 + 8) = (*(long *)(__fp - 0x268)) + lVar3;
      }
    }
    fclose(__stream);
    uVar6 = 1;
  }
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_longOptionsUsage @ 0x13c8c0 */

void Platform_longOptionsUsage(void)

{
  return;
}


/* Platform_getLongOption @ 0x13c8d0 */

undefined8 Platform_getLongOption(void)

{
  return 1;
}


/* Platform_done @ 0x13c8e0 */

void Platform_done(long param_rdi,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                  long param_r9)

{
  if (PTR_0015c0b8 != (void *)0x0) {
    (*(code *)PTR_0015c0b0)(param_rdi,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
    dlclose(PTR_0015c0b8);
    PTR_0015c0b8 = (void *)0x0;
    return;
  }
  return;
}


/* FUN_0013c920 @ 0x13c920 */

undefined8 FUN_0013c920(void)

{
  undefined1 __frame[0x11d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1198;
  ssize_t sVar1;
  FILE *__stream;
  char *pcVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  LibSensors_init();
  sVar1 = readlink(((char *)(long)&s__proc_self_ns_pid_00149a40 /* "/proc/self/ns/pid" */),(char *)&(*(long *)(__fp - 0x1048)),0xfff);
  if ((sVar1 < 1) ||
     ((*(undefined1 *)((long)&(*(long *)(__fp - 0x1048)) + sVar1) = 0,
      (*(long *)(__fp - 0x1048)) == 0x3230345b3a646970 && (*(long *)(__fp - 0x1040)) == 0x5d36333831333536 && ((*(char *)(__fp - 0x1038)) == '\0')))
     ) {
    __stream = fopen(((char *)(long)&s__proc_1_mounts_00149a63 /* "/proc/1/mounts" */),((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream != (FILE *)0x0) {
      do {
        pcVar2 = fgets((char *)&(*(undefined7 *)(__fp - 0x1148)),0x100,__stream);
        if (pcVar2 == (char *)0x0) goto LAB_0013ca70;
        if ((CONCAT17((undefined1)(*(int *)(__fp - 0x1141)),(*(undefined7 *)(__fp - 0x1148))) == 0x702f20736663786c) &&
           ((*(int *)(__fp - 0x1141)) == 0x636f7270)) {
          Running_containerized = '\x01';
          goto LAB_0013ca70;
        }
      } while ((CONCAT17((undefined1)(*(int *)(__fp - 0x1141)),(*(undefined7 *)(__fp - 0x1148))) != 0x2079616c7265766f ||
                CONCAT53((*(undefined5 *)(__fp - 0x113d)),(*(ulong *)((char *)&(*(int *)(__fp - 0x1141)) + 1))) != 0x616c7265766f202f) ||
              ((*(char *)(__fp - 0x1138)) != 'y'));
      Running_containerized = '\x01';
LAB_0013ca70:
      fclose(__stream);
    }
  }
  else {
    Running_containerized = '\x01';
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_init @ 0x13caa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Platform_init(void)

{
  int iVar1;
  undefined8 uVar2;

  iVar1 = access(((char *)(long)&s__proc_00149a78 /* "/proc" */),4);
  if (iVar1 == 0) {
    uVar2 = FUN_0013c920();
    return uVar2;
  }
  __fprintf_chk(_stderr,2,((char *)(long)&s_Error__could_not_read_procfs__co_0014b168 /* "Error: could not read procfs (compiled to look in %s).\n" */),((char *)(long)&s__proc_00149a78 /* "/proc" */));
  return 0;
}


/* Platform_getPressureStall @ 0x13ccc0 */

void Platform_getPressureStall
               (void *param_1,char param_2,undefined8 *param_3,undefined8 *param_4,
               undefined8 *param_5)

{
  undefined1 __frame[0x158] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x118;
  FILE *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  *param_5 = 0;
  *param_4 = 0;
  *param_3 = 0;
  xSnprintf((*(char (*)[136])(__fp - 0xc8)),0x80,((char *)(long)&s__proc_pressure__s_00149a90 /* "/proc/pressure/%s" */),param_1);
  __stream = fopen((*(char (*)[136])(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
    *param_5 = 0x7ff8000000000000;
    *param_4 = 0x7ff8000000000000;
    *param_3 = 0x7ff8000000000000;
  }
  else {
    __isoc23_fscanf(__stream,((char *)(long)&s_some_avg10__32lf_avg60__32lf_avg_0014cac0 /* "some avg10=%32lf avg60=%32lf avg300=%32lf total=%*f " */),param_3,param_4,
                    param_5);
    if (param_2 == '\0') {
      __isoc23_fscanf(__stream,((char *)(long)&s_full_avg10__32lf_avg60__32lf_avg_0014caf8 /* "full avg10=%32lf avg60=%32lf avg300=%32lf total=%*f " */),param_3,
                      param_4,param_5);
    }
    fclose(__stream);
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0013cdd0 @ 0x13cdd0 */

double FUN_0013cdd0(void)

{
  undefined1 __frame[0xa78] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa38;
  int iVar1;
  DIR *__dirp;
  dirent *pdVar2;
  char *pcVar3;
  int *piVar4;
  long lVar5;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar6;
  double dVar7;

  bVar6 = 0;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __dirp = opendir(((char *)(long)&s__proc_acpi_battery_00149aa2 /* "/proc/acpi/battery" */));
  if (__dirp != (DIR *)0x0) {
    (*(ulong *)(__fp - 0x9e8)) = 0;
    (*(ulong *)(__fp - 0x9e0)) = 0;
LAB_0013ce30:
    pdVar2 = readdir(__dirp);
    if (pdVar2 != (dirent *)0x0) {
      if (((pdVar2->d_name[0] == 'B') && (pdVar2->d_name[1] == 'A')) && (pdVar2->d_name[2] == 'T'))
      {
        pcVar3 = (*(char (*)[1032])(__fp - 0x448));
        for (lVar5 = 0x80; lVar5 != 0; lVar5 = lVar5 + -1) {
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
          pcVar3[4] = '\0';
          pcVar3[5] = '\0';
          pcVar3[6] = '\0';
          pcVar3[7] = '\0';
          pcVar3 = pcVar3 + (ulong)bVar6 * -0x10 + 8;
        }
        xSnprintf((*(char (*)[256])(__fp - 0x948)),0x100,((char *)(long)&s__s__s_info_00149ab5 /* "%s/%s/info" */),((char *)(long)&s__proc_acpi_battery_00149aa2 /* "/proc/acpi/battery" */),pdVar2->d_name);
        iVar1 = open((*(char (*)[256])(__fp - 0x948)),0);
        if (iVar1 < 0) {
          piVar4 = __errno_location();
          lVar5 = (long)-*piVar4;
        }
        else {
          lVar5 = FUN_0013a450(iVar1,(*(char (*)[1032])(__fp - 0x448)),0x400);
        }
        if (-1 < lVar5) {
          pcVar3 = (*(char (*)[1024])(__fp - 0x848));
          for (lVar5 = 0x80; lVar5 != 0; lVar5 = lVar5 + -1) {
            pcVar3[0] = '\0';
            pcVar3[1] = '\0';
            pcVar3[2] = '\0';
            pcVar3[3] = '\0';
            pcVar3[4] = '\0';
            pcVar3[5] = '\0';
            pcVar3[6] = '\0';
            pcVar3[7] = '\0';
            pcVar3 = pcVar3 + (ulong)bVar6 * -0x10 + 8;
          }
          xSnprintf((*(char (*)[256])(__fp - 0x948)),0x100,((char *)(long)&s__s__s_state_00149ac0 /* "%s/%s/state" */),((char *)(long)&s__proc_acpi_battery_00149aa2 /* "/proc/acpi/battery" */),pdVar2->d_name);
          iVar1 = open((*(char (*)[256])(__fp - 0x948)),0);
          if (iVar1 < 0) {
            piVar4 = __errno_location();
            lVar5 = (long)-*piVar4;
          }
          else {
            lVar5 = FUN_0013a450(iVar1,(*(char (*)[1024])(__fp - 0x848)),0x400);
          }
          if (-1 < lVar5) {
            (*(char * *)(__fp - 0x9c0)) = (*(char (*)[1032])(__fp - 0x448));
            do {
              pcVar3 = strsep(&(*(char * *)(__fp - 0x9c0)),((char *)(long)&DAT_00147506 /* "\n" */));
              if (pcVar3 == (char *)0x0) goto LAB_0013cfdb;
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x9b8)), (undefined16)0x0);
              (*(undefined4 *)(__fp - 0x958)) = 0;
              (*(int *)(__fp - 0x9c4)) = 0;
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x9a8)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x998)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x988)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x978)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x968)), (undefined16)0x0);
              iVar1 = __isoc23_sscanf(pcVar3,((char *)(long)&s__99______d_00149acc /* "%99[^:]:%d" */),(*(undefined1 (*)[16])(__fp - 0x9b8)),&(*(int *)(__fp - 0x9c4)));
            } while ((iVar1 != 2) || (iVar1 = strcmp((*(undefined1 (*)[16])(__fp - 0x9b8)),((char *)(long)&s_last_full_capacity_00149ad7 /* "last full capacity" */)), iVar1 != 0));
            (*(ulong *)(__fp - 0x9e0)) = (*(ulong *)(__fp - 0x9e0)) + (long)(*(int *)(__fp - 0x9c4));
LAB_0013cfdb:
            (*(char * *)(__fp - 0x9c0)) = (*(char (*)[1024])(__fp - 0x848));
            do {
              pcVar3 = strsep(&(*(char * *)(__fp - 0x9c0)),((char *)(long)&DAT_00147506 /* "\n" */));
              if (pcVar3 == (char *)0x0) goto LAB_0013ce30;
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x9b8)), (undefined16)0x0);
              (*(undefined4 *)(__fp - 0x958)) = 0;
              (*(int *)(__fp - 0x9c4)) = 0;
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x9a8)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x998)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x988)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x978)), (undefined16)0x0);
              ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x968)), (undefined16)0x0);
              iVar1 = __isoc23_sscanf(pcVar3,((char *)(long)&s__99______d_00149acc /* "%99[^:]:%d" */),(*(undefined1 (*)[16])(__fp - 0x9b8)),&(*(int *)(__fp - 0x9c4)));
            } while ((iVar1 != 2) || (iVar1 = strcmp((*(undefined1 (*)[16])(__fp - 0x9b8)),((char *)(long)&s_remaining_capacity_00149aea /* "remaining capacity" */)), iVar1 != 0));
            (*(ulong *)(__fp - 0x9e8)) = (*(ulong *)(__fp - 0x9e8)) + (long)(*(int *)(__fp - 0x9c4));
          }
        }
      }
      goto LAB_0013ce30;
    }
    closedir(__dirp);
    if ((*(ulong *)(__fp - 0x9e0)) != 0) {
      dVar7 = ((double)(*(ulong *)(__fp - 0x9e8)) * 100.0) / (double)(*(ulong *)(__fp - 0x9e0));
      goto LAB_0013d120;
    }
  }
  dVar7 = NAN;
LAB_0013d120:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return dVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getBattery @ 0x13d1a0 */

void Platform_getBattery(double *param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  time_t tVar3;
  undefined7 extraout_var;
  double dVar4;

  tVar3 = time((time_t *)0x0);
  iVar2 = INT_0015d888;
  if (tVar3 <= LONG_0015d890 + 9) {
    *param_1 = DOUBLE_0015c070;
    *param_2 = iVar2;
    return;
  }
  if (INT_0015d884 == 0) {
    uVar1 = FUN_0013a540();
    iVar2 = (int)CONCAT71(extraout_var,uVar1);
    *param_2 = iVar2;
    if (iVar2 == 2) {
      *param_1 = NAN;
    }
    else {
      dVar4 = FUN_0013cdd0();
      *param_1 = dVar4;
      if (0.0 <= dVar4) goto LAB_0013d1df;
    }
    INT_0015d884 = 1;
LAB_0013d23e:
    FUN_0013a5e0(param_1,param_2);
    if (*param_1 < 0.0) {
      INT_0015d884 = 2;
      goto LAB_0013d267;
    }
  }
  else {
LAB_0013d1df:
    if (INT_0015d884 == 1) goto LAB_0013d23e;
  }
  if (INT_0015d884 != 2) {
    DOUBLE_0015c070 = *param_1;
    if (DOUBLE_0015c070 <= 100.0) {
      if (DOUBLE_0015c070 <= 0.0) {
        DOUBLE_0015c070 = 0.0;
      }
      INT_0015d888 = *param_2;
      *param_1 = DOUBLE_0015c070;
      LONG_0015d890 = tVar3;
      return;
    }
    INT_0015d888 = *param_2;
    *param_1 = 100.0;
    DOUBLE_0015c070 = 100.0;
    LONG_0015d890 = tVar3;
    return;
  }
LAB_0013d267:
  *param_1 = NAN;
  *param_2 = 2;
  LONG_0015d890 = tVar3;
  INT_0015d888 = 2;
  DOUBLE_0015c070 = NAN;
  return;
}


/* FUN_0013d320 @ 0x13d320 */

void FUN_0013d320(long *param_1)

{
  undefined8 *puVar1;
  double *pdVar2;
  char *pcVar3;
  char *pcVar4;
  undefined *va0;
  char *va1;

  va1 = ((char *)(long)(__sec_rodata + 0x2e61) /* "cpu" */);
  pcVar4 = *(char **)(*param_1 + 0x70);
  pcVar3 = strstr(pcVar4,((char *)(long)(__sec_rodata + 0x826) /* "CPU" */));
  if (pcVar3 == (char *)0x0) {
    va1 = ((char *)(long)&DAT_0014a0f3 /* "io" */);
    pcVar3 = strstr(pcVar4,((char *)(long)(__sec_rodata + 0x859) /* "IO" */));
    if (pcVar3 == (char *)0x0) {
      va1 = ((char *)(long)(__sec_rodata + 0x8f5) /* "memory" */);
      pcVar3 = strstr(pcVar4,((char *)(long)(__sec_rodata + 0x8be) /* "IRQ" */));
      if (pcVar3 != (char *)0x0) {
        va1 = ((char *)(long)&DAT_00147051 /* "irq" */);
      }
    }
  }
  pcVar4 = strstr(pcVar4,((char *)(long)(__sec_rodata + 0x84b) /* "Some" */));
  puVar1 = (undefined8 *)param_1[0x2c];
  Platform_getPressureStall(va1,pcVar4 != (char *)0x0,puVar1,puVar1 + 1,puVar1 + 2);
  *(undefined1 *)(param_1 + 10) = 1;
  pdVar2 = (double *)param_1[0x2c];
  va0 = &DAT_00149b02;
  if (pcVar4 != (char *)0x0) {
    va0 = &DAT_00149afd;
  }
  xSnprintf((char *)(param_1 + 0xc),0x100,((char *)(long)&s__s__s__5_2lf____5_2lf____5_2lf___0014cb30 /* "%s %s %5.2lf%% %5.2lf%% %5.2lf%%" */),va0,va1,*pdVar2,
            pdVar2[1],pdVar2[2]);
  return;
}


/* FUN_0013d430 @ 0x13d430 */

void FUN_0013d430(long param_1)

{
  undefined1 __frame[0x1a8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x168;
  char cVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  char *va0;
  char *va1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = statfs(((char *)(long)&s__sys_fs_selinux_00149b3d /* "/sys/fs/selinux" */),&(*(struct statfs *)(__fp - 0xa8)));
  if ((iVar2 == 0) && ((int)(*(struct statfs *)(__fp - 0xa8)).f_type == -0x6830074)) {
    iVar2 = statvfs(((char *)(long)&s__sys_fs_selinux_00149b3d /* "/sys/fs/selinux" */),&(*(struct statvfs *)(__fp - 0x118)));
    if ((iVar2 != 0) || (((byte)(*(struct statvfs *)(__fp - 0x118)).f_flag & 1) != 0)) goto LAB_0013d47f;
    iVar2 = access(((char *)(long)&s__etc_selinux_config_00149b4d /* "/etc/selinux/config" */),0);
    if (iVar2 != 0) goto LAB_0013d47f;
    CHAR____0015d880 = '\x01';
    iVar2 = open(((char *)(long)&s__sys_fs_selinux_enforce_00149b61 /* "/sys/fs/selinux/enforce" */),0);
    if (iVar2 < 0) {
      piVar4 = __errno_location();
      lVar3 = (long)-*piVar4;
    }
    else {
      lVar3 = FUN_0013a450(iVar2,(undefined1 *)&(*(struct statfs *)(__fp - 0xa8)),0x14);
    }
    cVar1 = CHAR____0015d880;
    if (lVar3 < 0) {
LAB_0013d588:
      if (cVar1 != '\0') {
LAB_0013d591:
        va1 = ((char *)(long)&s___mode__permissive_00149b2a /* "; mode: permissive" */);
        va0 = ((char *)(long)&s_enabled_00149b19 /* "enabled" */);
        goto LAB_0013d494;
      }
    }
    else {
      (*(int *)(__fp - 0x11c)) = 0;
      iVar2 = __isoc23_sscanf((char *)&(*(struct statfs *)(__fp - 0xa8)),((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),&(*(int *)(__fp - 0x11c)));
      if (iVar2 != 1) goto LAB_0013d588;
      if (cVar1 != '\0') {
        if ((*(int *)(__fp - 0x11c)) != 0) {
          va1 = ((char *)(long)&s___mode__enforcing_00149b07 /* "; mode: enforcing" */);
          va0 = ((char *)(long)&s_enabled_00149b19 /* "enabled" */);
          goto LAB_0013d494;
        }
        goto LAB_0013d591;
      }
    }
  }
  else {
LAB_0013d47f:
    CHAR____0015d880 = '\0';
  }
  va1 = ((char *)(long)&DAT_00149c0c /* "" */);
  va0 = ((char *)(long)&s_disabled_00149b21 /* "disabled" */);
LAB_0013d494:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),va0,va1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0013d5c0 @ 0x13d5c0 */

void FUN_0013d5c0(long param_1)

{
  long lVar1;
  ulong uVar2;
  double dVar3;
  double dVar4;

  lVar1 = *(long *)(param_1 + 0x10);
  if (*(int *)(lVar1 + 0x1bc) == 0) {
    dVar4 = (double)*(ulong *)(lVar1 + 0x1d0);
    dVar3 = dVar4;
  }
  else {
    if ((long)*(ulong *)(lVar1 + 0x208) < 0) {
      uVar2 = *(ulong *)(lVar1 + 0x200);
    }
    else {
      uVar2 = *(ulong *)(lVar1 + 0x200);
    }
    dVar3 = (double)*(ulong *)(lVar1 + 0x208);
    if ((long)uVar2 < 0) {
      dVar4 = (double)uVar2;
    }
    else {
      dVar4 = (double)(long)uVar2;
    }
  }
  *(double *)(param_1 + 0x168) = dVar3;
  **(double **)(param_1 + 0x160) = dVar4;
  if (0.0 < dVar4) {
    xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s___2f_1_00149b79 /* "%.2f:1" */),*(double *)(param_1 + 0x168) / dVar4);
    return;
  }
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_001474de /* "N/A" */));
  return;
}


/* FUN_0013d700 @ 0x13d700 */

undefined8 FUN_0013d700(long param_1,int param_2,long param_3,char param_4,undefined1 *param_5)

{
  undefined1 __frame[0x8f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x8b8;
  char *__s;
  char cVar1;
  undefined16 auVar2;
  undefined16 auVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  ulong uVar9;
  undefined8 uVar10;
  int *piVar11;
  long lVar12;
  char *pcVar13;
  uint uVar14;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(char (*)[32])(__fp - 0x868))[8] = '\0';
  (*(char (*)[32])(__fp - 0x868))[9] = '\0';
  (*(char (*)[32])(__fp - 0x868))[10] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0xb] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0xc] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0xd] = '\0';
  builtin_strncpy((*(char (*)[32])(__fp - 0x868)),"stat",5);
  (*(char (*)[32])(__fp - 0x868))[5] = '\0';
  (*(char (*)[32])(__fp - 0x868))[6] = '\0';
  (*(char (*)[32])(__fp - 0x868))[7] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0xe] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0xf] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0x10] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0x11] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0x12] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0x13] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0x14] = '\0';
  (*(char (*)[32])(__fp - 0x868))[0x15] = '\0';
  if (param_4 != '\0') {
    xSnprintf((*(char (*)[32])(__fp - 0x868)),0x16,((char *)(long)&s_task__i_stat_00149b80 /* "task/%i/stat" */),*(int *)(param_1 + 0x10));
  }
  iVar4 = openat(param_2,(*(char (*)[32])(__fp - 0x868)),0);
  if (iVar4 < 0) {
    piVar11 = __errno_location();
    lVar5 = (long)-*piVar11;
  }
  else {
    lVar5 = FUN_0013a450(iVar4,(*(char (*)[2056])(__fp - 0x848)),0x801);
  }
  if ((-1 < lVar5) && (pcVar6 = strchr((*(char (*)[2056])(__fp - 0x848)),0x20), pcVar6 != (char *)0x0)) {
    __s = pcVar6 + 2;
    (*(char * *)(__fp - 0x870)) = __s;
    pcVar7 = strrchr(__s,0x29);
    if (pcVar7 != (char *)0x0) {
      pcVar13 = pcVar7 + (1 - (long)__s);
      if ((char *)0x81 < pcVar13) {
        pcVar13 = (char *)0x81;
      }
      pcVar8 = (char *)0x0;
      if (__s != pcVar7) {
        do {
          if (pcVar6[(long)(pcVar8 + 2)] == '\0') break;
          param_5[(long)pcVar8] = pcVar6[(long)(pcVar8 + 2)];
          pcVar8 = pcVar8 + 1;
        } while (pcVar8 < pcVar13 + -1);
        param_5 = param_5 + (long)pcVar8;
      }
      cVar1 = pcVar7[2];
      *param_5 = 0;
      uVar14 = 1;
      if ((byte)(cVar1 + 0xbcU) < 0x31) {
        uVar14 = (uint)(byte)(&DAT_0014e5e0)[(byte)(cVar1 + 0xbcU)];
      }
      *(uint *)(param_1 + 0x108) = uVar14;
      (*(char * *)(__fp - 0x870)) = pcVar7 + 4;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(int *)(param_1 + 0x18) = (int)lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(int *)(param_1 + 0x40) = (int)lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(int *)(param_1 + 0x44) = (int)lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoul((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x50) = uVar9;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(int *)(param_1 + 0x48) = (int)lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoul((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x260) = uVar9;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0xf8) = uVar9;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x1f0) = uVar9;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x100) = uVar9;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x1f8) = uVar9;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x200) = (uVar9 * 100) / *(ulong *)(param_3 + 0xb8);
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x208) = (uVar9 * 100) / *(ulong *)(param_3 + 0xb8);
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x210) = (uVar9 * 100) / *(ulong *)(param_3 + 0xb8);
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      uVar9 = __isoc23_strtoull((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(ulong *)(param_1 + 0x218) = (uVar9 * 100) / *(ulong *)(param_3 + 0xb8);
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(long *)(param_1 + 0xc0) = lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(long *)(param_1 + 200) = lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(long *)(param_1 + 0xd0) = lVar5;
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      (*(char * *)(__fp - 0x870)) = strchr((*(char * *)(__fp - 0x870)),0x20);
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      if (*(long *)(param_1 + 0xd8) == 0) {
        lVar5 = *(long *)(param_3 + 0xd0);
        lVar12 = __isoc23_strtoll((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
        (*(ulong *)((char *)&auVar2 + 8)) = 0;
        (*(ulong *)((char *)&auVar2 + 0)) = *(ulong *)(param_3 + 0xb8);
        (*(ulong *)((char *)&auVar3 + 8)) = 0;
        (*(ulong *)((char *)&auVar3 + 0)) = lVar12 * 100;
        *(long *)(param_1 + 0xd8) =
             SUB168((auVar3 / auVar2 >> 2 & (undefined16)0x3fffffffffffffff) /
                    (undefined16)0x19,0) + lVar5;
      }
      else {
        (*(char * *)(__fp - 0x870)) = strchr((*(char * *)(__fp - 0x870)),0x20);
      }
      (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
      iVar4 = 0x10;
      do {
        (*(char * *)(__fp - 0x870)) = strchr((*(char * *)(__fp - 0x870)),0x20);
        (*(char * *)(__fp - 0x870)) = (*(char * *)(__fp - 0x870)) + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      lVar5 = __isoc23_strtol((*(char * *)(__fp - 0x870)),&(*(char * *)(__fp - 0x870)),10);
      *(int *)(param_1 + 0xb0) = (int)lVar5;
      *(long *)(param_1 + 0x78) = *(long *)(param_1 + 0x208) + *(long *)(param_1 + 0x200);
      uVar10 = 1;
      goto LAB_0013dbb2;
    }
  }
  uVar10 = 0;
LAB_0013dbb2:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


/* FUN_0013dc70 @ 0x13dc70 */

bool FUN_0013dc70(ulong param_1,int param_2)

{
  undefined1 __frame[0x1d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x198;
  int iVar1;
  FILE *__stream;
  bool bVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf((*(char (*)[264])(__fp - 0x138)),0x100,((char *)(long)&s__proc__d_autogroup_00149b8d /* "/proc/%d/autogroup" */),(int)param_1);
  __stream = fopen((*(char (*)[264])(__fp - 0x138)),((char *)(long)&DAT_00149ba0 /* "r+" */));
  if (__stream == (FILE *)0x0) {
    bVar2 = false;
    goto LAB_0013dcf9;
  }
  iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__autogroup__ld_nice__d_00149ba3 /* "/autogroup-%ld nice %d" */),(*(undefined1 (*)[8])(__fp - 0x140)),&(*(int *)(__fp - 0x144)));
  if (iVar1 == 2) {
    iVar1 = fseek(__stream,0,0);
    if (iVar1 != 0) goto LAB_0013dcee;
    xSnprintf((*(char (*)[264])(__fp - 0x138)),0x100,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(*(int *)(__fp - 0x144)) + param_2);
    iVar1 = fputs((*(char (*)[264])(__fp - 0x138)),__stream);
    bVar2 = 0 < iVar1;
  }
  else {
LAB_0013dcee:
    bVar2 = false;
  }
  fclose(__stream);
LAB_0013dcf9:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getProcessEnv @ 0x13f480 */

void * Platform_getProcessEnv(ulong param_1)

{
  undefined1 __frame[0x158] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x118;
  FILE *__stream;
  void *__ptr;
  ulong uVar1;
  void *pvVar2;
  ulong uVar3;
  ulong __size;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf((*(char (*)[136])(__fp - 0xc8)),0x80,((char *)(long)&s__proc__d_environ_00149be4 /* "/proc/%d/environ" */),(int)param_1);
  __stream = fopen((*(char (*)[136])(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    uVar1 = 0;
    uVar3 = 0;
    __size = 0;
    pvVar2 = (void *)0x0;
    do {
      __size = __size + 0x1000;
      uVar3 = uVar3 + uVar1;
      __ptr = realloc(pvVar2,__size);
      if (__ptr == (void *)0x0) {
        free(pvVar2);
                    /* WARNING: Subroutine does not return */
        fail();
      }
      uVar1 = __size;
      if (__size <= uVar3) {
        uVar1 = uVar3;
      }
      uVar1 = __fread_chk((void *)((long)__ptr + uVar3),uVar1 - uVar3,1,__size - uVar3,__stream);
      pvVar2 = __ptr;
    } while (0 < (long)uVar1);
    fclose(__stream);
    if (uVar1 == 0) {
      pvVar2 = realloc(__ptr,uVar3 + 2);
      if (pvVar2 == (void *)0x0) {
        free(__ptr);
                    /* WARNING: Subroutine does not return */
        fail();
      }
      *(undefined2 *)((long)pvVar2 + uVar3) = 0;
      goto LAB_0013f564;
    }
    free(__ptr);
  }
  pvVar2 = (void *)0x0;
LAB_0013f564:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getProcessLocks @ 0x13f5c0 */

undefined1 * Platform_getProcessLocks(uint param_1)

{
  undefined1 __frame[0x25d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2598;
  char *p0;
  int __fd;
  int iVar1;
  undefined1 *puVar2;
  size_t sVar3;
  DIR *__dirp;
  dirent *pdVar4;
  int *piVar5;
  ulong uVar6;
  FILE *__stream;
  char *pcVar7;
  ulong uVar8;
  undefined8 *puVar9;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar2 = calloc(1,0x10);
  if (puVar2 == (undefined1 *)0x0) {
LAB_0013fa8d:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  xSnprintf((*(char (*)[4096])(__fp - 0x2048)),0x1000,((char *)(long)&s__proc__d_fdinfo__00149bf5 /* "/proc/%d/fdinfo/" */),param_1);
  sVar3 = strlen((*(char (*)[4096])(__fp - 0x2048)));
  if ((sVar3 < 0xffe) && (__dirp = opendir((*(char (*)[4096])(__fp - 0x2048))), __dirp != (DIR *)0x0)) {
    __fd = dirfd(__dirp);
    (*(undefined8 * *)(__fp - 0x2550)) = (undefined8 *)(puVar2 + 8);
    if (__fd != -1) {
      while (pdVar4 = readdir(__dirp), pdVar4 != (dirent *)0x0) {
        p0 = pdVar4->d_name;
        if (((pdVar4->d_name[0] != '.') || (pdVar4->d_name[1] != '\0')) &&
           ((pdVar4->d_name[0] != '.' || ((pdVar4->d_name[1] != '.' || (pdVar4->d_name[2] != '\0')))
            ))) {
          piVar5 = __errno_location();
          *piVar5 = 0;
          (*(char * *)(__fp - 0x2520)) = p0;
          uVar6 = __isoc23_strtoull(p0,&(*(char * *)(__fp - 0x2520)),10);
          if ((*piVar5 == 0) &&
             ((*(*(char * *)(__fp - 0x2520)) == '\0' && (iVar1 = openat(__fd,p0,0x80000), iVar1 != -1)))) {
            __stream = fdopen(iVar1,((char *)(long)&DAT_00147760 /* "r" */));
            if (__stream == (FILE *)0x0) {
              close(iVar1);
            }
            else {
              while (pcVar7 = fgets((char *)&(*(int *)(__fp - 0x2448)),0x400,__stream), pcVar7 != (char *)0x0) {
                pcVar7 = strchr((char *)&(*(int *)(__fp - 0x2448)),10);
                if (((pcVar7 != (char *)0x0) && ((*(int *)(__fp - 0x2448)) == 0x6b636f6c)) && ((*(short *)(__fp - 0x2444)) == 0x93a)
                   ) {
                  __builtin_memset(__fp - 0x24f4,0,12);
                  (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x24f8)) + 0)) = (int)uVar6;
                  (*(ulong *)(__fp - 0x24d8)) = 0;
                  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x2518)), (undefined16)0x0);
                  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x2508)), (undefined16)0x0);
                  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x24e8)), (undefined16)0x0);
                  iVar1 = __isoc23_sscanf((*(char (*)[1018])(__fp - 0x2442)),((char *)(long)&s__d___31s__31s__31s__d__x__x__lu___0014cb58 /* "%d: %31s %31s %31s %d %x:%x:%lu %lu %24s" */),
                                          (*(undefined1 (*)[4])(__fp - 0x2524)),(*(char (*)[32])(__fp - 0x2468)),(*(char (*)[32])(__fp - 0x2488)),(*(char (*)[32])(__fp - 0x24a8)),(*(undefined1 (*)[4])(__fp - 0x2524)),
                                          &(*(uint *)(__fp - 0x2528)),&(*(uint *)(__fp - 0x252c)),(*(undefined1 (*)[16])(__fp - 0x24e8)),(*(undefined1 (*)[16])(__fp - 0x24e8)) + 8,
                                          (*(int (*)[8])(__fp - 0x24c8)));
                  if (iVar1 == 10) {
                    pcVar7 = strdup((*(char (*)[32])(__fp - 0x2468)));
                    if (pcVar7 == (char *)0x0) goto LAB_0013fa8d;
                    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2518)) + 0)) = pcVar7;
                    pcVar7 = strdup((*(char (*)[32])(__fp - 0x2488)));
                    if (pcVar7 == (char *)0x0) goto LAB_0013fa8d;
                    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2518)) + 8)) = pcVar7;
                    pcVar7 = strdup((*(char (*)[32])(__fp - 0x24a8)));
                    if (pcVar7 == (char *)0x0) goto LAB_0013fa8d;
                    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2508)) + 0)) = pcVar7;
                    (*(ulong *)(__fp - 0x24f0)) = ((ulong)(*(uint *)(__fp - 0x252c)) & 0xffffff00) << 0xc |
                                  ((ulong)(*(uint *)(__fp - 0x2528)) & 0xfffff000) << 0x20 |
                                  (ulong)(((*(uint *)(__fp - 0x2528)) & 0xfff) << 8) | (ulong)(byte)(*(uint *)(__fp - 0x252c));
                    uVar8 = 0xffffffffffffffff;
                    if ((*(int (*)[8])(__fp - 0x24c8))[0] != 0x464f45) {
                      uVar8 = __isoc23_strtoull((char *)(*(int (*)[8])(__fp - 0x24c8)),(char **)0x0,10);
                    }
                    (*(ulong *)(__fp - 0x24d8)) = uVar8;
                    xSnprintf((*(char (*)[4096])(__fp - 0x2048)),0x1000,((char *)(long)&s__proc__d_fd__s_00149c11 /* "/proc/%d/fd/%s" */),param_1,p0);
                    sVar3 = strlen((*(char (*)[4096])(__fp - 0x2048)));
                    if (sVar3 < 0xffe) {
                      sVar3 = readlink((*(char (*)[4096])(__fp - 0x2048)),(*(char (*)[4104])(__fp - 0x1048)),0x1000);
                      if (sVar3 != 0xffffffffffffffff) {
                        pcVar7 = strndup((*(char (*)[4104])(__fp - 0x1048)),sVar3);
                        if (pcVar7 == (char *)0x0) goto LAB_0013fa8d;
                        (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2508)) + 8)) = pcVar7;
                      }
                    }
                    puVar9 = calloc(1,0x50);
                    if (puVar9 == (undefined8 *)0x0) goto LAB_0013fa8d;
                    *(*(undefined8 * *)(__fp - 0x2550)) = puVar9;
                    (*(undefined8 * *)(__fp - 0x2550)) = puVar9 + 9;
                    *puVar9 = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2518)) + 0));
                    puVar9[1] = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2518)) + 8));
                    puVar9[2] = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2508)) + 0));
                    puVar9[3] = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x2508)) + 8));
                    puVar9[4] = (*(undefined1 (*)[8])(__fp - 0x24f8));
                    puVar9[5] = (*(ulong *)(__fp - 0x24f0));
                    puVar9[6] = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x24e8)) + 0));
                    puVar9[7] = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x24e8)) + 8));
                    puVar9[8] = (*(ulong *)(__fp - 0x24d8));
                  }
                }
              }
              fclose(__stream);
            }
          }
        }
      }
      closedir(__dirp);
      goto LAB_0013f656;
    }
    closedir(__dirp);
  }
  *puVar2 = 1;
LAB_0013f656:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar2;
}


/* FUN_0013fab0 @ 0x13fab0 */

void FUN_0013fab0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  uint uVar1;
  int iVar2;
  __pid_t _Var3;
  long lVar4;
  FILE *__stream;
  ulong uVar5;
  void *p0;
  char *a3;
  undefined *va0;
  long extraout_RDX;
  long a0;
  long extraout_RDX_00;
  long *a0_00;
  char *pcVar6;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar7;
  char *pcVar8;

  a0_00 = (long *)&DAT_0015d840;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = strcmp(*(char **)(*param_1 + 0x70),((char *)(long)&s_SystemdUser_001477b1 /* "SystemdUser" */));
  if (uVar1 == 0) {
    a0_00 = &DAT_0015d860;
  }
  pcVar8 = (char *)0x13fb0e;
  free((void *)a0_00[1]);
  bVar7 = PTR_0015d830 == (void *)0x0;
  a0_00[1] = 0;
  *(undefined4 *)(a0_00 + 2) = 0xffffffff;
  *(undefined4 *)((long)a0_00 + 0x14) = 0xffffffff;
  *(undefined4 *)(a0_00 + 3) = 0xffffffff;
  *(undefined4 *)((long)a0_00 + 0x1c) = 0xffffffff;
  lVar4 = extraout_RDX;
  if (bVar7) {
    p0 = dlopen(((char *)(long)&s_libsystemd_so_0_00149c30 /* "libsystemd.so.0" */),1);
    PTR_0015d830 = p0;
    if (p0 != (void *)0x0) {
      dlerror();
      PTR_0015d820 = dlsym(p0,((char *)(long)&s_sd_bus_open_system_00149c40 /* "sd_bus_open_system" */));
      if ((((((PTR_0015d820 != (undefined *)0x0) && (pcVar8 = dlerror(), pcVar8 == (char *)0x0)) &&
            (PTR_0015d818 = dlsym(p0,((char *)(long)&s_sd_bus_open_user_00149c53 /* "sd_bus_open_user" */)), PTR_0015d818 != (undefined *)0x0)) &&
           ((pcVar8 = dlerror(), pcVar8 == (char *)0x0 &&
            (PTR_0015d810 = dlsym(p0,((char *)(long)&s_sd_bus_get_property_string_00149c64 /* "sd_bus_get_property_string" */)), PTR_0015d810 != (undefined *)0x0
            )))) && ((pcVar8 = dlerror(), pcVar8 == (char *)0x0 &&
                     ((PTR_0015d808 = dlsym(p0,((char *)(long)&s_sd_bus_get_property_trivial_00149c7f /* "sd_bus_get_property_trivial" */)),
                      PTR_0015d808 != (undefined *)0x0 &&
                      (pcVar8 = dlerror(), pcVar8 == (char *)0x0)))))) &&
         (PTR_0015d828 = dlsym(p0,((char *)(long)&s_sd_bus_unref_00149c9b /* "sd_bus_unref" */)), PTR_0015d828 != (undefined *)0x0)) {
        pcVar8 = (char *)0x13fef1;
        pcVar6 = dlerror();
        lVar4 = extraout_RDX_00;
        if (pcVar6 == (char *)0x0) goto LAB_0013fb37;
      }
      dlclose(p0);
      PTR_0015d830 = (void *)0x0;
    }
  }
  else {
LAB_0013fb37:
    a0 = *a0_00;
    if (a0 == 0) {
      pcVar6 = (char *)(ulong)uVar1;
      if (uVar1 == 0) {
        pcVar8 = (char *)0x13fdfe;
        lVar4 = (*(code *)PTR_0015d818)((long)a0_00,0,lVar4,param_rcx,param_r8,param_r9);
        iVar2 = (int)lVar4;
        a3 = (char *)param_rcx;
      }
      else {
        pcVar8 = (char *)0x13fca7;
        lVar4 = (*(code *)PTR_0015d820)((long)a0_00,(long)pcVar6,lVar4,param_rcx,param_r8,param_r9);
        iVar2 = (int)lVar4;
        a3 = (char *)param_rcx;
      }
      a0 = *a0_00;
      if (-1 < iVar2) goto LAB_0013fb43;
    }
    else {
LAB_0013fb43:
      a3 = pcVar8;
      param_r9 = 0;
      param_r8 = (long)(__sec_rodata + 0x2cfe);
      pcVar6 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
      lVar4 = (*(code *)PTR_0015d810)(a0,(long)&s_org_freedesktop_systemd1_00149cc2,(long)&s__org_freedesktop_systemd1_00149ca8,(long)&s_org_freedesktop_systemd1_Manager_0014cb88,(long)(__sec_rodata + 0x2cfe),0);
      if (-1 < (int)lVar4) {
        param_r9 = 0;
        a3 = ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */);
        param_r8 = (long)(__sec_rodata + 0x2ce6);
        pcVar6 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
        lVar4 = (*(code *)PTR_0015d808)(*a0_00,(long)&s_org_freedesktop_systemd1_00149cc2,(long)&s__org_freedesktop_systemd1_00149ca8,(long)&s_org_freedesktop_systemd1_Manager_0014cb88,(long)(__sec_rodata + 0x2ce6),0);
        if (-1 < (int)lVar4) {
          param_r9 = (long)a0_00 + 0x14;
          a3 = ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */);
          pcVar6 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
          param_r8 = 0x75;
          lVar4 = (*(code *)PTR_0015d808)(*a0_00,(long)&s_org_freedesktop_systemd1_00149cc2,(long)&s__org_freedesktop_systemd1_00149ca8,(long)&s_org_freedesktop_systemd1_Manager_0014cb88,(long)(__sec_rodata + 0x2d24),0);
          if (-1 < (int)lVar4) {
            param_r9 = 0;
            param_r8 = (long)(__sec_rodata + 0x2d4f);
            a3 = ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */);
            pcVar6 = (char *)0x75;
            lVar4 = (*(code *)PTR_0015d808)(*a0_00,(long)&s_org_freedesktop_systemd1_00149cc2,(long)&s__org_freedesktop_systemd1_00149ca8,(long)&s_org_freedesktop_systemd1_Manager_0014cb88,(long)(__sec_rodata + 0x2d4f),0);
            if (-1 < (int)lVar4) {
              a3 = (char *)((long)a0_00 + 0x1c);
              param_r9 = 0;
              param_r8 = (long)(__sec_rodata + 0x2d3e);
              pcVar6 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
              lVar4 = (*(code *)PTR_0015d808)(*a0_00,(long)&s_org_freedesktop_systemd1_00149cc2,(long)&s__org_freedesktop_systemd1_00149ca8,(long)&s_org_freedesktop_systemd1_Manager_0014cb88,(long)(__sec_rodata + 0x2d3e),0);
              if (-1 < (int)lVar4) goto LAB_0013fc3d;
            }
          }
        }
      }
      a0 = *a0_00;
    }
    (*(code *)PTR_0015d828)(a0,(long)pcVar6,a0,(long)a3,param_r8,param_r9);
    *a0_00 = 0;
  }
  if ((CHAR____0015c0d9 == '\0') && (iVar2 = pipe(&(*(int *)(__fp - 0xd0))), -1 < iVar2)) {
    _Var3 = fork();
    if (_Var3 < 0) {
      close((*(int *)(__fp - 0xcc)));
      close((*(int *)(__fp - 0xd0)));
    }
    else {
      if (_Var3 == 0) {
        close((*(int *)(__fp - 0xd0)));
        dup2((*(int *)(__fp - 0xcc)),1);
        close((*(int *)(__fp - 0xcc)));
        iVar2 = open(((char *)(long)&s__dev_null_001488eb /* "/dev/null" */),1);
        if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        dup2(iVar2,2);
        close(iVar2);
        pcVar8 = ((char *)(long)&s___system_00149c27 /* "--system" */);
        if (uVar1 == 0) {
          pcVar8 = ((char *)(long)&s___user_00149c20 /* "--user" */);
        }
        execlp(((char *)(long)&s_systemctl_00149d0f /* "systemctl" */),((char *)(long)&s_systemctl_00149d0f /* "systemctl" */),&DAT_00149d0a,pcVar8,((char *)(long)&s___property_SystemState_00149cf3 /* "--property=SystemState" */),
               ((char *)(long)&s___property_NFailedUnits_00149cdb /* "--property=NFailedUnits" */),((char *)(long)&s___property_NNames_00149d44 /* "--property=NNames" */),((char *)(long)&s___property_NJobs_00149d33 /* "--property=NJobs" */),
               ((char *)(long)&s___property_NInstalledJobs_00149d19 /* "--property=NInstalledJobs" */),0);
                    /* WARNING: Subroutine does not return */
        exit(0x7f);
      }
      close((*(int *)(__fp - 0xcc)));
      _Var3 = waitpid(_Var3,(int *)&(*(uint *)(__fp - 0xd4)),0);
      if (((_Var3 < 0) || (((*(uint *)(__fp - 0xd4)) & 0xff7f) != 0)) ||
         (__stream = fdopen((*(int *)(__fp - 0xd0)),((char *)(long)&DAT_00147760 /* "r" */)), __stream == (FILE *)0x0)) {
        close((*(int *)(__fp - 0xd0)));
      }
      else {
        while (pcVar8 = fgets((char *)&(*(int *)(__fp - 0xc8)),0x80,__stream), pcVar8 != (char *)0x0) {
          if ((CONCAT17((*(char *)(__fp - 0xc1)),
                        CONCAT16((*(char *)(__fp - 0xc2)),CONCAT15((*(undefined1 *)(__fp - 0xc3)),CONCAT14((*(undefined1 *)(__fp - 0xc4)),(*(int *)(__fp - 0xc8)))))) ==
               0x74536d6574737953) && ((*(int *)(__fp - 0xc0)) == 0x3d657461)) {
            pcVar8 = strchr(&(*(char *)(__fp - 0xbc)),10);
            if (pcVar8 != (char *)0x0) {
              *pcVar8 = '\0';
            }
            pcVar8 = (char *)a0_00[1];
            if ((pcVar8 == (char *)0x0) || (iVar2 = strcmp(pcVar8,&(*(char *)(__fp - 0xbc))), iVar2 != 0)) {
              free(pcVar8);
              pcVar8 = strdup(&(*(char *)(__fp - 0xbc)));
              if (pcVar8 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
                fail();
              }
              a0_00[1] = (long)pcVar8;
            }
          }
          else if ((CONCAT17((*(char *)(__fp - 0xc1)),
                             CONCAT16((*(char *)(__fp - 0xc2)),CONCAT15((*(undefined1 *)(__fp - 0xc3)),CONCAT14((*(undefined1 *)(__fp - 0xc4)),(*(int *)(__fp - 0xc8))))))
                    == 0x5564656c6961464e) &&
                  (CONCAT17((*(char *)(__fp - 0xbc)),CONCAT43((*(int *)(__fp - 0xc0)),CONCAT12((*(char *)(__fp - 0xc1)),
                                                                CONCAT11((*(char *)(__fp - 0xc2)),(*(undefined1 *)(__fp - 0xc3)))))) ==
                   0x3d7374696e556465)) {
            uVar5 = __isoc23_strtoul((char *)&(*(undefined2 *)(__fp - 0xbb)),(char **)0x0,10);
            *(int *)(a0_00 + 2) = (int)uVar5;
          }
          else if (((*(int *)(__fp - 0xc8)) == 0x6d614e4e) &&
                  (CONCAT13((*(char *)(__fp - 0xc2)),CONCAT12((*(undefined1 *)(__fp - 0xc3)),CONCAT11((*(undefined1 *)(__fp - 0xc4)),0x6d))) == 0x3d73656d))
          {
            uVar5 = __isoc23_strtoul(&(*(char *)(__fp - 0xc1)),(char **)0x0,10);
            *(int *)(a0_00 + 3) = (int)uVar5;
          }
          else if (((*(int *)(__fp - 0xc8)) == 0x626f4a4e) && (CONCAT11((*(undefined1 *)(__fp - 0xc3)),(*(undefined1 *)(__fp - 0xc4))) == 0x3d73)) {
            uVar5 = __isoc23_strtoul(&(*(char *)(__fp - 0xc2)),(char **)0x0,10);
            *(int *)((long)a0_00 + 0x1c) = (int)uVar5;
          }
          else if ((CONCAT17((*(char *)(__fp - 0xc1)),
                             CONCAT16((*(char *)(__fp - 0xc2)),CONCAT15((*(undefined1 *)(__fp - 0xc3)),CONCAT14((*(undefined1 *)(__fp - 0xc4)),(*(int *)(__fp - 0xc8))))))
                    == 0x6c6c6174736e494e) &&
                  (CONCAT26((*(undefined2 *)(__fp - 0xbb)),CONCAT15((*(char *)(__fp - 0xbc)),CONCAT41((*(int *)(__fp - 0xc0)),(*(char *)(__fp - 0xc1))))) ==
                   0x3d73626f4a64656c)) {
            uVar5 = __isoc23_strtoul((*(char (*)[121])(__fp - 0xb9)),(char **)0x0,10);
            *(int *)((long)a0_00 + 0x14) = (int)uVar5;
          }
        }
        fclose(__stream);
      }
    }
  }
LAB_0013fc3d:
  va0 = (undefined *)a0_00[1];
  if (va0 == (undefined *)0x0) {
    va0 = &DAT_00148963;
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  xSnprintf((char *)(param_1 + 0xc),0x100,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),va0);
  return;
}


/* FUN_00140160 @ 0x140160 */

long * FUN_00140160(__pid_t param_1,long param_2)

{
  undefined1 __frame[0x158] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x118;
  uint uVar1;
  int iVar2;
  long *plVar3;
  void *pvVar4;
  void *pvVar5;
  ulong uVar6;
  ulong uVar7;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = sched_getaffinity(param_1,0x80,&(*(cpu_set_t *)(__fp - 0xc8)));
  if (iVar2 != 0) {
    plVar3 = (long *)0x0;
LAB_00140250:
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return plVar3;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  plVar3 = calloc(1,0x18);
  if (plVar3 != (long *)0x0) {
    *(undefined4 *)(plVar3 + 1) = 8;
    pvVar4 = calloc(8,4);
    if (pvVar4 != (void *)0x0) {
      plVar3[2] = (long)pvVar4;
      iVar2 = *(int *)(param_2 + 0x7c);
      *plVar3 = param_2;
      if (iVar2 != 0) {
        uVar6 = 0;
        do {
          while ((uVar6 < 0x400 && (((*(cpu_set_t *)(__fp - 0xc8)).__bits[uVar6 >> 6] >> (uVar6 & 0x3f) & 1) != 0))) {
            uVar1 = *(uint *)((long)plVar3 + 0xc);
            pvVar4 = (void *)plVar3[2];
            pvVar5 = pvVar4;
            if (uVar1 == *(uint *)(plVar3 + 1)) {
              *(uint *)(plVar3 + 1) = uVar1 * 2;
              pvVar5 = realloc(pvVar4,(ulong)(uVar1 * 2) * 4);
              if (pvVar5 == (void *)0x0) {
                free(pvVar4);
                goto LAB_001402bb;
              }
              plVar3[2] = (long)pvVar5;
            }
            uVar7 = uVar6 + 1;
            *(int *)((long)pvVar5 + (ulong)uVar1 * 4) = (int)uVar6;
            *(uint *)((long)plVar3 + 0xc) = uVar1 + 1;
            uVar6 = uVar7;
            if (*(uint *)(param_2 + 0x7c) <= (uint)uVar7) goto LAB_00140250;
          }
          uVar6 = uVar6 + 1;
        } while ((uint)uVar6 < *(uint *)(param_2 + 0x7c));
      }
      goto LAB_00140250;
    }
  }
LAB_001402bb:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001402d0 @ 0x1402d0 */

void FUN_001402d0(void)

{
  undefined1 __frame[0x458] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x418;
  char cVar1;
  int iVar2;
  FILE *__stream;
  char *pcVar3;
  char *pcVar4;
  undefined *va1;
  ulong uVar5;
  undefined *va0;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = uname(&(*(utsname *)(__fp - 0x1c8)));
  __stream = fopen(((char *)(long)&s__etc_os_release_00149d90 /* "/etc/os-release" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
    xSnprintf((*(char (*)[128])(__fp - 0x348)),0x80,((char *)(long)&s_No_OS_Release_00149da0 /* "No OS Release" */));
  }
  else {
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x3c8)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x3b8)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x3a8)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x398)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x388)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x378)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x368)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x358)), (undefined16)0x0);
    do {
      while( true ) {
        pcVar3 = fgets((char *)&(*(int *)(__fp - 0x2c8)),0x100,__stream);
        if (pcVar3 == (char *)0x0) {
          fclose(__stream);
          va1 = &DAT_00149c0c;
          va0 = &DAT_00149c0c;
          if (((*(undefined1 (*)[16])(__fp - 0x3c8))[0] != '\0') && (va0 = (*(undefined1 (*)[16])(__fp - 0x3c8)), (*(undefined1 (*)[16])(__fp - 0x388))[0] != '\0')) {
            va1 = &DAT_001470dd;
          }
          __snprintf_chk((*(char (*)[128])(__fp - 0x348)),0x80,2,0x80,((char *)(long)(__sec_rodata + 0x641) /* "%s%s%s" */),va0,va1,(*(undefined1 (*)[16])(__fp - 0x388)));
          goto LAB_001404b6;
        }
        if ((CONCAT26((*(undefined2 *)(__fp - 0x2c2)),CONCAT15((*(undefined1 *)(__fp - 0x2c3)),CONCAT14((*(undefined1 *)(__fp - 0x2c4)),(*(int *)(__fp - 0x2c8))))) ==
             0x4e5f595454455250) &&
           (CONCAT44((*(undefined4 *)(__fp - 0x2bf)),CONCAT13((*(char *)(__fp - 0x2c0)),CONCAT21((*(undefined2 *)(__fp - 0x2c2)),(*(undefined1 *)(__fp - 0x2c3))))) ==
            0x223d454d414e5f59)) break;
        if (((*(int *)(__fp - 0x2c8)) == 0x454d414e) && (CONCAT11((*(undefined1 *)(__fp - 0x2c3)),(*(undefined1 *)(__fp - 0x2c4))) == 0x223d)) {
          pcVar3 = strrchr((char *)&(*(int *)(__fp - 0x2c8)),0x22);
          if ((pcVar3 != (char *)0x0) && (&(*(undefined2 *)(__fp - 0x2c2)) < pcVar3)) {
            pcVar3 = pcVar3 + (1 - (long)&(*(undefined2 *)(__fp - 0x2c2)));
            if ((char *)0x40 < pcVar3) {
              pcVar3 = (char *)0x40;
            }
            pcVar4 = (char *)0x0;
            do {
              cVar1 = *(char *)((long)&(*(undefined2 *)(__fp - 0x2c2)) + (long)pcVar4);
              if (cVar1 == '\0') break;
              (*(undefined1 (*)[16])(__fp - 0x3c8))[(long)pcVar4] = cVar1;
              pcVar4 = pcVar4 + 1;
            } while (pcVar4 < pcVar3 + -1);
            (*(undefined1 (*)[16])(__fp - 0x3c8))[(long)pcVar4] = 0;
          }
        }
        else if ((CONCAT26((*(undefined2 *)(__fp - 0x2c2)),CONCAT15((*(undefined1 *)(__fp - 0x2c3)),CONCAT14((*(undefined1 *)(__fp - 0x2c4)),(*(int *)(__fp - 0x2c8))))) ==
                  0x3d4e4f4953524556) && ((*(char *)(__fp - 0x2c0)) == '\"')) {
          pcVar3 = strrchr((char *)&(*(int *)(__fp - 0x2c8)),0x22);
          if ((pcVar3 != (char *)0x0) && (&(*(undefined4 *)(__fp - 0x2bf)) < pcVar3)) {
            pcVar3 = pcVar3 + (1 - (long)&(*(undefined4 *)(__fp - 0x2bf)));
            if ((char *)0x40 < pcVar3) {
              pcVar3 = (char *)0x40;
            }
            pcVar4 = (char *)0x0;
            do {
              cVar1 = *(char *)((long)&(*(undefined4 *)(__fp - 0x2bf)) + (long)pcVar4);
              if (cVar1 == '\0') break;
              (*(undefined1 (*)[16])(__fp - 0x388))[(long)pcVar4] = cVar1;
              pcVar4 = pcVar4 + 1;
            } while (pcVar4 < pcVar3 + -1);
            (*(undefined1 (*)[16])(__fp - 0x388))[(long)pcVar4] = 0;
          }
        }
      }
      pcVar3 = strrchr((char *)&(*(int *)(__fp - 0x2c8)),0x22);
    } while ((pcVar3 == (char *)0x0) || (pcVar3 <= (*(char (*)[243])(__fp - 0x2bb))));
    pcVar3 = pcVar3 + (1 - (long)(*(char (*)[243])(__fp - 0x2bb)));
    if ((char *)0x80 < pcVar3) {
      pcVar3 = (char *)0x80;
    }
    pcVar4 = (char *)0x0;
    do {
      cVar1 = (*(char (*)[243])(__fp - 0x2bb))[(long)pcVar4];
      if (cVar1 == '\0') break;
      (*(char (*)[128])(__fp - 0x348))[(long)pcVar4] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < pcVar3 + -1);
    (*(char (*)[128])(__fp - 0x348))[(long)pcVar4] = '\0';
    fclose(__stream);
  }
LAB_001404b6:
  if (iVar2 == 0) {
    iVar2 = xSnprintf(&DAT_0015d680,0x153,((char *)(long)&s__s__s___s__00149dc6 /* "%s %s [%s]" */),&(*(utsname *)(__fp - 0x1c8)),(*(utsname *)(__fp - 0x1c8)).release,
                      (*(utsname *)(__fp - 0x1c8)).machine);
    uVar5 = (ulong)iVar2;
    pcVar3 = strcasestr(&DAT_0015d680,(*(char (*)[128])(__fp - 0x348)));
    if ((pcVar3 == (char *)0x0) && (uVar5 < 0x153)) {
      __snprintf_chk(&DAT_0015d680 + uVar5,0x153 - uVar5,2,0x153 - uVar5,((char *)(long)&s____s_00149dd1 /* " @ %s" */),(*(char (*)[128])(__fp - 0x348)));
    }
  }
  else {
    snprintf(&DAT_0015d680,0x153,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),(*(char (*)[128])(__fp - 0x348)));
  }
  CHAR____0015d7d3 = '\x01';
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

