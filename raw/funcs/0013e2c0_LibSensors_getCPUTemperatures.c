/* LibSensors_getCPUTemperatures @ 0013e2c0 size 1487 */

void LibSensors_getCPUTemperatures(CPUData *cpus,uint existingCPUs,uint activeCPUs)

{
  double dVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  wchar_t wVar6;
  double *p1;
  double *pdVar7;
  sensors_chip_name *psVar8;
  sensors_feature *psVar9;
  ulong uVar10;
  sensors_subfeature *psVar11;
  double *pdVar12;
  size_t sVar13;
  ulong uVar14;
  double *in_RCX;
  ulong uVar15;
  double *extraout_RDX;
  long extraout_RDX_00;
  long a2;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  uint uVar16;
  size_t __size;
  long in_R9;
  undefined **ppuVar17;
  long lVar18;
  long in_FS_OFFSET;
  double dVar19;
  uint local_68;
  wchar_t n;
  wchar_t m;
  double temp;
  long local_40;

  uVar14 = (ulong)(existingCPUs + 1);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __size = uVar14 * 8;
                    /* Unresolved local var: void * data@[???] */
  p1 = malloc(__size);
  if (p1 == (double *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
                    /* Unresolved local var: size_t i@[???] */
  if (uVar14 == 0) {
    pdVar12 = extraout_RDX;
    if (dlopenHandle != (void *)0x0) goto LAB_0013e368;
LAB_0013e485:
                    /* Unresolved local var: uint i@[???] */
    cpus->temperature = *p1;
  }
  else {
    pdVar12 = p1 + uVar14;
    in_RCX = (double *)(ulong)((uint)__size & 8);
    pdVar7 = p1;
    if ((__size & 8) == 0) goto LAB_0013e348;
    *p1 = NAN;
    for (pdVar7 = p1 + 1; pdVar7 != pdVar12; pdVar7 = pdVar7 + 2) {
LAB_0013e348:
      *pdVar7 = NAN;
      pdVar7[1] = NAN;
    }
    if (dlopenHandle == (void *)0x0) {
LAB_0013e6ca:
      dVar19 = *p1;
    }
    else {
LAB_0013e368:
                    /* Unresolved local var: sensors_chip_name * chip@[???] */
      n = L'\0';
      psVar8 = (*sym_sensors_get_detected_chips)
                         ((sensors_chip_name *)0x0,&n,(long)pdVar12,(long)in_RCX,(ulong)existingCPUs
                          ,in_R9);
      uVar15 = (ulong)existingCPUs;
      if (psVar8 == (sensors_chip_name *)0x0) {
        if ((activeCPUs == 1) || (activeCPUs >> 1 == 1)) {
          sVar13 = 8;
          if (7 < __size) {
            sVar13 = __size;
          }
          __memmove_chk(p1 + 1,p1,uVar15 << 3,sVar13 - 8);
          dVar19 = NAN;
          local_68 = 1;
          *p1 = NAN;
          if (existingCPUs != 0) {
LAB_0013e80c:
            dVar19 = -INFINITY;
            uVar16 = 1;
            do {
              dVar1 = p1[uVar16];
              if (dVar19 < dVar1) {
                *p1 = dVar1;
                dVar19 = dVar1;
              }
              uVar16 = uVar16 + 1;
            } while (uVar16 <= existingCPUs);
            goto LAB_0013e6b6;
          }
LAB_0013e881:
          existingCPUs = 0;
          if (!NAN(p1[1])) {
            cpus->temperature = dVar19;
            goto LAB_0013e4c2;
          }
          uVar14 = (ulong)(activeCPUs >> 1);
          if (activeCPUs >> 1 == 1) goto LAB_0013e780;
LAB_0013e84f:
          dVar19 = *p1;
        }
        else {
          dVar19 = *p1;
LAB_0013e446:
          if (NAN(dVar19)) {
LAB_0013e76a:
            local_68 = 0;
            goto LAB_0013e6bc;
          }
                    /* Unresolved local var: uint i@[???] */
          if (existingCPUs != 0) {
            p1[1] = dVar19;
            uVar16 = 2;
            if (existingCPUs == 1) {
              cpus->temperature = dVar19;
              cpus[1].temperature = dVar19;
              goto LAB_0013e4c2;
            }
            while( true ) {
              uVar14 = (ulong)uVar16;
              uVar16 = uVar16 + 1;
              p1[uVar14] = dVar19;
              if (existingCPUs < uVar16) break;
              dVar19 = *p1;
            }
            goto LAB_0013e485;
          }
        }
        cpus->temperature = dVar19;
        goto LAB_0013e4c2;
      }
      local_68 = 0;
      iVar5 = 99;
      do {
                    /* Unresolved local var: wchar_t priority@[???]
                       Unresolved local var: size_t i@[???] */
        pcVar2 = psVar8->prefix;
        ppuVar17 = &tempDrivers_0;
        lVar18 = 0;
        do {
          iVar3 = strcmp(pcVar2,*ppuVar17);
          if (iVar3 == 0) {
            a2 = lVar18 * 0x10;
            iVar3 = (&DAT_00158168)[lVar18 * 4];
            if ((-1 < iVar3) && (iVar3 <= iVar5)) {
                    /* Unresolved local var: size_t i@[???] */
              if ((iVar3 < iVar5) && (uVar14 != 0)) {
                in_RCX = p1 + uVar14;
                pdVar12 = p1;
                if ((__size & 8) == 0) goto LAB_0013e640;
                *p1 = NAN;
                for (pdVar12 = p1 + 1; in_RCX != pdVar12; pdVar12 = pdVar12 + 2) {
LAB_0013e640:
                  *pdVar12 = NAN;
                  pdVar12[1] = NAN;
                }
              }
              m = L'\0';
                    /* Unresolved local var: sensors_feature * feature@[???] */
              while (psVar9 = (*sym_sensors_get_features)(psVar8,&m,a2,(long)in_RCX,uVar15,in_R9),
                    a2 = extraout_RDX_01, iVar5 = iVar3, psVar9 != (sensors_feature *)0x0) {
                    /* Unresolved local var: ulong tempID@[???]
                       Unresolved local var: sensors_subfeature * subFeature@[???]
                       Unresolved local var: wchar_t r@[???] */
                if (((psVar9->type == SENSORS_FEATURE_TEMP) &&
                    (pcVar2 = psVar9->name, pcVar2 != (char *)0x0)) &&
                   (iVar5 = strncmp(pcVar2,((char *)0x14a1d3 /* "temp" */),4), a2 = extraout_RDX_02, iVar5 == 0)) {
                  uVar10 = __isoc23_strtoul(pcVar2 + 4,(char **)0x0,10);
                  uVar10 = uVar10 - 1;
                  a2 = extraout_RDX_03;
                  if (((uVar10 < 0xfffffffffffffffe) && (uVar10 <= existingCPUs)) &&
                     ((psVar11 = (*sym_sensors_get_subfeature)
                                           (psVar8,psVar9,SENSORS_SUBFEATURE_TEMP_INPUT,(long)in_RCX
                                            ,uVar15,in_R9), a2 = extraout_RDX_04,
                      psVar11 != (sensors_subfeature *)0x0 &&
                      (wVar6 = (*sym_sensors_get_value)
                                         (psVar8,psVar11->number,&temp,(long)in_RCX,uVar15,in_R9),
                      a2 = extraout_RDX_05, wVar6 == L'\0')))) {
                    dVar19 = p1[uVar10];
                    if (NAN(dVar19)) {
                      local_68 = (local_68 + 1) - (uint)(uVar10 == 0);
                      dVar19 = temp;
                    }
                    else if (dVar19 <= temp) {
                      dVar19 = temp;
                    }
                    p1[uVar10] = dVar19;
                  }
                }
              }
            }
            break;
          }
          lVar18 = lVar18 + 1;
          ppuVar17 = ppuVar17 + 2;
          a2 = extraout_RDX_00;
        } while (lVar18 != 6);
        psVar8 = (*sym_sensors_get_detected_chips)
                           ((sensors_chip_name *)0x0,&n,a2,(long)in_RCX,uVar15,in_R9);
      } while (psVar8 != (sensors_chip_name *)0x0);
      uVar16 = activeCPUs;
      if ((local_68 + 1 == activeCPUs) || (uVar16 = activeCPUs >> 1, local_68 + 1 == uVar16)) {
        sVar13 = 8;
        if (7 < __size) {
          sVar13 = __size;
        }
        __memmove_chk(p1 + 1,p1,(ulong)existingCPUs << 3,sVar13 - 8);
        dVar19 = NAN;
        *p1 = NAN;
        local_68 = uVar16;
        if (uVar16 == 0) goto LAB_0013e76a;
LAB_0013e69b:
                    /* Unresolved local var: double maxTemp@[???]
                       Unresolved local var: uint i@[???] */
        if (existingCPUs != 0) goto LAB_0013e80c;
        existingCPUs = 0;
        if (local_68 == 1) goto LAB_0013e881;
        uVar14 = (ulong)(activeCPUs >> 1);
        if (local_68 != activeCPUs >> 1) goto LAB_0013e84f;
      }
      else {
        dVar19 = *p1;
        if (local_68 == 0) goto LAB_0013e446;
        if (NAN(dVar19)) goto LAB_0013e69b;
LAB_0013e6b6:
        if ((local_68 == 1) && (dVar19 = p1[1], !NAN(dVar19))) {
                    /* Unresolved local var: uint i@[???] */
          if (1 < existingCPUs) {
            p1[2] = dVar19;
            uVar16 = 3;
            if (existingCPUs != 2) {
              while( true ) {
                uVar14 = (ulong)uVar16;
                uVar16 = uVar16 + 1;
                p1[uVar14] = dVar19;
                if (existingCPUs < uVar16) break;
                dVar19 = p1[1];
              }
            }
            goto LAB_0013e485;
          }
          goto LAB_0013e6ca;
        }
LAB_0013e6bc:
        uVar14 = (ulong)(activeCPUs >> 1);
        if (activeCPUs >> 1 != local_68) goto LAB_0013e6ca;
      }
LAB_0013e780:
      uVar15 = (ulong)((int)uVar14 + 1);
      if (__size <= uVar15 * 8) {
        __size = uVar15 * 8;
      }
      __memcpy_chk(p1 + uVar15,p1 + 1,uVar14 * 8,__size + uVar15 * -8);
      dVar19 = *p1;
    }
    cpus->temperature = dVar19;
    if (existingCPUs == 0) goto LAB_0013e4c2;
  }
  uVar16 = 1;
  do {
    uVar4 = uVar16 + 1;
    cpus[uVar16].temperature = p1[uVar16];
    uVar16 = uVar4;
  } while (uVar4 <= existingCPUs);
LAB_0013e4c2:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    free(p1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

