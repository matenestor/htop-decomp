#include "htop.h"

/* procAcpiCheck @ 0x13a540 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ACPresence procAcpiCheck(void)

{
  undefined1 __frame[0x4b8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x478;
  long lVar1;
  int fd;
  int iVar2;
  ACPresence AVar3;
  ssize_t sVar4;
  int *piVar5;
  long lVar6;
  char *pcVar7;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int fd@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar7 = (*(char (*) [1024])(__fp - 0x428));
                    /* Unresolved local var: ssize_t r@[???] */
  for (lVar6 = 0x80; lVar6 != 0; lVar6 = lVar6 + -1) {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7[4] = '\0';
    pcVar7[5] = '\0';
    pcVar7[6] = '\0';
    pcVar7[7] = '\0';
    pcVar7 = pcVar7 + 8;
  }
  fd = open(((char *)(long)&s__proc_acpi_ac_adapter_AC_state_0014ca30 /* "/proc/acpi/ac_adapter/AC/state" */),0);
  if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar5 = __errno_location();
    if (-*piVar5 < 1) goto LAB_0013a5d0;
  }
  else {
    sVar4 = readfd_internal(fd,(*(char (*) [1024])(__fp - 0x428)),0x400);
    if (sVar4 < 1) {
LAB_0013a5d0:
      AVar3 = AC_ERROR;
      goto LAB_0013a5aa;
    }
  }
  iVar2 = strcmp((*(char (*) [1024])(__fp - 0x428)),((char *)(long)&s_on_line_00149898 /* "on-line" */));
  AVar3 = (ACPresence)(iVar2 == 0);
LAB_0013a5aa:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return AVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_Battery_getSysData @ 0x13a5e0 */

void Platform_Battery_getSysData(double *percent,ACPresence *isOnAC)

{
  undefined1 __frame[0x578] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x538;
  char cVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int wVar6;
  int iVar7;
  DIR_2 *__dirp;
  dirent *pdVar8;
  long lVar9;
  char *pcVar10;
  ssize_t sVar11;
  int *piVar12;
  ulong uVar13;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar14;

                    /* Unresolved local var: DIR * dir@[???]
                       Unresolved local var: uint64_t totalFull@[???]
                       Unresolved local var: uint64_t totalRemain@[???]
                       Unresolved local var: dirent * dirEntry@[???] */
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  *percent = NAN;
  *isOnAC = AC_ERROR;
  __dirp = opendir(((char *)(long)&s__sys_class_power_supply_001498a0 /* "/sys/class/power_supply" */));
  if (__dirp == (DIR_2 *)0x0) {
LAB_0013a8a4:
    if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar13 = 0;
  (*(ulong (*))(__fp - 0x4e8)) = 0;
  do {
    pdVar8 = readdir(__dirp);
    while( true ) {
      if (pdVar8 == (dirent *)0x0) {
        closedir(__dirp);
        dVar14 = NAN;
        if (uVar13 != 0) {
          dVar14 = ((double)(*(ulong (*))(__fp - 0x4e8)) * 100.0) / (double)uVar13;
        }
        *percent = dVar14;
        goto LAB_0013a8a4;
      }
                    /* Unresolved local var: char * entryName@[???]
                       Unresolved local var: int entryFd@[???]
                       Unresolved local var: anon_enum_32 type@[???] */
      iVar5 = dirfd(__dirp);
      iVar5 = openat(iVar5,pdVar8->d_name,0x210000);
      if (iVar5 < 0) break;
      if (((pdVar8->d_name[0] == 'B') && (pdVar8->d_name[1] == 'A')) && (pdVar8->d_name[2] == 'T'))
      {
LAB_0013a6a2:
                    /* Unresolved local var: ssize_t r@[???]
                       Unresolved local var: _Bool full@[???]
                       Unresolved local var: _Bool now@[???]
                       Unresolved local var: double fullCharge@[???]
                       Unresolved local var: double capacityLevel@[???]
                       Unresolved local var: char * line@[???]
                       Unresolved local var: int fd@[???] */
        wVar6 = openat(iVar5,((char *)(long)&s_uevent_001498c3 /* "uevent" */),0);
        if (wVar6 < 0) {
                    /* Unresolved local var: int fd@[???] */
          piVar12 = __errno_location();
          lVar9 = (long)-*piVar12;
        }
        else {
          lVar9 = readfd_internal(wVar6,(*(char (*) [1024])(__fp - 0x448)),0x400);
        }
        if (-1 < lVar9) {
          (*(char *(*))(__fp - 0x4c0)) = (*(char (*) [1024])(__fp - 0x448));
          bVar3 = false;
          (*(double (*))(__fp - 0x4d8)) = 0.0;
          (*(double (*))(__fp - 0x4e0)) = NAN;
          bVar4 = false;
          while (pcVar10 = strsep(&(*(char *(*))(__fp - 0x4c0)),((char *)(long)&DAT_00147506 /* "\n" */)), pcVar10 != (char *)0x0) {
            (*(char (*) [100])(__fp - 0x4b8))[0x60] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x61] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x62] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[99] = '\0';
            (*(int (*))(__fp - 0x4c4)) = 0;
            (*(char (*) [100])(__fp - 0x4b8))[0] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[1] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[2] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[3] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[4] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[5] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[6] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[7] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[8] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[9] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[10] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0xb] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0xc] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0xd] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0xe] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0xf] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x10] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x11] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x12] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x13] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x14] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x15] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x16] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x17] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x18] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x19] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x1a] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x1b] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x1c] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x1d] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x1e] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x1f] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x20] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x21] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x22] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x23] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x24] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x25] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x26] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x27] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x28] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x29] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x2a] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x2b] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x2c] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x2d] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x2e] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x2f] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x30] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x31] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x32] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x33] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x34] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x35] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x36] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x37] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x38] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x39] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x3a] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x3b] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x3c] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x3d] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x3e] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x3f] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x40] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x41] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x42] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x43] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x44] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x45] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x46] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x47] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x48] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x49] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x4a] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x4b] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x4c] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x4d] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x4e] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x4f] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x50] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x51] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x52] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x53] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x54] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x55] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x56] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x57] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x58] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x59] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x5a] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x5b] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x5c] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x5d] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x5e] = '\0';
            (*(char (*) [100])(__fp - 0x4b8))[0x5f] = '\0';
            iVar7 = __isoc23_sscanf(pcVar10,((char *)(long)&s_POWER_SUPPLY__99______d_001498ca /* "POWER_SUPPLY_%99[^=]=%d" */),(*(char (*) [100])(__fp - 0x4b8)),&(*(int (*))(__fp - 0x4c4)));
            if (iVar7 == 2) {
              iVar7 = strcmp((*(char (*) [100])(__fp - 0x4b8)),((char *)(long)&s_CAPACITY_001498e2 /* "CAPACITY" */));
              if (iVar7 == 0) {
                (*(double (*))(__fp - 0x4e0)) = (double)(*(int (*))(__fp - 0x4c4)) / 100.0;
              }
              else {
                iVar7 = strcmp((*(char (*) [100])(__fp - 0x4b8)),((char *)(long)&s_ENERGY_FULL_001498eb /* "ENERGY_FULL" */));
                if ((iVar7 == 0) || (iVar7 = strcmp((*(char (*) [100])(__fp - 0x4b8)),((char *)(long)&s_CHARGE_FULL_001498f7 /* "CHARGE_FULL" */)), iVar7 == 0)) {
                  (*(double (*))(__fp - 0x4d8)) = (double)(*(int (*))(__fp - 0x4c4));
                  dVar14 = (double)uVar13 + (*(double (*))(__fp - 0x4d8));
                  if (9.223372036854776e+18 <= dVar14) {
                    uVar13 = (long)(dVar14 - 9.223372036854776e+18) ^ 0x8000000000000000;
                  }
                  else {
                    uVar13 = (ulong)dVar14;
                  }
                  if (bVar3) goto LAB_0013a830;
                  bVar4 = true;
                }
                else {
                  iVar7 = strcmp((*(char (*) [100])(__fp - 0x4b8)),((char *)(long)&s_ENERGY_NOW_00149903 /* "ENERGY_NOW" */));
                  if ((iVar7 == 0) || (iVar7 = strcmp((*(char (*) [100])(__fp - 0x4b8)),((char *)(long)&s_CHARGE_NOW_0014990e /* "CHARGE_NOW" */)), iVar7 == 0)) {
                    (*(ulong (*))(__fp - 0x4e8)) = (*(ulong (*))(__fp - 0x4e8)) + (long)(*(int (*))(__fp - 0x4c4));
                    if (bVar4) goto LAB_0013a830;
                    bVar3 = true;
                  }
                }
              }
            }
          }
          if (((!bVar3) && (bVar4)) && (0.0 <= (*(double (*))(__fp - 0x4e0)))) {
            dVar14 = (*(double (*))(__fp - 0x4d8)) * (*(double (*))(__fp - 0x4e0)) + (double)(*(ulong (*))(__fp - 0x4e8));
            if (9.223372036854776e+18 <= dVar14) {
              (*(ulong (*))(__fp - 0x4e8)) = (long)(dVar14 - 9.223372036854776e+18) ^ 0x8000000000000000;
            }
            else {
              (*(ulong (*))(__fp - 0x4e8)) = (ulong)dVar14;
            }
          }
        }
      }
      else if ((pdVar8->d_name[0] == 'A') && (pdVar8->d_name[1] == 'C')) {
LAB_0013a97b:
                    /* Unresolved local var: ssize_t r@[???] */
        if (*isOnAC == AC_ERROR) {
                    /* Unresolved local var: int fd@[???] */
          wVar6 = openat(iVar5,((char *)(long)&s_online_00149919 /* "online" */),0);
          if (wVar6 < 0) {
                    /* Unresolved local var: int fd@[???] */
            piVar12 = __errno_location();
            if (-*piVar12 < 1) goto LAB_0013ab14;
          }
          else {
            sVar11 = readfd_internal(wVar6,(*(char (*) [1024])(__fp - 0x448)),2);
            if (sVar11 < 1) {
LAB_0013ab14:
              *isOnAC = AC_ERROR;
              goto LAB_0013a830;
            }
          }
          if ((*(char (*) [1024])(__fp - 0x448))[0] == '0') {
            *isOnAC = AC_ABSENT;
          }
          else if ((*(char (*) [1024])(__fp - 0x448))[0] == '1') {
            *isOnAC = AC_PRESENT;
          }
        }
      }
      else {
                    /* Unresolved local var: ssize_t ret@[???]
                       Unresolved local var: int fd@[???] */
        wVar6 = openat(iVar5,((char *)(long)&DAT_001498b8 /* "type" */),0);
        if (wVar6 < 0) {
                    /* Unresolved local var: int fd@[???] */
          piVar12 = __errno_location();
          lVar9 = (long)-*piVar12;
        }
        else {
          lVar9 = readfd_internal(wVar6,(*(char (*) [1024])(__fp - 0x448)),0x20);
        }
        if (0 < lVar9) {
          pcVar10 = (*(char (*) [1024])(__fp - 0x448)) + lVar9 + -1;
                    /* Unresolved local var: char * (*(char *(*))(__fp - 0x4c0))@[???] */
          cVar1 = (*(char (*) [1024])(__fp - 0x448))[lVar9 + -1];
          while (cVar1 == '\n') {
            *pcVar10 = '\0';
            pcVar10 = pcVar10 + -1;
            cVar1 = *pcVar10;
          }
          if (CONCAT26((*(ushort *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 6)),CONCAT24((*(ushort *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 4)),(*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 0)))) == 0x79726574746142)
          goto LAB_0013a6a2;
          if (((*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 0)) == 0x6e69614d) && ((*(ushort *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 4)) == 0x73)) goto LAB_0013a97b;
        }
      }
