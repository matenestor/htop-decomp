#include "htop.h"

/* ListItem_delete @ 0x11fe00 */

void ListItem_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 8));
  free(param_1);
  return;
}


/* ListItem_compare @ 0x11ff00 */

void ListItem_compare(long param_1,long param_2)

{
  strcmp(*(char **)(param_1 + 8),*(char **)(param_2 + 8));
  return;
}


/* FUN_0011ff20 @ 0x11ff20 */

void FUN_0011ff20(long param_1,int *param_2)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  long lVar1;
  uint uVar2;
  wint_t __wc;
  char *__s;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 (*pauVar9) [16];
  undefined1 *puVar10;
  long lVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar11;

  puVar10 = (*(undefined1 (*)[12])(__fp - 0x58));
  __s = *(char **)(param_1 + 8);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = *(uint *)(CRT_colors + 0x11c);
  sVar6 = strlen(__s);
  iVar5 = *param_2;
  uVar8 = (ulong)((int)sVar6 + 1);
  uVar7 = uVar8 * 4 + 0xf;
  puVar11 = (*(undefined1 (*)[12])(__fp - 0x58));
  puVar4 = (*(undefined1 (*)[12])(__fp - 0x58));
  while (puVar11 != (*(undefined1 (*)[12])(__fp - 0x58)) + -(uVar7 & 0xfffffffffffff000)) {
    puVar10 = puVar4 + -0x1000;
    *(undefined8 *)(puVar4 + -8) = *(undefined8 *)(puVar4 + -8);
    puVar11 = puVar4 + -0x1000;
    puVar4 = puVar4 + -0x1000;
  }
  uVar7 = (ulong)((uint)uVar7 & 0xff0);
  lVar3 = -uVar7;
  if (uVar7 != 0) {
    *(undefined8 *)(puVar10 + -8) = *(undefined8 *)(puVar10 + -8);
  }
  uVar7 = __mbstowcs_chk((int *)(puVar10 + lVar3),__s,(long)(int)sVar6,uVar8 & 0x3fffffffffffffff);
  if (0 < (int)uVar7) {
    (*(int *)(__fp - 0x4c)) = iVar5 + (int)uVar7;
    lVar12 = (long)iVar5;
    FUN_00130130(param_2,(*(int *)(__fp - 0x4c)));
    lVar1 = lVar12 * -4;
    pauVar9 = (undefined1 (*) [16])(*(long *)(param_2 + 2) + lVar12 * 0x1c);
    do {
      __wc = *(wint_t *)(puVar10 + lVar12 * 4 + lVar1 + lVar3);
      iVar5 = iswprint(__wc);
      *(undefined16 *)(*pauVar9) = (undefined16)0x0;
      if (iVar5 == 0) {
        __wc = 0xfffd;
      }
      *(uint *)*pauVar9 = uVar2 & 0xffffff;
      lVar12 = lVar12 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar9 + 0xc)) = (undefined16)0x0;
      *(wint_t *)(*pauVar9 + 4) = __wc;
      pauVar9 = (undefined1 (*) [16])(pauVar9[1] + 0xc);
    } while ((int)lVar12 < (*(int *)(__fp - 0x4c)));
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_00120080 @ 0x120080 */

void FUN_00120080(long param_1)

{
  gethostname((char *)(param_1 + 0x60),0xff);
  *(undefined1 *)(param_1 + 0x15f) = 0;
  return;
}


/* FUN_001200d0 @ 0x1200d0 */

