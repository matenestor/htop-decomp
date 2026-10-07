#include "htop.h"

/* Header_new @ 0x1184a0 */

Header_4 * Header_new(Machine_2 *host,HeaderLayout hLayout)

{
  Header_4 *pHVar1;
  Vector **ppVVar2;
  Vector *pVVar3;
  Object **ppOVar4;
  ulong uVar5;
  ulong uVar6;

                    /* Unresolved local var: void * data@[???] */
  pHVar1 = calloc(1,0x20);
  if (pHVar1 != (Header_4 *)0x0) {
    uVar6 = (ulong)HeaderLayout_layouts[hLayout].columns;
                    /* Unresolved local var: void * data@[???] */
    ppVVar2 = malloc(uVar6 * 8);
    if (ppVVar2 != (Vector **)0x0) {
      pHVar1->columns = ppVVar2;
      pHVar1->headerLayout = hLayout;
      pHVar1->host = host;
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
      if (uVar6 != 0) {
                    /* Unresolved local var: Vector * this@[???] */
        uVar5 = 0;
        do {
                    /* Unresolved local var: void * data@[???] */
          pVVar3 = malloc(0x28);
          if (pVVar3 == (Vector *)0x0) goto LAB_00118594;
          pVVar3->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
          ppOVar4 = calloc(10,8);
          if (ppOVar4 == (Object **)0x0) goto LAB_00118594;
          pVVar3->array = ppOVar4;
          ppVVar2[uVar5] = pVVar3;
          uVar5 = uVar5 + 1;
          pVVar3->arraySize = 10;
          pVVar3->type = &Meter_class.super;
          pVVar3->owner = true;
          pVVar3->items = 0;
          pVVar3->dirty_index = -1;
          pVVar3->dirty_count = 0;
        } while (uVar5 != uVar6);
      }
      return pHVar1;
    }
  }
LAB_00118594:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Header_reinit @ 0x120190 */

/* DWARF original prototype: void Header_reinit(Header * this) */

void Header_reinit(Header *this)

{
  byte bVar1;
  code *pcVar2;
  Vector *pVVar3;
  ulong a3;
  Vector **a2;
  long lVar4;
  long in_RSI;
  long in_R8;
  long in_R9;
  ulong uVar5;

                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar1 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar1 != 0) {
    a2 = this->columns;
    uVar5 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      pVVar3 = a2[uVar5];
      lVar4 = 0;
      a3 = (ulong)(uint)pVVar3->items;
      if (0 < pVVar3->items) {
        do {
                    /* Unresolved local var: Meter * meter@[???] */
          pcVar2 = pVVar3->array[lVar4]->klass[1].extends;
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)pVVar3->array[lVar4],in_RSI,(long)a2,a3,in_R8,in_R9);
            a2 = this->columns;
          }
          pVVar3 = a2[uVar5];
          lVar4 = lVar4 + 1;
        } while ((int)lVar4 < pVVar3->items);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != bVar1);
  }
  return;
}


/* Header_draw @ 0x120230 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void Header_draw(Header * this) */

