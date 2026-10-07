/* CategoriesPanel_makeScreensPage @ 0011cd00 size 140 */

/* DWARF original prototype: void CategoriesPanel_makeScreensPage(CategoriesPanel * this) */

void CategoriesPanel_makeScreensPage(CategoriesPanel *this)

{
  ColumnsPanel *item;
  AvailableColumnsPanel *item_00;
  ScreensPanel *item_01;

  item_01 = ScreensPanel_new((Settings_3 *)this->host->settings);
  item = item_01->columns;
  item_00 = item_01->availableColumns;
  ScreenManager_insert(this->scr,&item_01->super,L'\x14',this->scr->panels->items);
  ScreenManager_insert(this->scr,&item->super,L'\x14',this->scr->panels->items);
  ScreenManager_insert(this->scr,&item_00->super,L'\xffffffff',this->scr->panels->items);
  return;
}

