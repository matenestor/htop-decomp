#include "htop.h"

/* ScreenManager_size @ 0x12de10 */

undefined4 ScreenManager_size(long param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}


/* ScreenManager_resize @ 0x12dea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScreenManager_resize(int *param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  int iVar6;
  int iVar7;
  int iVar8;

  iVar8 = param_1[1];
  if ((*(char *)(*(long *)(param_1 + 0xe) + 0x1a) == '\0') && (*(long *)(param_1 + 10) != 0)) {
    iVar8 = iVar8 + *(int *)(*(long *)(param_1 + 10) + 0x18);
  }
  iVar4 = param_1[8];
  iVar1 = iVar4 + -1;
  plVar2 = (long *)**(long **)(param_1 + 4);
  iVar7 = (_LINES - iVar8) + param_1[3];
  if (iVar1 < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    plVar5 = plVar2;
    do {
      lVar3 = *plVar5;
      plVar5 = plVar5 + 1;
      *(int *)(lVar3 + 8) = iVar6;
      *(int *)(lVar3 + 0x14) = iVar7;
      iVar6 = iVar6 + *(int *)(lVar3 + 0x10) + 1;
      *(undefined1 *)(lVar3 + 0x48) = 1;
      *(int *)(lVar3 + 0xc) = iVar8;
    } while (plVar2 + (ulong)(iVar4 - 2) + 1 != plVar5);
  }
  lVar3 = plVar2[iVar1];
  iVar4 = _COLS - *param_1;
  iVar1 = param_1[2];
  *(undefined1 *)(lVar3 + 0x48) = 1;
  *(ulong *)(lVar3 + 8) = CONCAT44(iVar8,iVar6);
  *(ulong *)(lVar3 + 0x10) = CONCAT44(iVar7,(iVar4 + iVar1) - iVar6);
  return;
}


/* ScreenManager_delete @ 0x12e390 */

void ScreenManager_delete
               (void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  Vector_delete(*(long **)((long)param_1 + 0x10),param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  free(param_1);
  return;
}


/* ScreenManager_remove @ 0x12e530 */

long * ScreenManager_remove
                 (long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9
                 )

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long *a0;
  long *plVar7;
  long a2;
  long lVar8;
  ulong a1;

  lVar8 = (long)param_2;
  a1 = (ulong)(uint)param_2;
  plVar7 = *(long **)(param_1 + 0x10);
  iVar3 = *(int *)(*(long *)(*plVar7 + lVar8 * 8) + 0x10);
  a0 = (long *)Vector_take(plVar7,param_2);
  if (*(char *)((long)plVar7 + 0x24) != '\0') {
    (**(code **)(*a0 + 0x10))((long)a0,a1,a2,param_rcx,param_r8,param_r9);
    a0 = (long *)0x0;
  }
  iVar4 = *(int *)(param_1 + 0x20);
  iVar1 = iVar4 + -1;
  *(int *)(param_1 + 0x20) = iVar1;
  if (param_2 < iVar1) {
    lVar5 = **(long **)(param_1 + 0x10);
    plVar7 = (long *)(lVar8 * 8 + lVar5);
    do {
      lVar6 = *plVar7;
      plVar7 = plVar7 + 1;
      piVar2 = (int *)(lVar6 + 8);
      *piVar2 = *piVar2 - iVar3;
      *(undefined1 *)(lVar6 + 0x48) = 1;
    } while (plVar7 != (long *)(lVar5 + 8 + ((ulong)((iVar4 - param_2) - 2) + lVar8) * 8));
  }
  return a0;
}


/* ScreenManager_new @ 0x132190 */

