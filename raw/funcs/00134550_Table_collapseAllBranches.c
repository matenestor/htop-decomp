/* Table_collapseAllBranches @ 00134550 size 83 */

/* DWARF original prototype: void Table_collapseAllBranches(Table * this) */

void Table_collapseAllBranches(Table *this)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Object *pOVar3;
  Object **ppOVar4;

  Table_buildTree(this);
  this->needsSort = true;
  wVar2 = this->rows->items;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < wVar2) {
    ppOVar4 = this->rows->array;
    ppOVar1 = ppOVar4 + wVar2;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar3 = *ppOVar4;
      if ((*(int *)&pOVar3[5].klass != 0) && (1 < *(int *)&pOVar3[2].klass)) {
        *(undefined1 *)&pOVar3[4].klass = 0;
      }
      ppOVar4 = ppOVar4 + 1;
    } while (ppOVar4 != ppOVar1);
  }
  return;
}

