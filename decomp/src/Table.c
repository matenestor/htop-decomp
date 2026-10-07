#include "htop.h"

/* Table_prepareEntries @ 0x12d220 */

/* DWARF original prototype: void Table_prepareEntries(Table * this) */

void Table_prepareEntries(Table *this)

{
  Object **ppOVar1;
  undefined1 uVar2;
  int wVar3;
  Object *pOVar4;
  Object **ppOVar5;

                    /* Unresolved local var: int i@[???] */
  wVar3 = this->rows->items;
  if (0 < wVar3) {
    ppOVar5 = this->rows->array;
    ppOVar1 = ppOVar5 + wVar3;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar4 = *ppOVar5;
      ppOVar5 = ppOVar5 + 1;
      uVar2 = *(undefined1 *)((long)&pOVar4[3].klass + 6);
      *(undefined1 *)((long)&pOVar4[4].klass + 1) = 0;
      *(undefined1 *)((long)&pOVar4[3].klass + 6) = 1;
      *(undefined1 *)((long)&pOVar4[3].klass + 7) = uVar2;
    } while (ppOVar5 != ppOVar1);
  }
  return;
}


/* compareRowByKnownParentThenNatural @ 0x12db60 */

int compareRowByKnownParentThenNatural(void *v1,void *v2)

{
  int wVar1;
  long lVar2;
  long in_RCX;
  long in_RDX;
  long in_R8;
  long in_R9;

  if (*(code **)(*(long *)v1 + 0x48) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012db70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar2 = (**(code **)(*(long *)v1 + 0x48))((long)v1,(long)v2,in_RDX,in_RCX,in_R8,in_R9);
    return (int)lVar2;
  }
  wVar1 = Row_compareByParent_Base(v1,v2);
  return wVar1;
}


/* Table_setPanel @ 0x12e210 */

/* DWARF original prototype: void Table_setPanel(Table * this, Panel * panel) */

void Table_setPanel(Table *this,Panel *panel)

{
  this->panel = panel;
  return;
}


/* Table_expandTree @ 0x12e2a0 */

/* DWARF original prototype: void Table_expandTree(Table * this) */

void Table_expandTree(Table *this)

{
  Object **ppOVar1;
  int wVar2;
  Object *pOVar3;
  Object **ppOVar4;

  wVar2 = this->rows->items;
                    /* Unresolved local var: int i@[???] */
  if (0 < wVar2) {
    ppOVar4 = this->rows->array;
    ppOVar1 = ppOVar4 + wVar2;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar3 = *ppOVar4;
      ppOVar4 = ppOVar4 + 1;
      *(undefined1 *)&pOVar3[4].klass = 1;
    } while (ppOVar4 != ppOVar1);
  }
  return;
}


/* Table_done @ 0x12f930 */

/* DWARF original prototype: void Table_done(Table * this) */

void Table_done(Table *this)

{
  Hashtable *this_00;

  this_00 = this->table;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  Vector_delete(this->displayList);
  Vector_delete(this->rows);
  return;
}


/* Table_delete @ 0x12f980 */

void Table_delete(Table_ *cast)

{
  Hashtable *this;

  this = cast->table;
  Hashtable_clear(this);
  free(this->buckets);
  free(this);
  Vector_delete(cast->displayList);
  Vector_delete(cast->rows);
  free(cast);
  return;
}


/* Table_removeIndex @ 0x12fa10 */

/* DWARF original prototype: void Table_removeIndex(Table * this, Row * row, int idx) */

void Table_removeIndex(Table *this,Row_2 *row,int idx)

{
  int key;
  int wVar1;
  Vector *pVVar2;
  Object *pOVar3;
  ulong a1;
  long in_R8;
  long in_R9;

  key = row->id;
  a1 = (ulong)(uint)key;
  Hashtable_remove(this->table,key);
  pVVar2 = this->rows;
                    /* Unresolved local var: Object * removed@[???] */
  pOVar3 = pVVar2->array[idx];
  if (pOVar3 != (Object *)0x0) {
    pVVar2->array[idx] = (Object *)0x0;
    wVar1 = pVVar2->dirty_index;
    pVVar2->dirty_count = pVVar2->dirty_count + 1;
    if ((idx < wVar1) || (wVar1 < 0)) {
      pVVar2->dirty_index = idx;
    }
    if (pVVar2->owner != false) {
      (*(code *)(pOVar3->klass->delete))(pOVar3,a1,(ulong)(uint)wVar1,(long)idx,in_R8,in_R9);
    }
  }
  if ((this->following == key) && (this->following != -1)) {
                    /* Unresolved local var: int rowid@[???] */
    this->following = -1;
    this->panel->selectionColorId = PANEL_SELECTION_FOCUS;
    return;
  }
  return;
}


/* Table_cleanupRow @ 0x12fac0 */

