#include "htop.h"

/* Panel_getSelectedIndex @ 0x120830 */

undefined4 Panel_getSelectedIndex(long param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}


/* Panel_get @ 0x120840 */

undefined8 Panel_get(long param_1,int param_2)

{
  return *(undefined8 *)(**(long **)(param_1 + 0x20) + (long)param_2 * 8);
}


/* Panel_setHeader @ 0x120880 */

void Panel_setHeader(long param_1,char *param_2)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  uint uVar1;
  wint_t __wc;
  long lVar2;
  undefined1 *puVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  ulong uVar8;
  ulong uVar9;
  undefined1 (*pauVar10) [16];
  undefined1 *puVar11;
  wint_t *pwVar13;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar12;

  puVar11 = (*(undefined1 (*)[8])(__fp - 0x58));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *(uint *)(CRT_colors + 0x1c);
  (*(long *)(__fp - 0x50)) = param_1;
  sVar7 = strlen(param_2);
  uVar9 = (ulong)((int)sVar7 + 1);
  uVar8 = uVar9 * 4 + 0xf;
  puVar12 = (*(undefined1 (*)[8])(__fp - 0x58));
  puVar3 = (*(undefined1 (*)[8])(__fp - 0x58));
  while (puVar12 != (*(undefined1 (*)[8])(__fp - 0x58)) + -(uVar8 & 0xfffffffffffff000)) {
    puVar11 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar12 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar8 = (ulong)((uint)uVar8 & 0xff0);
  lVar2 = -uVar8;
  pwVar13 = (wint_t *)(puVar11 + lVar2);
  if (uVar8 != 0) {
    *(undefined8 *)(puVar11 + -8) = *(undefined8 *)(puVar11 + -8);
  }
  uVar8 = __mbstowcs_chk((int *)(puVar11 + lVar2),param_2,(long)(int)sVar7,
                         uVar9 & 0x3fffffffffffffff);
  lVar4 = (*(long *)(__fp - 0x50));
  iVar5 = (int)uVar8;
  if (0 < iVar5) {
    FUN_00130130((int *)((*(long *)(__fp - 0x50)) + 0x60),iVar5);
    pauVar10 = *(undefined1 (**) [16])(lVar4 + 0x68);
    do {
      __wc = *pwVar13;
      iVar6 = iswprint(__wc);
      *(undefined16 *)(*pauVar10) = (undefined16)0x0;
      if (iVar6 == 0) {
        __wc = 0xfffd;
      }
      pwVar13 = pwVar13 + 1;
      *(uint *)*pauVar10 = uVar1 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar10 + 0xc)) = (undefined16)0x0;
      *(wint_t *)(*pauVar10 + 4) = __wc;
      pauVar10 = (undefined1 (*) [16])(pauVar10[1] + 0xc);
    } while (pwVar13 != (wint_t *)(puVar11 + (ulong)(iVar5 - 1) * 4 + lVar2 + 4));
  }
  *(undefined1 *)((*(long *)(__fp - 0x50)) + 0x48) = 1;
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_001209c0 @ 0x1209c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001209c0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  undefined1 __frame[0x2758] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2718;
  code *pcVar1;
  int iVar2;
  int iVar3;
  size_t a3;
  undefined4 in_register_0000000c;
  undefined4 in_register_00000014;
  long a2;
  undefined4 in_register_00000034;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*param_1 + 0x48) == (code *)0x0) {
    (*(char * *)(__fp - 0x26c8)) = (char *)param_1[3];
  }
  else {
    (*(char * *)(__fp - 0x26c8)) = (char *)(**(code **)(*param_1 + 0x48))
                                   ((long)param_1,CONCAT44(in_register_00000034,param_2),
                                    CONCAT44(in_register_00000014,param_3),
                                    CONCAT44(in_register_0000000c,param_4),param_r8,param_r9);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0x38));
  iVar2 = wmove(_stdscr,param_3,param_2);
  if (iVar2 != -1) {
    waddnstr(_stdscr,(*(char * *)(__fp - 0x26c8)),param_4);
  }
  wattrset(_stdscr,*(int *)CRT_colors);
  a3 = strlen((*(char * *)(__fp - 0x26c8)));
  iVar2 = param_4 - (int)a3;
  if (0 < iVar2) {
    (*(undefined1 * *)(__fp - 0x26b0)) = (*(undefined1 (*)[12])(__fp - 0x26a8));
    (*(int (*)[2])(__fp - 0x26b8))[0] = 0;
    pcVar1 = *(code **)(*param_1 + 8);
    ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x26a8)), SUB1612((undefined16)0x0,0));
    (*(undefined4 *)(__fp - 0x44)) = 0;
    (*(undefined4 *)(__fp - 0x269c)) = 0;
    ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x2698)), SUB1612((undefined16)0x0,4));
    if (pcVar1 == (code *)0x0) {
      RichString_writeWide
                ((*(int (*)[2])(__fp - 0x26b8)),*(uint *)(CRT_colors + (long)**(int **)(*param_1 + 0x68) * 4),
                 (char *)(param_1 + 0xc));
    }
    else {
      (*pcVar1)((long)param_1,(long)(*(int (*)[2])(__fp - 0x26b8)),a2,a3,param_r8,param_r9);
    }
    iVar3 = wmove(_stdscr,param_3,param_2 + (int)a3);
    if (iVar3 != -1) {
      wadd_wchnstr(_stdscr,(*(undefined1 * *)(__fp - 0x26b0)),iVar2);
    }
    if (0x15e < (*(int (*)[2])(__fp - 0x26b8))[0]) {
      free((*(undefined1 * *)(__fp - 0x26b0)));
    }
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00120ba0 @ 0x120ba0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00120ba0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  undefined1 __frame[0x2788] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2748;
  int iVar1;
  int iVar2;
  int iVar3;
  char *p1;
  size_t sVar4;
  long lVar5;
  undefined4 in_register_0000000c;
  long lVar6;
  long a2;
  ulong a1;
  uint uVar7;
  int p1_00;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar5 = CONCAT44(in_register_0000000c,param_4);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  PTR_0015d658 = &PTR_DAT_001577a0;
  ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x26a8)), SUB1612((undefined16)0x0,0));
  if (CRT_utf8 != '\0') {
    PTR_0015d658 = &PTR_DAT_001578a0;
  }
  lVar6 = *param_1;
  (*(int (*)[2])(__fp - 0x26b8))[0] = 0;
  (*(undefined4 *)(__fp - 0x44)) = 0;
  (*(undefined1 * *)(__fp - 0x26b0)) = (*(undefined1 (*)[12])(__fp - 0x26a8));
  (*(undefined4 *)(__fp - 0x269c)) = 0;
  ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x2698)), SUB1612((undefined16)0x0,4));
  if (*(code **)(lVar6 + 8) == (code *)0x0) {
    lVar5 = (long)**(int **)(lVar6 + 0x68);
    RichString_writeWide((*(int (*)[2])(__fp - 0x26b8)),*(uint *)(CRT_colors + lVar5 * 4),(char *)(param_1 + 0xc));
  }
  else {
    (**(code **)(lVar6 + 8))((long)param_1,(long)(*(int (*)[2])(__fp - 0x26b8)),lVar6,lVar5,param_r8,param_r9);
  }
  (*(int *)(__fp - 0x26f4)) = param_3 + 2;
  if (CRT_utf8 != '\0') {
    (*(int *)(__fp - 0x26f4)) = param_3 + 1;
  }
  a1 = (ulong)*(uint *)(CRT_colors + 0x58);
  wattrset(_stdscr,*(uint *)(CRT_colors + 0x58));
  if (*(code **)(*param_1 + 0x48) == (code *)0x0) {
    p1 = (char *)param_1[3];
  }
  else {
    p1 = (char *)(**(code **)(*param_1 + 0x48))((long)param_1,a1,a2,lVar5,param_r8,param_r9);
  }
  iVar1 = wmove(_stdscr,(*(int *)(__fp - 0x26f4)),param_2);
  if (iVar1 != -1) {
    waddnstr(_stdscr,p1,-1);
  }
  sVar4 = strlen(p1);
  iVar1 = param_2 + (int)sVar4;
  lVar5 = (long)(*(int (*)[2])(__fp - 0x26b8))[0];
  if (0 < (*(int (*)[2])(__fp - 0x26b8))[0]) {
    lVar6 = 0;
    do {
      iVar3 = *(int *)((*(undefined1 * *)(__fp - 0x26b0)) + lVar6 + 4);
      uVar7 = iVar3 - 0x30;
      if (uVar7 < 10) {
        if (param_4 <= (iVar1 - param_2) + 3) break;
        p1_00 = param_3;
        do {
          iVar2 = wmove(_stdscr,p1_00,iVar1);
          if (iVar2 != -1) {
            waddnstr(_stdscr,PTR_0015d658[(int)uVar7],-1);
          }
          uVar7 = uVar7 + 10;
          p1_00 = p1_00 + 1;
        } while (uVar7 != iVar3 - 0x12U);
        iVar1 = iVar1 + 4;
      }
      else {
        if (param_4 <= iVar1 - param_2) break;
        (*(undefined4 *)(__fp - 0x26d8)) = 0;
        (*(undefined4 *)(__fp - 0x26d0)) = 0;
        (*(undefined4 *)(__fp - 0x26cc)) = 0;
        ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x26c8)), SUB1612((undefined16)0x0,4));
        (*(int *)(__fp - 0x26d4)) = iVar3;
        iVar3 = wmove(_stdscr,(*(int *)(__fp - 0x26f4)),iVar1);
        if (iVar3 != -1) {
          wadd_wch(_stdscr,&(*(undefined4 *)(__fp - 0x26d8)));
        }
        iVar1 = iVar1 + 1;
      }
      lVar6 = lVar6 + 0x1c;
    } while (lVar6 != lVar5 * 0x1c);
  }
  wattrset(_stdscr,*(int *)CRT_colors);
  if (0x15e < (*(int (*)[2])(__fp - 0x26b8))[0]) {
    free((*(undefined1 * *)(__fp - 0x26b0)));
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Panel_setSelected @ 0x120f60 */

void Panel_setSelected(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                      long param_r9)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;

  uVar1 = *(int *)(param_1[4] + 0x18) - 1;
  if (*(int *)(param_1[4] + 0x18) <= param_2) {
    param_2 = uVar1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x20);
  *(int *)(param_1 + 5) = param_2;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00120f8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)param_1,0xffffffff,(ulong)uVar1,param_rcx,param_r8,param_r9);
    return;
  }
  return;
}


