#include "htop.h"

/* InfoScreen_done @ 0x126cf0 */

long InfoScreen_done(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                    long param_r9)

{
  void *pvVar1;
  long extraout_RDX;
  long extraout_RDX_00;

  pvVar1 = *(void **)(param_1 + 0x10);
  free(*(void **)((long)pvVar1 + 0x38));
  Vector_delete(*(long **)((long)pvVar1 + 0x20),param_rsi,extraout_RDX,param_rcx,param_r8,param_r9);
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x58));
  if (0x15e < *(int *)((long)pvVar1 + 0x60)) {
    free(*(void **)((long)pvVar1 + 0x68));
  }
  free(pvVar1);
  pvVar1 = *(void **)(param_1 + 0x18);
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x88));
  FunctionBar_delete(*(int **)((long)pvVar1 + 0x120));
  free(pvVar1);
  Vector_delete(*(long **)(param_1 + 0x20),param_rsi,extraout_RDX_00,param_rcx,param_r8,param_r9);
  return param_1;
}


/* InfoScreen_init @ 0x127350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long InfoScreen_init(long param_1,undefined8 param_2,wint_t *param_3,undefined4 param_4,
                    char *param_5)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  uint uVar1;
  wint_t __wc;
  long lVar2;
  undefined1 *puVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  size_t sVar8;
  ulong uVar9;
  ulong uVar10;
  undefined1 *puVar11;
  wint_t *pwVar13;
  undefined1 (*pauVar14) [16];
  long in_FS_OFFSET = (long)__fake_fs;
  undefined8 uVar15;
  undefined1 *puVar12;

  puVar12 = (*(undefined1 (*)[8])(__fp - 0x68));
  puVar11 = (*(undefined1 (*)[8])(__fp - 0x68));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(param_1 + 8) = param_2;
  if (param_3 == (wint_t *)0x0) {
    (*(wint_t * *)(__fp - 0x58)) = (wint_t *)CONCAT44((*(uint *)((char *)&(*(wint_t * *)(__fp - 0x58)) + 4)),param_4);
    param_3 = FunctionBar_new(&PTR_s_Search_00157bc0,(long)&PTR_DAT_00157ba0,(long)&DAT_0014dbb0);
    param_4 = (*(uint *)((char *)&(*(wint_t * *)(__fp - 0x58)) + 0));
  }
  uVar15 = CONCAT44(param_4,_COLS);
  (*(wint_t * *)(__fp - 0x58)) = param_3;
  (*(wint_t * *)(__fp - 0x50)) = param_3;
  puVar6 = malloc(0x26e0);
  if (puVar6 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  puVar6[2] = uVar15;
  puVar6[3] = 0;
  *puVar6 = Panel_class;
  puVar6[7] = 0;
  puVar6[1] = 0x100000000;
  puVar7 = Vector_new(ListItem_class,0,-1);
  *(undefined8 **)(param_1 + 0x10) = puVar6;
  puVar6[4] = puVar7;
  *(undefined2 *)(puVar6 + 9) = 1;
  puVar6[0xd] = puVar6 + 0xe;
  puVar6[8] = 0;
  puVar6[5] = 0;
  *(undefined4 *)(puVar6 + 6) = 0;
  *(undefined1 *)((long)puVar6 + 0x4a) = 0;
  *(undefined4 *)(puVar6 + 0xc) = 0;
  *(undefined8 *)((long)puVar6 + 0x26d4) = 0x900000000;
  *(undefined16 *)(*(undefined1 (*) [16])(puVar6 + 0xe)) = (undefined16)0x0;
  puVar6[10] = (*(wint_t * *)(__fp - 0x58));
  puVar6[0xb] = (*(wint_t * *)(__fp - 0x50));
  *(undefined16 *)(*(undefined1 (*) [16])((long)puVar6 + 0x7c)) = (undefined16)0x0;
  puVar6 = IncSet_new(param_3);
  *(undefined8 **)(param_1 + 0x18) = puVar6;
  (*(long *)(__fp - 0x60)) = *(long *)(param_1 + 0x10);
  puVar6 = Vector_new(*(undefined8 *)(*(long *)((*(long *)(__fp - 0x60)) + 0x20) + 8),1,-1);
  *(undefined8 **)(param_1 + 0x20) = puVar6;
  uVar1 = *(uint *)(CRT_colors + 0x1c);
  sVar8 = strlen(param_5);
  uVar10 = (ulong)((int)sVar8 + 1);
  uVar9 = uVar10 * 4 + 0xf;
  puVar3 = (*(undefined1 (*)[8])(__fp - 0x68));
  while (puVar12 != (*(undefined1 (*)[8])(__fp - 0x68)) + -(uVar9 & 0xfffffffffffff000)) {
    puVar11 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar12 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar9 = (ulong)((uint)uVar9 & 0xff0);
  lVar2 = -uVar9;
  pwVar13 = (wint_t *)(puVar11 + lVar2);
  if (uVar9 != 0) {
    *(undefined8 *)(puVar11 + -8) = *(undefined8 *)(puVar11 + -8);
  }
  uVar9 = __mbstowcs_chk((int *)(puVar11 + lVar2),param_5,(long)(int)sVar8,
                         uVar10 & 0x3fffffffffffffff);
  lVar4 = (*(long *)(__fp - 0x60));
  iVar5 = (int)uVar9;
  if (0 < iVar5) {
    FUN_00130130((int *)((*(long *)(__fp - 0x60)) + 0x60),iVar5);
    (*(wint_t * *)(__fp - 0x58)) = (wint_t *)(puVar11 + (ulong)(iVar5 - 1) * 4 + lVar2 + 4);
    pauVar14 = *(undefined1 (**) [16])(lVar4 + 0x68);
    do {
      __wc = *pwVar13;
      iVar5 = iswprint(__wc);
      *(undefined16 *)(*pauVar14) = (undefined16)0x0;
      if (iVar5 == 0) {
        __wc = 0xfffd;
      }
      pwVar13 = pwVar13 + 1;
      *(uint *)*pauVar14 = uVar1 & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar14 + 0xc)) = (undefined16)0x0;
      *(wint_t *)(*pauVar14 + 4) = __wc;
      pauVar14 = (undefined1 (*) [16])(pauVar14[1] + 0xc);
    } while (pwVar13 != (*(wint_t * *)(__fp - 0x58)));
  }
  *(undefined1 *)((*(long *)(__fp - 0x60)) + 0x48) = 1;
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


/* InfoScreen_drawTitled @ 0x128160 */
void InfoScreen_drawTitled(void *this,char *fmt,...)

{
  __builtin_va_list ap;
  int n;
  int len = _COLS + 1;
  char title[len];

  __builtin_va_start(ap,fmt);
  n = vsnprintf(title,len,fmt,ap);
  __builtin_va_end(ap);
  if (_COLS < n) {
    memset(title + (_COLS - 3),'.',3);
  }
  wattrset(_stdscr,*(undefined4 *)((char *)CRT_colors + 0x38));
  if (wmove(_stdscr,0,0) != -1) {
    whline(_stdscr,0x20,_COLS);
  }
  if (wmove(_stdscr,0,0) != -1) {
    waddnstr(_stdscr,title,-1);
  }
  wattrset(_stdscr,*(undefined4 *)((char *)CRT_colors + 4));
  Panel_draw(*(long **)((char *)this + 0x10),'\x01','\x01','\x01','\0',0);
  IncSet_drawBar(*(long *)((char *)this + 0x18),*(int *)((char *)CRT_colors + 8));
}

/* FUN_00128370 @ 0x128370 */

void FUN_00128370(void *param_1)

