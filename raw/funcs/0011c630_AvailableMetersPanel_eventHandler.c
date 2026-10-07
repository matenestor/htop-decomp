/* AvailableMetersPanel_eventHandler @ 0011c630 size 658 */

HandlerResult AvailableMetersPanel_eventHandler(AvailableMetersPanel_ *super,wchar_t ch)

{
  uint64_t *puVar1;
  uint uVar2;
  Header_3 *this;
  Object *pOVar3;
  MetersPanel *pMVar4;
  code *pcVar5;
  Settings__4 *pSVar6;
  FunctionBar *pFVar7;
  int iVar8;
  wchar_t wVar9;
  Meter_3 *pMVar10;
  ListItem *pLVar11;
  uint param;
  wchar_t wVar12;
  Vector *pVVar13;
  long in_R8;
  long in_R9;
  HandlerResult HVar14;

  pVVar13 = (super->super).items;
  this = super->header;
  if (pVVar13->items < L'\x01') {
    return IGNORED;
  }
  pOVar3 = pVVar13->array[(super->super).selected];
  if (pOVar3 == (Object *)0x0) {
    return IGNORED;
  }
  uVar2 = *(uint *)&pOVar3[2].klass;
  param = uVar2 & 0xffff;
  iVar8 = (int)uVar2 >> 0x10;
  if (ch == L'l') {
LAB_0011c7b8:
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: Vector * meters@[???] */
    pMVar4 = *super->meterPanels;
    pVVar13 = *this->columns;
    pMVar10 = Meter_new((Machine_2 *)this->host,param,(MeterClass_3 *)Platform_meterTypes[iVar8]);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
    Vector_set(pVVar13,pVVar13->items,pMVar10);
    pLVar11 = Meter_toListItem((Meter *)pMVar10,false);
    Panel_add(&pMVar4->super,&pLVar11->super);
    pVVar13 = (pMVar4->super).items;
                    /* Unresolved local var: wchar_t size@[???] */
    wVar12 = pVVar13->items;
    wVar9 = wVar12 + L'\xffffffff';
    if (wVar9 < L'\0') {
      wVar9 = L'\0';
    }
    (pMVar4->super).selected = wVar9;
    pcVar5 = (pMVar4->super).super.klass[1].extends;
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)((long)pMVar4,0xffffffff,(long)pVVar13,(ulong)(uint)wVar12,in_R8,in_R9);
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar13 = (pMVar4->super).items;
      wVar12 = pVVar13->items;
    }
    pMVar4->moving = true;
    if ((L'\0' < wVar12) && (pVVar13->array[(pMVar4->super).selected] != (Object *)0x0)) {
      *(undefined1 *)((long)&pVVar13->array[(pMVar4->super).selected][2].klass + 4) = 1;
    }
    pFVar7 = Meters_movingBar;
    (pMVar4->super).selectionColorId = PANEL_SELECTION_FOLLOW;
    (pMVar4->super).currentBar = pFVar7;
    HVar14 = HANDLED;
  }
  else {
    if (ch < L'm') {
      if (ch == L'L') goto LAB_0011c7b8;
      if (ch < L'M') {
        if ((ch != L'\n') && (ch != L'\r')) {
          return IGNORED;
        }
      }
      else if (ch != L'R') {
        return IGNORED;
      }
    }
    else {
      if (ch == L'č') goto LAB_0011c7b8;
      if (ch < L'Ď') {
        if (ch != L'r') {
          return IGNORED;
        }
      }
      else if ((ch != L'Ď') && (ch != L'ŗ')) {
        return IGNORED;
      }
    }
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: Vector * meters@[???] */
    pMVar4 = super->meterPanels[super->columns - 1];
    pVVar13 = this->columns[(int)super->columns - 1];
    pMVar10 = Meter_new((Machine_2 *)this->host,param,(MeterClass_3 *)Platform_meterTypes[iVar8]);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
    Vector_set(pVVar13,pVVar13->items,pMVar10);
    pLVar11 = Meter_toListItem((Meter *)pMVar10,false);
    Panel_add(&pMVar4->super,&pLVar11->super);
    pVVar13 = (pMVar4->super).items;
                    /* Unresolved local var: wchar_t size@[???] */
    wVar12 = pVVar13->items;
    wVar9 = wVar12 + L'\xffffffff';
    if (wVar9 < L'\0') {
      wVar9 = L'\0';
    }
    (pMVar4->super).selected = wVar9;
    pcVar5 = (pMVar4->super).super.klass[1].extends;
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)((long)pMVar4,0xffffffff,(long)pVVar13,(ulong)(uint)wVar12,in_R8,in_R9);
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar13 = (pMVar4->super).items;
      wVar12 = pVVar13->items;
    }
    pMVar4->moving = true;
    if ((L'\0' < wVar12) && (pVVar13->array[(pMVar4->super).selected] != (Object *)0x0)) {
      *(undefined1 *)((long)&pVVar13->array[(pMVar4->super).selected][2].klass + 4) = 1;
    }
    pFVar7 = Meters_movingBar;
    (pMVar4->super).selectionColorId = PANEL_SELECTION_FOLLOW;
    (pMVar4->super).currentBar = pFVar7;
    HVar14 = 0x1040080;
  }
                    /* Unresolved local var: Settings * settings@[???] */
  pSVar6 = super->host->settings;
  puVar1 = &pSVar6->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar6->changed = true;
  Header_calculateHeight((Header *)this);
  Header_updateData((Header *)this);
  Header_draw((Header *)this);
  ScreenManager_resize((ScreenManager *)super->scr);
  return HVar14;
}

