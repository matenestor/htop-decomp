/* Process_writeCommand @ 00122550 size 655 */

/* DWARF original prototype: void Process_writeCommand(Process * this, wchar_t attr, wchar_t
   baseAttr, RichString * str) */

void Process_writeCommand(Process *this,wchar_t attr,wchar_t baseAttr,RichString *str)

{
  cchar_t *pcVar1;
  _Bool _Var2;
  _Bool _Var3;
  Settings__2 *pSVar4;
  wchar_t wVar5;
  cchar_t *pcVar6;
  cchar_t *pcVar7;
  long lVar8;
  wchar_t wVar9;
  ProcessCmdlineHighlight *pPVar10;
  wchar_t wVar11;
  wchar_t wVar12;
  ulong uVar13;
  char *pcVar14;
  ulong uVar15;
  wchar_t wVar16;
  long lVar17;
  wchar_t wVar18;

  wVar18 = str->chlen;
  pcVar14 = (this->mergedCommand).str;
  pSVar4 = ((this->super).host)->settings;
  _Var2 = pSVar4->highlightBaseName;
  _Var3 = pSVar4->highlightDeletedExe;
  if (pcVar14 != (char *)0x0) {
    RichString_appendWide(str,attr,pcVar14);
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t hlCount@[???] */
    uVar13 = (this->mergedCommand).highlightCount;
    uVar15 = 8;
    if (uVar13 < 9) {
      uVar15 = uVar13;
    }
    if (uVar13 == 0) {
      return;
    }
    pPVar10 = (this->mergedCommand).highlights;
    uVar13 = 0;
    do {
                    /* Unresolved local var: ProcessCmdlineHighlight * hl@[???] */
      if (((pPVar10->length != 0) &&
          ((wVar11 = pPVar10->flags, (wVar11 & 2U) == 0 || (_Var2 != false)))) &&
         ((((wVar11 & 8U) == 0 && ((wVar11 & 0x10U) == 0)) || (_Var3 != false)))) {
                    /* Unresolved local var: wchar_t end@[???] */
        wVar11 = pPVar10->attr;
        wVar16 = (int)pPVar10->offset + wVar18;
        wVar5 = (int)pPVar10->length + wVar16;
        wVar12 = L'\0';
        if (L'\xffffffff' < wVar5) {
          wVar12 = wVar5;
        }
        wVar9 = str->chlen;
        if (wVar5 <= str->chlen) {
          wVar9 = wVar12;
        }
                    /* Unresolved local var: wchar_t i@[???] */
        if (wVar16 < wVar9) {
          pcVar6 = str->chptr + wVar16;
          pcVar1 = str->chptr + (ulong)(uint)(wVar9 - wVar16) + (long)wVar16;
          if (((int)pcVar1 - (int)pcVar6 & 4U) != 0) {
            pcVar6->attr = wVar11;
            pcVar6 = pcVar6 + 1;
            if (pcVar6 == pcVar1) goto LAB_00122670;
          }
          do {
            pcVar6->attr = wVar11;
            pcVar7 = pcVar6 + 2;
            pcVar6[1].attr = wVar11;
            pcVar6 = pcVar7;
          } while (pcVar7 != pcVar1);
        }
      }
LAB_00122670:
      uVar13 = uVar13 + 1;
      pPVar10 = pPVar10 + 1;
      if (uVar15 <= uVar13) {
        return;
      }
    } while( true );
  }
                    /* Unresolved local var: wchar_t len@[???]
                       Unresolved local var: char * cmdline@[???] */
  pcVar14 = this->cmdline;
  if (_Var2 == false) {
    wVar12 = L'\0';
    if (pSVar4->showProgramPath != false) goto LAB_0012270c;
                    /* Unresolved local var: wchar_t basename@[???]
                       Unresolved local var: wchar_t i@[???] */
    wVar11 = this->cmdlineBasenameEnd;
    lVar17 = 0;
    if (L'\0' < wVar11) goto LAB_001226be;
  }
  else {
    wVar11 = this->cmdlineBasenameEnd;
    if (wVar11 < L'\x01') {
      lVar17 = 0;
    }
    else {
LAB_001226be:
      lVar8 = 1;
      lVar17 = 0;
      while( true ) {
        wVar12 = (wchar_t)lVar8;
        if (pcVar14[lVar8 + -1] == '/') {
          lVar17 = (long)wVar12;
        }
        else if (pcVar14[lVar8 + -1] == ':') goto LAB_0012270c;
        if (lVar8 == wVar11) break;
        lVar8 = lVar8 + 1;
      }
      wVar11 = wVar11 - (int)lVar17;
    }
    if (pSVar4->showProgramPath != false) {
      wVar18 = wVar18 + (int)lVar17;
      wVar12 = wVar11;
      goto LAB_0012270c;
    }
  }
  pcVar14 = pcVar14 + lVar17;
  wVar12 = wVar11;
LAB_0012270c:
  RichString_appendWide(str,attr,pcVar14);
  if (pSVar4->highlightBaseName != false) {
                    /* Unresolved local var: wchar_t end@[???] */
    wVar12 = wVar12 + wVar18;
    wVar11 = L'\0';
    if (L'\xffffffff' < wVar12) {
      wVar11 = wVar12;
    }
    wVar5 = str->chlen;
    if (wVar12 <= str->chlen) {
      wVar5 = wVar11;
    }
                    /* Unresolved local var: wchar_t i@[???] */
    if (wVar18 < wVar5) {
      pcVar6 = str->chptr + wVar18;
      pcVar1 = str->chptr + (ulong)(uint)(wVar5 - wVar18) + (long)wVar18;
      if (((int)pcVar1 - (int)pcVar6 & 4U) != 0) {
        pcVar6->attr = baseAttr;
        pcVar6 = pcVar6 + 1;
        if (pcVar1 == pcVar6) {
          return;
        }
      }
      do {
        pcVar6->attr = baseAttr;
        pcVar6[1].attr = baseAttr;
        if (pcVar1 == pcVar6 + 2) {
          return;
        }
        pcVar6[2].attr = baseAttr;
        pcVar7 = pcVar6 + 4;
        pcVar6[3].attr = baseAttr;
        pcVar6 = pcVar7;
      } while (pcVar1 != pcVar7);
    }
  }
  return;
}

