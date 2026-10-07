#include "htop.h"

/* MainPanel_getValue @ 0x11fae0 */

/* DWARF original prototype: char * MainPanel_getValue(Panel * this, int i) */

char * MainPanel_getValue(Panel *this,int i)

{
  Object *a0;
  code *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  long in_RCX;
  long in_RDX;
  long in_R8;
  long in_R9;

  a0 = this->items->array[i];
  UNRECOVERED_JUMPTABLE = a0->klass[2].extends;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011fafe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(*UNRECOVERED_JUMPTABLE)((long)a0,(long)i,in_RDX,in_RCX,in_R8,in_R9);
    return pcVar1;
  }
  return ((char *)(long)&DAT_00149c0c /* "" */);
}


/* MainPanel_selectedRow @ 0x121320 */

/* DWARF original prototype: int MainPanel_selectedRow(MainPanel * this) */

int MainPanel_selectedRow(MainPanel *this)

{
  Vector *pVVar1;
  Object *pOVar2;
  int wVar3;

  pVVar1 = (this->super).items;
  wVar3 = -1;
  if ((0 < pVVar1->items) &&
     (pOVar2 = pVVar1->array[(this->super).selected], pOVar2 != (Object *)0x0)) {
    wVar3 = *(int *)&pOVar2[2].klass;
  }
  return wVar3;
}


/* MainPanel_foreachRow @ 0x121350 */

/* DWARF original prototype: _Bool MainPanel_foreachRow(MainPanel * this, MainPanel_foreachRowFn fn,
   Arg arg, _Bool * wasAnyTagged) */

_Bool MainPanel_foreachRow(MainPanel *this,MainPanel_foreachRowFn fn,Arg arg,_Bool *wasAnyTagged)

{
  Row_3 *pRVar1;
  _Bool _Var2;
  _Bool _Var3;
  Vector *pVVar4;
  _Bool *a3;
  long lVar5;
  char cVar6;
  long in_R8;
  long in_R9;
  _Bool _Var7;

                    /* Unresolved local var: int i@[???] */
  pVVar4 = (this->super).items;
  if (pVVar4->items < 1) {
    cVar6 = false;
    _Var7 = true;
  }
  else {
    lVar5 = 0;
    cVar6 = '\0';
    _Var7 = true;
    a3 = wasAnyTagged;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pRVar1 = (Row_3 *)pVVar4->array[lVar5];
      _Var3 = pRVar1->tag;
      if (_Var3 != false) {
        _Var2 = (*(code *)(fn))(pRVar1,arg,(long)pVVar4->array,(long)a3,in_R8,in_R9);
        _Var7 = (_Bool)(_Var7 & _Var2);
        pVVar4 = (this->super).items;
        cVar6 = _Var3;
      }
      lVar5 = lVar5 + 1;
    } while ((int)lVar5 < pVVar4->items);
                    /* Unresolved local var: Row * row@[???] */
    if ((cVar6 != '\x01') && (0 < pVVar4->items)) {
      lVar5 = (long)(this->super).selected;
      if ((Row_3 *)pVVar4->array[lVar5] == (Row_3 *)0x0) {
        cVar6 = false;
      }
      else {
        _Var3 = (*(code *)(fn))((Row_3 *)pVVar4->array[lVar5],arg,lVar5,(long)a3,in_R8,in_R9);
        cVar6 = false;
        _Var7 = (_Bool)(_Var7 & _Var3);
      }
    }
  }
  if (wasAnyTagged != (_Bool *)0x0) {
    *wasAnyTagged = (_Bool)cVar6;
  }
  return _Var7;
}


/* MainPanel_setState @ 0x121420 */

/* DWARF original prototype: void MainPanel_setState(MainPanel * this, State * state) */

void MainPanel_setState(MainPanel *this,State *state)

{
  this->state = state;
  return;
}


/* MainPanel_setFunctionBar @ 0x121430 */

/* DWARF original prototype: void MainPanel_setFunctionBar(MainPanel * this, _Bool readonly) */

void MainPanel_setFunctionBar(MainPanel *this,_Bool readonly)

