#include "htop.h"

/* ScreenTabsPanel_delete_lto_priv_0 @ 0x12eb10 */

void ScreenTabsPanel_delete_lto_priv_0(void *param_1)

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


/* ScreenNamesPanel_delete @ 0x12eb70 */

void ScreenNamesPanel_delete(ScreenNamesPanel_ *object)

{
  Object **ppOVar1;
  int wVar2;
  Vector *pVVar3;
  Object *pOVar4;
  Object **ppOVar5;

  pVVar3 = (object->super).items;
  wVar2 = pVVar3->items;
                    /* Unresolved local var: int i@[???] */
  if (0 < wVar2) {
    ppOVar5 = pVVar3->array;
    ppOVar1 = ppOVar5 + wVar2;
    do {
                    /* Unresolved local var: ScreenNameListItem * item@[???] */
      pOVar4 = *ppOVar5;
      ppOVar5 = ppOVar5 + 1;
      pOVar4[3].klass = (ObjectClass *)0x0;
    } while (ppOVar5 != ppOVar1);
  }
  if (object->renamingItem != (ListItem *)0x0) {
    object->renamingItem->value = object->saved;
  }
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if ((object->super).header.chlen < 351) {
    free(object);
    return;
  }
  free((object->super).header.chptr);
  free(object);
  return;
}


/* ScreenNameListItem_new @ 0x132410 */

ScreenNameListItem * ScreenNameListItem_new(char *value,ScreenSettings_4 *ss)

