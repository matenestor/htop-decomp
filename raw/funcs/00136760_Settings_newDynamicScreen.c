/* Settings_newDynamicScreen @ 00136760 size 216 */

/* DWARF original prototype: ScreenSettings * Settings_newDynamicScreen(Settings * this, char * tab,
   DynamicScreen * screen, Table * table) */

ScreenSettings_4 *
Settings_newDynamicScreen(Settings *this,char *tab,DynamicScreen *screen,Table_3 *table)

{
  wchar_t wVar1;
  wchar_t wVar2;
  ScreenSettings_4 *pSVar3;
  char *pcVar4;
  char *pcVar5;
  RowField *pRVar6;

  wVar2 = toFieldIndex(this->dynamicColumns,screen->columnKeys);
                    /* Unresolved local var: void * data@[???] */
  pSVar3 = malloc(0x38);
  if (pSVar3 != (ScreenSettings_4 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup(tab);
    if (pcVar4 != (char *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pcVar5 = strdup(screen->name);
      if (pcVar5 != (char *)0x0) {
                    /* Unresolved local var: void * data@[???] */
        pRVar6 = calloc(0x84,4);
        if (pRVar6 != (RowField *)0x0) {
          pSVar3->fields = pRVar6;
          wVar1 = screen->direction;
          pSVar3->flags = 0;
          pSVar3->direction = L'\0';
          pSVar3->treeDirection = L'\0';
          pSVar3->sortKey = 0;
          pSVar3->treeSortKey = 0;
          pSVar3->treeView = false;
          pSVar3->treeViewAlwaysByPID = false;
          pSVar3->allBranchesCollapsed = false;
          pSVar3->field_0x37 = 0;
          pSVar3->dynamic = pcVar5;
          pcVar5 = screen->columnKeys;
          pSVar3->direction = wVar1;
          pSVar3->heading = pcVar4;
          pSVar3->table = table;
          pSVar3->treeDirection = L'\x01';
          pSVar3->sortKey = wVar2;
          pSVar3 = Settings_initScreenSettings(pSVar3,(Settings_3 *)this,pcVar5);
          return pSVar3;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

