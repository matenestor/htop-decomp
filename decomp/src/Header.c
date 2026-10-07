#include "htop.h"

/* Header_new @ 0x1184a0 */

undefined8 * Header_new(undefined8 param_1,int param_2)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  void *pvVar4;
  ulong uVar5;
  ulong uVar6;

  puVar1 = calloc(1,0x20);
  if (puVar1 != (undefined8 *)0x0) {
    uVar6 = (ulong)(byte)(&DAT_00155fa0)[(long)param_2 * 0x18];
    pvVar2 = malloc(uVar6 * 8);
    if (pvVar2 != (void *)0x0) {
      *puVar1 = pvVar2;
      *(int *)(puVar1 + 2) = param_2;
      puVar1[1] = param_1;
      if (uVar6 != 0) {
        uVar5 = 0;
        do {
          puVar3 = malloc(0x28);
          if (puVar3 == (undefined8 *)0x0) goto LAB_00118594;
          *(undefined4 *)((long)puVar3 + 0x14) = 10;
          pvVar4 = calloc(10,8);
          if (pvVar4 == (void *)0x0) goto LAB_00118594;
          *puVar3 = pvVar4;
          *(undefined8 **)((long)pvVar2 + uVar5 * 8) = puVar3;
          uVar5 = uVar5 + 1;
          *(undefined4 *)(puVar3 + 2) = 10;
          puVar3[1] = Meter_class;
          *(undefined1 *)((long)puVar3 + 0x24) = 1;
          puVar3[3] = 0xffffffff00000000;
          *(undefined4 *)(puVar3 + 4) = 0;
        } while (uVar5 != uVar6);
      }
      return puVar1;
    }
  }
LAB_00118594:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001185a0 @ 0x1185a0 */

