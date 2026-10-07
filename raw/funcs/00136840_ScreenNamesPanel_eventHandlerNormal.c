/* ScreenNamesPanel_eventHandlerNormal @ 00136840 size 1224 */

HandlerResult ScreenNamesPanel_eventHandlerNormal(ScreenNamesPanel_ *super,wchar_t ch)

{
  code *a2;
  ListItem *pLVar1;
  char *__src;
  wchar_t wVar2;
  HandlerResult HVar3;
  ScreenSettings_4 *pSVar4;
  undefined8 *data_;
  char *pcVar5;
  size_t sVar6;
  ushort **ppuVar7;
  Vector *pVVar8;
  long lVar9;
  long in_R8;
  long in_R9;
  Object *pOVar10;
  Object *pOVar11;
  wchar_t wVar12;
  long in_FS_OFFSET;
  ScreenDefaults local_68;
  long local_40;

                    /* Unresolved local var: ScreenNamesPanel * this@[???]
                       Unresolved local var: ScreenNameListItem * oldFocus@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: ScreenNameListItem * newFocus@[???] */
  pVVar8 = (super->super).items;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  wVar12 = pVVar8->items;
  if (wVar12 < L'\x01') {
    if (ch == L'Ć') {
      Panel_onKey(&super->super,L'Ć');
LAB_00136ba0:
      HVar3 = IGNORED;
      goto LAB_00136a83;
    }
    if (L'Ć' < ch) {
      if (ch < L'Ŕ') {
        if (ch < L'Œ') {
          pOVar11 = (Object *)0x0;
          pOVar10 = (Object *)0x0;
          if (ch == L'č') goto LAB_001368fc;
          if (ch == L'Ĩ') goto LAB_001368c0;
        }
        else {
LAB_00136cb5:
          Panel_onKey(&super->super,ch);
        }
      }
      else {
        if (ch == L'Ũ') {
          ch = L'Ũ';
          goto LAB_00136cb5;
        }
        if ((ch == L'ƙ') || (ch == L'ŗ')) {
LAB_00136ce4:
          pOVar10 = (Object *)0x0;
          goto LAB_001368c0;
        }
      }
      goto LAB_00136ba0;
    }
    if (ch == L'\xffffffff') goto LAB_00136a7e;
    if (L'\xfffffffe' < ch) {
      if (ch == L'\x0e') {
        pOVar11 = (Object *)0x0;
        goto LAB_001368fc;
      }
      if (L'\x0e' < ch) {
        pOVar10 = (Object *)0x0;
        if (ch < L'ÿ') goto LAB_00136cfc;
        goto LAB_00136ba0;
      }
      if (ch == L'\n') goto LAB_00136ce4;
      pOVar10 = (Object *)0x0;
      if (ch == L'\r') goto LAB_001368c0;
    }
    ppuVar7 = __ctype_b_loc();
    if ((*(byte *)((long)*ppuVar7 + (long)ch * 2 + 1) & 4) == 0) goto LAB_00136ba0;
    pOVar10 = (Object *)0x0;
LAB_00136b10:
    HVar3 = Panel_selectByTyping(&super->super,ch);
    pVVar8 = (super->super).items;
    wVar12 = pVVar8->items;
    pOVar11 = pOVar10;
    if (HVar3 == BREAK_LOOP) {
      HVar3 = IGNORED;
    }
LAB_00136a64:
    if (wVar12 < L'\x01') goto LAB_00136a83;
    lVar9 = (long)(super->super).selected;
    pOVar10 = pOVar11;
LAB_00136a6d:
    if ((pVVar8->array[lVar9] == pOVar10) || (pVVar8->array[lVar9] == (Object *)0x0))
    goto LAB_00136a83;
  }
  else {
    lVar9 = (long)(super->super).selected;
    pOVar10 = pVVar8->array[lVar9];
    if (ch == L'Ć') {
      Panel_onKey(&super->super,L'Ć');
      lVar9 = (long)(super->super).selected;
LAB_00136c50:
      HVar3 = IGNORED;
      goto LAB_00136a6d;
    }
    pOVar11 = pOVar10;
    if (L'Ć' < ch) {
      if (ch < L'Ŕ') {
        if (ch < L'Œ') {
          if (ch == L'č') goto LAB_001368fc;
          if (ch == L'Ĩ') goto LAB_001368c0;
        }
        else {
          Panel_onKey(&super->super,ch);
          lVar9 = (long)(super->super).selected;
        }
      }
      else if (ch == L'Ũ') {
        Panel_onKey(&super->super,L'Ũ');
        lVar9 = (long)(super->super).selected;
      }
      else if ((ch == L'ƙ') || (ch == L'ŗ')) {
LAB_001368c0:
        (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
        HVar3 = HANDLED;
        pOVar11 = pOVar10;
        goto LAB_00136a64;
      }
      goto LAB_00136c50;
    }
    if (ch != L'\xffffffff') {
      if (L'\xfffffffe' < ch) {
        if (ch == L'\x0e') {
LAB_001368fc:
                    /* Unresolved local var: ScreenNamesPanel * this@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: ScreenNameListItem * item@[???]
                       Unresolved local var: wchar_t idx@[???] */
          if (super->ds == (DynamicScreen *)0x0) {
            local_68.treeSortKey = (char *)0x0;
            local_68.sortKey = ((char *)0x14828e /* "PID" */);
            local_68.name = ((char *)0x1491b7 /* "New" */);
            local_68.columns = ((char *)0x1491bb /* "PID Command" */);
            pSVar4 = Settings_newScreen((Settings *)super->settings,&local_68);
          }
          else {
            pSVar4 = Settings_newDynamicScreen
                               ((Settings *)super->settings,((char *)0x1491b7 /* "New" */),super->ds,(Table_3 *)0x0);
          }
                    /* Unresolved local var: ScreenNameListItem * this@[???]
                       Unresolved local var: void * data@[???] */
          data_ = malloc(0x20);
          if (data_ == (undefined8 *)0x0) {
LAB_00136d57:
                    /* WARNING: Subroutine does not return */
            fail();
          }
                    /* Unresolved local var: char * data@[???] */
          *data_ = &ScreenNameListItem_class;
          pcVar5 = strdup(((char *)0x1491b7 /* "New" */));
          if (pcVar5 == (char *)0x0) goto LAB_00136d57;
          data_[1] = pcVar5;
          wVar12 = (super->super).selected;
          data_[3] = pSVar4;
          pVVar8 = (super->super).items;
          *(undefined4 *)(data_ + 2) = 0;
          wVar12 = wVar12 + L'\x01';
          *(undefined1 *)((long)data_ + 0x14) = 0;
          Vector_insert(pVVar8,wVar12,data_);
                    /* Unresolved local var: wchar_t size@[???] */
          pVVar8 = (super->super).items;
          (super->super).needsRedraw = true;
          wVar2 = pVVar8->items;
          if (wVar2 <= wVar12) {
            wVar12 = wVar2 + L'\xffffffff';
          }
          if (wVar12 < L'\0') {
            wVar12 = L'\0';
          }
          a2 = (super->super).super.klass[1].extends;
          (super->super).selected = wVar12;
          if (a2 != (code *)0x0) {
            (*a2)((long)super,0xffffffff,(long)a2,(long)pVVar8,in_R8,in_R9);
                    /* Unresolved local var: ScreenNamesPanel * this@[???]
                       Unresolved local var: ListItem * item@[???]
                       Unresolved local var: char * name@[???] */
            pVVar8 = (super->super).items;
            wVar2 = pVVar8->items;
          }
          if (L'\0' < wVar2) {
            wVar12 = (super->super).selected;
            pLVar1 = (ListItem *)pVVar8->array[wVar12];
            if (pLVar1 != (ListItem *)0x0) {
              __src = pLVar1->value;
              (super->super).cursorOn = true;
              pcVar5 = super->buffer;
              super->renamingItem = pLVar1;
              super->saved = __src;
              strncpy(pcVar5,__src,0x14);
              super->buffer[0x14] = '\0';
              sVar6 = strlen(pcVar5);
              super->cursor = (wchar_t)sVar6;
              pLVar1->value = pcVar5;
              (super->super).selectionColorId = PANEL_EDIT;
              sVar6 = strlen(pcVar5);
              (super->super).selectedLen = (wchar_t)sVar6;
              (super->super).cursorY =
                   ((wVar12 + (super->super).y) - (super->super).scrollV) + L'\x01';
              wVar12 = pVVar8->items;
              (super->super).cursorX = ((wchar_t)sVar6 + (super->super).x) - (super->super).scrollH;
              HVar3 = HANDLED;
              goto LAB_00136a64;
            }
          }
          goto LAB_00136a7e;
        }
        if (L'\x0e' < ch) {
          if (L'þ' < ch) goto LAB_00136c50;
LAB_00136cfc:
          ppuVar7 = __ctype_b_loc();
          HVar3 = IGNORED;
          pOVar11 = pOVar10;
          if ((*(byte *)((long)*ppuVar7 + (long)ch * 2 + 1) & 4) != 0) goto LAB_00136b10;
          goto LAB_00136a64;
        }
        if ((ch == L'\n') || (ch == L'\r')) goto LAB_001368c0;
      }
      ppuVar7 = __ctype_b_loc();
      if ((*(byte *)((long)*ppuVar7 + (long)ch * 2 + 1) & 4) != 0) goto LAB_00136b10;
      goto LAB_00136c50;
    }
  }
LAB_00136a7e:
  HVar3 = HANDLED;
LAB_00136a83:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return HVar3;
}