void Header_draw(Header *this)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  byte *pbVar1;
  byte bVar2;
  int wVar3;
  Vector *pVVar4;
  Object *a0;
  int iVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  int wVar9;
  long in_R8;
  long in_R9;
  int p1;
  uint uVar10;
  float fVar11;
  float fVar12;

  p1 = 0;
  wVar3 = this->height;
  wVar9 = this->pad;
  wattrset(_stdscr,*CRT_colors);
                    /* Unresolved local var: int y@[???] */
  if (0 < wVar3) {
    do {
      iVar5 = wmove(_stdscr,p1,0);
      if (iVar5 != -1) {
        whline(_stdscr,0x20,_COLS);
      }
      p1 = p1 + 1;
    } while (wVar3 != p1);
  }
  lVar6 = (long)this->headerLayout;
  bVar2 = HeaderLayout_layouts[lVar6].columns;
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  if ((ulong)bVar2 != 0) {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: float colWidth@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int i@[???] */
    (*(ulong (*))(__fp - 0x48)) = 0;
    (*(float (*))(__fp - 0x54)) = 0.0;
    uVar7 = wVar9 / 2;
    fVar12 = (float)((_COLS + wVar9 * -2) - (bVar2 - 1));
    while( true ) {
      pVVar4 = this->columns[(*(ulong (*))(__fp - 0x48))];
      (*(float (*))(__fp - 0x3c)) = ((float)*(byte *)((*(ulong (*))(__fp - 0x48)) + lVar6 * 0x18 + (long)(__sec_data_rel_ro + 0x3a1)) * fVar12) / 100.0;
      fVar11 = (*(float (*))(__fp - 0x3c));
      if (ABS((*(float (*))(__fp - 0x3c))) < 8388608.0) {
        fVar11 = __builtin_floorf((*(float (*))(__fp - 0x3c)));
      }
      (*(float (*))(__fp - 0x54)) = ((*(float (*))(__fp - 0x3c)) - fVar11) + (*(float (*))(__fp - 0x54));
      if (1.0 <= (*(float (*))(__fp - 0x54))) {
        (*(float (*))(__fp - 0x54)) = (*(float (*))(__fp - 0x54)) - 1.0;
        (*(float (*))(__fp - 0x3c)) = (*(float (*))(__fp - 0x3c)) + 1.0;
      }
      lVar6 = 0;
      uVar10 = uVar7;
      if (0 < pVVar4->items) {
        do {
          a0 = pVVar4->array[lVar6];
          fVar11 = (*(float (*))(__fp - 0x3c));
                    /* Unresolved local var: int j@[???] */
          if (((*(int *)&a0[4].klass == 2) && (*(char *)((long)&a0->klass[4].delete + 1) == '\0'))
             && (iVar5 = *(int *)((long)&a0[9].klass + 4), 1 < iVar5)) {
            lVar8 = 1;
            do {
              pbVar1 = (byte *)((*(ulong (*))(__fp - 0x48)) + (long)this->headerLayout * 0x18 + (long)(__sec_data_rel_ro + 0x3a1) + lVar8);
              lVar8 = lVar8 + 1;
              fVar11 = fVar11 + 1.0 + ((float)*pbVar1 * fVar12) / 100.0;
            } while ((int)lVar8 < iVar5);
          }
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: float actualWidth@[???] */
          if (ABS(fVar11) < 8388608.0) {
            fVar11 = __builtin_floorf(fVar11);
          }
          (*(code *)a0[1].klass)
                    ((long)a0,(ulong)(uint)wVar9,(ulong)uVar10,(ulong)(uint)(int)fVar11,in_R8,in_R9)
          ;
          lVar6 = lVar6 + 1;
          uVar10 = uVar10 + *(int *)&a0[9].klass;
        } while ((int)lVar6 < pVVar4->items);
      }
      if (ABS((*(float (*))(__fp - 0x3c))) < 8388608.0) {
        (*(float (*))(__fp - 0x3c)) = __builtin_floorf((*(float (*))(__fp - 0x3c)));
      }
      (*(ulong (*))(__fp - 0x48)) = (*(ulong (*))(__fp - 0x48)) + 1;
      wVar9 = (int)((float)wVar9 + (*(float (*))(__fp - 0x3c))) + 1;
      if (bVar2 <= (*(ulong (*))(__fp - 0x48))) break;
      lVar6 = (long)this->headerLayout;
    }
  }
  return;
}


/* Header_updateData @ 0x120590 */

/* DWARF original prototype: void Header_updateData(Header * this) */

void Header_updateData(Header *this)

{
  byte bVar1;
  int wVar2;
  Vector *pVVar3;
  long *a0;
  long in_RCX;
  long extraout_RDX;
  long a2;
  long lVar4;
  long in_RSI;
  long in_R8;
  long in_R9;
  ulong uVar5;

                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  a2 = (long)this->headerLayout * 3;
  bVar1 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar1 != 0) {
    uVar5 = 0;
    do {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: int items@[???] */
      pVVar3 = this->columns[uVar5];
      wVar2 = pVVar3->items;
                    /* Unresolved local var: int i@[???] */
      if (0 < wVar2) {
        lVar4 = 0;
        do {
                    /* Unresolved local var: Meter * meter@[???] */
          a0 = *(long **)((long)pVVar3->array + lVar4);
          lVar4 = lVar4 + 8;
          (**(code **)(*a0 + 0x38))((long)a0,in_RSI,a2,in_RCX,in_R8,in_R9);
          a2 = extraout_RDX;
        } while ((long)wVar2 * 8 != lVar4);
      }
      uVar5 = uVar5 + 1;
    } while (bVar1 != uVar5);
  }
  return;
}