/* WARNING: Removing unreachable block (ram,0x00118661) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011867e */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_001185a0(long *param_1)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  char cVar1;
  wchar_t __wc;
  int *piVar2;
  code *pcVar3;
  long *plVar4;
  ulong *puVar5;
  long *plVar6;
  ulong *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  long *a0;
  size_t sVar11;
  ulong *puVar12;
  long lVar13;
  long a3;
  undefined8 *puVar14;
  char *pcVar15;
  char *pcVar16;
  ulong *a3_00;
  uint uVar17;
  long *plVar18;
  long extraout_RDX;
  wchar_t *pwVar19;
  long *plVar20;
  long *plVar21;
  ulong *a5;
  undefined1 (*pauVar22) [16];
  undefined8 uVar23;
  long lVar24;
  long in_FS_OFFSET = (long)__fake_fs;

  plVar20 = &(*(undefined8 *)(__fp - 0x88));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x48)) = 0;
  (*(char * *)(__fp - 0x58)) = ((char *)(long)&s_Sort_0014721b /* "Sort   " */);
  (*(char * *)(__fp - 0x50)) = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(long * *)(__fp - 0x78)) = param_1;
  puVar10 = FunctionBar_new(&(*(char * *)(__fp - 0x58)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
  a0 = malloc(0x26e0);
  if (a0 != (long *)0x0) {
    a3_00 = (ulong *)0x0;
    *a0 = (long)Panel_class;
    Panel_init((long)a0,0,0,0,0,ListItem_class,1,puVar10);
    uVar17 = *(uint *)(CRT_colors + 0x1c);
    (*(long * *)(__fp - 0x60)) = &(*(undefined8 *)(__fp - 0x88));
    pwVar19 = (*(wchar_t (*)[4])(__fp - 0xa8));
    (*(long * *)(__fp - 0x60)) = &(*(undefined8 *)(__fp - 0x88));
    sVar11 = mbstowcs((*(wchar_t (*)[4])(__fp - 0xa8)),((char *)(long)&s_Sort_by_0014722b /* "Sort by" */),7);
    iVar8 = (int)sVar11;
    if (0 < iVar8) {
      FUN_00130130((int *)(a0 + 0xc),iVar8);
      (*(long * *)(__fp - 0x68)) = a0;
      pauVar22 = (undefined1 (*) [16])a0[0xd];
      do {
        __wc = *pwVar19;
        iVar9 = iswprint(__wc);
        *(undefined16 *)(*pauVar22) = (undefined16)0x0;
        if (iVar9 == 0) {
          __wc = L'�';
        }
        pwVar19 = pwVar19 + 1;
        *(uint *)*pauVar22 = uVar17 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar22 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar22 + 4) = __wc;
        a0 = (*(long * *)(__fp - 0x68));
        pauVar22 = (undefined1 (*) [16])(pauVar22[1] + 0xc);
      } while (pwVar19 != (*(wchar_t (*)[4])(__fp - 0xa8)) + (ulong)(iVar8 - 1) + 1);
    }
    plVar20 = (*(long * *)(__fp - 0x60));
    *(undefined1 *)(a0 + 9) = 1;
    lVar24 = 0;
    plVar21 = *(long **)*(*(long * *)(__fp - 0x78));
    a5 = (ulong *)plVar21[3];
    piVar2 = *(int **)(plVar21[8] + 0x18);
    iVar8 = *piVar2;
    puVar5 = (ulong *)*(*(long * *)(__fp - 0x78));
    plVar6 = plVar21;
    puVar7 = a5;
    plVar4 = (*(long * *)(__fp - 0x78));
    do {
      while( true ) {
        (*(long * *)(__fp - 0x78)) = plVar4;
        if (iVar8 == 0) {
          a3 = 0;
          uVar23 = 0x61;
          (*(long * *)(__fp - 0x60)) = plVar6;
          plVar18 = a0;
          lVar13 = Action_pickFromVector(plVar4,(long)a0,0xe,'\0',(long)plVar6,(long)a5);
          plVar21 = (*(long * *)(__fp - 0x60));
          lVar24 = extraout_RDX;
          if (lVar13 != 0) {
            iVar8 = *(int *)(lVar13 + 0x10);
            a3 = (long)iVar8;
            lVar24 = (*(long * *)(__fp - 0x60))[8];
            cVar1 = Process_fields[a3 * 0x20 + 0x1d];
            if ((*(char *)(lVar24 + 0x35) == '\0') && (*(char *)(lVar24 + 0x34) != '\0')) {
              *(int *)(lVar24 + 0x30) = iVar8;
              *(uint *)(lVar24 + 0x28) = (-(uint)(cVar1 == '\0') & 2) - 1;
            }
            else {
              *(int *)(lVar24 + 0x2c) = iVar8;
              *(undefined1 *)(lVar24 + 0x34) = 0;
              *(uint *)(lVar24 + 0x24) = (-(uint)(cVar1 == '\0') & 2) - 1;
            }
            uVar23 = 0x6d;
          }
          pcVar3 = *(code **)(*a0 + 0x10);
          (*pcVar3)((long)a0,(long)plVar18,lVar24,a3,(long)plVar21,(long)a5);
          *(undefined1 *)(puVar5[0x15] + 0x30) = 1;
          if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return uVar23;
        }
        (*(ulong * *)(__fp - 0x80)) = puVar5;
        (*(ulong * *)(__fp - 0x70)) = puVar7;
        (*(long * *)(__fp - 0x68)) = plVar6;
        if (iVar8 < 0x84) break;
        plVar21 = (long *)*puVar7;
        a5 = (ulong *)puVar7[1];
        plVar18 = (long *)((ulong)(long)iVar8 % (ulong)plVar21);
        pcVar16 = (char *)(a5 + (long)plVar18 * 3)[2];
        a3_00 = puVar7;
        if (pcVar16 != (char *)0x0) {
          a3_00 = (ulong *)0x0;
          puVar12 = a5 + (long)plVar18 * 3;
          do {
            while( true ) {
              if (iVar8 == (int)*puVar12) {
                pcVar15 = *(char **)(pcVar16 + 0x28);
                if (*(char **)(pcVar16 + 0x28) == (char *)0x0) {
                  pcVar15 = pcVar16;
                }
                pcVar16 = strdup(pcVar15);
                if (pcVar16 != (char *)0x0) goto LAB_001188a6;
                goto LAB_0011899f;
              }
              if ((ulong *)puVar12[1] < a3_00) goto LAB_001187d0;
              plVar18 = (long *)((long)plVar18 + 1);
              if (plVar21 != plVar18) break;
              plVar18 = (long *)0x0;
              a3_00 = (ulong *)((long)a3_00 + 1);
              pcVar16 = (char *)a5[2];
              puVar12 = a5;
              if (pcVar16 == (char *)0x0) goto LAB_001187d0;
            }
            a3_00 = (ulong *)((long)a3_00 + 1);
            puVar12 = a5 + (long)plVar18 * 3;
            pcVar16 = (char *)puVar12[2];
          } while (pcVar16 != (char *)0x0);
        }
LAB_001187d0:
        lVar24 = lVar24 + 1;
        iVar8 = piVar2[lVar24];
      }
      pcVar16 = *(char **)(Process_fields + (long)iVar8 * 0x20);
      pcVar16 = String_trim(pcVar16);
LAB_001188a6:
      iVar8 = piVar2[lVar24];
      puVar14 = malloc(0x18);
      if (puVar14 == (undefined8 *)0x0) break;
      *puVar14 = ListItem_class;
      (*(long * *)(__fp - 0x60)) = puVar14;
      pcVar15 = strdup(pcVar16);
      plVar6 = (*(long * *)(__fp - 0x60));
      if (pcVar15 == (char *)0x0) break;
      plVar4 = (long *)a0[4];
      (*(long * *)(__fp - 0x60))[1] = (long)pcVar15;
      lVar13 = plVar4[3];
      *(int *)((*(long * *)(__fp - 0x60)) + 2) = iVar8;
      *(undefined1 *)((long)(*(long * *)(__fp - 0x60)) + 0x14) = 0;
      Vector_set(plVar4,(int)lVar13,(long)plVar6,(long)a3_00,(long)plVar21,(long)a5);
      *(undefined1 *)(a0 + 9) = 1;
      a3_00 = (ulong *)(ulong)(uint)piVar2[lVar24];
      lVar13 = (*(long * *)(__fp - 0x68))[8];
      if (*(char *)(lVar13 + 0x34) == '\0') {
        uVar17 = *(uint *)(lVar13 + 0x2c);
      }
      else {
        uVar17 = 1;
        if (*(char *)(lVar13 + 0x35) == '\0') {
          uVar17 = *(uint *)(lVar13 + 0x30);
        }
      }
      if (piVar2[lVar24] == uVar17) {
        iVar8 = *(int *)(a0[4] + 0x18) + -1;
        if ((int)lVar24 < *(int *)(a0[4] + 0x18)) {
          iVar8 = (int)lVar24;
        }
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        *(int *)(a0 + 5) = iVar8;
        pcVar3 = *(code **)(*a0 + 0x20);
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)((long)a0,0xffffffff,0,(long)a3_00,(long)plVar21,(long)a5);
        }
      }
      lVar24 = lVar24 + 1;
      free(pcVar16);
      iVar8 = piVar2[lVar24];
      puVar5 = (*(ulong * *)(__fp - 0x80));
      plVar6 = (*(long * *)(__fp - 0x68));
      puVar7 = (*(ulong * *)(__fp - 0x70));
      plVar4 = (*(long * *)(__fp - 0x78));
    } while( true );
  }
