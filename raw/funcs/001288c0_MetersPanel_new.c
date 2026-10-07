/* MetersPanel_new @ 001288c0 size 617 */

MetersPanel_2 *
MetersPanel_new(Settings_4 *settings,char *header,Vector *meters,ScreenManager_3 *scr)

{
  wchar_t wVar1;
  Meter *this;
  Vector *this_00;
  undefined1 *puVar2;
  wchar_t len;
  int iVar3;
  MetersPanel_2 *this_01;
  FunctionBar *fuBar;
  size_t sVar4;
  ulong uVar5;
  ListItem *data_;
  ulong uVar6;
  undefined1 *puVar7;
  cchar_t *pcVar9;
  long lVar10;
  wchar_t *pwVar11;
  long in_FS_OFFSET;
  undefined1 auStack_68 [8];
  undefined1 *local_60;
  wchar_t *local_58;
  undefined8 local_50;
  long local_40;
  undefined1 *puVar8;

                    /* Unresolved local var: void * data@[???] */
  puVar8 = auStack_68;
  puVar7 = auStack_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_01 = malloc(10000);
  if (this_01 == (MetersPanel_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this_01->super).super.klass = &MetersPanel_class.super;
  fuBar = FunctionBar_new(MetersFunctions,MetersKeys,MetersEvents);
  if (Meters_movingBar == (FunctionBar *)0x0) {
    local_50 = fuBar;
    Meters_movingBar = FunctionBar_new(MetersMovingFunctions,MetersMovingKeys,MetersMovingEvents);
    fuBar = local_50;
  }
  Panel_init(&this_01->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
  this_01->scr = scr;
  this_01->settings = settings;
  this_01->meters = meters;
  pwVar11 = CRT_colors;
  this_01->moving = false;
  this_01->leftNeighbor = (MetersPanel_2 *)0x0;
  this_01->rightNeighbor = (MetersPanel_2 *)0x0;
  wVar1 = pwVar11[7];
  sVar4 = strlen(header);
                    /* Unresolved local var: wchar_t[44366] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  uVar6 = (ulong)((int)sVar4 + 1);
  uVar5 = uVar6 * 4 + 0xf;
  puVar2 = auStack_68;
  while (puVar8 != auStack_68 + -(uVar5 & 0xfffffffffffff000)) {
    puVar7 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar8 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar5 = (ulong)((uint)uVar5 & 0xff0);
  lVar10 = -uVar5;
  pwVar11 = (wchar_t *)(puVar7 + lVar10);
  if (uVar5 != 0) {
    *(undefined8 *)(puVar7 + -8) = *(undefined8 *)(puVar7 + -8);
  }
  *(undefined8 *)(puVar7 + lVar10 + -8) = 0x128a0a;
  local_60 = auStack_68;
  uVar5 = __mbstowcs_chk((int *)(puVar7 + lVar10),header,(long)(int)sVar4,uVar6 & 0x3fffffffffffffff
                        );
  len = (wchar_t)uVar5;
  if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar7 + lVar10 + -8) = 0x128a23;
    RichString_setLen(&(this_01->super).header,len);
    local_50 = (FunctionBar *)(CONCAT44(local_50._4_4_,wVar1) & 0xffffffff00ffffff);
    local_58 = (wchar_t *)(puVar7 + (ulong)(uint)(len + L'\xffffffff') * 4 + lVar10 + 4);
    pcVar9 = (this_01->super).header.chptr;
    do {
      wVar1 = *pwVar11;
      *(undefined8 *)(puVar7 + lVar10 + -8) = 0x128a4b;
      iVar3 = iswprint(wVar1);
      pcVar9->attr = 0;
      pcVar9->chars[0] = L'\0';
      pcVar9->chars[1] = L'\0';
      pcVar9->chars[2] = L'\0';
      if (iVar3 == 0) {
        wVar1 = L'�';
      }
      pwVar11 = pwVar11 + 1;
      *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
      pcVar9->attr = (attr_t)local_50;
      pcVar9->chars[0] = wVar1;
      pcVar9 = pcVar9 + 1;
    } while (pwVar11 != local_58);
  }
  puVar7 = local_60;
                    /* Unresolved local var: wchar_t i@[???] */
  wVar1 = meters->items;
  (this_01->super).needsRedraw = true;
  lVar10 = 0;
  if (L'\0' < wVar1) {
    do {
                    /* Unresolved local var: Meter * meter@[???] */
      this = (Meter *)meters->array[lVar10];
      lVar10 = lVar10 + 1;
      *(undefined8 *)(puVar7 + -8) = 0x128aab;
      data_ = Meter_toListItem(this,false);
      this_00 = (this_01->super).items;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      wVar1 = this_00->items;
      *(undefined8 *)(puVar7 + -8) = 0x128aba;
      Vector_set(this_00,wVar1,data_);
      (this_01->super).needsRedraw = true;
    } while ((wchar_t)lVar10 < meters->items);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar7 + -8) = &UNK_00128b38;
    __stack_chk_fail();
  }
  return this_01;
}