{
  ScreenNameListItem *pSVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pSVar1 = malloc(0x20);
  if (pSVar1 != (ScreenNameListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pSVar1->super).super.klass = &ScreenNameListItem_class;
    pcVar2 = strdup(value);
    if (pcVar2 != (char *)0x0) {
      (pSVar1->super).value = pcVar2;
      (pSVar1->super).key = 0;
      (pSVar1->super).moving = false;
      pSVar1->ss = ss;
      return pSVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ScreenNamesPanel_new @ 0x133970 */

/* WARNING: Removing unreachable block (ram,0x00133a58) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133a75 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ScreenNamesPanel * ScreenNamesPanel_new(Settings_3 *settings)

{
  undefined1 __frame[0x118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xd8;
  int wVar1;
  uint uVar2;
  ScreenSettings_4 *pSVar3;
  Vector *this;
  int len;
  int iVar4;
  ScreenNamesPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar5;
  undefined8 *data_;
  char *pcVar6;
  undefined1 *puVar7;
  cchar_t *pcVar8;
  long lVar9;
  int *pwVar10;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * data@[???] */
  puVar7 = (*(undefined1 (*) [8])(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = malloc(0x2728);
  if (this_00 == (ScreenNamesPanel *)0x0) {
LAB_00133bc0:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this_00->super).super.klass = &ScreenNamesPanel_class.super;
  fuBar = FunctionBar_new(ScreenNamesFunctions,(char **)0x0,(int *)0x0);
  Panel_init(&this_00->super,1,1,1,1,&ListItem_class,true,fuBar);
  this_00->cursor = 0;
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
                    /* Unresolved local var: int[46317] data@[???]
                       Unresolved local var: int newLen@[???] */
  (*(undefined1 *(*))(__fp - 0x60)) = (*(undefined1 (*) [8])(__fp - 0x68));
  pwVar10 = (*(int (*) [4])(__fp - 0x88));
  (*(undefined1 *(*))(__fp - 0x60)) = (*(undefined1 (*) [8])(__fp - 0x68));
  sVar5 = mbstowcs((*(int (*) [4])(__fp - 0x88)),((char *)(long)&s_Screens_00147c87 /* "Screens" */),7);
  len = (int)sVar5;
  if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(this_00->super).header,len);
    (*(attr_t (*))(__fp - 0x54)) = wVar1 & 0xffffff;
    (*(int *(*))(__fp - 0x50)) = (*(int (*) [4])(__fp - 0x88)) + (ulong)(uint)(len + -1) + 1;
    pcVar8 = (this_00->super).header.chptr;
    do {
      wVar1 = *pwVar10;
      iVar4 = iswprint(wVar1);
      pcVar8->attr = 0;
      pcVar8->chars[0] = 0;
      pcVar8->chars[1] = 0;
      pcVar8->chars[2] = 0;
      if (iVar4 == 0) {
        wVar1 = 65533;
      }
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar8->chars + 2)) = (undefined16)0x0;
      pwVar10 = pwVar10 + 1;
      pcVar8->attr = (*(attr_t (*))(__fp - 0x54));
      pcVar8->chars[0] = wVar1;
      pcVar8 = pcVar8 + 1;
    } while ((*(int *(*))(__fp - 0x50)) != pwVar10);
  }
  puVar7 = (*(undefined1 *(*))(__fp - 0x60));
                    /* Unresolved local var: uint i@[???] */
  uVar2 = settings->nScreens;
  (this_00->super).needsRedraw = true;
  lVar9 = 0;
  if (uVar2 != 0) {
    do {
                    /* Unresolved local var: ScreenSettings * ss@[???] */
      while (pSVar3 = settings->screens[lVar9], pSVar3->dynamic == (char *)0x0) {
                    /* Unresolved local var: ScreenNameListItem * this@[???] */
        (*(int *(*))(__fp - 0x50)) = (int *)pSVar3->heading;
                    /* Unresolved local var: void * data@[???] */
        data_ = malloc(0x20);
        pwVar10 = (*(int *(*))(__fp - 0x50));
        if (data_ == (undefined8 *)0x0) goto LAB_00133bc0;
                    /* Unresolved local var: char * data@[???] */
        *data_ = &ScreenNameListItem_class;
        pcVar6 = strdup((char *)pwVar10);
        if (pcVar6 == (char *)0x0) goto LAB_00133bc0;
        this = (this_00->super).items;
        data_[1] = pcVar6;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
        lVar9 = lVar9 + 1;
        *(undefined4 *)(data_ + 2) = 0;
        *(undefined1 *)((long)data_ + 0x14) = 0;
        wVar1 = this->items;
        data_[3] = pSVar3;
        Vector_set(this,wVar1,data_);
        (this_00->super).needsRedraw = true;
        if (settings->nScreens <= (uint)lVar9) goto LAB_00133b9f;
      }
      lVar9 = lVar9 + 1;
    } while ((uint)lVar9 < settings->nScreens);
  }
LAB_00133b9f:
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return this_00;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ScreenTabsPanel_new @ 0x133bd0 */

/* WARNING: Removing unreachable block (ram,0x00133c94) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133cb1 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ScreenTabsPanel * ScreenTabsPanel_new(Settings_3 *settings)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  int wVar1;
  Vector *pVVar2;
  Hashtable_2 *pHVar3;
  int *__s;
  int wVar4;
  int iVar5;
  ScreenTabsPanel *this;
  FunctionBar *fuBar;
  ScreenNamesPanel *pSVar6;
  size_t sVar7;
  undefined8 *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  int *pwVar11;
  cchar_t *pcVar12;
  ulong uVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar10 = (*(undefined1 (*) [8])(__fp - 0x68));
                    /* Unresolved local var: void * data@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(Settings_3 *(*))(__fp - 0x60)) = settings;
  this = malloc(0x2700);
  if (this != (ScreenTabsPanel *)0x0) {
    (this->super).super.klass = &ScreenTabsPanel_class.super;
    fuBar = FunctionBar_new(ScreenTabsFunctions,(char **)0x0,(int *)0x0);
    Panel_init(&this->super,1,1,1,1,&ListItem_class,true,fuBar);
    this->settings = (*(Settings_3 *(*))(__fp - 0x60));
    pSVar6 = ScreenNamesPanel_new((*(Settings_3 *(*))(__fp - 0x60)));
    (this->super).cursorOn = false;
    this->names = pSVar6;
    this->cursor = 0;
                    /* Unresolved local var: int[47580] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x58)) = (*(undefined1 (*) [8])(__fp - 0x68));
    wVar1 = CRT_colors[7];
    pwVar11 = (*(int (*) [8])(__fp - 0x98));
    (*(undefined1 *(*))(__fp - 0x58)) = (*(undefined1 (*) [8])(__fp - 0x68));
    sVar7 = mbstowcs((*(int (*) [8])(__fp - 0x98)),((char *)(long)&s_Screen_tabs_0014917a /* "Screen tabs" */),0xb);
    wVar4 = (int)sVar7;
    if (0 < wVar4) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(this->super).header,wVar4);
      (*(int *(*))(__fp - 0x50)) = (*(int (*) [8])(__fp - 0x98)) + (ulong)(uint)(wVar4 + -1) + 1;
      pcVar12 = (this->super).header.chptr;
      do {
        wVar4 = *pwVar11;
        iVar5 = iswprint(wVar4);
        pcVar12->attr = 0;
        pcVar12->chars[0] = 0;
        pcVar12->chars[1] = 0;
        pcVar12->chars[2] = 0;
        if (iVar5 == 0) {
          wVar4 = 65533;
        }
        pwVar11 = pwVar11 + 1;
        pcVar12->attr = wVar1 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar12->chars + 2)) = (undefined16)0x0;
        pcVar12->chars[0] = wVar4;
        pcVar12 = pcVar12 + 1;
      } while (pwVar11 != (*(int *(*))(__fp - 0x50)));
    }
    puVar10 = (*(undefined1 *(*))(__fp - 0x58));
    (this->super).needsRedraw = true;
                    /* Unresolved local var: ScreenTabListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    puVar8 = malloc(0x20);
    if (puVar8 != (undefined8 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      *puVar8 = &ScreenTabListItem_class;
      pcVar9 = strdup(((char *)(long)&s_Processes_00149186 /* "Processes" */));
      if (pcVar9 != (char *)0x0) {
        pVVar2 = (this->super).items;
        puVar8[1] = pcVar9;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
                    /* Unresolved local var: size_t i@[???] */
        uVar13 = 0;
        *(undefined4 *)(puVar8 + 2) = 0;
        *(undefined1 *)((long)puVar8 + 0x14) = 0;
        wVar1 = pVVar2->items;
        puVar8[3] = 0;
        Vector_set(pVVar2,wVar1,puVar8);
        (this->super).needsRedraw = true;
        pHVar3 = (*(Settings_3 *(*))(__fp - 0x60))->dynamicScreens;
        if (pHVar3->size != 0) {
          do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
            pwVar11 = pHVar3->buckets[uVar13].value;
            if (pwVar11 != (int *)0x0) {
                    /* Unresolved local var: DynamicScreen * screen@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: char * name@[???] */
                    /* Unresolved local var: ScreenTabListItem * this@[???]
                       Unresolved local var: void * data@[???] */
              (*(int *(*))(__fp - 0x50)) = *(int **)(pwVar11 + 8);
              if (*(int **)(pwVar11 + 8) == (int *)0x0) {
                (*(int *(*))(__fp - 0x50)) = pwVar11;
              }
              puVar8 = malloc(0x20);
              __s = (*(int *(*))(__fp - 0x50));
              if (puVar8 == (undefined8 *)0x0) goto LAB_00133e6a;
                    /* Unresolved local var: char * data@[???] */
              *puVar8 = &ScreenTabListItem_class;
              pcVar9 = strdup((char *)__s);
              if (pcVar9 == (char *)0x0) goto LAB_00133e6a;
              pVVar2 = (this->super).items;
              puVar8[1] = pcVar9;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
              *(undefined4 *)(puVar8 + 2) = 0;
              *(undefined1 *)((long)puVar8 + 0x14) = 0;
              wVar1 = pVVar2->items;
              puVar8[3] = pwVar11;
              Vector_set(pVVar2,wVar1,puVar8);
              (this->super).needsRedraw = true;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < pHVar3->size);
        }
        if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return this;
      }
    }
  }