LAB_0011899f:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001189d0 @ 0x1189d0 */

undefined8 FUN_001189d0(long *param_1)

{
  byte *pbVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;

  if (*(char *)(*(long *)(*(long *)*param_1 + 0x40) + 0x34) == '\0') {
    uVar4 = FUN_001185a0(param_1);
    return uVar4;
  }
  plVar2 = *(long **)(param_1[1] + 0x20);
  if ((0 < (int)plVar2[3]) &&
     (lVar3 = *(long *)(*plVar2 + (long)*(int *)(param_1[1] + 0x28) * 8), lVar3 != 0)) {
    pbVar1 = (byte *)(lVar3 + 0x20);
    *pbVar1 = *pbVar1 ^ 1;
    return 3;
  }
  return 0;
}


/* Header_reinit @ 0x120190 */

void Header_reinit(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                  long param_r9)

{
  byte bVar1;
  code *pcVar2;
  long *plVar3;
  ulong a3;
  long a2;
  long lVar4;
  ulong uVar5;

  bVar1 = (&DAT_00155fa0)[(long)(int)param_1[2] * 0x18];
  if ((ulong)bVar1 != 0) {
    a2 = *param_1;
    uVar5 = 0;
    do {
      plVar3 = *(long **)(a2 + uVar5 * 8);
      lVar4 = 0;
      a3 = (ulong)*(uint *)(plVar3 + 3);
      if (0 < (int)*(uint *)(plVar3 + 3)) {
        do {
          plVar3 = *(long **)(*plVar3 + lVar4 * 8);
          pcVar2 = *(code **)(*plVar3 + 0x20);
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)plVar3,param_rsi,a2,a3,param_r8,param_r9);
            a2 = *param_1;
          }
          plVar3 = *(long **)(a2 + uVar5 * 8);
          lVar4 = lVar4 + 1;
        } while ((int)lVar4 < (int)plVar3[3]);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != bVar1);
  }
  return;
}


