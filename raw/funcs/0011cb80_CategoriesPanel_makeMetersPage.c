/* CategoriesPanel_makeMetersPage @ 0011cb80 size 372 */

/* DWARF original prototype: void CategoriesPanel_makeMetersPage(CategoriesPanel * this) */

void CategoriesPanel_makeMetersPage(CategoriesPanel *this)

{
  long lVar1;
  Settings__2 *settings;
  MetersPanel_2 *pMVar2;
  MetersPanel **meterPanels;
  MetersPanel_2 *item;
  AvailableMetersPanel *item_00;
  Machine *host;
  ScreenManager *scr;
  ulong columns;
  ulong uVar3;
  ulong va0;
  long in_FS_OFFSET;
  char titleBuffer [32];

  scr = this->scr;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  columns = (ulong)HeaderLayout_layouts[scr->header->headerLayout].columns;
                    /* Unresolved local var: void * data@[???] */
  meterPanels = malloc(columns * 8);
  if (meterPanels == (MetersPanel **)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  host = this->host;
  settings = host->settings;
                    /* Unresolved local var: size_t i@[???] */
  if (columns != 0) {
    uVar3 = 0;
    do {
      va0 = uVar3 + 1;
      xSnprintf(titleBuffer,0x20,((char *)0x1474eb /* "Column %zu" */),va0);
      item = MetersPanel_new((Settings_4 *)settings,titleBuffer,this->header->columns[uVar3],
                             (ScreenManager_3 *)this->scr);
      meterPanels[uVar3] = (MetersPanel *)item;
      if (uVar3 != 0) {
        pMVar2 = (MetersPanel_2 *)meterPanels[uVar3 - 1];
        item->leftNeighbor = pMVar2;
        item = (MetersPanel_2 *)meterPanels[uVar3];
        pMVar2->rightNeighbor = item;
      }
      ScreenManager_insert(this->scr,&item->super,L'\x14',this->scr->panels->items);
      uVar3 = va0;
    } while (va0 != columns);
    scr = this->scr;
    host = this->host;
  }
  item_00 = AvailableMetersPanel_new
                      ((Machine_4 *)host,(Header_3 *)this->header,columns,meterPanels,
                       (ScreenManager_2 *)scr);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    ScreenManager_insert(this->scr,&item_00->super,L'\xffffffff',this->scr->panels->items);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

