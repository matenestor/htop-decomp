/* MainPanel_eventHandler @ 0012b050 size 1414 */

HandlerResult MainPanel_eventHandler(MainPanel_ *super,wchar_t ch)

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
  wchar_t wVar15;
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
  wchar_t *pwVar23;
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
  if (ch == L'ƚ') {
    return IGNORED;
  }
  if (ch == L'ƙ') {
    settings = pMVar1->settings;
    if (settings->enableMouse == false) {
      this_00 = (IncSet *)super->inc;
      if (this_00->active == (IncMode *)0x0) {
        a2 = 0x198;
        wVar15 = L'ƙ';
LAB_0012b2e7:
        if (super->keys[ch] != (Htop_Action)0x0) {
          HVar11 = (*super->keys[ch])(st,CONCAT44(in_register_00000034,ch),a2,in_RCX,in_R8,in_R9);
          goto LAB_0012b0d3;
        }
        if (((uint)a2 < 0xfe) &&
           (ppuVar17 = __ctype_b_loc(), (*(byte *)((long)*ppuVar17 + (long)ch * 2 + 1) & 8) != 0)) {
          iVar27 = wVar15 + L'\xffffffd0' + super->idSearch;
                    /* Unresolved local var: wchar_t i@[???] */
          pVVar5 = (super->super).items;
          wVar15 = pVVar5->items;
          if (L'\0' < wVar15) {
                    /* Unresolved local var: Row * row@[???] */
            lVar18 = 0;
            do {
              pOVar6 = pVVar5->array[lVar18];
              if ((pOVar6 != (Object *)0x0) && (iVar27 == *(int *)&pOVar6[2].klass)) {
                    /* Unresolved local var: wchar_t size@[???] */
                (super->super).selected = (wchar_t)lVar18;
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
      wVar15 = L'ƙ';
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
    wVar15 = L'\xffffffff';
    if ((L'\0' < pVVar5->items) &&
       (pOVar6 = pVVar5->array[(pMVar4->super).selected], pOVar6 != (Object *)0x0)) {
      wVar15 = *(wchar_t *)&pOVar6[2].klass;
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
    if (ch == L'\xffffffff') {
      return IGNORED;
    }
    settings = pMVar1->settings;
    st->hideSelection = false;
    pSVar2 = settings->ss;
    if ((uint)(ch + L'✐') < 0x3e9) {
                    /* Unresolved local var: wchar_t x@[???]
                       Unresolved local var: wchar_t hx@[???]
                       Unresolved local var: RowField field@[???] */
      RVar14 = RowField_keyAt(settings,ch + L'✐' + (super->super).scrollH + L'\x01');
      if (pSVar2->treeView == false) {
        if (RVar14 != pSVar2->sortKey) goto LAB_0012b1de;
                    /* Unresolved local var: wchar_t * attr@[???] */
        wVar15 = pSVar2->direction;
        pwVar23 = &pSVar2->direction;
LAB_0012b3c2:
        HVar11 = 0x67;
        *pwVar23 = ((wVar15 != L'\x01') - 1) + (uint)(wVar15 != L'\x01');
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
          pSVar2->direction = L'\x01';
        }
        _Var10 = Process_fields[RVar14].defaultSortDesc;
        if ((pSVar20->treeViewAlwaysByPID == false) && (pSVar20->treeView != false)) {
          pSVar20->treeSortKey = RVar14;
          cVar21 = '\x01';
          HVar11 = 0x6f;
          pSVar20->treeDirection = (-(uint)(_Var10 == false) & 2) + L'\xffffffff';
        }
        else {
          pSVar20->sortKey = RVar14;
          HVar11 = 0x6f;
          pSVar20->treeView = false;
          cVar21 = '\0';
          pSVar20->direction = (-(uint)(_Var10 == false) & 2) + L'\xffffffff';
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
      pcVar22 = ((char *)0x14750f /* "Tree  " */);
      if (cVar21 != '\0') {
        pcVar22 = ((char *)0x147508 /* "List  " */);
      }
      FunctionBar_setLabel(this,L'č',pcVar22);
      pcVar22 = ((char *)0x14751d /* "Filter" */);
      if (pIVar26 != (IncMode *)0x0) {
        pcVar22 = ((char *)0x147516 /* "FILTER" */);
      }
      FunctionBar_setLabel(this,L'Č',pcVar22);
    }
    else {
      if (9999 < (uint)(ch + L'丠')) {
        this_00 = (IncSet *)super->inc;
        if (this_00->active != (IncMode *)0x0) goto LAB_0012b32f;
        wVar15 = ch;
        if (ch == L'\x1b') {
          st->hideSelection = true;
          return HANDLED;
        }
LAB_0012b530:
        a2 = (ulong)(uint)(wVar15 + L'\xffffffff');
        if ((uint)(wVar15 + L'\xffffffff') < 0x1fe) goto LAB_0012b2e7;
        goto LAB_0012b4fc;
      }
                    /* Unresolved local var: wchar_t x@[???] */
      HVar11 = Action_setScreenTab((State_2 *)st,ch + L'丠');
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
  pMVar1->activeTable->following = L'\xffffffff';
  (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
  return HVar16;
}

