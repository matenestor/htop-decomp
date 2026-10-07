/* OpenFilesScreen_scan @ 0012b7f0 size 2388 */

/* DWARF func body range[0]: {@address 0x1138a0 001138a0} (5 bytes)
   DWARF func body range[1]: {@address 0x12b7f0 0012b7f0} (2407 bytes)
   DWARF: {@address 0x12b7f0 OpenFilesScreen_scan} disjoint block 1 */

void OpenFilesScreen_scan(InfoScreen_2 *super)

{
  byte bVar1;
  char cVar2;
  long lVar3;
  Panel *pPVar4;
  Vector *pVVar5;
  code *pcVar6;
  void *pvVar7;
  InfoScreen_2 *this;
  char **strp;
  undefined1 uVar8;
  int iVar9;
  __pid_t _Var10;
  int iVar11;
  wchar_t wVar12;
  __pid_t _Var13;
  uint uVar14;
  wchar_t wVar15;
  char *pcVar16;
  FILE_2 *pFVar17;
  char *__s1;
  char *__ptr;
  char *pcVar18;
  char *pcVar19;
  size_t sVar20;
  int *piVar21;
  ulong uVar22;
  undefined *puVar23;
  ulong uVar24;
  undefined *va1;
  undefined *va0;
  long lVar25;
  __pid_t *p_Var26;
  __pid_t *p_Var27;
  undefined *puVar29;
  undefined *puVar30;
  char *in_R8;
  undefined *in_R9;
  undefined *puVar31;
  undefined8 *__ptr_00;
  cchar_t *pcVar32;
  undefined8 *puVar33;
  wchar_t *pwVar34;
  long in_FS_OFFSET;
  __pid_t local_148;
  wchar_t local_144;
  Panel *local_140;
  InfoScreen_2 *local_138;
  char *local_130;
  char *local_128;
  char **local_120;
  char *local_118;
  FILE_2 *local_110;
  wchar_t wstatus;
  wchar_t fdpair [2];
  char fileSizeBuf [21];
  char buffer [32];
  long local_a8;
  __pid_t *p_Var28;

  p_Var28 = &local_148;
  p_Var27 = &local_148;
  p_Var26 = &local_148;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  pPVar4 = super->display;
  local_144 = pPVar4->selected;
  local_140 = pPVar4;
  local_138 = super;
  Vector_prune(pPVar4->items);
  pPVar4->needsRedraw = true;
                    /* Unresolved local var: OpenFiles_ProcessData * pdata@[???]
                       Unresolved local var: pid_t child@[???]
                       Unresolved local var: OpenFiles_Data * item@[???]
                       Unresolved local var: OpenFiles_FileData * fdata@[???]
                       Unresolved local var: _Bool lsofIncludesFileSize@[???]
                       Unresolved local var: FILE * fd@[???]
                       Unresolved local var: size_t fileSizeIndex@[???]
                       Unresolved local var: void * data@[???] */
  pPVar4->scrollV = L'\0';
  pPVar4->selected = L'\0';
  pPVar4->oldSelected = L'\0';
  iVar11 = *(int *)&super[1].super.klass;
  pcVar16 = calloc(1,0x70);
  if (pcVar16 == (char *)0x0) {
LAB_0012bdd3:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  pcVar16[0x58] = '\b';
  pcVar16[0x59] = '\0';
  pcVar16[0x5a] = '\0';
  pcVar16[0x5b] = '\0';
  pcVar16[0x60] = '\b';
  pcVar16[0x61] = '\0';
  pcVar16[0x62] = '\0';
  pcVar16[99] = '\0';
  pcVar16[0x50] = '\b';
  pcVar16[0x51] = '\0';
  pcVar16[0x52] = '\0';
  pcVar16[0x53] = '\0';
  fdpair[0] = L'\0';
  fdpair[1] = L'\0';
  iVar9 = pipe(fdpair);
  if (iVar9 != -1) {
    _Var10 = fork();
    if (_Var10 == -1) {
      close(fdpair[1]);
      close(fdpair[0]);
    }
    else {
      if (_Var10 == 0) {
                    /* Unresolved local var: wchar_t fdnull@[???] */
        close(fdpair[0]);
        dup2(fdpair[1],1);
        close(fdpair[1]);
        iVar9 = open(((char *)0x1488eb /* "/dev/null" */),1);
        if (-1 < iVar9) {
          dup2(iVar9,2);
          close(iVar9);
          buffer[0] = '\0';
          buffer[1] = '\0';
          buffer[2] = '\0';
          buffer[3] = '\0';
          buffer[4] = '\0';
          buffer[5] = '\0';
          buffer[6] = '\0';
          buffer[7] = '\0';
          buffer[8] = '\0';
          buffer[9] = '\0';
          buffer[10] = '\0';
          buffer[0xb] = '\0';
          buffer[0xc] = '\0';
          buffer[0xd] = '\0';
          buffer[0xe] = '\0';
          buffer[0xf] = '\0';
          buffer[0x10] = '\0';
          buffer[0x11] = '\0';
          buffer[0x12] = '\0';
          buffer[0x13] = '\0';
          buffer[0x14] = '\0';
          buffer[0x15] = '\0';
          buffer[0x16] = '\0';
          buffer[0x17] = '\0';
          buffer[0x18] = '\0';
          buffer[0x19] = '\0';
          buffer[0x1a] = '\0';
          buffer[0x1b] = '\0';
          buffer[0x1c] = '\0';
          buffer[0x1d] = '\0';
          buffer[0x1e] = '\0';
          buffer[0x1f] = '\0';
          xSnprintf(buffer,0x20,((char *)0x149710 /* "%d" */),iVar11);
          execlp(((char *)0x147fb0 /* "lsof" */),((char *)0x147fb0 /* "lsof" */),&DAT_001488fb,&DAT_001488f8,&DAT_001488f5,buffer,&DAT_001488fe,0);
                    /* WARNING: Subroutine does not return */
          exit(0x7f);
        }
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      close(fdpair[1]);
      pFVar17 = fdopen(fdpair[0],((char *)0x147760 /* "r" */));
      if (pFVar17 != (FILE_2 *)0x0) {
        local_118 = (char *)((ulong)local_118 & 0xffffffffffffff00);
        local_130 = (char *)0x0;
        pcVar18 = pcVar16;
        local_148 = _Var10;
        local_110 = pFVar17;
                    /* Unresolved local var: char * line@[???]
                       Unresolved local var: uchar cmd@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t dlen@[???] */
        while (__ptr = String_readLine((FILE *)local_110), _Var10 = local_148, __ptr != (char *)0x0)
        {
          cVar2 = *__ptr;
          bVar1 = cVar2 + 0xbc;
          if (bVar1 < 0x31) {
            if ((1L << (bVar1 & 0x3f) & 0x1842020000001U) == 0) {
              if (bVar1 != 0x22) {
                if (bVar1 != 0x2b) goto LAB_0012b998;
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t dlen@[???] */
                pcVar19 = __ptr + 1;
                iVar11 = (byte)__ptr[1] - 0x30;
                if (iVar11 == 0) {
                  iVar11 = (byte)__ptr[2] - 0x74;
                }
                __s1 = *(char **)(pcVar18 + 0x38);
                if (iVar11 == 0) {
                  pcVar19 = __ptr + 3;
                  if (__s1 == (char *)0x0) goto LAB_0012b953;
LAB_0012b944:
                  iVar11 = strcmp(__s1,pcVar19);
                  if (iVar11 != 0) goto LAB_0012b953;
                }
                else {
                  if (__s1 != (char *)0x0) goto LAB_0012b944;
LAB_0012b953:
                  free(__s1);
                    /* Unresolved local var: char * data@[???] */
                  __s1 = strdup(pcVar19);
                  if (__s1 == (char *)0x0) goto LAB_0012bdd3;
                  *(char **)(pcVar18 + 0x38) = __s1;
                }
                sVar20 = strlen(__s1);
                if ((ulong)(long)*(int *)(pcVar16 + 0x60) < sVar20) {
                  if (0x7fff < sVar20) {
                    sVar20 = 0x7fff;
                  }
                  *(int *)(pcVar16 + 0x60) = (int)sVar20;
                }
                goto LAB_0012b998;
              }
                    /* Unresolved local var: OpenFiles_FileData * nextFile@[???]
                       Unresolved local var: void * data@[???] */
              pcVar18 = calloc(1,0x48);
              if (pcVar18 == (char *)0x0) goto LAB_0012bdd3;
              if (local_130 == (char *)0x0) {
                *(char **)(pcVar16 + 0x68) = pcVar18;
              }
              else {
                *(char **)(local_130 + 0x40) = pcVar18;
              }
              lVar25 = 0;
              local_130 = pcVar18;
            }
            else {
              switch(bVar1) {
              case 0:
                lVar25 = 2;
                break;
              default:
                    /* WARNING: Subroutine does not return */
                abort();
              case 0x1d:
                lVar25 = 1;
                break;
              case 0x22:
                lVar25 = 0;
                break;
              case 0x25:
                lVar25 = 3;
                break;
              case 0x2a:
                lVar25 = 4;
                break;
              case 0x2b:
                lVar25 = 7;
                break;
              case 0x2f:
                lVar25 = 5;
                break;
              case 0x30:
                lVar25 = 6;
              }
            }
            pcVar19 = *(char **)(pcVar18 + lVar25 * 8);
            local_120 = (char **)(__ptr + 1);
            if ((pcVar19 == (char *)0x0) ||
               (local_128 = pcVar19, iVar11 = strcmp(pcVar19,(char *)local_120), pcVar19 = local_128
               , iVar11 != 0)) {
              free(pcVar19);
                    /* Unresolved local var: char * data@[???] */
              pcVar19 = strdup((char *)local_120);
              if (pcVar19 == (char *)0x0) goto LAB_0012bdd3;
              *(char **)(pcVar18 + lVar25 * 8) = pcVar19;
            }
            sVar20 = strlen(pcVar19);
            if ((ulong)(long)*(int *)(pcVar16 + lVar25 * 4 + 0x44) < sVar20) {
              if (0x7fff < sVar20) {
                sVar20 = 0x7fff;
              }
              *(int *)(pcVar16 + (lVar25 + 0x10) * 4 + 4) = (int)sVar20;
            }
            uVar8 = (char)local_118;
            if (cVar2 == 's') {
              uVar8 = 1;
            }
            local_118 = (char *)CONCAT71(local_118._1_7_,uVar8);
          }
LAB_0012b998:
          free(__ptr);
        }
        fclose(local_110);
        local_120 = (char **)&wstatus;
        do {
          _Var13 = waitpid(_Var10,&wstatus,0);
          if (_Var13 != -1) {
            if (((ulong)_wstatus & 0x7f) == 0) {
              uVar14 = (uint)wstatus >> 8 & 0xff;
              *(uint *)(pcVar16 + 0x40) = uVar14;
              if (((char)local_118 != '\0') || (lVar25 = *(long *)(pcVar16 + 0x68), lVar25 == 0))
              goto LAB_0012bdf5;
            }
            else {
              pcVar16[0x40] = '\x01';
              pcVar16[0x41] = '\0';
              pcVar16[0x42] = '\0';
              pcVar16[0x43] = '\0';
              if ((char)local_118 != '\0') break;
              lVar25 = *(long *)(pcVar16 + 0x68);
              uVar14 = 1;
              if (lVar25 == 0) break;
            }
                    /* Unresolved local var: char * filename@[???] */
            local_110 = (FILE_2 *)CONCAT44(local_110._4_4_,uVar14);
            goto LAB_0012bd5d;
          }
          piVar21 = __errno_location();
        } while (*piVar21 == 4);
      }
    }
  }
LAB_0012bc28:
  InfoScreen_addLine((InfoScreen *)local_138,((char *)0x148901 /* "Failed listing open files." */));
LAB_0012bc3b:
  *(char *)((long)p_Var26 + -8) = 'C';
  *(char *)((long)p_Var26 + -7) = -0x44;
  *(char *)((long)p_Var26 + -6) = '\x12';
  *(char *)((long)p_Var26 + -5) = '\0';
  *(char *)((long)p_Var26 + -4) = '\0';
  *(char *)((long)p_Var26 + -3) = '\0';
  *(char *)((long)p_Var26 + -2) = '\0';
  *(char *)((long)p_Var26 + -1) = '\0';
  free(pcVar16);
  pVVar5 = local_138->lines;
  *(char *)((long)p_Var26 + -8) = 'S';
  *(char *)((long)p_Var26 + -7) = -0x44;
  *(char *)((long)p_Var26 + -6) = '\x12';
  *(char *)((long)p_Var26 + -5) = '\0';
  *(char *)((long)p_Var26 + -4) = '\0';
  *(char *)((long)p_Var26 + -3) = '\0';
  *(char *)((long)p_Var26 + -2) = '\0';
  *(char *)((long)p_Var26 + -1) = '\0';
  Vector_insertionSort(pVVar5);
  pPVar4 = local_140;
  pVVar5 = local_140->items;
  *(char *)((long)p_Var26 + -8) = 'c';
  *(char *)((long)p_Var26 + -7) = -0x44;
  *(char *)((long)p_Var26 + -6) = '\x12';
  *(char *)((long)p_Var26 + -5) = '\0';
  *(char *)((long)p_Var26 + -4) = '\0';
  *(char *)((long)p_Var26 + -3) = '\0';
  *(char *)((long)p_Var26 + -2) = '\0';
  *(char *)((long)p_Var26 + -1) = '\0';
  Vector_insertionSort(pVVar5);
                    /* Unresolved local var: wchar_t size@[???] */
  uVar22 = (ulong)(uint)local_144;
  wVar12 = pPVar4->items->items;
  wVar15 = wVar12 + L'\xffffffff';
  if (local_144 < wVar12) {
    wVar15 = local_144;
  }
  wVar12 = L'\0';
  if (L'\xffffffff' < wVar15) {
    wVar12 = wVar15;
  }
  pPVar4->selected = wVar12;
  pcVar6 = (pPVar4->super).klass[1].extends;
  if (pcVar6 != (code *)0x0) {
    *(char *)((long)p_Var26 + -8) = -0x68;
    *(char *)((long)p_Var26 + -7) = -0x44;
    *(char *)((long)p_Var26 + -6) = '\x12';
    *(char *)((long)p_Var26 + -5) = '\0';
    *(char *)((long)p_Var26 + -4) = '\0';
    *(char *)((long)p_Var26 + -3) = '\0';
    *(char *)((long)p_Var26 + -2) = '\0';
    *(char *)((long)p_Var26 + -1) = '\0';
    (*pcVar6)((long)pPVar4,0xffffffff,(ulong)(uint)wVar15,uVar22,(long)in_R8,(long)in_R9);
  }
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)p_Var26 + -8) = &UNK_0012c157;
  __stack_chk_fail();
LAB_0012bd5d:
  do {
                    /* Unresolved local var: size_t index@[???] */
    pcVar18 = *(char **)(lVar25 + 0x20);
    if (pcVar18 == (char *)0x0) {
      pcVar18 = ((char *)0x149c0c /* "" */);
    }
    iVar11 = stat(pcVar18,(stat_2 *)buffer);
    if (iVar11 == 0) {
      xSnprintf(fileSizeBuf,0x15,((char *)0x14975f /* "%lu" */),local_a8);
      pcVar18 = *(char **)(lVar25 + 0x28);
      if ((pcVar18 == (char *)0x0) ||
         (local_118 = pcVar18, iVar11 = strcmp(pcVar18,fileSizeBuf), pcVar18 = local_118,
         iVar11 != 0)) {
        free(pcVar18);
                    /* Unresolved local var: char * data@[???] */
        pcVar18 = strdup(fileSizeBuf);
        if (pcVar18 == (char *)0x0) goto LAB_0012bdd3;
        *(char **)(lVar25 + 0x28) = pcVar18;
      }
    }
    lVar25 = *(long *)(lVar25 + 0x40);
  } while (lVar25 != 0);
  uVar14 = (uint)local_110;
LAB_0012bdf5:
  if (uVar14 == 0x7f) {
    InfoScreen_addLine((InfoScreen *)local_138,
                       ((char *)0x14c518 /* "Could not execute \'lsof\'. Please make sure it is available in your $PATH." */)
                      );
    p_Var26 = &local_148;
    goto LAB_0012bc3b;
  }
  if (uVar14 != 1) {
    buffer[0] = '\0';
    buffer[1] = '\0';
    buffer[2] = '\0';
    buffer[3] = '\0';
    buffer[4] = '\0';
    buffer[5] = '\0';
    buffer[6] = '\0';
    buffer[7] = '\0';
    buffer[8] = '\0';
    buffer[9] = '\0';
    buffer[10] = '\0';
    buffer[0xb] = '\0';
    buffer[0xc] = '\0';
    buffer[0xd] = '\0';
    buffer[0xe] = '\0';
    buffer[0xf] = '\0';
                    /* Unresolved local var: OpenFiles_FileData * fdata@[???] */
    buffer[0x10] = '\0';
    buffer[0x11] = '\0';
    buffer[0x12] = '\0';
    buffer[0x13] = '\0';
    buffer[0x14] = '\0';
    buffer[0x15] = '\0';
    buffer[0x16] = '\0';
    buffer[0x17] = '\0';
    buffer[0x18] = '\0';
    buffer[0x19] = '\0';
    buffer[0x1a] = '\0';
    buffer[0x1b] = '\0';
    buffer[0x1c] = '\0';
    buffer[0x1d] = '\0';
    buffer[0x1e] = '\0';
    buffer[0x1f] = '\0';
    in_R9 = &DAT_0014891c;
    in_R8 = ((char *)0x14c568 /* "%5.5s %-7.7s %-4.4s %6.6s %*s %*s %*s  %s" */);
    __snprintf_chk(buffer,0x80,2,0x80,((char *)0x14c568 /* "%5.5s %-7.7s %-4.4s %6.6s %*s %*s %*s  %s" */),&DAT_0014891c,
                   ((char *)0x147528 /* "TYPE" */),&DAT_0014893c,((char *)0x148935 /* "DEVICE" */),*(int *)(pcVar16 + 0x58),&DAT_00148930,
                   *(int *)(pcVar16 + 0x60),((char *)0x148929 /* "OFFSET" */),*(int *)(pcVar16 + 0x50),&DAT_00148924,
                   &DAT_0014891f);
                    /* Unresolved local var: wchar_t[64250] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    wVar12 = CRT_colors[7];
    sVar20 = strlen(buffer);
    uVar24 = (ulong)((int)sVar20 + 1);
    uVar22 = uVar24 * 4 + 0xf;
    p_Var26 = &local_148;
    while (p_Var28 != (__pid_t *)((long)&local_148 - (uVar22 & 0xfffffffffffff000))) {
      p_Var27 = (__pid_t *)((long)p_Var26 + -0x1000);
      *(undefined8 *)((long)p_Var26 + -8) = *(undefined8 *)((long)p_Var26 + -8);
      p_Var28 = (__pid_t *)((long)p_Var26 + -0x1000);
      p_Var26 = (__pid_t *)((long)p_Var26 + -0x1000);
    }
    uVar22 = (ulong)((uint)uVar22 & 0xff0);
    lVar25 = -uVar22;
    pwVar34 = (wchar_t *)((long)p_Var27 + lVar25);
    if (uVar22 != 0) {
      *(undefined8 *)((long)p_Var27 + -8) = *(undefined8 *)((long)p_Var27 + -8);
    }
    *(undefined8 *)((long)p_Var27 + lVar25 + -8) = 0x12bf44;
    uVar22 = __mbstowcs_chk((int *)((long)p_Var27 + lVar25),buffer,sVar20,
                            uVar24 & 0x3fffffffffffffff);
    wVar15 = (wchar_t)uVar22;
    p_Var26 = &local_148;
    if (L'\0' < wVar15) {
      *(undefined8 *)((long)p_Var27 + lVar25 + -8) = 0x12bf61;
      RichString_setLen(&local_140->header,wVar15);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      local_118 = pcVar16;
      local_128 = (char *)&local_148;
      local_110 = (FILE_2 *)((long)p_Var27 + (ulong)(uint)(wVar15 + L'\xffffffff') * 4 + lVar25 + 4)
      ;
      pcVar32 = (local_140->header).chptr;
      do {
        wVar15 = *pwVar34;
        *(undefined8 *)((long)p_Var27 + lVar25 + -8) = 0x12bfb3;
        iVar11 = iswprint(wVar15);
        pcVar32->attr = 0;
        pcVar32->chars[0] = L'\0';
        pcVar32->chars[1] = L'\0';
        pcVar32->chars[2] = L'\0';
        if (iVar11 == 0) {
          wVar15 = L'�';
        }
        pcVar32->attr = wVar12 & 0xffffff;
        pwVar34 = pwVar34 + 1;
        *(undefined1 (*) [16])(pcVar32->chars + 2) = (undefined1  [16])0x0;
        pcVar32->chars[0] = wVar15;
        p_Var26 = (__pid_t *)local_128;
        pcVar32 = pcVar32 + 1;
        pcVar16 = local_118;
      } while (local_110 != (FILE_2 *)pwVar34);
    }
    __ptr_00 = *(undefined8 **)(pcVar16 + 0x68);
    local_140->needsRedraw = true;
    if (__ptr_00 != (undefined8 *)0x0) {
                    /* Unresolved local var: OpenFiles_Data * data@[???]
                       Unresolved local var: OpenFiles_FileData * old@[???] */
      uVar14 = *(uint *)(pcVar16 + 0x50);
      local_128 = pcVar16;
                    /* Unresolved local var: size_t index@[???] */
      local_118 = (char *)CONCAT44(local_118._4_4_,*(undefined4 *)(pcVar16 + 0x60));
      local_110 = (FILE_2 *)CONCAT44(local_110._4_4_,*(undefined4 *)(pcVar16 + 0x58));
      do {
        _wstatus = (char *)0x0;
        puVar31 = (undefined *)__ptr_00[4];
                    /* Unresolved local var: size_t index@[???] */
        puVar30 = (undefined *)__ptr_00[3];
                    /* Unresolved local var: size_t index@[???] */
        puVar29 = (undefined *)__ptr_00[7];
                    /* Unresolved local var: size_t index@[???] */
        puVar23 = (undefined *)__ptr_00[5];
                    /* Unresolved local var: size_t index@[???] */
        in_R9 = (undefined *)__ptr_00[2];
        if (puVar31 == (undefined *)0x0) {
          puVar31 = &DAT_00149c0c;
        }
                    /* Unresolved local var: size_t index@[???] */
        in_R8 = (char *)__ptr_00[1];
                    /* Unresolved local var: size_t index@[???] */
        va1 = (undefined *)__ptr_00[6];
        if (puVar30 == (undefined *)0x0) {
          puVar30 = &DAT_00149c0c;
        }
                    /* Unresolved local var: size_t index@[???] */
        va0 = (undefined *)*__ptr_00;
        if (puVar29 == (undefined *)0x0) {
          puVar29 = &DAT_00149c0c;
        }
        if (puVar23 == (undefined *)0x0) {
          puVar23 = &DAT_00149c0c;
        }
        if (in_R9 == (undefined *)0x0) {
          in_R9 = &DAT_00149c0c;
        }
        if (in_R8 == (char *)0x0) {
          in_R8 = ((char *)0x149c0c /* "" */);
        }
        if (va1 == (undefined *)0x0) {
          va1 = &DAT_00149c0c;
        }
        if (va0 == (undefined *)0x0) {
          va0 = &DAT_00149c0c;
        }
        *(undefined **)((long)p_Var26 + -0x10) = puVar31;
        *(undefined **)((long)p_Var26 + -0x18) = puVar30;
        strp = local_120;
        *(ulong *)((long)p_Var26 + -0x20) = (ulong)uVar14;
        *(undefined **)((long)p_Var26 + -0x28) = puVar29;
        *(ulong *)((long)p_Var26 + -0x30) = (ulong)local_118 & 0xffffffff;
        *(undefined **)((long)p_Var26 + -0x38) = puVar23;
        *(ulong *)((long)p_Var26 + -0x40) = (ulong)local_110 & 0xffffffff;
        *(char *)((long)p_Var26 + -0x48) = -0x38;
        *(char *)((long)p_Var26 + -0x47) = -0x40;
        *(char *)((long)p_Var26 + -0x46) = '\x12';
        *(char *)((long)p_Var26 + -0x45) = '\0';
        *(char *)((long)p_Var26 + -0x44) = '\0';
        *(char *)((long)p_Var26 + -0x43) = '\0';
        *(char *)((long)p_Var26 + -0x42) = '\0';
        *(char *)((long)p_Var26 + -0x41) = '\0';
        xAsprintf(strp,((char *)0x14c568 /* "%5.5s %-7.7s %-4.4s %6.6s %*s %*s %*s  %s" */),va0,va1,in_R8,in_R9,
                  *(int *)((long)p_Var26 + -0x40),*(void **)((long)p_Var26 + -0x38),
                  *(int *)((long)p_Var26 + -0x30),*(void **)((long)p_Var26 + -0x28),
                  *(int *)((long)p_Var26 + -0x20),*(void **)((long)p_Var26 + -0x18),
                  *(void **)((long)p_Var26 + -0x10));
        pcVar16 = _wstatus;
        this = local_138;
        *(char *)((long)p_Var26 + -8) = -0x21;
        *(char *)((long)p_Var26 + -7) = -0x40;
        *(char *)((long)p_Var26 + -6) = '\x12';
        *(char *)((long)p_Var26 + -5) = '\0';
        *(char *)((long)p_Var26 + -4) = '\0';
        *(char *)((long)p_Var26 + -3) = '\0';
        *(char *)((long)p_Var26 + -2) = '\0';
        *(char *)((long)p_Var26 + -1) = '\0';
        InfoScreen_addLine((InfoScreen *)this,pcVar16);
        pcVar16 = _wstatus;
        *(char *)((long)p_Var26 + -8) = -0x15;
        *(char *)((long)p_Var26 + -7) = -0x40;
        *(char *)((long)p_Var26 + -6) = '\x12';
        *(char *)((long)p_Var26 + -5) = '\0';
        *(char *)((long)p_Var26 + -4) = '\0';
        *(char *)((long)p_Var26 + -3) = '\0';
        *(char *)((long)p_Var26 + -2) = '\0';
        *(char *)((long)p_Var26 + -1) = '\0';
        free(pcVar16);
                    /* Unresolved local var: size_t i@[???] */
        puVar33 = __ptr_00;
        do {
          pvVar7 = (void *)*puVar33;
          puVar33 = puVar33 + 1;
          *(char *)((long)p_Var26 + -8) = -4;
          *(char *)((long)p_Var26 + -7) = -0x40;
          *(char *)((long)p_Var26 + -6) = '\x12';
          *(char *)((long)p_Var26 + -5) = '\0';
          *(char *)((long)p_Var26 + -4) = '\0';
          *(char *)((long)p_Var26 + -3) = '\0';
          *(char *)((long)p_Var26 + -2) = '\0';
          *(char *)((long)p_Var26 + -1) = '\0';
          free(pvVar7);
        } while (__ptr_00 + 8 != puVar33);
        puVar33 = (undefined8 *)__ptr_00[8];
        *(char *)((long)p_Var26 + -8) = '\r';
        *(char *)((long)p_Var26 + -7) = -0x3f;
        *(char *)((long)p_Var26 + -6) = '\x12';
        *(char *)((long)p_Var26 + -5) = '\0';
        *(char *)((long)p_Var26 + -4) = '\0';
        *(char *)((long)p_Var26 + -3) = '\0';
        *(char *)((long)p_Var26 + -2) = '\0';
        *(char *)((long)p_Var26 + -1) = '\0';
        free(__ptr_00);
        __ptr_00 = puVar33;
        pcVar16 = local_128;
      } while (puVar33 != (undefined8 *)0x0);
    }
                    /* Unresolved local var: size_t i@[???] */
    pcVar18 = pcVar16;
    do {
      pvVar7 = *(void **)pcVar18;
      pcVar18 = pcVar18 + 8;
      *(char *)((long)p_Var26 + -8) = '=';
      *(char *)((long)p_Var26 + -7) = -0x3f;
      *(char *)((long)p_Var26 + -6) = '\x12';
      *(char *)((long)p_Var26 + -5) = '\0';
      *(char *)((long)p_Var26 + -4) = '\0';
      *(char *)((long)p_Var26 + -3) = '\0';
      *(char *)((long)p_Var26 + -2) = '\0';
      *(char *)((long)p_Var26 + -1) = '\0';
      free(pvVar7);
    } while (pcVar18 != pcVar16 + 0x40);
    goto LAB_0012bc3b;
  }
  goto LAB_0012bc28;
}

