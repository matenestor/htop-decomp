/* SystemdMeter_updateValues @ 0013fab0 size 1637 */

/* DWARF original prototype: void SystemdMeter_updateValues(Meter * this) */

void SystemdMeter_updateValues(Meter *this)

{
  long lVar1;
  uint uVar2;
  wchar_t wVar3;
  int iVar4;
  __pid_t _Var5;
  FILE_2 *__stream;
  ulong uVar6;
  void *p0;
  char *pcVar7;
  char *in_RCX;
  long extraout_RDX;
  long a2;
  sd_bus *a2_00;
  long extraout_RDX_00;
  SystemdMeterContext_t *pSVar8;
  char *pcVar9;
  char *in_R8;
  uint *in_R9;
  long in_FS_OFFSET;
  bool bVar10;
  uint *puVar11;
  wchar_t wstatus;
  wchar_t fdpair [2];
  char lineBuffer [128];

  pSVar8 = &ctx_system;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = strcmp((char *)(this->super).klass[3].delete,((char *)0x1477b1 /* "SystemdUser" */));
  if (uVar2 == 0) {
    pSVar8 = &ctx_user;
  }
  puVar11 = (uint *)0x13fb0e;
  free(pSVar8->systemState);
                    /* Unresolved local var: SystemdMeterContext_t * ctx@[???]
                       Unresolved local var: wchar_t r@[???] */
  bVar10 = dlopenHandle_15d830 == (void *)0x0;
  pSVar8->systemState = (char *)0x0;
  pSVar8->nFailedUnits = 0xffffffff;
  pSVar8->nInstalledJobs = 0xffffffff;
  pSVar8->nNames = 0xffffffff;
  pSVar8->nJobs = 0xffffffff;
  a2 = extraout_RDX;
  if (bVar10) {
    p0 = dlopen(((char *)0x149c30 /* "libsystemd.so.0" */),1);
    dlopenHandle_15d830 = p0;
    if (p0 != (void *)0x0) {
      dlerror();
      sym_sd_bus_open_system = dlsym(p0,((char *)0x149c40 /* "sd_bus_open_system" */));
      if ((((((sym_sd_bus_open_system != (_func_wchar_t_sd_bus_ptr_ptr *)0x0) &&
             (pcVar9 = dlerror(), pcVar9 == (char *)0x0)) &&
            (sym_sd_bus_open_user = dlsym(p0,((char *)0x149c53 /* "sd_bus_open_user" */)),
            sym_sd_bus_open_user != (_func_wchar_t_sd_bus_ptr_ptr *)0x0)) &&
           ((pcVar9 = dlerror(), pcVar9 == (char *)0x0 &&
            (sym_sd_bus_get_property_string = dlsym(p0,((char *)0x149c64 /* "sd_bus_get_property_string" */)),
            sym_sd_bus_get_property_string !=
            (_func_wchar_t_sd_bus_ptr_char_ptr_char_ptr_char_ptr_char_ptr_sd_bus_error_ptr_char_ptr_ptr
             *)0x0)))) &&
          ((pcVar9 = dlerror(), pcVar9 == (char *)0x0 &&
           ((sym_sd_bus_get_property_trivial = dlsym(p0,((char *)0x149c7f /* "sd_bus_get_property_trivial" */)),
            sym_sd_bus_get_property_trivial !=
            (_func_wchar_t_sd_bus_ptr_char_ptr_char_ptr_char_ptr_char_ptr_sd_bus_error_ptr_char_void_ptr
             *)0x0 && (pcVar9 = dlerror(), pcVar9 == (char *)0x0)))))) &&
         (sym_sd_bus_unref = dlsym(p0,((char *)0x149c9b /* "sd_bus_unref" */)),
         sym_sd_bus_unref != (_func_sd_bus_ptr_sd_bus_ptr *)0x0)) {
        puVar11 = (uint *)0x13fef1;
        pcVar9 = dlerror();
        a2 = extraout_RDX_00;
        if (pcVar9 == (char *)0x0) goto LAB_0013fb37;
      }
      dlclose(p0);
      dlopenHandle_15d830 = (void *)0x0;
    }
  }
  else {
LAB_0013fb37:
    a2_00 = pSVar8->bus;
    if (a2_00 == (sd_bus *)0x0) {
      pcVar9 = (char *)(ulong)uVar2;
      if (uVar2 == 0) {
        puVar11 = (uint *)0x13fdfe;
        wVar3 = (*sym_sd_bus_open_user)(&pSVar8->bus,0,a2,(long)in_RCX,(long)in_R8,(long)in_R9);
      }
      else {
        puVar11 = (uint *)0x13fca7;
        wVar3 = (*sym_sd_bus_open_system)
                          (&pSVar8->bus,(long)pcVar9,a2,(long)in_RCX,(long)in_R8,(long)in_R9);
      }
      a2_00 = pSVar8->bus;
      if (L'\xffffffff' < wVar3) goto LAB_0013fb43;
    }
    else {
LAB_0013fb43:
      in_RCX = (char *)puVar11;
      in_R9 = (uint *)0x0;
      in_R8 = ((char *)0x149cfe /* "SystemState" */);
      pcVar9 = ((char *)0x149cc2 /* "org.freedesktop.systemd1" */);
      wVar3 = (*sym_sd_bus_get_property_string)
                        (a2_00,((char *)0x149cc2 /* "org.freedesktop.systemd1" */),((char *)0x149ca8 /* "/org/freedesktop/systemd1" */),
                         ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)0x149cfe /* "SystemState" */),(sd_bus_error *)0x0,
                         &pSVar8->systemState);
      if (L'\xffffffff' < wVar3) {
        in_R9 = (uint *)0x0;
        in_RCX = ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */);
        in_R8 = ((char *)0x149ce6 /* "NFailedUnits" */);
        pcVar9 = ((char *)0x149cc2 /* "org.freedesktop.systemd1" */);
        wVar3 = (*sym_sd_bus_get_property_trivial)
                          (pSVar8->bus,((char *)0x149cc2 /* "org.freedesktop.systemd1" */),((char *)0x149ca8 /* "/org/freedesktop/systemd1" */),
                           ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)0x149ce6 /* "NFailedUnits" */),(sd_bus_error *)0x0,'u'
                           ,&pSVar8->nFailedUnits);
        if (L'\xffffffff' < wVar3) {
          in_R9 = &pSVar8->nInstalledJobs;
          in_RCX = ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */);
          pcVar9 = ((char *)0x149cc2 /* "org.freedesktop.systemd1" */);
          in_R8 = (char *)0x75;
          wVar3 = (*sym_sd_bus_get_property_trivial)
                            (pSVar8->bus,((char *)0x149cc2 /* "org.freedesktop.systemd1" */),((char *)0x149ca8 /* "/org/freedesktop/systemd1" */),
                             ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)0x149d24 /* "NInstalledJobs" */),(sd_bus_error *)0x0
                             ,'u',in_R9);
          if (L'\xffffffff' < wVar3) {
            in_R9 = (uint *)0x0;
            in_R8 = ((char *)0x149d4f /* "NNames" */);
            in_RCX = ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */);
            pcVar9 = (char *)0x75;
            wVar3 = (*sym_sd_bus_get_property_trivial)
                              (pSVar8->bus,((char *)0x149cc2 /* "org.freedesktop.systemd1" */),((char *)0x149ca8 /* "/org/freedesktop/systemd1" */),
                               ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)0x149d4f /* "NNames" */),(sd_bus_error *)0x0,'u',
                               &pSVar8->nNames);
            if (L'\xffffffff' < wVar3) {
              in_RCX = (char *)&pSVar8->nJobs;
              in_R9 = (uint *)0x0;
              in_R8 = ((char *)0x149d3e /* "NJobs" */);
              pcVar9 = ((char *)0x149cc2 /* "org.freedesktop.systemd1" */);
              wVar3 = (*sym_sd_bus_get_property_trivial)
                                (pSVar8->bus,((char *)0x149cc2 /* "org.freedesktop.systemd1" */),((char *)0x149ca8 /* "/org/freedesktop/systemd1" */),
                                 ((char *)0x14cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)0x149d3e /* "NJobs" */),(sd_bus_error *)0x0,'u',
                                 in_RCX);
              if (L'\xffffffff' < wVar3) goto LAB_0013fc3d;
            }
          }
        }
      }
      a2_00 = pSVar8->bus;
    }
    (*sym_sd_bus_unref)(a2_00,(long)pcVar9,(long)a2_00,(long)in_RCX,(long)in_R8,(long)in_R9);
    pSVar8->bus = (sd_bus *)0x0;
  }
                    /* Unresolved local var: SystemdMeterContext_t * ctx@[???]
                       Unresolved local var: pid_t child@[???]
                       Unresolved local var: FILE * commandOutput@[???] */
  if ((readonly == false) && (iVar4 = pipe(fdpair), -1 < iVar4)) {
    _Var5 = fork();
    if (_Var5 < 0) {
      close(fdpair[1]);
      close(fdpair[0]);
    }
    else {
      if (_Var5 == 0) {
                    /* Unresolved local var: wchar_t fdnull@[???] */
        close(fdpair[0]);
        dup2(fdpair[1],1);
        close(fdpair[1]);
        iVar4 = open(((char *)0x1488eb /* "/dev/null" */),1);
        if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        dup2(iVar4,2);
        close(iVar4);
        pcVar9 = ((char *)0x149c27 /* "--system" */);
        if (uVar2 == 0) {
          pcVar9 = ((char *)0x149c20 /* "--user" */);
        }
        execlp(((char *)0x149d0f /* "systemctl" */),((char *)0x149d0f /* "systemctl" */),&DAT_00149d0a,pcVar9,((char *)0x149cf3 /* "--property=SystemState" */),
               ((char *)0x149cdb /* "--property=NFailedUnits" */),((char *)0x149d44 /* "--property=NNames" */),((char *)0x149d33 /* "--property=NJobs" */),
               ((char *)0x149d19 /* "--property=NInstalledJobs" */),0);
                    /* WARNING: Subroutine does not return */
        exit(0x7f);
      }
      close(fdpair[1]);
      _Var5 = waitpid(_Var5,&wstatus,0);
      if (((_Var5 < 0) || ((wstatus & 0xff7fU) != 0)) ||
         (__stream = fdopen(fdpair[0],((char *)0x147760 /* "r" */)), __stream == (FILE_2 *)0x0)) {
        close(fdpair[0]);
      }
      else {
                    /* Unresolved local var: size_t sz@[???] */
        while (pcVar9 = fgets(lineBuffer,0x80,__stream), pcVar9 != (char *)0x0) {
          if ((CONCAT17(lineBuffer[7],
                        CONCAT16(lineBuffer[6],
                                 CONCAT15(lineBuffer[5],CONCAT14(lineBuffer[4],lineBuffer._0_4_))))
               == 0x74536d6574737953) && (lineBuffer._8_4_ == 0x3d657461)) {
                    /* Unresolved local var: char * newline@[???] */
            pcVar9 = lineBuffer + 0xc;
            pcVar7 = strchr(pcVar9,10);
            if (pcVar7 != (char *)0x0) {
              *pcVar7 = '\0';
            }
            pcVar7 = pSVar8->systemState;
            if ((pcVar7 == (char *)0x0) || (iVar4 = strcmp(pcVar7,pcVar9), iVar4 != 0)) {
              free(pcVar7);
                    /* Unresolved local var: char * data@[???] */
              pcVar9 = strdup(pcVar9);
              if (pcVar9 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
                fail();
              }
              pSVar8->systemState = pcVar9;
            }
          }
          else if ((CONCAT17(lineBuffer[7],
                             CONCAT16(lineBuffer[6],
                                      CONCAT15(lineBuffer[5],
                                               CONCAT14(lineBuffer[4],lineBuffer._0_4_)))) ==
                    0x5564656c6961464e) &&
                  (CONCAT17(lineBuffer[0xc],
                            CONCAT43(lineBuffer._8_4_,
                                     CONCAT12(lineBuffer[7],CONCAT11(lineBuffer[6],lineBuffer[5]))))
                   == 0x3d7374696e556465)) {
            uVar6 = __isoc23_strtoul(lineBuffer + 0xd,(char **)0x0,10);
            pSVar8->nFailedUnits = (uint)uVar6;
          }
          else if ((lineBuffer._0_4_ == 0x6d614e4e) &&
                  (CONCAT13(lineBuffer[6],CONCAT12(lineBuffer[5],CONCAT11(lineBuffer[4],0x6d))) ==
                   0x3d73656d)) {
            uVar6 = __isoc23_strtoul(lineBuffer + 7,(char **)0x0,10);
            pSVar8->nNames = (uint)uVar6;
          }
          else if ((lineBuffer._0_4_ == 0x626f4a4e) &&
                  (CONCAT11(lineBuffer[5],lineBuffer[4]) == 0x3d73)) {
            uVar6 = __isoc23_strtoul(lineBuffer + 6,(char **)0x0,10);
            pSVar8->nJobs = (uint)uVar6;
          }
          else if ((CONCAT17(lineBuffer[7],
                             CONCAT16(lineBuffer[6],
                                      CONCAT15(lineBuffer[5],
                                               CONCAT14(lineBuffer[4],lineBuffer._0_4_)))) ==
                    0x6c6c6174736e494e) &&
                  (CONCAT26(lineBuffer._13_2_,
                            CONCAT15(lineBuffer[0xc],CONCAT41(lineBuffer._8_4_,lineBuffer[7]))) ==
                   0x3d73626f4a64656c)) {
            uVar6 = __isoc23_strtoul(lineBuffer + 0xf,(char **)0x0,10);
            pSVar8->nInstalledJobs = (uint)uVar6;
          }
        }
        fclose(__stream);
      }
    }
  }
LAB_0013fc3d:
  pcVar9 = pSVar8->systemState;
  if (pcVar9 == (char *)0x0) {
    pcVar9 = ((char *)0x148963 /* "???" */);
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x147626 /* "%s" */),pcVar9);
  return;
}

