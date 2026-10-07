/* CategoriesPanel_new @ 00118a20 size 545 */

/* WARNING: Removing unreachable block (ram,0x00118adb) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00118af8 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

CategoriesPanel * CategoriesPanel_new(ScreenManager_3 *scr,Header_4 *header,Machine_2 *host)

{
  wchar_t wVar1;
  Vector *this;
  ScreenManager *this_00;
  wchar_t wVar2;
  int iVar3;
  CategoriesPanel *this_01;
  FunctionBar *fuBar;
  size_t sVar4;
  undefined8 *data_;
  char *pcVar5;
  undefined1 *puVar6;
  CategoriesPanelPage *pCVar7;
  cchar_t *pcVar8;
  wchar_t *pwVar9;
  long in_FS_OFFSET;
  wchar_t local_98 [8];
  undefined1 auStack_68 [8];
  ScreenManager *local_60;
  undefined1 *local_58;
  wchar_t *local_50;
  long local_40;

  puVar6 = auStack_68;
                    /* Unresolved local var: void * data@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = (ScreenManager *)scr;
  this_01 = malloc(0x26f8);
  if (this_01 != (CategoriesPanel *)0x0) {
    (this_01->super).super.klass = &CategoriesPanel_class.super;
    fuBar = FunctionBar_new(CategoriesFunctions,(char **)0x0,(wchar_t *)0x0);
    Panel_init(&this_01->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
    this_01->header = (Header_2 *)header;
    this_01->host = (Machine *)host;
    this_01->scr = local_60;
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[35903] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_58 = auStack_68;
    pwVar9 = local_98;
    local_58 = auStack_68;
    sVar4 = mbstowcs(local_98,((char *)0x147233 /* "Categories" */),10);
    wVar2 = (wchar_t)sVar4;
    if (L'\0' < wVar2) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(this_01->super).header,wVar2);
      local_50 = local_98 + (ulong)(uint)(wVar2 + L'\xffffffff') + 1;
      pcVar8 = (this_01->super).header.chptr;
      do {
        wVar2 = *pwVar9;
        iVar3 = iswprint(wVar2);
        pcVar8->attr = 0;
        pcVar8->chars[0] = L'\0';
        pcVar8->chars[1] = L'\0';
        pcVar8->chars[2] = L'\0';
        if (iVar3 == 0) {
          wVar2 = L'�';
        }
        pwVar9 = pwVar9 + 1;
        pcVar8->attr = wVar1 & 0xffffff;
        *(undefined1 (*) [16])(pcVar8->chars + 2) = (undefined1  [16])0x0;
        pcVar8->chars[0] = wVar2;
        pcVar8 = pcVar8 + 1;
      } while (pwVar9 != local_50);
    }
    puVar6 = local_58;
    (this_01->super).needsRedraw = true;
    pCVar7 = categoriesPanelPages;
                    /* Unresolved local var: size_t i@[???] */
    while( true ) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      pcVar5 = pCVar7->name;
      *(undefined8 *)(puVar6 + -8) = 0x118ba6;
      data_ = malloc(0x18);
      if (data_ == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
      *data_ = &ListItem_class;
      *(undefined8 *)(puVar6 + -8) = 0x118bc4;
      pcVar5 = strdup(pcVar5);
      if (pcVar5 == (char *)0x0) break;
      this = (this_01->super).items;
      data_[1] = pcVar5;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      pCVar7 = pCVar7 + 1;
      *(undefined4 *)(data_ + 2) = 0;
      *(undefined1 *)((long)data_ + 0x14) = 0;
      wVar1 = this->items;
      *(undefined8 *)(puVar6 + -8) = 0x118bed;
      Vector_set(this,wVar1,data_);
      this_00 = local_60;
      (this_01->super).needsRedraw = true;
      if (pCVar7 == (CategoriesPanelPage *)&DAT_00155f90) {
        wVar1 = local_60->panels->items;
        *(undefined8 *)(puVar6 + -8) = 0x118c0e;
        ScreenManager_insert(this_00,&this_01->super,L'\x10',wVar1);
        *(undefined8 *)(puVar6 + -8) = 0x118c16;
        CategoriesPanel_makeDisplayOptionsPage(this_01);
        if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar6 + -8) = &UNK_00118c41;
          __stack_chk_fail();
        }
        return this_01;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar6 + -8) = 0x118c3c;
  fail();
}

