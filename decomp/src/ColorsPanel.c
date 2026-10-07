#include "htop.h"

/* ColorsPanel_eventHandler @ 0x116530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HandlerResult ColorsPanel_eventHandler(ColorsPanel_ *super,int ch)

{
  int colorScheme;
  Object **ppOVar1;
  long lVar2;
  undefined1 *puVar3;
  Object *pOVar4;
  ObjectClass *pOVar5;
  Settings_4 *pSVar6;
  long lVar7;

  if (ch != 296) {
    if (ch < 297) {
      if (0x16 < (uint)(ch + -10)) {
        return IGNORED;
      }
      if ((0x100002400U >> ((ulong)(uint)ch & 0x3f) & 1) == 0) {
        return IGNORED;
      }
    }
    else if ((ch != 343) && (ch != 409)) {
      return IGNORED;
    }
  }
                    /* Unresolved local var: ColorsPanel * this@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: int mark@[???]
                       Unresolved local var: int i@[???] */
  colorScheme = (super->super).selected;
  ppOVar1 = ((super->super).items)->array;
  lVar7 = 0;
  do {
    while( true ) {
      lVar2 = *(long *)((long)ppOVar1 + lVar7);
      puVar3 = *(undefined1 **)(lVar2 + 0x10);
      if (puVar3 != (undefined1 *)0x0) break;
      *(undefined1 *)(lVar2 + 0x18) = 0;
      lVar2 = lVar7 + 8;
      lVar7 = lVar7 + 8;
      if (*(long *)((long)ColorSchemeNames + lVar2) == 0) goto LAB_001165b2;
    }
    *puVar3 = 0;
    lVar2 = lVar7 + 8;
    lVar7 = lVar7 + 8;
  } while (*(long *)((long)ColorSchemeNames + lVar2) != 0);
LAB_001165b2:
  pOVar4 = ppOVar1[colorScheme];
  pOVar5 = pOVar4[2].klass;
  if (pOVar5 == (ObjectClass *)0x0) {
    *(undefined1 *)&pOVar4[3].klass = 1;
  }
  else {
    *(undefined1 *)&pOVar5->extends = 1;
  }
  pSVar6 = super->settings;
  pSVar6->lastUpdate = pSVar6->lastUpdate + 1;
  pSVar6->colorScheme = colorScheme;
  pSVar6->changed = true;
  CRT_setColors(colorScheme);
  wclear(_stdscr);
  return REDRAW|HANDLED;
}


/* ColorsPanel_delete @ 0x117730 */

void ColorsPanel_delete(void *param_1)

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


/* ColorsPanel_new @ 0x118c50 */

/* WARNING: Removing unreachable block (ram,0x00118cfa) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00118d17 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ColorsPanel * ColorsPanel_new(Settings *settings)

{
  undefined1 __frame[0x118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xd8;
  int wVar1;
  Vector *this;
  Object *pOVar2;
  ObjectClass *pOVar3;
  int len;
  int iVar4;
  ColorsPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar5;
  undefined8 *data_;
  Settings **ppSVar6;
  cchar_t *pcVar7;
  int *pwVar8;
  char **ppcVar9;
  char *pcVar10;
  long in_FS_OFFSET = (long)__fake_fs;

  ppSVar6 = &(*(Settings *(*))(__fp - 0x68));
                    /* Unresolved local var: void * data@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(Settings *(*))(__fp - 0x68)) = settings;
  this_00 = malloc(0x26e8);
  if (this_00 != (ColorsPanel *)0x0) {
    (this_00->super).super.klass = &ColorsPanel_class.super;
    fuBar = FunctionBar_new(ColorsFunctions,(char **)0x0,(int *)0x0);
    Panel_init(&this_00->super,1,1,1,1,&CheckItem_class.super,true,fuBar);
    this_00->settings = (Settings_4 *)(*(Settings *(*))(__fp - 0x68));
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[37455] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x60)) = (undefined1 *)&(*(Settings *(*))(__fp - 0x68));
    pwVar8 = (*(int (*) [4])(__fp - 0x88));
    (*(undefined1 *(*))(__fp - 0x60)) = (undefined1 *)&(*(Settings *(*))(__fp - 0x68));
    sVar5 = mbstowcs((*(int (*) [4])(__fp - 0x88)),((char *)(long)&s_Colors_00147246 /* "Colors" */),6);
    len = (int)sVar5;
    if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(this_00->super).header,len);
      (*(attr_t (*))(__fp - 0x54)) = wVar1 & 0xffffff;
      (*(int *(*))(__fp - 0x50)) = (*(int (*) [4])(__fp - 0x88)) + (ulong)(uint)(len + -1) + 1;
      pcVar7 = (this_00->super).header.chptr;
      do {
        wVar1 = *pwVar8;
        iVar4 = iswprint(wVar1);
        pcVar7->attr = 0;
        pcVar7->chars[0] = 0;
        pcVar7->chars[1] = 0;
        pcVar7->chars[2] = 0;
        if (iVar4 == 0) {
          wVar1 = 65533;
        }
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar7->chars + 2)) = (undefined16)0x0;
        pwVar8 = pwVar8 + 1;
        pcVar7->attr = (*(attr_t (*))(__fp - 0x54));
        pcVar7->chars[0] = wVar1;
        pcVar7 = pcVar7 + 1;
      } while ((*(int *(*))(__fp - 0x50)) != pwVar8);
    }
    ppSVar6 = (Settings **)(*(undefined1 *(*))(__fp - 0x60));
    (this_00->super).needsRedraw = true;
                    /* Unresolved local var: int i@[???] */
    ppcVar9 = ColorSchemeNames;
    pcVar10 = ((char *)(long)&s_Default_0014723e /* "Default" */);
    while( true ) {
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
      ppcVar9 = ppcVar9 + 1;
      data_ = malloc(0x20);
      if (data_ == (undefined8 *)0x0) break;
      *data_ = &CheckItem_class;
                    /* Unresolved local var: char * data@[???] */
      pcVar10 = strdup(pcVar10);
      if (pcVar10 == (char *)0x0) break;
      this = (this_00->super).items;
      data_[1] = pcVar10;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
      *(undefined1 *)(data_ + 3) = 0;
      data_[2] = 0;
      wVar1 = this->items;
      Vector_set(this,wVar1,data_);
      pcVar10 = *ppcVar9;
      (this_00->super).needsRedraw = true;
      if (pcVar10 == (char *)0x0) {
        pOVar2 = ((this_00->super).items)->array[(*(Settings *(*))(__fp - 0x68))->colorScheme];
        pOVar3 = pOVar2[2].klass;
        if (pOVar3 == (ObjectClass *)0x0) {
          *(undefined1 *)&pOVar2[3].klass = 1;
        }
        else {
          *(undefined1 *)&pOVar3->extends = 1;
        }
        if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return this_00;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

