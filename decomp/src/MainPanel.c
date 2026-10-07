#include "htop.h"

/* MainPanel_selectedRow @ 0x121320 */

undefined4 MainPanel_selectedRow(long param_1)

{
  long lVar1;
  undefined4 uVar2;

  uVar2 = 0xffffffff;
  if ((0 < (int)(*(long **)(param_1 + 0x20))[3]) &&
     (lVar1 = *(long *)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8),
     lVar1 != 0)) {
    uVar2 = *(undefined4 *)(lVar1 + 0x10);
  }
  return uVar2;
}


/* MainPanel_foreachRow @ 0x121350 */

uint MainPanel_foreachRow
               (long param_1,undefined *param_2,long param_3,char *param_4,long param_r8,
               long param_r9)

{
  char cVar1;
  long lVar2;
  long *plVar3;
  char *a3;
  long lVar4;
  char cVar5;
  uint uVar6;

  plVar3 = *(long **)(param_1 + 0x20);
  if ((int)plVar3[3] < 1) {
    cVar5 = '\0';
    uVar6 = 1;
  }
  else {
    lVar4 = 0;
    cVar5 = '\0';
    uVar6 = 1;
    a3 = param_4;
    do {
      lVar2 = *(long *)(*plVar3 + lVar4 * 8);
      cVar1 = *(char *)(lVar2 + 0x1d);
      if (cVar1 != '\0') {
        lVar2 = (*(code *)param_2)(lVar2,param_3,*plVar3,(long)a3,param_r8,param_r9);
        uVar6 = uVar6 & (uint)lVar2;
        plVar3 = *(long **)(param_1 + 0x20);
        cVar5 = cVar1;
      }
      lVar4 = lVar4 + 1;
    } while ((int)lVar4 < (int)plVar3[3]);
    if ((cVar5 != '\x01') && (0 < (int)plVar3[3])) {
      lVar4 = *(long *)(*plVar3 + (long)*(int *)(param_1 + 0x28) * 8);
      if (lVar4 == 0) {
        cVar5 = '\0';
      }
      else {
        lVar4 = (*(code *)param_2)(lVar4,param_3,(long)*(int *)(param_1 + 0x28),(long)a3,param_r8,
                                   param_r9);
        cVar5 = '\0';
        uVar6 = uVar6 & (uint)lVar4;
      }
    }
  }
  if (param_4 != (char *)0x0) {
    *param_4 = cVar5;
  }
  return uVar6;
}


/* MainPanel_setState @ 0x121420 */

void MainPanel_setState(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x26e0) = param_2;
  return;
}


/* MainPanel_setFunctionBar @ 0x121430 */

void MainPanel_setFunctionBar(long param_1,char param_2)

{
  undefined8 uVar1;

  uVar1 = *(undefined8 *)(param_1 + 0x2700);
  if (param_2 == '\0') {
    uVar1 = *(undefined8 *)(param_1 + 0x26f8);
  }
  *(undefined8 *)(param_1 + 0x58) = uVar1;
  *(undefined8 *)(*(long *)(param_1 + 0x26e8) + 0x140) = uVar1;
  return;
}


/* MainPanel_delete @ 0x126d80 */

void MainPanel_delete(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                     long param_r9)

{
  int *piVar1;
  void *__ptr;
  long extraout_RDX;

  *(undefined8 *)((long)param_1 + 0x58) = *(undefined8 *)((long)param_1 + 0x26f8);
  piVar1 = *(int **)((long)param_1 + 0x2700);
  *(undefined8 *)(*(long *)((long)param_1 + 0x26e8) + 0x140) =
       *(undefined8 *)((long)param_1 + 0x26f8);
  FunctionBar_delete(piVar1);
  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9)
  ;
  FunctionBar_delete(*(int **)((long)param_1 + 0x58));
  if (0x15e < *(int *)((long)param_1 + 0x60)) {
    free(*(void **)((long)param_1 + 0x68));
    *(long *)((long)param_1 + 0x68) = (long)param_1 + 0x70;
  }
  __ptr = *(void **)((long)param_1 + 0x26e8);
  FunctionBar_delete(*(int **)((long)__ptr + 0x88));
  FunctionBar_delete(*(int **)((long)__ptr + 0x120));
  free(__ptr);
  free(*(void **)((long)param_1 + 0x26f0));
  free(param_1);
  return;
}


/* MainPanel_updateLabels @ 0x129160 */

void MainPanel_updateLabels(long param_1,char param_2,char param_3)

{
  int *piVar1;
  char *pcVar2;

  piVar1 = *(int **)(param_1 + 0x58);
  pcVar2 = ((char *)(long)&s_Tree_0014750f /* "Tree  " */);
  if (param_2 != '\0') {
    pcVar2 = ((char *)(long)&s_List_00147508 /* "List  " */);
  }
  FunctionBar_setLabel(piVar1,0x10d,pcVar2);
  pcVar2 = ((char *)(long)&s_Filter_0014751d /* "Filter" */);
  if (param_3 != '\0') {
    pcVar2 = ((char *)(long)&s_FILTER_00147516 /* "FILTER" */);
  }
  FunctionBar_setLabel(piVar1,0x10c,pcVar2);
  return;
}


