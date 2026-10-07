/* Process_makeCommandStr @ 001243c0 size 7823 */

/* DWARF original prototype: void Process_makeCommandStr(Process * this, Settings * settings) */

void Process_makeCommandStr(Process *this,Settings_5 *settings)

{
  ProcessCmdlineHighlight *pPVar1;
  byte bVar2;
  _Bool _Var3;
  _Bool _Var4;
  _Bool _Var5;
  _Bool _Var6;
  wchar_t wVar7;
  wchar_t wVar8;
  wchar_t wVar9;
  char *__s;
  byte bVar10;
  wchar_t *pwVar11;
  char cVar12;
  _Bool _Var13;
  int iVar14;
  int iVar15;
  wchar_t wVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  size_t sVar20;
  char *pcVar21;
  char *pcVar22;
  size_t sVar23;
  char *pcVar24;
  Object *pOVar25;
  ulong uVar26;
  byte bVar27;
  byte bVar28;
  char *pcVar29;
  undefined8 *puVar30;
  wchar_t wVar31;
  char *pcVar32;
  char *__s1;
  char *__s1_00;
  long lVar33;
  wchar_t wVar34;
  long lVar35;
  byte bVar36;
  bool bVar37;
  int local_b8;
  int local_98;
  wchar_t local_94;
  size_t local_90;
  size_t local_80;
  size_t local_60;
  long local_58;

  bVar27 = 0;
  _Var13 = settings->showMergedCommand;
  bVar36 = settings->showProgramPath;
  bVar2 = settings->findCommInCmdline;
  _Var3 = settings->stripExeFromCmdline;
  _Var4 = settings->showThreadNames;
  _Var5 = settings->shadowDistPathPrefix;
  if (this->isKernelThread != false) {
    return;
  }
  if (this->state == ZOMBIE) {
    if ((this->mergedCommand).str == (char *)0x0) {
      return;
    }
    uVar26 = (this->mergedCommand).lastUpdate;
  }
  else {
    uVar26 = (this->mergedCommand).lastUpdate;
  }
  if (settings->lastUpdate <= uVar26) {
    return;
  }
  (this->mergedCommand).lastUpdate = settings->lastUpdate;
  pcVar29 = *CRT_treeStr;
  sVar20 = strlen(pcVar29);
  iVar19 = (int)sVar20;
  local_60 = 8;
  if (this->cmdline != (char *)0x0) {
    local_60 = strlen(this->cmdline);
  }
  local_60 = (long)(iVar19 * 2 + 1) + local_60;
  if (this->procComm != (char *)0x0) {
    sVar20 = strlen(this->procComm);
    local_60 = local_60 + sVar20;
  }
  if (this->procExe != (char *)0x0) {
    sVar20 = strlen(this->procExe);
    local_60 = local_60 + sVar20;
  }
  free((this->mergedCommand).str);
                    /* Unresolved local var: void * data@[???] */
  pcVar21 = calloc(1,local_60);
  if (pcVar21 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this->mergedCommand).highlights[0].offset = 0;
  (this->mergedCommand).highlights[7].attr = L'\0';
  (this->mergedCommand).highlights[7].flags = L'\0';
  puVar30 = (undefined8 *)((ulong)&(this->mergedCommand).highlights[0].length & 0xfffffffffffffff8);
  (this->mergedCommand).str = pcVar21;
  (this->mergedCommand).highlightCount = 0;
  uVar26 = (ulong)(((int)this - (int)puVar30) + 0x1e8U >> 3);
  for (; pwVar11 = CRT_colors, uVar26 != 0; uVar26 = uVar26 - 1) {
    *puVar30 = 0;
    puVar30 = puVar30 + (ulong)bVar27 * -2 + 1;
  }
  _Var6 = this->isUserlandThread;
  if ((_Var6 == false) && (this->isKernelThread == false)) {
    wVar7 = CRT_colors[0x25];
    local_94 = CRT_colors[0x2c];
  }
  else {
    wVar7 = CRT_colors[0x2b];
    local_94 = CRT_colors[0x2d];
  }
  __s1_00 = this->cmdline;
  pcVar24 = this->procExe;
  wVar34 = this->cmdlineBasenameStart;
  wVar8 = CRT_colors[5];
  wVar9 = CRT_colors[0x1f];
  wVar31 = this->cmdlineBasenameEnd;
  __s = this->procComm;
  if (__s1_00 == (char *)0x0) {
    wVar31 = L'\0';
    wVar34 = L'\0';
    __s1_00 = ((char *)0x148787 /* "(zombie)" */);
  }
  if (_Var13 != true || pcVar24 == (char *)0x0) {
    if ((((_Var13 == false) && ((_Var4 == false || (_Var6 == false)))) || (__s == (char *)0x0)) ||
       (*__s == '\0')) {
LAB_001247b0:
      lVar35 = 0;
      pcVar29 = pcVar21;
    }
    else {
      sVar23 = strlen(__s);
      sVar20 = 0xf;
      if (sVar23 < 0x10) {
        sVar20 = sVar23;
      }
      iVar14 = strncmp(__s1_00 + wVar34,__s,sVar20);
      if (iVar14 == 0) goto LAB_001247b0;
      (this->mergedCommand).highlights[0].length = sVar23;
      (this->mergedCommand).highlights[0].flags = L'\x04';
      (this->mergedCommand).highlights[0].attr = local_94;
      (this->mergedCommand).highlightCount = 1;
      pcVar24 = __stpcpy_chk(pcVar21,__s,local_60);
      if (_Var13 == false) {
        return;
      }
      (this->mergedCommand).highlights[1].length = 1;
      (this->mergedCommand).highlights[1].offset = (long)pcVar24 - (long)pcVar21;
      wVar16 = pwVar11[5];
      (this->mergedCommand).highlights[1].flags = L'\x01';
      (this->mergedCommand).highlightCount = 2;
      (this->mergedCommand).highlights[1].attr = wVar16;
      lVar35 = (long)(iVar19 + -1);
      pcVar29 = stpcpy(pcVar24,pcVar29);
    }
    if (((_Bool)bVar36 == false) || (_Var5 == false)) {
      if (wVar31 <= wVar34) goto LAB_00124840;
      uVar26 = (this->mergedCommand).highlightCount;
      if (uVar26 < 8) {
        pcVar24 = pcVar29 + -(long)pcVar21;
        if ((_Bool)bVar36 != false) {
          pcVar24 = pcVar29 + -(long)pcVar21 + wVar34;
        }
        goto LAB_001247fc;
      }
LAB_00124a67:
      if (this->procExeDeleted != false) goto LAB_001248b6;
    }
    else {
      if (*__s1_00 == '/') {
        cVar12 = __s1_00[1];
        if (cVar12 == 's') {
          iVar19 = strncmp(__s1_00,((char *)0x148807 /* "/sbin/" */),6);
          if (iVar19 == 0) {
            uVar26 = (this->mergedCommand).highlightCount;
            if (uVar26 < 8) {
              pOVar25 = &(this->super).super + uVar26 * 3;
              pOVar25[0x26] = (ObjectClass *)0x6;
              lVar33 = (long)pcVar29 - (long)pcVar21;
              pOVar25[0x25] = (Object)(lVar33 - lVar35);
              goto LAB_001252c4;
            }
            goto LAB_00125810;
          }
        }
        else if (cVar12 < 't') {
          if (cVar12 == 'b') {
            iVar19 = strncmp(__s1_00,((char *)0x1487e7 /* "/bin/" */),5);
            if (iVar19 == 0) {
LAB_00125739:
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                pOVar25 = &(this->super).super + uVar26 * 3;
                pOVar25[0x26] = (ObjectClass *)0x5;
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25[0x25] = (Object)(lVar33 - lVar35);
LAB_001252c4:
                uVar26 = uVar26 + 1;
                wVar16 = pwVar11[0x1e];
                *(undefined4 *)((long)(pOVar25 + 0x27) + 4) = 0x10;
                *(wchar_t *)(pOVar25 + 0x27) = wVar16;
                (this->mergedCommand).highlightCount = uVar26;
                if (wVar34 < wVar31) {
                  if (uVar26 != 8) {
                    pcVar24 = (char *)(wVar34 + lVar33);
                    goto LAB_001247fc;
                  }
                  goto LAB_00124a67;
                }
                goto LAB_00124840;
              }
              goto LAB_00125810;
            }
          }
          else if (cVar12 == 'l') {
            iVar19 = strncmp(__s1_00,((char *)0x1487f7 /* "/lib/" */),5);
            if (iVar19 == 0) goto LAB_00125739;
            iVar19 = strncmp(__s1_00,((char *)0x1487bc /* "/lib32/" */),7);
            if ((iVar19 == 0) || (iVar19 = strncmp(__s1_00,((char *)0x1487c8 /* "/lib64/" */),7), iVar19 == 0)) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                pOVar25[0x26] = (ObjectClass *)0x7;
                pOVar25[0x25] = (Object)(lVar33 - lVar35);
                goto LAB_001252c4;
              }
            }
            else {
              _Var13 = String_startsWith(__s1_00,((char *)0x1487d4 /* "/libx32/" */));
              if (!_Var13) goto LAB_001247d5;
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                pOVar25[0x26] = (ObjectClass *)0x8;
                pOVar25[0x25] = (Object)(lVar33 - lVar35);
                goto LAB_001252c4;
              }
            }
LAB_00125810:
            if (wVar31 <= wVar34) goto LAB_00124a67;
            goto LAB_00124840;
          }
        }
        else if ((cVar12 == 'u') && (iVar19 = strncmp(__s1_00,((char *)0x148790 /* "/usr/" */),5), iVar19 == 0)) {
          cVar12 = __s1_00[5];
          if (cVar12 == 'l') {
            _Var13 = String_startsWith(__s1_00,((char *)0x1487a0 /* "/usr/libexec/" */));
            if (_Var13) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                pOVar25[0x26] = (ObjectClass *)0xd;
                pOVar25[0x25] = (Object)(lVar33 - lVar35);
                goto LAB_001252c4;
              }
            }
            else {
              _Var13 = String_startsWith(__s1_00,((char *)0x1487ae /* "/usr/lib/" */));
              if (_Var13) goto LAB_0012566c;
              _Var13 = String_startsWith(__s1_00,((char *)0x1487b8 /* "/usr/lib32/" */));
              if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)0x1487c4 /* "/usr/lib64/" */)), _Var13)) {
                uVar26 = (this->mergedCommand).highlightCount;
                if (uVar26 < 8) {
                  lVar33 = (long)pcVar29 - (long)pcVar21;
                  pOVar25 = &(this->super).super + uVar26 * 3;
                  pOVar25[0x26] = (ObjectClass *)0xb;
                  pOVar25[0x25] = (Object)(lVar33 - lVar35);
                  goto LAB_001252c4;
                }
              }
              else {
                _Var13 = String_startsWith(__s1_00,((char *)0x1487d0 /* "/usr/libx32/" */));
                if (_Var13) {
                  uVar26 = (this->mergedCommand).highlightCount;
                  if (uVar26 < 8) {
                    lVar33 = (long)pcVar29 - (long)pcVar21;
                    pOVar25 = &(this->super).super + uVar26 * 3;
                    pOVar25[0x26] = (ObjectClass *)0xc;
                    pOVar25[0x25] = (Object)(lVar33 - lVar35);
                    goto LAB_001252c4;
                  }
                }
                else {
                  _Var13 = String_startsWith(__s1_00,((char *)0x1487dd /* "/usr/local/bin/" */));
                  if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)0x1487ed /* "/usr/local/lib/" */)), _Var13)) {
                    uVar26 = (this->mergedCommand).highlightCount;
                    if (uVar26 < 8) {
                      lVar33 = (long)pcVar29 - (long)pcVar21;
                      pOVar25 = &(this->super).super + uVar26 * 3;
                      pOVar25[0x26] = (ObjectClass *)0xf;
                      pOVar25[0x25] = (Object)(lVar33 - lVar35);
                      goto LAB_001252c4;
                    }
                  }
                  else {
                    _Var13 = String_startsWith(__s1_00,((char *)0x1487fd /* "/usr/local/sbin/" */));
                    if (!_Var13) goto LAB_001247d5;
                    uVar26 = (this->mergedCommand).highlightCount;
                    if (uVar26 < 8) {
                      lVar33 = (long)pcVar29 - (long)pcVar21;
                      pOVar25 = &(this->super).super + uVar26 * 3;
                      pOVar25[0x26] = (ObjectClass *)0x10;
                      pOVar25[0x25] = (Object)(lVar33 - lVar35);
                      goto LAB_001252c4;
                    }
                  }
                }
              }
            }
            goto LAB_00125810;
          }
          if (cVar12 == 's') {
            _Var13 = String_startsWith(__s1_00,((char *)0x14880e /* "/usr/sbin/" */));
            if (_Var13) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                pOVar25[0x26] = (ObjectClass *)0xa;
                pOVar25[0x25] = (Object)(lVar33 - lVar35);
                goto LAB_001252c4;
              }
              goto LAB_00125810;
            }
          }
          else if ((cVar12 == 'b') && (_Var13 = String_startsWith(__s1_00,((char *)0x148796 /* "/usr/bin/" */)), _Var13)) {
LAB_0012566c:
            uVar26 = (this->mergedCommand).highlightCount;
            if (uVar26 < 8) {
              lVar33 = (long)pcVar29 - (long)pcVar21;
              pOVar25 = &(this->super).super + uVar26 * 3;
              pOVar25[0x26] = (ObjectClass *)0x9;
              pOVar25[0x25] = (Object)(lVar33 - lVar35);
              goto LAB_001252c4;
            }
            goto LAB_00125810;
          }
        }
      }