LAB_00133e6a:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ScreenNamesPanel_eventHandlerNormal @ 0x136840 */

HandlerResult ScreenNamesPanel_eventHandlerNormal(ScreenNamesPanel_ *super,int ch)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  code *a2;
  ListItem *pLVar1;
  char *__src;
  int wVar2;
  HandlerResult HVar3;
  ScreenSettings_4 *pSVar4;
  undefined8 *data_;
  char *pcVar5;
  size_t sVar6;
  ushort **ppuVar7;
  Vector *pVVar8;
  long lVar9;
  long in_R8;
  long in_R9;
  Object *pOVar10;
  Object *pOVar11;
  int wVar12;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: ScreenNamesPanel * this@[???]
                       Unresolved local var: ScreenNameListItem * oldFocus@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: ScreenNameListItem * newFocus@[???] */
  pVVar8 = (super->super).items;
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  wVar12 = pVVar8->items;
  if (wVar12 < 1) {
    if (ch == 262) {
      Panel_onKey(&super->super,262);
LAB_00136ba0:
      HVar3 = IGNORED;
      goto LAB_00136a83;
    }
    if (262 < ch) {
      if (ch < 340) {
        if (ch < 338) {
          pOVar11 = (Object *)0x0;
          pOVar10 = (Object *)0x0;
          if (ch == 269) goto LAB_001368fc;
          if (ch == 296) goto LAB_001368c0;
        }
        else {
LAB_00136cb5:
          Panel_onKey(&super->super,ch);
        }
      }
      else {
        if (ch == 360) {
          ch = 360;
          goto LAB_00136cb5;
        }
        if ((ch == 409) || (ch == 343)) {
LAB_00136ce4:
          pOVar10 = (Object *)0x0;
          goto LAB_001368c0;
        }
      }
      goto LAB_00136ba0;
    }
    if (ch == -1) goto LAB_00136a7e;
    if (-2 < ch) {
      if (ch == 14) {
        pOVar11 = (Object *)0x0;
        goto LAB_001368fc;
      }
      if (14 < ch) {
        pOVar10 = (Object *)0x0;
        if (ch < 255) goto LAB_00136cfc;
        goto LAB_00136ba0;
      }
      if (ch == 10) goto LAB_00136ce4;
      pOVar10 = (Object *)0x0;
      if (ch == 13) goto LAB_001368c0;
    }
    ppuVar7 = __ctype_b_loc();
    if ((*(byte *)((long)*ppuVar7 + (long)ch * 2 + 1) & 4) == 0) goto LAB_00136ba0;
    pOVar10 = (Object *)0x0;
LAB_00136b10:
    HVar3 = Panel_selectByTyping(&super->super,ch);
    pVVar8 = (super->super).items;
    wVar12 = pVVar8->items;
    pOVar11 = pOVar10;
    if (HVar3 == BREAK_LOOP) {
      HVar3 = IGNORED;
    }
LAB_00136a64:
    if (wVar12 < 1) goto LAB_00136a83;
    lVar9 = (long)(super->super).selected;
    pOVar10 = pOVar11;
LAB_00136a6d:
    if ((pVVar8->array[lVar9] == pOVar10) || (pVVar8->array[lVar9] == (Object *)0x0))
    goto LAB_00136a83;
  }
  else {
    lVar9 = (long)(super->super).selected;
    pOVar10 = pVVar8->array[lVar9];
    if (ch == 262) {
      Panel_onKey(&super->super,262);
      lVar9 = (long)(super->super).selected;
LAB_00136c50:
      HVar3 = IGNORED;
      goto LAB_00136a6d;
    }
    pOVar11 = pOVar10;
    if (262 < ch) {
      if (ch < 340) {
        if (ch < 338) {
          if (ch == 269) goto LAB_001368fc;
          if (ch == 296) goto LAB_001368c0;
        }
        else {
          Panel_onKey(&super->super,ch);
          lVar9 = (long)(super->super).selected;
        }
      }
      else if (ch == 360) {
        Panel_onKey(&super->super,360);
        lVar9 = (long)(super->super).selected;
      }
      else if ((ch == 409) || (ch == 343)) {
LAB_001368c0:
        (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
        HVar3 = HANDLED;
        pOVar11 = pOVar10;
        goto LAB_00136a64;
      }
      goto LAB_00136c50;
    }
    if (ch != -1) {
      if (-2 < ch) {
        if (ch == 14) {
LAB_001368fc:
                    /* Unresolved local var: ScreenNamesPanel * this@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: ScreenNameListItem * item@[???]
                       Unresolved local var: int idx@[???] */
          if (super->ds == (DynamicScreen *)0x0) {
            (*(ScreenDefaults (*))(__fp - 0x68)).treeSortKey = (char *)0x0;
            (*(ScreenDefaults (*))(__fp - 0x68)).sortKey = ((char *)(long)&DAT_0014828e /* "PID" */);
            (*(ScreenDefaults (*))(__fp - 0x68)).name = ((char *)(long)&DAT_001491b7 /* "New" */);
            (*(ScreenDefaults (*))(__fp - 0x68)).columns = ((char *)(long)&s_PID_Command_001491bb /* "PID Command" */);
            pSVar4 = Settings_newScreen((Settings *)super->settings,&(*(ScreenDefaults (*))(__fp - 0x68)));
          }
          else {
            pSVar4 = Settings_newDynamicScreen
                               ((Settings *)super->settings,((char *)(long)&DAT_001491b7 /* "New" */),super->ds,(Table_3 *)0x0);
          }
                    /* Unresolved local var: ScreenNameListItem * this@[???]
                       Unresolved local var: void * data@[???] */
          data_ = malloc(0x20);
          if (data_ == (undefined8 *)0x0) {
LAB_00136d57:
                    /* WARNING: Subroutine does not return */
            fail();
          }
                    /* Unresolved local var: char * data@[???] */
          *data_ = &ScreenNameListItem_class;
          pcVar5 = strdup(((char *)(long)&DAT_001491b7 /* "New" */));
          if (pcVar5 == (char *)0x0) goto LAB_00136d57;
          data_[1] = pcVar5;
          wVar12 = (super->super).selected;
          data_[3] = pSVar4;
          pVVar8 = (super->super).items;
          *(undefined4 *)(data_ + 2) = 0;
          wVar12 = wVar12 + 1;
          *(undefined1 *)((long)data_ + 0x14) = 0;
          Vector_insert(pVVar8,wVar12,data_);
                    /* Unresolved local var: int size@[???] */
          pVVar8 = (super->super).items;
          (super->super).needsRedraw = true;
          wVar2 = pVVar8->items;
          if (wVar2 <= wVar12) {
            wVar12 = wVar2 + -1;
          }
          if (wVar12 < 0) {
            wVar12 = 0;
          }
          a2 = (super->super).super.klass[1].extends;
          (super->super).selected = wVar12;
          if (a2 != (code *)0x0) {
            (*a2)((long)super,0xffffffff,(long)a2,(long)pVVar8,in_R8,in_R9);
                    /* Unresolved local var: ScreenNamesPanel * this@[???]
                       Unresolved local var: ListItem * item@[???]
                       Unresolved local var: char * name@[???] */
            pVVar8 = (super->super).items;
            wVar2 = pVVar8->items;
          }
          if (0 < wVar2) {
            wVar12 = (super->super).selected;
            pLVar1 = (ListItem *)pVVar8->array[wVar12];
            if (pLVar1 != (ListItem *)0x0) {
              __src = pLVar1->value;
              (super->super).cursorOn = true;
              pcVar5 = super->buffer;
              super->renamingItem = pLVar1;
              super->saved = __src;
              strncpy(pcVar5,__src,0x14);
              super->buffer[0x14] = '\0';
              sVar6 = strlen(pcVar5);
              super->cursor = (int)sVar6;
              pLVar1->value = pcVar5;
              (super->super).selectionColorId = PANEL_EDIT;
              sVar6 = strlen(pcVar5);
              (super->super).selectedLen = (int)sVar6;
              (super->super).cursorY =
                   ((wVar12 + (super->super).y) - (super->super).scrollV) + 1;
              wVar12 = pVVar8->items;
              (super->super).cursorX = ((int)sVar6 + (super->super).x) - (super->super).scrollH;
              HVar3 = HANDLED;
              goto LAB_00136a64;
            }
          }
          goto LAB_00136a7e;
        }
        if (14 < ch) {
          if (254 < ch) goto LAB_00136c50;
LAB_00136cfc:
          ppuVar7 = __ctype_b_loc();
          HVar3 = IGNORED;
          pOVar11 = pOVar10;
          if ((*(byte *)((long)*ppuVar7 + (long)ch * 2 + 1) & 4) != 0) goto LAB_00136b10;
          goto LAB_00136a64;
        }
        if ((ch == 10) || (ch == 13)) goto LAB_001368c0;
      }
      ppuVar7 = __ctype_b_loc();
      if ((*(byte *)((long)*ppuVar7 + (long)ch * 2 + 1) & 4) != 0) goto LAB_00136b10;
      goto LAB_00136c50;
    }
  }
LAB_00136a7e:
  HVar3 = HANDLED;
LAB_00136a83:
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return HVar3;
}


