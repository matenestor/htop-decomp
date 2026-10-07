#include "htop.h"

/* FunctionBar_delete @ 0x116fd0 */

void FunctionBar_delete(int *param_1)

{
  long lVar1;
  void *__ptr;
  long lVar2;

  lVar2 = 0;
  do {
    __ptr = *(void **)(param_1 + 2);
    if (*(void **)((long)__ptr + lVar2) == (void *)0x0) goto LAB_00117002;
    free(*(void **)((long)__ptr + lVar2));
    lVar2 = lVar2 + 8;
  } while (lVar2 != 0x78);
  __ptr = *(void **)(param_1 + 2);
LAB_00117002:
  free(__ptr);
  if ((char)param_1[8] == '\0') {
    lVar2 = 0;
    if (0 < *param_1) {
      do {
        lVar1 = lVar2 * 8;
        lVar2 = lVar2 + 1;
        free(*(void **)(*(long *)(param_1 + 4) + lVar1));
      } while ((int)lVar2 < *param_1);
    }
    free(*(void **)(param_1 + 4));
    free(*(void **)(param_1 + 6));
  }
  free(param_1);
  return;
}


/* FunctionBar_drawExtra @ 0x117060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FunctionBar_drawExtra(int *param_1,char *param_2,int param_3,char param_4)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;

  wattrset(_stdscr,*(int *)(CRT_colors + 8));
  iVar2 = wmove(_stdscr,_LINES + -1,0);
  if (iVar2 != -1) {
    whline(_stdscr,0x20,_COLS);
  }
  if (*param_1 < 1) {
    (*(int *)(__fp - 0x3c)) = 0;
  }
  else {
    (*(int *)(__fp - 0x3c)) = 0;
    lVar4 = 0;
    do {
      wattrset(_stdscr,*(int *)(CRT_colors + 0xc));
      iVar2 = wmove(_stdscr,_LINES + -1,(*(int *)(__fp - 0x3c)));
      lVar1 = lVar4 * 8;
      if (iVar2 != -1) {
        waddnstr(_stdscr,*(char **)(*(long *)(param_1 + 4) + lVar4 * 8),-1);
      }
      sVar3 = strlen(*(char **)(*(long *)(param_1 + 4) + lVar1));
      (*(int *)(__fp - 0x3c)) = (*(int *)(__fp - 0x3c)) + (int)sVar3;
      wattrset(_stdscr,*(int *)(CRT_colors + 8));
      iVar2 = wmove(_stdscr,_LINES + -1,(*(int *)(__fp - 0x3c)));
      if (iVar2 != -1) {
        waddnstr(_stdscr,*(char **)(*(long *)(param_1 + 2) + lVar1),-1);
      }
      lVar4 = lVar4 + 1;
      sVar3 = strlen(*(char **)(*(long *)(param_1 + 2) + lVar1));
      (*(int *)(__fp - 0x3c)) = (*(int *)(__fp - 0x3c)) + (int)sVar3;
    } while ((int)lVar4 < *param_1);
  }
  iVar2 = 0;
  if (param_2 != (char *)0x0) {
    if (param_3 == -1) {
      wattrset(_stdscr,*(int *)(CRT_colors + 8));
    }
    else {
      wattrset(_stdscr,param_3);
    }
    iVar2 = wmove(_stdscr,_LINES + -1,(*(int *)(__fp - 0x3c)));
    if (iVar2 != -1) {
      waddnstr(_stdscr,param_2,-1);
    }
    sVar3 = strlen(param_2);
    iVar2 = (*(int *)(__fp - 0x3c)) + (int)sVar3;
    (*(int *)(__fp - 0x3c)) = iVar2;
  }
  wattrset(_stdscr,*(int *)CRT_colors);
  if (param_4 == '\0') {
    curs_set(0);
  }
  else {
    curs_set(1);
  }
  INT_0015c0e8 = (*(int *)(__fp - 0x3c));
  return iVar2;
}


/* FunctionBar_draw @ 0x117270 */

void FunctionBar_draw(int *param_1)

{
  FunctionBar_drawExtra(param_1,(char *)0x0,-1,'\0');
  return;
}


/* FunctionBar_append @ 0x117290 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FunctionBar_append(char *param_1,int param_2)

{
  int iVar1;
  size_t sVar2;

  if (param_2 == -1) {
    wattrset(_stdscr,*(int *)(CRT_colors + 8));
  }
  else {
    wattrset(_stdscr,param_2);
  }
  iVar1 = wmove(_stdscr,_LINES + -1,INT_0015c0e8 + 1);
  if (iVar1 != -1) {
    waddnstr(_stdscr,param_1,-1);
  }
  wattrset(_stdscr,*(int *)CRT_colors);
  sVar2 = strlen(param_1);
  INT_0015c0e8 = INT_0015c0e8 + 1 + (int)sVar2;
  return;
}


/* FunctionBar_synthesizeEvent @ 0x117350 */

