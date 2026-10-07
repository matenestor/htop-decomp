/* Table_removeIndex @ 0012fa10 size 158 */

/* DWARF original prototype: void Table_removeIndex(Table * this, Row * row, wchar_t idx) */

void Table_removeIndex(Table *this,Row_2 *row,wchar_t idx)

{
  wchar_t key;
  wchar_t wVar1;
  Vector *pVVar2;
  Object *pOVar3;
  ulong a1;
  long in_R8;
  long in_R9;

  key = row->id;
  a1 = (ulong)(uint)key;
  Hashtable_remove(this->table,key);
  pVVar2 = this->rows;
                    /* Unresolved local var: Object * removed@[???] */
  pOVar3 = pVVar2->array[idx];
  if (pOVar3 != (Object *)0x0) {
    pVVar2->array[idx] = (Object *)0x0;
    wVar1 = pVVar2->dirty_index;
    pVVar2->dirty_count = pVVar2->dirty_count + L'\x01';
    if ((idx < wVar1) || (wVar1 < L'\0')) {
      pVVar2->dirty_index = idx;
    }
    if (pVVar2->owner != false) {
      (*pOVar3->klass->delete)(pOVar3,a1,(ulong)(uint)wVar1,(long)idx,in_R8,in_R9);
    }
  }
  if ((this->following == key) && (this->following != L'\xffffffff')) {
                    /* Unresolved local var: wchar_t rowid@[???] */
    this->following = L'\xffffffff';
    this->panel->selectionColorId = PANEL_SELECTION_FOCUS;
    return;
  }
  return;
}