{
  IncSet_2 *pIVar1;
  FunctionBar *pFVar2;

  pIVar1 = this->inc;
  pFVar2 = this->readonlyBar;
  if (!readonly) {
    pFVar2 = this->processBar;
  }
  (this->super).defaultBar = pFVar2;
  pIVar1->defaultBar = pFVar2;
  return;
}


/* MainPanel_delete @ 0x126d80 */

void MainPanel_delete(MainPanel_ *object)

{
  FunctionBar *pFVar1;
  IncSet_2 *pIVar2;
  FunctionBar *this;

  pFVar1 = object->processBar;
  pIVar2 = object->inc;
  (object->super).defaultBar = pFVar1;
  this = object->readonlyBar;
  pIVar2->defaultBar = pFVar1;
  FunctionBar_delete(this);
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if (350 < (object->super).header.chlen) {
    free((object->super).header.chptr);
    (object->super).header.chptr = (object->super).header.chstr;
  }
  pIVar2 = object->inc;
  FunctionBar_delete(pIVar2->modes[0].bar);
  FunctionBar_delete(pIVar2->modes[1].bar);
  free(pIVar2);
  free(object->keys);
  free(object);
  return;
}


/* MainPanel_updateLabels @ 0x129160 */

/* DWARF original prototype: void MainPanel_updateLabels(MainPanel * this, _Bool list, _Bool filter)
    */

void MainPanel_updateLabels(MainPanel *this,_Bool list,_Bool filter)

{
  FunctionBar *this_00;
  char *pcVar1;

  this_00 = (this->super).defaultBar;
  pcVar1 = ((char *)(long)&s_Tree_0014750f /* "Tree  " */);
  if (list) {
    pcVar1 = ((char *)(long)&s_List_00147508 /* "List  " */);
  }
  FunctionBar_setLabel(this_00,269,pcVar1);
  pcVar1 = ((char *)(long)&s_Filter_0014751d /* "Filter" */);
  if (filter) {
    pcVar1 = ((char *)(long)&s_FILTER_00147516 /* "FILTER" */);
  }
  FunctionBar_setLabel(this_00,268,pcVar1);
  return;
}


/* MainPanel_drawFunctionBar @ 0x1291c0 */

void MainPanel_drawFunctionBar(MainPanel_ *super,_Bool hideFunctionBar)

{
  if ((!hideFunctionBar) || (((IncSet *)super->inc)->active != (IncMode *)0x0)) {
    IncSet_drawBar((IncSet *)super->inc,CRT_colors[2]);
    if (super->state->pauseUpdate != false) {
                    /* Unresolved local var: MainPanel * this@[???] */
      FunctionBar_append(((char *)(long)&s_PAUSED_00148882 /* "PAUSED" */),CRT_colors[6]);
      return;
    }
  }
  return;
}


/* MainPanel_printHeader @ 0x129230 */

void MainPanel_printHeader(MainPanel_ *super)

{
  Table_printHeader(super->state->host->settings,&(super->super).header);
  return;
}


