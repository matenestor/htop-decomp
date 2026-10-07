#include "htop.h"

/* SignalsPanel_new @ 0x133e80 */

/* WARNING: Removing unreachable block (ram,0x00133fe5) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x00134002 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long * SignalsPanel_new(undefined4 param_1)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  wchar_t wVar1;
  undefined4 uVar2;
  long *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  long *a0;
  wchar_t *pwVar9;
  char *pcVar10;
  size_t sVar11;
  undefined8 *puVar12;
  undefined1 *a3;
  uint uVar13;
  uint uVar14;
  undefined1 (*pauVar15) [16];
  ulong a4;
  undefined1 *a5;
  undefined **ppuVar16;
  uint uVar17;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(undefined1 * *)(__fp - 0x70)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x70)) + 4)),param_1);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x48)) = 0;
  (*(char * *)(__fp - 0x58)) = ((char *)(long)&s_Send_00149190 /* "Send   " */);
  (*(char * *)(__fp - 0x50)) = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  puVar8 = FunctionBar_new(&(*(char * *)(__fp - 0x58)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
  a0 = malloc(0x26e0);
  if (a0 == (long *)0x0) {
LAB_0013419f:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  a5 = ListItem_class;
  a4 = 1;
  *a0 = (long)Panel_class;
  uVar17 = 0xf;
  uVar13 = 0;
  Panel_init((long)a0,1,1,1,1,ListItem_class,1,puVar8);
  ppuVar16 = &Platform_signals;
  do {
    (*(undefined8 *)(__fp - 0x60)) = *ppuVar16;
    wVar1 = *(wchar_t *)(ppuVar16 + 1);
    pwVar9 = malloc(0x18);
    if (pwVar9 == (wchar_t *)0x0) goto LAB_0013419f;
    a3 = ListItem_class;
    *(undefined1 **)pwVar9 = ListItem_class;
    (*(wchar_t * *)(__fp - 0x68)) = pwVar9;
    pcVar10 = strdup((*(undefined8 *)(__fp - 0x60)));
    if (pcVar10 == (char *)0x0) goto LAB_0013419f;
    plVar3 = (long *)a0[4];
    *(char **)((*(wchar_t * *)(__fp - 0x68)) + 2) = pcVar10;
    (*(wchar_t * *)(__fp - 0x68))[4] = wVar1;
    *(undefined1 *)((*(wchar_t * *)(__fp - 0x68)) + 5) = 0;
    Vector_set(plVar3,uVar13,(long)(*(wchar_t * *)(__fp - 0x68)),(long)a3,a4,(long)a5);
    if (wVar1 == (wchar_t)(*(undefined1 * *)(__fp - 0x70))) {
      uVar17 = uVar13;
    }
    uVar13 = uVar13 + 1;
    ppuVar16 = ppuVar16 + 2;
  } while (uVar13 != 0x22);
  iVar6 = __libc_current_sigrtmax();
  iVar7 = __libc_current_sigrtmin();
  if (iVar6 - iVar7 < 0x65) {
    uVar13 = __libc_current_sigrtmin();
    (*(undefined8 *)(__fp - 0x60)) = (char *)CONCAT44((*(uint *)((char *)&(*(undefined8 *)(__fp - 0x60)) + 4)),0x22 - uVar13);
    for (; iVar6 = __libc_current_sigrtmax(), (int)uVar13 <= iVar6; uVar13 = uVar13 + 1) {
      iVar6 = __libc_current_sigrtmin();
      a3 = (undefined1 *)(ulong)uVar13;
      uVar14 = uVar13 - iVar6;
      a4 = (ulong)uVar14;
      xSnprintf(&DAT_0015d7e0,0x10,((char *)(long)(__sec_rodata + 0x21a5) /* "%2d SIGRTMIN%-+3d" */),uVar13,uVar14);
      if (uVar14 == 0) {
        DAT_0015d7eb = 0;
      }
      puVar12 = malloc(0x18);
      if (puVar12 == (undefined8 *)0x0) goto LAB_0013419f;
      *puVar12 = ListItem_class;
      pcVar10 = strdup(&DAT_0015d7e0);
      if (pcVar10 == (char *)0x0) goto LAB_0013419f;
      puVar12[1] = pcVar10;
      *(uint *)(puVar12 + 2) = uVar13;
      plVar3 = (long *)a0[4];
      *(undefined1 *)((long)puVar12 + 0x14) = 0;
      Vector_set(plVar3,(int)(*(undefined8 *)(__fp - 0x60)) + uVar13,(long)puVar12,(long)a3,a4,(long)a5);
    }
  }
  (*(undefined1 * *)(__fp - 0x70)) = (*(undefined1 (*)[8])(__fp - 0x78));
  uVar2 = *(undefined4 *)(CRT_colors + 0x1c);
  pwVar9 = (*(wchar_t (*)[12])(__fp - 0xb8));
  (*(undefined1 * *)(__fp - 0x70)) = (*(undefined1 (*)[8])(__fp - 0x78));
  sVar11 = mbstowcs((*(wchar_t (*)[12])(__fp - 0xb8)),((char *)(long)&s_Send_signal__00149198 /* "Send signal:" */),0xc);
  iVar6 = (int)sVar11;
  if (0 < iVar6) {
    FUN_00130130((int *)(a0 + 0xc),iVar6);
    (*(undefined8 *)(__fp - 0x60)) = (char *)(CONCAT44((*(uint *)((char *)&(*(undefined8 *)(__fp - 0x60)) + 4)),uVar2) & 0xffffffff00ffffff);
    (*(wchar_t * *)(__fp - 0x68)) = (*(wchar_t (*)[12])(__fp - 0xb8)) + (ulong)(iVar6 - 1) + 1;
    pauVar15 = (undefined1 (*) [16])a0[0xd];
    do {
      wVar1 = *pwVar9;
      iVar6 = iswprint(wVar1);
      *(undefined16 *)(*pauVar15) = (undefined16)0x0;
      if (iVar6 == 0) {
        wVar1 = L'�';
      }
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar15 + 0xc)) = (undefined16)0x0;
      pwVar9 = pwVar9 + 1;
      *(int *)*pauVar15 = (int)(*(undefined8 *)(__fp - 0x60));
      *(wchar_t *)(*pauVar15 + 4) = wVar1;
      pauVar15 = (undefined1 (*) [16])(pauVar15[1] + 0xc);
    } while ((*(wchar_t * *)(__fp - 0x68)) != pwVar9);
  }
  puVar5 = (*(undefined1 * *)(__fp - 0x70));
  *(undefined1 *)(a0 + 9) = 1;
  uVar13 = *(int *)(a0[4] + 0x18) - 1;
  if (*(int *)(a0[4] + 0x18) <= (int)uVar17) {
    uVar17 = uVar13;
  }
  uVar14 = 0;
  if (-1 < (int)uVar17) {
    uVar14 = uVar17;
  }
  *(uint *)(a0 + 5) = uVar14;
  pcVar4 = *(code **)(*a0 + 0x20);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)((long)a0,0xffffffff,(ulong)uVar13,(long)a3,a4,(long)a5);
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a0;
}

