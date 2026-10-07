/* MetersPanel_eventHandler @ 00129b50 size 1061 */

HandlerResult MetersPanel_eventHandler(MetersPanel_ *super,wchar_t ch)

{
  uint64_t *puVar1;
  Object **ppOVar2;
  Header_3 *this;
  Settings_3 *pSVar3;
  Object **ppOVar4;
  MetersPanel *a0;
  Vector *pVVar5;
  code *a3;
  Object *pOVar6;
  FunctionBar *pFVar7;
  _Bool _Var8;
  wchar_t wVar9;
  Meter *pMVar10;
  ListItem *pLVar11;
  wchar_t wVar12;
  Vector *pVVar13;
  long in_R8;
  long in_R9;
  wchar_t idx;
  HandlerResult HVar14;

  idx = (super->super).selected;
  if (L'đ' < ch) {
    if (ch == L'Ŋ') {
switchD_00129b93_caseD_111:
      wVar9 = super->meters->items;
      if (wVar9 == L'\0') {
        return IGNORED;
      }
      if (idx < wVar9) {
        Vector_remove(super->meters,idx);
        Panel_remove(&super->super,idx);
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar13 = (super->super).items;
      super->moving = false;
      if ((L'\0' < pVVar13->items) &&
         (pOVar6 = pVVar13->array[(super->super).selected], pOVar6 != (Object *)0x0)) {
        *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
      }
    }
    else {
      if (ch != L'ŗ') {
        return IGNORED;
      }
switchD_00129bf3_caseD_a:
      if (super->meters->items == L'\0') {
        return IGNORED;
      }
      pVVar13 = (super->super).items;
      wVar9 = pVVar13->items;
      _Var8 = (_Bool)(super->moving ^ 1);
      super->moving = _Var8;
      if ((L'\0' < wVar9) && (pOVar6 = pVVar13->array[idx], pOVar6 != (Object *)0x0)) {
        *(_Bool *)((long)&pOVar6[2].klass + 4) = _Var8;
      }
      pFVar7 = Meters_movingBar;
      if (_Var8 != false) {
        (super->super).selectionColorId = PANEL_SELECTION_FOLLOW;
        (super->super).currentBar = pFVar7;
        goto LAB_00129c3c;
      }
    }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
    (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
    (super->super).currentBar = (super->super).defaultBar;
    goto LAB_00129c3c;
  }
  if (ch < L'Ă') {
    if (ch < L'.') {
      if (ch < L'\n') {
LAB_00129bc6:
        return IGNORED;
      }
      switch(ch) {
      case L'\n':
      case L'\r':
        goto switchD_00129bf3_caseD_a;
      default:
        goto LAB_00129bc6;
      case L' ':
        goto switchD_00129b93_caseD_10c;
      case L'+':
        goto switchD_00129b93_caseD_110;
      case L'-':
        goto switchD_00129b93_caseD_10f;
      }
    }
    if (ch != L']') {
      if (ch == L't') goto switchD_00129b93_caseD_10c;
      if (ch != L'[') {
        return IGNORED;
      }
      goto switchD_00129b93_caseD_10f;
    }
    goto switchD_00129b93_caseD_110;
  }
  switch(ch) {
  case L'Ă':
    if (super->moving == false) {
      return IGNORED;
    }
  case L'Đ':
switchD_00129b93_caseD_110:
                    /* Unresolved local var: Object * temp@[???] */
    if (idx != super->meters->items + L'\xffffffff') {
      ppOVar2 = super->meters->array + idx;
      pOVar6 = *ppOVar2;
      *ppOVar2 = ppOVar2[1];
      ppOVar2[1] = pOVar6;
    }
    Panel_moveSelectedDown(&super->super);
    break;
  case L'ă':
    if (super->moving == false) {
      return IGNORED;
    }
  case L'ď':
switchD_00129b93_caseD_10f:
                    /* Unresolved local var: Object * temp@[???] */
    if (idx != L'\0') {
      ppOVar4 = super->meters->array;
                    /* Unresolved local var: Object * temp@[???] */
      ppOVar2 = ppOVar4 + (long)idx + -1;
      pOVar6 = *ppOVar2;
      ppOVar4 = ppOVar4 + (long)idx + -1;
      *ppOVar4 = ppOVar2[1];
      ppOVar4[1] = pOVar6;
                    /* Unresolved local var: Object * temp@[???] */
      ppOVar4 = ((super->super).items)->array;
      ppOVar2 = ppOVar4 + (long)idx + -1;
                    /* Unresolved local var: Object * temp@[???] */
      pOVar6 = *ppOVar2;
      ppOVar4 = ppOVar4 + (long)idx + -1;
      *ppOVar4 = ppOVar2[1];
      ppOVar4[1] = pOVar6;
      if (L'\0' < idx) {
        (super->super).selected = idx + L'\xffffffff';
      }
    }
    break;
  case L'Ą':
    if (super->moving == false) {
      return IGNORED;
    }
    a0 = super->leftNeighbor;
    goto joined_r0x00129d6d;
  case L'ą':
                    /* Unresolved local var: Panel * super@[???] */
    if (super->moving == false) {
      return IGNORED;
    }
    a0 = super->rightNeighbor;
joined_r0x00129d6d:
                    /* Unresolved local var: Panel * super@[???] */
    if ((a0 != (MetersPanel *)0x0) && (pVVar13 = super->meters, idx < pVVar13->items)) {
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: Meter * meter@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar5 = (super->super).items;
      super->moving = false;
      if ((L'\0' < pVVar5->items) && (pOVar6 = pVVar5->array[idx], pOVar6 != (Object *)0x0)) {
        *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
      (super->super).currentBar = (super->super).defaultBar;
      pMVar10 = (Meter *)Vector_take(pVVar13,idx);
      Panel_remove(&super->super,idx);
      Vector_insert(a0->meters,idx,pMVar10);
      pLVar11 = Meter_toListItem(pMVar10,false);
      Vector_insert((a0->super).items,idx,pLVar11);
                    /* Unresolved local var: wchar_t size@[???] */
      pVVar13 = (a0->super).items;
      (a0->super).needsRedraw = true;
      wVar9 = pVVar13->items;
      if (wVar9 <= idx) {
        idx = wVar9 + L'\xffffffff';
      }
      wVar12 = L'\0';
      if (L'\xffffffff' < idx) {
        wVar12 = idx;
      }
      (a0->super).selected = wVar12;
      a3 = (a0->super).super.klass[1].extends;
      if (a3 != (code *)0x0) {
        (*a3)((long)a0,0xffffffff,(long)pVVar13,(long)a3,in_R8,in_R9);
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
        pVVar13 = (a0->super).items;
        wVar9 = pVVar13->items;
      }
      a0->moving = true;
      if ((L'\0' < wVar9) && (pVVar13->array[(a0->super).selected] != (Object *)0x0)) {
        *(undefined1 *)((long)&pVVar13->array[(a0->super).selected][2].klass + 4) = 1;
      }
      pFVar7 = Meters_movingBar;
      (a0->super).selectionColorId = PANEL_SELECTION_FOLLOW;
      (a0->super).currentBar = pFVar7;
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: wchar_t mode@[???] */
      HVar14 = IGNORED;
      goto LAB_00129c42;
    }
    break;
  default:
    goto LAB_00129bc6;
  case L'Č':
switchD_00129b93_caseD_10c:
    if (super->meters->items == L'\0') {
      return IGNORED;
    }
    pMVar10 = (Meter *)super->meters->array[idx];
    wVar9 = pMVar10->mode + L'\x01';
    if (pMVar10->mode == L'\x04') {
      wVar9 = L'\x01';
    }
    Meter_setMode(pMVar10,wVar9);
    pLVar11 = Meter_toListItem(pMVar10,super->moving);
    Vector_set((super->super).items,idx,pLVar11);
    break;
  case L'đ':
    goto switchD_00129b93_caseD_111;
  }
LAB_00129c3c:
  HVar14 = HANDLED;
LAB_00129c42:
                    /* Unresolved local var: Header * header@[???] */
  this = super->scr->header;
  pSVar3 = super->settings;
  puVar1 = &pSVar3->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar3->changed = true;
  Header_calculateHeight((Header *)this);
  ScreenManager_resize((ScreenManager *)super->scr);
  return HVar14;
}

