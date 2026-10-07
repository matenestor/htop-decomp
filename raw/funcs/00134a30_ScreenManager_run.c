/* ScreenManager_run @ 00134a30 size 2438 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void ScreenManager_run(ScreenManager * this, Panel * * lastFocus,
   wchar_t * lastKey, char * name) */

void ScreenManager_run(ScreenManager *this,Panel **lastFocus,wchar_t *lastKey,char *name)

{
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
  wchar_t wVar14;
  uint uVar15;
  ulong uVar16;
  Object **ppOVar17;
  void *pvVar18;
  wchar_t wVar19;
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
  long in_FS_OFFSET;
  bool bVar24;
  int local_94;
  double local_90;
  Panel *local_88;
  wchar_t local_80;
  uint local_78;
  uint local_74;
  double local_70;
  wchar_t y;
  wchar_t x;
  wchar_t local_54;
  wchar_t local_50;
  uint local_48;
  long local_40;

  cVar23 = '\x01';
                    /* Unresolved local var: wchar_t prevCh@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: double newTime@[???] */
  uVar21 = 1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  bVar10 = true;
  local_90 = 0.0;
  bVar11 = false;
  local_78 = 0;
  local_94 = 0;
  local_80 = L'\xffffffff';
  local_74 = 0;
  local_88 = (Panel *)*this->panels->array;
  pSVar2 = this->host->settings;
  this->name = name;
LAB_00134ac3:
  if (this->header == (Header_2 *)0x0) goto LAB_00134d68;
LAB_00134acf:
  super = (LinuxMachine_ *)this->host;
  Generic_gettime_realtime(&(super->super).realtime,&(super->super).realtimeMs);
  wVar14 = Row_uidDigits;
  pSVar3 = (super->super).settings;
  local_70 = (double)(super->super).realtime.tv_sec * 10.0 +
             (double)(super->super).realtime.tv_usec / 100000.0;
  bVar10 = (double)pSVar3->delay < local_70 - local_90;
  if (((local_70 < local_90) || (bVar10)) || (bVar11)) {
                    /* Unresolved local var: wchar_t oldUidDigits@[???] */
    name = (char *)this->state;
    if (((char)((Panel *)name)->cursorX == '\0') &&
       ((in_R9 = (ulong)local_78, local_78 == 0 || (pSVar3->ss->treeView != false)))) {
      local_78 = 1;
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
    local_70 = local_90;
  }
  Table_rebuildPanel((Table *)(super->super).activeTable);
  if (this->state->hideMeters == false) {
    Header_draw((Header *)this->header);
  }
  local_90 = local_70;
  bVar11 = false;
LAB_00134b63:
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: wchar_t nPanels@[???] */
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
                       Unresolved local var: wchar_t cur@[???]
                       Unresolved local var: wchar_t l@[???]
                       Unresolved local var: Panel * panel@[???] */
    ppSVar7 = pSVar4->screens;
    uVar15 = pSVar4->ssIndex;
    x = L'\x02';
    y = *(int *)((long)&(*this->panels->array)[1].klass + 4) + L'\xffffffff';
    name = this->name;
    if ((Panel *)name == (Panel *)0x0) {
      lVar22 = 0;
                    /* Unresolved local var: wchar_t s@[???] */
      pSVar8 = *ppSVar7;
      name = (char *)pPVar9;
      while (pSVar8 != (ScreenSettings_2 *)0x0) {
                    /* Unresolved local var: _Bool ok@[???] */
        bVar24 = uVar15 == (uint)lVar22;
        name = pSVar8->heading;
        in_R8 = (Object **)(ulong)bVar24;
        _Var12 = drawTab(&y,&x,wVar14,name,bVar24);
        if (!_Var12) break;
        lVar22 = lVar22 + 1;
        pSVar8 = ppSVar7[lVar22];
      }
      wattrset(_stdscr,*CRT_colors);
    }
    else {
      in_R8 = (Object **)0x1;
      drawTab(&y,&x,wVar14,name,true);
    }
  }
  wVar14 = this->panelCount;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < wVar14) {
                    /* Unresolved local var: Panel * panel@[???] */
    lVar22 = 0;
    do {
                    /* Unresolved local var: Settings * settings@[???] */
      in_R8 = (Object **)0x1;
      this_00 = (MainPanel__2 *)this->panels->array[lVar22];
      pSVar5 = this->state;
      wVar19 = pSVar5->host->settings->hideFunctionBar;
      if ((wVar19 != L'\x02') && (in_R8 = (Object **)0x0, wVar19 == L'\x01')) {
        in_R8 = (Object **)(ulong)pSVar5->hideSelection;
      }
      name = (char *)0x1;
      if (this_00 == pSVar5->mainPanel) {
        name = (char *)(ulong)(pSVar5->hideSelection ^ 1);
      }
      Panel_draw((Panel *)this_00,SUB41(uVar21,0),local_74 == (uint)lVar22,SUB81(name,0),
                 SUB81(in_R8,0));
      iVar13 = wmove(_stdscr,(this_00->super).y,(this_00->super).w + (this_00->super).x);
      if (iVar13 != -1) {
        name = (char *)this->state;
                    /* Unresolved local var: Settings * settings@[???] */
        wVar19 = (this_00->super).h;
        iVar13 = *(int *)((long)((((Panel *)name)->super).klass)->extends + 0x70);
        if (iVar13 == 2) {
          wVar19 = wVar19 + L'\x01';
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
      *lastFocus = local_88;
    }
    if (lastKey != (wchar_t *)0x0) {
      *lastKey = local_80;
    }
    if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
LAB_00134c80:
  wVar14 = Panel_getCh(local_88);
  a1 = (ulong)(uint)wVar14;
  pvVar20 = extraout_RDX;
  if (wVar14 == L'ƙ') {
    if (pSVar2->enableMouse == false) goto LAB_00134cd8;
                    /* Unresolved local var: wchar_t ok@[???] */
    iVar13 = getmouse(&x);
    if (iVar13 == 0) {
      if ((local_48 & 1) == 0) {
        pvVar20 = extraout_RDX_00;
        if ((local_48 & 0x10000) == 0) {
          a1 = 0x127;
          if ((local_48 & 0x200000) == 0) goto LAB_00134e75;
        }
        else {
          a1 = 0x126;
        }
        goto LAB_00134cd8;
      }
      if (local_50 == _LINES + L'\xffffffff') {
        wVar14 = FunctionBar_synthesizeEvent(local_88->currentBar,local_54);
        a1 = (ulong)(uint)wVar14;
        pvVar20 = extraout_RDX_01;
        goto LAB_00134c97;
      }
                    /* Unresolved local var: wchar_t i@[???] */
      if (L'\0' < this->panelCount) {
                    /* Unresolved local var: Panel * panel@[???] */
        name = (char *)(ulong)(uint)local_54;
        in_R8 = this->panels->array;
        lVar22 = 0;
        do {
          pPVar9 = (Panel *)in_R8[lVar22];
          wVar14 = pPVar9->x;
          pvVar20 = (void *)(ulong)(uint)wVar14;
          if ((wVar14 <= local_54) &&
             (wVar19 = pPVar9->w + wVar14, in_R9 = (ulong)(uint)wVar19, local_54 <= wVar19)) {
            wVar19 = pPVar9->y;
            if (local_50 == wVar19) {
              name = (char *)(ulong)(uint)(local_54 - wVar14);
              a1 = (ulong)(uint)((local_54 - wVar14) - 10000);
              goto LAB_00134c97;
            }
            if ((pSVar2->screenTabs != false) &&
               (pvVar20 = (void *)(ulong)(uint)(wVar19 + L'\xffffffff'),
               local_50 == wVar19 + L'\xffffffff')) {
              a1 = (ulong)(uint)(local_54 + L'\xffffb1e0');
              goto LAB_00134c97;
            }
            if ((wVar19 < local_50) &&
               (wVar14 = pPVar9->h + wVar19, pvVar20 = (void *)(ulong)(uint)wVar14,
               local_50 <= wVar14)) goto LAB_00135370;
          }
          lVar22 = lVar22 + 1;
          if (lVar22 == this->panelCount) break;
        } while( true );
      }
    }
LAB_00134e75:
    local_78 = local_78 - (0 < (int)local_78);
    if (local_80 != L'\xffffffff') {
      local_94 = 0;
      cVar23 = '\0';
      uVar21 = 0;
      local_80 = L'\xffffffff';
      goto LAB_00134ac3;
    }
    if (bVar10) {
      local_94 = 0;
      cVar23 = '\0';
      uVar21 = 0;
    }
    else {
      local_94 = local_94 + 1;
      if (local_94 == 100) goto LAB_00134eb5;
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
  if ((pPVar9 == local_88) || (this->allowFocusChange != false)) {
                    /* Unresolved local var: Object * oldSelection@[???] */
    name = (char *)pPVar9->items;
    pvVar20 = (void *)0x0;
    wVar14 = ((Panel *)name)->cursorX;
    if (L'\0' < wVar14) {
      pvVar20 = (&((((Panel *)name)->super).klass)->extends)[pPVar9->selected];
    }
                    /* Unresolved local var: wchar_t size@[???] */
    wVar19 = (local_50 - wVar19) + pPVar9->scrollV + L'\xffffffff';
    if (wVar14 <= wVar19) {
      wVar19 = wVar14 + L'\xffffffff';
    }
    if (wVar19 < L'\0') {
      wVar19 = L'\0';
    }
    pPVar9->selected = wVar19;
    pcVar6 = (pPVar9->super).klass[1].extends;
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)((long)pPVar9,0xffffffff,(long)pvVar20,(long)name,(long)in_R8,in_R9);
      name = (char *)pPVar9->items;
      wVar14 = ((Panel *)name)->cursorX;
    }
    pvVar18 = (void *)0x0;
    if (L'\0' < wVar14) {
      pvVar18 = (&((((Panel *)name)->super).klass)->extends)[pPVar9->selected];
    }
    local_74 = (uint)lVar22;
    local_88 = pPVar9;
    if (pvVar18 == pvVar20) {
      a1 = 0x128;
    }
  }
LAB_00134cd8:
  pcVar6 = (local_88->super).klass[1].extends;
  if (pcVar6 == (code *)0x0) {
    uVar21 = 0;
  }
  else {
    uVar16 = (*pcVar6)((long)local_88,a1,(long)pvVar20,(long)name,(long)in_R8,in_R9);
    if ((uVar16 & 0x80) != 0) {
      a1 = uVar16 >> 0x10 & 0xffff;
    }
    local_80 = (wchar_t)a1;
    uVar15 = 0;
    if ((uVar16 & 8) == 0) {
      uVar15 = local_78;
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
    local_78 = 0;
    if (!bVar24) {
      local_78 = uVar15;
    }
    if ((uVar16 & 1) != 0) goto LAB_00134d4d;
    if ((uVar16 & 4) != 0) goto switchD_00134fea_caseD_1b;
  }
  local_80 = (wchar_t)a1;
  if (local_80 == L'q') {
switchD_00134fea_caseD_1b:
    goto LAB_00134eb5;
  }
  if (L'q' < local_80) {
    if (local_80 == L'Ē') goto switchD_00134fea_caseD_1b;
    if (L'Ē' < local_80) {
      if (local_80 == L'ƚ') {
        cVar23 = '\x01';
        ScreenManager_resize(this);
        local_80 = L'ƚ';
        goto LAB_00134ac3;
      }
      goto switchD_00134fea_caseD_3;
    }
    if (local_80 != L'Ą') {
      if (local_80 != L'ą') goto switchD_00134fea_caseD_3;
      goto switchD_00134fea_caseD_6;
    }
switchD_00134fea_caseD_2:
    if (this->panelCount < L'\x02') {
switchD_00134fea_caseD_3:
      cVar23 = '\x01';
      Panel_onKey(local_88,local_80);
      local_78 = 5;
      goto LAB_00134ac3;
    }
    cVar23 = this->allowFocusChange;
    if ((_Bool)cVar23 != false) {
      ppOVar17 = this->panels->array + (int)local_74;
      if (0 < (int)local_74) goto LAB_0013530c;
      local_88 = (Panel *)*ppOVar17;
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
    if (this->panelCount < L'\x02') goto switchD_00134fea_caseD_3;
    cVar23 = this->allowFocusChange;
    if ((_Bool)cVar23 != false) {
      iVar13 = this->panelCount + L'\xffffffff';
      name = (char *)this->panels->array;
      lVar22 = (long)((((Panel *)name)->header).chstr + -4) + (long)(int)local_74 * 8;
      if ((int)local_74 < iVar13) {
        name = (char *)(ulong)local_74;
        break;
      }
      local_88 = *(Panel **)((long)((((Panel *)name)->header).chstr + -4) + (long)(int)local_74 * 8)
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
  while ((int)local_74 < iVar13) {
    local_88 = *(Panel **)(lVar22 + 8);
    local_74 = (int)name + 1;
    name = (char *)(ulong)local_74;
    lVar22 = lVar22 + 8;
    if (local_88->items->items != L'\0') break;
  }
  goto LAB_00134ac3;
  while (0 < (int)local_74) {
LAB_0013530c:
    name = (char *)ppOVar17[-1];
    local_74 = local_74 - 1;
    ppOVar17 = ppOVar17 + -1;
    wVar14 = ((Panel *)name)->items->items;
    in_R8 = (Object **)(ulong)(uint)wVar14;
    local_88 = (Panel *)name;
    if (wVar14 != L'\0') break;
  }
  goto LAB_00134ac3;
code_r0x00134d71:
  pSVar4 = this->host->settings;
  cVar23 = pSVar4->screenTabs;
  pPVar9 = (Panel *)name;
  wVar14 = _COLS;
  goto joined_r0x00134b6f;
}

