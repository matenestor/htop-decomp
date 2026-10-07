#include "htop.h"

/* ScreenListItem_delete @ 0x12d370 */

void ScreenListItem_delete(ScreenListItem_ *cast)

{
  ScreenSettings_4 *__ptr;

  __ptr = cast->ss;
  if (__ptr != (ScreenSettings_4 *)0x0) {
    free(__ptr->heading);
    free(__ptr->dynamic);
    free(__ptr->fields);
    free(__ptr);
  }
                    /* Unresolved local var: ListItem * this@[???] */
  free((cast->super).value);
  free(cast);
  return;
}


/* ScreensPanel_delete @ 0x12ea80 */

void ScreensPanel_delete(Panel_ *object)

{
  Object **ppOVar1;
  int wVar2;
  Object *pOVar3;
  Object **ppOVar4;

  wVar2 = object->items->items;
                    /* Unresolved local var: int i@[???] */
  if (0 < wVar2) {
    ppOVar4 = object->items->array;
    ppOVar1 = ppOVar4 + wVar2;
    do {
                    /* Unresolved local var: ScreenListItem * item@[???] */
      pOVar3 = *ppOVar4;
      ppOVar4 = ppOVar4 + 1;
      pOVar3[4].klass = (ObjectClass *)0x0;
    } while (ppOVar4 != ppOVar1);
  }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(object->eventHandlerState);
  Vector_delete(object->items);
  FunctionBar_delete(object->defaultBar);
  if ((object->header).chlen < 351) {
    free(object);
    return;
  }
  free((object->header).chptr);
  free(object);
  return;
}


/* ScreenListItem_new @ 0x132270 */

ScreenListItem * ScreenListItem_new(char *value,ScreenSettings_4 *ss)

