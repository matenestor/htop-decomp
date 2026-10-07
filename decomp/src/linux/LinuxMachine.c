#include "htop.h"

/* scanCPUFrequencyFromCPUinfo @ 0x138a90 */

/* DWARF original prototype: void scanCPUFrequencyFromCPUinfo(LinuxMachine * this) */

void scanCPUFrequencyFromCPUinfo(LinuxMachine *this)

{
  undefined1 __frame[0x10f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x10b8;
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  char *pcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: int numCPUsWithFrequency@[???]
                       Unresolved local var: double totalFrequency@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_cpuinfo_001496f6 /* "/proc/cpuinfo" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    (*(int (*))(__fp - 0x1054)) = -1;
                    /* Unresolved local var: size_t sz@[???] */
    (*(double (*))(__fp - 0x1060)) = 0.0;
    (*(int (*))(__fp - 0x1064)) = 0;
LAB_00138b10:
    iVar2 = feof(__stream);
    if (iVar2 == 0) {
      while( true ) {
        pcVar3 = fgets((*(char (*) [4096])(__fp - 0x1048)),0x1000,__stream);
        if (pcVar3 == (char *)0x0) goto LAB_00138bc0;
        iVar2 = __isoc23_sscanf((*(char (*) [4096])(__fp - 0x1048)),((char *)(long)&s_processor____d_00149704 /* "processor : %d" */),&(*(int (*))(__fp - 0x1054)));
        if (iVar2 == 1) goto LAB_00138b10;
        iVar2 = __isoc23_sscanf((*(char (*) [4096])(__fp - 0x1048)),((char *)(long)&s_cpu_MHz____lf_00149713 /* "cpu MHz : %lf" */),&(*(double (*))(__fp - 0x1050)));
        if ((iVar2 == 1) ||
           (iVar2 = __isoc23_sscanf((*(char (*) [4096])(__fp - 0x1048)),((char *)(long)&s_clock____lfMHz_00149721 /* "clock : %lfMHz" */),&(*(double (*))(__fp - 0x1050))), iVar2 == 1)) break;
        if ((*(char (*) [4096])(__fp - 0x1048))[0] != '\n') goto LAB_00138b10;
        (*(int (*))(__fp - 0x1054)) = -1;
        iVar2 = feof(__stream);
        if (iVar2 != 0) goto LAB_00138bc0;
      }
                    /* Unresolved local var: CPUData * cpuData@[???] */
      if ((-1 < (*(int (*))(__fp - 0x1054))) &&
         ((uint)(*(int (*))(__fp - 0x1054)) <= (uint)((this->super).existingCPUs + -1))) {
        if (this->cpuData[(long)(*(int (*))(__fp - 0x1054)) + 1].frequency < 0.0) {
          this->cpuData[(long)(*(int (*))(__fp - 0x1054)) + 1].frequency = (*(double (*))(__fp - 0x1050));
        }
        (*(double (*))(__fp - 0x1060)) = (*(double (*))(__fp - 0x1050)) + (*(double (*))(__fp - 0x1060));
        (*(int (*))(__fp - 0x1064)) = (*(int (*))(__fp - 0x1064)) + 1;
      }
      goto LAB_00138b10;
    }
LAB_00138bc0:
    fclose(__stream);
    if (0 < (*(int (*))(__fp - 0x1064))) {
      this->cpuData->frequency = (*(double (*))(__fp - 0x1060)) / (double)(*(int (*))(__fp - 0x1064));
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Machine_delete @ 0x13b1c0 */

void Machine_delete(LinuxMachine_ *super)

{
  Table_4 *pTVar1;
  long in_RCX;
  long in_RDX;
  long in_RSI;
  long in_R8;
  long in_R9;

  pTVar1 = (super->super).processTable;
  (*(code *)(((pTVar1->super).klass)->delete))(&pTVar1->super,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
  free((super->super).tables);
  free(super->cpuData);
  free(super);
  return;
}


/* Machine_isCPUonline @ 0x13b210 */

_Bool Machine_isCPUonline(LinuxMachine_ *super,uint id)

{
  return super->cpuData[id + 1].online;
}


/* LinuxMachine_updateCPUcount @ 0x141370 */

/* DWARF original prototype: void LinuxMachine_updateCPUcount(LinuxMachine * this) */

void LinuxMachine_updateCPUcount(LinuxMachine *this)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  _Bool _Var2;
  int iVar3;
  uint uVar4;
  int fd;
  DIR_2 *__dirp;
  dirent *pdVar5;
  ulong uVar6;
  ulong uVar8;
  CPUData *pCVar9;
  long lVar10;
  int *piVar11;
  size_t prevmemb;
  uint uVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong uVar7;

                    /* Unresolved local var: uint existing@[???]
                       Unresolved local var: uint active@[???]
                       Unresolved local var: Machine * super@[???]
                       Unresolved local var: DIR * dir@[???]
                       Unresolved local var: uint currExisting@[???]
                       Unresolved local var: dirent * entry@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (this->cpuData == (CPUData *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    pCVar9 = calloc(2,0xd8);
    if (pCVar9 == (CPUData *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->cpuData = pCVar9;
    pCVar9->online = true;
    pCVar9[1].online = true;
    (this->super).activeCPUs = 1;
    (this->super).existingCPUs = 1;
  }
  __dirp = opendir(((char *)(long)&s__sys_devices_system_cpu_00149e4d /* "/sys/devices/system/cpu" */));
  if (__dirp != (DIR_2 *)0x0) {
    (*(uint (*))(__fp - 0x6c)) = (this->super).existingCPUs;
    (*(uint (*))(__fp - 0x70)) = 0;
    uVar7 = 0;
                    /* Unresolved local var: ulong id@[???]
                       Unresolved local var: int cpuDirFd@[???]
                       Unresolved local var: uint max@[???]
                       Unresolved local var: ssize_t res@[???] */
LAB_001413d8:
    uVar4 = (uint)uVar7;
    pdVar5 = readdir(__dirp);
    if (pdVar5 != (dirent *)0x0) {
      while (((((pdVar5->d_type & 0xfb) == 0 && (pdVar5->d_name[0] == 'c')) &&
              (pdVar5->d_name[1] == 'p')) && (pdVar5->d_name[2] == 'u'))) {
        uVar6 = __isoc23_strtoul(pdVar5->d_name + 3,&(*(char *(*))(__fp - 0x50)),10);
        if (((uVar6 == 0xffffffffffffffff) || (pdVar5->d_name + 3 == (*(char *(*))(__fp - 0x50)))) || (*(*(char *(*))(__fp - 0x50)) != '\0'))
        break;
        iVar3 = dirfd(__dirp);
        iVar3 = openat(iVar3,pdVar5->d_name,0x230000);
        if (iVar3 < 0) break;
        uVar4 = (int)uVar7 + 1;
        uVar7 = (ulong)uVar4;
        uVar6 = uVar6 + 1;
        uVar8 = uVar7;
        if (uVar7 < uVar6) {
          uVar8 = uVar6;
        }
        uVar12 = (uint)uVar8;
        if ((*(uint (*))(__fp - 0x6c)) < uVar12) {
          prevmemb = (size_t)((*(uint (*))(__fp - 0x6c)) + 1);
          if ((*(uint (*))(__fp - 0x6c)) == 0) {
            prevmemb = 0;
          }
          pCVar9 = xReallocArrayZero(this->cpuData,prevmemb,(ulong)(uVar12 + 1),0xd8);
          this->cpuData = pCVar9;
          pCVar9->online = true;
          (*(uint (*))(__fp - 0x6c)) = uVar12;
        }
                    /* Unresolved local var: int fd@[???] */
        fd = openat(iVar3,((char *)(long)&s_online_00149919 /* "online" */),0);
        if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
          piVar11 = __errno_location();
          lVar10 = (long)-*piVar11;
        }
        else {
          lVar10 = readfd_internal(fd,(*(char (*) [8])(__fp - 0x48)),8);
        }
        if ((lVar10 < 1) || (_Var2 = false, (*(char (*) [8])(__fp - 0x48))[0] != '0')) {
          (*(uint (*))(__fp - 0x70)) = (*(uint (*))(__fp - 0x70)) + 1;
          _Var2 = true;
        }
        this->cpuData[uVar6].online = _Var2;
        close(iVar3);
        pdVar5 = readdir(__dirp);
        if (pdVar5 == (dirent *)0x0) goto LAB_00141528;
      }
      goto LAB_001413d8;
    }
LAB_00141528:
    closedir(__dirp);
    if (uVar4 != 0) {
      uVar4 = (this->super).existingCPUs;
      if ((uVar4 != 0) && (((this->super).activeCPUs < (*(uint (*))(__fp - 0x70)) || (uVar4 < (*(uint (*))(__fp - 0x6c)))))) {
        LibSensors_reload();
      }
      (this->super).activeCPUs = (*(uint (*))(__fp - 0x70));
      (this->super).existingCPUs = (*(uint (*))(__fp - 0x6c));
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* LinuxMachine_scanCPUTime @ 0x1415f0 */

/* DWARF original prototype: void LinuxMachine_scanCPUTime(LinuxMachine * this) */

void LinuxMachine_scanCPUTime(LinuxMachine *this)

{
  undefined1 __frame[0x1148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1108;
  uint uVar1;
  uint uVar2;
  long lVar3;
  CPUData *pCVar4;
  FILE_2 *__stream;
  char *pcVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  undefined8 *puVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar20;

                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: uint lastAdjCpuId@[???] */
  bVar20 = 0;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  LinuxMachine_updateCPUcount(this);
  __stream = fopen(((char *)(long)(__sec_rodata + 0x2e71) /* "/proc/stat" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_open__proc_stat_00149e65 /* "Cannot open /proc/stat" */));
  }
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: char * ok@[???]
                       Unresolved local var: uint adjCpuId@[???]
                       Unresolved local var: ulonglong idlealltime@[???]
                       Unresolved local var: ulonglong systemalltime@[???]
                       Unresolved local var: ulonglong virtalltime@[???]
                       Unresolved local var: ulonglong totaltime@[???]
                       Unresolved local var: CPUData * cpuData@[???] */
  uVar11 = 0;
  (*(uint (*))(__fp - 0x10b4)) = 0;
  do {
                    /* Unresolved local var: size_t sz@[???] */
    (*(ulonglong (*))(__fp - 0x1070)) = 0;
    (*(ulonglong (*))(__fp - 0x1078)) = 0;
    (*(ulonglong (*))(__fp - 0x1080)) = 0;
    (*(ulonglong (*))(__fp - 0x1088)) = 0;
    (*(ulonglong (*))(__fp - 0x1090)) = 0;
    (*(ulonglong (*))(__fp - 0x1098)) = 0;
    pcVar5 = fgets((*(char (*) [4097])(__fp - 0x1048)),0x1001,__stream);
    if (((pcVar5 == (char *)0x0) || ((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 0)) != 0x7063)) || ((*(char (*) [4097])(__fp - 0x1048))[2] != 'u')) {
LAB_001416e7:
      uVar6 = this->cpuData->totalPeriod;
      goto code_r0x00141a59;
    }
    if (uVar11 == 0) {
      __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1048)),
                      ((char *)(long)&s_cpu__16llu__16llu__16llu__16llu___0014cbb0 /* "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu" */),
                      &(*(ulonglong (*))(__fp - 0x1050)),&(*(ulonglong (*))(__fp - 0x1058)),&(*(ulonglong (*))(__fp - 0x1060)),&(*(ulonglong (*))(__fp - 0x1068)),&(*(ulonglong (*))(__fp - 0x1070)),&(*(ulonglong (*))(__fp - 0x1078)),&(*(ulonglong (*))(__fp - 0x1080)),&(*(ulonglong (*))(__fp - 0x1088)),&(*(ulonglong (*))(__fp - 0x1090)),
                      &(*(ulonglong (*))(__fp - 0x1098)));
                    /* Unresolved local var: uint j@[???] */
      uVar18 = (this->super).existingCPUs;
      lVar9 = 0;
      (*(uint (*))(__fp - 0x10b4)) = 0;
      uVar1 = (*(uint (*))(__fp - 0x10b4));
    }
    else {
      __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1048)),
                      ((char *)(long)&s_cpu_4u__16llu__16llu__16llu__16l_0014cc00 /* "cpu%4u %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu" */)
                      ,&(*(uint (*))(__fp - 0x109c)),&(*(ulonglong (*))(__fp - 0x1050)),&(*(ulonglong (*))(__fp - 0x1058)),&(*(ulonglong (*))(__fp - 0x1060)),&(*(ulonglong (*))(__fp - 0x1068)),&(*(ulonglong (*))(__fp - 0x1070)),&(*(ulonglong (*))(__fp - 0x1078)),&(*(ulonglong (*))(__fp - 0x1080)),&(*(ulonglong (*))(__fp - 0x1088))
                      ,&(*(ulonglong (*))(__fp - 0x1090)),&(*(ulonglong (*))(__fp - 0x1098)));
      uVar18 = (this->super).existingCPUs;
      uVar1 = (*(uint (*))(__fp - 0x109c)) + 1;
      if (uVar18 < uVar1) goto LAB_001416e7;
      uVar2 = (*(uint (*))(__fp - 0x10b4)) + 1;
      lVar9 = (ulong)uVar1 * 0xd8;
      if (uVar2 < uVar1) {
        lVar13 = (ulong)uVar2 * 0xd8;
        do {
          puVar15 = (undefined8 *)((long)&this->cpuData->totalTime + lVar13);
          lVar13 = lVar13 + 0xd8;
          *puVar15 = 0;
          puVar15[0x1a] = 0;
          uVar6 = (ulong)(((int)puVar15 -
                          (int)(undefined8 *)((ulong)(puVar15 + 1) & 0xfffffffffffffff8)) + 0xd8U >>
                         3);
          puVar15 = (undefined8 *)((ulong)(puVar15 + 1) & 0xfffffffffffffff8);
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar15 = 0;
            puVar15 = puVar15 + (ulong)bVar20 * -2 + 1;
          }
        } while (((ulong)uVar2 + 1 + (ulong)(((*(uint (*))(__fp - 0x109c)) - 1) - (*(uint (*))(__fp - 0x10b4)))) * 0xd8 != lVar13);
        uVar18 = (this->super).existingCPUs;
      }
    }
    (*(uint (*))(__fp - 0x10b4)) = uVar1;
    uVar19 = (*(ulonglong (*))(__fp - 0x1068)) + (*(ulonglong (*))(__fp - 0x1070));
    uVar16 = (*(ulonglong (*))(__fp - 0x1058)) - (*(ulonglong (*))(__fp - 0x1098));
    uVar17 = (*(ulonglong (*))(__fp - 0x1050)) - (*(ulonglong (*))(__fp - 0x1090));
    uVar12 = (*(ulonglong (*))(__fp - 0x1090)) + (*(ulonglong (*))(__fp - 0x1098));
    pCVar4 = this->cpuData;
    puVar7 = (ulong *)((long)&pCVar4->totalTime + lVar9);
    uVar10 = 0;
    uVar14 = (*(ulonglong (*))(__fp - 0x1060)) + (*(ulonglong (*))(__fp - 0x1078)) + (*(ulonglong (*))(__fp - 0x1080));
    uVar8 = uVar17 + uVar16 + (*(ulonglong (*))(__fp - 0x1088)) + uVar19 + uVar12 + uVar14;
    uVar6 = uVar17 - puVar7[1];
    if (uVar17 <= puVar7[1]) {
      uVar6 = uVar10;
    }
    puVar7[0xd] = uVar6;
    uVar6 = uVar16 - puVar7[6];
    if (uVar16 <= puVar7[6]) {
      uVar6 = uVar10;
    }
    puVar7[0x12] = uVar6;
    uVar6 = (*(ulonglong (*))(__fp - 0x1060)) - puVar7[2];
    if ((*(ulonglong (*))(__fp - 0x1060)) <= puVar7[2]) {
      uVar6 = uVar10;
    }
    puVar7[0xe] = uVar6;
    uVar6 = uVar14 - puVar7[3];
    if (uVar14 <= puVar7[3]) {
      uVar6 = uVar10;
    }
    puVar7[0xf] = uVar6;
    uVar6 = uVar19 - puVar7[4];
    if (uVar19 <= puVar7[4]) {
      uVar6 = uVar10;
    }
    puVar7[0x10] = uVar6;
    uVar6 = (*(ulonglong (*))(__fp - 0x1068)) - puVar7[5];
    if ((*(ulonglong (*))(__fp - 0x1068)) <= puVar7[5]) {
      uVar6 = uVar10;
    }
    puVar7[0x11] = uVar6;
    uVar6 = (*(ulonglong (*))(__fp - 0x1070)) - puVar7[7];
    if ((*(ulonglong (*))(__fp - 0x1070)) <= puVar7[7]) {
      uVar6 = uVar10;
    }
    puVar7[0x13] = uVar6;
    puVar7[1] = uVar17;
    puVar7[6] = uVar16;
    puVar7[3] = uVar14;
    uVar6 = (*(ulonglong (*))(__fp - 0x1078)) - puVar7[8];
    if ((*(ulonglong (*))(__fp - 0x1078)) <= puVar7[8]) {
      uVar6 = uVar10;
    }
    puVar7[4] = uVar19;
    puVar7[0x14] = uVar6;
    uVar6 = (*(ulonglong (*))(__fp - 0x1080)) - puVar7[9];
    if ((*(ulonglong (*))(__fp - 0x1080)) <= puVar7[9]) {
      uVar6 = uVar10;
    }
    puVar7[0x15] = uVar6;
    uVar6 = (*(ulonglong (*))(__fp - 0x1088)) - puVar7[10];
    if ((*(ulonglong (*))(__fp - 0x1088)) <= puVar7[10]) {
      uVar6 = uVar10;
    }
    puVar7[0x16] = uVar6;
    uVar6 = uVar12 - puVar7[0xb];
    if (uVar12 <= puVar7[0xb]) {
      uVar6 = uVar10;
    }
    puVar7[0x17] = uVar6;
    uVar6 = uVar8 - *puVar7;
    if (uVar8 <= *puVar7) {
      uVar6 = uVar10;
    }
    uVar11 = uVar11 + 1;
    puVar7[2] = (*(ulonglong (*))(__fp - 0x1060));
    puVar7[0xc] = uVar6;
    puVar7[5] = (*(ulonglong (*))(__fp - 0x1068));
    puVar7[7] = (*(ulonglong (*))(__fp - 0x1070));
    puVar7[8] = (*(ulonglong (*))(__fp - 0x1078));
    puVar7[9] = (*(ulonglong (*))(__fp - 0x1080));
    puVar7[10] = (*(ulonglong (*))(__fp - 0x1088));
    puVar7[0xb] = uVar12;
    *puVar7 = uVar8;
  } while (uVar11 <= uVar18);
  uVar6 = pCVar4->totalPeriod;
