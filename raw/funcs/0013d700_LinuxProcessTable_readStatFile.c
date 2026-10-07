/* LinuxProcessTable_readStatFile @ 0013d700 size 1353 */

_Bool LinuxProcessTable_readStatFile
                (LinuxProcess *lp,openat_arg_t procFd,LinuxMachine_2 *lhost,_Bool scanMainThread,
                char *command,size_t commLen)

{
  char *__s;
  char cVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  _Bool _Var5;
  wchar_t fd;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  ulong uVar10;
  int *piVar11;
  long lVar12;
  char *pcVar13;
  ProcessState PVar14;
  int iVar15;
  long in_FS_OFFSET;
  char *location;
  char path [22];
  char buf [2049];

                    /* Unresolved local var: Process * process@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: char * end@[???] */
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  path[8] = '\0';
  path[9] = '\0';
  path[10] = '\0';
  path[0xb] = '\0';
  path[0xc] = '\0';
  path[0xd] = '\0';
  builtin_strncpy(path,"stat",5);
  path[5] = '\0';
  path[6] = '\0';
  path[7] = '\0';
  path[0xe] = '\0';
  path[0xf] = '\0';
  path[0x10] = '\0';
  path[0x11] = '\0';
  path[0x12] = '\0';
  path[0x13] = '\0';
  path[0x14] = '\0';
  path[0x15] = '\0';
  if (scanMainThread) {
    xSnprintf(path,0x16,((char *)0x149b80 /* "task/%i/stat" */),(lp->super).super.id);
  }
                    /* Unresolved local var: wchar_t fd@[???] */
  fd = openat(procFd,path,0);
  if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    piVar11 = __errno_location();
    lVar6 = (long)-*piVar11;
  }
  else {
    lVar6 = readfd_internal(fd,buf,0x801);
  }
  if ((-1 < lVar6) && (pcVar7 = strchr(buf,0x20), pcVar7 != (char *)0x0)) {
    __s = pcVar7 + 2;
    location = __s;
    pcVar8 = strrchr(__s,0x29);
    if (pcVar8 != (char *)0x0) {
      pcVar13 = pcVar8 + (1 - (long)__s);
      if ((char *)0x81 < pcVar13) {
        pcVar13 = (char *)0x81;
      }
                    /* Unresolved local var: size_t i@[???] */
      pcVar9 = (char *)0x0;
      if (__s != pcVar8) {
        do {
          if (pcVar7[(long)(pcVar9 + 2)] == '\0') break;
          command[(long)pcVar9] = pcVar7[(long)(pcVar9 + 2)];
          pcVar9 = pcVar9 + 1;
        } while (pcVar9 < pcVar13 + -1);
        command = command + (long)pcVar9;
      }
      cVar1 = pcVar8[2];
      *command = '\0';
      PVar14 = UNKNOWN;
      if ((byte)(cVar1 + 0xbcU) < 0x31) {
        PVar14 = (ProcessState)(byte)(&CSWTCH_143)[(byte)(cVar1 + 0xbcU)];
      }
      (lp->super).state = PVar14;
      location = pcVar8 + 4;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).super.parent = (wchar_t)lVar6;
      location = location + 1;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).pgrp = (wchar_t)lVar6;
      location = location + 1;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).session = (wchar_t)lVar6;
      location = location + 1;
      uVar10 = __isoc23_strtoul(location,&location,10);
      (lp->super).tty_nr = uVar10;
      location = location + 1;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).tpgid = (wchar_t)lVar6;
      location = location + 1;
      uVar10 = __isoc23_strtoul(location,&location,10);
      lp->flags = uVar10;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      (lp->super).minflt = uVar10;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      lp->cminflt = uVar10;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      (lp->super).majflt = uVar10;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      lp->cmajflt = uVar10;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      lp->utime = (uVar10 * 100) / (ulong)lhost->jiffies;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      lp->stime = (uVar10 * 100) / (ulong)lhost->jiffies;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      lp->cutime = (uVar10 * 100) / (ulong)lhost->jiffies;
      location = location + 1;
      uVar10 = __isoc23_strtoull(location,&location,10);
      lp->cstime = (uVar10 * 100) / (ulong)lhost->jiffies;
      location = location + 1;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).priority = lVar6;
      location = location + 1;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).nice = lVar6;
      location = location + 1;
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).nlwp = lVar6;
      location = location + 1;
      pcVar7 = strchr(location,0x20);
      location = pcVar7 + 1;
      if ((lp->super).starttime_ctime == 0) {
        lVar6 = lhost->boottime;
        lVar12 = __isoc23_strtoll(location,&location,10);
        auVar3._8_8_ = 0;
        auVar3._0_8_ = lhost->jiffies;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = lVar12 * 100;
        (lp->super).starttime_ctime =
             SUB168((auVar4 / auVar3 >> 2 & (undefined1  [16])0x3fffffffffffffff) /
                    (undefined1  [16])0x19,0) + lVar6;
      }
      else {
        location = strchr(location,0x20);
      }
      location = location + 1;
      iVar15 = 0x10;
      do {
                    /* Unresolved local var: wchar_t i@[???] */
        pcVar7 = strchr(location,0x20);
        location = pcVar7 + 1;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      lVar6 = __isoc23_strtol(location,&location,10);
      (lp->super).processor = (wchar_t)lVar6;
      (lp->super).time = lp->stime + lp->utime;
      _Var5 = true;
      goto LAB_0013dbb2;
    }
  }
  _Var5 = false;
LAB_0013dbb2:
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var5;
}