{
  ScreenListItem *pSVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pSVar1 = malloc(0x28);
  if (pSVar1 != (ScreenListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pSVar1->super).super.klass = &ScreenListItem_class;
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


/* ScreensPanel_update @ 0x1322e0 */

void ScreensPanel_update(ScreensPanel_ *super)

{
  int wVar1;
  Settings_4 *pSVar2;
  long lVar3;
  undefined8 *puVar4;
  char *__s1;
  int iVar5;
  ScreenSettings_3 **ppSVar6;
  char *pcVar7;
  ScreenSettings_3 **ppSVar8;
  ulong uVar9;
  long lVar10;

  pSVar2 = super->settings;
  wVar1 = ((super->super).items)->items;
  ppSVar8 = pSVar2->screens;
  pSVar2->changed = true;
  pSVar2->lastUpdate = pSVar2->lastUpdate + 1;
  uVar9 = (ulong)(wVar1 + 1);
  if (uVar9 >> 0x3d == 0) {
                    /* Unresolved local var: void * data@[???] */
    ppSVar6 = realloc(ppSVar8,uVar9 * 8);
    if (ppSVar6 != (ScreenSettings_3 **)0x0) {
      pSVar2->screens = ppSVar6;
                    /* Unresolved local var: int i@[???] */
      if (wVar1 < 1) {
        ppSVar8 = super->settings->screens;
      }
      else {
        lVar10 = 0;
        do {
                    /* Unresolved local var: ScreenListItem * item@[???]
                       Unresolved local var: ScreenSettings * ss@[???] */
          lVar3 = *(long *)((long)((super->super).items)->array + lVar10);
          puVar4 = *(undefined8 **)(lVar3 + 0x20);
          pcVar7 = *(char **)(lVar3 + 8);
          __s1 = (char *)*puVar4;
          if (__s1 == (char *)0x0) {
LAB_00132393:
            free(__s1);
                    /* Unresolved local var: char * data@[???] */
            pcVar7 = strdup(pcVar7);
            if (pcVar7 == (char *)0x0) goto LAB_001323fd;
            *puVar4 = pcVar7;
          }
          else {
            iVar5 = strcmp(__s1,pcVar7);
            if (iVar5 != 0) goto LAB_00132393;
          }
          ppSVar8 = super->settings->screens;
          *(undefined8 **)((long)ppSVar8 + lVar10) = puVar4;
          lVar10 = lVar10 + 8;
        } while (uVar9 * 8 - 8 != lVar10);
      }
      ppSVar8[uVar9 - 1] = (ScreenSettings_3 *)0x0;
      return;
    }
    free(ppSVar8);
  }
LAB_001323fd:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ScreensPanel_new @ 0x133710 */

/* WARNING: Removing unreachable block (ram,0x00133816) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133833 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ScreensPanel * ScreensPanel_new(Settings_3 *settings)

{
  undefined1 __frame[0x118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xd8;
  int wVar1;
  uint uVar2;
  Hashtable_2 *pHVar3;
  Hashtable_2 *columns;
  ScreenSettings_4 **ppSVar4;
  ScreenSettings_4 *pSVar5;
  Vector *this;
  int len;
  int iVar6;
  ScreensPanel *this_00;
  FunctionBar *fuBar;
  ColumnsPanel *columns_00;
  AvailableColumnsPanel *pAVar7;
  size_t sVar8;
  int *pwVar9;
  char *pcVar10;
  undefined1 *puVar11;
  char **functions;
  cchar_t *pcVar12;
  long lVar13;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * data@[???] */
  puVar11 = (*(undefined1 (*) [8])(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = malloc(0x2730);
  if (this_00 == (ScreensPanel *)0x0) {
LAB_00133964:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  pHVar3 = settings->dynamicScreens;
  columns = settings->dynamicColumns;
  functions = ScreensFunctions;
  (this_00->super).super.klass = &ScreensPanel_class.super;
  if (pHVar3 != (Hashtable_2 *)0x0) {
    functions = DynamicFunctions;
  }
  fuBar = FunctionBar_new(functions,(char **)0x0,(int *)0x0);
  Panel_init(&this_00->super,1,1,1,1,&ListItem_class,true,fuBar);
  ppSVar4 = settings->screens;
  this_00->settings = (Settings_4 *)settings;
  columns_00 = ColumnsPanel_new((ScreenSettings *)*ppSVar4,columns,&settings->changed);
  this_00->columns = columns_00;
  pAVar7 = AvailableColumnsPanel_new(&columns_00->super,columns);
  this_00->moving = false;
  this_00->availableColumns = pAVar7;
  this_00->cursor = 0;
  pwVar9 = CRT_colors;
  (this_00->super).cursorOn = false;
  this_00->renamingItem = (ListItem *)0x0;
                    /* Unresolved local var: int[45057] data@[???]
                       Unresolved local var: int newLen@[???] */
  wVar1 = pwVar9[7];
  (*(undefined1 *(*))(__fp - 0x60)) = (*(undefined1 (*) [8])(__fp - 0x68));
  pwVar9 = (*(int (*) [4])(__fp - 0x88));
  (*(undefined1 *(*))(__fp - 0x60)) = (*(undefined1 (*) [8])(__fp - 0x68));
  sVar8 = mbstowcs((*(int (*) [4])(__fp - 0x88)),((char *)(long)&s_Screens_00147c87 /* "Screens" */),7);
  len = (int)sVar8;
  if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(this_00->super).header,len);
    (*(attr_t (*))(__fp - 0x54)) = wVar1 & 0xffffff;
    (*(int *(*))(__fp - 0x50)) = (*(int (*) [4])(__fp - 0x88)) + (ulong)(uint)(len + -1) + 1;
    pcVar12 = (this_00->super).header.chptr;
    do {
      wVar1 = *pwVar9;
      iVar6 = iswprint(wVar1);
      pcVar12->attr = 0;
      pcVar12->chars[0] = 0;
      pcVar12->chars[1] = 0;
      pcVar12->chars[2] = 0;
      if (iVar6 == 0) {
        wVar1 = 65533;
      }
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar12->chars + 2)) = (undefined16)0x0;
      pwVar9 = pwVar9 + 1;
      pcVar12->attr = (*(attr_t (*))(__fp - 0x54));
      pcVar12->chars[0] = wVar1;
      pcVar12 = pcVar12 + 1;
    } while ((*(int *(*))(__fp - 0x50)) != pwVar9);
  }
  puVar11 = (*(undefined1 *(*))(__fp - 0x60));
                    /* Unresolved local var: uint i@[???] */
  uVar2 = settings->nScreens;
  (this_00->super).needsRedraw = true;
  lVar13 = 0;
  if (uVar2 != 0) {
    do {
                    /* Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: char * name@[???] */
                    /* Unresolved local var: ScreenListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      pSVar5 = settings->screens[lVar13];
      pcVar10 = pSVar5->heading;
      pwVar9 = malloc(0x28);
      if (pwVar9 == (int *)0x0) goto LAB_00133964;
                    /* Unresolved local var: char * data@[???] */
      *(ObjectClass **)pwVar9 = &ScreenListItem_class;
      (*(int *(*))(__fp - 0x50)) = pwVar9;
      pcVar10 = strdup(pcVar10);
      pwVar9 = (*(int *(*))(__fp - 0x50));
      if (pcVar10 == (char *)0x0) goto LAB_00133964;
      this = (this_00->super).items;
      lVar13 = lVar13 + 1;
      *(char **)((*(int *(*))(__fp - 0x50)) + 2) = pcVar10;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
      wVar1 = this->items;
      (*(int *(*))(__fp - 0x50))[4] = 0;
      *(undefined1 *)((*(int *(*))(__fp - 0x50)) + 5) = 0;
      *(ScreenSettings_4 **)((*(int *(*))(__fp - 0x50)) + 8) = pSVar5;
      Vector_set(this,wVar1,pwVar9);
      (this_00->super).needsRedraw = true;
    } while ((uint)lVar13 < settings->nScreens);
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this_00;
}


/* ScreensPanel_eventHandler @ 0x135d60 */

HandlerResult ScreensPanel_eventHandler(ScreensPanel_ *super,int ch)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  Object **ppOVar1;
  Object *pOVar2;
  Object_Display p_Var3;
  Vector *this;
  code *pcVar4;
  Settings_4 *pSVar5;
  Object **ppOVar6;
  void *value;
  bool bVar7;
  _Bool _Var8;
  int wVar9;
  int wVar10;
  HandlerResult HVar11;
  size_t sVar12;
  ObjectClass *pOVar13;
  ushort **ppuVar14;
  ScreenSettings_4 *pSVar15;
  undefined8 *data_;
  char *pcVar16;
  ScreenSettings_3 **ppSVar17;
  long lVar18;
  int wVar19;
  Vector *pVVar20;
  int wVar21;
  Settings *this_00;
  long in_R8;
  ulong uVar22;
  Object *pOVar23;
  AvailableColumnsPanel *this_01;
  Hashtable_2 *columns;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (super->renamingItem != (ListItem *)0x0) {
                    /* Unresolved local var: ScreensPanel * this@[???] */
    if (((uint)(ch + -32) < 0x5f) && (ch != '=')) {
      wVar9 = super->cursor;
      if (wVar9 < 19) {
        super->buffer[wVar9] = (char)ch;
        super->cursor = wVar9 + 1;
LAB_00135eec:
        sVar12 = strlen(super->buffer);
        (super->super).selectedLen = (int)sVar12;
        (super->super).cursorY =
             (((super->super).selected + (super->super).y) - (super->super).scrollV) + 1;
        (super->super).cursorX = ((int)sVar12 + (super->super).x) - (super->super).scrollH;
      }
    }
    else if (ch == 27) {
                    /* Unresolved local var: ListItem * item@[???] */
      pVVar20 = (super->super).items;
      if ((0 < pVVar20->items) &&
         (pOVar23 = pVVar20->array[(super->super).selected], pOVar23 != (Object *)0x0)) {
        pOVar23[1].klass = (ObjectClass *)super->saved;
        super->renamingItem = (ListItem *)0x0;
        (super->super).cursorOn = false;
        (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
      }
    }
    else if (ch < 28) {
      if ((ch == 10) || (ch == 13)) {
LAB_00135f30:
                    /* Unresolved local var: ListItem * item@[???] */
        pVVar20 = (super->super).items;
        if ((0 < pVVar20->items) &&
           (pOVar23 = pVVar20->array[(super->super).selected], pOVar23 != (Object *)0x0)) {
          free(super->saved);
                    /* Unresolved local var: char * data@[???] */
          pOVar13 = (ObjectClass *)strdup(super->buffer);
          if (pOVar13 == (ObjectClass *)0x0) goto LAB_00136752;
          pOVar23[1].klass = pOVar13;
          super->renamingItem = (ListItem *)0x0;
          (super->super).cursorOn = false;
          (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
          ScreensPanel_update(super);
        }
      }
    }
    else {
      if (ch != 263) {
        if (ch == 343) goto LAB_00135f30;
        if (ch != 127) goto LAB_00135db6;
      }
      if (0 < super->cursor) {
        wVar9 = super->cursor + -1;
        super->cursor = wVar9;
        super->buffer[wVar9] = '\0';
        goto LAB_00135eec;
      }
    }
    goto LAB_00135db6;
  }
                    /* Unresolved local var: ScreensPanel * this@[???]
                       Unresolved local var: int selected@[???]
                       Unresolved local var: ScreenListItem * oldFocus@[???]
                       Unresolved local var: _Bool shouldRebuildArray@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: ScreenListItem * newFocus@[???] */
  pVVar20 = (super->super).items;
  wVar9 = (super->super).selected;
  wVar19 = pVVar20->items;
  uVar22 = (ulong)(uint)wVar19;
  wVar21 = wVar9;
  if (wVar19 < 1) {
    if (360 < ch) {
      if (ch == 409) {
switchD_00136039_caseD_128:
        _Var8 = (_Bool)(super->moving ^ 1);
        super->moving = _Var8;
        (super->super).selectionColorId = _Var8 + PANEL_SELECTION_FOCUS;
        goto switchD_00135ed0_caseD_ffffffff;
      }
      goto switchD_00136039_caseD_104;
    }
    pOVar23 = (Object *)0x0;
    if (ch < 258) {
      if (ch < '.') {
        if (-2 < ch) {
          switch(ch) {
          case 10:
          case 13:
            goto switchD_00136039_caseD_128;
          case 14:
            goto switchD_00136039_caseD_10d;
          case 18:
            goto switchD_00135e98_caseD_10a;
          case '+':
            goto switchD_00136039_caseD_110;
          case '-':
            goto switchD_00136039_caseD_10f;
          case -1:
            goto switchD_00135ed0_caseD_ffffffff;
          }
        }
      }
      else {
        if (ch == '[') goto switchD_00136039_caseD_10f;
        if (ch == ']') goto switchD_00136039_caseD_110;
        if (254 < ch) goto switchD_00136039_caseD_104;
      }
switchD_00135ed0_caseD_0:
      ppuVar14 = __ctype_b_loc();
      if ((*(byte *)((long)*ppuVar14 + (long)ch * 2 + 1) & 4) == 0) {
joined_r0x0013614f:
        if (0 < wVar19) goto switchD_00135e98_caseD_104;
        goto switchD_00136039_caseD_104;
      }
LAB_00136650:
      HVar11 = Panel_selectByTyping(&super->super,ch);
      pVVar20 = (super->super).items;
      if (HVar11 == BREAK_LOOP) {
        if (pVVar20->items < 1) goto switchD_00136039_caseD_104;
        bVar7 = false;
        HVar11 = IGNORED;
        wVar21 = (super->super).selected;
        goto LAB_00136068;
      }
      if (0 < pVVar20->items) {
        bVar7 = false;
        wVar21 = (super->super).selected;
        goto LAB_00136068;
      }
      goto LAB_00136472;
    }
    switch(ch) {
    case 258:
      pOVar23 = (Object *)0x0;
      if (super->moving != false) goto switchD_00136039_caseD_110;
LAB_001364ba:
                    /* Unresolved local var: int size@[???] */
      wVar21 = wVar9 + 1;
      if ((wVar21 < 0) || (wVar19 == 0)) {
        wVar21 = 0;
LAB_001364c5:
        (super->super).selected = wVar21;
        (super->super).needsRedraw = true;
        goto joined_r0x0013614f;
      }
      if (wVar19 <= wVar21) {
        wVar21 = wVar19 + -1;
        goto LAB_001364c5;
      }
LAB_00136699:
      ppOVar6 = pVVar20->array;
      (super->super).selected = wVar21;
      pOVar2 = ppOVar6[wVar21];
      if ((pOVar2 == (Object *)0x0) || (pOVar2 == pOVar23)) goto switchD_00136039_caseD_104;
      columns = super->settings->dynamicColumns;
      ColumnsPanel_fill(super->columns,(ScreenSettings *)pOVar2[4].klass,columns);
      this_01 = super->availableColumns;
      p_Var3 = (pOVar2[4].klass)->display;
      Vector_prune((this_01->super).items);
      (this_01->super).scrollV = 0;
      (this_01->super).selected = 0;
      (this_01->super).oldSelected = 0;
      (this_01->super).needsRedraw = true;
      if (p_Var3 == (Object_Display)0x0) {
        AvailableColumnsPanel_addPlatformColumns(this_01);
        bVar7 = false;
        if (columns->size == 0) goto switchD_00135ed0_caseD_ffffffff;
        goto LAB_0013658a;
      }
      goto switchD_00135ed0_caseD_ffffffff;
    case 259:
switchD_00135e98_caseD_103:
      if (super->moving == false) {
                    /* Unresolved local var: int size@[???] */
        wVar21 = wVar9 + -1;
        if ((wVar21 < 0) || (wVar19 == 0)) {
          wVar21 = 0;
        }
        else {
          if (wVar21 < wVar19) goto LAB_00136699;
          wVar21 = wVar19 + -1;
        }
        (super->super).selected = wVar21;
        HVar11 = IGNORED;
        (super->super).needsRedraw = true;
        bVar7 = false;
        if (0 < wVar19) goto LAB_00136068;
        goto switchD_00136039_caseD_104;
      }
                    /* Unresolved local var: Object * temp@[???] */
      if (wVar9 == 0) goto joined_r0x001363b3;
LAB_00136233:
      ppOVar6 = pVVar20->array + (long)wVar9 + -1;
                    /* Unresolved local var: Object * temp@[???] */
      pOVar2 = *ppOVar6;
      ppOVar1 = pVVar20->array + (long)wVar9 + -1;
      *ppOVar1 = ppOVar6[1];
      ppOVar1[1] = pOVar2;
      if (0 < wVar9) {
        (super->super).selected = wVar9 + -1;
        goto joined_r0x001363b3;
      }
      bVar7 = true;
      HVar11 = HANDLED;
      if (0 < wVar19) goto LAB_00136068;
      break;
    default:
      goto switchD_00136039_caseD_104;
    case 262:
    case 338:
    case 339:
    case 360:
      Panel_onKey(&super->super,ch);
      goto switchD_00136039_caseD_104;
    case 266:
      goto switchD_00135e98_caseD_10a;
    case 269:
switchD_00136039_caseD_10d:
      this_00 = (Settings *)super->settings;
      if (this_00->dynamicScreens != (Hashtable_2 *)0x0) goto switchD_00136039_caseD_104;
      pOVar23 = (Object *)0x0;
LAB_001362cc:
                    /* Unresolved local var: ScreensPanel * this@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: ScreenListItem * item@[???]
                       Unresolved local var: int idx@[???] */
      (*(ScreenDefaults (*))(__fp - 0x68)).treeSortKey = (char *)0x0;
      (*(ScreenDefaults (*))(__fp - 0x68)).name = ((char *)(long)&DAT_001491b7 /* "New" */);
      (*(ScreenDefaults (*))(__fp - 0x68)).columns = ((char *)(long)&s_PID_Command_001491bb /* "PID Command" */);
      (*(ScreenDefaults (*))(__fp - 0x68)).sortKey = ((char *)(long)&DAT_0014828e /* "PID" */);
      pSVar15 = Settings_newScreen(this_00,&(*(ScreenDefaults (*))(__fp - 0x68)));
                    /* Unresolved local var: ScreenListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      data_ = malloc(0x28);
      if (data_ == (undefined8 *)0x0) goto LAB_00136752;
                    /* Unresolved local var: char * data@[???] */
      *data_ = &ScreenListItem_class;
      pcVar16 = strdup(((char *)(long)&DAT_001491b7 /* "New" */));
      if (pcVar16 == (char *)0x0) goto LAB_00136752;
      this = (super->super).items;
      data_[1] = pcVar16;
      wVar21 = (super->super).selected;
      data_[4] = pSVar15;
      *(undefined4 *)(data_ + 2) = 0;
      wVar21 = wVar21 + 1;
      *(undefined1 *)((long)data_ + 0x14) = 0;
      Vector_insert(this,wVar21,data_);
                    /* Unresolved local var: int size@[???] */
      (super->super).needsRedraw = true;
      wVar10 = ((super->super).items)->items;
      wVar19 = wVar10 + -1;
      if (wVar10 <= wVar21) {
        wVar21 = wVar19;
      }
      if (wVar21 < 0) {
        wVar21 = 0;
      }
      pcVar4 = (super->super).super.klass[1].extends;
      (super->super).selected = wVar21;
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)((long)super,0xffffffff,(ulong)(uint)wVar19,uVar22,in_R8,(long)pVVar20);
      }
      startRenaming(super);
      pVVar20 = (super->super).items;
      wVar19 = pVVar20->items;
joined_r0x001363b3:
      if (0 < wVar19) {
        bVar7 = true;
        HVar11 = HANDLED;
        wVar21 = (super->super).selected;
        goto LAB_00136068;
      }
      break;
    case 271:
switchD_00136039_caseD_10f:
      if (wVar9 != 0) goto LAB_00136233;
      break;
    case 272:
switchD_00136039_caseD_110:
      Panel_moveSelectedDown(&super->super);
      goto LAB_00136528;
    case 273:
      break;
    case 296:
    case 343:
      goto switchD_00136039_caseD_128;
    }
    goto switchD_00136039_caseD_111;
  }
  pOVar23 = pVVar20->array[wVar9];
  if (360 < ch) {
    bVar7 = false;
    HVar11 = IGNORED;
    if (ch == 409) {
switchD_00135e98_caseD_128:
                    /* Unresolved local var: ListItem * item@[???] */
      _Var8 = (_Bool)(super->moving ^ 1);
      super->moving = _Var8;
      (super->super).selectionColorId = _Var8 + PANEL_SELECTION_FOCUS;
      if (pOVar23 != (Object *)0x0) {
        *(_Bool *)((long)&pOVar23[2].klass + 4) = _Var8;
      }
      bVar7 = false;
      HVar11 = HANDLED;
    }
    goto LAB_00136068;
  }
  if (ch < 258) {
    if (ch < '.') {
      if (-2 < ch) {
        switch(ch) {
        default:
          goto switchD_00135ed0_caseD_0;
        case 10:
        case 13:
          goto switchD_00135e98_caseD_128;
        case 14:
          goto switchD_00135e98_caseD_10d;
        case 18:
          goto switchD_00135e98_caseD_10a;
        case '+':
          goto switchD_00135e98_caseD_110;
        case '-':
          goto switchD_00135e98_caseD_10f;
        case -1:
          goto switchD_00135ed0_caseD_ffffffff;
        }
      }
      ppuVar14 = __ctype_b_loc();
      if ((*(byte *)((long)*ppuVar14 + (long)ch * 2 + 1) & 4) == 0) goto switchD_00135e98_caseD_104;
      goto LAB_00136650;
    }
    if (ch == '[') goto joined_r0x001365f2;
    if (ch == ']') goto switchD_00135e98_caseD_110;
    if (ch < 255) goto switchD_00135ed0_caseD_0;
    goto switchD_00135e98_caseD_104;
  }
  switch(ch) {
  case 258:
    if (super->moving == false) goto LAB_001364ba;
  case 272:
switchD_00135e98_caseD_110:
    Panel_moveSelectedDown(&super->super);
    wVar21 = (super->super).selected;
    goto LAB_0013628b;
  case 259:
    goto switchD_00135e98_caseD_103;
  default:
    goto switchD_00135e98_caseD_104;
  case 262:
  case 338:
  case 339:
  case 360:
    Panel_onKey(&super->super,ch);
    wVar21 = (super->super).selected;
    goto switchD_00135e98_caseD_104;
  case 266:
switchD_00135e98_caseD_10a:
    startRenaming(super);
    if (pVVar20->items < 1) goto switchD_00135ed0_caseD_ffffffff;
    bVar7 = false;
    wVar21 = (super->super).selected;
    HVar11 = HANDLED;
    break;
  case 269:
switchD_00135e98_caseD_10d:
    this_00 = (Settings *)super->settings;
    bVar7 = false;
    HVar11 = IGNORED;
    if (this_00->dynamicScreens == (Hashtable_2 *)0x0) goto LAB_001362cc;
    break;
  case 271:
switchD_00135e98_caseD_10f:
joined_r0x001365f2:
    if (wVar9 != 0) goto LAB_00136233;
    goto LAB_0013628b;
  case 273:
    if (wVar19 != 1) {
      Panel_remove(&super->super,wVar9);
      pVVar20 = (super->super).items;
      wVar19 = pVVar20->items;
      goto joined_r0x001363b3;
    }
LAB_0013628b:
    bVar7 = true;
    HVar11 = HANDLED;
    break;
  case 296:
  case 343:
    goto switchD_00135e98_caseD_128;
  }
LAB_00136068:
  pOVar2 = pVVar20->array[wVar21];
  if ((pOVar2 == (Object *)0x0) || (pOVar2 == pOVar23)) {
    if (bVar7) {
      pVVar20 = (super->super).items;
      goto LAB_001363c6;
    }
LAB_00136472:
    if (HVar11 != HANDLED) goto LAB_00135dbc;
  }
  else {
                    /* Unresolved local var: Hashtable * dynamicColumns@[???] */
    columns = super->settings->dynamicColumns;
    ColumnsPanel_fill(super->columns,(ScreenSettings *)pOVar2[4].klass,columns);
    this_01 = super->availableColumns;
                    /* Unresolved local var: Panel * super@[???] */
    p_Var3 = (pOVar2[4].klass)->display;
    Vector_prune((this_01->super).items);
    (this_01->super).scrollV = 0;
    (this_01->super).selected = 0;
    (this_01->super).oldSelected = 0;
    (this_01->super).needsRedraw = true;
                    /* Unresolved local var: Panel * super@[???] */
                    /* Unresolved local var: size_t i@[???] */
    if ((p_Var3 == (Object_Display)0x0) &&
       (AvailableColumnsPanel_addPlatformColumns(this_01), columns->size != 0)) {
LAB_0013658a:
      uVar22 = 0;
      do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
        value = columns->buckets[uVar22].value;
        if (value != (void *)0x0) {
          AvailableColumnsPanel_addDynamicColumn(columns->buckets[uVar22].key,value,this_01);
        }
        uVar22 = uVar22 + 1;
      } while (uVar22 < columns->size);
    }
    if (bVar7) {
LAB_00136528:
      pVVar20 = (super->super).items;
switchD_00136039_caseD_111:
      HVar11 = HANDLED;
LAB_001363c6:
                    /* Unresolved local var: ScreensPanel * this@[???]
                       Unresolved local var: int n@[???] */
      wVar21 = pVVar20->items;
      uVar22 = (ulong)(wVar21 + 1);
      free(super->settings->screens);
      pSVar5 = super->settings;
      if (uVar22 >> 0x3d != 0) {
LAB_00136752:
                    /* WARNING: Subroutine does not return */
        fail();
      }
                    /* Unresolved local var: void * data@[???] */
      ppSVar17 = malloc(uVar22 * 8);
      if (ppSVar17 == (ScreenSettings_3 **)0x0) goto LAB_00136752;
      pSVar5->screens = ppSVar17;
      ppSVar17[uVar22 - 1] = (ScreenSettings_3 *)0x0;
                    /* Unresolved local var: int i@[???] */
      if (0 < wVar21) {
                    /* Unresolved local var: ScreenListItem * item@[???] */
        ppOVar6 = ((super->super).items)->array;
        lVar18 = 0;
        do {
          *(undefined8 *)((long)ppSVar17 + lVar18) =
               *(undefined8 *)(*(long *)((long)ppOVar6 + lVar18) + 0x20);
          lVar18 = lVar18 + 8;
        } while (uVar22 * 8 - 8 != lVar18);
      }
      pSVar5->nScreens = wVar21;
      wVar19 = 0;
      if (-1 < wVar9) {
        wVar19 = wVar9;
      }
      wVar10 = wVar21 + -1;
      if (wVar9 < wVar21) {
        wVar10 = wVar19;
      }
      pSVar5->ssIndex = wVar10;
      pSVar5->ss = ppSVar17[wVar10];
      goto LAB_00136472;
    }
  }
switchD_00135ed0_caseD_ffffffff:
  ScreensPanel_update(super);
LAB_00135db6:
  HVar11 = HANDLED;
LAB_00135dbc:
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return HVar11;
switchD_00135e98_caseD_104:
  bVar7 = false;
  HVar11 = IGNORED;
  goto LAB_00136068;
switchD_00136039_caseD_104:
  HVar11 = IGNORED;
  goto LAB_00135dbc;
}

