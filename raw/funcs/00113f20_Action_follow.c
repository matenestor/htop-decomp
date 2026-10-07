/* Action_follow @ 00113f20 size 72 */

Htop_Reaction Action_follow(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Vector *pVVar2;
  Object *pOVar3;
  wchar_t wVar4;

  pMVar1 = st->mainPanel;
                    /* Unresolved local var: Row * row@[???] */
  pVVar2 = (pMVar1->super).items;
  wVar4 = L'\xffffffff';
  if ((L'\0' < pVVar2->items) &&
     (pOVar3 = pVVar2->array[(pMVar1->super).selected], pOVar3 != (Object *)0x0)) {
    wVar4 = *(wchar_t *)&pOVar3[2].klass;
  }
  st->host->activeTable->following = wVar4;
  (pMVar1->super).selectionColorId = PANEL_SELECTION_FOLLOW;
  return HTOP_KEEP_FOLLOWING;
}

