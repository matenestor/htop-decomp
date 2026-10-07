#include "htop.h"

/* RichString_setAttrn @ 0x12db80 */

void RichString_setAttrn(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;

  iVar5 = param_4 + param_3;
  iVar2 = 0;
  if (-1 < iVar5) {
    iVar2 = iVar5;
  }
  iVar6 = *param_1;
  if (iVar5 <= *param_1) {
    iVar6 = iVar2;
  }
  if (param_3 < iVar6) {
    puVar4 = (undefined4 *)(*(long *)(param_1 + 2) + (long)param_3 * 0x1c);
    puVar1 = (undefined4 *)
             (*(long *)(param_1 + 2) + ((ulong)(uint)(iVar6 - param_3) + (long)param_3) * 0x1c);
    puVar3 = puVar4;
    if (((int)puVar1 - (int)puVar4 & 4U) != 0) {
      *puVar4 = param_2;
      puVar3 = puVar4 + 7;
      if (puVar4 + 7 == puVar1) {
        return;
      }
    }
    do {
      *puVar3 = param_2;
      puVar4 = puVar3 + 0xe;
      puVar3[7] = param_2;
      puVar3 = puVar4;
    } while (puVar4 != puVar1);
  }
  return;
}


/* RichString_findChar @ 0x12dbf0 */

int RichString_findChar(int *param_1,char param_2,int param_3)

{
  wint_t wVar1;
  long lVar2;

  wVar1 = btowc((int)param_2);
  lVar2 = *(long *)(param_1 + 2) + (long)param_3 * 0x1c;
  if (param_3 < *param_1) {
    do {
      if (*(wint_t *)(lVar2 + 4) == wVar1) {
        return param_3;
      }
      param_3 = param_3 + 1;
      lVar2 = lVar2 + 0x1c;
    } while (param_3 != *param_1);
  }
  return -1;
}


/* RichString_delete @ 0x12dc60 */

void RichString_delete(int *param_1)

{
  if (*param_1 < 0x15f) {
    return;
  }
  free(*(void **)(param_1 + 2));
  *(int **)(param_1 + 2) = param_1 + 4;
  return;
}


/* RichString_setAttr @ 0x12dca0 */

void RichString_setAttr(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;

  iVar1 = *param_1;
  iVar2 = 0;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  if (0 < iVar1) {
    puVar3 = *(undefined4 **)(param_1 + 2);
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      *puVar3 = param_2;
      puVar3 = puVar3 + 7;
    } while (iVar1 < iVar2);
  }
  return;
}


/* RichString_appendChr @ 0x130300 */

void RichString_appendChr(int *param_1,undefined4 param_2,char param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined1 (*pauVar3) [16];
  undefined1 (*pauVar4) [16];

  iVar1 = *param_1;
  FUN_00130130(param_1,iVar1 + param_4);
  if (iVar1 < (int)(iVar1 + param_4)) {
    lVar2 = *(long *)(param_1 + 2);
    pauVar4 = (undefined1 (*) [16])(lVar2 + (long)iVar1 * 0x1c);
    do {
      *(undefined16 *)(*pauVar4) = (undefined16)0x0;
      pauVar3 = pauVar4 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar4 + 0xc)) = (undefined16)0x0;
      *(undefined4 *)*pauVar4 = param_2;
      *(int *)(*pauVar4 + 4) = (int)param_3;
      pauVar4 = (undefined1 (*) [16])(*pauVar3 + 0xc);
    } while ((undefined1 (*) [16])(*pauVar3 + 0xc) !=
             (undefined1 (*) [16])(lVar2 + ((ulong)param_4 + (long)iVar1) * 0x1c));
  }
  return;
}


/* RichString_rewind @ 0x130390 */

void RichString_rewind(int *param_1,int param_2)

{
  FUN_00130130(param_1,*param_1 - param_2);
  return;
}


/* RichString_appendnWideColumns @ 0x1303a0 */

