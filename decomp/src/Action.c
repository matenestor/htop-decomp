#include "htop.h"

/* tagAllChildren @ 0x1139b0 */

void tagAllChildren(Panel *panel,Row *parent)

{
  Object **ppOVar1;
  int wVar2;
  Vector *pVVar3;
  Row *parent_00;
  int wVar4;
  Object **ppOVar5;

                    /* Unresolved local var: int parent_id@[???]
                       Unresolved local var: int i@[???] */
  pVVar3 = panel->items;
  parent->tag = true;
  wVar4 = pVVar3->items;
  if (0 < wVar4) {
    ppOVar5 = pVVar3->array;
    wVar2 = parent->id;
    ppOVar1 = ppOVar5 + wVar4;
    do {
                    /* Unresolved local var: Row * row@[???] */
      parent_00 = (Row *)*ppOVar5;
      if (parent_00->tag == false) {
        wVar4 = parent_00->group;
        if (wVar4 == parent_00->id) {
          wVar4 = parent_00->parent;
        }
        if (wVar2 == wVar4) {
          tagAllChildren(panel,parent_00);
        }
      }
      ppOVar5 = ppOVar5 + 1;
    } while (ppOVar1 != ppOVar5);
    return;
  }
  return;
}


/* actionSortByPID @ 0x113a20 */

Htop_Reaction actionSortByPID(State_2 *st)

{
  ScreenSettings_2 *pSVar1;

  pSVar1 = st->host->settings->ss;
  if ((pSVar1->treeViewAlwaysByPID == false) && (pSVar1->treeView != false)) {
    pSVar1->treeSortKey = 1;
    pSVar1->treeDirection = 1;
    return 0x4d;
  }
  pSVar1->sortKey = 1;
  pSVar1->direction = 1;
  pSVar1->treeView = false;
  return 0x4d;
}


/* actionSortByMemory @ 0x113a70 */

Htop_Reaction actionSortByMemory(State_2 *st)

{
  ScreenSettings_2 *pSVar1;

  pSVar1 = st->host->settings->ss;
  if ((pSVar1->treeViewAlwaysByPID == false) && (pSVar1->treeView != false)) {
    pSVar1->treeSortKey = 0x30;
    pSVar1->treeDirection = -1;
    return 0x4d;
  }
  pSVar1->sortKey = 0x30;
  pSVar1->direction = -1;
  pSVar1->treeView = false;
  return 0x4d;
}


/* actionSortByCPU @ 0x113ac0 */

Htop_Reaction actionSortByCPU(State_2 *st)

{
  ScreenSettings_2 *pSVar1;

  pSVar1 = st->host->settings->ss;
  if ((pSVar1->treeViewAlwaysByPID == false) && (pSVar1->treeView != false)) {
    pSVar1->treeSortKey = 0x2f;
    pSVar1->treeDirection = -1;
    return 0x4d;
  }
  pSVar1->sortKey = 0x2f;
  pSVar1->direction = -1;
  pSVar1->treeView = false;
  return 0x4d;
}


/* actionSortByTime @ 0x113b10 */

Htop_Reaction actionSortByTime(State_2 *st)

{
  ScreenSettings_2 *pSVar1;

  pSVar1 = st->host->settings->ss;
  if ((pSVar1->treeViewAlwaysByPID == false) && (pSVar1->treeView != false)) {
    pSVar1->treeSortKey = 0x32;
    pSVar1->treeDirection = -1;
    return 0x4d;
  }
  pSVar1->sortKey = 0x32;
  pSVar1->direction = -1;
  pSVar1->treeView = false;
  return 0x4d;
}


/* actionToggleRunningInContainer @ 0x113b60 */

Htop_Reaction actionToggleRunningInContainer(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Settings__2 *pSVar3;

  pSVar3 = st->host->settings;
  p_Var1 = &pSVar3->hideRunningInContainer;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  return HTOP_KEEP_FOLLOWING|HTOP_SAVE_SETTINGS|HTOP_RECALCULATE;
}


/* actionToggleProgramPath @ 0x113b80 */

Htop_Reaction actionToggleProgramPath(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Settings__2 *pSVar3;

  pSVar3 = st->host->settings;
  p_Var1 = &pSVar3->showProgramPath;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  return HTOP_KEEP_FOLLOWING|HTOP_SAVE_SETTINGS|HTOP_REFRESH;
}


/* actionToggleMergedCommand @ 0x113ba0 */

Htop_Reaction actionToggleMergedCommand(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Settings__2 *pSVar3;

  pSVar3 = st->host->settings;
  p_Var1 = &pSVar3->showMergedCommand;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  return 0x4d;
}


/* actionToggleTreeView @ 0x113bc0 */

Htop_Reaction actionToggleTreeView(State_2 *st)

{
  _Bool *p_Var1;
  Object **ppOVar2;
  int wVar3;
  Table *pTVar4;
  ScreenSettings_2 *pSVar5;
  Object *pOVar6;
  Object **ppOVar7;

  pTVar4 = st->host->activeTable;
  pSVar5 = st->host->settings->ss;
  p_Var1 = &pSVar5->treeView;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  if (pSVar5->allBranchesCollapsed == false) {
                    /* Unresolved local var: int size@[???] */
    wVar3 = pTVar4->rows->items;
                    /* Unresolved local var: int i@[???] */
    if (0 < wVar3) {
      ppOVar7 = pTVar4->rows->array;
      ppOVar2 = ppOVar7 + wVar3;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pOVar6 = *ppOVar7;
        ppOVar7 = ppOVar7 + 1;
        *(undefined1 *)&pOVar6[4].klass = 1;
      } while (ppOVar7 != ppOVar2);
      pTVar4->needsSort = true;
      return 0x6d;
    }
  }
  pTVar4->needsSort = true;
  return 0x6d;
}


/* actionToggleHideMeters @ 0x113c30 */

Htop_Reaction actionToggleHideMeters(State_2 *st)

{
  st->hideMeters = (_Bool)(st->hideMeters ^ 1);
  return 0xe9;
}


/* actionInvertSortOrder @ 0x113c40 */

Htop_Reaction actionInvertSortOrder(State_2 *st)

{
  Machine *pMVar1;
  ScreenSettings_2 *pSVar2;
  int wVar3;
  int *pwVar4;

  pMVar1 = st->host;
  pSVar2 = pMVar1->settings->ss;
                    /* Unresolved local var: int * attr@[???] */
  if (pSVar2->treeView == false) {
    pwVar4 = &pSVar2->direction;
    wVar3 = pSVar2->direction;
  }
  else {
    pwVar4 = &pSVar2->treeDirection;
    wVar3 = pSVar2->treeDirection;
  }
  *pwVar4 = ((wVar3 != 1) - 1) + (uint)(wVar3 != 1);
  pMVar1->activeTable->needsSort = true;
  return 0x4d;
}


/* actionExpandOrCollapse @ 0x113c90 */

Htop_Reaction actionExpandOrCollapse(State_2 *st)

{
  Vector *pVVar1;
  Object *pOVar2;

  if (st->host->settings->ss->treeView != false) {
                    /* Unresolved local var: Row * row@[???] */
    pVVar1 = (st->mainPanel->super).items;
    if ((0 < pVVar1->items) &&
       (pOVar2 = pVVar1->array[(st->mainPanel->super).selected], pOVar2 != (Object *)0x0)) {
      pOVar2 = pOVar2 + 4;
      *(byte *)&pOVar2->klass = *(byte *)&pOVar2->klass ^ 1;
      return HTOP_RECALCULATE;
    }
  }
  return HTOP_OK;
}


/* actionCollapseIntoParent @ 0x113ce0 */

Htop_Reaction actionCollapseIntoParent(State_2 *st)

{
  int wVar1;
  MainPanel__2 *a0;
  Vector *pVVar2;
  Object **ppOVar3;
  Object *pOVar4;
  code *pcVar5;
  long lVar6;
  int iVar7;
  long in_R9;

  if (st->host->settings->ss->treeView != false) {
    a0 = st->mainPanel;
                    /* Unresolved local var: Row * r@[???]
                       Unresolved local var: int parent_id@[???] */
    pVVar2 = (a0->super).items;
    wVar1 = pVVar2->items;
    if (0 < wVar1) {
      ppOVar3 = pVVar2->array;
      pOVar4 = ppOVar3[(a0->super).selected];
      if (pOVar4 != (Object *)0x0) {
        iVar7 = *(int *)((long)&pOVar4[2].klass + 4);
        if (iVar7 == *(int *)&pOVar4[2].klass) {
          iVar7 = *(int *)&pOVar4[3].klass;
        }
                    /* Unresolved local var: int i@[???] */
        lVar6 = 0;
                    /* Unresolved local var: Row * row@[???] */
        while (pOVar4 = ppOVar3[lVar6], *(int *)&pOVar4[2].klass != iVar7) {
          lVar6 = lVar6 + 1;
          if (lVar6 == wVar1) {
            return HTOP_OK;
          }
        }
        *(undefined1 *)&pOVar4[4].klass = 0;
                    /* Unresolved local var: int size@[???] */
        (a0->super).selected = (int)lVar6;
        pcVar5 = (a0->super).super.klass[1].extends;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)((long)a0,0xffffffff,(long)pOVar4,(long)wVar1,(long)a0,in_R9);
          return HTOP_RECALCULATE;
        }
        return HTOP_RECALCULATE;
      }
    }
  }
  return HTOP_OK;
}


/* actionNextScreen @ 0x113d90 */

Htop_Reaction actionNextScreen(State_2 *st)

{
  Machine *pMVar1;
  Settings__2 *pSVar2;
  ScreenSettings_2 *pSVar3;
  Table_ *pTVar4;
  _Bool _Var5;
  MainPanel__2 *pMVar6;
  uint uVar7;
  FunctionBar *pFVar8;
  long lVar9;

  pMVar1 = st->host;
  pSVar2 = pMVar1->settings;
  uVar7 = pSVar2->ssIndex + 1;
                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: _Bool readonly@[???] */
  lVar9 = (ulong)uVar7 << 3;
  if (uVar7 == pSVar2->nScreens) {
    lVar9 = 0;
    uVar7 = 0;
  }
  pSVar2->ssIndex = uVar7;
  _Var5 = readonly;
  pSVar3 = *(ScreenSettings_2 **)((long)pSVar2->screens + lVar9);
  pSVar2->ss = pSVar3;
  pTVar4 = pSVar3->table;
  if (pTVar4 == (Table_ *)0x0) {
    pTVar4 = pMVar1->processTable;
    pSVar3->table = pTVar4;
    pMVar1->activeTable = pTVar4;
    if (_Var5 == false) {
      pMVar6 = st->mainPanel;
      pFVar8 = pMVar6->processBar;
      goto LAB_00113de5;
    }
  }
  else {
    pMVar1->activeTable = pTVar4;
    if ((_Var5 == false) && (pTVar4 == pMVar1->processTable)) {
      pMVar6 = st->mainPanel;
      pFVar8 = pMVar6->processBar;
      goto LAB_00113de5;
    }
  }
  pMVar6 = st->mainPanel;
  pFVar8 = pMVar6->readonlyBar;
LAB_00113de5:
  (pMVar6->super).defaultBar = pFVar8;
  pMVar6->inc->defaultBar = pFVar8;
  return 0x61;
}


/* actionPrevScreen @ 0x113e50 */

Htop_Reaction actionPrevScreen(State_2 *st)

