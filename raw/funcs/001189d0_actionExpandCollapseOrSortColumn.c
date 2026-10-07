/* actionExpandCollapseOrSortColumn @ 001189d0 size 69 */

Htop_Reaction actionExpandCollapseOrSortColumn(State_2 *st)

{
  Vector *pVVar1;
  Object *pOVar2;
  Htop_Reaction HVar3;

  if (st->host->settings->ss->treeView == false) {
    HVar3 = actionSetSortColumn(st);
    return HVar3;
  }
                    /* Unresolved local var: _Bool changed@[???] */
                    /* Unresolved local var: Row * row@[???] */
  pVVar1 = (st->mainPanel->super).items;
  if ((L'\0' < pVVar1->items) &&
     (pOVar2 = pVVar1->array[(st->mainPanel->super).selected], pOVar2 != (Object *)0x0)) {
    pOVar2 = pOVar2 + 4;
    *(byte *)&pOVar2->klass = *(byte *)&pOVar2->klass ^ 1;
    return HTOP_RECALCULATE;
  }
  return HTOP_OK;
}