/* FUN_001291c0 @ 0x1291c0 */

void FUN_001291c0(long param_1,char param_2)

{
  if ((param_2 == '\0') || (*(long *)(*(long *)(param_1 + 0x26e8) + 0x130) != 0)) {
    IncSet_drawBar(*(long *)(param_1 + 0x26e8),*(int *)(CRT_colors + 8));
    if (*(char *)(*(long *)(param_1 + 0x26e0) + 0x18) != '\0') {
      FunctionBar_append(((char *)(long)&s_PAUSED_00148882 /* "PAUSED" */),*(int *)(CRT_colors + 0x18));
      return;
    }
  }
  return;
}


/* FUN_00129230 @ 0x129230 */

void FUN_00129230(long param_1)

{
  Table_printHeader(*(long *)**(undefined8 **)(param_1 + 0x26e0),(int *)(param_1 + 0x60));
  return;
}


/* MainPanel_new @ 0x129250 */

undefined8 * MainPanel_new(void)

{
  long lVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined8 *puVar5;
  bool bVar6;

  puVar2 = malloc(10000);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = MainPanel_class;
    puVar3 = FunctionBar_new(&PTR_s_Help_00157b40,0,0);
    puVar2[0x4df] = puVar3;
    puVar3 = FunctionBar_new(&PTR_s_Help_00157ae0,0,0);
    bVar6 = CHAR____0015c0d9 == '\0';
    puVar2[0x4e0] = puVar3;
    if (bVar6) {
      puVar3 = (undefined4 *)puVar2[0x4df];
    }
    Panel_init((long)puVar2,1,1,1,1,Row_class,0,puVar3);
    pvVar4 = calloc(0x1ff,8);
    if (pvVar4 != (void *)0x0) {
      puVar2[0x4de] = pvVar4;
      puVar5 = IncSet_new(puVar3);
      puVar2[0x4dd] = puVar5;
      Action_setBindings(puVar2[0x4de]);
      lVar1 = puVar2[0x4de];
      *(code **)(lVar1 + 0x348) = FUN_001443c0;
      *(code **)(lVar1 + 0x3d8) = FUN_0013dee0;
      *(code **)(lVar1 + 1000) = FUN_0013dd80;
      *(code **)(lVar1 + 0x8d8) = FUN_0013dee0;
      *(code **)(lVar1 + 0x8e0) = FUN_0013dd80;
      return puVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001293a0 @ 0x1293a0 */

void FUN_001293a0(long param_1)

{
  char *pcVar1;
  double *pdVar2;
  int iVar3;
  ulong uVar4;
  double dVar5;

  pdVar2 = *(double **)(param_1 + 0x160);
  pdVar2[5] = NAN;
  pdVar2[1] = NAN;
  pdVar2[2] = NAN;
  Platform_setMemoryValues(param_1);
  *(undefined1 *)(param_1 + 0x50) = 5;
  dVar5 = *pdVar2;
  if (0.0 < pdVar2[1]) {
    dVar5 = dVar5 + pdVar2[1];
  }
  if (0.0 < pdVar2[2]) {
    dVar5 = dVar5 + pdVar2[2];
  }
  iVar3 = Meter_humanUnit(dVar5,(char *)(param_1 + 0x60),0x100);
  if (-1 < iVar3) {
    uVar4 = (ulong)iVar3;
    if ((uVar4 < 0x100) && (uVar4 != 0xff)) {
      pcVar1 = (char *)(param_1 + 0x60) + uVar4;
      pcVar1[0] = '/';
      pcVar1[1] = '\0';
      Meter_humanUnit(*(double *)(param_1 + 0x168),(char *)(param_1 + 0x61 + uVar4),0xff - uVar4);
      return;
    }
  }
  return;
}


/* FUN_00129470 @ 0x129470 */

void FUN_00129470(long param_1,int *param_2)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  double dVar1;
  long lVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit(*(double *)(param_1 + 0x168),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  Meter_humanUnit(**(double **)(param_1 + 0x160),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_used__00148889 /* " used:" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0xcc),(*(char (*)[56])(__fp - 0x68)));
  lVar2 = *(long *)(param_1 + 0x160);
  if (0.0 <= *(double *)(lVar2 + 8)) {
    Meter_humanUnit(*(double *)(lVar2 + 8),(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_shared__00148890 /* " shared:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0xdc),(*(char (*)[56])(__fp - 0x68)));
    lVar2 = *(long *)(param_1 + 0x160);
    dVar1 = *(double *)(lVar2 + 0x10);
  }
  else {
    dVar1 = *(double *)(lVar2 + 0x10);
  }
  if (0.0 <= dVar1) {
    Meter_humanUnit(dVar1,(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_compressed__00148899 /* " compressed:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0xe0),(*(char (*)[56])(__fp - 0x68)));
    lVar2 = *(long *)(param_1 + 0x160);
  }
  Meter_humanUnit(*(double *)(lVar2 + 0x18),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_buffers__001488a6 /* " buffers:" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0xd4),(*(char (*)[56])(__fp - 0x68)));
  Meter_humanUnit(*(double *)(*(long *)(param_1 + 0x160) + 0x20),(*(char (*)[56])(__fp - 0x68)),0x32);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_cache__001488b0 /* " cache:" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0xd8),(*(char (*)[56])(__fp - 0x68)));
  dVar1 = *(double *)(*(long *)(param_1 + 0x160) + 0x28);
  if (0.0 <= dVar1) {
    Meter_humanUnit(dVar1,(*(char (*)[56])(__fp - 0x68)),0x32);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_available__001488b8 /* " available:" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x3c),(*(char (*)[56])(__fp - 0x68)));
  }
  if ((*(long *)(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_001296f0 @ 0x1296f0 */

void FUN_001296f0(undefined8 param_1,int *param_2)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  uint uVar1;
  char *pcVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (INT_0015c060 == 2) {
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar1 = *(uint *)(CRT_colors + 0x40);
      pcVar2 = ((char *)(long)&s_no_data_001476cb /* "no data" */);
LAB_00129831:
      RichString_writeAscii(param_2,uVar1,pcVar2);
      return;
    }
  }
  else if (INT_0015c060 == 3) {
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar1 = *(uint *)(CRT_colors + 0x54);
      pcVar2 = ((char *)(long)&s_stale_data_00147702 /* "stale data" */);
      goto LAB_00129831;
    }
  }
  else if (INT_0015c060 == 1) {
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar1 = *(uint *)(CRT_colors + 0x3c);
      pcVar2 = ((char *)(long)&s_initializing____001476f2 /* "initializing..." */);
      goto LAB_00129831;
    }
  }
  else {
    RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_001488c4 /* "rx: " */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x44),&DAT_0015d638);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x44),((char *)(long)&DAT_00147715 /* "iB/s" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_tx__001488c9 /* " tx: " */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x48),&DAT_0015d610);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x48),((char *)(long)&DAT_00147715 /* "iB/s" */));
    uVar1 = xSnprintf((*(char (*)[72])(__fp - 0x78)),0x40,((char *)(long)&s___u__u_pkts_s__001488cf /* " (%u/%u pkts/s) " */),INT_0015d628,INT_0015d604);
    RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x38),(*(char (*)[72])(__fp - 0x78)),uVar1);
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00129890 @ 0x129890 */