void FUN_001200d0(long param_1)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long *plVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar5;

  bVar5 = false;
  plVar1 = *(long **)(param_1 + 0x20);
  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(byte *)(*(long *)(*plVar1 + 0x40) + 0x22) & 8) != 0) {
    iVar2 = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
    if (iVar2 < 0) {
      piVar4 = __errno_location();
      lVar3 = (long)-*piVar4;
    }
    else {
      lVar3 = FUN_0013a450(iVar2,(*(char (*)[24])(__fp - 0x38)),0x10);
    }
    bVar5 = false;
    if (-1 < lVar3) {
      bVar5 = (*(char (*)[24])(__fp - 0x38))[0] == '1';
    }
  }
  *(bool *)(param_1 + 0x61) = bVar5;
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_00144c10(param_1,-100,plVar1,((char *)(long)&s__proc_00149a78 /* "/proc" */),0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ListItem_display @ 0x121640 */

void ListItem_display(long param_1,int *param_2)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  uint uVar1;
  wint_t __wc;
  long lVar2;
  int *piVar3;
  int iVar4;
  ulong uVar5;
  undefined1 **ppuVar6;
  undefined1 **ppuVar7;
  char *pcVar9;
  undefined1 (*pauVar10) [16];
  wint_t *pwVar11;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 **ppuVar8;

  ppuVar7 = &(*(undefined1 * *)(__fp - 0x68));
  ppuVar6 = &(*(undefined1 * *)(__fp - 0x68));
  ppuVar8 = &(*(undefined1 * *)(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(int * *)(__fp - 0x60)) = param_2;
  if (*(char *)(param_1 + 0x14) != '\0') {
    pcVar9 = ((char *)(long)&DAT_0014837b /* "+ " */);
    if (CRT_utf8 != '\0') {
      pcVar9 = &DAT_00148769;
    }
    uVar5 = (-(ulong)(CRT_utf8 == '\0') & 0xfffffffffffffff8) + 0x23;
    uVar1 = *(uint *)(CRT_colors + 4);
    ppuVar6 = &(*(undefined1 * *)(__fp - 0x68));
    while (ppuVar8 != (undefined1 **)((long)&(*(undefined1 * *)(__fp - 0x68)) - (uVar5 & 0xfffffffffffff000))) {
      ppuVar7 = (undefined1 **)((long)ppuVar6 + -0x1000);
      *(undefined8 *)((long)ppuVar6 + -8) = *(undefined8 *)((long)ppuVar6 + -8);
      ppuVar8 = (undefined1 **)((long)ppuVar6 + -0x1000);
      ppuVar6 = (undefined1 **)((long)ppuVar6 + -0x1000);
    }
    uVar5 = (ulong)((uint)uVar5 & 0xff0);
    lVar2 = -uVar5;
    pwVar11 = (wint_t *)((long)ppuVar7 + lVar2);
    if (uVar5 != 0) {
      *(undefined8 *)((long)ppuVar7 + -8) = *(undefined8 *)((long)ppuVar7 + -8);
    }
    (*(undefined1 * *)(__fp - 0x68)) = (undefined1 *)&(*(undefined1 * *)(__fp - 0x68));
    uVar5 = __mbstowcs_chk((int *)((long)ppuVar7 + lVar2),pcVar9,
                           (-(ulong)(CRT_utf8 == '\0') & 0xfffffffffffffffe) + 4,
                           (-(ulong)(CRT_utf8 == '\0') & 0xfffffffffffffffe) + 5);
    iVar4 = (int)uVar5;
    ppuVar6 = (undefined1 **)(*(undefined1 * *)(__fp - 0x68));
    if (0 < iVar4) {
      FUN_00130130((*(int * *)(__fp - 0x60)),iVar4);
      (*(wint_t * *)(__fp - 0x50)) = (wint_t *)((long)ppuVar7 + (ulong)(iVar4 - 1) * 4 + lVar2 + 4);
      pauVar10 = *(undefined1 (**) [16])((*(int * *)(__fp - 0x60)) + 2);
      (*(uint *)(__fp - 0x54)) = uVar1 & 0xffffff;
      do {
        __wc = *pwVar11;
        iVar4 = iswprint(__wc);
        *(undefined16 *)(*pauVar10) = (undefined16)0x0;
        if (iVar4 == 0) {
          __wc = 0xfffd;
        }
        pwVar11 = pwVar11 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar10 + 0xc)) = (undefined16)0x0;
        *(uint *)*pauVar10 = (*(uint *)(__fp - 0x54));
        *(wint_t *)(*pauVar10 + 4) = __wc;
        ppuVar6 = (undefined1 **)(*(undefined1 * *)(__fp - 0x68));
        pauVar10 = (undefined1 (*) [16])(pauVar10[1] + 0xc);
      } while ((*(wint_t * *)(__fp - 0x50)) != pwVar11);
    }
  }
  piVar3 = (*(int * *)(__fp - 0x60));
  pcVar9 = *(char **)(param_1 + 8);
  uVar1 = *(uint *)(CRT_colors + 4);
  RichString_appendWide(piVar3,uVar1,pcVar9);
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001217e0 @ 0x1217e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001217e0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  undefined1 __frame[0x2778] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2738;
  undefined1 (*pauVar1) [16];
  undefined1 (*pauVar2) [16];
  undefined4 *puVar3;
  double dVar4;
  byte bVar5;
  char cVar6;
  undefined4 uVar7;
  double *pdVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char *p1;
  undefined1 (*pauVar14) [16];
  undefined1 (*pauVar15) [16];
  undefined1 (*pauVar16) [16];
  long lVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined4 in_register_0000000c;
  ulong uVar20;
  int iVar21;
  int iVar22;
  undefined4 in_register_00000014;
  undefined4 in_register_00000034;
  int iVar23;
  long lVar24;
  int iVar25;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar26;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*param_1 + 0x48) == (code *)0x0) {
    p1 = (char *)param_1[3];
  }
  else {
    p1 = (char *)(**(code **)(*param_1 + 0x48))
                           ((long)param_1,CONCAT44(in_register_00000034,param_2),
                            CONCAT44(in_register_00000014,param_3),
                            CONCAT44(in_register_0000000c,param_4),param_r8,param_r9);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0x38));
  iVar10 = wmove(_stdscr,param_3,param_2);
  if (iVar10 != -1) {
    waddnstr(_stdscr,p1,3);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0xbc));
  iVar10 = wmove(_stdscr,param_3,param_2 + 3);
  if (iVar10 != -1) {
    waddch(_stdscr,0x5b);
  }
  iVar10 = param_4 + -4;
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  iVar10 = wmove(_stdscr,param_3,iVar10 + param_2 + 3);
  if (iVar10 != -1) {
    waddch(_stdscr,0x5d);
  }
  iVar10 = param_4 + -5;
  wattrset(_stdscr,*(int *)CRT_colors);
  if (iVar10 < 1) goto LAB_00121d4d;
  (*(int (*)[2])(__fp - 0x26b8))[0] = 0;
  ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x26a8)), SUB1612((undefined16)0x0,0));
  (*(undefined4 *)(__fp - 0x269c)) = 0;
  ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x2698)), SUB1612((undefined16)0x0,4));
  (*(undefined4 *)(__fp - 0x44)) = 0;
  (*(undefined1 (**)[16])(__fp - 0x26b0)) = (undefined1 (*) [16])(*(undefined1 (*)[12])(__fp - 0x26a8));
  FUN_00130130((*(int (*)[2])(__fp - 0x26b8)),iVar10);
  pauVar14 = (*(undefined1 (**)[16])(__fp - 0x26b0));
  pauVar15 = (undefined1 (*) [16])((*(undefined1 (**)[16])(__fp - 0x26b0))[1] + 0xc);
  while( true ) {
    *(undefined16 *)(*pauVar14) = (undefined16)0x0;
    *(undefined4 *)(*pauVar14 + 4) = 0x20;
    *(undefined16 *)(*(undefined1 (*) [16])(*pauVar14 + 0xc)) = (undefined16)0x0;
    if (pauVar15 == (undefined1 (*) [16])((long)((*(undefined1 (**)[16])(__fp - 0x26b0))[1] + 0xc) + (ulong)(param_4 - 6) * 0x1c)
       ) break;
    pauVar14 = pauVar15;
    pauVar15 = (undefined1 (*) [16])(pauVar15[1] + 0xc);
  }
  RichString_appendWide((*(int (*)[2])(__fp - 0x26b8)),0,(char *)(param_1 + 0xc));
  pauVar14 = (*(undefined1 (**)[16])(__fp - 0x26b0));
  iVar25 = CRT_colorScheme;
  (*(int *)(__fp - 0x26f0)) = (*(int (*)[2])(__fp - 0x26b8))[0] - iVar10;
  if (iVar10 < (*(int *)(__fp - 0x26f0))) {
    iVar13 = iVar10 * 2;
    if (SBORROW4(iVar10,iVar13) != -iVar10 < 0) {
      lVar24 = (long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + (long)param_4 * 0x38;
      do {
        if (*(int *)(lVar24 + -0x114) == 0x20) {
          if (iVar13 <= iVar10) goto LAB_00121df2;
          lVar24 = (long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + (long)iVar13 * 0x1c;
          goto LAB_00121dec;
        }
        iVar13 = iVar13 + -1;
        lVar24 = lVar24 + -0x1c;
      } while (iVar10 != iVar13);
    }
    goto LAB_00121dfb;
  }
  goto LAB_001219d7;
LAB_00121bd0:
  do {
    lVar17 = param_1[0xb];
    if (lVar17 == 0) {
      lVar17 = *(long *)(*param_1 + 0x68);
    }
    iVar21 = (*(int (*)[12])(__fp - 0x26e8))[lVar24];
    iVar23 = (*(int *)(__fp - 0x26f0)) + iVar25;
    iVar12 = iVar21 + iVar23;
    uVar7 = *(undefined4 *)(CRT_colors + (long)*(int *)(lVar17 + lVar24 * 4) * 4);
    iVar11 = 0;
    if (-1 < iVar12) {
      iVar11 = iVar12;
    }
    iVar22 = (*(int (*)[2])(__fp - 0x26b8))[0];
    if (iVar12 <= (*(int (*)[2])(__fp - 0x26b8))[0]) {
      iVar22 = iVar11;
    }
    if (iVar23 < iVar22) {
      puVar18 = (undefined4 *)((long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + (long)iVar23 * 0x1c);
      puVar3 = (undefined4 *)
               ((long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + ((ulong)(uint)(iVar22 - iVar23) + (long)iVar23) * 0x1c);
      if (((int)puVar3 - (int)puVar18 & 4U) != 0) {
        *puVar18 = uVar7;
        puVar18 = puVar18 + 7;
        if (puVar3 == puVar18) goto LAB_00121c76;
      }
      do {
        *puVar18 = uVar7;
        puVar19 = puVar18 + 0xe;
        puVar18[7] = uVar7;
        puVar18 = puVar19;
      } while (puVar3 != puVar19);
    }
LAB_00121c76:
    iVar12 = wmove(_stdscr,param_3,iVar13 + iVar25);
    if (iVar12 != -1) {
      iVar12 = iVar10 - iVar25;
      if (iVar21 < iVar10 - iVar25) {
        iVar12 = iVar21;
      }
      wadd_wchnstr(_stdscr,(void *)((long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + (long)iVar23 * 0x1c),iVar12);
    }
    iVar21 = iVar21 + iVar25;
    iVar25 = 0;
    if (-1 < iVar21) {
      iVar25 = iVar21;
    }
    if (iVar10 < iVar21) {
      iVar25 = iVar10;
    }
    lVar24 = lVar24 + 1;
  } while ((byte)lVar24 < *(byte *)(param_1 + 10));
  if (iVar25 < iVar10) {
    iVar23 = iVar10 - iVar25;
    iVar12 = iVar25 + iVar13;
    iVar21 = (*(int *)(__fp - 0x26f0)) + iVar25;
    goto LAB_00121e52;
  }
  goto LAB_00121d0e;
  while( true ) {
    iVar13 = iVar13 + -1;
    lVar24 = lVar24 + -0x1c;
    if (iVar10 == iVar13) break;
LAB_00121dec:
    if (*(int *)(lVar24 + -0x18) != 0x20) break;
  }
LAB_00121df2:
  (*(int *)(__fp - 0x26f0)) = iVar13 - iVar10;
LAB_00121dfb:
  if (iVar10 < (*(int *)(__fp - 0x26f0))) {
    (*(int *)(__fp - 0x26f0)) = iVar10;
  }
LAB_001219d7:
  iVar13 = param_2 + 4;
  bVar5 = *(byte *)(param_1 + 10);
  iVar23 = iVar10;
  iVar12 = iVar13;
  iVar21 = (*(int *)(__fp - 0x26f0));
  if (bVar5 != 0) {
    pdVar8 = (double *)param_1[0x2c];
    uVar20 = 0;
    iVar23 = 0;
    dVar26 = *pdVar8;
    if (dVar26 <= 0.0) goto LAB_00121b70;
LAB_00121a50:
    dVar4 = *(double *)&param_1[0x2d];
    if (dVar4 <= 0.0) goto LAB_00121b70;
    if (dVar4 <= dVar26) {
      dVar26 = dVar4;
    }
    dVar26 = (dVar26 / dVar4) * (double)iVar10;
    if (ABS(dVar26) < 4503599627370496.0) {
      dVar26 = __builtin_ceil(dVar26);
    }
    iVar21 = (int)dVar26;
    iVar12 = iVar23;
    iVar23 = iVar21 + iVar23;
    do {
      (*(int (*)[12])(__fp - 0x26e8))[uVar20] = iVar21;
      iVar21 = 0;
      if (-1 < iVar23) {
        iVar21 = iVar23;
      }
      bVar9 = iVar10 < iVar23;
      iVar23 = iVar21;
      if (bVar9) {
        iVar23 = iVar10;
      }
      if (iVar12 < iVar23) {
        pauVar15 = (undefined1 (*) [16])((long)pauVar14 + ((long)iVar12 + (long)(*(int *)(__fp - 0x26f0))) * 0x1c);
        pauVar2 = (undefined1 (*) [16])
                  ((long)pauVar14 +
                  ((ulong)(uint)(iVar23 - iVar12) + (long)iVar12 + (long)(*(int *)(__fp - 0x26f0))) * 0x1c);
        do {
          while (*(int *)(*pauVar15 + 4) == 0x20) {
            if (iVar25 == 1) {
              cVar6 = ((char *)(long)&s__________0014db88 /* "|#*@$%&." */)[(int)uVar20];
              pauVar16 = pauVar15;
              do {
                *(undefined16 *)(*pauVar16) = (undefined16)0x0;
                pauVar15 = (undefined1 (*) [16])(pauVar16[1] + 0xc);
                *(undefined16 *)(*(undefined1 (*) [16])(*pauVar16 + 0xc)) = (undefined16)0x0;
                *(int *)(*pauVar16 + 4) = (int)cVar6;
                if (pauVar2 == pauVar15) goto LAB_00121b50;
                pauVar1 = pauVar16 + 2;
                pauVar16 = pauVar15;
              } while (*(int *)*pauVar1 == 0x20);
              break;
            }
            do {
              pauVar16 = pauVar15;
              *(undefined16 *)(*pauVar16) = (undefined16)0x0;
              *(undefined16 *)(*(undefined1 (*) [16])(*pauVar16 + 0xc)) = (undefined16)0x0;
              *(undefined4 *)(*pauVar16 + 4) = 0x7c;
              if (pauVar2 == (undefined1 (*) [16])(pauVar16[1] + 0xc)) goto LAB_00121b50;
              pauVar15 = (undefined1 (*) [16])(pauVar16[1] + 0xc);
            } while (*(int *)pauVar16[2] == 0x20);
            pauVar15 = (undefined1 (*) [16])(pauVar16[3] + 8);
            if (pauVar2 == pauVar15) goto LAB_00121b50;
          }
          pauVar15 = (undefined1 (*) [16])(pauVar15[1] + 0xc);
        } while (pauVar2 != pauVar15);
      }
LAB_00121b50:
      uVar20 = uVar20 + 1;
      if (bVar5 == uVar20) {
        lVar24 = 0;
        iVar25 = 0;
        goto LAB_00121bd0;
      }
      dVar26 = pdVar8[uVar20];
      if (0.0 < dVar26) goto LAB_00121a50;
LAB_00121b70:
      iVar21 = 0;
      iVar12 = iVar23;
    } while( true );
  }
LAB_00121e52:
  (*(int *)(__fp - 0x26f0)) = (*(int *)(__fp - 0x26f0)) + iVar10;
  uVar7 = *(undefined4 *)(CRT_colors + 0xc0);
  iVar10 = 0;
  if (-1 < (*(int *)(__fp - 0x26f0))) {
    iVar10 = (*(int *)(__fp - 0x26f0));
  }
  iVar25 = (*(int (*)[2])(__fp - 0x26b8))[0];
  if ((*(int *)(__fp - 0x26f0)) <= (*(int (*)[2])(__fp - 0x26b8))[0]) {
    iVar25 = iVar10;
  }
  if (iVar21 < iVar25) {
    puVar18 = (undefined4 *)((long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + (long)iVar21 * 0x1c);
    puVar3 = (undefined4 *)
             ((long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + ((long)iVar21 + (ulong)(uint)(iVar25 - iVar21)) * 0x1c);
    puVar19 = puVar18;
    if (((int)puVar3 - (int)puVar18 & 4U) != 0) {
      *puVar18 = uVar7;
      puVar19 = puVar18 + 7;
      if (puVar3 == puVar18 + 7) goto LAB_00121ed6;
    }
    do {
      *puVar19 = uVar7;
      puVar18 = puVar19 + 0xe;
      puVar19[7] = uVar7;
      puVar19 = puVar18;
    } while (puVar3 != puVar18);
  }
LAB_00121ed6:
  iVar10 = wmove(_stdscr,param_3,iVar12);
  if (iVar10 != -1) {
    wadd_wchnstr(_stdscr,(void *)((long)(*(undefined1 (**)[16])(__fp - 0x26b0)) + (long)iVar21 * 0x1c),iVar23);
  }
LAB_00121d0e:
  if (0x15e < (*(int (*)[2])(__fp - 0x26b8))[0]) {
    free((*(undefined1 (**)[16])(__fp - 0x26b0)));
    (*(undefined1 (**)[16])(__fp - 0x26b0)) = (undefined1 (*) [16])(*(undefined1 (*)[12])(__fp - 0x26a8));
  }
  wmove(_stdscr,param_3,param_4 + -4 + iVar13);
  wattrset(_stdscr,*(int *)CRT_colors);
LAB_00121d4d:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* ListItem_new @ 0x1232b0 */

undefined8 * ListItem_new(char *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x18);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = ListItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined4 *)(puVar1 + 2) = param_2;
      *(undefined1 *)((long)puVar1 + 0x14) = 0;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ListItem_init @ 0x123310 */

void ListItem_init(long param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;

  pcVar1 = strdup(param_2);
  if (pcVar1 != (char *)0x0) {
    *(char **)(param_1 + 8) = pcVar1;
    *(undefined4 *)(param_1 + 0x10) = param_3;
    *(undefined1 *)(param_1 + 0x14) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ListItem_append @ 0x123350 */

void ListItem_append(long param_1,char *param_2)

{
  char *__s;
  size_t sVar1;
  size_t p2;
  void *pvVar2;
  ulong __size;

  __s = *(char **)(param_1 + 8);
  sVar1 = strlen(__s);
  p2 = strlen(param_2);
  __size = sVar1 + p2 + 1;
  pvVar2 = realloc(__s,__size);
  if (pvVar2 != (void *)0x0) {
    *(void **)(param_1 + 8) = pvVar2;
    if (__size < sVar1) {
      __size = sVar1;
    }
    __memcpy_chk((void *)((long)pvVar2 + sVar1),param_2,p2,__size - sVar1);
    *(undefined1 *)(*(long *)(param_1 + 8) + sVar1 + p2) = 0;
    return;
  }
  free(__s);
                    /* WARNING: Subroutine does not return */
  fail();
}

