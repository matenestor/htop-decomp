/* Machine_populateTablesFromSettings @ 001233f0 size 285 */

/* DWARF original prototype: void Machine_populateTablesFromSettings(Machine * this, Settings *
   settings, Table * processTable) */

void Machine_populateTablesFromSettings(Machine *this,Settings_4 *settings,Table_2 *processTable)

{
  uint uVar1;
  Table **__ptr;
  size_t sVar2;
  Table **ppTVar3;
  size_t sVar4;
  ulong uVar5;
  Table_2 *pTVar6;

                    /* Unresolved local var: size_t i@[???] */
  uVar1 = settings->nScreens;
  this->settings = (Settings__2 *)settings;
  this->processTable = (Table *)processTable;
  if (uVar1 == 0) {
    return;
  }
  uVar5 = 0;
LAB_00123428:
                    /* Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: Table * table@[???] */
  pTVar6 = settings->screens[uVar5]->table;
  if (pTVar6 == (Table_2 *)0x0) {
    settings->screens[uVar5]->table = processTable;
    pTVar6 = processTable;
  }
  if (uVar5 == 0) {
    this->activeTable = (Table *)pTVar6;
  }
                    /* Unresolved local var: size_t nmemb@[???]
                       Unresolved local var: Table * * tables@[???]
                       Unresolved local var: size_t i@[???] */
  __ptr = this->tables;
  if (this->tableCount != 0) goto code_r0x00123460;
  sVar4 = 8;
  goto LAB_001234b3;
code_r0x00123460:
  sVar4 = 0;
  do {
    sVar2 = sVar4;
    if (pTVar6 == (Table_2 *)__ptr[sVar2]) {
      uVar5 = uVar5 + 1;
      if (settings->nScreens <= uVar5) {
        return;
      }
      goto LAB_00123428;
    }
    sVar4 = sVar2 + 1;
  } while (sVar2 + 1 != this->tableCount);
  if (sVar2 + 2 != 0x2000000000000000) {
    sVar4 = (sVar2 + 2) * 8;
LAB_001234b3:
                    /* Unresolved local var: void * data@[???] */
    ppTVar3 = realloc(__ptr,sVar4);
    if (ppTVar3 != (Table **)0x0) {
      *(Table_2 **)((long)ppTVar3 + (sVar4 - 8)) = pTVar6;
      uVar5 = uVar5 + 1;
      this->tables = ppTVar3;
      uVar1 = settings->nScreens;
      this->tableCount = this->tableCount + 1;
      if (uVar1 <= uVar5) {
        return;
      }
      goto LAB_00123428;
    }
    free(__ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

