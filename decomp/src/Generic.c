#include "htop.h"

/* Generic_gettime_realtime @ 0x13add0 */

void Generic_gettime_realtime(undefined1 (*param_1) [16],long *param_2)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  int iVar1;
  long lVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = clock_gettime(0,&(*(timespec *)(__fp - 0x38)));
  if (iVar1 == 0) {
    *(__time_t *)*param_1 = (*(timespec *)(__fp - 0x38)).tv_sec;
    *(long *)(*param_1 + 8) = (*(timespec *)(__fp - 0x38)).tv_nsec / 1000;
    lVar2 = (*(timespec *)(__fp - 0x38)).tv_sec * 1000 + (ulong)(*(timespec *)(__fp - 0x38)).tv_nsec / 1000000;
  }
  else {
    lVar2 = 0;
    *(undefined16 *)(*param_1) = (undefined16)0x0;
  }
  *param_2 = lVar2;
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Generic_gettime_monotonic @ 0x13ae90 */

void Generic_gettime_monotonic(long *param_1)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  int iVar1;
  long lVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = clock_gettime(1,&(*(timespec *)(__fp - 0x38)));
  lVar2 = 0;
  if (iVar1 == 0) {
    lVar2 = (ulong)(*(timespec *)(__fp - 0x38)).tv_nsec / 1000000 + (*(timespec *)(__fp - 0x38)).tv_sec * 1000;
  }
  *param_1 = lVar2;
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Generic_hostname @ 0x13af00 */

void Generic_hostname(char *param_1,long param_2)

{
  gethostname(param_1,param_2 - 1);
  param_1[param_2 + -1] = '\0';
  return;
}


/* Generic_uname @ 0x1406b0 */

undefined1 * Generic_uname(void)

{
  if (CHAR____0015d7d3 != '\0') {
    return &DAT_0015d680;
  }
  FUN_001402d0();
  return &DAT_0015d680;
}


/* FUN_001406e0 @ 0x1406e0 */

void FUN_001406e0(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  char *pcVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;

  lVar1 = *(long *)(param_1 + 0x10);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(lVar1 + 0xe8);
  uVar9 = 0;
  puVar2 = *(undefined8 **)(param_1 + 0x160);
  DAT_0015d8e8 = 0;
  PTR_0015d8e0 = ((char *)(long)&s_used__00148889 /* " used:" */);
  lVar6 = 0;
  *puVar2 = 0;
  puVar2[1] = 0x7ff8000000000000;
  DAT_0015d8f0 = 0;
  DAT_0015d8f8 = 0;
  puVar2[2] = 0x7ff8000000000000;
  puVar2[3] = 0x7ff8000000000000;
  uVar8 = 0;
  do {
    uVar4 = *(ulong *)(lVar1 + 0xf0 + lVar6);
    uVar7 = uVar8;
    if (uVar4 != 0xffffffffffffffff) {
      uVar9 = uVar9 + uVar4;
      pcVar3 = *(char **)((long)&PTR_s_64K__00158200 + lVar6);
      uVar7 = uVar8 + 1;
      puVar2[uVar8] = (double)uVar4;
      (&PTR_0015d8e0)[uVar8] = pcVar3;
      if (uVar7 == 4) break;
    }
    lVar6 = lVar6 + 8;
    uVar8 = uVar7;
  } while (lVar6 != 0xc0);
  iVar5 = Meter_humanUnit((double)uVar9,(char *)(param_1 + 0x60),0x100);
  if (-1 < iVar5) {
    uVar9 = (ulong)iVar5;
    if ((uVar9 < 0x100) && (uVar9 != 0xff)) {
      pcVar3 = (char *)(param_1 + 0x60) + uVar9;
      pcVar3[0] = '/';
      pcVar3[1] = '\0';
      Meter_humanUnit(*(double *)(param_1 + 0x168),(char *)(param_1 + 0x61 + uVar9),0xff - uVar9);
      return;
    }
  }
  return;
}


/* FUN_001408a0 @ 0x1408a0 */

void FUN_001408a0(long param_1)