/* ScreenTabsPanel_eventHandler @ 0x136d60 */

HandlerResult ScreenTabsPanel_eventHandler(ScreenTabsPanel_ *super,int ch)

{
  int wVar1;
  uint uVar2;
  Vector *pVVar3;
  ScreenNamesPanel *this;
  DynamicScreen *__s1;
  Settings_3 *pSVar4;
  ScreenSettings_4 *pSVar5;
  char *pcVar6;
  int iVar7;
  HandlerResult HVar8;
  ushort **ppuVar9;
  Object *pOVar10;
  ObjectClass *pOVar11;
  long lVar12;

  wVar1 = (super->super).selected;
  if (ch < 260) {
    if (ch < 258) {
      if (ch != -1) {
        if (ch == 14) goto LAB_00136de0;
        if (254 < ch) {
          return IGNORED;
        }
        ppuVar9 = __ctype_b_loc();
        if ((*(byte *)((long)*ppuVar9 + (long)ch * 2 + 1) & 4) == 0) {
          return IGNORED;
        }
        HVar8 = Panel_selectByTyping(&super->super,ch);
        if (HVar8 == BREAK_LOOP) {
          return IGNORED;
        }
        if (HVar8 != HANDLED) {
          return HVar8;
        }
      }
      goto LAB_00136e30;
    }
  }
  else {
    if (ch == 269) {
LAB_00136de0:
      HVar8 = ScreenNamesPanel_eventHandlerNormal(super->names,ch);
      return HVar8;
    }
    if (ch < 270) {
      if (ch != 262) {
        return IGNORED;
      }
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
                    /* Unresolved local var: int previous@[???] */
  Panel_onKey(&super->super,ch);
  if (wVar1 == (super->super).selected) {
    return IGNORED;
  }
LAB_00136e30:
                    /* Unresolved local var: ScreenTabListItem * focus@[???] */
  pVVar3 = (super->super).items;
  if ((0 < pVVar3->items) &&
     (pOVar10 = pVVar3->array[(super->super).selected], pOVar10 != (Object *)0x0)) {
    this = super->names;
    __s1 = (DynamicScreen *)pOVar10[3].klass;
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: uint i@[???] */
    lVar12 = 0;
    pSVar4 = this->settings;
    Vector_prune((this->super).items);
    (this->super).selected = 0;
    (this->super).oldSelected = 0;
    uVar2 = pSVar4->nScreens;
    (this->super).scrollV = 0;
    (this->super).needsRedraw = true;
    if (uVar2 != 0) {
      do {
        while( true ) {
          pSVar5 = pSVar4->screens[lVar12];
          pcVar6 = pSVar5->dynamic;
          if (__s1 == (DynamicScreen *)0x0) break;
                    /* Unresolved local var: ScreenSettings * ss@[???] */
          if ((pcVar6 != (char *)0x0) && (iVar7 = strcmp((char *)__s1,pcVar6), iVar7 == 0)) {
LAB_00136ea9:
            pcVar6 = pSVar5->heading;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
            pOVar10 = malloc(0x18);
            if (pOVar10 == (Object *)0x0) {
LAB_00136f9f:
                    /* WARNING: Subroutine does not return */
              fail();
            }
                    /* Unresolved local var: char * data@[???] */
            pOVar10->klass = &ListItem_class;
            pOVar11 = (ObjectClass *)strdup(pcVar6);
            if (pOVar11 == (ObjectClass *)0x0) goto LAB_00136f9f;
            pOVar10[1].klass = pOVar11;
            *(int *)&pOVar10[2].klass = (int)lVar12;
            *(undefined1 *)((long)&pOVar10[2].klass + 4) = 0;
            Panel_add(&this->super,pOVar10);
          }
          lVar12 = lVar12 + 1;
          if (pSVar4->nScreens <= (uint)lVar12) goto LAB_00136f30;
        }
        if (pcVar6 == (char *)0x0) goto LAB_00136ea9;
        lVar12 = lVar12 + 1;
      } while ((uint)lVar12 < pSVar4->nScreens);
    }
LAB_00136f30:
    this->ds = __s1;
  }
  return HANDLED;
}


/* ScreenNamesPanel_eventHandler @ 0x136fb0 */

HandlerResult ScreenNamesPanel_eventHandler(ScreenNamesPanel_ *super,int ch)

{
  uint64_t *puVar1;
  Vector *pVVar2;
  Object *pOVar3;
  ObjectClass *pOVar4;
  Settings_3 *pSVar5;
  int wVar6;
  HandlerResult HVar7;
  int iVar8;
  size_t sVar9;
  ObjectClass *__s2;
  char *pcVar10;

  if (super->renamingItem == (ListItem *)0x0) {
    HVar7 = ScreenNamesPanel_eventHandlerNormal(super,ch);
    return HVar7;
  }
                    /* Unresolved local var: ScreenNamesPanel * this@[???] */
  if (((uint)(ch + -32) < 0x5f) && (ch != '=')) {
    wVar6 = super->cursor;
    if (18 < wVar6) {
      return HANDLED;
    }
    super->buffer[wVar6] = (char)ch;
    super->cursor = wVar6 + 1;
    goto LAB_00137041;
  }
  if (ch == 27) {
                    /* Unresolved local var: ListItem * item@[???] */
    pVVar2 = (super->super).items;
    if (pVVar2->items < 1) {
      return HANDLED;
    }
    pOVar3 = pVVar2->array[(super->super).selected];
    if (pOVar3 == (Object *)0x0) {
      return HANDLED;
    }
    pOVar3[1].klass = (ObjectClass *)super->saved;
    super->renamingItem = (ListItem *)0x0;
    (super->super).cursorOn = false;
    (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
    return HANDLED;
  }
  if (27 < ch) {
    if (ch != 263) {
      if (ch == 343) goto LAB_0013710e;
      if (ch != 127) {
        return HANDLED;
      }
    }
    if (super->cursor < 1) {
      return HANDLED;
    }
    wVar6 = super->cursor + -1;
    super->cursor = wVar6;
    super->buffer[wVar6] = '\0';
LAB_00137041:
    sVar9 = strlen(super->buffer);
    (super->super).selectedLen = (int)sVar9;
    (super->super).cursorX = ((int)sVar9 + (super->super).x) - (super->super).scrollH;
    (super->super).cursorY =
         (((super->super).selected + (super->super).y) - (super->super).scrollV) + 1;
    return HANDLED;
  }
  if ((ch != 10) && (ch != 13)) {
    return HANDLED;
  }
LAB_0013710e:
                    /* Unresolved local var: ListItem * item@[???] */
  pVVar2 = (super->super).items;
  if (pVVar2->items < 1) {
    return HANDLED;
  }
  pOVar3 = pVVar2->array[(super->super).selected];
  if (pOVar3 == (Object *)0x0) {
    return HANDLED;
  }
  free(super->saved);
                    /* Unresolved local var: char * data@[???] */
  __s2 = (ObjectClass *)strdup(super->buffer);
  if (__s2 != (ObjectClass *)0x0) {
    pOVar3[1].klass = __s2;
                    /* Unresolved local var: ScreenNameListItem * nameItem@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: Settings * settings@[???] */
    pOVar4 = pOVar3[3].klass;
    super->renamingItem = (ListItem *)0x0;
    pcVar10 = pOVar4->extends;
    (super->super).cursorOn = false;
    (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
    if ((pcVar10 == (char *)0x0) || (iVar8 = strcmp(pcVar10,(char *)__s2), iVar8 != 0)) {
      free(pcVar10);
                    /* Unresolved local var: char * data@[???] */
      pcVar10 = strdup((char *)__s2);
      if (pcVar10 == (char *)0x0) goto LAB_001371b8;
      pOVar4->extends = pcVar10;
    }
    pSVar5 = super->settings;
    puVar1 = &pSVar5->lastUpdate;
    *puVar1 = *puVar1 + 1;
    pSVar5->changed = true;
    return HANDLED;
  }
LAB_001371b8:
                    /* WARNING: Subroutine does not return */
  fail();
}