LAB_0013a830:
      close(iVar5);
      pdVar8 = readdir(__dirp);
    }
  } while( true );
}


/* Platform_setBindings @ 0x13b340 */

void Platform_setBindings(Htop_Action_2 *keys)

{
  keys[0x69] = Platform_actionSetIOPriority;
  keys[0x7b] = Platform_actionLowerAutogroupPriority;
  keys[0x7d] = Platform_actionHigherAutogroupPriority;
  keys[0x11b] = Platform_actionLowerAutogroupPriority;
  keys[0x11c] = Platform_actionHigherAutogroupPriority;
  return;
}


/* Platform_getUptime @ 0x13b390 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Platform_getUptime(void)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  int iVar1;
  int wVar2;
  FILE_2 *__stream;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar3;

  (*(long (*))(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(double (*))(__fp - 0x28)) = 0.0;
  __stream = fopen(((char *)(long)&s__proc_uptime_001499c4 /* "/proc/(*(double (*))(__fp - 0x28))" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
                    /* Unresolved local var: int n@[???] */
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__64lf_001499d1 /* "%64lf" */),&(*(double (*))(__fp - 0x28)));
    fclose(__stream);
    if (iVar1 < 1) {
      wVar2 = 0;
      goto LAB_0013b41d;
    }
  }
  dVar3 = (*(double (*))(__fp - 0x28));
  if (ABS((*(double (*))(__fp - 0x28))) < 4503599627370496.0) {
    dVar3 = __builtin_floor((*(double (*))(__fp - 0x28)));
  }
  wVar2 = (int)dVar3;
LAB_0013b41d:
  if ((*(long (*))(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return wVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getLoadAverage @ 0x13b480 */

void Platform_getLoadAverage(double *one,double *five,double *fifteen)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  FILE_2 *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_loadavg_001499d7 /* "/proc/loadavg" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__lf__lf__lf_001499e5 /* "%lf %lf %lf" */),&(*(double (*))(__fp - 0x48)),&(*(double (*))(__fp - 0x50)),&(*(double (*))(__fp - 0x58)));
    fclose(__stream);
    if (iVar1 == 3) {
      *one = (*(double (*))(__fp - 0x48));
      *five = (*(double (*))(__fp - 0x50));
      goto LAB_0013b509;
    }
  }
  (*(double (*))(__fp - 0x58)) = NAN;
  *one = NAN;
  *five = NAN;
