#include "htop.h"

/* IncSet_getListItemValue @ 0x11fab0 */

undefined * IncSet_getListItemValue(long param_1,int param_2)

{
  long lVar1;
  undefined *puVar2;

  lVar1 = *(long *)(**(long **)(param_1 + 0x20) + (long)param_2 * 8);
  puVar2 = &DAT_00149c0c;
  if (lVar1 != 0) {
    puVar2 = *(undefined **)(lVar1 + 8);
  }
  return puVar2;
}


/* FUN_0011fae0 @ 0x11fae0 */

undefined *
FUN_0011fae0(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  long *a0;
  code *UNRECOVERED_JUMPTABLE;
  undefined *puVar1;

  a0 = *(long **)(**(long **)(param_1 + 0x20) + (long)param_2 * 8);
  UNRECOVERED_JUMPTABLE = *(code **)(*a0 + 0x40);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011fafe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar1 = (undefined *)
             (*UNRECOVERED_JUMPTABLE)((long)a0,(long)param_2,param_rdx,param_rcx,param_r8,param_r9);
    return puVar1;
  }
  return &DAT_00149c0c;
}


/* FUN_0011fb10 @ 0x11fb10 */

void FUN_0011fb10(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long *plVar1;
  long *a0;
  long a2;

  plVar1 = *(long **)(param_1 + 0x170);
  a0 = (long *)*plVar1;
  (**(code **)(*a0 + 0x38))((long)a0,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  plVar1 = (long *)plVar1[1];
                    /* WARNING: Could not recover jumptable at 0x0011fb3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar1 + 0x38))((long)plVar1,param_rsi,a2,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0011fb40 @ 0x11fb40 */

void FUN_0011fb40(long param_1,long param_2,ulong param_3,int param_4,long param_r8,long param_r9)

{
  long *plVar1;
  long lVar2;
  uint uVar3;

  uVar3 = param_4 / 2;
  plVar1 = *(long **)(param_1 + 0x170);
  lVar2 = *plVar1;
  (**(code **)(lVar2 + 8))(lVar2,param_2,param_3,(ulong)uVar3,param_r8,param_r9);
  lVar2 = plVar1[1];
                    /* WARNING: Could not recover jumptable at 0x0011fbac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar2 + 8))
            (lVar2,(ulong)(uVar3 + (int)param_2 + param_4 % 2),param_3 & 0xffffffff,(ulong)uVar3,
             param_r8,param_r9);
  return;
}


/* FUN_0011fbb0 @ 0x11fbb0 */

void FUN_0011fbb0(long param_1)

{
  *(undefined1 *)(param_1 + 0x60) = 0;
  return;
}


/* FUN_0011fbc0 @ 0x11fbc0 */

void FUN_0011fbc0(void)

{
  return;
}


/* IncSet_reset @ 0x120ef0 */

void IncSet_reset(long param_1,uint param_2)

{
  undefined1 *puVar1;

  puVar1 = (undefined1 *)(param_1 + (ulong)param_2 * 0x98);
  *(undefined4 *)(puVar1 + 0x84) = 0;
  *puVar1 = 0;
  return;
}


/* IncSet_setFilter @ 0x120f10 */

void IncSet_setFilter(long param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;

  lVar1 = 0;
  do {
    if (*(char *)(param_2 + lVar1) == '\0') {
      uVar2 = (undefined4)lVar1;
      goto LAB_00120f3d;
    }
    *(char *)(param_1 + 0x98 + lVar1) = *(char *)(param_2 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x80);
  uVar2 = 0x80;
LAB_00120f3d:
  *(undefined1 *)(param_1 + 0x98 + lVar1) = 0;
  *(undefined4 *)(param_1 + 0x11c) = uVar2;
  *(undefined1 *)(param_1 + 0x148) = 1;
  return;
}


/* IncSet_delete @ 0x126cb0 */

void IncSet_delete(void *param_1)

{
  FunctionBar_delete(*(int **)((long)param_1 + 0x88));
  FunctionBar_delete(*(int **)((long)param_1 + 0x120));
  free(param_1);
  return;
}


/* IncSet_new @ 0x127280 */

undefined8 * IncSet_new(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 *puVar4;
  byte bVar5;

  bVar5 = 0;
  puVar1 = malloc(0x150);
  if (puVar1 != (undefined8 *)0x0) {
    puVar4 = puVar1;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
    puVar2 = FunctionBar_new(&PTR_s_Next_00157c20,(long)&PTR_DAT_00157c00,(long)&DAT_0014dbc0);
    *(undefined1 *)(puVar1 + 0x12) = 0;
    puVar1[0x11] = puVar2;
    puVar4 = puVar1 + 0x13;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
    puVar2 = FunctionBar_new(&PTR_s_Done_00157c80,(long)&PTR_s_Enter_00157c50,(long)&DAT_0014dbd0);
    *(undefined1 *)(puVar1 + 0x25) = 1;
    puVar1[0x24] = puVar2;
    *(undefined2 *)(puVar1 + 0x29) = 0;
    puVar1[0x26] = 0;
    puVar1[0x28] = param_1;
    return puVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* IncSet_drawBar @ 0x1276f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IncSet_drawBar(long param_1,int param_2)

{
  char *pcVar1;
  long lVar2;
  int iVar3;

  pcVar1 = *(char **)(param_1 + 0x130);
  if (pcVar1 != (char *)0x0) {
    if ((pcVar1[0x90] == '\0') && (*(char *)(param_1 + 0x149) == '\0')) {
      param_2 = *(int *)(CRT_colors + 0x10);
    }
    iVar3 = FunctionBar_drawExtra(*(int **)(pcVar1 + 0x88),pcVar1,param_2,'\x01');
    lVar2 = *(long *)(param_1 + 0x138);
    *(int *)(lVar2 + 0x18) = iVar3;
    *(int *)(lVar2 + 0x1c) = _LINES + -1;
    return;
  }
  FunctionBar_drawExtra(*(int **)(param_1 + 0x140),(char *)0x0,-1,'\0');
  return;
}


/* IncSet_activate @ 0x127780 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IncSet_activate(long param_1,uint param_2,long param_3)

{
  char *pcVar1;
  int *piVar2;
  long lVar3;
  int iVar4;

  pcVar1 = (char *)(param_1 + (ulong)param_2 * 0x98);
  *(char **)(param_1 + 0x130) = pcVar1;
  piVar2 = *(int **)(pcVar1 + 0x88);
  *(undefined1 *)(param_3 + 0x49) = 1;
  lVar3 = CRT_colors;
  *(int **)(param_3 + 0x50) = piVar2;
  *(long *)(param_1 + 0x138) = param_3;
  iVar4 = *(int *)(lVar3 + 8);
  if ((pcVar1[0x90] == '\0') && (*(char *)(param_1 + 0x149) == '\0')) {
    iVar4 = *(int *)(lVar3 + 0x10);
  }
  iVar4 = FunctionBar_drawExtra(piVar2,pcVar1,iVar4,'\x01');
  lVar3 = *(long *)(param_1 + 0x138);
  *(int *)(lVar3 + 0x18) = iVar4;
  *(int *)(lVar3 + 0x1c) = _LINES + -1;
  return;
}


/* IncSet_synthesizeEvent @ 0x128660 */

void IncSet_synthesizeEvent(long param_1,int param_2)

{
  if (*(long *)(param_1 + 0x130) != 0) {
    FunctionBar_synthesizeEvent(*(int **)(*(long *)(param_1 + 0x130) + 0x88),param_2);
    return;
  }
  FunctionBar_synthesizeEvent(*(int **)(param_1 + 0x140),param_2);
  return;
}


/* IncSet_handleKey @ 0x12a3f0 */

char IncSet_handleKey(long param_1,int param_2,long *param_3,undefined *param_4,long *param_5,
                     long param_r9)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  code *pcVar1;
  long *plVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char **ppcVar8;
  char *pcVar9;
  ushort **ppuVar10;
  bool bVar11;
  ulong a3;
  ulong uVar12;
  long *a3_00;
  uint uVar13;
  ushort *extraout_RDX;
  long extraout_RDX_00;
  ushort *extraout_RDX_01;
  ushort *a2;
  ushort *extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  ushort *extraout_RDX_05;
  ushort *extraout_RDX_06;
  ushort *extraout_RDX_07;
  ushort *extraout_RDX_08;
  long extraout_RDX_09;
  ushort *extraout_RDX_10;
  char **ppcVar14;
  long lVar15;
  long *plVar16;
  uint uVar17;
  uint uVar18;
  ulong a1;
  char cVar19;
  char cVar20;
  long lVar21;
  long lVar22;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != -1) {
    pcVar9 = *(char **)(param_1 + 0x130);
    uVar13 = *(uint *)(param_3[4] + 0x18);
    a2 = (ushort *)(ulong)uVar13;
    bVar11 = param_2 == 0x10b || param_2 == 0x117;
    uVar12 = CONCAT71((int7)((ulong)param_4 >> 8),bVar11);
    if (param_2 != 0x10b && param_2 != 0x117) {
      plVar16 = param_5;
      if (param_2 - 1U < 0xfe) {
        ppuVar10 = __ctype_b_loc();
        uVar12 = (ulong)bVar11;
        a2 = *ppuVar10;
        if ((*(byte *)((long)a2 + (long)param_2 * 2 + 1) & 0x40) == 0) {
          if (param_2 != 0x7f) {
            cVar19 = pcVar9[0x90];
            if (cVar19 == '\0') {
              if (param_2 == 0x1b) {
                pcVar9[0x84] = '\0';
                pcVar9[0x85] = '\0';
                pcVar9[0x86] = '\0';
                pcVar9[0x87] = '\0';
                *pcVar9 = '\0';
              }
              goto LAB_0012ab56;
            }
            if (param_2 == 0x1b) {
              *(undefined1 *)(param_1 + 0x148) = 0;
              pcVar9[0x84] = '\0';
              pcVar9[0x85] = '\0';
              pcVar9[0x86] = '\0';
              pcVar9[0x87] = '\0';
              *pcVar9 = '\0';
            }
LAB_0012abb3:
            bVar11 = param_5 != (long *)0x0;
            goto LAB_0012ab5d;
          }
          goto LAB_0012aa7c;
        }
        iVar5 = *(int *)(pcVar9 + 0x84);
        if (iVar5 < 0x80) {
          iVar4 = iVar5 + 1;
          pcVar9[iVar5] = (char)param_2;
          a2 = (ushort *)(long)iVar4;
          *(int *)(pcVar9 + 0x84) = iVar4;
          pcVar9[(long)a2] = '\0';
          if (pcVar9[0x90] != '\0') {
            if (iVar4 == 1) {
              *(undefined1 *)(param_1 + 0x148) = 1;
            }
            goto LAB_0012a9f7;
          }
        }
LAB_0012a702:
        bVar11 = false;
        cVar20 = '\0';
        if ((int)uVar13 < 1) {
          *(undefined1 *)(param_1 + 0x149) = 0;
          goto LAB_0012a589;
        }
LAB_0012a714:
        a1 = 0;
        a3 = uVar12;
        do {
          uVar18 = (uint)a1;
          pcVar9 = *(char **)(param_1 + 0x130);
          pcVar6 = (char *)(*(code *)param_4)((long)param_3,a1,(long)a2,a3,(long)plVar16,param_r9);
          pcVar7 = strchr(pcVar9,0x7c);
          cVar19 = cVar20;
          if (pcVar7 == (char *)0x0) {
            pcVar6 = strcasestr(pcVar6,pcVar9);
            a2 = extraout_RDX_07;
            if (pcVar6 != (char *)0x0) goto LAB_0012a7e9;
          }
          else {
            pcVar7 = (char *)0x7c;
            ppcVar8 = String_split(pcVar9,'|',&(*(long *)(__fp - 0x48)));
            lVar15 = (*(long *)(__fp - 0x48));
            if ((*(long *)(__fp - 0x48)) != 0) {
              lVar21 = 0;
LAB_0012a79d:
              pcVar7 = ppcVar8[lVar21];
              pcVar9 = strcasestr(pcVar6,pcVar7);
              if (pcVar9 == (char *)0x0) goto LAB_0012a790;
              pcVar6 = *ppcVar8;
              ppcVar14 = ppcVar8;
              pcVar9 = pcVar7;
              while (pcVar6 != (char *)0x0) {
                ppcVar14 = ppcVar14 + 1;
                free(pcVar6);
                pcVar6 = *ppcVar14;
              }
              free(ppcVar8);
              goto LAB_0012a7e9;
            }
            a2 = extraout_RDX_01;
            pcVar9 = pcVar7;
            if (ppcVar8 != (char **)0x0) {
LAB_0012aa48:
              pcVar9 = *ppcVar8;
              ppcVar14 = ppcVar8;
              while (pcVar9 != (char *)0x0) {
                ppcVar14 = ppcVar14 + 1;
                free(pcVar9);
                pcVar9 = *ppcVar14;
              }
              free(ppcVar8);
              a2 = extraout_RDX_08;
              pcVar9 = pcVar7;
            }
          }
          a1 = (ulong)(uVar18 + 1);
        } while (uVar13 != uVar18 + 1);
        uVar12 = uVar12 & 0xff;
        goto LAB_0012a823;
      }
      if (param_2 == 0x107) {
LAB_0012aa7c:
        if (*(int *)(pcVar9 + 0x84) < 1) goto LAB_0012a589;
        iVar5 = *(int *)(pcVar9 + 0x84) + -1;
        a2 = (ushort *)(long)iVar5;
        *(int *)(pcVar9 + 0x84) = iVar5;
        pcVar9[(long)a2] = '\0';
        if (pcVar9[0x90] == '\0') goto LAB_0012a702;
        if (iVar5 == 0) {
          *(undefined1 *)(param_1 + 0x148) = 0;
          pcVar9[0x84] = '\0';
          pcVar9[0x85] = '\0';
          pcVar9[0x86] = '\0';
          pcVar9[0x87] = '\0';
          *pcVar9 = '\0';
        }
LAB_0012a9f7:
        bVar11 = param_5 != (long *)0x0;
        pcVar9 = (char *)(ulong)uVar13;
        cVar19 = '\x01';
        cVar20 = '\x01';
        if ((int)uVar13 < 1) goto LAB_0012a823;
        goto LAB_0012a714;
      }
      if (param_2 == 0x19a) {
        plVar16 = (long *)(ulong)*(uint *)(pcVar9 + 0x84);
        if (0 < (int)*(uint *)(pcVar9 + 0x84)) goto LAB_0012a702;
        goto LAB_0012a589;
      }
      cVar19 = pcVar9[0x90];
      if (cVar19 != '\0') goto LAB_0012abb3;
LAB_0012ab56:
      bVar11 = false;
      cVar19 = '\0';
LAB_0012ab5d:
      pcVar9 = (char *)0x0;
      lVar15 = param_3[0xb];
      piVar3 = *(int **)(param_1 + 0x140);
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined1 *)((long)param_3 + 0x49) = 0;
      param_3[10] = lVar15;
      FunctionBar_drawExtra(piVar3,(char *)0x0,-1,'\0');
      a2 = extraout_RDX_10;
      goto LAB_0012a82d;
    }
    if (uVar13 != 0) {
      uVar18 = *(uint *)(param_3 + 5);
      uVar12 = (ulong)uVar18;
      uVar17 = uVar18;
      do {
        while( true ) {
          uVar17 = uVar17 + ((param_2 == 0x10b) - 1) + (uint)(param_2 == 0x10b);
          if (uVar13 == uVar17) {
            uVar17 = 0;
          }
          else if (uVar17 == 0xffffffff) {
            uVar17 = uVar13 - 1;
          }
          if (uVar17 == uVar18) goto LAB_0012a589;
          pcVar6 = (char *)(*(code *)param_4)((long)param_3,(ulong)uVar17,(long)a2,uVar12,
                                              (long)param_5,param_r9);
          pcVar7 = strchr(pcVar9,0x7c);
          if (pcVar7 == (char *)0x0) break;
          ppcVar8 = String_split(pcVar9,'|',&(*(long *)(__fp - 0x48)));
          lVar15 = (*(long *)(__fp - 0x48));
          if ((*(long *)(__fp - 0x48)) != 0) {
            lVar21 = 0;
LAB_0012a515:
            pcVar7 = strcasestr(pcVar6,ppcVar8[lVar21]);
            if (pcVar7 == (char *)0x0) goto LAB_0012a508;
            pcVar9 = *ppcVar8;
            ppcVar14 = ppcVar8;
            while (pcVar9 != (char *)0x0) {
              ppcVar14 = ppcVar14 + 1;
              free(pcVar9);
              pcVar9 = *ppcVar14;
            }
            free(ppcVar8);
            goto LAB_0012a551;
          }
          a2 = extraout_RDX;
          if (ppcVar8 != (char **)0x0) {
LAB_0012a950:
            pcVar6 = *ppcVar8;
            ppcVar14 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar14 = ppcVar14 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar14;
            }
            free(ppcVar8);
            a2 = extraout_RDX_06;
          }
        }
        pcVar6 = strcasestr(pcVar6,pcVar9);
        a2 = extraout_RDX_05;
      } while (pcVar6 == (char *)0x0);
LAB_0012a551:
      uVar13 = *(int *)(param_3[4] + 0x18) - 1;
      if (*(int *)(param_3[4] + 0x18) <= (int)uVar17) {
        uVar17 = uVar13;
      }
      if ((int)uVar17 < 0) {
        uVar17 = 0;
      }
      pcVar1 = *(code **)(*param_3 + 0x20);
      *(uint *)(param_3 + 5) = uVar17;
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)((long)param_3,0xffffffff,(ulong)uVar13,(long)param_3,(long)param_5,param_r9);
      }
LAB_0012a589:
      cVar19 = '\0';
      goto LAB_0012a69e;
    }
  }
  goto LAB_0012a698;
LAB_0012a790:
  lVar21 = lVar21 + 1;
  if (lVar21 == lVar15) goto LAB_0012aa48;
  goto LAB_0012a79d;
LAB_0012a618:
  lVar22 = lVar22 + 1;
  if (lVar22 == lVar21) goto LAB_0012ab00;
  goto LAB_0012a625;
LAB_0012a508:
  lVar21 = lVar21 + 1;
  if (lVar21 == lVar15) goto LAB_0012a950;
  goto LAB_0012a515;
LAB_0012a7e9:
  uVar13 = *(int *)(param_3[4] + 0x18) - 1;
  if ((int)uVar18 < *(int *)(param_3[4] + 0x18)) {
    uVar13 = uVar18;
  }
  if ((int)uVar13 < 0) {
    uVar13 = 0;
  }
  a2 = (ushort *)(ulong)uVar13;
  pcVar1 = *(code **)(*param_3 + 0x20);
  *(uint *)(param_3 + 5) = uVar13;
  if (pcVar1 != (code *)0x0) {
    pcVar9 = (char *)0xffffffff;
    (*pcVar1)((long)param_3,0xffffffff,(long)a2,(long)param_3,(long)plVar16,param_r9);
    a2 = extraout_RDX_02;
  }
  uVar12 = 1;
LAB_0012a823:
  *(char *)(param_1 + 0x149) = (char)uVar12;
LAB_0012a82d:
  if (!bVar11) goto LAB_0012a69e;
  (*(long * *)(__fp - 0x70)) = (long *)0x0;
  plVar2 = (long *)param_3[4];
  a3_00 = (long *)(ulong)*(uint *)(plVar2 + 3);
  if (0 < (int)*(uint *)(plVar2 + 3)) {
    a2 = (ushort *)(long)(int)param_3[5];
    (*(long * *)(__fp - 0x70)) = *(long **)(*plVar2 + (long)a2 * 8);
  }
  Vector_prune(plVar2,(long)pcVar9,(long)a2,(long)a3_00,(long)plVar16,param_r9);
  *(undefined4 *)(param_3 + 8) = 0;
  param_3[5] = 0;
  *(undefined1 *)(param_3 + 9) = 1;
  if (*(char *)(param_1 + 0x148) == '\0') {
    lVar15 = 0;
    uVar12 = (ulong)*(uint *)(param_5 + 3);
    if (0 < (int)*(uint *)(param_5 + 3)) {
      do {
        plVar2 = *(long **)(*param_5 + lVar15 * 8);
        Panel_add((long)param_3,(long)plVar2,uVar12,(long)a3_00,(long)plVar16,param_r9);
        uVar12 = extraout_RDX_03;
        if (plVar2 == (*(long * *)(__fp - 0x70))) {
          iVar5 = *(int *)(param_3[4] + 0x18) + -1;
          if ((int)lVar15 < *(int *)(param_3[4] + 0x18)) {
            iVar5 = (int)lVar15;
          }
          uVar12 = 0;
          if (iVar5 < 0) {
            iVar5 = 0;
          }
          *(int *)(param_3 + 5) = iVar5;
          if (*(code **)(*param_3 + 0x20) != (code *)0x0) {
            (**(code **)(*param_3 + 0x20))
                      ((long)param_3,0xffffffff,0,(long)a3_00,(long)plVar16,param_r9);
            uVar12 = extraout_RDX_04;
          }
        }
        lVar15 = lVar15 + 1;
      } while ((int)lVar15 < (int)param_5[3]);
    }
  }
  else {
    pcVar9 = (char *)(param_1 + 0x98);
    if (0 < (int)param_5[3]) {
      (*(int *)(__fp - 0x7c)) = 0;
      lVar15 = 0;
      do {
        plVar2 = *(long **)(*param_5 + lVar15 * 8);
        pcVar6 = (char *)plVar2[1];
        pcVar7 = strchr(pcVar9,0x7c);
        if (pcVar7 == (char *)0x0) {
          pcVar6 = strcasestr(pcVar6,pcVar9);
          lVar21 = extraout_RDX_09;
          if (pcVar6 != (char *)0x0) {
LAB_0012a662:
            Panel_add((long)param_3,(long)plVar2,lVar21,(long)a3_00,(long)plVar16,param_r9);
            a3_00 = (*(long * *)(__fp - 0x70));
            if (plVar2 == (*(long * *)(__fp - 0x70))) {
              iVar5 = *(int *)(param_3[4] + 0x18) + -1;
              if ((*(int *)(__fp - 0x7c)) < *(int *)(param_3[4] + 0x18)) {
                iVar5 = (*(int *)(__fp - 0x7c));
              }
              if (iVar5 < 0) {
                iVar5 = 0;
              }
              *(int *)(param_3 + 5) = iVar5;
              a3_00 = param_3;
              if (*(code **)(*param_3 + 0x20) != (code *)0x0) {
                (**(code **)(*param_3 + 0x20))
                          ((long)param_3,0xffffffff,0,(long)param_3,(long)plVar16,param_r9);
              }
            }
            (*(int *)(__fp - 0x7c)) = (*(int *)(__fp - 0x7c)) + 1;
          }
        }
        else {
          ppcVar8 = String_split(pcVar9,'|',&(*(long *)(__fp - 0x48)));
          lVar21 = (*(long *)(__fp - 0x48));
          if ((*(long *)(__fp - 0x48)) != 0) {
            lVar22 = 0;
LAB_0012a625:
            pcVar7 = strcasestr(pcVar6,ppcVar8[lVar22]);
            if (pcVar7 == (char *)0x0) goto LAB_0012a618;
            pcVar6 = *ppcVar8;
            ppcVar14 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar14 = ppcVar14 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar14;
            }
            free(ppcVar8);
            lVar21 = extraout_RDX_00;
            goto LAB_0012a662;
          }
          if (ppcVar8 != (char **)0x0) {
LAB_0012ab00:
            pcVar6 = *ppcVar8;
            ppcVar14 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar14 = ppcVar14 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar14;
            }
            free(ppcVar8);
          }
        }
        lVar15 = lVar15 + 1;
      } while ((int)lVar15 < (int)param_5[3]);
    }
  }
LAB_0012a698:
  cVar19 = '\x01';
LAB_0012a69e:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar19;
}