/* Header_draw @ 0x120230 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Header_draw(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                long param_r9)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  byte bVar1;
  long *plVar2;
  long *a0;
  long lVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  int p1;
  uint uVar9;
  float fVar10;
  float fVar11;

  p1 = 0;
  lVar5 = param_1[3];
  uVar8 = *(uint *)((long)param_1 + 0x14);
  wattrset(_stdscr,*(int *)CRT_colors);
  if (0 < (int)lVar5) {
    do {
      iVar4 = wmove(_stdscr,p1,0);
      if (iVar4 != -1) {
        whline(_stdscr,0x20,_COLS);
      }
      p1 = p1 + 1;
    } while ((int)lVar5 != p1);
  }
  lVar5 = (long)(int)param_1[2];
  bVar1 = (&DAT_00155fa0)[lVar5 * 0x18];
  if ((ulong)bVar1 != 0) {
    (*(ulong *)(__fp - 0x48)) = 0;
    (*(float *)(__fp - 0x54)) = 0.0;
    uVar6 = (int)uVar8 / 2;
    fVar11 = (float)(int)((_COLS + uVar8 * -2) - (bVar1 - 1));
    while( true ) {
      plVar2 = *(long **)(*param_1 + (*(ulong *)(__fp - 0x48)) * 8);
      (*(float *)(__fp - 0x3c)) = ((float)(byte)(&UNK_00155fa1)[(*(ulong *)(__fp - 0x48)) + lVar5 * 0x18] * fVar11) / 100.0;
      fVar10 = (*(float *)(__fp - 0x3c));
      if (ABS((*(float *)(__fp - 0x3c))) < 8388608.0) {
        fVar10 = __builtin_floorf((*(float *)(__fp - 0x3c)));
      }
      (*(float *)(__fp - 0x54)) = ((*(float *)(__fp - 0x3c)) - fVar10) + (*(float *)(__fp - 0x54));
      if (1.0 <= (*(float *)(__fp - 0x54))) {
        (*(float *)(__fp - 0x54)) = (*(float *)(__fp - 0x54)) - 1.0;
        (*(float *)(__fp - 0x3c)) = (*(float *)(__fp - 0x3c)) + 1.0;
      }
      lVar5 = 0;
      uVar9 = uVar6;
      if (0 < (int)plVar2[3]) {
        do {
          a0 = *(long **)(*plVar2 + lVar5 * 8);
          fVar10 = (*(float *)(__fp - 0x3c));
          if ((((int)a0[4] == 2) && (*(char *)(*a0 + 0x91) == '\0')) &&
             (1 < *(int *)((long)a0 + 0x4c))) {
            lVar7 = 1;
            do {
              lVar3 = lVar7 + (*(ulong *)(__fp - 0x48)) + (long)(int)param_1[2] * 0x18;
              lVar7 = lVar7 + 1;
              fVar10 = fVar10 + 1.0 + ((float)(byte)(&UNK_00155fa1)[lVar3] * fVar11) / 100.0;
            } while ((int)lVar7 < *(int *)((long)a0 + 0x4c));
          }
          if (ABS(fVar10) < 8388608.0) {
            fVar10 = __builtin_floorf(fVar10);
          }
          (*(code *)a0[1])((long)a0,(ulong)uVar8,(ulong)uVar9,(ulong)(uint)(int)fVar10,param_r8,
                           param_r9);
          lVar5 = lVar5 + 1;
          uVar9 = uVar9 + (int)a0[9];
        } while ((int)lVar5 < (int)plVar2[3]);
      }
      if (ABS((*(float *)(__fp - 0x3c))) < 8388608.0) {
        (*(float *)(__fp - 0x3c)) = __builtin_floorf((*(float *)(__fp - 0x3c)));
      }
      (*(ulong *)(__fp - 0x48)) = (*(ulong *)(__fp - 0x48)) + 1;
      uVar8 = (int)((float)(int)uVar8 + (*(float *)(__fp - 0x3c))) + 1;
      if (bVar1 <= (*(ulong *)(__fp - 0x48))) break;
      lVar5 = (long)(int)param_1[2];
    }
  }
  return;
}


/* Header_updateData @ 0x120590 */

void Header_updateData(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                      long param_r9)

{
  byte bVar1;
  int iVar2;
  long *plVar3;
  long *a0;
  long extraout_RDX;
  long a2;
  long lVar4;
  ulong uVar5;

  a2 = (long)(int)param_1[2] * 3;
  bVar1 = (&DAT_00155fa0)[(long)(int)param_1[2] * 0x18];
  if ((ulong)bVar1 != 0) {
    uVar5 = 0;
    do {
      plVar3 = *(long **)(*param_1 + uVar5 * 8);
      iVar2 = (int)plVar3[3];
      if (0 < iVar2) {
        lVar4 = 0;
        do {
          a0 = *(long **)(*plVar3 + lVar4);
          lVar4 = lVar4 + 8;
          (**(code **)(*a0 + 0x38))((long)a0,param_rsi,a2,param_rcx,param_r8,param_r9);
          a2 = extraout_RDX;
        } while ((long)iVar2 * 8 != lVar4);
      }
      uVar5 = uVar5 + 1;
    } while (bVar1 != uVar5);
  }
  return;
}


/* Header_calculateHeight @ 0x120620 */

