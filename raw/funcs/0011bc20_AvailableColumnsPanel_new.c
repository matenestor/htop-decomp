/* AvailableColumnsPanel_new @ 0011bc20 size 486 */

/* WARNING: Removing unreachable block (ram,0x0011bcbf) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x0011bcdc */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

AvailableColumnsPanel * AvailableColumnsPanel_new(Panel *columns,Hashtable_2 *dynamicColumns)

{
  wchar_t wVar1;
  ht_key_t key;
  Vector *this;
  void *value;
  undefined1 *puVar2;
  wchar_t len;
  int iVar3;
  AvailableColumnsPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar4;
  cchar_t *pcVar5;
  ulong uVar6;
  wchar_t *pwVar7;
  long in_FS_OFFSET;
  wchar_t local_b8 [16];
  Panel *local_68;
  undefined1 *local_60;
  attr_t local_54;
  wchar_t *local_50;
  long local_40;

                    /* Unresolved local var: void * data@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = columns;
  this_00 = malloc(0x26e8);
  if (this_00 == (AvailableColumnsPanel *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this_00->super).super.klass = &AvailableColumnsPanel_class.super;
  fuBar = FunctionBar_new(AvailableColumnsFunctions,(char **)0x0,(wchar_t *)0x0);
  Panel_init(&this_00->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
  wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[67822] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  local_60 = (undefined1 *)&local_68;
  pwVar7 = local_b8;
  local_60 = (undefined1 *)&local_68;
  sVar4 = mbstowcs(local_b8,((char *)0x14743c /* "Available Columns" */),0x11);
  len = (wchar_t)sVar4;
  if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    RichString_setLen(&(this_00->super).header,len);
    local_54 = wVar1 & 0xffffff;
    local_50 = local_b8 + (ulong)(uint)(len + L'\xffffffff') + 1;
    pcVar5 = (this_00->super).header.chptr;
    do {
      wVar1 = *pwVar7;
      iVar3 = iswprint(wVar1);
      pcVar5->attr = 0;
      pcVar5->chars[0] = L'\0';
      pcVar5->chars[1] = L'\0';
      pcVar5->chars[2] = L'\0';
      if (iVar3 == 0) {
        wVar1 = L'�';
      }
      *(undefined1 (*) [16])(pcVar5->chars + 2) = (undefined1  [16])0x0;
      pwVar7 = pwVar7 + 1;
      pcVar5->attr = local_54;
      pcVar5->chars[0] = wVar1;
      pcVar5 = pcVar5 + 1;
    } while (local_50 != pwVar7);
  }
  puVar2 = local_60;
  (this_00->super).needsRedraw = true;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: size_t i@[???] */
  uVar6 = 0;
  this = (this_00->super).items;
  this_00->columns = local_68;
  *(undefined8 *)(local_60 + -8) = 0x11bd8c;
  Vector_prune(this);
  (this_00->super).scrollV = L'\0';
  (this_00->super).selected = L'\0';
  (this_00->super).oldSelected = L'\0';
  (this_00->super).needsRedraw = true;
  *(undefined8 *)(puVar2 + -8) = 0x11bda7;
  AvailableColumnsPanel_addPlatformColumns(this_00);
  if (dynamicColumns->size != 0) {
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
      value = dynamicColumns->buckets[uVar6].value;
      if (value != (void *)0x0) {
        key = dynamicColumns->buckets[uVar6].key;
        *(undefined8 *)(puVar2 + -8) = 0x11bdd1;
        AvailableColumnsPanel_addDynamicColumn(key,value,this_00);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < dynamicColumns->size);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar2 + -8) = 0x11be01;
    __stack_chk_fail();
  }
  return this_00;
}

