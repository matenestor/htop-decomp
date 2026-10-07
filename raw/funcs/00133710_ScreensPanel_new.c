/* ScreensPanel_new @ 00133710 size 606 */

/* WARNING: Removing unreachable block (ram,0x00133816) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133833 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ScreensPanel * ScreensPanel_new(Settings_3 *settings)

{
  wchar_t wVar1;
  uint uVar2;
  Hashtable_2 *pHVar3;
  Hashtable_2 *columns;
  ScreenSettings_4 **ppSVar4;
  ScreenSettings_4 *pSVar5;
  Vector *this;
  wchar_t len;
  int iVar6;
  ScreensPanel *this_00;
  FunctionBar *fuBar;
  ColumnsPanel *columns_00;
  AvailableColumnsPanel *pAVar7;
  size_t sVar8;
  wchar_t *pwVar9;
  char *pcVar10;
  undefined1 *puVar11;
  char **functions;
  cchar_t *pcVar12;
  long lVar13;
  long in_FS_OFFSET;
  wchar_t local_88 [4];
  undefined1 auStack_68 [8];
  undefined1 *local_60;
  attr_t local_54;
  wchar_t *local_50;
  long local_40;

                    /* Unresolved local var: void * data@[???] */
  puVar11 = auStack_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = malloc(0x2730);
  if (this_00 == (ScreensPanel *)0x0) {
LAB_00133964:
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar11 + -8) = 0x133969;
    fail();
  }
  pHVar3 = settings->dynamicScreens;
  columns = settings->dynamicColumns;
  functions = ScreensFunctions;
  (this_00->super).super.klass = &ScreensPanel_class.super;
  if (pHVar3 != (Hashtable_2 *)0x0) {
    functions = DynamicFunctions;
  }
  fuBar = FunctionBar_new(functions,(char **)0x0,(wchar_t *)0x0);
  Panel_init(&this_00->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
  ppSVar4 = settings->screens;
  this_00->settings = (Settings_4 *)settings;
  columns_00 = ColumnsPanel_new((ScreenSettings *)*ppSVar4,columns,&settings->changed);
  this_00->columns = columns_00;
  pAVar7 = AvailableColumnsPanel_new(&columns_00->super,columns);
  this_00->moving = false;
  this_00->availableColumns = pAVar7;
  this_00->cursor = L'\0';
  pwVar9 = CRT_colors;
  (this_00->super).cursorOn = false;
  this_00->renamingItem = (ListItem *)0x0;
                    /* Unresolved local var: wchar_t[45057] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  wVar1 = pwVar9[7];
  local_60 = auStack_68;
  pwVar9 = local_88;
  local_60 = auStack_68;
  sVar8 = mbstowcs(local_88,((char *)0x147c87 /* "Screens" */),7);
  len = (wchar_t)sVar8;
  if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    RichString_setLen(&(this_00->super).header,len);
    local_54 = wVar1 & 0xffffff;
    local_50 = local_88 + (ulong)(uint)(len + L'\xffffffff') + 1;
    pcVar12 = (this_00->super).header.chptr;
    do {
      wVar1 = *pwVar9;
      iVar6 = iswprint(wVar1);
      pcVar12->attr = 0;
      pcVar12->chars[0] = L'\0';
      pcVar12->chars[1] = L'\0';
      pcVar12->chars[2] = L'\0';
      if (iVar6 == 0) {
        wVar1 = L'�';
      }
      *(undefined1 (*) [16])(pcVar12->chars + 2) = (undefined1  [16])0x0;
      pwVar9 = pwVar9 + 1;
      pcVar12->attr = local_54;
      pcVar12->chars[0] = wVar1;
      pcVar12 = pcVar12 + 1;
    } while (local_50 != pwVar9);
  }
  puVar11 = local_60;
                    /* Unresolved local var: uint i@[???] */
  uVar2 = settings->nScreens;
  (this_00->super).needsRedraw = true;
  lVar13 = 0;
  if (uVar2 != 0) {
    do {
                    /* Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: char * name@[???] */
                    /* Unresolved local var: ScreenListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      pSVar5 = settings->screens[lVar13];
      pcVar10 = pSVar5->heading;
      *(undefined8 *)(puVar11 + -8) = 0x1338ee;
      pwVar9 = malloc(0x28);
      if (pwVar9 == (wchar_t *)0x0) goto LAB_00133964;
                    /* Unresolved local var: char * data@[???] */
      *(ObjectClass **)pwVar9 = &ScreenListItem_class;
      local_50 = pwVar9;
      *(undefined8 *)(puVar11 + -8) = 0x13390c;
      pcVar10 = strdup(pcVar10);
      pwVar9 = local_50;
      if (pcVar10 == (char *)0x0) goto LAB_00133964;
      this = (this_00->super).items;
      lVar13 = lVar13 + 1;
      *(char **)(local_50 + 2) = pcVar10;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      wVar1 = this->items;
      local_50[4] = L'\0';
      *(undefined1 *)(local_50 + 5) = 0;
      *(ScreenSettings_4 **)(local_50 + 8) = pSVar5;
      *(undefined8 *)(puVar11 + -8) = 0x133938;
      Vector_set(this,wVar1,pwVar9);
      (this_00->super).needsRedraw = true;
    } while ((uint)lVar13 < settings->nScreens);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar11 + -8) = &UNK_0013396e;
    __stack_chk_fail();
  }
  return this_00;
}

