#include "htop.h"

/* Row_display @ 0x11fc90 */

void Row_display(long *param_1,int *param_2,long param_rdx,long param_rcx,long param_r8,
                long param_r9)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  undefined4 *puVar9;
  uint *puVar10;
  int *a1;

  lVar4 = *(long *)param_1[1];
  puVar10 = *(uint **)(*(long *)(lVar4 + 0x40) + 0x18);
  uVar2 = *puVar10;
  a1 = param_2;
  while (uVar2 != 0) {
    puVar10 = puVar10 + 1;
    a1 = param_2;
    (**(code **)(*param_1 + 0x30))
              ((long)param_1,(long)param_2,(ulong)uVar2,param_rcx,param_r8,param_r9);
    uVar2 = *puVar10;
  }
  if ((*(code **)(*param_1 + 0x20) == (code *)0x0) ||
     (lVar7 = (**(code **)(*param_1 + 0x20))((long)param_1,(long)a1,0,param_rcx,param_r8,param_r9),
     (char)lVar7 == '\0')) {
    cVar1 = *(char *)((long)param_1 + 0x1d);
  }
  else {
    uVar3 = *(undefined4 *)(CRT_colors + 0x78);
    iVar6 = *param_2;
    iVar8 = 0;
    if (-1 < iVar6) {
      iVar8 = iVar6;
    }
    if (iVar6 < 1) goto LAB_0011fcfb;
    puVar9 = *(undefined4 **)(param_2 + 2);
    iVar6 = 0;
    do {
      iVar6 = iVar6 + 1;
      *puVar9 = uVar3;
      puVar9 = puVar9 + 7;
    } while (iVar6 < iVar8);
    cVar1 = *(char *)((long)param_1 + 0x1d);
  }
  if (cVar1 != '\0') {
    uVar3 = *(undefined4 *)(CRT_colors + 0x7c);
    iVar6 = *param_2;
    iVar8 = 0;
    if (-1 < iVar6) {
      iVar8 = iVar6;
    }
    if (0 < iVar6) {
      puVar9 = *(undefined4 **)(param_2 + 2);
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 1;
        *puVar9 = uVar3;
        puVar9 = puVar9 + 7;
      } while (iVar6 < iVar8);
    }
  }
LAB_0011fcfb:
  if (*(char *)(lVar4 + 0x61) != '\0') {
    if (param_1[7] == 0) {
      uVar5 = ((long *)param_1[1])[4];
      if (((ulong)param_1[6] <= uVar5) &&
         (uVar5 - param_1[6] <= (ulong)((long)*(int *)(*(long *)param_1[1] + 100) * 1000))) {
        param_2[0x99d] = *(int *)(CRT_colors + 0xa0);
      }
    }
    else {
      param_2[0x99d] = *(int *)(CRT_colors + 0xa4);
    }
  }
  return;
}


/* Row_setPidColumnWidth @ 0x120fe0 */

void Row_setPidColumnWidth(int param_1)

{
  double dVar1;

  if (param_1 < 100000) {
    Row_pidDigits = 5;
    return;
  }
  dVar1 = log10((double)param_1);
  Row_pidDigits = (int)dVar1 + 1;
  return;
}


/* Row_setUidColumnWidth @ 0x121260 */

void Row_setUidColumnWidth(uint param_1)

{
  double dVar1;

  if (param_1 < 100000) {
    Row_uidDigits = 5;
    return;
  }
  dVar1 = log10((double)param_1);
  Row_uidDigits = (int)dVar1 + 1;
  return;
}


/* Row_resetFieldWidths @ 0x1212b0 */

void Row_resetFieldWidths(void)

{
  size_t sVar1;
  undefined **ppuVar2;
  undefined1 *puVar3;

  puVar3 = &Row_fieldWidths;
  ppuVar2 = (undefined **)(Process_fields + 8);
  do {
    if (*(char *)((long)ppuVar2 + 0x16) != '\0') {
      sVar1 = strlen(*ppuVar2);
      *puVar3 = (char)sVar1;
    }
    ppuVar2 = ppuVar2 + 4;
    puVar3 = puVar3 + 1;
  } while (ppuVar2 != &PTR_s_Enter_00157668);
  return;
}


