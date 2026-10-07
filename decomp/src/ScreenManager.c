#include "htop.h"

/* drawTab @ 0x12d3d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool drawTab(int *y,int *x,int l,char *name,_Bool cur)

{
  int iVar1;
  int iVar2;
  int wVar3;
  size_t sVar4;
  long lVar5;

                    /* Unresolved local var: int nameLen@[???]
                       Unresolved local var: int n@[???] */
  lVar5 = (-(ulong)!cur & 0xfffffffffffffff8) + 0x158;
  wattrset(_stdscr,*(int *)((long)CRT_colors + lVar5));
  iVar1 = wmove(_stdscr,*y,*x);
  if (iVar1 != -1) {
    waddch(_stdscr,0x5b);
  }
  wVar3 = *x + 1;
  *x = wVar3;
  if (wVar3 < l) {
    sVar4 = strlen(name);
    iVar1 = (int)sVar4;
    if (l - wVar3 <= (int)sVar4) {
      iVar1 = l - wVar3;
    }
    wattrset(_stdscr,*(int *)((long)CRT_colors + (-(ulong)!cur & 0xfffffffffffffff8) + 0x15c));
    iVar2 = wmove(_stdscr,*y,*x);
    if (iVar2 == -1) {
      wVar3 = iVar1 + *x;
      *x = wVar3;
    }
    else {
      waddnstr(_stdscr,name,iVar1);
      wVar3 = iVar1 + *x;
      *x = wVar3;
    }
    if (wVar3 < l) {
      wattrset(_stdscr,*(int *)((long)CRT_colors + lVar5));
      iVar1 = wmove(_stdscr,*y,*x);
      if (iVar1 == -1) {
        wVar3 = *x + 2;
        *x = wVar3;
      }
      else {
        waddch(_stdscr,0x5d);
        wVar3 = *x + 2;
        *x = wVar3;
      }
      return wVar3 < l;
    }
  }
  return false;
}


/* ScreenManager_size @ 0x12de10 */

/* DWARF original prototype: int ScreenManager_size(ScreenManager * this) */

int ScreenManager_size(ScreenManager *this)

{
  return this->panelCount;
}


/* ScreenManager_resize @ 0x12dea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void ScreenManager_resize(ScreenManager * this) */

void ScreenManager_resize(ScreenManager *this)

{
  int wVar1;
  int iVar2;
  Object **ppOVar3;
  Object *pOVar4;
  int iVar5;
  Object **ppOVar6;
  int iVar7;
  int iVar8;
  int wVar9;

  wVar9 = this->y1;
  if ((this->state->hideMeters == false) && (this->header != (Header_2 *)0x0)) {
    wVar9 = wVar9 + this->header->height;
  }
  wVar1 = this->panelCount;
                    /* Unresolved local var: int i@[???] */
  iVar5 = wVar1 + -1;
  ppOVar3 = this->panels->array;
  iVar8 = (_LINES - wVar9) + this->y2;
  if (iVar5 < 1) {
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    ppOVar6 = ppOVar3;
    do {
                    /* Unresolved local var: Panel * panel@[???] */
      pOVar4 = *ppOVar6;
      ppOVar6 = ppOVar6 + 1;
      *(int *)&pOVar4[1].klass = iVar7;
      iVar2 = *(int *)&pOVar4[2].klass;
      *(int *)((long)&pOVar4[2].klass + 4) = iVar8;
      iVar7 = iVar7 + iVar2 + 1;
      *(undefined1 *)&pOVar4[9].klass = 1;
      *(int *)((long)&pOVar4[1].klass + 4) = wVar9;
    } while (ppOVar3 + (ulong)(uint)(wVar1 + -2) + 1 != ppOVar6);
  }
  pOVar4 = ppOVar3[iVar5];
  iVar5 = _COLS - this->x1;
  wVar1 = this->x2;
  *(undefined1 *)&pOVar4[9].klass = 1;
  pOVar4[1].klass = (ObjectClass *)CONCAT44(wVar9,iVar7);
  pOVar4[2].klass = (ObjectClass *)CONCAT44(iVar8,(iVar5 + wVar1) - iVar7);
  return;
}