int RichString_appendnWideColumns(int *param_1,uint param_2,char *param_3,int param_4,int *param_5)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  wchar_t __c;
  long lVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined1 (*pauVar6) [16];
  undefined1 *puVar7;
  wchar_t *pwVar9;
  long lVar10;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar8;

  puVar7 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = (long)(param_4 + 1) * 4 + 0xf;
  puVar8 = (*(undefined1 (*)[8])(__fp - 0x68));
  puVar2 = (*(undefined1 (*)[8])(__fp - 0x68));
  while (puVar8 != (*(undefined1 (*)[8])(__fp - 0x68)) + -(uVar5 & 0xfffffffffffff000)) {
    puVar7 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar8 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar5 = (ulong)((uint)uVar5 & 0xff0);
  lVar1 = -uVar5;
  pwVar9 = (wchar_t *)(puVar7 + lVar1);
  if (uVar5 != 0) {
    *(undefined8 *)(puVar7 + -8) = *(undefined8 *)(puVar7 + -8);
  }
  (*(uint *)(__fp - 0x58)) = param_2;
  (*(int * *)(__fp - 0x50)) = param_1;
  uVar5 = __mbstowcs_chk((int *)(puVar7 + lVar1),param_3,(long)param_4,
                         (long)(param_4 + 1) & 0x3fffffffffffffff);
  iVar4 = 0;
  if (0 < (int)uVar5) {
    iVar4 = *(*(int * *)(__fp - 0x50));
    (*(int *)(__fp - 0x5c)) = iVar4 + (int)uVar5;
    (*(int *)(__fp - 0x60)) = iVar4;
    FUN_00130130((*(int * *)(__fp - 0x50)),(*(int *)(__fp - 0x5c)));
    (*(int *)(__fp - 0x54)) = 0;
    lVar10 = (long)iVar4 * 0x1c;
    do {
      __c = *pwVar9;
      iVar3 = iswprint(__c);
      if (iVar3 == 0) {
        __c = L'�';
      }
      iVar3 = wcwidth(__c);
      if (*param_5 < iVar3) break;
      (*(int *)(__fp - 0x54)) = (*(int *)(__fp - 0x54)) + iVar3;
      *param_5 = *param_5 - iVar3;
      iVar4 = iVar4 + 1;
      pwVar9 = pwVar9 + 1;
      pauVar6 = (undefined1 (*) [16])(*(long *)((*(int * *)(__fp - 0x50)) + 2) + lVar10);
      lVar10 = lVar10 + 0x1c;
      *(undefined16 *)(*pauVar6) = (undefined16)0x0;
      *(uint *)*pauVar6 = (*(uint *)(__fp - 0x58)) & 0xffffff;
      *(wchar_t *)(*pauVar6 + 4) = __c;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar6 + 0xc)) = (undefined16)0x0;
    } while (iVar4 != (*(int *)(__fp - 0x5c)));
    FUN_00130130((*(int * *)(__fp - 0x50)),iVar4);
    *param_5 = (*(int *)(__fp - 0x54));
    iVar4 = iVar4 - (*(int *)(__fp - 0x60));
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


/* RichString_appendWide @ 0x130610 */

