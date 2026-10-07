/* ColumnsPanel_eventHandler @ 0011cf50 size 479 */

HandlerResult ColumnsPanel_eventHandler(ColumnsPanel_ *super,wchar_t ch)

{
  Object **ppOVar1;
  Object **ppOVar2;
  wchar_t i;
  wchar_t wVar3;
  Vector *pVVar4;
  Object *pOVar5;
  HandlerResult HVar6;
  ushort **ppuVar7;
  _Bool _Var8;

  pVVar4 = (super->super).items;
  i = (super->super).selected;
  wVar3 = pVVar4->items;
  if (L'Ĩ' < ch) {
    if (ch != L'Ŋ') {
      if (ch < L'Ŋ') {
        return IGNORED;
      }
      if ((ch != L'ŗ') && (ch != L'ƙ')) {
        return IGNORED;
      }
switchD_0011cf98_caseD_128:
      if (wVar3 + L'\xffffffff' <= i) {
        return IGNORED;
      }
                    /* Unresolved local var: ListItem * selectedItem@[???] */
      _Var8 = (_Bool)(super->moving ^ 1);
      super->moving = _Var8;
      (super->super).selectionColorId = _Var8 + PANEL_SELECTION_FOCUS;
      if ((L'\0' < wVar3) && (pVVar4->array[i] != (Object *)0x0)) {
        *(_Bool *)((long)&pVVar4->array[i][2].klass + 4) = _Var8;
      }
      goto LAB_0011d040;
    }
switchD_0011cf98_caseD_111:
    if (i < wVar3 + L'\xffffffff') {
      Panel_remove(&super->super,i);
    }
    goto LAB_0011d040;
  }
  if (L'ā' < ch) {
    switch(ch) {
    case L'Ă':
      if (super->moving == false) {
        return IGNORED;
      }
    case L'Đ':
switchD_0011cf98_caseD_110:
      if (i < wVar3 + L'\xfffffffe') {
        Panel_moveSelectedDown(&super->super);
      }
      break;
    case L'ă':
      if (super->moving == false) {
        return IGNORED;
      }
    case L'ď':
switchD_0011cf98_caseD_10f:
                    /* Unresolved local var: Object * temp@[???] */
      if ((i < wVar3 + L'\xffffffff') && (i != L'\0')) {
                    /* Unresolved local var: Object * temp@[???] */
        ppOVar1 = pVVar4->array + (long)i + -1;
        pOVar5 = *ppOVar1;
        ppOVar2 = pVVar4->array + (long)i + -1;
        *ppOVar2 = ppOVar1[1];
        ppOVar2[1] = pOVar5;
        if (L'\0' < i) {
          (super->super).selected = i + L'\xffffffff';
        }
      }
      break;
    default:
switchD_0011cf98_caseD_104:
      if (0xfd < (uint)(ch + L'\xffffffff')) {
        return IGNORED;
      }
      ppuVar7 = __ctype_b_loc();
      if (-1 < (short)(*ppuVar7)[ch]) {
        return IGNORED;
      }
      HVar6 = Panel_selectByTyping(&super->super,ch);
      if (HVar6 == BREAK_LOOP) {
        return IGNORED;
      }
      if (HVar6 != HANDLED) {
        return HVar6;
      }
      break;
    case L'đ':
      goto switchD_0011cf98_caseD_111;
    case L'Ĩ':
      goto switchD_0011cf98_caseD_128;
    }
LAB_0011d040:
    ColumnsPanel_update(super);
    return HANDLED;
  }
  if (ch != L'-') {
    if (ch < L'.') {
      if (ch != L'\r') {
        if (ch == L'+') goto switchD_0011cf98_caseD_110;
        if (ch != L'\n') goto switchD_0011cf98_caseD_104;
      }
      goto switchD_0011cf98_caseD_128;
    }
    if (ch != L'[') {
      if (ch != L']') goto switchD_0011cf98_caseD_104;
      goto switchD_0011cf98_caseD_110;
    }
  }
  goto switchD_0011cf98_caseD_10f;
}