undefined4 FunctionBar_synthesizeEvent(int *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  long lVar7;

  iVar1 = *param_1;
  if (0 < iVar1) {
    lVar2 = *(long *)(param_1 + 4);
    lVar3 = *(long *)(param_1 + 2);
    lVar7 = 0;
    iVar6 = 0;
    do {
      sVar4 = strlen(*(char **)(lVar2 + lVar7 * 8));
      sVar5 = strlen(*(char **)(lVar3 + lVar7 * 8));
      iVar6 = iVar6 + (int)sVar4 + (int)sVar5;
      if (param_2 < iVar6) {
        return *(undefined4 *)(*(long *)(param_1 + 6) + lVar7 * 4);
      }
      lVar7 = lVar7 + 1;
    } while (iVar1 != lVar7);
  }
  return 0xffffffff;
}


/* FunctionBar_new @ 0x117e30 */

undefined4 * FunctionBar_new(undefined **param_1,long param_2,long param_3)

{
  long lVar1;
  undefined4 *puVar2;
  void *pvVar3;
  char *pcVar4;
  long lVar5;
  undefined8 *puVar6;

  puVar2 = calloc(1,0x28);
  if (puVar2 != (undefined4 *)0x0) {
    pvVar3 = calloc(0x10,8);
    if (pvVar3 != (void *)0x0) {
      *(void **)(puVar2 + 2) = pvVar3;
      if (param_1 == (undefined **)0x0) {
        param_1 = &PTR_DAT_00155c60;
      }
      lVar5 = 0;
      do {
        if (*(char **)((long)param_1 + lVar5) == (char *)0x0) break;
        puVar6 = (undefined8 *)(*(long *)(puVar2 + 2) + lVar5);
        pcVar4 = strdup(*(char **)((long)param_1 + lVar5));
        if (pcVar4 == (char *)0x0) goto LAB_00117fb1;
        lVar5 = lVar5 + 8;
        *puVar6 = pcVar4;
      } while (lVar5 != 0x78);
      if ((param_2 == 0) || (param_3 == 0)) {
        *(undefined1 *)(puVar2 + 8) = 1;
        lVar5 = 10;
        *(undefined ***)(puVar2 + 4) = &PTR_DAT_00155c00;
        *(undefined **)(puVar2 + 6) = &DAT_0015b220;
LAB_00117f06:
        *puVar2 = (int)lVar5;
        return puVar2;
      }
      *(undefined1 *)(puVar2 + 8) = 0;
      pvVar3 = calloc(0xf,8);
      if (pvVar3 != (void *)0x0) {
        *(void **)(puVar2 + 4) = pvVar3;
        pvVar3 = calloc(0xf,4);
        if (pvVar3 != (void *)0x0) {
          *(void **)(puVar2 + 6) = pvVar3;
          lVar5 = 0;
          do {
            if (param_1[lVar5] == (undefined *)0x0) goto LAB_00117f06;
            lVar1 = *(long *)(puVar2 + 4);
            pcVar4 = strdup(*(char **)(param_2 + lVar5 * 8));
            if (pcVar4 == (char *)0x0) goto LAB_00117fb1;
            *(char **)(lVar5 * 8 + lVar1) = pcVar4;
            *(undefined4 *)(*(long *)(puVar2 + 6) + lVar5 * 4) =
                 *(undefined4 *)(param_3 + lVar5 * 4);
            lVar5 = lVar5 + 1;
          } while (lVar5 != 0xf);
          lVar5 = 0xf;
          goto LAB_00117f06;
        }
      }
    }
  }
LAB_00117fb1:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FunctionBar_newEnterEsc @ 0x117fc0 */

void FunctionBar_newEnterEsc(undefined *param_1,undefined8 param_2)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x10)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x18)) = 0;
  (*(undefined * *)(__fp - 0x28)) = param_1;
  (*(undefined8 *)(__fp - 0x20)) = param_2;
  FunctionBar_new(&(*(undefined * *)(__fp - 0x28)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
  if ((*(long *)(__fp - 0x10)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FunctionBar_setLabel @ 0x118020 */

void FunctionBar_setLabel(int *param_1,int param_2,char *param_3)

{
  long lVar1;
  long lVar2;
  char *pcVar3;

  if (*param_1 < 1) {
    return;
  }
  lVar2 = 0;
  do {
    if (*(int *)(*(long *)(param_1 + 6) + lVar2 * 4) == param_2) {
      free(*(void **)(*(long *)(param_1 + 2) + lVar2 * 8));
      lVar1 = *(long *)(param_1 + 2);
      pcVar3 = strdup(param_3);
      if (pcVar3 != (char *)0x0) {
        *(char **)(lVar2 * 8 + lVar1) = pcVar3;
        return;
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
    lVar2 = lVar2 + 1;
  } while (*param_1 != lVar2);
  return;
}