int RichString_appendWide(int *param_1,uint param_2,char *param_3)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  long lVar1;
  wint_t __wc;
  long lVar2;
  undefined1 *puVar3;
  int iVar4;
  size_t sVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 *puVar8;
  undefined1 (*pauVar10) [16];
  long lVar11;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar9;

  puVar8 = (*(undefined1 (*)[8])(__fp - 0x58));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  sVar5 = strlen(param_3);
  iVar4 = *param_1;
  lVar11 = (long)iVar4;
  uVar7 = (ulong)((int)sVar5 + 1);
  uVar6 = uVar7 * 4 + 0xf;
  puVar9 = (*(undefined1 (*)[8])(__fp - 0x58));
  puVar3 = (*(undefined1 (*)[8])(__fp - 0x58));
  while (puVar9 != (*(undefined1 (*)[8])(__fp - 0x58)) + -(uVar6 & 0xfffffffffffff000)) {
    puVar8 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar9 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar6 = (ulong)((uint)uVar6 & 0xff0);
  lVar2 = -uVar6;
  if (uVar6 != 0) {
    *(undefined8 *)(puVar8 + -8) = *(undefined8 *)(puVar8 + -8);
  }
  uVar6 = __mbstowcs_chk((int *)(puVar8 + lVar2),param_3,(long)(int)sVar5,uVar7 & 0x3fffffffffffffff
                        );
  (*(int *)(__fp - 0x50)) = (int)uVar6;
  if ((*(int *)(__fp - 0x50)) < 1) {
    (*(int *)(__fp - 0x50)) = 0;
  }
  else {
    (*(int *)(__fp - 0x4c)) = iVar4 + (*(int *)(__fp - 0x50));
    FUN_00130130(param_1,(*(int *)(__fp - 0x4c)));
    lVar1 = lVar11 * -4;
    pauVar10 = (undefined1 (*) [16])(*(long *)(param_1 + 2) + lVar11 * 0x1c);
    do {
      __wc = *(wint_t *)(puVar8 + lVar11 * 4 + lVar1 + lVar2);
      iVar4 = iswprint(__wc);
      *(undefined16 *)(*pauVar10) = (undefined16)0x0;
      if (iVar4 == 0) {
        __wc = 0xfffd;
      }
      *(uint *)*pauVar10 = param_2 & 0xffffff;
      lVar11 = lVar11 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar10 + 0xc)) = (undefined16)0x0;
      *(wint_t *)(*pauVar10 + 4) = __wc;
      pauVar10 = (undefined1 (*) [16])(pauVar10[1] + 0xc);
    } while ((int)lVar11 < (*(int *)(__fp - 0x4c)));
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int *)(__fp - 0x50));
}


/* RichString_appendnWide @ 0x130770 */

int RichString_appendnWide(int *param_1,uint param_2,char *param_3,int param_4)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  long lVar1;
  wint_t __wc;
  long lVar2;
  undefined1 *puVar3;
  int iVar4;
  ulong uVar5;
  undefined1 *puVar6;
  undefined1 (*pauVar8) [16];
  long lVar9;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar7;

  puVar6 = (*(undefined1 (*)[8])(__fp - 0x58));
  iVar4 = *param_1;
  lVar9 = (long)iVar4;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = (long)(param_4 + 1) * 4 + 0xf;
  puVar7 = (*(undefined1 (*)[8])(__fp - 0x58));
  puVar3 = (*(undefined1 (*)[8])(__fp - 0x58));
  while (puVar7 != (*(undefined1 (*)[8])(__fp - 0x58)) + -(uVar5 & 0xfffffffffffff000)) {
    puVar6 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar7 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar5 = (ulong)((uint)uVar5 & 0xff0);
  lVar2 = -uVar5;
  if (uVar5 != 0) {
    *(undefined8 *)(puVar6 + -8) = *(undefined8 *)(puVar6 + -8);
  }
  uVar5 = __mbstowcs_chk((int *)(puVar6 + lVar2),param_3,(long)param_4,
                         (long)(param_4 + 1) & 0x3fffffffffffffff);
  (*(int *)(__fp - 0x50)) = (int)uVar5;
  if ((*(int *)(__fp - 0x50)) < 1) {
    (*(int *)(__fp - 0x50)) = 0;
  }
  else {
    (*(int *)(__fp - 0x4c)) = iVar4 + (*(int *)(__fp - 0x50));
    FUN_00130130(param_1,(*(int *)(__fp - 0x4c)));
    lVar1 = lVar9 * -4;
    pauVar8 = (undefined1 (*) [16])(*(long *)(param_1 + 2) + lVar9 * 0x1c);
    do {
      __wc = *(wint_t *)(puVar6 + lVar9 * 4 + lVar1 + lVar2);
      iVar4 = iswprint(__wc);
      *(undefined16 *)(*pauVar8) = (undefined16)0x0;
      if (iVar4 == 0) {
        __wc = 0xfffd;
      }
      *(uint *)*pauVar8 = param_2 & 0xffffff;
      lVar9 = lVar9 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar8 + 0xc)) = (undefined16)0x0;
      *(wint_t *)(*pauVar8 + 4) = __wc;
      pauVar8 = (undefined1 (*) [16])(pauVar8[1] + 0xc);
    } while ((int)lVar9 < (*(int *)(__fp - 0x4c)));
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int *)(__fp - 0x50));
}


