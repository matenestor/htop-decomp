/* tagAllChildren @ 001139b0 size 95 */

void tagAllChildren(Panel *panel,Row *parent)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Vector *pVVar3;
  Row *parent_00;
  wchar_t wVar4;
  Object **ppOVar5;

                    /* Unresolved local var: wchar_t parent_id@[???]
                       Unresolved local var: wchar_t i@[???] */
  pVVar3 = panel->items;
  parent->tag = true;
  wVar4 = pVVar3->items;
  if (L'\0' < wVar4) {
    ppOVar5 = pVVar3->array;
    wVar2 = parent->id;
    ppOVar1 = ppOVar5 + wVar4;
    do {
                    /* Unresolved local var: Row * row@[???] */
      parent_00 = (Row *)*ppOVar5;
      if (parent_00->tag == false) {
        wVar4 = parent_00->group;
        if (wVar4 == parent_00->id) {
          wVar4 = parent_00->parent;
        }
        if (wVar2 == wVar4) {
          tagAllChildren(panel,parent_00);
        }
      }
      ppOVar5 = ppOVar5 + 1;
    } while (ppOVar1 != ppOVar5);
    return;
  }
  return;
}