{
  uint uVar1;
  Machine *pMVar2;
  Settings__2 *pSVar3;
  ScreenSettings_2 *pSVar4;
  Table_ *pTVar5;
  _Bool _Var6;
  MainPanel__2 *pMVar7;
  FunctionBar *pFVar8;

  pMVar2 = st->host;
  pSVar3 = pMVar2->settings;
  uVar1 = pSVar3->ssIndex;
  if (uVar1 == 0) {
    uVar1 = pSVar3->nScreens;
  }
                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: _Bool readonly@[???] */
  pSVar3->ssIndex = uVar1 - 1;
  _Var6 = readonly;
  pSVar4 = pSVar3->screens[uVar1 - 1];
  pSVar3->ss = pSVar4;
  pTVar5 = pSVar4->table;
  if (pTVar5 == (Table_ *)0x0) {
    pTVar5 = pMVar2->processTable;
    pSVar4->table = pTVar5;
    pMVar2->activeTable = pTVar5;
    if (_Var6 == false) {
      pMVar7 = st->mainPanel;
      pFVar8 = pMVar7->processBar;
      goto LAB_00113ea0;
    }
  }
  else {
    pMVar2->activeTable = pTVar5;
    if ((_Var6 == false) && (pTVar5 == pMVar2->processTable)) {
      pMVar7 = st->mainPanel;
      pFVar8 = pMVar7->processBar;
      goto LAB_00113ea0;
    }
  }
  pMVar7 = st->mainPanel;
  pFVar8 = pMVar7->readonlyBar;
LAB_00113ea0:
  (pMVar7->super).defaultBar = pFVar8;
  pMVar7->inc->defaultBar = pFVar8;
  return 0x61;
}


/* actionQuit @ 0x113f10 */

Htop_Reaction actionQuit(State_2 *st)

{
  return HTOP_QUIT;
}


/* Action_follow @ 0x113f20 */

Htop_Reaction Action_follow(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Vector *pVVar2;
  Object *pOVar3;
  int wVar4;

  pMVar1 = st->mainPanel;
                    /* Unresolved local var: Row * row@[???] */
  pVVar2 = (pMVar1->super).items;
  wVar4 = -1;
  if ((0 < pVVar2->items) &&
     (pOVar3 = pVVar2->array[(pMVar1->super).selected], pOVar3 != (Object *)0x0)) {
    wVar4 = *(int *)&pOVar3[2].klass;
  }
  st->host->activeTable->following = wVar4;
  (pMVar1->super).selectionColorId = PANEL_SELECTION_FOLLOW;
  return HTOP_KEEP_FOLLOWING;
}


/* actionTag @ 0x113f70 */

Htop_Reaction actionTag(State_2 *st)

{
  byte *pbVar1;
  int wVar2;
  MainPanel__2 *pMVar3;
  Vector *pVVar4;
  Object *pOVar5;
  int wVar6;

  pMVar3 = st->mainPanel;
  pVVar4 = (pMVar3->super).items;
  wVar2 = pVVar4->items;
  if (0 < wVar2) {
    wVar6 = (pMVar3->super).selected;
    pOVar5 = pVVar4->array[wVar6];
    if (pOVar5 != (Object *)0x0) {
      pbVar1 = (byte *)((long)&pOVar5[3].klass + 5);
      *pbVar1 = *pbVar1 ^ 1;
                    /* Unresolved local var: int size@[???] */
      wVar6 = wVar6 + 1;
      if (wVar6 < 0) {
        (pMVar3->super).selected = 0;
        (pMVar3->super).needsRedraw = true;
        return HTOP_OK;
      }
      if (wVar6 < wVar2) {
        (pMVar3->super).selected = wVar6;
        return HTOP_OK;
      }
      (pMVar3->super).needsRedraw = true;
      (pMVar3->super).selected = wVar2 + -1;
    }
  }
  return HTOP_OK;
}


/* actionTogglePauseUpdate @ 0x113fd0 */

Htop_Reaction actionTogglePauseUpdate(State_2 *st)

{
  st->pauseUpdate = (_Bool)(st->pauseUpdate ^ 1);
  return HTOP_REDRAW_BAR|HTOP_REFRESH;
}


/* actionUntagAll @ 0x113fe0 */

Htop_Reaction actionUntagAll(State_2 *st)

{
  Object **ppOVar1;
  int wVar2;
  Vector *pVVar3;
  Object *pOVar4;
  Object **ppOVar5;

                    /* Unresolved local var: int i@[???] */
  pVVar3 = (st->mainPanel->super).items;
  wVar2 = pVVar3->items;
  if (0 < wVar2) {
    ppOVar5 = pVVar3->array;
    ppOVar1 = ppOVar5 + wVar2;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar4 = *ppOVar5;
      ppOVar5 = ppOVar5 + 1;
      *(undefined1 *)((long)&pOVar4[3].klass + 5) = 0;
    } while (ppOVar5 != ppOVar1);
  }
  return HTOP_REFRESH;
}


/* actionTagAllChildren @ 0x114020 */

Htop_Reaction actionTagAllChildren(State_2 *st)

{
  MainPanel__2 *panel;
  Vector *pVVar1;
  Row *parent;

  panel = st->mainPanel;
  pVVar1 = (panel->super).items;
  if ((0 < pVVar1->items) &&
     (parent = (Row *)pVVar1->array[(panel->super).selected], parent != (Row *)0x0)) {
    tagAllChildren(&panel->super,parent);
    return HTOP_OK;
  }
  return HTOP_OK;
}


/* actionHigherPriority @ 0x114650 */

Htop_Reaction actionHigherPriority(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Process *pPVar2;
  _Bool _Var3;
  _Bool _Var4;
  Vector *pVVar5;
  Htop_Reaction HVar6;
  long lVar7;
  byte bVar8;
  byte bVar9;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  HVar6 = HTOP_OK;
  if ((!readonly) && (HVar6 = HTOP_OK, st->host->settings->ss->dynamic == (char *)0x0)) {
    pMVar1 = st->mainPanel;
                    /* Unresolved local var: _Bool changed@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: int i@[???] */
    pVVar5 = (pMVar1->super).items;
    if (0 < pVVar5->items) {
      lVar7 = 0;
      bVar8 = 1;
      bVar9 = readonly;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pPVar2 = (Process *)pVVar5->array[lVar7];
        _Var4 = (pPVar2->super).tag;
        if (_Var4 != false) {
                    /* Unresolved local var: Process * this@[???]
                       Unresolved local var: int old_prio@[???]
                       Unresolved local var: int err@[???] */
          _Var3 = Process_setPriority(pPVar2,(int)pPVar2->nice + -1);
          bVar8 = bVar8 & _Var3;
          pVVar5 = (pMVar1->super).items;
          bVar9 = _Var4;
        }
        lVar7 = lVar7 + 1;
      } while ((int)lVar7 < pVVar5->items);
                    /* Unresolved local var: Row * row@[???] */
      if (((bVar9 != 1) && (0 < pVVar5->items)) &&
         (pPVar2 = (Process *)pVVar5->array[(pMVar1->super).selected], pPVar2 != (Process *)0x0)) {
                    /* Unresolved local var: Process * this@[???]
                       Unresolved local var: int old_prio@[???]
                       Unresolved local var: int err@[???] */
        _Var4 = Process_setPriority(pPVar2,(int)pPVar2->nice + -1);
        bVar8 = bVar8 & _Var4;
      }
      if (bVar8 == 0) {
        beep();
      }
      HVar6 = (Htop_Reaction)bVar9;
    }
  }
  return HVar6;
}


/* actionLowerPriority @ 0x114740 */

Htop_Reaction actionLowerPriority(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Process *pPVar2;
  _Bool _Var3;
  _Bool _Var4;
  Vector *pVVar5;
  Htop_Reaction HVar6;
  long lVar7;
  byte bVar8;
  byte bVar9;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  HVar6 = HTOP_OK;
  if ((!readonly) && (HVar6 = HTOP_OK, st->host->settings->ss->dynamic == (char *)0x0)) {
    pMVar1 = st->mainPanel;
                    /* Unresolved local var: _Bool changed@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: int i@[???] */
    pVVar5 = (pMVar1->super).items;
    if (0 < pVVar5->items) {
      lVar7 = 0;
      bVar8 = 1;
      bVar9 = readonly;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pPVar2 = (Process *)pVVar5->array[lVar7];
        _Var4 = (pPVar2->super).tag;
        if (_Var4 != false) {
                    /* Unresolved local var: Process * this@[???]
                       Unresolved local var: int old_prio@[???]
                       Unresolved local var: int err@[???] */
          _Var3 = Process_setPriority(pPVar2,(int)pPVar2->nice + 1);
          bVar8 = bVar8 & _Var3;
          pVVar5 = (pMVar1->super).items;
          bVar9 = _Var4;
        }
        lVar7 = lVar7 + 1;
      } while ((int)lVar7 < pVVar5->items);
                    /* Unresolved local var: Row * row@[???] */
      if (((bVar9 != 1) && (0 < pVVar5->items)) &&
         (pPVar2 = (Process *)pVVar5->array[(pMVar1->super).selected], pPVar2 != (Process *)0x0)) {
                    /* Unresolved local var: Process * this@[???]
                       Unresolved local var: int old_prio@[???]
                       Unresolved local var: int err@[???] */
        _Var4 = Process_setPriority(pPVar2,(int)pPVar2->nice + 1);
        bVar8 = bVar8 & _Var4;
      }
      if (bVar8 == 0) {
        beep();
      }
      HVar6 = (Htop_Reaction)bVar9;
    }
  }
  return HVar6;
}