/* Row_init @ 0x122880 */

void Row_init(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1d) = 0x1000100;
  *(undefined1 *)(param_1 + 0x21) = 0;
  return;
}


/* Row_updateFieldWidth @ 0x122ed0 */

void Row_updateFieldWidth(int param_1,ulong param_2)

{
  if (0xff < param_2) {
    (&Row_fieldWidths)[param_1] = 0xff;
    return;
  }
  if ((byte)(&Row_fieldWidths)[param_1] < param_2) {
    (&Row_fieldWidths)[param_1] = (char)param_2;
  }
  return;
}


/* FUN_00122f10 @ 0x122f10 */

bool FUN_00122f10(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = getpriority(PRIO_PROCESS,*(id_t *)(param_1 + 0x10));
  iVar2 = setpriority(PRIO_PROCESS,*(id_t *)(param_1 + 0x10),param_2);
  if (iVar2 == 0) {
    iVar3 = getpriority(PRIO_PROCESS,*(id_t *)(param_1 + 0x10));
    if (iVar1 != iVar3) {
      *(long *)(param_1 + 200) = (long)param_2;
      return true;
    }
  }
  return iVar2 == 0;
}


/* Row_done @ 0x123060 */

void Row_done(void)

{
  return;
}


/* Row_compare @ 0x12d200 */

int Row_compare(long param_1,long param_2)

{
  return (uint)(*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) -
         (uint)(*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10));
}


/* Row_toggleTag @ 0x12da70 */

void Row_toggleTag(long param_1)

{
  *(byte *)(param_1 + 0x1d) = *(byte *)(param_1 + 0x1d) ^ 1;
  return;
}


/* Row_compareByParent_Base @ 0x12da80 */

int Row_compareByParent_Base(long param_1,long param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;

  cVar1 = *(char *)(param_2 + 0x1c);
  if (*(char *)(param_1 + 0x1c) == '\0') {
    iVar5 = *(int *)(param_1 + 0x14);
    iVar7 = iVar5;
    if (*(int *)(param_1 + 0x10) == iVar5) {
      iVar7 = *(int *)(param_1 + 0x18);
      uVar4 = (uint)(0 < iVar7);
      uVar6 = 0;
      if (cVar1 == '\0') goto LAB_0012dae0;
    }
    else if (cVar1 == '\0') {
LAB_0012dae0:
      uVar6 = *(uint *)(param_2 + 0x14);
      if (uVar6 == *(uint *)(param_2 + 0x10)) {
        bVar2 = *(int *)(param_2 + 0x18) < iVar7;
        uVar4 = (uint)bVar2;
        uVar3 = (uint)bVar2;
        if (*(int *)(param_1 + 0x10) == iVar5) {
LAB_0012dafd:
          uVar4 = uVar3;
          iVar5 = *(int *)(param_1 + 0x18);
          iVar7 = iVar5;
          if (uVar6 != *(uint *)(param_2 + 0x10)) goto LAB_0012daa7;
        }
        uVar6 = *(uint *)(param_2 + 0x18);
        iVar7 = iVar5;
      }
      else {
        uVar4 = (uint)((int)uVar6 < iVar7);
        iVar7 = iVar5;
        uVar3 = uVar4;
        if (iVar5 == *(int *)(param_1 + 0x10)) goto LAB_0012dafd;
      }
    }
    else {
      uVar4 = (uint)(0 < iVar5);
      uVar6 = 0;
    }
  }
  else {
    if (cVar1 != '\0') goto LAB_0012dab8;
    uVar6 = *(uint *)(param_2 + 0x14);
    if (uVar6 == *(uint *)(param_2 + 0x10)) {
      uVar6 = *(uint *)(param_2 + 0x18);
    }
    uVar4 = uVar6 >> 0x1f;
    iVar7 = 0;
  }
LAB_0012daa7:
  iVar5 = uVar4 - (iVar7 < (int)uVar6);
  if (iVar5 != 0) {
    return iVar5;
  }
LAB_0012dab8:
  return (uint)(*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) -
         (uint)(*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10));
}


/* FUN_0012db60 @ 0x12db60 */