code_r0x00141a59:
  this->period = (double)uVar6 / (double)(this->super).activeCPUs;
  do {
                    /* Unresolved local var: size_t sz@[???] */
    pcVar5 = fgets((*(char (*) [4097])(__fp - 0x1048)),0x1001,__stream);
    if (pcVar5 == (char *)0x0) goto LAB_0014177e;
  } while ((CONCAT35((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 5)),CONCAT23((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 3)),CONCAT12((*(char (*) [4097])(__fp - 0x1048))[2],(*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 0))))) !=
            0x75725f73636f7270) || (CONCAT53((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 8)),(*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 5))) != 0x676e696e6e75725f));
  uVar6 = __isoc23_strtoul((*(char (*) [4097])(__fp - 0x1048)) + 0xd,(char **)0x0,10);
  this->runningTasks = (uint)uVar6;
LAB_0014177e:
  fclose(__stream);
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Machine_scan @ 0x141bc0 */

void Machine_scan(LinuxMachine_ *super)

{
  undefined1 __frame[0x218] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1d8;
  ulonglong *puVar1;
  uint uVar2;
  long lVar3;
  Settings__5 *pSVar4;
  int iVar5;
  int wVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  FILE_2 *pFVar10;
  char *pcVar11;
  ulong uVar12;
  DIR_2 *__dirp;
  dirent *pdVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  FILE_2 *__stream;
  int *piVar17;
  CPUData *pCVar18;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: memory_t availableMem@[???]
                       Unresolved local var: memory_t freeMem@[???]
                       Unresolved local var: memory_t totalMem@[???]
                       Unresolved local var: memory_t buffersMem@[???]
                       Unresolved local var: memory_t cachedMem@[???]
                       Unresolved local var: memory_t sharedMem@[???]
                       Unresolved local var: memory_t swapTotalMem@[???]
                       Unresolved local var: memory_t swapCacheMem@[???]
                       Unresolved local var: memory_t swapFreeMem@[???]
                       Unresolved local var: memory_t sreclaimableMem@[???]
                       Unresolved local var: memory_t zswapCompMem@[???]
                       Unresolved local var: memory_t zswapOrigMem@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: memory_t usedDiff@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  pFVar10 = fopen(((char *)(long)(__sec_rodata + 0x2e96) /* "/proc/meminfo" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (pFVar10 == (FILE_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_open__proc_meminfo_00149e8a /* "Cannot open /proc/meminfo" */));
  }
  (*(memory_t (*))(__fp - 0x168)) = 0;
  (*(memory_t (*))(__fp - 0x158)) = 0;
  (*(memory_t (*))(__fp - 0x190)) = 0;
  (*(memory_t (*))(__fp - 0x170)) = 0;
  (*(memory_t (*))(__fp - 0x188)) = 0;
  (*(memory_t (*))(__fp - 0x180)) = 0;
  (*(memory_t (*))(__fp - 0x178)) = 0;
  (*(memory_t (*))(__fp - 0x150)) = 0;
  (*(memory_t (*))(__fp - 0x148)) = 0;
  (*(ulong (*))(__fp - 0x160)) = 0;
  (*(ulong (*))(__fp - 0x140)) = 0;
  uVar14 = 0;
                    /* Unresolved local var: size_t sz@[???] */
  while (pcVar11 = fgets((*(char (*) [128])(__fp - 0xc8)),0x80,pFVar10), pcVar11 != (char *)0x0) {
    switch((*(char (*) [128])(__fp - 0xc8))[0]) {
    case 'B':
      if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                    CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                             CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                      CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                               CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                        CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                 CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))))))
           == 0x3a73726566667542) &&
         (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 8,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)) {
        (*(memory_t (*))(__fp - 0x148)) = (*(memory_t (*))(__fp - 0x118));
      }
      break;
    case 'C':
      if (((CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))) == 0x68636143) &&
          (CONCAT13((*(char (*) [128])(__fp - 0xc8))[6],CONCAT12((*(char (*) [128])(__fp - 0xc8))[5],CONCAT11((*(char (*) [128])(__fp - 0xc8))[4],(*(char (*) [128])(__fp - 0xc8))[3]))) == 0x3a646568)) &&
         (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 7,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)) {
        (*(memory_t (*))(__fp - 0x150)) = (*(memory_t (*))(__fp - 0x118));
      }
      break;
    case 'M':
      if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                    CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                             CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                      CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                               CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                        CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                 CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))))))
           == 0x6c696176416d654d) &&
         (CONCAT26((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 11)),
                   CONCAT15((*(char (*) [128])(__fp - 0xc8))[10],
                            CONCAT14((*(char (*) [128])(__fp - 0xc8))[9],
                                     CONCAT13((*(char (*) [128])(__fp - 0xc8))[8],
                                              CONCAT12((*(char (*) [128])(__fp - 0xc8))[7],CONCAT11((*(char (*) [128])(__fp - 0xc8))[6],(*(char (*) [128])(__fp - 0xc8))[5]))))))
          == 0x3a656c62616c6961)) {
        iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 0xd,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118)));
        if (iVar5 == 1) {
          (*(ulong (*))(__fp - 0x140)) = (*(memory_t (*))(__fp - 0x118));
        }
      }
      else if (CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                        CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                 CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                          CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                   CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                            CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                     CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))
                                                  )))) == 0x3a656572466d654d) {
        iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 8,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118)));
        if (iVar5 == 1) {
          (*(ulong (*))(__fp - 0x160)) = (*(memory_t (*))(__fp - 0x118));
        }
      }
      else if (((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                          CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                   CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                            CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                     CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                              CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                       CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])
                                                                      )))))) == 0x6c61746f546d654d)
               && ((*(char (*) [128])(__fp - 0xc8))[8] == ':')) &&
              (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 9,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)) {
        uVar14 = (*(memory_t (*))(__fp - 0x118));
      }
      break;
    case 'S':
      if ((*(char (*) [128])(__fp - 0xc8))[1] == 'h') {
        if (((CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],CONCAT11(0x68,(*(char (*) [128])(__fp - 0xc8))[0]))) == 0x656d6853) &&
            (CONCAT11((*(char (*) [128])(__fp - 0xc8))[5],(*(char (*) [128])(__fp - 0xc8))[4]) == 0x3a6d)) &&
           (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 6,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)) {
          (*(memory_t (*))(__fp - 0x178)) = (*(memory_t (*))(__fp - 0x118));
        }
      }
      else if ((*(char (*) [128])(__fp - 0xc8))[1] == 'w') {
        if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                      CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                               CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                        CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                 CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                          CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                   CONCAT11(0x77,(*(char (*) [128])(__fp - 0xc8))[0]))))))) ==
             0x61746f5470617753) && (CONCAT11((*(char (*) [128])(__fp - 0xc8))[9],(*(char (*) [128])(__fp - 0xc8))[8]) == 0x3a6c)) {
          iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 10,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118)));
          if (iVar5 == 1) {
            (*(memory_t (*))(__fp - 0x180)) = (*(memory_t (*))(__fp - 0x118));
          }
        }
        else if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                           CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                    CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                             CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                      CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                               CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                        CONCAT11(0x77,(*(char (*) [128])(__fp - 0xc8))[0])))))
                                   )) == 0x6863614370617753) &&
                (CONCAT13((*(char (*) [128])(__fp - 0xc8))[10],CONCAT12((*(char (*) [128])(__fp - 0xc8))[9],CONCAT11((*(char (*) [128])(__fp - 0xc8))[8],(*(char (*) [128])(__fp - 0xc8))[7]))) ==
                 0x3a646568)) {
          iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 0xb,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118)));
          if (iVar5 == 1) {
            (*(memory_t (*))(__fp - 0x188)) = (*(memory_t (*))(__fp - 0x118));
          }
        }
        else if (((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                            CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                     CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                              CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                       CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                                CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                         CONCAT11(0x77,(*(char (*) [128])(__fp - 0xc8))[0]))))
                                             ))) == 0x6565724670617753) && ((*(char (*) [128])(__fp - 0xc8))[8] == ':')) &&
                (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 9,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)) {
          (*(memory_t (*))(__fp - 0x170)) = (*(memory_t (*))(__fp - 0x118));
        }
      }
      else if (((((*(char (*) [128])(__fp - 0xc8))[1] == 'R') &&
                (CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                          CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                   CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                            CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                     CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                              CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                       CONCAT11(0x52,(*(char (*) [128])(__fp - 0xc8))[0]))))))
                         ) == 0x6d69616c63655253)) &&
               (CONCAT26((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 11)),
                         CONCAT15((*(char (*) [128])(__fp - 0xc8))[10],
                                  CONCAT14((*(char (*) [128])(__fp - 0xc8))[9],
                                           CONCAT13((*(char (*) [128])(__fp - 0xc8))[8],
                                                    CONCAT12((*(char (*) [128])(__fp - 0xc8))[7],CONCAT11((*(char (*) [128])(__fp - 0xc8))[6],(*(char (*) [128])(__fp - 0xc8))[5])
                                                            ))))) == 0x3a656c62616d6961)) &&
              (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 0xd,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)) {
        (*(memory_t (*))(__fp - 0x190)) = (*(memory_t (*))(__fp - 0x118));
      }
      break;
    case 'Z':
      if ((CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))) == 0x6177735a) &&
         (CONCAT11((*(char (*) [128])(__fp - 0xc8))[5],(*(char (*) [128])(__fp - 0xc8))[4]) == 0x3a70)) {
        iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 6,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118)));
        if (iVar5 == 1) {
          (*(memory_t (*))(__fp - 0x158)) = (*(memory_t (*))(__fp - 0x118));
        }
      }
      else if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                         CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                  CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                           CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                    CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                             CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                      CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))
                                                            ))))) == 0x646570706177735a) &&
              (((*(char (*) [128])(__fp - 0xc8))[8] == ':' &&
               (iVar5 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 9,((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(memory_t (*))(__fp - 0x118))), iVar5 == 1)))) {
        (*(memory_t (*))(__fp - 0x168)) = (*(memory_t (*))(__fp - 0x118));
      }
    }
  }
  fclose(pFVar10);
  (super->super).totalMem = uVar14;
                    /* Unresolved local var: DIR * dir@[???]
                       Unresolved local var: dirent * entry@[???]
                       Unresolved local var: uint i@[???] */
  *(undefined4 *)super->usedHugePageMem = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 4) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 1) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xc) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 2) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x14) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 3) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x1c) = 0xffffffff;
  (super->super).sharedMem = (*(memory_t (*))(__fp - 0x178));
  (super->super).buffersMem = (*(memory_t (*))(__fp - 0x148));
  (super->super).cachedMem = ((*(memory_t (*))(__fp - 0x150)) + (*(memory_t (*))(__fp - 0x190))) - (*(memory_t (*))(__fp - 0x178));
  *(undefined4 *)(super->usedHugePageMem + 4) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x24) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 5) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x2c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 6) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x34) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 7) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x3c) = 0xffffffff;
  uVar12 = (*(ulong (*))(__fp - 0x160)) + (*(memory_t (*))(__fp - 0x148)) + (*(memory_t (*))(__fp - 0x150)) + (*(memory_t (*))(__fp - 0x190));
  *(undefined4 *)(super->usedHugePageMem + 8) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x44) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 9) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x4c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 10) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x54) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xb) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x5c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xc) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 100) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xd) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x6c) = 0xffffffff;
  if (uVar14 < uVar12) {
    uVar12 = (*(ulong (*))(__fp - 0x160));
  }
  *(undefined4 *)(super->usedHugePageMem + 0xe) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x74) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xf) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x7c) = 0xffffffff;
  (super->super).cachedSwap = (*(memory_t (*))(__fp - 0x188));
  (super->super).usedMem = uVar14 - uVar12;
  *(undefined4 *)(super->usedHugePageMem + 0x10) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x84) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x11) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x8c) = 0xffffffff;
  super->totalHugePageMem = 0;
  if ((*(ulong (*))(__fp - 0x140)) <= uVar14) {
    uVar14 = (*(ulong (*))(__fp - 0x140));
  }
  if ((*(ulong (*))(__fp - 0x140)) == 0) {
    uVar14 = (*(ulong (*))(__fp - 0x160));
  }
  (super->super).totalSwap = (*(memory_t (*))(__fp - 0x180));
  (super->super).usedSwap = (*(memory_t (*))(__fp - 0x180)) - ((*(memory_t (*))(__fp - 0x170)) + (*(memory_t (*))(__fp - 0x188)));
  (super->super).availableMem = uVar14;
  (super->zswap).usedZswapComp = (*(memory_t (*))(__fp - 0x158));
  (super->zswap).usedZswapOrig = (*(memory_t (*))(__fp - 0x168));
  *(undefined4 *)(super->usedHugePageMem + 0x12) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x94) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x13) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x9c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x14) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xa4) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x15) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xac) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x16) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xb4) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x17) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xbc) = 0xffffffff;
  __dirp = opendir(((char *)(long)&s__sys_kernel_mm_hugepages_00149f1d /* "/sys/kernel/mm/hugepages" */));
  if (__dirp != (DIR_2 *)0x0) {
LAB_00142030:
    pdVar13 = readdir(__dirp);
    if (pdVar13 != (dirent *)0x0) {
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: ulong hugePageSize@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: memory_t total@[???]
                       Unresolved local var: memory_t free@[???]
                       Unresolved local var: int shift@[???] */
      while ((pdVar13->d_type & 0xfb) == 0) {
        pcVar11 = pdVar13->d_name;
        iVar5 = strncmp(pcVar11,((char *)(long)&s_hugepages__00149f36 /* "hugepages-" */),10);
        if (((iVar5 != 0) ||
            (uVar14 = __isoc23_strtoul(pdVar13->d_name + 10,(char **)&(*(memory_t (*))(__fp - 0x118)),10), (*(memory_t (*))(__fp - 0x118)) == 0)) ||
           (*(char *)(*(memory_t (*))(__fp - 0x118)) != 'k')) break;
        xSnprintf((*(char (*) [128])(__fp - 0xc8)),0x80,((char *)(long)&s__sys_kernel_mm_hugepages__s_nr_h_0014cc50 /* "/sys/kernel/mm/hugepages/%s/nr_hugepages" */),pcVar11);
                    /* Unresolved local var: int fd@[???] */
        wVar6 = open((*(char (*) [128])(__fp - 0xc8)),0);
        if (wVar6 < 0) {
                    /* Unresolved local var: int fd@[???] */
          piVar17 = __errno_location();
          lVar15 = (long)-*piVar17;
        }
        else {
          lVar15 = readfd_internal(wVar6,(*(char (*) [64])(__fp - 0x108)),0x40);
        }
        if ((lVar15 < 1) || (uVar12 = __isoc23_strtoull((*(char (*) [64])(__fp - 0x108)),(char **)0x0,10), uVar12 == 0))
        break;
        xSnprintf((*(char (*) [128])(__fp - 0xc8)),0x80,((char *)(long)&s__sys_kernel_mm_hugepages__s_free_0014cc80 /* "/sys/kernel/mm/hugepages/%s/free_hugepages" */),pcVar11);
                    /* Unresolved local var: int fd@[???] */
        wVar6 = open((*(char (*) [128])(__fp - 0xc8)),0);
        if (wVar6 < 0) {
                    /* Unresolved local var: int fd@[???] */
          piVar17 = __errno_location();
          lVar15 = (long)-*piVar17;
        }
        else {
          lVar15 = readfd_internal(wVar6,(*(char (*) [64])(__fp - 0x108)),0x40);
        }
        if (lVar15 < 1) break;
        uVar16 = __isoc23_strtoull((*(char (*) [64])(__fp - 0x108)),(char **)0x0,10);
        iVar5 = ffsl(uVar14);
        super->totalHugePageMem = super->totalHugePageMem + uVar14 * uVar12;
        super->usedHugePageMem[iVar5 + -7] = (uVar12 - uVar16) * uVar14;
        pdVar13 = readdir(__dirp);
        if (pdVar13 == (dirent *)0x0) goto LAB_001421c0;
      }
      goto LAB_00142030;
    }
LAB_001421c0:
    closedir(__dirp);
  }
                    /* Unresolved local var: FILE * file@[???] */
  (*(memory_t (*))(__fp - 0x130)) = 0;
  (*(memory_t (*))(__fp - 0x128)) = 0;
  (*(memory_t (*))(__fp - 0x118)) = 0;
  pFVar10 = fopen(((char *)(long)&s__proc_spl_kstat_zfs_arcstats_00149f41 /* "/proc/spl/kstat/zfs/arcstats" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (pFVar10 == (FILE_2 *)0x0) {
    (super->zfs).enabled = 0;
  }
  else {
                    /* Unresolved local var: size_t sz@[???] */
    while (pcVar11 = fgets((*(char (*) [128])(__fp - 0xc8)),0x80,pFVar10), pcVar11 != (char *)0x0) {
      switch((*(char (*) [128])(__fp - 0xc8))[0]) {
      case 'a':
        if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                      CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                               CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                        CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                 CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                          CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                   CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))))
                              )) == 0x7a69735f6e6f6e61) && ((*(char (*) [128])(__fp - 0xc8))[8] == 'e')) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 9,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).anon);
        }
        break;
      case 'b':
        if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                      CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                               CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                        CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                 CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                          CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                   CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))))
                              )) == 0x69735f73756e6f62) && (CONCAT11((*(char (*) [128])(__fp - 0xc8))[9],(*(char (*) [128])(__fp - 0xc8))[8]) == 0x657a)
           ) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 10,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(*(memory_t (*))(__fp - 0x118)));
        }
        break;
      case 'c':
        if ((CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))) == 0x696d5f63) &&
           ((*(char (*) [128])(__fp - 0xc8))[4] == 'n')) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 5,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).min);
        }
        else if ((CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))) ==
                  0x616d5f63) && ((*(char (*) [128])(__fp - 0xc8))[4] == 'x')) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 5,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).max);
        }
        else if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                           CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                    CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                             CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                      CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                               CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                        CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]
                                                                                ))))))) ==
                  0x73736572706d6f63) &&
                (CONCAT26((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 13)),
                          CONCAT24((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 11)),
                                   CONCAT13((*(char (*) [128])(__fp - 0xc8))[10],
                                            CONCAT12((*(char (*) [128])(__fp - 0xc8))[9],CONCAT11((*(char (*) [128])(__fp - 0xc8))[8],(*(char (*) [128])(__fp - 0xc8))[7]))))) ==
                 0x657a69735f646573)) {
          wVar6 = __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 0xf,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).compressed);
          (super->zfs).isCompressed = wVar6;
        }
        break;
      case 'd':
        if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                      CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                               CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                        CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                 CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                          CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                   CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))))
                              )) == 0x7a69735f66756264) && ((*(char (*) [128])(__fp - 0xc8))[8] == 'e')) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 9,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(*(memory_t (*))(__fp - 0x130)));
        }
        else if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                           CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                    CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                             CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                      CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                               CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                        CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]
                                                                                ))))))) ==
                  0x69735f65646f6e64) && (CONCAT11((*(char (*) [128])(__fp - 0xc8))[9],(*(char (*) [128])(__fp - 0xc8))[8]) == 0x657a)) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 10,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(*(memory_t (*))(__fp - 0x128)));
        }
        break;
      case 'h':
        if (CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                     CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                              CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                       CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                         CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                  CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))))))
                    ) == 0x657a69735f726468) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 8,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).header);
        }
        break;
      case 'm':
        if (CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                     CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                              CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                       CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                         CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                  CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))))))
                    ) == 0x657a69735f75666d) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 8,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).MFU);
        }
        else if (CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                          CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                   CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                            CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                     CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                              CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                       CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])
                                                                      )))))) == 0x657a69735f75726d)
        {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 8,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).MRU);
        }
        break;
      case 's':
        if (CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0]))) == 0x657a6973) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 4,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).size);
        }
        break;
      case 'u':
        if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                      CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                               CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                        CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],
                                                 CONCAT13((*(char (*) [128])(__fp - 0xc8))[3],
                                                          CONCAT12((*(char (*) [128])(__fp - 0xc8))[2],
                                                                   CONCAT11((*(char (*) [128])(__fp - 0xc8))[1],(*(char (*) [128])(__fp - 0xc8))[0])))))
                              )) == 0x6572706d6f636e75 &&
             CONCAT17((*(char (*) [128])(__fp - 0xc8))[0xf],
                      CONCAT25((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 13)),
                               CONCAT23((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 11)),
                                        CONCAT12((*(char (*) [128])(__fp - 0xc8))[10],CONCAT11((*(char (*) [128])(__fp - 0xc8))[9],(*(char (*) [128])(__fp - 0xc8))[8]))))) ==
             0x7a69735f64657373) && ((*(char (*) [128])(__fp - 0xc8))[0x10] == 'e')) {
          __isoc23_sscanf((*(char (*) [128])(__fp - 0xc8)) + 0x11,((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(super->zfs).uncompressed);
        }
      }
    }
    fclose(pFVar10);
    puVar1 = &(super->zfs).header;
    *puVar1 = *puVar1 >> 10;
    (super->zfs).enabled = (uint)((super->zfs).size != 0);
    (super->zfs).min = (super->zfs).min >> 10;
    (super->zfs).max = (super->zfs).max >> 10;
    (super->zfs).size = (super->zfs).size >> 10;
    (super->zfs).MFU = (super->zfs).MFU >> 10;
    (super->zfs).MRU = (super->zfs).MRU >> 10;
    (super->zfs).anon = (super->zfs).anon >> 10;
    (super->zfs).other = (*(memory_t (*))(__fp - 0x128)) + (*(memory_t (*))(__fp - 0x130)) + (*(memory_t (*))(__fp - 0x118)) >> 10;
    if ((super->zfs).isCompressed != 0) {
      (super->zfs).compressed = (super->zfs).compressed >> 10;
      (super->zfs).uncompressed = (super->zfs).uncompressed >> 10;
    }
  }
                    /* Unresolved local var: memory_t totalZram@[???]
                       Unresolved local var: memory_t usedZramComp@[???]
                       Unresolved local var: memory_t usedZramOrig@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: FILE * disksize_file@[???]
                       Unresolved local var: FILE * mm_stat_file@[???] */
  uVar14 = 0;
  uVar12 = 0;
  (*(memory_t (*))(__fp - 0x150)) = 0;
  iVar5 = 0;
  while( true ) {
    xSnprintf((*(char (*) [64])(__fp - 0x108)),0x22,((char *)(long)&s__sys_block_zram_u_mm_stat_00149fce /* "/sys/block/zram%u/mm_stat" */),iVar5);
    xSnprintf((*(char (*) [128])(__fp - 0xc8)),0x22,((char *)(long)&s__sys_block_zram_u_disksize_00149fe8 /* "/sys/block/zram%u/disksize" */),iVar5);
    pFVar10 = fopen((*(char (*) [128])(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
    __stream = fopen((*(char (*) [64])(__fp - 0x108)),((char *)(long)&DAT_00147760 /* "r" */));
    if (pFVar10 == (FILE_2 *)0x0) break;
    if (__stream == (FILE_2 *)0x0) {
      if (pFVar10 != (FILE_2 *)0x0) {
        fclose(pFVar10);
      }
      break;
    }
    (*(memory_t (*))(__fp - 0x130)) = 0;
    (*(memory_t (*))(__fp - 0x128)) = 0;
    (*(memory_t (*))(__fp - 0x118)) = 0;
    iVar7 = __isoc23_fscanf(pFVar10,((char *)(long)&s__llu_0014a003 /* "%llu\n" */),&(*(memory_t (*))(__fp - 0x130)));
    if ((iVar7 == 0) ||
       (iVar7 = __isoc23_fscanf(__stream,((char *)(long)&s__llu__llu_0014a009 /* "    %llu       %llu" */),&(*(memory_t (*))(__fp - 0x128)),&(*(memory_t (*))(__fp - 0x118))), iVar7 == 0)) {
      fclose(pFVar10);
      goto LAB_001426af;
    }
    uVar12 = uVar12 + (*(memory_t (*))(__fp - 0x130));
    (*(memory_t (*))(__fp - 0x150)) = (*(memory_t (*))(__fp - 0x150)) + (*(memory_t (*))(__fp - 0x118));
    uVar14 = uVar14 + (*(memory_t (*))(__fp - 0x128));
    fclose(pFVar10);
    fclose(__stream);
    iVar5 = iVar5 + 1;
  }
  if (__stream != (FILE_2 *)0x0) {
LAB_001426af:
    fclose(__stream);
  }
  (super->zram).totalZram = uVar12 >> 10;
  uVar14 = uVar14 >> 10;
  (super->zram).usedZramOrig = uVar14;
  uVar12 = (*(memory_t (*))(__fp - 0x150)) >> 10;
  if (uVar14 < (*(memory_t (*))(__fp - 0x150)) >> 10) {
    uVar12 = uVar14;
  }
  (super->zram).usedZramComp = uVar12;
  LinuxMachine_scanCPUTime(super);
  pSVar4 = (super->super).settings;
  if (pSVar4->showCPUFrequency != false) {
                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: uint i@[???] */
    uVar2 = (super->super).existingCPUs;
    pCVar18 = super->cpuData;
    uVar8 = 0;
    do {
      uVar14 = (ulong)uVar8;
      uVar8 = uVar8 + 1;
      pCVar18[uVar14].frequency = NAN;
    } while (uVar8 <= uVar2);
                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: int numCPUsWithFrequency@[???]
                       Unresolved local var: ulong totalFrequency@[???] */
    if (timeout_0 < 1) {
                    /* Unresolved local var: uint i@[???] */
      uVar14 = 0;
                    /* Unresolved local var: FILE * file@[???] */
      if (uVar2 != 0) {
        (*(memory_t (*))(__fp - 0x150)) = 0;
        iVar5 = 0;
        while( true ) {
          iVar7 = (int)uVar14;
                    /* Unresolved local var: LinuxMachine * this@[???] */
          uVar14 = (ulong)(iVar7 + 1U);
          if (pCVar18[uVar14].online != false) {
            xSnprintf((*(char (*) [128])(__fp - 0xc8)),0x40,((char *)(long)&s__sys_devices_system_cpu_cpu_u_cp_0014ccb0 /* "/sys/devices/system/cpu/cpu%u/cpufreq/scaling_cur_freq" */),iVar7);
            if (iVar7 == 0) {
              clock_gettime(1,(timespec_2 *)&(*(memory_t (*))(__fp - 0x128)));
            }
            pFVar10 = fopen((*(char (*) [128])(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
            if (pFVar10 == (FILE_2 *)0x0) {
              piVar17 = __errno_location();
              if (*piVar17 == 0) goto LAB_00142705;
              goto LAB_00142b15;
            }
            iVar9 = __isoc23_fscanf(pFVar10,((char *)(long)(__sec_rodata + 0x275f) /* "%lu" */),&(*(memory_t (*))(__fp - 0x130)));
            if (iVar9 == 1) {
              iVar5 = iVar5 + 1;
              (*(memory_t (*))(__fp - 0x130)) = (*(memory_t (*))(__fp - 0x130)) / 1000;
              (*(memory_t (*))(__fp - 0x150)) = (*(memory_t (*))(__fp - 0x150)) + (*(memory_t (*))(__fp - 0x130));
              super->cpuData[uVar14].frequency = (double)(*(memory_t (*))(__fp - 0x130));
            }
            fclose(pFVar10);
                    /* Unresolved local var: time_t timeTakenUs@[???] */
            if ((iVar7 == 0) &&
               (clock_gettime(1,(timespec_2 *)&(*(memory_t (*))(__fp - 0x118))),
               500 < (long)(((*(memory_t (*))(__fp - 0x118)) - (*(memory_t (*))(__fp - 0x128))) * 1000000 + ((*(long (*))(__fp - 0x110)) - (*(long (*))(__fp - 0x120))) / 1000))) {
              timeout_0 = 0x1e;
              goto LAB_00142b15;
            }
          }
          if ((super->super).existingCPUs <= iVar7 + 1U) break;
          pCVar18 = super->cpuData;
        }
        if (0 < iVar5) {
          super->cpuData->frequency = (double)(*(memory_t (*))(__fp - 0x150)) / (double)iVar5;
        }
      }
    }
    else {
      timeout_0 = timeout_0 + -1;
LAB_00142b15:
      scanCPUFrequencyFromCPUinfo(super);
    }
  }
LAB_00142705:
  if (pSVar4->showCPUTemperature == false) {
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else {
                    /* Unresolved local var: LinuxMachine * this@[???]
                       Unresolved local var: Settings * settings@[???] */
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      LibSensors_getCPUTemperatures
                (super->cpuData,(super->super).existingCPUs,(super->super).activeCPUs);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Machine_new @ 0x142dd0 */

Machine_2 * Machine_new(UsersTable *usersTable,uid_t userId)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  long lVar1;
  int wVar2;
  int iVar3;
  LinuxMachine *this;
  long lVar4;
  FILE_2 *__stream;
  char *pcVar5;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x238);
  if (this == (LinuxMachine *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  Machine_init((Machine *)this,usersTable,userId);
  lVar4 = sysconf(0x1e);
  wVar2 = (int)lVar4;
  this->pageSize = wVar2;
  if (wVar2 == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_get_pagesize_by_sysconf___0014cce8 /* "Cannot get pagesize by sysconf(_SC_PAGESIZE)" */));
  }
  this->pageSizeKB = (int)((ulong)(long)wVar2 >> 10);
  lVar4 = sysconf(2);
  this->jiffies = lVar4;
  if (lVar4 == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_get_clock_ticks_by_syscon_0014cd18 /* "Cannot get clock ticks by sysconf(_SC_CLK_TCK)" */));
  }
  __stream = fopen(((char *)(long)(__sec_rodata + 0x2e71) /* "/proc/stat" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_open__proc_stat_00149e65 /* "Cannot open /proc/stat" */));
  }
  this->boottime = -1;
  do {
                    /* Unresolved local var: size_t sz@[???] */
    pcVar5 = fgets((*(char (*) [4097])(__fp - 0x1038)),0x1001,__stream);
    if (pcVar5 == (char *)0x0) goto LAB_00142ee1;
  } while (((*(uint *)((char *)&(*(char (*) [4097])(__fp - 0x1038)) + 0)) != 0x6d697462) || ((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1038)) + 4)) != 0x2065));
  iVar3 = __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1038)),((char *)(long)&s_btime__lld_0014a024 /* "btime %lld\n" */),&this->boottime);
  if (iVar3 != 1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Failed_to_parse_btime_from__proc_0014cd48 /* "Failed to parse btime from /proc/stat" */));
  }
LAB_00142ee1:
  fclose(__stream);
  if (this->boottime == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_No_btime_in__proc_stat_0014a030 /* "No btime in /proc/stat" */));
  }
  LinuxMachine_updateCPUcount(this);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (Machine_2 *)this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