LAB_001247d5:
      if (wVar34 < wVar31) {
        uVar26 = (this->mergedCommand).highlightCount;
        if (7 < uVar26) goto LAB_00124a67;
        pcVar24 = pcVar29 + ((long)wVar34 - (long)pcVar21);
LAB_001247fc:
        (this->mergedCommand).highlights[uVar26].offset = (long)pcVar24 - lVar35;
        *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar7;
        pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x5c;
        pcVar24[0] = '\x02';
        pcVar24[1] = '\0';
        pcVar24[2] = '\0';
        pcVar24[3] = '\0';
        *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(wVar31 - wVar34);
        (this->mergedCommand).highlightCount = uVar26 + 1;
      }
LAB_00124840:
      if (this->procExeDeleted != false) {
        uVar26 = (this->mergedCommand).highlightCount;
        if (uVar26 < 8) {
          lVar33 = (long)pcVar29 - (long)pcVar21;
          if ((_Bool)bVar36 != false) {
            lVar33 = (long)wVar34 + ((long)pcVar29 - (long)pcVar21);
          }
          *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar8;
          (this->mergedCommand).highlights[uVar26].offset = lVar33 - lVar35;
          *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(wVar31 - wVar34);
          pcVar21 = this->starttime_show + uVar26 * 0x18 + 0x5c;
          pcVar21[0] = '\b';
          pcVar21[1] = '\0';
          pcVar21[2] = '\0';
          pcVar21[3] = '\0';
          (this->mergedCommand).highlightCount = uVar26 + 1;
        }
        goto LAB_001248b6;
      }
    }
    if ((this->usesDeletedLib != false) &&
       (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
      lVar33 = (long)pcVar29 - (long)pcVar21;
      if ((_Bool)bVar36 != false) {
        lVar33 = (long)wVar34 + ((long)pcVar29 - (long)pcVar21);
      }
      *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar9;
      (this->mergedCommand).highlights[uVar26].offset = lVar33 - lVar35;
      pcVar21 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar21[0] = '\b';
      pcVar21[1] = '\0';
      pcVar21[2] = '\0';
      pcVar21[3] = '\0';
      *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(wVar31 - wVar34);
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
LAB_001248b6:
    if ((_Bool)bVar36 == false) {
      __s1_00 = __s1_00 + wVar34;
    }
    cVar12 = *__s1_00;
    if (cVar12 != '\0') {
      pcVar21 = pcVar29;
      do {
        if (cVar12 == '\n') {
          cVar12 = ' ';
        }
        __s1_00 = __s1_00 + 1;
        pcVar29 = pcVar21 + 1;
        *pcVar21 = cVar12;
        cVar12 = *__s1_00;
        pcVar21 = pcVar29;
      } while (cVar12 != '\0');
    }
    *pcVar29 = '\0';
    return;
  }
  if (__s == (char *)0x0) goto LAB_001247b0;
  sVar20 = strlen(pcVar24);
  wVar31 = this->procExeBasenameOffset;
  local_b8 = (int)sVar20;
  iVar14 = local_b8 - wVar31;
  bVar27 = _Var6 ^ 1U | _Var4;
  if (bVar27 == 0) {
    if ((_Bool)bVar36 == false) {
      lVar35 = 0;
      pcVar22 = pcVar24 + wVar31;
      sVar20 = 1;
      goto LAB_00124b4d;
    }
    if ((_Var5 != false) && (*pcVar24 == '/')) {
      cVar12 = pcVar24[1];
      if (cVar12 == 'l') {
        bVar36 = false;
LAB_0012467a:
        iVar15 = strncmp(pcVar24,((char *)0x1487f7 /* "/lib/" */),5);
        if (iVar15 == 0) {
          (this->mergedCommand).highlights[0].length = 5;
          wVar16 = pwVar11[0x1e];
        }
        else {
          iVar15 = strncmp(pcVar24,((char *)0x1487bc /* "/lib32/" */),7);
          if ((iVar15 != 0) && (_Var13 = String_startsWith(pcVar24,((char *)0x1487c8 /* "/lib64/" */)), !_Var13)) {
            _Var13 = String_startsWith(pcVar24,((char *)0x1487d4 /* "/libx32/" */));
            local_58 = 0;
            if (_Var13) {
              (this->mergedCommand).highlights[0].length = 8;
              goto LAB_00125aa0;
            }
            goto LAB_001246cf;
          }
          (this->mergedCommand).highlights[0].length = 7;
          wVar16 = pwVar11[0x1e];
        }
        goto LAB_001246a9;
      }
      if (cVar12 < 'm') {
        if ((cVar12 == 'b') && (iVar15 = strncmp(pcVar24,((char *)0x1487e7 /* "/bin/" */),5), iVar15 == 0)) {
          (this->mergedCommand).highlights[0].length = 5;
          wVar16 = pwVar11[0x1e];
          (this->mergedCommand).highlights[0].flags = L'\x10';
          (this->mergedCommand).highlights[0].attr = wVar16;
LAB_001260f1:
          lVar35 = 1;
          bVar36 = false;
          goto LAB_001246df;
        }
      }
      else if (cVar12 == 's') {
        iVar15 = strncmp(pcVar24,((char *)0x148807 /* "/sbin/" */),6);
        if (iVar15 == 0) {
          (this->mergedCommand).highlights[0].length = 6;
          wVar16 = pwVar11[0x1e];
          (this->mergedCommand).highlights[0].flags = L'\x10';
          (this->mergedCommand).highlights[0].attr = wVar16;
          goto LAB_001260f1;
        }
      }
      else if (cVar12 == 'u') {
        bVar36 = false;
        goto LAB_00125922;
      }
      lVar35 = 0;
LAB_001246d7:
      bVar36 = false;
      goto LAB_001246df;
    }
    bVar36 = false;
    sVar20 = 1;
    lVar35 = 0;
LAB_001246ee:
    local_80 = (size_t)iVar14;
    local_90 = (size_t)wVar31;
    _Var13 = this->procExeDeleted;
    *(size_t *)(this->starttime_show + lVar35 * 0x18 + 0x50) = local_80;
    (this->mergedCommand).highlights[lVar35].offset = local_90;
    *(wchar_t *)(this->starttime_show + lVar35 * 0x18 + 0x58) = wVar7;
    pcVar22 = this->starttime_show + lVar35 * 0x18 + 0x5c;
    pcVar22[0] = '\x02';
    pcVar22[1] = '\0';
    pcVar22[2] = '\0';
    pcVar22[3] = '\0';
    (this->mergedCommand).highlightCount = sVar20;
    if (_Var13 == false) {
      if (this->usesDeletedLib != false) {
        (this->mergedCommand).highlights[sVar20].offset = local_90;
        pcVar22 = this->starttime_show + sVar20 * 0x18 + 0x5c;
        pcVar22[0] = '\b';
        pcVar22[1] = '\0';
        pcVar22[2] = '\0';
        pcVar22[3] = '\0';
        *(size_t *)(this->starttime_show + sVar20 * 0x18 + 0x50) = local_80;
        *(wchar_t *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar9;
        (this->mergedCommand).highlightCount = sVar20 + 1;
      }
    }
    else {
      pPVar1 = (this->mergedCommand).highlights + sVar20;
      pPVar1->offset = local_90;
      pPVar1->length = local_80;
      *(wchar_t *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar8;
      pcVar22 = this->starttime_show + sVar20 * 0x18 + 0x5c;
      pcVar22[0] = '\b';
      pcVar22[1] = '\0';
      pcVar22[2] = '\0';
      pcVar22[3] = '\0';
      (this->mergedCommand).highlightCount = sVar20 + 1;
    }
    pcVar22 = __stpcpy_chk(pcVar21,pcVar24,local_60);
  }
  else {
    pcVar22 = pcVar24 + wVar31;
    iVar15 = strncmp(pcVar22,__s,0xf);
    if ((_Bool)bVar36 != false) {
      bVar36 = iVar15 == 0;
      local_58 = 0;
      if ((_Var5 == false) || (*pcVar24 != '/')) {
LAB_001246cf:
        local_90 = (size_t)wVar31;
        lVar35 = local_58;
        if ((bool)bVar36 == false) goto LAB_001246d7;
        lVar35 = local_58 + 1;
        (this->mergedCommand).highlights[local_58].offset = local_90;
        *(long *)(this->starttime_show + local_58 * 0x18 + 0x50) = (long)iVar14;
        *(wchar_t *)(this->starttime_show + local_58 * 0x18 + 0x58) = local_94;
        pcVar22 = this->starttime_show + local_58 * 0x18 + 0x5c;
        pcVar22[0] = '\x04';
        pcVar22[1] = '\0';
        pcVar22[2] = '\0';
        pcVar22[3] = '\0';
      }
      else {
        cVar12 = pcVar24[1];
        if (cVar12 == 's') {
          iVar15 = strncmp(pcVar24,((char *)0x148807 /* "/sbin/" */),6);
          local_58 = 0;
          if (iVar15 == 0) {
            (this->mergedCommand).highlights[0].length = 6;
LAB_00125aa0:
            wVar16 = pwVar11[0x1e];
LAB_001246a9:
            (this->mergedCommand).highlights[0].attr = wVar16;
            local_58 = 1;
            (this->mergedCommand).highlights[0].flags = L'\x10';
            (this->mergedCommand).highlightCount = 1;
          }
          goto LAB_001246cf;
        }
        if (cVar12 < 't') {
          if (cVar12 == 'b') {
            local_58 = 0;
            iVar15 = strncmp(pcVar24,((char *)0x1487e7 /* "/bin/" */),5);
            if (iVar15 == 0) {
              (this->mergedCommand).highlights[0].length = 5;
              goto LAB_00125aa0;
            }
            goto LAB_001246cf;
          }
          if (cVar12 == 'l') goto LAB_0012467a;
        }
        else if (cVar12 == 'u') {
LAB_00125922:
          iVar15 = strncmp(pcVar24,((char *)0x148790 /* "/usr/" */),5);
          if (iVar15 == 0) {
            cVar12 = pcVar24[5];
            if (cVar12 == 'l') {
              _Var13 = String_startsWith(pcVar24,((char *)0x1487a0 /* "/usr/libexec/" */));
              if (_Var13) {
                (this->mergedCommand).highlights[0].length = 0xd;
                wVar16 = pwVar11[0x1e];
              }
              else {
                _Var13 = String_startsWith(pcVar24,((char *)0x1487ae /* "/usr/lib/" */));
                if (_Var13) {
LAB_00125975:
                  (this->mergedCommand).highlights[0].length = 9;
                  wVar16 = pwVar11[0x1e];
                }
                else {
                  _Var13 = String_startsWith(pcVar24,((char *)0x1487b8 /* "/usr/lib32/" */));
                  if ((_Var13) || (_Var13 = String_startsWith(pcVar24,((char *)0x1487c4 /* "/usr/lib64/" */)), _Var13)) {
                    (this->mergedCommand).highlights[0].length = 0xb;
                    wVar16 = pwVar11[0x1e];
                  }
                  else {
                    _Var13 = String_startsWith(pcVar24,((char *)0x1487d0 /* "/usr/libx32/" */));
                    if (_Var13) {
                      (this->mergedCommand).highlights[0].length = 0xc;
                      wVar16 = pwVar11[0x1e];
                    }
                    else {
                      _Var13 = String_startsWith(pcVar24,((char *)0x1487dd /* "/usr/local/bin/" */));
                      if ((!_Var13) &&
                         (_Var13 = String_startsWith(pcVar24,((char *)0x1487ed /* "/usr/local/lib/" */)), !_Var13)) {
                        _Var13 = String_startsWith(pcVar24,((char *)0x1487fd /* "/usr/local/sbin/" */));
                        local_58 = 0;
                        if (_Var13) {
                          (this->mergedCommand).highlights[0].length = 0x10;
                          goto LAB_00125aa0;
                        }
                        goto LAB_001246cf;
                      }
                      (this->mergedCommand).highlights[0].length = 0xf;
                      wVar16 = pwVar11[0x1e];
                    }
                  }
                }
              }
              goto LAB_001246a9;
            }
            if (cVar12 == 's') {
              _Var13 = String_startsWith(pcVar24,((char *)0x14880e /* "/usr/sbin/" */));
              local_58 = 0;
              if (_Var13) {
                (this->mergedCommand).highlights[0].length = 10;
                goto LAB_00125aa0;
              }
            }
            else {
              if (cVar12 != 'b') goto LAB_00125a1a;
              _Var13 = String_startsWith(pcVar24,((char *)0x148796 /* "/usr/bin/" */));
              local_58 = 0;
              if (_Var13) goto LAB_00125975;
            }
          }
          else {
            local_58 = 0;
          }
          goto LAB_001246cf;
        }
LAB_00125a1a:
        local_90 = (size_t)wVar31;
        if ((bool)bVar36 == false) {
          lVar35 = 0;
          bVar36 = false;
        }
        else {
          lVar35 = 1;
          (this->mergedCommand).highlights[0].flags = L'\x04';
          (this->mergedCommand).highlights[0].offset = local_90;
          (this->mergedCommand).highlights[0].length = (long)iVar14;
          (this->mergedCommand).highlights[0].attr = local_94;
        }
      }
LAB_001246df:
      sVar20 = lVar35 + 1;
      goto LAB_001246ee;
    }
    if (iVar15 == 0) {
      (this->mergedCommand).highlights[0].length = (long)iVar14;
      lVar35 = 1;
      (this->mergedCommand).highlights[0].flags = L'\x04';
      (this->mergedCommand).highlights[0].attr = local_94;
      sVar20 = 2;
      bVar36 = bVar27;
    }
    else {
      sVar20 = 1;
      lVar35 = 0;
    }
LAB_00124b4d:
    local_80 = (size_t)iVar14;
    _Var13 = this->procExeDeleted;
    (this->mergedCommand).highlights[lVar35].offset = 0;
    *(size_t *)(this->starttime_show + lVar35 * 0x18 + 0x50) = local_80;
    *(wchar_t *)(this->starttime_show + lVar35 * 0x18 + 0x58) = wVar7;
    pcVar32 = this->starttime_show + lVar35 * 0x18 + 0x5c;
    pcVar32[0] = '\x02';
    pcVar32[1] = '\0';
    pcVar32[2] = '\0';
    pcVar32[3] = '\0';
    (this->mergedCommand).highlightCount = sVar20;
    if (_Var13 == false) {
      if (this->usesDeletedLib != false) {
        *(size_t *)(this->starttime_show + sVar20 * 0x18 + 0x50) = local_80;
        (this->mergedCommand).highlights[sVar20].offset = 0;
        *(wchar_t *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar9;
        pcVar32 = this->starttime_show + sVar20 * 0x18 + 0x5c;
        pcVar32[0] = '\b';
        pcVar32[1] = '\0';
        pcVar32[2] = '\0';
        pcVar32[3] = '\0';
        (this->mergedCommand).highlightCount = sVar20 + 1;
      }
    }
    else {
      *(size_t *)(this->starttime_show + sVar20 * 0x18 + 0x50) = local_80;
      (this->mergedCommand).highlights[sVar20].offset = 0;
      *(wchar_t *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar8;
      pcVar32 = this->starttime_show + sVar20 * 0x18 + 0x5c;
      pcVar32[0] = '\b';
      pcVar32[1] = '\0';
      pcVar32[2] = '\0';
      pcVar32[3] = '\0';
      (this->mergedCommand).highlightCount = sVar20 + 1;
    }
    pcVar22 = __stpcpy_chk(pcVar21,pcVar22,local_60);
  }
  local_80 = (size_t)iVar14;
  local_90 = (size_t)wVar31;
  bVar10 = bVar36;
  if ((_Bool)bVar2 == false) {
    bVar2 = 1;
LAB_00124d40:
    local_98 = 0;
    iVar15 = 0;
  }
  else {
    if (bVar27 == 0) goto LAB_00124d40;
                    /* Unresolved local var: char * tokenBase@[???]
                       Unresolved local var: size_t tokenLen@[???]
                       Unresolved local var: size_t commLen@[???] */
    if (L'\xffffffff' < wVar34) {
      sVar20 = strlen(__s);
                    /* Unresolved local var: char * token@[???] */
      cVar12 = __s1_00[wVar34];
      pcVar32 = __s1_00 + wVar34;
LAB_00124c40:
      __s1 = pcVar32;
      if (cVar12 != '\0') {
        pcVar32 = __s1;
        if (cVar12 == '\n') {
          if (sVar20 == 0) {
LAB_0012515f:
            local_98 = (int)__s1 - (int)__s1_00;
            iVar15 = (int)pcVar32 - (int)__s1_00;
            bVar10 = bVar27;
            bVar2 = bVar36;
            goto LAB_00124d54;
          }
LAB_00124ca6:
          do {
            cVar12 = __s1[1];
            pcVar32 = __s1 + 1;
            if (cVar12 != '\n') break;
            cVar12 = __s1[2];
            __s1 = __s1 + 2;
            pcVar32 = __s1;
          } while (cVar12 == '\n');
        }
        else {
          do {
            pcVar32 = pcVar32 + 1;
            bVar37 = cVar12 == '/';
            cVar12 = *pcVar32;
            if (bVar37) {
              __s1 = pcVar32;
            }
          } while ((cVar12 != '\n') && (cVar12 != '\0'));
          if (((sVar20 == (long)pcVar32 - (long)__s1) ||
              ((sVar20 < (ulong)((long)pcVar32 - (long)__s1) && (sVar20 == 0xf)))) &&
             (iVar15 = strncmp(__s1,__s,sVar20), iVar15 == 0)) goto LAB_0012515f;
          __s1 = pcVar32;
          if (cVar12 != '\0') goto LAB_00124ca6;
          cVar12 = *pcVar32;
        }
        goto LAB_00124c40;
      }
    }
    local_98 = 0;
    iVar15 = 0;
    bVar2 = bVar27;
  }
LAB_00124d54:
                    /* Unresolved local var: wchar_t matchLen@[???]
                       Unresolved local var: char delim@[???]
                       Unresolved local var: _Bool delimFound@[???] */
  if (*__s1_00 != '/') {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    bVar36 = (byte)((uint)-wVar31 >> 0x1f);
LAB_00124da0:
    if (wVar31 <= wVar34) goto LAB_00124df0;
LAB_00124da6:
    iVar17 = strncmp(__s1_00 + wVar34,pcVar24 + local_90,local_80);
    if (iVar17 == 0) {
      local_b8 = wVar34 + iVar14;
      if (((byte)__s1_00[local_b8] < 0x21) &&
         ((0x100000401U >> ((ulong)(byte)__s1_00[local_b8] & 0x3f) & 1) != 0)) {
        lVar35 = (long)(wVar31 + L'\xffffffff');
        iVar17 = wVar34 + L'\xffffffff';
        bVar28 = bVar36;
        if ((-wVar34 < 0) && (-wVar31 < 0)) {
          lVar33 = (long)(wVar31 + L'\xfffffffe');
          do {
            if (__s1_00[lVar33 + 1 + ((long)wVar34 - local_90)] != pcVar24[lVar33 + 1])
            goto LAB_00124df0;
            iVar18 = (int)lVar33;
            lVar35 = (long)iVar18;
            bVar28 = (byte)~(byte)((ulong)lVar33 >> 0x18) >> 7;
            iVar17 = iVar17 + -1;
            if (iVar17 < 0) goto LAB_001250ae;
            lVar33 = lVar33 + -1;
          } while (-1 < iVar18);
        }
        if (iVar17 < 0) {
LAB_001250ae:
          if ((bVar28 != 0) && (pcVar24[lVar35] == '/')) goto LAB_001250d7;
        }
      }
    }
LAB_00124df0:
    wVar34 = wVar34 + L'\xfffffffe';
    if (L'\0' < wVar34) goto code_r0x00124df9;
    goto LAB_00124e57;
  }
  iVar14 = strncmp(__s1_00,pcVar24,(long)local_b8);
  if (((iVar14 == 0) && ((byte)__s1_00[local_b8] < 0x21)) &&
     ((0x100000401U >> ((ulong)(byte)__s1_00[local_b8] & 0x3f) & 1) != 0)) {
LAB_001250d7:
    bVar36 = local_b8 != 0 & _Var3;
    bVar37 = bVar10 == 0;
    bVar10 = bVar36;
    if (bVar37) {
LAB_00124e72:
      bVar36 = bVar10;
      if (bVar27 != 0) goto LAB_00124e7c;
    }
    if (bVar36 == 0) {
LAB_00125124:
      lVar35 = 0;
      lVar33 = (long)(iVar19 + -1);
      goto LAB_00124f73;
    }
    lVar33 = 0;
    local_98 = local_98 - local_b8;
    iVar15 = iVar15 - local_b8;
    __s1_00 = __s1_00 + local_b8;
  }
  else {
    if ((bVar10 != 0) || (local_b8 = 0, bVar27 == 0)) goto LAB_00125124;
LAB_00124e7c:
    uVar26 = (this->mergedCommand).highlightCount;
    if (uVar26 < 8) {
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x50;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      pcVar24[4] = '\0';
      pcVar24[5] = '\0';
      pcVar24[6] = '\0';
      pcVar24[7] = '\0';
      (this->mergedCommand).highlights[uVar26].offset = (long)pcVar22 - (long)pcVar21;
      wVar7 = pwVar11[5];
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar7;
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
    pcVar24 = stpcpy(pcVar22,pcVar29);
    uVar26 = (this->mergedCommand).highlightCount;
    lVar35 = (long)(iVar19 + -1);
    if (uVar26 < 8) {
      (this->mergedCommand).highlights[uVar26].offset =
           (size_t)(pcVar24 + (-lVar35 - (long)pcVar21));
      sVar20 = strlen(__s);
      *(size_t *)(this->starttime_show + uVar26 * 0x18 + 0x50) = sVar20;
      pcVar22 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar22[0] = '\x04';
      pcVar22[1] = '\0';
      pcVar22[2] = '\0';
      pcVar22[3] = '\0';
      *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = local_94;
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
    pcVar22 = stpcpy(pcVar24,__s);
    if (bVar10 == 0) {
      lVar33 = lVar35 * 2;
      bVar2 = 1;
    }
    else {
      __s1_00 = __s1_00 + local_b8;
      if (*__s1_00 == '\0') {
        return;
      }
      local_98 = local_98 - local_b8;
      lVar33 = lVar35 * 2;
      iVar15 = iVar15 - local_b8;
      bVar2 = bVar10;
    }
LAB_00124f73:
    uVar26 = (this->mergedCommand).highlightCount;
    if (uVar26 < 8) {
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x50;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      pcVar24[4] = '\0';
      pcVar24[5] = '\0';
      pcVar24[6] = '\0';
      pcVar24[7] = '\0';
      (this->mergedCommand).highlights[uVar26].offset =
           (size_t)(pcVar22 + (-lVar35 - (long)pcVar21));
      wVar7 = pwVar11[5];
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar7;
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
    pcVar22 = stpcpy(pcVar22,pcVar29);
  }
  if ((_Var5 == false) || (*__s1_00 != '/')) {
LAB_00124fef:
    if (bVar2 == 0) goto LAB_00125356;
  }
  else {
    cVar12 = __s1_00[1];
    if (cVar12 == 's') {
      iVar19 = strncmp(__s1_00,((char *)0x148807 /* "/sbin/" */),6);
      if ((iVar19 != 0) || (uVar26 = (this->mergedCommand).highlightCount, 7 < uVar26))
      goto LAB_0012534c;
      pOVar25 = &(this->super).super + uVar26 * 3;
      pOVar25[0x26] = (ObjectClass *)0x6;
      pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
LAB_00125873:
      wVar7 = pwVar11[0x1e];
      *(undefined4 *)((long)(pOVar25 + 0x27) + 4) = 0x10;
      *(wchar_t *)(pOVar25 + 0x27) = wVar7;
      (this->mergedCommand).highlightCount = uVar26 + 1;
      goto LAB_00124fef;
    }
    if (cVar12 < 't') {
      if (cVar12 == 'b') {
        iVar19 = strncmp(__s1_00,((char *)0x1487e7 /* "/bin/" */),5);
        if (iVar19 == 0) {
LAB_0012583a:
          uVar26 = (this->mergedCommand).highlightCount;
          if (uVar26 < 8) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            pOVar25[0x26] = (ObjectClass *)0x5;
            pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
            goto LAB_00125873;
          }
        }
      }
      else if (cVar12 == 'l') {
        iVar19 = strncmp(__s1_00,((char *)0x1487f7 /* "/lib/" */),5);
        if (iVar19 == 0) goto LAB_0012583a;
        iVar19 = strncmp(__s1_00,((char *)0x1487bc /* "/lib32/" */),7);
        if ((iVar19 == 0) || (iVar19 = strncmp(__s1_00,((char *)0x1487c8 /* "/lib64/" */),7), iVar19 == 0)) {
          uVar26 = (this->mergedCommand).highlightCount;
          if (uVar26 < 8) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
            pOVar25[0x26] = (ObjectClass *)0x7;
            goto LAB_00125531;
          }
        }
        else {
          _Var13 = String_startsWith(__s1_00,((char *)0x1487d4 /* "/libx32/" */));
          if ((_Var13) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
            pOVar25[0x26] = (ObjectClass *)0x8;
LAB_00125531:
            wVar7 = pwVar11[0x1e];
            *(undefined4 *)((long)(pOVar25 + 0x27) + 4) = 0x10;
            *(wchar_t *)(pOVar25 + 0x27) = wVar7;
            (this->mergedCommand).highlightCount = uVar26 + 1;
            goto LAB_00124fef;
          }
        }
      }
    }
    else if ((cVar12 == 'u') && (iVar19 = strncmp(__s1_00,((char *)0x148790 /* "/usr/" */),5), iVar19 == 0)) {
      cVar12 = __s1_00[5];
      if (cVar12 == 'l') {
        _Var13 = String_startsWith(__s1_00,((char *)0x1487a0 /* "/usr/libexec/" */));
        if (_Var13) {
          uVar26 = (this->mergedCommand).highlightCount;
          if (uVar26 < 8) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
            pOVar25[0x26] = (ObjectClass *)0xd;
            goto LAB_00125531;
          }
        }
        else {
          _Var13 = String_startsWith(__s1_00,((char *)0x1487ae /* "/usr/lib/" */));
          if (_Var13) goto LAB_001257d2;
          _Var13 = String_startsWith(__s1_00,((char *)0x1487b8 /* "/usr/lib32/" */));
          if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)0x1487c4 /* "/usr/lib64/" */)), _Var13)) {
            uVar26 = (this->mergedCommand).highlightCount;
            if (uVar26 < 8) {
              pOVar25 = &(this->super).super + uVar26 * 3;
              pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
              pOVar25[0x26] = (ObjectClass *)0xb;
              goto LAB_00125531;
            }
          }
          else {
            _Var13 = String_startsWith(__s1_00,((char *)0x1487d0 /* "/usr/libx32/" */));
            if (_Var13) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                pOVar25 = &(this->super).super + uVar26 * 3;
                pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
                pOVar25[0x26] = (ObjectClass *)0xc;
                goto LAB_00125531;
              }
            }
            else {
              _Var13 = String_startsWith(__s1_00,((char *)0x1487dd /* "/usr/local/bin/" */));
              if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)0x1487ed /* "/usr/local/lib/" */)), _Var13)) {
                uVar26 = (this->mergedCommand).highlightCount;
                if (uVar26 < 8) {
                  pOVar25 = &(this->super).super + uVar26 * 3;
                  pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
                  pOVar25[0x26] = (ObjectClass *)0xf;
                  goto LAB_00125531;
                }
              }
              else {
                _Var13 = String_startsWith(__s1_00,((char *)0x1487fd /* "/usr/local/sbin/" */));
                if ((_Var13) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
                  pOVar25 = &(this->super).super + uVar26 * 3;
                  pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
                  pOVar25[0x26] = (ObjectClass *)0x10;
                  goto LAB_00125531;
                }
              }
            }
          }
        }
      }
      else if (cVar12 == 's') {
        _Var13 = String_startsWith(__s1_00,((char *)0x14880e /* "/usr/sbin/" */));
        if ((_Var13) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
          pOVar25 = &(this->super).super + uVar26 * 3;
          pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
          pOVar25[0x26] = (ObjectClass *)0xa;
          goto LAB_00125531;
        }
      }
      else if ((cVar12 == 'b') && (_Var13 = String_startsWith(__s1_00,((char *)0x148796 /* "/usr/bin/" */)), _Var13)) {
LAB_001257d2:
        uVar26 = (this->mergedCommand).highlightCount;
        if (uVar26 < 8) {
          pOVar25 = &(this->super).super + uVar26 * 3;
          pOVar25[0x25] = (Object)(pcVar22 + (-lVar33 - (long)pcVar21));
          pOVar25[0x26] = (ObjectClass *)0x9;
          goto LAB_00125531;
        }
      }
    }