/* Header_calculateHeight @ 0x120620 */

/* DWARF original prototype: int Header_calculateHeight(Header * this) */

int Header_calculateHeight(Header *this)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  Object **ppOVar1;
  Object **ppOVar2;
  _Bool _Var3;
  byte bVar4;
  Settings__5 *pSVar5;
  Vector **ppVVar6;
  Vector *pVVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  int wVar11;
  Object **ppOVar12;
  Object **ppOVar13;
  int wVar14;
  MeterClass_3 *pMVar15;
  ulong uVar16;
  int wVar17;
  int wVar18;
  ulong uVar19;

  pSVar5 = this->host->settings;
  _Var3 = pSVar5->headerMargin;
  (*(int (*))(__fp - 0x50)) = (uint)_Var3 + (uint)_Var3;
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar4 = HeaderLayout_layouts[this->headerLayout].columns;
  uVar19 = (ulong)bVar4;
  if (uVar19 != 0) {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Meter * meter@[???] */
    ppVVar6 = this->columns;
    uVar16 = 0;
    wVar11 = (*(int (*))(__fp - 0x50));
    do {
      pVVar7 = ppVVar6[uVar16];
      wVar17 = pVVar7->items;
      wVar18 = (*(int (*))(__fp - 0x50));
      if (0 < wVar17) {
        ppOVar13 = pVVar7->array;
        iVar8 = (int)uVar16;
                    /* Unresolved local var: size_t i@[???] */
        ppOVar1 = ppOVar13 + wVar17;
        wVar17 = (*(int (*))(__fp - 0x50));
        do {
          wVar18 = *(int *)&(*ppOVar13)[9].klass + wVar17;
          for (uVar10 = (ulong)(iVar8 + 1); iVar9 = (uint)bVar4 - iVar8, uVar10 < uVar19;
              uVar10 = uVar10 + 1) {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: int height@[???] */
            pVVar7 = ppVVar6[uVar10];
                    /* Unresolved local var: int j@[???] */
            wVar14 = pVVar7->items;
            if (0 < wVar14) {
              ppOVar12 = pVVar7->array;
              ppOVar2 = ppOVar12 + wVar14;
              wVar14 = (*(int (*))(__fp - 0x50));
              do {
                    /* Unresolved local var: Meter * meter@[???] */
                if (wVar18 <= wVar14) break;
                wVar14 = wVar14 + *(int *)&(*ppOVar12)[9].klass;
                if (wVar17 < wVar14) {
                    /* Unresolved local var: ObjectClass * type@[???] */
                  pMVar15 = (MeterClass_3 *)(*ppOVar12)->klass;
                  if (pMVar15 == (MeterClass_3 *)0x0) {
LAB_00120735:
                    iVar9 = (int)uVar10 - iVar8;
                    goto LAB_0012073e;
                  }
                  if (pMVar15 != &BlankMeter_class) {
                    do {
                      pMVar15 = (pMVar15->super).extends;
                      if (pMVar15 == (MeterClass_3 *)0x0) goto LAB_00120735;
                    } while (pMVar15 != &BlankMeter_class);
                  }
                }
                ppOVar12 = ppOVar12 + 1;
              } while (ppOVar2 != ppOVar12);
            }
          }
LAB_0012073e:
          *(int *)((long)&(*ppOVar13)[9].klass + 4) = iVar9;
          ppOVar13 = ppOVar13 + 1;
          wVar17 = wVar18;
        } while (ppOVar1 != ppOVar13);
      }
      if (wVar11 < wVar18) {
        wVar11 = wVar18;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 != uVar19);
    if (wVar11 != (*(int (*))(__fp - 0x50))) goto LAB_00120780;
  }
  (*(int (*))(__fp - 0x50)) = 0;
  wVar11 = 0;
LAB_00120780:
  wVar11 = (wVar11 + 1) - (uint)(pSVar5->screenTabs == false);
  this->pad = (*(int (*))(__fp - 0x50));
  this->height = wVar11;
  return wVar11;
}


