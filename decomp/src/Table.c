#include "htop.h"

/* Table_prepareEntries @ 0x12d220 */

void Table_prepareEntries(long param_1)

{
  long *plVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;

  iVar3 = (int)(*(long **)(param_1 + 8))[3];
  if (0 < iVar3) {
    plVar5 = (long *)**(long **)(param_1 + 8);
    plVar1 = plVar5 + iVar3;
    do {
      lVar4 = *plVar5;
      plVar5 = plVar5 + 1;
      uVar2 = *(undefined1 *)(lVar4 + 0x1e);
      *(undefined1 *)(lVar4 + 0x21) = 0;
      *(undefined1 *)(lVar4 + 0x1e) = 1;
      *(undefined1 *)(lVar4 + 0x1f) = uVar2;
    } while (plVar5 != plVar1);
  }
  return;
}


/* FUN_0012d260 @ 0x12d260 */

void FUN_0012d260(long param_1,int param_2,int param_3,undefined *param_4,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long *plVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  ulong a2;
  ulong extraout_RDX;
  int iVar6;
  long a1;
  long *plVar7;

  if (param_2 < param_3) {
    plVar1 = (long *)(param_1 + (long)param_3 * 8);
    (*(int *)(__fp - 0x44)) = param_2;
    do {
      plVar7 = (long *)(param_1 + (long)((param_3 + (*(int *)(__fp - 0x44))) / 2) * 8);
      a1 = *plVar7;
      *plVar7 = *plVar1;
      a2 = (ulong)(uint)param_3;
      *plVar1 = a1;
      iVar6 = (*(int *)(__fp - 0x44));
      if ((*(int *)(__fp - 0x44)) < param_3) {
        lVar5 = (long)(*(int *)(__fp - 0x44));
        plVar7 = (long *)(param_1 + lVar5 * 8);
        lVar3 = (ulong)(uint)(param_3 - (*(int *)(__fp - 0x44))) + lVar5;
        do {
          lVar4 = (*(code *)param_4)(*plVar7,a1,a2,lVar5,param_r8,param_r9);
          if ((int)lVar4 < 1) {
            lVar4 = (long)iVar6;
            lVar5 = *plVar7;
            iVar6 = iVar6 + 1;
            plVar2 = (long *)(param_1 + lVar4 * 8);
            *plVar7 = *plVar2;
            *plVar2 = lVar5;
          }
          plVar7 = plVar7 + 1;
          a2 = extraout_RDX;
        } while ((long *)(param_1 + lVar3 * 8) != plVar7);
        a1 = *plVar1;
      }
      plVar7 = (long *)(param_1 + (long)iVar6 * 8);
      lVar5 = *plVar7;
      *plVar7 = a1;
      *plVar1 = lVar5;
      FUN_0012d260(param_1,(*(int *)(__fp - 0x44)),iVar6 + -1,param_4,param_r8,param_r9);
      (*(int *)(__fp - 0x44)) = iVar6 + 1;
    } while ((*(int *)(__fp - 0x44)) < param_3);
  }
  return;
}


/* FUN_0012d370 @ 0x12d370 */

void FUN_0012d370(void *param_1)

{
  undefined8 *__ptr;

  __ptr = *(undefined8 **)((long)param_1 + 0x20);
  if (__ptr != (undefined8 *)0x0) {
    free((void *)*__ptr);
    free((void *)__ptr[1]);
    free((void *)__ptr[3]);
    free(__ptr);
  }
  free(*(void **)((long)param_1 + 8));
  free(param_1);
  return;
}


/* FUN_0012d3d0 @ 0x12d3d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0012d3d0(undefined4 *param_1,int *param_2,int param_3,char *param_4,char param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  long lVar5;

  lVar5 = (-(ulong)(param_5 == '\0') & 0xfffffffffffffff8) + 0x158;
  wattrset(_stdscr,*(int *)(CRT_colors + lVar5));
  iVar1 = wmove(_stdscr,*param_1,*param_2);
  if (iVar1 != -1) {
    waddch(_stdscr,0x5b);
  }
  iVar1 = *param_2 + 1;
  *param_2 = iVar1;
  if (iVar1 < param_3) {
    sVar4 = strlen(param_4);
    iVar2 = (int)sVar4;
    if (param_3 - iVar1 <= (int)sVar4) {
      iVar2 = param_3 - iVar1;
    }
    wattrset(_stdscr,*(int *)(CRT_colors + 0x15c + (-(ulong)(param_5 == '\0') & 0xfffffffffffffff8))
            );
    iVar1 = wmove(_stdscr,*param_1,*param_2);
    if (iVar1 == -1) {
      iVar2 = iVar2 + *param_2;
      *param_2 = iVar2;
    }
    else {
      waddnstr(_stdscr,param_4,iVar2);
      iVar2 = iVar2 + *param_2;
      *param_2 = iVar2;
    }
    if (iVar2 < param_3) {
      wattrset(_stdscr,*(int *)(CRT_colors + lVar5));
      iVar1 = wmove(_stdscr,*param_1,*param_2);
      if (iVar1 == -1) {
        iVar1 = *param_2 + 2;
        *param_2 = iVar1;
        uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),iVar1 < param_3);
      }
      else {
        waddch(_stdscr,0x5d);
        iVar1 = *param_2 + 2;
        *param_2 = iVar1;
        uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),iVar1 < param_3);
      }
      return uVar3;
    }
  }
  return 0;
}


/* FUN_0012d550 @ 0x12d550 */

void FUN_0012d550(long param_1)

{
  char *__dest;
  int iVar1;
  long lVar2;
  char *__src;
  size_t sVar3;

  if (0 < (int)(*(long **)(param_1 + 0x20))[3]) {
    iVar1 = *(int *)(param_1 + 0x28);
    lVar2 = *(long *)(**(long **)(param_1 + 0x20) + (long)iVar1 * 8);
    if (lVar2 != 0) {
      __src = *(char **)(lVar2 + 8);
      *(undefined1 *)(param_1 + 0x49) = 1;
      __dest = (char *)(param_1 + 0x2700);
      *(long *)(param_1 + 0x2728) = lVar2;
      *(char **)(param_1 + 0x2718) = __src;
      strncpy(__dest,__src,0x14);
      *(undefined1 *)(param_1 + 0x2714) = 0;
      sVar3 = strlen(__dest);
      *(int *)(param_1 + 0x2720) = (int)sVar3;
      *(char **)(lVar2 + 8) = __dest;
      *(undefined4 *)(param_1 + 0x26d8) = 0x53;
      sVar3 = strlen(__dest);
      *(int *)(param_1 + 0x30) = (int)sVar3;
      *(int *)(param_1 + 0x1c) = ((iVar1 + *(int *)(param_1 + 0xc)) - *(int *)(param_1 + 0x40)) + 1;
      *(int *)(param_1 + 0x18) = ((int)sVar3 + *(int *)(param_1 + 8)) - *(int *)(param_1 + 0x44);
    }
    return;
  }
  return;
}


/* FUN_0012d610 @ 0x12d610 */

