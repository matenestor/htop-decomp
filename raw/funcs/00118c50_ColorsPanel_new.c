/* ColorsPanel_new @ 00118c50 size 539 */

/* WARNING: Removing unreachable block (ram,0x00118cfa) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00118d17 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ColorsPanel * ColorsPanel_new(Settings *settings)

{
  wchar_t wVar1;
  Vector *this;
  Object *pOVar2;
  ObjectClass *pOVar3;
  wchar_t len;
  int iVar4;
  ColorsPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar5;
  undefined8 *data_;
  Settings **ppSVar6;
  cchar_t *pcVar7;
  wchar_t *pwVar8;
  char **ppcVar9;
  char *pcVar10;
  long in_FS_OFFSET;
  wchar_t local_88 [4];
  Settings *local_68;
  undefined1 *local_60;
  attr_t local_54;
  wchar_t *local_50;
  long local_40;

  ppSVar6 = &local_68;
                    /* Unresolved local var: void * data@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = settings;
  this_00 = malloc(0x26e8);
  if (this_00 != (ColorsPanel *)0x0) {
    (this_00->super).super.klass = &ColorsPanel_class.super;
    fuBar = FunctionBar_new(ColorsFunctions,(char **)0x0,(wchar_t *)0x0);
    Panel_init(&this_00->super,L'\x01',L'\x01',L'\x01',L'\x01',&CheckItem_class.super,true,fuBar);
    this_00->settings = (Settings_4 *)local_68;
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[37455] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_60 = (undefined1 *)&local_68;
    pwVar8 = local_88;
    local_60 = (undefined1 *)&local_68;
    sVar5 = mbstowcs(local_88,((char *)0x147246 /* "Colors" */),6);
    len = (wchar_t)sVar5;
    if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(this_00->super).header,len);
      local_54 = wVar1 & 0xffffff;
      local_50 = local_88 + (ulong)(uint)(len + L'\xffffffff') + 1;
      pcVar7 = (this_00->super).header.chptr;
      do {
        wVar1 = *pwVar8;
        iVar4 = iswprint(wVar1);
        pcVar7->attr = 0;
        pcVar7->chars[0] = L'\0';
        pcVar7->chars[1] = L'\0';
        pcVar7->chars[2] = L'\0';
        if (iVar4 == 0) {
          wVar1 = L'�';
        }
        *(undefined1 (*) [16])(pcVar7->chars + 2) = (undefined1  [16])0x0;
        pwVar8 = pwVar8 + 1;
        pcVar7->attr = local_54;
        pcVar7->chars[0] = wVar1;
        pcVar7 = pcVar7 + 1;
      } while (local_50 != pwVar8);
    }
    ppSVar6 = (Settings **)local_60;
    (this_00->super).needsRedraw = true;
                    /* Unresolved local var: wchar_t i@[???] */
    ppcVar9 = ColorSchemeNames;
    pcVar10 = ((char *)0x14723e /* "Default" */);
    while( true ) {
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
      ppcVar9 = ppcVar9 + 1;
      *(undefined8 *)((long)ppSVar6 + -8) = 0x118dca;
      data_ = malloc(0x20);
      if (data_ == (undefined8 *)0x0) break;
      *data_ = &CheckItem_class;
                    /* Unresolved local var: char * data@[???] */
      *(undefined8 *)((long)ppSVar6 + -8) = 0x118de1;
      pcVar10 = strdup(pcVar10);
      if (pcVar10 == (char *)0x0) break;
      this = (this_00->super).items;
      data_[1] = pcVar10;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      *(undefined1 *)(data_ + 3) = 0;
      data_[2] = 0;
      wVar1 = this->items;
      *(undefined8 *)((long)ppSVar6 + -8) = 0x118e0e;
      Vector_set(this,wVar1,data_);
      pcVar10 = *ppcVar9;
      (this_00->super).needsRedraw = true;
      if (pcVar10 == (char *)0x0) {
        pOVar2 = ((this_00->super).items)->array[local_68->colorScheme];
        pOVar3 = pOVar2[2].klass;
        if (pOVar3 == (ObjectClass *)0x0) {
          *(undefined1 *)&pOVar2[3].klass = 1;
        }
        else {
          *(undefined1 *)&pOVar3->extends = 1;
        }
        if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          *(code **)((long)ppSVar6 + -8) = CategoriesPanel_makeColorsPage;
          __stack_chk_fail();
        }
        return this_00;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)((long)ppSVar6 + -8) = 0x118e6b;
  fail();
}

