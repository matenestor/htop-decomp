/* Settings_newScreen @ 00135bf0 size 345 */

/* DWARF original prototype: ScreenSettings * Settings_newScreen(Settings * this, ScreenDefaults *
   defaults) */

ScreenSettings_4 * Settings_newScreen(Settings *this,ScreenDefaults *defaults)

{
  wchar_t wVar1;
  ScreenSettings_4 *pSVar2;
  char *pcVar3;
  RowField *pRVar4;
  char cVar5;
  wchar_t local_3c;

  if (defaults->sortKey == (char *)0x0) {
    if (defaults->treeSortKey == (char *)0x0) {
      local_3c = L'\x01';
      wVar1 = L'\x01';
    }
    else {
      wVar1 = L'\x01';
      local_3c = toFieldIndex(this->dynamicColumns,defaults->treeSortKey);
    }
  }
  else {
    wVar1 = toFieldIndex(this->dynamicColumns,defaults->sortKey);
    local_3c = L'\x01';
    if (defaults->treeSortKey != (char *)0x0) {
      local_3c = toFieldIndex(this->dynamicColumns,defaults->treeSortKey);
    }
    cVar5 = '\x01';
    if (0x83 < (uint)wVar1) goto LAB_00135c54;
  }
  cVar5 = Process_fields[wVar1].defaultSortDesc;
LAB_00135c54:
                    /* Unresolved local var: void * data@[???] */
  pSVar2 = malloc(0x38);
  if (pSVar2 != (ScreenSettings_4 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    pcVar3 = strdup(defaults->name);
    if (pcVar3 != (char *)0x0) {
                    /* Unresolved local var: void * data@[???] */
      pRVar4 = calloc(0x84,4);
      if (pRVar4 != (RowField *)0x0) {
        pSVar2->fields = pRVar4;
        pSVar2->dynamic = (char *)0x0;
        pSVar2->treeSortKey = local_3c;
        pSVar2->heading = pcVar3;
        pcVar3 = defaults->columns;
        pSVar2->direction = -(uint)(cVar5 != '\0') | 1;
        pSVar2->table = (Table__3 *)0x0;
        pSVar2->flags = 0;
        pSVar2->treeDirection = L'\x01';
        pSVar2->sortKey = wVar1;
        pSVar2->treeView = false;
        pSVar2->treeViewAlwaysByPID = false;
        pSVar2->allBranchesCollapsed = false;
        pSVar2 = Settings_initScreenSettings(pSVar2,(Settings_3 *)this,pcVar3);
        return pSVar2;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