LAB_0013b509:
  *fifteen = (*(double (*))(__fp - 0x58));
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getMaxPid @ 0x13b560 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pid_t Platform_getMaxPid(void)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  FILE_2 *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(pid_t (*))(__fp - 0x24)) = 0x3fffff;
  __stream = fopen(((char *)(long)&s__proc_sys_kernel_pid_max_00148869 /* "/proc/sys/kernel/pid_max" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    __isoc23_fscanf(__stream,((char *)(long)&DAT_0014978b /* "%32d" */),&(*(pid_t (*))(__fp - 0x24)));
    fclose(__stream);
  }
  if ((*(long (*))(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return (*(pid_t (*))(__fp - 0x24));
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_setCPUValues @ 0x13b5e0 */

/* DWARF original prototype: double Platform_setCPUValues(Meter * this, uint cpu) */

double Platform_setCPUValues(Meter *this,uint cpu)

{
  long lVar1;
  char cVar2;
  _Bool _Var3;
  _Bool _Var4;
  Settings__2 *pSVar5;
  double *pdVar6;
  ulong uVar7;
  undefined16 auVar8;
  undefined16 auVar9;
  ulong uVar10;
  double *pdVar11;
  ulong uVar12;
  ulong uVar13;
  double dVar14;
  undefined16 auVar15;
  undefined16 auVar16;
  undefined16 auVar17;
  undefined16 auVar18;
  double dVar19;
  double dVar20;

  dVar19 = 1.0;
  pSVar5 = this->host->settings;
  lVar1 = this->host[1].iterationsRemaining + (ulong)cpu * 0xd8;
  uVar12 = *(ulong *)(lVar1 + 0x60);
  if (uVar12 == 0) {
LAB_0013b623:
    cVar2 = *(char *)(lVar1 + 0xd0);
    pdVar6 = this->values;
  }
  else {
    if (-1 < (long)uVar12) {
      dVar19 = (double)(long)uVar12;
      goto LAB_0013b623;
    }
    cVar2 = *(char *)(lVar1 + 0xd0);
    pdVar6 = this->values;
    dVar19 = (double)uVar12;
  }
  if (cVar2 == '\0') {
    this->curItems = '\0';
    return NAN;
  }
  uVar12 = *(ulong *)(lVar1 + 0x90);
  if ((long)uVar12 < 0) {
    uVar10 = *(ulong *)(lVar1 + 0x68);
    dVar14 = (double)uVar12;
    if (-1 < (long)uVar10) goto LAB_0013b665;
LAB_0013b7be:
    dVar20 = (double)uVar10;
  }
  else {
    dVar14 = (double)(long)uVar12;
    uVar10 = *(ulong *)(lVar1 + 0x68);
    if ((long)uVar10 < 0) goto LAB_0013b7be;
LAB_0013b665:
    dVar20 = (double)(long)uVar10;
  }
  _Var3 = pSVar5->detailedCPUTime;
  uVar12 = *(ulong *)(lVar1 + 0xb0);
  uVar10 = *(ulong *)(lVar1 + 0xb8);
  *pdVar6 = (dVar14 / dVar19) * 100.0;
  pdVar6[1] = (dVar20 / dVar19) * 100.0;
  if (_Var3 == false) {
    uVar7 = *(ulong *)(lVar1 + 0x78);
    if ((long)uVar7 < 0) {
      dVar14 = (double)uVar7;
      if (-1 < (long)(uVar12 + uVar10)) goto LAB_0013b83f;
LAB_0013b8ea:
      dVar20 = (double)(uVar12 + uVar10);
    }
    else {
      dVar14 = (double)(long)uVar7;
      if ((long)(uVar12 + uVar10) < 0) goto LAB_0013b8ea;
LAB_0013b83f:
      dVar20 = (double)(long)(uVar12 + uVar10);
    }
    uVar12 = 4;
    pdVar6[2] = (dVar14 / dVar19) * 100.0;
    pdVar6[3] = (dVar20 / dVar19) * 100.0;
    this->curItems = '\x04';
LAB_0013b869:
                    /* Unresolved local var: double sum@[???] */
    dVar14 = 0.0;
                    /* Unresolved local var: size_t i@[???] */
    pdVar11 = pdVar6;
    do {
      if (0.0 < *pdVar11) {
        dVar14 = dVar14 + *pdVar11;
      }
      pdVar11 = pdVar11 + 1;
    } while (pdVar6 + uVar12 != pdVar11);
    if (100.0 <= dVar14) {
      dVar14 = 100.0;
    }
    if (_Var3 == false) goto LAB_0013b8a4;
  }
  else {
    uVar7 = *(ulong *)(lVar1 + 0x70);
    if ((long)uVar7 < 0) {
      uVar13 = *(ulong *)(lVar1 + 0xa0);
      dVar14 = (double)uVar7;
      if (-1 < (long)uVar13) goto LAB_0013b6cb;
LAB_0013b93a:
      dVar20 = (double)uVar13;
    }
    else {
      dVar14 = (double)(long)uVar7;
      uVar13 = *(ulong *)(lVar1 + 0xa0);
      if ((long)uVar13 < 0) goto LAB_0013b93a;
LAB_0013b6cb:
      dVar20 = (double)(long)uVar13;
    }
    uVar7 = *(ulong *)(lVar1 + 0xa8);
    pdVar6[2] = (dVar14 / dVar19) * 100.0;
    pdVar6[3] = (dVar20 / dVar19) * 100.0;
    pdVar6[4] = ((double)uVar7 / dVar19) * 100.0;
    this->curItems = '\x05';
    pdVar6[5] = ((double)uVar12 / dVar19) * 100.0;
    _Var4 = pSVar5->accountGuestInCPUMeter;
    pdVar6[6] = ((double)uVar10 / dVar19) * 100.0;
    if (_Var4 != false) {
      this->curItems = '\a';
      uVar12 = 7;
      pdVar6[7] = ((double)*(ulong *)(lVar1 + 0x98) / dVar19) * 100.0;
      goto LAB_0013b869;
    }
    uVar12 = (ulong)this->curItems;
    dVar14 = 0.0;
    pdVar6[7] = ((double)*(ulong *)(lVar1 + 0x98) / dVar19) * 100.0;
    if (uVar12 != 0) goto LAB_0013b869;
  }
  this->curItems = '\b';
LAB_0013b8a4:
  pdVar6[8] = *(double *)(lVar1 + 0xc0);
  pdVar6[9] = *(double *)(lVar1 + 200);
  return dVar14;
}


/* Platform_setMemoryValues @ 0x13ba40 */

/* DWARF original prototype: void Platform_setMemoryValues(Meter * this) */

void Platform_setMemoryValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  memory_t mVar5;
  double dVar6;
  double dVar7;

  pMVar1 = this->host;
  uVar2 = pMVar1->usedMem;
  pdVar3 = this->values;
  this->total = (double)pMVar1->totalMem;
  dVar6 = (double)uVar2;
  uVar2 = pMVar1->sharedMem;
  uVar4 = pMVar1->buffersMem;
  pdVar3[2] = 0.0;
  *pdVar3 = dVar6;
  pdVar3[1] = (double)uVar2;
  uVar2 = pMVar1->cachedMem;
  pdVar3[3] = (double)uVar4;
  uVar4 = pMVar1->availableMem;
  pdVar3[4] = (double)uVar2;
  mVar5 = pMVar1[2].cachedMem;
  pdVar3[5] = (double)uVar4;
  if (((int)mVar5 != 0) && (Running_containerized == false)) {
                    /* Unresolved local var: ulonglong shrinkableSize@[???] */
    dVar7 = 0.0;
    if (pMVar1[2].sharedMem < pMVar1[2].totalSwap) {
      dVar7 = (double)(pMVar1[2].totalSwap - pMVar1[2].sharedMem);
      dVar6 = dVar6 - dVar7;
    }
    *pdVar3 = dVar6;
    pdVar3[4] = (double)uVar2 + dVar7;
    pdVar3[5] = (double)uVar4 + dVar7;
  }
  if (pMVar1[3].settings != (Settings__2 *)0x0 || pMVar1[3].realtime.tv_sec != 0) {
    dVar6 = *(double *)&pMVar1[3].settings;
    *pdVar3 = *pdVar3 - dVar6;
    pdVar3[2] = dVar6 + 0.0;
  }
  return;
}


/* Platform_setSwapValues @ 0x13bca0 */

/* DWARF original prototype: void Platform_setSwapValues(Meter * this) */

void Platform_setSwapValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  double dVar5;
  double dVar6;

  pMVar1 = this->host;
  uVar2 = pMVar1->usedSwap;
  pdVar3 = this->values;
  this->total = (double)pMVar1->totalSwap;
  dVar5 = (double)uVar2;
  uVar2 = pMVar1->cachedSwap;
  uVar4 = pMVar1[3].realtime.tv_sec;
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
  if (pMVar1[3].settings != (Settings__2 *)0x0) {
    *pdVar3 = dVar5;
    pdVar3[2] = 0.0;
    return;
  }
  return;
}


/* Platform_setZramValues @ 0x13be10 */

/* DWARF original prototype: void Platform_setZramValues(Meter * this) */

void Platform_setZramValues(Meter *this)

{
  Machine *pMVar1;
  Table *pTVar2;
  double *pdVar3;
  ulong uVar4;
  double dVar5;

  pMVar1 = this->host;
  pTVar2 = pMVar1[2].activeTable;
  this->total = *(double *)&pMVar1[2].tables;
  dVar5 = *(double *)&pTVar2;
  uVar4 = (long)pMVar1[2].processTable - (long)pTVar2;
  if (-1 < (long)uVar4) {
    pdVar3 = this->values;
    *pdVar3 = dVar5;
    pdVar3[1] = (double)(long)uVar4;
    return;
  }
  pdVar3 = this->values;
  *pdVar3 = dVar5;
  pdVar3[1] = (double)uVar4;
  return;
}


/* Platform_setZfsArcValues @ 0x13bef0 */

/* DWARF original prototype: void Platform_setZfsArcValues(Meter * this) */

void Platform_setZfsArcValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double *pdVar3;
  ulong uVar4;
  UsersTable *pUVar5;

  pMVar1 = this->host;
  uVar2 = pMVar1[2].usedSwap;
  pdVar3 = this->values;
  this->total = (double)pMVar1[2].availableMem;
  uVar4 = pMVar1[2].cachedSwap;
  *pdVar3 = (double)uVar2;
  (*(uint *)((char *)&uVar2 + 0)) = pMVar1[2].activeCPUs;
  (*(uint *)((char *)&uVar2 + 4)) = pMVar1[2].existingCPUs;
  pdVar3[1] = (double)uVar4;
  pUVar5 = pMVar1[2].usersTable;
  pdVar3[2] = (double)uVar2;
  (*(uint *)((char *)&uVar4 + 0)) = pMVar1[2].htopUserId;
  (*(uint *)((char *)&uVar4 + 4)) = pMVar1[2].maxUserId;
  pdVar3[3] = *(double *)&pUVar5;
  pdVar3[4] = (double)uVar4;
  this->curItems = '\x05';
  uVar2 = pMVar1[2].totalSwap;
  if (-1 < (long)uVar2) {
    pdVar3[5] = (double)(long)uVar2;
    return;
  }
  pdVar3[5] = (double)uVar2;
  return;
}


/* Platform_setZfsCompressedArcValues @ 0x13c270 */

/* DWARF original prototype: void Platform_setZfsCompressedArcValues(Meter * this) */

void Platform_setZfsCompressedArcValues(Meter *this)

{
  Machine *pMVar1;
  double *pdVar2;
  ulong uVar3;
  double dVar4;

  pMVar1 = this->host;
  pdVar2 = this->values;
  if (*(int *)((long)&pMVar1[2].cachedMem + 4) == 0) {
    uVar3 = pMVar1[2].totalSwap;
    this->total = (double)uVar3;
    *pdVar2 = (double)uVar3;
    return;
  }
  if ((long)pMVar1[2].tableCount < 0) {
    (*(uint *)((char *)&uVar3 + 0)) = pMVar1[2].userId;
    (*(uchar *)((char *)&uVar3 + 4)) = pMVar1[2].field_0x94;
    (*(uchar *)((char *)&uVar3 + 5)) = pMVar1[2].field_0x95;
    (*(uchar *)((char *)&uVar3 + 6)) = pMVar1[2].field_0x96;
    (*(uchar *)((char *)&uVar3 + 7)) = pMVar1[2].field_0x97;
  }
  else {
    (*(uint *)((char *)&uVar3 + 0)) = pMVar1[2].userId;
    (*(uchar *)((char *)&uVar3 + 4)) = pMVar1[2].field_0x94;
    (*(uchar *)((char *)&uVar3 + 5)) = pMVar1[2].field_0x95;
    (*(uchar *)((char *)&uVar3 + 6)) = pMVar1[2].field_0x96;
    (*(uchar *)((char *)&uVar3 + 7)) = pMVar1[2].field_0x97;
  }
  dVar4 = (double)pMVar1[2].tableCount;
  if (-1 < (long)uVar3) {
    this->total = dVar4;
    *pdVar2 = (double)(long)uVar3;
    return;
  }
  this->total = dVar4;
  *pdVar2 = (double)uVar3;
  return;
}


