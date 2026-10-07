/* Table_printHeader @ 00131d50 size 880 */

void Table_printHeader(Settings_4 *settings,RichString *header)

{
  wchar_t wVar1;
  ScreenSettings_3 *pSVar2;
  int *piVar3;
  Settings_4 *settings_00;
  RichString *pRVar4;
  int iVar5;
  wchar_t wVar6;
  char *pcVar7;
  size_t sVar8;
  ulong uVar9;
  ulong uVar10;
  char cVar11;
  long lVar12;
  cchar_t *pcVar13;
  int **ppiVar14;
  int **ppiVar15;
  undefined1 *puVar16;
  RowField RVar17;
  long lVar18;
  long lVar19;
  int *piVar20;
  long in_FS_OFFSET;
  int *local_88;
  Settings_4 *local_80;
  ScreenSettings_3 *local_78;
  wchar_t local_6c;
  int *local_68;
  RichString *local_60;
  undefined8 local_58;
  int local_50;
  wchar_t local_4c;
  wchar_t local_48 [2];
  long local_40;

  ppiVar14 = &local_88;
  ppiVar15 = &local_88;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_80 = settings;
  local_60 = header;
  RichString_setLen(header,L'\0');
  pSVar2 = settings->ss;
  cVar11 = pSVar2->treeView;
  piVar20 = pSVar2->fields;
  if ((_Bool)cVar11 == false) {
    RVar17 = pSVar2->sortKey;
  }
  else {
    RVar17 = 1;
    if (pSVar2->treeViewAlwaysByPID == false) {
      RVar17 = pSVar2->treeSortKey;
    }
  }
                    /* Unresolved local var: wchar_t i@[???] */
  iVar5 = *piVar20;
  if (iVar5 != 0) {
    do {
      local_50 = RVar17;
      local_78 = pSVar2;
      settings_00 = local_80;
      if (((cVar11 == '\0') || (local_78->treeViewAlwaysByPID == false)) && (local_50 == iVar5)) {
        local_6c = CRT_colors[9];
      }
      else {
        local_6c = CRT_colors[7];
      }
      *(int *)((long)ppiVar14 + -8) = 0x131df8;
      *(int *)((long)ppiVar14 + -4) = 0;
      pcVar7 = RowField_alignedTitle(settings_00,iVar5);
      *(int *)((long)ppiVar14 + -8) = 0x131e03;
      *(int *)((long)ppiVar14 + -4) = 0;
      sVar8 = strlen(pcVar7);
                    /* Unresolved local var: wchar_t[32149] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
      local_68 = (int *)ppiVar14;
      uVar10 = (ulong)((int)sVar8 + 1);
      wVar6 = local_60->chlen;
      uVar9 = uVar10 * 4 + 0xf;
      puVar16 = (undefined1 *)((long)ppiVar14 - (uVar9 & 0xfffffffffffff000));
      for (; ppiVar14 != (int **)puVar16; ppiVar14 = (int **)((long)ppiVar14 + -0x1000)) {
        *(undefined8 *)((long)ppiVar14 + -8) = *(undefined8 *)((long)ppiVar14 + -8);
      }
      uVar9 = (ulong)((uint)uVar9 & 0xff0);
      lVar18 = -uVar9;
      if (uVar9 != 0) {
        *(undefined8 *)((long)ppiVar14 + -8) = *(undefined8 *)((long)ppiVar14 + -8);
      }
      *(undefined8 *)((long)ppiVar14 + lVar18 + -8) = 0x131e75;
      uVar9 = __mbstowcs_chk((int *)((long)ppiVar14 + lVar18),pcVar7,(long)(int)sVar8,
                             uVar10 & 0x3fffffffffffffff);
      pRVar4 = local_60;
      if (0 < (int)uVar9) {
        local_4c = wVar6 + (int)uVar9;
        lVar12 = (long)wVar6;
        *(undefined8 *)((long)ppiVar14 + lVar18 + -8) = 0x131e96;
        RichString_setLen(local_60,local_4c);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
        local_88 = piVar20;
        local_58 = (int *)(CONCAT44(local_58._4_4_,local_6c) & 0xffffffff00ffffff);
        lVar19 = lVar12 * -4;
        pcVar13 = pRVar4->chptr + lVar12;
        do {
          wVar6 = *(wchar_t *)((long)ppiVar14 + lVar12 * 4 + lVar19 + lVar18);
          *(undefined8 *)((long)ppiVar14 + lVar18 + -8) = 0x131edd;
          iVar5 = iswprint(wVar6);
          pcVar13->attr = 0;
          pcVar13->chars[0] = L'\0';
          pcVar13->chars[1] = L'\0';
          pcVar13->chars[2] = L'\0';
          if (iVar5 == 0) {
            wVar6 = L'�';
          }
          *(undefined1 (*) [16])(pcVar13->chars + 2) = (undefined1  [16])0x0;
          lVar12 = lVar12 + 1;
          pcVar13->attr = (attr_t)local_58;
          pcVar13->chars[0] = wVar6;
          piVar20 = local_88;
          pcVar13 = pcVar13 + 1;
        } while ((wchar_t)lVar12 < local_4c);
      }
      pRVar4 = local_60;
      piVar3 = local_68;
      if ((*piVar20 == local_50) &&
         (wVar6 = local_60->chlen, local_60->chptr[(long)wVar6 + -1].chars[0] == L' ')) {
                    /* Unresolved local var: _Bool ascending@[???] */
                    /* Unresolved local var: wchar_t[32162] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
        wVar1 = local_78->treeDirection;
        if (local_78->treeView == false) {
          wVar1 = local_78->direction;
        }
        piVar3[-2] = 0x131f81;
        piVar3[-1] = 0;
        RichString_setLen(pRVar4,wVar6 + L'\xffffffff');
        local_58 = piVar3;
        wVar6 = pRVar4->chlen;
        lVar18 = (long)wVar6;
        pcVar7 = CRT_treeStr[(ulong)(wVar1 != L'\x01') + 6];
        wVar1 = CRT_colors[9];
        piVar3[-2] = 0x131fba;
        piVar3[-1] = 0;
        sVar8 = mbstowcs(local_48,pcVar7,1);
        pRVar4 = local_60;
        if (0 < (int)sVar8) {
          wVar6 = (int)sVar8 + wVar6;
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
          local_4c = wVar6;
          piVar3[-2] = 0x131fd9;
          piVar3[-1] = 0;
          RichString_setLen(pRVar4,wVar6);
          local_68 = piVar20;
          pcVar13 = pRVar4->chptr + lVar18;
          lVar19 = lVar18;
          do {
            wVar6 = local_48[lVar19 - lVar18];
            piVar3[-2] = 0x13200c;
            piVar3[-1] = 0;
            iVar5 = iswprint(wVar6);
            pcVar13->attr = 0;
            pcVar13->chars[0] = L'\0';
            pcVar13->chars[1] = L'\0';
            pcVar13->chars[2] = L'\0';
            if (iVar5 == 0) {
              wVar6 = L'�';
            }
            pcVar13->attr = wVar1 & 0xffffff;
            lVar19 = lVar19 + 1;
            *(undefined1 (*) [16])(pcVar13->chars + 2) = (undefined1  [16])0x0;
            pcVar13->chars[0] = wVar6;
            pcVar13 = pcVar13 + 1;
            piVar20 = local_68;
          } while ((wchar_t)lVar19 < local_4c);
        }
        ppiVar15 = (int **)local_58;
        if (*piVar20 != 2) goto LAB_00131f23;
LAB_00132050:
        if (local_80->showMergedCommand == false) goto LAB_00131f23;
        piVar20 = piVar20 + 1;
        *(int *)((long)ppiVar15 + -8) = 0x132075;
        *(int *)((long)ppiVar15 + -4) = 0;
        RichString_appendAscii(local_60,local_6c,((char *)0x14915d /* "(merged)" */));
        iVar5 = *piVar20;
      }
      else {
        ppiVar15 = (int **)local_68;
        if (*piVar20 == 2) goto LAB_00132050;
LAB_00131f23:
        iVar5 = piVar20[1];
        piVar20 = piVar20 + 1;
      }
      if (iVar5 == 0) break;
      cVar11 = local_78->treeView;
      ppiVar14 = ppiVar15;
      pSVar2 = local_78;
      RVar17 = local_50;
    } while( true );
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)ppiVar15 + -8) = &UNK_001320c7;
  __stack_chk_fail();
}

