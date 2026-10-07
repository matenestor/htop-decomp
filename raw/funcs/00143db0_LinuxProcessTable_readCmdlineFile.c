/* LinuxProcessTable_readCmdlineFile @ 00143db0 size 1490 */

_Bool LinuxProcessTable_readCmdlineFile(Process_2 *process,openat_arg_t procFd)

{
  long lVar1;
  bool bVar2;
  _Bool _Var3;
  wchar_t wVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  ssize_t sVar9;
  size_t sVar10;
  int *piVar11;
  wchar_t wVar12;
  ulong uVar13;
  char *pcVar14;
  ulong uVar15;
  wchar_t wVar16;
  wchar_t wVar17;
  wchar_t wVar18;
  char cVar19;
  wchar_t wVar20;
  wchar_t wVar21;
  wchar_t wVar22;
  long in_FS_OFFSET;
  bool bVar23;
  undefined8 local_10e8;
  int *local_10e0;
  char filename [129];
  char local_1049;
  char command [4097];

                    /* Unresolved local var: ssize_t amtRead@[???]
                       Unresolved local var: wchar_t tokenEnd@[???]
                       Unresolved local var: wchar_t tokenStart@[???]
                       Unresolved local var: wchar_t lastChar@[???]
                       Unresolved local var: _Bool argSepNUL@[???]
                       Unresolved local var: _Bool argSepSpace@[???] */
                    /* Unresolved local var: wchar_t fd@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar4 = openat(procFd,((char *)0x149306 /* "cmdline" */),0);
  if (wVar4 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    piVar11 = __errno_location();
    uVar6 = (ulong)-*piVar11;
  }
  else {
    uVar6 = readfd_internal(wVar4,command,0x1001);
  }
  if (0 < (long)uVar6) {
    uVar13 = 1;
    bVar2 = false;
    bVar23 = false;
    wVar4 = L'\0';
    uVar15 = 0;
    wVar18 = L'\0';
    do {
      wVar12 = (wchar_t)uVar15;
      wVar16 = (int)uVar13 + L'\xffffffff';
      cVar19 = command[uVar13 - 1];
      if (cVar19 == '\0') {
                    /* Unresolved local var: wchar_t i@[???] */
        command[uVar13 - 1] = '\n';
        if (wVar18 == L'\0') {
          wVar18 = wVar16;
        }
LAB_00143e4a:
        wVar12 = (wchar_t)uVar15;
      }
      else {
        if (wVar18 == L'\0') {
          if (cVar19 < '!') {
            if (cVar19 == '\n') {
              bVar2 = true;
              wVar18 = wVar16;
            }
            else {
              bVar2 = true;
              wVar4 = wVar16;
            }
          }
          else {
            wVar4 = wVar16;
            if (cVar19 == '/') {
              uVar15 = uVar13 & 0xffffffff;
            }
          }
          goto LAB_00143e4a;
        }
        if (cVar19 < '!') {
          bVar2 = true;
          bVar23 = true;
          if (cVar19 != '\n') {
            wVar4 = wVar16;
          }
          goto LAB_00143e4a;
        }
        bVar23 = true;
        wVar4 = wVar16;
      }
      if (uVar6 == uVar13) goto LAB_00143e90;
      uVar13 = uVar13 + 1;
    } while( true );
  }
  _Var3 = false;
  goto LAB_00144138;