/* MainPanel_new @ 0x129250 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

MainPanel * MainPanel_new(void)

{
  MainPanel *this;
  FunctionBar *pFVar1;
  Htop_Action *pp_Var2;
  IncSet_3 *pIVar3;
  bool bVar4;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(10000);
  if (this != (MainPanel *)0x0) {
    (this->super).super.klass = &MainPanel_class.super;
    pFVar1 = FunctionBar_new(MainFunctions,(char **)0x0,(int *)0x0);
    this->processBar = pFVar1;
    pFVar1 = FunctionBar_new(MainFunctions_ro,(char **)0x0,(int *)0x0);
    bVar4 = readonly == false;
    this->readonlyBar = pFVar1;
    if (bVar4) {
      pFVar1 = this->processBar;
    }
    Panel_init(&this->super,1,1,1,1,&Row_class.super,false,pFVar1);
                    /* Unresolved local var: void * data@[???] */
    pp_Var2 = calloc(0x1ff,8);
    if (pp_Var2 != (Htop_Action *)0x0) {
      this->keys = pp_Var2;
      pIVar3 = IncSet_new(pFVar1);
      this->inc = (IncSet_2 *)pIVar3;
      Action_setBindings(this->keys);
      pp_Var2 = this->keys;
      pp_Var2[0x69] = Platform_actionSetIOPriority;
      pp_Var2[0x7b] = Platform_actionLowerAutogroupPriority;
      pp_Var2[0x7d] = Platform_actionHigherAutogroupPriority;
      pp_Var2[0x11b] = Platform_actionLowerAutogroupPriority;
      pp_Var2[0x11c] = Platform_actionHigherAutogroupPriority;
      return this;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* MainPanel_eventHandler @ 0x12b050 */

HandlerResult MainPanel_eventHandler(MainPanel_ *super,int ch)

{
  State *st;
  Machine_2 *pMVar1;
  ScreenSettings_3 *pSVar2;
  FunctionBar *this;
  IncSet_2 *pIVar3;
  MainPanel_ *pMVar4;
  Vector *pVVar5;
  Object *pOVar6;
  code *pcVar7;
  uint uVar8;
  bool bVar9;
  _Bool _Var10;
  Htop_Reaction HVar11;
  Htop_Reaction HVar12;
  HandlerResult HVar13;
  RowField RVar14;
  int wVar15;
  HandlerResult HVar16;
  IncSet *this_00;
  ushort **ppuVar17;
  long lVar18;
  Htop_Reaction HVar19;
  long in_RCX;
  ScreenSettings_3 *pSVar20;
  char cVar21;
  char *pcVar22;
  ulong a2;
  int *pwVar23;
  undefined4 in_register_00000034;
  Htop_Reaction HVar24;
  long in_R8;
  Htop_Reaction HVar25;
  long in_R9;
  IncMode *pIVar26;
  int iVar27;
  Settings_4 *settings;
  Htop_Reaction HVar28;

                    /* Unresolved local var: MainPanel * this@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: Htop_Reaction reaction@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: _Bool needReset@[???]
                       Unresolved local var: Settings * settings@[???]
                       Unresolved local var: ScreenSettings * ss@[???] */
  st = super->state;
  pMVar1 = st->host;
  if (ch == 410) {
    return IGNORED;
  }
  if (ch == 409) {
    settings = pMVar1->settings;
    if (settings->enableMouse == false) {
      this_00 = (IncSet *)super->inc;
      if (this_00->active == (IncMode *)0x0) {
        a2 = 0x198;
        wVar15 = 409;
LAB_0012b2e7:
        if (super->keys[ch] != (Htop_Action)0x0) {
          HVar11 = (*(code *)(super->keys[ch]))(st,CONCAT44(in_register_00000034,ch),a2,in_RCX,in_R8,in_R9);
          goto LAB_0012b0d3;
        }
        if (((uint)a2 < 0xfe) &&
           (ppuVar17 = __ctype_b_loc(), (*(byte *)((long)*ppuVar17 + (long)ch * 2 + 1) & 8) != 0)) {
          iVar27 = wVar15 + -48 + super->idSearch;
                    /* Unresolved local var: int i@[???] */
          pVVar5 = (super->super).items;
          wVar15 = pVVar5->items;
          if (0 < wVar15) {
                    /* Unresolved local var: Row * row@[???] */
            lVar18 = 0;
            do {
              pOVar6 = pVVar5->array[lVar18];
              if ((pOVar6 != (Object *)0x0) && (iVar27 == *(int *)&pOVar6[2].klass)) {
                    /* Unresolved local var: int size@[???] */
                (super->super).selected = (int)lVar18;
                pcVar7 = (super->super).super.klass[1].extends;
                if (pcVar7 != (code *)0x0) {
                  (*pcVar7)((long)super,0xffffffff,(long)pOVar6,(long)wVar15,in_R8,in_R9);
                }
                break;
              }
              lVar18 = lVar18 + 1;
            } while (wVar15 != lVar18);
          }
          uVar8 = iVar27 * 10;
          super->idSearch = uVar8;
          if (10000000 < uVar8) goto LAB_0012b4fc;
        }
        else {
LAB_0012b4fc:
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: pid_t id@[???] */
          super->idSearch = 0;
        }
        HVar16 = IGNORED;
        goto LAB_0012b182;
      }
    }
    else {
      this_00 = (IncSet *)super->inc;
      st->hideSelection = false;
      wVar15 = 409;
      if (this_00->active == (IncMode *)0x0) goto LAB_0012b530;
    }
LAB_0012b32f:
    _Var10 = IncSet_handleKey(this_00,ch,&super->super,MainPanel_getValue,(Vector *)0x0);
    if (_Var10) {
      pIVar3 = super->inc;
      pIVar26 = (IncMode *)0x0;
      if (pIVar3->filtering != false) {
        pIVar26 = pIVar3->modes + 1;
      }
      _Var10 = pIVar3->found;
      pMVar1->activeTable->incFilter = pIVar26->buffer;
      if (_Var10 == false) {
        HVar28 = HTOP_OK;
        HVar19 = HTOP_OK;
        HVar24 = HTOP_REFRESH;
        HVar25 = HTOP_REFRESH;
        HVar11 = HTOP_REDRAW_BAR|HTOP_REFRESH;
        cVar21 = settings->ss->treeView;
        HVar12 = HTOP_REDRAW_BAR|HTOP_REFRESH;
        goto LAB_0012b24d;
      }
      bVar9 = true;
      HVar11 = HTOP_REDRAW_BAR|HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
    }
    else {
                    /* Unresolved local var: _Bool filterChanged@[???] */
      bVar9 = false;
      HVar16 = HANDLED;
      HVar11 = HTOP_KEEP_FOLLOWING;
      if (super->inc->found == false) goto LAB_0012b182;
    }
    pMVar4 = super->state->mainPanel;
                    /* Unresolved local var: Row * row@[???] */
    pVVar5 = (pMVar4->super).items;
    wVar15 = -1;
    if ((0 < pVVar5->items) &&
       (pOVar6 = pVVar5->array[(pMVar4->super).selected], pOVar6 != (Object *)0x0)) {
      wVar15 = *(int *)&pOVar6[2].klass;
    }
    super->state->host->activeTable->following = wVar15;
    (pMVar4->super).selectionColorId = PANEL_SELECTION_FOLLOW;
    if (bVar9) {
      HVar28 = HTOP_OK;
      HVar19 = HTOP_OK;
      HVar24 = HTOP_REFRESH;
      HVar25 = HTOP_REFRESH;
      HVar11 = HTOP_REDRAW_BAR|HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
      pIVar26 = (IncMode *)pMVar1->activeTable->incFilter;
      cVar21 = settings->ss->treeView;
      HVar12 = HTOP_REDRAW_BAR|HTOP_REFRESH;
      goto LAB_0012b24d;
    }
    HVar16 = (-(uint)((HVar11 & HTOP_REFRESH) == HTOP_OK) & 0xfffffff8) + (REFRESH|HANDLED);
  }
  else {
    if (ch == -1) {
      return IGNORED;
    }
    settings = pMVar1->settings;
    st->hideSelection = false;
    pSVar2 = settings->ss;
    if ((uint)(ch + 10000) < 0x3e9) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int hx@[???]
                       Unresolved local var: RowField field@[???] */
      RVar14 = RowField_keyAt(settings,ch + 10000 + (super->super).scrollH + 1);
      if (pSVar2->treeView == false) {
        if (RVar14 != pSVar2->sortKey) goto LAB_0012b1de;
                    /* Unresolved local var: int * attr@[???] */
        wVar15 = pSVar2->direction;
        pwVar23 = &pSVar2->direction;
LAB_0012b3c2:
        HVar11 = 0x67;
        *pwVar23 = ((wVar15 != 1) - 1) + (uint)(wVar15 != 1);
        cVar21 = settings->ss->treeView;
      }
      else {
        if (pSVar2->treeViewAlwaysByPID == false) {
          if (RVar14 == pSVar2->treeSortKey) {
            wVar15 = pSVar2->treeDirection;
            pwVar23 = &pSVar2->treeDirection;
            goto LAB_0012b3c2;
          }
LAB_0012b1de:
          pSVar20 = settings->ss;
        }
        else {
          pSVar20 = settings->ss;
          pSVar2->treeView = false;
          pSVar2->direction = 1;
        }
        _Var10 = Process_fields[RVar14].defaultSortDesc;
        if ((pSVar20->treeViewAlwaysByPID == false) && (pSVar20->treeView != false)) {
          pSVar20->treeSortKey = RVar14;
          cVar21 = '\x01';
          HVar11 = 0x6f;
          pSVar20->treeDirection = (-(uint)(_Var10 == false) & 2) + -1;
        }
        else {
          pSVar20->sortKey = RVar14;
          HVar11 = 0x6f;
          pSVar20->treeView = false;
          cVar21 = '\0';
          pSVar20->direction = (-(uint)(_Var10 == false) & 2) + -1;
        }
      }
      HVar28 = HTOP_OK;
      HVar19 = HTOP_SAVE_SETTINGS;
      HVar24 = HTOP_REFRESH;
      HVar25 = HTOP_UPDATE_PANELHDR;
      pIVar26 = (IncMode *)pMVar1->activeTable->incFilter;
      HVar12 = 0x61;
LAB_0012b24d:
                    /* Unresolved local var: FunctionBar * bar@[???] */
      this = (super->super).defaultBar;
      pcVar22 = ((char *)(long)&s_Tree_0014750f /* "Tree  " */);
      if (cVar21 != '\0') {
        pcVar22 = ((char *)(long)&s_List_00147508 /* "List  " */);
      }
      FunctionBar_setLabel(this,269,pcVar22);
      pcVar22 = ((char *)(long)&s_Filter_0014751d /* "Filter" */);
      if (pIVar26 != (IncMode *)0x0) {
        pcVar22 = ((char *)(long)&s_FILTER_00147516 /* "FILTER" */);
      }
      FunctionBar_setLabel(this,268,pcVar22);
    }
    else {
      if (9999 < (uint)(ch + 20000)) {
        this_00 = (IncSet *)super->inc;
        if (this_00->active != (IncMode *)0x0) goto LAB_0012b32f;
        wVar15 = ch;
        if (ch == 27) {
          st->hideSelection = true;
          return HANDLED;
        }
LAB_0012b530:
        a2 = (ulong)(uint)(wVar15 + -1);
        if ((uint)(wVar15 + -1) < 0x1fe) goto LAB_0012b2e7;
        goto LAB_0012b4fc;
      }
                    /* Unresolved local var: int x@[???] */
      HVar11 = Action_setScreenTab((State_2 *)st,ch + 20000);
LAB_0012b0d3:
      HVar12 = HVar11 & HTOP_RESIZE;
      HVar25 = HVar11 & HTOP_UPDATE_PANELHDR;
      HVar24 = HVar11 & HTOP_REFRESH;
      HVar19 = HVar11 & HTOP_SAVE_SETTINGS;
      HVar28 = HVar11 & HTOP_QUIT;
      if ((HVar11 & HTOP_REDRAW_BAR) != HTOP_OK) {
        pIVar26 = (IncMode *)pMVar1->activeTable->incFilter;
        cVar21 = settings->ss->treeView;
        goto LAB_0012b24d;
      }
    }
    HVar13 = RESIZE|HANDLED;
    if (HVar12 != HTOP_RESIZE) {
      HVar13 = HANDLED;
    }
    if (HVar25 == HTOP_UPDATE_PANELHDR) {
      HVar13 = HVar13 | REDRAW;
    }
    HVar16 = HVar13;
    if (HVar24 != HTOP_OK) {
      HVar16 = HVar13 | (RESCAN|REFRESH);
      if ((~HVar11 & 3) != 0) {
        HVar16 = HVar13 | REFRESH;
      }
    }
    if (HVar19 != HTOP_OK) {
      pMVar1->settings->changed = true;
    }
    if (HVar28 != HTOP_OK) {
      return BREAK_LOOP;
    }
  }
  if ((HVar11 & HTOP_KEEP_FOLLOWING) != HTOP_OK) {
    return HVar16;
  }
LAB_0012b182:
  pMVar1->activeTable->following = -1;
  (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
  return HVar16;
}

