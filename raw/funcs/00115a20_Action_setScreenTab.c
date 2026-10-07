/* Action_setScreenTab @ 00115a20 size 296 */

Htop_Reaction Action_setScreenTab(State_2 *st,wchar_t x)

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
  wchar_t wVar11;
  uint uVar12;

  pMVar2 = st->host;
  pSVar3 = pMVar2->settings;
                    /* Unresolved local var: uint i@[???] */
  uVar1 = pSVar3->nScreens;
                    /* Unresolved local var: char * tab@[???]
                       Unresolved local var: wchar_t len@[???] */
  if ((uVar1 != 0) && (L'\x01' < x)) {
    ppSVar10 = pSVar3->screens;
    uVar12 = 0;
    wVar11 = L'\x02';
    do {
      pSVar4 = *ppSVar10;
      sVar7 = strlen(pSVar4->heading);
      _Var6 = readonly;
      if (x <= wVar11 + L'\x01' + (int)sVar7) {
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
      wVar11 = wVar11 + L'\x03' + (int)sVar7;
      uVar12 = uVar12 + 1;
      ppSVar10 = ppSVar10 + 1;
    } while ((uVar12 < uVar1) && (wVar11 <= x));
  }
  return HTOP_OK;
}