int FUN_0012d610(ulong *param_1,char *param_2)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  char *__s2;
  int iVar1;
  ushort **ppuVar2;
  long lVar3;
  char *pcVar4;
  int *piVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  int *piVar9;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  ppuVar2 = __ctype_b_loc();
  if ((*(byte *)((long)*ppuVar2 + (long)*param_2 * 2 + 1) & 8) == 0) {
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x68)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x58)), (undefined16)0x0);
    iVar1 = __isoc23_sscanf(param_2,((char *)(long)&s_Dynamic__30s__00148bfc /* "Dynamic(%30s)" */),(*(undefined1 (*)[16])(__fp - 0x68)));
    if ((iVar1 != 0) && (pcVar4 = strrchr((*(undefined1 (*)[16])(__fp - 0x68)),0x29), pcVar4 != (char *)0x0)) {
      *pcVar4 = '\0';
      if ((param_1 == (ulong *)0x0) || (*param_1 == 0)) {
        *pcVar4 = ')';
      }
      else {
        piVar9 = (int *)param_1[1];
        (*(int *)(__fp - 0x74)) = 0;
        (*(char * *)(__fp - 0x80)) = (char *)0x0;
        piVar5 = piVar9 + *param_1 * 6;
        do {
          __s2 = *(char **)(piVar9 + 4);
          if ((__s2 != (char *)0x0) && (iVar1 = strcmp((*(undefined1 (*)[16])(__fp - 0x68)),__s2), iVar1 == 0)) {
            (*(int *)(__fp - 0x74)) = *piVar9;
            (*(char * *)(__fp - 0x80)) = __s2;
          }
          piVar9 = piVar9 + 6;
        } while (piVar9 != piVar5);
        *pcVar4 = ')';
        if ((*(char * *)(__fp - 0x80)) != (char *)0x0) goto LAB_0012d68a;
      }
    }
    (*(int *)(__fp - 0x74)) = 1;
    puVar8 = (undefined8 *)(Process_fields + 0x20);
    do {
      if (((char *)*puVar8 != (char *)0x0) && (iVar1 = strcmp((char *)*puVar8,param_2), iVar1 == 0))
      goto LAB_0012d68a;
      (*(int *)(__fp - 0x74)) = (*(int *)(__fp - 0x74)) + 1;
      puVar8 = puVar8 + 4;
    } while ((*(int *)(__fp - 0x74)) != 0x84);
  }
  else {
    lVar3 = __isoc23_strtol(param_2,(char **)0x0,10);
    (*(int *)(__fp - 0x74)) = (int)lVar3 + 1;
    if (-1 < (*(int *)(__fp - 0x74))) {
      if ((*(int *)(__fp - 0x74)) < 0x84) {
        if (*(long *)(Process_fields + (long)(*(int *)(__fp - 0x74)) * 0x20) != 0) goto LAB_0012d68a;
      }
      else {
        piVar9 = (int *)param_1[1];
        uVar7 = (ulong)(long)(*(int *)(__fp - 0x74)) % *param_1;
        piVar5 = piVar9 + uVar7 * 6;
        if (*(long *)(piVar5 + 4) != 0) {
          uVar6 = 0;
          do {
            if ((*(int *)(__fp - 0x74)) == *piVar5) goto LAB_0012d68a;
            if (*(ulong *)(piVar5 + 2) < uVar6) break;
            uVar7 = uVar7 + 1;
            if (*param_1 == uVar7) {
              uVar7 = 0;
              piVar5 = piVar9;
            }
            else {
              piVar5 = piVar9 + uVar7 * 6;
            }
            uVar6 = uVar6 + 1;
          } while (*(long *)(piVar5 + 4) != 0);
        }
      }
    }
  }
  (*(int *)(__fp - 0x74)) = -1;
LAB_0012d68a:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int *)(__fp - 0x74));
}


/* FUN_0012d840 @ 0x12d840 */

void FUN_0012d840(FILE *param_1,int *param_2,ulong *param_3,char param_4,char param_5)

{
  int iVar1;
  int *piVar2;
  ulong uVar3;
  int *piVar4;
  ulong uVar5;
  undefined *va0;
  ulong uVar6;
  void *pvVar7;

  iVar1 = *param_2;
  if (iVar1 != 0) {
    uVar3 = 0;
    va0 = &DAT_00149c0c;
    do {
      if (iVar1 < 0x84) {
        if (param_4 == '\0') {
LAB_0012d891:
          __fprintf_chk(param_1,2,((char *)(long)&DAT_00148c18 /* "%s%d" */),va0,iVar1 + -1);
        }
        else {
          if (iVar1 < 0) {
            pvVar7 = (void *)0x0;
          }
          else {
            pvVar7 = *(void **)(Process_fields + (long)iVar1 * 0x20);
          }
          __fprintf_chk(param_1,2,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),va0,pvVar7);
        }
      }
      else {
        if (param_4 == '\0') goto LAB_0012d891;
        piVar2 = (int *)param_3[1];
        uVar5 = (ulong)(long)iVar1 % *param_3;
        piVar4 = piVar2 + uVar5 * 6;
        pvVar7 = *(void **)(piVar4 + 4);
        if (pvVar7 != (void *)0x0) {
          uVar6 = 0;
          do {
            if (iVar1 == *piVar4) {
              if (*(char *)((long)pvVar7 + 0x3c) != '\0') {
                __fprintf_chk(param_1,2,((char *)(long)&s__sDynamic__s__00148c0a /* "%sDynamic(%s)" */),va0,pvVar7);
              }
              break;
            }
            if (*(ulong *)(piVar4 + 2) < uVar6) break;
            uVar5 = uVar5 + 1;
            if (*param_3 == uVar5) {
              uVar5 = 0;
              piVar4 = piVar2;
            }
            else {
              piVar4 = piVar2 + uVar5 * 6;
            }
            pvVar7 = *(void **)(piVar4 + 4);
            uVar6 = uVar6 + 1;
          } while (pvVar7 != (void *)0x0);
        }
      }
      uVar3 = (ulong)((int)uVar3 + 1);
      va0 = &DAT_001470dd;
      iVar1 = param_2[uVar3];
    } while (iVar1 != 0);
  }
  fputc((int)param_5,param_1);
  return;
}


/* FUN_0012d9d0 @ 0x12d9d0 */

void FUN_0012d9d0(long param_1)

{
  undefined1 *puVar1;
  long lVar2;

  if (PTR_0015d7d8 == (undefined1 *)0x0) {
    if (CHAR____0015d7d3 == '\0') {
      FUN_001402d0();
      lVar2 = 0;
      PTR_0015d7d8 = &DAT_0015d680;
      do {
        if ((&DAT_0015d680)[lVar2] == '\0') break;
        *(undefined1 *)(param_1 + 0x60 + lVar2) = (&DAT_0015d680)[lVar2];
        lVar2 = lVar2 + 1;
      } while (lVar2 != 0xff);
      *(undefined1 *)(param_1 + 0x60 + lVar2) = 0;
      return;
    }
    PTR_0015d7d8 = &DAT_0015d680;
  }
  puVar1 = PTR_0015d7d8;
  lVar2 = 0;
  do {
    if (puVar1[lVar2] == '\0') break;
    *(undefined1 *)(param_1 + 0x60 + lVar2) = puVar1[lVar2];
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0xff);
  *(undefined1 *)(param_1 + 0x60 + lVar2) = 0;
  return;
}


/* Table_setPanel @ 0x12e210 */

void Table_setPanel(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x38) = param_2;
  return;
}


/* Table_expandTree @ 0x12e2a0 */

void Table_expandTree(long param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long *plVar4;

  iVar2 = (int)(*(long **)(param_1 + 8))[3];
  if (0 < iVar2) {
    plVar4 = (long *)**(long **)(param_1 + 8);
    plVar1 = plVar4 + iVar2;
    do {
      lVar3 = *plVar4;
      plVar4 = plVar4 + 1;
      *(undefined1 *)(lVar3 + 0x20) = 1;
    } while (plVar4 != plVar1);
  }
  return;
}


/* Table_done @ 0x12f930 */

