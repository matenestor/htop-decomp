#include "htop.h"

/* IOPriorityPanel_getIOPriority @ 0x13af30 */

undefined4 IOPriorityPanel_getIOPriority(long param_1)

{
  long lVar1;
  undefined4 uVar2;

  uVar2 = 0;
  if ((0 < (int)(*(long **)(param_1 + 0x20))[3]) &&
     (lVar1 = *(long *)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8), uVar2 = 0
     , lVar1 != 0)) {
    uVar2 = *(undefined4 *)(lVar1 + 0x10);
  }
  return uVar2;
}


/* IOPriorityPanel_new @ 0x140f60 */

/* WARNING: Removing unreachable block (ram,0x0014102f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x0014104c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long * IOPriorityPanel_new(uint param_1)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  wchar_t __wc;
  long *plVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *a3;
  long *a0;
  size_t sVar5;
  undefined8 *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  long *va0;
  long extraout_RDX;
  long a2;
  long extraout_RDX_00;
  wchar_t *pwVar10;
  char ***pppcVar11;
  long lVar12;
  ulong a4;
  undefined1 *a5;
  char *va2;
  undefined1 (*pauVar13) [16];
  uint va1;
  char **buf;
  int *piVar14;
  long in_FS_OFFSET = (long)__fake_fs;

  pppcVar11 = &(*(char ** *)(__fp - 0x98));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x68)) = 0;
  (*(char * *)(__fp - 0x78)) = ((char *)(long)&s_Set_00147e48 /* "Set    " */);
  (*(char * *)(__fp - 0x70)) = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(uint *)(__fp - 0x84)) = param_1;
  a3 = FunctionBar_new(&(*(char * *)(__fp - 0x78)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
  a0 = malloc(0x26e0);
  if (a0 != (long *)0x0) {
    a5 = ListItem_class;
    lVar12 = 1;
    *a0 = (long)Panel_class;
    Panel_init((long)a0,1,1,1,1,ListItem_class,1,a3);
    (*(undefined8 * *)(__fp - 0x80)) = &(*(char ** *)(__fp - 0x98));
    uVar9 = *(uint *)(CRT_colors + 0x1c);
    pwVar10 = (*(wchar_t (*)[12])(__fp - 0xd8));
    (*(undefined8 * *)(__fp - 0x80)) = &(*(char ** *)(__fp - 0x98));
    sVar5 = mbstowcs((*(wchar_t (*)[12])(__fp - 0xd8)),((char *)(long)&s_IO_Priority__00149e22 /* "IO Priority:" */),0xc);
    iVar4 = (int)sVar5;
    buf = &(*(char * *)(__fp - 0x78));
    if (0 < iVar4) {
      FUN_00130130((int *)(a0 + 0xc),iVar4);
      (*(char ** *)(__fp - 0x98)) = &(*(char * *)(__fp - 0x78));
      uVar9 = uVar9 & 0xffffff;
      a3 = (undefined4 *)(ulong)uVar9;
      (*(long * *)(__fp - 0x90)) = a0;
      pauVar13 = (undefined1 (*) [16])a0[0xd];
      do {
        __wc = *pwVar10;
        iVar3 = iswprint(__wc);
        *(undefined16 *)(*pauVar13) = (undefined16)0x0;
        if (iVar3 == 0) {
          __wc = L'�';
        }
        pwVar10 = pwVar10 + 1;
        *(uint *)*pauVar13 = uVar9;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar13 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar13 + 4) = __wc;
        a0 = (*(long * *)(__fp - 0x90));
        pauVar13 = (undefined1 (*) [16])(pauVar13[1] + 0xc);
        buf = (*(char ** *)(__fp - 0x98));
      } while ((*(wchar_t (*)[12])(__fp - 0xd8)) + (ulong)(iVar4 - 1) + 1 != pwVar10);
    }
    pppcVar11 = (char ***)(*(undefined8 * *)(__fp - 0x80));
    *(undefined1 *)(a0 + 9) = 1;
    puVar6 = malloc(0x18);
    if (puVar6 != (undefined8 *)0x0) {
      *puVar6 = ListItem_class;
      pcVar7 = strdup(((char *)(long)&s_None__based_on_nice__00149e2f /* "None (based on nice)" */));
      if (pcVar7 != (char *)0x0) {
        puVar6[1] = pcVar7;
        *(undefined4 *)(puVar6 + 2) = 0;
        *(undefined1 *)((long)puVar6 + 0x14) = 0;
        Panel_add((long)a0,(long)puVar6,extraout_RDX,(long)a3,lVar12,(long)a5);
        if ((*(uint *)(__fp - 0x84)) == 0) {
          *(undefined4 *)(a0 + 5) = 0;
          pcVar2 = *(code **)(*a0 + 0x20);
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)a0,0xffffffff,a2,(long)a3,lVar12,(long)a5);
          }
        }
        piVar14 = &DAT_001581c0;
        pcVar7 = ((char *)(long)&s_Realtime_00149e19 /* "Realtime" */);
        do {
          a4 = 0;
          va2 = ((char *)(long)&s__High__00149e12 /* "(High)" */);
          (*(long * *)(__fp - 0x90)) = (long *)pcVar7;
          while( true ) {
            va0 = (*(long * *)(__fp - 0x90));
            va1 = (uint)a4;
            xSnprintf((char *)buf,0x32,((char *)(long)&s__s__d__s_00149e44 /* "%s %d %s" */),va0,va1,va2);
            iVar4 = *piVar14;
            puVar6 = malloc(0x18);
            uVar9 = iVar4 << 0xd | va1;
            if (puVar6 == (undefined8 *)0x0) goto LAB_00141360;
            *puVar6 = ListItem_class;
            (*(undefined8 * *)(__fp - 0x80)) = puVar6;
            pcVar7 = strdup((char *)buf);
            puVar6 = (*(undefined8 * *)(__fp - 0x80));
            if (pcVar7 == (char *)0x0) goto LAB_00141360;
            plVar1 = (long *)a0[4];
            (*(undefined8 * *)(__fp - 0x80))[1] = pcVar7;
            lVar12 = plVar1[3];
            *(uint *)((*(undefined8 * *)(__fp - 0x80)) + 2) = uVar9;
            *(undefined1 *)((long)(*(undefined8 * *)(__fp - 0x80)) + 0x14) = 0;
            Vector_set(plVar1,(int)lVar12,(long)puVar6,(long)va0,a4,(long)va2);
            *(undefined1 *)(a0 + 9) = 1;
            if ((*(uint *)(__fp - 0x84)) == uVar9) {
              iVar4 = *(int *)(a0[4] + 0x18) + -1;
              if (iVar4 < 0) {
                iVar4 = 0;
              }
              *(int *)(a0 + 5) = iVar4;
              pcVar2 = *(code **)(*a0 + 0x20);
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)((long)a0,0xffffffff,0,(long)va0,a4,(long)va2);
              }
            }
            if (va1 == 7) break;
            a4 = (ulong)(va1 + 1);
            va2 = ((char *)(long)&s__Low__00149e0c /* "(Low)" */);
            if (va1 + 1 != 7) {
              va2 = ((char *)(long)&DAT_00149c0c /* "" */);
            }
          }
          pcVar7 = *(char **)(piVar14 + 6);
          piVar14 = piVar14 + 4;
        } while ((long *)pcVar7 != (long *)0x0);
        puVar6 = malloc(0x18);
        if (puVar6 != (undefined8 *)0x0) {
          *puVar6 = ListItem_class;
          pcVar8 = strdup(((char *)(long)&DAT_0014825a /* "Idle" */));
          if (pcVar8 != (char *)0x0) {
            puVar6[1] = pcVar8;
            *(undefined4 *)(puVar6 + 2) = 0x6007;
            *(undefined1 *)((long)puVar6 + 0x14) = 0;
            Panel_add((long)a0,(long)puVar6,extraout_RDX_00,(long)pcVar7,a4,(long)va2);
            if ((*(uint *)(__fp - 0x84)) == 0x6007) {
              iVar4 = *(int *)(a0[4] + 0x18) + -1;
              if (iVar4 < 0) {
                iVar4 = 0;
              }
              *(int *)(a0 + 5) = iVar4;
              pcVar2 = *(code **)(*a0 + 0x20);
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)((long)a0,0xffffffff,0,(long)pcVar7,a4,(long)va2);
              }
            }
            if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
              return a0;
            }
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
        }
      }
    }
  }
