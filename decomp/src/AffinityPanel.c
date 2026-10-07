#include "htop.h"

/* AffinityPanel_getAffinity @ 0x117bd0 */

undefined8 * AffinityPanel_getAffinity(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  undefined8 *puVar4;
  void *pvVar5;
  void *pvVar6;
  long *plVar7;
  long lVar8;

  puVar4 = calloc(1,0x18);
  if (puVar4 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar4 + 1) = 8;
    pvVar5 = calloc(8,4);
    if (pvVar5 != (void *)0x0) {
      plVar7 = *(long **)(param_1 + 0x26f0);
      *puVar4 = param_2;
      lVar8 = 0;
      puVar4[2] = pvVar5;
      if (0 < (int)plVar7[3]) {
        do {
          while (lVar3 = *(long *)(*plVar7 + lVar8 * 8), *(int *)(lVar3 + 0x18) == 0) {
            lVar8 = lVar8 + 1;
            if ((int)plVar7[3] <= (int)lVar8) {
              return puVar4;
            }
          }
          uVar1 = *(undefined4 *)(lVar3 + 0x28);
          uVar2 = *(uint *)((long)puVar4 + 0xc);
          pvVar5 = (void *)puVar4[2];
          pvVar6 = pvVar5;
          if (uVar2 == *(uint *)(puVar4 + 1)) {
            *(uint *)(puVar4 + 1) = uVar2 * 2;
            pvVar6 = realloc(pvVar5,(ulong)(uVar2 * 2) * 4);
            if (pvVar6 == (void *)0x0) {
              free(pvVar5);
              goto LAB_00117cdd;
            }
            puVar4[2] = pvVar6;
            plVar7 = *(long **)(param_1 + 0x26f0);
          }
          lVar8 = lVar8 + 1;
          *(undefined4 *)((long)pvVar6 + (ulong)uVar2 * 4) = uVar1;
          *(uint *)((long)puVar4 + 0xc) = uVar2 + 1;
        } while ((int)lVar8 < (int)plVar7[3]);
      }
      return puVar4;
    }
  }
LAB_00117cdd:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* AffinityPanel_new @ 0x11b410 */