{
  long lVar1;
  void *va1;

  lVar1 = *(long *)((long)param_1 + 8);
  if (((*(char *)(lVar1 + 0x4d) != '\0') && (*(char *)(**(long **)(lVar1 + 8) + 0x58) != '\0')) ||
     (va1 = *(void **)(lVar1 + 0x118), va1 == (void *)0x0)) {
    va1 = *(void **)(lVar1 + 0x80);
  }
  InfoScreen_drawTitled
            (param_1,((char *)(long)&s_Snapshot_of_files_open_in_proces_0014c498 /* "Snapshot of files open in process %d - %s" */),*(int *)((long)param_1 + 0x28),va1)
  ;
  return;
}


/* FUN_001283c0 @ 0x1283c0 */

void FUN_001283c0(void *param_1)

{
  long lVar1;
  void *va1;

  lVar1 = *(long *)((long)param_1 + 8);
  if (((*(char *)(lVar1 + 0x4d) != '\0') && (*(char *)(**(long **)(lVar1 + 8) + 0x58) != '\0')) ||
     (va1 = *(void **)(lVar1 + 0x118), va1 == (void *)0x0)) {
    va1 = *(void **)(lVar1 + 0x80);
  }
  InfoScreen_drawTitled
            (param_1,((char *)(long)&s_Snapshot_of_file_locks_of_proces_0014c4c8 /* "Snapshot of file locks of process %d - %s" */),*(int *)((long)param_1 + 0x28),va1)
  ;
  return;
}


/* InfoScreen_run @ 0x12ac40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InfoScreen_run(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                   long param_r9)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long *a0;
  code *a2;
  long lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  ulong a3;
  uint uVar7;
  long extraout_RDX;
  ulong a2_00;
  long a2_01;
  ulong extraout_RDX_00;
  undefined *a2_03;
  long a2_04;
  undefined *extraout_RDX_01;
  undefined *extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  ulong uVar8;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong a2_02;

  a0 = (long *)param_1[2];
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *param_1;
  a2 = *(code **)(lVar5 + 0x20);
  lVar6 = 0;
  if (a2 != (code *)0x0) {
    (*a2)((long)param_1,param_rsi,(long)a2,param_rcx,param_r8,param_r9);
    lVar5 = *param_1;
    lVar6 = extraout_RDX;
  }
  (**(code **)(lVar5 + 0x28))((long)param_1,param_rsi,lVar6,param_rcx,param_r8,param_r9);
LAB_0012ac90:
  do {
    while( true ) {
      lVar5 = 0;
      a3 = 1;
      Panel_draw(a0,'\0','\x01','\x01','\0',param_r9);
      uVar8 = (ulong)*(uint *)(CRT_colors + 8);
      IncSet_drawBar(param_1[3],*(uint *)(CRT_colors + 8));
      uVar2 = Panel_getCh((long)a0);
      if (uVar2 != 0xffffffff) break;
      if (*(code **)(*param_1 + 0x30) == (code *)0x0) {
        param_r9 = param_1[3];
        if (*(long *)(param_r9 + 0x130) != 0) {
LAB_0012ad68:
          IncSet_handleKey(param_r9,uVar2,a0,IncSet_getListItemValue,(long *)param_1[4],param_r9);
        }
      }
      else {
        (**(code **)(*param_1 + 0x30))((long)param_1,uVar8,a2_00,a3,lVar5,param_r9);
      }
    }
    if (uVar2 == 0x199) {
      iVar3 = getmouse((*(undefined1 (*)[4])(__fp - 0x58)));
      a2_02 = extraout_RDX_00;
      if (iVar3 == 0) {
        if (((*(uint *)(__fp - 0x48)) & 1) != 0) {
          uVar4 = *(uint *)((long)a0 + 0xc);
          a3 = (ulong)uVar4;
          uVar7 = _LINES - 1;
          a2_02 = (ulong)uVar7;
          if (((int)(*(uint *)(__fp - 0x50)) < (int)uVar4) || ((int)uVar7 <= (int)(*(uint *)(__fp - 0x50)))) {
            if ((*(uint *)(__fp - 0x50)) != uVar7) goto LAB_0012adce;
            param_r9 = param_1[3];
            uVar8 = (ulong)(*(uint *)(__fp - 0x54));
            if (*(long *)(param_r9 + 0x130) == 0) {
              uVar2 = FunctionBar_synthesizeEvent(*(int **)(param_r9 + 0x140),(*(uint *)(__fp - 0x54)));
              a2_02 = extraout_RDX_04;
              goto LAB_0012ace5;
            }
            uVar2 = FunctionBar_synthesizeEvent
                              (*(int **)(*(long *)(param_r9 + 0x130) + 0x88),(*(uint *)(__fp - 0x54)));
          }
          else {
            uVar4 = (((*(uint *)(__fp - 0x50)) - uVar4) + (int)a0[8]) - 1;
            uVar2 = *(int *)(a0[4] + 0x18) - 1;
            a3 = (ulong)uVar2;
            if (*(int *)(a0[4] + 0x18) <= (int)uVar4) {
              uVar4 = uVar2;
            }
            a2_02 = 0;
            if ((int)uVar4 < 0) {
              uVar4 = 0;
            }
            *(uint *)(a0 + 5) = uVar4;
            if (*(code **)(*a0 + 0x20) == (code *)0x0) {
              param_r9 = param_1[3];
              lVar6 = *(long *)(param_r9 + 0x130);
            }
            else {
              (**(code **)(*a0 + 0x20))((long)a0,0xffffffff,0,a3,lVar5,param_r9);
              param_r9 = param_1[3];
              lVar6 = *(long *)(param_r9 + 0x130);
              a2_02 = extraout_RDX_03;
            }
            if (lVar6 == 0) {
              uVar2 = 0;
              goto LAB_0012addd;
            }
            uVar2 = 0;
          }
          goto LAB_0012ad68;
        }
        param_r9 = param_1[3];
        a2_02 = *(ulong *)(param_r9 + 0x130);
        uVar8 = a2_02;
        if (((*(uint *)(__fp - 0x48)) & 0x10000) == 0) {
          if (((*(uint *)(__fp - 0x48)) & 0x200000) == 0) goto LAB_0012adce;
          uVar2 = 0x127;
        }
        else {
          uVar2 = 0x126;
        }
      }
      else {
LAB_0012adce:
        param_r9 = param_1[3];
        uVar8 = *(ulong *)(param_r9 + 0x130);
      }
      if (uVar8 != 0) goto LAB_0012ad68;
      goto LAB_0012addd;
    }
    param_r9 = param_1[3];
    a2_02 = a2_00;
    if (*(long *)(param_r9 + 0x130) != 0) goto LAB_0012ad68;
LAB_0012ace5:
    if (uVar2 == 0x10b) {
LAB_0012aea3:
      *(long *)(param_r9 + 0x130) = param_r9;
      lVar5 = *(long *)(param_r9 + 0x88);
LAB_0012aef5:
      a0[10] = lVar5;
      lVar5 = CRT_colors;
      *(undefined1 *)((long)a0 + 0x49) = 1;
      *(long **)(param_r9 + 0x138) = a0;
      IncSet_drawBar(param_r9,*(int *)(lVar5 + 8));
      goto LAB_0012ac90;
    }
    if ((int)uVar2 < 0x10c) {
      if (uVar2 != 0x1b) {
        if ((int)uVar2 < 0x1c) break;
        if (uVar2 == 0x5c) goto LAB_0012aee0;
        if (uVar2 != 0x71) {
          if (uVar2 != 0x2f) goto LAB_0012addd;
          goto LAB_0012aea3;
        }
      }
      goto LAB_0012aeb8;
    }
    if (uVar2 == 0x10d) {
      wclear(_stdscr);
      lVar6 = *param_1;
      lVar1 = *(long *)(lVar6 + 0x20);
      a2_03 = extraout_RDX_02;
    }
    else {
      if ((int)uVar2 < 0x10e) {
LAB_0012aee0:
        *(long *)(param_r9 + 0x130) = param_r9 + 0x98;
        lVar5 = *(long *)(param_r9 + 0x120);
        goto LAB_0012aef5;
      }
      if (uVar2 == 0x112) {
LAB_0012aeb8:
        if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      if (uVar2 != 0x19a) goto LAB_0012addd;
      a2_03 = &COLS;
      *(undefined1 *)(a0 + 9) = 1;
      lVar6 = *param_1;
      lVar1 = *(long *)(lVar6 + 0x20);
      a0[2] = CONCAT44(_LINES + -2,_COLS);
    }
    if (lVar1 != 0) {
      Vector_prune((long *)param_1[4],uVar8,(long)a2_03,a3,lVar5,param_r9);
      (**(code **)(*param_1 + 0x20))((long)param_1,uVar8,a2_04,a3,lVar5,param_r9);
      lVar6 = *param_1;
      a2_03 = extraout_RDX_01;
    }
    (**(code **)(lVar6 + 0x28))((long)param_1,uVar8,(long)a2_03,a3,lVar5,param_r9);
  } while( true );
  if (uVar2 != 0xffffffff) {
    if (uVar2 == 0xc) {
      wclear(_stdscr);
      (**(code **)(*param_1 + 0x28))((long)param_1,uVar8,a2_01,a3,lVar5,param_r9);
    }
    else {
LAB_0012addd:
      if ((*(code **)(*param_1 + 0x38) == (code *)0x0) ||
         (lVar5 = (**(code **)(*param_1 + 0x38))((long)param_1,(ulong)uVar2,a2_02,a3,lVar5,param_r9)
         , (char)lVar5 == '\0')) {
        Panel_onKey((long)a0,uVar2);
      }
    }
  }
  goto LAB_0012ac90;
}


/* FUN_0012b050 @ 0x12b050 */

