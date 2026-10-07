/* Table_buildTree @ 001343c0 size 380 */

/* DWARF original prototype: void Table_buildTree(Table * this) */

void Table_buildTree(Table *this)

{
  wchar_t wVar1;
  Vector *pVVar2;
  Object **array;
  Object *pOVar3;
  ulong uVar4;
  HashtableItem *pHVar5;
  void *data_;
  HashtableItem *pHVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  Object **ppOVar10;
  long lVar11;
  long lVar12;

                    /* Unresolved local var: wchar_t vsize@[???] */
  Vector_prune(this->displayList);
  pVVar2 = this->rows;
  wVar1 = pVVar2->items;
                    /* Unresolved local var: wchar_t i@[???] */
  if (wVar1 < L'\x01') {
    quickSort(pVVar2->array,L'\0',wVar1 + L'\xffffffff',compareRowByKnownParentThenNatural);
    this->needsSort = false;
    return;
  }
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: wchar_t parent@[???] */
  array = pVVar2->array;
  lVar11 = (long)wVar1 * 8;
  ppOVar10 = array;
  do {
    pOVar3 = *ppOVar10;
    uVar9 = *(uint *)((long)&pOVar3[2].klass + 4);
    if ((uVar9 == *(uint *)&pOVar3[2].klass) &&
       (uVar9 = *(uint *)&pOVar3[3].klass, uVar9 == *(uint *)&pOVar3[2].klass)) {
      *(undefined1 *)((long)&pOVar3[3].klass + 4) = 1;
    }
    else {
      *(undefined1 *)((long)&pOVar3[3].klass + 4) = 0;
      if (uVar9 != 0) {
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        uVar4 = this->table->size;
        pHVar5 = this->table->buckets;
        uVar8 = (ulong)uVar9 % uVar4;
        if (pHVar5[uVar8].value != (void *)0x0) {
          uVar7 = 0;
          pHVar6 = pHVar5 + uVar8;
          do {
            while( true ) {
              if (uVar9 == pHVar6->key) goto LAB_00134484;
              if (pHVar6->probe < uVar7) goto LAB_00134480;
              uVar8 = uVar8 + 1;
              if (uVar4 != uVar8) break;
              uVar8 = 0;
              uVar7 = uVar7 + 1;
              pHVar6 = pHVar5;
              if (pHVar5->value == (void *)0x0) goto LAB_00134480;
            }
            uVar7 = uVar7 + 1;
            pHVar6 = pHVar5 + uVar8;
          } while (pHVar6->value != (void *)0x0);
        }
      }
LAB_00134480:
      *(undefined1 *)((long)&pOVar3[3].klass + 4) = 1;
    }
LAB_00134484:
    ppOVar10 = ppOVar10 + 1;
  } while (array + wVar1 != ppOVar10);
  quickSort(array,L'\0',wVar1 + L'\xffffffff',compareRowByKnownParentThenNatural);
                    /* Unresolved local var: wchar_t i@[???] */
  lVar12 = 0;
  do {
                    /* Unresolved local var: Row * row@[???] */
    while (data_ = *(void **)((long)this->rows->array + lVar12),
          *(char *)((long)data_ + 0x1c) == '\0') {
      lVar12 = lVar12 + 8;
      if (lVar11 == lVar12) goto LAB_00134500;
    }
    pVVar2 = this->displayList;
    *(undefined8 *)((long)data_ + 0x24) = 0;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
    lVar12 = lVar12 + 8;
    Vector_set(pVVar2,pVVar2->items,data_);
    Table_buildTreeBranch(this,*(wchar_t *)((long)data_ + 0x10),0,0,*(_Bool *)((long)data_ + 0x20));
  } while (lVar11 != lVar12);
LAB_00134500:
  this->needsSort = false;
  return;
}

