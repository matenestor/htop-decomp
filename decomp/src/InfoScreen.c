#include "htop.h"

/* InfoScreen_done @ 0x126cf0 */

/* DWARF original prototype: InfoScreen * InfoScreen_done(InfoScreen * this) */

InfoScreen_2 * InfoScreen_done(InfoScreen *this)

{
  Panel *__ptr;
  IncSet *__ptr_00;

  __ptr = this->display;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(__ptr->eventHandlerState);
  Vector_delete(__ptr->items);
  FunctionBar_delete(__ptr->defaultBar);
  if (350 < (__ptr->header).chlen) {
    free((__ptr->header).chptr);
  }
  free(__ptr);
  __ptr_00 = this->inc;
  FunctionBar_delete(__ptr_00->modes[0].bar);
  FunctionBar_delete(__ptr_00->modes[1].bar);
  free(__ptr_00);
  Vector_delete(this->lines);
  return (InfoScreen_2 *)this;
}


/* InfoScreen_init @ 0x127350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: InfoScreen * InfoScreen_init(InfoScreen * this, Process * process,
   FunctionBar * bar, int height, char * panelHeader) */

InfoScreen_2 *
InfoScreen_init(InfoScreen *this,Process *process,FunctionBar *bar,int height,char *panelHeader)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  int wVar1;
  long lVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int wVar5;
  int iVar6;
  Panel *pPVar7;
  Vector *pVVar8;
  IncSet_3 *pIVar9;
  size_t sVar10;
  ulong uVar11;
  ulong uVar12;
  undefined1 *puVar13;
  int *pwVar15;
  cchar_t *pcVar16;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar14;

  puVar14 = (*(undefined1 (*) [8])(__fp - 0x68));
  puVar13 = (*(undefined1 (*) [8])(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this->process = process;
  if (bar == (FunctionBar *)0x0) {
    (*(FunctionBar *(*))(__fp - 0x58)) = (FunctionBar *)CONCAT44((*(uint *)((char *)&(*(FunctionBar *(*))(__fp - 0x58)) + 4)),height);
    bar = FunctionBar_new(InfoScreenFunctions,InfoScreenKeys,((char *)(long)&InfoScreenEvents /* L"ċČč\x1b" */));
    height = (int)(*(FunctionBar *(*))(__fp - 0x58));
  }
  uVar4 = _COLS;
  (*(FunctionBar *(*))(__fp - 0x58)) = bar;
  (*(FunctionBar *(*))(__fp - 0x50)) = bar;
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  pPVar7 = malloc(0x26e0);
  if (pPVar7 == (Panel *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  pPVar7->w = uVar4;
  pPVar7->h = height;
  pPVar7->cursorX = 0;
  pPVar7->cursorY = 0;
  (pPVar7->super).klass = &Panel_class.super;
  pPVar7->eventHandlerState = (void *)0x0;
  pPVar7->x = 0;
  pPVar7->y = 1;
  pVVar8 = Vector_new(&ListItem_class,false,-1);
  this->display = pPVar7;
  pPVar7->items = pVVar8;
  pPVar7->needsRedraw = true;
  pPVar7->cursorOn = false;
  (pPVar7->header).chptr = (pPVar7->header).chstr;
  pPVar7->scrollV = 0;
  pPVar7->scrollH = 0;
  pPVar7->selected = 0;
  pPVar7->oldSelected = 0;
  pPVar7->selectedLen = 0;
  pPVar7->wasFocus = false;
  (pPVar7->header).chlen = 0;
  *(undefined8 *)&(pPVar7->header).highlightAttr = 0x900000000;
  (pPVar7->header).chstr[0].attr = 0;
  (pPVar7->header).chstr[0].chars[0] = 0;
  (pPVar7->header).chstr[0].chars[1] = 0;
  (pPVar7->header).chstr[0].chars[2] = 0;
  pPVar7->currentBar = (*(FunctionBar *(*))(__fp - 0x58));
  pPVar7->defaultBar = (*(FunctionBar *(*))(__fp - 0x50));
  *(undefined16 *)(*(undefined1 (*) [16])((pPVar7->header).chstr[0].chars + 2)) = (undefined16)0x0;
  pIVar9 = IncSet_new(bar);
  this->inc = (IncSet *)pIVar9;
  (*(Panel *(*))(__fp - 0x60)) = this->display;
  pVVar8 = Vector_new((*(Panel *(*))(__fp - 0x60))->items->type,true,-1);
  this->lines = pVVar8;
  wVar1 = CRT_colors[7];
  sVar10 = strlen(panelHeader);
                    /* Unresolved local var: int[37790] data@[???]
                       Unresolved local var: int newLen@[???] */
  uVar12 = (ulong)((int)sVar10 + 1);
  uVar11 = uVar12 * 4 + 0xf;
  puVar3 = (*(undefined1 (*) [8])(__fp - 0x68));
  while (puVar14 != (*(undefined1 (*) [8])(__fp - 0x68)) + -(uVar11 & 0xfffffffffffff000)) {
    puVar13 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar14 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar11 = (ulong)((uint)uVar11 & 0xff0);
  lVar2 = -uVar11;
  pwVar15 = (int *)(puVar13 + lVar2);
  if (uVar11 != 0) {
    *(undefined8 *)(puVar13 + -8) = *(undefined8 *)(puVar13 + -8);
  }
  uVar11 = __mbstowcs_chk((int *)(puVar13 + lVar2),panelHeader,(long)(int)sVar10,
                          uVar12 & 0x3fffffffffffffff);
  pPVar7 = (*(Panel *(*))(__fp - 0x60));
  wVar5 = (int)uVar11;
  if (0 < wVar5) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(*(Panel *(*))(__fp - 0x60))->header,wVar5);
    (*(FunctionBar *(*))(__fp - 0x58)) = (FunctionBar *)(puVar13 + (ulong)(uint)(wVar5 + -1) * 4 + lVar2 + 4);
    pcVar16 = (pPVar7->header).chptr;
    do {
      wVar5 = *pwVar15;
      iVar6 = iswprint(wVar5);
      pcVar16->attr = 0;
      pcVar16->chars[0] = 0;
      pcVar16->chars[1] = 0;
      pcVar16->chars[2] = 0;
      if (iVar6 == 0) {
        wVar5 = 65533;
      }
      pwVar15 = pwVar15 + 1;
      pcVar16->attr = wVar1 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar16->chars + 2)) = (undefined16)0x0;
      pcVar16->chars[0] = wVar5;
      pcVar16 = pcVar16 + 1;
    } while ((FunctionBar *)pwVar15 != (*(FunctionBar *(*))(__fp - 0x58)));
  }
  (*(Panel *(*))(__fp - 0x60))->needsRedraw = true;
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (InfoScreen_2 *)this;
}


