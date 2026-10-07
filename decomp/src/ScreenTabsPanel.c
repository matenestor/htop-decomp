#include "htop.h"

/* ScreenTabsPanel_new @ 0x133bd0 */

/* WARNING: Removing unreachable block (ram,0x00133c94) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133cb1 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * ScreenTabsPanel_new(long param_1)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  uint uVar1;
  wchar_t __wc;
  long *plVar2;
  ulong *puVar3;
  long lVar4;
  wchar_t *__s;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  size_t sVar9;
  char *pcVar10;
  wchar_t *pwVar11;
  undefined1 *puVar12;
  long lVar13;
  undefined1 *puVar14;
  wchar_t *pwVar15;
  undefined1 (*pauVar16) [16];
  ulong uVar17;
  long in_FS_OFFSET = (long)__fake_fs;
  long lVar18;

  puVar12 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(long *)(__fp - 0x60)) = param_1;
  puVar6 = malloc(0x2700);
  if (puVar6 != (undefined8 *)0x0) {
    *puVar6 = ScreenTabsPanel_class;
    puVar7 = FunctionBar_new(&PTR_DAT_00158040,0,0);
    puVar14 = ListItem_class;
    lVar13 = 1;
    lVar18 = 1;
    Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
    puVar6[0x4dd] = (*(long *)(__fp - 0x60));
    puVar8 = ScreenNamesPanel_new((*(long *)(__fp - 0x60)));
    *(undefined1 *)((long)puVar6 + 0x49) = 0;
    puVar6[0x4de] = puVar8;
    *(undefined4 *)(puVar6 + 0x4df) = 0;
    (*(undefined1 * *)(__fp - 0x58)) = (*(undefined1 (*)[8])(__fp - 0x68));
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    pwVar15 = (*(wchar_t (*)[8])(__fp - 0x98));
    (*(undefined1 * *)(__fp - 0x58)) = (*(undefined1 (*)[8])(__fp - 0x68));
    sVar9 = mbstowcs((*(wchar_t (*)[8])(__fp - 0x98)),((char *)(long)&s_Screen_tabs_0014917a /* "Screen tabs" */),0xb);
    iVar5 = (int)sVar9;
    if (0 < iVar5) {
      FUN_00130130((int *)(puVar6 + 0xc),iVar5);
      (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[8])(__fp - 0x98)) + (ulong)(iVar5 - 1) + 1;
      pauVar16 = (undefined1 (*) [16])puVar6[0xd];
      do {
        __wc = *pwVar15;
        iVar5 = iswprint(__wc);
        *(undefined16 *)(*pauVar16) = (undefined16)0x0;
        if (iVar5 == 0) {
          __wc = L'�';
        }
        pwVar15 = pwVar15 + 1;
        *(uint *)*pauVar16 = uVar1 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar16 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar16 + 4) = __wc;
        pauVar16 = (undefined1 (*) [16])(pauVar16[1] + 0xc);
      } while (pwVar15 != (*(wchar_t * *)(__fp - 0x50)));
    }
    puVar12 = (*(undefined1 * *)(__fp - 0x58));
    *(undefined1 *)(puVar6 + 9) = 1;
    puVar8 = malloc(0x20);
    if (puVar8 != (undefined8 *)0x0) {
      *puVar8 = ScreenTabListItem_class;
      pcVar10 = strdup(((char *)(long)&s_Processes_00149186 /* "Processes" */));
      if (pcVar10 != (char *)0x0) {
        plVar2 = (long *)puVar6[4];
        puVar8[1] = pcVar10;
        uVar17 = 0;
        *(undefined4 *)(puVar8 + 2) = 0;
        *(undefined1 *)((long)puVar8 + 0x14) = 0;
        lVar4 = plVar2[3];
        puVar8[3] = 0;
        Vector_set(plVar2,(int)lVar4,(long)puVar8,lVar18,lVar13,(long)puVar14);
        *(undefined1 *)(puVar6 + 9) = 1;
        puVar3 = *(ulong **)((*(long *)(__fp - 0x60)) + 0x28);
        if (*puVar3 != 0) {
          do {
            pwVar15 = *(wchar_t **)(puVar3[1] + uVar17 * 0x18 + 0x10);
            if (pwVar15 != (wchar_t *)0x0) {
              pwVar11 = *(wchar_t **)(pwVar15 + 8);
              if (*(wchar_t **)(pwVar15 + 8) == (wchar_t *)0x0) {
                pwVar11 = pwVar15;
              }
              (*(wchar_t * *)(__fp - 0x50)) = pwVar11;
              puVar8 = malloc(0x20);
              __s = (*(wchar_t * *)(__fp - 0x50));
              if (puVar8 == (undefined8 *)0x0) goto LAB_00133e6a;
              *puVar8 = ScreenTabListItem_class;
              pcVar10 = strdup((char *)__s);
              if (pcVar10 == (char *)0x0) goto LAB_00133e6a;
              plVar2 = (long *)puVar6[4];
              puVar8[1] = pcVar10;
              *(undefined4 *)(puVar8 + 2) = 0;
              *(undefined1 *)((long)puVar8 + 0x14) = 0;
              lVar18 = plVar2[3];
              puVar8[3] = pwVar15;
              Vector_set(plVar2,(int)lVar18,(long)puVar8,(long)pwVar11,lVar13,(long)puVar14);
              *(undefined1 *)(puVar6 + 9) = 1;
            }
            uVar17 = uVar17 + 1;
          } while (uVar17 < *puVar3);
        }
        if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return puVar6;
      }
    }
  }
LAB_00133e6a:
                    /* WARNING: Subroutine does not return */
  fail();
}

