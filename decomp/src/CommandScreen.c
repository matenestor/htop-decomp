#include "htop.h"

/* CommandScreen_delete @ 0x1177f0 */

void CommandScreen_delete
               (void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
               long param_r9)

{
  void *pvVar1;
  long extraout_RDX;
  long extraout_RDX_00;

  pvVar1 = *(void **)((long)param_1 + 0x10);
  free(*(void **)((long)pvVar1 + 0x38));
  Vector_delete(*(long **)((long)pvVar1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x58));
  if (0x15e < *(int *)((long)pvVar1 + 0x60)) {
    free(*(void **)((long)pvVar1 + 0x68));
  }
  free(pvVar1);
  pvVar1 = *(void **)((long)param_1 + 0x18);
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x88));
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x120));
  free(pvVar1);
  Vector_delete(*(long **)((long)param_1 + 0x20),param_rsi,extraout_RDX_00,param_rcx,param_r8,
                param_r9);
  free(param_1);
  return;
}


/* FUN_00117890 @ 0x117890 */

void FUN_00117890(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
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


/* CommandScreen_new @ 0x11acc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CommandScreen_new(undefined8 param_1)

{
  undefined8 *puVar1;

  puVar1 = malloc(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = CommandScreen_class;
    InfoScreen_init((long)puVar1,param_1,(wint_t *)0x0,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0011ad20 @ 0x11ad20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0011ad20(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar5;
  undefined *puVar6;

  uVar3 = 0;
  if (*(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0) {
    plVar2 = *(long **)(param_1[1] + 0x20);
    if (0 < (int)plVar2[3]) {
      lVar5 = *(long *)(*plVar2 + (long)*(int *)(param_1[1] + 0x28) * 8);
      if (lVar5 != 0) {
        puVar1 = malloc(0x28);
        if (puVar1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        puVar6 = &DAT_001470dd;
        *puVar1 = CommandScreen_class;
        uVar4 = (ulong)(_LINES - 2U);
        plVar2 = (long *)InfoScreen_init((long)puVar1,lVar5,(wint_t *)0x0,_LINES - 2U,((char *)(long)&DAT_001470dd /* " " */));
        InfoScreen_run(plVar2,lVar5,extraout_RDX,uVar4,(long)puVar6,param_r9);
        CommandScreen_delete(plVar2,lVar5,extraout_RDX_00,uVar4,(long)puVar6,param_r9);
        wclear(_stdscr);
        halfdelay(*PTR_0015c0d0);
        uVar3 = 0x21;
      }
      return uVar3;
    }
  }
  return 0;
}


/* FUN_0011adf0 @ 0x11adf0 */

void FUN_0011adf0(long param_1,int *param_2)

{
  char *pcVar1;

  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&DAT_0014703c /* "[" */));
  if (*(int *)(param_1 + 0x18) == 2) {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x108),((char *)(long)&DAT_00149f75 /* "x" */));
  }
  else if (*(int *)(param_1 + 0x18) == 1) {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x108),((char *)(long)&DAT_001488f9 /* "o" */));
  }
  else {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x108),((char *)(long)&DAT_001470dd /* " " */));
  }
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x104),((char *)(long)&DAT_00149a61 /* "]" */));
  RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x10c),((char *)(long)&DAT_001470dd /* " " */));
  if (*(char **)(param_1 + 0x10) != (char *)0x0) {
    RichString_appendWide(param_2,*(uint *)(CRT_colors + 0x88),*(char **)(param_1 + 0x10));
    if (*(int *)(param_1 + 0x1c) == 2) {
      pcVar1 = *(char **)(CRT_treeStr + 0x20);
    }
    else {
      pcVar1 = *(char **)(CRT_treeStr + 0x28);
    }
    RichString_appendWide(param_2,*(uint *)(CRT_colors + 0x88),pcVar1);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x10c),((char *)(long)&DAT_001470dd /* " " */));
  }
  RichString_appendWide(param_2,*(uint *)(CRT_colors + 0x10c),*(char **)(param_1 + 8));
  return;
}


/* FUN_0011af60 @ 0x11af60 */

void FUN_0011af60(long *param_1,char param_2,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  uint uVar1;
  code *pcVar2;
  char *pcVar3;
  long extraout_RDX;
  long lVar4;
  uint uVar5;

  pcVar3 = ((char *)(long)&DAT_00149c0c /* "" */);
  lVar4 = 0x10b;
  if ((char)param_1[0x4dd] != '\0') {
    pcVar3 = ((char *)(long)&s_Collapse_Expand_00147401 /* "Collapse/Expand" */);
  }
  FunctionBar_setLabel((int *)param_1[10],0x10b,pcVar3);
  uVar5 = *(uint *)(param_1 + 5);
  Vector_prune((long *)param_1[4],lVar4,extraout_RDX,param_rcx,param_r8,param_r9);
  *(undefined4 *)(param_1 + 8) = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 9) = 1;
  Vector_splice((long *)param_1[4],(long *)param_1[0x4de]);
  *(undefined1 *)(param_1 + 9) = 1;
  if (param_2 != '\0') {
    uVar1 = *(int *)(param_1[4] + 0x18) - 1;
    if (*(int *)(param_1[4] + 0x18) <= (int)uVar5) {
      uVar5 = uVar1;
    }
    if ((int)uVar5 < 0) {
      uVar5 = 0;
    }
    pcVar2 = *(code **)(*param_1 + 0x20);
    *(uint *)(param_1 + 5) = uVar5;
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)((long)param_1,0xffffffff,(ulong)uVar1,param_rcx,param_r8,param_r9);
      *(undefined1 *)(param_1 + 9) = 1;
      return;
    }
  }
  *(undefined1 *)(param_1 + 9) = 1;
  return;
}


/* FUN_0011b030 @ 0x11b030 */

char FUN_0011b030(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  uint uVar1;
  uint uVar2;
  long lVar3;

  lVar3 = 0;
  uVar1 = *(uint *)((long *)param_1[4] + 3);
  if (0 < (int)uVar1) {
    lVar3 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8);
  }
  if (param_2 != 0x128) {
    if (param_2 < 0x129) {
      if (param_2 == 0xd) {
        return '\x04';
      }
      if (param_2 != 0x20) {
        return (param_2 == 10) * '\x02' + '\x02';
      }
    }
    else {
      if (param_2 == 0x157) {
        return '\x04';
      }
      if (param_2 != 0x199) {
        return '\x02';
      }
    }
  }
  uVar2 = *(uint *)(lVar3 + 0x18);
  *(uint *)(lVar3 + 0x18) = (uint)(uVar2 == 0) * 2;
  FUN_0011af60(param_1,'\x01',lVar3,(ulong)uVar2,(ulong)uVar1,param_r9);
  return '\x01';
}