/* InfoScreen_drawTitled @ 0x128160 */
void InfoScreen_drawTitled(InfoScreen *this,char *fmt,...)

{
  undefined1 __frame[0x198] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x158;
  int n;
  int len = COLS + 1;
  char title[len];

  __builtin_va_start((*(__builtin_va_list (*))(__fp - 0x108)),fmt);
  n = vsnprintf(title,len,fmt,(*(__builtin_va_list (*))(__fp - 0x108)));
  __builtin_va_end((*(__builtin_va_list (*))(__fp - 0x108)));
  if (COLS < n) {
    memset(title + (COLS - 3),'.',3);
  }
  wattrset(stdscr,CRT_colors[METER_TEXT]);
  if (wmove(stdscr,0,0) != -1) {
    whline(stdscr,' ',COLS);
  }
  if (wmove(stdscr,0,0) != -1) {
    waddnstr(stdscr,title,-1);
  }
  wattrset(stdscr,CRT_colors[DEFAULT_COLOR]);
  Panel_draw(this->display,true,true,true,false);
  IncSet_drawBar(this->inc,CRT_colors[FUNCTION_BAR]);
}

/* InfoScreen_run @ 0x12ac40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void InfoScreen_run(InfoScreen * this) */

void InfoScreen_run(InfoScreen *this)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  Panel *this_00;
  long lVar1;
  code *pcVar2;
  Object_Delete p_Var3;
  Object_Compare p_Var4;
  void *pvVar5;
  IncMode *pIVar6;
  int *pwVar7;
  int wVar8;
  int wVar9;
  int iVar10;
  ObjectClass *pOVar11;
  FunctionBar *pFVar12;
  long in_RCX;
  ulong a3;
  int wVar13;
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
  long in_FS_OFFSET = (long)__fake_fs;
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
                    /* Unresolved local var: int ch@[???]
                       Unresolved local var: int ok@[???] */
  (*(code *)(pOVar11[1].display))(&this->super,in_RSI,lVar14,in_RCX,in_R8,(long)in_R9);
