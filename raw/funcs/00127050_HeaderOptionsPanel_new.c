/* HeaderOptionsPanel_new @ 00127050 size 557 */

/* WARNING: Removing unreachable block (ram,0x00127103) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00127120 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

HeaderOptionsPanel * HeaderOptionsPanel_new(Settings_4 *settings,ScreenManager_3 *scr)

{
  wchar_t wVar1;
  Vector *this;
  Object *pOVar2;
  ObjectClass *pOVar3;
  wchar_t len;
  int iVar4;
  HeaderOptionsPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar5;
  undefined8 *data_;
  char *pcVar6;
  cchar_t *pcVar7;
  char **ppcVar8;
  undefined1 *puVar9;
  wchar_t *pwVar10;
  long in_FS_OFFSET;
  wchar_t local_a8 [12];
  undefined1 auStack_68 [8];
  ScreenManager_3 *local_60;
  undefined1 *local_58;
  attr_t local_4c;
  long local_40;

                    /* Unresolved local var: void * data@[???] */
  puVar9 = auStack_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = scr;
  this_00 = malloc(0x26f0);
  if (this_00 != (HeaderOptionsPanel *)0x0) {
    (this_00->super).super.klass = &HeaderOptionsPanel_class.super;
    fuBar = FunctionBar_new(HeaderOptionsFunctions,(char **)0x0,(wchar_t *)0x0);
    Panel_init(&this_00->super,L'\x01',L'\x01',L'\x01',L'\x01',&CheckItem_class.super,true,fuBar);
    this_00->settings = settings;
    this_00->scr = local_60;
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[35747] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_58 = auStack_68;
    pwVar10 = local_a8;
    local_58 = auStack_68;
    sVar5 = mbstowcs(local_a8,((char *)0x14882e /* "Header Layout" */),0xd);
    len = (wchar_t)sVar5;
    if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(this_00->super).header,len);
      local_4c = wVar1 & 0xffffff;
      pcVar7 = (this_00->super).header.chptr;
      do {
        wVar1 = *pwVar10;
        iVar4 = iswprint(wVar1);
        pcVar7->attr = 0;
        pcVar7->chars[0] = L'\0';
        pcVar7->chars[1] = L'\0';
        pcVar7->chars[2] = L'\0';
        if (iVar4 == 0) {
          wVar1 = L'�';
        }
        pwVar10 = pwVar10 + 1;
        *(undefined1 (*) [16])(pcVar7->chars + 2) = (undefined1  [16])0x0;
        pcVar7->attr = local_4c;
        pcVar7->chars[0] = wVar1;
        pcVar7 = pcVar7 + 1;
      } while (pwVar10 != local_a8 + (ulong)(uint)(len + L'\xffffffff') + 1);
    }
    puVar9 = local_58;
    (this_00->super).needsRedraw = true;
    ppcVar8 = &HeaderLayout_layouts[0].description;
                    /* Unresolved local var: wchar_t i@[???] */
    while( true ) {
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
      pcVar6 = *ppcVar8;
      *(undefined8 *)(puVar9 + -8) = 0x1271d5;
      data_ = malloc(0x20);
      if (data_ == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
      *data_ = &CheckItem_class;
      *(undefined8 *)(puVar9 + -8) = 0x1271f3;
      pcVar6 = strdup(pcVar6);
      if (pcVar6 == (char *)0x0) break;
      this = (this_00->super).items;
      data_[1] = pcVar6;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      ppcVar8 = ppcVar8 + 3;
      *(undefined1 *)(data_ + 3) = 0;
      data_[2] = 0;
      wVar1 = this->items;
      *(undefined8 *)(puVar9 + -8) = 0x12721d;
      Vector_set(this,wVar1,data_);
      (this_00->super).needsRedraw = true;
      if (ppcVar8 == AvailableColumnsFunctions + 2) {
        pOVar2 = ((this_00->super).items)->array[local_60->header->headerLayout];
        pOVar3 = pOVar2[2].klass;
        if (pOVar3 == (ObjectClass *)0x0) {
          *(undefined1 *)&pOVar2[3].klass = 1;
        }
        else {
          *(undefined1 *)&pOVar3->extends = 1;
        }
        if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          *(code **)(puVar9 + -8) = IncSet_new;
          __stack_chk_fail();
        }
        return this_00;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar9 + -8) = 0x12727b;
  fail();
}

