#include "htop.h"

/* ColumnsPanel_delete @ 0x117790 */

void ColumnsPanel_delete(void *param_1)

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


/* ColumnsPanel_update @ 0x117cf0 */

void ColumnsPanel_update(ColumnsPanel_ *super)

{
  int wVar1;
  int iVar2;
  ScreenSettings_3 *pSVar3;
  ScreenSettings_3 *pSVar4;
  Object **ppOVar5;
  RowField *pRVar6;
  long lVar7;
  RowField *pRVar8;

  pSVar3 = super->ss;
  wVar1 = ((super->super).items)->items;
  pRVar8 = pSVar3->fields;
  *super->changed = true;
                    /* Unresolved local var: void * data@[???] */
  pRVar6 = realloc(pRVar8,(long)(wVar1 + 1) * 4);
  if (pRVar6 != (RowField *)0x0) {
    pSVar4 = super->ss;
    pSVar3->fields = pRVar6;
    pSVar4->flags = 0;
                    /* Unresolved local var: int i@[???] */
    if (wVar1 < 1) {
      pRVar8 = pSVar4->fields;
    }
    else {
                    /* Unresolved local var: int key@[???] */
      pRVar8 = pSVar4->fields;
      lVar7 = 0;
      ppOVar5 = ((super->super).items)->array;
      do {
        iVar2 = *(int *)&ppOVar5[lVar7][2].klass;
        pRVar8[lVar7] = iVar2;
        if (iVar2 < 0x84) {
          pSVar4->flags = pSVar4->flags | Process_fields[iVar2].flags;
        }
        lVar7 = lVar7 + 1;
      } while (wVar1 != lVar7);
    }
    pRVar8[(long)(wVar1 + 1) + -1] = 0;
    return;
  }
  free(pRVar8);
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ColumnsPanel_fill @ 0x11b0c0 */

/* DWARF original prototype: void ColumnsPanel_fill(ColumnsPanel * this, ScreenSettings * ss,
   Hashtable * columns) */

void ColumnsPanel_fill(ColumnsPanel *this,ScreenSettings *ss,Hashtable_2 *columns)

{
  uint uVar1;
  Vector *this_00;
  HashtableItem *pHVar2;
  undefined8 *data_;
  char *pcVar3;
  HashtableItem *pHVar4;
  ulong uVar5;
  ulong uVar6;
  uint *puVar7;
  char *pcVar8;

  Vector_prune((this->super).items);
                    /* Unresolved local var: RowField * fields@[???] */
  puVar7 = (uint *)ss->fields;
  (this->super).needsRedraw = true;
  (this->super).scrollV = 0;
  (this->super).selected = 0;
  (this->super).oldSelected = 0;
  uVar1 = *puVar7;
  do {
    if (uVar1 == 0) {
      this->ss = (ScreenSettings_3 *)ss;
      return;
    }
    if (uVar1 < 0x84) {
                    /* Unresolved local var: char * name@[???] */
      pcVar3 = Process_fields[uVar1].name;
      if (Process_fields[uVar1].name == (char *)0x0) {
        pcVar3 = ((char *)(long)&DAT_00147411 /* "- " */);
      }
    }
    else {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
      pHVar2 = columns->buckets;
      uVar6 = (ulong)uVar1 % columns->size;
      pcVar8 = pHVar2[uVar6].value;
      pcVar3 = ((char *)(long)&DAT_00147411 /* "- " */);
      if (pcVar8 != (char *)0x0) {
        uVar5 = 0;
        pHVar4 = pHVar2 + uVar6;
        do {
          while( true ) {
            if (uVar1 == pHVar4->key) {
              pcVar3 = *(char **)(pcVar8 + 0x20);
              if (*(char **)(pcVar8 + 0x20) == (char *)0x0) {
                pcVar3 = pcVar8;
              }
              goto LAB_0011b13f;
            }
            if (pHVar4->probe < uVar5) goto LAB_0011b228;
            uVar6 = uVar6 + 1;
            if (columns->size != uVar6) break;
            uVar6 = 0;
            uVar5 = uVar5 + 1;
            pcVar8 = pHVar2->value;
            pHVar4 = pHVar2;
            if (pcVar8 == (char *)0x0) goto LAB_0011b228;
          }
          uVar5 = uVar5 + 1;
          pHVar4 = pHVar2 + uVar6;
          pcVar8 = pHVar4->value;
        } while (pcVar8 != (char *)0x0);
LAB_0011b228:
        pcVar3 = ((char *)(long)&DAT_00147411 /* "- " */);
      }
    }
LAB_0011b13f:
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    data_ = malloc(0x18);
    if (data_ == (undefined8 *)0x0) {
LAB_0011b26b:
                    /* WARNING: Subroutine does not return */
      fail();
    }
                    /* Unresolved local var: char * data@[???] */
    *data_ = &ListItem_class;
    pcVar3 = strdup(pcVar3);
    if (pcVar3 == (char *)0x0) goto LAB_0011b26b;
    this_00 = (this->super).items;
    *(uint *)(data_ + 2) = uVar1;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
    puVar7 = puVar7 + 1;
    data_[1] = pcVar3;
    *(undefined1 *)((long)data_ + 0x14) = 0;
    Vector_set(this_00,this_00->items,data_);
    uVar1 = *puVar7;
    (this->super).needsRedraw = true;
  } while( true );
}


/* ColumnsPanel_new @ 0x11b270 */

/* WARNING: Removing unreachable block (ram,0x0011b32c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x0011b349 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ColumnsPanel * ColumnsPanel_new(ScreenSettings *ss,Hashtable_2 *columns,_Bool *changed)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  int wVar1;
  Hashtable_2 *columns_00;
  undefined1 *puVar2;
  ScreenSettings *ss_00;
  int wVar3;
  int iVar4;
  ColumnsPanel *this;
  FunctionBar *fuBar;
  size_t sVar5;
  cchar_t *pcVar6;
  int *pwVar7;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * data@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(Hashtable_2 *(*))(__fp - 0x68)) = columns;
  (*(ScreenSettings *(*))(__fp - 0x58)) = ss;
  this = malloc(0x26f8);
  if (this == (ColumnsPanel *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this->super).super.klass = &ColumnsPanel_class.super;
  fuBar = FunctionBar_new(ColumnsFunctions,(char **)0x0,(int *)0x0);
  Panel_init(&this->super,1,1,1,1,&ListItem_class,true,fuBar);
  this->changed = changed;
  this->moving = false;
  this->ss = (ScreenSettings_3 *)(*(ScreenSettings *(*))(__fp - 0x58));
  wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[62483] data@[???]
                       Unresolved local var: int newLen@[???] */
  (*(undefined1 *(*))(__fp - 0x60)) = (undefined1 *)&(*(Hashtable_2 *(*))(__fp - 0x68));
  pwVar7 = (*(int (*) [12])(__fp - 0xa8));
  (*(undefined1 *(*))(__fp - 0x60)) = (undefined1 *)&(*(Hashtable_2 *(*))(__fp - 0x68));
  sVar5 = mbstowcs((*(int (*) [12])(__fp - 0xa8)),((char *)(long)&s_Active_Columns_00147414 /* "Active Columns" */),0xe);
  wVar3 = (int)sVar5;
  if (0 < wVar3) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(this->super).header,wVar3);
    (*(int *(*))(__fp - 0x50)) = (*(int (*) [12])(__fp - 0xa8)) + (ulong)(uint)(wVar3 + -1) + 1;
    pcVar6 = (this->super).header.chptr;
    do {
      wVar3 = *pwVar7;
      iVar4 = iswprint(wVar3);
      pcVar6->attr = 0;
      pcVar6->chars[0] = 0;
      pcVar6->chars[1] = 0;
      pcVar6->chars[2] = 0;
      if (iVar4 == 0) {
        wVar3 = 65533;
      }
      pcVar6->attr = wVar1 & 0xffffff;
      pwVar7 = pwVar7 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar6->chars + 2)) = (undefined16)0x0;
      pcVar6->chars[0] = wVar3;
      pcVar6 = pcVar6 + 1;
    } while ((*(int *(*))(__fp - 0x50)) != pwVar7);
  }
  ss_00 = (*(ScreenSettings *(*))(__fp - 0x58));
  puVar2 = (*(undefined1 *(*))(__fp - 0x60));
  columns_00 = (*(Hashtable_2 *(*))(__fp - 0x68));
  (this->super).needsRedraw = true;
  ColumnsPanel_fill(this,ss_00,columns_00);
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this;
}


