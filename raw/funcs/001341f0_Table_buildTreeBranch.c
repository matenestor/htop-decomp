/* Table_buildTreeBranch @ 001341f0 size 421 */

/* DWARF original prototype: void Table_buildTreeBranch(Table * this, wchar_t rowid, uint level,
   int32_t indent, _Bool show) */

void Table_buildTreeBranch(Table *this,wchar_t rowid,uint level,int32_t indent,_Bool show)

{
  wchar_t wVar1;
  Object *pOVar2;
  void *data_;
  wchar_t wVar3;
  uint uVar4;
  uint uVar5;
  Vector *pVVar6;
  wchar_t wVar7;
  long lVar8;
  wchar_t wVar9;
  undefined1 show_00;
  uint indent_00;
  Object **ppOVar10;
  wchar_t wVar11;

                    /* Unresolved local var: wchar_t vsize@[???]
                       Unresolved local var: wchar_t l@[???]
                       Unresolved local var: wchar_t r@[???]
                       Unresolved local var: wchar_t lastShown@[???] */
  if (rowid == L'\0') {
    return;
  }
  wVar11 = L'\0';
  pVVar6 = this->rows;
  wVar1 = pVVar6->items;
  wVar3 = wVar1;
  while (wVar7 = wVar3, wVar11 < wVar7) {
    while( true ) {
                    /* Unresolved local var: wchar_t c@[???]
                       Unresolved local var: Row * row@[???]
                       Unresolved local var: wchar_t parent@[???] */
      wVar3 = (wVar11 + wVar7) / 2;
      pOVar2 = pVVar6->array[wVar3];
      wVar9 = L'\0';
      if ((*(char *)((long)&pOVar2[3].klass + 4) == '\0') &&
         (wVar9 = *(wchar_t *)((long)&pOVar2[2].klass + 4), wVar9 == *(wchar_t *)&pOVar2[2].klass))
      {
        wVar9 = *(wchar_t *)&pOVar2[3].klass;
      }
      if (rowid <= wVar9) break;
      wVar11 = wVar3 + L'\x01';
      if (wVar7 <= wVar11) goto LAB_00134269;
    }
  }
LAB_00134269:
  if (wVar7 < wVar1) {
                    /* Unresolved local var: Row * row@[???] */
    ppOVar10 = pVVar6->array + wVar7;
    wVar3 = wVar7;
    do {
      pOVar2 = *ppOVar10;
      wVar9 = *(wchar_t *)((long)&pOVar2[2].klass + 4);
      if (wVar9 == *(wchar_t *)&pOVar2[2].klass) {
        wVar9 = *(wchar_t *)&pOVar2[3].klass;
      }
      if (rowid != wVar9) break;
      if (*(char *)((long)&pOVar2[3].klass + 6) != '\0') {
        wVar7 = wVar3;
      }
      wVar3 = wVar3 + L'\x01';
      ppOVar10 = ppOVar10 + 1;
    } while (wVar3 != wVar1);
                    /* Unresolved local var: wchar_t i@[???] */
    if (wVar11 < wVar3) {
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: int32_t nextIndent@[DW_OP_reg11(R11)] */
      uVar4 = 0x1e;
      if (level < 0x1f) {
        uVar4 = level;
      }
      indent_00 = indent | 1 << (uVar4 & 0x1f);
      uVar4 = level + 1;
      lVar8 = (long)wVar11 * 8;
      while( true ) {
        data_ = *(void **)((long)pVVar6->array + lVar8);
        if (!show) {
          *(undefined1 *)((long)data_ + 0x1e) = 0;
        }
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
        Vector_set(this->displayList,this->displayList->items,data_);
        show_00 = false;
        if (*(char *)((long)data_ + 0x1e) != '\0') {
          show_00 = *(undefined1 *)((long)data_ + 0x20);
        }
        uVar5 = indent_00;
        if (wVar11 < wVar7) {
          Table_buildTreeBranch
                    (this,*(wchar_t *)((long)data_ + 0x10),uVar4,indent_00,(_Bool)show_00);
        }
        else {
          Table_buildTreeBranch(this,*(wchar_t *)((long)data_ + 0x10),uVar4,indent,(_Bool)show_00);
          if (wVar7 == wVar11) {
            uVar5 = -indent_00;
          }
        }
        wVar11 = wVar11 + L'\x01';
        *(uint *)((long)data_ + 0x24) = uVar5;
        lVar8 = lVar8 + 8;
        *(uint *)((long)data_ + 0x28) = uVar4;
        if (wVar11 == wVar3) break;
        pVVar6 = this->rows;
      }
    }
  }
  return;
}

