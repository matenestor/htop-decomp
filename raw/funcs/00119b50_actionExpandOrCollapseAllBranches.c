/* actionExpandOrCollapseAllBranches @ 00119b50 size 109 */

Htop_Reaction actionExpandOrCollapseAllBranches(State_2 *st)

{
  Object **ppOVar1;
  wchar_t wVar2;
  ScreenSettings_2 *pSVar3;
  Table *this;
  Vector *pVVar4;
  Object *pOVar5;
  Object **ppOVar6;
  _Bool _Var7;

  pSVar3 = st->host->settings->ss;
  if (pSVar3->treeView == false) {
    return HTOP_OK;
  }
  this = st->host->activeTable;
  _Var7 = (_Bool)(pSVar3->allBranchesCollapsed ^ 1);
  pSVar3->allBranchesCollapsed = _Var7;
  if (_Var7 == false) {
                    /* Unresolved local var: wchar_t size@[???] */
    pVVar4 = this->rows;
    wVar2 = pVVar4->items;
                    /* Unresolved local var: wchar_t i@[???] */
    if (L'\0' < wVar2) {
      ppOVar6 = pVVar4->array;
      ppOVar1 = ppOVar6 + wVar2;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pOVar5 = *ppOVar6;
        ppOVar6 = ppOVar6 + 1;
        *(undefined1 *)&pOVar5[4].klass = 1;
      } while (ppOVar6 != ppOVar1);
    }
    return HTOP_SAVE_SETTINGS|HTOP_REFRESH;
  }
  Table_collapseAllBranches(this);
  return HTOP_SAVE_SETTINGS|HTOP_REFRESH;
}

