/* ColumnsPanel_new @ 0011b270 size 413 */

/* WARNING: Removing unreachable block (ram,0x0011b32c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x0011b349 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ColumnsPanel * ColumnsPanel_new(ScreenSettings *ss,Hashtable_2 *columns,_Bool *changed)

{
  wchar_t wVar1;
  Hashtable_2 *columns_00;
  undefined1 *puVar2;
  ScreenSettings *ss_00;
  wchar_t wVar3;
  int iVar4;
  ColumnsPanel *this;
  FunctionBar *fuBar;
  size_t sVar5;
  cchar_t *pcVar6;
  wchar_t *pwVar7;
  long in_FS_OFFSET;
  wchar_t local_a8 [12];
  Hashtable_2 *local_68;
  undefined1 *local_60;
  ScreenSettings *local_58;
  wchar_t *local_50;
  long local_40;

                    /* Unresolved local var: void * data@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = columns;
  local_58 = ss;
  this = malloc(0x26f8);
  if (this == (ColumnsPanel *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this->super).super.klass = &ColumnsPanel_class.super;
  fuBar = FunctionBar_new(ColumnsFunctions,(char **)0x0,(wchar_t *)0x0);
  Panel_init(&this->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
  this->changed = changed;
  this->moving = false;
  this->ss = (ScreenSettings_3 *)local_58;
  wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[62483] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  local_60 = (undefined1 *)&local_68;
  pwVar7 = local_a8;
  local_60 = (undefined1 *)&local_68;
  sVar5 = mbstowcs(local_a8,((char *)0x147414 /* "Active Columns" */),0xe);
  wVar3 = (wchar_t)sVar5;
  if (L'\0' < wVar3) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    RichString_setLen(&(this->super).header,wVar3);
    local_50 = local_a8 + (ulong)(uint)(wVar3 + L'\xffffffff') + 1;
    pcVar6 = (this->super).header.chptr;
    do {
      wVar3 = *pwVar7;
      iVar4 = iswprint(wVar3);
      pcVar6->attr = 0;
      pcVar6->chars[0] = L'\0';
      pcVar6->chars[1] = L'\0';
      pcVar6->chars[2] = L'\0';
      if (iVar4 == 0) {
        wVar3 = L'�';
      }
      pcVar6->attr = wVar1 & 0xffffff;
      pwVar7 = pwVar7 + 1;
      *(undefined1 (*) [16])(pcVar6->chars + 2) = (undefined1  [16])0x0;
      pcVar6->chars[0] = wVar3;
      pcVar6 = pcVar6 + 1;
    } while (local_50 != pwVar7);
  }
  ss_00 = local_58;
  puVar2 = local_60;
  columns_00 = local_68;
  (this->super).needsRedraw = true;
  *(undefined8 *)(local_60 + -8) = 0x11b3e2;
  ColumnsPanel_fill(this,ss_00,columns_00);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar2 + -8) = 0x11b408;
    __stack_chk_fail();
  }
  return this;
}