LAB_0012ac90:
  do {
    while( true ) {
      lVar14 = 0;
      a3 = 1;
      Panel_draw(this_00,false,true,true,false);
      a1 = (RichString *)(ulong)(uint)CRT_colors[2];
      IncSet_drawBar(this->inc,CRT_colors[2]);
      wVar8 = Panel_getCh(this_00);
      if (wVar8 != -1) break;
      p_Var3 = (this->super).klass[1].delete;
      if (p_Var3 == (Object_Delete)0x0) {
        in_R9 = this->inc;
        if (in_R9->active != (IncMode *)0x0) {
LAB_0012ad68:
          IncSet_handleKey(in_R9,wVar8,this_00,IncSet_getListItemValue,this->lines);
        }
      }
      else {
        (*(code *)(p_Var3))(&this->super,(long)a1,(long)a2,a3,lVar14,(long)in_R9);
      }
    }
    if (wVar8 == 409) {
      iVar10 = getmouse(&(*(MEVENT (*))(__fp - 0x58)));
      a2_01 = extraout_RDX_00;
      if (iVar10 == 0) {
        if (((*(MEVENT (*))(__fp - 0x58)).bstate & 1) != 0) {
          wVar9 = this_00->y;
          a3 = (ulong)(uint)wVar9;
          wVar13 = _LINES + -1;
          a2_01 = (IncMode *)(ulong)(uint)wVar13;
          if (((*(MEVENT (*))(__fp - 0x58)).y < wVar9) || (wVar13 <= (*(MEVENT (*))(__fp - 0x58)).y)) {
            if ((*(MEVENT (*))(__fp - 0x58)).y != wVar13) goto LAB_0012adce;
            in_R9 = this->inc;
            a1 = (RichString *)(ulong)(uint)(*(MEVENT (*))(__fp - 0x58)).x;
            if (in_R9->active == (IncMode *)0x0) {
              wVar8 = FunctionBar_synthesizeEvent(in_R9->defaultBar,(*(MEVENT (*))(__fp - 0x58)).x);
              a2_01 = extraout_RDX_04;
              goto LAB_0012ace5;
            }
            wVar8 = FunctionBar_synthesizeEvent(in_R9->active->bar,(*(MEVENT (*))(__fp - 0x58)).x);
          }
          else {
                    /* Unresolved local var: int size@[???] */
            wVar13 = ((*(MEVENT (*))(__fp - 0x58)).y - wVar9) + this_00->scrollV + -1;
            wVar9 = this_00->items->items;
            wVar8 = wVar9 + -1;
            a3 = (ulong)(uint)wVar8;
            if (wVar9 <= wVar13) {
              wVar13 = wVar8;
            }
            a2_01 = (IncMode *)0x0;
            if (wVar13 < 0) {
              wVar13 = 0;
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
              wVar8 = 0;
              goto LAB_0012addd;
            }
            wVar8 = 0;
          }
          goto LAB_0012ad68;
        }
        in_R9 = this->inc;
        a2_01 = in_R9->active;
        pIVar6 = a2_01;
        if (((*(MEVENT (*))(__fp - 0x58)).bstate & 0x10000) == 0) {
          if (((*(MEVENT (*))(__fp - 0x58)).bstate & 0x200000) == 0) goto LAB_0012adce;
          wVar8 = 295;
        }
        else {
          wVar8 = 294;
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
    if (wVar8 == 267) {
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
    if (wVar8 < 268) {
      if (wVar8 != 27) {
        if (wVar8 < 28) break;
        if (wVar8 == 92) goto LAB_0012aee0;
        if (wVar8 != 'q') {
          if (wVar8 != '/') goto LAB_0012addd;
          goto LAB_0012aea3;
        }
      }
      goto LAB_0012aeb8;
    }
    if (wVar8 == 269) {
      wclear(_stdscr);
      pOVar11 = (this->super).klass;
      pvVar5 = pOVar11[1].extends;
      a2_02 = extraout_RDX_02;
    }
    else {
      if (wVar8 < 270) {
LAB_0012aee0:
        in_R9->active = in_R9->modes + 1;
        pFVar12 = in_R9->modes[1].bar;
        goto LAB_0012aef5;
      }
      if (wVar8 == 274) {
LAB_0012aeb8:
        if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      if (wVar8 != 410) goto LAB_0012addd;
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
      (*(code *)((this->super).klass[1].extends))((long)this,(long)a1,a2_03,a3,lVar14,(long)in_R9);
      pOVar11 = (this->super).klass;
      a2_02 = extraout_RDX_01;
    }
    (*(code *)(pOVar11[1].display))(&this->super,a1,(long)a2_02,a3,lVar14,(long)in_R9);
  } while( true );
  if (wVar8 != -1) {
    if (wVar8 == 12) {
      wclear(_stdscr);
      (*(code *)((this->super).klass[1].display))(&this->super,a1,a2_00,a3,lVar14,(long)in_R9);
    }
    else {
LAB_0012addd:
      p_Var4 = (this->super).klass[1].compare;
      if ((p_Var4 == (Object_Compare)0x0) ||
         (wVar9 = (*(code *)(p_Var4))(this,(void *)(ulong)(uint)wVar8,(long)a2_01,a3,lVar14,(long)in_R9),
         (char)wVar9 == '\0')) {
        Panel_onKey(this_00,wVar8);
      }
    }
  }
  goto LAB_0012ac90;
}


/* InfoScreen_addLine @ 0x12b620 */

/* DWARF original prototype: void InfoScreen_addLine(InfoScreen * this, char * line) */

void InfoScreen_addLine(InfoScreen *this,char *line)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  IncMode *__s;
  Vector *this_00;
  undefined8 *data_;
  char *pcVar1;
  char **__ptr;
  size_t sVar2;
  char **ppcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  data_ = malloc(0x18);
  if (data_ == (undefined8 *)0x0) {
LAB_0012b7e3:
                    /* WARNING: Subroutine does not return */
    fail();
  }
                    /* Unresolved local var: char * data@[???] */
  *data_ = &ListItem_class;
  pcVar1 = strdup(line);
  if (pcVar1 == (char *)0x0) goto LAB_0012b7e3;
  this_00 = this->lines;
  data_[1] = pcVar1;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
  *(undefined4 *)(data_ + 2) = 0;
  *(undefined1 *)((long)data_ + 0x14) = 0;
  Vector_set(this_00,this_00->items,data_);
  if (this->inc->filtering == false) {
LAB_0012b739:
                    /* Unresolved local var: char * incFilter@[???] */
    if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      Panel_add(this->display,this->lines->array[this->lines->items + -1]);
      return;
    }
  }
  else {
    __s = this->inc->modes + 1;
    pcVar1 = strchr(__s->buffer,0x7c);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strcasestr(line,__s->buffer);
      if (pcVar1 != (char *)0x0) goto LAB_0012b739;
    }
    else {
                    /* Unresolved local var: char * * needles@[???] */
      __ptr = String_split(__s->buffer,'|',&(*(size_t (*))(__fp - 0x48)));
                    /* Unresolved local var: size_t i@[???] */
      if ((*(size_t (*))(__fp - 0x48)) != 0) {
        sVar2 = 0;
LAB_0012b6fd:
        pcVar1 = strcasestr(line,__ptr[sVar2]);
        if (pcVar1 == (char *)0x0) goto LAB_0012b6f0;
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
        goto LAB_0012b739;
      }
      if (__ptr != (char **)0x0) {
LAB_0012b7b8:
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
      }
    }
    if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012b6f0:
  sVar2 = sVar2 + 1;
  if ((*(size_t (*))(__fp - 0x48)) == sVar2) goto LAB_0012b7b8;
  goto LAB_0012b6fd;
}


/* InfoScreen_appendLine @ 0x12c160 */

/* DWARF original prototype: void InfoScreen_appendLine(InfoScreen * this, char * line) */

void InfoScreen_appendLine(InfoScreen *this,char *line)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  IncMode *__s;
  ListItem *this_00;
  char *pcVar1;
  char **__ptr;
  char **ppcVar2;
  size_t sVar3;
  Panel *this_01;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (ListItem *)this->lines->array[this->lines->items + -1];
  ListItem_append(this_00,line);
  if ((this->inc->filtering != false) &&
     (this_01 = this->display,
     this_00 != (ListItem *)this_01->items->array[this_01->items->items + -1])) {
    __s = this->inc->modes + 1;
    pcVar1 = strchr(__s->buffer,0x7c);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strcasestr(line,__s->buffer);
      if (pcVar1 != (char *)0x0) {
LAB_0012c26e:
        if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
          Panel_add(this_01,(Object *)this_00);
          return;
        }
        goto LAB_0012c305;
      }
    }
    else {
                    /* Unresolved local var: char * * needles@[???] */
      __ptr = String_split(__s->buffer,'|',&(*(size_t (*))(__fp - 0x48)));
                    /* Unresolved local var: size_t i@[???] */
      if ((*(size_t (*))(__fp - 0x48)) != 0) {
        sVar3 = 0;
LAB_0012c22a:
        pcVar1 = strcasestr(line,__ptr[sVar3]);
        if (pcVar1 == (char *)0x0) goto LAB_0012c220;
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar2 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar2 = ppcVar2 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar2;
        }
        free(__ptr);
        this_01 = this->display;
        goto LAB_0012c26e;
      }
      if (__ptr != (char **)0x0) {
LAB_0012c2a0:
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar2 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar2 = ppcVar2 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar2;
        }
        free(__ptr);
      }
    }
  }
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0012c305:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012c220:
  sVar3 = sVar3 + 1;
  if ((*(size_t (*))(__fp - 0x48)) == sVar3) goto LAB_0012c2a0;
  goto LAB_0012c22a;
}

