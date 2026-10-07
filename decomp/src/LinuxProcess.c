#include "htop.h"

/* LinuxProcess_updateIOPriority @ 0x13b240 */

void LinuxProcess_updateIOPriority(long param_1)

{
  long lVar1;

  lVar1 = syscall(0xfc,1,(ulong)*(uint *)(param_1 + 0x10));
  *(int *)(param_1 + 0x1e8) = (int)lVar1;
  return;
}


/* LinuxProcess_rowSetIOPriority @ 0x13b270 */

bool LinuxProcess_rowSetIOPriority(long param_1,uint param_2)

{
  long lVar1;

  syscall(0xfb,1,(ulong)*(uint *)(param_1 + 0x10),param_2);
  lVar1 = syscall(0xfc,1,(ulong)*(uint *)(param_1 + 0x10));
  *(uint *)(param_1 + 0x1e8) = (uint)lVar1;
  return param_2 == (uint)lVar1;
}


/* LinuxProcess_isAutogroupEnabled @ 0x13b2c0 */

bool LinuxProcess_isAutogroupEnabled(void)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  int iVar1;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x10)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (iVar1 < 0) {
    piVar3 = __errno_location();
    lVar2 = (long)-*piVar3;
  }
  else {
    lVar2 = FUN_0013a450(iVar1,(*(char (*)[24])(__fp - 0x28)),0x10);
  }
  if ((*(long *)(__fp - 0x10)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return -1 < lVar2 && (*(char (*)[24])(__fp - 0x28))[0] == '1';
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcess_rowChangeAutogroupPriorityBy @ 0x13dd70 */

void LinuxProcess_rowChangeAutogroupPriorityBy(long param_1,int param_2)

{
  FUN_0013dc70((ulong)*(uint *)(param_1 + 0x10),param_2);
  return;
}


/* FUN_0013dd80 @ 0x13dd80 */

char FUN_0013dd80(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  char cVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long *plVar8;
  int *piVar9;
  byte bVar10;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  cVar5 = '\0';
  if (CHAR____0015c0d9 != '\0') goto LAB_0013ddb1;
  lVar2 = *(long *)(param_1 + 8);
  iVar6 = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (iVar6 < 0) {
    piVar9 = __errno_location();
    if (-1 < -*piVar9) goto LAB_0013de0b;
  }
  else {
    lVar7 = FUN_0013a450(iVar6,(*(char (*)[24])(__fp - 0x58)),0x10);
    if (-1 < lVar7) {
LAB_0013de0b:
      if ((*(char (*)[24])(__fp - 0x58))[0] == '1') {
        plVar8 = *(long **)(lVar2 + 0x20);
        if ((int)plVar8[3] < 1) {
          cVar5 = '\0';
        }
        else {
          lVar7 = 0;
          bVar10 = 1;
          cVar5 = '\0';
          do {
            lVar3 = *(long *)(*plVar8 + lVar7 * 8);
            cVar1 = *(char *)(lVar3 + 0x1d);
            if (cVar1 != '\0') {
              bVar4 = FUN_0013dc70((ulong)*(uint *)(lVar3 + 0x10),-1);
              bVar10 = bVar10 & bVar4;
              plVar8 = *(long **)(lVar2 + 0x20);
              cVar5 = cVar1;
            }
            lVar7 = lVar7 + 1;
          } while ((int)lVar7 < (int)plVar8[3]);
          if (((cVar5 != '\x01') && (0 < (int)plVar8[3])) &&
             (lVar2 = *(long *)(*plVar8 + (long)*(int *)(lVar2 + 0x28) * 8), lVar2 != 0)) {
            bVar4 = FUN_0013dc70((ulong)*(uint *)(lVar2 + 0x10),-1);
            bVar10 = bVar10 & bVar4;
          }
          if (bVar10 == 0) {
            beep();
          }
        }
        goto LAB_0013ddb1;
      }
    }
  }
  beep();
  cVar5 = '\0';
LAB_0013ddb1:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar5;
}


/* FUN_0013dee0 @ 0x13dee0 */

char FUN_0013dee0(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  char cVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long *plVar8;
  int *piVar9;
  byte bVar10;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  cVar5 = '\0';
  if (CHAR____0015c0d9 != '\0') goto LAB_0013df11;
  lVar2 = *(long *)(param_1 + 8);
  iVar6 = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (iVar6 < 0) {
    piVar9 = __errno_location();
    if (-1 < -*piVar9) goto LAB_0013df6b;
  }
  else {
    lVar7 = FUN_0013a450(iVar6,(*(char (*)[24])(__fp - 0x58)),0x10);
    if (-1 < lVar7) {
LAB_0013df6b:
      if ((*(char (*)[24])(__fp - 0x58))[0] == '1') {
        plVar8 = *(long **)(lVar2 + 0x20);
        if ((int)plVar8[3] < 1) {
          cVar5 = '\0';
        }
        else {
          lVar7 = 0;
          bVar10 = 1;
          cVar5 = '\0';
          do {
            lVar3 = *(long *)(*plVar8 + lVar7 * 8);
            cVar1 = *(char *)(lVar3 + 0x1d);
            if (cVar1 != '\0') {
              bVar4 = FUN_0013dc70((ulong)*(uint *)(lVar3 + 0x10),1);
              bVar10 = bVar10 & bVar4;
              plVar8 = *(long **)(lVar2 + 0x20);
              cVar5 = cVar1;
            }
            lVar7 = lVar7 + 1;
          } while ((int)lVar7 < (int)plVar8[3]);
          if (((cVar5 != '\x01') && (0 < (int)plVar8[3])) &&
             (lVar2 = *(long *)(*plVar8 + (long)*(int *)(lVar2 + 0x28) * 8), lVar2 != 0)) {
            bVar4 = FUN_0013dc70((ulong)*(uint *)(lVar2 + 0x10),1);
            bVar10 = bVar10 & bVar4;
          }
          if (bVar10 == 0) {
            beep();
          }
        }
        goto LAB_0013df11;
      }
    }
  }
  beep();
  cVar5 = '\0';
LAB_0013df11:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar5;
}


/* LinuxProcess_new @ 0x13e8b0 */

void LinuxProcess_new(undefined8 param_1)

{
  undefined8 *puVar1;

  puVar1 = calloc(1,0x348);
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[1] = param_1;
    *(undefined4 *)((long)puVar1 + 0x1d) = 0x1000100;
    *puVar1 = LinuxProcess_class;
    *(undefined1 *)((long)puVar1 + 0x21) = 0;
    *(undefined4 *)(puVar1 + 0x11) = 0xffffffff;
    *(undefined4 *)(puVar1 + 0xc) = 0xffffffff;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0013e910 @ 0x13e910 */

void FUN_0013e910(long param_1)

{
  undefined1 __frame[0x40e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x40a8;
  undefined8 *puVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  void *pvVar10;
  int *piVar11;
  undefined1 *puVar12;
  size_t __size;
  char *pcVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar3 = (undefined1 *)(*(undefined1 (*)[16368])(__fp - 0x4030));
  puVar12 = (undefined1 *)(*(undefined1 (*)[16368])(__fp - 0x4030)) + 0x1000;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar4 = open(((char *)(long)&s__proc_tty_drivers_00149bba /* "/proc/tty/drivers" */),0);
  if (iVar4 < 0) {
    piVar11 = __errno_location();
    lVar6 = (long)-*piVar11;
  }
  else {
    lVar6 = FUN_0013a450(iVar4,(*(char (*)[24])(__fp - 0x4048)),0x4000);
  }
  if (lVar6 < 0) {
LAB_0013eba5:
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  (*(void * *)(__fp - 0x4058)) = malloc(0xf0);
  if ((*(void * *)(__fp - 0x4058)) != (void *)0x0) {
    iVar4 = 0;
    __size = 0x18;
    if ((*(char (*)[24])(__fp - 0x4048))[0] != '\0') {
      (*(int *)(__fp - 0x4050)) = 10;
      lVar6 = 0;
      pcVar7 = (*(char (*)[24])(__fp - 0x4048));
      (*(int *)(__fp - 0x404c)) = 0;
      iVar4 = (*(int *)(__fp - 0x404c));
      do {
        (*(int *)(__fp - 0x404c)) = iVar4;
        pcVar7 = strchr(pcVar7,0x20);
        cVar2 = *pcVar7;
        while (cVar2 == ' ') {
          pcVar7 = pcVar7 + 1;
          cVar2 = *pcVar7;
        }
        pcVar8 = strchr(pcVar7,0x20);
        *pcVar8 = '\0';
        pcVar13 = pcVar8 + 1;
        puVar1 = (undefined8 *)((long)(*(void * *)(__fp - 0x4058)) + lVar6);
        pcVar7 = strdup(pcVar7);
        if (pcVar7 == (char *)0x0) goto LAB_0013ec2e;
        cVar2 = pcVar8[1];
        *puVar1 = pcVar7;
        while (cVar2 == ' ') {
          pcVar13 = pcVar13 + 1;
          cVar2 = *pcVar13;
        }
        pcVar7 = strchr(pcVar13,0x20);
        *pcVar7 = '\0';
        lVar9 = __isoc23_strtol(pcVar13,(char **)0x0,10);
        *(int *)(puVar1 + 1) = (int)lVar9;
        cVar2 = pcVar7[1];
        while (pcVar8 = pcVar7 + 1, pcVar13 = pcVar8, cVar2 == ' ') {
          cVar2 = pcVar7[2];
          pcVar7 = pcVar8;
        }
        while ((byte)(cVar2 - 0x30U) < 10) {
          cVar2 = pcVar13[1];
          pcVar13 = pcVar13 + 1;
        }
        *pcVar13 = '\0';
        pcVar13 = pcVar13 + 1;
        if (cVar2 == '-') {
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          *(int *)((long)puVar1 + 0xc) = (int)lVar9;
          pcVar7 = strchr(pcVar13,0x20);
          *pcVar7 = '\0';
          pcVar7 = pcVar7 + 1;
          lVar9 = __isoc23_strtol(pcVar13,(char **)0x0,10);
          uVar5 = (undefined4)lVar9;
        }
        else {
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          *(int *)((long)puVar1 + 0xc) = (int)lVar9;
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          uVar5 = (undefined4)lVar9;
          pcVar7 = pcVar13;
        }
        *(undefined4 *)(puVar1 + 2) = uVar5;
        pcVar13 = strchr(pcVar7,10);
        pcVar7 = pcVar13 + 1;
        iVar4 = (*(int *)(__fp - 0x404c)) + 1;
        pvVar10 = (*(void * *)(__fp - 0x4058));
        if (iVar4 == (*(int *)(__fp - 0x4050))) {
          (*(int *)(__fp - 0x4050)) = (*(int *)(__fp - 0x404c)) + 0xb;
          pvVar10 = realloc((*(void * *)(__fp - 0x4058)),(long)(*(int *)(__fp - 0x4050)) * 0x18);
          if (pvVar10 == (void *)0x0) goto LAB_0013ec22;
        }
        (*(void * *)(__fp - 0x4058)) = pvVar10;
        lVar6 = lVar6 + 0x18;
      } while (pcVar13[1] != '\0');
      __size = (long)((*(int *)(__fp - 0x404c)) + 2) * 0x18;
    }
    pvVar10 = realloc((*(void * *)(__fp - 0x4058)),__size);
    if (pvVar10 != (void *)0x0) {
      *(undefined8 *)((long)pvVar10 + (__size - 0x18)) = 0;
      qsort(pvVar10,(long)iVar4,0x18,FUN_00138920);
      *(void **)(param_1 + 0x58) = pvVar10;
      goto LAB_0013eba5;
    }
LAB_0013ec22:
    free((*(void * *)(__fp - 0x4058)));
  }
LAB_0013ec2e:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0013ec40 @ 0x13ec40 */

void FUN_0013ec40(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9
                 )

{
  undefined1 __frame[0x20e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x20a8;
  bool bVar1;
  int iVar2;
  int iVar3;
  FILE *__stream;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar7;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  char *pcVar8;
  void *__ptr;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = openat(param_2,((char *)(long)&s_cgroup_00149bcc /* "cgroup" */),0);
  if (iVar2 < 0) {
LAB_0013f1ca:
    if (*(void **)(param_1 + 0x2c8) != (void *)0x0) {
      free(*(void **)(param_1 + 0x2c8));
      *(undefined8 *)(param_1 + 0x2c8) = 0;
    }
    if (*(void **)(param_1 + 0x2d0) != (void *)0x0) {
      free(*(void **)(param_1 + 0x2d0));
      *(undefined8 *)(param_1 + 0x2d0) = 0;
    }
    __ptr = *(void **)(param_1 + 0x2d8);
    if (__ptr == (void *)0x0) goto LAB_0013eedb;
  }
  else {
    pcVar8 = ((char *)(long)&DAT_00147760 /* "r" */);
    __stream = fdopen(iVar2,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream == (FILE *)0x0) {
      close(iVar2);
      goto LAB_0013f1ca;
    }
    (*(char (*)[4112])(__fp - 0x2058))[0] = '\0';
    iVar2 = 0x1000;
    while ((iVar3 = feof(__stream), 0 < iVar2 && (iVar3 == 0))) {
      pcVar8 = (char *)0x1000;
      pcVar5 = fgets((*(char (*)[4104])(__fp - 0x1048)),0x1000,__stream);
      if (pcVar5 == (char *)0x0) break;
      param_r9 = (long)strchrnul((*(char (*)[4104])(__fp - 0x1048)),0x3a);
      if (*(char *)param_r9 != '\0') {
        pcVar8 = strchrnul((char *)(param_r9 + 1),0x3a);
        param_r9 = (long)(pcVar8 + (*pcVar8 != '\0'));
      }
      pcVar5 = strchrnul((char *)param_r9,10);
      pcVar8 = (char *)(long)iVar2;
      param_rcx = 0x1001;
      *pcVar5 = '\0';
      param_r8 = (long)(__sec_rodata + 0x626);
      iVar3 = __snprintf_chk((*(char (*)[4112])(__fp - 0x2058)),(ulong)pcVar8,2,0x1001,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),(void *)param_r9);
      iVar2 = iVar2 - iVar3;
    }
    fclose(__stream);
    pcVar5 = *(char **)(param_1 + 0x2c8);
    if (pcVar5 == (char *)0x0) {
      sVar4 = strlen((*(char (*)[4112])(__fp - 0x2058)));
      if (sVar4 < 0x100) {
        if (BYTE_0015d4d1 < sVar4) {
          BYTE_0015d4d1 = (byte)sVar4;
        }
      }
      else {
        BYTE_0015d4d1 = 0xff;
      }
      goto LAB_0013efd7;
    }
    pcVar8 = (*(char (*)[4112])(__fp - 0x2058));
    iVar2 = strcmp(pcVar5,(*(char (*)[4112])(__fp - 0x2058)));
    sVar4 = strlen((*(char (*)[4112])(__fp - 0x2058)));
    if (iVar2 == 0) {
      bVar1 = false;
      if (sVar4 < 0x100) {
        if (BYTE_0015d4d1 < sVar4) goto LAB_0013f0a7;
      }
      else {
        BYTE_0015d4d1 = 0xff;
        pcVar8 = (*(char (*)[4112])(__fp - 0x2058));
        iVar2 = strcmp(pcVar5,(*(char (*)[4112])(__fp - 0x2058)));
        if (iVar2 != 0) goto LAB_0013eff9;
      }
LAB_0013ef20:
      pcVar8 = *(char **)(param_1 + 0x2d0);
      if (pcVar8 == (char *)0x0) {
        pcVar8 = *(char **)(param_1 + 0x2c8);
      }
      sVar4 = strlen(pcVar8);
      if (sVar4 < 0x100) {
        if (BYTE_0015d4e1 < sVar4) {
          BYTE_0015d4e1 = (byte)sVar4;
        }
      }
      else {
        BYTE_0015d4e1 = 0xff;
      }
      if (*(char **)(param_1 + 0x2d8) == (char *)0x0) {
        if (BYTE_0015d4e2 < 3) {
          BYTE_0015d4e2 = 3;
        }
      }
      else {
        sVar4 = strlen(*(char **)(param_1 + 0x2d8));
        if (sVar4 < 0x100) {
          if (BYTE_0015d4e2 < sVar4) {
            BYTE_0015d4e2 = (byte)sVar4;
          }
        }
        else {
          BYTE_0015d4e2 = 0xff;
        }
      }
      goto LAB_0013eedb;
    }
    if (sVar4 < 0x100) {
      if (sVar4 <= BYTE_0015d4d1) goto LAB_0013efd7;
      bVar1 = true;
LAB_0013f0a7:
      BYTE_0015d4d1 = (byte)sVar4;
      pcVar8 = (*(char (*)[4112])(__fp - 0x2058));
      iVar2 = strcmp(pcVar5,(*(char (*)[4112])(__fp - 0x2058)));
      lVar7 = extraout_RDX_03;
      if (iVar2 != 0) goto LAB_0013eff9;
LAB_0013f020:
      if (!bVar1) goto LAB_0013ef20;
      pcVar5 = CGroup_filterName(*(char **)(param_1 + 0x2c8),(long)pcVar8,lVar7,param_rcx,param_r8,
                                 param_r9);
      if (pcVar5 != (char *)0x0) goto LAB_0013ede0;
LAB_0013f04b:
      sVar4 = strlen(*(char **)(param_1 + 0x2c8));
      if (sVar4 < 0x100) {
        if (BYTE_0015d4e1 < sVar4) {
          BYTE_0015d4e1 = (byte)sVar4;
        }
      }
      else {
        BYTE_0015d4e1 = 0xff;
      }
      free(*(void **)(param_1 + 0x2d0));
      *(undefined8 *)(param_1 + 0x2d0) = 0;
      lVar7 = extraout_RDX_02;
    }
    else {
      BYTE_0015d4d1 = 0xff;
      pcVar8 = (*(char (*)[4112])(__fp - 0x2058));
      iVar2 = strcmp(pcVar5,(*(char (*)[4112])(__fp - 0x2058)));
      if (iVar2 != 0) {
LAB_0013efd7:
        bVar1 = true;
LAB_0013eff9:
        free(pcVar5);
        pcVar5 = strdup((*(char (*)[4112])(__fp - 0x2058)));
        if (pcVar5 == (char *)0x0) goto LAB_0013f1be;
        *(char **)(param_1 + 0x2c8) = pcVar5;
        param_rcx = param_1;
        lVar7 = extraout_RDX_01;
        goto LAB_0013f020;
      }
      pcVar5 = CGroup_filterName(pcVar5,(long)pcVar8,extraout_RDX,param_rcx,param_r8,param_r9);
      if (pcVar5 == (char *)0x0) goto LAB_0013f04b;
LAB_0013ede0:
      sVar4 = strlen(pcVar5);
      if (sVar4 < 0x100) {
        if (BYTE_0015d4e1 < sVar4) {
          BYTE_0015d4e1 = (byte)sVar4;
        }
      }
      else {
        BYTE_0015d4e1 = 0xff;
      }
      pcVar6 = *(char **)(param_1 + 0x2d0);
      if ((pcVar6 == (char *)0x0) || (pcVar8 = pcVar5, iVar2 = strcmp(pcVar6,pcVar5), iVar2 != 0)) {
        free(pcVar6);
        pcVar6 = strdup(pcVar5);
        if (pcVar6 == (char *)0x0) goto LAB_0013f1be;
        *(char **)(param_1 + 0x2d0) = pcVar6;
        param_rcx = param_1;
      }
      free(pcVar5);
      lVar7 = extraout_RDX_00;
    }
    pcVar8 = CGroup_filterContainer
                       (*(char **)(param_1 + 0x2c8),(long)pcVar8,lVar7,param_rcx,param_r8,param_r9);
    if (pcVar8 != (char *)0x0) {
      sVar4 = strlen(pcVar8);
      if (sVar4 < 0x100) {
        if (BYTE_0015d4e2 < sVar4) {
          BYTE_0015d4e2 = (byte)sVar4;
        }
      }
      else {
        BYTE_0015d4e2 = 0xff;
      }
      pcVar5 = *(char **)(param_1 + 0x2d8);
      if ((pcVar5 == (char *)0x0) || (iVar2 = strcmp(pcVar5,pcVar8), iVar2 != 0)) {
        free(pcVar5);
        pcVar5 = strdup(pcVar8);
        if (pcVar5 == (char *)0x0) {
LAB_0013f1be:
                    /* WARNING: Subroutine does not return */
          fail();
        }
        *(char **)(param_1 + 0x2d8) = pcVar5;
      }
      free(pcVar8);
      goto LAB_0013eedb;
    }
    if (BYTE_0015d4e2 < 3) {
      BYTE_0015d4e2 = 3;
    }
    __ptr = *(void **)(param_1 + 0x2d8);
  }
  free(__ptr);
  *(undefined8 *)(param_1 + 0x2d8) = 0;
LAB_0013eedb:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_0013f230 @ 0x13f230 */

void FUN_0013f230(long param_1,int param_2)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  size_t sVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = openat(param_2,((char *)(long)&s_attr_current_00149bd3 /* "attr/current" */),0);
  if (-1 < iVar1) {
    __stream = fdopen(iVar1,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream == (FILE *)0x0) {
      close(iVar1);
    }
    else {
      pcVar2 = fgets((*(char (*)[4104])(__fp - 0x1038)),0x1001,__stream);
      fclose(__stream);
      if (pcVar2 != (char *)0x0) {
        pcVar2 = strchr((*(char (*)[4104])(__fp - 0x1038)),10);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        sVar3 = strlen((*(char (*)[4104])(__fp - 0x1038)));
        if (sVar3 < 0x100) {
          if (BYTE_0015d4db < sVar3) {
            BYTE_0015d4db = (byte)sVar3;
          }
        }
        else {
          BYTE_0015d4db = 0xff;
        }
        pcVar2 = *(char **)(param_1 + 0x328);
        if (pcVar2 != (char *)0x0) {
          iVar1 = strcmp(pcVar2,(*(char (*)[4104])(__fp - 0x1038)));
          if (iVar1 == 0) goto LAB_0013f32c;
        }
        free(pcVar2);
        pcVar2 = strdup((*(char (*)[4104])(__fp - 0x1038)));
        if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        *(char **)(param_1 + 0x328) = pcVar2;
        goto LAB_0013f32c;
      }
    }
  }
  free(*(void **)(param_1 + 0x328));
  *(undefined8 *)(param_1 + 0x328) = 0;
LAB_0013f32c:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0013f390 @ 0x13f390 */

void FUN_0013f390(long param_1,int param_2)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  int iVar1;
  ssize_t sVar2;
  char *pcVar3;
  long lVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  pcVar3 = (*(char (*)[4104])(__fp - 0x1038));
  for (lVar4 = 0x200; lVar4 != 0; lVar4 = lVar4 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3[4] = '\0';
    pcVar3[5] = '\0';
    pcVar3[6] = '\0';
    pcVar3[7] = '\0';
    pcVar3 = pcVar3 + 8;
  }
  *pcVar3 = '\0';
  sVar2 = readlinkat(param_2,((char *)(long)&DAT_00149be0 /* "cwd" */),(*(char (*)[4104])(__fp - 0x1038)),0x1000);
  if (sVar2 < 0) {
    free(*(void **)(param_1 + 0xa0));
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  else {
    pcVar3 = *(char **)(param_1 + 0xa0);
    (*(char (*)[4104])(__fp - 0x1038))[sVar2] = '\0';
    if (pcVar3 != (char *)0x0) {
      iVar1 = strcmp(pcVar3,(*(char (*)[4104])(__fp - 0x1038)));
      if (iVar1 == 0) goto LAB_0013f432;
    }
    free(pcVar3);
    pcVar3 = strdup((*(char (*)[4104])(__fp - 0x1038)));
    if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(char **)(param_1 + 0xa0) = pcVar3;
  }
LAB_0013f432:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