/* ScreenManager_delete @ 0x12e390 */

/* DWARF original prototype: void ScreenManager_delete(ScreenManager * this) */

void ScreenManager_delete(ScreenManager *this)

{
  Vector_delete(this->panels);
  free(this);
  return;
}


/* ScreenManager_remove @ 0x12e530 */

/* DWARF original prototype: Panel * ScreenManager_remove(ScreenManager * this, int idx) */

Panel * ScreenManager_remove(ScreenManager *this,int idx)

{
  int wVar1;
  Object *pOVar2;
  int iVar3;
  int wVar4;
  Vector *this_00;
  Object **ppOVar5;
  Object *pOVar6;
  Panel *pPVar7;
  Object **ppOVar8;
  long in_RCX;
  long a2;
  long lVar9;
  ulong a1;
  long in_R8;
  long in_R9;

  lVar9 = (long)idx;
                    /* Unresolved local var: Object * removed@[???] */
  a1 = (ulong)(uint)idx;
  this_00 = this->panels;
  iVar3 = *(int *)&this_00->array[lVar9][2].klass;
  pPVar7 = (Panel *)Vector_take(this_00,idx);
  if (this_00->owner != false) {
    (*(code *)(((pPVar7->super).klass)->delete))((Object *)pPVar7,a1,a2,in_RCX,in_R8,in_R9);
    pPVar7 = (Panel *)0x0;
  }
  wVar4 = this->panelCount;
  wVar1 = wVar4 + -1;
  this->panelCount = wVar1;
  if (idx < wVar1) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Panel * p@[???] */
    ppOVar5 = this->panels->array;
    ppOVar8 = ppOVar5 + lVar9;
    do {
      pOVar6 = *ppOVar8;
      ppOVar8 = ppOVar8 + 1;
      pOVar2 = pOVar6 + 1;
      *(int *)&pOVar2->klass = *(int *)&pOVar2->klass - iVar3;
      *(undefined1 *)&pOVar6[9].klass = 1;
    } while (ppOVar8 != ppOVar5 + (ulong)(uint)((wVar4 - idx) - 2) + lVar9 + 1);
  }
  return pPVar7;
}


/* ScreenManager_new @ 0x132190 */

ScreenManager_3 * ScreenManager_new(Header_4 *header,Machine_2 *host,State *state,_Bool owner)

