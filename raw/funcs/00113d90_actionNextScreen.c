/* actionNextScreen @ 00113d90 size 167 */

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

