/* LEDMeterMode_draw @ 00120ba0 size 816 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* DWARF original prototype: void LEDMeterMode_draw(Meter * this, wchar_t x, wchar_t y, wchar_t w)
    */

void LEDMeterMode_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  wchar_t wVar1;
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
  wchar_t p1_00;
  long in_FS_OFFSET;
  int local_26f4;
  cchar_t wc;
  RichString out;

                    /* Unresolved local var: wchar_t yText@[???]
                       Unresolved local var: char * caption@[???]
                       Unresolved local var: wchar_t xx@[???]
                       Unresolved local var: wchar_t len@[???] */
  lVar7 = CONCAT44(in_register_0000000c,w);
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  LEDMeterMode_digits = LEDMeterMode_digitsAscii;
  out.chstr[0]._0_12_ = SUB1612((undefined1  [16])0x0,0);
  if (CRT_utf8) {
    LEDMeterMode_digits = LEDMeterMode_digitsUtf8;
  }
  a2 = (this->super).klass;
  out.chlen = L'\0';
  out.highlightAttr = L'\0';
  out.chptr = out.chstr;
  out.chstr[0].chars[2] = L'\0';
  out.chstr[0]._16_12_ = SUB1612((undefined1  [16])0x0,4);
  if (a2->display == (Object_Display)0x0) {
    lVar7 = (long)*(int *)a2[3].display;
    RichString_writeWide(&out,CRT_colors[lVar7],this->txtBuffer);
  }
  else {
    (*a2->display)(&this->super,&out,(long)a2,lVar7,in_R8,in_R9);
  }
  local_26f4 = y + L'\x02';
  if (CRT_utf8 != false) {
    local_26f4 = y + L'\x01';
  }
  pRVar9 = (RichString *)(ulong)(uint)CRT_colors[0x16];
  wattrset(_stdscr,CRT_colors[0x16]);
  p_Var3 = (this->super).klass[2].display;
  if (p_Var3 == (Object_Display)0x0) {
    p1 = this->caption;
  }
  else {
    p1 = (char *)(*p_Var3)(&this->super,pRVar9,a2_00,lVar7,in_R8,in_R9);
  }
  iVar4 = wmove(_stdscr,local_26f4,x);
  if (iVar4 != -1) {
    waddnstr(_stdscr,p1,-1);
  }
  sVar6 = strlen(p1);
  iVar4 = x + (int)sVar6;
  lVar7 = (long)out.chlen;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < out.chlen) {
    lVar8 = 0;
                    /* Unresolved local var: wchar_t c@[???] */
    do {
      wVar1 = *(wchar_t *)((long)(out.chptr)->chars + lVar8);
      uVar10 = wVar1 + L'\xffffffd0';
      if (uVar10 < 10) {
        if (w <= (iVar4 - x) + L'\x03') break;
                    /* Unresolved local var: wchar_t i@[???] */
        p1_00 = y;
        do {
          iVar5 = wmove(_stdscr,p1_00,iVar4);
          if (iVar5 != -1) {
            waddnstr(_stdscr,LEDMeterMode_digits[(int)uVar10],-1);
          }
          uVar10 = uVar10 + 10;
          p1_00 = p1_00 + L'\x01';
        } while (uVar10 != wVar1 + L'\xffffffee');
        iVar4 = iVar4 + 4;
      }
      else {
        if (w <= iVar4 - x) break;
        wc.attr = 0;
        wc.chars[1] = L'\0';
        wc.chars[2] = L'\0';
        wc._16_12_ = SUB1612((undefined1  [16])0x0,4);
        wc.chars[0] = wVar1;
        iVar5 = wmove(_stdscr,local_26f4,iVar4);
        if (iVar5 != -1) {
          wadd_wch(_stdscr,&wc);
        }
        iVar4 = iVar4 + 1;
      }
      lVar8 = lVar8 + 0x1c;
    } while (lVar8 != lVar7 * 0x1c);
  }
  wattrset(_stdscr,*CRT_colors);
  if (L'Ş' < out.chlen) {
    free(out.chptr);
  }
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

