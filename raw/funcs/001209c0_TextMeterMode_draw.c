/* TextMeterMode_draw @ 001209c0 size 464 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void TextMeterMode_draw(Meter * this, wchar_t x, wchar_t y, wchar_t w)
    */

void TextMeterMode_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
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
  long in_FS_OFFSET;
  char *local_26c8;
  RichString out;

                    /* Unresolved local var: char * caption@[???]
                       Unresolved local var: wchar_t captionLen@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  p_Var2 = (this->super).klass[2].display;
  if (p_Var2 == (Object_Display)0x0) {
    local_26c8 = this->caption;
  }
  else {
    local_26c8 = (char *)(*p_Var2)(&this->super,(RichString *)CONCAT44(in_register_00000034,x),
                                   CONCAT44(in_register_00000014,y),CONCAT44(in_register_0000000c,w)
                                   ,in_R8,in_R9);
  }
  wattrset(_stdscr,CRT_colors[0xe]);
  iVar4 = wmove(_stdscr,y,x);
  if (iVar4 != -1) {
    waddnstr(_stdscr,local_26c8,w);
  }
  wattrset(_stdscr,*CRT_colors);
  a3 = strlen(local_26c8);
  iVar4 = w - (int)a3;
  if (0 < iVar4) {
    pOVar3 = (this->super).klass;
    out.chptr = out.chstr;
    out.chlen = L'\0';
    p_Var2 = pOVar3->display;
    out.chstr[0]._0_12_ = SUB1612((undefined1  [16])0x0,0);
    out.highlightAttr = L'\0';
    out.chstr[0].chars[2] = L'\0';
    out.chstr[0]._16_12_ = SUB1612((undefined1  [16])0x0,4);
    if (p_Var2 == (Object_Display)0x0) {
      RichString_writeWide(&out,CRT_colors[*(int *)pOVar3[3].display],this->txtBuffer);
    }
    else {
      (*p_Var2)(&this->super,&out,a2,a3,in_R8,in_R9);
    }
    iVar5 = wmove(_stdscr,y,x + (int)a3);
    if (iVar5 != -1) {
      wadd_wchnstr(_stdscr,out.chptr,iVar4);
    }
    if (L'Ş' < out.chlen) {
      free(out.chptr);
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