/* ColumnsPanel_eventHandler @ 0x11cf50 */

HandlerResult ColumnsPanel_eventHandler(ColumnsPanel_ *super,int ch)

{
  Object **ppOVar1;
  Object **ppOVar2;
  int i;
  int wVar3;
  Vector *pVVar4;
  Object *pOVar5;
  HandlerResult HVar6;
  ushort **ppuVar7;
  _Bool _Var8;

  pVVar4 = (super->super).items;
  i = (super->super).selected;
  wVar3 = pVVar4->items;
  if (296 < ch) {
    if (ch != 330) {
      if (ch < 330) {
        return IGNORED;
      }
      if ((ch != 343) && (ch != 409)) {
        return IGNORED;
      }
switchD_0011cf98_caseD_128:
      if (wVar3 + -1 <= i) {
        return IGNORED;
      }
                    /* Unresolved local var: ListItem * selectedItem@[???] */
      _Var8 = (_Bool)(super->moving ^ 1);
      super->moving = _Var8;
      (super->super).selectionColorId = _Var8 + PANEL_SELECTION_FOCUS;
      if ((0 < wVar3) && (pVVar4->array[i] != (Object *)0x0)) {
        *(_Bool *)((long)&pVVar4->array[i][2].klass + 4) = _Var8;
      }
      goto LAB_0011d040;
    }
switchD_0011cf98_caseD_111:
    if (i < wVar3 + -1) {
      Panel_remove(&super->super,i);
    }
    goto LAB_0011d040;
  }
  if (257 < ch) {
    switch(ch) {
    case 258:
      if (super->moving == false) {
        return IGNORED;
      }
    case 272:
switchD_0011cf98_caseD_110:
      if (i < wVar3 + -2) {
        Panel_moveSelectedDown(&super->super);
      }
      break;
    case 259:
      if (super->moving == false) {
        return IGNORED;
      }
    case 271:
switchD_0011cf98_caseD_10f:
                    /* Unresolved local var: Object * temp@[???] */
      if ((i < wVar3 + -1) && (i != 0)) {
                    /* Unresolved local var: Object * temp@[???] */
        ppOVar1 = pVVar4->array + (long)i + -1;
        pOVar5 = *ppOVar1;
        ppOVar2 = pVVar4->array + (long)i + -1;
        *ppOVar2 = ppOVar1[1];
        ppOVar2[1] = pOVar5;
        if (0 < i) {
          (super->super).selected = i + -1;
        }
      }
      break;
    default:
switchD_0011cf98_caseD_104:
      if (0xfd < (uint)(ch + -1)) {
        return IGNORED;
      }
      ppuVar7 = __ctype_b_loc();
      if (-1 < (short)(*ppuVar7)[ch]) {
        return IGNORED;
      }
      HVar6 = Panel_selectByTyping(&super->super,ch);
      if (HVar6 == BREAK_LOOP) {
        return IGNORED;
      }
      if (HVar6 != HANDLED) {
        return HVar6;
      }
      break;
    case 273:
      goto switchD_0011cf98_caseD_111;
    case 296:
      goto switchD_0011cf98_caseD_128;
    }
LAB_0011d040:
    ColumnsPanel_update(super);
    return HANDLED;
  }
  if (ch != '-') {
    if (ch < '.') {
      if (ch != 13) {
        if (ch == '+') goto switchD_0011cf98_caseD_110;
        if (ch != 10) goto switchD_0011cf98_caseD_104;
      }
      goto switchD_0011cf98_caseD_128;
    }
    if (ch != '[') {
      if (ch != ']') goto switchD_0011cf98_caseD_104;
      goto switchD_0011cf98_caseD_110;
    }
  }
  goto switchD_0011cf98_caseD_10f;
}