int Header_calculateHeight(long *param_1)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long *plVar1;
  long *plVar2;
  byte bVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  int iVar8;
  long *plVar9;
  long *plVar10;
  int iVar11;
  long *plVar12;
  ulong uVar13;
  int iVar14;
  int iVar15;
  ulong uVar16;

  lVar4 = *(long *)param_1[1];
  bVar3 = *(byte *)(lVar4 + 0x6d);
  (*(int *)(__fp - 0x50)) = (uint)bVar3 + (uint)bVar3;
  bVar3 = (&DAT_00155fa0)[(long)(int)param_1[2] * 0x18];
  uVar16 = (ulong)bVar3;
  if (uVar16 != 0) {
    lVar5 = *param_1;
    uVar13 = 0;
    iVar8 = (*(int *)(__fp - 0x50));
    do {
      plVar10 = *(long **)(lVar5 + uVar13 * 8);
      iVar14 = (int)plVar10[3];
      iVar15 = (*(int *)(__fp - 0x50));
      if (0 < iVar14) {
        plVar10 = (long *)*plVar10;
        iVar6 = (int)uVar13;
        plVar1 = plVar10 + iVar14;
        iVar14 = (*(int *)(__fp - 0x50));
        do {
          iVar15 = *(int *)(*plVar10 + 0x48) + iVar14;
          for (uVar7 = (ulong)(iVar6 + 1); iVar11 = (uint)bVar3 - iVar6, uVar7 < uVar16;
              uVar7 = uVar7 + 1) {
            plVar9 = *(long **)(lVar5 + uVar7 * 8);
            iVar11 = (int)plVar9[3];
            if (0 < iVar11) {
              plVar9 = (long *)*plVar9;
              plVar2 = plVar9 + iVar11;
              iVar11 = (*(int *)(__fp - 0x50));
              do {
                if (iVar15 <= iVar11) break;
                iVar11 = iVar11 + (int)((long *)*plVar9)[9];
                if (iVar14 < iVar11) {
                  plVar12 = *(long **)*plVar9;
                  if (plVar12 == (long *)0x0) {
LAB_00120735:
                    iVar11 = (int)uVar7 - iVar6;
                    goto LAB_0012073e;
                  }
                  if (plVar12 != (long *)BlankMeter_class) {
                    do {
                      plVar12 = (long *)*plVar12;
                      if (plVar12 == (long *)0x0) goto LAB_00120735;
                    } while (plVar12 != (long *)BlankMeter_class);
                  }
                }
                plVar9 = plVar9 + 1;
              } while (plVar2 != plVar9);
            }
          }
LAB_0012073e:
          *(int *)(*plVar10 + 0x4c) = iVar11;
          plVar10 = plVar10 + 1;
          iVar14 = iVar15;
        } while (plVar1 != plVar10);
      }
      if (iVar8 < iVar15) {
        iVar8 = iVar15;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != uVar16);
    if (iVar8 != (*(int *)(__fp - 0x50))) goto LAB_00120780;
  }
  (*(int *)(__fp - 0x50)) = 0;
  iVar8 = 0;
LAB_00120780:
  iVar8 = (iVar8 + 1) - (uint)(*(char *)(lVar4 + 0x6e) == '\0');
  *(int *)((long)param_1 + 0x14) = (*(int *)(__fp - 0x50));
  *(int *)(param_1 + 3) = iVar8;
  return iVar8;
}


/* Header_delete @ 0x123070 */

void Header_delete(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                  long param_r9)

{
  long lVar1;
  byte bVar2;
  long lVar3;
  long extraout_RDX;
  ulong uVar4;

  lVar3 = (long)(int)param_1[2] * 3;
  bVar2 = (&DAT_00155fa0)[(long)(int)param_1[2] * 0x18];
  if ((ulong)bVar2 != 0) {
    uVar4 = 0;
    do {
      lVar1 = uVar4 * 8;
      uVar4 = uVar4 + 1;
      Vector_delete(*(long **)(*param_1 + lVar1),param_rsi,lVar3,param_rcx,param_r8,param_r9);
      lVar3 = extraout_RDX;
    } while (uVar4 != bVar2);
  }
  free((void *)*param_1);
  free(param_1);
  return;
}


/* Header_setLayout @ 0x1230e0 */

