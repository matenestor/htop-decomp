/* CategoriesPanel_makeDisplayOptionsPage @ 00119aa0 size 70 */

/* DWARF original prototype: void CategoriesPanel_makeDisplayOptionsPage(CategoriesPanel * this) */

void CategoriesPanel_makeDisplayOptionsPage(CategoriesPanel *this)

{
  DisplayOptionsPanel *item;

  item = DisplayOptionsPanel_new((Settings_4 *)this->host->settings,(ScreenManager_3 *)this->scr);
  ScreenManager_insert(this->scr,&item->super,L'\xffffffff',this->scr->panels->items);
  return;
}