void Table_done(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  ulong *__ptr;
  long extraout_RDX;
  long extraout_RDX_00;

  __ptr = *(ulong **)(param_1 + 0x18);
  Hashtable_clear(__ptr);
  free((void *)__ptr[1]);
  free(__ptr);
  Vector_delete(*(long **)(param_1 + 0x10),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  Vector_delete(*(long **)(param_1 + 8),param_rsi,extraout_RDX_00,param_rcx,param_r8,param_r9);
  return;
}


/* FUN_0012f980 @ 0x12f980 */

void FUN_0012f980(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  ulong *__ptr;
  long extraout_RDX;
  long extraout_RDX_00;

  __ptr = *(ulong **)((long)param_1 + 0x18);
  Hashtable_clear(__ptr);
  free((void *)__ptr[1]);
  free(__ptr);
  Vector_delete(*(long **)((long)param_1 + 0x10),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  Vector_delete(*(long **)((long)param_1 + 8),param_rsi,extraout_RDX_00,param_rcx,param_r8,param_r9)
  ;
  free(param_1);
  return;
}


/* Table_removeIndex @ 0x12fa10 */

void Table_removeIndex(long param_1,long param_2,int param_3,long param_rcx,long param_r8,
                      long param_r9)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  long *a0;
  ulong a1;

  uVar2 = *(uint *)(param_2 + 0x10);
  a1 = (ulong)uVar2;
  Hashtable_remove(*(ulong **)(param_1 + 0x18),uVar2);
  plVar4 = *(long **)(param_1 + 8);
  plVar1 = (long *)(*plVar4 + (long)param_3 * 8);
  a0 = (long *)*plVar1;
  if (a0 != (long *)0x0) {
    *plVar1 = 0;
    uVar3 = *(uint *)((long)plVar4 + 0x1c);
    *(int *)(plVar4 + 4) = (int)plVar4[4] + 1;
    if ((param_3 < (int)uVar3) || ((int)uVar3 < 0)) {
      *(int *)((long)plVar4 + 0x1c) = param_3;
    }
    if (*(char *)((long)plVar4 + 0x24) != '\0') {
      (**(code **)(*a0 + 0x10))((long)a0,a1,(ulong)uVar3,(long)param_3,param_r8,param_r9);
    }
  }
  if ((*(uint *)(param_1 + 0x34) == uVar2) && (*(uint *)(param_1 + 0x34) != 0xffffffff)) {
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
    *(undefined4 *)(*(long *)(param_1 + 0x38) + 0x26d8) = 9;
    return;
  }
  return;
}


/* Table_cleanupRow @ 0x12fac0 */

void Table_cleanupRow(long param_1,long param_2,int param_3,long param_rcx,long param_r8,
                     long param_r9)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;

  plVar1 = *(long **)(param_1 + 0x20);
  uVar2 = *(ulong *)(param_2 + 0x38);
  lVar3 = *plVar1;
  if (uVar2 == 0) {
    if (*(char *)(param_2 + 0x21) == '\0') {
      if ((*(char *)(lVar3 + 0x61) != '\0') && (*(char *)(param_2 + 0x1f) != '\0')) {
        *(long *)(param_2 + 0x38) = (long)(*(int *)(lVar3 + 100) * 1000) + plVar1[4];
        return;
      }
      goto LAB_0012fb10;
    }
  }
  else if (uVar2 <= (ulong)plVar1[4]) {
LAB_0012fb10:
    Table_removeIndex(param_1,param_2,param_3,uVar2,lVar3,param_r9);
    return;
  }
  return;
}


/* Table_cleanupEntries @ 0x12fb20 */

void Table_cleanupEntries
               (long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  long extraout_RDX;
  int iVar5;
  long *plVar6;
  long lVar7;

  plVar6 = *(long **)(param_1 + 8);
  iVar5 = (int)plVar6[3] + -1;
  if (-1 < iVar5) {
    lVar7 = (long)iVar5 << 3;
LAB_0012fb62:
    do {
      plVar2 = *(long **)(param_1 + 0x20);
      lVar3 = *(long *)(*plVar6 + lVar7);
      uVar4 = *(ulong *)(lVar3 + 0x38);
      if (uVar4 == 0) {
        if (*(char *)(lVar3 + 0x21) == '\0') {
          if ((*(char *)(*plVar2 + 0x61) != '\0') && (*(char *)(lVar3 + 0x1f) != '\0')) {
            iVar5 = iVar5 + -1;
            lVar7 = lVar7 + -8;
            *(long *)(lVar3 + 0x38) = (long)(*(int *)(*plVar2 + 100) * 1000) + plVar2[4];
            if (iVar5 == -1) break;
            goto LAB_0012fb62;
          }
LAB_0012fbc0:
          uVar1 = *(uint *)(lVar3 + 0x10);
          Hashtable_remove(*(ulong **)(param_1 + 0x18),uVar1);
          Vector_softRemove(*(long **)(param_1 + 8),iVar5,extraout_RDX,uVar4,param_r8,param_r9);
          if ((uVar1 == *(uint *)(param_1 + 0x34)) && (*(uint *)(param_1 + 0x34) != 0xffffffff)) {
            *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
            *(undefined4 *)(*(long *)(param_1 + 0x38) + 0x26d8) = 9;
          }
          plVar6 = *(long **)(param_1 + 8);
        }
      }
      else if (uVar4 <= (ulong)plVar2[4]) goto LAB_0012fbc0;
      iVar5 = iVar5 + -1;
      lVar7 = lVar7 + -8;
    } while (iVar5 != -1);
  }
  Vector_compact(plVar6);
  return;
}


/* FUN_0012fc10 @ 0x12fc10 */

void FUN_0012fc10(void *param_1)

{
  long lVar1;
  void *va1;

  lVar1 = *(long *)((long)param_1 + 8);
  if (((*(char *)(lVar1 + 0x4d) != '\0') && (*(char *)(**(long **)(lVar1 + 8) + 0x58) != '\0')) ||
     (va1 = *(void **)(lVar1 + 0x118), va1 == (void *)0x0)) {
    va1 = *(void **)(lVar1 + 0x80);
  }
  InfoScreen_drawTitled(param_1,((char *)(long)&s_Trace_of_process__d____s_00148ff0 /* "Trace of process %d - %s" */),*(int *)(lVar1 + 0x10),va1);
  return;
}


/* FUN_0012fc60 @ 0x12fc60 */