/* WARNING: Removing unreachable block (ram,0x0011b4f3) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011b510 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long * AffinityPanel_new(long *param_1,long param_2,undefined4 *param_3)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  long *plVar1;
  long lVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  size_t sVar11;
  char *pcVar12;
  void *pvVar13;
  long *plVar14;
  undefined4 *extraout_RDX;
  undefined4 *extraout_RDX_00;
  undefined4 *extraout_RDX_01;
  undefined1 (*pauVar15) [16];
  undefined4 **ppuVar16;
  char *pcVar17;
  long lVar18;
  uint uVar19;
  wchar_t __wc;
  wchar_t *pwVar20;
  long in_FS_OFFSET = (long)__fake_fs;

  ppuVar16 = &(*(undefined4 * *)(__fp - 0x88));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined4 * *)(__fp - 0x88)) = param_3;
  (*(long *)(__fp - 0x80)) = param_2;
  plVar8 = malloc(0x2700);
  if (plVar8 != (long *)0x0) {
    *plVar8 = (long)AffinityPanel_class;
    puVar9 = FunctionBar_new(&PTR_s_Set_00156170,(long)&PTR_s_Enter_00156140,(long)&DAT_0014d240);
    plVar14 = (long *)0x1;
    Panel_init((long)plVar8,1,1,1,1,&DAT_00156120,0,puVar9);
    plVar8[0x4dc] = (long)param_1;
    *(undefined4 *)(plVar8 + 0x4df) = 0xe;
    puVar10 = Vector_new(&DAT_00156120,1,-1);
    *(undefined1 *)(plVar8 + 0x4dd) = 0;
    plVar8[0x4de] = (long)puVar10;
    (*(char * *)(__fp - 0x68)) = (char *)&(*(undefined4 * *)(__fp - 0x88));
    uVar7 = *(uint *)(CRT_colors + 0x1c);
    pwVar20 = (*(wchar_t (*)[8])(__fp - 0xb8));
    (*(char * *)(__fp - 0x68)) = (char *)&(*(undefined4 * *)(__fp - 0x88));
    sVar11 = mbstowcs((*(wchar_t (*)[8])(__fp - 0xb8)),((char *)(long)&s_Use_CPUs__00147423 /* "Use CPUs:" */),9);
    iVar5 = (int)sVar11;
    puVar9 = extraout_RDX;
    if (0 < iVar5) {
      FUN_00130130((int *)(plVar8 + 0xc),iVar5);
      (*(long * *)(__fp - 0x70)) = plVar8;
      (*(wchar_t * *)(__fp - 0x60)) = (*(wchar_t (*)[8])(__fp - 0xb8)) + (ulong)(iVar5 - 1) + 1;
      (*(long * *)(__fp - 0x78)) = param_1;
      pauVar15 = (undefined1 (*) [16])plVar8[0xd];
      do {
        __wc = *pwVar20;
        iVar5 = iswprint(__wc);
        *(undefined16 *)(*pauVar15) = (undefined16)0x0;
        if (iVar5 == 0) {
          __wc = L'�';
        }
        *(uint *)*pauVar15 = uVar7 & 0xffffff;
        pwVar20 = pwVar20 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar15 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar15 + 4) = __wc;
        puVar9 = extraout_RDX_00;
        plVar8 = (*(long * *)(__fp - 0x70));
        pauVar15 = (undefined1 (*) [16])(pauVar15[1] + 0xc);
        param_1 = (*(long * *)(__fp - 0x78));
      } while ((*(wchar_t * *)(__fp - 0x60)) != pwVar20);
    }
    ppuVar16 = (undefined4 **)(*(char * *)(__fp - 0x68));
    iVar5 = *(int *)((long)param_1 + 0x7c);
    *(undefined1 *)(plVar8 + 9) = 1;
    lVar18 = 0;
    pcVar17 = (*(char (*)[24])(__fp - 0x58));
    pcVar3 = (*(char * *)(__fp - 0x68));
    if (iVar5 != 0) {
      (*(long * *)(__fp - 0x78)) = (long *)((ulong)(*(long * *)(__fp - 0x78)) & 0xffffffff00000000);
      puVar4 = (undefined4 *)0x0;
      (*(char * *)(__fp - 0x68)) = pcVar17;
      do {
        puVar9 = puVar4;
        pcVar12 = (*(char * *)(__fp - 0x68));
        uVar7 = (uint)puVar9;
        uVar6 = uVar7 + 1;
        (*(wchar_t * *)(__fp - 0x60)) = (wchar_t *)CONCAT44((*(uint *)((char *)&(*(wchar_t * *)(__fp - 0x60)) + 4)),uVar7);
        plVar14 = (long *)param_1[0x1c];
        uVar19 = (uint)*(byte *)(plVar14 + (long)(ulong)uVar6 * 0x1b + 0x1a);
        if (*(byte *)(plVar14 + (long)(ulong)uVar6 * 0x1b + 0x1a) != 0) {
          if (*(char *)(*param_1 + 0x50) != '\0') {
            uVar7 = uVar6;
          }
          pcVar3[-8] = '\n';
          pcVar3[-7] = -0x49;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          xSnprintf(pcVar12,9,((char *)(long)&s_CPU__d_0014742d /* "CPU %d" */),uVar7);
          pcVar3[-8] = '\x12';
          pcVar3[-7] = -0x49;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          sVar11 = strlen(pcVar12);
          uVar7 = (int)sVar11 + 4;
          if (*(uint *)(plVar8 + 0x4df) < uVar7) {
            *(uint *)(plVar8 + 0x4df) = uVar7;
          }
          if (((uint)(*(long * *)(__fp - 0x78)) < *(uint *)((*(long *)(__fp - 0x80)) + 0xc)) &&
             (*(int *)(*(long *)((*(long *)(__fp - 0x80)) + 0x10) + ((ulong)(*(long * *)(__fp - 0x78)) & 0xffffffff) * 4) ==
              (int)(*(wchar_t * *)(__fp - 0x60)))) {
            (*(long * *)(__fp - 0x78)) = (long *)CONCAT44((*(uint *)((char *)&(*(long * *)(__fp - 0x78)) + 4)),(uint)(*(long * *)(__fp - 0x78)) + 1);
          }
          else {
            uVar19 = 0;
          }
          pcVar3[-8] = -0x1b;
          pcVar3[-7] = -0x4b;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          puVar10 = malloc(0x30);
          pcVar12 = (*(char * *)(__fp - 0x68));
          if (puVar10 == (undefined8 *)0x0) goto LAB_0011b78e;
          *puVar10 = &DAT_00156120;
          pcVar3[-8] = '\x05';
          pcVar3[-7] = -0x4a;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          pcVar12 = strdup(pcVar12);
          if (pcVar12 == (char *)0x0) goto LAB_0011b78e;
          puVar10[1] = pcVar12;
          puVar10[2] = 0;
          *(undefined4 *)((long)puVar10 + 0x1c) = 0;
          pcVar3[-8] = ',';
          pcVar3[-7] = -0x4a;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          plVar14 = malloc(0x28);
          if (plVar14 == (long *)0x0) goto LAB_0011b78e;
          *(undefined4 *)((long)plVar14 + 0x14) = 10;
          (*(long * *)(__fp - 0x70)) = plVar14;
          pcVar3[-8] = 'O';
          pcVar3[-7] = -0x4a;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          pvVar13 = calloc(10,8);
          plVar14 = (*(long * *)(__fp - 0x70));
          if (pvVar13 == (void *)0x0) goto LAB_0011b78e;
          plVar1 = (long *)plVar8[0x4de];
          *(uint *)(puVar10 + 3) = uVar19 * 2;
          *(*(long * *)(__fp - 0x70)) = (long)pvVar13;
          (*(long * *)(__fp - 0x70))[1] = (long)&DAT_00156120;
          *(undefined4 *)((*(long * *)(__fp - 0x70)) + 2) = 10;
          (*(long * *)(__fp - 0x70))[3] = -0x100000000;
          *(undefined1 *)((long)(*(long * *)(__fp - 0x70)) + 0x24) = 1;
          lVar2 = plVar1[3];
          *(undefined4 *)((*(long * *)(__fp - 0x70)) + 4) = 0;
          puVar10[4] = (*(long * *)(__fp - 0x70));
          *(int *)(puVar10 + 5) = (int)(*(wchar_t * *)(__fp - 0x60));
          pcVar3[-8] = -0x55;
          pcVar3[-7] = -0x4a;
          pcVar3[-6] = '\x11';
          pcVar3[-5] = '\0';
          pcVar3[-4] = '\0';
          pcVar3[-3] = '\0';
          pcVar3[-2] = '\0';
          pcVar3[-1] = '\0';
          Vector_set(plVar1,(int)lVar2,(long)puVar10,(long)plVar14,(long)pcVar17,lVar18);
          puVar9 = extraout_RDX_01;
        }
        puVar4 = (undefined4 *)(ulong)uVar6;
      } while (uVar6 < *(uint *)((long)param_1 + 0x7c));
    }
    if ((*(undefined4 * *)(__fp - 0x88)) != (undefined4 *)0x0) {
      *(*(undefined4 * *)(__fp - 0x88)) = (int)plVar8[0x4df];
      puVar9 = (*(undefined4 * *)(__fp - 0x88));
    }
    pcVar3[-8] = 'm';
    pcVar3[-7] = -0x49;
    pcVar3[-6] = '\x11';
    pcVar3[-5] = '\0';
    pcVar3[-4] = '\0';
    pcVar3[-3] = '\0';
    pcVar3[-2] = '\0';
    pcVar3[-1] = '\0';
    FUN_0011af60(plVar8,'\0',(long)puVar9,(long)plVar14,(long)pcVar17,lVar18);
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return plVar8;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
LAB_0011b78e:
                    /* WARNING: Subroutine does not return */
  *(char *)((long)ppuVar16 + -8) = -0x6d;
  *(char *)((long)ppuVar16 + -7) = -0x49;
  *(char *)((long)ppuVar16 + -6) = '\x11';
  *(char *)((long)ppuVar16 + -5) = '\0';
  *(char *)((long)ppuVar16 + -4) = '\0';
  *(char *)((long)ppuVar16 + -3) = '\0';
  *(char *)((long)ppuVar16 + -2) = '\0';
  *(char *)((long)ppuVar16 + -1) = '\0';
  fail();
}


