/* Platform_Battery_getSysData @ 0013a5e0 size 1560 */

void Platform_Battery_getSysData(double *percent,ACPresence *isOnAC)

{
  char cVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  wchar_t wVar6;
  int iVar7;
  DIR_2 *__dirp;
  dirent *pdVar8;
  long lVar9;
  char *pcVar10;
  ssize_t sVar11;
  int *piVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  double dVar14;
  ulong local_4e8;
  double local_4e0;
  double local_4d8;
  wchar_t val;
  char *buf;
  char field [100];
  char cStack_449;
  char buffer [1024];

                    /* Unresolved local var: DIR * dir@[???]
                       Unresolved local var: uint64_t totalFull@[???]
                       Unresolved local var: uint64_t totalRemain@[???]
                       Unresolved local var: dirent * dirEntry@[???] */
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  *percent = NAN;
  *isOnAC = AC_ERROR;
  __dirp = opendir(((char *)0x1498a0 /* "/sys/class/power_supply" */));
  if (__dirp == (DIR_2 *)0x0) {
LAB_0013a8a4:
    if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar13 = 0;
  local_4e8 = 0;
  do {
    pdVar8 = readdir(__dirp);
    while( true ) {
      if (pdVar8 == (dirent *)0x0) {
        closedir(__dirp);
        dVar14 = NAN;
        if (uVar13 != 0) {
          dVar14 = ((double)local_4e8 * 100.0) / (double)uVar13;
        }
        *percent = dVar14;
        goto LAB_0013a8a4;
      }
                    /* Unresolved local var: char * entryName@[???]
                       Unresolved local var: wchar_t entryFd@[???]
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
                       Unresolved local var: wchar_t fd@[???] */
        wVar6 = openat(iVar5,((char *)0x1498c3 /* "uevent" */),0);
        if (wVar6 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
          piVar12 = __errno_location();
          lVar9 = (long)-*piVar12;
        }
        else {
          lVar9 = readfd_internal(wVar6,buffer,0x400);
        }
        if (-1 < lVar9) {
          buf = buffer;
          bVar3 = false;
          local_4d8 = 0.0;
          local_4e0 = NAN;
          bVar4 = false;
          while (pcVar10 = strsep(&buf,((char *)0x147506 /* "\n" */)), pcVar10 != (char *)0x0) {
            field[0x60] = '\0';
            field[0x61] = '\0';
            field[0x62] = '\0';
            field[99] = '\0';
            val = L'\0';
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
            iVar7 = __isoc23_sscanf(pcVar10,((char *)0x1498ca /* "POWER_SUPPLY_%99[^=]=%d" */),field,&val);
            if (iVar7 == 2) {
              iVar7 = strcmp(field,((char *)0x1498e2 /* "CAPACITY" */));
              if (iVar7 == 0) {
                local_4e0 = (double)val / 100.0;
              }
              else {
                iVar7 = strcmp(field,((char *)0x1498eb /* "ENERGY_FULL" */));
                if ((iVar7 == 0) || (iVar7 = strcmp(field,((char *)0x1498f7 /* "CHARGE_FULL" */)), iVar7 == 0)) {
                  local_4d8 = (double)val;
                  dVar14 = (double)uVar13 + local_4d8;
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
                  iVar7 = strcmp(field,((char *)0x149903 /* "ENERGY_NOW" */));
                  if ((iVar7 == 0) || (iVar7 = strcmp(field,((char *)0x14990e /* "CHARGE_NOW" */)), iVar7 == 0)) {
                    local_4e8 = local_4e8 + (long)val;
                    if (bVar4) goto LAB_0013a830;
                    bVar3 = true;
                  }
                }
              }
            }
          }
          if (((!bVar3) && (bVar4)) && (0.0 <= local_4e0)) {
            dVar14 = local_4d8 * local_4e0 + (double)local_4e8;
            if (9.223372036854776e+18 <= dVar14) {
              local_4e8 = (long)(dVar14 - 9.223372036854776e+18) ^ 0x8000000000000000;
            }
            else {
              local_4e8 = (ulong)dVar14;
            }
          }
        }
      }
      else if ((pdVar8->d_name[0] == 'A') && (pdVar8->d_name[1] == 'C')) {
LAB_0013a97b:
                    /* Unresolved local var: ssize_t r@[???] */
        if (*isOnAC == AC_ERROR) {
                    /* Unresolved local var: wchar_t fd@[???] */
          wVar6 = openat(iVar5,((char *)0x149919 /* "online" */),0);
          if (wVar6 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
            piVar12 = __errno_location();
            if (-*piVar12 < 1) goto LAB_0013ab14;
          }
          else {
            sVar11 = readfd_internal(wVar6,buffer,2);
            if (sVar11 < 1) {
LAB_0013ab14:
              *isOnAC = AC_ERROR;
              goto LAB_0013a830;
            }
          }
          if (buffer[0] == '0') {
            *isOnAC = AC_ABSENT;
          }
          else if (buffer[0] == '1') {
            *isOnAC = AC_PRESENT;
          }
        }
      }
      else {
                    /* Unresolved local var: ssize_t ret@[???]
                       Unresolved local var: wchar_t fd@[???] */
        wVar6 = openat(iVar5,((char *)0x1498b8 /* "type" */),0);
        if (wVar6 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
          piVar12 = __errno_location();
          lVar9 = (long)-*piVar12;
        }
        else {
          lVar9 = readfd_internal(wVar6,buffer,0x20);
        }
        if (0 < lVar9) {
          pcVar10 = buffer + lVar9 + -1;
                    /* Unresolved local var: char * buf@[???] */
          cVar1 = buffer[lVar9 + -1];
          while (cVar1 == '\n') {
            *pcVar10 = '\0';
            pcVar10 = pcVar10 + -1;
            cVar1 = *pcVar10;
          }
          if (CONCAT26(buffer._6_2_,CONCAT24(buffer._4_2_,buffer._0_4_)) == 0x79726574746142)
          goto LAB_0013a6a2;
          if ((buffer._0_4_ == 0x6e69614d) && (buffer._4_2_ == 0x73)) goto LAB_0013a97b;
        }
      }
LAB_0013a830:
      close(iVar5);
      pdVar8 = readdir(__dirp);
    }
  } while( true );
}