/* Panel_getSelected @ 0x120fa0 */

undefined8 Panel_getSelected(long param_1)

{
  undefined8 uVar1;

  uVar1 = 0;
  if (0 < (int)(*(long **)(param_1 + 0x20))[3]) {
    uVar1 = *(undefined8 *)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8);
  }
  return uVar1;
}


/* Panel_size @ 0x120fc0 */

undefined4 Panel_size(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0x20) + 0x18);
}


/* Panel_resize @ 0x120fd0 */

void Panel_resize(long param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


/* Panel_setSelectionColor @ 0x121310 */

void Panel_setSelectionColor(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x26d8) = param_2;
  return;
}


/* Panel_moveSelectedUp @ 0x1215d0 */

void Panel_moveSelectedUp(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;

  iVar3 = *(int *)(param_1 + 0x28);
  if (iVar3 != 0) {
    puVar1 = (undefined8 *)(**(long **)(param_1 + 0x20) + -8 + (long)iVar3 * 8);
    uVar4 = *puVar1;
    puVar2 = (undefined8 *)(**(long **)(param_1 + 0x20) + -8 + (long)iVar3 * 8);
    *puVar2 = puVar1[1];
    puVar2[1] = uVar4;
    if (0 < iVar3) {
      *(int *)(param_1 + 0x28) = iVar3 + -1;
    }
  }
  return;
}


/* Panel_setCursorToSelection @ 0x122090 */

void Panel_setCursorToSelection(long param_1)

{
  *(int *)(param_1 + 0x1c) =
       ((*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0xc)) - *(int *)(param_1 + 0x40)) + 1;
  *(int *)(param_1 + 0x18) =
       (*(int *)(param_1 + 0x30) + *(int *)(param_1 + 8)) - *(int *)(param_1 + 0x44);
  return;
}


/* Panel_move @ 0x1220b0 */

void Panel_move(long param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


/* Panel_remove @ 0x1220c0 */

long * Panel_remove(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                   long param_r9)

{
  char cVar1;
  long *plVar2;
  long *a0;
  long a3;
  int iVar3;
  undefined4 in_register_00000034;
  void *__src;
  long *plVar4;

  __src = (void *)CONCAT44(in_register_00000034,param_2);
  plVar2 = *(long **)(param_1 + 0x20);
  *(undefined1 *)(param_1 + 0x48) = 1;
  a3 = *plVar2;
  iVar3 = (int)plVar2[3] + -1;
  plVar4 = (long *)(a3 + (long)param_2 * 8);
  a0 = (long *)*plVar4;
  *(int *)(plVar2 + 3) = iVar3;
  if (param_2 < iVar3) {
    __src = (void *)(a3 + 8 + (long)param_2 * 8);
    memmove(plVar4,__src,(long)(iVar3 - param_2) << 3);
    a3 = *plVar2;
    iVar3 = (int)plVar2[3];
  }
  cVar1 = *(char *)((long)plVar2 + 0x24);
  *(undefined8 *)(a3 + (long)iVar3 * 8) = 0;
  plVar4 = a0;
  if (cVar1 != '\0') {
    plVar4 = (long *)0x0;
    (**(code **)(*a0 + 0x10))((long)a0,(long)__src,(long)iVar3,a3,param_r8,param_r9);
  }
  iVar3 = *(int *)(param_1 + 0x28);
  if ((0 < iVar3) && (*(int *)(*(long *)(param_1 + 0x20) + 0x18) <= iVar3)) {
    *(int *)(param_1 + 0x28) = iVar3 + -1;
  }
  return plVar4;
}


/* Panel_moveSelectedDown @ 0x122170 */

void Panel_moveSelectedDown(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;

  iVar2 = *(int *)(param_1 + 0x28);
  iVar3 = (int)(*(long **)(param_1 + 0x20))[3];
  if (iVar2 != iVar3 + -1) {
    puVar1 = (undefined8 *)(**(long **)(param_1 + 0x20) + (long)iVar2 * 8);
    uVar4 = *puVar1;
    *puVar1 = puVar1[1];
    puVar1[1] = uVar4;
  }
  if (iVar2 + 1 < iVar3) {
    *(int *)(param_1 + 0x28) = iVar2 + 1;
  }
  return;
}


/* Panel_onKey @ 0x1221b0 */

undefined8 Panel_onKey(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;

  iVar5 = CRT_scrollWheelVAmount;
  iVar1 = *(int *)(*(long *)(param_1 + 0x20) + 0x18);
  if (0x127 < param_2) {
    if (param_2 == 0x153) {
      iVar3 = *(int *)(param_1 + 0x14);
      uVar6 = (uint)(0 < *(int *)(param_1 + 0x60));
      iVar5 = uVar6 - iVar3;
    }
    else {
      if (param_2 == 0x168) {
        *(int *)(param_1 + 0x28) = iVar1 + -1;
        if (0 < iVar1) {
          return 1;
        }
        goto LAB_001222a1;
      }
      if (param_2 != 0x152) {
        return 0;
      }
      iVar3 = *(int *)(param_1 + 0x14);
      uVar6 = (uint)(0 < *(int *)(param_1 + 0x60));
      iVar5 = iVar3 - uVar6;
    }
    iVar2 = *(int *)(param_1 + 0x28) + iVar5;
    *(int *)(param_1 + 0x28) = iVar2;
LAB_0012226d:
    iVar3 = (iVar1 - iVar3) - uVar6;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar5 = iVar5 + *(int *)(param_1 + 0x40);
LAB_0012227d:
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    *(undefined1 *)(param_1 + 0x48) = 1;
    if (iVar5 < iVar3) {
      iVar3 = iVar5;
    }
    bVar4 = (byte)((uint)iVar2 >> 0x1f);
    *(int *)(param_1 + 0x40) = iVar3;
    goto LAB_00122294;
  }
  if (param_2 < 0x102) {
    if (param_2 < 0x25) {
      switch(param_2) {
      case 1:
        goto switchD_0012220e_caseD_1;
      case 2:
        goto switchD_001221e7_caseD_104;
      default:
        goto switchD_001221e7_caseD_107;
      case 5:
      case 0x24:
        iVar5 = *(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x10);
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        *(int *)(param_1 + 0x44) = iVar5;
        goto LAB_001222e1;
      case 6:
        goto switchD_001221e7_caseD_105;
      case 0xe:
        goto switchD_001221e7_caseD_102;
      case 0x10:
        goto switchD_001221e7_caseD_103;
      }
    }
    if (param_2 != 0x5e) {
switchD_001221e7_caseD_107:
      return 0;
    }
switchD_0012220e_caseD_1:
    *(undefined4 *)(param_1 + 0x44) = 0;
LAB_001222e1:
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined1 *)(param_1 + 0x48) = 1;
    bVar4 = (byte)((uint)iVar2 >> 0x1f);
  }
  else {
    switch(param_2) {
    case 0x102:
switchD_001221e7_caseD_102:
      iVar2 = *(int *)(param_1 + 0x28) + 1;
      *(int *)(param_1 + 0x28) = iVar2;
      bVar4 = (byte)((uint)iVar2 >> 0x1f);
      break;
    case 0x103:
switchD_001221e7_caseD_103:
      iVar2 = *(int *)(param_1 + 0x28) + -1;
      *(int *)(param_1 + 0x28) = iVar2;
      bVar4 = (byte)((uint)iVar2 >> 0x1f);
      break;
    case 0x104:
switchD_001221e7_caseD_104:
      iVar2 = *(int *)(param_1 + 0x28);
      bVar4 = (byte)((uint)iVar2 >> 0x1f);
      if (0 < *(int *)(param_1 + 0x44)) {
        *(undefined1 *)(param_1 + 0x48) = 1;
        iVar5 = CRT_scrollHAmount;
        if (CRT_scrollHAmount < 0) {
          iVar5 = 0;
        }
        *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) - iVar5;
      }
      break;
    case 0x105:
switchD_001221e7_caseD_105:
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + CRT_scrollHAmount;
      goto LAB_001222e1;
    case 0x106:
      *(undefined4 *)(param_1 + 0x28) = 0;
      bVar4 = 0;
      iVar2 = 0;
      break;
    default:
      goto switchD_001221e7_caseD_107;
    case 0x126:
      iVar2 = *(int *)(param_1 + 0x28) - CRT_scrollWheelVAmount;
      *(int *)(param_1 + 0x28) = iVar2;
      iVar3 = (iVar1 - *(int *)(param_1 + 0x14)) - (uint)(0 < *(int *)(param_1 + 0x60));
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      iVar5 = *(int *)(param_1 + 0x40) - iVar5;
      goto LAB_0012227d;
    case 0x127:
      iVar3 = *(int *)(param_1 + 0x14);
      iVar2 = *(int *)(param_1 + 0x28) + CRT_scrollWheelVAmount;
      *(int *)(param_1 + 0x28) = iVar2;
      uVar6 = (uint)(0 < *(int *)(param_1 + 0x60));
      goto LAB_0012226d;
    }
  }
