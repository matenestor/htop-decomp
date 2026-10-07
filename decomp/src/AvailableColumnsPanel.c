#include "htop.h"

/* AvailableColumnsPanel_fill @ 0x11bb80 */

void AvailableColumnsPanel_fill
               (long param_1,long param_2,ulong *param_3,long param_rcx,long param_r8,long param_r9)

{
  undefined4 *puVar1;
  long extraout_RDX;
  long lVar2;
  ulong uVar3;

  lVar2 = param_2;
  Vector_prune(*(long **)(param_1 + 0x20),param_2,(long)param_3,param_rcx,param_r8,param_r9);
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x48) = 1;
  if (param_2 == 0) {
    FUN_0011ba60(param_1,lVar2,extraout_RDX,param_rcx,param_r8,param_r9);
    uVar3 = 0;
    if (*param_3 != 0) {
      do {
        puVar1 = (undefined4 *)(param_3[1] + uVar3 * 0x18);
        lVar2 = *(long *)(puVar1 + 4);
        if (lVar2 != 0) {
          FUN_0011b960(*puVar1,lVar2,param_1,param_rcx,param_r8,param_r9);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *param_3);
      return;
    }
  }
  return;
}


/* AvailableColumnsPanel_new @ 0x11bc20 */

/* WARNING: Removing unreachable block (ram,0x0011bcbf) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x0011bcdc */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * AvailableColumnsPanel_new(undefined8 param_1,ulong *param_2)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  uint uVar1;
  wchar_t __wc;
  undefined4 uVar2;
  long *plVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  long lVar9;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar10;
  long extraout_RDX_01;
  ulong uVar11;
  long lVar12;
  undefined1 *puVar13;
  undefined1 (*pauVar14) [16];
  ulong uVar15;
  wchar_t *pwVar16;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x68)) = param_1;
  puVar6 = malloc(0x26e8);
  if (puVar6 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *puVar6 = AvailableColumnsPanel_class;
  puVar7 = FunctionBar_new(&PTR_DAT_001560c0,0,0);
  puVar13 = ListItem_class;
  lVar12 = 1;
  lVar9 = 1;
  Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
  uVar1 = *(uint *)(CRT_colors + 0x1c);
  (*(undefined1 * *)(__fp - 0x60)) = (undefined1 *)&(*(undefined8 *)(__fp - 0x68));
  pwVar16 = (*(wchar_t (*)[16])(__fp - 0xb8));
  (*(undefined1 * *)(__fp - 0x60)) = (undefined1 *)&(*(undefined8 *)(__fp - 0x68));
  sVar8 = mbstowcs((*(wchar_t (*)[16])(__fp - 0xb8)),((char *)(long)&s_Available_Columns_0014743c /* "Available Columns" */),0x11);
  iVar5 = (int)sVar8;
  uVar11 = sVar8 & 0xffffffff;
  lVar10 = extraout_RDX;
  if (0 < iVar5) {
    FUN_00130130((int *)(puVar6 + 0xc),iVar5);
    (*(uint *)(__fp - 0x54)) = uVar1 & 0xffffff;
    (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[16])(__fp - 0xb8)) + (ulong)(iVar5 - 1) + 1;
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
      lVar10 = extraout_RDX_00;
      pauVar14 = (undefined1 (*) [16])(pauVar14[1] + 0xc);
    } while ((*(wchar_t * *)(__fp - 0x50)) != pwVar16);
  }
  puVar4 = (*(undefined1 * *)(__fp - 0x60));
  *(undefined1 *)(puVar6 + 9) = 1;
  uVar15 = 0;
  plVar3 = (long *)puVar6[4];
  puVar6[0x4dc] = (*(undefined8 *)(__fp - 0x68));
  Vector_prune(plVar3,uVar11,lVar10,lVar9,lVar12,(long)puVar13);
  *(undefined4 *)(puVar6 + 8) = 0;
  puVar6[5] = 0;
  *(undefined1 *)(puVar6 + 9) = 1;
  FUN_0011ba60((long)puVar6,uVar11,extraout_RDX_01,lVar9,lVar12,(long)puVar13);
  if (*param_2 != 0) {
    do {
      puVar7 = (undefined4 *)(param_2[1] + uVar15 * 0x18);
      lVar10 = *(long *)(puVar7 + 4);
      if (lVar10 != 0) {
        uVar2 = *puVar7;
        FUN_0011b960(uVar2,lVar10,(long)puVar6,lVar9,lVar12,(long)puVar13);
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < *param_2);
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}

