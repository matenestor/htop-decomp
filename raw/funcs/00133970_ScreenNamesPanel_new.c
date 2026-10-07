/* ScreenNamesPanel_new @ 00133970 size 600 */

/* WARNING: Removing unreachable block (ram,0x00133a58) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133a75 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ScreenNamesPanel * ScreenNamesPanel_new(Settings_3 *settings)

{
  wchar_t wVar1;
  uint uVar2;
  ScreenSettings_4 *pSVar3;
  Vector *this;
  wchar_t len;
  int iVar4;
  ScreenNamesPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar5;
  undefined8 *data_;
  char *pcVar6;
  undefined1 *puVar7;
  cchar_t *pcVar8;
  long lVar9;
  wchar_t *pwVar10;
  long in_FS_OFFSET;
  wchar_t local_88 [4];
  undefined1 auStack_68 [8];
  undefined1 *local_60;
  attr_t local_54;
  wchar_t *local_50;
  long local_40;

                    /* Unresolved local var: void * data@[???] */
  puVar7 = auStack_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = malloc(0x2728);
  if (this_00 == (ScreenNamesPanel *)0x0) {
LAB_00133bc0:
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar7 + -8) = 0x133bc5;
    fail();
  }
  (this_00->super).super.klass = &ScreenNamesPanel_class.super;
  fuBar = FunctionBar_new(ScreenNamesFunctions,(char **)0x0,(wchar_t *)0x0);
  Panel_init(&this_00->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
  this_00->cursor = L'\0';
  this_00->buffer[0] = '\0';
  pwVar10 = CRT_colors;
  this_00->buffer[1] = '\0';
  this_00->buffer[2] = '\0';
  this_00->buffer[3] = '\0';
  this_00->buffer[4] = '\0';
  this_00->buffer[5] = '\0';
  this_00->buffer[6] = '\0';
  this_00->buffer[7] = '\0';
  this_00->buffer[8] = '\0';
  this_00->buffer[9] = '\0';
  this_00->buffer[10] = '\0';
  this_00->buffer[0xb] = '\0';
  this_00->buffer[0xc] = '\0';
  this_00->buffer[0xd] = '\0';
  this_00->buffer[0xe] = '\0';
  this_00->buffer[0xf] = '\0';
  this_00->settings = settings;
  this_00->buffer[0xd] = '\0';
  this_00->buffer[0xe] = '\0';
  this_00->buffer[0xf] = '\0';
  this_00->buffer[0x10] = '\0';
  this_00->buffer[0x11] = '\0';
  this_00->buffer[0x12] = '\0';
  this_00->buffer[0x13] = '\0';
  this_00->buffer[0x14] = '\0';
  this_00->ds = (DynamicScreen *)0x0;
  this_00->saved = (char *)0x0;
  wVar1 = pwVar10[7];
  this_00->renamingItem = (ListItem *)0x0;
  (this_00->super).cursorOn = false;
                    /* Unresolved local var: wchar_t[46317] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  local_60 = auStack_68;
  pwVar10 = local_88;
  local_60 = auStack_68;
  sVar5 = mbstowcs(local_88,((char *)0x147c87 /* "Screens" */),7);
  len = (wchar_t)sVar5;
  if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    RichString_setLen(&(this_00->super).header,len);
    local_54 = wVar1 & 0xffffff;
    local_50 = local_88 + (ulong)(uint)(len + L'\xffffffff') + 1;
    pcVar8 = (this_00->super).header.chptr;
    do {
      wVar1 = *pwVar10;
      iVar4 = iswprint(wVar1);
      pcVar8->attr = 0;
      pcVar8->chars[0] = L'\0';
      pcVar8->chars[1] = L'\0';
      pcVar8->chars[2] = L'\0';
      if (iVar4 == 0) {
        wVar1 = L'�';
      }
      *(undefined1 (*) [16])(pcVar8->chars + 2) = (undefined1  [16])0x0;
      pwVar10 = pwVar10 + 1;
      pcVar8->attr = local_54;
      pcVar8->chars[0] = wVar1;
      pcVar8 = pcVar8 + 1;
    } while (local_50 != pwVar10);
  }
  puVar7 = local_60;
                    /* Unresolved local var: uint i@[???] */
  uVar2 = settings->nScreens;
  (this_00->super).needsRedraw = true;
  lVar9 = 0;
  if (uVar2 != 0) {
    do {
                    /* Unresolved local var: ScreenSettings * ss@[???] */
      while (pSVar3 = settings->screens[lVar9], pSVar3->dynamic == (char *)0x0) {
                    /* Unresolved local var: ScreenNameListItem * this@[???] */
        local_50 = (wchar_t *)pSVar3->heading;
                    /* Unresolved local var: void * data@[???] */
        *(undefined8 *)(puVar7 + -8) = 0x133b4a;
        data_ = malloc(0x20);
        pwVar10 = local_50;
        if (data_ == (undefined8 *)0x0) goto LAB_00133bc0;
                    /* Unresolved local var: char * data@[???] */
        *data_ = &ScreenNameListItem_class;
        *(undefined8 *)(puVar7 + -8) = 0x133b65;
        pcVar6 = strdup((char *)pwVar10);
        if (pcVar6 == (char *)0x0) goto LAB_00133bc0;
        this = (this_00->super).items;
        data_[1] = pcVar6;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
        lVar9 = lVar9 + 1;
        *(undefined4 *)(data_ + 2) = 0;
        *(undefined1 *)((long)data_ + 0x14) = 0;
        wVar1 = this->items;
        data_[3] = pSVar3;
        *(undefined8 *)(puVar7 + -8) = 0x133b93;
        Vector_set(this,wVar1,data_);
        (this_00->super).needsRedraw = true;
        if (settings->nScreens <= (uint)lVar9) goto LAB_00133b9f;
      }
      lVar9 = lVar9 + 1;
    } while ((uint)lVar9 < settings->nScreens);
  }
LAB_00133b9f:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this_00;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar7 + -8) = &UNK_00133bca;
  __stack_chk_fail();
}

