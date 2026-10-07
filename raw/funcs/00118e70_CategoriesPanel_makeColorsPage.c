/* CategoriesPanel_makeColorsPage @ 00118e70 size 63 */

/* DWARF original prototype: void CategoriesPanel_makeColorsPage(CategoriesPanel * this) */

void CategoriesPanel_makeColorsPage(CategoriesPanel *this)

{
  ColorsPanel *item;

  item = ColorsPanel_new((Settings *)this->host->settings);
  ScreenManager_insert(this->scr,&item->super,L'\xffffffff',this->scr->panels->items);
  return;
}

