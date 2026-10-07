/* actionExpandOrCollapse @ 00113c90 size 64 */

Htop_Reaction actionExpandOrCollapse(State_2 *st)

{
  Vector *pVVar1;
  Object *pOVar2;

  if (st->host->settings->ss->treeView != false) {
                    /* Unresolved local var: Row * row@[???] */
    pVVar1 = (st->mainPanel->super).items;
    if ((L'\0' < pVVar1->items) &&
       (pOVar2 = pVVar1->array[(st->mainPanel->super).selected], pOVar2 != (Object *)0x0)) {
      pOVar2 = pOVar2 + 4;
      *(byte *)&pOVar2->klass = *(byte *)&pOVar2->klass ^ 1;
      return HTOP_RECALCULATE;
    }
  }
  return HTOP_OK;
}

