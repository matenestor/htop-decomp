/* actionCollapseIntoParent @ 00113ce0 size 140 */

Htop_Reaction actionCollapseIntoParent(State_2 *st)

{
  wchar_t wVar1;
  MainPanel__2 *a0;
  Vector *pVVar2;
  Object **ppOVar3;
  Object *pOVar4;
  code *pcVar5;
  long lVar6;
  int iVar7;
  long in_R9;

  if (st->host->settings->ss->treeView != false) {
    a0 = st->mainPanel;
                    /* Unresolved local var: Row * r@[???]
                       Unresolved local var: wchar_t parent_id@[???] */
    pVVar2 = (a0->super).items;
    wVar1 = pVVar2->items;
    if (L'\0' < wVar1) {
      ppOVar3 = pVVar2->array;
      pOVar4 = ppOVar3[(a0->super).selected];
      if (pOVar4 != (Object *)0x0) {
        iVar7 = *(int *)((long)&pOVar4[2].klass + 4);
        if (iVar7 == *(int *)&pOVar4[2].klass) {
          iVar7 = *(int *)&pOVar4[3].klass;
        }
                    /* Unresolved local var: wchar_t i@[???] */
        lVar6 = 0;
                    /* Unresolved local var: Row * row@[???] */
        while (pOVar4 = ppOVar3[lVar6], *(int *)&pOVar4[2].klass != iVar7) {
          lVar6 = lVar6 + 1;
          if (lVar6 == wVar1) {
            return HTOP_OK;
          }
        }
        *(undefined1 *)&pOVar4[4].klass = 0;
                    /* Unresolved local var: wchar_t size@[???] */
        (a0->super).selected = (wchar_t)lVar6;
        pcVar5 = (a0->super).super.klass[1].extends;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)((long)a0,0xffffffff,(long)pOVar4,(long)wVar1,(long)a0,in_R9);
          return HTOP_RECALCULATE;
        }
        return HTOP_RECALCULATE;
      }
    }
  }
  return HTOP_OK;
}

