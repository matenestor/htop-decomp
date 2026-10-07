#include "htop.h"

/* LibSensors_init @ 0x13af60 */

undefined8 LibSensors_init(void)

{
  undefined8 uVar1;
  char *pcVar2;

  if (PTR_0015c0b8 != (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0013af70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_0015d8c0)(0);
    return uVar1;
  }
  PTR_0015c0b8 = dlopen(((char *)(long)&s_libsensors_so_00149920 /* "libsensors.so" */),1);
  if (((PTR_0015c0b8 != (void *)0x0) ||
      (PTR_0015c0b8 = dlopen(((char *)(long)&s_libsensors_so_5_0014992e /* "libsensors.so.5" */),1), PTR_0015c0b8 != (void *)0x0)) ||
     (PTR_0015c0b8 = dlopen(((char *)(long)&s_libsensors_so_4_0014993e /* "libsensors.so.4" */),1), PTR_0015c0b8 != (void *)0x0)) {
    dlerror();
    PTR_0015d8c0 = dlsym(PTR_0015c0b8,((char *)(long)&s_sensors_init_001499b7 /* "sensors_init" */));
    if ((((PTR_0015d8c0 != (undefined *)0x0) && (pcVar2 = dlerror(), pcVar2 == (char *)0x0)) &&
        ((PTR_0015c0b0 = dlsym(PTR_0015c0b8,((char *)(long)&s_sensors_cleanup_0014994e /* "sensors_cleanup" */)), PTR_0015c0b0 != (undefined *)0x0 &&
         ((pcVar2 = dlerror(), pcVar2 == (char *)0x0 &&
          (PTR_0015d8b8 = dlsym(PTR_0015c0b8,((char *)(long)&s_sensors_get_detected_chips_0014995e /* "sensors_get_detected_chips" */)),
          PTR_0015d8b8 != (void *)0x0)))))) &&
       ((pcVar2 = dlerror(), pcVar2 == (char *)0x0 &&
        (((((PTR_0015d8b0 = dlsym(PTR_0015c0b8,((char *)(long)&s_sensors_get_features_00149979 /* "sensors_get_features" */)), PTR_0015d8b0 != (void *)0x0
            && (pcVar2 = dlerror(), pcVar2 == (char *)0x0)) &&
           (PTR_0015d8a8 = dlsym(PTR_0015c0b8,((char *)(long)&s_sensors_get_subfeature_0014998e /* "sensors_get_subfeature" */)), PTR_0015d8a8 != (void *)0x0
           )) && ((pcVar2 = dlerror(), pcVar2 == (char *)0x0 &&
                  (PTR_0015d8a0 = dlsym(PTR_0015c0b8,((char *)(long)&s_sensors_get_value_001499a5 /* "sensors_get_value" */)),
                  PTR_0015d8a0 != (void *)0x0)))) && (pcVar2 = dlerror(), pcVar2 == (char *)0x0)))))
       ) {
                    /* WARNING: Could not recover jumptable at 0x0013b0bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)PTR_0015d8c0)(0);
      return uVar1;
    }
    if (PTR_0015c0b8 != (void *)0x0) {
      dlclose(PTR_0015c0b8);
      PTR_0015c0b8 = (void *)0x0;
    }
  }
  return 0xffffffff;
}


/* LibSensors_cleanup @ 0x13b140 */

void LibSensors_cleanup(long param_rdi,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                       long param_r9)

{
  if (PTR_0015c0b8 != (void *)0x0) {
    (*(code *)PTR_0015c0b0)(param_rdi,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
    dlclose(PTR_0015c0b8);
    PTR_0015c0b8 = (void *)0x0;
    return;
  }
  return;
}


/* LibSensors_reload @ 0x13b180 */

undefined8
LibSensors_reload(long param_rdi,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined8 uVar1;
  int *piVar2;

  if (PTR_0015c0b8 != (void *)0x0) {
    (*(code *)PTR_0015c0b0)(param_rdi,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
                    /* WARNING: Could not recover jumptable at 0x0013b19b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_0015d8c0)(0);
    return uVar1;
  }
  piVar2 = __errno_location();
  *piVar2 = 0x5f;
  return 0xffffffff;
}


/* LibSensors_getCPUTemperatures @ 0x13e2c0 */

void LibSensors_getCPUTemperatures
               (long param_1,uint param_2,uint param_3,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  double dVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  double *p1;
  double *pdVar5;
  undefined8 *a0;
  undefined8 *a1;
  ulong uVar6;
  double *pdVar7;
  size_t sVar8;
  ulong uVar9;
  ulong uVar10;
  double *extraout_RDX;
  long extraout_RDX_00;
  long a2;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  uint uVar11;
  size_t __size;
  undefined **ppuVar12;
  long lVar13;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar14;

  uVar9 = (ulong)(param_2 + 1);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __size = uVar9 * 8;
  p1 = malloc(__size);
  if (p1 == (double *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  if (uVar9 == 0) {
    pdVar7 = extraout_RDX;
    if (PTR_0015c0b8 != (void *)0x0) goto LAB_0013e368;
LAB_0013e485:
    *(double *)(param_1 + 200) = *p1;
  }
  else {
    pdVar7 = p1 + uVar9;
    param_rcx = (long)((uint)__size & 8);
    pdVar5 = p1;
    if ((__size & 8) == 0) goto LAB_0013e348;
    *p1 = NAN;
    for (pdVar5 = p1 + 1; pdVar5 != pdVar7; pdVar5 = pdVar5 + 2) {
LAB_0013e348:
      *pdVar5 = NAN;
      pdVar5[1] = NAN;
    }
    if (PTR_0015c0b8 == (void *)0x0) {
LAB_0013e6ca:
      dVar14 = *p1;
    }
    else {
LAB_0013e368:
      (*(undefined4 *)(__fp - 0x50)) = 0;
      a0 = (undefined8 *)
           (*PTR_0015d8b8)(0,(long)&(*(undefined4 *)(__fp - 0x50)),(long)pdVar7,param_rcx,(ulong)param_2,param_r9);
      uVar10 = (ulong)param_2;
      if (a0 == (undefined8 *)0x0) {
        if ((param_3 == 1) || (param_3 >> 1 == 1)) {
          sVar8 = 8;
          if (7 < __size) {
            sVar8 = __size;
          }
          __memmove_chk(p1 + 1,p1,uVar10 << 3,sVar8 - 8);
          dVar14 = NAN;
          (*(uint *)(__fp - 0x68)) = 1;
          *p1 = NAN;
          if (param_2 != 0) {
LAB_0013e80c:
            dVar14 = -INFINITY;
            uVar11 = 1;
            do {
              dVar1 = p1[uVar11];
              if (dVar14 < dVar1) {
                *p1 = dVar1;
                dVar14 = dVar1;
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 <= param_2);
            goto LAB_0013e6b6;
          }
LAB_0013e881:
          param_2 = 0;
          if (!NAN(p1[1])) {
            *(double *)(param_1 + 200) = dVar14;
            goto LAB_0013e4c2;
          }
          uVar9 = (ulong)(param_3 >> 1);
          if (param_3 >> 1 == 1) goto LAB_0013e780;
LAB_0013e84f:
          dVar14 = *p1;
        }
        else {
          dVar14 = *p1;
LAB_0013e446:
          if (NAN(dVar14)) {
LAB_0013e76a:
            (*(uint *)(__fp - 0x68)) = 0;
            goto LAB_0013e6bc;
          }
          if (param_2 != 0) {
            p1[1] = dVar14;
            uVar11 = 2;
            if (param_2 == 1) {
              *(double *)(param_1 + 200) = dVar14;
              *(double *)(param_1 + 0x1a0) = dVar14;
              goto LAB_0013e4c2;
            }
            while( true ) {
              uVar9 = (ulong)uVar11;
              uVar11 = uVar11 + 1;
              p1[uVar9] = dVar14;
              if (param_2 < uVar11) break;
              dVar14 = *p1;
            }
            goto LAB_0013e485;
          }
        }
        *(double *)(param_1 + 200) = dVar14;
        goto LAB_0013e4c2;
      }
      (*(uint *)(__fp - 0x68)) = 0;
      iVar4 = 99;
      do {
        pcVar2 = (char *)*a0;
        ppuVar12 = &PTR_s_coretemp_00158160;
        lVar13 = 0;
        do {
          iVar3 = strcmp(pcVar2,*ppuVar12);
          if (iVar3 == 0) {
            a2 = lVar13 * 0x10;
            iVar3 = (&DAT_00158168)[lVar13 * 4];
            if ((-1 < iVar3) && (iVar3 <= iVar4)) {
              if ((iVar3 < iVar4) && (uVar9 != 0)) {
                param_rcx = (long)(p1 + uVar9);
                pdVar7 = p1;
                if ((__size & 8) == 0) goto LAB_0013e640;
                *p1 = NAN;
                for (pdVar7 = p1 + 1; (double *)param_rcx != pdVar7; pdVar7 = pdVar7 + 2) {
LAB_0013e640:
                  *pdVar7 = NAN;
                  pdVar7[1] = NAN;
                }
              }
              (*(undefined4 *)(__fp - 0x4c)) = 0;
              while (a1 = (undefined8 *)
                          (*PTR_0015d8b0)((long)a0,(long)&(*(undefined4 *)(__fp - 0x4c)),a2,param_rcx,uVar10,param_r9),
                    a2 = extraout_RDX_01, iVar4 = iVar3, a1 != (undefined8 *)0x0) {
                if (((*(int *)((long)a1 + 0xc) == 2) &&
                    (pcVar2 = (char *)*a1, pcVar2 != (char *)0x0)) &&
                   (iVar4 = strncmp(pcVar2,((char *)(long)&DAT_0014a1d3 /* "temp" */),4), a2 = extraout_RDX_02, iVar4 == 0)) {
                  uVar6 = __isoc23_strtoul(pcVar2 + 4,(char **)0x0,10);
                  uVar6 = uVar6 - 1;
                  a2 = extraout_RDX_03;
                  if (((uVar6 < 0xfffffffffffffffe) && (uVar6 <= param_2)) &&
                     ((lVar13 = (*PTR_0015d8a8)((long)a0,(long)a1,0x200,param_rcx,uVar10,param_r9),
                      a2 = extraout_RDX_04, lVar13 != 0 &&
                      (lVar13 = (*PTR_0015d8a0)((long)a0,(ulong)*(uint *)(lVar13 + 8),
                                                (long)&(*(double *)(__fp - 0x48)),param_rcx,uVar10,param_r9),
                      a2 = extraout_RDX_05, (int)lVar13 == 0)))) {
                    dVar14 = p1[uVar6];
                    if (NAN(dVar14)) {
                      (*(uint *)(__fp - 0x68)) = ((*(uint *)(__fp - 0x68)) + 1) - (uint)(uVar6 == 0);
                      dVar14 = (*(double *)(__fp - 0x48));
                    }
                    else if (dVar14 <= (*(double *)(__fp - 0x48))) {
                      dVar14 = (*(double *)(__fp - 0x48));
                    }
                    p1[uVar6] = dVar14;
                  }
                }
              }
            }
            break;
          }
          lVar13 = lVar13 + 1;
          ppuVar12 = ppuVar12 + 2;
          a2 = extraout_RDX_00;
        } while (lVar13 != 6);
        a0 = (undefined8 *)(*PTR_0015d8b8)(0,(long)&(*(undefined4 *)(__fp - 0x50)),a2,param_rcx,uVar10,param_r9);
      } while (a0 != (undefined8 *)0x0);
      uVar11 = param_3;
      if (((*(uint *)(__fp - 0x68)) + 1 == param_3) || (uVar11 = param_3 >> 1, (*(uint *)(__fp - 0x68)) + 1 == uVar11)) {
        sVar8 = 8;
        if (7 < __size) {
          sVar8 = __size;
        }
        __memmove_chk(p1 + 1,p1,(ulong)param_2 << 3,sVar8 - 8);
        dVar14 = NAN;
        *p1 = NAN;
        (*(uint *)(__fp - 0x68)) = uVar11;
        if (uVar11 == 0) goto LAB_0013e76a;
LAB_0013e69b:
        if (param_2 != 0) goto LAB_0013e80c;
        param_2 = 0;
        if ((*(uint *)(__fp - 0x68)) == 1) goto LAB_0013e881;
        uVar9 = (ulong)(param_3 >> 1);
        if ((*(uint *)(__fp - 0x68)) != param_3 >> 1) goto LAB_0013e84f;
      }
      else {
        dVar14 = *p1;
        if ((*(uint *)(__fp - 0x68)) == 0) goto LAB_0013e446;
        if (NAN(dVar14)) goto LAB_0013e69b;
LAB_0013e6b6:
        if (((*(uint *)(__fp - 0x68)) == 1) && (dVar14 = p1[1], !NAN(dVar14))) {
          if (1 < param_2) {
            p1[2] = dVar14;
            uVar11 = 3;
            if (param_2 != 2) {
              while( true ) {
                uVar9 = (ulong)uVar11;
                uVar11 = uVar11 + 1;
                p1[uVar9] = dVar14;
                if (param_2 < uVar11) break;
                dVar14 = p1[1];
              }
            }
            goto LAB_0013e485;
          }
          goto LAB_0013e6ca;
        }
LAB_0013e6bc:
        uVar9 = (ulong)(param_3 >> 1);
        if (param_3 >> 1 != (*(uint *)(__fp - 0x68))) goto LAB_0013e6ca;
      }
LAB_0013e780:
      uVar10 = (ulong)((int)uVar9 + 1);
      if (__size <= uVar10 * 8) {
        __size = uVar10 * 8;
      }
      __memcpy_chk(p1 + uVar10,p1 + 1,uVar9 * 8,__size + uVar10 * -8);
      dVar14 = *p1;
    }
    *(double *)(param_1 + 200) = dVar14;
    if (param_2 == 0) goto LAB_0013e4c2;
  }
  uVar11 = 1;
  do {
    uVar9 = (ulong)uVar11;
    uVar11 = uVar11 + 1;
    *(double *)(param_1 + 200 + uVar9 * 0xd8) = p1[uVar9];
  } while (uVar11 <= param_2);
LAB_0013e4c2:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    free(p1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