uint FUN_0012b050(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  char cVar1;
  long *a0;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  ushort **ppuVar12;
  long lVar13;
  uint uVar14;
  undefined4 uVar15;
  char *pcVar16;
  int *piVar17;
  undefined4 in_register_00000034;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;

  a0 = (long *)param_1[0x4dc];
  plVar2 = (long *)*a0;
  if (param_2 == 0x19a) {
    return 2;
  }
  if (param_2 == 0x199) {
    lVar13 = *plVar2;
    if (*(char *)(lVar13 + 0x6f) == '\0') {
      lVar11 = param_1[0x4dd];
      if (*(long *)(lVar11 + 0x130) == 0) {
        uVar10 = 0x198;
        iVar9 = 0x199;
LAB_0012b2e7:
        pcVar3 = *(code **)(param_1[0x4de] + (long)param_2 * 8);
        if (pcVar3 != (code *)0x0) {
          uVar10 = (*pcVar3)((long)a0,CONCAT44(in_register_00000034,param_2),uVar10,param_rcx,
                             param_r8,param_r9);
          goto LAB_0012b0d3;
        }
        if (((uint)uVar10 < 0xfe) &&
           (ppuVar12 = __ctype_b_loc(),
           (*(byte *)((long)*ppuVar12 + (long)param_2 * 2 + 1) & 8) != 0)) {
          iVar20 = iVar9 + -0x30 + (int)param_1[0x4e1];
          iVar9 = (int)((long *)param_1[4])[3];
          if (0 < iVar9) {
            lVar13 = 0;
            do {
              lVar11 = *(long *)(*(long *)param_1[4] + lVar13 * 8);
              if ((lVar11 != 0) && (iVar20 == *(int *)(lVar11 + 0x10))) {
                *(int *)(param_1 + 5) = (int)lVar13;
                if (*(code **)(*param_1 + 0x20) != (code *)0x0) {
                  (**(code **)(*param_1 + 0x20))
                            ((long)param_1,0xffffffff,lVar11,(long)iVar9,param_r8,param_r9);
                }
                break;
              }
              lVar13 = lVar13 + 1;
            } while (iVar9 != lVar13);
          }
          uVar21 = iVar20 * 10;
          *(uint *)(param_1 + 0x4e1) = uVar21;
          if (10000000 < uVar21) goto LAB_0012b4fc;
        }
        else {
LAB_0012b4fc:
          *(undefined4 *)(param_1 + 0x4e1) = 0;
        }
        uVar7 = 2;
        goto LAB_0012b182;
      }
    }
    else {
      lVar11 = param_1[0x4dd];
      *(undefined1 *)((long)a0 + 0x19) = 0;
      iVar9 = 0x199;
      if (*(long *)(lVar11 + 0x130) == 0) goto LAB_0012b530;
    }
LAB_0012b32f:
    cVar6 = IncSet_handleKey(lVar11,param_2,param_1,FUN_0011fae0,(long *)0x0,param_r9);
    if (cVar6 == '\0') {
      bVar5 = false;
      uVar7 = 1;
      uVar21 = 8;
      if (*(char *)(param_1[0x4dd] + 0x149) == '\0') goto LAB_0012b182;
    }
    else {
      lVar4 = param_1[0x4dd];
      lVar11 = 0;
      if (*(char *)(lVar4 + 0x148) != '\0') {
        lVar11 = lVar4 + 0x98;
      }
      cVar6 = *(char *)(lVar4 + 0x149);
      *(long *)(plVar2[0x15] + 0x28) = lVar11;
      if (cVar6 == '\0') {
        uVar22 = 0;
        uVar14 = 0;
        uVar18 = 1;
        uVar19 = 1;
        uVar21 = 0x21;
        cVar6 = *(char *)(*(long *)(lVar13 + 0x40) + 0x34);
        uVar7 = 0x21;
        goto LAB_0012b24d;
      }
      bVar5 = true;
      uVar21 = 0x29;
    }
    lVar11 = ((long *)param_1[0x4dc])[1];
    uVar15 = 0xffffffff;
    if ((0 < (int)(*(long **)(lVar11 + 0x20))[3]) &&
       (lVar4 = *(long *)(**(long **)(lVar11 + 0x20) + (long)*(int *)(lVar11 + 0x28) * 8),
       lVar4 != 0)) {
      uVar15 = *(undefined4 *)(lVar4 + 0x10);
    }
    *(undefined4 *)(*(long *)(*(long *)param_1[0x4dc] + 0xa8) + 0x34) = uVar15;
    *(undefined4 *)(lVar11 + 0x26d8) = 10;
    if (bVar5) {
      uVar22 = 0;
      uVar14 = 0;
      uVar18 = 1;
      uVar19 = 1;
      uVar21 = 0x29;
      lVar11 = *(long *)(plVar2[0x15] + 0x28);
      cVar6 = *(char *)(*(long *)(lVar13 + 0x40) + 0x34);
      uVar7 = 0x21;
      goto LAB_0012b24d;
    }
    uVar7 = (-(uint)((uVar21 & 1) == 0) & 0xfffffff8) + 9;
  }
  else {
    if (param_2 == -1) {
      return 2;
    }
    lVar13 = *plVar2;
    *(undefined1 *)((long)a0 + 0x19) = 0;
    lVar11 = *(long *)(lVar13 + 0x40);
    if (param_2 + 10000U < 0x3e9) {
      iVar9 = RowField_keyAt(lVar13,param_2 + 10000U + *(int *)((long)param_1 + 0x44) + 1);
      if (*(char *)(lVar11 + 0x34) == '\0') {
        if (iVar9 != *(int *)(lVar11 + 0x2c)) goto LAB_0012b1de;
        iVar9 = *(int *)(lVar11 + 0x24);
        piVar17 = (int *)(lVar11 + 0x24);
LAB_0012b3c2:
        uVar21 = 0x67;
        *piVar17 = ((iVar9 != 1) - 1) + (uint)(iVar9 != 1);
        cVar6 = *(char *)(*(long *)(lVar13 + 0x40) + 0x34);
      }
      else {
        if (*(char *)(lVar11 + 0x35) == '\0') {
          if (iVar9 == *(int *)(lVar11 + 0x30)) {
            iVar9 = *(int *)(lVar11 + 0x28);
            piVar17 = (int *)(lVar11 + 0x28);
            goto LAB_0012b3c2;
          }
LAB_0012b1de:
          lVar13 = *(long *)(lVar13 + 0x40);
        }
        else {
          lVar13 = *(long *)(lVar13 + 0x40);
          *(undefined1 *)(lVar11 + 0x34) = 0;
          *(undefined4 *)(lVar11 + 0x24) = 1;
        }
        cVar1 = Process_fields[(long)iVar9 * 0x20 + 0x1d];
        if ((*(char *)(lVar13 + 0x35) == '\0') && (*(char *)(lVar13 + 0x34) != '\0')) {
          *(int *)(lVar13 + 0x30) = iVar9;
          cVar6 = '\x01';
          uVar21 = 0x6f;
          *(uint *)(lVar13 + 0x28) = (-(uint)(cVar1 == '\0') & 2) - 1;
        }
        else {
          *(int *)(lVar13 + 0x2c) = iVar9;
          uVar21 = 0x6f;
          *(undefined1 *)(lVar13 + 0x34) = 0;
          cVar6 = '\0';
          *(uint *)(lVar13 + 0x24) = (-(uint)(cVar1 == '\0') & 2) - 1;
        }
      }
      uVar22 = 0;
      uVar14 = 4;
      uVar18 = 1;
      uVar19 = 0x41;
      lVar11 = *(long *)(plVar2[0x15] + 0x28);
      uVar7 = 0x61;
LAB_0012b24d:
      piVar17 = (int *)param_1[0xb];
      pcVar16 = ((char *)(long)&s_Tree_0014750f /* "Tree  " */);
      if (cVar6 != '\0') {
        pcVar16 = ((char *)(long)&s_List_00147508 /* "List  " */);
      }
      FunctionBar_setLabel(piVar17,0x10d,pcVar16);
      pcVar16 = ((char *)(long)&s_Filter_0014751d /* "Filter" */);
      if (lVar11 != 0) {
        pcVar16 = ((char *)(long)&s_FILTER_00147516 /* "FILTER" */);
      }
      FunctionBar_setLabel(piVar17,0x10c,pcVar16);
    }
    else {
      if (9999 < param_2 + 20000U) {
        lVar11 = param_1[0x4dd];
        if (*(long *)(lVar11 + 0x130) != 0) goto LAB_0012b32f;
        iVar9 = param_2;
        if (param_2 == 0x1b) {
          *(undefined1 *)((long)a0 + 0x19) = 1;
          return 1;
        }
LAB_0012b530:
        uVar10 = (ulong)(iVar9 - 1U);
        if (iVar9 - 1U < 0x1fe) goto LAB_0012b2e7;
        goto LAB_0012b4fc;
      }
      uVar10 = Action_setScreenTab(a0,param_2 + 20000U);
LAB_0012b0d3:
      uVar21 = (uint)uVar10;
      uVar7 = uVar21 & 0xe1;
      uVar19 = uVar21 & 0x41;
      uVar18 = uVar21 & 1;
      uVar14 = uVar21 & 4;
      uVar22 = uVar21 & 0x10;
      if ((uVar10 & 0x20) != 0) {
        lVar11 = *(long *)(plVar2[0x15] + 0x28);
        cVar6 = *(char *)(*(long *)(lVar13 + 0x40) + 0x34);
        goto LAB_0012b24d;
      }
    }
    uVar8 = 0x41;
    if (uVar7 != 0xe1) {
      uVar8 = 1;
    }
    if (uVar19 == 0x41) {
      uVar8 = uVar8 | 0x10;
    }
    uVar7 = uVar8;
    if (uVar18 != 0) {
      uVar7 = uVar8 | 0x28;
      if ((~uVar21 & 3) != 0) {
        uVar7 = uVar8 | 8;
      }
    }
    if (uVar14 != 0) {
      *(undefined1 *)(*plVar2 + 0x74) = 1;
    }
    if (uVar22 != 0) {
      return 4;
    }
  }
  if ((uVar21 & 8) != 0) {
    return uVar7;
  }
LAB_0012b182:
  *(undefined4 *)(plVar2[0x15] + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x4db) = 9;
  return uVar7;
}


