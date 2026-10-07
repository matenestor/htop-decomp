/* actionUntagAll @ 00113fe0 size 54 */

Htop_Reaction actionUntagAll(State_2 *st)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Vector *pVVar3;
  Object *pOVar4;
  Object **ppOVar5;

                    /* Unresolved local var: wchar_t i@[???] */
  pVVar3 = (st->mainPanel->super).items;
  wVar2 = pVVar3->items;
  if (L'\0' < wVar2) {
    ppOVar5 = pVVar3->array;
    ppOVar1 = ppOVar5 + wVar2;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar4 = *ppOVar5;
      ppOVar5 = ppOVar5 + 1;
      *(undefined1 *)((long)&pOVar4[3].klass + 5) = 0;
    } while (ppOVar5 != ppOVar1);
  }
  return HTOP_REFRESH;
}

