/* CategoriesPanel_makeHeaderOptionsPage @ 0011cd90 size 70 */

/* DWARF original prototype: void CategoriesPanel_makeHeaderOptionsPage(CategoriesPanel * this) */

void CategoriesPanel_makeHeaderOptionsPage(CategoriesPanel *this)

{
  HeaderOptionsPanel *item;

  item = HeaderOptionsPanel_new((Settings_4 *)this->host->settings,(ScreenManager_3 *)this->scr);
  ScreenManager_insert(this->scr,&item->super,L'\xffffffff',this->scr->panels->items);
  return;
}

