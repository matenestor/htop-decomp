/* Action_setSortKey @ 00115940 size 86 */

Htop_Reaction Action_setSortKey(Settings_2 *settings,ProcessField sortKey)

{
  _Bool _Var1;
  ScreenSettings_2 *pSVar2;

  pSVar2 = settings->ss;
  _Var1 = Process_fields[sortKey].defaultSortDesc;
  if ((pSVar2->treeViewAlwaysByPID == false) && (pSVar2->treeView != false)) {
    pSVar2->treeSortKey = sortKey;
    pSVar2->treeDirection = (-(uint)(_Var1 == false) & 2) + L'\xffffffff';
    return 0x4d;
  }
  pSVar2->sortKey = sortKey;
  pSVar2->treeView = false;
  pSVar2->direction = (-(uint)(_Var1 == false) & 2) + L'\xffffffff';
  return 0x4d;
}

