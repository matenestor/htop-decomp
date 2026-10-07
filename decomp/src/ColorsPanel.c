#include "htop.h"

/* ColorsPanel_new @ 0x118c50 */

/* WARNING: Removing unreachable block (ram,0x00118cfa) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00118d17 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * ColorsPanel_new(long param_1)

{
  undefined1 __frame[0x118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xd8;
  uint uVar1;
  wchar_t __wc;
  long *plVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  size_t sVar7;
  undefined8 *puVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  undefined1 *puVar12;
  undefined1 (*pauVar13) [16];
  wchar_t *pwVar14;
  undefined **ppuVar15;
  char *pcVar16;
  long in_FS_OFFSET = (long)__fake_fs;

  plVar10 = &(*(long *)(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(long *)(__fp - 0x68)) = param_1;
  puVar5 = malloc(0x26e8);
  if (puVar5 != (undefined8 *)0x0) {
    *puVar5 = ColorsPanel_class;
    puVar6 = FunctionBar_new(&PTR_DAT_00155e40,0,0);
    lVar11 = 1;
    lVar9 = 1;
    puVar12 = CheckItem_class;
    Panel_init((long)puVar5,1,1,1,1,CheckItem_class,1,puVar6);
    puVar5[0x4dc] = (*(long *)(__fp - 0x68));
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined1 * *)(__fp - 0x60)) = (undefined1 *)&(*(long *)(__fp - 0x68));
    pwVar14 = (*(wchar_t (*)[4])(__fp - 0x88));
    (*(undefined1 * *)(__fp - 0x60)) = (undefined1 *)&(*(long *)(__fp - 0x68));
    sVar7 = mbstowcs((*(wchar_t (*)[4])(__fp - 0x88)),((char *)(long)&s_Colors_00147246 /* "Colors" */),6);
    iVar4 = (int)sVar7;
    if (0 < iVar4) {
      FUN_00130130((int *)(puVar5 + 0xc),iVar4);
      (*(uint *)(__fp - 0x54)) = uVar1 & 0xffffff;
      (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[4])(__fp - 0x88)) + (ulong)(iVar4 - 1) + 1;
      pauVar13 = (undefined1 (*) [16])puVar5[0xd];
      do {
        __wc = *pwVar14;
        iVar4 = iswprint(__wc);
        *(undefined16 *)(*pauVar13) = (undefined16)0x0;
        if (iVar4 == 0) {
          __wc = L'�';
        }
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar13 + 0xc)) = (undefined16)0x0;
        pwVar14 = pwVar14 + 1;
        *(uint *)*pauVar13 = (*(uint *)(__fp - 0x54));
        *(wchar_t *)(*pauVar13 + 4) = __wc;
        pauVar13 = (undefined1 (*) [16])(pauVar13[1] + 0xc);
      } while ((*(wchar_t * *)(__fp - 0x50)) != pwVar14);
    }
    plVar10 = (long *)(*(undefined1 * *)(__fp - 0x60));
    *(undefined1 *)(puVar5 + 9) = 1;
    pcVar16 = ((char *)(long)&s_Default_0014723e /* "Default" */);
    ppuVar15 = &PTR_s_Monochromatic_00155ea8;
    while( true ) {
      puVar8 = malloc(0x20);
      if (puVar8 == (undefined8 *)0x0) break;
      *puVar8 = CheckItem_class;
      pcVar16 = strdup(pcVar16);
      if (pcVar16 == (char *)0x0) break;
      plVar2 = (long *)puVar5[4];
      puVar8[1] = pcVar16;
      *(undefined1 *)(puVar8 + 3) = 0;
      puVar8[2] = 0;
      lVar3 = plVar2[3];
      Vector_set(plVar2,(int)lVar3,(long)puVar8,lVar9,lVar11,(long)puVar12);
      pcVar16 = *ppuVar15;
      *(undefined1 *)(puVar5 + 9) = 1;
      ppuVar15 = ppuVar15 + 1;
      if (pcVar16 == (char *)0x0) {
        lVar9 = *(long *)(*(long *)puVar5[4] + (long)*(int *)((*(long *)(__fp - 0x68)) + 0x48) * 8);
        puVar12 = *(undefined1 **)(lVar9 + 0x10);
        if (puVar12 == (undefined1 *)0x0) {
          *(undefined1 *)(lVar9 + 0x18) = 1;
        }
        else {
          *puVar12 = 1;
        }
        if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return puVar5;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00118e70 @ 0x118e70 */

void FUN_00118e70(long param_1)

{
  undefined8 *puVar1;

  puVar1 = ColorsPanel_new(**(long **)(param_1 + 0x26e8));
  ScreenManager_insert
            (*(int **)(param_1 + 0x26e0),(long)puVar1,-1,
             *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
  return;
}