/* Header_delete @ 0x123070 */

/* DWARF original prototype: void Header_delete(Header * this) */

void Header_delete(Header *this)

{
  Vector **ppVVar1;
  byte bVar2;
  ulong uVar3;

                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar2 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar2 != 0) {
    uVar3 = 0;
    do {
      ppVVar1 = this->columns + uVar3;
      uVar3 = uVar3 + 1;
      Vector_delete(*ppVVar1);
    } while (uVar3 != bVar2);
  }
  free(this->columns);
  free(this);
  return;
}


/* Header_setLayout @ 0x1230e0 */

/* DWARF original prototype: void Header_setLayout(Header * this, HeaderLayout hLayout) */

void Header_setLayout(Header *this,HeaderLayout hLayout)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  size_t __size;
  HeaderLayout HVar1;
  Vector **ppVVar2;
  Object *data_;
  Vector **ppVVar3;
  Object **ppOVar4;
  Vector *pVVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  int idx;
  int wVar9;

  HVar1 = this->headerLayout;
  this->headerLayout = hLayout;
  (*(ulong (*))(__fp - 0x40)) = (ulong)HeaderLayout_layouts[HVar1].columns;
  uVar7 = (ulong)HeaderLayout_layouts[hLayout].columns;
  if (uVar7 == (*(ulong (*))(__fp - 0x40))) {
    return;
  }
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: int j@[???] */
  __size = uVar7 * 8;
  ppVVar2 = this->columns;
  sVar6 = __size;
  uVar8 = uVar7;
  if ((*(ulong (*))(__fp - 0x40)) < uVar7) {
                    /* Unresolved local var: void * data@[???] */
    ppVVar3 = realloc(ppVVar2,__size);
    if (ppVVar3 == (Vector **)0x0) {
      free(ppVVar2);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->columns = ppVVar3;
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: Vector * this@[???] */
    do {
      pVVar5 = malloc(0x28);
      if (pVVar5 == (Vector *)0x0) goto LAB_00123275;
                    /* Unresolved local var: void * data@[???] */
      pVVar5->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
      ppOVar4 = calloc(10,8);
      if (ppOVar4 == (Object **)0x0) goto LAB_00123275;
      pVVar5->array = ppOVar4;
      pVVar5->arraySize = 10;
      pVVar5->type = &Meter_class.super;
      pVVar5->owner = true;
      pVVar5->items = 0;
      pVVar5->dirty_index = -1;
      pVVar5->dirty_count = 0;
      ppVVar3[(*(ulong (*))(__fp - 0x40))] = pVVar5;
      (*(ulong (*))(__fp - 0x40)) = (*(ulong (*))(__fp - 0x40)) + 1;
    } while ((*(ulong (*))(__fp - 0x40)) < uVar7);
  }
  else {
    while( true ) {
      pVVar5 = *(Vector **)((long)this->columns + sVar6);
      idx = pVVar5->items + -1;
      if (-1 < idx) {
        do {
          wVar9 = idx + -1;
          data_ = Vector_take(pVVar5,idx);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
          Vector_set(this->columns[uVar7 - 1],this->columns[uVar7 - 1]->items,data_);
          pVVar5 = *(Vector **)((long)this->columns + sVar6);
          idx = wVar9;
        } while (wVar9 != -1);
      }
      Vector_delete(pVVar5);
      uVar8 = uVar8 + 1;
      if ((*(ulong (*))(__fp - 0x40)) <= uVar8) break;
      sVar6 = uVar8 * 8;
    }
    ppVVar2 = this->columns;
                    /* Unresolved local var: void * data@[???] */
    ppVVar3 = realloc(ppVVar2,__size);
    if (ppVVar3 == (Vector **)0x0) {
      free(ppVVar2);
LAB_00123275:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->columns = ppVVar3;
  }
  Header_calculateHeight(this);
  return;
}


/* Header_addMeterByClass @ 0x123600 */

/* DWARF original prototype: Meter * Header_addMeterByClass(Header * this, MeterClass * type, uint
   param, uint column) */

Meter_3 * Header_addMeterByClass(Header *this,MeterClass_3 *type,uint param,uint column)

{
  Vector *this_00;
  Meter_3 *data_;

  this_00 = this->columns[column];
  data_ = Meter_new((Machine_2 *)this->host,param,type);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
  Vector_set(this_00,this_00->items,data_);
  return data_;
}


/* Header_populateFromSettings @ 0x126560 */

/* DWARF original prototype: void Header_populateFromSettings(Header * this) */

void Header_populateFromSettings(Header *this)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  MeterColumnSetting *pMVar1;
  HashtableItem *pHVar2;
  byte bVar3;
  int modeIndex;
  long lVar4;
  Settings__5 *pSVar5;
  char *__s;
  Vector *this_00;
  Hashtable_2 *pHVar6;
  bool bVar7;
  int iVar8;
  char *pcVar9;
  Meter_3 *this_01;
  char *pcVar10;
  size_t __n;
  ht_key_t hVar11;
  MeterClass **ppMVar12;
  ulong uVar13;
  HashtableItem *pHVar14;
  MeterClass_3 *type;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar5 = this->host->settings;
  Header_setLayout(this,pSVar5->hLayout);
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar3 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar3 != 0) {
    uVar13 = 0;
    do {
                    /* Unresolved local var: MeterColumnSetting * colSettings@[???] */
      pMVar1 = pSVar5->hColumns + uVar13;
      Vector_prune(this->columns[uVar13]);
                    /* Unresolved local var: size_t i@[???] */
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: char * paren@[???]
                       Unresolved local var: size_t nameLen@[???]
                       Unresolved local var: int ok@[???] */
      if (pMVar1->len != 0) {
        (*(ulong (*))(__fp - 0x80)) = 0;
        do {
          modeIndex = pMVar1->modes[(*(ulong (*))(__fp - 0x80))];
          __s = pMVar1->names[(*(ulong (*))(__fp - 0x80))];
          this_00 = this->columns[uVar13];
          pcVar9 = strchr(__s,0x28);
          (*(uint (*))(__fp - 0x6c)) = 0;
          if (pcVar9 == (char *)0x0) {
            __n = strlen(__s);
LAB_001266af:
                    /* Unresolved local var: MeterClass * * type@[???] */
            ppMVar12 = Platform_meterTypes;
            type = &CPUMeter_class;
                    /* Unresolved local var: char * end@[???]
                       Unresolved local var: Settings * settings@[???]
                       Unresolved local var: DynamicIterator_conflict1 iter@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator_conflict1 * iter@[???] */
            pcVar9 = ((char *)(long)(__sec_rodata + 0x826) /* "CPU" */);
            while ((iVar8 = strncmp(__s,pcVar9,__n), iVar8 != 0 || (pcVar9[__n] != '\0'))) {
              type = (MeterClass_3 *)ppMVar12[1];
              ppMVar12 = ppMVar12 + 1;
              if (type == (MeterClass_3 *)0x0) goto LAB_001266fe;
              pcVar9 = ((MeterClass *)type)->name;
            }
                    /* Unresolved local var: Meter * meter@[???] */
            this_01 = Meter_new((Machine_2 *)this->host,(*(uint (*))(__fp - 0x6c)),type);
            if (modeIndex != 0) {
              Meter_setMode((Meter *)this_01,modeIndex);
            }
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
            Vector_set(this_00,this_00->items,this_01);
          }
          else {
            iVar8 = __isoc23_sscanf(pcVar9,((char *)(long)&s___10u__00148819 /* "(%10u)" */),&(*(uint (*))(__fp - 0x6c)));
            if (iVar8 != 0) {
LAB_001266a9:
              __n = (long)pcVar9 - (long)__s;
              goto LAB_001266af;
            }
            (*(char (*) [32])(__fp - 0x68))[0] = '\0';
            (*(char (*) [32])(__fp - 0x68))[1] = '\0';
            (*(char (*) [32])(__fp - 0x68))[2] = '\0';
            (*(char (*) [32])(__fp - 0x68))[3] = '\0';
            (*(char (*) [32])(__fp - 0x68))[4] = '\0';
            (*(char (*) [32])(__fp - 0x68))[5] = '\0';
            (*(char (*) [32])(__fp - 0x68))[6] = '\0';
            (*(char (*) [32])(__fp - 0x68))[7] = '\0';
            (*(char (*) [32])(__fp - 0x68))[8] = '\0';
            (*(char (*) [32])(__fp - 0x68))[9] = '\0';
            (*(char (*) [32])(__fp - 0x68))[10] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0xb] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0xc] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0xd] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0xe] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0xf] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x10] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x11] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x12] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x13] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x14] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x15] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x16] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x17] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x18] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x19] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x1a] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x1b] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x1c] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x1d] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x1e] = '\0';
            (*(char (*) [32])(__fp - 0x68))[0x1f] = '\0';
            iVar8 = __isoc23_sscanf(pcVar9,((char *)(long)(__sec_rodata + 0x1c03) /* "(%30s)" */),(*(char (*) [32])(__fp - 0x68)));
            if (iVar8 == 0) {
              (*(uint (*))(__fp - 0x6c)) = 0;
              goto LAB_001266a9;
            }
            pcVar10 = strrchr((*(char (*) [32])(__fp - 0x68)),0x29);
            if (pcVar10 != (char *)0x0) {
              *pcVar10 = '\0';
              pHVar6 = this->host->settings->dynamicMeters;
              if ((pHVar6 != (Hashtable_2 *)0x0) && (pHVar6->size != 0)) {
                pHVar14 = pHVar6->buckets;
                hVar11 = 0;
                pHVar2 = pHVar14 + pHVar6->size;
                bVar7 = false;
                do {
                  if ((pHVar14->value != (char *)0x0) &&
                     (iVar8 = strcmp((*(char (*) [32])(__fp - 0x68)),pHVar14->value), iVar8 == 0)) {
                    hVar11 = pHVar14->key;
                    bVar7 = true;
                  }
                  pHVar14 = pHVar14 + 1;
                } while (pHVar2 != pHVar14);
                (*(uint (*))(__fp - 0x6c)) = hVar11;
                if (bVar7) goto LAB_001266a9;
              }
            }
          }
