#include "htop.h"

/* RowField_alignedTitle @ 0x128b40 */

undefined * RowField_alignedTitle(long param_1,int param_2)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  uint va0;
  int *piVar4;
  ulong uVar5;
  long lVar6;
  int *piVar7;
  undefined *va2;

  if (0x83 < param_2) {
    uVar1 = **(ulong **)(param_1 + 0x18);
    piVar7 = (int *)(*(ulong **)(param_1 + 0x18))[1];
    uVar5 = (ulong)(long)param_2 % uVar1;
    lVar6 = *(long *)(piVar7 + uVar5 * 6 + 4);
    if (lVar6 == 0) {
      return &DAT_00147411;
    }
    uVar3 = 0;
    piVar4 = piVar7 + uVar5 * 6;
    do {
      while( true ) {
        if (param_2 == *piVar4) {
          va0 = *(uint *)(lVar6 + 0x38);
          if (va0 == 0) {
            va0 = 0xfffffffb;
          }
          else {
            uVar2 = -va0;
            if ((int)-va0 < 0) {
              uVar2 = va0;
            }
            if (0x40 < (int)uVar2) {
              va0 = 0xfffffffb;
            }
          }
          va2 = *(undefined **)(lVar6 + 0x20);
          goto LAB_00128bfd;
        }
        if (*(ulong *)(piVar4 + 2) < uVar3) goto LAB_00128bd0;
        uVar5 = uVar5 + 1;
        if (uVar1 != uVar5) break;
        uVar5 = 0;
        uVar3 = uVar3 + 1;
        lVar6 = *(long *)(piVar7 + 4);
        piVar4 = piVar7;
        if (lVar6 == 0) goto LAB_00128bd0;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar7 + uVar5 * 6;
      lVar6 = *(long *)(piVar4 + 4);
    } while (lVar6 != 0);
LAB_00128bd0:
    return &DAT_00147411;
  }
  lVar6 = (long)param_2 * 0x20;
  va2 = *(undefined **)(Process_fields + lVar6 + 8);
  if (va2 == (undefined *)0x0) goto LAB_00128bd0;
  if (Process_fields[lVar6 + 0x1c] == '\0') {
    if (param_2 == 0x2e) {
      piVar7 = &Row_uidDigits;
      goto LAB_00128c9f;
    }
    if (Process_fields[lVar6 + 0x1e] == '\0') {
      return va2;
    }
    if (param_2 != 0x2f) {
      xSnprintf(&DAT_0015d500,0x101,((char *)(long)&s______s_0014884c /* "%-*.*s " */),(uint)(byte)(&Row_fieldWidths)[param_2],
                (uint)(byte)(&Row_fieldWidths)[param_2],va2);
      goto LAB_00128c17;
    }
    va0 = (uint)BYTE_0015d48f;
  }
  else {
    piVar7 = &Row_pidDigits;
LAB_00128c9f:
    va0 = *piVar7;
  }
LAB_00128bfd:
  xSnprintf(&DAT_0015d500,0x101,((char *)(long)&DAT_00148847 /* "%*s " */),va0,va2);
LAB_00128c17:
  return &DAT_0015d500;
}


/* RowField_keyAt @ 0x128cc0 */

int RowField_keyAt(long param_1,int param_2)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  int iVar3;
  int *piVar4;

  iVar3 = 0;
  piVar4 = *(int **)(*(long *)(param_1 + 0x40) + 0x18);
  iVar1 = *piVar4;
  while( true ) {
    if (iVar1 == 0) {
      return 2;
    }
    piVar4 = piVar4 + 1;
    __s = RowField_alignedTitle(param_1,iVar1);
    sVar2 = strlen(__s);
    if ((iVar3 <= param_2) && (param_2 <= iVar3 + (int)sVar2)) break;
    iVar3 = iVar3 + (int)sVar2;
    iVar1 = *piVar4;
  }
  return iVar1;
}


/* FUN_00128d50 @ 0x128d50 */

void FUN_00128d50(long param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  double *pdVar3;
  undefined *puVar4;
  double dVar5;

  puVar2 = *(undefined8 **)(param_1 + 0x160);
  Platform_getLoadAverage(puVar2,puVar2 + 1,puVar2 + 2);
  pdVar3 = *(double **)(param_1 + 0x160);
  *(undefined1 *)(param_1 + 0x50) = 1;
  puVar4 = &DAT_0014dbac;
  dVar5 = 1.0;
  if (1.0 <= *pdVar3) {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x10) + 0x78);
    dVar5 = (double)uVar1;
    puVar4 = &DAT_0014dba8;
    if (dVar5 <= *pdVar3) {
      dVar5 = (double)(uVar1 * 2);
      puVar4 = &DAT_0014dba4;
    }
  }
  *(undefined **)(param_1 + 0x58) = puVar4;
  *(double *)(param_1 + 0x168) = dVar5;
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_00148854 /* "%.2f/%.2f/%.2f" */),*pdVar3,pdVar3[1],pdVar3[2]);
  return;
}


/* FUN_00128e10 @ 0x128e10 */

void FUN_00128e10(long param_1)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  double dVar1;
  uint uVar2;
  undefined *puVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  Platform_getLoadAverage(*(undefined8 **)(param_1 + 0x160),&(*(undefined8 *)(__fp - 0x28)),&(*(undefined8 *)(__fp - 0x30)));
  dVar4 = 1.0;
  puVar3 = &DAT_0014dbac;
  dVar1 = **(double **)(param_1 + 0x160);
  if (1.0 <= dVar1) {
    uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x78);
    dVar4 = (double)uVar2;
    puVar3 = &DAT_0014dba8;
    if (dVar4 <= dVar1) {
      dVar4 = (double)(uVar2 * 2);
      puVar3 = &DAT_0014dba4;
    }
  }
  *(undefined **)(param_1 + 0x58) = puVar3;
  *(double *)(param_1 + 0x168) = dVar4;
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_0014885e /* "%.2f" */),**(double **)(param_1 + 0x160));
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00128ef0 @ 0x128ef0 */

void FUN_00128ef0(long param_1,int *param_2)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  uint uVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),**(double **)(param_1 + 0x160));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x100),(*(char (*)[24])(__fp - 0x58)),uVar1);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),*(double *)(*(long *)(param_1 + 0x160) + 8));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0xfc),(*(char (*)[24])(__fp - 0x58)),uVar1);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),*(double *)(*(long *)(param_1 + 0x160) + 0x10));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0xf8),(*(char (*)[24])(__fp - 0x58)),uVar1);
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00129000 @ 0x129000 */

void FUN_00129000(long param_1,int *param_2)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  uint uVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x38)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),**(double **)(param_1 + 0x160));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0xf4),(*(char (*)[24])(__fp - 0x38)),uVar1);
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