void FUN_0012fc60(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x568] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x528;
  char *pcVar1;
  char cVar2;
  long *a0;
  int iVar3;
  int iVar4;
  size_t sVar5;
  long lVar6;
  FILE *__stream;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  char *pcVar7;
  char *pcVar8;
  fd_set *pfVar9;
  timeval *__timeout;
  ulong uVar10;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar11;

  bVar11 = 0;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = fileno(*(FILE **)(param_1 + 0x30));
  pfVar9 = &(*(fd_set *)(__fp - 0x4c8));
  for (lVar6 = 0x10; lVar6 != 0; lVar6 = lVar6 + -1) {
    pfVar9->fds_bits[0] = 0;
    pfVar9 = (fd_set *)((long)pfVar9 + ((ulong)bVar11 * -2 + 1) * 8);
  }
  lVar6 = __fdelt_chk((long)iVar3);
  uVar10 = 1L << ((byte)iVar3 & 0x3f);
  __timeout = &(*(timeval *)(__fp - 0x4d8));
  (*(fd_set *)(__fp - 0x4c8)).fds_bits[lVar6] = (*(fd_set *)(__fp - 0x4c8)).fds_bits[lVar6] | uVar10;
  (*(timeval *)(__fp - 0x4d8)).tv_sec = 0;
  (*(timeval *)(__fp - 0x4d8)).tv_usec = 500;
  iVar4 = select(iVar3 + 1,&(*(fd_set *)(__fp - 0x4c8)),(fd_set *)0x0,(fd_set *)0x0,__timeout);
  if ((0 < iVar4) && (lVar6 = __fdelt_chk((long)iVar3), (uVar10 & (*(fd_set *)(__fp - 0x4c8)).fds_bits[lVar6]) != 0))
  {
    __stream = *(FILE **)(param_1 + 0x30);
    sVar5 = fread((*(char (*)[1032])(__fp - 0x448)),1,0x400,__stream);
    if ((sVar5 != 0) && (*(char *)(param_1 + 0x28) != '\0')) {
      pcVar7 = (*(char (*)[1032])(__fp - 0x448)) + 1;
      (*(char (*)[1032])(__fp - 0x448))[sVar5] = '\0';
      pcVar1 = pcVar7 + sVar5;
      lVar6 = extraout_RDX;
      pcVar8 = (*(char (*)[1032])(__fp - 0x448));
      do {
        if (pcVar7[-1] == '\n') {
          cVar2 = *(char *)(param_1 + 0x38);
          pcVar7[-1] = '\0';
          if (cVar2 == '\0') {
            InfoScreen_addLine(param_1,pcVar8,lVar6,(long)__stream,(long)__timeout,param_r9);
            lVar6 = extraout_RDX_01;
            pcVar8 = pcVar7;
          }
          else {
            InfoScreen_appendLine(param_1,pcVar8,lVar6,(long)__stream,(long)__timeout,param_r9);
            *(undefined1 *)(param_1 + 0x38) = 0;
            lVar6 = extraout_RDX_00;
            pcVar8 = pcVar7;
          }
        }
        pcVar7 = pcVar7 + 1;
      } while (pcVar1 != pcVar7);
      if (pcVar8 < (*(char (*)[1032])(__fp - 0x448)) + sVar5) {
        InfoScreen_addLine(param_1,pcVar8,lVar6,(long)__stream,(long)__timeout,param_r9);
        *(undefined1 *)(param_1 + 0x38) = 1;
        (*(char (*)[1032])(__fp - 0x448))[sVar5] = '\0';
      }
      if (*(char *)(param_1 + 0x39) != '\0') {
        a0 = *(long **)(param_1 + 0x10);
        iVar3 = *(int *)(a0[4] + 0x18) + -1;
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        *(int *)(a0 + 5) = iVar3;
        if (*(code **)(*a0 + 0x20) != (code *)0x0) {
          (**(code **)(*a0 + 0x20))((long)a0,0xffffffff,0,(long)__stream,(long)__timeout,param_r9);
        }
      }
    }
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_0012fe10 @ 0x12fe10 */

undefined8
FUN_0012fe10(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  byte *pbVar1;
  long *a0;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long a2;
  long a1;

  if (param_2 == 0x110) {
LAB_0012fe80:
    pbVar1 = (byte *)((long)param_1 + 0x39);
    *pbVar1 = *pbVar1 ^ 1;
    if (*pbVar1 != 0) {
      a0 = (long *)param_1[2];
      iVar2 = *(int *)(a0[4] + 0x18) + -1;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      *(int *)(a0 + 5) = iVar2;
      if (*(code **)(*a0 + 0x20) != (code *)0x0) {
        (**(code **)(*a0 + 0x20))((long)a0,0xffffffff,0,param_rcx,param_r8,param_r9);
      }
    }
LAB_0012fe79:
    uVar3 = 1;
  }
  else {
    if (param_2 < 0x111) {
      if (param_2 == 0x66) goto LAB_0012fe80;
      if (param_2 == 0x74) goto LAB_0012fe48;
    }
    else if (param_2 == 0x111) {
LAB_0012fe48:
      pbVar1 = (byte *)(param_1 + 5);
      *pbVar1 = *pbVar1 ^ 1;
      a1 = 0x111;
      pcVar4 = ((char *)(long)&s_Resume_Tracing_00149019 /* "Resume Tracing " */);
      if (*pbVar1 != 0) {
        pcVar4 = ((char *)(long)&s_Stop_Tracing_00149009 /* "Stop Tracing   " */);
      }
      FunctionBar_setLabel(*(int **)(param_1[2] + 0x58),0x111,pcVar4);
      (**(code **)(*param_1 + 0x28))((long)param_1,a1,a2,param_rcx,param_r8,param_r9);
      goto LAB_0012fe79;
    }
    *(undefined1 *)((long)param_1 + 0x39) = 0;
    uVar3 = 0;
  }
  return uVar3;
}


/* FUN_0012fec0 @ 0x12fec0 */

void FUN_0012fec0(long param_1)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  int va0;
  int iVar1;
  int iVar2;
  int iVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = Platform_getUptime();
  if (iVar1 < 1) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s__unknown__00149029 /* "(unknown)" */));
      return;
    }
    goto LAB_001300b7;
  }
  iVar3 = iVar1 >> 0x1f;
  iVar2 = iVar1 / 0x3c + iVar3;
  va0 = iVar1 / 0x15180;
  dVar4 = (double)va0;
  **(double **)(param_1 + 0x160) = dVar4;
  if (*(double *)(param_1 + 0x168) <= dVar4 && dVar4 != *(double *)(param_1 + 0x168)) {
    *(double *)(param_1 + 0x168) = dVar4;
    if (0x85277f < iVar1) goto LAB_00130018;
LAB_0012ff9d:
    if (iVar1 < 0x2a300) {
      if (va0 == 1) {
        xSnprintf((*(char (*)[40])(__fp - 0x68)),0x20,((char *)(long)&s_1_day__0014904a /* "1 day, " */));
      }
      else {
        (*(char (*)[40])(__fp - 0x68))[0] = '\0';
      }
    }
    else {
      xSnprintf((*(char (*)[40])(__fp - 0x68)),0x20,((char *)(long)&s__d_days__00149040 /* "%d days, " */),va0);
    }
  }
  else {
    if (iVar1 < 0x852780) goto LAB_0012ff9d;
LAB_00130018:
    xSnprintf((*(char (*)[40])(__fp - 0x68)),0x20,((char *)(long)&DAT_00149033 /* "%d days(!), " */),va0);
  }
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s__s_02d__02d__02d_00149052 /* "%s%02d:%02d:%02d" */),(*(char (*)[40])(__fp - 0x68)),(uint)(iVar1 / 0xe10) % 0x18,
            (uint)(iVar2 - iVar3) % 0x3c,iVar1 + (iVar2 - iVar3) * -0x3c);
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_001300b7:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Table_printHeader @ 0x131d50 */

void Table_printHeader(long param_1,int *param_2)