/* InfoScreen_addLine @ 0x12b620 */

void InfoScreen_addLine(long param_1,char *param_2,long param_rdx,long param_rcx,long param_r8,
                       long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long *plVar1;
  undefined8 *puVar2;
  char *pcVar3;
  char *pcVar4;
  char **__ptr;
  long lVar5;
  char **ppcVar6;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar2 = malloc(0x18);
  if (puVar2 == (undefined8 *)0x0) {
LAB_0012b7e3:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *puVar2 = ListItem_class;
  pcVar3 = strdup(param_2);
  if (pcVar3 == (char *)0x0) goto LAB_0012b7e3;
  plVar1 = *(long **)(param_1 + 0x20);
  puVar2[1] = pcVar3;
  *(undefined4 *)(puVar2 + 2) = 0;
  *(undefined1 *)((long)puVar2 + 0x14) = 0;
  Vector_set(plVar1,(int)plVar1[3],(long)puVar2,param_rcx,param_r8,param_r9);
  if (*(char *)(*(long *)(param_1 + 0x18) + 0x148) == '\0') {
LAB_0012b739:
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      lVar5 = **(long **)(param_1 + 0x20);
      Panel_add(*(long *)(param_1 + 0x10),
                *(long *)(lVar5 + (long)((int)(*(long **)(param_1 + 0x20))[3] + -1) * 8),lVar5,
                param_rcx,param_r8,param_r9);
      return;
    }
  }
  else {
    pcVar3 = (char *)(*(long *)(param_1 + 0x18) + 0x98);
    pcVar4 = strchr(pcVar3,0x7c);
    if (pcVar4 == (char *)0x0) {
      pcVar3 = strcasestr(param_2,pcVar3);
      if (pcVar3 != (char *)0x0) goto LAB_0012b739;
    }
    else {
      __ptr = String_split(pcVar3,'|',&(*(long *)(__fp - 0x48)));
      if ((*(long *)(__fp - 0x48)) != 0) {
        lVar5 = 0;
LAB_0012b6fd:
        pcVar3 = strcasestr(param_2,__ptr[lVar5]);
        if (pcVar3 == (char *)0x0) goto LAB_0012b6f0;
        pcVar3 = *__ptr;
        ppcVar6 = __ptr;
        while (pcVar3 != (char *)0x0) {
          ppcVar6 = ppcVar6 + 1;
          free(pcVar3);
          pcVar3 = *ppcVar6;
        }
        free(__ptr);
        goto LAB_0012b739;
      }
      if (__ptr != (char **)0x0) {
LAB_0012b7b8:
        pcVar3 = *__ptr;
        ppcVar6 = __ptr;
        while (pcVar3 != (char *)0x0) {
          ppcVar6 = ppcVar6 + 1;
          free(pcVar3);
          pcVar3 = *ppcVar6;
        }
        free(__ptr);
      }
    }
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012b6f0:
  lVar5 = lVar5 + 1;
  if ((*(long *)(__fp - 0x48)) == lVar5) goto LAB_0012b7b8;
  goto LAB_0012b6fd;
}


/* FUN_0012b7f0 @ 0x12b7f0 */

void FUN_0012b7f0(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x1001d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x100198;
  byte bVar1;
  long *plVar2;
  code *pcVar3;
  void *pvVar4;
  long *a0;
  char **strp;
  undefined1 uVar5;
  int iVar6;
  __pid_t _Var7;
  int iVar8;
  uint uVar9;
  __pid_t _Var10;
  char *pcVar11;
  FILE *pFVar12;
  byte *__ptr;
  char *pcVar13;
  char *pcVar14;
  undefined *puVar15;
  int *piVar16;
  size_t p2;
  ulong uVar17;
  undefined *puVar18;
  byte bVar19;
  uint uVar20;
  ulong uVar21;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  long extraout_RDX_06;
  long extraout_RDX_07;
  long extraout_RDX_08;
  undefined *va0;
  long extraout_RDX_09;
  byte *__s2;
  long lVar22;
  __pid_t *p_Var23;
  __pid_t *p_Var24;
  undefined *puVar26;
  undefined *puVar27;
  char *va2;
  wint_t __wc;
  long lVar28;
  undefined8 *__ptr_00;
  undefined1 (*pauVar29) [16];
  undefined8 *puVar30;
  wint_t *pwVar31;
  long in_FS_OFFSET = (long)__fake_fs;
  __pid_t *p_Var25;

  p_Var25 = &(*(__pid_t *)(__fp - 0x148));
  p_Var24 = &(*(__pid_t *)(__fp - 0x148));
  p_Var23 = &(*(__pid_t *)(__fp - 0x148));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  plVar2 = *(long **)(param_1 + 0x10);
  (*(uint *)(__fp - 0x144)) = *(uint *)(plVar2 + 5);
  (*(long * *)(__fp - 0x140)) = plVar2;
  (*(long *)(__fp - 0x138)) = param_1;
  Vector_prune((long *)plVar2[4],param_rsi,(ulong)(*(uint *)(__fp - 0x144)),param_rcx,param_r8,param_r9);
  *(undefined1 *)(plVar2 + 9) = 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar2[5] = 0;
  iVar8 = *(int *)(param_1 + 0x28);
  pcVar11 = calloc(1,0x70);
  if (pcVar11 == (char *)0x0) {
LAB_0012bdd3:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  pcVar11[0x58] = '\b';
  pcVar11[0x59] = '\0';
  pcVar11[0x5a] = '\0';
  pcVar11[0x5b] = '\0';
  pcVar11[0x60] = '\b';
  pcVar11[0x61] = '\0';
  pcVar11[0x62] = '\0';
  pcVar11[99] = '\0';
  pcVar11[0x50] = '\b';
  pcVar11[0x51] = '\0';
  pcVar11[0x52] = '\0';
  pcVar11[0x53] = '\0';
  (*(int (*)[2])(__fp - 0x100))[0] = 0;
  (*(int (*)[2])(__fp - 0x100))[1] = 0;
  iVar6 = pipe((*(int (*)[2])(__fp - 0x100)));
  lVar22 = extraout_RDX;
  va2 = (char *)param_r8;
  if (iVar6 != -1) {
    _Var7 = fork();
    if (_Var7 == -1) {
      close((*(int (*)[2])(__fp - 0x100))[1]);
      close((*(int (*)[2])(__fp - 0x100))[0]);
      lVar22 = extraout_RDX_01;
      va2 = (char *)param_r8;
    }
    else {
      if (_Var7 == 0) {
        close((*(int (*)[2])(__fp - 0x100))[0]);
        dup2((*(int (*)[2])(__fp - 0x100))[1],1);
        close((*(int (*)[2])(__fp - 0x100))[1]);
        iVar6 = open(((char *)(long)&s__dev_null_001488eb /* "/dev/null" */),1);
        if (-1 < iVar6) {
          dup2(iVar6,2);
          close(iVar6);
          (*(undefined16 *)((char *)&(*(undefined1 (*)[32])(__fp - 0xd8)) + 0)) = (undefined16)0x0;
          (*(undefined16 *)((char *)&(*(undefined1 (*)[32])(__fp - 0xd8)) + 16)) = (undefined16)0x0;
          xSnprintf((*(undefined1 (*)[32])(__fp - 0xd8)),0x20,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),iVar8);
          execlp(((char *)(long)(__sec_rodata + 0xfb0) /* "lsof" */),((char *)(long)(__sec_rodata + 0xfb0) /* "lsof" */),&DAT_001488fb,&DAT_001488f8,&DAT_001488f5,(*(undefined1 (*)[32])(__fp - 0xd8)),&DAT_001488fe,0);
                    /* WARNING: Subroutine does not return */
          exit(0x7f);
        }
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      close((*(int (*)[2])(__fp - 0x100))[1]);
      pFVar12 = fdopen((*(int (*)[2])(__fp - 0x100))[0],((char *)(long)&DAT_00147760 /* "r" */));
      lVar22 = extraout_RDX_00;
      va2 = (char *)param_r8;
      if (pFVar12 != (FILE *)0x0) {
        (*(char * *)(__fp - 0x118)) = (char *)((ulong)(*(char * *)(__fp - 0x118)) & 0xffffffffffffff00);
        (*(char * *)(__fp - 0x130)) = (char *)0x0;
        pcVar13 = pcVar11;
        (*(__pid_t *)(__fp - 0x148)) = _Var7;
        (*(FILE * *)(__fp - 0x110)) = pFVar12;
        while (__ptr = (byte *)String_readLine((*(FILE * *)(__fp - 0x110))), _Var7 = (*(__pid_t *)(__fp - 0x148)), __ptr != (byte *)0x0)
        {
          bVar1 = *__ptr;
          uVar20 = bVar1 - 0x44;
          param_rcx = (long)uVar20;
          bVar19 = (byte)uVar20;
          if (bVar19 < 0x31) {
            if ((1L << (bVar19 & 0x3f) & 0x1842020000001U) == 0) {
              if (bVar19 != 0x22) {
                if (bVar19 != 0x2b) goto LAB_0012b998;
                __s2 = __ptr + 1;
                iVar8 = __ptr[1] - 0x30;
                if (iVar8 == 0) {
                  iVar8 = __ptr[2] - 0x74;
                }
                pcVar14 = *(char **)(pcVar13 + 0x38);
                if (iVar8 == 0) {
                  __s2 = __ptr + 3;
                  if (pcVar14 == (char *)0x0) goto LAB_0012b953;
LAB_0012b944:
                  iVar8 = strcmp(pcVar14,(char *)__s2);
                  if (iVar8 != 0) goto LAB_0012b953;
                }
                else {
                  if (pcVar14 != (char *)0x0) goto LAB_0012b944;
LAB_0012b953:
                  free(pcVar14);
                  pcVar14 = strdup((char *)__s2);
                  if (pcVar14 == (char *)0x0) goto LAB_0012bdd3;
                  *(char **)(pcVar13 + 0x38) = pcVar14;
                }
                puVar15 = (undefined *)strlen(pcVar14);
                param_rcx = (long)*(int *)(pcVar11 + 0x60);
                if ((ulong)param_rcx < puVar15) {
                  param_rcx = 0x7fff;
                  if ((undefined *)0x7fff < puVar15) {
                    puVar15 = (undefined *)0x7fff;
                  }
                  *(int *)(pcVar11 + 0x60) = (int)puVar15;
                }
                goto LAB_0012b998;
              }
              pcVar13 = calloc(1,0x48);
              if (pcVar13 == (char *)0x0) goto LAB_0012bdd3;
              if ((*(char * *)(__fp - 0x130)) == (char *)0x0) {
                *(char **)(pcVar11 + 0x68) = pcVar13;
              }
              else {
                *(char **)((*(char * *)(__fp - 0x130)) + 0x40) = pcVar13;
              }
              lVar22 = 0;
              (*(char * *)(__fp - 0x130)) = pcVar13;
            }
            else {
              switch(uVar20 & 0xff) {
              case 0:
                lVar22 = 2;
                break;
              default:
                    /* WARNING: Subroutine does not return */
                abort();
              case 0x1d:
                lVar22 = 1;
                break;
              case 0x22:
                lVar22 = 0;
                break;
              case 0x25:
                lVar22 = 3;
                break;
              case 0x2a:
                lVar22 = 4;
                break;
              case 0x2b:
                lVar22 = 7;
                break;
              case 0x2f:
                lVar22 = 5;
                break;
              case 0x30:
                lVar22 = 6;
              }
            }
            pcVar14 = *(char **)(pcVar13 + lVar22 * 8);
            (*(char ** *)(__fp - 0x120)) = (char **)(__ptr + 1);
            if ((pcVar14 == (char *)0x0) ||
               ((*(char * *)(__fp - 0x128)) = pcVar14, iVar8 = strcmp(pcVar14,(char *)(*(char ** *)(__fp - 0x120))), pcVar14 = (*(char * *)(__fp - 0x128)),
               iVar8 != 0)) {
              free(pcVar14);
              pcVar14 = strdup((char *)(*(char ** *)(__fp - 0x120)));
              if (pcVar14 == (char *)0x0) goto LAB_0012bdd3;
              *(char **)(pcVar13 + lVar22 * 8) = pcVar14;
            }
            puVar15 = (undefined *)strlen(pcVar14);
            param_rcx = (long)*(int *)(pcVar11 + lVar22 * 4 + 0x44);
            if ((ulong)param_rcx < puVar15) {
              param_rcx = 0x7fff;
              if ((undefined *)0x7fff < puVar15) {
                puVar15 = (undefined *)0x7fff;
              }
              *(int *)(pcVar11 + (lVar22 + 0x10) * 4 + 4) = (int)puVar15;
            }
            uVar5 = (char)(*(char * *)(__fp - 0x118));
            if (bVar1 == 0x73) {
              uVar5 = 1;
            }
            (*(char * *)(__fp - 0x118)) = (char *)CONCAT71((*(ulong *)((char *)&(*(char * *)(__fp - 0x118)) + 1)),uVar5);
          }
LAB_0012b998:
          free(__ptr);
        }
        fclose((*(FILE * *)(__fp - 0x110)));
        (*(char ** *)(__fp - 0x120)) = &(*(char * *)(__fp - 0x108));
        do {
          _Var10 = waitpid(_Var7,(int *)&(*(char * *)(__fp - 0x108)),0);
          if (_Var10 != -1) {
            lVar22 = extraout_RDX_05;
            if (((ulong)(*(char * *)(__fp - 0x108)) & 0x7f) == 0) {
              uVar20 = (uint)(*(char * *)(__fp - 0x108)) >> 8 & 0xff;
              *(uint *)(pcVar11 + 0x40) = uVar20;
              if (((char)(*(char * *)(__fp - 0x118)) != '\0') || (lVar28 = *(long *)(pcVar11 + 0x68), lVar28 == 0))
              goto LAB_0012bdf5;
            }
            else {
              pcVar11[0x40] = '\x01';
              pcVar11[0x41] = '\0';
              pcVar11[0x42] = '\0';
              pcVar11[0x43] = '\0';
              if ((char)(*(char * *)(__fp - 0x118)) != '\0') break;
              lVar28 = *(long *)(pcVar11 + 0x68);
              uVar20 = 1;
              if (lVar28 == 0) break;
            }
            (*(FILE * *)(__fp - 0x110)) = (FILE *)CONCAT44((*(uint *)((char *)&(*(FILE * *)(__fp - 0x110)) + 4)),uVar20);
            goto LAB_0012bd5d;
          }
          piVar16 = __errno_location();
          lVar22 = extraout_RDX_04;
        } while (*piVar16 == 4);
      }
    }
  }
LAB_0012bc28:
  pcVar13 = ((char *)(long)&s_Failed_listing_open_files__00148901 /* "Failed listing open files." */);
  InfoScreen_addLine((*(long *)(__fp - 0x138)),((char *)(long)&s_Failed_listing_open_files__00148901 /* "Failed listing open files." */),lVar22,param_rcx,(long)va2,param_r9);
LAB_0012bc3b:
  *(char *)((long)p_Var23 + -8) = 'C';
  *(char *)((long)p_Var23 + -7) = -0x44;
  *(char *)((long)p_Var23 + -6) = '\x12';
  *(char *)((long)p_Var23 + -5) = '\0';
  *(char *)((long)p_Var23 + -4) = '\0';
  *(char *)((long)p_Var23 + -3) = '\0';
  *(char *)((long)p_Var23 + -2) = '\0';
  *(char *)((long)p_Var23 + -1) = '\0';
  free(pcVar11);
  plVar2 = *(long **)((*(long *)(__fp - 0x138)) + 0x20);
  *(char *)((long)p_Var23 + -8) = 'S';
  *(char *)((long)p_Var23 + -7) = -0x44;
  *(char *)((long)p_Var23 + -6) = '\x12';
  *(char *)((long)p_Var23 + -5) = '\0';
  *(char *)((long)p_Var23 + -4) = '\0';
  *(char *)((long)p_Var23 + -3) = '\0';
  *(char *)((long)p_Var23 + -2) = '\0';
  *(char *)((long)p_Var23 + -1) = '\0';
  Vector_insertionSort(plVar2,(long)pcVar13,extraout_RDX_02,param_rcx,(long)va2,param_r9);
  a0 = (*(long * *)(__fp - 0x140));
  plVar2 = (long *)(*(long * *)(__fp - 0x140))[4];
  *(char *)((long)p_Var23 + -8) = 'c';
  *(char *)((long)p_Var23 + -7) = -0x44;
  *(char *)((long)p_Var23 + -6) = '\x12';
  *(char *)((long)p_Var23 + -5) = '\0';
  *(char *)((long)p_Var23 + -4) = '\0';
  *(char *)((long)p_Var23 + -3) = '\0';
  *(char *)((long)p_Var23 + -2) = '\0';
  *(char *)((long)p_Var23 + -1) = '\0';
  Vector_insertionSort(plVar2,(long)pcVar13,extraout_RDX_03,param_rcx,(long)va2,param_r9);
  uVar17 = (ulong)(*(uint *)(__fp - 0x144));
  uVar20 = *(int *)(a0[4] + 0x18) - 1;
  if ((int)(*(uint *)(__fp - 0x144)) < *(int *)(a0[4] + 0x18)) {
    uVar20 = (*(uint *)(__fp - 0x144));
  }
  uVar9 = 0;
  if (-1 < (int)uVar20) {
    uVar9 = uVar20;
  }
  *(uint *)(a0 + 5) = uVar9;
  pcVar3 = *(code **)(*a0 + 0x20);
  if (pcVar3 != (code *)0x0) {
    *(char *)((long)p_Var23 + -8) = -0x68;
    *(char *)((long)p_Var23 + -7) = -0x44;
    *(char *)((long)p_Var23 + -6) = '\x12';
    *(char *)((long)p_Var23 + -5) = '\0';
    *(char *)((long)p_Var23 + -4) = '\0';
    *(char *)((long)p_Var23 + -3) = '\0';
    *(char *)((long)p_Var23 + -2) = '\0';
    *(char *)((long)p_Var23 + -1) = '\0';
    (*pcVar3)((long)a0,0xffffffff,(ulong)uVar20,uVar17,(long)va2,param_r9);
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012bd5d:
  do {
    pcVar13 = *(char **)(lVar28 + 0x20);
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar8 = stat(pcVar13,(struct stat *)(*(undefined1 (*)[32])(__fp - 0xd8)));
    lVar22 = extraout_RDX_06;
    if (iVar8 == 0) {
      param_rcx = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0xa8)) + 0));
      xSnprintf((*(char (*)[32])(__fp - 0xf8)),0x15,((char *)(long)(__sec_rodata + 0x275f) /* "%lu" */),(*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0xa8)) + 0)));
      pcVar13 = *(char **)(lVar28 + 0x28);
      if ((pcVar13 == (char *)0x0) ||
         ((*(char * *)(__fp - 0x118)) = pcVar13, iVar8 = strcmp(pcVar13,(*(char (*)[32])(__fp - 0xf8))), lVar22 = extraout_RDX_07,
         pcVar13 = (*(char * *)(__fp - 0x118)), iVar8 != 0)) {
        free(pcVar13);
        pcVar13 = strdup((*(char (*)[32])(__fp - 0xf8)));
        if (pcVar13 == (char *)0x0) goto LAB_0012bdd3;
        *(char **)(lVar28 + 0x28) = pcVar13;
        lVar22 = extraout_RDX_08;
      }
    }
    lVar28 = *(long *)(lVar28 + 0x40);
  } while (lVar28 != 0);
  uVar20 = (uint)(*(FILE * *)(__fp - 0x110));