/* FUN_0011b7a0 @ 0x11b7a0 */

undefined8
FUN_0011b7a0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char cVar1;
  long lVar2;
  long *plVar3;
  long *a0;
  long lVar4;
  long *__ptr;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long extraout_RDX;
  long extraout_RDX_00;
  long *plVar8;
  char cVar9;
  byte bVar10;
  uint uVar11;
  long in_FS_OFFSET = (long)__fake_fs;

  plVar8 = (long *)*param_1;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (((CHAR____0015c0d9 == '\0') && (*(long *)(*(long *)(*plVar8 + 0x40) + 8) == 0)) &&
     ((int)plVar8[0xf] != 1)) {
    plVar3 = *(long **)(param_1[1] + 0x20);
    if ((0 < (int)plVar3[3]) &&
       (lVar6 = *(long *)(*plVar3 + (long)*(int *)(param_1[1] + 0x28) * 8), lVar6 != 0)) {
      plVar3 = FUN_00140160(*(__pid_t *)(lVar6 + 0x10),(long)plVar8);
      if (plVar3 != (long *)0x0) {
        a0 = AffinityPanel_new(plVar8,(long)plVar3,&(*(int *)(__fp - 0x44)));
        free((void *)plVar3[2]);
        free(plVar3);
        lVar6 = 1;
        plVar3 = a0;
        lVar4 = Action_pickFromVector(param_1,(long)a0,(*(int *)(__fp - 0x44)),'\x01',param_r8,param_r9);
        lVar7 = extraout_RDX;
        if (lVar4 != 0) {
          __ptr = AffinityPanel_getAffinity((long)a0,plVar8);
          lVar7 = param_1[1];
          plVar3 = *(long **)(lVar7 + 0x20);
          if (0 < (int)plVar3[3]) {
            lVar4 = 0;
            uVar11 = 1;
            cVar9 = '\0';
            do {
              lVar2 = *(long *)(*plVar3 + lVar4 * 8);
              cVar1 = *(char *)(lVar2 + 0x1d);
              if (cVar1 != '\0') {
                plVar8 = __ptr;
                uVar5 = Affinity_rowSet(lVar2,(long)__ptr);
                uVar11 = uVar11 & (uint)uVar5;
                plVar3 = *(long **)(lVar7 + 0x20);
                cVar9 = cVar1;
              }
              bVar10 = (byte)uVar11;
              lVar4 = lVar4 + 1;
            } while ((int)lVar4 < (int)plVar3[3]);
            if ((cVar9 != '\x01') && (0 < (int)plVar3[3])) {
              lVar4 = *(long *)(*plVar3 + (long)*(int *)(lVar7 + 0x28) * 8);
              lVar6 = lVar7;
              if (lVar4 != 0) {
                plVar8 = __ptr;
                uVar5 = Affinity_rowSet(lVar4,(long)__ptr);
                bVar10 = bVar10 & (byte)uVar5;
                lVar6 = lVar7;
              }
            }
            if (bVar10 == 0) {
              beep();
            }
          }
          free((void *)__ptr[2]);
          free(__ptr);
          lVar7 = extraout_RDX_00;
          plVar3 = plVar8;
        }
        (**(code **)(*a0 + 0x10))((long)a0,(long)plVar3,lVar7,lVar6,param_r8,param_r9);
        uVar5 = 0x61;
        goto LAB_0011b7e5;
      }
    }
  }
  uVar5 = 0;