void FUN_0012db60(long *param_1,long param_2,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  if (*(code **)(*param_1 + 0x48) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012db70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x48))((long)param_1,param_2,param_rdx,param_rcx,param_r8,param_r9);
    return;
  }
  Row_compareByParent_Base((long)param_1,param_2);
  return;
}


/* Row_printPercentage @ 0x12e760 */

void Row_printPercentage(float param_1,char *param_2,ulong param_3,byte param_4,undefined4 *param_5)

{
  uint va0;
  int va1;
  double va2;

  va0 = (uint)param_4;
  if (param_1 < 0.0) {
    *param_5 = *(undefined4 *)(CRT_colors + 0x78);
    xSnprintf(param_2,param_3,((char *)(long)&s_____s_00148c24 /* "%*.*s " */),va0,va0,&DAT_001474de);
    return;
  }
  if (0.05 <= param_1) {
    if ((99.9 <= param_1) && (*param_5 = *(undefined4 *)(CRT_colors + 0x80), param_4 == 4)) {
      va1 = 0;
      va2 = 100.0;
      if (99.9 < param_1) goto LAB_0012e79e;
    }
    va1 = 1;
    va2 = (double)param_1;
  }
  else {
    va1 = 1;
    va2 = (double)param_1;
    *param_5 = *(undefined4 *)(CRT_colors + 0x78);
  }
LAB_0012e79e:
  xSnprintf(param_2,param_3,((char *)(long)&s_____f_00148c1d /* "%*.*f " */),va0,va1,va2);
  return;
}


/* FUN_0012e840 @ 0x12e840 */

void FUN_0012e840(long param_1)

{
  uint va0;
  uint uVar1;
  uint uVar2;
  uint va1;
  double *pdVar3;
  long lVar4;

  pdVar3 = *(double **)(param_1 + 0x160);
  lVar4 = *(long *)(*(long *)(param_1 + 0x10) + 0xb0);
  va0 = *(uint *)(*(long *)(param_1 + 0x10) + 0x78);
  uVar1 = *(uint *)(lVar4 + 0x54);
  uVar2 = *(uint *)(lVar4 + 0x50);
  va1 = *(uint *)(lVar4 + 0x48);
  if (*(uint *)(lVar4 + 0x4c) < va0) {
    va0 = *(uint *)(lVar4 + 0x4c);
  }
  *pdVar3 = (double)uVar1;
  pdVar3[1] = (double)uVar2;
  pdVar3[2] = (double)(va1 - (uVar1 + uVar2));
  pdVar3[3] = (double)va0;
  *(double *)(param_1 + 0x168) = (double)va1;
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s__u__u_00148c2b /* "%u/%u" */),va0,va1);
  return;
}


/* Row_printLeftAlignedField @ 0x130530 */

void Row_printLeftAlignedField(int *param_1,uint param_2,char *param_3,int param_4)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined1 (*pauVar4) [16];
  size_t sVar5;
  undefined1 (*pauVar6) [16];
  int iVar7;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(int *)(__fp - 0x44)) = param_4;
  sVar5 = strlen(param_3);
  RichString_appendnWideColumns(param_1,param_2,param_3,(int)sVar5,&(*(int *)(__fp - 0x44)));
  uVar1 = (param_4 - (*(int *)(__fp - 0x44))) + 1;
  iVar2 = *param_1;
  iVar7 = uVar1 + iVar2;
  FUN_00130130(param_1,iVar7);
  if (iVar2 < iVar7) {
    lVar3 = *(long *)(param_1 + 2);
    pauVar6 = (undefined1 (*) [16])(lVar3 + (long)iVar2 * 0x1c);
    do {
      *(undefined16 *)(*pauVar6) = (undefined16)0x0;
      pauVar4 = pauVar6 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar6 + 0xc)) = (undefined16)0x0;
      *(uint *)*pauVar6 = param_2;
      *(undefined4 *)(*pauVar6 + 4) = 0x20;
      pauVar6 = (undefined1 (*) [16])(*pauVar4 + 0xc);
    } while ((undefined1 (*) [16])(*pauVar4 + 0xc) !=
             (undefined1 (*) [16])(lVar3 + ((ulong)uVar1 + (long)iVar2) * 0x1c));
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printKBytes @ 0x130b70 */