undefined8 *
ScreenManager_new(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *pvVar3;

  puVar1 = malloc(0x48);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0xffffffff00000000;
    puVar2 = malloc(0x28);
    if (puVar2 != (undefined8 *)0x0) {
      *(undefined4 *)((long)puVar2 + 0x14) = 10;
      pvVar3 = calloc(10,8);
      if (pvVar3 != (void *)0x0) {
        *(undefined4 *)(puVar1 + 4) = 0;
        puVar1[5] = param_1;
        *puVar2 = pvVar3;
        *(undefined4 *)(puVar2 + 2) = 10;
        puVar2[1] = Panel_class;
        *(undefined1 *)((long)puVar2 + 0x24) = param_4;
        puVar2[3] = 0xffffffff00000000;
        *(undefined4 *)(puVar2 + 4) = 0;
        puVar1[2] = puVar2;
        puVar1[6] = param_2;
        puVar1[7] = param_3;
        *(undefined1 *)(puVar1 + 8) = 1;
        return puVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ScreenManager_insert @ 0x132f90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScreenManager_insert(int *param_1,long param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  int iVar9;

  iVar8 = 0;
  plVar3 = *(long **)(param_1 + 4);
  if (0 < param_4) {
    lVar4 = *(long *)(*plVar3 + (long)(param_4 + -1) * 8);
    iVar8 = *(int *)(lVar4 + 0x10) + *(int *)(lVar4 + 8) + 1;
  }
  iVar9 = param_1[1];
  iVar2 = param_1[3];
  iVar6 = _LINES - iVar9;
  if (*(char *)(*(long *)(param_1 + 0xe) + 0x1a) == '\0') {
    lVar4 = *(long *)(param_1 + 10);
    if (lVar4 != 0) {
      iVar6 = iVar6 - *(int *)(lVar4 + 0x18);
    }
    if (param_3 < 1) {
      param_3 = ((_COLS - *param_1) + param_1[2]) - iVar8;
    }
    *(int *)(param_2 + 0x10) = param_3;
    *(int *)(param_2 + 0x14) = iVar6 + iVar2;
    *(undefined1 *)(param_2 + 0x48) = 1;
    if (lVar4 != 0) {
      iVar9 = iVar9 + *(int *)(lVar4 + 0x18);
    }
  }
  else {
    if (param_3 < 1) {
      param_3 = ((_COLS - *param_1) + param_1[2]) - iVar8;
    }
    *(int *)(param_2 + 0x10) = param_3;
    *(int *)(param_2 + 0x14) = iVar6 + iVar2;
    *(undefined1 *)(param_2 + 0x48) = 1;
  }
  *(int *)(param_2 + 0xc) = iVar9;
  iVar9 = param_1[8];
  *(int *)(param_2 + 8) = iVar8;
  if ((param_4 < iVar9) && (param_4 + 1 <= iVar9)) {
    lVar4 = *plVar3;
    lVar7 = (long)(param_4 + 1);
    do {
      lVar5 = *(long *)(lVar4 + lVar7 * 8);
      lVar7 = lVar7 + 1;
      piVar1 = (int *)(lVar5 + 8);
      *piVar1 = *piVar1 + param_3;
      *(undefined1 *)(lVar5 + 0x48) = 1;
    } while ((int)lVar7 <= iVar9);
  }
  Vector_insert(plVar3,param_4,param_2);
  *(undefined1 *)(param_2 + 0x48) = 1;
  param_1[8] = param_1[8] + 1;
  return;
}


/* ScreenManager_add @ 0x1330b0 */

void ScreenManager_add(int *param_1,long param_2,int param_3)

{
  ScreenManager_insert(param_1,param_2,param_3,*(int *)(*(long *)(param_1 + 4) + 0x18));
  return;
}


/* ScreenManager_run @ 0x134a30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScreenManager_run(int *param_1,undefined8 *param_2,uint *param_3,long *param_4,long param_r8,
                      long param_r9)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  long lVar1;
  long *plVar2;
  undefined8 *puVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long *plVar12;
  ulong uVar13;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  ulong extraout_RDX_03;
  uint uVar14;
  long lVar15;
  ulong a1;
  char cVar16;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar17;

  cVar16 = '\x01';
  uVar7 = 1;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  bVar4 = true;
  (*(double *)(__fp - 0x90)) = 0.0;
  bVar5 = false;
  (*(uint *)(__fp - 0x78)) = 0;
  (*(int *)(__fp - 0x94)) = 0;
  (*(uint *)(__fp - 0x80)) = 0xffffffff;
  (*(uint *)(__fp - 0x74)) = 0;
  (*(long * *)(__fp - 0x88)) = *(long **)**(undefined8 **)(param_1 + 4);
  lVar1 = **(long **)(param_1 + 0xc);
  *(long **)(param_1 + 6) = param_4;
LAB_00134ac3:
  if (*(long *)(param_1 + 10) == 0) goto LAB_00134d68;
LAB_00134acf:
  plVar2 = *(long **)(param_1 + 0xc);
  plVar12 = plVar2 + 3;
  Generic_gettime_realtime((undefined1 (*) [16])(plVar2 + 1),plVar12);
  iVar9 = Row_uidDigits;
  lVar15 = *plVar2;
  (*(double *)(__fp - 0x70)) = (double)plVar2[1] * 10.0 + (double)plVar2[2] / 100000.0;
  bVar4 = (double)*(int *)(lVar15 + 0x4c) < (*(double *)(__fp - 0x70)) - (*(double *)(__fp - 0x90));
  if ((((*(double *)(__fp - 0x70)) < (*(double *)(__fp - 0x90))) || (bVar4)) || (bVar5)) {
    param_4 = *(long **)(param_1 + 0xe);
    if (((char)param_4[3] == '\0') &&
       ((param_r9 = (long)(*(uint *)(__fp - 0x78)), (*(uint *)(__fp - 0x78)) == 0 ||
        (lVar15 = *(long *)(lVar15 + 0x40), *(char *)(lVar15 + 0x34) != '\0')))) {
      lVar15 = plVar2[0x15];
      (*(uint *)(__fp - 0x78)) = 1;
      *(undefined1 *)(lVar15 + 0x30) = 1;
    }
    Machine_scan(plVar2,(long)plVar12,lVar15,(long)param_4,param_r8,param_r9);
    lVar15 = *(long *)(param_1 + 0xe);
    if (*(char *)(lVar15 + 0x18) == '\0') {
      Machine_scanTables((long)plVar2,(long)plVar12,lVar15,(long)param_4,param_r8,param_r9);
      lVar15 = extraout_RDX_02;
    }
    Header_updateData(*(long **)(param_1 + 10),(long)plVar12,lVar15,(long)param_4,param_r8,param_r9)
    ;
    lVar15 = 1;
    if (iVar9 != Row_uidDigits) {
      uVar7 = 1;
    }
  }
  else {
    if (cVar16 == '\0') goto LAB_00134b5b;
    (*(double *)(__fp - 0x70)) = (*(double *)(__fp - 0x90));
  }
  Table_rebuildPanel(plVar2[0x15],(long)plVar12,lVar15,(long)param_4,param_r8,param_r9);
  if (*(char *)(*(long *)(param_1 + 0xe) + 0x1a) == '\0') {
    Header_draw(*(long **)(param_1 + 10),(long)plVar12,extraout_RDX_01,(long)param_4,param_r8,
                param_r9);
  }
  (*(double *)(__fp - 0x90)) = (*(double *)(__fp - 0x70));
  bVar5 = false;
LAB_00134b63:
  lVar15 = **(long **)(param_1 + 0xc);
  cVar16 = *(char *)(lVar15 + 0x6e);
  plVar12 = param_4;
  iVar9 = _COLS;
joined_r0x00134b6f:
  param_4 = plVar12;
  _COLS = iVar9;
  if (cVar16 != '\0') {
    puVar11 = *(undefined8 **)(lVar15 + 0x30);
    iVar6 = *(int *)(lVar15 + 0x3c);
    (*(int *)(__fp - 0x58)) = 2;
    (*(int *)(__fp - 0x5c)) = *(int *)(*(long *)**(undefined8 **)(param_1 + 4) + 0xc) + -1;
    param_4 = *(long **)(param_1 + 6);
    if (param_4 == (long *)0x0) {
      lVar15 = 0;
      puVar3 = (undefined8 *)*puVar11;
      param_4 = plVar12;
      while (puVar3 != (undefined8 *)0x0) {
        bVar17 = iVar6 == (int)lVar15;
        param_4 = (long *)*puVar3;
        param_r8 = (long)bVar17;
        uVar8 = FUN_0012d3d0(&(*(int *)(__fp - 0x5c)),&(*(int *)(__fp - 0x58)),iVar9,(char *)param_4,bVar17);
        if ((char)uVar8 == '\0') break;
        lVar15 = lVar15 + 1;
        puVar3 = (undefined8 *)puVar11[lVar15];
      }
      wattrset(_stdscr,*(int *)CRT_colors);
    }
    else {
      param_r8 = 1;
      FUN_0012d3d0(&(*(int *)(__fp - 0x5c)),&(*(int *)(__fp - 0x58)),iVar9,(char *)param_4,'\x01');
    }
  }
  iVar9 = param_1[8];
  if (0 < iVar9) {
    lVar15 = 0;
    do {
      param_r8 = 1;
      plVar12 = *(long **)(**(long **)(param_1 + 4) + lVar15 * 8);
      puVar11 = *(undefined8 **)(param_1 + 0xe);
      if ((*(int *)(*(long *)*puVar11 + 0x70) != 2) &&
         (param_r8 = 0, *(int *)(*(long *)*puVar11 + 0x70) == 1)) {
        param_r8 = (long)*(byte *)((long)puVar11 + 0x19);
      }
      param_4 = (long *)0x1;
      if (plVar12 == (long *)puVar11[1]) {
        param_4 = (long *)(ulong)(*(byte *)((long)puVar11 + 0x19) ^ 1);
      }
      Panel_draw(plVar12,(char)uVar7,(*(uint *)(__fp - 0x74)) == (uint)lVar15,(char)param_4,(char)param_r8,param_r9)
      ;
      iVar6 = wmove(_stdscr,*(int *)((long)plVar12 + 0xc),(int)plVar12[2] + (int)plVar12[1]);
      if (iVar6 != -1) {
        param_4 = *(long **)(param_1 + 0xe);
        iVar6 = *(int *)((long)plVar12 + 0x14);
        if (*(int *)(*(long *)*param_4 + 0x70) == 2) {
          iVar6 = iVar6 + 1;
        }
        else if (*(int *)(*(long *)*param_4 + 0x70) == 1) {
          iVar6 = iVar6 + (uint)*(byte *)((long)param_4 + 0x19);
        }
        wvline(_stdscr,0x20,iVar6);
      }
      lVar15 = lVar15 + 1;
    } while (lVar15 != iVar9);
  }
  lVar15 = *(long *)(*(long *)(param_1 + 0xc) + 0x28);
  if ((lVar15 != -1) &&
     (lVar15 = lVar15 + -1, *(long *)(*(long *)(param_1 + 0xc) + 0x28) = lVar15, lVar15 == 0)) {
LAB_00134eb5:
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = (*(long * *)(__fp - 0x88));
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = (*(uint *)(__fp - 0x80));
    }
    if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
LAB_00134c80:
  uVar7 = Panel_getCh((long)(*(long * *)(__fp - 0x88)));
  a1 = (ulong)uVar7;
  uVar10 = extraout_RDX;
  if (uVar7 == 0x199) {
    if (*(char *)(lVar1 + 0x6f) == '\0') goto LAB_00134cd8;
    iVar9 = getmouse(&(*(int *)(__fp - 0x58)));
    if (iVar9 == 0) {
      if (((*(uint *)(__fp - 0x48)) & 1) == 0) {
        uVar10 = extraout_RDX_00;
        if (((*(uint *)(__fp - 0x48)) & 0x10000) == 0) {
          a1 = 0x127;
          if (((*(uint *)(__fp - 0x48)) & 0x200000) == 0) goto LAB_00134e75;
        }
        else {
          a1 = 0x126;
        }
        goto LAB_00134cd8;
      }
      if ((*(uint *)(__fp - 0x50)) == _LINES - 1U) {
        uVar7 = FunctionBar_synthesizeEvent((int *)(*(long * *)(__fp - 0x88))[10],(*(uint *)(__fp - 0x54)));
        a1 = (ulong)uVar7;
        uVar10 = extraout_RDX_03;
        goto LAB_00134c97;
      }
      if (0 < param_1[8]) {
        param_4 = (long *)(ulong)(*(uint *)(__fp - 0x54));
        param_r8 = **(ulong **)(param_1 + 4);
        lVar15 = 0;
        do {
          plVar12 = *(long **)(param_r8 + lVar15 * 8);
          uVar7 = *(uint *)(plVar12 + 1);
          uVar10 = (ulong)uVar7;
          if (((int)uVar7 <= (int)(*(uint *)(__fp - 0x54))) &&
             (uVar14 = (int)plVar12[2] + uVar7, param_r9 = (long)uVar14,
             (int)(*(uint *)(__fp - 0x54)) <= (int)uVar14)) {
            uVar14 = *(uint *)((long)plVar12 + 0xc);
            if ((*(uint *)(__fp - 0x50)) == uVar14) {
              param_4 = (long *)(ulong)((*(uint *)(__fp - 0x54)) - uVar7);
              a1 = (ulong)(((*(uint *)(__fp - 0x54)) - uVar7) - 10000);
              goto LAB_00134c97;
            }
            if ((*(char *)(lVar1 + 0x6e) != '\0') &&
               (uVar10 = (ulong)(uVar14 - 1), (*(uint *)(__fp - 0x50)) == uVar14 - 1)) {
              a1 = (ulong)((*(uint *)(__fp - 0x54)) - 20000);
              goto LAB_00134c97;
            }
            if (((int)uVar14 < (int)(*(uint *)(__fp - 0x50))) &&
               (uVar7 = *(int *)((long)plVar12 + 0x14) + uVar14, uVar10 = (ulong)uVar7,
               (int)(*(uint *)(__fp - 0x50)) <= (int)uVar7)) goto LAB_00135370;
          }
          lVar15 = lVar15 + 1;
          if (lVar15 == param_1[8]) break;
        } while( true );
      }
    }
LAB_00134e75:
    (*(uint *)(__fp - 0x78)) = (*(uint *)(__fp - 0x78)) - (0 < (int)(*(uint *)(__fp - 0x78)));
    if ((*(uint *)(__fp - 0x80)) != 0xffffffff) {
      (*(int *)(__fp - 0x94)) = 0;
      cVar16 = '\0';
      uVar7 = 0;
      (*(uint *)(__fp - 0x80)) = 0xffffffff;
      goto LAB_00134ac3;
    }
    if (bVar4) {
      (*(int *)(__fp - 0x94)) = 0;
      cVar16 = '\0';
      uVar7 = 0;
    }
    else {
      (*(int *)(__fp - 0x94)) = (*(int *)(__fp - 0x94)) + 1;
      if ((*(int *)(__fp - 0x94)) == 100) goto LAB_00134eb5;
      cVar16 = '\0';
      uVar7 = 0;
    }
    goto LAB_00134ac3;
  }
LAB_00134c97:
  iVar9 = (int)a1;
  if (iVar9 == -1) goto LAB_00134e75;
  if (iVar9 == 0x138) {
    a1 = 0x103;
  }
  else if (iVar9 < 0x139) {
    if (iVar9 == 0x135) {
      a1 = 0x104;
    }
    else if (iVar9 == 0x137) {
      a1 = 0x102;
    }
  }
  else if (iVar9 == 0x139) {
    a1 = 0x105;
  }
  goto LAB_00134cd8;
LAB_00135370:
  if ((plVar12 == (*(long * *)(__fp - 0x88))) || ((char)param_1[0x10] != '\0')) {
    param_4 = (long *)plVar12[4];
    uVar10 = 0;
    iVar9 = (int)param_4[3];
    if (0 < iVar9) {
      uVar10 = *(ulong *)(*param_4 + (long)(int)plVar12[5] * 8);
    }
    iVar6 = ((*(uint *)(__fp - 0x50)) - uVar14) + (int)plVar12[8] + -1;
    if (iVar9 <= iVar6) {
      iVar6 = iVar9 + -1;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    *(int *)(plVar12 + 5) = iVar6;
    if (*(code **)(*plVar12 + 0x20) != (code *)0x0) {
      (**(code **)(*plVar12 + 0x20))
                ((long)plVar12,0xffffffff,uVar10,(long)param_4,param_r8,param_r9);
      param_4 = (long *)plVar12[4];
      iVar9 = (int)param_4[3];
    }
    uVar13 = 0;
    if (0 < iVar9) {
      uVar13 = *(ulong *)(*param_4 + (long)(int)plVar12[5] * 8);
    }
    (*(uint *)(__fp - 0x74)) = (uint)lVar15;
    (*(long * *)(__fp - 0x88)) = plVar12;
    if (uVar13 == uVar10) {
      a1 = 0x128;
    }
  }
LAB_00134cd8:
  if (*(code **)(*(*(long * *)(__fp - 0x88)) + 0x20) == (code *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar10 = (**(code **)(*(*(long * *)(__fp - 0x88)) + 0x20))
                       ((long)(*(long * *)(__fp - 0x88)),a1,uVar10,(long)param_4,param_r8,param_r9);
    if ((uVar10 & 0x80) != 0) {
      a1 = uVar10 >> 0x10 & 0xffff;
    }
    (*(uint *)(__fp - 0x80)) = (uint)a1;
    uVar14 = 0;
    if ((uVar10 & 8) == 0) {
      uVar14 = (*(uint *)(__fp - 0x78));
    }
    if ((uVar10 & 0x40) == 0) {
      uVar7 = (uint)(uVar10 >> 4) & 1;
    }
    else {
      uVar7 = 1;
      ScreenManager_resize(param_1);
    }
    bVar17 = (uVar10 & 0x20) != 0;
    if (bVar17) {
      bVar5 = true;
    }
    (*(uint *)(__fp - 0x78)) = 0;
    if (!bVar17) {
      (*(uint *)(__fp - 0x78)) = uVar14;
    }
    if ((uVar10 & 1) != 0) goto LAB_00134d4d;
    if ((uVar10 & 4) != 0) goto switchD_00134fea_caseD_1b;
  }
  (*(uint *)(__fp - 0x80)) = (uint)a1;
  if ((*(uint *)(__fp - 0x80)) == 0x71) {
switchD_00134fea_caseD_1b:
    goto LAB_00134eb5;
  }
  if (0x71 < (int)(*(uint *)(__fp - 0x80))) {
    if ((*(uint *)(__fp - 0x80)) == 0x112) goto switchD_00134fea_caseD_1b;
    if (0x112 < (int)(*(uint *)(__fp - 0x80))) {
      if ((*(uint *)(__fp - 0x80)) == 0x19a) {
        cVar16 = '\x01';
        ScreenManager_resize(param_1);
        (*(uint *)(__fp - 0x80)) = 0x19a;
        goto LAB_00134ac3;
      }
      goto switchD_00134fea_caseD_3;
    }
    if ((*(uint *)(__fp - 0x80)) != 0x104) {
      if ((*(uint *)(__fp - 0x80)) != 0x105) goto switchD_00134fea_caseD_3;
      goto switchD_00134fea_caseD_6;
    }
switchD_00134fea_caseD_2:
    if (param_1[8] < 2) {
switchD_00134fea_caseD_3:
      cVar16 = '\x01';
      Panel_onKey((long)(*(long * *)(__fp - 0x88)),(*(uint *)(__fp - 0x80)));
      (*(uint *)(__fp - 0x78)) = 5;
      goto LAB_00134ac3;
    }
    cVar16 = (char)param_1[0x10];
    if (cVar16 != '\0') {
      puVar11 = (undefined8 *)(**(long **)(param_1 + 4) + (long)(int)(*(uint *)(__fp - 0x74)) * 8);
      if (0 < (int)(*(uint *)(__fp - 0x74))) goto LAB_0013530c;
      (*(long * *)(__fp - 0x88)) = (long *)*puVar11;
      goto LAB_00134ac3;
    }
LAB_00134d4d:
    cVar16 = '\x01';
    if (*(long *)(param_1 + 10) != 0) goto LAB_00134acf;
LAB_00134d68:
    if (cVar16 != '\0') goto code_r0x00134d71;
LAB_00134b5b:
    if ((char)uVar7 != '\0') goto LAB_00134b63;
    goto LAB_00134c80;
  }
  switch(a1) {
  case 2:
    goto switchD_00134fea_caseD_2;
  default:
    goto switchD_00134fea_caseD_3;
  case 6:
  case 9:
switchD_00134fea_caseD_6:
    if (param_1[8] < 2) goto switchD_00134fea_caseD_3;
    cVar16 = (char)param_1[0x10];
    if (cVar16 != '\0') {
      iVar9 = param_1[8] + -1;
      param_4 = (long *)**(undefined8 **)(param_1 + 4);
      plVar12 = param_4 + (int)(*(uint *)(__fp - 0x74));
      if ((int)(*(uint *)(__fp - 0x74)) < iVar9) {
        param_4 = (long *)(ulong)(*(uint *)(__fp - 0x74));
        break;
      }
      (*(long * *)(__fp - 0x88)) = (long *)param_4[(int)(*(uint *)(__fp - 0x74))];
      goto LAB_00134ac3;
    }
    goto LAB_00134d4d;
  case 0x1b:
    goto switchD_00134fea_caseD_1b;
  case 0x23:
    cVar16 = '\x01';
    uVar7 = 1;
    *(byte *)(*(long *)(param_1 + 0xe) + 0x1a) = *(byte *)(*(long *)(param_1 + 0xe) + 0x1a) ^ 1;
    ScreenManager_resize(param_1);
    goto LAB_00134ac3;
  }
  while ((int)(*(uint *)(__fp - 0x74)) < iVar9) {
    (*(long * *)(__fp - 0x88)) = (long *)plVar12[1];
    (*(uint *)(__fp - 0x74)) = (int)param_4 + 1;
    param_4 = (long *)(ulong)(*(uint *)(__fp - 0x74));
    plVar12 = plVar12 + 1;
    if (*(int *)((*(long * *)(__fp - 0x88))[4] + 0x18) != 0) break;
  }
  goto LAB_00134ac3;
  while (0 < (int)(*(uint *)(__fp - 0x74))) {
LAB_0013530c:
    param_4 = (long *)puVar11[-1];
    (*(uint *)(__fp - 0x74)) = (*(uint *)(__fp - 0x74)) - 1;
    puVar11 = puVar11 + -1;
    param_r8 = (long)*(uint *)(param_4[4] + 0x18);
    (*(long * *)(__fp - 0x88)) = param_4;
    if (*(uint *)(param_4[4] + 0x18) != 0) break;
  }
  goto LAB_00134ac3;
code_r0x00134d71:
  lVar15 = **(long **)(param_1 + 0xc);
  cVar16 = *(char *)(lVar15 + 0x6e);
  plVar12 = param_4;
  iVar9 = _COLS;
  goto joined_r0x00134b6f;
}