/* Platform_getFileDescriptors @ 0x13c450 */

void Platform_getFileDescriptors(double *used,double *max)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  int iVar1;
  FILE_2 *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  *used = NAN;
  *max = 65536.0;
  __stream = fopen(((char *)(long)&s__proc_sys_fs_file_nr_001499f1 /* "/proc/sys/fs/file-nr" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__llu__llu__llu_00149a06 /* "%llu %llu %llu" */),&(*(ulonglong (*))(__fp - 0x38)),&(*(ulonglong (*))(__fp - 0x40)),&(*(ulonglong (*))(__fp - 0x48)));
    if (iVar1 == 3) {
      if ((long)(*(ulonglong (*))(__fp - 0x38)) < 0) {
        *used = (double)(*(ulonglong (*))(__fp - 0x38));
      }
      else {
        *used = (double)(long)(*(ulonglong (*))(__fp - 0x38));
      }
      *max = (double)(*(ulonglong (*))(__fp - 0x48));
    }
    fclose(__stream);
  }
  if ((*(long (*))(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Platform_getDiskIO @ 0x13c570 */

_Bool Platform_getDiskIO(DiskIOData *data)

{
  undefined1 __frame[0x248] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x208;
  char cVar1;
  long lVar2;
  _Bool _Var3;
  int iVar4;
  FILE_2 *__stream;
  char *pcVar5;
  size_t __n;
  long lVar6;
  uint64_t uVar7;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_diskstats_00149a15 /* "/proc/diskstats" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    _Var3 = false;
  }
  else {
    uVar7 = 0;
    (*(char (*) [32])(__fp - 0x188))[0] = '\0';
    (*(char (*) [32])(__fp - 0x188))[1] = '\0';
    (*(char (*) [32])(__fp - 0x188))[2] = '\0';
    (*(char (*) [32])(__fp - 0x188))[3] = '\0';
    (*(char (*) [32])(__fp - 0x188))[4] = '\0';
    (*(char (*) [32])(__fp - 0x188))[5] = '\0';
    (*(char (*) [32])(__fp - 0x188))[6] = '\0';
    (*(char (*) [32])(__fp - 0x188))[7] = '\0';
    (*(char (*) [32])(__fp - 0x188))[8] = '\0';
    (*(char (*) [32])(__fp - 0x188))[9] = '\0';
    (*(char (*) [32])(__fp - 0x188))[10] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0xb] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0xc] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0xd] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0xe] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0xf] = '\0';
    (*(long (*))(__fp - 0x1b8)) = 0;
    (*(long (*))(__fp - 0x1b0)) = 0;
    (*(char (*) [32])(__fp - 0x188))[0x10] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x11] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x12] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x13] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x14] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x15] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x16] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x17] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x18] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x19] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x1a] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x1b] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x1c] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x1d] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x1e] = '\0';
    (*(char (*) [32])(__fp - 0x188))[0x1f] = '\0';
LAB_0013c600:
                    /* Unresolved local var: size_t sz@[???] */
    pcVar5 = fgets((*(char (*) [256])(__fp - 0x148)),0x100,__stream);
    if (pcVar5 != (char *)0x0) {
      iVar4 = __isoc23_sscanf((*(char (*) [256])(__fp - 0x148)),((char *)(long)&s___d___d__31s___u___u__llu___u____0014ca50 /* "%*d %*d %31s %*u %*u %llu %*u %*u %*u %llu %*u %*u %llu" */),
                              (*(char (*) [32])(__fp - 0x168)),&(*(ulonglong (*))(__fp - 0x190)),&(*(ulonglong (*))(__fp - 0x198)),&(*(ulonglong (*))(__fp - 0x1a0)));
      if ((iVar4 == 4) &&
         ((((*(ushort *)((char *)&(*(char (*) [32])(__fp - 0x168)) + 0)) != 0x6d64 || ((*(char (*) [32])(__fp - 0x168))[2] != '-')) && ((*(uint *)((char *)&(*(char (*) [32])(__fp - 0x168)) + 0)) != 0x6d61727a)))) {
        if ((*(char (*) [32])(__fp - 0x188))[0] != '\0') {
          __n = strlen((*(char (*) [32])(__fp - 0x188)));
          iVar4 = strncmp((*(char (*) [32])(__fp - 0x168)),(*(char (*) [32])(__fp - 0x188)),__n);
          if (iVar4 == 0) goto LAB_0013c600;
        }
        lVar6 = 0;
        do {
          cVar1 = (*(char (*) [32])(__fp - 0x168))[lVar6];
          if (cVar1 == '\0') break;
                    /* Unresolved local var: size_t i@[???] */
          (*(char (*) [32])(__fp - 0x188))[lVar6] = cVar1;
          lVar6 = lVar6 + 1;
        } while (lVar6 != 0x1f);
        (*(char (*) [32])(__fp - 0x188))[lVar6] = '\0';
        (*(long (*))(__fp - 0x1b0)) = (*(long (*))(__fp - 0x1b0)) + (*(ulonglong (*))(__fp - 0x190));
        uVar7 = uVar7 + (*(ulonglong (*))(__fp - 0x1a0));
        (*(long (*))(__fp - 0x1b8)) = (*(long (*))(__fp - 0x1b8)) + (*(ulonglong (*))(__fp - 0x198));
      }
      goto LAB_0013c600;
    }
    fclose(__stream);
    data->totalMsTimeSpend = uVar7;
    data->totalBytesRead = (*(long (*))(__fp - 0x1b0)) << 9;
    data->totalBytesWritten = (*(long (*))(__fp - 0x1b8)) << 9;
    _Var3 = true;
  }
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var3;
}


/* Platform_getNetworkIO @ 0x13c770 */

_Bool Platform_getNetworkIO(NetworkIOData *data)

{
  undefined1 __frame[0x308] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2c8;
  long lVar1;
  _Bool _Var2;
  int iVar3;
  FILE_2 *__stream;
  char *pcVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_net_dev_00149a2e /* "/proc/net/dev" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    _Var2 = false;
  }
  else {
    data->bytesReceived = 0;
    data->packetsReceived = 0;
    data->bytesTransmitted = 0;
    data->packetsTransmitted = 0;
    while( true ) {
                    /* Unresolved local var: size_t sz@[???] */
      pcVar4 = fgets((*(char (*) [512])(__fp - 0x238)),0x200,__stream);
      if (pcVar4 == (char *)0x0) break;
      iVar3 = __isoc23_sscanf((*(char (*) [512])(__fp - 0x238)),((char *)(long)&s__31s__llu__llu___u___u___u___u___0014ca88 /* "%31s %llu %llu %*u %*u %*u %*u %*u %*u %llu %llu" */),
                              (*(char (*) [32])(__fp - 0x258)),&(*(ulonglong (*))(__fp - 0x260)),&(*(ulonglong (*))(__fp - 0x268)),&(*(ulonglong (*))(__fp - 0x270)),
                              &(*(ulonglong (*))(__fp - 0x278)));
      if ((iVar3 == 5) && ((*(uint *)((char *)&(*(char (*) [32])(__fp - 0x258)) + 0)) != 0x3a6f6c)) {
        data->bytesTransmitted = (*(ulonglong (*))(__fp - 0x270)) + data->bytesTransmitted;
        data->packetsTransmitted = (*(ulonglong (*))(__fp - 0x278)) + data->packetsTransmitted;
        data->bytesReceived = (*(ulonglong (*))(__fp - 0x260)) + data->bytesReceived;
        data->packetsReceived = (*(ulonglong (*))(__fp - 0x268)) + data->packetsReceived;
      }
    }
    fclose(__stream);
    _Var2 = true;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var2;
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

CommandLineStatus Platform_getLongOption(int opt,int argc,char **argv)

{
  return STATUS_ERROR_EXIT;
}


/* Platform_done @ 0x13c8e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Platform_done(void)

{
  long in_RCX;
  long in_RDX;
  long in_RSI;
  long in_RDI;
  long in_R8;
  long in_R9;

  if (dlopenHandle != (void *)0x0) {
    (*(code *)(sym_sensors_cleanup))(in_RDI,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    dlclose(dlopenHandle);
    dlopenHandle = (void *)0x0;
    return;
  }
  return;
}


/* Platform_init @ 0x13c920 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool Platform_init(void)

{
  undefined1 __frame[0x11d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1198;
  long lVar1;
  ssize_t sVar2;
  FILE_2 *__stream;
  char *pcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  LibSensors_init();
  sVar2 = readlink(((char *)(long)&s__proc_self_ns_pid_00149a40 /* "/proc/self/ns/pid" */),(*(char (*) [4096])(__fp - 0x1048)),0xfff);
  if ((sVar2 < 1) ||
     (((*(char (*) [4096])(__fp - 0x1048))[sVar2] = '\0',
      (*(ulong *)((char *)&(*(char (*) [4096])(__fp - 0x1048)) + 0)) == 0x3230345b3a646970 && (*(ulong *)((char *)&(*(char (*) [4096])(__fp - 0x1048)) + 8)) == 0x5d36333831333536 &&
      ((*(char (*) [4096])(__fp - 0x1048))[0x10] == '\0')))) {
    __stream = fopen(((char *)(long)&s__proc_1_mounts_00149a63 /* "/proc/1/mounts" */),((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream != (FILE_2 *)0x0) {
      do {
                    /* Unresolved local var: size_t sz@[???] */
        pcVar3 = fgets((*(char (*) [256])(__fp - 0x1148)),0x100,__stream);
        if (pcVar3 == (char *)0x0) goto LAB_0013ca70;
        if ((CONCAT17((*(char (*) [256])(__fp - 0x1148))[7],(*(ulong *)((char *)&(*(char (*) [256])(__fp - 0x1148)) + 0))) == 0x702f20736663786c) &&
           ((*(uint *)((char *)&(*(char (*) [256])(__fp - 0x1148)) + 7)) == 0x636f7270)) {
          Running_containerized = true;
          goto LAB_0013ca70;
        }
      } while ((CONCAT17((*(char (*) [256])(__fp - 0x1148))[7],(*(ulong *)((char *)&(*(char (*) [256])(__fp - 0x1148)) + 0))) != 0x2079616c7265766f ||
                CONCAT53((*(ulong *)((char *)&(*(char (*) [256])(__fp - 0x1148)) + 11)),(*(ulong *)((char *)&(*(char (*) [256])(__fp - 0x1148)) + 8))) != 0x616c7265766f202f) ||
              ((*(char (*) [256])(__fp - 0x1148))[0x10] != 'y'));
      Running_containerized = true;
LAB_0013ca70:
      fclose(__stream);
    }
  }
  else {
    Running_containerized = true;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return true;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_init_13caa0 @ 0x13caa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool Platform_init_13caa0(void)

{
  _Bool _Var1;
  int iVar2;

  iVar2 = access(((char *)(long)&s__proc_00149a78 /* "/proc" */),4);
  if (iVar2 == 0) {
    _Var1 = Platform_init();
    return _Var1;
  }
  __fprintf_chk(_stderr,2,((char *)(long)&s_Error__could_not_read_procfs__co_0014b168 /* "Error: could not read procfs (compiled to look in %s).\n" */),((char *)(long)&s__proc_00149a78 /* "/proc" */));
  return false;
}


/* Platform_getPressureStall @ 0x13ccc0 */

void Platform_getPressureStall(char *file,_Bool some,double *ten,double *sixty,double *threehundred)

{
  undefined1 __frame[0x158] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x118;
  long lVar1;
  FILE_2 *__stream;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  *threehundred = 0.0;
  *sixty = 0.0;
  *ten = 0.0;
  xSnprintf((*(char (*) [128])(__fp - 0xc8)),0x80,((char *)(long)&s__proc_pressure__s_00149a90 /* "/proc/pressure/%s" */),file);
  __stream = fopen((*(char (*) [128])(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    *threehundred = NAN;
    *sixty = NAN;
    *ten = NAN;
  }
  else {
    __isoc23_fscanf(__stream,((char *)(long)&s_some_avg10__32lf_avg60__32lf_avg_0014cac0 /* "some avg10=%32lf avg60=%32lf avg300=%32lf total=%*f " */),ten,sixty,
                    threehundred);
    if (!some) {
      __isoc23_fscanf(__stream,((char *)(long)&s_full_avg10__32lf_avg60__32lf_avg_0014caf8 /* "full avg10=%32lf avg60=%32lf avg300=%32lf total=%*f " */),ten,sixty,
                      threehundred);
    }
    fclose(__stream);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_Battery_getProcBatInfo @ 0x13cdd0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double Platform_Battery_getProcBatInfo(void)

{
  undefined1 __frame[0xa78] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa38;
  long lVar1;
  int wVar2;
  int iVar3;
  DIR_2 *__dirp;
  dirent *pdVar4;
  char *pcVar5;
  int *piVar6;
  long lVar7;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar8;
  double dVar9;

                    /* Unresolved local var: DIR * batteryDir@[???]
                       Unresolved local var: uint64_t totalFull@[???]
                       Unresolved local var: uint64_t totalRemain@[???]
                       Unresolved local var: dirent * dirEntry@[???] */
  bVar8 = 0;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __dirp = opendir(((char *)(long)&s__proc_acpi_battery_00149aa2 /* "/proc/acpi/battery" */));
  if (__dirp != (DIR_2 *)0x0) {
    (*(ulong (*))(__fp - 0x9e8)) = 0;
                    /* Unresolved local var: char * entryName@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: char * line@[???] */
    (*(ulong (*))(__fp - 0x9e0)) = 0;
LAB_0013ce30:
    pdVar4 = readdir(__dirp);
    if (pdVar4 != (dirent *)0x0) {
      if (((pdVar4->d_name[0] == 'B') && (pdVar4->d_name[1] == 'A')) && (pdVar4->d_name[2] == 'T'))
      {
        pcVar5 = (*(char (*) [1024])(__fp - 0x448));
        for (lVar7 = 0x80; lVar7 != 0; lVar7 = lVar7 + -1) {
          pcVar5[0] = '\0';
          pcVar5[1] = '\0';
          pcVar5[2] = '\0';
          pcVar5[3] = '\0';
          pcVar5[4] = '\0';
          pcVar5[5] = '\0';
          pcVar5[6] = '\0';
          pcVar5[7] = '\0';
          pcVar5 = pcVar5 + (ulong)bVar8 * -0x10 + 8;
        }
        xSnprintf((*(char (*) [256])(__fp - 0x948)),0x100,((char *)(long)&s__s__s_info_00149ab5 /* "%s/%s/info" */),((char *)(long)&s__proc_acpi_battery_00149aa2 /* "/proc/acpi/battery" */),pdVar4->d_name);
                    /* Unresolved local var: int fd@[???] */
        wVar2 = open((*(char (*) [256])(__fp - 0x948)),0);
        if (wVar2 < 0) {
                    /* Unresolved local var: int fd@[???] */
          piVar6 = __errno_location();
          lVar7 = (long)-*piVar6;
        }
        else {
          lVar7 = readfd_internal(wVar2,(*(char (*) [1024])(__fp - 0x448)),0x400);
        }
        if (-1 < lVar7) {
          pcVar5 = (*(char (*) [1024])(__fp - 0x848));
          for (lVar7 = 0x80; lVar7 != 0; lVar7 = lVar7 + -1) {
            pcVar5[0] = '\0';
            pcVar5[1] = '\0';
            pcVar5[2] = '\0';
            pcVar5[3] = '\0';
            pcVar5[4] = '\0';
            pcVar5[5] = '\0';
            pcVar5[6] = '\0';
            pcVar5[7] = '\0';
            pcVar5 = pcVar5 + (ulong)bVar8 * -0x10 + 8;
          }
          xSnprintf((*(char (*) [256])(__fp - 0x948)),0x100,((char *)(long)&s__s__s_state_00149ac0 /* "%s/%s/state" */),((char *)(long)&s__proc_acpi_battery_00149aa2 /* "/proc/acpi/battery" */),pdVar4->d_name);
                    /* Unresolved local var: int fd@[???] */
          wVar2 = open((*(char (*) [256])(__fp - 0x948)),0);
          if (wVar2 < 0) {
                    /* Unresolved local var: int fd@[???] */
            piVar6 = __errno_location();
            lVar7 = (long)-*piVar6;
          }
          else {
            lVar7 = readfd_internal(wVar2,(*(char (*) [1024])(__fp - 0x848)),0x400);
          }
          if (-1 < lVar7) {
            (*(char *(*))(__fp - 0x9c0)) = (*(char (*) [1024])(__fp - 0x448));
            do {
              pcVar5 = strsep(&(*(char *(*))(__fp - 0x9c0)),((char *)(long)&DAT_00147506 /* "\n" */));
              if (pcVar5 == (char *)0x0) goto LAB_0013cfdb;
              (*(char (*) [100])(__fp - 0x9b8))[0] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[1] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[2] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[3] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[4] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[5] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[6] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[7] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[8] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[9] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[10] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xb] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xc] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xd] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xe] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xf] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x60] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x61] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x62] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[99] = '\0';
              (*(int (*))(__fp - 0x9c4)) = 0;
              (*(char (*) [100])(__fp - 0x9b8))[0x10] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x11] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x12] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x13] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x14] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x15] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x16] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x17] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x18] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x19] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x20] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x21] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x22] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x23] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x24] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x25] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x26] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x27] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x28] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x29] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x30] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x31] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x32] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x33] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x34] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x35] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x36] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x37] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x38] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x39] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x40] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x41] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x42] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x43] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x44] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x45] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x46] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x47] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x48] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x49] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x50] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x51] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x52] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x53] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x54] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x55] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x56] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x57] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x58] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x59] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5f] = '\0';
              iVar3 = __isoc23_sscanf(pcVar5,((char *)(long)&s__99______d_00149acc /* "%99[^:]:%d" */),(*(char (*) [100])(__fp - 0x9b8)),&(*(int (*))(__fp - 0x9c4)));
            } while ((iVar3 != 2) || (iVar3 = strcmp((*(char (*) [100])(__fp - 0x9b8)),((char *)(long)&s_last_full_capacity_00149ad7 /* "last full capacity" */)), iVar3 != 0));
            (*(ulong (*))(__fp - 0x9e0)) = (*(ulong (*))(__fp - 0x9e0)) + (long)(*(int (*))(__fp - 0x9c4));
