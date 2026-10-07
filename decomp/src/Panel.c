#include "htop.h"

/* Panel_getSelectedIndex @ 0x120830 */

/* DWARF original prototype: int Panel_getSelectedIndex(Panel * this) */

int Panel_getSelectedIndex(Panel *this)

{
  return this->selected;
}


/* Panel_get @ 0x120840 */

/* DWARF original prototype: Object * Panel_get(Panel * this, int i) */

Object * Panel_get(Panel *this,int i)

{
  return this->items->array[i];
}


/* Panel_setHeader @ 0x120880 */

/* DWARF original prototype: void Panel_setHeader(Panel * this, char * header) */

void Panel_setHeader(Panel *this,char *header)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  int wVar1;
  int __wc;
  long lVar2;
  undefined1 *puVar3;
  Panel *pPVar4;
  int len;
  int iVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  cchar_t *pcVar9;
  undefined1 *puVar10;
  int *pwVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar11;

  puVar10 = (*(undefined1 (*) [8])(__fp - 0x58));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  wVar1 = CRT_colors[7];
  (*(Panel *(*))(__fp - 0x50)) = this;
  sVar6 = strlen(header);
                    /* Unresolved local var: int[6165] data@[???]
                       Unresolved local var: int newLen@[???] */
  uVar8 = (ulong)((int)sVar6 + 1);
  uVar7 = uVar8 * 4 + 0xf;
  puVar11 = (*(undefined1 (*) [8])(__fp - 0x58));
  puVar3 = (*(undefined1 (*) [8])(__fp - 0x58));
  while (puVar11 != (*(undefined1 (*) [8])(__fp - 0x58)) + -(uVar7 & 0xfffffffffffff000)) {
    puVar10 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar11 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar7 = (ulong)((uint)uVar7 & 0xff0);
  lVar2 = -uVar7;
  pwVar12 = (int *)(puVar10 + lVar2);
  if (uVar7 != 0) {
    *(undefined8 *)(puVar10 + -8) = *(undefined8 *)(puVar10 + -8);
  }
  uVar7 = __mbstowcs_chk((int *)(puVar10 + lVar2),header,(long)(int)sVar6,uVar8 & 0x3fffffffffffffff
                        );
  pPVar4 = (*(Panel *(*))(__fp - 0x50));
  len = (int)uVar7;
  if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(*(Panel *(*))(__fp - 0x50))->header,len);
    pcVar9 = (pPVar4->header).chptr;
    do {
      __wc = *pwVar12;
      iVar5 = iswprint(__wc);
      pcVar9->attr = 0;
      pcVar9->chars[0] = 0;
      pcVar9->chars[1] = 0;
      pcVar9->chars[2] = 0;
      if (iVar5 == 0) {
        __wc = 65533;
      }
      pwVar12 = pwVar12 + 1;
      pcVar9->attr = wVar1 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
      pcVar9->chars[0] = __wc;
      pcVar9 = pcVar9 + 1;
    } while (pwVar12 != (int *)(puVar10 + (ulong)(uint)(len + -1) * 4 + lVar2 + 4));
  }
  (*(Panel *(*))(__fp - 0x50))->needsRedraw = true;
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Panel_setSelected @ 0x120f60 */

/* DWARF original prototype: void Panel_setSelected(Panel * this, int selected) */

void Panel_setSelected(Panel *this,int selected)

{
  int wVar1;
  int wVar2;
  code *UNRECOVERED_JUMPTABLE;
  long in_RCX;
  long in_R8;
  long in_R9;

  wVar2 = this->items->items;
  wVar1 = wVar2 + -1;
  if (wVar2 <= selected) {
    selected = wVar1;
  }
  if (selected < 0) {
    selected = 0;
  }
  UNRECOVERED_JUMPTABLE = (this->super).klass[1].extends;
  this->selected = selected;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00120f8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)this,0xffffffff,(ulong)(uint)wVar1,in_RCX,in_R8,in_R9);
    return;
  }
  return;
}


/* Panel_getSelected @ 0x120fa0 */

/* DWARF original prototype: Object * Panel_getSelected(Panel * this) */

Object * Panel_getSelected(Panel *this)

{
  Object *pOVar1;

  pOVar1 = (Object *)0x0;
  if (0 < this->items->items) {
    pOVar1 = this->items->array[this->selected];
  }
  return pOVar1;
}


/* Panel_size @ 0x120fc0 */

/* DWARF original prototype: int Panel_size(Panel * this) */

int Panel_size(Panel *this)

{
  return this->items->items;
}


/* Panel_resize @ 0x120fd0 */

/* DWARF original prototype: void Panel_resize(Panel * this, int w, int h) */

void Panel_resize(Panel *this,int w,int h)

{
  this->w = w;
  this->h = h;
  this->needsRedraw = true;
  return;
}


/* Panel_setSelectionColor @ 0x121310 */

/* DWARF original prototype: void Panel_setSelectionColor(Panel * this, ColorElements colorId) */

void Panel_setSelectionColor(Panel *this,ColorElements colorId)

{
  this->selectionColorId = colorId;
  return;
}


/* Panel_moveSelectedUp @ 0x1215d0 */

/* DWARF original prototype: void Panel_moveSelectedUp(Panel * this) */

void Panel_moveSelectedUp(Panel *this)

{
  Object **ppOVar1;
  int wVar2;
  Object **ppOVar3;
  Object *pOVar4;

  wVar2 = this->selected;
                    /* Unresolved local var: Object * temp@[???] */
  if (wVar2 != 0) {
    ppOVar3 = this->items->array;
                    /* Unresolved local var: Object * temp@[???] */
    ppOVar1 = ppOVar3 + (long)wVar2 + -1;
    pOVar4 = *ppOVar1;
    ppOVar3 = ppOVar3 + (long)wVar2 + -1;
    *ppOVar3 = ppOVar1[1];
    ppOVar3[1] = pOVar4;
    if (0 < wVar2) {
      this->selected = wVar2 + -1;
    }
  }
  return;
}


