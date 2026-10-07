#include "htop.h"

/* SystemdMeter_done @ 0x1389f0 */

/* DWARF original prototype: void SystemdMeter_done(Meter * this) */

void SystemdMeter_done(Meter *this)

{
  int iVar1;
  long in_RCX;
  long a2;
  SystemdMeterContext_t *pSVar2;
  char *a1;
  long in_R8;
  long in_R9;
  bool bVar3;

  a1 = ((char *)(long)&s_SystemdUser_001477b1 /* "SystemdUser" */);
  pSVar2 = &ctx_system;
  iVar1 = strcmp((char *)(this->super).klass[3].delete,((char *)(long)&s_SystemdUser_001477b1 /* "SystemdUser" */));
  if (iVar1 == 0) {
    pSVar2 = &ctx_user;
  }
  free(pSVar2->systemState);
  pSVar2->systemState = (char *)0x0;
  if ((pSVar2->bus != (sd_bus *)0x0) && (dlopenHandle_15d830 != (void *)0x0)) {
    (*(code *)(sym_sd_bus_unref))(pSVar2->bus,(long)a1,a2,in_RCX,in_R8,in_R9);
  }
  bVar3 = ctx_system_systemState == (char *)0x0;
  pSVar2->bus = (sd_bus *)0x0;
  if (((bVar3) && (ctx_user_systemState == (char *)0x0)) && (dlopenHandle_15d830 != (void *)0x0)) {
    dlclose(dlopenHandle_15d830);
    dlopenHandle_15d830 = (void *)0x0;
  }
  return;
}


/* SystemdMeter_updateValues @ 0x13fab0 */

/* DWARF original prototype: void SystemdMeter_updateValues(Meter * this) */

void SystemdMeter_updateValues(Meter *this)

