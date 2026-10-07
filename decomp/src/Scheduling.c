#include "htop.h"

/* Scheduling_rowSetPolicy @ 0x12dcd0 */

undefined8 Scheduling_rowSetPolicy(long param_1,uint *param_2)

{
  undefined1 __frame[0xa8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x68;
  uint __policy;
  int iVar1;
  undefined4 extraout_var;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(sched_param *)(__fp - 0x14)).__sched_priority = 0;
  __policy = *param_2;
  (*(long *)(__fp - 0x10)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((&DAT_0015656c)[(long)(int)__policy * 0x10] != '\0') {
    (*(sched_param *)(__fp - 0x14)).__sched_priority = param_2[1];
  }
  if (BYTE_0015c0d8 != 0) {
    __policy = __policy & 0x40000000;
  }
  iVar1 = sched_setscheduler(*(__pid_t *)(param_1 + 0x10),__policy,&(*(sched_param *)(__fp - 0x14)));
  if ((*(long *)(__fp - 0x10)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 != -1);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Scheduling_formatPolicy @ 0x12dd50 */

char * Scheduling_formatPolicy(uint param_1)

{
  switch(param_1 & 0xbfffffff) {
  case 0:
    return ((char *)(long)&s_OTHER_0014895d /* "OTHER" */);
  case 1:
    return ((char *)(long)&DAT_00148958 /* "FIFO" */);
  case 2:
    return ((char *)(long)&DAT_00148976 /* "RR" */);
  case 3:
    return ((char *)(long)&s_BATCH_00148970 /* "BATCH" */);
  default:
    return ((char *)(long)&DAT_00148963 /* "???" */);
  case 5:
    return ((char *)(long)&DAT_0014896b /* "IDLE" */);
  case 6:
    return ((char *)(long)&DAT_00148967 /* "EDF" */);
  }
}


/* Scheduling_readProcessPolicy @ 0x12dde0 */

void Scheduling_readProcessPolicy(long param_1)

{
  int iVar1;

  iVar1 = sched_getscheduler(*(__pid_t *)(param_1 + 0x10));
  *(int *)(param_1 + 0x10c) = iVar1;
  return;
}


/* Scheduling_togglePolicyPanelResetOnFork @ 0x1320d0 */

void Scheduling_togglePolicyPanelResetOnFork(long param_1)

{
  long lVar1;
  char *__s1;
  int iVar2;
  byte bVar3;
  char *pcVar4;

  pcVar4 = ((char *)(long)&s_Reset_on_fork__off_001473b8 /* "Reset on fork: off" */);
  bVar3 = BYTE_0015c0d8 ^ 1;
  if (BYTE_0015c0d8 != 1) {
    pcVar4 = ((char *)(long)&s_Reset_on_fork__on_001473a6 /* "Reset on fork: on" */);
  }
  lVar1 = *(long *)**(undefined8 **)(param_1 + 0x20);
  __s1 = *(char **)(lVar1 + 8);
  BYTE_0015c0d8 = bVar3;
  if ((__s1 != (char *)0x0) && (iVar2 = strcmp(__s1,pcVar4), iVar2 == 0)) {
    return;
  }
  free(__s1);
  pcVar4 = strdup(pcVar4);
  if (pcVar4 != (char *)0x0) {
    *(char **)(lVar1 + 8) = pcVar4;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Scheduling_newPolicyPanel @ 0x133160 */

/* WARNING: Removing unreachable block (ram,0x0013321f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x0013323c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long * Scheduling_newPolicyPanel(int param_1)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  uint uVar1;
  wchar_t __wc;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  wchar_t *__s;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  long *a0;
  size_t sVar8;
  undefined8 *puVar9;
  long lVar10;
  wchar_t *pwVar11;
  undefined **ppuVar12;
  undefined1 *puVar13;
  long a4;
  undefined1 *a5;
  char *pcVar14;
  undefined1 (*pauVar15) [16];
  long in_FS_OFFSET = (long)__fake_fs;

  puVar13 = (*(undefined1 (*)[8])(__fp - 0x78));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x48)) = 0;
  (*(char * *)(__fp - 0x58)) = ((char *)(long)&s_Select_00149166 /* "Select " */);
  (*(char * *)(__fp - 0x50)) = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(int *)(__fp - 0x64)) = param_1;
  puVar7 = FunctionBar_new(&(*(char * *)(__fp - 0x58)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
  a0 = malloc(0x26e0);
  if (a0 != (long *)0x0) {
    a4 = 0;
    a5 = ListItem_class;
    lVar10 = 0;
    *a0 = (long)Panel_class;
    Panel_init((long)a0,0,0,0,0,ListItem_class,1,puVar7);
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined1 * *)(__fp - 0x70)) = (*(undefined1 (*)[8])(__fp - 0x78));
    pwVar11 = (*(wchar_t (*)[8])(__fp - 0xa8));
    (*(undefined1 * *)(__fp - 0x70)) = (*(undefined1 (*)[8])(__fp - 0x78));
    sVar8 = mbstowcs((*(wchar_t (*)[8])(__fp - 0xa8)),((char *)(long)&s_New_policy__0014916e /* "New policy:" */),0xb);
    iVar5 = (int)sVar8;
    if (0 < iVar5) {
      FUN_00130130((int *)(a0 + 0xc),iVar5);
      (*(wchar_t * *)(__fp - 0x60)) = (*(wchar_t (*)[8])(__fp - 0xa8)) + (ulong)(iVar5 - 1) + 1;
      pauVar15 = (undefined1 (*) [16])a0[0xd];
      do {
        __wc = *pwVar11;
        iVar5 = iswprint(__wc);
        *(undefined16 *)(*pauVar15) = (undefined16)0x0;
        if (iVar5 == 0) {
          __wc = L'�';
        }
        *(uint *)*pauVar15 = uVar1 & 0xffffff;
        pwVar11 = pwVar11 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar15 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar15 + 4) = __wc;
        pauVar15 = (undefined1 (*) [16])(pauVar15[1] + 0xc);
      } while ((*(wchar_t * *)(__fp - 0x60)) != pwVar11);
    }
    puVar13 = (*(undefined1 * *)(__fp - 0x70));
    *(undefined1 *)(a0 + 9) = 1;
    pcVar14 = ((char *)(long)&s_Reset_on_fork__off_001473b8 /* "Reset on fork: off" */);
    if (BYTE_0015c0d8 != 0) {
      pcVar14 = ((char *)(long)&s_Reset_on_fork__on_001473a6 /* "Reset on fork: on" */);
    }
    puVar9 = malloc(0x18);
    if (puVar9 != (undefined8 *)0x0) {
      *puVar9 = ListItem_class;
      pcVar14 = strdup(pcVar14);
      if (pcVar14 != (char *)0x0) {
        plVar2 = (long *)a0[4];
        puVar9[1] = pcVar14;
        iVar5 = 0;
        *(undefined4 *)(puVar9 + 2) = 0xffffffff;
        *(undefined1 *)((long)puVar9 + 0x14) = 0;
        lVar4 = plVar2[3];
        ppuVar12 = &PTR_s_Other_00156560;
        Vector_set(plVar2,(int)lVar4,(long)puVar9,lVar10,a4,(long)a5);
        *(undefined1 *)(a0 + 9) = 1;
        do {
          pwVar11 = (wchar_t *)*ppuVar12;
          (*(wchar_t * *)(__fp - 0x60)) = pwVar11;
          if (pwVar11 != (wchar_t *)0x0) {
            iVar6 = *(int *)(ppuVar12 + 1);
            puVar9 = malloc(0x18);
            __s = (*(wchar_t * *)(__fp - 0x60));
            if (puVar9 == (undefined8 *)0x0) break;
            *puVar9 = ListItem_class;
            pcVar14 = strdup((char *)__s);
            if (pcVar14 == (char *)0x0) break;
            plVar2 = (long *)a0[4];
            puVar9[1] = pcVar14;
            *(int *)(puVar9 + 2) = iVar6;
            *(undefined1 *)((long)puVar9 + 0x14) = 0;
            lVar10 = plVar2[3];
            Vector_set(plVar2,(int)lVar10,(long)puVar9,(long)pwVar11,a4,(long)a5);
            *(undefined1 *)(a0 + 9) = 1;
            if (iVar6 == (*(int *)(__fp - 0x64))) {
              iVar6 = *(int *)(a0[4] + 0x18) + -1;
              if (iVar5 < *(int *)(a0[4] + 0x18)) {
                iVar6 = iVar5;
              }
              if (iVar6 < 0) {
                iVar6 = 0;
              }
              *(int *)(a0 + 5) = iVar6;
              pcVar3 = *(code **)(*a0 + 0x20);
              if (pcVar3 != (code *)0x0) {
                (*pcVar3)((long)a0,0xffffffff,0,(long)pwVar11,a4,(long)a5);
              }
            }
          }
          iVar5 = iVar5 + 1;
          ppuVar12 = ppuVar12 + 2;
          if (iVar5 == 6) {
            if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
            return a0;
          }
        } while( true );
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Scheduling_newPriorityPanel @ 0x133430 */

/* WARNING: Removing unreachable block (ram,0x0013354d) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0013356a */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long * Scheduling_newPriorityPanel(uint param_1,uint param_2)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  wint_t __wc;
  long *plVar1;
  code *pcVar2;
  long lVar3;
  uint va0;
  int iVar4;
  uint uVar5;
  long *a0;
  size_t sVar6;
  undefined8 *puVar7;
  char *pcVar8;
  ulong a3;
  undefined1 (*pauVar9) [16];
  undefined1 *puVar10;
  undefined1 (*pauVar11) [16];
  long a4;
  undefined1 *a5;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar10 = (*(undefined1 (*)[8])(__fp - 0x88));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((((param_1 < 6) && ((&PTR_s_Other_00156560)[(long)(int)param_1 * 2] != (undefined *)0x0)) &&
      ((&DAT_0015656c)[(long)(int)param_1 * 0x10] != '\0')) &&
     ((va0 = sched_get_priority_min(param_1), -1 < (int)va0 &&
      ((*(int *)(__fp - 0x5c)) = sched_get_priority_max(param_1), -1 < (*(int *)(__fp - 0x5c)))))) {
    (*(undefined8 *)(__fp - 0x48)) = 0;
    (*(char * *)(__fp - 0x58)) = ((char *)(long)&s_Select_00149166 /* "Select " */);
    (*(char * *)(__fp - 0x50)) = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
    (*(undefined1 (**)[16])(__fp - 0x68)) = (undefined1 (*) [16])FunctionBar_new(&(*(char * *)(__fp - 0x58)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
    a0 = malloc(0x26e0);
    puVar10 = (*(undefined1 (*)[8])(__fp - 0x88));
    if (a0 == (long *)0x0) {
LAB_00133704:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    a4 = 0;
    a5 = ListItem_class;
    *a0 = (long)Panel_class;
    Panel_init((long)a0,0,0,0,0,ListItem_class,1,(*(undefined1 (**)[16])(__fp - 0x68)));
    uVar5 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined1 * *)(__fp - 0x80)) = (*(undefined1 (*)[8])(__fp - 0x88));
    (*(undefined1 (**)[16])(__fp - 0x70)) = (undefined1 (*) [16])(*(wchar_t (*)[8])(__fp - 0xb8));
    (*(undefined1 * *)(__fp - 0x80)) = (*(undefined1 (*)[8])(__fp - 0x88));
    sVar6 = mbstowcs((*(wchar_t (*)[8])(__fp - 0xb8)),((char *)(long)(__sec_rodata + 0x2e25) /* "Priority:" */),9);
    if (0 < (int)sVar6) {
      (*(undefined1 (**)[16])(__fp - 0x68)) = (undefined1 (*) [16])sVar6;
      FUN_00130130((int *)(a0 + 0xc),(int)sVar6);
      pauVar9 = (undefined1 (*) [16])a0[0xd];
      (*(uint *)(__fp - 0x60)) = uVar5 & 0xffffff;
      (*(undefined1 (**)[16])(__fp - 0x78)) = (undefined1 (*) [16])(*(*(undefined1 (**)[16])(__fp - 0x70)) + (ulong)((int)(*(undefined1 (**)[16])(__fp - 0x68)) - 1) * 4 + 4);
      pauVar11 = (*(undefined1 (**)[16])(__fp - 0x70));
      do {
        __wc = *(wint_t *)*pauVar11;
        (*(undefined1 (**)[16])(__fp - 0x70)) = pauVar9;
        (*(undefined1 (**)[16])(__fp - 0x68)) = pauVar11;
        iVar4 = iswprint(__wc);
        if (iVar4 == 0) {
          __wc = 0xfffd;
        }
        *(undefined16 *)(*(*(undefined1 (**)[16])(__fp - 0x70))) = (undefined16)0x0;
        pauVar11 = (undefined1 (*) [16])(*(*(undefined1 (**)[16])(__fp - 0x68)) + 4);
        *(undefined16 *)(*(undefined1 (*) [16])(*(*(undefined1 (**)[16])(__fp - 0x70)) + 0xc)) = (undefined16)0x0;
        pauVar9 = (undefined1 (*) [16])((*(undefined1 (**)[16])(__fp - 0x70))[1] + 0xc);
        *(uint *)*(*(undefined1 (**)[16])(__fp - 0x70)) = (*(uint *)(__fp - 0x60));
        *(wint_t *)(*(*(undefined1 (**)[16])(__fp - 0x70)) + 4) = __wc;
      } while ((*(undefined1 (**)[16])(__fp - 0x78)) != pauVar11);
    }
    puVar10 = (*(undefined1 * *)(__fp - 0x80));
    *(undefined1 *)(a0 + 9) = 1;
    if ((int)va0 <= (*(int *)(__fp - 0x5c))) {
      do {
        a3 = (ulong)va0;
        xSnprintf((char *)&(*(char * *)(__fp - 0x58)),0x10,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),va0);
        puVar7 = malloc(0x18);
        if (puVar7 == (undefined8 *)0x0) goto LAB_00133704;
        *puVar7 = ListItem_class;
        pcVar8 = strdup((char *)&(*(char * *)(__fp - 0x58)));
        if (pcVar8 == (char *)0x0) goto LAB_00133704;
        plVar1 = (long *)a0[4];
        puVar7[1] = pcVar8;
        *(uint *)(puVar7 + 2) = va0;
        *(undefined1 *)((long)puVar7 + 0x14) = 0;
        lVar3 = plVar1[3];
        Vector_set(plVar1,(int)lVar3,(long)puVar7,a3,a4,(long)a5);
        *(undefined1 *)(a0 + 9) = 1;
        if (param_2 == va0) {
          uVar5 = *(int *)(a0[4] + 0x18) - 1;
          if ((int)param_2 < *(int *)(a0[4] + 0x18)) {
            uVar5 = param_2;
          }
          if ((int)uVar5 < 0) {
            uVar5 = 0;
          }
          *(uint *)(a0 + 5) = uVar5;
          pcVar2 = *(code **)(*a0 + 0x20);
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)a0,0xffffffff,0,a3,a4,(long)a5);
          }
        }
        va0 = va0 + 1;
      } while ((int)va0 <= (*(int *)(__fp - 0x5c)));
    }
  }
  else {
    a0 = (long *)0x0;
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return a0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