LAB_0013cfdb:
            (*(char *(*))(__fp - 0x9c0)) = (*(char (*) [1024])(__fp - 0x848));
            do {
              pcVar5 = strsep(&(*(char *(*))(__fp - 0x9c0)),((char *)(long)&DAT_00147506 /* "\n" */));
              if (pcVar5 == (char *)0x0) goto LAB_0013ce30;
              (*(char (*) [100])(__fp - 0x9b8))[0] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[1] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[2] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[3] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[4] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[5] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[6] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[7] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[8] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[9] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[10] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xb] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xc] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xd] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xe] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0xf] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x60] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x61] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x62] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[99] = '\0';
              (*(int (*))(__fp - 0x9c4)) = 0;
              (*(char (*) [100])(__fp - 0x9b8))[0x10] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x11] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x12] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x13] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x14] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x15] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x16] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x17] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x18] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x19] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x1f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x20] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x21] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x22] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x23] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x24] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x25] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x26] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x27] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x28] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x29] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x2f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x30] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x31] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x32] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x33] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x34] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x35] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x36] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x37] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x38] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x39] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x3f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x40] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x41] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x42] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x43] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x44] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x45] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x46] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x47] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x48] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x49] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x4f] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x50] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x51] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x52] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x53] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x54] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x55] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x56] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x57] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x58] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x59] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5a] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5b] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5c] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5d] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5e] = '\0';
              (*(char (*) [100])(__fp - 0x9b8))[0x5f] = '\0';
              iVar3 = __isoc23_sscanf(pcVar5,((char *)(long)&s__99______d_00149acc /* "%99[^:]:%d" */),(*(char (*) [100])(__fp - 0x9b8)),&(*(int (*))(__fp - 0x9c4)));
            } while ((iVar3 != 2) || (iVar3 = strcmp((*(char (*) [100])(__fp - 0x9b8)),((char *)(long)&s_remaining_capacity_00149aea /* "remaining capacity" */)), iVar3 != 0));
            (*(ulong (*))(__fp - 0x9e8)) = (*(ulong (*))(__fp - 0x9e8)) + (long)(*(int (*))(__fp - 0x9c4));
          }
        }
      }
      goto LAB_0013ce30;
    }
    closedir(__dirp);
    if ((*(ulong (*))(__fp - 0x9e0)) != 0) {
      dVar9 = ((double)(*(ulong (*))(__fp - 0x9e8)) * 100.0) / (double)(*(ulong (*))(__fp - 0x9e0));
      goto LAB_0013d120;
    }
  }
  dVar9 = NAN;
