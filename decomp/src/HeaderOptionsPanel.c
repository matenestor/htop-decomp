#include "htop.h"

/* HeaderOptionsPanel_new @ 0x127050 */

/* WARNING: Removing unreachable block (ram,0x00127103) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00127120 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * HeaderOptionsPanel_new(undefined8 param_1,long param_2)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  uint uVar1;
  wchar_t __wc;
  long *plVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  undefined8 *puVar9;
  char *pcVar10;
  long lVar11;
  undefined1 (*pauVar12) [16];
  undefined **ppuVar13;
  undefined1 *puVar14;
  long lVar15;
  undefined1 *puVar16;
  wchar_t *pwVar17;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar14 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(long *)(__fp - 0x60)) = param_2;
  puVar6 = malloc(0x26f0);
  if (puVar6 != (undefined8 *)0x0) {
    *puVar6 = HeaderOptionsPanel_class;
    puVar7 = FunctionBar_new(&PTR_DAT_00157ca0,0,0);
    puVar16 = CheckItem_class;
    lVar15 = 1;
    lVar11 = 1;
    Panel_init((long)puVar6,1,1,1,1,CheckItem_class,1,puVar7);
    puVar6[0x4dd] = param_1;
    puVar6[0x4dc] = (*(long *)(__fp - 0x60));
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined1 * *)(__fp - 0x58)) = (*(undefined1 (*)[8])(__fp - 0x68));
    pwVar17 = (*(wchar_t (*)[12])(__fp - 0xa8));
    (*(undefined1 * *)(__fp - 0x58)) = (*(undefined1 (*)[8])(__fp - 0x68));
    sVar8 = mbstowcs((*(wchar_t (*)[12])(__fp - 0xa8)),((char *)(long)&s_Header_Layout_0014882e /* "Header Layout" */),0xd);
    iVar4 = (int)sVar8;
    if (0 < iVar4) {
      FUN_00130130((int *)(puVar6 + 0xc),iVar4);
      (*(uint *)(__fp - 0x4c)) = uVar1 & 0xffffff;
      pauVar12 = (undefined1 (*) [16])puVar6[0xd];
      do {
        __wc = *pwVar17;
        iVar5 = iswprint(__wc);
        *(undefined16 *)(*pauVar12) = (undefined16)0x0;
        if (iVar5 == 0) {
          __wc = L'�';
        }
        pwVar17 = pwVar17 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar12 + 0xc)) = (undefined16)0x0;
        *(uint *)*pauVar12 = (*(uint *)(__fp - 0x4c));
        *(wchar_t *)(*pauVar12 + 4) = __wc;
        pauVar12 = (undefined1 (*) [16])(pauVar12[1] + 0xc);
      } while (pwVar17 != (*(wchar_t (*)[12])(__fp - 0xa8)) + (ulong)(iVar4 - 1) + 1);
    }
    puVar14 = (*(undefined1 * *)(__fp - 0x58));
    *(undefined1 *)(puVar6 + 9) = 1;
    ppuVar13 = &PTR_s_2_columns___50_50__default__00155fb0;
    while( true ) {
      pcVar10 = *ppuVar13;
      puVar9 = malloc(0x20);
      if (puVar9 == (undefined8 *)0x0) break;
      *puVar9 = CheckItem_class;
      pcVar10 = strdup(pcVar10);
      if (pcVar10 == (char *)0x0) break;
      plVar2 = (long *)puVar6[4];
      puVar9[1] = pcVar10;
      ppuVar13 = ppuVar13 + 3;
      *(undefined1 *)(puVar9 + 3) = 0;
      puVar9[2] = 0;
      lVar3 = plVar2[3];
      Vector_set(plVar2,(int)lVar3,(long)puVar9,lVar11,lVar15,(long)puVar16);
      *(undefined1 *)(puVar6 + 9) = 1;
      if (ppuVar13 == &PTR_DAT_001560d0) {
        lVar11 = *(long *)(*(long *)puVar6[4] +
                          (long)*(int *)(*(long *)((*(long *)(__fp - 0x60)) + 0x28) + 0x10) * 8);
        puVar16 = *(undefined1 **)(lVar11 + 0x10);
        if (puVar16 == (undefined1 *)0x0) {
          *(undefined1 *)(lVar11 + 0x18) = 1;
        }
        else {
          *puVar16 = 1;
        }
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