/* actionRedraw @ 0x114830 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionRedraw(State_2 *st)

{
  wclear(_stdscr);
  return HTOP_REDRAW_BAR|HTOP_RECALCULATE;
}


/* actionHelp @ 0x114850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionHelp(State_2 *st)

{
  _Bool _Var1;
  int *pwVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int wVar7;
  char *pcVar8;
  int iVar9;
  _Bool *p_Var10;

  iVar9 = 0;
  wclear(_stdscr);
  wattrset(_stdscr,CRT_colors[0x47]);
                    /* Unresolved local var: int i@[???] */
  if (1 < _LINES) {
    do {
      iVar3 = wmove(_stdscr,iVar9,0);
      if (iVar3 != -1) {
        whline(_stdscr,0x20,_COLS);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < _LINES + -1);
  }
  iVar9 = wmove(_stdscr,0,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_htop_3_3_0____C__2004_2019_Hisha_0014a288 /* "htop 3.3.0 - (C) 2004-2019 Hisham Muhammad. (C) 2020-2024 htop dev team." */),-1);
  }
  iVar9 = wmove(_stdscr,1,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x32d8) /* "Released under the GNU GPLv2+. See \'man\' page for more info." */),-1);
  }
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,3,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_CPU_usage_bar__0014702c /* "CPU usage bar: " */),-1);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014703c /* "[" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149c0c /* "" */),-1);
  wattrset(_stdscr,CRT_colors[0x4b]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x217) /* "low" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x4c]);
  waddnstr(_stdscr,((char *)(long)&s_normal_0014703e /* "normal" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x4d]);
  waddnstr(_stdscr,((char *)(long)&s_kernel_00147045 /* "kernel" */),-1);
  if (st->host->settings->detailedCPUTime == false) {
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x52]);
    waddnstr(_stdscr,((char *)(long)&s_guest_0014705b /* "guest" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    pcVar8 = ((char *)(long)&DAT_001470cc /* "                  " */);
  }
  else {
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x4f]);
    waddnstr(_stdscr,((char *)(long)&DAT_00147051 /* "irq" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x50]);
    waddnstr(_stdscr,((char *)(long)&DAT_0014704c /* "soft-irq" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x51]);
    waddnstr(_stdscr,((char *)(long)&s_steal_00147055 /* "steal" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x52]);
    waddnstr(_stdscr,((char *)(long)&s_guest_0014705b /* "guest" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x4e]);
    waddnstr(_stdscr,((char *)(long)&s_io_wait_00147061 /* "io-wait" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    pcVar8 = ((char *)(long)&DAT_001470dd /* " " */);
  }
  waddnstr(_stdscr,pcVar8,-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)(long)&s_used__00147069 /* "used%" */),-1);
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149a61 /* "]" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,4,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Memory_bar__0014706f /* "Memory bar:    " */),-1);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014703c /* "[" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149c0c /* "" */),-1);
  wattrset(_stdscr,CRT_colors[0x33]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x37]);
  waddnstr(_stdscr,((char *)(long)&s_shared_00147084 /* "shared" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x38]);
  waddnstr(_stdscr,((char *)(long)&s_compressed_0014708b /* "compressed" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x35]);
  waddnstr(_stdscr,((char *)(long)&s_buffers_00147096 /* "buffers" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x36]);
  waddnstr(_stdscr,((char *)(long)&s_cache_0014709e /* "cache" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&DAT_001470d4 /* "          " */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)(long)&s_total_001470a4 /* "total" */),-1);
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149a61 /* "]" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,5,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Swap_bar__001470aa /* "Swap bar:      " */),-1);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014703c /* "[" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149c0c /* "" */),-1);
  wattrset(_stdscr,CRT_colors[0x1a]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x1b]);
  waddnstr(_stdscr,((char *)(long)&s_cache_0014709e /* "cache" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x1c]);
  waddnstr(_stdscr,((char *)(long)&s_frontswap_001470ba /* "frontswap" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&DAT_001470c4 /* "                          " */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x17c2) /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)(long)&s_total_001470a4 /* "total" */),-1);
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149a61 /* "]" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,7,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Type_and_layout_of_header_meters_0014a318 /* "Type and layout of header meters are configurable in the setup screen." */),-1);
  }
  if ((CRT_colorScheme == COLORSCHEME_MONOCHROME) && (iVar9 = wmove(_stdscr,8,0), iVar9 != -1)) {
    waddnstr(_stdscr,((char *)(long)&s_In_monochrome__meters_display_as_0014a360 /* "In monochrome, meters display as different chars, in order: |#*@$%&." */),-1);
  }
  iVar9 = wmove(_stdscr,9,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)(long)&s_Process_state__001470df /* "Process state: " */),-1);
  }
  p_Var10 = &helpLeft_0__roInactive;
  iVar9 = 0;
  pcVar8 = ((char *)(long)&s____00147018 /* "      #: " */);
  wattrset(_stdscr,CRT_colors[0x23]);
  waddnstr(_stdscr,((char *)(long)&DAT_001471ab /* "R" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&s___running__001470ef /* ": running; " */),-1);
  wattrset(_stdscr,CRT_colors[0x1e]);
  waddnstr(_stdscr,((char *)(long)&DAT_0014716d /* "S" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&s___sleeping__001470fb /* ": sleeping; " */),-1);
  wattrset(_stdscr,CRT_colors[0x23]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x2e7a) /* "t" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&s___traced_stopped__00147108 /* ": traced/stopped; " */),-1);
  wattrset(_stdscr,CRT_colors[0x24]);
  waddnstr(_stdscr,((char *)(long)&DAT_00149691 /* "Z" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&s___zombie__0014711b /* ": zombie; " */),-1);
  wattrset(_stdscr,CRT_colors[0x24]);
  waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x1783) /* "D" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)(long)&s___disk_sleep_00147126 /* ": disk sleep" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  _Var1 = readonly;
  do {
    iVar3 = iVar9 + 0xb;
    bVar6 = _Var1 & *p_Var10;
    if (bVar6 == 0) {
      wattrset(_stdscr,CRT_colors[1]);
      iVar4 = wmove(_stdscr,iVar3,10);
      if (iVar4 != -1) {
        waddnstr(_stdscr,*(char **)(p_Var10 + 8),-1);
      }
      wVar7 = CRT_colors[0x47];
    }
    else {
      wattrset(_stdscr,CRT_colors[0x48]);
      iVar4 = wmove(_stdscr,iVar3,10);
      if (iVar4 != -1) {
        waddnstr(_stdscr,*(char **)(p_Var10 + 8),-1);
      }
      wVar7 = CRT_colors[0x48];
    }
    wattrset(_stdscr,wVar7);
    iVar4 = wmove(_stdscr,iVar3,1);
    if (iVar4 != -1) {
      waddnstr(_stdscr,pcVar8,-1);
    }
    iVar4 = strcmp(pcVar8,((char *)(long)&s_H__00147133 /* "      H: " */));
    pwVar2 = CRT_colors;
    if (iVar4 == 0) {
      if (bVar6 == 0) {
        wVar7 = CRT_colors[0x2a];
      }
      else {
        wVar7 = CRT_colors[0x48];
      }
      wattrset(_stdscr,wVar7);
      iVar3 = wmove(_stdscr,iVar3,0x21);
joined_r0x001152ab:
      if (iVar3 != -1) {
        waddnstr(_stdscr,((char *)(long)(__sec_rodata + 0x2b7) /* "threads" */),-1);
      }
    }
    else {
      iVar4 = strcmp(pcVar8,((char *)(long)&s_K__0014713d /* "      K: " */));
      if (iVar4 == 0) {
        if (bVar6 == 0) {
          wVar7 = pwVar2[0x2a];
        }
        else {
          wVar7 = pwVar2[0x48];
        }
        wattrset(_stdscr,wVar7);
        iVar3 = wmove(_stdscr,iVar3,0x1b);
        goto joined_r0x001152ab;
      }
    }
    pcVar8 = *(char **)(p_Var10 + 0x10);
    p_Var10 = p_Var10 + 0x18;
    iVar9 = iVar9 + 1;
    if (pcVar8 == (char *)0x0) {
      p_Var10 = &helpRight_0__roInactive;
      pcVar8 = ((char *)(long)&s_S_Tab__00147022 /* "  S-Tab: " */);
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 0xb;
        if ((*p_Var10 == false) || (_Var1 == false)) {
          wattrset(_stdscr,CRT_colors[0x47]);
          iVar5 = wmove(_stdscr,iVar4,0x2b);
          if (iVar5 != -1) {
            waddnstr(_stdscr,pcVar8,-1);
          }
          wVar7 = CRT_colors[1];
        }
        else {
          wattrset(_stdscr,CRT_colors[0x48]);
          iVar5 = wmove(_stdscr,iVar4,0x2b);
          if (iVar5 != -1) {
            waddnstr(_stdscr,pcVar8,-1);
          }
          wVar7 = CRT_colors[0x48];
        }
        wattrset(_stdscr,wVar7);
        iVar4 = wmove(_stdscr,iVar4,0x34);
        if (iVar4 != -1) {
          waddnstr(_stdscr,*(char **)(p_Var10 + 8),-1);
        }
        pcVar8 = *(char **)(p_Var10 + 0x10);
        p_Var10 = p_Var10 + 0x18;
        iVar3 = iVar3 + 1;
      } while (pcVar8 != (char *)0x0);
      wattrset(_stdscr,CRT_colors[0x47]);
      if (iVar9 <= iVar3) {
        iVar9 = iVar3;
      }
      iVar9 = wmove(_stdscr,iVar9 + 0xc,0);
      if (iVar9 != -1) {
        waddnstr(_stdscr,((char *)(long)&s_Press_any_key_to_return__00147147 /* "Press any key to return." */),-1);
      }
      wattrset(_stdscr,CRT_colors[1]);
      wrefresh(_stdscr);
                    /* Unresolved local var: int ret@[???] */
      nocbreak();
      cbreak();
      nodelay(_stdscr,0);
      wgetch(_stdscr);
      halfdelay(*CRT_delay);
      wclear(_stdscr);
      return HTOP_REDRAW_BAR|HTOP_KEEP_FOLLOWING|HTOP_RECALCULATE;
    }
  } while( true );
}


/* Action_setUserOnly @ 0x115900 */

_Bool Action_setUserOnly(char *userName,uid_t *userId)

{
  passwd *ppVar1;

  ppVar1 = getpwnam(userName);
  if (ppVar1 != (passwd *)0x0) {
    *userId = ppVar1->pw_uid;
    return true;
  }
  *userId = 0xffffffff;
  return false;
}


/* Action_setSortKey @ 0x115940 */

Htop_Reaction Action_setSortKey(Settings_2 *settings,ProcessField sortKey)

{
  _Bool _Var1;
  ScreenSettings_2 *pSVar2;

  pSVar2 = settings->ss;
  _Var1 = Process_fields[sortKey].defaultSortDesc;
  if ((pSVar2->treeViewAlwaysByPID == false) && (pSVar2->treeView != false)) {
    pSVar2->treeSortKey = sortKey;
    pSVar2->treeDirection = (-(uint)(_Var1 == false) & 2) + -1;
    return 0x4d;
  }
  pSVar2->sortKey = sortKey;
  pSVar2->treeView = false;
  pSVar2->direction = (-(uint)(_Var1 == false) & 2) + -1;
  return 0x4d;
}


/* Action_setScreenTab @ 0x115a20 */

Htop_Reaction Action_setScreenTab(State_2 *st,int x)

{
  uint uVar1;
  Machine *pMVar2;
  Settings__2 *pSVar3;
  ScreenSettings_2 *pSVar4;
  Table_ *pTVar5;
  _Bool _Var6;
  size_t sVar7;
  MainPanel__2 *pMVar8;
  FunctionBar *pFVar9;
  ScreenSettings_2 **ppSVar10;
  int wVar11;
  uint uVar12;

  pMVar2 = st->host;
  pSVar3 = pMVar2->settings;
                    /* Unresolved local var: uint i@[???] */
  uVar1 = pSVar3->nScreens;
                    /* Unresolved local var: char * tab@[???]
                       Unresolved local var: int len@[???] */
  if ((uVar1 != 0) && (1 < x)) {
    ppSVar10 = pSVar3->screens;
    uVar12 = 0;
    wVar11 = 2;
    do {
      pSVar4 = *ppSVar10;
      sVar7 = strlen(pSVar4->heading);
      _Var6 = readonly;
      if (x <= wVar11 + 1 + (int)sVar7) {
                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: _Bool readonly@[???] */
        pSVar3->ssIndex = uVar12;
        pSVar3->ss = pSVar4;
        pTVar5 = pSVar4->table;
        if (pTVar5 == (Table_ *)0x0) {
          pTVar5 = pMVar2->processTable;
          pSVar4->table = pTVar5;
          pMVar2->activeTable = pTVar5;
          if (_Var6 == false) goto LAB_00115b46;
        }
        else {
          pMVar2->activeTable = pTVar5;
          if ((_Var6 == false) && (pTVar5 == pMVar2->processTable)) {
LAB_00115b46:
            pMVar8 = st->mainPanel;
            pFVar9 = pMVar8->processBar;
            goto LAB_00115aeb;
          }
        }
        pMVar8 = st->mainPanel;
        pFVar9 = pMVar8->readonlyBar;
LAB_00115aeb:
        (pMVar8->super).defaultBar = pFVar9;
        pMVar8->inc->defaultBar = pFVar9;
        return 0x61;
      }
      wVar11 = wVar11 + 3 + (int)sVar7;
      uVar12 = uVar12 + 1;
      ppSVar10 = ppSVar10 + 1;
    } while ((uVar12 < uVar1) && (wVar11 <= x));
  }
  return HTOP_OK;
}


/* Action_setBindings @ 0x115c90 */

void Action_setBindings(Htop_Action_2 *keys)

