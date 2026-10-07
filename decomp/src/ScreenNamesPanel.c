#include "htop.h"

/* ScreenNamesPanel_new @ 0x133970 */

/* WARNING: Removing unreachable block (ram,0x00133a58) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133a75 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * ScreenNamesPanel_new(long param_1)

{
  undefined1 __frame[0x118] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xd8;
  uint uVar1;
  wchar_t __wc;
  undefined8 *puVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  undefined8 *puVar9;
  char *pcVar10;
  undefined1 *puVar11;
  long lVar12;
  undefined1 *puVar13;
  undefined1 (*pauVar14) [16];
  long lVar15;
  wchar_t *pwVar16;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar11 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar6 = malloc(0x2728);
  if (puVar6 == (undefined8 *)0x0) {
LAB_00133bc0:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *puVar6 = ScreenNamesPanel_class;
  puVar7 = FunctionBar_new(&PTR_DAT_00157fe0,0,0);
  puVar13 = ListItem_class;
  lVar12 = 1;
  Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
  *(undefined4 *)(puVar6 + 0x4e3) = 0;
  *(undefined16 *)(*(undefined1 (*) [16])(puVar6 + 0x4de)) = (undefined16)0x0;
  lVar15 = CRT_colors;
  puVar6[0x4dd] = param_1;
  *(undefined8 *)((long)puVar6 + 0x26fd) = 0;
  *(undefined16 *)(*(undefined1 (*) [16])(puVar6 + 0x4e1)) = (undefined16)0x0;
  uVar1 = *(uint *)(lVar15 + 0x1c);
  puVar6[0x4e4] = 0;
  *(undefined1 *)((long)puVar6 + 0x49) = 0;
  (*(undefined1 * *)(__fp - 0x60)) = (*(undefined1 (*)[8])(__fp - 0x68));
  pwVar16 = (*(wchar_t (*)[4])(__fp - 0x88));
  (*(undefined1 * *)(__fp - 0x60)) = (*(undefined1 (*)[8])(__fp - 0x68));
  sVar8 = mbstowcs((*(wchar_t (*)[4])(__fp - 0x88)),((char *)(long)&s_Screens_00147c87 /* "Screens" */),7);
  iVar5 = (int)sVar8;
  if (0 < iVar5) {
    FUN_00130130((int *)(puVar6 + 0xc),iVar5);
    (*(uint *)(__fp - 0x54)) = uVar1 & 0xffffff;
    (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[4])(__fp - 0x88)) + (ulong)(iVar5 - 1) + 1;
    pauVar14 = (undefined1 (*) [16])puVar6[0xd];
    do {
      __wc = *pwVar16;
      iVar5 = iswprint(__wc);
      *(undefined16 *)(*pauVar14) = (undefined16)0x0;
      if (iVar5 == 0) {
        __wc = L'�';
      }
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar14 + 0xc)) = (undefined16)0x0;
      pwVar16 = pwVar16 + 1;
      *(uint *)*pauVar14 = (*(uint *)(__fp - 0x54));
      *(wchar_t *)(*pauVar14 + 4) = __wc;
      pauVar14 = (undefined1 (*) [16])(pauVar14[1] + 0xc);
    } while ((*(wchar_t * *)(__fp - 0x50)) != pwVar16);
  }
  puVar11 = (*(undefined1 * *)(__fp - 0x60));
  iVar5 = *(int *)(param_1 + 0x38);
  *(undefined1 *)(puVar6 + 9) = 1;
  lVar15 = 0;
  if (iVar5 != 0) {
    do {
      while (puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x30) + lVar15 * 8), puVar2[1] == 0) {
        (*(wchar_t * *)(__fp - 0x50)) = (wchar_t *)*puVar2;
        puVar9 = malloc(0x20);
        pwVar16 = (*(wchar_t * *)(__fp - 0x50));
        if (puVar9 == (undefined8 *)0x0) goto LAB_00133bc0;
        *puVar9 = ScreenNameListItem_class;
        pcVar10 = strdup((char *)pwVar16);
        if (pcVar10 == (char *)0x0) goto LAB_00133bc0;
        plVar3 = (long *)puVar6[4];
        puVar9[1] = pcVar10;
        lVar15 = lVar15 + 1;
        *(undefined4 *)(puVar9 + 2) = 0;
        *(undefined1 *)((long)puVar9 + 0x14) = 0;
        lVar4 = plVar3[3];
        puVar9[3] = puVar2;
        Vector_set(plVar3,(int)lVar4,(long)puVar9,(long)puVar7,lVar12,(long)puVar13);
        *(undefined1 *)(puVar6 + 9) = 1;
        if (*(uint *)(param_1 + 0x38) <= (uint)lVar15) goto LAB_00133b9f;
      }
      lVar15 = lVar15 + 1;
    } while ((uint)lVar15 < *(uint *)(param_1 + 0x38));
  }
LAB_00133b9f:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return puVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

