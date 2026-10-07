#include "htop.h"

/* AvailableMetersPanel_new @ 0x11be10 */

/* WARNING: Removing unreachable block (ram,0x0011bf1b) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff50 : 0x0011bf38 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 *
AvailableMetersPanel_new
          (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
          )

{
  undefined1 __frame[0x188] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x148;
  wchar_t __wc;
  ulong *puVar1;
  long *plVar2;
  long lVar3;
  char **ppcVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  size_t sVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  char *pcVar11;
  long extraout_RDX;
  long extraout_RDX_00;
  char ***pppcVar12;
  uint va1;
  long lVar13;
  undefined1 *puVar14;
  uint uVar15;
  undefined1 (*pauVar16) [16];
  ulong uVar17;
  wchar_t *pwVar18;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong uVar19;

  pppcVar12 = &(*(char ** *)(__fp - 0xa8));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(long * *)(__fp - 0xa0)) = param_1;
  puVar6 = malloc(0x2708);
  if (puVar6 != (undefined8 *)0x0) {
    (*(char ** *)(__fp - 0xa8)) = &(*(char * *)(__fp - 0x78));
    *puVar6 = AvailableMetersPanel_class;
    (*(undefined8 *)(__fp - 0x68)) = 0;
    (*(char * *)(__fp - 0x78)) = ((char *)(long)&s_Add_0014744e /* "Add   " */);
    (*(char * *)(__fp - 0x70)) = ((char *)(long)&s_Done_00147455 /* "Done   " */);
    puVar7 = FunctionBar_new((*(char ** *)(__fp - 0xa8)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
    puVar14 = ListItem_class;
    lVar13 = 1;
    uVar19 = 1;
    Panel_init((long)puVar6,1,1,1,1,ListItem_class,1,puVar7);
    puVar6[0x4de] = param_2;
    puVar6[0x4df] = param_3;
    puVar6[0x4dd] = (*(long * *)(__fp - 0xa0));
    puVar6[0x4e0] = param_4;
    lVar3 = CRT_colors;
    puVar6[0x4dc] = param_5;
    (*(char * *)(__fp - 0x88)) = (char *)&(*(char ** *)(__fp - 0xa8));
    uVar15 = *(uint *)(lVar3 + 0x1c);
    pwVar18 = (*(wchar_t (*)[16])(__fp - 0xf8));
    (*(char * *)(__fp - 0x88)) = (char *)&(*(char ** *)(__fp - 0xa8));
    sVar8 = mbstowcs((*(wchar_t (*)[16])(__fp - 0xf8)),((char *)(long)&s_Available_meters_0014745d /* "Available meters" */),0x10);
    iVar5 = (int)sVar8;
    if (0 < iVar5) {
      FUN_00130130((int *)(puVar6 + 0xc),iVar5);
      (*(wchar_t * *)(__fp - 0x80)) = (*(wchar_t (*)[16])(__fp - 0xf8)) + (ulong)(iVar5 - 1) + 1;
      pauVar16 = (undefined1 (*) [16])puVar6[0xd];
      do {
        __wc = *pwVar18;
        iVar5 = iswprint(__wc);
        *(undefined16 *)(*pauVar16) = (undefined16)0x0;
        if (iVar5 == 0) {
          __wc = L'�';
        }
        pwVar18 = pwVar18 + 1;
        *(uint *)*pauVar16 = uVar15 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar16 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar16 + 4) = __wc;
        pauVar16 = (undefined1 (*) [16])(pauVar16[1] + 0xc);
      } while (pwVar18 != (*(wchar_t * *)(__fp - 0x80)));
    }
    pppcVar12 = (char ***)(*(char * *)(__fp - 0x88));
    uVar17 = 1;
    *(undefined1 *)(puVar6 + 9) = 1;
    puVar9 = ClockMeter_class;
    do {
      iVar5 = (int)uVar17;
      if (puVar9 == DynamicMeter_class) {
        uVar17 = 0;
        uVar15 = 1;
        puVar1 = *(ulong **)(*(*(long * *)(__fp - 0xa0)) + 0x18);
        (*(uint *)(__fp - 0x94)) = iVar5 << 0x10;
        if (*puVar1 != 0) {
          do {
            pcVar11 = *(char **)(puVar1[1] + uVar17 * 0x18 + 0x10);
            if (pcVar11 != (char *)0x0) {
              uVar19 = (ulong)((*(uint *)(__fp - 0x94)) | uVar15);
              (*(wchar_t * *)(__fp - 0x80)) = (wchar_t *)CONCAT44((*(uint *)((char *)&(*(wchar_t * *)(__fp - 0x80)) + 4)),(*(uint *)(__fp - 0x94)) | uVar15);
              (*(char * *)(__fp - 0x88)) = *(char **)(pcVar11 + 0x28);
              if ((*(char **)(pcVar11 + 0x28) == (char *)0x0) &&
                 ((*(char * *)(__fp - 0x88)) = *(char **)(pcVar11 + 0x20), *(char **)(pcVar11 + 0x20) == (char *)0x0))
              {
                (*(char * *)(__fp - 0x88)) = pcVar11;
              }
              *(char *)((long)pppcVar12 + -8) = -0x52;
              *(char *)((long)pppcVar12 + -7) = -0x40;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              puVar10 = malloc(0x18);
              pcVar11 = (*(char * *)(__fp - 0x88));
              if (puVar10 == (undefined8 *)0x0) goto LAB_0011c2ea;
              *puVar10 = ListItem_class;
              (*(undefined8 * *)(__fp - 0x90)) = puVar10;
              *(char *)((long)pppcVar12 + -8) = -0x2c;
              *(char *)((long)pppcVar12 + -7) = -0x40;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              pcVar11 = strdup(pcVar11);
              puVar10 = (*(undefined8 * *)(__fp - 0x90));
              if (pcVar11 == (char *)0x0) goto LAB_0011c2ea;
              plVar2 = (long *)puVar6[4];
              uVar15 = uVar15 + 1;
              (*(undefined8 * *)(__fp - 0x90))[1] = pcVar11;
              *(undefined1 *)((long)(*(undefined8 * *)(__fp - 0x90)) + 0x14) = 0;
              lVar3 = plVar2[3];
              *(undefined4 *)((*(undefined8 * *)(__fp - 0x90)) + 2) = (*(uint *)((char *)&(*(wchar_t * *)(__fp - 0x80)) + 0));
              *(char *)((long)pppcVar12 + -8) = '\x02';
              *(char *)((long)pppcVar12 + -7) = -0x3f;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              Vector_set(plVar2,(int)lVar3,(long)puVar10,uVar19,lVar13,(long)puVar14);
              *(undefined1 *)(puVar6 + 9) = 1;
            }
            uVar17 = uVar17 + 1;
          } while (uVar17 < *puVar1);
        }
      }
      else {
        pcVar11 = *(char **)(puVar9 + 0x88);
        if (*(char **)(puVar9 + 0x88) == (char *)0x0) {
          pcVar11 = *(char **)(puVar9 + 0x78);
        }
        *(char *)((long)pppcVar12 + -8) = '\0';
        *(char *)((long)pppcVar12 + -7) = -0x40;
        *(char *)((long)pppcVar12 + -6) = '\x11';
        *(char *)((long)pppcVar12 + -5) = '\0';
        *(char *)((long)pppcVar12 + -4) = '\0';
        *(char *)((long)pppcVar12 + -3) = '\0';
        *(char *)((long)pppcVar12 + -2) = '\0';
        *(char *)((long)pppcVar12 + -1) = '\0';
        puVar10 = malloc(0x18);
        if (puVar10 == (undefined8 *)0x0) goto LAB_0011c2ea;
        *puVar10 = ListItem_class;
        *(char *)((long)pppcVar12 + -8) = '\x1f';
        *(char *)((long)pppcVar12 + -7) = -0x40;
        *(char *)((long)pppcVar12 + -6) = '\x11';
        *(char *)((long)pppcVar12 + -5) = '\0';
        *(char *)((long)pppcVar12 + -4) = '\0';
        *(char *)((long)pppcVar12 + -3) = '\0';
        *(char *)((long)pppcVar12 + -2) = '\0';
        *(char *)((long)pppcVar12 + -1) = '\0';
        pcVar11 = strdup(pcVar11);
        if (pcVar11 == (char *)0x0) goto LAB_0011c2ea;
        plVar2 = (long *)puVar6[4];
        puVar10[1] = pcVar11;
        *(int *)(puVar10 + 2) = iVar5 << 0x10;
        *(undefined1 *)((long)puVar10 + 0x14) = 0;
        lVar3 = plVar2[3];
        *(char *)((long)pppcVar12 + -8) = 'D';
        *(char *)((long)pppcVar12 + -7) = -0x40;
        *(char *)((long)pppcVar12 + -6) = '\x11';
        *(char *)((long)pppcVar12 + -5) = '\0';
        *(char *)((long)pppcVar12 + -4) = '\0';
        *(char *)((long)pppcVar12 + -3) = '\0';
        *(char *)((long)pppcVar12 + -2) = '\0';
        *(char *)((long)pppcVar12 + -1) = '\0';
        Vector_set(plVar2,(int)lVar3,(long)puVar10,uVar19,lVar13,(long)puVar14);
        *(undefined1 *)(puVar6 + 9) = 1;
      }
      plVar2 = (*(long * *)(__fp - 0xa0));
      uVar17 = (ulong)(iVar5 + 1);
      puVar9 = *(undefined1 **)(Platform_meterTypes + uVar17 * 8);
    } while (puVar9 != (undefined1 *)0x0);
    if (*(uint *)((long)(*(long * *)(__fp - 0xa0)) + 0x7c) < 2) {
      *(char *)((long)pppcVar12 + -8) = -0x5b;
      *(char *)((long)pppcVar12 + -7) = -0x3e;
      *(char *)((long)pppcVar12 + -6) = '\x11';
      *(char *)((long)pppcVar12 + -5) = '\0';
      *(char *)((long)pppcVar12 + -4) = '\0';
      *(char *)((long)pppcVar12 + -3) = '\0';
      *(char *)((long)pppcVar12 + -2) = '\0';
      *(char *)((long)pppcVar12 + -1) = '\0';
      puVar10 = malloc(0x18);
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = ListItem_class;
        *(char *)((long)pppcVar12 + -8) = -0x3c;
        *(char *)((long)pppcVar12 + -7) = -0x3e;
        *(char *)((long)pppcVar12 + -6) = '\x11';
        *(char *)((long)pppcVar12 + -5) = '\0';
        *(char *)((long)pppcVar12 + -4) = '\0';
        *(char *)((long)pppcVar12 + -3) = '\0';
        *(char *)((long)pppcVar12 + -2) = '\0';
        *(char *)((long)pppcVar12 + -1) = '\0';
        pcVar11 = strdup(((char *)(long)(__sec_rodata + 0x826) /* "CPU" */));
        if (pcVar11 != (char *)0x0) {
          puVar10[1] = pcVar11;
          *(undefined4 *)(puVar10 + 2) = 1;
          *(undefined1 *)((long)puVar10 + 0x14) = 0;
          *(char *)((long)pppcVar12 + -8) = -0x18;
          *(char *)((long)pppcVar12 + -7) = -0x3e;
          *(char *)((long)pppcVar12 + -6) = '\x11';
          *(char *)((long)pppcVar12 + -5) = '\0';
          *(char *)((long)pppcVar12 + -4) = '\0';
          *(char *)((long)pppcVar12 + -3) = '\0';
          *(char *)((long)pppcVar12 + -2) = '\0';
          *(char *)((long)pppcVar12 + -1) = '\0';
          Panel_add((long)puVar6,(long)puVar10,extraout_RDX_00,uVar19,lVar13,(long)puVar14);
          goto LAB_0011c278;
        }
      }
    }
    else {
      *(char *)((long)pppcVar12 + -8) = 't';
      *(char *)((long)pppcVar12 + -7) = -0x3f;
      *(char *)((long)pppcVar12 + -6) = '\x11';
      *(char *)((long)pppcVar12 + -5) = '\0';
      *(char *)((long)pppcVar12 + -4) = '\0';
      *(char *)((long)pppcVar12 + -3) = '\0';
      *(char *)((long)pppcVar12 + -2) = '\0';
      *(char *)((long)pppcVar12 + -1) = '\0';
      puVar10 = malloc(0x18);
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = ListItem_class;
        *(char *)((long)pppcVar12 + -8) = -0x69;
        *(char *)((long)pppcVar12 + -7) = -0x3f;
        *(char *)((long)pppcVar12 + -6) = '\x11';
        *(char *)((long)pppcVar12 + -5) = '\0';
        *(char *)((long)pppcVar12 + -4) = '\0';
        *(char *)((long)pppcVar12 + -3) = '\0';
        *(char *)((long)pppcVar12 + -2) = '\0';
        *(char *)((long)pppcVar12 + -1) = '\0';
        pcVar11 = strdup(((char *)(long)&s_CPU_average_0014746e /* "CPU average" */));
        if (pcVar11 != (char *)0x0) {
          puVar10[1] = pcVar11;
          *(undefined4 *)(puVar10 + 2) = 0;
          *(undefined1 *)((long)puVar10 + 0x14) = 0;
          uVar15 = 1;
          *(char *)((long)pppcVar12 + -8) = -0x2d;
          *(char *)((long)pppcVar12 + -7) = -0x3f;
          *(char *)((long)pppcVar12 + -6) = '\x11';
          *(char *)((long)pppcVar12 + -5) = '\0';
          *(char *)((long)pppcVar12 + -4) = '\0';
          *(char *)((long)pppcVar12 + -3) = '\0';
          *(char *)((long)pppcVar12 + -2) = '\0';
          *(char *)((long)pppcVar12 + -1) = '\0';
          Panel_add((long)puVar6,(long)puVar10,extraout_RDX,uVar19,lVar13,(long)puVar14);
          if (*(int *)((long)plVar2 + 0x7c) != 0) {
            do {
              ppcVar4 = (*(char ** *)(__fp - 0xa8));
              va1 = uVar15 - (*(char *)(*(*(long * *)(__fp - 0xa0)) + 0x50) == '\0');
              uVar19 = (ulong)va1;
              *(char *)((long)pppcVar12 + -8) = '\x0e';
              *(char *)((long)pppcVar12 + -7) = -0x3e;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              xSnprintf((char *)ppcVar4,0x32,((char *)(long)&s__s__d_0014747a /* "%s %d" */),((char *)(long)(__sec_rodata + 0x826) /* "CPU" */),va1);
              *(char *)((long)pppcVar12 + -8) = '\x18';
              *(char *)((long)pppcVar12 + -7) = -0x3e;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              puVar10 = malloc(0x18);
              ppcVar4 = (*(char ** *)(__fp - 0xa8));
              if (puVar10 == (undefined8 *)0x0) goto LAB_0011c2ea;
              puVar9 = ListItem_class;
              *puVar10 = ListItem_class;
              *(char *)((long)pppcVar12 + -8) = ':';
              *(char *)((long)pppcVar12 + -7) = -0x3e;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              pcVar11 = strdup((char *)ppcVar4);
              if (pcVar11 == (char *)0x0) goto LAB_0011c2ea;
              plVar2 = (long *)puVar6[4];
              puVar10[1] = pcVar11;
              *(uint *)(puVar10 + 2) = uVar15;
              uVar15 = uVar15 + 1;
              *(undefined1 *)((long)puVar10 + 0x14) = 0;
              lVar3 = plVar2[3];
              *(char *)((long)pppcVar12 + -8) = 'c';
              *(char *)((long)pppcVar12 + -7) = -0x3e;
              *(char *)((long)pppcVar12 + -6) = '\x11';
              *(char *)((long)pppcVar12 + -5) = '\0';
              *(char *)((long)pppcVar12 + -4) = '\0';
              *(char *)((long)pppcVar12 + -3) = '\0';
              *(char *)((long)pppcVar12 + -2) = '\0';
              *(char *)((long)pppcVar12 + -1) = '\0';
              Vector_set(plVar2,(int)lVar3,(long)puVar10,(long)puVar9,uVar19,(long)puVar14);
              *(undefined1 *)(puVar6 + 9) = 1;
            } while (uVar15 <= *(uint *)((long)(*(long * *)(__fp - 0xa0)) + 0x7c));
          }
LAB_0011c278:
          if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
            return puVar6;
          }
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
      }
    }
  }
LAB_0011c2ea:
                    /* WARNING: Subroutine does not return */
  *(char *)((long)pppcVar12 + -8) = -0x11;
  *(char *)((long)pppcVar12 + -7) = -0x3e;
  *(char *)((long)pppcVar12 + -6) = '\x11';
  *(char *)((long)pppcVar12 + -5) = '\0';
  *(char *)((long)pppcVar12 + -4) = '\0';
  *(char *)((long)pppcVar12 + -3) = '\0';
  *(char *)((long)pppcVar12 + -2) = '\0';
  *(char *)((long)pppcVar12 + -1) = '\0';
  fail();
}

