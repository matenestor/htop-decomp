/* Table_prepareEntries @ 0012d220 size 60 */

/* DWARF original prototype: void Table_prepareEntries(Table * this) */

void Table_prepareEntries(Table *this)

{
  Object **ppOVar1;
  undefined1 uVar2;
  wchar_t wVar3;
  Object *pOVar4;
  Object **ppOVar5;

                    /* Unresolved local var: wchar_t i@[???] */
  wVar3 = this->rows->items;
  if (L'\0' < wVar3) {
    ppOVar5 = this->rows->array;
    ppOVar1 = ppOVar5 + wVar3;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar4 = *ppOVar5;
      ppOVar5 = ppOVar5 + 1;
      uVar2 = *(undefined1 *)((long)&pOVar4[3].klass + 6);
      *(undefined1 *)((long)&pOVar4[4].klass + 1) = 0;
      *(undefined1 *)((long)&pOVar4[3].klass + 6) = 1;
      *(undefined1 *)((long)&pOVar4[3].klass + 7) = uVar2;
    } while (ppOVar5 != ppOVar1);
  }
  return;
}