{
  double *pdVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  double dVar7;

  lVar6 = *(long *)(param_1 + 0x10);
  uVar3 = *(ulong *)(lVar6 + 0x218);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(lVar6 + 0x210);
  dVar7 = (double)uVar3;
  lVar6 = *(long *)(lVar6 + 0x220);
  pdVar1 = *(double **)(param_1 + 0x160);
  *pdVar1 = dVar7;
  pdVar1[1] = (double)(lVar6 - uVar3);
  iVar2 = Meter_humanUnit(dVar7,(char *)(param_1 + 0x60),0x100);
  if (-1 < iVar2) {
    uVar3 = (ulong)iVar2;
    if ((uVar3 < 0x100) && (uVar3 != 0xff)) {
      pcVar5 = (char *)(param_1 + 0x60) + uVar3;
      pcVar5[0] = '(';
      pcVar5[1] = '\0';
      uVar3 = 0xff - uVar3;
      iVar2 = Meter_humanUnit(**(double **)(param_1 + 0x160) + (*(double **)(param_1 + 0x160))[1],
                              pcVar5 + 1,uVar3);
      if ((-1 < iVar2) && (uVar4 = (ulong)iVar2, uVar4 < uVar3)) {
        lVar6 = uVar3 - uVar4;
        pcVar5 = pcVar5 + 1 + uVar4;
        if (lVar6 != 1) {
          *pcVar5 = ')';
          if (lVar6 != 2) {
            pcVar5[1] = '/';
            pcVar5[2] = '\0';
            Meter_humanUnit(*(double *)(param_1 + 0x168),pcVar5 + 2,lVar6 - 2);
            return;
          }
          pcVar5[1] = '\0';
        }
      }
    }
  }
  return;
}


/* FUN_00140a50 @ 0x140a50 */

void FUN_00140a50(long param_1)

{
  int iVar1;
  ulong uVar2;

  ZfsArcMeter_readStats(param_1,*(long *)(param_1 + 0x10) + 0x1b8);
  iVar1 = Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 0x28),(char *)(param_1 + 0x60),
                          0x100);
  if (-1 < iVar1) {
    uVar2 = (ulong)iVar1;
    if ((uVar2 < 0x100) && (uVar2 != 0xff)) {
      *(undefined2 *)(param_1 + 0x60 + uVar2) = 0x2f;
      Meter_humanUnit(*(double *)(param_1 + 0x168),(char *)(param_1 + 0x61 + uVar2),0xff - uVar2);
      return;
    }
  }
  return;
}


/* FUN_00140ad0 @ 0x140ad0 */

void FUN_00140ad0(long param_1,int *param_2)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  uint *puVar1;
  char *pcVar2;
  long lVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar3 = 0;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit(*(double *)(param_1 + 0x168),(*(char (*)[56])(__fp - 0x78)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x78)));
  do {
    pcVar2 = *(char **)((long)&PTR_0015d8e0 + lVar3 * 2);
    if (pcVar2 == (char *)0x0) break;
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),pcVar2);
    Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + lVar3 * 2),(*(char (*)[56])(__fp - 0x78)),0x32);
    puVar1 = (uint *)(CRT_colors + 0xe4 + lVar3);
    lVar3 = lVar3 + 4;
    RichString_appendAscii(param_2,*puVar1,(*(char (*)[56])(__fp - 0x78)));
  } while (lVar3 != 0x10);
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00140bc0 @ 0x140bc0 */

void FUN_00140bc0(long param_1,int *param_2)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit(*(double *)(param_1 + 0x168),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  Meter_humanUnit(**(double **)(param_1 + 0x160),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_used__00148889 /* " used:" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  Meter_humanUnit(**(double **)(param_1 + 0x160) + (*(double **)(param_1 + 0x160))[1],(*(char (*)[56])(__fp - 0x68)),0x32)
  ;
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_uncompressed__00149dd7 /* " uncompressed:" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00140ce0 @ 0x140ce0 */

void FUN_00140ce0(long param_1,int *param_2)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (*(double *)(*(long *)(param_1 + 0x160) + 0x28) <= 0.0) {
    RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_001470dd /* " " */));
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x14),((char *)(long)(__sec_rodata + 0x30be) /* "Unavailable" */));
      return;
    }
  }
  else {
    Meter_humanUnit(*(double *)(param_1 + 0x168),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
    Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 0x28),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Used__00149de6 /* " Used:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
    Meter_humanUnit(**(double **)(param_1 + 0x160),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_MFU__00149ded /* " MFU:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x174),(*(char (*)[56])(__fp - 0x68)));
    Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 8),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_MRU__00149df3 /* " MRU:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x178),(*(char (*)[56])(__fp - 0x68)));
    Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 0x10),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Anon__00149df9 /* " Anon:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x17c),(*(char (*)[56])(__fp - 0x68)));
    Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 0x18),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Hdr__00149e00 /* " Hdr:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x180),(*(char (*)[56])(__fp - 0x68)));
    Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 0x20),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_Oth__00149e06 /* " Oth:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x184),(*(char (*)[56])(__fp - 0x68)));
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

