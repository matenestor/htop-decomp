#include "htop.h"

/* Meter_delete @ 0x11fe30 */

void Meter_delete(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  if (param_1 != (long *)0x0) {
    if (*(code **)(*param_1 + 0x28) != (code *)0x0) {
      (**(code **)(*param_1 + 0x28))((long)param_1,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
    }
    free((void *)param_1[8]);
    free((void *)param_1[3]);
    free((void *)param_1[0x2c]);
    free(param_1);
    return;
  }
  return;
}


/* FUN_0011fe90 @ 0x11fe90 */

void FUN_0011fe90(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined8 *__ptr;
  long extraout_RDX;

  __ptr = *(undefined8 **)(param_1 + 0x170);
  Meter_delete((long *)__ptr[1],param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  Meter_delete((long *)*__ptr,param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  free(__ptr);
  return;
}


/* FUN_0011fed0 @ 0x11fed0 */

void FUN_0011fed0(void *param_1)

{
  free(*(void **)((long)param_1 + 8));
  free(param_1);
  return;
}


/* Meter_setMode @ 0x121460 */

void Meter_setMode(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                  long param_r9)

{
  int iVar1;
  long lVar2;
  long a2;
  code *pcVar3;

  if (param_2 < 1) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    lVar2 = *param_1;
    iVar1 = *(int *)(lVar2 + 0x58);
  }
  else {
    if ((int)param_1[4] == param_2) {
      return;
    }
    lVar2 = *param_1;
    iVar1 = *(int *)(lVar2 + 0x58);
  }
  if (iVar1 == 0) {
    a2 = *(long *)(lVar2 + 0x40);
    pcVar3 = *(code **)(lVar2 + 0x30);
    param_1[1] = a2;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)((long)param_1,(ulong)(uint)param_2,a2,param_rcx,param_r8,param_r9);
    }
  }
  else {
    free((void *)param_1[8]);
    param_1[8] = 0;
    param_1[7] = 0;
    lVar2 = (*(long **)(Meter_modes + (long)param_2 * 8))[2];
    param_1[1] = **(long **)(Meter_modes + (long)param_2 * 8);
    *(int *)(param_1 + 9) = (int)lVar2;
  }
  *(int *)(param_1 + 4) = param_2;
  return;
}


/* FUN_00121500 @ 0x121500 */

void FUN_00121500(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9
                 )

{
  long *plVar1;
  int iVar2;
  long extraout_RDX;

  plVar1 = *(long **)(param_1 + 0x170);
  *(int *)(param_1 + 0x20) = param_2;
  Meter_setMode((long *)*plVar1,param_2,param_rdx,param_rcx,param_r8,param_r9);
  Meter_setMode((long *)plVar1[1],param_2,extraout_RDX,param_rcx,param_r8,param_r9);
  iVar2 = *(int *)(*(long *)(Meter_modes + (long)*(int *)(plVar1[1] + 0x20) * 8) + 0x10);
  if (*(int *)(*(long *)(Meter_modes + (long)*(int *)(plVar1[1] + 0x20) * 8) + 0x10) <
      *(int *)(*(long *)(Meter_modes + (long)*(int *)(*plVar1 + 0x20) * 8) + 0x10)) {
    iVar2 = *(int *)(*(long *)(Meter_modes + (long)*(int *)(*plVar1 + 0x20) * 8) + 0x10);
  }
  *(int *)(param_1 + 0x48) = iVar2;
  return;
}


/* Meter_new @ 0x123520 */

long * Meter_new(long param_1,undefined4 param_2,long param_3,long param_rcx,long param_r8,
                long param_r9)