void FUN_00129890(long param_1,int *param_2)

{
  char cVar1;

  RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&DAT_0014703c /* "[" */));
  if (*(char **)(param_1 + 0x10) == (char *)0x0) {
    cVar1 = *(char *)(param_1 + 0x18);
  }
  else {
    cVar1 = **(char **)(param_1 + 0x10);
  }
  if (cVar1 == '\0') {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x108),((char *)(long)&DAT_001470dd /* " " */));
  }
  else {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x108),((char *)(long)&DAT_00149f75 /* "x" */));
  }
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&s___001488e0 /* "]    " */));
  RichString_appendWide(param_2,*(uint *)(CRT_colors + 0x10c),*(char **)(param_1 + 8));
  return;
}


/* FUN_00129950 @ 0x129950 */

void FUN_00129950(long param_1,int *param_2)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  int iVar2;
  int iVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&DAT_0014703c /* "[" */));
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 < 0) {
    dVar4 = pow(10.0,(double)iVar3);
    if (*(int **)(param_1 + 0x18) == (int *)0x0) {
      iVar2 = *(int *)(param_1 + 0x20);
    }
    else {
      iVar2 = **(int **)(param_1 + 0x18);
    }
    uVar1 = xSnprintf((*(char (*)[12])(__fp - 0x4c)),0xc,((char *)(long)&DAT_001488e6 /* "%.*f" */),-iVar3,(double)iVar2 * dVar4);
  }
  else {
    if (iVar3 == 0) {
      if (*(int **)(param_1 + 0x18) == (int *)0x0) {
        iVar3 = *(int *)(param_1 + 0x20);
      }
      else {
        iVar3 = **(int **)(param_1 + 0x18);
      }
    }
    else {
      dVar4 = pow(10.0,(double)iVar3);
      if (*(int **)(param_1 + 0x18) == (int *)0x0) {
        iVar3 = *(int *)(param_1 + 0x20);
      }
      else {
        iVar3 = **(int **)(param_1 + 0x18);
      }
      iVar3 = (int)((double)iVar3 * dVar4);
    }
    uVar1 = xSnprintf((*(char (*)[12])(__fp - 0x4c)),0xc,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),iVar3);
  }
  RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x108),(*(char (*)[12])(__fp - 0x4c)),uVar1);
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&DAT_00149a61 /* "]" */));
  if ((int)uVar1 < 5) {
    do {
      uVar1 = uVar1 + 1;
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&DAT_001470dd /* " " */));
    } while (uVar1 != 5);
  }
  RichString_appendWide(param_2,*(uint *)(CRT_colors + 0x10c),*(char **)(param_1 + 8));
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