LAB_0012534c:
    cVar12 = '/';
    if (bVar2 != 0) goto LAB_00125007;
LAB_00125356:
    if ((bVar27 != 0) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
      pcVar29 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar29[0] = '\x04';
      pcVar29[1] = '\0';
      pcVar29[2] = '\0';
      pcVar29[3] = '\0';
      (this->mergedCommand).highlights[uVar26].offset =
           (size_t)(pcVar22 + (((long)local_98 - (long)pcVar21) - lVar33));
      *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(iVar15 - local_98);
      *(wchar_t *)(this->starttime_show + uVar26 * 0x18 + 0x58) = local_94;
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
  }
  cVar12 = *__s1_00;
  if (cVar12 == '\0') {
    return;
  }
LAB_00125007:
  do {
    if (cVar12 == '\n') {
      cVar12 = ' ';
    }
    __s1_00 = __s1_00 + 1;
    pcVar29 = pcVar22 + 1;
    *pcVar22 = cVar12;
    cVar12 = *__s1_00;
    pcVar22 = pcVar29;
  } while (cVar12 != '\0');
  *pcVar29 = '\0';
  return;
code_r0x00124df9:
  pcVar32 = __s1_00 + wVar34;
  while( true ) {
    cVar12 = *pcVar32;
    pcVar32 = pcVar32 + -1;
    wVar34 = wVar34 + L'\xffffffff';
    if (wVar34 == L'\0') break;
    if (cVar12 == ' ' || cVar12 == '\n') goto LAB_00124e36;
  }
  if ((cVar12 != ' ' && cVar12 != '\n') || (wVar31 < L'\x01')) {
LAB_00124e57:
    if (bVar10 != 0) goto LAB_00125124;
    local_b8 = 0;
    goto LAB_00124e72;
  }
  goto LAB_00124da6;
  while( true ) {
    pcVar32 = pcVar32 + -1;
    wVar34 = wVar34 + L'\xffffffff';
    if (wVar34 == L'\0') break;
LAB_00124e36:
    if (pcVar32[-1] == '/') break;
  }
  goto LAB_00124da0;
}