void Header_setLayout(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                     long param_r9)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  size_t __size;
  uint uVar1;
  long lVar2;
  void *pvVar3;
  void *pvVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long extraout_RDX;
  long extraout_RDX_00;
  undefined4 in_register_00000034;
  ulong uVar7;
  long *plVar8;
  size_t sVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;

  uVar7 = CONCAT44(in_register_00000034,param_2);
  lVar2 = param_1[2];
  *(int *)(param_1 + 2) = param_2;
  (*(ulong *)(__fp - 0x40)) = (ulong)(byte)(&DAT_00155fa0)[(long)(int)lVar2 * 0x18];
  lVar2 = (long)param_2 * 3;
  uVar10 = (ulong)(byte)(&DAT_00155fa0)[(long)param_2 * 0x18];
  if (uVar10 == (*(ulong *)(__fp - 0x40))) {
    return;
  }
  __size = uVar10 * 8;
  pvVar4 = (void *)*param_1;
  if ((*(ulong *)(__fp - 0x40)) < uVar10) {
    pvVar3 = realloc(pvVar4,__size);
    if (pvVar3 == (void *)0x0) {
      free(pvVar4);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *param_1 = (long)pvVar3;
    do {
      puVar5 = malloc(0x28);
      if (puVar5 == (undefined8 *)0x0) goto LAB_00123275;
      *(undefined4 *)((long)puVar5 + 0x14) = 10;
      pvVar4 = calloc(10,8);
      if (pvVar4 == (void *)0x0) goto LAB_00123275;
      *puVar5 = pvVar4;
      *(undefined4 *)(puVar5 + 2) = 10;
      puVar5[1] = Meter_class;
      *(undefined1 *)((long)puVar5 + 0x24) = 1;
      puVar5[3] = 0xffffffff00000000;
      *(undefined4 *)(puVar5 + 4) = 0;
      *(undefined8 **)((long)pvVar3 + (*(ulong *)(__fp - 0x40)) * 8) = puVar5;
      (*(ulong *)(__fp - 0x40)) = (*(ulong *)(__fp - 0x40)) + 1;
    } while ((*(ulong *)(__fp - 0x40)) < uVar10);
  }
  else {
    uVar6 = (*(ulong *)(__fp - 0x40));
    sVar9 = __size;
    while( true ) {
      plVar8 = *(long **)(*param_1 + sVar9);
      iVar11 = (int)plVar8[3] + -1;
      if (-1 < iVar11) {
        do {
          iVar12 = iVar11 + -1;
          lVar2 = Vector_take(plVar8,iVar11);
          plVar8 = *(long **)(*param_1 + (__size - 8));
          uVar1 = *(uint *)(plVar8 + 3);
          uVar7 = (ulong)uVar1;
          Vector_set(plVar8,uVar1,lVar2,uVar6,param_r8,param_r9);
          plVar8 = *(long **)(*param_1 + sVar9);
          lVar2 = extraout_RDX;
          iVar11 = iVar12;
        } while (iVar12 != -1);
      }
      Vector_delete(plVar8,uVar7,lVar2,uVar6,param_r8,param_r9);
      uVar10 = uVar10 + 1;
      if ((*(ulong *)(__fp - 0x40)) <= uVar10) break;
      sVar9 = uVar10 * 8;
      lVar2 = extraout_RDX_00;
    }
    pvVar4 = (void *)*param_1;
    pvVar3 = realloc(pvVar4,__size);
    if (pvVar3 == (void *)0x0) {
      free(pvVar4);
LAB_00123275:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *param_1 = (long)pvVar3;
  }
  Header_calculateHeight(param_1);
  return;
}


/* Header_addMeterByClass @ 0x123600 */

long * Header_addMeterByClass
                 (long *param_1,long param_2,undefined4 param_3,uint param_4,long param_r8,
                 long param_r9)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;

  uVar3 = (ulong)param_4;
  plVar1 = *(long **)(*param_1 + uVar3 * 8);
  plVar2 = Meter_new(param_1[1],param_3,param_2,uVar3,param_r8,param_r9);
  Vector_set(plVar1,(int)plVar1[3],(long)plVar2,uVar3,param_r8,param_r9);
  return plVar2;
}


/* FUN_00123640 @ 0x123640 */