{
  keys[0x46] = Action_follow;
  keys[0x68] = actionHelp;
  keys[0x2a] = actionExpandOrCollapseAllBranches;
  keys[0x2b] = actionExpandOrCollapse;
  keys[0x43] = actionSetup;
  keys[0x2e] = actionSetSortColumn;
  keys[0x2f] = actionIncSearch;
  keys[0x20] = actionTag;
  keys[0x3e] = actionSetSortColumn;
  keys[0x3f] = actionHelp;
  keys[0x109] = actionHelp;
  keys[0x10a] = actionSetup;
  keys[0x2c] = actionSetSortColumn;
  keys[0x2d] = actionExpandOrCollapse;
  keys[0x48] = actionToggleUserlandThreads;
  keys[0x49] = actionInvertSortOrder;
  keys[0x23] = actionToggleHideMeters;
  keys[0x4d] = actionSortByMemory;
  keys[0x4e] = actionSortByPID;
  keys[0x4b] = actionToggleKernelThreads;
  keys[0x4f] = actionToggleRunningInContainer;
  keys[0x50] = actionSortByCPU;
  keys[0xc] = actionRedraw;
  keys[0x55] = actionUntagAll;
  keys[0x53] = actionSetup;
  keys[0x54] = actionSortByTime;
  keys[0x61] = actionSetAffinity;
  keys[0x59] = actionSetSchedPolicy;
  keys[0x5a] = actionTogglePauseUpdate;
  keys[0x7f] = actionCollapseIntoParent;
  keys[0x5b] = actionLowerPriority;
  keys[0x5c] = actionIncFilter;
  keys[99] = actionTagAllChildren;
  keys[0x6b] = actionKill;
  keys[0x6c] = actionLsof;
  keys[0x65] = actionShowEnvScreen;
  keys[0x6d] = actionToggleMergedCommand;
  keys[0x70] = actionToggleProgramPath;
  keys[0x71] = actionQuit;
  keys[0x75] = actionFilterByUser;
  keys[0x73] = actionStrace;
  keys[0x74] = actionToggleTreeView;
  keys[0x5d] = actionHigherPriority;
  keys[0x3c] = actionSetSortColumn;
  keys[0x3d] = actionExpandOrCollapse;
  keys[0x77] = actionShowCommandScreen;
  keys[0x78] = actionShowLocks;
  keys[0x10b] = actionIncSearch;
  keys[0x10c] = actionIncFilter;
  keys[0x11a] = actionExpandCollapseOrSortColumn;
  keys[0x10d] = actionToggleTreeView;
  keys[0x10e] = actionSetSortColumn;
  keys[9] = actionNextScreen;
  keys[0x10f] = actionHigherPriority;
  keys[0x110] = actionLowerPriority;
  keys[0x111] = actionKill;
  keys[0x112] = actionQuit;
  keys[0x128] = actionExpandOrCollapse;
  keys[0x129] = actionPrevScreen;
  return;
}


/* Action_pickFromVector @ 0x1178f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Object * Action_pickFromVector(State_2 *st,MainPanel_ *list,int x,_Bool follow)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  Machine *host;
  MainPanel__2 *item;
  Vector *pVVar1;
  ScreenManager *this;
  Object *pOVar2;
  int wVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  host = st->host;
  item = st->mainPanel;
  wVar3 = (item->super).y;
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this = (ScreenManager *)
         ScreenManager_new((Header_4 *)st->header,(Machine_2 *)host,(State *)st,false);
  this->allowFocusChange = false;
  ScreenManager_insert(this,&list->super,x,this->panels->items);
  ScreenManager_insert(this,&item->super,-1,this->panels->items);
  if (follow) {
                    /* Unresolved local var: Row * row@[???] */
    pVVar1 = (item->super).items;
    (*(int (*))(__fp - 0x60)) = -1;
    if ((0 < pVVar1->items) &&
       (pOVar2 = pVVar1->array[(item->super).selected], pOVar2 != (Object *)0x0)) {
      (*(int (*))(__fp - 0x60)) = *(int *)&pOVar2[2].klass;
    }
    if (((Table_2 *)host->activeTable)->following == -1) {
      ((Table_2 *)host->activeTable)->following = (*(int (*))(__fp - 0x60));
      ScreenManager_run(this,&(*(Panel *(*))(__fp - 0x48)),&(*(int (*))(__fp - 0x4c)),(char *)0x0);
      ((Table_2 *)host->activeTable)->following = -1;
    }
    else {
      ScreenManager_run(this,&(*(Panel *(*))(__fp - 0x48)),&(*(int (*))(__fp - 0x4c)),(char *)0x0);
    }
  }
  else {
    ScreenManager_run(this,&(*(Panel *(*))(__fp - 0x48)),&(*(int (*))(__fp - 0x4c)),(char *)0x0);
    (*(int (*))(__fp - 0x60)) = -1;
  }
  Vector_delete(this->panels);
  free(this);
  (item->super).y = wVar3;
  (item->super).x = 0;
  wVar3 = ~wVar3 + _LINES;
  (item->super).needsRedraw = true;
  (item->super).h = wVar3;
  (item->super).w = _COLS;
  if (((MainPanel_ *)(*(Panel *(*))(__fp - 0x48)) == list) && ((*(int (*))(__fp - 0x4c)) == 13)) {
                    /* Unresolved local var: Row * selected@[???] */
    if ((follow) &&
       (((pVVar1 = (item->super).items, pVVar1->items < 1 ||
         (pOVar2 = pVVar1->array[(item->super).selected], pOVar2 == (Object *)0x0)) ||
        (*(int *)&pOVar2[2].klass != (*(int (*))(__fp - 0x60)))))) {
      beep();
    }
    else {
      pVVar1 = (list->super).items;
      if (0 < pVVar1->items) {
        pOVar2 = pVVar1->array[(list->super).selected];
        goto LAB_00117a1a;
      }
    }
  }
  pOVar2 = (Object *)0x0;
LAB_00117a1a:
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return pOVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* actionSetSortColumn @ 0x1185a0 */

