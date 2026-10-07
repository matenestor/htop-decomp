/* ScreenSettings_invertSortOrder @ 0012e150 size 56 */

/* DWARF original prototype: void ScreenSettings_invertSortOrder(ScreenSettings * this) */

void ScreenSettings_invertSortOrder(ScreenSettings *this)

{
  bool bVar1;

  if (this->treeView != false) {
    bVar1 = this->treeDirection != L'\x01';
    this->treeDirection = (bVar1 - 1) + (uint)bVar1;
    return;
  }
  bVar1 = this->direction != L'\x01';
  this->direction = (bVar1 - 1) + (uint)bVar1;
  return;
}