{
  undefined1 __frame[0x178] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x138;
  long lVar1;
  uint uVar2;
  int wVar3;
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
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar10;

  pSVar8 = &ctx_system;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = strcmp((char *)(this->super).klass[3].delete,((char *)(long)&s_SystemdUser_001477b1 /* "SystemdUser" */));
  if (uVar2 == 0) {
    pSVar8 = &ctx_user;
  }
  (*(uint *(*))(__fp - 0xf0)) = (uint *)0x13fb0e;
  free(pSVar8->systemState);
                    /* Unresolved local var: SystemdMeterContext_t * ctx@[???]
                       Unresolved local var: int r@[???] */
  bVar10 = dlopenHandle_15d830 == (void *)0x0;
  pSVar8->systemState = (char *)0x0;
  pSVar8->nFailedUnits = 0xffffffff;
  pSVar8->nInstalledJobs = 0xffffffff;
  pSVar8->nNames = 0xffffffff;
  pSVar8->nJobs = 0xffffffff;
  a2 = extraout_RDX;
  if (bVar10) {
    p0 = dlopen(((char *)(long)&s_libsystemd_so_0_00149c30 /* "libsystemd.so.0" */),1);
    dlopenHandle_15d830 = p0;
    if (p0 != (void *)0x0) {
      dlerror();
      sym_sd_bus_open_system = dlsym(p0,((char *)(long)&s_sd_bus_open_system_00149c40 /* "sd_bus_open_system" */));
      if ((((((sym_sd_bus_open_system != (_func_wchar_t_sd_bus_ptr_ptr *)0x0) &&
             (pcVar9 = dlerror(), pcVar9 == (char *)0x0)) &&
            (sym_sd_bus_open_user = dlsym(p0,((char *)(long)&s_sd_bus_open_user_00149c53 /* "sd_bus_open_user" */)),
            sym_sd_bus_open_user != (_func_wchar_t_sd_bus_ptr_ptr *)0x0)) &&
           ((pcVar9 = dlerror(), pcVar9 == (char *)0x0 &&
            (sym_sd_bus_get_property_string = dlsym(p0,((char *)(long)&s_sd_bus_get_property_string_00149c64 /* "sd_bus_get_property_string" */)),
            sym_sd_bus_get_property_string !=
            (_func_wchar_t_sd_bus_ptr_char_ptr_char_ptr_char_ptr_char_ptr_sd_bus_error_ptr_char_ptr_ptr
             *)0x0)))) &&
          ((pcVar9 = dlerror(), pcVar9 == (char *)0x0 &&
           ((sym_sd_bus_get_property_trivial = dlsym(p0,((char *)(long)&s_sd_bus_get_property_trivial_00149c7f /* "sd_bus_get_property_trivial" */)),
            sym_sd_bus_get_property_trivial !=
            (_func_wchar_t_sd_bus_ptr_char_ptr_char_ptr_char_ptr_char_ptr_sd_bus_error_ptr_char_void_ptr
             *)0x0 && (pcVar9 = dlerror(), pcVar9 == (char *)0x0)))))) &&
         (sym_sd_bus_unref = dlsym(p0,((char *)(long)&s_sd_bus_unref_00149c9b /* "sd_bus_unref" */)),
         sym_sd_bus_unref != (_func_sd_bus_ptr_sd_bus_ptr *)0x0)) {
        (*(uint *(*))(__fp - 0xf0)) = (uint *)0x13fef1;
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
        (*(uint *(*))(__fp - 0xf0)) = (uint *)0x13fdfe;
        wVar3 = (*(code *)(sym_sd_bus_open_user))(&pSVar8->bus,0,a2,(long)in_RCX,(long)in_R8,(long)in_R9);
      }
      else {
        (*(uint *(*))(__fp - 0xf0)) = (uint *)0x13fca7;
        wVar3 = (*(code *)(sym_sd_bus_open_system))
                          (&pSVar8->bus,(long)pcVar9,a2,(long)in_RCX,(long)in_R8,(long)in_R9);
      }
      a2_00 = pSVar8->bus;
      if (-1 < wVar3) goto LAB_0013fb43;
    }
    else {
LAB_0013fb43:
      in_RCX = (char *)(*(uint *(*))(__fp - 0xf0));
      in_R9 = (uint *)0x0;
      in_R8 = ((char *)(long)(__sec_rodata + 0x2cfe) /* "SystemState" */);
      pcVar9 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
      wVar3 = (*sym_sd_bus_get_property_string)
                        (a2_00,((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */),((char *)(long)&s__org_freedesktop_systemd1_00149ca8 /* "/org/freedesktop/systemd1" */),
                         ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)(long)(__sec_rodata + 0x2cfe) /* "SystemState" */),(sd_bus_error *)0x0,
                         &pSVar8->systemState);
      if (-1 < wVar3) {
        in_R9 = (uint *)0x0;
        in_RCX = ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */);
        in_R8 = ((char *)(long)(__sec_rodata + 0x2ce6) /* "NFailedUnits" */);
        pcVar9 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
        wVar3 = (*sym_sd_bus_get_property_trivial)
                          (pSVar8->bus,((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */),((char *)(long)&s__org_freedesktop_systemd1_00149ca8 /* "/org/freedesktop/systemd1" */),
                           ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)(long)(__sec_rodata + 0x2ce6) /* "NFailedUnits" */),(sd_bus_error *)0x0,'u'
                           ,&pSVar8->nFailedUnits);
        if (-1 < wVar3) {
          in_R9 = &pSVar8->nInstalledJobs;
          in_RCX = ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */);
          pcVar9 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
          in_R8 = (char *)0x75;
          wVar3 = (*sym_sd_bus_get_property_trivial)
                            (pSVar8->bus,((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */),((char *)(long)&s__org_freedesktop_systemd1_00149ca8 /* "/org/freedesktop/systemd1" */),
                             ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)(long)(__sec_rodata + 0x2d24) /* "NInstalledJobs" */),(sd_bus_error *)0x0
                             ,'u',in_R9);
          if (-1 < wVar3) {
            in_R9 = (uint *)0x0;
            in_R8 = ((char *)(long)(__sec_rodata + 0x2d4f) /* "NNames" */);
            in_RCX = ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */);
            pcVar9 = (char *)0x75;
            wVar3 = (*sym_sd_bus_get_property_trivial)
                              (pSVar8->bus,((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */),((char *)(long)&s__org_freedesktop_systemd1_00149ca8 /* "/org/freedesktop/systemd1" */),
                               ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)(long)(__sec_rodata + 0x2d4f) /* "NNames" */),(sd_bus_error *)0x0,'u',
                               &pSVar8->nNames);
            if (-1 < wVar3) {
              in_RCX = (char *)&pSVar8->nJobs;
              in_R9 = (uint *)0x0;
              in_R8 = ((char *)(long)(__sec_rodata + 0x2d3e) /* "NJobs" */);
              pcVar9 = ((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */);
              wVar3 = (*sym_sd_bus_get_property_trivial)
                                (pSVar8->bus,((char *)(long)&s_org_freedesktop_systemd1_00149cc2 /* "org.freedesktop.systemd1" */),((char *)(long)&s__org_freedesktop_systemd1_00149ca8 /* "/org/freedesktop/systemd1" */),
                                 ((char *)(long)&s_org_freedesktop_systemd1_Manager_0014cb88 /* "org.freedesktop.systemd1.Manager" */),((char *)(long)(__sec_rodata + 0x2d3e) /* "NJobs" */),(sd_bus_error *)0x0,'u',
                                 in_RCX);
              if (-1 < wVar3) goto LAB_0013fc3d;
            }
          }
        }
      }
      a2_00 = pSVar8->bus;
    }
    (*(code *)(sym_sd_bus_unref))(a2_00,(long)pcVar9,(long)a2_00,(long)in_RCX,(long)in_R8,(long)in_R9);
    pSVar8->bus = (sd_bus *)0x0;
  }
                    /* Unresolved local var: SystemdMeterContext_t * ctx@[???]
                       Unresolved local var: pid_t child@[???]
                       Unresolved local var: FILE * commandOutput@[???] */
  if ((readonly == false) && (iVar4 = pipe((*(int (*) [2])(__fp - 0xd0))), -1 < iVar4)) {
    _Var5 = fork();
    if (_Var5 < 0) {
      close((*(int (*) [2])(__fp - 0xd0))[1]);
      close((*(int (*) [2])(__fp - 0xd0))[0]);
    }
    else {
      if (_Var5 == 0) {
                    /* Unresolved local var: int fdnull@[???] */
        close((*(int (*) [2])(__fp - 0xd0))[0]);
        dup2((*(int (*) [2])(__fp - 0xd0))[1],1);
        close((*(int (*) [2])(__fp - 0xd0))[1]);
        iVar4 = open(((char *)(long)&s__dev_null_001488eb /* "/dev/null" */),1);
        if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        dup2(iVar4,2);
        close(iVar4);
        pcVar9 = ((char *)(long)&s___system_00149c27 /* "--system" */);
        if (uVar2 == 0) {
          pcVar9 = ((char *)(long)&s___user_00149c20 /* "--user" */);
        }
        execlp(((char *)(long)&s_systemctl_00149d0f /* "systemctl" */),((char *)(long)&s_systemctl_00149d0f /* "systemctl" */),&DAT_00149d0a,pcVar9,((char *)(long)&s___property_SystemState_00149cf3 /* "--property=SystemState" */),
               ((char *)(long)&s___property_NFailedUnits_00149cdb /* "--property=NFailedUnits" */),((char *)(long)&s___property_NNames_00149d44 /* "--property=NNames" */),((char *)(long)&s___property_NJobs_00149d33 /* "--property=NJobs" */),
               ((char *)(long)&s___property_NInstalledJobs_00149d19 /* "--property=NInstalledJobs" */),0);
                    /* WARNING: Subroutine does not return */
        exit(0x7f);
      }
      close((*(int (*) [2])(__fp - 0xd0))[1]);
      _Var5 = waitpid(_Var5,&(*(int (*))(__fp - 0xd4)),0);
      if (((_Var5 < 0) || (((*(int (*))(__fp - 0xd4)) & 0xff7fU) != 0)) ||
         (__stream = fdopen((*(int (*) [2])(__fp - 0xd0))[0],((char *)(long)&DAT_00147760 /* "r" */)), __stream == (FILE_2 *)0x0)) {
        close((*(int (*) [2])(__fp - 0xd0))[0]);
      }
      else {
                    /* Unresolved local var: size_t sz@[???] */
        while (pcVar9 = fgets((*(char (*) [128])(__fp - 0xc8)),0x80,__stream), pcVar9 != (char *)0x0) {
          if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                        CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                 CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],(*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 0))))))
               == 0x74536d6574737953) && ((*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 8)) == 0x3d657461)) {
                    /* Unresolved local var: char * newline@[???] */
            pcVar9 = (*(char (*) [128])(__fp - 0xc8)) + 0xc;
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
          else if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                             CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                      CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                               CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],(*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 0)))))) ==
                    0x5564656c6961464e) &&
                  (CONCAT17((*(char (*) [128])(__fp - 0xc8))[0xc],
                            CONCAT43((*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 8)),
                                     CONCAT12((*(char (*) [128])(__fp - 0xc8))[7],CONCAT11((*(char (*) [128])(__fp - 0xc8))[6],(*(char (*) [128])(__fp - 0xc8))[5]))))
                   == 0x3d7374696e556465)) {
            uVar6 = __isoc23_strtoul((*(char (*) [128])(__fp - 0xc8)) + 0xd,(char **)0x0,10);
            pSVar8->nFailedUnits = (uint)uVar6;
          }
          else if (((*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 0)) == 0x6d614e4e) &&
                  (CONCAT13((*(char (*) [128])(__fp - 0xc8))[6],CONCAT12((*(char (*) [128])(__fp - 0xc8))[5],CONCAT11((*(char (*) [128])(__fp - 0xc8))[4],0x6d))) ==
                   0x3d73656d)) {
            uVar6 = __isoc23_strtoul((*(char (*) [128])(__fp - 0xc8)) + 7,(char **)0x0,10);
            pSVar8->nNames = (uint)uVar6;
          }
          else if (((*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 0)) == 0x626f4a4e) &&
                  (CONCAT11((*(char (*) [128])(__fp - 0xc8))[5],(*(char (*) [128])(__fp - 0xc8))[4]) == 0x3d73)) {
            uVar6 = __isoc23_strtoul((*(char (*) [128])(__fp - 0xc8)) + 6,(char **)0x0,10);
            pSVar8->nJobs = (uint)uVar6;
          }
          else if ((CONCAT17((*(char (*) [128])(__fp - 0xc8))[7],
                             CONCAT16((*(char (*) [128])(__fp - 0xc8))[6],
                                      CONCAT15((*(char (*) [128])(__fp - 0xc8))[5],
                                               CONCAT14((*(char (*) [128])(__fp - 0xc8))[4],(*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 0)))))) ==
                    0x6c6c6174736e494e) &&
                  (CONCAT26((*(ushort *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 13)),
                            CONCAT15((*(char (*) [128])(__fp - 0xc8))[0xc],CONCAT41((*(uint *)((char *)&(*(char (*) [128])(__fp - 0xc8)) + 8)),(*(char (*) [128])(__fp - 0xc8))[7]))) ==
                   0x3d73626f4a64656c)) {
            uVar6 = __isoc23_strtoul((*(char (*) [128])(__fp - 0xc8)) + 0xf,(char **)0x0,10);
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
    pcVar9 = ((char *)(long)&DAT_00148963 /* "???" */);
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),pcVar9);
  return;
}


