#include "htop.h"

/* CategoriesPanel_new @ 0x118a20 */

/* WARNING: Removing unreachable block (ram,0x00118adb) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00118af8 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * CategoriesPanel_new(int *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  uint uVar1;
  wchar_t __wc;
  long *plVar2;
  long lVar3;
  int *piVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  undefined8 *puVar9;
  char *pcVar10;
  long lVar11;
  undefined1 *puVar12;
  long lVar13;
  undefined1 *puVar14;
  undefined **ppuVar15;
  undefined1 (*pauVar16) [16];
  wchar_t *pwVar17;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar12 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(int * *)(__fp - 0x60)) = param_1;
  puVar6 = malloc(0x26f8);
  if (puVar6 != (undefined8 *)0x0) {
    *puVar6 = CategoriesPanel_class;
    puVar7 = FunctionBar_new(&PTR_DAT_00155ee0,0,0);
    puVar14 = ListItem_class;
    lVar13 = 1;
    lVar11 = 1;
    Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
    puVar6[0x4de] = param_2;
    puVar6[0x4dd] = param_3;
    puVar6[0x4dc] = (*(int * *)(__fp - 0x60));
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined1 * *)(__fp - 0x58)) = (*(undefined1 (*)[8])(__fp - 0x68));
    pwVar17 = (*(wchar_t (*)[8])(__fp - 0x98));
    (*(undefined1 * *)(__fp - 0x58)) = (*(undefined1 (*)[8])(__fp - 0x68));
    sVar8 = mbstowcs((*(wchar_t (*)[8])(__fp - 0x98)),((char *)(long)&s_Categories_00147233 /* "Categories" */),10);
    iVar5 = (int)sVar8;
    if (0 < iVar5) {
      FUN_00130130((int *)(puVar6 + 0xc),iVar5);
      (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[8])(__fp - 0x98)) + (ulong)(iVar5 - 1) + 1;
      pauVar16 = (undefined1 (*) [16])puVar6[0xd];
      do {
        __wc = *pwVar17;
        iVar5 = iswprint(__wc);
        *(undefined16 *)(*pauVar16) = (undefined16)0x0;
        if (iVar5 == 0) {
          __wc = L'�';
        }
        pwVar17 = pwVar17 + 1;
        *(uint *)*pauVar16 = uVar1 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar16 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar16 + 4) = __wc;
        pauVar16 = (undefined1 (*) [16])(pauVar16[1] + 0xc);
      } while (pwVar17 != (*(wchar_t * *)(__fp - 0x50)));
    }
    puVar12 = (*(undefined1 * *)(__fp - 0x58));
    *(undefined1 *)(puVar6 + 9) = 1;
    ppuVar15 = &PTR_s_Display_options_00155f40;
    while( true ) {
      pcVar10 = *ppuVar15;
      puVar9 = malloc(0x18);
      if (puVar9 == (undefined8 *)0x0) break;
      *puVar9 = ListItem_class;
      pcVar10 = strdup(pcVar10);
      if (pcVar10 == (char *)0x0) break;
      plVar2 = (long *)puVar6[4];
      puVar9[1] = pcVar10;
      ppuVar15 = ppuVar15 + 2;
      *(undefined4 *)(puVar9 + 2) = 0;
      *(undefined1 *)((long)puVar9 + 0x14) = 0;
      lVar3 = plVar2[3];
      Vector_set(plVar2,(int)lVar3,(long)puVar9,lVar11,lVar13,(long)puVar14);
      piVar4 = (*(int * *)(__fp - 0x60));
      *(undefined1 *)(puVar6 + 9) = 1;
      if (ppuVar15 == (undefined **)&DAT_00155f90) {
        iVar5 = *(int *)(*(long *)((*(int * *)(__fp - 0x60)) + 4) + 0x18);
        ScreenManager_insert(piVar4,(long)puVar6,0x10,iVar5);
        FUN_00119aa0((long)puVar6);
        if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return puVar6;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

