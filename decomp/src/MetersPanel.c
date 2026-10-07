#include "htop.h"

/* MetersPanel_setMoving @ 0x121570 */

void MetersPanel_setMoving(long param_1,char param_2)

{
  long lVar1;

  *(char *)(param_1 + 0x2708) = param_2;
  if ((0 < (int)(*(long **)(param_1 + 0x20))[3]) &&
     (lVar1 = *(long *)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8),
     lVar1 != 0)) {
    *(char *)(lVar1 + 0x14) = param_2;
  }
  lVar1 = LONG_0015c0c0;
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x26d8) = 9;
    *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_1 + 0x58);
    return;
  }
  *(undefined4 *)(param_1 + 0x26d8) = 10;
  *(long *)(param_1 + 0x50) = lVar1;
  return;
}


/* MetersPanel_cleanup @ 0x126e40 */

void MetersPanel_cleanup(void)

{
  if (LONG_0015c0c0 != 0) {
    FunctionBar_delete((int *)LONG_0015c0c0);
    LONG_0015c0c0 = 0;
    return;
  }
  return;
}


/* FUN_00126e80 @ 0x126e80 */

void FUN_00126e80(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  long extraout_RDX;

  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* MetersPanel_new @ 0x1288c0 */

undefined8 * MetersPanel_new(undefined8 param_1,char *param_2,long *param_3,undefined8 param_4)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  undefined4 uVar1;
  wint_t __wc;
  long *plVar2;
  undefined1 *puVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  ulong uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar12;
  long extraout_RDX_01;
  undefined1 *puVar13;
  long lVar15;
  undefined1 *puVar16;
  undefined1 (*pauVar17) [16];
  long lVar18;
  wint_t *pwVar19;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar14;

  puVar14 = (*(undefined1 (*)[8])(__fp - 0x68));
  puVar13 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar6 = malloc(10000);
  if (puVar6 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *puVar6 = MetersPanel_class;
  puVar7 = FunctionBar_new(&PTR_s_Style_00157760,(long)&PTR_s_Space_00157720,(long)&DAT_0014db70);
  if (LONG_0015c0c0 == 0) {
    (*(undefined8 *)(__fp - 0x50)) = puVar7;
    LONG_0015c0c0 = (long)FunctionBar_new(&PTR_s_Style_001576c0,(long)&PTR_s_Space_00157660,(long)&DAT_0014db40);
    puVar7 = (*(undefined8 *)(__fp - 0x50));
  }
  puVar16 = ListItem_class;
  lVar15 = 1;
  Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
  puVar6[0x4de] = param_4;
  puVar6[0x4dc] = param_1;
  puVar6[0x4dd] = param_3;
  lVar4 = CRT_colors;
  *(undefined1 *)(puVar6 + 0x4e1) = 0;
  *(undefined16 *)(*(undefined1 (*) [16])(puVar6 + 0x4df)) = (undefined16)0x0;
  uVar1 = *(undefined4 *)(lVar4 + 0x1c);
  sVar8 = strlen(param_2);
  uVar11 = (ulong)((int)sVar8 + 1);
  uVar9 = uVar11 * 4 + 0xf;
  puVar3 = (*(undefined1 (*)[8])(__fp - 0x68));
  while (puVar14 != (*(undefined1 (*)[8])(__fp - 0x68)) + -(uVar9 & 0xfffffffffffff000)) {
    puVar13 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar14 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar9 = (ulong)((uint)uVar9 & 0xff0);
  lVar4 = -uVar9;
  pwVar19 = (wint_t *)(puVar13 + lVar4);
  if (uVar9 != 0) {
    *(undefined8 *)(puVar13 + -8) = *(undefined8 *)(puVar13 + -8);
  }
  uVar11 = uVar11 & 0x3fffffffffffffff;
  (*(undefined1 * *)(__fp - 0x60)) = (*(undefined1 (*)[8])(__fp - 0x68));
  uVar9 = __mbstowcs_chk((int *)(puVar13 + lVar4),param_2,(long)(int)sVar8,uVar11);
  iVar5 = (int)uVar9;
  lVar12 = extraout_RDX;
  if (0 < iVar5) {
    FUN_00130130((int *)(puVar6 + 0xc),iVar5);
    (*(undefined8 *)(__fp - 0x50)) = (undefined4 *)(CONCAT44((*(uint *)((char *)&(*(undefined8 *)(__fp - 0x50)) + 4)),uVar1) & 0xffffffff00ffffff);
    (*(wint_t * *)(__fp - 0x58)) = (wint_t *)(puVar13 + (ulong)(iVar5 - 1) * 4 + lVar4 + 4);
    pauVar17 = (undefined1 (*) [16])puVar6[0xd];
    do {
      __wc = *pwVar19;
      iVar5 = iswprint(__wc);
      *(undefined16 *)(*pauVar17) = (undefined16)0x0;
      if (iVar5 == 0) {
        __wc = 0xfffd;
      }
      pwVar19 = pwVar19 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar17 + 0xc)) = (undefined16)0x0;
      *(undefined4 *)*pauVar17 = (undefined4)(*(undefined8 *)(__fp - 0x50));
      *(wint_t *)(*pauVar17 + 4) = __wc;
      lVar12 = extraout_RDX_00;
      pauVar17 = (undefined1 (*) [16])(pauVar17[1] + 0xc);
    } while (pwVar19 != (*(wint_t * *)(__fp - 0x58)));
  }
  puVar13 = (*(undefined1 * *)(__fp - 0x60));
  lVar4 = param_3[3];
  *(undefined1 *)(puVar6 + 9) = 1;
  lVar18 = 0;
  if (0 < (int)lVar4) {
    do {
      plVar2 = *(long **)(*param_3 + lVar18 * 8);
      lVar18 = lVar18 + 1;
      puVar10 = Meter_toListItem(plVar2,0,lVar12,uVar11,lVar15,(long)puVar16);
      plVar2 = (long *)puVar6[4];
      lVar4 = plVar2[3];
      Vector_set(plVar2,(int)lVar4,(long)puVar10,uVar11,lVar15,(long)puVar16);
      *(undefined1 *)(puVar6 + 9) = 1;
      lVar12 = extraout_RDX_01;
    } while ((int)lVar18 < (int)param_3[3]);
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}

