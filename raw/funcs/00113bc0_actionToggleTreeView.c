/* actionToggleTreeView @ 00113bc0 size 91 */

Htop_Reaction actionToggleTreeView(State_2 *st)

{
  _Bool *p_Var1;
  Object **ppOVar2;
  wchar_t wVar3;
  Table *pTVar4;
  ScreenSettings_2 *pSVar5;
  Object *pOVar6;
  Object **ppOVar7;

  pTVar4 = st->host->activeTable;
  pSVar5 = st->host->settings->ss;
  p_Var1 = &pSVar5->treeView;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  if (pSVar5->allBranchesCollapsed == false) {
                    /* Unresolved local var: wchar_t size@[???] */
    wVar3 = pTVar4->rows->items;
                    /* Unresolved local var: wchar_t i@[???] */
    if (L'\0' < wVar3) {
      ppOVar7 = pTVar4->rows->array;
      ppOVar2 = ppOVar7 + wVar3;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pOVar6 = *ppOVar7;
        ppOVar7 = ppOVar7 + 1;
        *(undefined1 *)&pOVar6[4].klass = 1;
      } while (ppOVar7 != ppOVar2);
      pTVar4->needsSort = true;
      return 0x6d;
    }
  }
  pTVar4->needsSort = true;
  return 0x6d;
}

