/* actionKill @ 0011a000 size 733 */

/* WARNING: Removing unreachable block (ram,0x0011a109) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x0011a126 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Htop_Reaction actionKill(State_2 *st)

{
  char cVar1;
  wchar_t wVar2;
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
  long in_FS_OFFSET;
  cchar_t local_a8;
  undefined1 *local_78;
  MainPanel__2 *local_70;
  wchar_t *local_68;
  attr_t local_5c;
  cchar_t *local_58;
  MainPanel__2 *local_50;
  long local_40;

  cVar14 = readonly;
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ppuVar11 = &local_78;
  HVar5 = HTOP_OK;
  if ((!readonly) &&
     (ppuVar11 = &local_78, HVar5 = HTOP_OK, st->host->settings->ss->dynamic == (char *)0x0)) {
                    /* Unresolved local var: Panel * signalsPanel@[???]
                       Unresolved local var: ListItem * sgn@[???] */
    list = (MainPanel_ *)SignalsPanel_new(preSelectedSignal);
    pOVar7 = Action_pickFromVector(st,list,L'\x0e',true);
    ppuVar11 = &local_78;
    if ((pOVar7 != (Object *)0x0) && (ppuVar11 = &local_78, *(wchar_t *)&pOVar7[2].klass != L'\0'))
    {
                    /* Unresolved local var: _Bool ok@[???] */
      local_70 = st->mainPanel;
                    /* Unresolved local var: wchar_t[52958] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
      local_78 = (undefined1 *)&local_78;
      wVar2 = CRT_colors[7];
      local_58 = &local_a8;
      preSelectedSignal = *(wchar_t *)&pOVar7[2].klass;
      local_78 = (undefined1 *)&local_78;
      pMVar8 = (MainPanel__2 *)mbstowcs((wchar_t *)&local_a8,((char *)0x1473cb /* "Sending..." */),10);
      if (L'\0' < (wchar_t)pMVar8) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
        local_50 = pMVar8;
        RichString_setLen(&(local_70->super).header,(wchar_t)pMVar8);
        pcVar10 = (local_70->super).header.chptr;
        local_68 = local_58->chars + ((int)local_50 - 1);
        pcVar13 = local_58;
        local_5c = wVar2 & 0xffffff;
        do {
          local_50 = (MainPanel__2 *)CONCAT44(local_50._4_4_,pcVar13->attr);
          local_58 = pcVar10;
          iVar6 = iswprint(pcVar13->attr);
          wVar2 = (wchar_t)local_50;
          if (iVar6 == 0) {
            wVar2 = L'�';
          }
          local_58->attr = 0;
          local_58->chars[0] = L'\0';
          local_58->chars[1] = L'\0';
          local_58->chars[2] = L'\0';
          pcVar13 = (cchar_t *)pcVar13->chars;
          *(undefined1 (*) [16])(local_58->chars + 2) = (undefined1  [16])0x0;
          pcVar10 = local_58 + 1;
          local_58->attr = local_5c;
          local_58->chars[0] = wVar2;
        } while ((cchar_t *)local_68 != pcVar13);
      }
      ppuVar11 = (undefined1 **)local_78;
                    /* Unresolved local var: Settings * settings@[???] */
      hideFunctionBar = true;
      (local_70->super).needsRedraw = true;
      wVar2 = st->host->settings->hideFunctionBar;
      if ((wVar2 != L'\x02') && (hideFunctionBar = false, wVar2 == L'\x01')) {
        hideFunctionBar = st->hideSelection;
      }
      pMVar8 = st->mainPanel;
      *(undefined8 *)(local_78 + -8) = 0x11a217;
      Panel_draw(&pMVar8->super,false,true,true,hideFunctionBar);
      *(undefined8 *)((long)ppuVar11 + -8) = 0x11a226;
      wrefresh(_stdscr);
      local_58 = (cchar_t *)CONCAT44(local_58._4_4_,*(undefined4 *)&pOVar7[2].klass);
      local_50 = st->mainPanel;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: wchar_t i@[???] */
      pVVar9 = (local_50->super).items;
      if (L'\0' < pVVar9->items) {
        lVar12 = 0;
        bVar4 = true;
        do {
                    /* Unresolved local var: Row * row@[???] */
          cVar1 = *(char *)((long)&pVVar9->array[lVar12][3].klass + 5);
          if (cVar1 != '\0') {
                    /* Unresolved local var: Process * this@[???] */
            _Var3 = *(__pid_t *)&pVVar9->array[lVar12][2].klass;
            iVar6 = (int)local_58;
            *(undefined8 *)((long)ppuVar11 + -8) = 0x11a26f;
            iVar6 = kill(_Var3,iVar6);
            bVar4 = (bool)(bVar4 & iVar6 == 0);
            pVVar9 = (local_50->super).items;
            cVar14 = cVar1;
          }
          lVar12 = lVar12 + 1;
        } while ((wchar_t)lVar12 < pVVar9->items);
                    /* Unresolved local var: Row * row@[???] */
        if (((cVar14 != '\x01') && (L'\0' < pVVar9->items)) &&
           (pVVar9->array[(local_50->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * this@[???] */
          _Var3 = *(__pid_t *)&pVVar9->array[(local_50->super).selected][2].klass;
          iVar6 = (int)local_58;
          *(undefined8 *)((long)ppuVar11 + -8) = 0x11a2df;
          iVar6 = kill(_Var3,iVar6);
          bVar4 = (bool)(bVar4 & iVar6 == 0);
        }
        if (!bVar4) {
          *(undefined8 *)((long)ppuVar11 + -8) = 0x11a29f;
          beep();
        }
      }
      *(undefined8 *)((long)ppuVar11 + -8) = 0x11a2a9;
      napms(500);
    }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
    __ptr = (list->super).eventHandlerState;
    *(undefined8 *)((long)ppuVar11 + -8) = 0x11a0ab;
    free(__ptr);
    pVVar9 = (list->super).items;
    *(undefined8 *)((long)ppuVar11 + -8) = 0x11a0b4;
    Vector_delete(pVVar9);
    this = (list->super).defaultBar;
    *(undefined8 *)((long)ppuVar11 + -8) = 0x11a0bd;
    FunctionBar_delete(this);
    if (L'Ş' < (list->super).header.chlen) {
      pcVar10 = (list->super).header.chptr;
      *(undefined8 *)((long)ppuVar11 + -8) = 0x11a2b9;
      free(pcVar10);
    }
    *(undefined8 *)((long)ppuVar11 + -8) = 0x11a0d2;
    free(list);
    HVar5 = 0x61;
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)((long)ppuVar11 + -8) = &UNK_0011a2ee;
    __stack_chk_fail();
  }
  return HVar5;
}