LAB_0013d120:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return dVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getBattery @ 0x13d1a0 */

void Platform_getBattery(double *percent,ACPresence *isOnAC)

{
  ACPresence AVar1;
  time_t tVar2;
  double dVar3;

  tVar2 = time((time_t *)0x0);
  AVar1 = Platform_Battery_cacheIsOnAC;
  if (tVar2 <= Platform_Battery_cacheTime + 9) {
    *percent = Platform_Battery_cachePercent;
    *isOnAC = AVar1;
    return;
  }
  if (Platform_Battery_method == CPU_METER_NICE) {
    AVar1 = procAcpiCheck();
    *isOnAC = AVar1;
    if (AVar1 == AC_ERROR) {
      *percent = NAN;
    }
    else {
      dVar3 = Platform_Battery_getProcBatInfo();
      *percent = dVar3;
      if (0.0 <= dVar3) goto LAB_0013d1df;
    }
    Platform_Battery_method = CPU_METER_NORMAL;
LAB_0013d23e:
    Platform_Battery_getSysData(percent,isOnAC);
    if (*percent < 0.0) {
      Platform_Battery_method = CPU_METER_KERNEL;
      goto LAB_0013d267;
    }
  }
  else {
LAB_0013d1df:
    if (Platform_Battery_method == CPU_METER_NORMAL) goto LAB_0013d23e;
  }
  if (Platform_Battery_method != CPU_METER_KERNEL) {
    Platform_Battery_cachePercent = *percent;
    if (Platform_Battery_cachePercent <= 100.0) {
      if (Platform_Battery_cachePercent <= 0.0) {
        Platform_Battery_cachePercent = 0.0;
      }
      Platform_Battery_cacheIsOnAC = *isOnAC;
      *percent = Platform_Battery_cachePercent;
      Platform_Battery_cacheTime = tVar2;
      return;
    }
    Platform_Battery_cacheIsOnAC = *isOnAC;
    *percent = 100.0;
    Platform_Battery_cachePercent = 100.0;
    Platform_Battery_cacheTime = tVar2;
    return;
  }
LAB_0013d267:
  *percent = NAN;
  *isOnAC = AC_ERROR;
  Platform_Battery_cacheTime = tVar2;
  Platform_Battery_cacheIsOnAC = AC_ERROR;
  Platform_Battery_cachePercent = NAN;
  return;
}


/* Platform_actionHigherAutogroupPriority @ 0x13dd80 */