LAB_00143e90:
  wVar16 = wVar4 + L'\x01';
  pcVar8 = command;
  command[wVar16] = '\0';
  if ((bVar23) || (!bVar2)) {
LAB_00143ff0:
    wVar4 = wVar16;
    if (wVar18 != L'\0') {
      wVar4 = wVar18;
    }
  }
  else {
    uVar6 = (ulong)local_10e8 >> 0x20;
    local_10e8 = (char *)CONCAT44((int)uVar6,wVar16);
                    /* Unresolved local var: wchar_t ret@[???] */
    local_10e0 = __errno_location();
    *local_10e0 = 0;
    iVar5 = faccessat(-100,pcVar8,0,0x100);
    wVar16 = (wchar_t)local_10e8;
    if (iVar5 != 0) {
      if (*local_10e0 == 0x16) {
        iVar5 = lstat(pcVar8,(stat_2 *)filename);
        wVar16 = (wchar_t)local_10e8;
        if (iVar5 == 0) goto LAB_00143f26;
      }
                    /* Unresolved local var: wchar_t i@[???] */
      wVar17 = L'\0';
      wVar18 = L'\0';
      pcVar14 = pcVar8;
      wVar21 = L'\0';
      local_10e8 = pcVar8;
      wVar20 = L'\0';
      do {
        cVar19 = *pcVar14;
        wVar22 = wVar21 + L'\x01';
        wVar12 = wVar20;
        if (cVar19 < '!') {
                    /* Unresolved local var: char tmpCommandChar@[???] */
          if (wVar18 == L'\0') {
                    /* Unresolved local var: _Bool found@[???] */
            *pcVar14 = '\0';
                    /* Unresolved local var: wchar_t ret@[???] */
            *local_10e0 = 0;
            iVar5 = faccessat(-100,local_10e8,0,0x100);
            if ((iVar5 == 0) ||
               ((*local_10e0 == 0x16 && (iVar5 = lstat(local_10e8,(stat_2 *)filename), iVar5 == 0)))
               ) {
              cVar19 = '\n';
              wVar18 = wVar21;
            }
            *pcVar14 = cVar19;
            if (wVar17 == L'\0') {
              wVar17 = wVar20;
            }
          }
          else {
            *pcVar14 = '\n';
          }
        }
        else if ((wVar18 == L'\0') && (wVar12 = wVar22, cVar19 != '/')) {
          if (cVar19 == '\\') {
            if ((wVar20 != L'\0') && (wVar12 = wVar20, command[wVar20 + L'\xffffffff'] == '\\')) {
              wVar12 = wVar22;
            }
          }
          else {
            wVar12 = wVar20;
            if (((cVar19 == ':') && (pcVar14[1] != '/')) && (pcVar14[1] != '\\')) {
              wVar18 = wVar21;
            }
          }
        }
        pcVar14 = pcVar14 + 1;
        wVar21 = wVar22;
        wVar20 = wVar12;
      } while (wVar22 <= wVar4);
                    /* Unresolved local var: wchar_t tokenArg0Start@[???] */
      if (wVar18 == L'\0') {
                    /* Unresolved local var: wchar_t i@[???] */
        wVar12 = L'\0';
        do {
          if ((*pcVar8 < '!') && (*pcVar8 = '\n', wVar18 == L'\0')) {
            wVar18 = wVar12;
          }
          wVar12 = wVar12 + L'\x01';
          pcVar8 = pcVar8 + 1;
        } while (wVar12 <= wVar4);
        pcVar8 = local_10e8;
        wVar12 = wVar17;
        if (wVar17 < wVar18) goto LAB_00143ff0;
      }
      else {
        pcVar8 = local_10e8;
        wVar4 = wVar18;
        if (wVar12 < wVar18) goto LAB_00143ff7;
      }
    }
LAB_00143f26:
    wVar12 = L'\0';
    wVar4 = wVar16;
  }
LAB_00143ff7:
  Process_updateCmdline((Process *)process,pcVar8,wVar12,wVar4);
                    /* Unresolved local var: wchar_t fd@[???] */
  wVar4 = openat(procFd,((char *)0x14a07e /* "comm" */),0);
  if (wVar4 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    piVar11 = __errno_location();
    pcVar14 = process->procComm;
    lVar7 = (long)-*piVar11;
    if (lVar7 < 1) goto LAB_0014417b;
LAB_00144041:
    command[lVar7 + -1] = '\0';
    if ((pcVar14 == (char *)0x0) || (iVar5 = strcmp(pcVar14,pcVar8), iVar5 != 0)) {
      free(pcVar14);
                    /* Unresolved local var: char * data@[???] */
      pcVar8 = strdup(pcVar8);
      if (pcVar8 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
        fail();
      }
      process->procComm = pcVar8;
      (process->mergedCommand).lastUpdate = 0;
    }
  }
  else {
    lVar7 = readfd_internal(wVar4,pcVar8,0x1001);
    pcVar14 = process->procComm;
    if (0 < lVar7) goto LAB_00144041;
LAB_0014417b:
    if (pcVar14 != (char *)0x0) {
      free(pcVar14);
      process->procComm = (char *)0x0;
      (process->mergedCommand).lastUpdate = 0;
    }
  }
  sVar9 = readlinkat(procFd,((char *)0x149289 /* "exe" */),filename,0x80);
  if (sVar9 < 1) {
    if (process->procExe != (char *)0x0) {
      free(process->procExe);
      process->procExeDeleted = false;
      process->procExe = (char *)0x0;
      process->procExeBasenameOffset = L'\0';
      (process->mergedCommand).lastUpdate = 0;
    }
  }
  else {
    pcVar8 = process->procExe;
    filename[sVar9] = '\0';
    if (((pcVar8 == (char *)0x0) || (process->procExeDeleted != false)) ||
       (iVar5 = strcmp(filename,pcVar8), iVar5 != 0)) {
                    /* Unresolved local var: char * deletedMarker@[???]
                       Unresolved local var: size_t markerLen@[???]
                       Unresolved local var: size_t filenameLen@[???] */
      sVar10 = strlen(filename);
      if (10 < sVar10) {
                    /* Unresolved local var: _Bool oldExeDeleted@[???] */
        _Var3 = process->procExeDeleted;
        iVar5 = strcmp(filename + (sVar10 - 10),((char *)0x14898b /* " (deleted)" */));
        bVar23 = iVar5 == 0;
        process->procExeDeleted = bVar23;
        if (bVar23) {
          *(undefined1 *)((long)&local_10e8 + sVar10 + 6) = 0;
        }
        if (_Var3 != bVar23) {
          (process->mergedCommand).lastUpdate = 0;
        }
      }
      Process_updateExe((Process *)process,filename);
    }
  }
  _Var3 = true;
LAB_00144138:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