/* WARNING: Removing unreachable block (ram,0x00118661) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011867e */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Htop_Reaction actionSetSortColumn(State_2 *st)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  _Bool _Var1;
  int wVar2;
  int __wc;
  ht_key_t hVar3;
  uint uVar4;
  long lVar5;
  ht_key_t *phVar6;
  Object_Delete p_Var7;
  Vector *this;
  code *pcVar8;
  ObjectClass **ppOVar9;
  Machine *pMVar10;
  Hashtable_2 *pHVar11;
  State_2 *st_00;
  int wVar12;
  int iVar13;
  FunctionBar *fuBar;
  MainPanel_ *list;
  size_t sVar14;
  Hashtable_2 *pHVar15;
  Object *pOVar16;
  undefined8 *puVar17;
  char *pcVar18;
  char *pcVar19;
  HashtableItem *pHVar20;
  uint uVar21;
  MainPanel_ *pMVar22;
  ScreenSettings_2 *extraout_RDX;
  ScreenSettings_2 *pSVar23;
  int *pwVar24;
  MainPanel_ *pMVar25;
  MainPanel_ *pMVar26;
  MainPanel_ *pMVar27;
  Hashtable_2 *a5;
  Htop_Reaction HVar28;
  cchar_t *pcVar29;
  long lVar30;
  long in_FS_OFFSET = (long)__fake_fs;

  pMVar25 = (MainPanel_ *)&(*(undefined8 (*))(__fp - 0x88));
  lVar5 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*) [3])(__fp - 0x58))[2] = (char *)0x0;
  (*(char *(*) [3])(__fp - 0x58))[0] = ((char *)(long)&s_Sort_0014721b /* "Sort   " */);
  (*(char *(*) [3])(__fp - 0x58))[1] = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(State_2 *(*))(__fp - 0x78)) = st;
  fuBar = FunctionBar_new((*(char *(*) [3])(__fp - 0x58)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  list = malloc(0x26e0);
  if (list != (MainPanel_ *)0x0) {
    (list->super).super.klass = &Panel_class.super;
    Panel_init(&list->super,0,0,0,0,&ListItem_class,true,fuBar);
    wVar2 = CRT_colors[7];
                    /* Unresolved local var: int[33847] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)&(*(undefined8 (*))(__fp - 0x88));
    pwVar24 = (*(int (*) [4])(__fp - 0xa8));
    (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)&(*(undefined8 (*))(__fp - 0x88));
    sVar14 = mbstowcs((*(int (*) [4])(__fp - 0xa8)),((char *)(long)&s_Sort_by_0014722b /* "Sort by" */),7);
    wVar12 = (int)sVar14;
    if (0 < wVar12) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(list->super).header,wVar12);
      (*(MainPanel_ *(*))(__fp - 0x68)) = list;
      pcVar29 = (list->super).header.chptr;
      do {
        __wc = *pwVar24;
        iVar13 = iswprint(__wc);
        pcVar29->attr = 0;
        pcVar29->chars[0] = 0;
        pcVar29->chars[1] = 0;
        pcVar29->chars[2] = 0;
        if (iVar13 == 0) {
          __wc = 65533;
        }
        pwVar24 = pwVar24 + 1;
        pcVar29->attr = wVar2 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar29->chars + 2)) = (undefined16)0x0;
        pcVar29->chars[0] = __wc;
        list = (*(MainPanel_ *(*))(__fp - 0x68));
        pcVar29 = pcVar29 + 1;
      } while (pwVar24 != (*(int (*) [4])(__fp - 0xa8)) + (ulong)(uint)(wVar12 + -1) + 1);
    }
    pMVar25 = (*(MainPanel_ *(*))(__fp - 0x60));
    (list->super).needsRedraw = true;
                    /* Unresolved local var: int i@[???] */
    lVar30 = 0;
    pMVar27 = (MainPanel_ *)(*(State_2 *(*))(__fp - 0x78))->host->settings;
    a5 = *(Hashtable_2 **)&(pMVar27->super).cursorX;
    phVar6 = (ht_key_t *)(*(ScreenSettings_2 **)&(pMVar27->super).scrollV)->fields;
    hVar3 = *phVar6;
    pMVar10 = (*(State_2 *(*))(__fp - 0x78))->host;
    pMVar22 = pMVar27;
    pHVar11 = a5;
    st_00 = (*(State_2 *(*))(__fp - 0x78));
    pMVar26 = (*(MainPanel_ *(*))(__fp - 0x60));
    do {
      while( true ) {
        (*(MainPanel_ *(*))(__fp - 0x60)) = pMVar22;
        (*(State_2 *(*))(__fp - 0x78)) = st_00;
        if (hVar3 == 0) {
          lVar30 = 0;
          HVar28 = 0x61;
          pMVar26 = list;
          pOVar16 = Action_pickFromVector(st_00,list,14,false);
          pMVar27 = (*(MainPanel_ *(*))(__fp - 0x60));
          pSVar23 = extraout_RDX;
          if (pOVar16 != (Object *)0x0) {
            iVar13 = *(int *)&pOVar16[2].klass;
            lVar30 = (long)iVar13;
            pSVar23 = *(ScreenSettings_2 **)&((*(MainPanel_ *(*))(__fp - 0x60))->super).scrollV;
            _Var1 = Process_fields[lVar30].defaultSortDesc;
            if ((pSVar23->treeViewAlwaysByPID == false) && (pSVar23->treeView != false)) {
              pSVar23->treeSortKey = iVar13;
              pSVar23->treeDirection = (-(uint)(_Var1 == false) & 2) + -1;
            }
            else {
              pSVar23->sortKey = iVar13;
              pSVar23->treeView = false;
              pSVar23->direction = (-(uint)(_Var1 == false) & 2) + -1;
            }
            HVar28 = 0x6d;
          }
          p_Var7 = ((list->super).super.klass)->delete;
          (*(code *)(p_Var7))((Object *)list,(long)pMVar26,(long)pSVar23,lVar30,(long)pMVar27,(long)a5);
          pMVar10->activeTable->needsSort = true;
          if (lVar5 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return HVar28;
        }
                    /* Unresolved local var: char * name@[???] */
        (*(Machine *(*))(__fp - 0x80)) = pMVar10;
        (*(Hashtable_2 *(*))(__fp - 0x70)) = pHVar11;
        (*(MainPanel_ *(*))(__fp - 0x68)) = (*(MainPanel_ *(*))(__fp - 0x60));
        if ((int)hVar3 < 0x84) break;
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pMVar27 = (MainPanel_ *)pHVar11->size;
        a5 = (Hashtable_2 *)pHVar11->buckets;
        pMVar22 = (MainPanel_ *)((ulong)(long)(int)hVar3 % (ulong)pMVar27);
        pcVar19 = (char *)((Hashtable_2 *)(&a5->size + (long)pMVar22 * 3))->items;
        if (pcVar19 != (char *)0x0) {
          pHVar20 = (HashtableItem *)0x0;
          pHVar15 = (Hashtable_2 *)(&a5->size + (long)pMVar22 * 3);
          do {
            while( true ) {
              if (hVar3 == (ht_key_t)pHVar15->size) {
                pcVar18 = *(char **)(pcVar19 + 0x28);
                if (*(char **)(pcVar19 + 0x28) == (char *)0x0) {
                  pcVar18 = pcVar19;
                }
                    /* Unresolved local var: char * data@[???] */
                (*(MainPanel_ *(*))(__fp - 0x60)) = pMVar26;
                pcVar19 = strdup(pcVar18);
                if (pcVar19 != (char *)0x0) goto LAB_001188a6;
                goto LAB_0011899f;
              }
              if (pHVar15->buckets < pHVar20) goto LAB_001187d0;
              ppOVar9 = &(pMVar22->super).super.klass;
              pMVar22 = (MainPanel_ *)((long)ppOVar9 + 1);
              if (pMVar27 != pMVar22) break;
              pMVar22 = (MainPanel_ *)0x0;
              pHVar20 = (HashtableItem *)((long)&pHVar20->key + 1);
              pcVar19 = (char *)a5->items;
              pHVar15 = a5;
              if (pcVar19 == (char *)0x0) goto LAB_001187d0;
            }
            pHVar20 = (HashtableItem *)((long)&pHVar20->key + 1);
            pHVar15 = (Hashtable_2 *)(&a5->owner + (long)ppOVar9 * 0x18);
            pcVar19 = (char *)pHVar15->items;
          } while (pcVar19 != (char *)0x0);
        }
LAB_001187d0:
        lVar30 = lVar30 + 1;
        hVar3 = phVar6[lVar30];
        pMVar22 = (*(MainPanel_ *(*))(__fp - 0x60));
      }
      pcVar19 = Process_fields[(int)hVar3].name;
      (*(MainPanel_ *(*))(__fp - 0x60)) = pMVar26;
      pcVar19 = String_trim(pcVar19);
LAB_001188a6:
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      hVar3 = phVar6[lVar30];
      puVar17 = malloc(0x18);
      if (puVar17 == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
      *puVar17 = &ListItem_class;
      (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)puVar17;
      pcVar18 = strdup(pcVar19);
      pMVar26 = (*(MainPanel_ *(*))(__fp - 0x60));
      if (pcVar18 == (char *)0x0) break;
      this = (list->super).items;
      *(char **)((long)(*(MainPanel_ *(*))(__fp - 0x60)) + 8) = pcVar18;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
      wVar2 = this->items;
      *(ht_key_t *)((long)(*(MainPanel_ *(*))(__fp - 0x60)) + 0x10) = hVar3;
      *(undefined1 *)((long)(*(MainPanel_ *(*))(__fp - 0x60)) + 0x14) = 0;
      Vector_set(this,wVar2,pMVar26);
      (list->super).needsRedraw = true;
      uVar4 = phVar6[lVar30];
      pSVar23 = *(ScreenSettings_2 **)&((*(MainPanel_ *(*))(__fp - 0x68))->super).scrollV;
      if (pSVar23->treeView == false) {
        uVar21 = pSVar23->sortKey;
      }
      else {
        uVar21 = 1;
        if (pSVar23->treeViewAlwaysByPID == false) {
          uVar21 = pSVar23->treeSortKey;
        }
      }
      if (uVar4 == uVar21) {
                    /* Unresolved local var: int size@[???] */
        wVar2 = ((list->super).items)->items;
        wVar12 = wVar2 + -1;
        if ((int)lVar30 < wVar2) {
          wVar12 = (int)lVar30;
        }
        if (wVar12 < 0) {
          wVar12 = 0;
        }
        (list->super).selected = wVar12;
        pcVar8 = (list->super).super.klass[1].extends;
        if (pcVar8 != (code *)0x0) {
          (*pcVar8)((long)list,0xffffffff,0,(ulong)uVar4,(long)pMVar27,(long)a5);
        }
      }
      lVar30 = lVar30 + 1;
      free(pcVar19);
      hVar3 = phVar6[lVar30];
      pMVar10 = (*(Machine *(*))(__fp - 0x80));
      pMVar22 = (*(MainPanel_ *(*))(__fp - 0x68));
      pHVar11 = (*(Hashtable_2 *(*))(__fp - 0x70));
      st_00 = (*(State_2 *(*))(__fp - 0x78));
      pMVar26 = (*(MainPanel_ *(*))(__fp - 0x60));
    } while( true );
  }
LAB_0011899f:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* actionExpandCollapseOrSortColumn @ 0x1189d0 */

Htop_Reaction actionExpandCollapseOrSortColumn(State_2 *st)

{
  Vector *pVVar1;
  Object *pOVar2;
  Htop_Reaction HVar3;

  if (st->host->settings->ss->treeView == false) {
    HVar3 = actionSetSortColumn(st);
    return HVar3;
  }
                    /* Unresolved local var: _Bool changed@[???] */
                    /* Unresolved local var: Row * row@[???] */
  pVVar1 = (st->mainPanel->super).items;
  if ((0 < pVVar1->items) &&
     (pOVar2 = pVVar1->array[(st->mainPanel->super).selected], pOVar2 != (Object *)0x0)) {
    pOVar2 = pOVar2 + 4;
    *(byte *)&pOVar2->klass = *(byte *)&pOVar2->klass ^ 1;
    return HTOP_RECALCULATE;
  }
  return HTOP_OK;
}


/* actionToggleKernelThreads @ 0x119af0 */

Htop_Reaction actionToggleKernelThreads(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Machine *this;
  Settings__2 *pSVar3;

  this = st->host;
  pSVar3 = this->settings;
  p_Var1 = &pSVar3->hideKernelThreads;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  Machine_scanTables(this);
  return HTOP_KEEP_FOLLOWING|HTOP_SAVE_SETTINGS|HTOP_RECALCULATE;
}


/* actionToggleUserlandThreads @ 0x119b20 */

Htop_Reaction actionToggleUserlandThreads(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Machine *this;
  Settings__2 *pSVar3;

  this = st->host;
  pSVar3 = this->settings;
  p_Var1 = &pSVar3->hideUserlandThreads;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  Machine_scanTables(this);
  return HTOP_KEEP_FOLLOWING|HTOP_SAVE_SETTINGS|HTOP_RECALCULATE;
}


/* actionExpandOrCollapseAllBranches @ 0x119b50 */

Htop_Reaction actionExpandOrCollapseAllBranches(State_2 *st)

{
  Object **ppOVar1;
  int wVar2;
  ScreenSettings_2 *pSVar3;
  Table *this;
  Vector *pVVar4;
  Object *pOVar5;
  Object **ppOVar6;
  _Bool _Var7;

  pSVar3 = st->host->settings->ss;
  if (pSVar3->treeView == false) {
    return HTOP_OK;
  }
  this = st->host->activeTable;
  _Var7 = (_Bool)(pSVar3->allBranchesCollapsed ^ 1);
  pSVar3->allBranchesCollapsed = _Var7;
  if (_Var7 == false) {
                    /* Unresolved local var: int size@[???] */
    pVVar4 = this->rows;
    wVar2 = pVVar4->items;
                    /* Unresolved local var: int i@[???] */
    if (0 < wVar2) {
      ppOVar6 = pVVar4->array;
      ppOVar1 = ppOVar6 + wVar2;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pOVar5 = *ppOVar6;
        ppOVar6 = ppOVar6 + 1;
        *(undefined1 *)&pOVar5[4].klass = 1;
      } while (ppOVar6 != ppOVar1);
    }
    return HTOP_SAVE_SETTINGS|HTOP_REFRESH;
  }
  Table_collapseAllBranches(this);
  return HTOP_SAVE_SETTINGS|HTOP_REFRESH;
}


/* actionIncFilter @ 0x119bd0 */

Htop_Reaction actionIncFilter(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Machine *pMVar2;
  IncSet *this;
  FunctionBar *pFVar3;
  IncMode *pIVar4;

  pMVar1 = st->mainPanel;
  pMVar2 = st->host;
  this = pMVar1->inc;
  pFVar3 = this->modes[1].bar;
  this->active = this->modes + 1;
  (pMVar1->super).currentBar = pFVar3;
  (pMVar1->super).cursorOn = true;
  this->panel = &pMVar1->super;
  IncSet_drawBar(this,CRT_colors[2]);
  pIVar4 = this->modes + 1;
  if (this->filtering == false) {
    pIVar4 = (IncMode *)0x0;
  }
  pMVar2->activeTable->incFilter = pIVar4->buffer;
  return HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
}


/* actionIncSearch @ 0x119c50 */

Htop_Reaction actionIncSearch(State_2 *st)

{
  MainPanel__2 *pMVar1;
  IncSet *this;
  FunctionBar *pFVar2;

  pMVar1 = st->mainPanel;
  this = pMVar1->inc;
  pFVar2 = this->modes[0].bar;
  this->modes[0].buffer[0] = '\0';
  this->modes[0].index = 0;
  this->active = this->modes;
  (pMVar1->super).currentBar = pFVar2;
  (pMVar1->super).cursorOn = true;
  this->panel = &pMVar1->super;
  IncSet_drawBar(this,CRT_colors[2]);
  return HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
}


/* actionSetSchedPolicy @ 0x119cb0 */