/* RichString_writeWide @ 0x1308c0 */

int RichString_writeWide(int *param_1,uint param_2,char *param_3)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  wint_t __wc;
  long lVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 (*pauVar8) [16];
  undefined1 *puVar9;
  wint_t *pwVar11;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar10;

  puVar9 = (*(undefined1 (*)[12])(__fp - 0x58));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  sVar5 = strlen(param_3);
  uVar7 = (ulong)((int)sVar5 + 1);
  uVar6 = uVar7 * 4 + 0xf;
  puVar10 = (*(undefined1 (*)[12])(__fp - 0x58));
  puVar2 = (*(undefined1 (*)[12])(__fp - 0x58));
  while (puVar10 != (*(undefined1 (*)[12])(__fp - 0x58)) + -(uVar6 & 0xfffffffffffff000)) {
    puVar9 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar10 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar6 = (ulong)((uint)uVar6 & 0xff0);
  lVar1 = -uVar6;
  pwVar11 = (wint_t *)(puVar9 + lVar1);
  if (uVar6 != 0) {
    *(undefined8 *)(puVar9 + -8) = *(undefined8 *)(puVar9 + -8);
  }
  uVar6 = __mbstowcs_chk((int *)(puVar9 + lVar1),param_3,(long)(int)sVar5,uVar7 & 0x3fffffffffffffff
                        );
  iVar3 = (int)uVar6;
  if (iVar3 < 1) {
    (*(int *)(__fp - 0x4c)) = 0;
  }
  else {
    (*(int *)(__fp - 0x4c)) = iVar3;
    FUN_00130130(param_1,iVar3);
    pauVar8 = *(undefined1 (**) [16])(param_1 + 2);
    do {
      __wc = *pwVar11;
      iVar4 = iswprint(__wc);
      *(undefined16 *)(*pauVar8) = (undefined16)0x0;
      if (iVar4 == 0) {
        __wc = 0xfffd;
      }
      pwVar11 = pwVar11 + 1;
      *(uint *)*pauVar8 = param_2 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar8 + 0xc)) = (undefined16)0x0;
      *(wint_t *)(*pauVar8 + 4) = __wc;
      pauVar8 = (undefined1 (*) [16])(pauVar8[1] + 0xc);
    } while ((wint_t *)(puVar9 + (ulong)(iVar3 - 1) * 4 + lVar1 + 4) != pwVar11);
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int *)(__fp - 0x4c));
}


/* RichString_appendAscii @ 0x130a00 */

int RichString_appendAscii(int *param_1,uint param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  ushort **ppuVar7;
  undefined1 (*pauVar8) [16];
  char *pcVar9;

  sVar6 = strlen(param_3);
  iVar5 = *param_1;
  iVar4 = (int)sVar6 + iVar5;
  FUN_00130130(param_1,iVar4);
  if (iVar5 < iVar4) {
    ppuVar7 = __ctype_b_loc();
    puVar3 = *ppuVar7;
    pcVar9 = param_3 + (sVar6 & 0xffffffff);
    pauVar8 = (undefined1 (*) [16])(*(long *)(param_1 + 2) + (long)iVar5 * 0x1c);
    do {
      cVar1 = *param_3;
      bVar2 = *(byte *)((long)puVar3 + (long)cVar1 * 2 + 1);
      *(undefined16 *)(*pauVar8) = (undefined16)0x0;
      iVar5 = (int)cVar1;
      if ((bVar2 & 0x40) == 0) {
        iVar5 = 0xfffd;
      }
      param_3 = param_3 + 1;
      *(uint *)*pauVar8 = param_2 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar8 + 0xc)) = (undefined16)0x0;
      *(int *)(*pauVar8 + 4) = iVar5;
      pauVar8 = (undefined1 (*) [16])(pauVar8[1] + 0xc);
    } while (param_3 != pcVar9);
  }
  return (int)sVar6;
}


