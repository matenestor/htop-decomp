/* InfoScreen_run @ 0012ac40 size 978 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void InfoScreen_run(InfoScreen * this) */

void InfoScreen_run(InfoScreen *this)

{
  Panel *this_00;
  long lVar1;
  code *pcVar2;
  Object_Delete p_Var3;
  Object_Compare p_Var4;
  void *pvVar5;
  IncMode *pIVar6;
  wchar_t *pwVar7;
  wchar_t wVar8;
  wchar_t wVar9;
  int iVar10;
  ObjectClass *pOVar11;
  FunctionBar *pFVar12;
  long in_RCX;
  ulong a3;
  wchar_t wVar13;
  long extraout_RDX;
  long lVar14;
  IncMode *a2;
  long a2_00;
  IncMode *extraout_RDX_00;
  undefined *a2_02;
  long a2_03;
  undefined *extraout_RDX_01;
  undefined *extraout_RDX_02;
  IncMode *extraout_RDX_03;
  IncMode *extraout_RDX_04;
  RichString *in_RSI;
  RichString *a1;
  long in_R8;
  IncSet *in_R9;
  long in_FS_OFFSET;
  MEVENT mevent;
  IncMode *a2_01;

  this_00 = this->display;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pOVar11 = (this->super).klass;
  pcVar2 = pOVar11[1].extends;
  lVar14 = 0;
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)((long)this,(long)in_RSI,(long)pcVar2,in_RCX,in_R8,(long)in_R9);
    pOVar11 = (this->super).klass;
    lVar14 = extraout_RDX;
  }
                    /* Unresolved local var: wchar_t ch@[???]
                       Unresolved local var: wchar_t ok@[???] */
  (*pOVar11[1].display)(&this->super,in_RSI,lVar14,in_RCX,in_R8,(long)in_R9);
