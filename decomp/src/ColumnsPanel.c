#include "htop.h"

/* ColumnsPanel_update @ 0x117cf0 */

void ColumnsPanel_update(long param_1)

{
  int iVar1;
  int iVar2;
  void *__ptr;
  long lVar3;
  long lVar4;
  void *pvVar5;
  long lVar6;
  long lVar7;
  size_t __size;

  lVar7 = *(long *)(param_1 + 0x26e0);
  iVar1 = *(int *)(*(long *)(param_1 + 0x20) + 0x18);
  __ptr = *(void **)(lVar7 + 0x18);
  **(undefined1 **)(param_1 + 0x26e8) = 1;
  __size = (long)(iVar1 + 1) * 4;
  pvVar5 = realloc(__ptr,__size);
  if (pvVar5 != (void *)0x0) {
    lVar3 = *(long *)(param_1 + 0x26e0);
    *(void **)(lVar7 + 0x18) = pvVar5;
    *(undefined4 *)(lVar3 + 0x20) = 0;
    if (iVar1 < 1) {
      lVar7 = *(long *)(lVar3 + 0x18);
    }
    else {
      lVar7 = *(long *)(lVar3 + 0x18);
      lVar6 = 0;
      lVar4 = **(long **)(param_1 + 0x20);
      do {
        iVar2 = *(int *)(*(long *)(lVar4 + lVar6 * 8) + 0x10);
        *(int *)(lVar7 + lVar6 * 4) = iVar2;
        if (iVar2 < 0x84) {
          *(uint *)(lVar3 + 0x20) =
               *(uint *)(lVar3 + 0x20) | *(uint *)(Process_fields + (long)iVar2 * 0x20 + 0x18);
        }
        lVar6 = lVar6 + 1;
      } while (iVar1 != lVar6);
    }
    *(undefined4 *)(lVar7 + -4 + __size) = 0;
    return;
  }
  free(__ptr);
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ColumnsPanel_fill @ 0x11b0c0 */

void ColumnsPanel_fill(long param_1,long param_2,ulong *param_3,long param_rcx,long param_r8,
                      long param_r9)

{
  uint uVar1;
  long *plVar2;
  undefined8 *puVar3;
  char *pcVar4;
  uint *puVar5;
  ulong uVar6;
  uint *puVar7;
  char *pcVar8;

  Vector_prune(*(long **)(param_1 + 0x20),param_2,(long)param_3,param_rcx,param_r8,param_r9);
  puVar7 = *(uint **)(param_2 + 0x18);
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  uVar1 = *puVar7;
  do {
    if (uVar1 == 0) {
      *(long *)(param_1 + 0x26e0) = param_2;
      return;
    }
    if (uVar1 < 0x84) {
      pcVar4 = *(char **)(Process_fields + (ulong)uVar1 * 0x20);
      if (*(char **)(Process_fields + (ulong)uVar1 * 0x20) == (char *)0x0) {
        pcVar4 = ((char *)(long)&DAT_00147411 /* "- " */);
      }
    }
    else {
      param_r8 = *param_3;
      param_r9 = param_3[1];
      uVar6 = (ulong)uVar1 % (ulong)param_r8;
      pcVar8 = *(char **)((uint *)(param_r9 + uVar6 * 6 * 4) + 4);
      pcVar4 = ((char *)(long)&DAT_00147411 /* "- " */);
      if (pcVar8 != (char *)0x0) {
        param_rcx = 0;
        puVar5 = (uint *)(param_r9 + uVar6 * 6 * 4);
        do {
          while( true ) {
            if (uVar1 == *puVar5) {
              pcVar4 = *(char **)(pcVar8 + 0x20);
              if (*(char **)(pcVar8 + 0x20) == (char *)0x0) {
                pcVar4 = pcVar8;
              }
              goto LAB_0011b13f;
            }
            if (*(ulong *)(puVar5 + 2) < (ulong)param_rcx) goto LAB_0011b228;
            uVar6 = uVar6 + 1;
            if (param_r8 != uVar6) break;
            uVar6 = 0;
            param_rcx = param_rcx + 1;
            pcVar8 = *(char **)(param_r9 + 0x10);
            puVar5 = (uint *)param_r9;
            if (pcVar8 == (char *)0x0) goto LAB_0011b228;
          }
          param_rcx = param_rcx + 1;
          puVar5 = (uint *)(param_r9 + uVar6 * 6 * 4);
          pcVar8 = *(char **)(puVar5 + 4);
        } while (pcVar8 != (char *)0x0);
LAB_0011b228:
        pcVar4 = ((char *)(long)&DAT_00147411 /* "- " */);
      }
    }
LAB_0011b13f:
    puVar3 = malloc(0x18);
    if (puVar3 == (undefined8 *)0x0) {
LAB_0011b26b:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *puVar3 = ListItem_class;
    pcVar4 = strdup(pcVar4);
    if (pcVar4 == (char *)0x0) goto LAB_0011b26b;
    plVar2 = *(long **)(param_1 + 0x20);
    *(uint *)(puVar3 + 2) = uVar1;
    puVar7 = puVar7 + 1;
    puVar3[1] = pcVar4;
    *(undefined1 *)((long)puVar3 + 0x14) = 0;
    Vector_set(plVar2,(int)plVar2[3],(long)puVar3,param_rcx,param_r8,param_r9);
    uVar1 = *puVar7;
    *(undefined1 *)(param_1 + 0x48) = 1;
  } while( true );
}


/* ColumnsPanel_new @ 0x11b270 */

/* WARNING: Removing unreachable block (ram,0x0011b32c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x0011b349 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * ColumnsPanel_new(long param_1,ulong *param_2,undefined8 param_3)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  uint uVar1;
  wchar_t __wc;
  ulong *puVar2;
  undefined1 *puVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  long lVar9;
  long lVar10;
  undefined1 *puVar11;
  undefined1 (*pauVar12) [16];
  wchar_t *pwVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(ulong * *)(__fp - 0x68)) = param_2;
  (*(long *)(__fp - 0x58)) = param_1;
  puVar6 = malloc(0x26f8);
  if (puVar6 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *puVar6 = ColumnsPanel_class;
  puVar7 = FunctionBar_new(&PTR_DAT_00155de0,0,0);
  puVar11 = ListItem_class;
  lVar10 = 1;
  lVar9 = 1;
  Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
  puVar6[0x4dd] = param_3;
  *(undefined1 *)(puVar6 + 0x4de) = 0;
  puVar6[0x4dc] = (*(long *)(__fp - 0x58));
  uVar1 = *(uint *)(CRT_colors + 0x1c);
  (*(undefined1 * *)(__fp - 0x60)) = (undefined1 *)&(*(ulong * *)(__fp - 0x68));
  pwVar13 = (*(wchar_t (*)[12])(__fp - 0xa8));
  (*(undefined1 * *)(__fp - 0x60)) = (undefined1 *)&(*(ulong * *)(__fp - 0x68));
  sVar8 = mbstowcs((*(wchar_t (*)[12])(__fp - 0xa8)),((char *)(long)&s_Active_Columns_00147414 /* "Active Columns" */),0xe);
  iVar5 = (int)sVar8;
  if (0 < iVar5) {
    FUN_00130130((int *)(puVar6 + 0xc),iVar5);
    (*(wchar_t * *)(__fp - 0x50)) = (*(wchar_t (*)[12])(__fp - 0xa8)) + (ulong)(iVar5 - 1) + 1;
    pauVar12 = (undefined1 (*) [16])puVar6[0xd];
    do {
      __wc = *pwVar13;
      iVar5 = iswprint(__wc);
      *(undefined16 *)(*pauVar12) = (undefined16)0x0;
      if (iVar5 == 0) {
        __wc = L'�';
      }
      *(uint *)*pauVar12 = uVar1 & 0xffffff;
      pwVar13 = pwVar13 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar12 + 0xc)) = (undefined16)0x0;
      *(wchar_t *)(*pauVar12 + 4) = __wc;
      pauVar12 = (undefined1 (*) [16])(pauVar12[1] + 0xc);
    } while ((*(wchar_t * *)(__fp - 0x50)) != pwVar13);
  }
  lVar4 = (*(long *)(__fp - 0x58));
  puVar3 = (*(undefined1 * *)(__fp - 0x60));
  puVar2 = (*(ulong * *)(__fp - 0x68));
  *(undefined1 *)(puVar6 + 9) = 1;
  ColumnsPanel_fill((long)puVar6,lVar4,puVar2,lVar9,lVar10,(long)puVar11);
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}