LAB_00122294:
  if ((iVar1 != 0) && (bVar4 == 0)) {
    if (iVar2 < iVar1) {
      return 1;
    }
    *(undefined1 *)(param_1 + 0x48) = 1;
    *(int *)(param_1 + 0x28) = iVar1 + -1;
    return 1;
  }
LAB_001222a1:
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return 1;
}


/* Panel_getCh @ 0x122440 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Panel_getCh(long param_1)

{
  int iVar1;

  if (*(char *)(param_1 + 0x49) == '\0') {
    curs_set(0);
  }
  else {
    wmove(_stdscr,*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x18));
    curs_set(1);
  }
  set_escdelay(0x19);
  iVar1 = wgetch(_stdscr);
  return iVar1;
}


/* Panel_new @ 0x123f10 */

undefined8 *
Panel_new(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined8 param_5,undefined1 param_6,undefined8 param_7)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *pvVar3;

  puVar1 = malloc(0x26e0);
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[3] = 0;
    *puVar1 = Panel_class;
    puVar1[7] = 0;
    puVar1[1] = CONCAT44(param_2,param_1);
    puVar1[2] = CONCAT44(param_4,param_3);
    puVar2 = malloc(0x28);
    if (puVar2 != (undefined8 *)0x0) {
      *(undefined4 *)((long)puVar2 + 0x14) = 10;
      pvVar3 = calloc(10,8);
      if (pvVar3 != (void *)0x0) {
        *puVar2 = pvVar3;
        *(undefined16 *)(*(undefined1 (*) [16])(puVar1 + 0xe)) = (undefined16)0x0;
        puVar2[3] = 0xffffffff00000000;
        *(undefined2 *)(puVar1 + 9) = 1;
        puVar1[0xd] = puVar1 + 0xe;
        *(undefined8 *)((long)puVar1 + 0x26d4) = 0x900000000;
        *(undefined4 *)(puVar2 + 2) = 10;
        puVar2[1] = param_5;
        *(undefined1 *)((long)puVar2 + 0x24) = param_6;
        *(undefined4 *)(puVar2 + 4) = 0;
        puVar1[4] = puVar2;
        puVar1[8] = 0;
        puVar1[5] = 0;
        *(undefined4 *)(puVar1 + 6) = 0;
        *(undefined1 *)((long)puVar1 + 0x4a) = 0;
        *(undefined4 *)(puVar1 + 0xc) = 0;
        *(undefined16 *)(*(undefined1 (*) [16])((long)puVar1 + 0x7c)) = (undefined16)0x0;
        puVar1[10] = param_7;
        puVar1[0xb] = param_7;
        return puVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Panel_init @ 0x124070 */

void Panel_init(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6,undefined1 param_7,undefined8 param_8)

{
  undefined8 *puVar1;
  void *pvVar2;

  *(ulong *)(param_1 + 8) = CONCAT44(param_3,param_2);
  *(ulong *)(param_1 + 0x10) = CONCAT44(param_5,param_4);
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  puVar1 = malloc(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)((long)puVar1 + 0x14) = 10;
    pvVar2 = calloc(10,8);
    if (pvVar2 != (void *)0x0) {
      *puVar1 = pvVar2;
      *(undefined16 *)(*(undefined1 (*) [16])(param_1 + 0x70)) = (undefined16)0x0;
      puVar1[3] = 0xffffffff00000000;
      *(undefined2 *)(param_1 + 0x48) = 1;
      *(long *)(param_1 + 0x68) = param_1 + 0x70;
      *(undefined4 *)(puVar1 + 2) = 10;
      puVar1[1] = param_6;
      *(undefined1 *)((long)puVar1 + 0x24) = param_7;
      *(undefined4 *)(puVar1 + 4) = 0;
      *(undefined8 **)(param_1 + 0x20) = puVar1;
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined1 *)(param_1 + 0x4a) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x26d4) = 0x900000000;
      *(undefined16 *)(*(undefined1 (*) [16])(param_1 + 0x7c)) = (undefined16)0x0;
      *(undefined8 *)(param_1 + 0x50) = param_8;
      *(undefined8 *)(param_1 + 0x58) = param_8;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Panel_selectByTyping @ 0x1241a0 */

undefined8
Panel_selectByTyping
          (long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  char cVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  int iVar6;
  ushort **ppuVar7;
  size_t sVar8;
  long lVar9;
  char *__s;
  uint uVar10;
  char *pcVar11;
  long lVar12;

  iVar3 = *(int *)(param_1[4] + 0x18);
  if (param_2 == 0x23) {
    return 2;
  }
  __s = (char *)param_1[7];
  if (__s == (char *)0x0) {
    __s = calloc(100,1);
    if (__s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    param_1[7] = (long)__s;
  }
  if (0xfd < param_2 - 1U) {
    if (param_2 == -1) {
      return 2;
    }
    *__s = '\0';
    return 2;
  }
  ppuVar7 = __ctype_b_loc();
  if (-1 < (short)(*ppuVar7)[param_2]) {
    *__s = '\0';
    if (param_2 != 0xd) {
      return 2;
    }
    return 4;
  }
  sVar8 = strlen(__s);
  iVar6 = (int)sVar8;
  if (iVar6 == 0) {
    pcVar11 = __s;
    if (param_2 == 0x2f) {
      lVar9 = 1;
      param_2 = 1;
    }
    else {
      if (param_2 == 0x71) {
        return 4;
      }
      lVar9 = 1;
    }
  }
  else if (iVar6 == 1) {
    pcVar11 = __s + (*__s != '\x01');
    lVar9 = (ulong)(*__s != '\x01') + 1;
  }
  else {
    if (0x62 < iVar6) goto LAB_00124276;
    pcVar11 = __s + iVar6;
    lVar9 = (long)iVar6 + 1;
  }
  *pcVar11 = (char)param_2;
  __s[lVar9] = '\0';
  sVar8 = strlen(__s);
LAB_00124276:
  (*(int *)(__fp - 0x50)) = 2;
  do {
    if (0 < iVar3) {
      plVar4 = (long *)param_1[4];
      lVar12 = 0;
      lVar9 = *plVar4;
      do {
        pcVar11 = *(char **)(*(long *)(lVar9 + lVar12 * 8) + 8);
        cVar2 = *pcVar11;
        while (cVar2 == ' ') {
          pcVar11 = pcVar11 + 1;
          cVar2 = *pcVar11;
        }
        iVar6 = strncasecmp(pcVar11,__s,(long)(int)sVar8);
        if (iVar6 == 0) {
          iVar3 = (int)plVar4[3];
          uVar1 = iVar3 - 1;
          uVar10 = uVar1;
          if ((int)(uint)lVar12 < iVar3) {
            uVar10 = (uint)lVar12;
          }
          if ((int)uVar10 < 0) {
            uVar10 = 0;
          }
          pcVar5 = *(code **)(*param_1 + 0x20);
          *(uint *)(param_1 + 5) = uVar10;
          if (pcVar5 == (code *)0x0) {
            return 1;
          }
          (*pcVar5)((long)param_1,0xffffffff,(ulong)uVar1,(ulong)uVar10,param_r8,param_r9);
          return 1;
        }
        lVar12 = lVar12 + 1;
      } while (lVar12 != iVar3);
    }
    *__s = (char)param_2;
    __s[1] = '\0';
    if ((*(int *)(__fp - 0x50)) == 1) {
      return 1;
    }
    sVar8 = strlen(__s);
    (*(int *)(__fp - 0x50)) = 1;
  } while( true );
}


/* Panel_prune @ 0x1268d0 */

void Panel_prune(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                long param_r9)

{
  Vector_prune(*(long **)(param_1 + 0x20),param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


/* Panel_done @ 0x126bf0 */

void Panel_done(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  long extraout_RDX;

  free(*(void **)(param_1 + 0x38));
  Vector_delete(*(long **)(param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  FunctionBar_delete(*(int **)(param_1 + 0x58));
  if (*(int *)(param_1 + 0x60) < 0x15f) {
    return;
  }
  free(*(void **)(param_1 + 0x68));
  *(long *)(param_1 + 0x68) = param_1 + 0x70;
  return;
}


/* FUN_00126c50 @ 0x126c50 */

void FUN_00126c50(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* Panel_delete @ 0x126ee0 */

void Panel_delete(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* FUN_00126f40 @ 0x126f40 */

undefined8
FUN_00126f40(long param_1,ulong param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  long *plVar6;
  int iVar7;

  iVar7 = (int)param_2;
  if (iVar7 != 0x128) {
    if (iVar7 < 0x129) {
      if ((0x16 < iVar7 - 10U) || ((0x100002400U >> (param_2 & 0x3f) & 1) == 0)) {
        return 2;
      }
    }
    else if ((iVar7 != 0x157) && (iVar7 != 0x199)) {
      return 2;
    }
  }
  uVar1 = *(uint *)(param_1 + 0x28);
  plVar2 = (long *)**(long **)(param_1 + 0x20);
  plVar6 = plVar2;
  do {
    while( true ) {
      lVar3 = *plVar6;
      if (*(undefined1 **)(lVar3 + 0x10) != (undefined1 *)0x0) break;
      plVar6 = plVar6 + 1;
      *(undefined1 *)(lVar3 + 0x18) = 0;
      if (plVar6 == plVar2 + 0xc) goto LAB_00126fbd;
    }
    plVar6 = plVar6 + 1;
    **(undefined1 **)(lVar3 + 0x10) = 0;
  } while (plVar6 != plVar2 + 0xc);
LAB_00126fbd:
  lVar4 = plVar2[(int)uVar1];
  if (*(undefined1 **)(lVar4 + 0x10) == (undefined1 *)0x0) {
    *(undefined1 *)(lVar4 + 0x18) = 1;
  }
  else {
    **(undefined1 **)(lVar4 + 0x10) = 1;
  }
  Header_setLayout(*(long **)(*(long *)(param_1 + 0x26e0) + 0x28),uVar1,lVar4,lVar3,(ulong)uVar1,
                   param_r9);
  lVar3 = *(long *)(param_1 + 0x26e8);
  piVar5 = *(int **)(param_1 + 0x26e0);
  plVar2 = (long *)(lVar3 + 0x78);
  *plVar2 = *plVar2 + 1;
  *(undefined1 *)(lVar3 + 0x74) = 1;
  ScreenManager_resize(piVar5);
  return 1;
}


/* Panel_draw @ 0x127810 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Panel_draw(long *param_1,char param_2,char param_3,char param_4,char param_5,long param_r9)

{
  undefined1 __frame[0x4dd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x4d98;
  int iVar1;
  int p2;
  int iVar2;
  code *pcVar3;
  long *plVar4;
  long lVar5;
  void *p0;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined7 in_register_00000009;
  ulong a3;
  undefined7 in_register_00000011;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  ulong uVar13;
  uint *puVar14;
  ulong extraout_RDX_05;
  ulong extraout_RDX_06;
  int *piVar15;
  ulong extraout_RDX_07;
  ulong extraout_RDX_08;
  ulong extraout_RDX_09;
  undefined1 *puVar16;
  ulong uVar17;
  uint uVar18;
  undefined7 in_register_00000081;
  ulong a4;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar7 = (undefined1 *)(*(undefined1 (*)[6508])(__fp - 0x4030));
  puVar16 = (undefined1 *)(*(undefined1 (*)[6508])(__fp - 0x4030)) + 0x1000;
  uVar17 = CONCAT71(in_register_00000081,param_5) & 0xffffffff;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar18 = (*(int *)((long)param_1 + 0x14) + 1) - (uint)((char)uVar17 == '\0');
  iVar12 = *(int *)(param_1[4] + 0x18);
  iVar1 = *(int *)((long)param_1 + 0x44);
  (*(int *)(__fp - 0x4d4c)) = *(int *)((long)param_1 + 0xc);
  p2 = (int)param_1[1];
  if (param_3 == '\0') {
    iVar8 = *(int *)(CRT_colors + 0x20);
  }
  else {
    iVar8 = *(int *)(CRT_colors + 0x1c);
  }
  if (param_2 == '\0') {
LAB_00127c20:
    iVar11 = (int)param_1[0xc];
    if (iVar11 < 1) goto LAB_00127c2d;
LAB_001278ee:
    wattrset(_stdscr,iVar8);
    iVar8 = wmove(_stdscr,(*(int *)(__fp - 0x4d4c)),p2);
    if (iVar8 != -1) {
      lVar5 = param_1[2];
      whline(_stdscr,0x20,(int)lVar5);
    }
    if (iVar1 < iVar11) {
      iVar8 = wmove(_stdscr,(*(int *)(__fp - 0x4d4c)),p2);
      if (iVar8 != -1) {
        iVar8 = (int)param_1[2];
        if (iVar11 - iVar1 <= (int)param_1[2]) {
          iVar8 = iVar11 - iVar1;
        }
        lVar5 = param_1[0xd];
        wadd_wchnstr(_stdscr,(void *)(lVar5 + (long)iVar1 * 0x1c),iVar8);
      }
    }
    iVar8 = *(int *)CRT_colors;
    wattrset(_stdscr,iVar8);
    (*(int *)(__fp - 0x4d3c)) = (int)param_1[8];
    (*(int *)(__fp - 0x4d4c)) = (*(int *)(__fp - 0x4d4c)) + 1;
    uVar17 = (ulong)(uVar18 - 1);
    if (-1 < (*(int *)(__fp - 0x4d3c))) goto LAB_00127c3a;
LAB_0012798e:
    *(undefined4 *)(param_1 + 8) = 0;
    (*(int *)(__fp - 0x4d3c)) = 0;
    *(undefined1 *)(param_1 + 9) = 1;
  }
  else {
    pcVar3 = *(code **)(*param_1 + 0x30);
    if (pcVar3 == (code *)0x0) {
      iVar11 = (int)param_1[0xc];
      iVar9 = 0;
      if (-1 < iVar11) {
        iVar9 = iVar11;
      }
      if (0 < iVar11) {
        piVar15 = (int *)param_1[0xd];
        iVar11 = 0;
        do {
          iVar11 = iVar11 + 1;
          *piVar15 = iVar8;
          piVar15 = piVar15 + 7;
        } while (iVar11 < iVar9);
        goto LAB_00127c20;
      }
    }
    else {
      (*pcVar3)((long)param_1,uVar17,CONCAT71(in_register_00000011,param_3),
                CONCAT71(in_register_00000009,param_4),(ulong)uVar18,param_r9);
      iVar11 = (int)param_1[0xc];
      if (0 < iVar11) goto LAB_001278ee;
    }
LAB_00127c2d:
    uVar17 = (ulong)uVar18;
    (*(int *)(__fp - 0x4d3c)) = (int)param_1[8];
    if ((*(int *)(__fp - 0x4d3c)) < 0) goto LAB_0012798e;
LAB_00127c3a:
    iVar8 = iVar12 - (int)uVar17;
    if (iVar8 < (*(int *)(__fp - 0x4d3c))) {
      *(undefined1 *)(param_1 + 9) = 1;
      (*(int *)(__fp - 0x4d3c)) = 0;
      if (-1 < iVar8) {
        (*(int *)(__fp - 0x4d3c)) = iVar8;
      }
      *(int *)(param_1 + 8) = (*(int *)(__fp - 0x4d3c));
    }
  }
  iVar8 = (int)param_1[5];
  iVar11 = (int)uVar17;
  if (iVar8 < (*(int *)(__fp - 0x4d3c))) {
LAB_001279b9:
    *(int *)(param_1 + 8) = iVar8;
    iVar9 = iVar8 + iVar11;
    *(undefined1 *)(param_1 + 9) = 1;
    uVar13 = CRT_colors;
    (*(int *)(__fp - 0x4d3c)) = iVar8;
    if (param_3 == '\0') {
      a3 = (ulong)*(uint *)(CRT_colors + 0x2c);
    }
    else {
      a3 = (ulong)*(uint *)(CRT_colors + (ulong)*(uint *)(param_1 + 0x4db) * 4);
    }
  }
  else {
    iVar9 = iVar11 + (*(int *)(__fp - 0x4d3c));
    if (iVar9 <= iVar8) {
      iVar8 = (iVar8 - iVar11) + 1;
      goto LAB_001279b9;
    }
    uVar13 = (ulong)(byte)(param_2 | *(byte *)(param_1 + 9));
    if (param_3 == '\0') {
      uVar18 = *(uint *)(CRT_colors + 0x2c);
    }
    else {
      uVar18 = *(uint *)(CRT_colors + (ulong)*(uint *)(param_1 + 0x4db) * 4);
    }
    a3 = (ulong)uVar18;
    if ((byte)(param_2 | *(byte *)(param_1 + 9)) == 0) {
      iVar12 = *(int *)((long)param_1 + 0x2c);
      plVar4 = *(long **)(*(long *)param_1[4] + (long)iVar12 * 8);
      (*(int * *)(__fp - 0x26b0)) = (int *)(*(undefined1 (*)[12])(__fp - 0x26a8));
      ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x26a8)), SUB1612((undefined16)0x0,0));
      (*(undefined4 *)(__fp - 0x269c)) = 0;
      ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x2698)), SUB1612((undefined16)0x0,4));
      (*(uint (*)[2])(__fp - 0x26b8))[0] = 0;
      (*(int *)(__fp - 0x44)) = 0;
      pcVar3 = *(code **)(*plVar4 + 8);
      (*pcVar3)((long)plVar4,(long)(*(uint (*)[2])(__fp - 0x26b8)),(long)iVar12,a3,uVar17,param_r9);
      uVar6 = (*(uint (*)[2])(__fp - 0x26b8))[0];
      lVar5 = param_1[5];
      plVar4 = *(long **)(*(long *)param_1[4] + (long)(int)lVar5 * 8);
      (*(uint * *)(__fp - 0x4d30)) = (uint *)(*(undefined1 (*)[12])(__fp - 0x4d28));
      ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x4d28)), SUB1612((undefined16)0x0,0));
      (*(undefined4 *)(__fp - 0x4d1c)) = 0;
      ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x4d18)), SUB1612((undefined16)0x0,4));
      (*(int (*)[2])(__fp - 0x4d38))[0] = 0;
      (*(undefined4 *)(__fp - 0x26c4)) = 0;
      pcVar3 = *(code **)(*plVar4 + 8);
      (*pcVar3)((long)plVar4,(long)(*(int (*)[2])(__fp - 0x4d38)),(long)(int)lVar5,a3,uVar17,param_r9);
      iVar8 = (*(int (*)[2])(__fp - 0x4d38))[0];
      p0 = _stdscr;
      iVar12 = *(int *)((long)param_1 + 0x2c);
      *(int *)(param_1 + 6) = (*(int (*)[2])(__fp - 0x4d38))[0];
      iVar12 = wmove(p0,((*(int *)(__fp - 0x4d4c)) + iVar12) - (*(int *)(__fp - 0x4d3c)),p2);
      a4 = uVar17;
      if (iVar12 != -1) {
        lVar5 = param_1[2];
        whline(_stdscr,0x20,(int)lVar5);
        a4 = uVar17;
      }
      if (iVar1 < (int)uVar6) {
        iVar12 = *(int *)((long)param_1 + 0x2c);
        iVar12 = wmove(_stdscr,((*(int *)(__fp - 0x4d4c)) + iVar12) - (*(int *)(__fp - 0x4d3c)),p2);
        if (iVar12 != -1) {
          iVar11 = uVar6 - iVar1;
          iVar12 = (int)param_1[2];
          if (iVar11 <= (int)param_1[2]) {
            iVar12 = iVar11;
          }
          wadd_wchnstr(_stdscr,(*(int * *)(__fp - 0x26b0)) + (long)iVar1 * 7,iVar12);
        }
      }
      wattrset(_stdscr,uVar18);
      lVar5 = param_1[5];
      iVar12 = wmove(_stdscr,((*(int *)(__fp - 0x4d4c)) + (int)lVar5) - (*(int *)(__fp - 0x4d3c)),p2);
      if (iVar12 != -1) {
        lVar5 = param_1[2];
        whline(_stdscr,0x20,(int)lVar5);
      }
      a3 = (ulong)uVar18;
      iVar12 = 0;
      if (-1 < (*(int (*)[2])(__fp - 0x4d38))[0]) {
        iVar12 = (*(int (*)[2])(__fp - 0x4d38))[0];
      }
      if (0 < (*(int (*)[2])(__fp - 0x4d38))[0]) {
        iVar11 = 0;
        puVar14 = (*(uint * *)(__fp - 0x4d30));
        do {
          iVar11 = iVar11 + 1;
          *puVar14 = uVar18;
          puVar14 = puVar14 + 7;
        } while (iVar11 < iVar12);
      }
      if (iVar1 < iVar8) {
        lVar5 = param_1[5];
        iVar12 = wmove(_stdscr,((*(int *)(__fp - 0x4d4c)) + (int)lVar5) - (*(int *)(__fp - 0x4d3c)),p2);
        if (iVar12 != -1) {
          a3 = (ulong)iVar1;
          iVar8 = iVar8 - iVar1;
          iVar12 = (int)param_1[2];
          if (iVar8 <= (int)param_1[2]) {
            iVar12 = iVar8;
          }
          wadd_wchnstr(_stdscr,(*(uint * *)(__fp - 0x4d30)) + a3 * 7,iVar12);
        }
      }
      iVar12 = *(int *)CRT_colors;
      wattrset(_stdscr,iVar12);
      uVar13 = extraout_RDX_05;
      if (0x15e < (*(int (*)[2])(__fp - 0x4d38))[0]) {
        free((*(uint * *)(__fp - 0x4d30)));
        uVar13 = extraout_RDX_09;
      }
      if (0x15e < (int)(*(uint (*)[2])(__fp - 0x26b8))[0]) {
        free((*(int * *)(__fp - 0x26b0)));
        uVar13 = extraout_RDX_06;
      }
      goto LAB_00127e70;
    }
  }
  if (iVar9 <= iVar12) {
    iVar12 = iVar9;
  }
  if ((iVar11 < 1) || (iVar12 <= (*(int *)(__fp - 0x4d3c)))) {
    iVar8 = 0;
  }
  else {
    iVar9 = (int)a3;
    (*(ulong *)(__fp - 0x4d48)) = (long)(*(int *)(__fp - 0x4d3c)) * 8;
    iVar8 = 0;
    uVar13 = (long)iVar1;
    a4 = uVar17;
    do {
      plVar4 = *(long **)(*(long *)param_1[4] + (*(ulong *)(__fp - 0x4d48)));
      ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x26a8)), SUB1612((undefined16)0x0,0));
      (*(uint (*)[2])(__fp - 0x26b8))[0] = 0;
      (*(int *)(__fp - 0x44)) = 0;
      (*(undefined4 *)(__fp - 0x269c)) = 0;
      ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x2698)), SUB1612((undefined16)0x0,4));
      pcVar3 = *(code **)(*plVar4 + 8);
      a3 = (*(ulong *)(__fp - 0x4d48));
      (*(int * *)(__fp - 0x26b0)) = (int *)(*(undefined1 (*)[12])(__fp - 0x26a8));
      (*pcVar3)((long)plVar4,(long)(*(uint (*)[2])(__fp - 0x26b8)),uVar13,(*(ulong *)(__fp - 0x4d48)),a4,param_r9);
      uVar18 = (*(uint (*)[2])(__fp - 0x26b8))[0];
      iVar2 = (*(uint (*)[2])(__fp - 0x26b8))[0] - iVar1;
      if ((int)param_1[2] < (int)((*(uint (*)[2])(__fp - 0x26b8))[0] - iVar1)) {
        iVar2 = (int)param_1[2];
      }
      if ((param_4 != '\0') && ((int)param_1[5] == (*(int *)(__fp - 0x4d3c)))) {
        (*(int *)(__fp - 0x44)) = iVar9;
      }
      if ((*(int *)(__fp - 0x44)) != 0) {
        wattrset(_stdscr,(*(int *)(__fp - 0x44)));
        a3 = 0;
        if (-1 < (int)(*(uint (*)[2])(__fp - 0x26b8))[0]) {
          a3 = (ulong)(*(uint (*)[2])(__fp - 0x26b8))[0];
        }
        if (0 < (int)(*(uint (*)[2])(__fp - 0x26b8))[0]) {
          iVar10 = 0;
          piVar15 = (*(int * *)(__fp - 0x26b0));
          do {
            iVar10 = iVar10 + 1;
            *piVar15 = (*(int *)(__fp - 0x44));
            piVar15 = piVar15 + 7;
          } while (iVar10 < (int)a3);
        }
        *(uint *)(param_1 + 6) = uVar18;
      }
      iVar10 = wmove(_stdscr,iVar8 + (*(int *)(__fp - 0x4d4c)),p2);
      uVar13 = extraout_RDX;
      if (iVar10 != -1) {
        lVar5 = param_1[2];
        whline(_stdscr,0x20,(int)lVar5);
        uVar13 = extraout_RDX_00;
      }
      if (0 < iVar2) {
        iVar10 = wmove(_stdscr,iVar8 + (*(int *)(__fp - 0x4d4c)),p2);
        uVar13 = extraout_RDX_01;
        if (iVar10 != -1) {
          wadd_wchnstr(_stdscr,(*(int * *)(__fp - 0x26b0)) + (long)iVar1 * 7,iVar2);
          uVar13 = extraout_RDX_02;
        }
      }
      if ((*(int *)(__fp - 0x44)) != 0) {
        iVar2 = *(int *)CRT_colors;
        wattrset(_stdscr,iVar2);
        uVar13 = extraout_RDX_03;
      }
      if (0x15e < (int)(*(uint (*)[2])(__fp - 0x26b8))[0]) {
        free((*(int * *)(__fp - 0x26b0)));
        uVar13 = extraout_RDX_04;
      }
      (*(int *)(__fp - 0x4d3c)) = (*(int *)(__fp - 0x4d3c)) + 1;
      iVar8 = iVar8 + 1;
      (*(ulong *)(__fp - 0x4d48)) = (*(ulong *)(__fp - 0x4d48)) + 8;
      if (iVar11 <= iVar8) goto LAB_00127e70;
    } while ((*(int *)(__fp - 0x4d3c)) < iVar12);
  }
  a4 = uVar17;
  if (iVar8 < iVar11) {
    iVar8 = iVar8 + (*(int *)(__fp - 0x4d4c));
    do {
      iVar12 = wmove(_stdscr,iVar8,p2);
      uVar13 = extraout_RDX_07;
      if (iVar12 != -1) {
        lVar5 = param_1[2];
        whline(_stdscr,0x20,(int)lVar5);
        uVar13 = extraout_RDX_08;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != (*(int *)(__fp - 0x4d4c)) + iVar11);
  }
LAB_00127e70:
  if ((param_3 != '\0') &&
     ((((char)param_1[9] != '\0' || (param_2 != '\0')) || (*(char *)((long)param_1 + 0x4a) == '\0'))
     )) {
    pcVar3 = *(code **)(*param_1 + 0x28);
    if (pcVar3 == (code *)0x0) {
      if (param_5 == '\0') {
        piVar15 = (int *)param_1[10];
        FunctionBar_drawExtra(piVar15,(char *)0x0,-1,'\0');
      }
    }
    else {
      (*pcVar3)((long)param_1,(ulong)(byte)param_5,uVar13,a3,a4,param_r9);
    }
  }
  *(undefined1 *)(param_1 + 9) = 0;
  *(int *)((long)param_1 + 0x2c) = (int)param_1[5];
  *(char *)((long)param_1 + 0x4a) = param_3;
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Panel_insert @ 0x129b20 */

void Panel_insert(long param_1,int param_2,undefined8 param_3)

{
  Vector_insert(*(undefined8 **)(param_1 + 0x20),param_2,param_3);
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


/* FUN_00129b50 @ 0x129b50 */

undefined8
FUN_00129b50(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  long *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  code *a3;
  byte bVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  undefined8 *puVar8;
  int iVar9;
  ulong uVar10;
  uint *puVar11;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  int iVar12;
  undefined8 uVar13;

  iVar12 = *(int *)(param_1 + 0x28);
  if (0x111 < param_2) {
    puVar11 = (uint *)param_rdx;
    if (param_2 == 0x14a) {
switchD_00129b93_caseD_111:
      iVar5 = (int)(*(long **)(param_1 + 0x26e8))[3];
      if (iVar5 == 0) {
        return 2;
      }
      if (iVar12 < iVar5) {
        Vector_remove(*(long **)(param_1 + 0x26e8),iVar12,(long)puVar11,param_rcx,param_r8,param_r9)
        ;
        Panel_remove(param_1,iVar12,extraout_RDX_02,param_rcx,param_r8,param_r9);
      }
      *(undefined1 *)(param_1 + 0x2708) = 0;
      if ((0 < (int)(*(long **)(param_1 + 0x20))[3]) &&
         (lVar6 = *(long *)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8),
         lVar6 != 0)) {
        *(undefined1 *)(lVar6 + 0x14) = 0;
      }
    }
    else {
      if (param_2 != 0x157) {
        return 2;
      }
switchD_00129bf3_caseD_a:
      if (*(int *)(*(long *)(param_1 + 0x26e8) + 0x18) == 0) {
        return 2;
      }
      lVar6 = (*(long **)(param_1 + 0x20))[3];
      bVar4 = *(byte *)(param_1 + 0x2708) ^ 1;
      *(byte *)(param_1 + 0x2708) = bVar4;
      if ((0 < (int)lVar6) &&
         (lVar6 = *(long *)(**(long **)(param_1 + 0x20) + (long)iVar12 * 8), lVar6 != 0)) {
        *(byte *)(lVar6 + 0x14) = bVar4;
      }
      lVar6 = LONG_0015c0c0;
      if (bVar4 != 0) {
        *(undefined4 *)(param_1 + 0x26d8) = 10;
        *(long *)(param_1 + 0x50) = lVar6;
        goto LAB_00129c3c;
      }
    }
    *(undefined4 *)(param_1 + 0x26d8) = 9;
    *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_1 + 0x58);
    goto LAB_00129c3c;
  }
  if (param_2 < 0x102) {
    if (param_2 < 0x2e) {
      if (param_2 < 10) {
LAB_00129bc6:
        return 2;
      }
      switch(param_2) {
      case 10:
      case 0xd:
        goto switchD_00129bf3_caseD_a;
      default:
        goto LAB_00129bc6;
      case 0x20:
        goto switchD_00129b93_caseD_10c;
      case 0x2b:
        goto switchD_00129b93_caseD_110;
      case 0x2d:
        goto switchD_00129b93_caseD_10f;
      }
    }
    if (param_2 != 0x5d) {
      if (param_2 == 0x74) goto switchD_00129b93_caseD_10c;
      if (param_2 != 0x5b) {
        return 2;
      }
      goto switchD_00129b93_caseD_10f;
    }
    goto switchD_00129b93_caseD_110;
  }
  puVar11 = &switchdataD_0014d768;
  switch(param_2) {
  case 0x102:
    if (*(char *)(param_1 + 0x2708) == '\0') {
      return 2;
    }
  case 0x110:
switchD_00129b93_caseD_110:
    if (iVar12 != (int)(*(long **)(param_1 + 0x26e8))[3] + -1) {
      puVar8 = (undefined8 *)(**(long **)(param_1 + 0x26e8) + (long)iVar12 * 8);
      uVar13 = *puVar8;
      *puVar8 = puVar8[1];
      puVar8[1] = uVar13;
    }
    Panel_moveSelectedDown(param_1);
    break;
  case 0x103:
    if (*(char *)(param_1 + 0x2708) == '\0') {
      return 2;
    }
  case 0x10f:
switchD_00129b93_caseD_10f:
    if (iVar12 != 0) {
      lVar6 = (long)iVar12 * 8;
      puVar8 = (undefined8 *)(**(long **)(param_1 + 0x26e8) + -8 + lVar6);
      uVar13 = *puVar8;
      puVar2 = (undefined8 *)(**(long **)(param_1 + 0x26e8) + -8 + lVar6);
      *puVar2 = puVar8[1];
      puVar2[1] = uVar13;
      puVar8 = (undefined8 *)(**(long **)(param_1 + 0x20) + -8 + lVar6);
      uVar13 = *puVar8;
      puVar2 = (undefined8 *)(**(long **)(param_1 + 0x20) + -8 + lVar6);
      *puVar2 = puVar8[1];
      puVar2[1] = uVar13;
      if (0 < iVar12) {
        *(int *)(param_1 + 0x28) = iVar12 + -1;
      }
    }
    break;
  case 0x104:
    if (*(char *)(param_1 + 0x2708) == '\0') {
      return 2;
    }
    plVar1 = *(long **)(param_1 + 0x26f8);
    goto joined_r0x00129d6d;
  case 0x105:
    if (*(char *)(param_1 + 0x2708) == '\0') {
      return 2;
    }
    plVar1 = *(long **)(param_1 + 0x2700);
joined_r0x00129d6d:
    if ((plVar1 != (long *)0x0) && (plVar7 = *(long **)(param_1 + 0x26e8), iVar12 < (int)plVar7[3]))
    {
      *(undefined1 *)(param_1 + 0x2708) = 0;
      uVar3 = *(uint *)(*(long **)(param_1 + 0x20) + 3);
      uVar10 = (ulong)uVar3;
      if ((0 < (int)uVar3) &&
         (lVar6 = *(long *)(**(long **)(param_1 + 0x20) + (long)iVar12 * 8), lVar6 != 0)) {
        *(undefined1 *)(lVar6 + 0x14) = 0;
      }
      *(undefined4 *)(param_1 + 0x26d8) = 9;
      *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_1 + 0x58);
      plVar7 = (long *)Vector_take(plVar7,iVar12);
      Panel_remove(param_1,iVar12,extraout_RDX,uVar10,param_r8,param_r9);
      Vector_insert((undefined8 *)plVar1[0x4dd],iVar12,plVar7);
      puVar8 = Meter_toListItem(plVar7,0,extraout_RDX_00,uVar10,param_r8,param_r9);
      Vector_insert((undefined8 *)plVar1[4],iVar12,puVar8);
      plVar7 = (long *)plVar1[4];
      *(undefined1 *)(plVar1 + 9) = 1;
      iVar5 = (int)plVar7[3];
      if (iVar5 <= iVar12) {
        iVar12 = iVar5 + -1;
      }
      iVar9 = 0;
      if (-1 < iVar12) {
        iVar9 = iVar12;
      }
      *(int *)(plVar1 + 5) = iVar9;
      a3 = *(code **)(*plVar1 + 0x20);
      if (a3 != (code *)0x0) {
        (*a3)((long)plVar1,0xffffffff,(long)plVar7,(long)a3,param_r8,param_r9);
        plVar7 = (long *)plVar1[4];
        iVar5 = (int)plVar7[3];
      }
      *(undefined1 *)(plVar1 + 0x4e1) = 1;
      if ((0 < iVar5) && (lVar6 = *(long *)(*plVar7 + (long)(int)plVar1[5] * 8), lVar6 != 0)) {
        *(undefined1 *)(lVar6 + 0x14) = 1;
      }
      lVar6 = LONG_0015c0c0;
      *(undefined4 *)(plVar1 + 0x4db) = 10;
      plVar1[10] = lVar6;
      uVar13 = 2;
      goto LAB_00129c42;
    }
    break;
  default:
    goto LAB_00129bc6;
  case 0x10c:
switchD_00129b93_caseD_10c:
    if ((int)(*(long **)(param_1 + 0x26e8))[3] == 0) {
      return 2;
    }
    plVar1 = *(long **)(**(long **)(param_1 + 0x26e8) + (long)iVar12 * 8);
    iVar5 = (int)plVar1[4] + 1;
    if ((int)plVar1[4] == 4) {
      iVar5 = 1;
    }
    Meter_setMode(plVar1,iVar5,(long)iVar12,param_rcx,param_r8,param_r9);
    puVar8 = Meter_toListItem(plVar1,*(undefined1 *)(param_1 + 0x2708),extraout_RDX_01,param_rcx,
                              param_r8,param_r9);
    Vector_set(*(long **)(param_1 + 0x20),iVar12,(long)puVar8,param_rcx,param_r8,param_r9);
    break;
  case 0x111:
    goto switchD_00129b93_caseD_111;
  }
LAB_00129c3c:
  uVar13 = 1;
LAB_00129c42:
  plVar7 = *(long **)(*(long *)(param_1 + 0x26f0) + 0x28);
  lVar6 = *(long *)(param_1 + 0x26e0);
  plVar1 = (long *)(lVar6 + 0x78);
  *plVar1 = *plVar1 + 1;
  *(undefined1 *)(lVar6 + 0x74) = 1;
  Header_calculateHeight(plVar7);
  ScreenManager_resize(*(int **)(param_1 + 0x26f0));
  return uVar13;
}


/* FUN_00129fb0 @ 0x129fb0 */

void FUN_00129fb0(long param_1)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  char *buf;
  long lVar1;
  double *pdVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar6;
  double dVar7;
  double dVar8;

  lVar1 = *(long *)(param_1 + 0x10);
  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = *(long *)(lVar1 + 0x18) - LONG_0015d650;
  if (uVar5 < 0x1f5) {
LAB_00129ff5:
    dVar8 = DOUBLE_0015d618;
    iVar3 = INT_0015c060;
    pdVar2 = *(double **)(param_1 + 0x160);
    dVar7 = DOUBLE_0015d640 + DOUBLE_0015d618;
    *pdVar2 = DOUBLE_0015d640;
    pdVar2[1] = dVar8;
    if (*(double *)(param_1 + 0x168) <= dVar7 && dVar7 != *(double *)(param_1 + 0x168)) {
      *(double *)(param_1 + 0x168) = dVar7;
    }
    if (iVar3 != 2) {
      buf = (char *)(param_1 + 0x60);
      if (iVar3 == 1) {
        xSnprintf(buf,0x100,((char *)(long)(__sec_rodata + 0x29bf) /* "init" */));
      }
      else if (iVar3 == 3) {
        xSnprintf(buf,0x100,((char *)(long)&s_stale_001476d3 /* "stale" */));
      }
      else {
        xSnprintf(buf,0x100,((char *)(long)&s_rx__siB_s_tx__siB_s__u__upkts_s_0014c4f8 /* "rx:%siB/s tx:%siB/s %u/%upkts/s" */),&DAT_0015d638,&DAT_0015d610,
                  INT_0015d628,INT_0015d604);
      }
      goto LAB_0012a079;
    }
  }
  else {
    uVar4 = Platform_getNetworkIO((undefined1 (*) [16])&(*(ulong *)(__fp - 0x58)));
    dVar8 = DOUBLE_0015d618;
    if ((char)uVar4 != '\0') {
      bVar6 = LONG_0015d650 == 0;
      LONG_0015d650 = *(long *)(lVar1 + 0x18);
      if (bVar6) {
        INT_0015c060 = 1;
      }
      else {
        INT_0015c060 = ~-(uint)(uVar5 < 0x7531) & 3;
        if (ULONG_0015d648 < (*(ulong *)(__fp - 0x58))) {
          DOUBLE_0015d640 = (double)(long)((((*(ulong *)(__fp - 0x58)) - ULONG_0015d648) * 1000) / uVar5);
          dVar8 = DOUBLE_0015d640 * 0.0009765625;
        }
        else {
          dVar8 = 0.0;
          DOUBLE_0015d640 = 0.0;
        }
        Meter_humanUnit(dVar8,&DAT_0015d638,6);
        INT_0015d628 = 0;
        if (ULONG_0015d630 < (*(ulong *)(__fp - 0x50))) {
          INT_0015d628 = (int)((((*(ulong *)(__fp - 0x50)) - ULONG_0015d630) * 1000) / uVar5);
        }
        if (ULONG_0015d620 < (*(ulong *)(__fp - 0x48))) {
          DOUBLE_0015d618 = (double)(long)((((*(ulong *)(__fp - 0x48)) - ULONG_0015d620) * 1000) / uVar5);
          dVar8 = DOUBLE_0015d618 * 0.0009765625;
        }
        else {
          dVar8 = 0.0;
          DOUBLE_0015d618 = 0.0;
        }
        Meter_humanUnit(dVar8,&DAT_0015d610,6);
        if (ULONG_0015d608 < (*(ulong *)(__fp - 0x40))) {
          INT_0015d604 = (int)((((*(ulong *)(__fp - 0x40)) - ULONG_0015d608) * 1000) / uVar5);
        }
        else {
          INT_0015d604 = 0;
        }
      }
      ULONG_0015d648 = (*(ulong *)(__fp - 0x58));
      ULONG_0015d630 = (*(ulong *)(__fp - 0x50));
      ULONG_0015d620 = (*(ulong *)(__fp - 0x48));
      ULONG_0015d608 = (*(ulong *)(__fp - 0x40));
      goto LAB_00129ff5;
    }
    LONG_0015d650 = *(long *)(lVar1 + 0x18);
    INT_0015c060 = 2;
    pdVar2 = *(double **)(param_1 + 0x160);
    dVar7 = DOUBLE_0015d618 + DOUBLE_0015d640;
    *pdVar2 = DOUBLE_0015d640;
    pdVar2[1] = dVar8;
    if (*(double *)(param_1 + 0x168) <= dVar7 && dVar7 != *(double *)(param_1 + 0x168)) {
      *(double *)(param_1 + 0x168) = dVar7;
    }
  }
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s_no_data_001476cb /* "no data" */));
LAB_0012a079:
  if ((*(long *)(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Panel_add @ 0x12a340 */

void Panel_add(long param_1,long param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  int iVar1;
  long *plVar2;
  long *a0;
  void *pvVar3;
  long a3;
  int iVar4;
  ulong a1;
  long *plVar5;
  uint uVar6;
  long lVar7;

  plVar2 = *(long **)(param_1 + 0x20);
  iVar1 = (int)plVar2[3];
  a1 = (ulong)(int)plVar2[2];
  pvVar3 = (void *)*plVar2;
  uVar6 = iVar1 + 1;
  lVar7 = (long)iVar1 * 8;
  if ((int)plVar2[2] < (int)uVar6) {
    iVar4 = uVar6 + *(int *)((long)plVar2 + 0x14);
    a3 = 8;
    *(int *)(plVar2 + 2) = iVar4;
    pvVar3 = xReallocArrayZero(pvVar3,a1,(long)iVar4,8);
    *plVar2 = (long)pvVar3;
    if (iVar1 < (int)plVar2[3]) {
      plVar5 = (long *)((long)pvVar3 + lVar7);
      if ((*(char *)((long)plVar2 + 0x24) != '\0') && (a0 = (long *)*plVar5, a0 != (long *)0x0)) {
        (**(code **)(*a0 + 0x10))((long)a0,a1,*a0,a3,(ulong)uVar6,param_r9);
        plVar5 = (long *)(*plVar2 + lVar7);
      }
      goto LAB_0012a381;
    }
  }
  *(uint *)(plVar2 + 3) = uVar6;
  plVar5 = (long *)((long)pvVar3 + lVar7);
LAB_0012a381:
  *plVar5 = param_2;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


/* Panel_set @ 0x12c310 */

void Panel_set(long param_1,int param_2,long param_3,long param_rcx,long param_r8,long param_r9)

{
  long *plVar1;
  long *a0;
  void *pvVar2;
  int iVar3;
  ulong a1;
  long *plVar4;
  int iVar5;

  iVar5 = param_2 + 1;
  plVar1 = *(long **)(param_1 + 0x20);
  a1 = (ulong)(int)plVar1[2];
  pvVar2 = (void *)*plVar1;
  if ((int)plVar1[2] < iVar5) {
    param_rcx = 8;
    iVar3 = *(int *)((long)plVar1 + 0x14) + iVar5;
    *(int *)(plVar1 + 2) = iVar3;
    pvVar2 = xReallocArrayZero(pvVar2,a1,(long)iVar3,8);
    *plVar1 = (long)pvVar2;
  }
  plVar4 = (long *)((long)pvVar2 + (long)param_2 * 8);
  if (param_2 < (int)plVar1[3]) {
    if ((*(char *)((long)plVar1 + 0x24) != '\0') && (a0 = (long *)*plVar4, a0 != (long *)0x0)) {
      (**(code **)(*a0 + 0x10))((long)a0,a1,*a0,param_rcx,param_r8,param_r9);
      plVar4 = (long *)(*plVar1 + (long)param_2 * 8);
    }
  }
  else {
    *(int *)(plVar1 + 3) = iVar5;
  }
  *plVar4 = param_3;
  return;
}


/* Panel_splice @ 0x12c3b0 */

void Panel_splice(long param_1,long *param_2)

{
  Vector_splice(*(long **)(param_1 + 0x20),param_2);
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}