Htop_Reaction actionSetSchedPolicy(State_2 *st)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char cVar1;
  int wVar2;
  long lVar3;
  MainPanel__2 *pMVar4;
  bool bVar5;
  Htop_Reaction HVar6;
  int iVar7;
  MainPanel_ *list;
  Object *pOVar8;
  ObjectClass *pOVar9;
  MainPanel_ *list_00;
  Vector *pVVar10;
  byte bVar11;
  long lVar12;
  int __policy;
  int __policy_00;
  char *__s2;
  long lVar13;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  (*(char (*))(__fp - 0x49)) = readonly;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  if (readonly) {
    HVar6 = HTOP_KEEP_FOLLOWING;
  }
  else {
    HVar6 = HTOP_KEEP_FOLLOWING;
    if (st->host->settings->ss->dynamic == (char *)0x0) {
                    /* Unresolved local var: Panel * schedPanel@[???]
                       Unresolved local var: ListItem * policy@[???] */
      list = (MainPanel_ *)Scheduling_newPolicyPanel(preSelectedPolicy);
LAB_00119d48:
      pOVar8 = Action_pickFromVector(st,list,18,true);
      if (pOVar8 != (Object *)0x0) {
        wVar2 = *(int *)&pOVar8[2].klass;
        if (wVar2 == -1) {
                    /* Unresolved local var: ListItem * item@[???] */
          __s2 = ((char *)(long)&s_Reset_on_fork__on_001473a6 /* "Reset on fork: on" */);
          bVar11 = reset_on_fork ^ 1;
          if (reset_on_fork == true) {
            __s2 = ((char *)(long)&s_Reset_on_fork__off_001473b8 /* "Reset on fork: off" */);
          }
          pOVar8 = *((list->super).items)->array;
          pOVar9 = pOVar8[1].klass;
          reset_on_fork = (_Bool)bVar11;
          if (pOVar9 != (ObjectClass *)0x0) goto code_r0x00119da8;
          goto LAB_00119db7;
        }
        preSelectedPolicy = wVar2;
                    /* Unresolved local var: Panel * prioPanel@[???]
                       Unresolved local var: SchedulingArg v@[???]
                       Unresolved local var: _Bool ok@[???] */
        list_00 = (MainPanel_ *)Scheduling_newPriorityPanel(wVar2,preSelectedPriority);
        if (list_00 != (MainPanel_ *)0x0) {
                    /* Unresolved local var: ListItem * prio@[???] */
          pOVar8 = Action_pickFromVector(st,list_00,14,true);
          if (pOVar8 != (Object *)0x0) {
            preSelectedPriority = *(int *)&pOVar8[2].klass;
          }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
          free((list_00->super).eventHandlerState);
          Vector_delete((list_00->super).items);
          FunctionBar_delete((list_00->super).defaultBar);
          if (350 < (list_00->super).header.chlen) {
            free((list_00->super).header.chptr);
          }
          free(list_00);
        }
        __policy_00 = preSelectedPolicy;
        wVar2 = preSelectedPriority;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: int i@[???] */
        lVar13 = 0;
        bVar5 = true;
        pMVar4 = st->mainPanel;
        pVVar10 = (pMVar4->super).items;
        if (0 < pVVar10->items) {
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: Process * p@[???]
                       Unresolved local var: SchedulingArg * sarg@[???]
                       Unresolved local var: int policy@[???]
                       Unresolved local var: int r@[???] */
          lVar12 = (long)preSelectedPolicy;
          do {
            cVar1 = *(char *)((long)&pVVar10->array[lVar13][3].klass + 5);
            if (cVar1 != '\0') {
              (*(sched_param (*))(__fp - 0x44)).sched_priority = 0;
              if (policies[lVar12].prioritySupport != false) {
                (*(sched_param (*))(__fp - 0x44)).sched_priority = wVar2;
              }
              __policy = __policy_00;
              if (reset_on_fork != false) {
                __policy = __policy_00 & 0x40000000;
              }
              iVar7 = sched_setscheduler(*(__pid_t *)&pVVar10->array[lVar13][2].klass,__policy,
                                         (sched_param_2 *)&(*(sched_param (*))(__fp - 0x44)));
              bVar5 = (bool)(bVar5 & iVar7 != -1);
              pVVar10 = (pMVar4->super).items;
              (*(char (*))(__fp - 0x49)) = cVar1;
            }
            lVar13 = lVar13 + 1;
          } while ((int)lVar13 < pVVar10->items);
                    /* Unresolved local var: Row * row@[???] */
          if ((((*(char (*))(__fp - 0x49)) != '\x01') && (0 < pVVar10->items)) &&
             (pVVar10->array[(pMVar4->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
                    /* Unresolved local var: SchedulingArg * sarg@[???]
                       Unresolved local var: int policy@[???]
                       Unresolved local var: int r@[???] */
            (*(sched_param (*))(__fp - 0x44)).sched_priority = 0;
            if (policies[__policy_00].prioritySupport != false) {
              (*(sched_param (*))(__fp - 0x44)).sched_priority = wVar2;
            }
            if (reset_on_fork != false) {
              __policy_00 = __policy_00 & 0x40000000;
            }
            iVar7 = sched_setscheduler(*(__pid_t *)
                                        &pVVar10->array[(pMVar4->super).selected][2].klass,
                                       __policy_00,(sched_param_2 *)&(*(sched_param (*))(__fp - 0x44)));
            bVar5 = (bool)(bVar5 & iVar7 != -1);
          }
          if (!bVar5) {
            beep();
          }
        }
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
      free((list->super).eventHandlerState);
      Vector_delete((list->super).items);
      FunctionBar_delete((list->super).defaultBar);
      if (350 < (list->super).header.chlen) {
        free((list->super).header.chptr);
      }
      free(list);
      HVar6 = HTOP_REDRAW_BAR|HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
    }
  }
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x00119da8:
  iVar7 = strcmp((char *)pOVar9,__s2);
  if (iVar7 != 0) {
LAB_00119db7:
    free(pOVar9);
                    /* Unresolved local var: char * data@[???] */
    pOVar9 = (ObjectClass *)strdup(__s2);
    if (pOVar9 == (ObjectClass *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    pOVar8[1].klass = pOVar9;
  }
  goto LAB_00119d48;
}


/* actionKill @ 0x11a000 */

/* WARNING: Removing unreachable block (ram,0x0011a109) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x0011a126 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Htop_Reaction actionKill(State_2 *st)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  char cVar1;
  int wVar2;
  __pid_t _Var3;
  void *__ptr;
  FunctionBar *this;
  bool bVar4;
  Htop_Reaction HVar5;
  int iVar6;
  MainPanel_ *list;
  Object *pOVar7;
  MainPanel__2 *pMVar8;
  Vector *pVVar9;
  cchar_t *pcVar10;
  undefined1 **ppuVar11;
  _Bool hideFunctionBar;
  long lVar12;
  cchar_t *pcVar13;
  char cVar14;
  long in_FS_OFFSET = (long)__fake_fs;

  cVar14 = readonly;
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  ppuVar11 = &(*(undefined1 *(*))(__fp - 0x78));
  HVar5 = HTOP_OK;
  if ((!readonly) &&
     (ppuVar11 = &(*(undefined1 *(*))(__fp - 0x78)), HVar5 = HTOP_OK, st->host->settings->ss->dynamic == (char *)0x0)) {
                    /* Unresolved local var: Panel * signalsPanel@[???]
                       Unresolved local var: ListItem * sgn@[???] */
    list = (MainPanel_ *)SignalsPanel_new(preSelectedSignal);
    pOVar7 = Action_pickFromVector(st,list,14,true);
    ppuVar11 = &(*(undefined1 *(*))(__fp - 0x78));
    if ((pOVar7 != (Object *)0x0) && (ppuVar11 = &(*(undefined1 *(*))(__fp - 0x78)), *(int *)&pOVar7[2].klass != 0))
    {
                    /* Unresolved local var: _Bool ok@[???] */
      (*(MainPanel__2 *(*))(__fp - 0x70)) = st->mainPanel;
                    /* Unresolved local var: int[52958] data@[???]
                       Unresolved local var: int newLen@[???] */
      (*(undefined1 *(*))(__fp - 0x78)) = (undefined1 *)&(*(undefined1 *(*))(__fp - 0x78));
      wVar2 = CRT_colors[7];
      (*(cchar_t *(*))(__fp - 0x58)) = &(*(cchar_t (*))(__fp - 0xa8));
      preSelectedSignal = *(int *)&pOVar7[2].klass;
      (*(undefined1 *(*))(__fp - 0x78)) = (undefined1 *)&(*(undefined1 *(*))(__fp - 0x78));
      pMVar8 = (MainPanel__2 *)mbstowcs((int *)&(*(cchar_t (*))(__fp - 0xa8)),((char *)(long)&s_Sending____001473cb /* "Sending..." */),10);
      if (0 < (int)pMVar8) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
        (*(MainPanel__2 *(*))(__fp - 0x50)) = pMVar8;
        RichString_setLen(&((*(MainPanel__2 *(*))(__fp - 0x70))->super).header,(int)pMVar8);
        pcVar10 = ((*(MainPanel__2 *(*))(__fp - 0x70))->super).header.chptr;
        (*(int *(*))(__fp - 0x68)) = (*(cchar_t *(*))(__fp - 0x58))->chars + ((int)(*(MainPanel__2 *(*))(__fp - 0x50)) - 1);
        pcVar13 = (*(cchar_t *(*))(__fp - 0x58));
        (*(attr_t (*))(__fp - 0x5c)) = wVar2 & 0xffffff;
        do {
          (*(MainPanel__2 *(*))(__fp - 0x50)) = (MainPanel__2 *)CONCAT44((*(uint *)((char *)&(*(MainPanel__2 *(*))(__fp - 0x50)) + 4)),pcVar13->attr);
          (*(cchar_t *(*))(__fp - 0x58)) = pcVar10;
          iVar6 = iswprint(pcVar13->attr);
          wVar2 = (int)(*(MainPanel__2 *(*))(__fp - 0x50));
          if (iVar6 == 0) {
            wVar2 = 65533;
          }
          (*(cchar_t *(*))(__fp - 0x58))->attr = 0;
          (*(cchar_t *(*))(__fp - 0x58))->chars[0] = 0;
          (*(cchar_t *(*))(__fp - 0x58))->chars[1] = 0;
          (*(cchar_t *(*))(__fp - 0x58))->chars[2] = 0;
          pcVar13 = (cchar_t *)pcVar13->chars;
          *(undefined16 *)(*(undefined1 (*) [16])((*(cchar_t *(*))(__fp - 0x58))->chars + 2)) = (undefined16)0x0;
          pcVar10 = (*(cchar_t *(*))(__fp - 0x58)) + 1;
          (*(cchar_t *(*))(__fp - 0x58))->attr = (*(attr_t (*))(__fp - 0x5c));
          (*(cchar_t *(*))(__fp - 0x58))->chars[0] = wVar2;
        } while ((cchar_t *)(*(int *(*))(__fp - 0x68)) != pcVar13);
      }
      ppuVar11 = (undefined1 **)(*(undefined1 *(*))(__fp - 0x78));
                    /* Unresolved local var: Settings * settings@[???] */
      hideFunctionBar = true;
      ((*(MainPanel__2 *(*))(__fp - 0x70))->super).needsRedraw = true;
      wVar2 = st->host->settings->hideFunctionBar;
      if ((wVar2 != 2) && (hideFunctionBar = false, wVar2 == 1)) {
        hideFunctionBar = st->hideSelection;
      }
      pMVar8 = st->mainPanel;
      Panel_draw(&pMVar8->super,false,true,true,hideFunctionBar);
      wrefresh(_stdscr);
      (*(cchar_t *(*))(__fp - 0x58)) = (cchar_t *)CONCAT44((*(uint *)((char *)&(*(cchar_t *(*))(__fp - 0x58)) + 4)),*(undefined4 *)&pOVar7[2].klass);
      (*(MainPanel__2 *(*))(__fp - 0x50)) = st->mainPanel;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: int i@[???] */
      pVVar9 = ((*(MainPanel__2 *(*))(__fp - 0x50))->super).items;
      if (0 < pVVar9->items) {
        lVar12 = 0;
        bVar4 = true;
        do {
                    /* Unresolved local var: Row * row@[???] */
          cVar1 = *(char *)((long)&pVVar9->array[lVar12][3].klass + 5);
          if (cVar1 != '\0') {
                    /* Unresolved local var: Process * this@[???] */
            _Var3 = *(__pid_t *)&pVVar9->array[lVar12][2].klass;
            iVar6 = (int)(*(cchar_t *(*))(__fp - 0x58));
            iVar6 = kill(_Var3,iVar6);
            bVar4 = (bool)(bVar4 & iVar6 == 0);
            pVVar9 = ((*(MainPanel__2 *(*))(__fp - 0x50))->super).items;
            cVar14 = cVar1;
          }
          lVar12 = lVar12 + 1;
        } while ((int)lVar12 < pVVar9->items);
                    /* Unresolved local var: Row * row@[???] */
        if (((cVar14 != '\x01') && (0 < pVVar9->items)) &&
           (pVVar9->array[((*(MainPanel__2 *(*))(__fp - 0x50))->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * this@[???] */
          _Var3 = *(__pid_t *)&pVVar9->array[((*(MainPanel__2 *(*))(__fp - 0x50))->super).selected][2].klass;
          iVar6 = (int)(*(cchar_t *(*))(__fp - 0x58));
          iVar6 = kill(_Var3,iVar6);
          bVar4 = (bool)(bVar4 & iVar6 == 0);
        }
        if (!bVar4) {
          beep();
        }
      }
      napms(500);
    }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
    __ptr = (list->super).eventHandlerState;
    free(__ptr);
    pVVar9 = (list->super).items;
    Vector_delete(pVVar9);
    this = (list->super).defaultBar;
    FunctionBar_delete(this);
    if (350 < (list->super).header.chlen) {
      pcVar10 = (list->super).header.chptr;
      free(pcVar10);
    }
    free(list);
    HVar5 = 0x61;
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return HVar5;
}


/* actionFilterByUser @ 0x11a490 */

/* WARNING: Removing unreachable block (ram,0x0011a551) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011a56e */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Htop_Reaction actionFilterByUser(State_2 *st)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  int wVar1;
  long lVar2;
  Hashtable_2 *pHVar3;
  Vector *pVVar4;
  long *a0;
  code *pcVar5;
  void *__ptr;
  State_2 *st_00;
  int iVar6;
  FunctionBar *pFVar7;
  MainPanel_ *list;
  size_t sVar8;
  undefined8 *puVar9;
  char *pcVar10;
  Object **ptr;
  long *plVar11;
  Object *data_;
  ObjectClass *pOVar12;
  Object *pOVar13;
  passwd *ppVar14;
  long a3;
  int wVar15;
  long a2;
  int *pwVar16;
  MainPanel_ *pMVar17;
  long a4;
  MainPanel_ *pMVar18;
  int wVar19;
  cchar_t *pcVar20;
  ulong uVar21;
  Machine *pMVar22;
  long in_FS_OFFSET = (long)__fake_fs;

  pMVar17 = (MainPanel_ *)(*(undefined1 (*) [16])(__fp - 0x88));
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*) [3])(__fp - 0x58))[2] = (char *)0x0;
  (*(char *(*) [3])(__fp - 0x58))[0] = ((char *)(long)&s_Show_001473d6 /* "Show   " */);
  (*(char *(*) [3])(__fp - 0x58))[1] = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(State_2 *(*))(__fp - 0x78)) = st;
  pFVar7 = FunctionBar_new((*(char *(*) [3])(__fp - 0x58)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  list = malloc(0x26e0);
  if (list != (MainPanel_ *)0x0) {
    a4 = 0;
    (list->super).super.klass = &Panel_class.super;
    Panel_init(&list->super,0,0,0,0,&ListItem_class,true,pFVar7);
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[54854] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)(*(undefined1 (*) [16])(__fp - 0x88));
    pwVar16 = (*(int (*) [16])(__fp - 0xd8));
    (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)(*(undefined1 (*) [16])(__fp - 0x88));
    sVar8 = mbstowcs((*(int (*) [16])(__fp - 0xd8)),((char *)(long)&s_Show_processes_of__001473de /* "Show processes of:" */),0x12);
    wVar15 = (int)sVar8;
    if (0 < wVar15) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(list->super).header,wVar15);
      (*(MainPanel_ *(*))(__fp - 0x68)) = list;
      pcVar20 = (list->super).header.chptr;
      do {
        wVar19 = *pwVar16;
        iVar6 = iswprint(wVar19);
        pcVar20->attr = 0;
        pcVar20->chars[0] = 0;
        pcVar20->chars[1] = 0;
        pcVar20->chars[2] = 0;
        if (iVar6 == 0) {
          wVar19 = 65533;
        }
        pwVar16 = pwVar16 + 1;
        pcVar20->attr = wVar1 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar20->chars + 2)) = (undefined16)0x0;
        pcVar20->chars[0] = wVar19;
        list = (*(MainPanel_ *(*))(__fp - 0x68));
        pcVar20 = pcVar20 + 1;
      } while ((*(int (*) [16])(__fp - 0xd8)) + (ulong)(uint)(wVar15 + -1) + 1 != pwVar16);
    }
    pMVar17 = (*(MainPanel_ *(*))(__fp - 0x60));
                    /* Unresolved local var: size_t i@[???] */
    uVar21 = 0;
    (list->super).needsRedraw = true;
    pMVar22 = (*(State_2 *(*))(__fp - 0x78))->host;
    pHVar3 = pMVar22->usersTable->users;
    if (pHVar3->size != 0) {
      do {
        (*(ulong *)((char *)&(*(undefined1 (*) [16])(__fp - 0x88)) + 8)) = pMVar22;
        pcVar10 = pHVar3->buckets[uVar21].value;
        if (pcVar10 != (char *)0x0) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
          (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)CONCAT44((*(uint *)((char *)&(*(MainPanel_ *(*))(__fp - 0x60)) + 4)),pHVar3->buckets[uVar21].key);
          pMVar17[-1].idSearch = 0x11a671;
          pMVar17[-1].field_0x270c = 0;
          pMVar17[-1].field_0x270d = 0;
          pMVar17[-1].field_0x270e = 0;
          pMVar17[-1].field_0x270f = 0;
          puVar9 = malloc(0x18);
          if (puVar9 == (undefined8 *)0x0) goto LAB_0011a84b;
                    /* Unresolved local var: char * data@[???] */
          *puVar9 = &ListItem_class;
          pMVar17[-1].idSearch = 0x11a68f;
          pMVar17[-1].field_0x270c = 0;
          pMVar17[-1].field_0x270d = 0;
          pMVar17[-1].field_0x270e = 0;
          pMVar17[-1].field_0x270f = 0;
          pcVar10 = strdup(pcVar10);
          if (pcVar10 == (char *)0x0) goto LAB_0011a84b;
          pVVar4 = (list->super).items;
          puVar9[1] = pcVar10;
          *(undefined1 *)((long)puVar9 + 0x14) = 0;
          wVar1 = pVVar4->items;
          wVar15 = pVVar4->arraySize;
          sVar8 = (size_t)wVar15;
          *(int *)(puVar9 + 2) = (int)(*(MainPanel_ *(*))(__fp - 0x60));
                    /* Unresolved local var: int oldSize@[???] */
          ptr = pVVar4->array;
          wVar19 = wVar1 + 1;
                    /* Unresolved local var: Object * removed@[???] */
          pMVar18 = (MainPanel_ *)((long)wVar1 << 3);
          if (wVar15 < wVar19) {
            wVar15 = wVar19 + pVVar4->growthRate;
            a3 = 8;
            pVVar4->arraySize = wVar15;
            (*(MainPanel_ *(*))(__fp - 0x60)) = (MainPanel_ *)CONCAT44((*(uint *)((char *)&(*(MainPanel_ *(*))(__fp - 0x60)) + 4)),wVar19);
            (*(int (*))(__fp - 0x6c)) = wVar1;
            (*(MainPanel_ *(*))(__fp - 0x68)) = (MainPanel_ *)((long)wVar1 << 3);
            pMVar17[-1].idSearch = 0x11a6f2;
            pMVar17[-1].field_0x270c = 0;
            pMVar17[-1].field_0x270d = 0;
            pMVar17[-1].field_0x270e = 0;
            pMVar17[-1].field_0x270f = 0;
            ptr = xReallocArrayZero(ptr,sVar8,(long)wVar15,8);
            pMVar18 = (*(MainPanel_ *(*))(__fp - 0x68));
            pVVar4->array = ptr;
            wVar19 = (int)(*(MainPanel_ *(*))(__fp - 0x60));
            if (pVVar4->items <= (*(int (*))(__fp - 0x6c))) goto LAB_0011a630;
            plVar11 = (long *)((long)ptr + (long)(*(MainPanel_ *(*))(__fp - 0x68)));
            (*(MainPanel_ *(*))(__fp - 0x60)) = (*(MainPanel_ *(*))(__fp - 0x68));
            if ((pVVar4->owner != false) && (a0 = (long *)*plVar11, a0 != (long *)0x0)) {
              pcVar5 = *(code **)(*a0 + 0x10);
              pMVar17[-1].idSearch = 0x11a72f;
              pMVar17[-1].field_0x270c = 0;
              pMVar17[-1].field_0x270d = 0;
              pMVar17[-1].field_0x270e = 0;
              pMVar17[-1].field_0x270f = 0;
              (*pcVar5)((long)a0,sVar8,a2,a3,a4,(long)pMVar18);
              plVar11 = (long *)((long)pVVar4->array +
                                (long)(&((*(MainPanel_ *(*))(__fp - 0x60))->super).header + -1) + 0x2618);
            }
          }
          else {
LAB_0011a630:
                    /* Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: char * user@[???]
                       Unresolved local var: Panel * panel@[???]
                       Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
            pVVar4->items = wVar19;
            plVar11 = (long *)((long)ptr + (long)pMVar18);
          }
          *plVar11 = (long)puVar9;
          (list->super).needsRedraw = true;
        }
        uVar21 = uVar21 + 1;
        pMVar22 = (Machine *)(*(ulong *)((char *)&(*(undefined1 (*) [16])(__fp - 0x88)) + 8));
      } while (uVar21 < pHVar3->size);
    }
    pVVar4 = (list->super).items;
    pMVar17[-1].idSearch = 0x11a74d;
    pMVar17[-1].field_0x270c = 0;
    pMVar17[-1].field_0x270d = 0;
    pMVar17[-1].field_0x270e = 0;
    pMVar17[-1].field_0x270f = 0;
    Vector_insertionSort(pVVar4);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    pMVar17[-1].idSearch = 0x11a757;
    pMVar17[-1].field_0x270c = 0;
    pMVar17[-1].field_0x270d = 0;
    pMVar17[-1].field_0x270e = 0;
    pMVar17[-1].field_0x270f = 0;
    data_ = malloc(0x18);
    if (data_ != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      data_->klass = &ListItem_class;
      pMVar17[-1].idSearch = 0x11a77a;
      pMVar17[-1].field_0x270c = 0;
      pMVar17[-1].field_0x270d = 0;
      pMVar17[-1].field_0x270e = 0;
      pMVar17[-1].field_0x270f = 0;
      pOVar12 = (ObjectClass *)strdup(((char *)(long)&s_All_users_001473f1 /* "All users" */));
      if (pOVar12 != (ObjectClass *)0x0) {
        data_[1].klass = pOVar12;
        pVVar4 = (list->super).items;
        *(undefined4 *)&data_[2].klass = 0xffffffff;
        *(undefined1 *)((long)&data_[2].klass + 4) = 0;
        pMVar17[-1].idSearch = 0x11a7a5;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        Vector_insert(pVVar4,0,data_);
        st_00 = (*(State_2 *(*))(__fp - 0x78));
        (list->super).needsRedraw = true;
        pMVar17[-1].idSearch = 0x11a7bc;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        pOVar13 = Action_pickFromVector(st_00,list,19,false);
        if (pOVar13 != (Object *)0x0) {
          if (pOVar13 != data_) {
                    /* Unresolved local var: passwd * user@[???] */
            pOVar12 = pOVar13[1].klass;
            pMVar17[-1].idSearch = 0x11a7cf;
            pMVar17[-1].field_0x270c = 0;
            pMVar17[-1].field_0x270d = 0;
            pMVar17[-1].field_0x270e = 0;
            pMVar17[-1].field_0x270f = 0;
            ppVar14 = getpwnam((char *)pOVar12);
            if (ppVar14 != (passwd *)0x0) {
              pMVar22->userId = ppVar14->pw_uid;
              goto LAB_0011a7de;
            }
          }
          pMVar22->userId = 0xffffffff;
        }
LAB_0011a7de:
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
        __ptr = (list->super).eventHandlerState;
        pMVar17[-1].idSearch = 0x11a7e7;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        free(__ptr);
        pVVar4 = (list->super).items;
        pMVar17[-1].idSearch = 0x11a7f0;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        Vector_delete(pVVar4);
        pFVar7 = (list->super).defaultBar;
        pMVar17[-1].idSearch = 0x11a7f9;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        FunctionBar_delete(pFVar7);
        if (350 < (list->super).header.chlen) {
          pcVar20 = (list->super).header.chptr;
          pMVar17[-1].idSearch = 0x11a849;
          pMVar17[-1].field_0x270c = 0;
          pMVar17[-1].field_0x270d = 0;
          pMVar17[-1].field_0x270e = 0;
          pMVar17[-1].field_0x270f = 0;
          free(pcVar20);
        }
        pMVar17[-1].idSearch = 0x11a80a;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        free(list);
        if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
          return 0x61;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
    }
  }