LAB_00141360:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00141370 @ 0x141370 */

void FUN_00141370(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  DIR *__dirp;
  dirent *pdVar5;
  ulong uVar6;
  void *pvVar8;
  long lVar9;
  int *piVar10;
  long extraout_RDX;
  ulong uVar11;
  uint uVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong uVar7;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (*(long *)(param_1 + 0xe0) == 0) {
    pvVar8 = calloc(2,0xd8);
    if (pvVar8 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(void **)(param_1 + 0xe0) = pvVar8;
    *(undefined1 *)((long)pvVar8 + 0xd0) = 1;
    *(undefined1 *)((long)pvVar8 + 0x1a8) = 1;
    *(undefined8 *)(param_1 + 0x78) = 0x100000001;
  }
  __dirp = opendir(((char *)(long)&s__sys_devices_system_cpu_00149e4d /* "/sys/devices/system/cpu" */));
  if (__dirp != (DIR *)0x0) {
    (*(uint *)(__fp - 0x6c)) = *(uint *)(param_1 + 0x7c);
    (*(uint *)(__fp - 0x70)) = 0;
    uVar7 = 0;
LAB_001413d8:
    uVar3 = (uint)uVar7;
    pdVar5 = readdir(__dirp);
    if (pdVar5 != (dirent *)0x0) {
      while (((((pdVar5->d_type & 0xfb) == 0 && (pdVar5->d_name[0] == 'c')) &&
              (pdVar5->d_name[1] == 'p')) && (pdVar5->d_name[2] == 'u'))) {
        uVar6 = __isoc23_strtoul(pdVar5->d_name + 3,&(*(char * *)(__fp - 0x50)),10);
        if (((uVar6 == 0xffffffffffffffff) || (pdVar5->d_name + 3 == (*(char * *)(__fp - 0x50)))) ||
           (*(*(char * *)(__fp - 0x50)) != '\0')) break;
        iVar2 = dirfd(__dirp);
        iVar2 = openat(iVar2,pdVar5->d_name,0x230000);
        if (iVar2 < 0) break;
        uVar3 = (int)uVar7 + 1;
        uVar7 = (ulong)uVar3;
        uVar6 = uVar6 + 1;
        param_r8 = uVar7;
        if (uVar7 < uVar6) {
          param_r8 = uVar6;
        }
        uVar12 = (uint)param_r8;
        if ((*(uint *)(__fp - 0x6c)) < uVar12) {
          uVar11 = (ulong)((*(uint *)(__fp - 0x6c)) + 1);
          if ((*(uint *)(__fp - 0x6c)) == 0) {
            uVar11 = 0;
          }
          pvVar8 = xReallocArrayZero(*(void **)(param_1 + 0xe0),uVar11,(ulong)(uVar12 + 1),0xd8);
          *(void **)(param_1 + 0xe0) = pvVar8;
          *(undefined1 *)((long)pvVar8 + 0xd0) = 1;
          (*(uint *)(__fp - 0x6c)) = uVar12;
        }
        iVar4 = openat(iVar2,((char *)(long)&s_online_00149919 /* "online" */),0);
        if (iVar4 < 0) {
          piVar10 = __errno_location();
          lVar9 = (long)-*piVar10;
        }
        else {
          lVar9 = FUN_0013a450(iVar4,(*(char (*)[8])(__fp - 0x48)),8);
        }
        param_rcx = uVar6 * 0x1b;
        if ((lVar9 < 1) || (uVar1 = 0, (*(char (*)[8])(__fp - 0x48))[0] != '0')) {
          (*(uint *)(__fp - 0x70)) = (*(uint *)(__fp - 0x70)) + 1;
          uVar1 = 1;
        }
        *(undefined1 *)(*(long *)(param_1 + 0xe0) + uVar6 * 0xd8 + 0xd0) = uVar1;
        close(iVar2);
        pdVar5 = readdir(__dirp);
        if (pdVar5 == (dirent *)0x0) goto LAB_00141528;
      }
      goto LAB_001413d8;
    }
LAB_00141528:
    closedir(__dirp);
    if (uVar3 != 0) {
      if ((*(uint *)(param_1 + 0x7c) != 0) &&
         ((uVar3 = (*(uint *)(__fp - 0x70)), *(uint *)(param_1 + 0x78) < (*(uint *)(__fp - 0x70)) ||
          (uVar3 = (*(uint *)(__fp - 0x6c)), *(uint *)(param_1 + 0x7c) < (*(uint *)(__fp - 0x6c)))))) {
        LibSensors_reload((long)__dirp,(ulong)uVar3,extraout_RDX,param_rcx,param_r8,param_r9);
      }
      *(uint *)(param_1 + 0x78) = (*(uint *)(__fp - 0x70));
      *(uint *)(param_1 + 0x7c) = (*(uint *)(__fp - 0x6c));
    }
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_001415f0 @ 0x1415f0 */

void FUN_001415f0(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x1148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1108;
  uint uVar1;
  uint uVar2;
  FILE *__stream;
  char *pcVar3;
  ulong uVar4;
  ulong *puVar5;
  ulong uVar6;
  undefined8 *puVar7;
  long lVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  uint uVar16;
  ulong uVar17;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar18;

  bVar18 = 0;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00141370(param_1,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  __stream = fopen(((char *)(long)(__sec_rodata + 0x2e71) /* "/proc/stat" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_open__proc_stat_00149e65 /* "Cannot open /proc/stat" */));
  }
  uVar10 = 0;
  (*(uint *)(__fp - 0x10b4)) = 0;
  do {
    (*(ulong *)(__fp - 0x1070)) = 0;
    (*(ulong *)(__fp - 0x1078)) = 0;
    (*(ulong *)(__fp - 0x1080)) = 0;
    (*(ulong *)(__fp - 0x1088)) = 0;
    (*(long *)(__fp - 0x1090)) = 0;
    (*(long *)(__fp - 0x1098)) = 0;
    pcVar3 = fgets((char *)&(*(short *)(__fp - 0x1048)),0x1001,__stream);
    if (((pcVar3 == (char *)0x0) || ((*(short *)(__fp - 0x1048)) != 0x7063)) || ((*(char *)(__fp - 0x1046)) != 'u')) {
LAB_001416e7:
      uVar4 = *(ulong *)(*(long *)(param_1 + 0xe0) + 0x60);
      goto code_r0x00141a59;
    }
    if (uVar10 == 0) {
      __isoc23_sscanf((char *)&(*(short *)(__fp - 0x1048)),
                      ((char *)(long)&s_cpu__16llu__16llu__16llu__16llu___0014cbb0 /* "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu" */),
                      &(*(long *)(__fp - 0x1050)),&(*(long *)(__fp - 0x1058)),&(*(ulong *)(__fp - 0x1060)),&(*(ulong *)(__fp - 0x1068)),&(*(ulong *)(__fp - 0x1070)),&(*(ulong *)(__fp - 0x1078)),
                      &(*(ulong *)(__fp - 0x1080)),&(*(ulong *)(__fp - 0x1088)),&(*(long *)(__fp - 0x1090)),&(*(long *)(__fp - 0x1098)));
      uVar16 = *(uint *)(param_1 + 0x7c);
      lVar8 = 0;
      (*(uint *)(__fp - 0x10b4)) = 0;
      uVar1 = (*(uint *)(__fp - 0x10b4));
    }
    else {
      __isoc23_sscanf((char *)&(*(short *)(__fp - 0x1048)),
                      ((char *)(long)&s_cpu_4u__16llu__16llu__16llu__16l_0014cc00 /* "cpu%4u %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu" */)
                      ,&(*(int *)(__fp - 0x109c)),&(*(long *)(__fp - 0x1050)),&(*(long *)(__fp - 0x1058)),&(*(ulong *)(__fp - 0x1060)),&(*(ulong *)(__fp - 0x1068)),&(*(ulong *)(__fp - 0x1070)),
                      &(*(ulong *)(__fp - 0x1078)),&(*(ulong *)(__fp - 0x1080)),&(*(ulong *)(__fp - 0x1088)),&(*(long *)(__fp - 0x1090)),&(*(long *)(__fp - 0x1098)));
      uVar16 = *(uint *)(param_1 + 0x7c);
      uVar1 = (*(int *)(__fp - 0x109c)) + 1;
      if (uVar16 < uVar1) goto LAB_001416e7;
      uVar2 = (*(uint *)(__fp - 0x10b4)) + 1;
      lVar8 = (ulong)uVar1 * 0xd8;
      if (uVar2 < uVar1) {
        lVar12 = (ulong)uVar2 * 0xd8;
        do {
          puVar7 = (undefined8 *)(*(long *)(param_1 + 0xe0) + lVar12);
          lVar12 = lVar12 + 0xd8;
          *puVar7 = 0;
          puVar7[0x1a] = 0;
          uVar4 = (ulong)(((int)puVar7 -
                          (int)(undefined8 *)((ulong)(puVar7 + 1) & 0xfffffffffffffff8)) + 0xd8U >>
                         3);
          puVar7 = (undefined8 *)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          for (; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + (ulong)bVar18 * -2 + 1;
          }
        } while (((ulong)uVar2 + 1 + (ulong)(((*(int *)(__fp - 0x109c)) + -1) - (*(uint *)(__fp - 0x10b4)))) * 0xd8 != lVar12);
        uVar16 = *(uint *)(param_1 + 0x7c);
      }
    }
    (*(uint *)(__fp - 0x10b4)) = uVar1;
    uVar17 = (*(ulong *)(__fp - 0x1068)) + (*(ulong *)(__fp - 0x1070));
    uVar14 = (*(long *)(__fp - 0x1058)) - (*(long *)(__fp - 0x1098));
    uVar15 = (*(long *)(__fp - 0x1050)) - (*(long *)(__fp - 0x1090));
    uVar11 = (*(long *)(__fp - 0x1090)) + (*(long *)(__fp - 0x1098));
    lVar12 = *(long *)(param_1 + 0xe0);
    puVar5 = (ulong *)(lVar12 + lVar8);
    uVar9 = 0;
    uVar13 = (*(ulong *)(__fp - 0x1060)) + (*(ulong *)(__fp - 0x1078)) + (*(ulong *)(__fp - 0x1080));
    uVar6 = uVar15 + uVar14 + (*(ulong *)(__fp - 0x1088)) + uVar17 + uVar11 + uVar13;
    uVar4 = uVar15 - puVar5[1];
    if (uVar15 <= puVar5[1]) {
      uVar4 = uVar9;
    }
    puVar5[0xd] = uVar4;
    uVar4 = uVar14 - puVar5[6];
    if (uVar14 <= puVar5[6]) {
      uVar4 = uVar9;
    }
    puVar5[0x12] = uVar4;
    uVar4 = (*(ulong *)(__fp - 0x1060)) - puVar5[2];
    if ((*(ulong *)(__fp - 0x1060)) <= puVar5[2]) {
      uVar4 = uVar9;
    }
    puVar5[0xe] = uVar4;
    uVar4 = uVar13 - puVar5[3];
    if (uVar13 <= puVar5[3]) {
      uVar4 = uVar9;
    }
    puVar5[0xf] = uVar4;
    uVar4 = uVar17 - puVar5[4];
    if (uVar17 <= puVar5[4]) {
      uVar4 = uVar9;
    }
    puVar5[0x10] = uVar4;
    uVar4 = (*(ulong *)(__fp - 0x1068)) - puVar5[5];
    if ((*(ulong *)(__fp - 0x1068)) <= puVar5[5]) {
      uVar4 = uVar9;
    }
    puVar5[0x11] = uVar4;
    uVar4 = (*(ulong *)(__fp - 0x1070)) - puVar5[7];
    if ((*(ulong *)(__fp - 0x1070)) <= puVar5[7]) {
      uVar4 = uVar9;
    }
    puVar5[0x13] = uVar4;
    puVar5[1] = uVar15;
    puVar5[6] = uVar14;
    puVar5[3] = uVar13;
    uVar4 = (*(ulong *)(__fp - 0x1078)) - puVar5[8];
    if ((*(ulong *)(__fp - 0x1078)) <= puVar5[8]) {
      uVar4 = uVar9;
    }
    puVar5[4] = uVar17;
    puVar5[0x14] = uVar4;
    uVar4 = (*(ulong *)(__fp - 0x1080)) - puVar5[9];
    if ((*(ulong *)(__fp - 0x1080)) <= puVar5[9]) {
      uVar4 = uVar9;
    }
    puVar5[0x15] = uVar4;
    uVar4 = (*(ulong *)(__fp - 0x1088)) - puVar5[10];
    if ((*(ulong *)(__fp - 0x1088)) <= puVar5[10]) {
      uVar4 = uVar9;
    }
    puVar5[0x16] = uVar4;
    uVar4 = uVar11 - puVar5[0xb];
    if (uVar11 <= puVar5[0xb]) {
      uVar4 = uVar9;
    }
    puVar5[0x17] = uVar4;
    uVar4 = uVar6 - *puVar5;
    if (uVar6 <= *puVar5) {
      uVar4 = uVar9;
    }
    uVar10 = uVar10 + 1;
    puVar5[2] = (*(ulong *)(__fp - 0x1060));
    puVar5[0xc] = uVar4;
    puVar5[5] = (*(ulong *)(__fp - 0x1068));
    puVar5[7] = (*(ulong *)(__fp - 0x1070));
    puVar5[8] = (*(ulong *)(__fp - 0x1078));
    puVar5[9] = (*(ulong *)(__fp - 0x1080));
    puVar5[10] = (*(ulong *)(__fp - 0x1088));
    puVar5[0xb] = uVar11;
    *puVar5 = uVar6;
  } while (uVar10 <= uVar16);
  uVar4 = *(ulong *)(lVar12 + 0x60);
code_r0x00141a59:
  *(double *)(param_1 + 0xd8) = (double)uVar4 / (double)*(uint *)(param_1 + 0x78);
  do {
    pcVar3 = fgets((char *)&(*(short *)(__fp - 0x1048)),0x1001,__stream);
    if (pcVar3 == (char *)0x0) goto LAB_0014177e;
  } while ((CONCAT35((*(undefined3 *)(__fp - 0x1043)),CONCAT23((*(undefined2 *)(__fp - 0x1045)),CONCAT12((*(char *)(__fp - 0x1046)),(*(short *)(__fp - 0x1048))))) !=
            0x75725f73636f7270) || (CONCAT53((*(undefined5 *)(__fp - 0x1040)),(*(undefined3 *)(__fp - 0x1043))) != 0x676e696e6e75725f));
  uVar4 = __isoc23_strtoul((*(char (*)[4091])(__fp - 0x103b)),(char **)0x0,10);
  *(int *)(param_1 + 200) = (int)uVar4;
LAB_0014177e:
  fclose(__stream);
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

