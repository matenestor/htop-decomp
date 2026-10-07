#include "htop.h"

/* CategoriesPanel_delete @ 0x1176d0 */

void CategoriesPanel_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(Vector **)((long)param_1 + 0x20));
  FunctionBar_delete(*(FunctionBar **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* CategoriesPanel_new @ 0x118a20 */

/* WARNING: Removing unreachable block (ram,0x00118adb) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00118af8 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

CategoriesPanel * CategoriesPanel_new(ScreenManager_3 *scr,Header_4 *header,Machine_2 *host)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  int wVar1;
  Vector *this;
  ScreenManager *this_00;
  int wVar2;
  int iVar3;
  CategoriesPanel *this_01;
  FunctionBar *fuBar;
  size_t sVar4;
  undefined8 *data_;
  char *pcVar5;
  undefined1 *puVar6;
  CategoriesPanelPage *pCVar7;
  cchar_t *pcVar8;
  int *pwVar9;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar6 = (*(undefined1 (*) [8])(__fp - 0x68));
                    /* Unresolved local var: void * data@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(ScreenManager *(*))(__fp - 0x60)) = (ScreenManager *)scr;
  this_01 = malloc(0x26f8);
  if (this_01 != (CategoriesPanel *)0x0) {
    (this_01->super).super.klass = &CategoriesPanel_class.super;
    fuBar = FunctionBar_new(CategoriesFunctions,(char **)0x0,(int *)0x0);
    Panel_init(&this_01->super,1,1,1,1,&ListItem_class,true,fuBar);
    this_01->header = (Header_2 *)header;
    this_01->host = (Machine *)host;
    this_01->scr = (*(ScreenManager *(*))(__fp - 0x60));
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[35903] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x58)) = (*(undefined1 (*) [8])(__fp - 0x68));
    pwVar9 = (*(int (*) [8])(__fp - 0x98));
    (*(undefined1 *(*))(__fp - 0x58)) = (*(undefined1 (*) [8])(__fp - 0x68));
    sVar4 = mbstowcs((*(int (*) [8])(__fp - 0x98)),((char *)(long)&s_Categories_00147233 /* "Categories" */),10);
    wVar2 = (int)sVar4;
    if (0 < wVar2) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(this_01->super).header,wVar2);
      (*(int *(*))(__fp - 0x50)) = (*(int (*) [8])(__fp - 0x98)) + (ulong)(uint)(wVar2 + -1) + 1;
      pcVar8 = (this_01->super).header.chptr;
      do {
        wVar2 = *pwVar9;
        iVar3 = iswprint(wVar2);
        pcVar8->attr = 0;
        pcVar8->chars[0] = 0;
        pcVar8->chars[1] = 0;
        pcVar8->chars[2] = 0;
        if (iVar3 == 0) {
          wVar2 = 65533;
        }
        pwVar9 = pwVar9 + 1;
        pcVar8->attr = wVar1 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar8->chars + 2)) = (undefined16)0x0;
        pcVar8->chars[0] = wVar2;
        pcVar8 = pcVar8 + 1;
      } while (pwVar9 != (*(int *(*))(__fp - 0x50)));
    }
    puVar6 = (*(undefined1 *(*))(__fp - 0x58));
    (this_01->super).needsRedraw = true;
    pCVar7 = categoriesPanelPages;
                    /* Unresolved local var: size_t i@[???] */
    while( true ) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      pcVar5 = pCVar7->name;
      data_ = malloc(0x18);
      if (data_ == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
      *data_ = &ListItem_class;
      pcVar5 = strdup(pcVar5);
      if (pcVar5 == (char *)0x0) break;
      this = (this_01->super).items;
      data_[1] = pcVar5;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
      pCVar7 = pCVar7 + 1;
      *(undefined4 *)(data_ + 2) = 0;
      *(undefined1 *)((long)data_ + 0x14) = 0;
      wVar1 = this->items;
      Vector_set(this,wVar1,data_);
      this_00 = (*(ScreenManager *(*))(__fp - 0x60));
      (this_01->super).needsRedraw = true;
      if (pCVar7 == (CategoriesPanelPage *)&DAT_00155f90) {
        wVar1 = (*(ScreenManager *(*))(__fp - 0x60))->panels->items;
        ScreenManager_insert(this_00,&this_01->super,16,wVar1);
        CategoriesPanel_makeDisplayOptionsPage(this_01);
        if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return this_01;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* CategoriesPanel_makeColorsPage @ 0x118e70 */

/* DWARF original prototype: void CategoriesPanel_makeColorsPage(CategoriesPanel * this) */

void CategoriesPanel_makeColorsPage(CategoriesPanel *this)

{
  ColorsPanel *item;

  item = ColorsPanel_new((Settings *)this->host->settings);
  ScreenManager_insert(this->scr,&item->super,-1,this->scr->panels->items);
  return;
}


/* CategoriesPanel_makeDisplayOptionsPage @ 0x119aa0 */

/* DWARF original prototype: void CategoriesPanel_makeDisplayOptionsPage(CategoriesPanel * this) */

void CategoriesPanel_makeDisplayOptionsPage(CategoriesPanel *this)

{
  DisplayOptionsPanel *item;

  item = DisplayOptionsPanel_new((Settings_4 *)this->host->settings,(ScreenManager_3 *)this->scr);
  ScreenManager_insert(this->scr,&item->super,-1,this->scr->panels->items);
  return;
}


/* CategoriesPanel_makeMetersPage @ 0x11cb80 */

/* DWARF original prototype: void CategoriesPanel_makeMetersPage(CategoriesPanel * this) */

void CategoriesPanel_makeMetersPage(CategoriesPanel *this)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  Settings__2 *settings;
  MetersPanel_2 *pMVar2;
  MetersPanel **meterPanels;
  MetersPanel_2 *item;
  AvailableMetersPanel *item_00;
  Machine *host;
  ScreenManager *scr;
  ulong columns;
  ulong uVar3;
  ulong va0;
  long in_FS_OFFSET = (long)__fake_fs;

  scr = this->scr;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  columns = (ulong)HeaderLayout_layouts[scr->header->headerLayout].columns;
                    /* Unresolved local var: void * data@[???] */
  meterPanels = malloc(columns * 8);
  if (meterPanels == (MetersPanel **)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  host = this->host;
  settings = host->settings;
                    /* Unresolved local var: size_t i@[???] */
  if (columns != 0) {
    uVar3 = 0;
    do {
      va0 = uVar3 + 1;
      xSnprintf((*(char (*) [32])(__fp - 0x68)),0x20,((char *)(long)&s_Column__zu_001474eb /* "Column %zu" */),va0);
      item = MetersPanel_new((Settings_4 *)settings,(*(char (*) [32])(__fp - 0x68)),this->header->columns[uVar3],
                             (ScreenManager_3 *)this->scr);
      meterPanels[uVar3] = (MetersPanel *)item;
      if (uVar3 != 0) {
        pMVar2 = (MetersPanel_2 *)meterPanels[uVar3 - 1];
        item->leftNeighbor = pMVar2;
        item = (MetersPanel_2 *)meterPanels[uVar3];
        pMVar2->rightNeighbor = item;
      }
      ScreenManager_insert(this->scr,&item->super,20,this->scr->panels->items);
      uVar3 = va0;
    } while (va0 != columns);
    scr = this->scr;
    host = this->host;
  }
  item_00 = AvailableMetersPanel_new
                      ((Machine_4 *)host,(Header_3 *)this->header,columns,meterPanels,
                       (ScreenManager_2 *)scr);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    ScreenManager_insert(this->scr,&item_00->super,-1,this->scr->panels->items);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* CategoriesPanel_makeScreensPage @ 0x11cd00 */

/* DWARF original prototype: void CategoriesPanel_makeScreensPage(CategoriesPanel * this) */

void CategoriesPanel_makeScreensPage(CategoriesPanel *this)

{
  ColumnsPanel *item;
  AvailableColumnsPanel *item_00;
  ScreensPanel *item_01;

  item_01 = ScreensPanel_new((Settings_3 *)this->host->settings);
  item = item_01->columns;
  item_00 = item_01->availableColumns;
  ScreenManager_insert(this->scr,&item_01->super,20,this->scr->panels->items);
  ScreenManager_insert(this->scr,&item->super,20,this->scr->panels->items);
  ScreenManager_insert(this->scr,&item_00->super,-1,this->scr->panels->items);
  return;
}


/* CategoriesPanel_makeHeaderOptionsPage @ 0x11cd90 */

/* DWARF original prototype: void CategoriesPanel_makeHeaderOptionsPage(CategoriesPanel * this) */

void CategoriesPanel_makeHeaderOptionsPage(CategoriesPanel *this)

{
  HeaderOptionsPanel *item;

  item = HeaderOptionsPanel_new((Settings_4 *)this->host->settings,(ScreenManager_3 *)this->scr);
  ScreenManager_insert(this->scr,&item->super,-1,this->scr->panels->items);
  return;
}


/* CategoriesPanel_eventHandler @ 0x11cde0 */

HandlerResult CategoriesPanel_eventHandler(CategoriesPanel_ *super,int ch)

{
  int wVar1;
  int wVar2;
  HandlerResult HVar3;
  ushort **ppuVar4;
  long in_RCX;
  long in_RDX;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  int wVar5;
  undefined4 in_register_00000034;
  long a1;
  ScreenManager *this;
  long in_R8;
  long in_R9;
  bool bVar6;

                    /* Unresolved local var: CategoriesPanel * this@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: int selected@[???] */
  a1 = CONCAT44(in_register_00000034,ch);
  wVar1 = (super->super).selected;
  if (ch != 14) {
    if (ch < 15) {
      if (ch == -1) goto LAB_0011ce18;
LAB_0011ced0:
      if (0xfd < (uint)(ch + -1)) {
        return IGNORED;
      }
      ppuVar4 = __ctype_b_loc();
      a1 = (long)ch;
      if (-1 < (short)(*ppuVar4)[a1]) {
        return IGNORED;
      }
      HVar3 = Panel_selectByTyping(&super->super,ch);
      if (HVar3 == BREAK_LOOP) {
        return IGNORED;
      }
      in_RDX = extraout_RDX_01;
      if (HVar3 != HANDLED) {
        return HVar3;
      }
      goto LAB_0011ce18;
    }
    if (ch != 262) {
      if (ch < 263) {
        if ((ch != 16) && (1 < (uint)(ch + -258))) goto LAB_0011ced0;
      }
      else if (ch < 340) {
        if (ch < 338) {
          return IGNORED;
        }
      }
      else if (ch != 360) {
        return IGNORED;
      }
    }
  }
                    /* Unresolved local var: int previous@[???] */
  Panel_onKey(&super->super,ch);
  wVar2 = (super->super).selected;
  bVar6 = wVar1 == wVar2;
  in_RDX = extraout_RDX_00;
  wVar1 = wVar2;
  if (bVar6) {
    return IGNORED;
  }
LAB_0011ce18:
                    /* Unresolved local var: int size@[???] */
  this = super->scr;
  wVar2 = this->panelCount;
                    /* Unresolved local var: int i@[???] */
  if (1 < wVar2) {
    wVar5 = 1;
    while( true ) {
      a1 = 1;
      wVar5 = wVar5 + 1;
      ScreenManager_remove(this,1);
      in_RDX = extraout_RDX;
      if (wVar5 == wVar2) break;
      this = super->scr;
    }
  }
  if ((uint)wVar1 < 5) {
    (*(code *)(categoriesPanelPages[wVar1].ctor))(super,a1,in_RDX,in_RCX,in_R8,in_R9);
  }
  return HANDLED;
}