LAB_0011a84b:
                    /* WARNING: Subroutine does not return */
  pMVar17[-1].idSearch = 0x11a850;
  pMVar17[-1].field_0x270c = 0;
  pMVar17[-1].field_0x270d = 0;
  pMVar17[-1].field_0x270e = 0;
  pMVar17[-1].field_0x270f = 0;
  fail();
}


/* actionSetup @ 0x11a860 */

Htop_Reaction actionSetup(State_2 *st)

{
  Machine *host;
  Header_4 *header;
  Settings__2 *pSVar1;
  ScreenManager *this;
  Vector *pVVar2;
  Object **ppOVar3;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: ScreenManager * scr@[???] */
  host = st->host;
  header = (Header_4 *)st->header;
                    /* Unresolved local var: ScreenManager * this@[???]
                       Unresolved local var: void * data@[???] */
  pSVar1 = host->settings;
  this = malloc(0x48);
  if (this != (ScreenManager *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = 0;
    this->y2 = -1;
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
      pVVar2->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pVVar2->array = ppOVar3;
        pVVar2->arraySize = 10;
        pVVar2->type = &Panel_class.super;
        pVVar2->owner = true;
        pVVar2->items = 0;
        pVVar2->dirty_index = -1;
        pVVar2->dirty_count = 0;
        this->panels = pVVar2;
        this->panelCount = 0;
        this->state = st;
        this->allowFocusChange = true;
        this->header = (Header_2 *)header;
        this->host = host;
        CategoriesPanel_new((ScreenManager_3 *)this,header,(Machine_2 *)host);
        ScreenManager_run(this,(Panel **)0x0,(int *)0x0,((char *)(long)&s_Setup_001473fb /* "Setup" */));
        Vector_delete(this->panels);
        free(this);
        if (pSVar1->changed != false) {
          if (pSVar1->enableMouse == false) {
            mousemask(0,(ulong *)0x0);
          }
          else {
            mousemask(0x210001,(ulong *)0x0);
          }
          Header_writeBackToSettings((Header *)st->header);
        }
        return HTOP_RESIZE;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* actionLsof @ 0x11a9d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionLsof(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  OpenFilesScreen *this;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  if ((!readonly) && (st->host->settings->ss->dynamic == (char *)0x0)) {
    pVVar1 = (st->mainPanel->super).items;
    if ((0 < pVVar1->items) &&
       (process = (Process *)pVVar1->array[(st->mainPanel->super).selected],
       process != (Process *)0x0)) {
      this = OpenFilesScreen_new(process);
      InfoScreen_run(&this->super);
      CommandScreen_delete((Object *)this);
      wclear(_stdscr);
      halfdelay(*CRT_delay);
      return HTOP_REDRAW_BAR|HTOP_REFRESH;
    }
  }
  return HTOP_OK;
}


/* actionShowLocks @ 0x11aa60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionShowLocks(State_2 *st)

{
  Vector *pVVar1;
  Process_2 *process;
  ProcessLocksScreen *this;

                    /* Unresolved local var: Settings * settings@[???] */
  if (st->host->settings->ss->dynamic == (char *)0x0) {
    pVVar1 = (st->mainPanel->super).items;
    if ((0 < pVVar1->items) &&
       (process = (Process_2 *)pVVar1->array[(st->mainPanel->super).selected],
       process != (Process_2 *)0x0)) {
      this = ProcessLocksScreen_new(process);
      InfoScreen_run(&this->super);
      CommandScreen_delete((Object *)this);
      wclear(_stdscr);
      halfdelay(*CRT_delay);
      return HTOP_REDRAW_BAR|HTOP_REFRESH;
    }
  }
  return HTOP_OK;
}


/* actionStrace @ 0x11aaf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionStrace(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  _Bool _Var2;
  TraceScreen *this;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  if ((!readonly) && (st->host->settings->ss->dynamic == (char *)0x0)) {
    pVVar1 = (st->mainPanel->super).items;
    if ((0 < pVVar1->items) &&
       (process = (Process *)pVVar1->array[(st->mainPanel->super).selected],
       process != (Process *)0x0)) {
      this = TraceScreen_new(process);
      _Var2 = TraceScreen_forkTracer(this);
      if (_Var2) {
        InfoScreen_run(&this->super);
      }
      TraceScreen_delete(this);
      wclear(_stdscr);
      halfdelay(*CRT_delay);
      return HTOP_REDRAW_BAR|HTOP_REFRESH;
    }
  }
  return HTOP_OK;
}


/* actionShowEnvScreen @ 0x11abf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionShowEnvScreen(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  Htop_Reaction HVar2;
  InfoScreen *this;
  InfoScreen_2 *this_00;

                    /* Unresolved local var: Settings * settings@[???] */
  HVar2 = HTOP_OK;
  if (st->host->settings->ss->dynamic == (char *)0x0) {
    pVVar1 = (st->mainPanel->super).items;
    if (0 < pVVar1->items) {
      process = (Process *)pVVar1->array[(st->mainPanel->super).selected];
      if (process != (Process *)0x0) {
                    /* Unresolved local var: EnvScreen * this@[???]
                       Unresolved local var: void * data@[???] */
        this = malloc(0x28);
        if (this == (InfoScreen *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        (this->super).klass = &EnvScreen_class.super;
        this_00 = InfoScreen_init(this,process,(FunctionBar *)0x0,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
        InfoScreen_run((InfoScreen *)this_00);
        CommandScreen_delete(&this_00->super);
        wclear(_stdscr);
        halfdelay(*CRT_delay);
        HVar2 = HTOP_REDRAW_BAR|HTOP_REFRESH;
      }
      return HVar2;
    }
  }
  return HTOP_OK;
}


/* actionShowCommandScreen @ 0x11ad20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionShowCommandScreen(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  Htop_Reaction HVar2;
  InfoScreen *this;
  InfoScreen_2 *this_00;

                    /* Unresolved local var: Settings * settings@[???] */
  HVar2 = HTOP_OK;
  if (st->host->settings->ss->dynamic == (char *)0x0) {
    pVVar1 = (st->mainPanel->super).items;
    if (0 < pVVar1->items) {
      process = (Process *)pVVar1->array[(st->mainPanel->super).selected];
      if (process != (Process *)0x0) {
                    /* Unresolved local var: CommandScreen * this@[???]
                       Unresolved local var: void * data@[???] */
        this = malloc(0x28);
        if (this == (InfoScreen *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        (this->super).klass = &CommandScreen_class.super;
        this_00 = InfoScreen_init(this,process,(FunctionBar *)0x0,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
        InfoScreen_run((InfoScreen *)this_00);
        CommandScreen_delete(&this_00->super);
        wclear(_stdscr);
        halfdelay(*CRT_delay);
        HVar2 = HTOP_REDRAW_BAR|HTOP_REFRESH;
      }
      return HVar2;
    }
  }
  return HTOP_OK;
}


/* actionSetAffinity @ 0x11b7a0 */

Htop_Reaction actionSetAffinity(State_2 *st)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  _Bool _Var1;
  _Bool _Var2;
  Htop_Reaction HVar3;
  Affinity *affinity;
  Arg list;
  Object *pOVar4;
  Arg AVar5;
  Vector *pVVar6;
  MainPanel__2 *a3;
  MainPanel__2 *pMVar7;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar8;
  Arg host;
  long in_R8;
  long in_R9;
  char cVar9;
  byte bVar10;
  long in_FS_OFFSET = (long)__fake_fs;

  cVar9 = readonly;
  host = ((Arg){.v = (void *)(st->host)});
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (((!readonly) && (*(long *)(*(long *)(*(long *)host.v + 0x40) + 8) == 0)) &&
     (*(int *)((long)host.v + 0x78) != 1)) {
    pVVar6 = (st->mainPanel->super).items;
    if ((0 < pVVar6->items) &&
       (pOVar4 = pVVar6->array[(st->mainPanel->super).selected], pOVar4 != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
      affinity = (Affinity *)Affinity_get((Process *)(ulong)*(uint *)&pOVar4[2].klass,host.v);
      if (affinity != (Affinity *)0x0) {
        list.v = AffinityPanel_new(host.v,affinity,&(*(int (*))(__fp - 0x44)));
        free(affinity->cpus);
        free(affinity);
        a3 = (MainPanel__2 *)0x1;
        AVar5.v = list.v;
        pOVar4 = Action_pickFromVector(st,list.v,(*(int (*))(__fp - 0x44)),true);
        lVar8 = extraout_RDX;
        if (pOVar4 != (Object *)0x0) {
                    /* Unresolved local var: Affinity * affinity2@[???]
                       Unresolved local var: _Bool ok@[???] */
          AVar5.v = AffinityPanel_getAffinity(list.v,host.v);
          pMVar7 = st->mainPanel;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: int i@[???] */
          pVVar6 = (pMVar7->super).items;
          if (0 < pVVar6->items) {
            lVar8 = 0;
            bVar10 = 1;
            do {
                    /* Unresolved local var: Row * row@[???] */
              _Var2 = (((Process_ *)pVVar6->array[lVar8])->super).tag;
              if (_Var2 != false) {
                host.v = AVar5.v;
                _Var1 = Affinity_rowSet((Process_ *)pVVar6->array[lVar8],AVar5);
                bVar10 = bVar10 & _Var1;
                pVVar6 = (pMVar7->super).items;
                cVar9 = _Var2;
              }
              lVar8 = lVar8 + 1;
            } while ((int)lVar8 < pVVar6->items);
                    /* Unresolved local var: Row * row@[???] */
            if ((cVar9 != '\x01') && (0 < pVVar6->items)) {
              a3 = pMVar7;
              if ((Process_ *)pVVar6->array[(pMVar7->super).selected] != (Process_ *)0x0) {
                host.v = AVar5.v;
                _Var2 = Affinity_rowSet((Process_ *)pVVar6->array[(pMVar7->super).selected],AVar5);
                bVar10 = bVar10 & _Var2;
                a3 = pMVar7;
              }
            }
            if (bVar10 == 0) {
              beep();
            }
          }
          free(*(void **)((long)AVar5.v + 0x10));
          free(AVar5.v);
          lVar8 = extraout_RDX_00;
          AVar5 = host;
        }
        (**(code **)(*(long *)list.v + 0x10))(list.v,*(long *)&AVar5,lVar8,(long)a3,in_R8,in_R9);
        HVar3 = 0x61;
        goto LAB_0011b7e5;
      }
    }
  }
  HVar3 = HTOP_OK;
LAB_0011b7e5:
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