LAB_001266fe:
          (*(ulong (*))(__fp - 0x80)) = (*(ulong (*))(__fp - 0x80)) + 1;
        } while ((*(ulong (*))(__fp - 0x80)) < pMVar1->len);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != bVar3);
  }
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  Header_calculateHeight(this);
  return;
}


/* Header_writeBackToSettings @ 0x126910 */

/* DWARF original prototype: void Header_writeBackToSettings(Header * this) */

void Header_writeBackToSettings(Header *this)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  MeterColumnSetting *pMVar1;
  int wVar2;
  uint va1;
  Settings *this_00;
  Vector *pVVar3;
  Object *pOVar4;
  MeterClass_3 *pMVar5;
  HashtableItem *pHVar6;
  ulong uVar7;
  char **ppcVar8;
  int *pwVar9;
  HashtableItem *pHVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  void *va1_00;
  ulong uVar15;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (Settings *)this->host->settings;
  Settings_setHeaderLayout(this_00,this->headerLayout);
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  uVar7 = (ulong)HeaderLayout_layouts[this->headerLayout].columns;
  if (uVar7 != 0) {
    uVar15 = 0;
    do {
      while( true ) {
        pMVar1 = this_00->hColumns + uVar15;
        ppcVar8 = pMVar1->names;
        if (ppcVar8 != (char **)0x0) {
                    /* Unresolved local var: size_t j@[???] */
          if (pMVar1->len != 0) {
            uVar12 = 0;
            do {
              ppcVar8 = ppcVar8 + uVar12;
              uVar12 = uVar12 + 1;
              free(*ppcVar8);
              ppcVar8 = pMVar1->names;
            } while (uVar12 < pMVar1->len);
          }
          free(ppcVar8);
        }
                    /* Unresolved local var: MeterColumnSetting * colSettings@[???]
                       Unresolved local var: Vector * vec@[???]
                       Unresolved local var: int len@[???] */
        free(pMVar1->modes);
        pVVar3 = this->columns[uVar15];
        wVar2 = pVVar3->items;
        if (wVar2 != 0) break;
        pMVar1->len = 0;
        uVar15 = uVar15 + 1;
        pMVar1->names = (char **)0x0;
        pMVar1->modes = (int *)0x0;
                    /* Unresolved local var: int i@[???] */
        if (uVar7 == uVar15) goto LAB_00126b00;
      }
                    /* Unresolved local var: void * data@[???] */
      if ((0x1fffffffffffffff < (ulong)(long)(wVar2 + 1)) ||
         (ppcVar8 = calloc((long)(wVar2 + 1),8), ppcVar8 == (char **)0x0)) {
LAB_00126be5:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      pMVar1->names = ppcVar8;
      uVar12 = (ulong)wVar2;
                    /* Unresolved local var: void * data@[???] */
      if ((0x3fffffffffffffff < uVar12) || (pwVar9 = calloc(uVar12,4), pwVar9 == (int *)0x0))
      goto LAB_00126be5;
      pMVar1->modes = pwVar9;
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: char * dynamic@[???] */
      pMVar1->len = uVar12;
      lVar13 = 0;
      do {
        pOVar4 = pVVar3->array[lVar13];
        va1 = *(uint *)((long)&pOVar4[4].klass + 4);
        pMVar5 = (MeterClass_3 *)pOVar4->klass;
        if (va1 == 0) {
LAB_00126ab3:
          xAsprintf(&(*(char *(*))(__fp - 0x48)),((char *)(long)(__sec_rodata + 0x626) /* "%s" */),pMVar5->name);
        }
        else if (pMVar5 == &DynamicMeter_class) {
                    /* Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
          uVar12 = this_00->dynamicMeters->size;
          pHVar6 = this_00->dynamicMeters->buckets;
          uVar11 = (ulong)va1 % uVar12;
          va1_00 = pHVar6[uVar11].value;
          if (va1_00 != (void *)0x0) {
            uVar14 = 0;
            pHVar10 = pHVar6 + uVar11;
            do {
              while( true ) {
                if (va1 == pHVar10->key) goto LAB_00126bb8;
                if (pHVar10->probe < uVar14) {
                  va1_00 = (void *)0x0;
                  goto LAB_00126bb8;
                }
                uVar11 = uVar11 + 1;
                if (uVar12 != uVar11) break;
                uVar11 = 0;
                uVar14 = uVar14 + 1;
                va1_00 = pHVar6->value;
                pHVar10 = pHVar6;
                if (va1_00 == (void *)0x0) goto LAB_00126bb8;
              }
              uVar14 = uVar14 + 1;
              pHVar10 = pHVar6 + uVar11;
              va1_00 = pHVar10->value;
            } while (va1_00 != (void *)0x0);
          }
LAB_00126bb8:
          xAsprintf(&(*(char *(*))(__fp - 0x48)),((char *)(long)&s__s__s__00148820 /* "%s(%s)" */),((char *)(long)&s_Dynamic_00147e36 /* "Dynamic" */),va1_00);
        }
        else {
          if (pMVar5 != &CPUMeter_class) goto LAB_00126ab3;
          xAsprintf(&(*(char *(*))(__fp - 0x48)),((char *)(long)&s__s__u__00148827 /* "%s(%u)" */),((char *)(long)(__sec_rodata + 0x826) /* "CPU" */),va1);
        }
        pMVar1->names[lVar13] = (*(char *(*))(__fp - 0x48));
        pMVar1->modes[lVar13] = *(int *)&pOVar4[4].klass;
        lVar13 = lVar13 + 1;
      } while ((int)lVar13 < wVar2);
      uVar15 = uVar15 + 1;
    } while (uVar7 != uVar15);
  }
LAB_00126b00:
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

