/* actionSortByTime @ 00113b10 size 70 */

Htop_Reaction actionSortByTime(State_2 *st)

{
  ScreenSettings_2 *pSVar1;

  pSVar1 = st->host->settings->ss;
  if ((pSVar1->treeViewAlwaysByPID == false) && (pSVar1->treeView != false)) {
    pSVar1->treeSortKey = 0x32;
    pSVar1->treeDirection = L'\xffffffff';
    return 0x4d;
  }
  pSVar1->sortKey = 0x32;
  pSVar1->direction = L'\xffffffff';
  pSVar1->treeView = false;
  return 0x4d;
}

