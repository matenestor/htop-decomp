#include "htop.h"

/* BlankMeter_updateValues @ 0x11fbb0 */

/* DWARF original prototype: void BlankMeter_updateValues(Meter * this) */

void BlankMeter_updateValues(Meter *this)

{
  this->txtBuffer[0] = '\0';
  return;
}


/* BlankMeter_display_lto_priv_0 @ 0x11fbc0 */

void BlankMeter_display_lto_priv_0(void)

{
  return;
}


/* Meter_delete @ 0x11fe30 */

void Meter_delete(Meter_ *cast)

{
  Object_Display p_Var1;
  long in_RCX;
  long in_RDX;
  RichString *in_RSI;
  long in_R8;
  long in_R9;

  if (cast != (Meter_ *)0x0) {
    p_Var1 = (cast->super).klass[1].display;
    if (p_Var1 != (Object_Display)0x0) {
      (*(code *)(p_Var1))(&cast->super,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    }
    free((cast->drawData).values);
    free(cast->caption);
    free(cast->values);
    free(cast);
    return;
  }
  return;
}


/* TextMeterMode_draw @ 0x1209c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void TextMeterMode_draw(Meter * this, int x, int y, int w)
    */

void TextMeterMode_draw(Meter *this,int x,int y,int w)

{
  undefined1 __frame[0x2758] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2718;
  long lVar1;
  Object_Display p_Var2;
  ObjectClass *pOVar3;
  int iVar4;
  int iVar5;
  size_t a3;
  undefined4 in_register_0000000c;
  undefined4 in_register_00000014;
  long a2;
  undefined4 in_register_00000034;
  long in_R8;
  long in_R9;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: char * caption@[???]
                       Unresolved local var: int captionLen@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  p_Var2 = (this->super).klass[2].display;
  if (p_Var2 == (Object_Display)0x0) {
    (*(char *(*))(__fp - 0x26c8)) = this->caption;
  }
  else {
    (*(char *(*))(__fp - 0x26c8)) = (char *)(*(code *)(p_Var2))(&this->super,(RichString *)CONCAT44(in_register_00000034,x),
                                   CONCAT44(in_register_00000014,y),CONCAT44(in_register_0000000c,w)
                                   ,in_R8,in_R9);
  }
  wattrset(_stdscr,CRT_colors[0xe]);
  iVar4 = wmove(_stdscr,y,x);
  if (iVar4 != -1) {
    waddnstr(_stdscr,(*(char *(*))(__fp - 0x26c8)),w);
  }
  wattrset(_stdscr,*CRT_colors);
  a3 = strlen((*(char *(*))(__fp - 0x26c8)));
  iVar4 = w - (int)a3;
  if (0 < iVar4) {
    pOVar3 = (this->super).klass;
    (*(RichString (*))(__fp - 0x26b8)).chptr = (*(RichString (*))(__fp - 0x26b8)).chstr;
    (*(RichString (*))(__fp - 0x26b8)).chlen = 0;
    p_Var2 = pOVar3->display;
    (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 0)) = SUB1612((undefined16)0x0,0);
    (*(RichString (*))(__fp - 0x26b8)).highlightAttr = 0;
    (*(RichString (*))(__fp - 0x26b8)).chstr[0].chars[2] = 0;
    (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 16)) = SUB1612((undefined16)0x0,4);
    if (p_Var2 == (Object_Display)0x0) {
      RichString_writeWide(&(*(RichString (*))(__fp - 0x26b8)),CRT_colors[*(int *)pOVar3[3].display],this->txtBuffer);
    }
    else {
      (*(code *)(p_Var2))(&this->super,&(*(RichString (*))(__fp - 0x26b8)),a2,a3,in_R8,in_R9);
    }
    iVar5 = wmove(_stdscr,y,x + (int)a3);
    if (iVar5 != -1) {
      wadd_wchnstr(_stdscr,(*(RichString (*))(__fp - 0x26b8)).chptr,iVar4);
    }
    if (350 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
      free((*(RichString (*))(__fp - 0x26b8)).chptr);
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LEDMeterMode_draw @ 0x120ba0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* DWARF original prototype: void LEDMeterMode_draw(Meter * this, int x, int y, int w)
    */

void LEDMeterMode_draw(Meter *this,int x,int y,int w)

{
  undefined1 __frame[0x2788] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2748;
  int wVar1;
  long lVar2;
  ObjectClass *a2;
  Object_Display p_Var3;
  int iVar4;
  int iVar5;
  char *p1;
  size_t sVar6;
  long lVar7;
  undefined4 in_register_0000000c;
  long lVar8;
  long a2_00;
  RichString *pRVar9;
  long in_R8;
  long in_R9;
  uint uVar10;
  int p1_00;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int yText@[???]
                       Unresolved local var: char * caption@[???]
                       Unresolved local var: int xx@[???]
                       Unresolved local var: int len@[???] */
  lVar7 = CONCAT44(in_register_0000000c,w);
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  LEDMeterMode_digits = LEDMeterMode_digitsAscii;
  (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 0)) = SUB1612((undefined16)0x0,0);
  if (CRT_utf8) {
    LEDMeterMode_digits = LEDMeterMode_digitsUtf8;
  }
  a2 = (this->super).klass;
  (*(RichString (*))(__fp - 0x26b8)).chlen = 0;
  (*(RichString (*))(__fp - 0x26b8)).highlightAttr = 0;
  (*(RichString (*))(__fp - 0x26b8)).chptr = (*(RichString (*))(__fp - 0x26b8)).chstr;
  (*(RichString (*))(__fp - 0x26b8)).chstr[0].chars[2] = 0;
  (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 16)) = SUB1612((undefined16)0x0,4);
  if (a2->display == (Object_Display)0x0) {
    lVar7 = (long)*(int *)a2[3].display;
    RichString_writeWide(&(*(RichString (*))(__fp - 0x26b8)),CRT_colors[lVar7],this->txtBuffer);
  }
  else {
    (*(code *)(a2->display))(&this->super,&(*(RichString (*))(__fp - 0x26b8)),(long)a2,lVar7,in_R8,in_R9);
  }
  (*(int (*))(__fp - 0x26f4)) = y + 2;
  if (CRT_utf8 != false) {
    (*(int (*))(__fp - 0x26f4)) = y + 1;
  }
  pRVar9 = (RichString *)(ulong)(uint)CRT_colors[0x16];
  wattrset(_stdscr,CRT_colors[0x16]);
  p_Var3 = (this->super).klass[2].display;
  if (p_Var3 == (Object_Display)0x0) {
    p1 = this->caption;
  }
  else {
    p1 = (char *)(*(code *)(p_Var3))(&this->super,pRVar9,a2_00,lVar7,in_R8,in_R9);
  }
  iVar4 = wmove(_stdscr,(*(int (*))(__fp - 0x26f4)),x);
  if (iVar4 != -1) {
    waddnstr(_stdscr,p1,-1);
  }
  sVar6 = strlen(p1);
  iVar4 = x + (int)sVar6;
  lVar7 = (long)(*(RichString (*))(__fp - 0x26b8)).chlen;
                    /* Unresolved local var: int i@[???] */
  if (0 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
    lVar8 = 0;
                    /* Unresolved local var: int c@[???] */
    do {
      wVar1 = *(int *)((long)((*(RichString (*))(__fp - 0x26b8)).chptr)->chars + lVar8);
      uVar10 = wVar1 + -48;
      if (uVar10 < 10) {
        if (w <= (iVar4 - x) + 3) break;
                    /* Unresolved local var: int i@[???] */
        p1_00 = y;
        do {
          iVar5 = wmove(_stdscr,p1_00,iVar4);
          if (iVar5 != -1) {
            waddnstr(_stdscr,LEDMeterMode_digits[(int)uVar10],-1);
          }
          uVar10 = uVar10 + 10;
          p1_00 = p1_00 + 1;
        } while (uVar10 != wVar1 + -18);
        iVar4 = iVar4 + 4;
      }
      else {
        if (w <= iVar4 - x) break;
        (*(cchar_t (*))(__fp - 0x26d8)).attr = 0;
        (*(cchar_t (*))(__fp - 0x26d8)).chars[1] = 0;
        (*(cchar_t (*))(__fp - 0x26d8)).chars[2] = 0;
        (*(ulong *)((char *)&(*(cchar_t (*))(__fp - 0x26d8)) + 16)) = SUB1612((undefined16)0x0,4);
        (*(cchar_t (*))(__fp - 0x26d8)).chars[0] = wVar1;
        iVar5 = wmove(_stdscr,(*(int (*))(__fp - 0x26f4)),iVar4);
        if (iVar5 != -1) {
          wadd_wch(_stdscr,&(*(cchar_t (*))(__fp - 0x26d8)));
        }
        iVar4 = iVar4 + 1;
      }
      lVar8 = lVar8 + 0x1c;
    } while (lVar8 != lVar7 * 0x1c);
  }
  wattrset(_stdscr,*CRT_colors);
  if (350 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
    free((*(RichString (*))(__fp - 0x26b8)).chptr);
  }
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Meter_setMode @ 0x121460 */

/* DWARF original prototype: void Meter_setMode(Meter * this, int modeIndex) */

void Meter_setMode(Meter *this,int modeIndex)

{
  int iVar1;
  int wVar2;
  ObjectClass *pOVar3;
  Meter_Draw a2;
  Object_Delete p_Var4;
  long in_RCX;
  long in_R8;
  long in_R9;

  if (modeIndex < 1) {
    if (modeIndex == 0) {
      modeIndex = 1;
    }
    pOVar3 = (this->super).klass;
    iVar1 = *(int *)&pOVar3[2].compare;
  }
  else {
    if (this->mode == modeIndex) {
      return;
    }
    pOVar3 = (this->super).klass;
    iVar1 = *(int *)&pOVar3[2].compare;
  }
  if (iVar1 == 0) {
    a2 = pOVar3[2].extends;
    p_Var4 = pOVar3[1].delete;
    this->draw = a2;
    if (p_Var4 != (Object_Delete)0x0) {
      (*(code *)(p_Var4))(&this->super,(ulong)(uint)modeIndex,(long)a2,in_RCX,in_R8,in_R9);
    }
  }
  else {
                    /* Unresolved local var: MeterMode * mode@[???] */
    free((this->drawData).values);
    (this->drawData).values = (double *)0x0;
    (this->drawData).nValues = 0;
    wVar2 = Meter_modes[modeIndex]->h;
    this->draw = Meter_modes[modeIndex]->draw;
    this->h = wVar2;
  }
  this->mode = modeIndex;
  return;
}


/* BarMeterMode_draw @ 0x1217e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void BarMeterMode_draw(Meter * this, int x, int y, int w)
    */

void BarMeterMode_draw(Meter *this,int x,int y,int w)

{
  undefined1 __frame[0x2778] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2738;
  double dVar1;
  byte bVar2;
  char cVar3;
  int wVar4;
  long lVar5;
  double *pdVar6;
  bool bVar7;
  cchar_t *pcVar8;
  ColorScheme CVar9;
  int iVar10;
  int wVar11;
  int iVar12;
  int wVar13;
  char *p1;
  cchar_t *pcVar14;
  cchar_t *pcVar15;
  Object_Display p_Var16;
  cchar_t *pcVar17;
  cchar_t *pcVar18;
  int wVar19;
  undefined4 in_register_0000000c;
  ulong uVar20;
  int wVar21;
  int wVar22;
  undefined4 in_register_00000014;
  undefined4 in_register_00000034;
  int wVar23;
  long in_R8;
  long in_R9;
  long lVar24;
  int wVar25;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar26;

                    /* Unresolved local var: char * caption@[???]
                       Unresolved local var: int captionLen@[???]
                       Unresolved local var: int startPos@[???]
                       Unresolved local var: int offset@[???] */
  lVar5 = *(long *)(in_FS_OFFSET + 0x28);
  p_Var16 = (this->super).klass[2].display;
  if (p_Var16 == (Object_Display)0x0) {
    p1 = this->caption;
  }
  else {
    p1 = (char *)(*(code *)(p_Var16))(&this->super,(RichString *)CONCAT44(in_register_00000034,x),
                            CONCAT44(in_register_00000014,y),CONCAT44(in_register_0000000c,w),in_R8,
                            in_R9);
  }
  wattrset(_stdscr,CRT_colors[0xe]);
  iVar10 = wmove(_stdscr,y,x);
  if (iVar10 != -1) {
    waddnstr(_stdscr,p1,3);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  iVar10 = wmove(_stdscr,y,x + 3);
  if (iVar10 != -1) {
    waddch(_stdscr,0x5b);
  }
  iVar10 = w + -4;
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  iVar10 = wmove(_stdscr,y,iVar10 + x + 3);
  if (iVar10 != -1) {
    waddch(_stdscr,0x5d);
  }
  wVar25 = w + -5;
  wattrset(_stdscr,*CRT_colors);
  if (wVar25 < 1) goto LAB_00121d4d;
                    /* Unresolved local var: int from@[???]
                       Unresolved local var: int newLen@[???] */
  (*(RichString (*))(__fp - 0x26b8)).chlen = 0;
  (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 0)) = SUB1612((undefined16)0x0,0);
  (*(RichString (*))(__fp - 0x26b8)).chstr[0].chars[2] = 0;
  (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 16)) = SUB1612((undefined16)0x0,4);
  (*(RichString (*))(__fp - 0x26b8)).highlightAttr = 0;
  (*(RichString (*))(__fp - 0x26b8)).chptr = (*(RichString (*))(__fp - 0x26b8)).chstr;
  RichString_setLen(&(*(RichString (*))(__fp - 0x26b8)),wVar25);
                    /* Unresolved local var: int i@[???] */
  pcVar17 = (*(RichString (*))(__fp - 0x26b8)).chptr;
  pcVar14 = (*(RichString (*))(__fp - 0x26b8)).chptr + 1;
  while( true ) {
    pcVar17->attr = 0;
    pcVar17->chars[0] = 0;
    pcVar17->chars[1] = 0;
    pcVar17->chars[2] = 0;
    pcVar17->chars[0] = ' ';
    *(undefined16 *)(*(undefined1 (*) [16])(pcVar17->chars + 2)) = (undefined16)0x0;
    if (pcVar14 == (*(RichString (*))(__fp - 0x26b8)).chptr + 1 + (uint)(w + -6)) break;
    pcVar17 = pcVar14;
    pcVar14 = pcVar14 + 1;
  }
  RichString_appendWide(&(*(RichString (*))(__fp - 0x26b8)),0,this->txtBuffer);
  pcVar17 = (*(RichString (*))(__fp - 0x26b8)).chptr;
  CVar9 = CRT_colorScheme;
  (*(int (*))(__fp - 0x26f0)) = (*(RichString (*))(__fp - 0x26b8)).chlen - wVar25;
  if (wVar25 < (*(int (*))(__fp - 0x26f0))) {
                    /* Unresolved local var: int pos@[???] */
    wVar13 = wVar25 * 2;
    if (SBORROW4(wVar25,wVar13) != -wVar25 < 0) {
      pcVar14 = (*(RichString (*))(__fp - 0x26b8)).chptr + (long)w * 2;
      do {
        if (pcVar14[-10].chars[0] == ' ') {
          if (wVar13 <= wVar25) goto LAB_00121df2;
          pcVar14 = (*(RichString (*))(__fp - 0x26b8)).chptr + wVar13;
          goto LAB_00121dec;
        }
        wVar13 = wVar13 + -1;
        pcVar14 = pcVar14 + -1;
      } while (wVar25 != wVar13);
    }
    goto LAB_00121dfb;
  }
  goto LAB_001219d7;
LAB_00121bd0:
  do {
                    /* Unresolved local var: uint8_t i@[???]
                       Unresolved local var: int attr@[???] */
    p_Var16 = (Object_Display)this->curAttributes;
    if (p_Var16 == (Object_Display)0x0) {
      p_Var16 = (this->super).klass[3].display;
    }
    wVar19 = (*(int (*) [10])(__fp - 0x26e8))[lVar24];
    wVar13 = (*(int (*))(__fp - 0x26f0)) + wVar23;
                    /* Unresolved local var: int end@[???] */
    wVar21 = wVar19 + wVar13;
    wVar4 = CRT_colors[*(int *)(p_Var16 + lVar24 * 4)];
    wVar11 = 0;
    if (-1 < wVar21) {
      wVar11 = wVar21;
    }
    wVar22 = (*(RichString (*))(__fp - 0x26b8)).chlen;
    if (wVar21 <= (*(RichString (*))(__fp - 0x26b8)).chlen) {
      wVar22 = wVar11;
    }
                    /* Unresolved local var: int i@[???] */
    if (wVar13 < wVar22) {
      pcVar17 = (*(RichString (*))(__fp - 0x26b8)).chptr + wVar13;
      pcVar14 = (*(RichString (*))(__fp - 0x26b8)).chptr + (ulong)(uint)(wVar22 - wVar13) + (long)wVar13;
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
      wadd_wchnstr(_stdscr,(*(RichString (*))(__fp - 0x26b8)).chptr + wVar13,wVar21);
    }
    wVar19 = wVar19 + wVar23;
    wVar23 = 0;
    if (-1 < wVar19) {
      wVar23 = wVar19;
    }
    if (wVar25 < wVar19) {
      wVar23 = wVar25;
    }
    lVar24 = lVar24 + 1;
  } while ((byte)lVar24 < this->curItems);
                    /* Unresolved local var: int end@[???] */
  if (wVar23 < wVar25) {
    wVar13 = wVar25 - wVar23;
    iVar12 = wVar23 + iVar10;
    wVar23 = (*(int (*))(__fp - 0x26f0)) + wVar23;
    goto LAB_00121e52;
  }
  goto LAB_00121d0e;
  while( true ) {
    wVar13 = wVar13 + -1;
    pcVar14 = pcVar14 + -1;
    if (wVar25 == wVar13) break;
LAB_00121dec:
    if (pcVar14[-1].chars[0] != ' ') break;
  }
LAB_00121df2:
  (*(int (*))(__fp - 0x26f0)) = wVar13 - wVar25;
LAB_00121dfb:
  if (wVar25 < (*(int (*))(__fp - 0x26f0))) {
    (*(int (*))(__fp - 0x26f0)) = wVar25;
  }
LAB_001219d7:
  iVar10 = x + 4;
                    /* Unresolved local var: uint8_t i@[???] */
  bVar2 = this->curItems;
  wVar13 = wVar25;
  iVar12 = iVar10;
  wVar23 = (*(int (*))(__fp - 0x26f0));
  if (bVar2 != 0) {
                    /* Unresolved local var: double value@[???]
                       Unresolved local var: int nextOffset@[???] */
    pdVar6 = this->values;
                    /* Unresolved local var: int j@[???] */
    uVar20 = 0;
    wVar13 = 0;
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
      dVar26 = __builtin_ceil(dVar26);
    }
    wVar21 = (int)dVar26;
    wVar23 = wVar13;
    wVar13 = wVar21 + wVar13;
    do {
      (*(int (*) [10])(__fp - 0x26e8))[uVar20] = wVar21;
      wVar21 = 0;
      if (-1 < wVar13) {
        wVar21 = wVar13;
      }
      bVar7 = wVar25 < wVar13;
      wVar13 = wVar21;
      if (bVar7) {
        wVar13 = wVar25;
      }
      if (wVar23 < wVar13) {
        pcVar14 = pcVar17 + (long)wVar23 + (long)(*(int (*))(__fp - 0x26f0));
        pcVar18 = pcVar17 + (ulong)(uint)(wVar13 - wVar23) + (long)wVar23 + (long)(*(int (*))(__fp - 0x26f0));
        do {
          while (pcVar14->chars[0] == ' ') {
            if (CVar9 == COLORSCHEME_MONOCHROME) {
              cVar3 = ((char *)(long)&BarMeterMode_characters /* "|#*@$%&." */)[(int)uVar20];
              pcVar15 = pcVar14;
              do {
                pcVar15->attr = 0;
                pcVar15->chars[0] = 0;
                pcVar15->chars[1] = 0;
                pcVar15->chars[2] = 0;
                pcVar14 = pcVar15 + 1;
                *(undefined16 *)(*(undefined1 (*) [16])(pcVar15->chars + 2)) = (undefined16)0x0;
                pcVar15->chars[0] = (int)cVar3;
                if (pcVar18 == pcVar14) goto LAB_00121b50;
                pcVar8 = pcVar15 + 1;
                pcVar15 = pcVar14;
              } while (pcVar8->chars[0] == ' ');
              break;
            }
            do {
              pcVar15 = pcVar14;
              pcVar15->attr = 0;
              pcVar15->chars[0] = 0;
              pcVar15->chars[1] = 0;
              pcVar15->chars[2] = 0;
              *(undefined16 *)(*(undefined1 (*) [16])(pcVar15->chars + 2)) = (undefined16)0x0;
              pcVar15->chars[0] = '|';
              if (pcVar18 == pcVar15 + 1) goto LAB_00121b50;
              pcVar14 = pcVar15 + 1;
            } while (pcVar15[1].chars[0] == ' ');
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
        wVar23 = 0;
        goto LAB_00121bd0;
      }
      dVar26 = pdVar6[uVar20];
      if (0.0 < dVar26) goto LAB_00121a50;
LAB_00121b70:
      wVar21 = 0;
      wVar23 = wVar13;
    } while( true );
  }
LAB_00121e52:
  (*(int (*))(__fp - 0x26f0)) = (*(int (*))(__fp - 0x26f0)) + wVar25;
  wVar25 = CRT_colors[0x30];
  wVar21 = 0;
  if (-1 < (*(int (*))(__fp - 0x26f0))) {
    wVar21 = (*(int (*))(__fp - 0x26f0));
  }
  wVar19 = (*(RichString (*))(__fp - 0x26b8)).chlen;
  if ((*(int (*))(__fp - 0x26f0)) <= (*(RichString (*))(__fp - 0x26b8)).chlen) {
    wVar19 = wVar21;
  }
                    /* Unresolved local var: int i@[???] */
  if (wVar23 < wVar19) {
    pcVar17 = (*(RichString (*))(__fp - 0x26b8)).chptr + wVar23;
    pcVar14 = (*(RichString (*))(__fp - 0x26b8)).chptr + (long)wVar23 + (ulong)(uint)(wVar19 - wVar23);
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
    wadd_wchnstr(_stdscr,(*(RichString (*))(__fp - 0x26b8)).chptr + wVar23,wVar13);
  }
LAB_00121d0e:
  if (350 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
    free((*(RichString (*))(__fp - 0x26b8)).chptr);
    (*(RichString (*))(__fp - 0x26b8)).chptr = (*(RichString (*))(__fp - 0x26b8)).chstr;
  }
  wmove(_stdscr,y,w + -4 + iVar10);
  wattrset(_stdscr,*CRT_colors);
LAB_00121d4d:
  if (lVar5 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Meter_new @ 0x123520 */

Meter_3 * Meter_new(Machine_2 *host,uint param,MeterClass_3 *type)

{
  double dVar1;
  byte bVar2;
  code *pcVar3;
  Meter_3 *this;
  char *pcVar4;
  double *pdVar5;
  long in_RCX;
  long a2;
  long a1;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: void * data@[???] */
  a1 = 0x178;
  this = calloc(1,0x178);
  if (this != (Meter_3 *)0x0) {
    bVar2 = type->maxItems;
    (this->super).klass = &type->super;
    this->h = 1;
    this->param = param;
    this->host = host;
    this->curItems = bVar2;
    this->curAttributes = (int *)0x0;
    pdVar5 = (double *)0x0;
    if (bVar2 != 0) {
                    /* Unresolved local var: void * data@[???] */
      a1 = 8;
      pdVar5 = calloc((ulong)bVar2,8);
      if (pdVar5 == (double *)0x0) goto LAB_001235ef;
    }
    dVar1 = type->total;
    this->values = pdVar5;
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = type->caption;
    this->total = dVar1;
    pcVar4 = strdup(pcVar4);
    if (pcVar4 != (char *)0x0) {
      this->caption = pcVar4;
      pcVar3 = (this->super).klass[1].extends;
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)((long)this,a1,a2,in_RCX,in_R8,in_R9);
      }
      Meter_setMode((Meter *)this,type->defaultMode);
      return this;
    }
  }
LAB_001235ef:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Meter_setCaption @ 0x123750 */

/* DWARF original prototype: void Meter_setCaption(Meter * this, char * caption) */

void Meter_setCaption(Meter *this,char *caption)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = this->caption;
  if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,caption), iVar1 == 0)) {
    return;
  }
  free(pcVar2);
                    /* Unresolved local var: char * data@[???] */
  pcVar2 = strdup(caption);
  if (pcVar2 != (char *)0x0) {
    this->caption = pcVar2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* GraphMeterMode_draw @ 0x1237b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void GraphMeterMode_draw(Meter * this, int x, int y, int w)
    */

void GraphMeterMode_draw(Meter *this,int x,int y,int w)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  Object_Display p_Var2;
  Machine *pMVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *p1;
  long lVar8;
  double *pdVar9;
  ulong uVar10;
  double *pdVar11;
  undefined4 in_register_0000000c;
  long lVar12;
  char **ppcVar13;
  size_t __size;
  int iVar14;
  undefined4 in_register_00000014;
  ulong uVar15;
  undefined4 in_register_00000034;
  long in_R9;
  int wVar16;
  ulong uVar17;
  int iVar18;
  uint uVar19;
  double __x;
  double dVar20;

                    /* Unresolved local var: char * caption@[???]
                       Unresolved local var: int captionLen@[???]
                       Unresolved local var: GraphData * data@[???]
                       Unresolved local var: size_t nValues@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: char * * GraphMeterMode_dots@[???]
                       Unresolved local var: int GraphMeterMode_pixPerRow@[???]
                       Unresolved local var: size_t i@[???] */
  p_Var2 = (this->super).klass[2].display;
  if (p_Var2 == (Object_Display)0x0) {
    p1 = this->caption;
  }
  else {
    p1 = (char *)(*(code *)(p_Var2))(&this->super,(RichString *)CONCAT44(in_register_00000034,x),
                           CONCAT44(in_register_00000014,y),CONCAT44(in_register_0000000c,w),
                           (long)this,in_R9);
  }
  wattrset(_stdscr,CRT_colors[0xe]);
  iVar4 = wmove(_stdscr,y,x);
  if (iVar4 != -1) {
    waddnstr(_stdscr,p1,3);
  }
  iVar4 = w + -3;
  uVar17 = (this->drawData).nValues;
  if (((int)(uVar17 >> 1) < iVar4) && (uVar17 < 0x8000)) {
                    /* Unresolved local var: size_t oldNValues@[???] */
    uVar10 = (uVar17 >> 1) + uVar17;
    pdVar9 = (this->drawData).values;
    if (uVar10 <= (ulong)((long)iVar4 * 2)) {
      uVar10 = (long)iVar4 * 2;
    }
    if (0x8000 < uVar10) {
      uVar10 = 0x8000;
    }
    (this->drawData).nValues = uVar10;
    __size = uVar10 * 8;
                    /* Unresolved local var: void * data@[???] */
    pdVar11 = realloc(pdVar9,__size);
    if (pdVar11 == (double *)0x0) {
      free(pdVar9);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (this->drawData).values = pdVar11;
    lVar12 = (this->drawData).nValues - uVar17;
    if (__size <= (ulong)(lVar12 * 8)) {
      __size = lVar12 * 8;
    }
    __memmove_chk(pdVar11 + lVar12,pdVar11,uVar17 * 8,__size + lVar12 * -8);
    memset((this->drawData).values,0,((this->drawData).nValues - uVar17) * 8);
    uVar17 = (this->drawData).nValues;
  }
  if (uVar17 == 0) {
    return;
  }
  pMVar3 = this->host;
  lVar12 = (pMVar3->realtime).tv_sec;
  lVar8 = (this->drawData).time.tv_sec;
  if (lVar12 == lVar8) {
    lVar8 = (pMVar3->realtime).tv_usec;
    if (lVar8 < (this->drawData).time.tv_usec) goto LAB_0012392b;
  }
  else {
    if (lVar12 < lVar8) goto LAB_0012392b;
    lVar8 = (pMVar3->realtime).tv_usec;
  }
                    /* Unresolved local var: int globalDelay@[???]
                       Unresolved local var: timeval delay@[???] */
  wVar16 = pMVar3->settings->delay;
  lVar12 = wVar16 / 10 + lVar12;
  (this->drawData).time.tv_sec = lVar12;
  lVar8 = (long)(wVar16 % 10) * 100000 + lVar8;
  (this->drawData).time.tv_usec = lVar8;
  if (999999 < lVar8) {
    (this->drawData).time.tv_sec = lVar12 + 1;
    (this->drawData).time.tv_usec = lVar8 + -1000000;
  }
  pdVar9 = (this->drawData).values;
  memmove(pdVar9,pdVar9 + 1,uVar17 * 8 - 8);
  pdVar9 = this->values;
                    /* Unresolved local var: double sum@[???]
                       Unresolved local var: size_t i@[???] */
  if ((ulong)this->curItems == 0) {
    dVar20 = 0.0;
  }
  else {
    dVar20 = 0.0;
    pdVar11 = pdVar9 + this->curItems;
    do {
      if (0.0 < *pdVar9) {
        dVar20 = dVar20 + *pdVar9;
      }
      pdVar9 = pdVar9 + 1;
    } while (pdVar9 != pdVar11);
  }
  (this->drawData).values[uVar17 - 1] = dVar20;
LAB_0012392b:
  if (iVar4 < 1) {
    return;
  }
  (*(int (*))(__fp - 0x40)) = x + 3;
  uVar15 = uVar17 >> 1;
  uVar10 = (long)iVar4;
  if (uVar15 < (ulong)(long)iVar4) {
    (*(int (*))(__fp - 0x40)) = (iVar4 + (*(int (*))(__fp - 0x40))) - (int)uVar15;
    uVar10 = uVar15;
  }
  ppcVar13 = GraphMeterMode_dotsAscii;
  uVar19 = -(uint)(CRT_utf8 == false) & 0xfffffffe;
  iVar4 = uVar19 + 4;
  if (CRT_utf8 != false) {
    ppcVar13 = GraphMeterMode_dotsUtf8;
  }
                    /* Unresolved local var: int col@[???] */
  (*(ulong (*))(__fp - 0x58)) = uVar17 + uVar10 * -2;
  if ((*(ulong (*))(__fp - 0x58)) < uVar17 - 1) {
                    /* Unresolved local var: int pix@[DW_OP_reg10(R10)]
                       Unresolved local var: double total@[???]
                       Unresolved local var: int v1@[???]
                       Unresolved local var: int v2@[???]
                       Unresolved local var: int colorIdx@[???] */
    iVar1 = iVar4 * 4;
                    /* Unresolved local var: int line@[???]
                       Unresolved local var: int line1@[???]
                       Unresolved local var: int line2@[???] */
    do {
      dVar20 = this->total;
      pdVar9 = (this->drawData).values;
      if (dVar20 <= 1.0) {
        dVar20 = 1.0;
      }
      __x = (pdVar9[(*(ulong (*))(__fp - 0x58))] / dVar20) * (double)iVar1;
      lVar12 = lround(__x);
      iVar7 = iVar1;
      if ((int)lVar12 <= iVar1) {
        lVar12 = lround(__x);
        iVar7 = 1;
        if (1 < (int)lVar12) {
          lVar12 = lround(__x);
          iVar7 = (int)lVar12;
        }
      }
      dVar20 = (pdVar9[(*(ulong (*))(__fp - 0x58)) + 1] / dVar20) * (double)iVar1;
      lVar12 = lround(dVar20);
      iVar6 = iVar1;
      if ((int)lVar12 <= iVar1) {
        lVar12 = lround(dVar20);
        iVar6 = 1;
        if (1 < (int)lVar12) {
          lVar12 = lround(dVar20);
          iVar6 = (int)lVar12;
        }
      }
      iVar18 = iVar7 + iVar4 * -3;
      lVar12 = 0x31;
      wVar16 = y;
      do {
        wattrset(_stdscr,CRT_colors[lVar12]);
        iVar5 = wmove(_stdscr,wVar16,(*(int (*))(__fp - 0x40)));
        if (iVar5 != -1) {
          iVar5 = 0;
          if (-1 < iVar18) {
            iVar5 = iVar18;
          }
          if (iVar4 < iVar5) {
            iVar5 = iVar4;
          }
          iVar14 = (iVar6 - iVar7) + iVar18;
          if (iVar14 < 0) {
            iVar14 = 0;
          }
          if (iVar4 < iVar14) {
            iVar14 = iVar4;
          }
          waddnstr(_stdscr,ppcVar13[(int)(iVar5 * (uVar19 + 5) + iVar14)],-1);
        }
        wVar16 = wVar16 + 1;
        iVar18 = iVar18 + iVar4;
        lVar12 = 0x32;
      } while (wVar16 != y + 4);
      (*(ulong (*))(__fp - 0x58)) = (*(ulong (*))(__fp - 0x58)) + 2;
      (*(int (*))(__fp - 0x40)) = (*(int (*))(__fp - 0x40)) + 1;
    } while ((*(ulong (*))(__fp - 0x58)) < uVar17 - 1);
  }
  wattrset(_stdscr,*CRT_colors);
  return;
}


/* Meter_humanUnit @ 0x128690 */

int Meter_humanUnit(char *buffer,double value,size_t size)

{
  int wVar1;
  long lVar2;
  long lVar3;
  int va0;
  int va2;
  double dVar4;

  va0 = 0;
  va2 = 0x4b;
  lVar2 = 0;
  dVar4 = value;
  if (1024.0 <= value) {
    do {
      value = value * 0.0009765625;
      lVar3 = lVar2 + 1;
      dVar4 = value;
      if (value < 1024.0) {
        va2 = (int)((char *)(long)&unitPrefixes /* "KMGTPEZYRQ" */)[lVar2 + 1];
        if (99.9 < value) {
          dVar4 = 100.0;
          va0 = 0;
        }
        else {
          va0 = 2;
          if (value <= 9.99) goto LAB_001286de;
                    /* Unresolved local var: double limit@[???] */
          dVar4 = 10.0;
          va0 = 1;
        }
        if (dVar4 <= value) {
          dVar4 = value;
        }
        goto LAB_001286de;
      }
      lVar2 = lVar3;
    } while (lVar3 != 9);
    va0 = 0;
    va2 = 0x51;
    if (9999.0 < value) {
      wVar1 = xSnprintf(buffer,size,((char *)(long)&DAT_0014883c /* "inf" */));
      return wVar1;
    }
  }
LAB_001286de:
  wVar1 = xSnprintf(buffer,size,((char *)(long)&s____f_c_00148840 /* "%.*f%c" */),va0,dVar4,va2);
  return wVar1;
}


/* Meter_toListItem @ 0x128760 */

/* DWARF original prototype: ListItem * Meter_toListItem(Meter * this, _Bool moving) */

ListItem * Meter_toListItem(Meter *this,_Bool moving)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  long lVar1;
  ObjectClass *pOVar2;
  Object_Delete p_Var3;
  ListItem *pLVar4;
  char *pcVar5;
  char *in_RCX;
  long in_R8;
  long in_R9;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (this->mode == 0) {
    pOVar2 = (this->super).klass;
    (*(char (*) [20])(__fp - 0xb8))[0] = '\0';
    p_Var3 = pOVar2[2].delete;
  }
  else {
    in_RCX = Meter_modes[this->mode]->uiName;
    xSnprintf((*(char (*) [20])(__fp - 0xb8)),0x14,((char *)(long)(__sec_rodata + 0x2dcb) /* " [%s]" */),in_RCX);
    pOVar2 = (this->super).klass;
    p_Var3 = pOVar2[2].delete;
  }
  if (p_Var3 == (Object_Delete)0x0) {
    xSnprintf((*(char (*) [32])(__fp - 0x98)),0x20,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),pOVar2[3].compare);
  }
  else {
    (*(code *)(p_Var3))(&this->super,(long)(*(char (*) [32])(__fp - 0x98)),0x20,(long)in_RCX,in_R8,in_R9);
  }
  xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),(*(char (*) [32])(__fp - 0x98)),(*(char (*) [20])(__fp - 0xb8)));
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
  pLVar4 = malloc(0x18);
  if (pLVar4 != (ListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pLVar4->super).klass = &ListItem_class;
    pcVar5 = strdup((*(char (*) [50])(__fp - 0x78)));
    if (pcVar5 != (char *)0x0) {
      pLVar4->value = pcVar5;
      pLVar4->key = 0;
      pLVar4->moving = moving;
      if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return pLVar4;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