void Row_printKBytes(int *param_1,ulong param_2,char param_3)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  long lVar7;
  ulong uVar8;
  int va0;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = *(uint *)(CRT_colors + 0x74);
  (*(undefined8 *)(__fp - 0x68)) = CONCAT44(*(uint *)(CRT_colors + 0x80),uVar3);
  (*(undefined8 *)(__fp - 0x60)) = CONCAT44(*(undefined4 *)(CRT_colors + 0x30),*(undefined4 *)(CRT_colors + 0x84));
  if (param_2 == 0xffffffffffffffff) {
    if (param_3 != '\0') {
      uVar3 = *(uint *)(CRT_colors + 0x78);
    }
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(param_1,uVar3,((char *)(long)&DAT_00149092 /* "  N/A " */));
      return;
    }
  }
  else {
    uVar4 = *(uint *)(CRT_colors + 0x80);
    if (param_3 == '\0') {
      uVar4 = uVar3;
    }
    if (param_2 < 1000) {
      uVar4 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149063 /* "%5u " */),(int)param_2);
      RichString_appendnAscii(param_1,uVar3,(*(char (*)[24])(__fp - 0x58)),uVar4);
    }
    else if (param_2 < 100000) {
      iVar5 = (int)(param_2 / 1000);
      uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149068 /* "%2u" */),iVar5);
      RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
      uVar4 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&s__03u_0014906c /* "%03u " */),(int)param_2 + iVar5 * -1000);
      RichString_appendnAscii(param_1,uVar3,(*(char (*)[24])(__fp - 0x58)),uVar4);
    }
    else {
      lVar7 = 1;
      uVar8 = ((param_2 & 0xff) * 0x19 >> 8) + (param_2 >> 8) * 0x19;
      while( true ) {
        uVar2 = uVar4;
        if ((param_3 != '\0') && (lVar7 + 1U < 4)) {
          uVar2 = *(uint *)((long)&(*(undefined8 *)(__fp - 0x68)) + lVar7 * 4 + 4);
        }
        if (uVar8 < 1000000) break;
        uVar8 = uVar8 >> 10;
        lVar7 = lVar7 + 1;
        uVar3 = uVar4;
        uVar4 = uVar2;
      }
      iVar5 = (int)(uVar8 / 100);
      if (uVar8 < 10000) {
        va0 = (int)(uVar8 % 100);
        if (uVar8 < 1000) {
          uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149079 /* "%1u" */),9);
          RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
          pcVar6 = ((char *)(long)&s___02u_00149072 /* ".%02u" */);
        }
        else {
          uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149068 /* "%2u" */),iVar5);
          RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar2);
          pcVar6 = ((char *)(long)&DAT_00149078 /* ".%1u" */);
          va0 = (int)((uVar8 % 100) / 10);
        }
        uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,pcVar6,va0);
        RichString_appendnAscii(param_1,uVar3,(*(char (*)[24])(__fp - 0x58)),uVar2);
        uVar3 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149088 /* "%c " */),(int)(char)(&DAT_0014db98)[lVar7]);
      }
      else {
        if (uVar8 < 100000) {
          cVar1 = (&DAT_0014db98)[lVar7];
          pcVar6 = ((char *)(long)&s__4u_c_0014907d /* "%4u%c " */);
        }
        else {
          uVar8 = uVar8 / 100 & 0xffffffff;
          uVar3 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149079 /* "%1u" */),(int)(uVar8 / 1000));
          RichString_appendnAscii(param_1,uVar2,(*(char (*)[24])(__fp - 0x58)),uVar3);
          pcVar6 = ((char *)(long)&DAT_00149084 /* "%03u%c " */);
          cVar1 = (&DAT_0014db98)[lVar7];
          iVar5 = iVar5 + (int)(uVar8 / 1000) * -1000;
        }
        uVar3 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x10,pcVar6,iVar5,(int)cVar1);
      }
      RichString_appendnAscii(param_1,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar3);
    }
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printBytes @ 0x130f70 */

void Row_printBytes(int *param_1,ulong param_2,char param_3)