/* _SystemdMeter_display @ 0x1448c0 */

void _SystemdMeter_display(Object *cast,RichString *out,SystemdMeterContext_t *ctx)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  attr_t aVar1;
  long lVar2;
  int iVar3;
  int wVar4;
  int wVar5;
  long lVar6;
  cchar_t *__s1;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int color@[???] */
  __s1 = out->chptr;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  if (__s1 == (cchar_t *)0x0) {
    lVar6 = 0x40;
    __s1 = (cchar_t *)&DAT_001474de;
  }
  else {
    iVar3 = strcmp((char *)__s1,((char *)(long)(__sec_rodata + 0x2149) /* "running" */));
    lVar6 = 0x50;
    if (iVar3 != 0) {
      iVar3 = strcmp((char *)__s1,((char *)(long)&s_degraded_0014a0ca /* "degraded" */));
      lVar6 = (-(ulong)(iVar3 == 0) & 0xffffffffffffffec) + 0x54;
    }
  }
  RichString_writeAscii((RichString *)cast,*(int *)((long)CRT_colors + lVar6),(char *)__s1);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)(long)(__sec_rodata + 0x30db) /* " (" */));
  aVar1 = out->chstr[0].attr;
  if (aVar1 == 0xffffffff) {
    wVar5 = 1;
    (*(char (*) [16])(__fp - 0x58))[0] = '?';
    (*(char (*) [16])(__fp - 0x58))[1] = '\0';
LAB_0014495f:
    wVar4 = CRT_colors[0x10];
  }
  else {
    wVar5 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),aVar1);
    aVar1 = out->chstr[0].attr;
    if (aVar1 == 0) {
      wVar4 = CRT_colors[0xf];
    }
    else {
      if (aVar1 == 0xffffffff) goto LAB_0014495f;
      wVar4 = CRT_colors[0x13];
    }
  }
  RichString_appendnAscii((RichString *)cast,wVar4,(*(char (*) [16])(__fp - 0x58)),wVar5);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)(long)(__sec_rodata + 0x17c2) /* "/" */));
  wVar5 = out->chstr[0].chars[1];
  if (wVar5 == -1) {
    (*(char (*) [16])(__fp - 0x58))[0] = '?';
    (*(char (*) [16])(__fp - 0x58))[1] = '\0';
    wVar4 = 1;
LAB_001449a5:
    wVar5 = CRT_colors[0x10];
  }
  else {
    wVar4 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),wVar5);
    wVar5 = out->chstr[0].chars[1];
    if (wVar5 == 0) {
      wVar5 = CRT_colors[0x13];
    }
    else {
      if (wVar5 == -1) goto LAB_001449a5;
      wVar5 = CRT_colors[0xf];
    }
  }
  RichString_appendnAscii((RichString *)cast,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar4);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)(long)&s_failed____0014a0d3 /* " failed) (" */));
  wVar5 = out->chstr[0].chars[2];
  if (wVar5 == -1) {
    wVar4 = 1;
    (*(char (*) [16])(__fp - 0x58))[0] = '?';
    (*(char (*) [16])(__fp - 0x58))[1] = '\0';
LAB_001449e8:
    wVar5 = CRT_colors[0x10];
  }
  else {
    wVar4 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),wVar5);
    wVar5 = out->chstr[0].chars[2];
    if (wVar5 == 0) {
      wVar5 = CRT_colors[0xf];
    }
    else {
      if (wVar5 == -1) goto LAB_001449e8;
      wVar5 = CRT_colors[0x13];
    }
  }
  RichString_appendnAscii((RichString *)cast,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar4);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)(long)(__sec_rodata + 0x17c2) /* "/" */));
  wVar5 = out->chstr[0].chars[0];
  if (wVar5 == -1) {
    wVar4 = 1;
    (*(char (*) [16])(__fp - 0x58))[0] = '?';
    (*(char (*) [16])(__fp - 0x58))[1] = '\0';
  }
  else {
    wVar4 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474a2 /* "%u" */),wVar5);
    wVar5 = out->chstr[0].chars[0];
    if (wVar5 == 0) {
      wVar5 = CRT_colors[0x13];
      goto LAB_00144a2a;
    }
    if (wVar5 != -1) {
      wVar5 = CRT_colors[0xf];
      goto LAB_00144a2a;
    }
  }
  wVar5 = CRT_colors[0x10];
LAB_00144a2a:
  RichString_appendnAscii((RichString *)cast,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar4);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)(long)&s_jobs__0014a0de /* " jobs)" */));
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* SystemdMeter_display @ 0x144bd0 */

void SystemdMeter_display(Object *cast,RichString *out)

{
  SystemdMeterContext_t *in_RDX;

  _SystemdMeter_display((Object *)out,(RichString *)&ctx_system,in_RDX);
  return;
}


/* SystemdUserMeter_display @ 0x144bf0 */

void SystemdUserMeter_display(Object *cast,RichString *out)

{
  SystemdMeterContext_t *in_RDX;

  _SystemdMeter_display((Object *)out,(RichString *)&ctx_user,in_RDX);
  return;
}