void Table_cleanupRow(Table_2 *table,Row_2 *row,int idx)

{
  Machine__2 *pMVar1;

  pMVar1 = table->host;
  if (row->tombStampMs == 0) {
    if (row->updated == false) {
      if ((pMVar1->settings->highlightChanges != false) && (row->wasShown != false)) {
        row->tombStampMs = (long)(pMVar1->settings->highlightDelaySecs * 1000) + pMVar1->monotonicMs
        ;
        return;
      }
      goto LAB_0012fb10;
    }
  }
  else if (row->tombStampMs <= pMVar1->monotonicMs) {
LAB_0012fb10:
    Table_removeIndex((Table *)table,row,idx);
    return;
  }
  return;
}


/* Table_cleanupEntries @ 0x12fb20 */

/* DWARF original prototype: void Table_cleanupEntries(Table * this) */

void Table_cleanupEntries(Table *this)

{
  int key;
  Machine_ *pMVar1;
  long lVar2;
  int idx;
  Vector *this_00;
  long lVar3;

                    /* Unresolved local var: int i@[???] */
  this_00 = this->rows;
  idx = this_00->items + -1;
  if (-1 < idx) {
    lVar3 = (long)idx << 3;
LAB_0012fb62:
    do {
      pMVar1 = this->host;
      lVar2 = *(long *)((long)this_00->array + lVar3);
      if (*(ulong *)(lVar2 + 0x38) == 0) {
        if (*(char *)(lVar2 + 0x21) == '\0') {
          if ((pMVar1->settings->highlightChanges != false) && (*(char *)(lVar2 + 0x1f) != '\0')) {
            idx = idx + -1;
            lVar3 = lVar3 + -8;
            *(uint64_t *)(lVar2 + 0x38) =
                 (long)(pMVar1->settings->highlightDelaySecs * 1000) + pMVar1->monotonicMs;
            if (idx == -1) break;
            goto LAB_0012fb62;
          }
LAB_0012fbc0:
                    /* Unresolved local var: int rowid@[???] */
          key = *(int *)(lVar2 + 0x10);
          Hashtable_remove(this->table,key);
          Vector_softRemove(this->rows,idx);
          if ((key == this->following) && (this->following != -1)) {
            this->following = -1;
            this->panel->selectionColorId = PANEL_SELECTION_FOCUS;
          }
                    /* Unresolved local var: int rowid@[???] */
          this_00 = this->rows;
        }
      }
      else {
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???] */
        if (*(ulong *)(lVar2 + 0x38) <= pMVar1->monotonicMs) goto LAB_0012fbc0;
      }
      idx = idx + -1;
      lVar3 = lVar3 + -8;
    } while (idx != -1);
  }
  Vector_compact(this_00);
  return;
}


/* Table_printHeader @ 0x131d50 */

void Table_printHeader(Settings_4 *settings,RichString *header)