Htop_Reaction Platform_actionHigherAutogroupPriority(State_2 *st)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  byte bVar1;
  long lVar2;
  MainPanel__2 *pMVar3;
  _Bool _Var4;
  int fd;
  Htop_Reaction HVar5;
  ssize_t sVar6;
  Vector *pVVar7;
  int *piVar8;
  long lVar9;
  byte bVar10;
  byte bVar11;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  HVar5 = HTOP_OK;
  if (readonly) goto LAB_0013ddb1;
  pMVar3 = st->mainPanel;
                    /* Unresolved local var: _Bool changed@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: int fd@[???] */
  fd = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar8 = __errno_location();
    if (-1 < -*piVar8) goto LAB_0013de0b;
  }
  else {
    sVar6 = readfd_internal(fd,(*(char (*) [16])(__fp - 0x58)),0x10);
    if (-1 < sVar6) {
LAB_0013de0b:
      if ((*(char (*) [16])(__fp - 0x58))[0] == '1') {
                    /* Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: int i@[???] */
        pVVar7 = (pMVar3->super).items;
        if (pVVar7->items < 1) {
          HVar5 = HTOP_OK;
        }
        else {
          lVar9 = 0;
          bVar11 = 1;
          bVar10 = 0;
          do {
                    /* Unresolved local var: Row * row@[???] */
            bVar1 = *(byte *)((long)&pVVar7->array[lVar9][3].klass + 5);
            if (bVar1 != 0) {
                    /* Unresolved local var: Process * p@[???] */
              _Var4 = LinuxProcess_changeAutogroupPriorityBy
                                ((Process_3 *)(ulong)*(uint *)&pVVar7->array[lVar9][2].klass,
                                 ((Arg){.i = (int)0xffffffff}));
              bVar11 = bVar11 & _Var4;
              pVVar7 = (pMVar3->super).items;
              bVar10 = bVar1;
            }
            lVar9 = lVar9 + 1;
          } while ((int)lVar9 < pVVar7->items);
                    /* Unresolved local var: Row * row@[???] */
          if (((bVar10 != 1) && (0 < pVVar7->items)) &&
             (pVVar7->array[(pMVar3->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
            _Var4 = LinuxProcess_changeAutogroupPriorityBy
                              ((Process_3 *)
                               (ulong)*(uint *)&pVVar7->array[(pMVar3->super).selected][2].klass,
                               ((Arg){.i = (int)0xffffffff}));
            bVar11 = bVar11 & _Var4;
          }
          if (bVar11 == 0) {
            beep();
            HVar5 = (Htop_Reaction)bVar10;
          }
          else {
            HVar5 = (Htop_Reaction)bVar10;
          }
        }
        goto LAB_0013ddb1;
      }
    }
  }
  beep();
  HVar5 = HTOP_OK;
LAB_0013ddb1:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_actionLowerAutogroupPriority @ 0x13dee0 */

Htop_Reaction Platform_actionLowerAutogroupPriority(State_2 *st)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  byte bVar1;
  long lVar2;
  MainPanel__2 *pMVar3;
  _Bool _Var4;
  int fd;
  Htop_Reaction HVar5;
  ssize_t sVar6;
  Vector *pVVar7;
  int *piVar8;
  long lVar9;
  byte bVar10;
  byte bVar11;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  HVar5 = HTOP_OK;
  if (readonly) goto LAB_0013df11;
  pMVar3 = st->mainPanel;
                    /* Unresolved local var: _Bool changed@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: int fd@[???] */
  fd = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar8 = __errno_location();
    if (-1 < -*piVar8) goto LAB_0013df6b;
  }
  else {
    sVar6 = readfd_internal(fd,(*(char (*) [16])(__fp - 0x58)),0x10);
    if (-1 < sVar6) {
LAB_0013df6b:
      if ((*(char (*) [16])(__fp - 0x58))[0] == '1') {
                    /* Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: int i@[???] */
        pVVar7 = (pMVar3->super).items;
        if (pVVar7->items < 1) {
          HVar5 = HTOP_OK;
        }
        else {
          lVar9 = 0;
          bVar11 = 1;
          bVar10 = 0;
          do {
                    /* Unresolved local var: Row * row@[???] */
            bVar1 = *(byte *)((long)&pVVar7->array[lVar9][3].klass + 5);
            if (bVar1 != 0) {
                    /* Unresolved local var: Process * p@[???] */
              _Var4 = LinuxProcess_changeAutogroupPriorityBy
                                ((Process_3 *)(ulong)*(uint *)&pVVar7->array[lVar9][2].klass,
                                 ((Arg){.i = (int)0x1}));
              bVar11 = bVar11 & _Var4;
              pVVar7 = (pMVar3->super).items;
              bVar10 = bVar1;
            }
            lVar9 = lVar9 + 1;
          } while ((int)lVar9 < pVVar7->items);
                    /* Unresolved local var: Row * row@[???] */
          if (((bVar10 != 1) && (0 < pVVar7->items)) &&
             (pVVar7->array[(pMVar3->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
            _Var4 = LinuxProcess_changeAutogroupPriorityBy
                              ((Process_3 *)
                               (ulong)*(uint *)&pVVar7->array[(pMVar3->super).selected][2].klass,
                               ((Arg){.i = (int)0x1}));
            bVar11 = bVar11 & _Var4;
          }
          if (bVar11 == 0) {
            beep();
            HVar5 = (Htop_Reaction)bVar10;
          }
          else {
            HVar5 = (Htop_Reaction)bVar10;
          }
        }
        goto LAB_0013df11;
      }
    }
  }
  beep();
  HVar5 = HTOP_OK;
LAB_0013df11:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getProcessEnv @ 0x13f480 */

char * Platform_getProcessEnv(pid_t pid)

{
  undefined1 __frame[0x158] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x118;
  long lVar1;
  FILE_2 *__stream;
  void *__ptr;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  void *__ptr_00;
  ulong __size;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf((*(char (*) [128])(__fp - 0xc8)),0x80,((char *)(long)&s__proc__d_environ_00149be4 /* "/proc/%d/environ" */),pid);
  __stream = fopen((*(char (*) [128])(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    uVar2 = 0;
    uVar4 = 0;
    __size = 0;
    __ptr_00 = (void *)0x0;
    do {
      __size = __size + 0x1000;
                    /* Unresolved local var: void * data@[???] */
      uVar4 = uVar4 + uVar2;
      __ptr = realloc(__ptr_00,__size);
      if (__ptr == (void *)0x0) {
        free(__ptr_00);
                    /* WARNING: Subroutine does not return */
        fail();
      }
                    /* Unresolved local var: size_t sz@[???] */
      uVar2 = __size;
      if (__size <= uVar4) {
        uVar2 = uVar4;
      }
      uVar2 = __fread_chk((void *)((long)__ptr + uVar4),uVar2 - uVar4,1,__size - uVar4,__stream);
      __ptr_00 = __ptr;
    } while (0 < (long)uVar2);
    fclose(__stream);
    if (uVar2 == 0) {
                    /* Unresolved local var: void * data@[???] */
      pcVar3 = realloc(__ptr,uVar4 + 2);
      if (pcVar3 == (char *)0x0) {
        free(__ptr);
                    /* WARNING: Subroutine does not return */
        fail();
      }
      (pcVar3 + uVar4)[0] = '\0';
      (pcVar3 + uVar4)[1] = '\0';
      goto LAB_0013f564;
    }
    free(__ptr);
  }
  pcVar3 = (char *)0x0;
LAB_0013f564:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Platform_getProcessLocks @ 0x13f5c0 */

FileLocks_ProcessData * Platform_getProcessLocks(pid_t pid)

{
  undefined1 __frame[0x25d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2598;
  char *p0;
  long lVar1;
  undefined16 auVar2;
  int __fd;
  int iVar3;
  FileLocks_ProcessData *pFVar4;
  size_t sVar5;
  DIR_2 *__dirp;
  dirent *pdVar6;
  int *piVar7;
  ulong uVar8;
  FILE_2 *__stream;
  char *pcVar9;
  ulong uVar10;
  FileLocks_LockData_ *pFVar11;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * (*(FileLocks_Data (*))(__fp - 0x2518))@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pFVar4 = calloc(1,0x10);
  if (pFVar4 == (FileLocks_ProcessData *)0x0) {
LAB_0013fa8d:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  xSnprintf((*(char (*) [4096])(__fp - 0x2048)),0x1000,((char *)(long)&s__proc__d_fdinfo__00149bf5 /* "/proc/%d/fdinfo/" */),pid);
  sVar5 = strlen((*(char (*) [4096])(__fp - 0x2048)));
  if ((sVar5 < 0xffe) && (__dirp = opendir((*(char (*) [4096])(__fp - 0x2048))), __dirp != (DIR_2 *)0x0)) {
    __fd = dirfd(__dirp);
    (*(FileLocks_LockData_ **(*))(__fp - 0x2550)) = &pFVar4->locks;
                    /* Unresolved local var: dirent * de@[???]
                       Unresolved local var: int file@[???]
                       Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * f@[???] */
    if (__fd != -1) {
      while (pdVar6 = readdir(__dirp), pdVar6 != (dirent *)0x0) {
        p0 = pdVar6->d_name;
        if (((pdVar6->d_name[0] != '.') || (pdVar6->d_name[1] != '\0')) &&
           ((pdVar6->d_name[0] != '.' || ((pdVar6->d_name[1] != '.' || (pdVar6->d_name[2] != '\0')))
            ))) {
          piVar7 = __errno_location();
          *piVar7 = 0;
          (*(char *(*))(__fp - 0x2520)) = p0;
          uVar8 = __isoc23_strtoull(p0,&(*(char *(*))(__fp - 0x2520)),10);
          if ((*piVar7 == 0) && ((*(*(char *(*))(__fp - 0x2520)) == '\0' && (iVar3 = openat(__fd,p0,0x80000), iVar3 != -1))))
          {
            __stream = fdopen(iVar3,((char *)(long)&DAT_00147760 /* "r" */));
            if (__stream == (FILE_2 *)0x0) {
              close(iVar3);
            }
            else {
                    /* Unresolved local var: size_t sz@[???] */
              while (pcVar9 = fgets((*(char (*) [1024])(__fp - 0x2448)),0x400,__stream), pcVar9 != (char *)0x0) {
                    /* Unresolved local var: ssize_t link_len@[???] */
                pcVar9 = strchr((*(char (*) [1024])(__fp - 0x2448)),10);
                if (((pcVar9 != (char *)0x0) && ((*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x2448)) + 0)) == 0x6b636f6c)) &&
                   ((*(ushort *)((char *)&(*(char (*) [1024])(__fp - 0x2448)) + 4)) == 0x93a)) {
                  (*(ulong *)((char *)&(*(FileLocks_Data (*))(__fp - 0x2518)) + 36)) = SUB1612((undefined16)0x0,4);
                  (*(FileLocks_Data (*))(__fp - 0x2518)).fd = (int)uVar8;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).end = 0;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).locktype = (char *)0x0;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).exclusive = (char *)0x0;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).readwrite = (char *)0x0;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).filename = (char *)0x0;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).inode = 0;
                  (*(FileLocks_Data (*))(__fp - 0x2518)).start = 0;
                  iVar3 = __isoc23_sscanf((*(char (*) [1024])(__fp - 0x2448)) + 6,((char *)(long)&s__d___31s__31s__31s__d__x__x__lu___0014cb58 /* "%d: %31s %31s %31s %d %x:%x:%lu %lu %24s" */),&(*(int (*))(__fp - 0x2524)),
                                          (*(char (*) [32])(__fp - 0x2468)),(*(char (*) [32])(__fp - 0x2488)),(*(char (*) [32])(__fp - 0x24a8)),&(*(int (*))(__fp - 0x2524)),&(*(uint (*))(__fp - 0x2528)),&(*(uint (*))(__fp - 0x252c)),&(*(FileLocks_Data (*))(__fp - 0x2518)).inode,
                                          &(*(FileLocks_Data (*))(__fp - 0x2518)).start,(*(char (*) [25])(__fp - 0x24c8)));
                  if (iVar3 == 10) {
                    /* Unresolved local var: char * (*(FileLocks_Data (*))(__fp - 0x2518))@[???] */
                    pcVar9 = strdup((*(char (*) [32])(__fp - 0x2468)));
                    if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                    /* Unresolved local var: char * (*(FileLocks_Data (*))(__fp - 0x2518))@[???] */
                    (*(FileLocks_Data (*))(__fp - 0x2518)).locktype = pcVar9;
                    pcVar9 = strdup((*(char (*) [32])(__fp - 0x2488)));
                    if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                    /* Unresolved local var: char * (*(FileLocks_Data (*))(__fp - 0x2518))@[???] */
                    (*(FileLocks_Data (*))(__fp - 0x2518)).exclusive = pcVar9;
                    pcVar9 = strdup((*(char (*) [32])(__fp - 0x24a8)));
                    if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                    /* Unresolved local var: __dev_t __dev@[???] */
                    (*(FileLocks_Data (*))(__fp - 0x2518)).readwrite = pcVar9;
                    (*(FileLocks_Data (*))(__fp - 0x2518)).dev = ((ulong)(*(uint (*))(__fp - 0x252c)) & 0xffffff00) << 0xc |
                               ((ulong)(*(uint (*))(__fp - 0x2528)) & 0xfffff000) << 0x20 | (ulong)(((*(uint (*))(__fp - 0x2528)) & 0xfff) << 8) |
                               (ulong)(byte)(*(uint (*))(__fp - 0x252c));
                    uVar10 = 0xffffffffffffffff;
                    if ((*(uint *)((char *)&(*(char (*) [25])(__fp - 0x24c8)) + 0)) != 0x464f45) {
                      uVar10 = __isoc23_strtoull((*(char (*) [25])(__fp - 0x24c8)),(char **)0x0,10);
                    }
                    (*(FileLocks_Data (*))(__fp - 0x2518)).end = uVar10;
                    xSnprintf((*(char (*) [4096])(__fp - 0x2048)),0x1000,((char *)(long)&s__proc__d_fd__s_00149c11 /* "/proc/%d/fd/%s" */),pid,p0);
                    sVar5 = strlen((*(char (*) [4096])(__fp - 0x2048)));
                    if (sVar5 < 0xffe) {
                      sVar5 = readlink((*(char (*) [4096])(__fp - 0x2048)),(*(char (*) [4096])(__fp - 0x1048)),0x1000);
                      if (sVar5 != 0xffffffffffffffff) {
                    /* Unresolved local var: char * (*(FileLocks_Data (*))(__fp - 0x2518))@[???] */
                        pcVar9 = strndup((*(char (*) [4096])(__fp - 0x1048)),sVar5);
                        if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                        (*(FileLocks_Data (*))(__fp - 0x2518)).filename = pcVar9;
                      }
                    }
                    /* Unresolved local var: void * (*(FileLocks_Data (*))(__fp - 0x2518))@[???] */
                    pFVar11 = calloc(1,0x50);
                    auVar2 = (undefined16)(*(undefined16 *)((char *)&(*(FileLocks_Data (*))(__fp - 0x2518)) + 32));
                    if (pFVar11 == (FileLocks_LockData_ *)0x0) goto LAB_0013fa8d;
                    *(*(FileLocks_LockData_ **(*))(__fp - 0x2550)) = pFVar11;
                    (*(FileLocks_LockData_ **(*))(__fp - 0x2550)) = &pFVar11->next;
                    (pFVar11->data).locktype = (*(FileLocks_Data (*))(__fp - 0x2518)).locktype;
                    (pFVar11->data).exclusive = (*(FileLocks_Data (*))(__fp - 0x2518)).exclusive;
                    (pFVar11->data).readwrite = (*(FileLocks_Data (*))(__fp - 0x2518)).readwrite;
                    (pFVar11->data).filename = (*(FileLocks_Data (*))(__fp - 0x2518)).filename;
                    (pFVar11->data).fd = (*(FileLocks_Data (*))(__fp - 0x2518)).fd;
                    (pFVar11->data).field_0x24 = (*(FileLocks_Data (*))(__fp - 0x2518)).field_0x24;
                    (pFVar11->data).field_0x25 = (*(FileLocks_Data (*))(__fp - 0x2518)).field_0x25;
                    (pFVar11->data).field_0x26 = (*(FileLocks_Data (*))(__fp - 0x2518)).field_0x26;
                    (pFVar11->data).field_0x27 = (*(FileLocks_Data (*))(__fp - 0x2518)).field_0x27;
                    (pFVar11->data).dev = (*(FileLocks_Data (*))(__fp - 0x2518)).dev;
                    (pFVar11->data).inode = (*(FileLocks_Data (*))(__fp - 0x2518)).inode;
                    (pFVar11->data).start = (*(FileLocks_Data (*))(__fp - 0x2518)).start;
                    (pFVar11->data).end = (*(FileLocks_Data (*))(__fp - 0x2518)).end;
                    (*(undefined16 *)((char *)&(*(FileLocks_Data (*))(__fp - 0x2518)) + 32)) = auVar2;
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
  pFVar4->error = true;
LAB_0013f656:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pFVar4;
}


/* Platform_actionSetIOPriority @ 0x1443c0 */

Htop_Reaction Platform_actionSetIOPriority(State_2 *st)

{
  char cVar1;
  MainPanel__2 *pMVar2;
  bool bVar3;
  MainPanel_ *list;
  Object *pOVar4;
  long lVar5;
  Vector *pVVar6;
  long lVar7;
  char cVar8;
  uint uVar9;

  cVar8 = readonly;
  if (!readonly) {
    pVVar6 = (st->mainPanel->super).items;
    if ((0 < pVVar6->items) &&
       (pOVar4 = pVVar6->array[(st->mainPanel->super).selected], pOVar4 != (Object *)0x0)) {
      list = (MainPanel_ *)IOPriorityPanel_new(*(IOPriority *)&pOVar4[0x3d].klass);
      pOVar4 = Action_pickFromVector(st,list,20,true);
      if (pOVar4 != (Object *)0x0) {
                    /* Unresolved local var: IOPriority ioprio2@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: ListItem * selected@[???] */
        pVVar6 = (list->super).items;
        uVar9 = 0;
        if ((0 < pVVar6->items) &&
           (pOVar4 = pVVar6->array[(list->super).selected], uVar9 = 0, pOVar4 != (Object *)0x0)) {
          uVar9 = *(uint *)&pOVar4[2].klass;
        }
        pMVar2 = st->mainPanel;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: int i@[???] */
        pVVar6 = (pMVar2->super).items;
        if (0 < pVVar6->items) {
          lVar7 = 0;
          bVar3 = true;
          do {
                    /* Unresolved local var: Row * row@[???] */
            pOVar4 = pVVar6->array[lVar7];
            cVar1 = *(char *)((long)&pOVar4[3].klass + 5);
            if (cVar1 != '\0') {
                    /* Unresolved local var: Process * p@[???] */
              syscall(0xfb,1,(ulong)*(uint *)&pOVar4[2].klass,(ulong)uVar9);
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
              lVar5 = syscall(0xfc,1,(ulong)*(uint *)&pOVar4[2].klass);
              *(uint *)&pOVar4[0x3d].klass = (uint)lVar5;
              bVar3 = (bool)(bVar3 & uVar9 == (uint)lVar5);
              pVVar6 = (pMVar2->super).items;
              cVar8 = cVar1;
            }
            lVar7 = lVar7 + 1;
          } while ((int)lVar7 < pVVar6->items);
                    /* Unresolved local var: Row * row@[???] */
          if (((cVar8 != '\x01') && (0 < pVVar6->items)) &&
             (pOVar4 = pVVar6->array[(pMVar2->super).selected], pOVar4 != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
            syscall(0xfb,1,(ulong)*(uint *)&pOVar4[2].klass,(ulong)uVar9);
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
            lVar7 = syscall(0xfc,1,(ulong)*(uint *)&pOVar4[2].klass);
            *(uint *)&pOVar4[0x3d].klass = (uint)lVar7;
            bVar3 = (bool)(bVar3 & uVar9 == (uint)lVar7);
          }
          if (!bVar3) {
            beep();
          }
        }
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
      free((list->super).eventHandlerState);
      Vector_delete((list->super).items);
      FunctionBar_delete((list->super).defaultBar);
      if (350 < (list->super).header.chlen) {
        free((list->super).header.chptr);
      }
      free(list);
      return 0x61;
    }
  }
  return HTOP_OK;
}

