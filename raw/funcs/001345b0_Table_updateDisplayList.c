/* Table_updateDisplayList @ 001345b0 size 297 */

/* DWARF original prototype: void Table_updateDisplayList(Table * this) */

void Table_updateDisplayList(Table *this)

{
  wchar_t wVar1;
  wchar_t wVar2;
  Vector *pVVar3;
  Object *pOVar4;
  Object *pOVar5;
  Vector *pVVar6;
  Object **ppOVar7;
  long a3;
  wchar_t wVar8;
  long a2;
  size_t prevmemb;
  long in_R9;
  wchar_t wVar9;
  long lVar10;

  if (this->host->settings->ss->treeView == false) {
                    /* Unresolved local var: wchar_t size@[???] */
    if (this->needsSort != false) {
      Vector_insertionSort(this->rows);
    }
    Vector_prune(this->displayList);
    pVVar6 = this->rows;
    wVar1 = pVVar6->items;
                    /* Unresolved local var: wchar_t i@[???] */
    if (L'\0' < wVar1) {
      lVar10 = 0;
      do {
        pVVar3 = this->displayList;
        wVar2 = pVVar3->items;
        prevmemb = (size_t)pVVar3->arraySize;
        pOVar4 = *(Object **)((long)pVVar6->array + lVar10);
                    /* Unresolved local var: wchar_t oldSize@[???] */
        ppOVar7 = pVVar3->array;
        wVar9 = wVar2 + L'\x01';
                    /* Unresolved local var: Object * removed@[???] */
        if (pVVar3->arraySize < wVar9) {
          wVar8 = wVar9 + pVVar3->growthRate;
          a3 = 8;
          pVVar3->arraySize = wVar8;
          ppOVar7 = xReallocArrayZero(ppOVar7,prevmemb,(long)wVar8,8);
          pVVar3->array = ppOVar7;
          if (pVVar3->items <= wVar2) goto LAB_00134630;
          ppOVar7 = ppOVar7 + wVar2;
          if ((pVVar3->owner != false) && (pOVar5 = *ppOVar7, pOVar5 != (Object *)0x0)) {
            (*pOVar5->klass->delete)(pOVar5,prevmemb,a2,a3,(ulong)(uint)wVar2,in_R9);
            ppOVar7 = pVVar3->array + wVar2;
          }
        }
        else {
LAB_00134630:
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
          pVVar3->items = wVar9;
          ppOVar7 = ppOVar7 + wVar2;
        }
        *ppOVar7 = pOVar4;
        lVar10 = lVar10 + 8;
        if ((long)wVar1 * 8 == lVar10) break;
        pVVar6 = this->rows;
      } while( true );
    }
  }
  else if (this->needsSort != false) {
    Table_buildTree(this);
  }
  this->needsSort = false;
  return;
}