{
  uint uVar1;

  if (param_2 != 0xffffffffffffffff) {
    Row_printKBytes(param_1,param_2 >> 10,param_3);
    return;
  }
  uVar1 = *(uint *)(CRT_colors + 0x74);
  if (param_3 != '\0') {
    uVar1 = *(uint *)(CRT_colors + 0x78);
  }
  RichString_appendAscii(param_1,uVar1,((char *)(long)&DAT_00149092 /* "  N/A " */));
  return;
}


/* Row_printCount @ 0x130fb0 */

void Row_printCount(int *param_1,ulong param_2,char param_3)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *(uint *)(CRT_colors + 0x74);
  uVar2 = uVar1;
  uVar3 = uVar1;
  uVar4 = uVar1;
  if (param_3 != '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x30);
    uVar3 = *(uint *)(CRT_colors + 0x80);
    uVar4 = *(uint *)(CRT_colors + 0x78);
  }
  if (param_2 == 0xffffffffffffffff) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(param_1,*(uint *)(CRT_colors + 0x78),((char *)(long)&DAT_0014908c /* "        N/A " */));
      return;
    }
  }
  else {
    if (param_2 < 100000000000000000) {
      if (param_2 < 100000000000000) {
        if (param_2 < 10000000000) {
          xSnprintf((*(char (*)[2])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),param_2);
          RichString_appendnAscii(param_1,uVar2,(*(char (*)[2])(__fp - 0x4d)),2);
          RichString_appendnAscii(param_1,uVar3,(*(char (*)[3])(__fp - 0x4b)),3);
          RichString_appendnAscii(param_1,uVar1,(*(char (*)[3])(__fp - 0x48)),3);
          RichString_appendnAscii(param_1,uVar4,(*(char (*)[5])(__fp - 0x45)),4);
        }
        else {
          xSnprintf((*(char (*)[2])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),param_2 / 1000);
          RichString_appendnAscii(param_1,uVar2,(*(char (*)[2])(__fp - 0x4d)),5);
          RichString_appendnAscii(param_1,uVar3,(*(char (*)[3])(__fp - 0x48)),3);
          RichString_appendnAscii(param_1,uVar1,(*(char (*)[5])(__fp - 0x45)),4);
        }
      }
      else {
        xSnprintf((*(char (*)[2])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),param_2 / 1000000);
        RichString_appendnAscii(param_1,uVar2,(*(char (*)[2])(__fp - 0x4d)),8);
        RichString_appendnAscii(param_1,uVar3,(*(char (*)[5])(__fp - 0x45)),4);
      }
    }
    else {
      xSnprintf((*(char (*)[2])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),param_2 / 1000000000);
      RichString_appendnAscii(param_1,uVar2,(*(char (*)[2])(__fp - 0x4d)),0xc);
    }
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printTime @ 0x131250 */

void Row_printTime(int *param_1,ulong param_2,char param_3)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  int va1;
  int va0;
  uint uVar7;
  uint uVar8;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *(uint *)(CRT_colors + 0x74);
  uVar2 = uVar1;
  uVar8 = uVar1;
  uVar7 = uVar1;
  if (param_3 != '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x30);
    uVar8 = *(uint *)(CRT_colors + 0x84);
    uVar7 = *(uint *)(CRT_colors + 0x80);
  }
  uVar6 = param_2 / 100;
  iVar3 = (int)(uVar6 / 0x3c);
  uVar5 = (uVar6 / 0x3c) / 0x3c;
  iVar4 = (int)uVar5;
  va0 = iVar3 + ((int)(uVar5 << 4) - iVar4) * -4;
  va1 = (int)(uVar6 % 0x3c);
  if (param_2 < 360000) {
    uVar2 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__2u__02u__02u_001490a1 /* "%2u:%02u.%02u " */),iVar3,va1,(int)param_2 + (int)uVar6 * -100);
    RichString_appendnAscii(param_1,uVar1,(*(char (*)[10])(__fp - 0x4a)),uVar2);
  }
  else if (param_2 < 0x83d600) {
    uVar2 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490b0 /* "%2uh" */),iVar4);
    RichString_appendnAscii(param_1,uVar7,(*(char (*)[10])(__fp - 0x4a)),uVar2);
    uVar2 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__02u__02u_001490b5 /* "%02u:%02u " */),va0,va1);
    RichString_appendnAscii(param_1,uVar1,(*(char (*)[10])(__fp - 0x4a)),uVar2);
  }
  else {
    iVar3 = (int)(uVar5 / 0x18);
    iVar4 = iVar4 + iVar3 * -0x18;
    if (param_2 < 86400000) {
      uVar2 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490c0 /* "%1ud" */),iVar3);
      RichString_appendnAscii(param_1,uVar8,(*(char (*)[10])(__fp - 0x4a)),uVar2);
      uVar2 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__02uh_001490c5 /* "%02uh" */),iVar4);
      RichString_appendnAscii(param_1,uVar7,(*(char (*)[10])(__fp - 0x4a)),uVar2);
      uVar2 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__02um_001490cb /* "%02um " */),va0);
      RichString_appendnAscii(param_1,uVar1,(*(char (*)[10])(__fp - 0x4a)),uVar2);
    }
    else if (param_2 < 0xbbf81e00) {
      uVar1 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490d2 /* "%4ud" */),iVar3);
      RichString_appendnAscii(param_1,uVar8,(*(char (*)[10])(__fp - 0x4a)),uVar1);
      uVar1 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__02uh_001490d7 /* "%02uh " */),iVar4);
      RichString_appendnAscii(param_1,uVar7,(*(char (*)[10])(__fp - 0x4a)),uVar1);
    }
    else {
      uVar5 = (uVar5 / 0x18) / 0x16d;
      if (param_2 < 0x2de41353000) {
        iVar4 = (int)uVar5;
        uVar1 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490de /* "%3uy" */),iVar4);
        RichString_appendnAscii(param_1,uVar2,(*(char (*)[10])(__fp - 0x4a)),uVar1);
        uVar1 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__03ud_001490e3 /* "%03ud " */),iVar3 + iVar4 * -0x16d);
        RichString_appendnAscii(param_1,uVar8,(*(char (*)[10])(__fp - 0x4a)),uVar1);
      }
      else {
        if (0x7009d32da2ffff < param_2) {
          if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
            RichString_appendAscii(param_1,uVar2,((char *)(long)&s_eternity_001490f1 /* "eternity " */));
            return;
          }
          goto LAB_00131646;
        }
        uVar1 = xSnprintf((*(char (*)[10])(__fp - 0x4a)),10,((char *)(long)&s__7luy_001490ea /* "%7luy " */),uVar5);
        RichString_appendnAscii(param_1,uVar2,(*(char (*)[10])(__fp - 0x4a)),uVar1);
      }
    }
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00131646:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printRate @ 0x131650 */