/* Panel_setCursorToSelection @ 0x122090 */

/* DWARF original prototype: void Panel_setCursorToSelection(Panel * this) */

void Panel_setCursorToSelection(Panel *this)

{
  this->cursorY = ((this->selected + this->y) - this->scrollV) + 1;
  this->cursorX = (this->selectedLen + this->x) - this->scrollH;
  return;
}


/* Panel_move @ 0x1220b0 */

/* DWARF original prototype: void Panel_move(Panel * this, int x, int y) */

void Panel_move(Panel *this,int x,int y)

{
  this->x = x;
  this->y = y;
  this->needsRedraw = true;
  return;
}


/* Panel_remove @ 0x1220c0 */

/* DWARF original prototype: Object * Panel_remove(Panel * this, int i) */

Object * Panel_remove(Panel *this,int i)

{
  _Bool _Var1;
  Vector *pVVar2;
  Object *pOVar3;
  Object **a3;
  int wVar4;
  undefined4 in_register_00000034;
  Object **__src;
  long in_R8;
  long in_R9;
  Object *pOVar5;

                    /* Unresolved local var: Object * removed@[???] */
  __src = (Object **)CONCAT44(in_register_00000034,i);
  pVVar2 = this->items;
  this->needsRedraw = true;
  a3 = pVVar2->array;
  wVar4 = pVVar2->items + -1;
                    /* Unresolved local var: Object * removed@[???] */
  pOVar3 = a3[i];
  pVVar2->items = wVar4;
  if (i < wVar4) {
    __src = a3 + (long)i + 1;
    memmove(a3 + i,__src,(long)(wVar4 - i) << 3);
    a3 = pVVar2->array;
    wVar4 = pVVar2->items;
  }
  _Var1 = pVVar2->owner;
  a3[wVar4] = (Object *)0x0;
  pOVar5 = pOVar3;
  if (_Var1 != false) {
    pOVar5 = (Object *)0x0;
    (*(code *)(pOVar3->klass->delete))(pOVar3,(long)__src,(long)wVar4,(long)a3,in_R8,in_R9);
  }
  wVar4 = this->selected;
  if ((0 < wVar4) && (this->items->items <= wVar4)) {
    this->selected = wVar4 + -1;
  }
  return pOVar5;
}


/* Panel_moveSelectedDown @ 0x122170 */

/* DWARF original prototype: void Panel_moveSelectedDown(Panel * this) */

void Panel_moveSelectedDown(Panel *this)

{
  Object **ppOVar1;
  int wVar2;
  int wVar3;
  Object *pOVar4;

  wVar2 = this->selected;
                    /* Unresolved local var: Object * temp@[???] */
  wVar3 = this->items->items;
  if (wVar2 != wVar3 + -1) {
    ppOVar1 = this->items->array + wVar2;
    pOVar4 = *ppOVar1;
    *ppOVar1 = ppOVar1[1];
    ppOVar1[1] = pOVar4;
  }
  if (wVar2 + 1 < wVar3) {
    this->selected = wVar2 + 1;
  }
  return;
}


/* Panel_onKey @ 0x1221b0 */

/* DWARF original prototype: _Bool Panel_onKey(Panel * this, int key) */

_Bool Panel_onKey(Panel *this,int key)

{
  int wVar1;
  int wVar2;
  int wVar3;
  int wVar4;
  byte bVar5;
  int wVar6;
  uint uVar7;

  wVar6 = CRT_scrollWheelVAmount;
  wVar1 = this->items->items;
  if (295 < key) {
    if (key == 339) {
      wVar4 = this->h;
      uVar7 = (uint)(0 < (this->header).chlen);
      wVar6 = uVar7 - wVar4;
    }
    else {
      if (key == 360) {
        this->selected = wVar1 + -1;
        if (0 < wVar1) {
          return true;
        }
        goto LAB_001222a1;
      }
      if (key != 338) {
        return false;
      }
      wVar4 = this->h;
      uVar7 = (uint)(0 < (this->header).chlen);
      wVar6 = wVar4 - uVar7;
    }
    wVar3 = this->selected + wVar6;
    this->selected = wVar3;
LAB_0012226d:
    wVar4 = (wVar1 - wVar4) - uVar7;
    if (wVar4 < 0) {
      wVar4 = 0;
    }
    wVar6 = wVar6 + this->scrollV;
LAB_0012227d:
    if (wVar6 < 0) {
      wVar6 = 0;
    }
    this->needsRedraw = true;
    if (wVar6 < wVar4) {
      wVar4 = wVar6;
    }
    bVar5 = (byte)((uint)wVar3 >> 0x1f);
    this->scrollV = wVar4;
    goto LAB_00122294;
  }
  if (key < 258) {
    if (key < '%') {
      switch(key) {
      case 1:
        goto switchD_0012220e_caseD_1;
      case 2:
        goto switchD_001221e7_caseD_104;
      default:
        goto switchD_001221e7_caseD_107;
      case 5:
      case '$':
        wVar6 = this->selectedLen - this->w;
        if (wVar6 < 0) {
          wVar6 = 0;
        }
        this->scrollH = wVar6;
        goto LAB_001222e1;
      case 6:
        goto switchD_001221e7_caseD_105;
      case 14:
        goto switchD_001221e7_caseD_102;
      case 16:
        goto switchD_001221e7_caseD_103;
      }
    }
    if (key != '^') {
switchD_001221e7_caseD_107:
      return false;
    }
switchD_0012220e_caseD_1:
    this->scrollH = 0;
LAB_001222e1:
    wVar3 = this->selected;
    this->needsRedraw = true;
    bVar5 = (byte)((uint)wVar3 >> 0x1f);
  }
  else {
    switch(key) {
    case 258:
switchD_001221e7_caseD_102:
      wVar3 = this->selected + 1;
      this->selected = wVar3;
      bVar5 = (byte)((uint)wVar3 >> 0x1f);
      break;
    case 259:
switchD_001221e7_caseD_103:
      wVar3 = this->selected + -1;
      this->selected = wVar3;
      bVar5 = (byte)((uint)wVar3 >> 0x1f);
      break;
    case 260:
switchD_001221e7_caseD_104:
      wVar3 = this->selected;
      bVar5 = (byte)((uint)wVar3 >> 0x1f);
      if (0 < this->scrollH) {
        this->needsRedraw = true;
        wVar6 = CRT_scrollHAmount;
        if (CRT_scrollHAmount < 0) {
          wVar6 = 0;
        }
        this->scrollH = this->scrollH - wVar6;
      }
      break;
    case 261:
switchD_001221e7_caseD_105:
      this->scrollH = this->scrollH + CRT_scrollHAmount;
      goto LAB_001222e1;
    case 262:
      this->selected = 0;
      bVar5 = 0;
      wVar3 = 0;
      break;
    default:
      goto switchD_001221e7_caseD_107;
    case 294:
      wVar4 = (this->header).chlen;
      wVar3 = this->selected - CRT_scrollWheelVAmount;
      this->selected = wVar3;
      wVar4 = (wVar1 - this->h) - (uint)(0 < wVar4);
      if (wVar4 < 0) {
        wVar4 = 0;
      }
      wVar6 = this->scrollV - wVar6;
      goto LAB_0012227d;
    case 295:
      wVar2 = (this->header).chlen;
      wVar4 = this->h;
      wVar3 = this->selected + CRT_scrollWheelVAmount;
      this->selected = wVar3;
      uVar7 = (uint)(0 < wVar2);
      goto LAB_0012226d;
    }
  }
LAB_00122294:
  if ((wVar1 != 0) && (bVar5 == 0)) {
    if (wVar3 < wVar1) {
      return true;
    }
    this->needsRedraw = true;
    this->selected = wVar1 + -1;
    return true;
  }
LAB_001222a1:
  this->selected = 0;
  this->needsRedraw = true;
  return true;
}


