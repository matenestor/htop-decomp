#include "htop.h"

/* MetersPanel_setMoving @ 0x121570 */

/* DWARF original prototype: void MetersPanel_setMoving(MetersPanel * this, _Bool moving) */

void MetersPanel_setMoving(MetersPanel *this,_Bool moving)

{
  Vector *pVVar1;
  Object *pOVar2;
  FunctionBar *pFVar3;

  pVVar1 = (this->super).items;
  this->moving = moving;
  if ((0 < pVVar1->items) &&
     (pOVar2 = pVVar1->array[(this->super).selected], pOVar2 != (Object *)0x0)) {
    *(_Bool *)((long)&pOVar2[2].klass + 4) = moving;
  }
  pFVar3 = Meters_movingBar;
  if (!moving) {
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
    (this->super).selectionColorId = PANEL_SELECTION_FOCUS;
    (this->super).currentBar = (this->super).defaultBar;
    return;
  }
  (this->super).selectionColorId = PANEL_SELECTION_FOLLOW;
  (this->super).currentBar = pFVar3;
  return;
}


/* MetersPanel_cleanup @ 0x126e40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MetersPanel_cleanup(void)

{
  if (Meters_movingBar != (FunctionBar *)0x0) {
    FunctionBar_delete(Meters_movingBar);
    Meters_movingBar = (FunctionBar *)0x0;
    return;
  }
  return;
}


/* MetersPanel_delete_lto_priv_0 @ 0x126e80 */

void MetersPanel_delete_lto_priv_0(void *param_1)

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


/* MetersPanel_new @ 0x1288c0 */