{
  ScreenManager_3 *pSVar1;
  Vector *pVVar2;
  Object **ppOVar3;

                    /* Unresolved local var: void * data@[???] */
  pSVar1 = malloc(0x48);
  if (pSVar1 != (ScreenManager_3 *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    pSVar1->x1 = 0;
    pSVar1->y1 = 0;
    pSVar1->x2 = 0;
    pSVar1->y2 = -1;
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
                    /* Unresolved local var: void * data@[???] */
      pVVar2->growthRate = 10;
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pSVar1->panelCount = 0;
        pSVar1->header = header;
        pVVar2->array = ppOVar3;
        pVVar2->arraySize = 10;
        pVVar2->type = &Panel_class.super;
        pVVar2->owner = owner;
        pVVar2->items = 0;
        pVVar2->dirty_index = -1;
        pVVar2->dirty_count = 0;
        pSVar1->panels = pVVar2;
        pSVar1->host = host;
        pSVar1->state = state;
        pSVar1->allowFocusChange = true;
        return pSVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ScreenManager_insert @ 0x132f90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void ScreenManager_insert(ScreenManager * this, Panel * item, int
   size, int idx) */

void ScreenManager_insert(ScreenManager *this,Panel *item,int size,int idx)

{
  Object *pOVar1;
  int wVar2;
  Vector *this_00;
  Header_2 *pHVar3;
  Object **ppOVar4;
  Object *pOVar5;
  int iVar6;
  long lVar7;
  int wVar8;
  int wVar9;

  wVar8 = 0;
                    /* Unresolved local var: Panel * last@[???] */
  this_00 = this->panels;
  if (0 < idx) {
    wVar8 = *(int *)&this_00->array[idx + -1][2].klass +
            *(int *)&this_00->array[idx + -1][1].klass + 1;
  }
  wVar9 = this->y1;
  wVar2 = this->y2;
  iVar6 = _LINES - wVar9;
  if (this->state->hideMeters == false) {
    pHVar3 = this->header;
    if (pHVar3 != (Header_2 *)0x0) {
      iVar6 = iVar6 - pHVar3->height;
    }
    if (size < 1) {
      size = ((_COLS - this->x1) + this->x2) - wVar8;
    }
    item->w = size;
    item->h = iVar6 + wVar2;
    item->needsRedraw = true;
    if (pHVar3 != (Header_2 *)0x0) {
      wVar9 = wVar9 + pHVar3->height;
    }
  }
  else {
    if (size < 1) {
      size = ((_COLS - this->x1) + this->x2) - wVar8;
    }
    item->w = size;
    item->h = iVar6 + wVar2;
    item->needsRedraw = true;
  }
  item->y = wVar9;
  wVar9 = this->panelCount;
  item->x = wVar8;
                    /* Unresolved local var: int i@[???] */
  if ((idx < wVar9) && (idx + 1 <= wVar9)) {
                    /* Unresolved local var: Panel * p@[???] */
    ppOVar4 = this_00->array;
    lVar7 = (long)(idx + 1);
    do {
      pOVar5 = ppOVar4[lVar7];
      lVar7 = lVar7 + 1;
      pOVar1 = pOVar5 + 1;
      *(int *)&pOVar1->klass = *(int *)&pOVar1->klass + size;
      *(undefined1 *)&pOVar5[9].klass = 1;
    } while ((int)lVar7 <= wVar9);
  }
  Vector_insert(this_00,idx,item);
  item->needsRedraw = true;
  this->panelCount = this->panelCount + 1;
  return;
}


/* ScreenManager_add @ 0x1330b0 */

/* DWARF original prototype: void ScreenManager_add(ScreenManager * this, Panel * item, int
   size) */

void ScreenManager_add(ScreenManager *this,Panel *item,int size)

{
  ScreenManager_insert(this,item,size,this->panels->items);
  return;
}


/* Vector_set @ 0x1330c0 */

/* DWARF original prototype: void Vector_set(Vector * this, int idx, void * data_) */

void Vector_set(Vector *this,int idx,void *data_)

{
  Object *pOVar1;
  Object **ppOVar2;
  long in_RCX;
  int wVar3;
  size_t prevmemb;
  long in_R8;
  long in_R9;
  int wVar4;

  wVar4 = idx + 1;
  prevmemb = (size_t)this->arraySize;
                    /* Unresolved local var: int oldSize@[???] */
  ppOVar2 = this->array;
  if (this->arraySize < wVar4) {
    in_RCX = 8;
    wVar3 = this->growthRate + wVar4;
    this->arraySize = wVar3;
    ppOVar2 = xReallocArrayZero(ppOVar2,prevmemb,(long)wVar3,8);
    this->array = ppOVar2;
  }
                    /* Unresolved local var: Object * removed@[???] */
  ppOVar2 = ppOVar2 + idx;
  if (idx < this->items) {
    if ((this->owner != false) && (pOVar1 = *ppOVar2, pOVar1 != (Object *)0x0)) {
      (*(code *)(pOVar1->klass->delete))(pOVar1,prevmemb,(long)pOVar1->klass,in_RCX,in_R8,in_R9);
      ppOVar2 = this->array + idx;
    }
  }
  else {
    this->items = wVar4;
  }
  *ppOVar2 = data_;
  return;
}


/* ScreenManager_run @ 0x134a30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void ScreenManager_run(ScreenManager * this, Panel * * lastFocus,
   int * lastKey, char * name) */

void ScreenManager_run(ScreenManager *this,Panel **lastFocus,int *lastKey,char *name)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  _Bool *p_Var1;
  Settings__2 *pSVar2;
  LinuxMachine_ *super;
  Settings__5 *pSVar3;
  Settings__2 *pSVar4;
  MainPanel__2 *this_00;
  State_2 *pSVar5;
  code *pcVar6;
  ScreenSettings_2 **ppSVar7;
  ScreenSettings_2 *pSVar8;
  Panel *pPVar9;
  bool bVar10;
  bool bVar11;
  _Bool _Var12;
  int iVar13;
  int wVar14;
  uint uVar15;
  ulong uVar16;
  Object **ppOVar17;
  void *pvVar18;
  int wVar19;
  void *extraout_RDX;
  void *extraout_RDX_00;
  void *pvVar20;
  void *extraout_RDX_01;
  uint uVar21;
  Object **in_R8;
  ulong in_R9;
  long lVar22;
  ulong a1;
  char cVar23;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar24;

  cVar23 = '\x01';
                    /* Unresolved local var: int prevCh@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: double newTime@[???] */
  uVar21 = 1;
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  bVar10 = true;
  (*(double (*))(__fp - 0x90)) = 0.0;
  bVar11 = false;
  (*(uint (*))(__fp - 0x78)) = 0;
  (*(int (*))(__fp - 0x94)) = 0;
  (*(int (*))(__fp - 0x80)) = -1;
  (*(uint (*))(__fp - 0x74)) = 0;
  (*(Panel *(*))(__fp - 0x88)) = (Panel *)*this->panels->array;
  pSVar2 = this->host->settings;
  this->name = name;
LAB_00134ac3:
  if (this->header == (Header_2 *)0x0) goto LAB_00134d68;
LAB_00134acf:
  super = (LinuxMachine_ *)this->host;
  Generic_gettime_realtime(&(super->super).realtime,&(super->super).realtimeMs);
  wVar14 = Row_uidDigits;
  pSVar3 = (super->super).settings;
  (*(double (*))(__fp - 0x70)) = (double)(super->super).realtime.tv_sec * 10.0 +
             (double)(super->super).realtime.tv_usec / 100000.0;
  bVar10 = (double)pSVar3->delay < (*(double (*))(__fp - 0x70)) - (*(double (*))(__fp - 0x90));
  if ((((*(double (*))(__fp - 0x70)) < (*(double (*))(__fp - 0x90))) || (bVar10)) || (bVar11)) {
                    /* Unresolved local var: int oldUidDigits@[???] */
    name = (char *)this->state;
    if (((char)((Panel *)name)->cursorX == '\0') &&
       ((in_R9 = (ulong)(*(uint (*))(__fp - 0x78)), (*(uint (*))(__fp - 0x78)) == 0 || (pSVar3->ss->treeView != false)))) {
      (*(uint (*))(__fp - 0x78)) = 1;
      ((super->super).activeTable)->needsSort = true;
    }
    Machine_scan(super);
    if (this->state->pauseUpdate == false) {
      Machine_scanTables((Machine *)super);
    }
    Header_updateData((Header *)this->header);
    if (wVar14 != Row_uidDigits) {
      uVar21 = 1;
    }
  }
  else {
    if (cVar23 == '\0') goto LAB_00134b5b;
    (*(double (*))(__fp - 0x70)) = (*(double (*))(__fp - 0x90));
  }
  Table_rebuildPanel((Table *)(super->super).activeTable);
  if (this->state->hideMeters == false) {
    Header_draw((Header *)this->header);
  }
  (*(double (*))(__fp - 0x90)) = (*(double (*))(__fp - 0x70));
  bVar11 = false;
LAB_00134b63:
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: int nPanels@[???] */
  pSVar4 = this->host->settings;
  cVar23 = pSVar4->screenTabs;
  pPVar9 = (Panel *)name;
  wVar14 = _COLS;
joined_r0x00134b6f:
  name = (char *)pPVar9;
  _COLS = wVar14;
  if (cVar23 != '\0') {
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: ScreenSettings * * screens@[???]
                       Unresolved local var: int cur@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: Panel * panel@[???] */
    ppSVar7 = pSVar4->screens;
    uVar15 = pSVar4->ssIndex;
    (*(int (*))(__fp - 0x58)) = 2;
    (*(int (*))(__fp - 0x5c)) = *(int *)((long)&(*this->panels->array)[1].klass + 4) + -1;
    name = this->name;
    if ((Panel *)name == (Panel *)0x0) {
      lVar22 = 0;
                    /* Unresolved local var: int s@[???] */
      pSVar8 = *ppSVar7;
      name = (char *)pPVar9;
      while (pSVar8 != (ScreenSettings_2 *)0x0) {
                    /* Unresolved local var: _Bool ok@[???] */
        bVar24 = uVar15 == (uint)lVar22;
        name = pSVar8->heading;
        in_R8 = (Object **)(ulong)bVar24;
        _Var12 = drawTab(&(*(int (*))(__fp - 0x5c)),&(*(int (*))(__fp - 0x58)),wVar14,name,bVar24);
        if (!_Var12) break;
        lVar22 = lVar22 + 1;
        pSVar8 = ppSVar7[lVar22];
      }
      wattrset(_stdscr,*CRT_colors);
    }
    else {
      in_R8 = (Object **)0x1;
      drawTab(&(*(int (*))(__fp - 0x5c)),&(*(int (*))(__fp - 0x58)),wVar14,name,true);
    }
  }
  wVar14 = this->panelCount;
                    /* Unresolved local var: int i@[???] */
  if (0 < wVar14) {
                    /* Unresolved local var: Panel * panel@[???] */
    lVar22 = 0;
    do {
                    /* Unresolved local var: Settings * settings@[???] */
      in_R8 = (Object **)0x1;
      this_00 = (MainPanel__2 *)this->panels->array[lVar22];
      pSVar5 = this->state;
      wVar19 = pSVar5->host->settings->hideFunctionBar;
      if ((wVar19 != 2) && (in_R8 = (Object **)0x0, wVar19 == 1)) {
        in_R8 = (Object **)(ulong)pSVar5->hideSelection;
      }
      name = (char *)0x1;
      if (this_00 == pSVar5->mainPanel) {
        name = (char *)(ulong)(pSVar5->hideSelection ^ 1);
      }
      Panel_draw((Panel *)this_00,SUB41(uVar21,0),(*(uint (*))(__fp - 0x74)) == (uint)lVar22,SUB81(name,0),
                 SUB81(in_R8,0));
      iVar13 = wmove(_stdscr,(this_00->super).y,(this_00->super).w + (this_00->super).x);
      if (iVar13 != -1) {
        name = (char *)this->state;
                    /* Unresolved local var: Settings * settings@[???] */
        wVar19 = (this_00->super).h;
        iVar13 = *(int *)((long)((((Panel *)name)->super).klass)->extends + 0x70);
        if (iVar13 == 2) {
          wVar19 = wVar19 + 1;
        }
        else if (iVar13 == 1) {
          wVar19 = wVar19 + (uint)*(byte *)((long)&((Panel *)name)->cursorX + 1);
        }
        wvline(_stdscr,0x20,wVar19);
      }
      lVar22 = lVar22 + 1;
    } while (lVar22 != wVar14);
  }
  lVar22 = this->host->iterationsRemaining;
  if ((lVar22 != -1) &&
     (lVar22 = lVar22 + -1, this->host->iterationsRemaining = lVar22, lVar22 == 0)) {
LAB_00134eb5:
    if (lastFocus != (Panel **)0x0) {
      *lastFocus = (*(Panel *(*))(__fp - 0x88));
    }
    if (lastKey != (int *)0x0) {
      *lastKey = (*(int (*))(__fp - 0x80));
    }
    if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
LAB_00134c80:
  wVar14 = Panel_getCh((*(Panel *(*))(__fp - 0x88)));
  a1 = (ulong)(uint)wVar14;
  pvVar20 = extraout_RDX;
  if (wVar14 == 409) {
    if (pSVar2->enableMouse == false) goto LAB_00134cd8;
                    /* Unresolved local var: int ok@[???] */
    iVar13 = getmouse(&(*(int (*))(__fp - 0x58)));
    if (iVar13 == 0) {
      if (((*(uint (*))(__fp - 0x48)) & 1) == 0) {
        pvVar20 = extraout_RDX_00;
        if (((*(uint (*))(__fp - 0x48)) & 0x10000) == 0) {
          a1 = 0x127;
          if (((*(uint (*))(__fp - 0x48)) & 0x200000) == 0) goto LAB_00134e75;
        }
        else {
          a1 = 0x126;
        }
        goto LAB_00134cd8;
      }
      if ((*(int (*))(__fp - 0x50)) == _LINES + -1) {
        wVar14 = FunctionBar_synthesizeEvent((*(Panel *(*))(__fp - 0x88))->currentBar,(*(int (*))(__fp - 0x54)));
        a1 = (ulong)(uint)wVar14;
        pvVar20 = extraout_RDX_01;
        goto LAB_00134c97;
      }
                    /* Unresolved local var: int i@[???] */
      if (0 < this->panelCount) {
                    /* Unresolved local var: Panel * panel@[???] */
        name = (char *)(ulong)(uint)(*(int (*))(__fp - 0x54));
        in_R8 = this->panels->array;
        lVar22 = 0;
        do {
          pPVar9 = (Panel *)in_R8[lVar22];
          wVar14 = pPVar9->x;
          pvVar20 = (void *)(ulong)(uint)wVar14;
          if ((wVar14 <= (*(int (*))(__fp - 0x54))) &&
             (wVar19 = pPVar9->w + wVar14, in_R9 = (ulong)(uint)wVar19, (*(int (*))(__fp - 0x54)) <= wVar19)) {
            wVar19 = pPVar9->y;
            if ((*(int (*))(__fp - 0x50)) == wVar19) {
              name = (char *)(ulong)(uint)((*(int (*))(__fp - 0x54)) - wVar14);
              a1 = (ulong)(uint)(((*(int (*))(__fp - 0x54)) - wVar14) - 10000);
              goto LAB_00134c97;
            }
            if ((pSVar2->screenTabs != false) &&
               (pvVar20 = (void *)(ulong)(uint)(wVar19 + -1),
               (*(int (*))(__fp - 0x50)) == wVar19 + -1)) {
              a1 = (ulong)(uint)((*(int (*))(__fp - 0x54)) + -20000);
              goto LAB_00134c97;
            }
            if ((wVar19 < (*(int (*))(__fp - 0x50))) &&
               (wVar14 = pPVar9->h + wVar19, pvVar20 = (void *)(ulong)(uint)wVar14,
               (*(int (*))(__fp - 0x50)) <= wVar14)) goto LAB_00135370;
          }
          lVar22 = lVar22 + 1;
          if (lVar22 == this->panelCount) break;
        } while( true );
      }
    }
LAB_00134e75:
    (*(uint (*))(__fp - 0x78)) = (*(uint (*))(__fp - 0x78)) - (0 < (int)(*(uint (*))(__fp - 0x78)));
    if ((*(int (*))(__fp - 0x80)) != -1) {
      (*(int (*))(__fp - 0x94)) = 0;
      cVar23 = '\0';
      uVar21 = 0;
      (*(int (*))(__fp - 0x80)) = -1;
      goto LAB_00134ac3;
    }
    if (bVar10) {
      (*(int (*))(__fp - 0x94)) = 0;
      cVar23 = '\0';
      uVar21 = 0;
    }
    else {
      (*(int (*))(__fp - 0x94)) = (*(int (*))(__fp - 0x94)) + 1;
      if ((*(int (*))(__fp - 0x94)) == 100) goto LAB_00134eb5;
      cVar23 = '\0';
      uVar21 = 0;
    }
    goto LAB_00134ac3;
  }
LAB_00134c97:
  iVar13 = (int)a1;
  if (iVar13 == -1) goto LAB_00134e75;
  if (iVar13 == 0x138) {
    a1 = 0x103;
  }
  else if (iVar13 < 0x139) {
    if (iVar13 == 0x135) {
      a1 = 0x104;
    }
    else if (iVar13 == 0x137) {
      a1 = 0x102;
    }
  }
  else if (iVar13 == 0x139) {
    a1 = 0x105;
  }
  goto LAB_00134cd8;
LAB_00135370:
  if ((pPVar9 == (*(Panel *(*))(__fp - 0x88))) || (this->allowFocusChange != false)) {
                    /* Unresolved local var: Object * oldSelection@[???] */
    name = (char *)pPVar9->items;
    pvVar20 = (void *)0x0;
    wVar14 = ((Panel *)name)->cursorX;
    if (0 < wVar14) {
      pvVar20 = (&((((Panel *)name)->super).klass)->extends)[pPVar9->selected];
    }
                    /* Unresolved local var: int size@[???] */
    wVar19 = ((*(int (*))(__fp - 0x50)) - wVar19) + pPVar9->scrollV + -1;
    if (wVar14 <= wVar19) {
      wVar19 = wVar14 + -1;
    }
    if (wVar19 < 0) {
      wVar19 = 0;
    }
    pPVar9->selected = wVar19;
    pcVar6 = (pPVar9->super).klass[1].extends;
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)((long)pPVar9,0xffffffff,(long)pvVar20,(long)name,(long)in_R8,in_R9);
      name = (char *)pPVar9->items;
      wVar14 = ((Panel *)name)->cursorX;
    }
    pvVar18 = (void *)0x0;
    if (0 < wVar14) {
      pvVar18 = (&((((Panel *)name)->super).klass)->extends)[pPVar9->selected];
    }
    (*(uint (*))(__fp - 0x74)) = (uint)lVar22;
    (*(Panel *(*))(__fp - 0x88)) = pPVar9;
    if (pvVar18 == pvVar20) {
      a1 = 0x128;
    }
  }
LAB_00134cd8:
  pcVar6 = ((*(Panel *(*))(__fp - 0x88))->super).klass[1].extends;
  if (pcVar6 == (code *)0x0) {
    uVar21 = 0;
  }
  else {
    uVar16 = (*pcVar6)((long)(*(Panel *(*))(__fp - 0x88)),a1,(long)pvVar20,(long)name,(long)in_R8,in_R9);
    if ((uVar16 & 0x80) != 0) {
      a1 = uVar16 >> 0x10 & 0xffff;
    }
    (*(int (*))(__fp - 0x80)) = (int)a1;
    uVar15 = 0;
    if ((uVar16 & 8) == 0) {
      uVar15 = (*(uint (*))(__fp - 0x78));
    }
    if ((uVar16 & 0x40) == 0) {
      uVar21 = (uint)(uVar16 >> 4) & 1;
    }
    else {
      uVar21 = 1;
      ScreenManager_resize(this);
    }
    bVar24 = (uVar16 & 0x20) != 0;
    if (bVar24) {
      bVar11 = true;
    }
    (*(uint (*))(__fp - 0x78)) = 0;
    if (!bVar24) {
      (*(uint (*))(__fp - 0x78)) = uVar15;
    }
    if ((uVar16 & 1) != 0) goto LAB_00134d4d;
    if ((uVar16 & 4) != 0) goto switchD_00134fea_caseD_1b;
  }
  (*(int (*))(__fp - 0x80)) = (int)a1;
  if ((*(int (*))(__fp - 0x80)) == 'q') {
switchD_00134fea_caseD_1b:
    goto LAB_00134eb5;
  }
  if ('q' < (*(int (*))(__fp - 0x80))) {
    if ((*(int (*))(__fp - 0x80)) == 274) goto switchD_00134fea_caseD_1b;
    if (274 < (*(int (*))(__fp - 0x80))) {
      if ((*(int (*))(__fp - 0x80)) == 410) {
        cVar23 = '\x01';
        ScreenManager_resize(this);
        (*(int (*))(__fp - 0x80)) = 410;
        goto LAB_00134ac3;
      }
      goto switchD_00134fea_caseD_3;
    }
    if ((*(int (*))(__fp - 0x80)) != 260) {
      if ((*(int (*))(__fp - 0x80)) != 261) goto switchD_00134fea_caseD_3;
      goto switchD_00134fea_caseD_6;
    }
switchD_00134fea_caseD_2:
    if (this->panelCount < 2) {
switchD_00134fea_caseD_3:
      cVar23 = '\x01';
      Panel_onKey((*(Panel *(*))(__fp - 0x88)),(*(int (*))(__fp - 0x80)));
      (*(uint (*))(__fp - 0x78)) = 5;
      goto LAB_00134ac3;
    }
    cVar23 = this->allowFocusChange;
    if ((_Bool)cVar23 != false) {
      ppOVar17 = this->panels->array + (int)(*(uint (*))(__fp - 0x74));
      if (0 < (int)(*(uint (*))(__fp - 0x74))) goto LAB_0013530c;
      (*(Panel *(*))(__fp - 0x88)) = (Panel *)*ppOVar17;
      goto LAB_00134ac3;
    }
LAB_00134d4d:
    cVar23 = '\x01';
    if (this->header != (Header_2 *)0x0) goto LAB_00134acf;
LAB_00134d68:
    if (cVar23 != '\0') goto code_r0x00134d71;
LAB_00134b5b:
    if ((char)uVar21 != '\0') goto LAB_00134b63;
    goto LAB_00134c80;
  }
  switch(a1) {
  case 2:
    goto switchD_00134fea_caseD_2;
  default:
    goto switchD_00134fea_caseD_3;
  case 6:
  case 9:
switchD_00134fea_caseD_6:
    if (this->panelCount < 2) goto switchD_00134fea_caseD_3;
    cVar23 = this->allowFocusChange;
    if ((_Bool)cVar23 != false) {
      iVar13 = this->panelCount + -1;
      name = (char *)this->panels->array;
      lVar22 = (long)((((Panel *)name)->header).chstr + -4) + (long)(int)(*(uint (*))(__fp - 0x74)) * 8;
      if ((int)(*(uint (*))(__fp - 0x74)) < iVar13) {
        name = (char *)(ulong)(*(uint (*))(__fp - 0x74));
        break;
      }
      (*(Panel *(*))(__fp - 0x88)) = *(Panel **)((long)((((Panel *)name)->header).chstr + -4) + (long)(int)(*(uint (*))(__fp - 0x74)) * 8)
      ;
      goto LAB_00134ac3;
    }
    goto LAB_00134d4d;
  case 0x1b:
    goto switchD_00134fea_caseD_1b;
  case 0x23:
    cVar23 = '\x01';
    uVar21 = 1;
    p_Var1 = &this->state->hideMeters;
    *p_Var1 = (_Bool)(*p_Var1 ^ 1);
    ScreenManager_resize(this);
    goto LAB_00134ac3;
  }
  while ((int)(*(uint (*))(__fp - 0x74)) < iVar13) {
    (*(Panel *(*))(__fp - 0x88)) = *(Panel **)(lVar22 + 8);
    (*(uint (*))(__fp - 0x74)) = (int)name + 1;
    name = (char *)(ulong)(*(uint (*))(__fp - 0x74));
    lVar22 = lVar22 + 8;
    if ((*(Panel *(*))(__fp - 0x88))->items->items != 0) break;
  }
  goto LAB_00134ac3;
  while (0 < (int)(*(uint (*))(__fp - 0x74))) {
LAB_0013530c:
    name = (char *)ppOVar17[-1];
    (*(uint (*))(__fp - 0x74)) = (*(uint (*))(__fp - 0x74)) - 1;
    ppOVar17 = ppOVar17 + -1;
    wVar14 = ((Panel *)name)->items->items;
    in_R8 = (Object **)(ulong)(uint)wVar14;
    (*(Panel *(*))(__fp - 0x88)) = (Panel *)name;
    if (wVar14 != 0) break;
  }
  goto LAB_00134ac3;
code_r0x00134d71:
  pSVar4 = this->host->settings;
  cVar23 = pSVar4->screenTabs;
  pPVar9 = (Panel *)name;
  wVar14 = _COLS;
  goto joined_r0x00134b6f;
}