LAB_0012ac90:
  do {
    while( true ) {
      lVar14 = 0;
      a3 = 1;
      Panel_draw(this_00,false,true,true,false);
      a1 = (RichString *)(ulong)(uint)CRT_colors[2];
      IncSet_drawBar(this->inc,CRT_colors[2]);
      wVar8 = Panel_getCh(this_00);
      if (wVar8 != L'\xffffffff') break;
      p_Var3 = (this->super).klass[1].delete;
      if (p_Var3 == (Object_Delete)0x0) {
        in_R9 = this->inc;
        if (in_R9->active != (IncMode *)0x0) {
LAB_0012ad68:
          IncSet_handleKey(in_R9,wVar8,this_00,IncSet_getListItemValue,this->lines);
        }
      }
      else {
        (*p_Var3)(&this->super,(long)a1,(long)a2,a3,lVar14,(long)in_R9);
      }
    }
    if (wVar8 == L'ƙ') {
      iVar10 = getmouse(&mevent);
      a2_01 = extraout_RDX_00;
      if (iVar10 == 0) {
        if ((mevent.bstate & 1) != 0) {
          wVar9 = this_00->y;
          a3 = (ulong)(uint)wVar9;
          wVar13 = _LINES + L'\xffffffff';
          a2_01 = (IncMode *)(ulong)(uint)wVar13;
          if ((mevent.y < wVar9) || (wVar13 <= mevent.y)) {
            if (mevent.y != wVar13) goto LAB_0012adce;
            in_R9 = this->inc;
            a1 = (RichString *)(ulong)(uint)mevent.x;
            if (in_R9->active == (IncMode *)0x0) {
              wVar8 = FunctionBar_synthesizeEvent(in_R9->defaultBar,mevent.x);
              a2_01 = extraout_RDX_04;
              goto LAB_0012ace5;
            }
            wVar8 = FunctionBar_synthesizeEvent(in_R9->active->bar,mevent.x);
          }
          else {
                    /* Unresolved local var: wchar_t size@[???] */
            wVar13 = (mevent.y - wVar9) + this_00->scrollV + L'\xffffffff';
            wVar9 = this_00->items->items;
            wVar8 = wVar9 + L'\xffffffff';
            a3 = (ulong)(uint)wVar8;
            if (wVar9 <= wVar13) {
              wVar13 = wVar8;
            }
            a2_01 = (IncMode *)0x0;
            if (wVar13 < L'\0') {
              wVar13 = L'\0';
            }
            this_00->selected = wVar13;
            pcVar2 = (this_00->super).klass[1].extends;
            if (pcVar2 == (code *)0x0) {
              in_R9 = this->inc;
              pIVar6 = in_R9->active;
            }
            else {
              (*pcVar2)((long)this_00,0xffffffff,0,a3,lVar14,(long)in_R9);
              in_R9 = this->inc;
              pIVar6 = in_R9->active;
              a2_01 = extraout_RDX_03;
            }
            if (pIVar6 == (IncMode *)0x0) {
              wVar8 = L'\0';
              goto LAB_0012addd;
            }
            wVar8 = L'\0';
          }
          goto LAB_0012ad68;
        }
        in_R9 = this->inc;
        a2_01 = in_R9->active;
        pIVar6 = a2_01;
        if ((mevent.bstate & 0x10000) == 0) {
          if ((mevent.bstate & 0x200000) == 0) goto LAB_0012adce;
          wVar8 = L'ħ';
        }
        else {
          wVar8 = L'Ħ';
        }
      }
      else {
LAB_0012adce:
        in_R9 = this->inc;
        pIVar6 = in_R9->active;
      }
      if (pIVar6 != (IncMode *)0x0) goto LAB_0012ad68;
      goto LAB_0012addd;
    }
    in_R9 = this->inc;
    a2_01 = a2;
    if (in_R9->active != (IncMode *)0x0) goto LAB_0012ad68;
LAB_0012ace5:
    if (wVar8 == L'ċ') {
LAB_0012aea3:
      in_R9->active = in_R9->modes;
      pFVar12 = in_R9->modes[0].bar;
LAB_0012aef5:
      this_00->currentBar = pFVar12;
      pwVar7 = CRT_colors;
      this_00->cursorOn = true;
      in_R9->panel = this_00;
      IncSet_drawBar(in_R9,pwVar7[2]);
      goto LAB_0012ac90;
    }
    if (wVar8 < L'Č') {
      if (wVar8 != L'\x1b') {
        if (wVar8 < L'\x1c') break;
        if (wVar8 == L'\\') goto LAB_0012aee0;
        if (wVar8 != L'q') {
          if (wVar8 != L'/') goto LAB_0012addd;
          goto LAB_0012aea3;
        }
      }
      goto LAB_0012aeb8;
    }
    if (wVar8 == L'č') {
      wclear(_stdscr);
      pOVar11 = (this->super).klass;
      pvVar5 = pOVar11[1].extends;
      a2_02 = extraout_RDX_02;
    }
    else {
      if (wVar8 < L'Ď') {
LAB_0012aee0:
        in_R9->active = in_R9->modes + 1;
        pFVar12 = in_R9->modes[1].bar;
        goto LAB_0012aef5;
      }
      if (wVar8 == L'Ē') {
LAB_0012aeb8:
        if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      if (wVar8 != L'ƚ') goto LAB_0012addd;
      a2_02 = &COLS;
      this_00->needsRedraw = true;
      iVar10 = _LINES + -2;
      pOVar11 = (this->super).klass;
      pvVar5 = pOVar11[1].extends;
      this_00->w = _COLS;
      this_00->h = iVar10;
    }
    if (pvVar5 != (void *)0x0) {
      Vector_prune(this->lines);
      (*(this->super).klass[1].extends)((long)this,(long)a1,a2_03,a3,lVar14,(long)in_R9);
      pOVar11 = (this->super).klass;
      a2_02 = extraout_RDX_01;
    }
    (*pOVar11[1].display)(&this->super,a1,(long)a2_02,a3,lVar14,(long)in_R9);
  } while( true );
  if (wVar8 != L'\xffffffff') {
    if (wVar8 == L'\f') {
      wclear(_stdscr);
      (*(this->super).klass[1].display)(&this->super,a1,a2_00,a3,lVar14,(long)in_R9);
    }
    else {
LAB_0012addd:
      p_Var4 = (this->super).klass[1].compare;
      if ((p_Var4 == (Object_Compare)0x0) ||
         (wVar9 = (*p_Var4)(this,(void *)(ulong)(uint)wVar8,(long)a2_01,a3,lVar14,(long)in_R9),
         (char)wVar9 == '\0')) {
        Panel_onKey(this_00,wVar8);
      }
    }
  }
  goto LAB_0012ac90;
}