LAB_0011b7e5:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011b960 @ 0x11b960 */

void FUN_0011b960(undefined4 param_1,long param_2,long param_3,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x1c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x188;
  undefined8 *puVar1;
  char *pcVar2;
  void *va0;
  long extraout_RDX;
  void *va1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (*(long *)(param_2 + 0x40) != 0) {
LAB_0011b98c:
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  va1 = *(void **)(param_2 + 0x30);
  va0 = *(void **)(param_2 + 0x20);
  if (*(void **)(param_2 + 0x20) == (void *)0x0) {
    va0 = (void *)param_2;
  }
  if ((va1 == (void *)0x0) && (va1 = *(void **)(param_2 + 0x28), va1 == (void *)0x0)) {
    xSnprintf((*(char (*)[264])(__fp - 0x138)),0x100,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),va0);
  }
  else {
    xSnprintf((*(char (*)[264])(__fp - 0x138)),0x100,((char *)(long)&s__s____s_00147434 /* "%s - %s" */),va0,va1);
  }
  puVar1 = malloc(0x18);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = ListItem_class;
    pcVar2 = strdup((*(char (*)[264])(__fp - 0x138)));
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined4 *)(puVar1 + 2) = param_1;
      *(undefined1 *)((long)puVar1 + 0x14) = 0;
      Panel_add(param_3,(long)puVar1,extraout_RDX,(long)va0,(long)va1,param_r9);
      goto LAB_0011b98c;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0011ba60 @ 0x11ba60 */

void FUN_0011ba60(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x1d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x198;
  long *plVar1;
  undefined8 *puVar2;
  char *pcVar3;
  void *va0;
  int iVar4;
  void *va1;
  undefined8 *puVar5;
  long in_FS_OFFSET = (long)__fake_fs;

  iVar4 = 1;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar5 = (undefined8 *)(Process_fields + 0x20);
  do {
    if (iVar4 == 2) {
      puVar5 = puVar5 + 4;
      iVar4 = 3;
    }
    va1 = (void *)puVar5[2];
    if (va1 != (void *)0x0) {
      va0 = (void *)*puVar5;
      xSnprintf((*(char (*)[264])(__fp - 0x148)),0x100,((char *)(long)&s__s____s_00147434 /* "%s - %s" */),va0,va1);
      puVar2 = malloc(0x18);
      if (puVar2 == (undefined8 *)0x0) {
LAB_0011bb69:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      *puVar2 = ListItem_class;
      pcVar3 = strdup((*(char (*)[264])(__fp - 0x148)));
      if (pcVar3 == (char *)0x0) goto LAB_0011bb69;
      plVar1 = *(long **)(param_1 + 0x20);
      puVar2[1] = pcVar3;
      *(int *)(puVar2 + 2) = iVar4;
      *(undefined1 *)((long)puVar2 + 0x14) = 0;
      Vector_set(plVar1,(int)plVar1[3],(long)puVar2,(long)va0,(long)va1,param_r9);
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 4;
    if (iVar4 == 0x84) {
      if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}

