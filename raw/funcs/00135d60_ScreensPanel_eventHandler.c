/* ScreensPanel_eventHandler @ 00135d60 size 2446 */

HandlerResult ScreensPanel_eventHandler(ScreensPanel_ *super,wchar_t ch)

{
  Object **ppOVar1;
  Object *pOVar2;
  Object_Display p_Var3;
  Vector *this;
  code *pcVar4;
  Settings_4 *pSVar5;
  Object **ppOVar6;
  void *value;
  bool bVar7;
  _Bool _Var8;
  wchar_t wVar9;
  wchar_t wVar10;
  HandlerResult HVar11;
  size_t sVar12;
  ObjectClass *pOVar13;
  ushort **ppuVar14;
  ScreenSettings_4 *pSVar15;
  undefined8 *data_;
  char *pcVar16;
  ScreenSettings_3 **ppSVar17;
  long lVar18;
  wchar_t wVar19;
  Vector *pVVar20;
  wchar_t wVar21;
  Settings *this_00;
  long in_R8;
  ulong uVar22;
  Object *pOVar23;
  AvailableColumnsPanel *this_01;
  Hashtable_2 *columns;
  long in_FS_OFFSET;
  ScreenDefaults local_68;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (super->renamingItem != (ListItem *)0x0) {
                    /* Unresolved local var: ScreensPanel * this@[???] */
    if (((uint)(ch + L'\xffffffe0') < 0x5f) && (ch != L'=')) {
      wVar9 = super->cursor;
      if (wVar9 < L'\x13') {
        super->buffer[wVar9] = (char)ch;
        super->cursor = wVar9 + L'\x01';
LAB_00135eec:
        sVar12 = strlen(super->buffer);
        (super->super).selectedLen = (wchar_t)sVar12;
        (super->super).cursorY =
             (((super->super).selected + (super->super).y) - (super->super).scrollV) + L'\x01';
        (super->super).cursorX = ((wchar_t)sVar12 + (super->super).x) - (super->super).scrollH;
      }
    }
    else if (ch == L'\x1b') {
                    /* Unresolved local var: ListItem * item@[???] */
      pVVar20 = (super->super).items;
      if ((L'\0' < pVVar20->items) &&
         (pOVar23 = pVVar20->array[(super->super).selected], pOVar23 != (Object *)0x0)) {
        pOVar23[1].klass = (ObjectClass *)super->saved;
        super->renamingItem = (ListItem *)0x0;
        (super->super).cursorOn = false;
        (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
      }
    }
    else if (ch < L'\x1c') {
      if ((ch == L'\n') || (ch == L'\r')) {
LAB_00135f30:
                    /* Unresolved local var: ListItem * item@[???] */
        pVVar20 = (super->super).items;
        if ((L'\0' < pVVar20->items) &&
           (pOVar23 = pVVar20->array[(super->super).selected], pOVar23 != (Object *)0x0)) {
          free(super->saved);
                    /* Unresolved local var: char * data@[???] */
          pOVar13 = (ObjectClass *)strdup(super->buffer);
          if (pOVar13 == (ObjectClass *)0x0) goto LAB_00136752;
          pOVar23[1].klass = pOVar13;
          super->renamingItem = (ListItem *)0x0;
          (super->super).cursorOn = false;
          (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
          ScreensPanel_update(super);
        }
      }
    }
    else {
      if (ch != L'ć') {
        if (ch == L'ŗ') goto LAB_00135f30;
        if (ch != L'\x7f') goto LAB_00135db6;
      }
      if (L'\0' < super->cursor) {
        wVar9 = super->cursor + L'\xffffffff';
        super->cursor = wVar9;
        super->buffer[wVar9] = '\0';
        goto LAB_00135eec;
      }
    }
    goto LAB_00135db6;
  }
                    /* Unresolved local var: ScreensPanel * this@[???]
                       Unresolved local var: wchar_t selected@[???]
                       Unresolved local var: ScreenListItem * oldFocus@[???]
                       Unresolved local var: _Bool shouldRebuildArray@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: ScreenListItem * newFocus@[???] */
  pVVar20 = (super->super).items;
  wVar9 = (super->super).selected;
  wVar19 = pVVar20->items;
  uVar22 = (ulong)(uint)wVar19;
  wVar21 = wVar9;
  if (wVar19 < L'\x01') {
    if (L'Ũ' < ch) {
      if (ch == L'ƙ') {
switchD_00136039_caseD_128:
        _Var8 = (_Bool)(super->moving ^ 1);
        super->moving = _Var8;
        (super->super).selectionColorId = _Var8 + PANEL_SELECTION_FOCUS;
        goto switchD_00135ed0_caseD_ffffffff;
      }
      goto switchD_00136039_caseD_104;
    }
    pOVar23 = (Object *)0x0;
    if (ch < L'Ă') {
      if (ch < L'.') {
        if (L'\xfffffffe' < ch) {
          switch(ch) {
          case L'\n':
          case L'\r':
            goto switchD_00136039_caseD_128;
          case L'\x0e':
            goto switchD_00136039_caseD_10d;
          case L'\x12':
            goto switchD_00135e98_caseD_10a;
          case L'+':
            goto switchD_00136039_caseD_110;
          case L'-':
            goto switchD_00136039_caseD_10f;
          case L'\xffffffff':
            goto switchD_00135ed0_caseD_ffffffff;
          }
        }
      }
      else {
        if (ch == L'[') goto switchD_00136039_caseD_10f;
        if (ch == L']') goto switchD_00136039_caseD_110;
        if (L'þ' < ch) goto switchD_00136039_caseD_104;
      }
switchD_00135ed0_caseD_0:
      ppuVar14 = __ctype_b_loc();
      if ((*(byte *)((long)*ppuVar14 + (long)ch * 2 + 1) & 4) == 0) {
joined_r0x0013614f:
        if (L'\0' < wVar19) goto switchD_00135e98_caseD_104;
        goto switchD_00136039_caseD_104;
      }
LAB_00136650:
      HVar11 = Panel_selectByTyping(&super->super,ch);
      pVVar20 = (super->super).items;
      if (HVar11 == BREAK_LOOP) {
        if (pVVar20->items < L'\x01') goto switchD_00136039_caseD_104;
        bVar7 = false;
        HVar11 = IGNORED;
        wVar21 = (super->super).selected;
        goto LAB_00136068;
      }
      if (L'\0' < pVVar20->items) {
        bVar7 = false;
        wVar21 = (super->super).selected;
        goto LAB_00136068;
      }
      goto LAB_00136472;
    }
    switch(ch) {
    case L'Ă':
      pOVar23 = (Object *)0x0;
      if (super->moving != false) goto switchD_00136039_caseD_110;
LAB_001364ba:
                    /* Unresolved local var: wchar_t size@[???] */
      wVar21 = wVar9 + L'\x01';
      if ((wVar21 < L'\0') || (wVar19 == L'\0')) {
        wVar21 = L'\0';
LAB_001364c5:
        (super->super).selected = wVar21;
        (super->super).needsRedraw = true;
        goto joined_r0x0013614f;
      }
      if (wVar19 <= wVar21) {
        wVar21 = wVar19 + L'\xffffffff';
        goto LAB_001364c5;
      }
LAB_00136699:
      ppOVar6 = pVVar20->array;
      (super->super).selected = wVar21;
      pOVar2 = ppOVar6[wVar21];
      if ((pOVar2 == (Object *)0x0) || (pOVar2 == pOVar23)) goto switchD_00136039_caseD_104;
      columns = super->settings->dynamicColumns;
      ColumnsPanel_fill(super->columns,(ScreenSettings *)pOVar2[4].klass,columns);
      this_01 = super->availableColumns;
      p_Var3 = (pOVar2[4].klass)->display;
      Vector_prune((this_01->super).items);
      (this_01->super).scrollV = L'\0';
      (this_01->super).selected = L'\0';
      (this_01->super).oldSelected = L'\0';
      (this_01->super).needsRedraw = true;
      if (p_Var3 == (Object_Display)0x0) {
        AvailableColumnsPanel_addPlatformColumns(this_01);
        bVar7 = false;
        if (columns->size == 0) goto switchD_00135ed0_caseD_ffffffff;
        goto LAB_0013658a;
      }
      goto switchD_00135ed0_caseD_ffffffff;
    case L'ă':
switchD_00135e98_caseD_103:
      if (super->moving == false) {
                    /* Unresolved local var: wchar_t size@[???] */
        wVar21 = wVar9 + L'\xffffffff';
        if ((wVar21 < L'\0') || (wVar19 == L'\0')) {
          wVar21 = L'\0';
        }
        else {
          if (wVar21 < wVar19) goto LAB_00136699;
          wVar21 = wVar19 + L'\xffffffff';
        }
        (super->super).selected = wVar21;
        HVar11 = IGNORED;
        (super->super).needsRedraw = true;
        bVar7 = false;
        if (L'\0' < wVar19) goto LAB_00136068;
        goto switchD_00136039_caseD_104;
      }
                    /* Unresolved local var: Object * temp@[???] */
      if (wVar9 == L'\0') goto joined_r0x001363b3;
LAB_00136233:
      ppOVar6 = pVVar20->array + (long)wVar9 + -1;
                    /* Unresolved local var: Object * temp@[???] */
      pOVar2 = *ppOVar6;
      ppOVar1 = pVVar20->array + (long)wVar9 + -1;
      *ppOVar1 = ppOVar6[1];
      ppOVar1[1] = pOVar2;
      if (L'\0' < wVar9) {
        (super->super).selected = wVar9 + L'\xffffffff';
        goto joined_r0x001363b3;
      }
      bVar7 = true;
      HVar11 = HANDLED;
      if (L'\0' < wVar19) goto LAB_00136068;
      break;
    default:
      goto switchD_00136039_caseD_104;
    case L'Ć':
    case L'Œ':
    case L'œ':
    case L'Ũ':
      Panel_onKey(&super->super,ch);
      goto switchD_00136039_caseD_104;
    case L'Ċ':
      goto switchD_00135e98_caseD_10a;
    case L'č':
switchD_00136039_caseD_10d:
      this_00 = (Settings *)super->settings;
      if (this_00->dynamicScreens != (Hashtable_2 *)0x0) goto switchD_00136039_caseD_104;
      pOVar23 = (Object *)0x0;
LAB_001362cc:
                    /* Unresolved local var: ScreensPanel * this@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: ScreenListItem * item@[???]
                       Unresolved local var: wchar_t idx@[???] */
      local_68.treeSortKey = (char *)0x0;
      local_68.name = ((char *)0x1491b7 /* "New" */);
      local_68.columns = ((char *)0x1491bb /* "PID Command" */);
      local_68.sortKey = ((char *)0x14828e /* "PID" */);
      pSVar15 = Settings_newScreen(this_00,&local_68);
                    /* Unresolved local var: ScreenListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      data_ = malloc(0x28);
      if (data_ == (undefined8 *)0x0) goto LAB_00136752;
                    /* Unresolved local var: char * data@[???] */
      *data_ = &ScreenListItem_class;
      pcVar16 = strdup(((char *)0x1491b7 /* "New" */));
      if (pcVar16 == (char *)0x0) goto LAB_00136752;
      this = (super->super).items;
      data_[1] = pcVar16;
      wVar21 = (super->super).selected;
      data_[4] = pSVar15;
      *(undefined4 *)(data_ + 2) = 0;
      wVar21 = wVar21 + L'\x01';
      *(undefined1 *)((long)data_ + 0x14) = 0;
      Vector_insert(this,wVar21,data_);
                    /* Unresolved local var: wchar_t size@[???] */
      (super->super).needsRedraw = true;
      wVar10 = ((super->super).items)->items;
      wVar19 = wVar10 + L'\xffffffff';
      if (wVar10 <= wVar21) {
        wVar21 = wVar19;
      }
      if (wVar21 < L'\0') {
        wVar21 = L'\0';
      }
      pcVar4 = (super->super).super.klass[1].extends;
      (super->super).selected = wVar21;
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)((long)super,0xffffffff,(ulong)(uint)wVar19,uVar22,in_R8,(long)pVVar20);
      }
      startRenaming(super);
      pVVar20 = (super->super).items;
      wVar19 = pVVar20->items;
joined_r0x001363b3:
      if (L'\0' < wVar19) {
        bVar7 = true;
        HVar11 = HANDLED;
        wVar21 = (super->super).selected;
        goto LAB_00136068;
      }
      break;
    case L'ď':
switchD_00136039_caseD_10f:
      if (wVar9 != L'\0') goto LAB_00136233;
      break;
    case L'Đ':
switchD_00136039_caseD_110:
      Panel_moveSelectedDown(&super->super);
      goto LAB_00136528;
    case L'đ':
      break;
    case L'Ĩ':
    case L'ŗ':
      goto switchD_00136039_caseD_128;
    }
    goto switchD_00136039_caseD_111;
  }
  pOVar23 = pVVar20->array[wVar9];
  if (L'Ũ' < ch) {
    bVar7 = false;
    HVar11 = IGNORED;
    if (ch == L'ƙ') {
switchD_00135e98_caseD_128:
                    /* Unresolved local var: ListItem * item@[???] */
      _Var8 = (_Bool)(super->moving ^ 1);
      super->moving = _Var8;
      (super->super).selectionColorId = _Var8 + PANEL_SELECTION_FOCUS;
      if (pOVar23 != (Object *)0x0) {
        *(_Bool *)((long)&pOVar23[2].klass + 4) = _Var8;
      }
      bVar7 = false;
      HVar11 = HANDLED;
    }
    goto LAB_00136068;
  }
  if (ch < L'Ă') {
    if (ch < L'.') {
      if (L'\xfffffffe' < ch) {
        switch(ch) {
        default:
          goto switchD_00135ed0_caseD_0;
        case L'\n':
        case L'\r':
          goto switchD_00135e98_caseD_128;
        case L'\x0e':
          goto switchD_00135e98_caseD_10d;
        case L'\x12':
          goto switchD_00135e98_caseD_10a;
        case L'+':
          goto switchD_00135e98_caseD_110;
        case L'-':
          goto switchD_00135e98_caseD_10f;
        case L'\xffffffff':
          goto switchD_00135ed0_caseD_ffffffff;
        }
      }
      ppuVar14 = __ctype_b_loc();
      if ((*(byte *)((long)*ppuVar14 + (long)ch * 2 + 1) & 4) == 0) goto switchD_00135e98_caseD_104;
      goto LAB_00136650;
    }
    if (ch == L'[') goto joined_r0x001365f2;
    if (ch == L']') goto switchD_00135e98_caseD_110;
    if (ch < L'ÿ') goto switchD_00135ed0_caseD_0;
    goto switchD_00135e98_caseD_104;
  }
  switch(ch) {
  case L'Ă':
    if (super->moving == false) goto LAB_001364ba;
  case L'Đ':
switchD_00135e98_caseD_110:
    Panel_moveSelectedDown(&super->super);
    wVar21 = (super->super).selected;
    goto LAB_0013628b;
  case L'ă':
    goto switchD_00135e98_caseD_103;
  default:
    goto switchD_00135e98_caseD_104;
  case L'Ć':
  case L'Œ':
  case L'œ':
  case L'Ũ':
    Panel_onKey(&super->super,ch);
    wVar21 = (super->super).selected;
    goto switchD_00135e98_caseD_104;
  case L'Ċ':
switchD_00135e98_caseD_10a:
    startRenaming(super);
    if (pVVar20->items < L'\x01') goto switchD_00135ed0_caseD_ffffffff;
    bVar7 = false;
    wVar21 = (super->super).selected;
    HVar11 = HANDLED;
    break;
  case L'č':
switchD_00135e98_caseD_10d:
    this_00 = (Settings *)super->settings;
    bVar7 = false;
    HVar11 = IGNORED;
    if (this_00->dynamicScreens == (Hashtable_2 *)0x0) goto LAB_001362cc;
    break;
  case L'ď':
switchD_00135e98_caseD_10f:
joined_r0x001365f2:
    if (wVar9 != L'\0') goto LAB_00136233;
    goto LAB_0013628b;
  case L'đ':
    if (wVar19 != L'\x01') {
      Panel_remove(&super->super,wVar9);
      pVVar20 = (super->super).items;
      wVar19 = pVVar20->items;
      goto joined_r0x001363b3;
    }
LAB_0013628b:
    bVar7 = true;
    HVar11 = HANDLED;
    break;
  case L'Ĩ':
  case L'ŗ':
    goto switchD_00135e98_caseD_128;
  }
LAB_00136068:
  pOVar2 = pVVar20->array[wVar21];
  if ((pOVar2 == (Object *)0x0) || (pOVar2 == pOVar23)) {
    if (bVar7) {
      pVVar20 = (super->super).items;
      goto LAB_001363c6;
    }
LAB_00136472:
    if (HVar11 != HANDLED) goto LAB_00135dbc;
  }
  else {
                    /* Unresolved local var: Hashtable * dynamicColumns@[???] */
    columns = super->settings->dynamicColumns;
    ColumnsPanel_fill(super->columns,(ScreenSettings *)pOVar2[4].klass,columns);
    this_01 = super->availableColumns;
                    /* Unresolved local var: Panel * super@[???] */
    p_Var3 = (pOVar2[4].klass)->display;
    Vector_prune((this_01->super).items);
    (this_01->super).scrollV = L'\0';
    (this_01->super).selected = L'\0';
    (this_01->super).oldSelected = L'\0';
    (this_01->super).needsRedraw = true;
                    /* Unresolved local var: Panel * super@[???] */
                    /* Unresolved local var: size_t i@[???] */
    if ((p_Var3 == (Object_Display)0x0) &&
       (AvailableColumnsPanel_addPlatformColumns(this_01), columns->size != 0)) {
LAB_0013658a:
      uVar22 = 0;
      do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
        value = columns->buckets[uVar22].value;
        if (value != (void *)0x0) {
          AvailableColumnsPanel_addDynamicColumn(columns->buckets[uVar22].key,value,this_01);
        }
        uVar22 = uVar22 + 1;
      } while (uVar22 < columns->size);
    }
    if (bVar7) {
LAB_00136528:
      pVVar20 = (super->super).items;
switchD_00136039_caseD_111:
      HVar11 = HANDLED;
LAB_001363c6:
                    /* Unresolved local var: ScreensPanel * this@[???]
                       Unresolved local var: wchar_t n@[???] */
      wVar21 = pVVar20->items;
      uVar22 = (ulong)(wVar21 + L'\x01');
      free(super->settings->screens);
      pSVar5 = super->settings;
      if (uVar22 >> 0x3d != 0) {
LAB_00136752:
                    /* WARNING: Subroutine does not return */
        fail();
      }
                    /* Unresolved local var: void * data@[???] */
      ppSVar17 = malloc(uVar22 * 8);
      if (ppSVar17 == (ScreenSettings_3 **)0x0) goto LAB_00136752;
      pSVar5->screens = ppSVar17;
      ppSVar17[uVar22 - 1] = (ScreenSettings_3 *)0x0;
                    /* Unresolved local var: wchar_t i@[???] */
      if (L'\0' < wVar21) {
                    /* Unresolved local var: ScreenListItem * item@[???] */
        ppOVar6 = ((super->super).items)->array;
        lVar18 = 0;
        do {
          *(undefined8 *)((long)ppSVar17 + lVar18) =
               *(undefined8 *)(*(long *)((long)ppOVar6 + lVar18) + 0x20);
          lVar18 = lVar18 + 8;
        } while (uVar22 * 8 - 8 != lVar18);
      }
      pSVar5->nScreens = wVar21;
      wVar19 = L'\0';
      if (L'\xffffffff' < wVar9) {
        wVar19 = wVar9;
      }
      wVar10 = wVar21 + L'\xffffffff';
      if (wVar9 < wVar21) {
        wVar10 = wVar19;
      }
      pSVar5->ssIndex = wVar10;
      pSVar5->ss = ppSVar17[wVar10];
      goto LAB_00136472;
    }
  }
switchD_00135ed0_caseD_ffffffff:
  ScreensPanel_update(super);
LAB_00135db6:
  HVar11 = HANDLED;
LAB_00135dbc:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return HVar11;
switchD_00135e98_caseD_104:
  bVar7 = false;
  HVar11 = IGNORED;
  goto LAB_00136068;
switchD_00136039_caseD_104:
  HVar11 = IGNORED;
  goto LAB_00135dbc;
}