void Row_printRate(double param_1,int *param_2,char param_3)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  long in_FS_OFFSET = (long)__fake_fs;
  double va0;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = *(uint *)(CRT_colors + 0x74);
  uVar4 = *(uint *)(CRT_colors + 0x78);
  uVar1 = uVar3;
  if (param_3 != '\0') {
    uVar1 = *(uint *)(CRT_colors + 0x80);
  }
  uVar2 = uVar3;
  if (param_3 != '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x30);
  }
  if (param_1 < 0.0) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(param_2,uVar4,((char *)(long)&DAT_0014908c /* "        N/A " */));
      return;
    }
    goto LAB_001318c8;
  }
  if (param_1 < 0.005) {
    uVar3 = __snprintf_chk((*(char (*)[24])(__fp - 0x58)),0x10,2,0x10,((char *)(long)&s__7_2f_B_s_001490fb /* "%7.2f B/s " */),param_1);
    RichString_appendnAscii(param_2,uVar4,(*(char (*)[24])(__fp - 0x58)),uVar3);
  }
  else {
    pcVar5 = ((char *)(long)&s__7_2f_B_s_001490fb /* "%7.2f B/s " */);
    if (1024.0 <= param_1) {
      if (1048576.0 <= param_1) {
        if (param_1 < 1073741824.0) {
          uVar3 = __snprintf_chk((*(char (*)[24])(__fp - 0x58)),0x10,2,0x10,((char *)(long)&s__7_2f_M_s_00149111 /* "%7.2f M/s " */),param_1 * 9.5367431640625e-07);
          RichString_appendnAscii(param_2,uVar1,(*(char (*)[24])(__fp - 0x58)),uVar3);
        }
        else {
          if (param_1 < 1099511627776.0) {
            va0 = param_1 * 9.313225746154785e-10;
            pcVar5 = ((char *)(long)&s__7_2f_G_s_0014911c /* "%7.2f G/s " */);
          }
          else if (param_1 < 1125899906842624.0) {
            va0 = param_1 * 9.094947017729282e-13;
            pcVar5 = ((char *)(long)&s__7_2f_T_s_00149127 /* "%7.2f T/s " */);
          }
          else {
            va0 = param_1 * 8.881784197001252e-16;
            pcVar5 = ((char *)(long)&s__7_2f_P_s_00149132 /* "%7.2f P/s " */);
          }
          uVar3 = __snprintf_chk((*(char (*)[24])(__fp - 0x58)),0x10,2,0x10,pcVar5,va0);
          RichString_appendnAscii(param_2,uVar2,(*(char (*)[24])(__fp - 0x58)),uVar3);
        }
        goto LAB_0013179f;
      }
      param_1 = param_1 * 0.0009765625;
      pcVar5 = ((char *)(long)&s__7_2f_K_s_00149106 /* "%7.2f K/s " */);
    }
    uVar4 = __snprintf_chk((*(char (*)[24])(__fp - 0x58)),0x10,2,0x10,pcVar5,param_1);
    RichString_appendnAscii(param_2,uVar3,(*(char (*)[24])(__fp - 0x58)),uVar4);
  }