LAB_0012bdf5:
  if (uVar20 == 0x7f) {
    pcVar13 = ((char *)(long)&s_Could_not_execute__lsof___Please_0014c518 /* "Could not execute \'lsof\'. Please make sure it is available in your $PATH." */);
    InfoScreen_addLine((*(long *)(__fp - 0x138)),
                       ((char *)(long)&s_Could_not_execute__lsof___Please_0014c518 /* "Could not execute \'lsof\'. Please make sure it is available in your $PATH." */)
                       ,lVar22,param_rcx,(long)va2,param_r9);
    p_Var23 = &(*(__pid_t *)(__fp - 0x148));
    goto LAB_0012bc3b;
  }
  if (uVar20 != 1) {
    (*(undefined16 *)((char *)&(*(undefined1 (*)[32])(__fp - 0xd8)) + 0)) = (undefined16)0x0;
    (*(undefined16 *)((char *)&(*(undefined1 (*)[32])(__fp - 0xd8)) + 16)) = (undefined16)0x0;
    param_r9 = (long)&DAT_0014891c;
    va2 = ((char *)(long)&s__5_5s___7_7s___4_4s__6_6s___s____0014c568 /* "%5.5s %-7.7s %-4.4s %6.6s %*s %*s %*s  %s" */);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0xb8)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0xa8)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x98)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x88)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x78)), (undefined16)0x0);
    ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x68)), (undefined16)0x0);
    __snprintf_chk((*(undefined1 (*)[32])(__fp - 0xd8)),0x80,2,0x80,((char *)(long)&s__5_5s___7_7s___4_4s__6_6s___s____0014c568 /* "%5.5s %-7.7s %-4.4s %6.6s %*s %*s %*s  %s" */),&DAT_0014891c,
                   ((char *)(long)(__sec_rodata + 0x528) /* "TYPE" */),&DAT_0014893c,((char *)(long)&s_DEVICE_00148935 /* "DEVICE" */),*(int *)(pcVar11 + 0x58),&DAT_00148930,
                   *(int *)(pcVar11 + 0x60),((char *)(long)&s_OFFSET_00148929 /* "OFFSET" */),*(int *)(pcVar11 + 0x50),&DAT_00148924,
                   &DAT_0014891f);
    uVar20 = *(uint *)(CRT_colors + 0x1c);
    p2 = strlen((*(undefined1 (*)[32])(__fp - 0xd8)));
    uVar21 = (ulong)((int)p2 + 1);
    uVar17 = uVar21 * 4 + 0xf;
    p_Var23 = &(*(__pid_t *)(__fp - 0x148));
    while (p_Var25 != (__pid_t *)((long)&(*(__pid_t *)(__fp - 0x148)) - (uVar17 & 0xfffffffffffff000))) {
      p_Var24 = (__pid_t *)((long)p_Var23 + -0x1000);
      *(undefined8 *)((long)p_Var23 + -8) = *(undefined8 *)((long)p_Var23 + -8);
      p_Var25 = (__pid_t *)((long)p_Var23 + -0x1000);
      p_Var23 = (__pid_t *)((long)p_Var23 + -0x1000);
    }
    uVar17 = (ulong)((uint)uVar17 & 0xff0);
    lVar22 = -uVar17;
    pwVar31 = (wint_t *)((long)p_Var24 + lVar22);
    if (uVar17 != 0) {
      *(undefined8 *)((long)p_Var24 + -8) = *(undefined8 *)((long)p_Var24 + -8);
    }
    param_rcx = uVar21 & 0x3fffffffffffffff;
    uVar17 = __mbstowcs_chk((int *)((long)p_Var24 + lVar22),(*(undefined1 (*)[32])(__fp - 0xd8)),p2,param_rcx);
    iVar8 = (int)uVar17;
    pcVar13 = (char *)(uVar17 & 0xffffffff);
    p_Var23 = &(*(__pid_t *)(__fp - 0x148));
    if (0 < iVar8) {
      FUN_00130130((int *)((*(long * *)(__fp - 0x140)) + 0xc),iVar8);
      (*(char * *)(__fp - 0x118)) = pcVar11;
      (*(char * *)(__fp - 0x128)) = (char *)&(*(__pid_t *)(__fp - 0x148));
      (*(FILE * *)(__fp - 0x110)) = (FILE *)((long)p_Var24 + (ulong)(iVar8 - 1) * 4 + lVar22 + 4);
      pauVar29 = (undefined1 (*) [16])(*(long * *)(__fp - 0x140))[0xd];
      do {
        __wc = *pwVar31;
        iVar8 = iswprint(__wc);
        *(undefined16 *)(*pauVar29) = (undefined16)0x0;
        if (iVar8 == 0) {
          __wc = 0xfffd;
        }
        *(uint *)*pauVar29 = uVar20 & 0xffffff;
        pwVar31 = pwVar31 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar29 + 0xc)) = (undefined16)0x0;
        *(wint_t *)(*pauVar29 + 4) = __wc;
        p_Var23 = (__pid_t *)(*(char * *)(__fp - 0x128));
        pauVar29 = (undefined1 (*) [16])(pauVar29[1] + 0xc);
        pcVar11 = (*(char * *)(__fp - 0x118));
      } while ((*(FILE * *)(__fp - 0x110)) != (FILE *)pwVar31);
    }
    __ptr_00 = *(undefined8 **)(pcVar11 + 0x68);
    *(undefined1 *)((*(long * *)(__fp - 0x140)) + 9) = 1;
    if (__ptr_00 != (undefined8 *)0x0) {
      uVar20 = *(uint *)(pcVar11 + 0x50);
      (*(char * *)(__fp - 0x128)) = pcVar11;
      (*(char * *)(__fp - 0x118)) = (char *)CONCAT44((*(uint *)((char *)&(*(char * *)(__fp - 0x118)) + 4)),*(undefined4 *)(pcVar11 + 0x60));
      (*(FILE * *)(__fp - 0x110)) = (FILE *)CONCAT44((*(uint *)((char *)&(*(FILE * *)(__fp - 0x110)) + 4)),*(undefined4 *)(pcVar11 + 0x58));
      do {
        (*(char * *)(__fp - 0x108)) = (char *)0x0;
        puVar15 = (undefined *)__ptr_00[4];
        puVar27 = (undefined *)__ptr_00[3];
        puVar26 = (undefined *)__ptr_00[7];
        puVar18 = (undefined *)__ptr_00[5];
        param_r9 = __ptr_00[2];
        if (puVar15 == (undefined *)0x0) {
          puVar15 = &DAT_00149c0c;
        }
        va2 = (char *)__ptr_00[1];
        param_rcx = __ptr_00[6];
        if (puVar27 == (undefined *)0x0) {
          puVar27 = &DAT_00149c0c;
        }
        va0 = (undefined *)*__ptr_00;
        if (puVar26 == (undefined *)0x0) {
          puVar26 = &DAT_00149c0c;
        }
        if (puVar18 == (undefined *)0x0) {
          puVar18 = &DAT_00149c0c;
        }
        if ((undefined *)param_r9 == (undefined *)0x0) {
          param_r9 = (long)&DAT_00149c0c;
        }
        if (va2 == (char *)0x0) {
          va2 = ((char *)(long)&DAT_00149c0c /* "" */);
        }
        if ((undefined *)param_rcx == (undefined *)0x0) {
          param_rcx = (long)&DAT_00149c0c;
        }
        if (va0 == (undefined *)0x0) {
          va0 = &DAT_00149c0c;
        }
        *(undefined **)((long)p_Var23 + -0x10) = puVar15;
        *(undefined **)((long)p_Var23 + -0x18) = puVar27;
        strp = (*(char ** *)(__fp - 0x120));
        *(ulong *)((long)p_Var23 + -0x20) = (ulong)uVar20;
        *(undefined **)((long)p_Var23 + -0x28) = puVar26;
        *(ulong *)((long)p_Var23 + -0x30) = (ulong)(*(char * *)(__fp - 0x118)) & 0xffffffff;
        *(undefined **)((long)p_Var23 + -0x38) = puVar18;
        *(ulong *)((long)p_Var23 + -0x40) = (ulong)(*(FILE * *)(__fp - 0x110)) & 0xffffffff;
        *(char *)((long)p_Var23 + -0x48) = -0x38;
        *(char *)((long)p_Var23 + -0x47) = -0x40;
        *(char *)((long)p_Var23 + -0x46) = '\x12';
        *(char *)((long)p_Var23 + -0x45) = '\0';
        *(char *)((long)p_Var23 + -0x44) = '\0';
        *(char *)((long)p_Var23 + -0x43) = '\0';
        *(char *)((long)p_Var23 + -0x42) = '\0';
        *(char *)((long)p_Var23 + -0x41) = '\0';
        xAsprintf(strp,((char *)(long)&s__5_5s___7_7s___4_4s__6_6s___s____0014c568 /* "%5.5s %-7.7s %-4.4s %6.6s %*s %*s %*s  %s" */),va0,(void *)param_rcx,va2,
                  (void *)param_r9,*(int *)((long)p_Var23 + -0x40),*(void **)((long)p_Var23 + -0x38)
                  ,*(int *)((long)p_Var23 + -0x30),*(void **)((long)p_Var23 + -0x28),
                  *(int *)((long)p_Var23 + -0x20),*(void **)((long)p_Var23 + -0x18),
                  *(void **)((long)p_Var23 + -0x10));
        pcVar13 = (*(char * *)(__fp - 0x108));
        lVar22 = (*(long *)(__fp - 0x138));
        *(char *)((long)p_Var23 + -8) = -0x21;
        *(char *)((long)p_Var23 + -7) = -0x40;
        *(char *)((long)p_Var23 + -6) = '\x12';
        *(char *)((long)p_Var23 + -5) = '\0';
        *(char *)((long)p_Var23 + -4) = '\0';
        *(char *)((long)p_Var23 + -3) = '\0';
        *(char *)((long)p_Var23 + -2) = '\0';
        *(char *)((long)p_Var23 + -1) = '\0';
        InfoScreen_addLine(lVar22,pcVar13,extraout_RDX_09,param_rcx,(long)va2,param_r9);
        pcVar11 = (*(char * *)(__fp - 0x108));
        *(char *)((long)p_Var23 + -8) = -0x15;
        *(char *)((long)p_Var23 + -7) = -0x40;
        *(char *)((long)p_Var23 + -6) = '\x12';
        *(char *)((long)p_Var23 + -5) = '\0';
        *(char *)((long)p_Var23 + -4) = '\0';
        *(char *)((long)p_Var23 + -3) = '\0';
        *(char *)((long)p_Var23 + -2) = '\0';
        *(char *)((long)p_Var23 + -1) = '\0';
        free(pcVar11);
        puVar30 = __ptr_00;
        do {
          pvVar4 = (void *)*puVar30;
          puVar30 = puVar30 + 1;
          *(char *)((long)p_Var23 + -8) = -4;
          *(char *)((long)p_Var23 + -7) = -0x40;
          *(char *)((long)p_Var23 + -6) = '\x12';
          *(char *)((long)p_Var23 + -5) = '\0';
          *(char *)((long)p_Var23 + -4) = '\0';
          *(char *)((long)p_Var23 + -3) = '\0';
          *(char *)((long)p_Var23 + -2) = '\0';
          *(char *)((long)p_Var23 + -1) = '\0';
          free(pvVar4);
        } while (__ptr_00 + 8 != puVar30);
        puVar30 = (undefined8 *)__ptr_00[8];
        *(char *)((long)p_Var23 + -8) = '\r';
        *(char *)((long)p_Var23 + -7) = -0x3f;
        *(char *)((long)p_Var23 + -6) = '\x12';
        *(char *)((long)p_Var23 + -5) = '\0';
        *(char *)((long)p_Var23 + -4) = '\0';
        *(char *)((long)p_Var23 + -3) = '\0';
        *(char *)((long)p_Var23 + -2) = '\0';
        *(char *)((long)p_Var23 + -1) = '\0';
        free(__ptr_00);
        __ptr_00 = puVar30;
        pcVar11 = (*(char * *)(__fp - 0x128));
      } while (puVar30 != (undefined8 *)0x0);
    }
    pcVar14 = pcVar11;
    do {
      pvVar4 = *(void **)pcVar14;
      pcVar14 = pcVar14 + 8;
      *(char *)((long)p_Var23 + -8) = '=';
      *(char *)((long)p_Var23 + -7) = -0x3f;
      *(char *)((long)p_Var23 + -6) = '\x12';
      *(char *)((long)p_Var23 + -5) = '\0';
      *(char *)((long)p_Var23 + -4) = '\0';
      *(char *)((long)p_Var23 + -3) = '\0';
      *(char *)((long)p_Var23 + -2) = '\0';
      *(char *)((long)p_Var23 + -1) = '\0';
      free(pvVar4);
    } while (pcVar14 != pcVar11 + 0x40);
    goto LAB_0012bc3b;
  }
  goto LAB_0012bc28;
}