/* RichString_appendnAscii @ 0x130ac0 */

uint RichString_appendnAscii(int *param_1,uint param_2,char *param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  int iVar4;
  ushort **ppuVar5;
  undefined1 (*pauVar6) [16];
  char *pcVar7;

  iVar4 = *param_1;
  FUN_00130130(param_1,iVar4 + param_4);
  if (iVar4 < (int)(iVar4 + param_4)) {
    ppuVar5 = __ctype_b_loc();
    puVar3 = *ppuVar5;
    pcVar7 = param_3 + param_4;
    pauVar6 = (undefined1 (*) [16])(*(long *)(param_1 + 2) + (long)iVar4 * 0x1c);
    do {
      cVar1 = *param_3;
      bVar2 = *(byte *)((long)puVar3 + (long)cVar1 * 2 + 1);
      *(undefined16 *)(*pauVar6) = (undefined16)0x0;
      iVar4 = (int)cVar1;
      if ((bVar2 & 0x40) == 0) {
        iVar4 = 0xfffd;
      }
      param_3 = param_3 + 1;
      *(uint *)*pauVar6 = param_2 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar6 + 0xc)) = (undefined16)0x0;
      *(int *)(*pauVar6 + 4) = iVar4;
      pauVar6 = (undefined1 (*) [16])(pauVar6[1] + 0xc);
    } while (param_3 != pcVar7);
  }
  return param_4;
}


/* RichString_writeAscii @ 0x131b20 */

ulong RichString_writeAscii(int *param_1,uint param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  ushort *puVar4;
  int iVar5;
  size_t sVar6;
  ushort **ppuVar7;
  undefined1 (*pauVar8) [16];

  sVar6 = strlen(param_3);
  iVar5 = (int)sVar6;
  FUN_00130130(param_1,iVar5);
  if (0 < iVar5) {
    ppuVar7 = __ctype_b_loc();
    puVar4 = *ppuVar7;
    pcVar1 = param_3 + (ulong)(iVar5 - 1) + 1;
    pauVar8 = *(undefined1 (**) [16])(param_1 + 2);
    do {
      cVar2 = *param_3;
      bVar3 = *(byte *)((long)puVar4 + (long)cVar2 * 2 + 1);
      *(undefined16 *)(*pauVar8) = (undefined16)0x0;
      iVar5 = (int)cVar2;
      if ((bVar3 & 0x40) == 0) {
        iVar5 = 0xfffd;
      }
      param_3 = param_3 + 1;
      *(uint *)*pauVar8 = param_2 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar8 + 0xc)) = (undefined16)0x0;
      *(int *)(*pauVar8 + 4) = iVar5;
      pauVar8 = (undefined1 (*) [16])(pauVar8[1] + 0xc);
    } while (param_3 != pcVar1);
  }
  return sVar6 & 0xffffffff;
}


/* FUN_00131bd0 @ 0x131bd0 */

void FUN_00131bd0(long param_1,int *param_2)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  double dVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit(*(double *)(param_1 + 0x168),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  Meter_humanUnit(**(double **)(param_1 + 0x160),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_used__00148889 /* " used:" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  dVar1 = *(double *)(*(long *)(param_1 + 0x160) + 8);
  if (0.0 <= dVar1) {
    Meter_humanUnit(dVar1,(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_cache__001488b0 /* " cache:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x6c),(*(char (*)[56])(__fp - 0x68)));
    dVar1 = *(double *)(*(long *)(param_1 + 0x160) + 0x10);
  }
  else {
    dVar1 = *(double *)(*(long *)(param_1 + 0x160) + 0x10);
  }
  if (0.0 <= dVar1) {
    Meter_humanUnit(dVar1,(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_frontswap__00149151 /* " frontswap:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x70),(*(char (*)[56])(__fp - 0x68)));
  }
  if ((*(long *)(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

