/* BarMeterMode_draw @ 001217e0 size 1844 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void BarMeterMode_draw(Meter * this, wchar_t x, wchar_t y, wchar_t w)
    */

void BarMeterMode_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  double dVar1;
  byte bVar2;
  char cVar3;
  wchar_t wVar4;
  long lVar5;
  double *pdVar6;
  bool bVar7;
  cchar_t *pcVar8;
  ColorScheme CVar9;
  int iVar10;
  wchar_t wVar11;
  int iVar12;
  wchar_t wVar13;
  char *p1;
  cchar_t *pcVar14;
  cchar_t *pcVar15;
  Object_Display p_Var16;
  cchar_t *pcVar17;
  cchar_t *pcVar18;
  wchar_t wVar19;
  undefined4 in_register_0000000c;
  ulong uVar20;
  wchar_t wVar21;
  wchar_t wVar22;
  undefined4 in_register_00000014;
  undefined4 in_register_00000034;
  wchar_t wVar23;
  long in_R8;
  long in_R9;
  long lVar24;
  wchar_t wVar25;
  long in_FS_OFFSET;
  double dVar26;
  wchar_t local_26f0;
  wchar_t blockSizes [10];
  RichString bar;

                    /* Unresolved local var: char * caption@[???]
                       Unresolved local var: wchar_t captionLen@[???]
                       Unresolved local var: wchar_t startPos@[???]
                       Unresolved local var: wchar_t offset@[???] */
  lVar5 = *(long *)(in_FS_OFFSET + 0x28);
  p_Var16 = (this->super).klass[2].display;
  if (p_Var16 == (Object_Display)0x0) {
    p1 = this->caption;
  }
  else {
    p1 = (char *)(*p_Var16)(&this->super,(RichString *)CONCAT44(in_register_00000034,x),
                            CONCAT44(in_register_00000014,y),CONCAT44(in_register_0000000c,w),in_R8,
                            in_R9);
  }
  wattrset(_stdscr,CRT_colors[0xe]);
  iVar10 = wmove(_stdscr,y,x);
  if (iVar10 != -1) {
    waddnstr(_stdscr,p1,3);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  iVar10 = wmove(_stdscr,y,x + L'\x03');
  if (iVar10 != -1) {
    waddch(_stdscr,0x5b);
  }
  iVar10 = w + L'\xfffffffc';
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  iVar10 = wmove(_stdscr,y,iVar10 + x + L'\x03');
  if (iVar10 != -1) {
    waddch(_stdscr,0x5d);
  }
  wVar25 = w + L'\xfffffffb';
  wattrset(_stdscr,*CRT_colors);
  if (wVar25 < L'\x01') goto LAB_00121d4d;
                    /* Unresolved local var: wchar_t from@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  bar.chlen = L'\0';
  bar.chstr[0]._0_12_ = SUB1612((undefined1  [16])0x0,0);
  bar.chstr[0].chars[2] = L'\0';
  bar.chstr[0]._16_12_ = SUB1612((undefined1  [16])0x0,4);
  bar.highlightAttr = L'\0';
  bar.chptr = bar.chstr;
  RichString_setLen(&bar,wVar25);
                    /* Unresolved local var: wchar_t i@[???] */
  pcVar17 = bar.chptr;
  pcVar14 = bar.chptr + 1;
  while( true ) {
    pcVar17->attr = 0;
    pcVar17->chars[0] = L'\0';
    pcVar17->chars[1] = L'\0';
    pcVar17->chars[2] = L'\0';
    pcVar17->chars[0] = L' ';
    *(undefined1 (*) [16])(pcVar17->chars + 2) = (undefined1  [16])0x0;
    if (pcVar14 == bar.chptr + 1 + (uint)(w + L'\xfffffffa')) break;
    pcVar17 = pcVar14;
    pcVar14 = pcVar14 + 1;
  }
  RichString_appendWide(&bar,L'\0',this->txtBuffer);
  pcVar17 = bar.chptr;
  CVar9 = CRT_colorScheme;
  local_26f0 = bar.chlen - wVar25;
  if (wVar25 < local_26f0) {
                    /* Unresolved local var: wchar_t pos@[???] */
    wVar13 = wVar25 * 2;
    if (SBORROW4(wVar25,wVar13) != -wVar25 < 0) {
      pcVar14 = bar.chptr + (long)w * 2;
      do {
        if (pcVar14[-10].chars[0] == L' ') {
          if (wVar13 <= wVar25) goto LAB_00121df2;
          pcVar14 = bar.chptr + wVar13;
          goto LAB_00121dec;
        }
        wVar13 = wVar13 + L'\xffffffff';
        pcVar14 = pcVar14 + -1;
      } while (wVar25 != wVar13);
    }
    goto LAB_00121dfb;
  }
  goto LAB_001219d7;
LAB_00121bd0:
  do {
                    /* Unresolved local var: uint8_t i@[???]
                       Unresolved local var: wchar_t attr@[???] */
    p_Var16 = (Object_Display)this->curAttributes;
    if (p_Var16 == (Object_Display)0x0) {
      p_Var16 = (this->super).klass[3].display;
    }
    wVar19 = blockSizes[lVar24];
    wVar13 = local_26f0 + wVar23;
                    /* Unresolved local var: wchar_t end@[???] */
    wVar21 = wVar19 + wVar13;
    wVar4 = CRT_colors[*(int *)(p_Var16 + lVar24 * 4)];
    wVar11 = L'\0';
    if (L'\xffffffff' < wVar21) {
      wVar11 = wVar21;
    }
    wVar22 = bar.chlen;
    if (wVar21 <= bar.chlen) {
      wVar22 = wVar11;
    }
                    /* Unresolved local var: wchar_t i@[???] */
    if (wVar13 < wVar22) {
      pcVar17 = bar.chptr + wVar13;
      pcVar14 = bar.chptr + (ulong)(uint)(wVar22 - wVar13) + (long)wVar13;
      if (((int)pcVar14 - (int)pcVar17 & 4U) != 0) {
        pcVar17->attr = wVar4;
        pcVar17 = pcVar17 + 1;
        if (pcVar14 == pcVar17) goto LAB_00121c76;
      }
      do {
        pcVar17->attr = wVar4;
        pcVar18 = pcVar17 + 2;
        pcVar17[1].attr = wVar4;
        pcVar17 = pcVar18;
      } while (pcVar14 != pcVar18);
    }
LAB_00121c76:
    iVar12 = wmove(_stdscr,y,iVar10 + wVar23);
    if (iVar12 != -1) {
      wVar21 = wVar25 - wVar23;
      if (wVar19 < wVar25 - wVar23) {
        wVar21 = wVar19;
      }
      wadd_wchnstr(_stdscr,bar.chptr + wVar13,wVar21);
    }
    wVar19 = wVar19 + wVar23;
    wVar23 = L'\0';
    if (L'\xffffffff' < wVar19) {
      wVar23 = wVar19;
    }
    if (wVar25 < wVar19) {
      wVar23 = wVar25;
    }
    lVar24 = lVar24 + 1;
  } while ((byte)lVar24 < this->curItems);
                    /* Unresolved local var: wchar_t end@[???] */
  if (wVar23 < wVar25) {
    wVar13 = wVar25 - wVar23;
    iVar12 = wVar23 + iVar10;
    wVar23 = local_26f0 + wVar23;
    goto LAB_00121e52;
  }
  goto LAB_00121d0e;
  while( true ) {
    wVar13 = wVar13 + L'\xffffffff';
    pcVar14 = pcVar14 + -1;
    if (wVar25 == wVar13) break;
LAB_00121dec:
    if (pcVar14[-1].chars[0] != L' ') break;
  }
LAB_00121df2:
  local_26f0 = wVar13 - wVar25;
LAB_00121dfb:
  if (wVar25 < local_26f0) {
    local_26f0 = wVar25;
  }
LAB_001219d7:
  iVar10 = x + L'\x04';
                    /* Unresolved local var: uint8_t i@[???] */
  bVar2 = this->curItems;
  wVar13 = wVar25;
  iVar12 = iVar10;
  wVar23 = local_26f0;
  if (bVar2 != 0) {
                    /* Unresolved local var: double value@[???]
                       Unresolved local var: wchar_t nextOffset@[???] */
    pdVar6 = this->values;
                    /* Unresolved local var: wchar_t j@[???] */
    uVar20 = 0;
    wVar13 = L'\0';
    dVar26 = *pdVar6;
    if (dVar26 <= 0.0) goto LAB_00121b70;
LAB_00121a50:
    dVar1 = this->total;
    if (dVar1 <= 0.0) goto LAB_00121b70;
    if (dVar1 <= dVar26) {
      dVar26 = dVar1;
    }
    dVar26 = (dVar26 / dVar1) * (double)wVar25;
    if (ABS(dVar26) < 4503599627370496.0) {
      dVar26 = (double)((ulong)((double)(long)dVar26 +
                               (double)(-(ulong)((double)(long)dVar26 < dVar26) & 0x3ff0000000000000
                                       )) | (ulong)dVar26 & 0x8000000000000000);
    }
    wVar21 = (wchar_t)dVar26;
    wVar23 = wVar13;
    wVar13 = wVar21 + wVar13;
    do {
      blockSizes[uVar20] = wVar21;
      wVar21 = L'\0';
      if (L'\xffffffff' < wVar13) {
        wVar21 = wVar13;
      }
      bVar7 = wVar25 < wVar13;
      wVar13 = wVar21;
      if (bVar7) {
        wVar13 = wVar25;
      }
      if (wVar23 < wVar13) {
        pcVar14 = pcVar17 + (long)wVar23 + (long)local_26f0;
        pcVar18 = pcVar17 + (ulong)(uint)(wVar13 - wVar23) + (long)wVar23 + (long)local_26f0;
        do {
          while (pcVar14->chars[0] == L' ') {
            if (CVar9 == COLORSCHEME_MONOCHROME) {
              cVar3 = ((char *)0x14db88 /* "|#*@$%&." */)[(int)uVar20];
              pcVar15 = pcVar14;
              do {
                pcVar15->attr = 0;
                pcVar15->chars[0] = L'\0';
                pcVar15->chars[1] = L'\0';
                pcVar15->chars[2] = L'\0';
                pcVar14 = pcVar15 + 1;
                *(undefined1 (*) [16])(pcVar15->chars + 2) = (undefined1  [16])0x0;
                pcVar15->chars[0] = (int)cVar3;
                if (pcVar18 == pcVar14) goto LAB_00121b50;
                pcVar8 = pcVar15 + 1;
                pcVar15 = pcVar14;
              } while (pcVar8->chars[0] == L' ');
              break;
            }
            do {
              pcVar15 = pcVar14;
              pcVar15->attr = 0;
              pcVar15->chars[0] = L'\0';
              pcVar15->chars[1] = L'\0';
              pcVar15->chars[2] = L'\0';
              *(undefined1 (*) [16])(pcVar15->chars + 2) = (undefined1  [16])0x0;
              pcVar15->chars[0] = L'|';
              if (pcVar18 == pcVar15 + 1) goto LAB_00121b50;
              pcVar14 = pcVar15 + 1;
            } while (pcVar15[1].chars[0] == L' ');
            pcVar14 = pcVar15 + 2;
            if (pcVar18 == pcVar14) goto LAB_00121b50;
          }
          pcVar14 = pcVar14 + 1;
        } while (pcVar18 != pcVar14);
      }
LAB_00121b50:
      uVar20 = uVar20 + 1;
      if (bVar2 == uVar20) {
        lVar24 = 0;
        wVar23 = L'\0';
        goto LAB_00121bd0;
      }
      dVar26 = pdVar6[uVar20];
      if (0.0 < dVar26) goto LAB_00121a50;
LAB_00121b70:
      wVar21 = L'\0';
      wVar23 = wVar13;
    } while( true );
  }
LAB_00121e52:
  local_26f0 = local_26f0 + wVar25;
  wVar25 = CRT_colors[0x30];
  wVar21 = L'\0';
  if (L'\xffffffff' < local_26f0) {
    wVar21 = local_26f0;
  }
  wVar19 = bar.chlen;
  if (local_26f0 <= bar.chlen) {
    wVar19 = wVar21;
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (wVar23 < wVar19) {
    pcVar17 = bar.chptr + wVar23;
    pcVar14 = bar.chptr + (long)wVar23 + (ulong)(uint)(wVar19 - wVar23);
    pcVar18 = pcVar17;
    if (((int)pcVar14 - (int)pcVar17 & 4U) != 0) {
      pcVar17->attr = wVar25;
      pcVar18 = pcVar17 + 1;
      if (pcVar14 == pcVar17 + 1) goto LAB_00121ed6;
    }
    do {
      pcVar18->attr = wVar25;
      pcVar17 = pcVar18 + 2;
      pcVar18[1].attr = wVar25;
      pcVar18 = pcVar17;
    } while (pcVar14 != pcVar17);
  }
LAB_00121ed6:
  iVar12 = wmove(_stdscr,y,iVar12);
  if (iVar12 != -1) {
    wadd_wchnstr(_stdscr,bar.chptr + wVar23,wVar13);
  }
LAB_00121d0e:
  if (L'Ş' < bar.chlen) {
    free(bar.chptr);
    bar.chptr = bar.chstr;
  }
  wmove(_stdscr,y,w + L'\xfffffffc' + iVar10);
  wattrset(_stdscr,*CRT_colors);
LAB_00121d4d:
  if (lVar5 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

