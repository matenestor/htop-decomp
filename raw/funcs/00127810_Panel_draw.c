/* Panel_draw @ 00127810 size 2319 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void Panel_draw(Panel * this, _Bool force_redraw, _Bool focus, _Bool
   highlightSelected, _Bool hideFunctionBar) */

void Panel_draw(Panel *this,_Bool force_redraw,_Bool focus,_Bool highlightSelected,
               _Bool hideFunctionBar)

{
  wchar_t wVar1;
  wchar_t p2;
  long lVar2;
  Object_Delete p_Var3;
  long *a0;
  code *pcVar4;
  Object *pOVar5;
  Object_Display p_Var6;
  FunctionBar *this_00;
  void *p0;
  undefined1 *puVar7;
  int iVar8;
  wchar_t wVar9;
  int iVar10;
  wchar_t wVar11;
  undefined7 in_register_00000009;
  ulong a3;
  byte bVar12;
  undefined7 in_register_00000011;
  wchar_t *extraout_RDX;
  wchar_t *extraout_RDX_00;
  wchar_t *extraout_RDX_01;
  wchar_t *extraout_RDX_02;
  wchar_t *extraout_RDX_03;
  wchar_t *extraout_RDX_04;
  wchar_t *extraout_RDX_05;
  wchar_t *extraout_RDX_06;
  cchar_t *pcVar14;
  wchar_t *extraout_RDX_07;
  wchar_t *extraout_RDX_08;
  wchar_t *extraout_RDX_09;
  undefined1 *puVar15;
  wchar_t wVar16;
  wchar_t wVar17;
  ulong uVar18;
  uint uVar19;
  undefined7 in_register_00000081;
  ulong a4;
  long in_R9;
  int iVar20;
  long in_FS_OFFSET;
  wchar_t local_4d4c;
  ulong local_4d48;
  wchar_t local_4d3c;
  RichString new;
  RichString item;
  wchar_t *pwVar13;

                    /* Unresolved local var: wchar_t size@[???]
                       Unresolved local var: wchar_t scrollH@[???]
                       Unresolved local var: wchar_t y@[???]
                       Unresolved local var: wchar_t x@[???]
                       Unresolved local var: wchar_t h@[???]
                       Unresolved local var: wchar_t header_attr@[???]
                       Unresolved local var: wchar_t headerLen@[???]
                       Unresolved local var: wchar_t first@[???]
                       Unresolved local var: wchar_t upTo@[???]
                       Unresolved local var: wchar_t selectionColor@[???] */
  puVar7 = &stack0xffffffffffffffd0;
  do {
    puVar15 = puVar7;
    *(undefined8 *)(puVar15 + -0x1000) = *(undefined8 *)(puVar15 + -0x1000);
    puVar7 = puVar15 + -0x1000;
  } while ((wchar_t *)(puVar15 + -0x1000) != new.chstr[0x76].chars + 3);
  uVar18 = CONCAT71(in_register_00000081,hideFunctionBar) & 0xffffffff;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  uVar19 = (this->h + L'\x01') - (uint)((char)uVar18 == '\0');
  wVar17 = this->items->items;
  wVar1 = this->scrollH;
  local_4d4c = this->y;
  p2 = this->x;
  if (focus) {
    wVar16 = CRT_colors[7];
  }
  else {
    wVar16 = CRT_colors[8];
  }
  if (force_redraw) {
    p_Var3 = (this->super).klass[1].delete;
    if (p_Var3 == (Object_Delete)0x0) {
      wVar9 = (this->header).chlen;
                    /* Unresolved local var: wchar_t end@[???] */
      wVar11 = L'\0';
      if (L'\xffffffff' < wVar9) {
        wVar11 = wVar9;
      }
                    /* Unresolved local var: wchar_t i@[???] */
      if (L'\0' < wVar9) {
        pcVar14 = (this->header).chptr;
        wVar9 = L'\0';
        do {
          wVar9 = wVar9 + L'\x01';
          pcVar14->attr = wVar16;
          pcVar14 = pcVar14 + 1;
        } while (wVar9 < wVar11);
        goto LAB_00127c20;
      }
    }
    else {
      *(undefined8 *)(puVar15 + -0x1d60) = 0x1278da;
      (*p_Var3)(&this->super,uVar18,CONCAT71(in_register_00000011,focus),
                CONCAT71(in_register_00000009,highlightSelected),(ulong)uVar19,in_R9);
      wVar9 = (this->header).chlen;
      if (L'\0' < wVar9) goto LAB_001278ee;
    }
LAB_00127c2d:
    uVar18 = (ulong)uVar19;
    local_4d3c = this->scrollV;
    if (local_4d3c < L'\0') goto LAB_0012798e;
LAB_00127c3a:
    wVar16 = wVar17 - (int)uVar18;
    if (wVar16 < local_4d3c) {
      this->needsRedraw = true;
      local_4d3c = L'\0';
      if (L'\xffffffff' < wVar16) {
        local_4d3c = wVar16;
      }
      this->scrollV = local_4d3c;
    }
  }
  else {
LAB_00127c20:
    wVar9 = (this->header).chlen;
    if (wVar9 < L'\x01') goto LAB_00127c2d;
LAB_001278ee:
    *(undefined8 *)(puVar15 + -0x1d60) = 0x127908;
    wattrset(_stdscr,wVar16);
    *(undefined8 *)(puVar15 + -0x1d60) = 0x12791d;
    iVar8 = wmove(_stdscr,local_4d4c,p2);
    if (iVar8 != -1) {
      wVar16 = this->w;
      *(undefined8 *)(puVar15 + -0x1d60) = 0x12793b;
      whline(_stdscr,0x20,wVar16);
    }
    if (wVar1 < wVar9) {
      *(undefined8 *)(puVar15 + -0x1d60) = 0x1280d0;
      iVar8 = wmove(_stdscr,local_4d4c,p2);
      if (iVar8 != -1) {
        wVar16 = this->w;
        if (wVar9 - wVar1 <= this->w) {
          wVar16 = wVar9 - wVar1;
        }
        pcVar14 = (this->header).chptr;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x128113;
        wadd_wchnstr(_stdscr,pcVar14 + wVar1,wVar16);
      }
    }
    wVar16 = *CRT_colors;
    *(undefined8 *)(puVar15 + -0x1d60) = 0x12796f;
    wattrset(_stdscr,wVar16);
    local_4d3c = this->scrollV;
    local_4d4c = local_4d4c + L'\x01';
    uVar18 = (ulong)(uVar19 - 1);
    if (L'\xffffffff' < local_4d3c) goto LAB_00127c3a;
LAB_0012798e:
    this->scrollV = L'\0';
    local_4d3c = L'\0';
    this->needsRedraw = true;
  }
  wVar16 = this->selected;
  iVar8 = (int)uVar18;
  if (wVar16 < local_4d3c) {
LAB_001279b9:
    this->scrollV = wVar16;
    wVar9 = wVar16 + iVar8;
    this->needsRedraw = true;
    pwVar13 = CRT_colors;
    local_4d3c = wVar16;
    if (focus) {
      a3 = (ulong)(uint)CRT_colors[this->selectionColorId];
    }
    else {
      a3 = (ulong)(uint)CRT_colors[0xb];
    }
  }
  else {
    wVar9 = iVar8 + local_4d3c;
    if (wVar9 <= wVar16) {
      wVar16 = (wVar16 - iVar8) + L'\x01';
      goto LAB_001279b9;
    }
    bVar12 = force_redraw | this->needsRedraw;
    pwVar13 = (wchar_t *)(ulong)bVar12;
    if (focus) {
      wVar16 = CRT_colors[this->selectionColorId];
    }
    else {
      wVar16 = CRT_colors[0xb];
    }
    a3 = (ulong)(uint)wVar16;
    if (bVar12 == 0) {
                    /* Unresolved local var: Object * oldObj@[???]
                       Unresolved local var: wchar_t oldLen@[???]
                       Unresolved local var: Object * newObj@[???]
                       Unresolved local var: wchar_t newLen@[???] */
      wVar17 = this->oldSelected;
      pOVar5 = this->items->array[wVar17];
      item.chptr = item.chstr;
      item.chstr[0]._0_12_ = SUB1612((undefined1  [16])0x0,0);
      item.chstr[0].chars[2] = L'\0';
      item.chstr[0]._16_12_ = SUB1612((undefined1  [16])0x0,4);
      item.chlen = L'\0';
      item.highlightAttr = L'\0';
      p_Var6 = pOVar5->klass->display;
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127cf0;
      (*p_Var6)(pOVar5,&item,(long)wVar17,a3,uVar18,in_R9);
      wVar11 = item.chlen;
      wVar17 = this->selected;
      pOVar5 = this->items->array[wVar17];
      new.chptr = new.chstr;
      new.chstr[0]._0_12_ = SUB1612((undefined1  [16])0x0,0);
      new.chstr[0].chars[2] = L'\0';
      new.chstr[0]._16_12_ = SUB1612((undefined1  [16])0x0,4);
      new.chlen = L'\0';
      new.highlightAttr = L'\0';
      p_Var6 = pOVar5->klass->display;
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127d47;
      (*p_Var6)(pOVar5,&new,(long)wVar17,a3,uVar18,in_R9);
      wVar9 = new.chlen;
      p0 = _stdscr;
      wVar17 = this->oldSelected;
      this->selectedLen = new.chlen;
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127d74;
      iVar8 = wmove(p0,(local_4d4c + wVar17) - local_4d3c,p2);
      a4 = uVar18;
      if (iVar8 != -1) {
        wVar17 = this->w;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127d91;
        whline(_stdscr,0x20,wVar17);
        a4 = uVar18;
      }
      if (wVar1 < wVar11) {
        wVar17 = this->oldSelected;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127fee;
        iVar8 = wmove(_stdscr,(local_4d4c + wVar17) - local_4d3c,p2);
        if (iVar8 != -1) {
          wVar11 = wVar11 - wVar1;
          wVar17 = this->w;
          if (wVar11 <= this->w) {
            wVar17 = wVar11;
          }
          *(undefined8 *)(puVar15 + -0x1d60) = 0x128033;
          wadd_wchnstr(_stdscr,item.chptr + wVar1,wVar17);
        }
      }
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127db9;
      wattrset(_stdscr,wVar16);
      wVar17 = this->selected;
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127dd5;
      iVar8 = wmove(_stdscr,(local_4d4c + wVar17) - local_4d3c,p2);
      if (iVar8 != -1) {
        wVar17 = this->w;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127df2;
        whline(_stdscr,0x20,wVar17);
      }
      a3 = (ulong)(uint)wVar16;
                    /* Unresolved local var: wchar_t end@[???] */
      wVar17 = L'\0';
      if (L'\xffffffff' < new.chlen) {
        wVar17 = new.chlen;
      }
                    /* Unresolved local var: wchar_t i@[???] */
      if (L'\0' < new.chlen) {
        wVar11 = L'\0';
        pcVar14 = new.chptr;
        do {
          wVar11 = wVar11 + L'\x01';
          pcVar14->attr = wVar16;
          pcVar14 = pcVar14 + 1;
        } while (wVar11 < wVar17);
      }
      if (wVar1 < wVar9) {
        wVar17 = this->selected;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x128070;
        iVar8 = wmove(_stdscr,(local_4d4c + wVar17) - local_4d3c,p2);
        if (iVar8 != -1) {
          a3 = (ulong)wVar1;
          wVar9 = wVar9 - wVar1;
          wVar17 = this->w;
          if (wVar9 <= this->w) {
            wVar17 = wVar9;
          }
          *(undefined8 *)(puVar15 + -0x1d60) = 0x1280ac;
          wadd_wchnstr(_stdscr,new.chptr + a3,wVar17);
        }
      }
      wVar17 = *CRT_colors;
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127e42;
      wattrset(_stdscr,wVar17);
      pwVar13 = extraout_RDX_05;
      if (L'Ş' < new.chlen) {
        *(undefined8 *)(puVar15 + -0x1d60) = 0x12804c;
        free(new.chptr);
        pwVar13 = extraout_RDX_09;
      }
      if (L'Ş' < item.chlen) {
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127e6a;
        free(item.chptr);
        pwVar13 = extraout_RDX_06;
      }
      goto LAB_00127e70;
    }
  }
  if (wVar9 <= wVar17) {
    wVar17 = wVar9;
  }
                    /* Unresolved local var: wchar_t line@[???]
                       Unresolved local var: wchar_t i@[???] */
  if ((iVar8 < 1) || (wVar17 <= local_4d3c)) {
    iVar20 = 0;
  }
  else {
                    /* Unresolved local var: Object * itemObj@[???]
                       Unresolved local var: wchar_t itemLen@[???]
                       Unresolved local var: wchar_t amt@[???] */
    wVar16 = (wchar_t)a3;
    local_4d48 = (long)local_4d3c * 8;
    iVar20 = 0;
    pwVar13 = (wchar_t *)(long)wVar1;
    a4 = uVar18;
    do {
      a0 = *(long **)((long)this->items->array + local_4d48);
      item.chstr[0]._0_12_ = SUB1612((undefined1  [16])0x0,0);
      item.chlen = L'\0';
      item.highlightAttr = L'\0';
      item.chstr[0].chars[2] = L'\0';
      item.chstr[0]._16_12_ = SUB1612((undefined1  [16])0x0,4);
      pcVar4 = *(code **)(*a0 + 8);
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127b0d;
      a3 = local_4d48;
      item.chptr = item.chstr;
      (*pcVar4)((long)a0,(long)&item,(long)pwVar13,local_4d48,a4,in_R9);
      wVar11 = item.chlen;
      wVar9 = item.chlen - wVar1;
      if (this->w < item.chlen - wVar1) {
        wVar9 = this->w;
      }
      if ((highlightSelected) && (this->selected == local_4d3c)) {
        item.highlightAttr = wVar16;
      }
      if (item.highlightAttr != L'\0') {
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127ef9;
        wattrset(_stdscr,item.highlightAttr);
                    /* Unresolved local var: wchar_t end@[???] */
        a3 = 0;
        if (L'\xffffffff' < item.chlen) {
          a3 = (ulong)(uint)item.chlen;
        }
                    /* Unresolved local var: wchar_t i@[???] */
        if (L'\0' < item.chlen) {
          iVar10 = 0;
          pcVar14 = item.chptr;
          do {
            iVar10 = iVar10 + 1;
            pcVar14->attr = item.highlightAttr;
            pcVar14 = pcVar14 + 1;
          } while (iVar10 < (int)a3);
        }
        this->selectedLen = wVar11;
      }
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127b68;
      iVar10 = wmove(_stdscr,iVar20 + local_4d4c,p2);
      pwVar13 = extraout_RDX;
      if (iVar10 != -1) {
        wVar11 = this->w;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127b7f;
        whline(_stdscr,0x20,wVar11);
        pwVar13 = extraout_RDX_00;
      }
      if (L'\0' < wVar9) {
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127b99;
        iVar10 = wmove(_stdscr,iVar20 + local_4d4c,p2);
        pwVar13 = extraout_RDX_01;
        if (iVar10 != -1) {
          *(undefined8 *)(puVar15 + -0x1d60) = 0x127bbb;
          wadd_wchnstr(_stdscr,item.chptr + wVar1,wVar9);
          pwVar13 = extraout_RDX_02;
        }
      }
      if (item.highlightAttr != L'\0') {
        wVar9 = *CRT_colors;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127bdb;
        wattrset(_stdscr,wVar9);
        pwVar13 = extraout_RDX_03;
      }
      if (L'Ş' < item.chlen) {
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127bf7;
        free(item.chptr);
        pwVar13 = extraout_RDX_04;
      }
      local_4d3c = local_4d3c + L'\x01';
      iVar20 = iVar20 + 1;
      local_4d48 = local_4d48 + 8;
      if (iVar8 <= iVar20) goto LAB_00127e70;
    } while (local_4d3c < wVar17);
  }
  a4 = uVar18;
  if (iVar20 < iVar8) {
    iVar20 = iVar20 + local_4d4c;
    do {
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127f8f;
      iVar10 = wmove(_stdscr,iVar20,p2);
      pwVar13 = extraout_RDX_07;
      if (iVar10 != -1) {
        wVar17 = this->w;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x127fa6;
        whline(_stdscr,0x20,wVar17);
        pwVar13 = extraout_RDX_08;
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 != local_4d4c + iVar8);
  }
LAB_00127e70:
  if ((focus) && (((this->needsRedraw != false || (force_redraw)) || (this->wasFocus == false)))) {
    p_Var6 = (this->super).klass[1].display;
    if (p_Var6 == (Object_Display)0x0) {
      if (!hideFunctionBar) {
        this_00 = this->currentBar;
        *(undefined8 *)(puVar15 + -0x1d60) = 0x12813e;
        FunctionBar_drawExtra(this_00,(char *)0x0,L'\xffffffff',false);
      }
    }
    else {
      *(undefined8 *)(puVar15 + -0x1d60) = 0x127eac;
      (*p_Var6)(&this->super,(RichString *)(ulong)hideFunctionBar,(long)pwVar13,a3,a4,in_R9);
    }
  }
  this->needsRedraw = false;
  this->oldSelected = this->selected;
  this->wasFocus = focus;
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar15 + -0x1d60) = &UNK_00128158;
  __stack_chk_fail();
}