/* Panel_getCh @ 0x122440 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: int Panel_getCh(Panel * this) */

int Panel_getCh(Panel *this)

{
  int wVar1;

  if (this->cursorOn == false) {
    curs_set(0);
  }
  else {
    wmove(_stdscr,this->cursorY,this->cursorX);
    curs_set(1);
  }
  set_escdelay(0x19);
  wVar1 = wgetch(_stdscr);
  return wVar1;
}


/* Panel_new @ 0x123f10 */

Panel * Panel_new(int x,int y,int w,int h,ObjectClass *type,_Bool owner,
                 FunctionBar *fuBar)

{
  Panel *pPVar1;
  Vector *pVVar2;
  Object **ppOVar3;

                    /* Unresolved local var: void * data@[???] */
  pPVar1 = malloc(0x26e0);
  if (pPVar1 != (Panel *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    pPVar1->cursorX = 0;
    pPVar1->cursorY = 0;
    (pPVar1->super).klass = &Panel_class.super;
    pPVar1->eventHandlerState = (void *)0x0;
    pPVar1->x = x;
    pPVar1->y = y;
    pPVar1->w = w;
    pPVar1->h = h;
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
      pVVar2->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pVVar2->array = ppOVar3;
        (pPVar1->header).chstr[0].attr = 0;
        (pPVar1->header).chstr[0].chars[0] = 0;
        (pPVar1->header).chstr[0].chars[1] = 0;
        (pPVar1->header).chstr[0].chars[2] = 0;
        pVVar2->items = 0;
        pVVar2->dirty_index = -1;
        pPVar1->needsRedraw = true;
        pPVar1->cursorOn = false;
        (pPVar1->header).chptr = (pPVar1->header).chstr;
        *(undefined8 *)&(pPVar1->header).highlightAttr = 0x900000000;
        pVVar2->arraySize = 10;
        pVVar2->type = type;
        pVVar2->owner = owner;
        pVVar2->dirty_count = 0;
        pPVar1->items = pVVar2;
        pPVar1->scrollV = 0;
        pPVar1->scrollH = 0;
        pPVar1->selected = 0;
        pPVar1->oldSelected = 0;
        pPVar1->selectedLen = 0;
        pPVar1->wasFocus = false;
        (pPVar1->header).chlen = 0;
        *(undefined16 *)(*(undefined1 (*) [16])((pPVar1->header).chstr[0].chars + 2)) = (undefined16)0x0;
        pPVar1->currentBar = fuBar;
        pPVar1->defaultBar = fuBar;
        return pPVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Panel_init @ 0x124070 */

/* DWARF original prototype: void Panel_init(Panel * this, int x, int y, int w, int
   h, ObjectClass * type, _Bool owner, FunctionBar * fuBar) */

void Panel_init(Panel *this,int x,int y,int w,int h,ObjectClass *type,_Bool owner,
               FunctionBar *fuBar)

{
  Vector *pVVar1;
  Object **ppOVar2;

  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->cursorX = 0;
  this->cursorY = 0;
  this->eventHandlerState = (void *)0x0;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
  pVVar1 = malloc(0x28);
  if (pVVar1 != (Vector *)0x0) {
    pVVar1->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
    ppOVar2 = calloc(10,8);
    if (ppOVar2 != (Object **)0x0) {
      pVVar1->array = ppOVar2;
      (this->header).chstr[0].attr = 0;
      (this->header).chstr[0].chars[0] = 0;
      (this->header).chstr[0].chars[1] = 0;
      (this->header).chstr[0].chars[2] = 0;
      pVVar1->items = 0;
      pVVar1->dirty_index = -1;
      this->needsRedraw = true;
      this->cursorOn = false;
      (this->header).chptr = (this->header).chstr;
      pVVar1->arraySize = 10;
      pVVar1->type = type;
      pVVar1->owner = owner;
      pVVar1->dirty_count = 0;
      this->items = pVVar1;
      this->scrollV = 0;
      this->scrollH = 0;
      this->selected = 0;
      this->oldSelected = 0;
      this->selectedLen = 0;
      this->wasFocus = false;
      (this->header).chlen = 0;
      *(undefined8 *)&(this->header).highlightAttr = 0x900000000;
      *(undefined16 *)(*(undefined1 (*) [16])((this->header).chstr[0].chars + 2)) = (undefined16)0x0;
      this->currentBar = fuBar;
      this->defaultBar = fuBar;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Panel_selectByTyping @ 0x1241a0 */

/* DWARF original prototype: HandlerResult Panel_selectByTyping(Panel * this, int ch) */

HandlerResult Panel_selectByTyping(Panel *this,int ch)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char cVar1;
  int wVar2;
  int wVar3;
  Vector *pVVar4;
  Object **ppOVar5;
  code *pcVar6;
  int iVar7;
  ushort **ppuVar8;
  size_t sVar9;
  long lVar10;
  char *__s;
  int wVar11;
  char *pcVar12;
  ObjectClass *__s1;
  long in_R8;
  long in_R9;

  wVar2 = this->items->items;
  if (ch == '#') {
    return IGNORED;
  }
  __s = this->eventHandlerState;
  if (__s == (char *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    __s = calloc(100,1);
    if (__s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->eventHandlerState = __s;
  }
  if (0xfd < (uint)(ch + -1)) {
    if (ch == -1) {
      return IGNORED;
    }
    *__s = '\0';
    return IGNORED;
  }
  ppuVar8 = __ctype_b_loc();
  if (-1 < (short)(*ppuVar8)[ch]) {
    *__s = '\0';
    if (ch != 13) {
      return IGNORED;
    }
                    /* Unresolved local var: int len@[???] */
    return BREAK_LOOP;
  }
  sVar9 = strlen(__s);
  iVar7 = (int)sVar9;
  if (iVar7 == 0) {
    pcVar12 = __s;
    if (ch == '/') {
      lVar10 = 1;
      ch = 1;
    }
    else {
      if (ch == 'q') {
        return BREAK_LOOP;
      }
      lVar10 = 1;
    }
  }
  else if (iVar7 == 1) {
    pcVar12 = __s + (*__s != '\x01');
    lVar10 = (ulong)(*__s != '\x01') + 1;
  }
  else {
    if (0x62 < iVar7) goto LAB_00124276;
    pcVar12 = __s + iVar7;
    lVar10 = (long)iVar7 + 1;
  }
  *pcVar12 = (char)ch;
                    /* Unresolved local var: int try@[???] */
  __s[lVar10] = '\0';
  sVar9 = strlen(__s);
LAB_00124276:
  (*(int (*))(__fp - 0x50)) = 2;
  do {
                    /* Unresolved local var: int i@[???] */
    if (0 < wVar2) {
                    /* Unresolved local var: char * cur@[???] */
      pVVar4 = this->items;
      lVar10 = 0;
      ppOVar5 = pVVar4->array;
      do {
        __s1 = ppOVar5[lVar10][1].klass;
        cVar1 = *(char *)&__s1->extends;
        while (cVar1 == ' ') {
          __s1 = (ObjectClass *)((long)&__s1->extends + 1);
          cVar1 = *(char *)&__s1->extends;
        }
        iVar7 = strncasecmp((char *)__s1,__s,(long)(int)sVar9);
        if (iVar7 == 0) {
                    /* Unresolved local var: int size@[???] */
          wVar3 = pVVar4->items;
          wVar2 = wVar3 + -1;
          wVar11 = wVar2;
          if ((int)lVar10 < wVar3) {
            wVar11 = (int)lVar10;
          }
          if (wVar11 < 0) {
            wVar11 = 0;
          }
          pcVar6 = (this->super).klass[1].extends;
          this->selected = wVar11;
          if (pcVar6 == (code *)0x0) {
            return HANDLED;
          }
          (*pcVar6)((long)this,0xffffffff,(ulong)(uint)wVar2,(ulong)(uint)wVar11,in_R8,in_R9);
          return HANDLED;
        }
        lVar10 = lVar10 + 1;
      } while (lVar10 != wVar2);
    }
    *__s = (char)ch;
    __s[1] = '\0';
    if ((*(int (*))(__fp - 0x50)) == 1) {
      return HANDLED;
    }
    sVar9 = strlen(__s);
    (*(int (*))(__fp - 0x50)) = 1;
  } while( true );
}


/* Panel_prune @ 0x1268d0 */

/* DWARF original prototype: void Panel_prune(Panel * this) */

void Panel_prune(Panel *this)

{
  Vector_prune(this->items);
  this->scrollV = 0;
  this->selected = 0;
  this->oldSelected = 0;
  this->needsRedraw = true;
  return;
}


/* Panel_done @ 0x126bf0 */

/* DWARF original prototype: void Panel_done(Panel * this) */

void Panel_done(Panel *this)

{
  free(this->eventHandlerState);
  Vector_delete(this->items);
  FunctionBar_delete(this->defaultBar);
  if ((this->header).chlen < 351) {
    return;
  }
  free((this->header).chptr);
  (this->header).chptr = (this->header).chstr;
  return;
}


/* Panel_delete @ 0x126ee0 */

void Panel_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(Vector **)((long)param_1 + 0x20));
  FunctionBar_delete(*(FunctionBar **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* Panel_draw @ 0x127810 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void Panel_draw(Panel * this, _Bool force_redraw, _Bool focus, _Bool
   highlightSelected, _Bool hideFunctionBar) */

void Panel_draw(Panel *this,_Bool force_redraw,_Bool focus,_Bool highlightSelected,
               _Bool hideFunctionBar)

{
  undefined1 __frame[0x104dd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x104d98;
  int wVar1;
  int p2;
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
  int wVar9;
  int iVar10;
  int wVar11;
  undefined7 in_register_00000009;
  ulong a3;
  byte bVar12;
  undefined7 in_register_00000011;
  int *extraout_RDX;
  int *extraout_RDX_00;
  int *extraout_RDX_01;
  int *extraout_RDX_02;
  int *extraout_RDX_03;
  int *extraout_RDX_04;
  int *extraout_RDX_05;
  int *extraout_RDX_06;
  cchar_t *pcVar14;
  int *extraout_RDX_07;
  int *extraout_RDX_08;
  int *extraout_RDX_09;
  undefined1 *puVar15;
  int wVar16;
  int wVar17;
  ulong uVar18;
  uint uVar19;
  undefined7 in_register_00000081;
  ulong a4;
  long in_R9;
  int iVar20;
  long in_FS_OFFSET = (long)__fake_fs;
  int *pwVar13;

                    /* Unresolved local var: int size@[???]
                       Unresolved local var: int scrollH@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int header_attr@[???]
                       Unresolved local var: int headerLen@[???]
                       Unresolved local var: int first@[???]
                       Unresolved local var: int upTo@[???]
                       Unresolved local var: int selectionColor@[???] */
  puVar7 = (__fp - 0x30);
  do {
    puVar15 = puVar7;
    *(undefined8 *)(puVar15 + -0x1000) = *(undefined8 *)(puVar15 + -0x1000);
    puVar7 = puVar15 + -0x1000;
  } while ((int *)(puVar15 + -0x1000) != (*(RichString (*))(__fp - 0x4d38)).chstr[0x76].chars + 3);
  uVar18 = CONCAT71(in_register_00000081,hideFunctionBar) & 0xffffffff;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  uVar19 = (this->h + 1) - (uint)((char)uVar18 == '\0');
  wVar17 = this->items->items;
  wVar1 = this->scrollH;
  (*(int (*))(__fp - 0x4d4c)) = this->y;
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
                    /* Unresolved local var: int end@[???] */
      wVar11 = 0;
      if (-1 < wVar9) {
        wVar11 = wVar9;
      }
                    /* Unresolved local var: int i@[???] */
      if (0 < wVar9) {
        pcVar14 = (this->header).chptr;
        wVar9 = 0;
        do {
          wVar9 = wVar9 + 1;
          pcVar14->attr = wVar16;
          pcVar14 = pcVar14 + 1;
        } while (wVar9 < wVar11);
        goto LAB_00127c20;
      }
    }
    else {
      (*(code *)(p_Var3))(&this->super,uVar18,CONCAT71(in_register_00000011,focus),
                CONCAT71(in_register_00000009,highlightSelected),(ulong)uVar19,in_R9);
      wVar9 = (this->header).chlen;
      if (0 < wVar9) goto LAB_001278ee;
    }
LAB_00127c2d:
    uVar18 = (ulong)uVar19;
    (*(int (*))(__fp - 0x4d3c)) = this->scrollV;
    if ((*(int (*))(__fp - 0x4d3c)) < 0) goto LAB_0012798e;
LAB_00127c3a:
    wVar16 = wVar17 - (int)uVar18;
    if (wVar16 < (*(int (*))(__fp - 0x4d3c))) {
      this->needsRedraw = true;
      (*(int (*))(__fp - 0x4d3c)) = 0;
      if (-1 < wVar16) {
        (*(int (*))(__fp - 0x4d3c)) = wVar16;
      }
      this->scrollV = (*(int (*))(__fp - 0x4d3c));
    }
  }
  else {
LAB_00127c20:
    wVar9 = (this->header).chlen;
    if (wVar9 < 1) goto LAB_00127c2d;
LAB_001278ee:
    wattrset(_stdscr,wVar16);
    iVar8 = wmove(_stdscr,(*(int (*))(__fp - 0x4d4c)),p2);
    if (iVar8 != -1) {
      wVar16 = this->w;
      whline(_stdscr,0x20,wVar16);
    }
    if (wVar1 < wVar9) {
      iVar8 = wmove(_stdscr,(*(int (*))(__fp - 0x4d4c)),p2);
      if (iVar8 != -1) {
        wVar16 = this->w;
        if (wVar9 - wVar1 <= this->w) {
          wVar16 = wVar9 - wVar1;
        }
        pcVar14 = (this->header).chptr;
        wadd_wchnstr(_stdscr,pcVar14 + wVar1,wVar16);
      }
    }
    wVar16 = *CRT_colors;
    wattrset(_stdscr,wVar16);
    (*(int (*))(__fp - 0x4d3c)) = this->scrollV;
    (*(int (*))(__fp - 0x4d4c)) = (*(int (*))(__fp - 0x4d4c)) + 1;
    uVar18 = (ulong)(uVar19 - 1);
    if (-1 < (*(int (*))(__fp - 0x4d3c))) goto LAB_00127c3a;
LAB_0012798e:
    this->scrollV = 0;
    (*(int (*))(__fp - 0x4d3c)) = 0;
    this->needsRedraw = true;
  }
  wVar16 = this->selected;
  iVar8 = (int)uVar18;
  if (wVar16 < (*(int (*))(__fp - 0x4d3c))) {
LAB_001279b9:
    this->scrollV = wVar16;
    wVar9 = wVar16 + iVar8;
    this->needsRedraw = true;
    pwVar13 = CRT_colors;
    (*(int (*))(__fp - 0x4d3c)) = wVar16;
    if (focus) {
      a3 = (ulong)(uint)CRT_colors[this->selectionColorId];
    }
    else {
      a3 = (ulong)(uint)CRT_colors[0xb];
    }
  }
  else {
    wVar9 = iVar8 + (*(int (*))(__fp - 0x4d3c));
    if (wVar9 <= wVar16) {
      wVar16 = (wVar16 - iVar8) + 1;
      goto LAB_001279b9;
    }
    bVar12 = force_redraw | this->needsRedraw;
    pwVar13 = (int *)(ulong)bVar12;
    if (focus) {
      wVar16 = CRT_colors[this->selectionColorId];
    }
    else {
      wVar16 = CRT_colors[0xb];
    }
    a3 = (ulong)(uint)wVar16;
    if (bVar12 == 0) {
                    /* Unresolved local var: Object * oldObj@[???]
                       Unresolved local var: int oldLen@[???]
                       Unresolved local var: Object * newObj@[???]
                       Unresolved local var: int newLen@[???] */
      wVar17 = this->oldSelected;
      pOVar5 = this->items->array[wVar17];
      (*(RichString (*))(__fp - 0x26b8)).chptr = (*(RichString (*))(__fp - 0x26b8)).chstr;
      (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 0)) = SUB1612((undefined16)0x0,0);
      (*(RichString (*))(__fp - 0x26b8)).chstr[0].chars[2] = 0;
      (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 16)) = SUB1612((undefined16)0x0,4);
      (*(RichString (*))(__fp - 0x26b8)).chlen = 0;
      (*(RichString (*))(__fp - 0x26b8)).highlightAttr = 0;
      p_Var6 = pOVar5->klass->display;
      (*(code *)(p_Var6))(pOVar5,&(*(RichString (*))(__fp - 0x26b8)),(long)wVar17,a3,uVar18,in_R9);
      wVar11 = (*(RichString (*))(__fp - 0x26b8)).chlen;
      wVar17 = this->selected;
      pOVar5 = this->items->array[wVar17];
      (*(RichString (*))(__fp - 0x4d38)).chptr = (*(RichString (*))(__fp - 0x4d38)).chstr;
      (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x4d38)).chstr[0] + 0)) = SUB1612((undefined16)0x0,0);
      (*(RichString (*))(__fp - 0x4d38)).chstr[0].chars[2] = 0;
      (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x4d38)).chstr[0] + 16)) = SUB1612((undefined16)0x0,4);
      (*(RichString (*))(__fp - 0x4d38)).chlen = 0;
      (*(RichString (*))(__fp - 0x4d38)).highlightAttr = 0;
      p_Var6 = pOVar5->klass->display;
      (*(code *)(p_Var6))(pOVar5,&(*(RichString (*))(__fp - 0x4d38)),(long)wVar17,a3,uVar18,in_R9);
      wVar9 = (*(RichString (*))(__fp - 0x4d38)).chlen;
      p0 = _stdscr;
      wVar17 = this->oldSelected;
      this->selectedLen = (*(RichString (*))(__fp - 0x4d38)).chlen;
      iVar8 = wmove(p0,((*(int (*))(__fp - 0x4d4c)) + wVar17) - (*(int (*))(__fp - 0x4d3c)),p2);
      a4 = uVar18;
      if (iVar8 != -1) {
        wVar17 = this->w;
        whline(_stdscr,0x20,wVar17);
        a4 = uVar18;
      }
      if (wVar1 < wVar11) {
        wVar17 = this->oldSelected;
        iVar8 = wmove(_stdscr,((*(int (*))(__fp - 0x4d4c)) + wVar17) - (*(int (*))(__fp - 0x4d3c)),p2);
        if (iVar8 != -1) {
          wVar11 = wVar11 - wVar1;
          wVar17 = this->w;
          if (wVar11 <= this->w) {
            wVar17 = wVar11;
          }
          wadd_wchnstr(_stdscr,(*(RichString (*))(__fp - 0x26b8)).chptr + wVar1,wVar17);
        }
      }
      wattrset(_stdscr,wVar16);
      wVar17 = this->selected;
      iVar8 = wmove(_stdscr,((*(int (*))(__fp - 0x4d4c)) + wVar17) - (*(int (*))(__fp - 0x4d3c)),p2);
      if (iVar8 != -1) {
        wVar17 = this->w;
        whline(_stdscr,0x20,wVar17);
      }
      a3 = (ulong)(uint)wVar16;
                    /* Unresolved local var: int end@[???] */
      wVar17 = 0;
      if (-1 < (*(RichString (*))(__fp - 0x4d38)).chlen) {
        wVar17 = (*(RichString (*))(__fp - 0x4d38)).chlen;
      }
                    /* Unresolved local var: int i@[???] */
      if (0 < (*(RichString (*))(__fp - 0x4d38)).chlen) {
        wVar11 = 0;
        pcVar14 = (*(RichString (*))(__fp - 0x4d38)).chptr;
        do {
          wVar11 = wVar11 + 1;
          pcVar14->attr = wVar16;
          pcVar14 = pcVar14 + 1;
        } while (wVar11 < wVar17);
      }
      if (wVar1 < wVar9) {
        wVar17 = this->selected;
        iVar8 = wmove(_stdscr,((*(int (*))(__fp - 0x4d4c)) + wVar17) - (*(int (*))(__fp - 0x4d3c)),p2);
        if (iVar8 != -1) {
          a3 = (ulong)wVar1;
          wVar9 = wVar9 - wVar1;
          wVar17 = this->w;
          if (wVar9 <= this->w) {
            wVar17 = wVar9;
          }
          wadd_wchnstr(_stdscr,(*(RichString (*))(__fp - 0x4d38)).chptr + a3,wVar17);
        }
      }
      wVar17 = *CRT_colors;
      wattrset(_stdscr,wVar17);
      pwVar13 = extraout_RDX_05;
      if (350 < (*(RichString (*))(__fp - 0x4d38)).chlen) {
        free((*(RichString (*))(__fp - 0x4d38)).chptr);
        pwVar13 = extraout_RDX_09;
      }
      if (350 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
        free((*(RichString (*))(__fp - 0x26b8)).chptr);
        pwVar13 = extraout_RDX_06;
      }
      goto LAB_00127e70;
    }
  }
  if (wVar9 <= wVar17) {
    wVar17 = wVar9;
  }
                    /* Unresolved local var: int line@[???]
                       Unresolved local var: int i@[???] */
  if ((iVar8 < 1) || (wVar17 <= (*(int (*))(__fp - 0x4d3c)))) {
    iVar20 = 0;
  }
  else {
                    /* Unresolved local var: Object * itemObj@[???]
                       Unresolved local var: int itemLen@[???]
                       Unresolved local var: int amt@[???] */
    wVar16 = (int)a3;
    (*(ulong (*))(__fp - 0x4d48)) = (long)(*(int (*))(__fp - 0x4d3c)) * 8;
    iVar20 = 0;
    pwVar13 = (int *)(long)wVar1;
    a4 = uVar18;
    do {
      a0 = *(long **)((long)this->items->array + (*(ulong (*))(__fp - 0x4d48)));
      (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 0)) = SUB1612((undefined16)0x0,0);
      (*(RichString (*))(__fp - 0x26b8)).chlen = 0;
      (*(RichString (*))(__fp - 0x26b8)).highlightAttr = 0;
      (*(RichString (*))(__fp - 0x26b8)).chstr[0].chars[2] = 0;
      (*(ulong *)((char *)&(*(RichString (*))(__fp - 0x26b8)).chstr[0] + 16)) = SUB1612((undefined16)0x0,4);
      pcVar4 = *(code **)(*a0 + 8);
      a3 = (*(ulong (*))(__fp - 0x4d48));
      (*(RichString (*))(__fp - 0x26b8)).chptr = (*(RichString (*))(__fp - 0x26b8)).chstr;
      (*pcVar4)((long)a0,(long)&(*(RichString (*))(__fp - 0x26b8)),(long)pwVar13,(*(ulong (*))(__fp - 0x4d48)),a4,in_R9);
      wVar11 = (*(RichString (*))(__fp - 0x26b8)).chlen;
      wVar9 = (*(RichString (*))(__fp - 0x26b8)).chlen - wVar1;
      if (this->w < (*(RichString (*))(__fp - 0x26b8)).chlen - wVar1) {
        wVar9 = this->w;
      }
      if ((highlightSelected) && (this->selected == (*(int (*))(__fp - 0x4d3c)))) {
        (*(RichString (*))(__fp - 0x26b8)).highlightAttr = wVar16;
      }
      if ((*(RichString (*))(__fp - 0x26b8)).highlightAttr != 0) {
        wattrset(_stdscr,(*(RichString (*))(__fp - 0x26b8)).highlightAttr);
                    /* Unresolved local var: int end@[???] */
        a3 = 0;
        if (-1 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
          a3 = (ulong)(uint)(*(RichString (*))(__fp - 0x26b8)).chlen;
        }
                    /* Unresolved local var: int i@[???] */
        if (0 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
          iVar10 = 0;
          pcVar14 = (*(RichString (*))(__fp - 0x26b8)).chptr;
          do {
            iVar10 = iVar10 + 1;
            pcVar14->attr = (*(RichString (*))(__fp - 0x26b8)).highlightAttr;
            pcVar14 = pcVar14 + 1;
          } while (iVar10 < (int)a3);
        }
        this->selectedLen = wVar11;
      }
      iVar10 = wmove(_stdscr,iVar20 + (*(int (*))(__fp - 0x4d4c)),p2);
      pwVar13 = extraout_RDX;
      if (iVar10 != -1) {
        wVar11 = this->w;
        whline(_stdscr,0x20,wVar11);
        pwVar13 = extraout_RDX_00;
      }
      if (0 < wVar9) {
        iVar10 = wmove(_stdscr,iVar20 + (*(int (*))(__fp - 0x4d4c)),p2);
        pwVar13 = extraout_RDX_01;
        if (iVar10 != -1) {
          wadd_wchnstr(_stdscr,(*(RichString (*))(__fp - 0x26b8)).chptr + wVar1,wVar9);
          pwVar13 = extraout_RDX_02;
        }
      }
      if ((*(RichString (*))(__fp - 0x26b8)).highlightAttr != 0) {
        wVar9 = *CRT_colors;
        wattrset(_stdscr,wVar9);
        pwVar13 = extraout_RDX_03;
      }
      if (350 < (*(RichString (*))(__fp - 0x26b8)).chlen) {
        free((*(RichString (*))(__fp - 0x26b8)).chptr);
        pwVar13 = extraout_RDX_04;
      }
      (*(int (*))(__fp - 0x4d3c)) = (*(int (*))(__fp - 0x4d3c)) + 1;
      iVar20 = iVar20 + 1;
      (*(ulong (*))(__fp - 0x4d48)) = (*(ulong (*))(__fp - 0x4d48)) + 8;
      if (iVar8 <= iVar20) goto LAB_00127e70;
    } while ((*(int (*))(__fp - 0x4d3c)) < wVar17);
  }
  a4 = uVar18;
  if (iVar20 < iVar8) {
    iVar20 = iVar20 + (*(int (*))(__fp - 0x4d4c));
    do {
      iVar10 = wmove(_stdscr,iVar20,p2);
      pwVar13 = extraout_RDX_07;
      if (iVar10 != -1) {
        wVar17 = this->w;
        whline(_stdscr,0x20,wVar17);
        pwVar13 = extraout_RDX_08;
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 != (*(int (*))(__fp - 0x4d4c)) + iVar8);
  }
LAB_00127e70:
  if ((focus) && (((this->needsRedraw != false || (force_redraw)) || (this->wasFocus == false)))) {
    p_Var6 = (this->super).klass[1].display;
    if (p_Var6 == (Object_Display)0x0) {
      if (!hideFunctionBar) {
        this_00 = this->currentBar;
        FunctionBar_drawExtra(this_00,(char *)0x0,-1,false);
      }
    }
    else {
      (*(code *)(p_Var6))(&this->super,(RichString *)(ulong)hideFunctionBar,(long)pwVar13,a3,a4,in_R9);
    }
  }
  this->needsRedraw = false;
  this->oldSelected = this->selected;
  this->wasFocus = focus;
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Panel_insert @ 0x129b20 */

/* DWARF original prototype: void Panel_insert(Panel * this, int i, Object * o) */

void Panel_insert(Panel *this,int i,Object *o)

{
  Vector_insert(this->items,i,o);
  this->needsRedraw = true;
  return;
}


/* Panel_add @ 0x12a340 */

/* DWARF original prototype: void Panel_add(Panel * this, Object * o) */

void Panel_add(Panel *this,Object *o)

{
  int wVar1;
  Vector *pVVar2;
  Object *pOVar3;
  Object **ppOVar4;
  long a3;
  int wVar5;
  size_t prevmemb;
  int wVar6;
  long in_R9;

  pVVar2 = this->items;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
  wVar1 = pVVar2->items;
                    /* Unresolved local var: Object * data@[???] */
  prevmemb = (size_t)pVVar2->arraySize;
                    /* Unresolved local var: int oldSize@[???] */
  ppOVar4 = pVVar2->array;
  wVar6 = wVar1 + 1;
                    /* Unresolved local var: Object * removed@[???] */
  if (pVVar2->arraySize < wVar6) {
    wVar5 = wVar6 + pVVar2->growthRate;
    a3 = 8;
    pVVar2->arraySize = wVar5;
    ppOVar4 = xReallocArrayZero(ppOVar4,prevmemb,(long)wVar5,8);
    pVVar2->array = ppOVar4;
    if (wVar1 < pVVar2->items) {
      ppOVar4 = ppOVar4 + wVar1;
      if ((pVVar2->owner != false) && (pOVar3 = *ppOVar4, pOVar3 != (Object *)0x0)) {
        (*(code *)(pOVar3->klass->delete))(pOVar3,prevmemb,(long)pOVar3->klass,a3,(ulong)(uint)wVar6,in_R9);
        ppOVar4 = pVVar2->array + wVar1;
      }
      goto LAB_0012a381;
    }
  }
  pVVar2->items = wVar6;
  ppOVar4 = ppOVar4 + wVar1;
LAB_0012a381:
  *ppOVar4 = o;
  this->needsRedraw = true;
  return;
}


/* Panel_set @ 0x12c310 */

/* DWARF original prototype: void Panel_set(Panel * this, int i, Object * o) */

void Panel_set(Panel *this,int i,Object *o)

{
  Vector *pVVar1;
  Object *pOVar2;
  Object **ppOVar3;
  long in_RCX;
  int wVar4;
  size_t prevmemb;
  long in_R8;
  long in_R9;
  int wVar5;

                    /* Unresolved local var: Object * data@[???] */
  wVar5 = i + 1;
  pVVar1 = this->items;
  prevmemb = (size_t)pVVar1->arraySize;
                    /* Unresolved local var: int oldSize@[???] */
  ppOVar3 = pVVar1->array;
  if (pVVar1->arraySize < wVar5) {
    in_RCX = 8;
    wVar4 = pVVar1->growthRate + wVar5;
    pVVar1->arraySize = wVar4;
    ppOVar3 = xReallocArrayZero(ppOVar3,prevmemb,(long)wVar4,8);
    pVVar1->array = ppOVar3;
  }
                    /* Unresolved local var: Object * removed@[???] */
  ppOVar3 = ppOVar3 + i;
  if (i < pVVar1->items) {
    if ((pVVar1->owner != false) && (pOVar2 = *ppOVar3, pOVar2 != (Object *)0x0)) {
      (*(code *)(pOVar2->klass->delete))(pOVar2,prevmemb,(long)pOVar2->klass,in_RCX,in_R8,in_R9);
      ppOVar3 = pVVar1->array + i;
    }
  }
  else {
    pVVar1->items = wVar5;
  }
  *ppOVar3 = o;
  return;
}


/* Panel_splice @ 0x12c3b0 */

/* DWARF original prototype: void Panel_splice(Panel * this, Vector * from) */

void Panel_splice(Panel *this,Vector *from)

{
  Vector_splice(this->items,from);
  this->needsRedraw = true;
  return;
}


/* startRenaming @ 0x12d550 */

void startRenaming(ScreensPanel_ *super)

{
  char *__dest;
  int wVar1;
  Vector *pVVar2;
  ListItem *pLVar3;
  char *__src;
  size_t sVar4;

                    /* Unresolved local var: ScreensPanel * this@[DW_OP_reg5(RDI)]
                       Unresolved local var: ListItem * item@[???]
                       Unresolved local var: char * name@[???] */
  pVVar2 = (super->super).items;
  if (0 < pVVar2->items) {
    wVar1 = (super->super).selected;
    pLVar3 = (ListItem *)pVVar2->array[wVar1];
    if (pLVar3 != (ListItem *)0x0) {
      __src = pLVar3->value;
      (super->super).cursorOn = true;
      __dest = super->buffer;
      super->renamingItem = pLVar3;
      super->saved = __src;
      strncpy(__dest,__src,0x14);
      super->buffer[0x14] = '\0';
      sVar4 = strlen(__dest);
      super->cursor = (int)sVar4;
      pLVar3->value = __dest;
      (super->super).selectionColorId = PANEL_EDIT;
      sVar4 = strlen(__dest);
      (super->super).selectedLen = (int)sVar4;
      (super->super).cursorY = ((wVar1 + (super->super).y) - (super->super).scrollV) + 1;
      (super->super).cursorX = ((int)sVar4 + (super->super).x) - (super->super).scrollH;
    }
    return;
  }
  return;
}