/* InfoScreen_appendLine @ 0x12c160 */

void InfoScreen_appendLine
               (long param_1,char *param_2,long param_rdx,long param_rcx,long param_r8,long param_r9
               )

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long lVar1;
  char *pcVar2;
  char **__ptr;
  char *pcVar3;
  long extraout_RDX;
  long lVar4;
  long extraout_RDX_00;
  char **ppcVar5;
  long lVar6;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)(**(long **)(param_1 + 0x20) +
                   (long)((int)(*(long **)(param_1 + 0x20))[3] + -1) * 8);
  ListItem_append(lVar1,param_2);
  if ((*(char *)(*(long *)(param_1 + 0x18) + 0x148) != '\0') &&
     (lVar6 = *(long *)(param_1 + 0x10),
     lVar1 != *(long *)(**(long **)(lVar6 + 0x20) +
                       (long)((int)(*(long **)(lVar6 + 0x20))[3] + -1) * 8))) {
    pcVar3 = (char *)(*(long *)(param_1 + 0x18) + 0x98);
    pcVar2 = strchr(pcVar3,0x7c);
    if (pcVar2 == (char *)0x0) {
      pcVar3 = strcasestr(param_2,pcVar3);
      lVar4 = extraout_RDX_00;
      if (pcVar3 != (char *)0x0) {
LAB_0012c26e:
        if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
          Panel_add(lVar6,lVar1,lVar4,param_rcx,param_r8,param_r9);
          return;
        }
        goto LAB_0012c305;
      }
    }
    else {
      __ptr = String_split(pcVar3,'|',&(*(long *)(__fp - 0x48)));
      if ((*(long *)(__fp - 0x48)) != 0) {
        lVar6 = 0;
LAB_0012c22a:
        pcVar3 = strcasestr(param_2,__ptr[lVar6]);
        if (pcVar3 == (char *)0x0) goto LAB_0012c220;
        pcVar3 = *__ptr;
        ppcVar5 = __ptr;
        while (pcVar3 != (char *)0x0) {
          ppcVar5 = ppcVar5 + 1;
          free(pcVar3);
          pcVar3 = *ppcVar5;
        }
        free(__ptr);
        lVar6 = *(long *)(param_1 + 0x10);
        lVar4 = extraout_RDX;
        goto LAB_0012c26e;
      }
      if (__ptr != (char **)0x0) {
LAB_0012c2a0:
        pcVar3 = *__ptr;
        ppcVar5 = __ptr;
        while (pcVar3 != (char *)0x0) {
          ppcVar5 = ppcVar5 + 1;
          free(pcVar3);
          pcVar3 = *ppcVar5;
        }
        free(__ptr);
      }
    }
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0012c305:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012c220:
  lVar6 = lVar6 + 1;
  if ((*(long *)(__fp - 0x48)) == lVar6) goto LAB_0012c2a0;
  goto LAB_0012c22a;
}