{
  byte bVar1;
  long *a0;
  char *pcVar2;
  void *pvVar3;
  long a2;
  long extraout_RDX;
  long lVar4;
  long a1;

  a1 = 0x178;
  a0 = calloc(1,0x178);
  if (a0 != (long *)0x0) {
    bVar1 = *(byte *)(param_3 + 0x90);
    *a0 = param_3;
    *(undefined4 *)(a0 + 9) = 1;
    *(undefined4 *)((long)a0 + 0x24) = param_2;
    a0[2] = param_1;
    *(byte *)(a0 + 10) = bVar1;
    a0[0xb] = 0;
    pvVar3 = (void *)0x0;
    if (bVar1 != 0) {
      a1 = 8;
      pvVar3 = calloc((ulong)bVar1,8);
      if (pvVar3 == (void *)0x0) goto LAB_001235ef;
    }
    lVar4 = *(long *)(param_3 + 0x60);
    a0[0x2c] = (long)pvVar3;
    pcVar2 = *(char **)(param_3 + 0x80);
    a0[0x2d] = lVar4;
    pcVar2 = strdup(pcVar2);
    if (pcVar2 != (char *)0x0) {
      a0[3] = (long)pcVar2;
      lVar4 = a2;
      if (*(code **)(*a0 + 0x20) != (code *)0x0) {
        (**(code **)(*a0 + 0x20))((long)a0,a1,a2,param_rcx,param_r8,param_r9);
        lVar4 = extraout_RDX;
      }
      Meter_setMode(a0,*(int *)(param_3 + 0x58),lVar4,param_rcx,param_r8,param_r9);
      return a0;
    }
  }
LAB_001235ef:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Meter_setCaption @ 0x123750 */

void Meter_setCaption(long param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = *(char **)(param_1 + 0x18);
  if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,param_2), iVar1 == 0)) {
    return;
  }
  free(pcVar2);
  pcVar2 = strdup(param_2);
  if (pcVar2 != (char *)0x0) {
    *(char **)(param_1 + 0x18) = pcVar2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001237b0 @ 0x1237b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001237b0(long *param_1,int param_2,int param_3,int param_4,long param_r8,long param_r9)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  double *pdVar1;
  int iVar2;
  long *plVar3;
  void *__ptr;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *p1;
  long lVar8;
  double *pdVar9;
  ulong uVar10;
  void *p1_00;
  undefined4 in_register_0000000c;
  long lVar11;
  undefined **ppuVar12;
  size_t __size;
  int iVar13;
  undefined4 in_register_00000014;
  ulong uVar14;
  undefined4 in_register_00000034;
  int p1_01;
  ulong uVar15;
  int iVar16;
  uint uVar17;
  double __x;
  double dVar18;

  if (*(code **)(*param_1 + 0x48) == (code *)0x0) {
    p1 = (char *)param_1[3];
  }
  else {
    p1 = (char *)(**(code **)(*param_1 + 0x48))
                           ((long)param_1,CONCAT44(in_register_00000034,param_2),
                            CONCAT44(in_register_00000014,param_3),
                            CONCAT44(in_register_0000000c,param_4),(long)param_1,param_r9);
  }
  wattrset(_stdscr,*(int *)(CRT_colors + 0x38));
  iVar4 = wmove(_stdscr,param_3,param_2);
  if (iVar4 != -1) {
    waddnstr(_stdscr,p1,3);
  }
  iVar4 = param_4 + -3;
  uVar15 = param_1[7];
  if (((int)(uVar15 >> 1) < iVar4) && (uVar15 < 0x8000)) {
    uVar10 = (uVar15 >> 1) + uVar15;
    __ptr = (void *)param_1[8];
    if (uVar10 <= (ulong)((long)iVar4 * 2)) {
      uVar10 = (long)iVar4 * 2;
    }
    if (0x8000 < uVar10) {
      uVar10 = 0x8000;
    }
    param_1[7] = uVar10;
    __size = uVar10 * 8;
    p1_00 = realloc(__ptr,__size);
    if (p1_00 == (void *)0x0) {
      free(__ptr);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    param_1[8] = (long)p1_00;
    uVar10 = (param_1[7] - uVar15) * 8;
    if (__size <= uVar10) {
      __size = uVar10;
    }
    __memmove_chk((void *)((long)p1_00 + uVar10),p1_00,uVar15 * 8,
                  __size + (param_1[7] - uVar15) * -8);
    memset((void *)param_1[8],0,(param_1[7] - uVar15) * 8);
    uVar15 = param_1[7];
  }
  if (uVar15 == 0) {
    return;
  }
  plVar3 = (long *)param_1[2];
  lVar11 = plVar3[1];
  if (lVar11 == param_1[5]) {
    lVar8 = plVar3[2];
    if (lVar8 < param_1[6]) goto LAB_0012392b;
  }
  else {
    if (lVar11 < param_1[5]) goto LAB_0012392b;
    lVar8 = plVar3[2];
  }
  iVar2 = *(int *)(*plVar3 + 0x4c);
  lVar11 = iVar2 / 10 + lVar11;
  param_1[5] = lVar11;
  lVar8 = (long)(iVar2 % 10) * 100000 + lVar8;
  param_1[6] = lVar8;
  if (999999 < lVar8) {
    param_1[5] = lVar11 + 1;
    param_1[6] = lVar8 + -1000000;
  }
  memmove((void *)param_1[8],(void *)(param_1[8] + 8),uVar15 * 8 - 8);
  pdVar9 = (double *)param_1[0x2c];
  if ((ulong)*(byte *)(param_1 + 10) == 0) {
    dVar18 = 0.0;
  }
  else {
    dVar18 = 0.0;
    pdVar1 = pdVar9 + *(byte *)(param_1 + 10);
    do {
      if (0.0 < *pdVar9) {
        dVar18 = dVar18 + *pdVar9;
      }
      pdVar9 = pdVar9 + 1;
    } while (pdVar9 != pdVar1);
  }
  *(double *)(param_1[8] + -8 + uVar15 * 8) = dVar18;
LAB_0012392b:
  if (iVar4 < 1) {
    return;
  }
  (*(int *)(__fp - 0x40)) = param_2 + 3;
  uVar14 = uVar15 >> 1;
  uVar10 = (long)iVar4;
  if (uVar14 < (ulong)(long)iVar4) {
    (*(int *)(__fp - 0x40)) = (iVar4 + (*(int *)(__fp - 0x40))) - (int)uVar14;
    uVar10 = uVar14;
  }
  ppuVar12 = (undefined **)&DAT_001579a0;
  uVar17 = -(uint)(CRT_utf8 == '\0') & 0xfffffffe;
  iVar4 = uVar17 + 4;
  if (CRT_utf8 != '\0') {
    ppuVar12 = &PTR_DAT_00157a00;
  }
  (*(ulong *)(__fp - 0x58)) = uVar15 + uVar10 * -2;
  if ((*(ulong *)(__fp - 0x58)) < uVar15 - 1) {
    iVar2 = iVar4 * 4;
    do {
      dVar18 = *(double *)&param_1[0x2d];
      lVar11 = param_1[8];
      if (dVar18 <= 1.0) {
        dVar18 = 1.0;
      }
      __x = (*(double *)(lVar11 + (*(ulong *)(__fp - 0x58)) * 8) / dVar18) * (double)iVar2;
      lVar8 = lround(__x);
      iVar7 = iVar2;
      if ((int)lVar8 <= iVar2) {
        lVar8 = lround(__x);
        iVar7 = 1;
        if (1 < (int)lVar8) {
          lVar8 = lround(__x);
          iVar7 = (int)lVar8;
        }
      }
      dVar18 = (*(double *)(lVar11 + 8 + (*(ulong *)(__fp - 0x58)) * 8) / dVar18) * (double)iVar2;
      lVar11 = lround(dVar18);
      iVar6 = iVar2;
      if ((int)lVar11 <= iVar2) {
        lVar11 = lround(dVar18);
        iVar6 = 1;
        if (1 < (int)lVar11) {
          lVar11 = lround(dVar18);
          iVar6 = (int)lVar11;
        }
      }
      iVar16 = iVar7 + iVar4 * -3;
      lVar11 = 0x31;
      p1_01 = param_3;
      do {
        wattrset(_stdscr,*(int *)(CRT_colors + lVar11 * 4));
        iVar5 = wmove(_stdscr,p1_01,(*(int *)(__fp - 0x40)));
        if (iVar5 != -1) {
          iVar5 = 0;
          if (-1 < iVar16) {
            iVar5 = iVar16;
          }
          if (iVar4 < iVar5) {
            iVar5 = iVar4;
          }
          iVar13 = (iVar6 - iVar7) + iVar16;
          if (iVar13 < 0) {
            iVar13 = 0;
          }
          if (iVar4 < iVar13) {
            iVar13 = iVar4;
          }
          waddnstr(_stdscr,ppuVar12[(int)(iVar5 * (uVar17 + 5) + iVar13)],-1);
        }
        p1_01 = p1_01 + 1;
        iVar16 = iVar16 + iVar4;
        lVar11 = 0x32;
      } while (p1_01 != param_3 + 4);
      (*(ulong *)(__fp - 0x58)) = (*(ulong *)(__fp - 0x58)) + 2;
      (*(int *)(__fp - 0x40)) = (*(int *)(__fp - 0x40)) + 1;
    } while ((*(ulong *)(__fp - 0x58)) < uVar15 - 1);
  }
  wattrset(_stdscr,*(int *)CRT_colors);
  return;
}


/* Meter_humanUnit @ 0x128690 */

int Meter_humanUnit(double param_1,char *param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int va2;
  double dVar4;

  iVar1 = 0;
  va2 = 0x4b;
  lVar2 = 0;
  dVar4 = param_1;
  if (1024.0 <= param_1) {
    do {
      param_1 = param_1 * 0.0009765625;
      lVar3 = lVar2 + 1;
      dVar4 = param_1;
      if (param_1 < 1024.0) {
        va2 = (int)(char)(&UNK_0014db99)[lVar2];
        if (99.9 < param_1) {
          dVar4 = 100.0;
          iVar1 = 0;
        }
        else {
          iVar1 = 2;
          if (param_1 <= 9.99) goto LAB_001286de;
          dVar4 = 10.0;
          iVar1 = 1;
        }
        if (dVar4 <= param_1) {
          dVar4 = param_1;
        }
        goto LAB_001286de;
      }
      lVar2 = lVar3;
    } while (lVar3 != 9);
    iVar1 = 0;
    va2 = 0x51;
    if (9999.0 < param_1) {
      iVar1 = xSnprintf(param_2,param_3,((char *)(long)&DAT_0014883c /* "inf" */));
      return iVar1;
    }
  }
LAB_001286de:
  iVar1 = xSnprintf(param_2,param_3,((char *)(long)&s____f_c_00148840 /* "%.*f%c" */),iVar1,dVar4,va2);
  return iVar1;
}


/* Meter_toListItem @ 0x128760 */

undefined8 *
Meter_toListItem(long *param_1,undefined1 param_2,long param_rdx,long param_rcx,long param_r8,
                long param_r9)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  long lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  char *pcVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((int)param_1[4] == 0) {
    lVar1 = *param_1;
    (*(char (*)[32])(__fp - 0xb8))[0] = '\0';
    pcVar2 = *(code **)(lVar1 + 0x50);
  }
  else {
    param_rcx = *(undefined8 *)(*(long *)(Meter_modes + (long)(int)param_1[4] * 8) + 8);
    xSnprintf((*(char (*)[32])(__fp - 0xb8)),0x14,((char *)(long)(__sec_rodata + 0x2dcb) /* " [%s]" */),(void *)param_rcx);
    lVar1 = *param_1;
    pcVar2 = *(code **)(lVar1 + 0x50);
  }
  if (pcVar2 == (code *)0x0) {
    xSnprintf((*(char (*)[32])(__fp - 0x98)),0x20,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),*(void **)(lVar1 + 0x78));
  }
  else {
    (*pcVar2)((long)param_1,(long)(*(char (*)[32])(__fp - 0x98)),0x20,param_rcx,param_r8,param_r9);
  }
  xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),(*(char (*)[32])(__fp - 0x98)),(*(char (*)[32])(__fp - 0xb8)));
  puVar3 = malloc(0x18);
  if (puVar3 != (undefined8 *)0x0) {
    *puVar3 = ListItem_class;
    pcVar4 = strdup((*(char (*)[56])(__fp - 0x78)));
    if (pcVar4 != (char *)0x0) {
      puVar3[1] = pcVar4;
      *(undefined4 *)(puVar3 + 2) = 0;
      *(undefined1 *)((long)puVar3 + 0x14) = param_2;
      if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return puVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