void FUN_00123640(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  undefined1 (*pauVar4) [16];
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;

  pauVar4 = *(undefined1 (**) [16])(param_1 + 0x170);
  if (pauVar4 == (undefined1 (*) [16])0x0) {
    pauVar4 = malloc(0x10);
    if (pauVar4 == (undefined1 (*) [16])0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(undefined1 (**) [16])(param_1 + 0x170) = pauVar4;
    *(undefined16 *)(*pauVar4) = (undefined16)0x0;
  }
  else if (*(long *)*pauVar4 != 0) goto LAB_00123668;
  param_rsi = 0;
  plVar3 = Meter_new(*(long *)(param_1 + 0x10),0,(long)&MemoryMeter_class,param_rcx,param_r8,param_r9);
  *(long **)*pauVar4 = plVar3;
  param_rdx = extraout_RDX_01;
LAB_00123668:
  if (*(long *)(*pauVar4 + 8) == 0) {
    param_rsi = 0;
    plVar3 = Meter_new(*(long *)(param_1 + 0x10),0,(long)&SwapMeter_class,param_rcx,param_r8,param_r9);
    *(long **)(*pauVar4 + 8) = plVar3;
    param_rdx = extraout_RDX_00;
  }
  pcVar1 = *(code **)(**(long **)*pauVar4 + 0x20);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)((long)*(long **)*pauVar4,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
    param_rdx = extraout_RDX;
  }
  plVar3 = *(long **)(*pauVar4 + 8);
  if (*(code **)(*plVar3 + 0x20) != (code *)0x0) {
    (**(code **)(*plVar3 + 0x20))((long)plVar3,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
    plVar3 = *(long **)(*pauVar4 + 8);
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  iVar2 = *(int *)(*(long *)(Meter_modes + (long)*(int *)(*(long *)*pauVar4 + 0x20) * 8) + 0x10);
  if (*(int *)(*(long *)(Meter_modes + (long)*(int *)(*(long *)*pauVar4 + 0x20) * 8) + 0x10) <
      *(int *)(*(long *)(Meter_modes + (long)(int)plVar3[4] * 8) + 0x10)) {
    iVar2 = *(int *)(*(long *)(Meter_modes + (long)(int)plVar3[4] * 8) + 0x10);
  }
  *(int *)(param_1 + 0x48) = iVar2;
  return;
}


/* Header_populateFromSettings @ 0x126560 */

void Header_populateFromSettings
               (long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  ulong *puVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  char *__s;
  long *plVar7;
  bool bVar8;
  int iVar9;
  char *pcVar10;
  long *plVar11;
  char *pcVar12;
  ulong uVar13;
  long extraout_RDX;
  size_t __n;
  char *__s2;
  uint uVar14;
  undefined1 *puVar15;
  ulong uVar16;
  uint *puVar17;
  undefined1 *puVar18;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *(long *)param_1[1];
  uVar14 = *(uint *)(lVar5 + 0xc);
  __s2 = (char *)(ulong)uVar14;
  Header_setLayout(param_1,uVar14,param_rdx,param_rcx,param_r8,param_r9);
  bVar3 = (&DAT_00155fa0)[(long)(int)param_1[2] * 0x18];
  if ((ulong)bVar3 != 0) {
    uVar16 = 0;
    do {
      lVar6 = *(long *)(lVar5 + 0x10);
      puVar1 = (ulong *)(lVar6 + uVar16 * 0x18);
      Vector_prune(*(long **)(*param_1 + uVar16 * 8),(long)__s2,lVar6,param_rcx,param_r8,param_r9);
      param_rcx = (long)(ulong *)0x0;
      param_r8 = (long)&(*(uint *)(__fp - 0x6c));
      if (*puVar1 != 0) {
        (*(ulong *)(__fp - 0x80)) = 0;
        do {
          iVar4 = *(int *)(puVar1[2] + (*(ulong *)(__fp - 0x80)) * 4);
          __s = *(char **)(puVar1[1] + (*(ulong *)(__fp - 0x80)) * 8);
          plVar7 = *(long **)(*param_1 + uVar16 * 8);
          uVar13 = uVar16 * 8;
          pcVar10 = strchr(__s,0x28);
          (*(uint *)(__fp - 0x6c)) = 0;
          if (pcVar10 == (char *)0x0) {
            __n = strlen(__s);
LAB_001266af:
            puVar15 = Platform_meterTypes;
            puVar18 = CPUMeter_class;
            pcVar10 = ((char *)(long)(__sec_rodata + 0x826) /* "CPU" */);
            while ((__s2 = pcVar10, iVar9 = strncmp(__s,pcVar10,__n), iVar9 != 0 ||
                   (pcVar10[__n] != '\0'))) {
              puVar18 = *(undefined1 **)(puVar15 + 8);
              puVar15 = puVar15 + 8;
              if (puVar18 == (undefined1 *)0x0) goto LAB_001266fe;
              pcVar10 = *(char **)(puVar18 + 0x70);
            }
            plVar11 = Meter_new(param_1[1],(*(uint *)(__fp - 0x6c)),(long)puVar18,uVar13,param_r8,param_r9);
            if (iVar4 != 0) {
              Meter_setMode(plVar11,iVar4,extraout_RDX,uVar13,param_r8,param_r9);
            }
            uVar14 = *(uint *)(plVar7 + 3);
            __s2 = (char *)(ulong)uVar14;
            Vector_set(plVar7,uVar14,(long)plVar11,uVar13,param_r8,param_r9);
          }
          else {
            iVar9 = __isoc23_sscanf(pcVar10,((char *)(long)&s___10u__00148819 /* "(%10u)" */),&(*(uint *)(__fp - 0x6c)));
            if (iVar9 != 0) {
LAB_001266a9:
              __n = (long)pcVar10 - (long)__s;
              goto LAB_001266af;
            }
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x68)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x58)), (undefined16)0x0);
            iVar9 = __isoc23_sscanf(pcVar10,((char *)(long)(__sec_rodata + 0x1c03) /* "(%30s)" */),(*(undefined1 (*)[16])(__fp - 0x68)));
            if (iVar9 == 0) {
              (*(uint *)(__fp - 0x6c)) = 0;
              goto LAB_001266a9;
            }
            __s2 = (char *)0x29;
            pcVar12 = strrchr((*(undefined1 (*)[16])(__fp - 0x68)),0x29);
            if (pcVar12 != (char *)0x0) {
              *pcVar12 = '\0';
              plVar11 = *(long **)(*(long *)param_1[1] + 0x20);
              if (plVar11 != (long *)0x0) {
                __s2 = (char *)0x0;
                if (*plVar11 != 0) {
                  puVar17 = (uint *)plVar11[1];
                  uVar14 = 0;
                  puVar2 = puVar17 + *plVar11 * 6;
                  bVar8 = false;
                  do {
                    __s2 = *(char **)(puVar17 + 4);
                    if ((__s2 != (char *)0x0) && (iVar9 = strcmp((*(undefined1 (*)[16])(__fp - 0x68)),__s2), iVar9 == 0)) {
                      uVar14 = *puVar17;
                      bVar8 = true;
                    }
                    puVar17 = puVar17 + 6;
                  } while (puVar2 != puVar17);
                  uVar13 = (ulong)uVar14;
                  (*(uint *)(__fp - 0x6c)) = uVar14;
                  if (bVar8) goto LAB_001266a9;
                }
              }
            }
          }
LAB_001266fe:
          (*(ulong *)(__fp - 0x80)) = (*(ulong *)(__fp - 0x80)) + 1;
          param_rcx = (long)puVar1;
        } while ((*(ulong *)(__fp - 0x80)) < *puVar1);
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 != bVar3);
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  Header_calculateHeight(param_1);
  return;
}


