/* Table_expandTree @ 0012e2a0 size 49 */

/* DWARF original prototype: void Table_expandTree(Table * this) */

void Table_expandTree(Table *this)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Object *pOVar3;
  Object **ppOVar4;

  wVar2 = this->rows->items;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < wVar2) {
    ppOVar4 = this->rows->array;
    ppOVar1 = ppOVar4 + wVar2;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar3 = *ppOVar4;
      ppOVar4 = ppOVar4 + 1;
      *(undefined1 *)&pOVar3[4].klass = 1;
    } while (ppOVar4 != ppOVar1);
  }
  return;
}