MetersPanel_2 *
MetersPanel_new(Settings_4 *settings,char *header,Vector *meters,ScreenManager_3 *scr)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  int wVar1;
  Meter *this;
  Vector *this_00;
  undefined1 *puVar2;
  int len;
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
  int *pwVar11;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar8;

                    /* Unresolved local var: void * data@[???] */
  puVar8 = (*(undefined1 (*) [8])(__fp - 0x68));
  puVar7 = (*(undefined1 (*) [8])(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this_01 = malloc(10000);
  if (this_01 == (MetersPanel_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this_01->super).super.klass = &MetersPanel_class.super;
  fuBar = FunctionBar_new(MetersFunctions,MetersKeys,MetersEvents);
  if (Meters_movingBar == (FunctionBar *)0x0) {
    (*(undefined8 (*))(__fp - 0x50)) = fuBar;
    Meters_movingBar = FunctionBar_new(MetersMovingFunctions,MetersMovingKeys,MetersMovingEvents);
    fuBar = (*(undefined8 (*))(__fp - 0x50));
  }
  Panel_init(&this_01->super,1,1,1,1,&ListItem_class,true,fuBar);
  this_01->scr = scr;
  this_01->settings = settings;
  this_01->meters = meters;
  pwVar11 = CRT_colors;
  this_01->moving = false;
  this_01->leftNeighbor = (MetersPanel_2 *)0x0;
  this_01->rightNeighbor = (MetersPanel_2 *)0x0;
  wVar1 = pwVar11[7];
  sVar4 = strlen(header);
                    /* Unresolved local var: int[44366] data@[???]
                       Unresolved local var: int newLen@[???] */
  uVar6 = (ulong)((int)sVar4 + 1);
  uVar5 = uVar6 * 4 + 0xf;
  puVar2 = (*(undefined1 (*) [8])(__fp - 0x68));
  while (puVar8 != (*(undefined1 (*) [8])(__fp - 0x68)) + -(uVar5 & 0xfffffffffffff000)) {
    puVar7 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar8 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar5 = (ulong)((uint)uVar5 & 0xff0);
  lVar10 = -uVar5;
  pwVar11 = (int *)(puVar7 + lVar10);
  if (uVar5 != 0) {
    *(undefined8 *)(puVar7 + -8) = *(undefined8 *)(puVar7 + -8);
  }
  (*(undefined1 *(*))(__fp - 0x60)) = (*(undefined1 (*) [8])(__fp - 0x68));
  uVar5 = __mbstowcs_chk((int *)(puVar7 + lVar10),header,(long)(int)sVar4,uVar6 & 0x3fffffffffffffff
                        );
  len = (int)uVar5;
  if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(this_01->super).header,len);
    (*(undefined8 (*))(__fp - 0x50)) = (FunctionBar *)(CONCAT44((*(uint *)((char *)&(*(undefined8 (*))(__fp - 0x50)) + 4)),wVar1) & 0xffffffff00ffffff);
    (*(int *(*))(__fp - 0x58)) = (int *)(puVar7 + (ulong)(uint)(len + -1) * 4 + lVar10 + 4);
    pcVar9 = (this_01->super).header.chptr;
    do {
      wVar1 = *pwVar11;
      iVar3 = iswprint(wVar1);
      pcVar9->attr = 0;
      pcVar9->chars[0] = 0;
      pcVar9->chars[1] = 0;
      pcVar9->chars[2] = 0;
      if (iVar3 == 0) {
        wVar1 = 65533;
      }
      pwVar11 = pwVar11 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
      pcVar9->attr = (attr_t)(*(undefined8 (*))(__fp - 0x50));
      pcVar9->chars[0] = wVar1;
      pcVar9 = pcVar9 + 1;
    } while (pwVar11 != (*(int *(*))(__fp - 0x58)));
  }
  puVar7 = (*(undefined1 *(*))(__fp - 0x60));
                    /* Unresolved local var: int i@[???] */
  wVar1 = meters->items;
  (this_01->super).needsRedraw = true;
  lVar10 = 0;
  if (0 < wVar1) {
    do {
                    /* Unresolved local var: Meter * meter@[???] */
      this = (Meter *)meters->array[lVar10];
      lVar10 = lVar10 + 1;
      data_ = Meter_toListItem(this,false);
      this_00 = (this_01->super).items;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
      wVar1 = this_00->items;
      Vector_set(this_00,wVar1,data_);
      (this_01->super).needsRedraw = true;
    } while ((int)lVar10 < meters->items);
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this_01;
}


/* MetersPanel_eventHandler @ 0x129b50 */

HandlerResult MetersPanel_eventHandler(MetersPanel_ *super,int ch)

{
  uint64_t *puVar1;
  Object **ppOVar2;
  Header_3 *this;
  Settings_3 *pSVar3;
  Object **ppOVar4;
  MetersPanel *a0;
  Vector *pVVar5;
  code *a3;
  Object *pOVar6;
  FunctionBar *pFVar7;
  _Bool _Var8;
  int wVar9;
  Meter *pMVar10;
  ListItem *pLVar11;
  int wVar12;
  Vector *pVVar13;
  long in_R8;
  long in_R9;
  int idx;
  HandlerResult HVar14;

  idx = (super->super).selected;
  if (273 < ch) {
    if (ch == 330) {
switchD_00129b93_caseD_111:
      wVar9 = super->meters->items;
      if (wVar9 == 0) {
        return IGNORED;
      }
      if (idx < wVar9) {
        Vector_remove(super->meters,idx);
        Panel_remove(&super->super,idx);
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar13 = (super->super).items;
      super->moving = false;
      if ((0 < pVVar13->items) &&
         (pOVar6 = pVVar13->array[(super->super).selected], pOVar6 != (Object *)0x0)) {
        *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
      }
    }
    else {
      if (ch != 343) {
        return IGNORED;
      }
switchD_00129bf3_caseD_a:
      if (super->meters->items == 0) {
        return IGNORED;
      }
      pVVar13 = (super->super).items;
      wVar9 = pVVar13->items;
      _Var8 = (_Bool)(super->moving ^ 1);
      super->moving = _Var8;
      if ((0 < wVar9) && (pOVar6 = pVVar13->array[idx], pOVar6 != (Object *)0x0)) {
        *(_Bool *)((long)&pOVar6[2].klass + 4) = _Var8;
      }
      pFVar7 = Meters_movingBar;
      if (_Var8 != false) {
        (super->super).selectionColorId = PANEL_SELECTION_FOLLOW;
        (super->super).currentBar = pFVar7;
        goto LAB_00129c3c;
      }
    }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
    (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
    (super->super).currentBar = (super->super).defaultBar;
    goto LAB_00129c3c;
  }
  if (ch < 258) {
    if (ch < '.') {
      if (ch < 10) {
LAB_00129bc6:
        return IGNORED;
      }
      switch(ch) {
      case 10:
      case 13:
        goto switchD_00129bf3_caseD_a;
      default:
        goto LAB_00129bc6;
      case ' ':
        goto switchD_00129b93_caseD_10c;
      case '+':
        goto switchD_00129b93_caseD_110;
      case '-':
        goto switchD_00129b93_caseD_10f;
      }
    }
    if (ch != ']') {
      if (ch == 't') goto switchD_00129b93_caseD_10c;
      if (ch != '[') {
        return IGNORED;
      }
      goto switchD_00129b93_caseD_10f;
    }
    goto switchD_00129b93_caseD_110;
  }
  switch(ch) {
  case 258:
    if (super->moving == false) {
      return IGNORED;
    }
  case 272:
switchD_00129b93_caseD_110:
                    /* Unresolved local var: Object * temp@[???] */
    if (idx != super->meters->items + -1) {
      ppOVar2 = super->meters->array + idx;
      pOVar6 = *ppOVar2;
      *ppOVar2 = ppOVar2[1];
      ppOVar2[1] = pOVar6;
    }
    Panel_moveSelectedDown(&super->super);
    break;
  case 259:
    if (super->moving == false) {
      return IGNORED;
    }
  case 271:
switchD_00129b93_caseD_10f:
                    /* Unresolved local var: Object * temp@[???] */
    if (idx != 0) {
      ppOVar4 = super->meters->array;
                    /* Unresolved local var: Object * temp@[???] */
      ppOVar2 = ppOVar4 + (long)idx + -1;
      pOVar6 = *ppOVar2;
      ppOVar4 = ppOVar4 + (long)idx + -1;
      *ppOVar4 = ppOVar2[1];
      ppOVar4[1] = pOVar6;
                    /* Unresolved local var: Object * temp@[???] */
      ppOVar4 = ((super->super).items)->array;
      ppOVar2 = ppOVar4 + (long)idx + -1;
                    /* Unresolved local var: Object * temp@[???] */
      pOVar6 = *ppOVar2;
      ppOVar4 = ppOVar4 + (long)idx + -1;
      *ppOVar4 = ppOVar2[1];
      ppOVar4[1] = pOVar6;
      if (0 < idx) {
        (super->super).selected = idx + -1;
      }
    }
    break;
  case 260:
    if (super->moving == false) {
      return IGNORED;
    }
    a0 = super->leftNeighbor;
    goto joined_r0x00129d6d;
  case 261:
                    /* Unresolved local var: Panel * super@[???] */
    if (super->moving == false) {
      return IGNORED;
    }
    a0 = super->rightNeighbor;
joined_r0x00129d6d:
                    /* Unresolved local var: Panel * super@[???] */
    if ((a0 != (MetersPanel *)0x0) && (pVVar13 = super->meters, idx < pVVar13->items)) {
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: Meter * meter@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar5 = (super->super).items;
      super->moving = false;
      if ((0 < pVVar5->items) && (pOVar6 = pVVar5->array[idx], pOVar6 != (Object *)0x0)) {
        *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
      (super->super).currentBar = (super->super).defaultBar;
      pMVar10 = (Meter *)Vector_take(pVVar13,idx);
      Panel_remove(&super->super,idx);
      Vector_insert(a0->meters,idx,pMVar10);
      pLVar11 = Meter_toListItem(pMVar10,false);
      Vector_insert((a0->super).items,idx,pLVar11);
                    /* Unresolved local var: int size@[???] */
      pVVar13 = (a0->super).items;
      (a0->super).needsRedraw = true;
      wVar9 = pVVar13->items;
      if (wVar9 <= idx) {
        idx = wVar9 + -1;
      }
      wVar12 = 0;
      if (-1 < idx) {
        wVar12 = idx;
      }
      (a0->super).selected = wVar12;
      a3 = (a0->super).super.klass[1].extends;
      if (a3 != (code *)0x0) {
        (*a3)((long)a0,0xffffffff,(long)pVVar13,(long)a3,in_R8,in_R9);
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
        pVVar13 = (a0->super).items;
        wVar9 = pVVar13->items;
      }
      a0->moving = true;
      if ((0 < wVar9) && (pVVar13->array[(a0->super).selected] != (Object *)0x0)) {
        *(undefined1 *)((long)&pVVar13->array[(a0->super).selected][2].klass + 4) = 1;
      }
      pFVar7 = Meters_movingBar;
      (a0->super).selectionColorId = PANEL_SELECTION_FOLLOW;
      (a0->super).currentBar = pFVar7;
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: int mode@[???] */
      HVar14 = IGNORED;
      goto LAB_00129c42;
    }
    break;
  default:
    goto LAB_00129bc6;
  case 268:
switchD_00129b93_caseD_10c:
    if (super->meters->items == 0) {
      return IGNORED;
    }
    pMVar10 = (Meter *)super->meters->array[idx];
    wVar9 = pMVar10->mode + 1;
    if (pMVar10->mode == 4) {
      wVar9 = 1;
    }
    Meter_setMode(pMVar10,wVar9);
    pLVar11 = Meter_toListItem(pMVar10,super->moving);
    Vector_set((super->super).items,idx,pLVar11);
    break;
  case 273:
    goto switchD_00129b93_caseD_111;
  }
LAB_00129c3c:
  HVar14 = HANDLED;
LAB_00129c42:
                    /* Unresolved local var: Header * header@[???] */
  this = super->scr->header;
  pSVar3 = super->settings;
  puVar1 = &pSVar3->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar3->changed = true;
  Header_calculateHeight((Header *)this);
  ScreenManager_resize((ScreenManager *)super->scr);
  return HVar14;
}

