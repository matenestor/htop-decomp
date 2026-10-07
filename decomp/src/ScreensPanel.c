#include "htop.h"

/* ScreensPanel_update @ 0x1322e0 */

void ScreensPanel_update(long param_1)

{
  size_t __size;
  void *__ptr;
  undefined8 *puVar1;
  char *__s1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;

  lVar5 = *(long *)(param_1 + 0x26e8);
  iVar2 = *(int *)(*(long *)(param_1 + 0x20) + 0x18);
  __ptr = *(void **)(lVar5 + 0x30);
  *(undefined1 *)(lVar5 + 0x74) = 1;
  *(long *)(lVar5 + 0x78) = *(long *)(lVar5 + 0x78) + 1;
  uVar6 = (ulong)(iVar2 + 1);
  if (uVar6 >> 0x3d == 0) {
    __size = uVar6 * 8;
    pvVar3 = realloc(__ptr,__size);
    if (pvVar3 != (void *)0x0) {
      *(void **)(lVar5 + 0x30) = pvVar3;
      if (iVar2 < 1) {
        lVar5 = *(long *)(*(long *)(param_1 + 0x26e8) + 0x30);
      }
      else {
        lVar7 = 0;
        do {
          lVar5 = *(long *)(**(long **)(param_1 + 0x20) + lVar7);
          puVar1 = *(undefined8 **)(lVar5 + 0x20);
          pcVar4 = *(char **)(lVar5 + 8);
          __s1 = (char *)*puVar1;
          if (__s1 == (char *)0x0) {
LAB_00132393:
            free(__s1);
            pcVar4 = strdup(pcVar4);
            if (pcVar4 == (char *)0x0) goto LAB_001323fd;
            *puVar1 = pcVar4;
          }
          else {
            iVar2 = strcmp(__s1,pcVar4);
            if (iVar2 != 0) goto LAB_00132393;
          }
          lVar5 = *(long *)(*(long *)(param_1 + 0x26e8) + 0x30);
          *(undefined8 **)(lVar5 + lVar7) = puVar1;
          lVar7 = lVar7 + 8;
        } while (__size - 8 != lVar7);
      }
      *(undefined8 *)(lVar5 + -8 + __size) = 0;
      return;
    }
    free(__ptr);
  }
LAB_001323fd:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ScreensPanel_new @ 0x133710 */

/* WARNING: Removing unreachable block (ram,0x00133816) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133833 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * ScreensPanel_new(long param_1)

{
  undefined1 __frame[0x118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xd8;
  uint uVar1;
  wchar_t __wc;
  ulong *puVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  size_t sVar9;
  wchar_t *pwVar10;
  char *pcVar11;
  undefined1 *puVar12;
  undefined **ppuVar13;
  long lVar14;
  undefined1 *puVar15;
  undefined1 (*pauVar16) [16];
  long lVar17;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar12 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar6 = malloc(0x2730);
  if (puVar6 == (undefined8 *)0x0) {
LAB_00133964:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  lVar17 = *(long *)(param_1 + 0x28);
  puVar2 = *(ulong **)(param_1 + 0x18);
  ppuVar13 = &PTR_DAT_001580a0;
  *puVar6 = ScreensPanel_class;
  if (lVar17 != 0) {
    ppuVar13 = &PTR_DAT_00158100;
  }
  puVar7 = FunctionBar_new(ppuVar13,0,0);
  puVar15 = ListItem_class;
  lVar14 = 1;
  Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
  plVar3 = *(long **)(param_1 + 0x30);
  puVar6[0x4dd] = param_1;
  puVar8 = ColumnsPanel_new(*plVar3,puVar2,param_1 + 0x74);
  puVar6[0x4de] = puVar8;
  puVar8 = AvailableColumnsPanel_new(puVar8,puVar2);
  *(undefined1 *)((long)puVar6 + 0x2724) = 0;
  puVar6[0x4df] = puVar8;
  *(undefined4 *)(puVar6 + 0x4e4) = 0;
  lVar17 = CRT_colors;
  *(undefined1 *)((long)puVar6 + 0x49) = 0;
  puVar6[0x4e5] = 0;
  uVar1 = *(uint *)(lVar17 + 0x1c);
  (*(undefined1 * *)(__fp - 0x60)) = (*(undefined1 (*)[8])(__fp - 0x68));
  pwVar10 = (*(wchar_t (*)[4])(__fp - 0x88));
  (*(undefined1 * *)(__fp - 0x60)) = (*(undefined1 (*)[8])(__fp - 0x68));
  sVar9 = mbstowcs((*(wchar_t (*)[4])(__fp - 0x88)),((char *)(long)&s_Screens_00147c87 /* "Screens" */),7);
  iVar5 = (int)sVar9;
  if (0 < iVar5) {
    FUN_00130130((int *)(puVar6 + 0xc),iVar5);
    (*(uint *)(__fp - 0x54)) = uVar1 & 0xffffff;
    (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[4])(__fp - 0x88)) + (ulong)(iVar5 - 1) + 1;
    pauVar16 = (undefined1 (*) [16])puVar6[0xd];
    do {
      __wc = *pwVar10;
      iVar5 = iswprint(__wc);
      *(undefined16 *)(*pauVar16) = (undefined16)0x0;
      if (iVar5 == 0) {
        __wc = L'�';
      }
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar16 + 0xc)) = (undefined16)0x0;
      pwVar10 = pwVar10 + 1;
      *(uint *)*pauVar16 = (*(uint *)(__fp - 0x54));
      *(wchar_t *)(*pauVar16 + 4) = __wc;
      pauVar16 = (undefined1 (*) [16])(pauVar16[1] + 0xc);
    } while ((*(wchar_t * *)(__fp - 0x50)) != pwVar10);
  }
  puVar12 = (*(undefined1 * *)(__fp - 0x60));
  iVar5 = *(int *)(param_1 + 0x38);
  *(undefined1 *)(puVar6 + 9) = 1;
  lVar17 = 0;
  if (iVar5 != 0) {
    do {
      puVar8 = *(undefined8 **)(*(long *)(param_1 + 0x30) + lVar17 * 8);
      pcVar11 = (char *)*puVar8;
      pwVar10 = malloc(0x28);
      if (pwVar10 == (wchar_t *)0x0) goto LAB_00133964;
      *(undefined1 **)pwVar10 = ScreenListItem_class;
      (*(wchar_t * *)(__fp - 0x50)) = pwVar10;
      pcVar11 = strdup(pcVar11);
      pwVar10 = (*(wchar_t * *)(__fp - 0x50));
      if (pcVar11 == (char *)0x0) goto LAB_00133964;
      plVar3 = (long *)puVar6[4];
      lVar17 = lVar17 + 1;
      *(char **)((*(wchar_t * *)(__fp - 0x50)) + 2) = pcVar11;
      lVar4 = plVar3[3];
      (*(wchar_t * *)(__fp - 0x50))[4] = L'\0';
      *(undefined1 *)((*(wchar_t * *)(__fp - 0x50)) + 5) = 0;
      *(undefined8 **)((*(wchar_t * *)(__fp - 0x50)) + 8) = puVar8;
      Vector_set(plVar3,(int)lVar4,(long)pwVar10,(long)puVar7,lVar14,(long)puVar15);
      *(undefined1 *)(puVar6 + 9) = 1;
    } while ((uint)lVar17 < *(uint *)(param_1 + 0x38));
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}

