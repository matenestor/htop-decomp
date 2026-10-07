/* ScreenManager_insert @ 00132f90 size 278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void ScreenManager_insert(ScreenManager * this, Panel * item, wchar_t
   size, wchar_t idx) */

void ScreenManager_insert(ScreenManager *this,Panel *item,wchar_t size,wchar_t idx)

{
  Object *pOVar1;
  wchar_t wVar2;
  Vector *this_00;
  Header_2 *pHVar3;
  Object **ppOVar4;
  Object *pOVar5;
  int iVar6;
  long lVar7;
  wchar_t wVar8;
  wchar_t wVar9;

  wVar8 = L'\0';
                    /* Unresolved local var: Panel * last@[???] */
  this_00 = this->panels;
  if (L'\0' < idx) {
    wVar8 = *(int *)&this_00->array[idx + L'\xffffffff'][2].klass +
            *(int *)&this_00->array[idx + L'\xffffffff'][1].klass + L'\x01';
  }
  wVar9 = this->y1;
  wVar2 = this->y2;
  iVar6 = _LINES - wVar9;
  if (this->state->hideMeters == false) {
    pHVar3 = this->header;
    if (pHVar3 != (Header_2 *)0x0) {
      iVar6 = iVar6 - pHVar3->height;
    }
    if (size < L'\x01') {
      size = ((_COLS - this->x1) + this->x2) - wVar8;
    }
    item->w = size;
    item->h = iVar6 + wVar2;
    item->needsRedraw = true;
    if (pHVar3 != (Header_2 *)0x0) {
      wVar9 = wVar9 + pHVar3->height;
    }
  }
  else {
    if (size < L'\x01') {
      size = ((_COLS - this->x1) + this->x2) - wVar8;
    }
    item->w = size;
    item->h = iVar6 + wVar2;
    item->needsRedraw = true;
  }
  item->y = wVar9;
  wVar9 = this->panelCount;
  item->x = wVar8;
                    /* Unresolved local var: wchar_t i@[???] */
  if ((idx < wVar9) && (idx + L'\x01' <= wVar9)) {
                    /* Unresolved local var: Panel * p@[???] */
    ppOVar4 = this_00->array;
    lVar7 = (long)(idx + L'\x01');
    do {
      pOVar5 = ppOVar4[lVar7];
      lVar7 = lVar7 + 1;
      pOVar1 = pOVar5 + 1;
      *(wchar_t *)&pOVar1->klass = *(int *)&pOVar1->klass + size;
      *(undefined1 *)&pOVar5[9].klass = 1;
    } while ((wchar_t)lVar7 <= wVar9);
  }
  Vector_insert(this_00,idx,item);
  item->needsRedraw = true;
  this->panelCount = this->panelCount + L'\x01';
  return;
}