/* Header_writeBackToSettings @ 0x126910 */

void Header_writeBackToSettings(long *param_1)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  ulong *puVar1;
  int iVar2;
  uint va1;
  long lVar3;
  long *plVar4;
  long *plVar5;
  undefined1 *puVar6;
  uint *puVar7;
  ulong uVar8;
  void *pvVar9;
  uint *puVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = *(long *)param_1[1];
  Settings_setHeaderLayout(lVar3,(int)param_1[2]);
  uVar8 = (ulong)(byte)(&DAT_00155fa0)[(long)(int)param_1[2] * 0x18];
  if (uVar8 != 0) {
    uVar15 = 0;
    do {
      while( true ) {
        puVar1 = (ulong *)(*(long *)(lVar3 + 0x10) + uVar15 * 0x18);
        pvVar9 = (void *)puVar1[1];
        if (pvVar9 != (void *)0x0) {
          if (*puVar1 != 0) {
            uVar12 = 0;
            do {
              lVar13 = uVar12 * 8;
              uVar12 = uVar12 + 1;
              free(*(void **)((long)pvVar9 + lVar13));
              pvVar9 = (void *)puVar1[1];
            } while (uVar12 < *puVar1);
          }
          free(pvVar9);
        }
        free((void *)puVar1[2]);
        plVar4 = *(long **)(*param_1 + uVar15 * 8);
        iVar2 = (int)plVar4[3];
        if (iVar2 != 0) break;
        *puVar1 = 0;
        uVar15 = uVar15 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(puVar1 + 1)) = (undefined16)0x0;
        if (uVar8 == uVar15) goto LAB_00126b00;
      }
      if ((0x1fffffffffffffff < (ulong)(long)(iVar2 + 1)) ||
         (pvVar9 = calloc((long)(iVar2 + 1),8), pvVar9 == (void *)0x0)) {
LAB_00126be5:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      puVar1[1] = (ulong)pvVar9;
      uVar12 = (ulong)iVar2;
      if ((0x3fffffffffffffff < uVar12) || (pvVar9 = calloc(uVar12,4), pvVar9 == (void *)0x0))
      goto LAB_00126be5;
      puVar1[2] = (ulong)pvVar9;
      *puVar1 = uVar12;
      lVar13 = 0;
      do {
        plVar5 = *(long **)(*plVar4 + lVar13 * 8);
        va1 = *(uint *)((long)plVar5 + 0x24);
        puVar6 = (undefined1 *)*plVar5;
        if (va1 == 0) {
LAB_00126ab3:
          xAsprintf(&(*(char * *)(__fp - 0x48)),((char *)(long)(__sec_rodata + 0x626) /* "%s" */),*(void **)(puVar6 + 0x70));
        }
        else if (puVar6 == DynamicMeter_class) {
          uVar12 = **(ulong **)(lVar3 + 0x20);
          puVar7 = (uint *)(*(ulong **)(lVar3 + 0x20))[1];
          uVar11 = (ulong)va1 % uVar12;
          pvVar9 = *(void **)(puVar7 + uVar11 * 6 + 4);
          if (pvVar9 != (void *)0x0) {
            uVar14 = 0;
            puVar10 = puVar7 + uVar11 * 6;
            do {
              while( true ) {
                if (va1 == *puVar10) goto LAB_00126bb8;
                if (*(ulong *)(puVar10 + 2) < uVar14) {
                  pvVar9 = (void *)0x0;
                  goto LAB_00126bb8;
                }
                uVar11 = uVar11 + 1;
                if (uVar12 != uVar11) break;
                uVar11 = 0;
                uVar14 = uVar14 + 1;
                pvVar9 = *(void **)(puVar7 + 4);
                puVar10 = puVar7;
                if (pvVar9 == (void *)0x0) goto LAB_00126bb8;
              }
              uVar14 = uVar14 + 1;
              puVar10 = puVar7 + uVar11 * 6;
              pvVar9 = *(void **)(puVar10 + 4);
            } while (pvVar9 != (void *)0x0);
          }
LAB_00126bb8:
          xAsprintf(&(*(char * *)(__fp - 0x48)),((char *)(long)&s__s__s__00148820 /* "%s(%s)" */),((char *)(long)&s_Dynamic_00147e36 /* "Dynamic" */),pvVar9);
        }
        else {
          if (puVar6 != CPUMeter_class) goto LAB_00126ab3;
          xAsprintf(&(*(char * *)(__fp - 0x48)),((char *)(long)&s__s__u__00148827 /* "%s(%u)" */),((char *)(long)(__sec_rodata + 0x826) /* "CPU" */),va1);
        }
        *(char **)(puVar1[1] + lVar13 * 8) = (*(char * *)(__fp - 0x48));
        *(int *)(puVar1[2] + lVar13 * 4) = (int)plVar5[4];
        lVar13 = lVar13 + 1;
      } while ((int)lVar13 < iVar2);
      uVar15 = uVar15 + 1;
    } while (uVar8 != uVar15);
  }
LAB_00126b00:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