{
  undefined1 __frame[0x100118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000d8;
  int wVar1;
  ScreenSettings_3 *pSVar2;
  int *piVar3;
  Settings_4 *settings_00;
  RichString *pRVar4;
  int iVar5;
  int wVar6;
  char *pcVar7;
  size_t sVar8;
  ulong uVar9;
  ulong uVar10;
  char cVar11;
  long lVar12;
  cchar_t *pcVar13;
  int **ppiVar14;
  int **ppiVar15;
  undefined1 *puVar16;
  RowField RVar17;
  long lVar18;
  long lVar19;
  int *piVar20;
  long in_FS_OFFSET = (long)__fake_fs;

  ppiVar14 = &(*(int *(*))(__fp - 0x88));
  ppiVar15 = &(*(int *(*))(__fp - 0x88));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(Settings_4 *(*))(__fp - 0x80)) = settings;
  (*(RichString *(*))(__fp - 0x60)) = header;
  RichString_setLen(header,0);
  pSVar2 = settings->ss;
  cVar11 = pSVar2->treeView;
  piVar20 = pSVar2->fields;
  if ((_Bool)cVar11 == false) {
    RVar17 = pSVar2->sortKey;
  }
  else {
    RVar17 = 1;
    if (pSVar2->treeViewAlwaysByPID == false) {
      RVar17 = pSVar2->treeSortKey;
    }
  }
                    /* Unresolved local var: int i@[???] */
  iVar5 = *piVar20;
  if (iVar5 != 0) {
    do {
      (*(int (*))(__fp - 0x50)) = RVar17;
      (*(ScreenSettings_3 *(*))(__fp - 0x78)) = pSVar2;
      settings_00 = (*(Settings_4 *(*))(__fp - 0x80));
      if (((cVar11 == '\0') || ((*(ScreenSettings_3 *(*))(__fp - 0x78))->treeViewAlwaysByPID == false)) && ((*(int (*))(__fp - 0x50)) == iVar5)) {
        (*(int (*))(__fp - 0x6c)) = CRT_colors[9];
      }
      else {
        (*(int (*))(__fp - 0x6c)) = CRT_colors[7];
      }
      *(int *)((long)ppiVar14 + -8) = 0x131df8;
      *(int *)((long)ppiVar14 + -4) = 0;
      pcVar7 = RowField_alignedTitle(settings_00,iVar5);
      *(int *)((long)ppiVar14 + -8) = 0x131e03;
      *(int *)((long)ppiVar14 + -4) = 0;
      sVar8 = strlen(pcVar7);
                    /* Unresolved local var: int[32149] data@[???]
                       Unresolved local var: int newLen@[???] */
      (*(int *(*))(__fp - 0x68)) = (int *)ppiVar14;
      uVar10 = (ulong)((int)sVar8 + 1);
      wVar6 = (*(RichString *(*))(__fp - 0x60))->chlen;
      uVar9 = uVar10 * 4 + 0xf;
      puVar16 = (undefined1 *)((long)ppiVar14 - (uVar9 & 0xfffffffffffff000));
      for (; ppiVar14 != (int **)puVar16; ppiVar14 = (int **)((long)ppiVar14 + -0x1000)) {
        *(undefined8 *)((long)ppiVar14 + -8) = *(undefined8 *)((long)ppiVar14 + -8);
      }
      uVar9 = (ulong)((uint)uVar9 & 0xff0);
      lVar18 = -uVar9;
      if (uVar9 != 0) {
        *(undefined8 *)((long)ppiVar14 + -8) = *(undefined8 *)((long)ppiVar14 + -8);
      }
      uVar9 = __mbstowcs_chk((int *)((long)ppiVar14 + lVar18),pcVar7,(long)(int)sVar8,
                             uVar10 & 0x3fffffffffffffff);
      pRVar4 = (*(RichString *(*))(__fp - 0x60));
      if (0 < (int)uVar9) {
        (*(int (*))(__fp - 0x4c)) = wVar6 + (int)uVar9;
        lVar12 = (long)wVar6;
        RichString_setLen((*(RichString *(*))(__fp - 0x60)),(*(int (*))(__fp - 0x4c)));
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
        (*(int *(*))(__fp - 0x88)) = piVar20;
        (*(undefined8 (*))(__fp - 0x58)) = (int *)(CONCAT44((*(uint *)((char *)&(*(undefined8 (*))(__fp - 0x58)) + 4)),(*(int (*))(__fp - 0x6c))) & 0xffffffff00ffffff);
        lVar19 = lVar12 * -4;
        pcVar13 = pRVar4->chptr + lVar12;
        do {
          wVar6 = *(int *)((long)ppiVar14 + lVar12 * 4 + lVar19 + lVar18);
          iVar5 = iswprint(wVar6);
          pcVar13->attr = 0;
          pcVar13->chars[0] = 0;
          pcVar13->chars[1] = 0;
          pcVar13->chars[2] = 0;
          if (iVar5 == 0) {
            wVar6 = 65533;
          }
          *(undefined16 *)(*(undefined1 (*) [16])(pcVar13->chars + 2)) = (undefined16)0x0;
          lVar12 = lVar12 + 1;
          pcVar13->attr = (attr_t)(*(undefined8 (*))(__fp - 0x58));
          pcVar13->chars[0] = wVar6;
          piVar20 = (*(int *(*))(__fp - 0x88));
          pcVar13 = pcVar13 + 1;
        } while ((int)lVar12 < (*(int (*))(__fp - 0x4c)));
      }
      pRVar4 = (*(RichString *(*))(__fp - 0x60));
      piVar3 = (*(int *(*))(__fp - 0x68));
      if ((*piVar20 == (*(int (*))(__fp - 0x50))) &&
         (wVar6 = (*(RichString *(*))(__fp - 0x60))->chlen, (*(RichString *(*))(__fp - 0x60))->chptr[(long)wVar6 + -1].chars[0] == ' ')) {
                    /* Unresolved local var: _Bool ascending@[???] */
                    /* Unresolved local var: int[32162] data@[???]
                       Unresolved local var: int newLen@[???] */
        wVar1 = (*(ScreenSettings_3 *(*))(__fp - 0x78))->treeDirection;
        if ((*(ScreenSettings_3 *(*))(__fp - 0x78))->treeView == false) {
          wVar1 = (*(ScreenSettings_3 *(*))(__fp - 0x78))->direction;
        }
        piVar3[-2] = 0x131f81;
        piVar3[-1] = 0;
        RichString_setLen(pRVar4,wVar6 + -1);
        (*(undefined8 (*))(__fp - 0x58)) = piVar3;
        wVar6 = pRVar4->chlen;
        lVar18 = (long)wVar6;
        pcVar7 = CRT_treeStr[(ulong)(wVar1 != 1) + 6];
        wVar1 = CRT_colors[9];
        piVar3[-2] = 0x131fba;
        piVar3[-1] = 0;
        sVar8 = mbstowcs((*(int (*) [2])(__fp - 0x48)),pcVar7,1);
        pRVar4 = (*(RichString *(*))(__fp - 0x60));
        if (0 < (int)sVar8) {
          wVar6 = (int)sVar8 + wVar6;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
          (*(int (*))(__fp - 0x4c)) = wVar6;
          piVar3[-2] = 0x131fd9;
          piVar3[-1] = 0;
          RichString_setLen(pRVar4,wVar6);
          (*(int *(*))(__fp - 0x68)) = piVar20;
          pcVar13 = pRVar4->chptr + lVar18;
          lVar19 = lVar18;
          do {
            wVar6 = (*(int (*) [2])(__fp - 0x48))[lVar19 - lVar18];
            piVar3[-2] = 0x13200c;
            piVar3[-1] = 0;
            iVar5 = iswprint(wVar6);
            pcVar13->attr = 0;
            pcVar13->chars[0] = 0;
            pcVar13->chars[1] = 0;
            pcVar13->chars[2] = 0;
            if (iVar5 == 0) {
              wVar6 = 65533;
            }
            pcVar13->attr = wVar1 & 0xffffff;
            lVar19 = lVar19 + 1;
            *(undefined16 *)(*(undefined1 (*) [16])(pcVar13->chars + 2)) = (undefined16)0x0;
            pcVar13->chars[0] = wVar6;
            pcVar13 = pcVar13 + 1;
            piVar20 = (*(int *(*))(__fp - 0x68));
          } while ((int)lVar19 < (*(int (*))(__fp - 0x4c)));
        }
        ppiVar15 = (int **)(*(undefined8 (*))(__fp - 0x58));
        if (*piVar20 != 2) goto LAB_00131f23;
LAB_00132050:
        if ((*(Settings_4 *(*))(__fp - 0x80))->showMergedCommand == false) goto LAB_00131f23;
        piVar20 = piVar20 + 1;
        *(int *)((long)ppiVar15 + -8) = 0x132075;
        *(int *)((long)ppiVar15 + -4) = 0;
        RichString_appendAscii((*(RichString *(*))(__fp - 0x60)),(*(int (*))(__fp - 0x6c)),((char *)(long)&s__merged__0014915d /* "(merged)" */));
        iVar5 = *piVar20;
      }
      else {
        ppiVar15 = (int **)(*(int *(*))(__fp - 0x68));
        if (*piVar20 == 2) goto LAB_00132050;
LAB_00131f23:
        iVar5 = piVar20[1];
        piVar20 = piVar20 + 1;
      }
      if (iVar5 == 0) break;
      cVar11 = (*(ScreenSettings_3 *(*))(__fp - 0x78))->treeView;
      ppiVar14 = ppiVar15;
      pSVar2 = (*(ScreenSettings_3 *(*))(__fp - 0x78));
      RVar17 = (*(int (*))(__fp - 0x50));
    } while( true );
  }
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Table_init @ 0x132aa0 */

/* DWARF original prototype: Table * Table_init(Table * this, ObjectClass * klass, Machine * host)
    */

Table_2 * Table_init(Table *this,ObjectClass *klass,Machine_2 *host)

{
  Vector *pVVar1;
  Object **ppOVar2;
  Hashtable *pHVar3;

                    /* Unresolved local var: Vector * this@[???] */
                    /* Unresolved local var: void * data@[???] */
  pVVar1 = malloc(0x28);
  if (pVVar1 != (Vector *)0x0) {
    pVVar1->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
    ppOVar2 = calloc(10,8);
    if (ppOVar2 != (Object **)0x0) {
      pVVar1->array = ppOVar2;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
      pVVar1->arraySize = 10;
      pVVar1->type = klass;
      pVVar1->owner = true;
      pVVar1->items = 0;
      pVVar1->dirty_index = -1;
      pVVar1->dirty_count = 0;
      this->rows = pVVar1;
      pVVar1 = malloc(0x28);
      if (pVVar1 != (Vector *)0x0) {
        pVVar1->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
        ppOVar2 = calloc(10,8);
        if (ppOVar2 != (Object **)0x0) {
          pVVar1->type = klass;
          pVVar1->items = 0;
          pVVar1->dirty_index = -1;
          this->displayList = pVVar1;
          pVVar1->array = ppOVar2;
          pVVar1->arraySize = 10;
          pVVar1->owner = false;
          pVVar1->dirty_count = 0;
          pHVar3 = Hashtable_new(200,false);
          this->needsSort = true;
          this->table = pHVar3;
          this->following = -1;
          this->host = (Machine_ *)host;
          return (Table_2 *)this;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Table_add @ 0x1341b0 */

/* DWARF original prototype: void Table_add(Table * this, Row * row) */

void Table_add(Table *this,Row_2 *row)

{
  Vector *this_00;

  this_00 = this->rows;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
  row->seenStampMs = this->host->monotonicMs;
  Vector_set(this_00,this_00->items,row);
  Hashtable_put(this->table,row->id,row);
  return;
}


/* Table_buildTreeBranch @ 0x1341f0 */

/* DWARF original prototype: void Table_buildTreeBranch(Table * this, int rowid, uint level,
   int32_t indent, _Bool show) */

void Table_buildTreeBranch(Table *this,int rowid,uint level,int32_t indent,_Bool show)

{
  int wVar1;
  Object *pOVar2;
  void *data_;
  int wVar3;
  uint uVar4;
  uint uVar5;
  Vector *pVVar6;
  int wVar7;
  long lVar8;
  int wVar9;
  undefined1 show_00;
  uint indent_00;
  Object **ppOVar10;
  int wVar11;

                    /* Unresolved local var: int vsize@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int lastShown@[???] */
  if (rowid == 0) {
    return;
  }
  wVar11 = 0;
  pVVar6 = this->rows;
  wVar1 = pVVar6->items;
  wVar3 = wVar1;
  while (wVar7 = wVar3, wVar11 < wVar7) {
    while( true ) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: Row * row@[???]
                       Unresolved local var: int parent@[???] */
      wVar3 = (wVar11 + wVar7) / 2;
      pOVar2 = pVVar6->array[wVar3];
      wVar9 = 0;
      if ((*(char *)((long)&pOVar2[3].klass + 4) == '\0') &&
         (wVar9 = *(int *)((long)&pOVar2[2].klass + 4), wVar9 == *(int *)&pOVar2[2].klass))
      {
        wVar9 = *(int *)&pOVar2[3].klass;
      }
      if (rowid <= wVar9) break;
      wVar11 = wVar3 + 1;
      if (wVar7 <= wVar11) goto LAB_00134269;
    }
  }
LAB_00134269:
  if (wVar7 < wVar1) {
                    /* Unresolved local var: Row * row@[???] */
    ppOVar10 = pVVar6->array + wVar7;
    wVar3 = wVar7;
    do {
      pOVar2 = *ppOVar10;
      wVar9 = *(int *)((long)&pOVar2[2].klass + 4);
      if (wVar9 == *(int *)&pOVar2[2].klass) {
        wVar9 = *(int *)&pOVar2[3].klass;
      }
      if (rowid != wVar9) break;
      if (*(char *)((long)&pOVar2[3].klass + 6) != '\0') {
        wVar7 = wVar3;
      }
      wVar3 = wVar3 + 1;
      ppOVar10 = ppOVar10 + 1;
    } while (wVar3 != wVar1);
                    /* Unresolved local var: int i@[???] */
    if (wVar11 < wVar3) {
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: int32_t nextIndent@[DW_OP_reg11(R11)] */
      uVar4 = 0x1e;
      if (level < 0x1f) {
        uVar4 = level;
      }
      indent_00 = indent | 1 << (uVar4 & 0x1f);
      uVar4 = level + 1;
      lVar8 = (long)wVar11 * 8;
      while( true ) {
        data_ = *(void **)((long)pVVar6->array + lVar8);
        if (!show) {
          *(undefined1 *)((long)data_ + 0x1e) = 0;
        }
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
        Vector_set(this->displayList,this->displayList->items,data_);
        show_00 = false;
        if (*(char *)((long)data_ + 0x1e) != '\0') {
          show_00 = *(undefined1 *)((long)data_ + 0x20);
        }
        uVar5 = indent_00;
        if (wVar11 < wVar7) {
          Table_buildTreeBranch
                    (this,*(int *)((long)data_ + 0x10),uVar4,indent_00,(_Bool)show_00);
        }
        else {
          Table_buildTreeBranch(this,*(int *)((long)data_ + 0x10),uVar4,indent,(_Bool)show_00);
          if (wVar7 == wVar11) {
            uVar5 = -indent_00;
          }
        }
        wVar11 = wVar11 + 1;
        *(uint *)((long)data_ + 0x24) = uVar5;
        lVar8 = lVar8 + 8;
        *(uint *)((long)data_ + 0x28) = uVar4;
        if (wVar11 == wVar3) break;
        pVVar6 = this->rows;
      }
    }
  }
  return;
}


/* Table_buildTree @ 0x1343c0 */

/* DWARF original prototype: void Table_buildTree(Table * this) */

void Table_buildTree(Table *this)

{
  int wVar1;
  Vector *pVVar2;
  Object **array;
  Object *pOVar3;
  ulong uVar4;
  HashtableItem *pHVar5;
  void *data_;
  HashtableItem *pHVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  Object **ppOVar10;
  long lVar11;
  long lVar12;

                    /* Unresolved local var: int vsize@[???] */
  Vector_prune(this->displayList);
  pVVar2 = this->rows;
  wVar1 = pVVar2->items;
                    /* Unresolved local var: int i@[???] */
  if (wVar1 < 1) {
    quickSort(pVVar2->array,0,wVar1 + -1,compareRowByKnownParentThenNatural);
    this->needsSort = false;
    return;
  }
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: int parent@[???] */
  array = pVVar2->array;
  lVar11 = (long)wVar1 * 8;
  ppOVar10 = array;
  do {
    pOVar3 = *ppOVar10;
    uVar9 = *(uint *)((long)&pOVar3[2].klass + 4);
    if ((uVar9 == *(uint *)&pOVar3[2].klass) &&
       (uVar9 = *(uint *)&pOVar3[3].klass, uVar9 == *(uint *)&pOVar3[2].klass)) {
      *(undefined1 *)((long)&pOVar3[3].klass + 4) = 1;
    }
    else {
      *(undefined1 *)((long)&pOVar3[3].klass + 4) = 0;
      if (uVar9 != 0) {
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        uVar4 = this->table->size;
        pHVar5 = this->table->buckets;
        uVar8 = (ulong)uVar9 % uVar4;
        if (pHVar5[uVar8].value != (void *)0x0) {
          uVar7 = 0;
          pHVar6 = pHVar5 + uVar8;
          do {
            while( true ) {
              if (uVar9 == pHVar6->key) goto LAB_00134484;
              if (pHVar6->probe < uVar7) goto LAB_00134480;
              uVar8 = uVar8 + 1;
              if (uVar4 != uVar8) break;
              uVar8 = 0;
              uVar7 = uVar7 + 1;
              pHVar6 = pHVar5;
              if (pHVar5->value == (void *)0x0) goto LAB_00134480;
            }
            uVar7 = uVar7 + 1;
            pHVar6 = pHVar5 + uVar8;
          } while (pHVar6->value != (void *)0x0);
        }
      }
LAB_00134480:
      *(undefined1 *)((long)&pOVar3[3].klass + 4) = 1;
    }
LAB_00134484:
    ppOVar10 = ppOVar10 + 1;
  } while (array + wVar1 != ppOVar10);
  quickSort(array,0,wVar1 + -1,compareRowByKnownParentThenNatural);
                    /* Unresolved local var: int i@[???] */
  lVar12 = 0;
  do {
                    /* Unresolved local var: Row * row@[???] */
    while (data_ = *(void **)((long)this->rows->array + lVar12),
          *(char *)((long)data_ + 0x1c) == '\0') {
      lVar12 = lVar12 + 8;
      if (lVar11 == lVar12) goto LAB_00134500;
    }
    pVVar2 = this->displayList;
    *(undefined8 *)((long)data_ + 0x24) = 0;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
    lVar12 = lVar12 + 8;
    Vector_set(pVVar2,pVVar2->items,data_);
    Table_buildTreeBranch(this,*(int *)((long)data_ + 0x10),0,0,*(_Bool *)((long)data_ + 0x20));
  } while (lVar11 != lVar12);
LAB_00134500:
  this->needsSort = false;
  return;
}


/* Table_collapseAllBranches @ 0x134550 */

/* DWARF original prototype: void Table_collapseAllBranches(Table * this) */

void Table_collapseAllBranches(Table *this)

{
  Object **ppOVar1;
  int wVar2;
  Object *pOVar3;
  Object **ppOVar4;

  Table_buildTree(this);
  this->needsSort = true;
  wVar2 = this->rows->items;
                    /* Unresolved local var: int i@[???] */
  if (0 < wVar2) {
    ppOVar4 = this->rows->array;
    ppOVar1 = ppOVar4 + wVar2;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar3 = *ppOVar4;
      if ((*(int *)&pOVar3[5].klass != 0) && (1 < *(int *)&pOVar3[2].klass)) {
        *(undefined1 *)&pOVar3[4].klass = 0;
      }
      ppOVar4 = ppOVar4 + 1;
    } while (ppOVar4 != ppOVar1);
  }
  return;
}


/* Table_updateDisplayList @ 0x1345b0 */

/* DWARF original prototype: void Table_updateDisplayList(Table * this) */

void Table_updateDisplayList(Table *this)

{
  int wVar1;
  int wVar2;
  Vector *pVVar3;
  Object *pOVar4;
  Object *pOVar5;
  Vector *pVVar6;
  Object **ppOVar7;
  long a3;
  int wVar8;
  long a2;
  size_t prevmemb;
  long in_R9;
  int wVar9;
  long lVar10;

  if (this->host->settings->ss->treeView == false) {
                    /* Unresolved local var: int size@[???] */
    if (this->needsSort != false) {
      Vector_insertionSort(this->rows);
    }
    Vector_prune(this->displayList);
    pVVar6 = this->rows;
    wVar1 = pVVar6->items;
                    /* Unresolved local var: int i@[???] */
    if (0 < wVar1) {
      lVar10 = 0;
      do {
        pVVar3 = this->displayList;
        wVar2 = pVVar3->items;
        prevmemb = (size_t)pVVar3->arraySize;
        pOVar4 = *(Object **)((long)pVVar6->array + lVar10);
                    /* Unresolved local var: int oldSize@[???] */
        ppOVar7 = pVVar3->array;
        wVar9 = wVar2 + 1;
                    /* Unresolved local var: Object * removed@[???] */
        if (pVVar3->arraySize < wVar9) {
          wVar8 = wVar9 + pVVar3->growthRate;
          a3 = 8;
          pVVar3->arraySize = wVar8;
          ppOVar7 = xReallocArrayZero(ppOVar7,prevmemb,(long)wVar8,8);
          pVVar3->array = ppOVar7;
          if (pVVar3->items <= wVar2) goto LAB_00134630;
          ppOVar7 = ppOVar7 + wVar2;
          if ((pVVar3->owner != false) && (pOVar5 = *ppOVar7, pOVar5 != (Object *)0x0)) {
            (*(code *)(pOVar5->klass->delete))(pOVar5,prevmemb,a2,a3,(ulong)(uint)wVar2,in_R9);
            ppOVar7 = pVVar3->array + wVar2;
          }
        }
        else {
LAB_00134630:
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
          pVVar3->items = wVar9;
          ppOVar7 = ppOVar7 + wVar2;
        }
        *ppOVar7 = pOVar4;
        lVar10 = lVar10 + 8;
        if ((long)wVar1 * 8 == lVar10) break;
        pVVar6 = this->rows;
      } while( true );
    }
  }
  else if (this->needsSort != false) {
    Table_buildTree(this);
  }
  this->needsSort = false;
  return;
}


/* Table_rebuildPanel @ 0x134700 */

/* DWARF original prototype: void Table_rebuildPanel(Table * this) */

void Table_rebuildPanel(Table *this)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char cVar1;
  int wVar2;
  int wVar3;
  Object *data_;
  Object_Compare p_Var4;
  code *pcVar5;
  HashtableItem *pHVar6;
  int wVar7;
  int wVar8;
  int wVar9;
  Vector *pVVar10;
  ulong a5;
  HashtableItem *pHVar11;
  Hashtable_2 *a3;
  ulong uVar12;
  uint uVar13;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong a2;
  ulong extraout_RDX_02;
  long *a0;
  Panel_ *pPVar14;
  long in_R8;
  int wVar15;
  long lVar16;

  Table_updateDisplayList(this);
  pPVar14 = this->panel;
  wVar9 = pPVar14->selected;
  wVar2 = pPVar14->scrollV;
  wVar3 = pPVar14->items->items;
  Vector_prune(pPVar14->items);
  pPVar14->selected = 0;
  pPVar14->oldSelected = 0;
  wVar15 = this->following;
  a5 = (ulong)(uint)wVar15;
  pPVar14->scrollV = 0;
  pPVar14->needsRedraw = true;
  if (wVar15 != -1) {
    a3 = this->table;
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
    uVar12 = a3->size;
    pHVar6 = a3->buckets;
    a2 = (ulong)(uint)wVar15 % uVar12;
    pHVar11 = pHVar6 + a2;
    a0 = pHVar11->value;
    if (a0 != (long *)0x0) {
      a3 = (Hashtable_2 *)0x0;
      do {
        if (wVar15 == pHVar11->key) {
          a5 = (ulong)*(uint *)((long)a0 + 0x14);
          a3 = (Hashtable_2 *)0x0;
          a2 = a5 % uVar12;
          pHVar11 = pHVar6 + a2;
          if (pHVar11->value != (void *)0x0) goto LAB_0013499f;
          break;
        }
        if ((Hashtable_2 *)pHVar11->probe < a3) break;
        a2 = a2 + 1;
        if (uVar12 == a2) {
          a2 = 0;
          pHVar11 = pHVar6;
        }
        else {
          pHVar11 = pHVar6 + a2;
        }
        a0 = pHVar11->value;
        a3 = (Hashtable_2 *)((long)&a3->size + 1);
      } while (a0 != (long *)0x0);
    }
    goto LAB_00134860;
  }
  pVVar10 = this->displayList;
  (*(int (*))(__fp - 0x3c)) = pVVar10->items;
  a3 = (Hashtable_2 *)(ulong)(uint)(*(int (*))(__fp - 0x3c));
                    /* Unresolved local var: int i@[???] */
  a2 = extraout_RDX;
  if (0 < (*(int (*))(__fp - 0x3c))) goto LAB_0013476f;
  goto LAB_001349c0;
  while( true ) {
    if ((Hashtable_2 *)pHVar11->probe < a3) break;
    a2 = a2 + 1;
    if (uVar12 == a2) {
      a2 = 0;
      pHVar11 = pHVar6;
    }
    else {
      pHVar11 = pHVar6 + a2;
    }
    a3 = (Hashtable_2 *)((long)&a3->size + 1);
    if (pHVar11->value == (void *)0x0) break;
LAB_0013499f:
    if (*(uint *)((long)a0 + 0x14) == pHVar11->key) {
      if (*(code **)(*a0 + 0x28) != (code *)0x0) {
        lVar16 = (**(code **)(*a0 + 0x28))((long)a0,(long)this,a2,(long)a3,in_R8,a5);
        if ((char)lVar16 == '\0') {
          this->following = *(int *)((long)a0 + 0x14);
        }
        pVVar10 = this->displayList;
        (*(int (*))(__fp - 0x3c)) = pVVar10->items;
        a3 = (Hashtable_2 *)(ulong)(uint)(*(int (*))(__fp - 0x3c));
        a2 = extraout_RDX_02;
        if (0 < (*(int (*))(__fp - 0x3c))) goto LAB_0013476f;
        (*(char (*))(__fp - 0x41)) = '\0';
        goto LAB_001347dd;
      }
      break;
    }
  }
LAB_00134860:
  pVVar10 = this->displayList;
  (*(int (*))(__fp - 0x3c)) = pVVar10->items;
  if ((*(int (*))(__fp - 0x3c)) < 1) {
LAB_00134878:
    pPVar14 = this->panel;
    this->following = -1;
    pPVar14->selectionColorId = PANEL_SELECTION_FOCUS;
    goto LAB_0013488e;
  }
LAB_0013476f:
  (*(char (*))(__fp - 0x41)) = '\0';
                    /* Unresolved local var: Row * followed@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  lVar16 = 0;
  wVar15 = 0;
  while( true ) {
    data_ = pVVar10->array[lVar16];
    cVar1 = *(char *)((long)&data_[3].klass + 6);
    if ((cVar1 != '\0') &&
       ((p_Var4 = data_->klass[1].compare, p_Var4 == (Object_Compare)0x0 ||
        (wVar7 = (*(code *)(p_Var4))(data_,this,a2,(long)a3,in_R8,a5), a2 = extraout_RDX_00,
        (char)wVar7 == '\0')))) {
      Vector_set(this->panel->items,wVar15,data_);
      a2 = extraout_RDX_01;
      if ((this->following != -1) && (this->following == *(int *)&data_[2].klass)) {
        pPVar14 = this->panel;
                    /* Unresolved local var: int size@[???] */
        wVar7 = pPVar14->items->items;
        wVar8 = wVar7 + -1;
        if (wVar15 < wVar7) {
          wVar8 = wVar15;
        }
        if (wVar8 < 0) {
          wVar8 = 0;
        }
        pPVar14->selected = wVar8;
        pcVar5 = (pPVar14->super).klass[1].extends;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)((long)pPVar14,0xffffffff,0,(long)a3,in_R8,a5);
          pPVar14 = this->panel;
        }
        uVar13 = wVar9 - wVar2;
        a2 = (ulong)uVar13;
        pPVar14->scrollV = wVar15 - uVar13;
        (*(char (*))(__fp - 0x41)) = cVar1;
      }
      wVar15 = wVar15 + 1;
    }
    lVar16 = lVar16 + 1;
    if ((*(int (*))(__fp - 0x3c)) <= (int)lVar16) break;
                    /* Unresolved local var: Row * row@[???] */
    pVVar10 = this->displayList;
  }
LAB_001347dd:
  if (this->following != -1) {
    if ((*(char (*))(__fp - 0x41)) == '\0') goto LAB_00134878;
    if (this->following != -1) {
      return;
    }
  }
LAB_001349c0:
  pPVar14 = this->panel;
LAB_0013488e:
                    /* Unresolved local var: int size@[???] */
  wVar15 = pPVar14->items->items;
  pcVar5 = (pPVar14->super).klass[1].extends;
  if ((wVar9 < 1) || (wVar3 + -1 != wVar9)) {
    wVar3 = wVar15 + -1;
    if (wVar9 < wVar15) {
      wVar3 = wVar9;
    }
    uVar12 = (ulong)(uint)wVar3;
    wVar9 = 0;
    if (-1 < wVar3) {
      wVar9 = wVar3;
    }
    pPVar14->selected = wVar9;
  }
  else {
    wVar15 = wVar15 + -1;
    uVar12 = 0;
    if (wVar15 < 0) {
      wVar15 = 0;
    }
    pPVar14->selected = wVar15;
  }
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)((long)pPVar14,0xffffffff,(long)pcVar5,uVar12,in_R8,a5);
    pPVar14 = this->panel;
  }
  pPVar14->scrollV = wVar2;
  return;
}

