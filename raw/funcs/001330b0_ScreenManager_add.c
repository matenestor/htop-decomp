/* ScreenManager_add @ 001330b0 size 16 */

/* DWARF original prototype: void ScreenManager_add(ScreenManager * this, Panel * item, wchar_t
   size) */

void ScreenManager_add(ScreenManager *this,Panel *item,wchar_t size)

{
  ScreenManager_insert(this,item,size,this->panels->items);
  return;
}

