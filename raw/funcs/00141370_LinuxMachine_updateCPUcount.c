/* LinuxMachine_updateCPUcount @ 00141370 size 615 */

/* DWARF original prototype: void LinuxMachine_updateCPUcount(LinuxMachine * this) */

void LinuxMachine_updateCPUcount(LinuxMachine *this)

{
  long lVar1;
  _Bool _Var2;
  int iVar3;
  uint uVar4;
  wchar_t fd;
  DIR_2 *__dirp;
  dirent *pdVar5;
  ulong uVar6;
  ulong uVar8;
  CPUData *pCVar9;
  long lVar10;
  int *piVar11;
  size_t prevmemb;
  uint uVar12;
  long in_FS_OFFSET;
  uint local_70;
  uint local_6c;
  char *endp;
  char buffer [8];
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
  __dirp = opendir(((char *)0x149e4d /* "/sys/devices/system/cpu" */));
  if (__dirp != (DIR_2 *)0x0) {
    local_6c = (this->super).existingCPUs;
    local_70 = 0;
    uVar7 = 0;
                    /* Unresolved local var: ulong id@[???]
                       Unresolved local var: wchar_t cpuDirFd@[???]
                       Unresolved local var: uint max@[???]
                       Unresolved local var: ssize_t res@[???] */
LAB_001413d8:
    uVar4 = (uint)uVar7;
    pdVar5 = readdir(__dirp);
    if (pdVar5 != (dirent *)0x0) {
      while (((((pdVar5->d_type & 0xfb) == 0 && (pdVar5->d_name[0] == 'c')) &&
              (pdVar5->d_name[1] == 'p')) && (pdVar5->d_name[2] == 'u'))) {
        uVar6 = __isoc23_strtoul(pdVar5->d_name + 3,&endp,10);
        if (((uVar6 == 0xffffffffffffffff) || (pdVar5->d_name + 3 == endp)) || (*endp != '\0'))
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
        if (local_6c < uVar12) {
          prevmemb = (size_t)(local_6c + 1);
          if (local_6c == 0) {
            prevmemb = 0;
          }
          pCVar9 = xReallocArrayZero(this->cpuData,prevmemb,(ulong)(uVar12 + 1),0xd8);
          this->cpuData = pCVar9;
          pCVar9->online = true;
          local_6c = uVar12;
        }
                    /* Unresolved local var: wchar_t fd@[???] */
        fd = openat(iVar3,((char *)0x149919 /* "online" */),0);
        if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
          piVar11 = __errno_location();
          lVar10 = (long)-*piVar11;
        }
        else {
          lVar10 = readfd_internal(fd,buffer,8);
        }
        if ((lVar10 < 1) || (_Var2 = false, buffer[0] != '0')) {
          local_70 = local_70 + 1;
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
      if ((uVar4 != 0) && (((this->super).activeCPUs < local_70 || (uVar4 < local_6c)))) {
        LibSensors_reload();
      }
      (this->super).activeCPUs = local_70;
      (this->super).existingCPUs = local_6c;
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