{
  undefined1 __frame[0x100118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000d8;
  wint_t __wc;
  uint uVar1;
  wchar_t __wc_00;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  char cVar9;
  long lVar10;
  undefined1 (*pauVar11) [16];
  int **ppiVar12;
  int **ppiVar13;
  int iVar14;
  undefined1 *puVar15;
  long lVar16;
  long lVar17;
  int *piVar18;
  long in_FS_OFFSET = (long)__fake_fs;

  ppiVar12 = &(*(int * *)(__fp - 0x88));
  ppiVar13 = &(*(int * *)(__fp - 0x88));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(long *)(__fp - 0x80)) = param_1;
  (*(int * *)(__fp - 0x60)) = param_2;
  FUN_00130130(param_2,0);
  lVar16 = *(long *)(param_1 + 0x40);
  cVar9 = *(char *)(lVar16 + 0x34);
  piVar18 = *(int **)(lVar16 + 0x18);
  if (cVar9 == '\0') {
    iVar4 = *(int *)(lVar16 + 0x2c);
  }
  else {
    iVar4 = 1;
    if (*(char *)(lVar16 + 0x35) == '\0') {
      iVar4 = *(int *)(lVar16 + 0x30);
    }
  }
  iVar14 = *piVar18;
  if (iVar14 != 0) {
    do {
      (*(int *)(__fp - 0x50)) = iVar4;
      (*(long *)(__fp - 0x78)) = lVar16;
      lVar16 = (*(long *)(__fp - 0x80));
      if (((cVar9 == '\0') || (*(char *)((*(long *)(__fp - 0x78)) + 0x35) == '\0')) && ((*(int *)(__fp - 0x50)) == iVar14)) {
        (*(uint *)(__fp - 0x6c)) = *(uint *)(CRT_colors + 0x24);
      }
      else {
        (*(uint *)(__fp - 0x6c)) = *(uint *)(CRT_colors + 0x1c);
      }
      *(int *)((long)ppiVar12 + -8) = 0x131df8;
      *(int *)((long)ppiVar12 + -4) = 0;
      pcVar5 = RowField_alignedTitle(lVar16,iVar14);
      *(int *)((long)ppiVar12 + -8) = 0x131e03;
      *(int *)((long)ppiVar12 + -4) = 0;
      sVar6 = strlen(pcVar5);
      (*(int * *)(__fp - 0x68)) = (int *)ppiVar12;
      uVar8 = (ulong)((int)sVar6 + 1);
      iVar4 = *(*(int * *)(__fp - 0x60));
      uVar7 = uVar8 * 4 + 0xf;
      puVar15 = (undefined1 *)((long)ppiVar12 - (uVar7 & 0xfffffffffffff000));
      for (; ppiVar12 != (int **)puVar15; ppiVar12 = (int **)((long)ppiVar12 + -0x1000)) {
        *(undefined8 *)((long)ppiVar12 + -8) = *(undefined8 *)((long)ppiVar12 + -8);
      }
      uVar7 = (ulong)((uint)uVar7 & 0xff0);
      lVar16 = -uVar7;
      if (uVar7 != 0) {
        *(undefined8 *)((long)ppiVar12 + -8) = *(undefined8 *)((long)ppiVar12 + -8);
      }
      uVar7 = __mbstowcs_chk((int *)((long)ppiVar12 + lVar16),pcVar5,(long)(int)sVar6,
                             uVar8 & 0x3fffffffffffffff);
      piVar2 = (*(int * *)(__fp - 0x60));
      if (0 < (int)uVar7) {
        (*(int *)(__fp - 0x4c)) = iVar4 + (int)uVar7;
        lVar10 = (long)iVar4;
        FUN_00130130((*(int * *)(__fp - 0x60)),(*(int *)(__fp - 0x4c)));
        (*(int * *)(__fp - 0x88)) = piVar18;
        (*(undefined8 *)(__fp - 0x58)) = (int *)(CONCAT44((*(uint *)((char *)&(*(undefined8 *)(__fp - 0x58)) + 4)),(*(uint *)(__fp - 0x6c))) & 0xffffffff00ffffff);
        lVar17 = lVar10 * -4;
        pauVar11 = (undefined1 (*) [16])(*(long *)(piVar2 + 2) + lVar10 * 0x1c);
        do {
          __wc = *(wint_t *)((long)ppiVar12 + lVar10 * 4 + lVar17 + lVar16);
          iVar4 = iswprint(__wc);
          *(undefined16 *)(*pauVar11) = (undefined16)0x0;
          if (iVar4 == 0) {
            __wc = 0xfffd;
          }
          *(undefined16 *)(*(undefined1 (*) [16])(*pauVar11 + 0xc)) = (undefined16)0x0;
          lVar10 = lVar10 + 1;
          *(undefined4 *)*pauVar11 = (undefined4)(*(undefined8 *)(__fp - 0x58));
          *(wint_t *)(*pauVar11 + 4) = __wc;
          piVar18 = (*(int * *)(__fp - 0x88));
          pauVar11 = (undefined1 (*) [16])(pauVar11[1] + 0xc);
        } while ((int)lVar10 < (*(int *)(__fp - 0x4c)));
      }
      piVar3 = (*(int * *)(__fp - 0x60));
      piVar2 = (*(int * *)(__fp - 0x68));
      if ((*piVar18 == (*(int *)(__fp - 0x50))) &&
         (iVar4 = *(*(int * *)(__fp - 0x60)), *(int *)(*(long *)((*(int * *)(__fp - 0x60)) + 2) + (long)iVar4 * 0x1c + -0x18) == 0x20)
         ) {
        iVar14 = *(int *)((*(long *)(__fp - 0x78)) + 0x28);
        if (*(char *)((*(long *)(__fp - 0x78)) + 0x34) == '\0') {
          iVar14 = *(int *)((*(long *)(__fp - 0x78)) + 0x24);
        }
        piVar2[-2] = 0x131f81;
        piVar2[-1] = 0;
        FUN_00130130(piVar3,iVar4 + -1);
        (*(undefined8 *)(__fp - 0x58)) = piVar2;
        iVar4 = *piVar3;
        lVar16 = (long)iVar4;
        pcVar5 = *(char **)(CRT_treeStr + (ulong)(iVar14 != 1) * 8 + 0x30);
        uVar1 = *(uint *)(CRT_colors + 0x24);
        piVar2[-2] = 0x131fba;
        piVar2[-1] = 0;
        sVar6 = mbstowcs((*(wchar_t (*)[2])(__fp - 0x48)),pcVar5,1);
        piVar3 = (*(int * *)(__fp - 0x60));
        if (0 < (int)sVar6) {
          iVar4 = (int)sVar6 + iVar4;
          (*(int *)(__fp - 0x4c)) = iVar4;
          piVar2[-2] = 0x131fd9;
          piVar2[-1] = 0;
          FUN_00130130(piVar3,iVar4);
          (*(int * *)(__fp - 0x68)) = piVar18;
          pauVar11 = (undefined1 (*) [16])(*(long *)(piVar3 + 2) + lVar16 * 0x1c);
          lVar17 = lVar16;
          do {
            __wc_00 = (*(wchar_t (*)[2])(__fp - 0x48))[lVar17 - lVar16];
            piVar2[-2] = 0x13200c;
            piVar2[-1] = 0;
            iVar4 = iswprint(__wc_00);
            *(undefined16 *)(*pauVar11) = (undefined16)0x0;
            if (iVar4 == 0) {
              __wc_00 = L'�';
            }
            *(uint *)*pauVar11 = uVar1 & 0xffffff;
            lVar17 = lVar17 + 1;
            *(undefined16 *)(*(undefined1 (*) [16])(*pauVar11 + 0xc)) = (undefined16)0x0;
            *(wchar_t *)(*pauVar11 + 4) = __wc_00;
            pauVar11 = (undefined1 (*) [16])(pauVar11[1] + 0xc);
            piVar18 = (*(int * *)(__fp - 0x68));
          } while ((int)lVar17 < (*(int *)(__fp - 0x4c)));
        }
        ppiVar13 = (int **)(*(undefined8 *)(__fp - 0x58));
        if (*piVar18 != 2) goto LAB_00131f23;
LAB_00132050:
        if (*(char *)((*(long *)(__fp - 0x80)) + 0x6a) == '\0') goto LAB_00131f23;
        piVar18 = piVar18 + 1;
        *(int *)((long)ppiVar13 + -8) = 0x132075;
        *(int *)((long)ppiVar13 + -4) = 0;
        RichString_appendAscii((*(int * *)(__fp - 0x60)),(*(uint *)(__fp - 0x6c)),((char *)(long)&s__merged__0014915d /* "(merged)" */));
        iVar14 = *piVar18;
      }
      else {
        ppiVar13 = (int **)(*(int * *)(__fp - 0x68));
        if (*piVar18 == 2) goto LAB_00132050;
LAB_00131f23:
        iVar14 = piVar18[1];
        piVar18 = piVar18 + 1;
      }
      if (iVar14 == 0) break;
      cVar9 = *(char *)((*(long *)(__fp - 0x78)) + 0x34);
      ppiVar12 = ppiVar13;
      lVar16 = (*(long *)(__fp - 0x78));
      iVar4 = (*(int *)(__fp - 0x50));
    } while( true );
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Table_init @ 0x132aa0 */

long Table_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  void *pvVar2;
  ulong *puVar3;

  puVar1 = malloc(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)((long)puVar1 + 0x14) = 10;
    pvVar2 = calloc(10,8);
    if (pvVar2 != (void *)0x0) {
      *puVar1 = pvVar2;
      *(undefined4 *)(puVar1 + 2) = 10;
      puVar1[1] = param_2;
      *(undefined1 *)((long)puVar1 + 0x24) = 1;
      puVar1[3] = 0xffffffff00000000;
      *(undefined4 *)(puVar1 + 4) = 0;
      *(undefined8 **)(param_1 + 8) = puVar1;
      puVar1 = malloc(0x28);
      if (puVar1 != (undefined8 *)0x0) {
        *(undefined4 *)((long)puVar1 + 0x14) = 10;
        pvVar2 = calloc(10,8);
        if (pvVar2 != (void *)0x0) {
          puVar1[1] = param_2;
          puVar1[3] = 0xffffffff00000000;
          *(undefined8 **)(param_1 + 0x10) = puVar1;
          *puVar1 = pvVar2;
          *(undefined4 *)(puVar1 + 2) = 10;
          *(undefined1 *)((long)puVar1 + 0x24) = 0;
          *(undefined4 *)(puVar1 + 4) = 0;
          puVar3 = Hashtable_new(200,0);
          *(undefined1 *)(param_1 + 0x30) = 1;
          *(ulong **)(param_1 + 0x18) = puVar3;
          *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
          *(undefined8 *)(param_1 + 0x20) = param_3;
          return param_1;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Table_add @ 0x1341b0 */

void Table_add(long param_1,void *param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  long *plVar1;

  plVar1 = *(long **)(param_1 + 8);
  *(undefined8 *)((long)param_2 + 0x30) = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x20);
  Vector_set(plVar1,(int)plVar1[3],(long)param_2,param_rcx,param_r8,param_r9);
  Hashtable_put(*(ulong **)(param_1 + 0x18),*(uint *)((long)param_2 + 0x10),param_2);
  return;
}


/* FUN_001341f0 @ 0x1341f0 */

void FUN_001341f0(long param_1,int param_2,uint param_3,uint param_4,char param_5)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 in_register_0000000c;
  ulong uVar4;
  uint uVar5;
  long *plVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  int iVar10;
  undefined7 in_register_00000081;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  long *plVar14;
  uint uVar15;
  uint uVar17;
  ulong uVar16;

  uVar4 = CONCAT44(in_register_0000000c,param_4);
  if (param_2 == 0) {
    return;
  }
  uVar12 = CONCAT71(in_register_00000081,param_5) & 0xffffffff;
  uVar17 = 0;
  plVar6 = *(long **)(param_1 + 8);
  uVar3 = *(uint *)(plVar6 + 3);
  uVar11 = (ulong)uVar3;
  uVar9 = uVar11;
  while (iVar7 = (int)uVar9, (int)uVar17 < iVar7) {
    while( true ) {
      uVar2 = (int)(uVar17 + iVar7) / 2;
      lVar8 = *(long *)(*plVar6 + (long)(int)uVar2 * 8);
      iVar10 = 0;
      if ((*(char *)(lVar8 + 0x1c) == '\0') &&
         (iVar10 = *(int *)(lVar8 + 0x14), iVar10 == *(int *)(lVar8 + 0x10))) {
        iVar10 = *(int *)(lVar8 + 0x18);
      }
      if (param_2 <= iVar10) break;
      uVar17 = uVar2 + 1;
      if (iVar7 <= (int)uVar17) goto LAB_00134269;
    }
    uVar9 = (ulong)uVar2;
  }
LAB_00134269:
  if (iVar7 < (int)uVar3) {
    plVar14 = (long *)(*plVar6 + (long)iVar7 * 8);
    uVar16 = uVar9;
    do {
      uVar2 = (uint)uVar9;
      uVar15 = (uint)uVar16;
      lVar8 = *plVar14;
      iVar7 = *(int *)(lVar8 + 0x14);
      if (iVar7 == *(int *)(lVar8 + 0x10)) {
        iVar7 = *(int *)(lVar8 + 0x18);
      }
      if (param_2 != iVar7) break;
      if (*(char *)(lVar8 + 0x1e) != '\0') {
        uVar9 = uVar16;
      }
      uVar2 = (uint)uVar9;
      uVar15 = uVar15 + 1;
      uVar16 = (ulong)uVar15;
      plVar14 = plVar14 + 1;
    } while (uVar15 != uVar3);
    if ((int)uVar17 < (int)uVar15) {
      uVar3 = 0x1e;
      if (param_3 < 0x1f) {
        uVar3 = param_3;
      }
      uVar13 = param_4 | 1 << (uVar3 & 0x1f);
      uVar3 = param_3 + 1;
      lVar8 = (long)(int)uVar17 * 8;
      while( true ) {
        lVar1 = *(long *)(*plVar6 + lVar8);
        if (param_5 == '\0') {
          *(undefined1 *)(lVar1 + 0x1e) = 0;
        }
        Vector_set(*(long **)(param_1 + 0x10),(int)(*(long **)(param_1 + 0x10))[3],lVar1,uVar4,
                   uVar11,uVar12);
        uVar11 = 0;
        if (*(char *)(lVar1 + 0x1e) != '\0') {
          uVar11 = (ulong)*(byte *)(lVar1 + 0x20);
        }
        uVar5 = uVar13;
        if ((int)uVar17 < (int)uVar2) {
          uVar4 = (ulong)uVar13;
          FUN_001341f0(param_1,*(int *)(lVar1 + 0x10),uVar3,uVar13,(char)uVar11);
        }
        else {
          uVar4 = (ulong)param_4;
          FUN_001341f0(param_1,*(int *)(lVar1 + 0x10),uVar3,param_4,(char)uVar11);
          if (uVar2 == uVar17) {
            uVar5 = -uVar13;
          }
        }
        uVar17 = uVar17 + 1;
        *(uint *)(lVar1 + 0x24) = uVar5;
        lVar8 = lVar8 + 8;
        *(uint *)(lVar1 + 0x28) = uVar3;
        if (uVar17 == uVar15) break;
        plVar6 = *(long **)(param_1 + 8);
      }
    }
  }
  return;
}


/* FUN_001343c0 @ 0x1343c0 */

void FUN_001343c0(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  int iVar1;
  long *plVar2;
  uint *puVar3;
  long lVar4;
  uint *puVar5;
  ulong uVar6;
  code *pcVar7;
  ulong uVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  long lVar12;

  Vector_prune(*(long **)(param_1 + 0x10),param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  plVar2 = *(long **)(param_1 + 8);
  iVar1 = (int)plVar2[3];
  if (iVar1 < 1) {
    FUN_0012d260(*plVar2,0,iVar1 + -1,FUN_0012db60,param_r8,param_r9);
    *(undefined1 *)(param_1 + 0x30) = 0;
    return;
  }
  plVar2 = (long *)*plVar2;
  lVar11 = (long)iVar1 * 8;
  plVar10 = plVar2;
  do {
    lVar12 = *plVar10;
    uVar9 = *(uint *)(lVar12 + 0x14);
    if ((uVar9 == *(uint *)(lVar12 + 0x10)) &&
       (uVar9 = *(uint *)(lVar12 + 0x18), uVar9 == *(uint *)(lVar12 + 0x10))) {
      *(undefined1 *)(lVar12 + 0x1c) = 1;
    }
    else {
      *(undefined1 *)(lVar12 + 0x1c) = 0;
      if (uVar9 != 0) {
        param_r8 = **(ulong **)(param_1 + 0x18);
        puVar3 = (uint *)(*(ulong **)(param_1 + 0x18))[1];
        uVar8 = (ulong)uVar9 % (ulong)param_r8;
        if (*(long *)(puVar3 + uVar8 * 6 + 4) != 0) {
          uVar6 = 0;
          puVar5 = puVar3 + uVar8 * 6;
          do {
            while( true ) {
              if (uVar9 == *puVar5) goto LAB_00134484;
              if (*(ulong *)(puVar5 + 2) < uVar6) goto LAB_00134480;
              uVar8 = uVar8 + 1;
              if (param_r8 != uVar8) break;
              uVar8 = 0;
              uVar6 = uVar6 + 1;
              puVar5 = puVar3;
              if (*(long *)(puVar3 + 4) == 0) goto LAB_00134480;
            }
            uVar6 = uVar6 + 1;
            puVar5 = puVar3 + uVar8 * 6;
          } while (*(long *)(puVar5 + 4) != 0);
        }
      }
LAB_00134480:
      *(undefined1 *)(lVar12 + 0x1c) = 1;
    }
LAB_00134484:
    plVar10 = plVar10 + 1;
  } while (plVar2 + iVar1 != plVar10);
  pcVar7 = FUN_0012db60;
  FUN_0012d260((long)plVar2,0,iVar1 + -1,FUN_0012db60,param_r8,(long)plVar10);
  lVar12 = 0;
  do {
    while (lVar4 = *(long *)(**(long **)(param_1 + 8) + lVar12), *(char *)(lVar4 + 0x1c) == '\0') {
      lVar12 = lVar12 + 8;
      if (lVar11 == lVar12) goto LAB_00134500;
    }
    plVar2 = *(long **)(param_1 + 0x10);
    *(undefined8 *)(lVar4 + 0x24) = 0;
    lVar12 = lVar12 + 8;
    Vector_set(plVar2,(int)plVar2[3],lVar4,(long)pcVar7,param_r8,(long)plVar10);
    param_r8 = (long)*(byte *)(lVar4 + 0x20);
    pcVar7 = (code *)0x0;
    FUN_001341f0(param_1,*(int *)(lVar4 + 0x10),0,0,*(byte *)(lVar4 + 0x20));
  } while (lVar11 != lVar12);
LAB_00134500:
  *(undefined1 *)(param_1 + 0x30) = 0;
  return;
}


/* Table_collapseAllBranches @ 0x134550 */

void Table_collapseAllBranches
               (long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long *plVar4;

  FUN_001343c0(param_1,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  *(undefined1 *)(param_1 + 0x30) = 1;
  iVar2 = (int)(*(long **)(param_1 + 8))[3];
  if (0 < iVar2) {
    plVar4 = (long *)**(long **)(param_1 + 8);
    plVar1 = plVar4 + iVar2;
    do {
      lVar3 = *plVar4;
      if ((*(int *)(lVar3 + 0x28) != 0) && (1 < *(int *)(lVar3 + 0x10))) {
        *(undefined1 *)(lVar3 + 0x20) = 0;
      }
      plVar4 = plVar4 + 1;
    } while (plVar4 != plVar1);
  }
  return;
}


/* Table_updateDisplayList @ 0x1345b0 */

void Table_updateDisplayList
               (long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  long *a0;
  void *pvVar4;
  long *plVar5;
  long a3;
  int iVar6;
  long lVar7;
  long a2;
  long extraout_RDX;
  ulong a1;
  int iVar8;
  long lVar9;
  long lVar10;

  lVar7 = *(long *)(**(long **)(param_1 + 0x20) + 0x40);
  if (*(char *)(lVar7 + 0x34) == '\0') {
    if (*(char *)(param_1 + 0x30) != '\0') {
      Vector_insertionSort(*(long **)(param_1 + 8),param_rsi,lVar7,param_rcx,param_r8,param_r9);
      lVar7 = extraout_RDX;
    }
    Vector_prune(*(long **)(param_1 + 0x10),param_rsi,lVar7,param_rcx,param_r8,param_r9);
    plVar5 = *(long **)(param_1 + 8);
    lVar7 = plVar5[3];
    if (0 < (int)lVar7) {
      lVar10 = 0;
      do {
        plVar2 = *(long **)(param_1 + 0x10);
        uVar1 = *(uint *)(plVar2 + 3);
        a1 = (ulong)(int)plVar2[2];
        lVar3 = *(long *)(*plVar5 + lVar10);
        pvVar4 = (void *)*plVar2;
        iVar8 = uVar1 + 1;
        lVar9 = (long)(int)uVar1 * 8;
        if ((int)plVar2[2] < iVar8) {
          iVar6 = iVar8 + *(int *)((long)plVar2 + 0x14);
          a3 = 8;
          *(int *)(plVar2 + 2) = iVar6;
          pvVar4 = xReallocArrayZero(pvVar4,a1,(long)iVar6,8);
          *plVar2 = (long)pvVar4;
          if ((int)plVar2[3] <= (int)uVar1) goto LAB_00134630;
          plVar5 = (long *)((long)pvVar4 + lVar9);
          if ((*(char *)((long)plVar2 + 0x24) != '\0') && (a0 = (long *)*plVar5, a0 != (long *)0x0))
          {
            (**(code **)(*a0 + 0x10))((long)a0,a1,a2,a3,(ulong)uVar1,param_r9);
            plVar5 = (long *)(*plVar2 + lVar9);
          }
        }
        else {
LAB_00134630:
          *(int *)(plVar2 + 3) = iVar8;
          plVar5 = (long *)((long)pvVar4 + lVar9);
        }
        *plVar5 = lVar3;
        lVar10 = lVar10 + 8;
        if ((long)(int)lVar7 * 8 == lVar10) break;
        plVar5 = *(long **)(param_1 + 8);
      } while( true );
    }
  }
  else if (*(char *)(param_1 + 0x30) != '\0') {
    FUN_001343c0(param_1,param_rsi,lVar7,param_rcx,param_r8,param_r9);
  }
  *(undefined1 *)(param_1 + 0x30) = 0;
  return;
}


/* Table_rebuildPanel @ 0x134700 */

void Table_rebuildPanel(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                       long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char cVar1;
  int iVar2;
  code *a2;
  uint *puVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long lVar8;
  ulong a5;
  uint *puVar9;
  ulong *a3;
  ulong uVar10;
  uint uVar11;
  long extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong a2_00;
  ulong extraout_RDX_03;
  int iVar12;
  long lVar13;

  Table_updateDisplayList(param_1,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  lVar13 = *(long *)(param_1 + 0x38);
  uVar6 = *(uint *)(lVar13 + 0x28);
  iVar2 = *(int *)(lVar13 + 0x40);
  lVar4 = (*(long **)(lVar13 + 0x20))[3];
  Vector_prune(*(long **)(lVar13 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  *(undefined8 *)(lVar13 + 0x28) = 0;
  uVar11 = *(uint *)(param_1 + 0x34);
  a5 = (ulong)uVar11;
  *(undefined4 *)(lVar13 + 0x40) = 0;
  *(undefined1 *)(lVar13 + 0x48) = 1;
  if (uVar11 != 0xffffffff) {
    a3 = *(ulong **)(param_1 + 0x18);
    uVar10 = *a3;
    puVar3 = (uint *)a3[1];
    a2_00 = (ulong)uVar11 % uVar10;
    puVar9 = puVar3 + a2_00 * 6;
    plVar7 = *(long **)(puVar9 + 4);
    if (plVar7 != (long *)0x0) {
      a3 = (ulong *)0x0;
      do {
        if (uVar11 == *puVar9) {
          a5 = (ulong)*(uint *)((long)plVar7 + 0x14);
          a3 = (ulong *)0x0;
          a2_00 = a5 % uVar10;
          puVar9 = puVar3 + a2_00 * 6;
          if (*(long *)(puVar9 + 4) != 0) goto LAB_0013499f;
          break;
        }
        if (*(ulong **)(puVar9 + 2) < a3) break;
        a2_00 = a2_00 + 1;
        if (uVar10 == a2_00) {
          a2_00 = 0;
          puVar9 = puVar3;
        }
        else {
          puVar9 = puVar3 + a2_00 * 6;
        }
        plVar7 = *(long **)(puVar9 + 4);
        a3 = (ulong *)((long)a3 + 1);
      } while (plVar7 != (long *)0x0);
    }
    goto LAB_00134860;
  }
  plVar7 = *(long **)(param_1 + 0x10);
  (*(uint *)(__fp - 0x3c)) = *(uint *)(plVar7 + 3);
  a3 = (ulong *)(ulong)(*(uint *)(__fp - 0x3c));
  a2_00 = extraout_RDX_00;
  if (0 < (int)(*(uint *)(__fp - 0x3c))) goto LAB_0013476f;
  goto LAB_001349c0;
  while( true ) {
    if (*(ulong **)(puVar9 + 2) < a3) break;
    a2_00 = a2_00 + 1;
    if (uVar10 == a2_00) {
      a2_00 = 0;
      puVar9 = puVar3;
    }
    else {
      puVar9 = puVar3 + a2_00 * 6;
    }
    a3 = (ulong *)((long)a3 + 1);
    if (*(long *)(puVar9 + 4) == 0) break;
LAB_0013499f:
    if (*(uint *)((long)plVar7 + 0x14) == *puVar9) {
      if (*(code **)(*plVar7 + 0x28) != (code *)0x0) {
        lVar13 = (**(code **)(*plVar7 + 0x28))((long)plVar7,param_1,a2_00,(long)a3,param_r8,a5);
        if ((char)lVar13 == '\0') {
          *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)((long)plVar7 + 0x14);
        }
        plVar7 = *(long **)(param_1 + 0x10);
        (*(uint *)(__fp - 0x3c)) = *(uint *)(plVar7 + 3);
        a3 = (ulong *)(ulong)(*(uint *)(__fp - 0x3c));
        a2_00 = extraout_RDX_03;
        if (0 < (int)(*(uint *)(__fp - 0x3c))) goto LAB_0013476f;
        (*(char *)(__fp - 0x41)) = '\0';
        goto LAB_001347dd;
      }
      break;
    }
  }
LAB_00134860:
  plVar7 = *(long **)(param_1 + 0x10);
  (*(uint *)(__fp - 0x3c)) = *(uint *)(plVar7 + 3);
  if ((int)(*(uint *)(__fp - 0x3c)) < 1) {
LAB_00134878:
    plVar7 = *(long **)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
    *(undefined4 *)(plVar7 + 0x4db) = 9;
    goto LAB_0013488e;
  }
LAB_0013476f:
  (*(char *)(__fp - 0x41)) = '\0';
  lVar13 = 0;
  iVar12 = 0;
  while( true ) {
    plVar7 = *(long **)(*plVar7 + lVar13 * 8);
    cVar1 = *(char *)((long)plVar7 + 0x1e);
    if ((cVar1 != '\0') &&
       ((*(code **)(*plVar7 + 0x38) == (code *)0x0 ||
        (lVar8 = (**(code **)(*plVar7 + 0x38))((long)plVar7,param_1,a2_00,(long)a3,param_r8,a5),
        a2_00 = extraout_RDX_01, (char)lVar8 == '\0')))) {
      Vector_set(*(long **)(*(long *)(param_1 + 0x38) + 0x20),iVar12,(long)plVar7,(long)a3,param_r8,
                 a5);
      a2_00 = extraout_RDX_02;
      if ((*(int *)(param_1 + 0x34) != -1) && (*(int *)(param_1 + 0x34) == (int)plVar7[2])) {
        plVar7 = *(long **)(param_1 + 0x38);
        iVar5 = *(int *)(plVar7[4] + 0x18) + -1;
        if (iVar12 < *(int *)(plVar7[4] + 0x18)) {
          iVar5 = iVar12;
        }
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        *(int *)(plVar7 + 5) = iVar5;
        if (*(code **)(*plVar7 + 0x20) != (code *)0x0) {
          (**(code **)(*plVar7 + 0x20))((long)plVar7,0xffffffff,0,(long)a3,param_r8,a5);
          plVar7 = *(long **)(param_1 + 0x38);
        }
        uVar11 = uVar6 - iVar2;
        a2_00 = (ulong)uVar11;
        *(uint *)(plVar7 + 8) = iVar12 - uVar11;
        (*(char *)(__fp - 0x41)) = cVar1;
      }
      iVar12 = iVar12 + 1;
    }
    lVar13 = lVar13 + 1;
    if ((int)(*(uint *)(__fp - 0x3c)) <= (int)lVar13) break;
    plVar7 = *(long **)(param_1 + 0x10);
  }
LAB_001347dd:
  if (*(int *)(param_1 + 0x34) != -1) {
    if ((*(char *)(__fp - 0x41)) == '\0') goto LAB_00134878;
    if (*(int *)(param_1 + 0x34) != -1) {
      return;
    }
  }
LAB_001349c0:
  plVar7 = *(long **)(param_1 + 0x38);
LAB_0013488e:
  iVar12 = *(int *)(plVar7[4] + 0x18);
  a2 = *(code **)(*plVar7 + 0x20);
  if (((int)uVar6 < 1) || ((int)lVar4 - 1U != uVar6)) {
    uVar11 = iVar12 - 1;
    if ((int)uVar6 < iVar12) {
      uVar11 = uVar6;
    }
    uVar10 = (ulong)uVar11;
    uVar6 = 0;
    if (-1 < (int)uVar11) {
      uVar6 = uVar11;
    }
    *(uint *)(plVar7 + 5) = uVar6;
  }
  else {
    iVar12 = iVar12 + -1;
    uVar10 = 0;
    if (iVar12 < 0) {
      iVar12 = 0;
    }
    *(int *)(plVar7 + 5) = iVar12;
  }
  if (a2 != (code *)0x0) {
    (*a2)((long)plVar7,0xffffffff,(long)a2,uVar10,param_r8,a5);
    plVar7 = *(long **)(param_1 + 0x38);
  }
  *(int *)(plVar7 + 8) = iVar2;
  return;
}