LAB_0013179f:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_001318c8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001318d0 @ 0x1318d0 */

void FUN_001318d0(long param_1,int *param_2)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  uint uVar2;
  uint uVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = **(long **)(param_1 + 0x10);
  uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)*(double *)(*(long *)(param_1 + 0x160) + 0x10));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[24])(__fp - 0x58)),uVar2);
  if (*(char *)(lVar1 + 0x5b) == '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x38);
  }
  else {
    uVar2 = *(uint *)(CRT_colors + 0x34);
  }
  RichString_appendAscii(param_2,uVar2,((char *)(long)&DAT_0014903d /* ", " */));
  uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)*(double *)(*(long *)(param_1 + 0x160) + 8));
  if (*(char *)(lVar1 + 0x5b) == '\0') {
    uVar3 = *(uint *)(CRT_colors + 100);
  }
  else {
    uVar3 = *(uint *)(CRT_colors + 0x34);
  }
  RichString_appendnAscii(param_2,uVar3,(*(char (*)[24])(__fp - 0x58)),uVar2);
  if (*(char *)(lVar1 + 0x5b) == '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x38);
  }
  else {
    uVar2 = *(uint *)(CRT_colors + 0x34);
  }
  RichString_appendAscii(param_2,uVar2,((char *)(long)&DAT_0014913d /* " thr" */));
  if (*(char *)(lVar1 + 0x59) == '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x38);
  }
  else {
    uVar2 = *(uint *)(CRT_colors + 0x34);
  }
  RichString_appendAscii(param_2,uVar2,((char *)(long)&DAT_0014903d /* ", " */));
  uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)**(double **)(param_1 + 0x160));
  if (*(char *)(lVar1 + 0x59) == '\0') {
    uVar3 = *(uint *)(CRT_colors + 100);
  }
  else {
    uVar3 = *(uint *)(CRT_colors + 0x34);
  }
  RichString_appendnAscii(param_2,uVar3,(*(char (*)[24])(__fp - 0x58)),uVar2);
  if (*(char *)(lVar1 + 0x59) == '\0') {
    uVar2 = *(uint *)(CRT_colors + 0x38);
  }
  else {
    uVar2 = *(uint *)(CRT_colors + 0x34);
  }
  RichString_appendAscii(param_2,uVar2,((char *)(long)&s_kthr_00149142 /* " kthr" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)(__sec_rodata + 0x118) /* "; " */));
  uVar2 = xSnprintf((*(char (*)[24])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)*(double *)(*(long *)(param_1 + 0x160) + 0x18));
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 100),(*(char (*)[24])(__fp - 0x58)),uVar2);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_running_00149148 /* " running" */));
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

