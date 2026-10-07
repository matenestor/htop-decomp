/* Platform_Battery_getProcBatInfo @ 0013cdd0 size 943 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double Platform_Battery_getProcBatInfo(void)

{
  long lVar1;
  wchar_t wVar2;
  int iVar3;
  DIR_2 *__dirp;
  dirent *pdVar4;
  char *pcVar5;
  int *piVar6;
  long lVar7;
  long in_FS_OFFSET;
  byte bVar8;
  double dVar9;
  ulong local_9e8;
  ulong local_9e0;
  wchar_t val;
  char *buf;
  char field [100];
  char filePath [256];
  char bufState [1024];
  char bufInfo [1024];

                    /* Unresolved local var: DIR * batteryDir@[???]
                       Unresolved local var: uint64_t totalFull@[???]
                       Unresolved local var: uint64_t totalRemain@[???]
                       Unresolved local var: dirent * dirEntry@[???] */
  bVar8 = 0;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __dirp = opendir(((char *)0x149aa2 /* "/proc/acpi/battery" */));
  if (__dirp != (DIR_2 *)0x0) {
    local_9e8 = 0;
                    /* Unresolved local var: char * entryName@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: char * line@[???] */
    local_9e0 = 0;
LAB_0013ce30:
    pdVar4 = readdir(__dirp);
    if (pdVar4 != (dirent *)0x0) {
      if (((pdVar4->d_name[0] == 'B') && (pdVar4->d_name[1] == 'A')) && (pdVar4->d_name[2] == 'T'))
      {
        pcVar5 = bufInfo;
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
        xSnprintf(filePath,0x100,((char *)0x149ab5 /* "%s/%s/info" */),((char *)0x149aa2 /* "/proc/acpi/battery" */),pdVar4->d_name);
                    /* Unresolved local var: wchar_t fd@[???] */
        wVar2 = open(filePath,0);
        if (wVar2 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
          piVar6 = __errno_location();
          lVar7 = (long)-*piVar6;
        }
        else {
          lVar7 = readfd_internal(wVar2,bufInfo,0x400);
        }
        if (-1 < lVar7) {
          pcVar5 = bufState;
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
          xSnprintf(filePath,0x100,((char *)0x149ac0 /* "%s/%s/state" */),((char *)0x149aa2 /* "/proc/acpi/battery" */),pdVar4->d_name);
                    /* Unresolved local var: wchar_t fd@[???] */
          wVar2 = open(filePath,0);
          if (wVar2 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
            piVar6 = __errno_location();
            lVar7 = (long)-*piVar6;
          }
          else {
            lVar7 = readfd_internal(wVar2,bufState,0x400);
          }
          if (-1 < lVar7) {
            buf = bufInfo;
            do {
              pcVar5 = strsep(&buf,((char *)0x147506 /* "\n" */));
              if (pcVar5 == (char *)0x0) goto LAB_0013cfdb;
              field[0] = '\0';
              field[1] = '\0';
              field[2] = '\0';
              field[3] = '\0';
              field[4] = '\0';
              field[5] = '\0';
              field[6] = '\0';
              field[7] = '\0';
              field[8] = '\0';
              field[9] = '\0';
              field[10] = '\0';
              field[0xb] = '\0';
              field[0xc] = '\0';
              field[0xd] = '\0';
              field[0xe] = '\0';
              field[0xf] = '\0';
              field[0x60] = '\0';
              field[0x61] = '\0';
              field[0x62] = '\0';
              field[99] = '\0';
              val = L'\0';
              field[0x10] = '\0';
              field[0x11] = '\0';
              field[0x12] = '\0';
              field[0x13] = '\0';
              field[0x14] = '\0';
              field[0x15] = '\0';
              field[0x16] = '\0';
              field[0x17] = '\0';
              field[0x18] = '\0';
              field[0x19] = '\0';
              field[0x1a] = '\0';
              field[0x1b] = '\0';
              field[0x1c] = '\0';
              field[0x1d] = '\0';
              field[0x1e] = '\0';
              field[0x1f] = '\0';
              field[0x20] = '\0';
              field[0x21] = '\0';
              field[0x22] = '\0';
              field[0x23] = '\0';
              field[0x24] = '\0';
              field[0x25] = '\0';
              field[0x26] = '\0';
              field[0x27] = '\0';
              field[0x28] = '\0';
              field[0x29] = '\0';
              field[0x2a] = '\0';
              field[0x2b] = '\0';
              field[0x2c] = '\0';
              field[0x2d] = '\0';
              field[0x2e] = '\0';
              field[0x2f] = '\0';
              field[0x30] = '\0';
              field[0x31] = '\0';
              field[0x32] = '\0';
              field[0x33] = '\0';
              field[0x34] = '\0';
              field[0x35] = '\0';
              field[0x36] = '\0';
              field[0x37] = '\0';
              field[0x38] = '\0';
              field[0x39] = '\0';
              field[0x3a] = '\0';
              field[0x3b] = '\0';
              field[0x3c] = '\0';
              field[0x3d] = '\0';
              field[0x3e] = '\0';
              field[0x3f] = '\0';
              field[0x40] = '\0';
              field[0x41] = '\0';
              field[0x42] = '\0';
              field[0x43] = '\0';
              field[0x44] = '\0';
              field[0x45] = '\0';
              field[0x46] = '\0';
              field[0x47] = '\0';
              field[0x48] = '\0';
              field[0x49] = '\0';
              field[0x4a] = '\0';
              field[0x4b] = '\0';
              field[0x4c] = '\0';
              field[0x4d] = '\0';
              field[0x4e] = '\0';
              field[0x4f] = '\0';
              field[0x50] = '\0';
              field[0x51] = '\0';
              field[0x52] = '\0';
              field[0x53] = '\0';
              field[0x54] = '\0';
              field[0x55] = '\0';
              field[0x56] = '\0';
              field[0x57] = '\0';
              field[0x58] = '\0';
              field[0x59] = '\0';
              field[0x5a] = '\0';
              field[0x5b] = '\0';
              field[0x5c] = '\0';
              field[0x5d] = '\0';
              field[0x5e] = '\0';
              field[0x5f] = '\0';
              iVar3 = __isoc23_sscanf(pcVar5,((char *)0x149acc /* "%99[^:]:%d" */),field,&val);
            } while ((iVar3 != 2) || (iVar3 = strcmp(field,((char *)0x149ad7 /* "last full capacity" */)), iVar3 != 0));
            local_9e0 = local_9e0 + (long)val;
LAB_0013cfdb:
            buf = bufState;
            do {
              pcVar5 = strsep(&buf,((char *)0x147506 /* "\n" */));
              if (pcVar5 == (char *)0x0) goto LAB_0013ce30;
              field[0] = '\0';
              field[1] = '\0';
              field[2] = '\0';
              field[3] = '\0';
              field[4] = '\0';
              field[5] = '\0';
              field[6] = '\0';
              field[7] = '\0';
              field[8] = '\0';
              field[9] = '\0';
              field[10] = '\0';
              field[0xb] = '\0';
              field[0xc] = '\0';
              field[0xd] = '\0';
              field[0xe] = '\0';
              field[0xf] = '\0';
              field[0x60] = '\0';
              field[0x61] = '\0';
              field[0x62] = '\0';
              field[99] = '\0';
              val = L'\0';
              field[0x10] = '\0';
              field[0x11] = '\0';
              field[0x12] = '\0';
              field[0x13] = '\0';
              field[0x14] = '\0';
              field[0x15] = '\0';
              field[0x16] = '\0';
              field[0x17] = '\0';
              field[0x18] = '\0';
              field[0x19] = '\0';
              field[0x1a] = '\0';
              field[0x1b] = '\0';
              field[0x1c] = '\0';
              field[0x1d] = '\0';
              field[0x1e] = '\0';
              field[0x1f] = '\0';
              field[0x20] = '\0';
              field[0x21] = '\0';
              field[0x22] = '\0';
              field[0x23] = '\0';
              field[0x24] = '\0';
              field[0x25] = '\0';
              field[0x26] = '\0';
              field[0x27] = '\0';
              field[0x28] = '\0';
              field[0x29] = '\0';
              field[0x2a] = '\0';
              field[0x2b] = '\0';
              field[0x2c] = '\0';
              field[0x2d] = '\0';
              field[0x2e] = '\0';
              field[0x2f] = '\0';
              field[0x30] = '\0';
              field[0x31] = '\0';
              field[0x32] = '\0';
              field[0x33] = '\0';
              field[0x34] = '\0';
              field[0x35] = '\0';
              field[0x36] = '\0';
              field[0x37] = '\0';
              field[0x38] = '\0';
              field[0x39] = '\0';
              field[0x3a] = '\0';
              field[0x3b] = '\0';
              field[0x3c] = '\0';
              field[0x3d] = '\0';
              field[0x3e] = '\0';
              field[0x3f] = '\0';
              field[0x40] = '\0';
              field[0x41] = '\0';
              field[0x42] = '\0';
              field[0x43] = '\0';
              field[0x44] = '\0';
              field[0x45] = '\0';
              field[0x46] = '\0';
              field[0x47] = '\0';
              field[0x48] = '\0';
              field[0x49] = '\0';
              field[0x4a] = '\0';
              field[0x4b] = '\0';
              field[0x4c] = '\0';
              field[0x4d] = '\0';
              field[0x4e] = '\0';
              field[0x4f] = '\0';
              field[0x50] = '\0';
              field[0x51] = '\0';
              field[0x52] = '\0';
              field[0x53] = '\0';
              field[0x54] = '\0';
              field[0x55] = '\0';
              field[0x56] = '\0';
              field[0x57] = '\0';
              field[0x58] = '\0';
              field[0x59] = '\0';
              field[0x5a] = '\0';
              field[0x5b] = '\0';
              field[0x5c] = '\0';
              field[0x5d] = '\0';
              field[0x5e] = '\0';
              field[0x5f] = '\0';
              iVar3 = __isoc23_sscanf(pcVar5,((char *)0x149acc /* "%99[^:]:%d" */),field,&val);
            } while ((iVar3 != 2) || (iVar3 = strcmp(field,((char *)0x149aea /* "remaining capacity" */)), iVar3 != 0));
            local_9e8 = local_9e8 + (long)val;
          }
        }
      }
      goto LAB_0013ce30;
    }
    closedir(__dirp);
    if (local_9e0 != 0) {
      dVar9 = ((double)local_9e8 * 100.0) / (double)local_9e0;
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

