/* actionPrevScreen @ 00113e50 size 162 */

Htop_Reaction actionPrevScreen(State_2 *st)

{
  uint uVar1;
  Machine *pMVar2;
  Settings__2 *pSVar3;
  ScreenSettings_2 *pSVar4;
  Table_ *pTVar5;
  _Bool _Var6;
  MainPanel__2 *pMVar7;
  FunctionBar *pFVar8;

  pMVar2 = st->host;
  pSVar3 = pMVar2->settings;
  uVar1 = pSVar3->ssIndex;
  if (uVar1 == 0) {
    uVar1 = pSVar3->nScreens;
  }
                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: _Bool readonly@[???] */
  pSVar3->ssIndex = uVar1 - 1;
  _Var6 = readonly;
  pSVar4 = pSVar3->screens[uVar1 - 1];
  pSVar3->ss = pSVar4;
  pTVar5 = pSVar4->table;
  if (pTVar5 == (Table_ *)0x0) {
    pTVar5 = pMVar2->processTable;
    pSVar4->table = pTVar5;
    pMVar2->activeTable = pTVar5;
    if (_Var6 == false) {
      pMVar7 = st->mainPanel;
      pFVar8 = pMVar7->processBar;
      goto LAB_00113ea0;
    }
  }
  else {
    pMVar2->activeTable = pTVar5;
    if ((_Var6 == false) && (pTVar5 == pMVar2->processTable)) {
      pMVar7 = st->mainPanel;
      pFVar8 = pMVar7->processBar;
      goto LAB_00113ea0;
    }
  }
  pMVar7 = st->mainPanel;
  pFVar8 = pMVar7->readonlyBar;
LAB_00113ea0:
  (pMVar7->super).defaultBar = pFVar8;
  pMVar7->inc->defaultBar = pFVar8;
  return 0x61;
}

