/* ScreenManager_delete @ 0012e390 size 38 */

/* DWARF original prototype: void ScreenManager_delete(ScreenManager * this) */

void ScreenManager_delete(ScreenManager *this)

{
  Vector_delete(this->panels);
  free(this);
  return;
}

