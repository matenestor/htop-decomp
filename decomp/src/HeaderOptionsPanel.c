#include "htop.h"

/* HeaderOptionsPanel_delete_lto_priv_0 @ 0x126c50 */

void HeaderOptionsPanel_delete_lto_priv_0(void *param_1)

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


/* HeaderOptionsPanel_eventHandler @ 0x126f40 */

HandlerResult HeaderOptionsPanel_eventHandler(HeaderOptionsPanel_ *super,int ch)

{
  uint64_t *puVar1;
  int hLayout;
  Object **ppOVar2;
  Object *pOVar3;
  ObjectClass *pOVar4;
  Settings_4 *pSVar5;
  ScreenManager *this;
  Object **ppOVar6;

  if (ch != 296) {
    if (ch < 297) {
      if ((0x16 < (uint)(ch + -10)) ||
         ((0x100002400U >> ((ulong)(uint)ch & 0x3f) & 1) == 0)) {
        return IGNORED;
      }
    }
    else if ((ch != 343) && (ch != 409)) {
      return IGNORED;
    }
  }
                    /* Unresolved local var: HeaderOptionsPanel * this@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: int mark@[???]
                       Unresolved local var: int i@[???] */
  hLayout = (super->super).selected;
  ppOVar2 = ((super->super).items)->array;
  ppOVar6 = ppOVar2;
  do {
    while( true ) {
      pOVar3 = *ppOVar6;
      pOVar4 = pOVar3[2].klass;
      if (pOVar4 != (ObjectClass *)0x0) break;
      ppOVar6 = ppOVar6 + 1;
      *(undefined1 *)&pOVar3[3].klass = 0;
      if (ppOVar6 == ppOVar2 + 0xc) goto LAB_00126fbd;
    }
    ppOVar6 = ppOVar6 + 1;
    *(undefined1 *)&pOVar4->extends = 0;
  } while (ppOVar6 != ppOVar2 + 0xc);
LAB_00126fbd:
  pOVar4 = ppOVar2[hLayout][2].klass;
  if (pOVar4 == (ObjectClass *)0x0) {
    *(undefined1 *)&ppOVar2[hLayout][3].klass = 1;
  }
  else {
    *(undefined1 *)&pOVar4->extends = 1;
  }
  Header_setLayout((Header *)super->scr->header,hLayout);
  pSVar5 = super->settings;
  this = (ScreenManager *)super->scr;
  puVar1 = &pSVar5->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar5->changed = true;
  ScreenManager_resize(this);
  return HANDLED;
}


/* HeaderOptionsPanel_new @ 0x127050 */

/* WARNING: Removing unreachable block (ram,0x00127103) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00127120 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

HeaderOptionsPanel * HeaderOptionsPanel_new(Settings_4 *settings,ScreenManager_3 *scr)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  int wVar1;
  Vector *this;
  Object *pOVar2;
  ObjectClass *pOVar3;
  int len;
  int iVar4;
  HeaderOptionsPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar5;
  undefined8 *data_;
  char *pcVar6;
  cchar_t *pcVar7;
  char **ppcVar8;
  undefined1 *puVar9;
  int *pwVar10;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * data@[???] */
  puVar9 = (*(undefined1 (*) [8])(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(ScreenManager_3 *(*))(__fp - 0x60)) = scr;
  this_00 = malloc(0x26f0);
  if (this_00 != (HeaderOptionsPanel *)0x0) {
    (this_00->super).super.klass = &HeaderOptionsPanel_class.super;
    fuBar = FunctionBar_new(HeaderOptionsFunctions,(char **)0x0,(int *)0x0);
    Panel_init(&this_00->super,1,1,1,1,&CheckItem_class.super,true,fuBar);
    this_00->settings = settings;
    this_00->scr = (*(ScreenManager_3 *(*))(__fp - 0x60));
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[35747] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x58)) = (*(undefined1 (*) [8])(__fp - 0x68));
    pwVar10 = (*(int (*) [12])(__fp - 0xa8));
    (*(undefined1 *(*))(__fp - 0x58)) = (*(undefined1 (*) [8])(__fp - 0x68));
    sVar5 = mbstowcs((*(int (*) [12])(__fp - 0xa8)),((char *)(long)&s_Header_Layout_0014882e /* "Header Layout" */),0xd);
    len = (int)sVar5;
    if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(this_00->super).header,len);
      (*(attr_t (*))(__fp - 0x4c)) = wVar1 & 0xffffff;
      pcVar7 = (this_00->super).header.chptr;
      do {
        wVar1 = *pwVar10;
        iVar4 = iswprint(wVar1);
        pcVar7->attr = 0;
        pcVar7->chars[0] = 0;
        pcVar7->chars[1] = 0;
        pcVar7->chars[2] = 0;
        if (iVar4 == 0) {
          wVar1 = 65533;
        }
        pwVar10 = pwVar10 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar7->chars + 2)) = (undefined16)0x0;
        pcVar7->attr = (*(attr_t (*))(__fp - 0x4c));
        pcVar7->chars[0] = wVar1;
        pcVar7 = pcVar7 + 1;
      } while (pwVar10 != (*(int (*) [12])(__fp - 0xa8)) + (ulong)(uint)(len + -1) + 1);
    }
    puVar9 = (*(undefined1 *(*))(__fp - 0x58));
    (this_00->super).needsRedraw = true;
    ppcVar8 = &HeaderLayout_layouts_0__description;
                    /* Unresolved local var: int i@[???] */
    while( true ) {
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
      pcVar6 = *ppcVar8;
      data_ = malloc(0x20);
      if (data_ == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
      *data_ = &CheckItem_class;
      pcVar6 = strdup(pcVar6);
      if (pcVar6 == (char *)0x0) break;
      this = (this_00->super).items;
      data_[1] = pcVar6;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
      ppcVar8 = ppcVar8 + 3;
      *(undefined1 *)(data_ + 3) = 0;
      data_[2] = 0;
      wVar1 = this->items;
      Vector_set(this,wVar1,data_);
      (this_00->super).needsRedraw = true;
      if (ppcVar8 == AvailableColumnsFunctions + 2) {
        pOVar2 = ((this_00->super).items)->array[(*(ScreenManager_3 *(*))(__fp - 0x60))->header->headerLayout];
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

