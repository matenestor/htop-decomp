/* ScreenSettings_setSortKey @ 0012e190 size 72 */

/* DWARF original prototype: void ScreenSettings_setSortKey(ScreenSettings * this, ProcessField
   sortKey) */

void ScreenSettings_setSortKey(ScreenSettings *this,ProcessField sortKey)

{
  _Bool _Var1;

  _Var1 = Process_fields[sortKey].defaultSortDesc;
  if ((this->treeViewAlwaysByPID == false) && (this->treeView != false)) {
    this->treeSortKey = sortKey;
    this->treeDirection = (-(uint)(_Var1 == false) & 2) + L'\xffffffff';
    return;
  }
  this->sortKey = sortKey;
  this->treeView = false;
  this->direction = (-(uint)(_Var1 == false) & 2) + L'\xffffffff';
  return;
}

