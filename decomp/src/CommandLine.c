#include "htop.h"

/* CommandLine_run @ 0x11d310 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CommandLine_run(int param_1,long param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0x348] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x308;
  char cVar1;
  ulong *puVar2;
  undefined16 auVar3;
  undefined *va0;
  int iVar4;
  int iVar5;
  __uid_t _Var6;
  char *pcVar7;
  passwd *ppVar8;
  undefined8 uVar9;
  undefined8 *__ptr;
  ulong *puVar10;
  long *__ptr_00;
  undefined8 *puVar11;
  undefined8 *puVar12;
  long *__ptr_01;
  undefined8 *puVar13;
  long *plVar14;
  long lVar15;
  int *piVar16;
  ushort **ppuVar17;
  byte *pbVar18;
  timespec *va1;
  long lVar19;
  void *va0_00;
  undefined4 uVar20;
  long extraout_RDX;
  long extraout_RDX_00;
  char *pcVar21;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  long a2;
  long extraout_RDX_06;
  long a2_00;
  long extraout_RDX_07;
  undefined **ppuVar22;
  long lVar23;
  long *plVar24;
  int *a0;
  ulong uVar25;
  byte *pbVar26;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar27;

  bVar27 = 0;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  pcVar7 = getenv(((char *)(long)&s_LC_CTYPE_00147524 /* "LC_CTYPE" */));
  if ((pcVar7 == (char *)0x0) && (pcVar7 = getenv(((char *)(long)&s_LC_ALL_0014752d /* "LC_ALL" */)), pcVar7 == (char *)0x0)) {
    pcVar7 = ((char *)(long)&DAT_00149c0c /* "" */);
  }
  setlocale(0,pcVar7);
  ppuVar22 = &PTR_DAT_0015b020;
  puVar11 = (*(undefined8 (*)[65])(__fp - 0x248));
  for (lVar19 = 0x40; lVar19 != 0; lVar19 = lVar19 + -1) {
    *puVar11 = *ppuVar22;
    ppuVar22 = ppuVar22 + (ulong)bVar27 * -2 + 1;
    puVar11 = puVar11 + (ulong)bVar27 * -2 + 1;
  }
  __builtin_memset(__fp - 0x264,0,12);
  (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 0)) = 0xffffffff;
  (*(undefined8 *)(__fp - 0x260)) = 0xffffffffffffffff;
  ASSIGN_ARR((*(undefined1 (*)[12])(__fp - 0x254)), SUB1612((undefined16)0x0,4));
  (*(undefined16 *)(__fp - 0x258)) = 0x1000101;
  auVar3 = (*(undefined16 *)(__fp - 0x258));
  (*(undefined16 *)(__fp - 0x258)) = (*(ulong *)((char *)&auVar3 + 0));
  (*(uint *)((char *)&(*(undefined1 (*)[12])(__fp - 0x254)) + 4)) = 0xffffffff;
  (*(timespec *)(__fp - 0x2a8)).tv_sec = (ulong)(*(uint *)((char *)&(*(timespec *)(__fp - 0x2a8)).tv_sec + 4)) << 0x20;
  (*(ulong * *)(__fp - 0x278)) = (ulong *)0x0;
  (*(char * *)(__fp - 0x270)) = (char *)0x0;
  pcVar7 = (*(char * *)(__fp - 0x270));
LAB_0011d3d9:
  (*(char * *)(__fp - 0x270)) = pcVar7;
  puVar11 = (*(undefined8 (*)[65])(__fp - 0x248));
  va1 = &(*(timespec *)(__fp - 0x2a8));
  iVar4 = getopt_long(param_1,(char **)param_2,((char *)(long)&DAT_0014756e /* "hVMCs:td:n:Up:F:H::" */),(*(undefined8 (*)[65])(__fp - 0x248)),(int *)&(*(timespec *)(__fp - 0x2a8)))
  ;
  pcVar21 = (*(char * *)(__fp - 0x270));
  pbVar26 = _optarg;
  va0 = program;
  if (1 < iVar4 + 1U) {
    pcVar7 = (*(char * *)(__fp - 0x270));
    switch(iVar4) {
    case 0x43:
      (*(uchar *)((char *)&auVar3 + 0xf)) = 0;
      __builtin_memcpy(&auVar3,__fp - 0x257,15);
      (*(undefined16 *)(__fp - 0x258)) = auVar3 << 8;
      goto LAB_0011d3d9;
    default:
      goto switchD_0011d413_caseD_44;
    case 0x46:
      if (((*(char * *)(__fp - 0x270)) == (char *)0x0) ||
         (iVar4 = strcmp((*(char * *)(__fp - 0x270)),(char *)_optarg), pcVar7 = (*(char * *)(__fp - 0x270)), iVar4 != 0)) {
        free(pcVar21);
        pcVar7 = strdup((char *)pbVar26);
        if (pcVar7 == (char *)0x0) goto LAB_0011e0f1;
      }
      goto LAB_0011d3d9;
    case 0x48:
      if (_optarg == (byte *)0x0) {
        if (((_optind < param_1) &&
            (pbVar26 = *(byte **)(param_2 + (long)_optind * 8), pbVar26 != (byte *)0x0)) &&
           ((*pbVar26 != 0 && (*pbVar26 != 0x2d)))) {
          _optind = _optind + 1;
          goto LAB_0011d773;
        }
      }
      else {
LAB_0011d773:
        iVar4 = __isoc23_sscanf((char *)pbVar26,((char *)(long)&DAT_0014754c /* "%16d" */),(*(undefined1 (*)[12])(__fp - 0x254)) + 4);
        auVar3 = (*(undefined16 *)(__fp - 0x258));
        if (iVar4 != 1) {
          __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_highlight_delay_v_0014b108 /* "Error: invalid highlight delay value \"%s\".\n" */),pbVar26);
          goto switchD_0011d413_caseD_44;
        }
        if ((int)(*(uint *)((char *)&(*(undefined1 (*)[12])(__fp - 0x254)) + 4)) < 1) {
          (*(uint *)((char *)&(*(undefined1 (*)[12])(__fp - 0x254)) + 4)) = 1;
          (*(undefined16 *)(__fp - 0x258)) = (*(uint *)((char *)&auVar3 + 0));
          (*(undefined1 (*)[12])(__fp - 0x254))[0] = 1;
          pcVar7 = (*(char * *)(__fp - 0x270));
          goto LAB_0011d3d9;
        }
      }
      (*(undefined1 (*)[12])(__fp - 0x254))[0] = 1;
      pcVar7 = (*(char * *)(__fp - 0x270));
      goto LAB_0011d3d9;
    case 0x4d:
      (*(undefined1 (*)[2])(__fp - 0x258))[1] = 0;
      goto LAB_0011d3d9;
    case 0x55:
      (*(char *)(__fp - 0x255)) = 0;
      goto LAB_0011d3d9;
    case 0x56:
      __printf_chk(2,((char *)(long)&s__s_3_3_0_00147534 /* "%s 3.3.0\n" */),program);
      break;
    case 100:
      iVar4 = __isoc23_sscanf((char *)_optarg,((char *)(long)&DAT_0014754c /* "%16d" */),&(*(undefined8 *)(__fp - 0x260)));
      if (iVar4 != 1) {
        __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_delay_value___s___0014b078 /* "Error: invalid delay value \"%s\".\n" */),_optarg);
        goto switchD_0011d413_caseD_44;
      }
      pcVar7 = (*(char * *)(__fp - 0x270));
      if ((int)(*(undefined8 *)(__fp - 0x260)) < 1) {
        (*(uint *)((char *)&(*(undefined8 *)(__fp - 0x260)) + 0)) = 1;
      }
      else if (100 < (int)(*(undefined8 *)(__fp - 0x260))) {
        (*(uint *)((char *)&(*(undefined8 *)(__fp - 0x260)) + 0)) = 100;
      }
      goto LAB_0011d3d9;
    case 0x68:
      __printf_chk(2,
                   ((char *)(long)&s__s_3_3_0__C__2004_2019_Hisham_Mu_0014abe0 /* "%s 3.3.0\n(C) 2004-2019 Hisham Muhammad. (C) 2020-2024 htop dev team.\nReleased under the GNU GPLv2+.\n\n-C --no-color                   Use a monochrome color scheme\n-d --delay=DELAY                Set the delay between updates, in tenths of seconds\n-F --filter=FILTER              Show only the commands matching the given filter\n-h --help                       Print this help screen\n-H --highlight-changes[=DELAY]  Highlight new and old processes\n" */)
                   ,program);
      __printf_chk(2,((char *)(long)&s__M___no_mouse_Disable_the_mouse_0014ada0 /* "-M --no-mouse                   Disable the mouse\n" */));
      __printf_chk(2,
                   ((char *)(long)&s__n___max_iterations_NUMBER_Exit_h_0014add8 /* "-n --max-iterations=NUMBER      Exit htop after NUMBER iterations/frame updates\n-p --pid=PID[,PID,PID...]       Show only the given PIDs\n   --readonly                   Disable all system and process changing features\n-s --sort-key=COLUMN            Sort by COLUMN in list view (try --sort-key=help for a list)\n-t --tree                       Show the tree view (can be combined with -s)\n-u --user[=USERNAME]            Show only processes for a given user (or $USER)\n-U --no-unicode                 Do not use unicode but plain ASCII\n-V --version                    Print version info\n" */)
                  );
      __printf_chk(2,((char *)(long)&s_Press_F1_inside__s_for_online_he_0014b028 /* "\nPress F1 inside %s for online help.\nSee \'man %s\' for more information.\n" */)
                   ,va0,va0);
      break;
    case 0x6e:
      iVar4 = __isoc23_sscanf((char *)_optarg,((char *)(long)&DAT_0014754c /* "%16d" */),(void *)((long)&(*(undefined8 *)(__fp - 0x260)) + 4));
      if (iVar4 == 1) goto code_r0x0011d628;
      __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_maximum_iteration_0014b0d8 /* "Error: invalid maximum iteration count \"%s\".\n" */),_optarg);
      goto switchD_0011d413_caseD_44;
    case 0x70:
      pcVar7 = strdup((char *)_optarg);
      if (pcVar7 == (char *)0x0) {
LAB_0011e0f1:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      pcVar21 = strtok_r(pcVar7,((char *)(long)&DAT_0014756c /* "," */),(char **)&(*(long * *)(__fp - 0x298)));
      if ((*(ulong * *)(__fp - 0x278)) == (ulong *)0x0) {
        (*(ulong * *)(__fp - 0x278)) = Hashtable_new(8,0);
      }
      while (pcVar21 != (char *)0x0) {
        lVar19 = __isoc23_strtol(pcVar21,(char **)0x0,10);
        Hashtable_put((*(ulong * *)(__fp - 0x278)),(uint)lVar19,(void *)0x1);
        pcVar21 = strtok_r((char *)0x0,((char *)(long)&DAT_0014756c /* "," */),(char **)&(*(long * *)(__fp - 0x298)));
      }
      free(pcVar7);
      pcVar7 = (*(char * *)(__fp - 0x270));
      goto LAB_0011d3d9;
    case 0x73:
      iVar4 = strcmp((char *)_optarg,((char *)(long)&DAT_0014753e /* "help" */));
      if (iVar4 == 0) {
        (*(undefined4 *)(__fp - 0x2b8)) = 0;
        ppuVar22 = (undefined **)(Process_fields + 0x20);
        do {
          if (*ppuVar22 != (undefined *)0x0) {
            __printf_chk(2,((char *)(long)&s__19s__s_00147543 /* "%19s %s\n" */),*ppuVar22,ppuVar22[2]);
          }
          ppuVar22 = ppuVar22 + 4;
        } while (ppuVar22 != &PTR_s_Space_00157660);
        goto LAB_0011d44a;
      }
      iVar4 = 1;
      (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 4)) = 0;
      puVar11 = (undefined8 *)(Process_fields + 0x20);
      while (((char *)*puVar11 == (char *)0x0 ||
             (iVar5 = strcmp((char *)pbVar26,(char *)*puVar11), iVar5 != 0))) {
        iVar4 = iVar4 + 1;
        puVar11 = puVar11 + 4;
        if (iVar4 == 0x84) {
          __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_column___s___00147585 /* "Error: invalid column \"%s\".\n" */),pbVar26);
          goto switchD_0011d413_caseD_44;
        }
      }
      (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 4)) = iVar4;
      pcVar7 = (*(char * *)(__fp - 0x270));
      goto LAB_0011d3d9;
    case 0x74:
      (*(char *)(__fp - 0x256)) = 1;
      goto LAB_0011d3d9;
    case 0x75:
      if (_optarg == (byte *)0x0) {
        if ((((param_1 <= _optind) ||
             (pbVar26 = *(byte **)(param_2 + (long)_optind * 8), pbVar26 == (byte *)0x0)) ||
            (*pbVar26 == 0)) || (*pbVar26 == 0x2d)) {
          _Var6 = geteuid();
          (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 0)) = _Var6;
          pcVar7 = (*(char * *)(__fp - 0x270));
          goto LAB_0011d3d9;
        }
        _optind = _optind + 1;
      }
      ppVar8 = getpwnam((char *)pbVar26);
      if (ppVar8 == (passwd *)0x0) {
        (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 0)) = 0xffffffff;
        bVar27 = *pbVar26;
        if (bVar27 != 0) {
          ppuVar17 = __ctype_b_loc();
          pbVar18 = pbVar26;
          do {
            if ((*(byte *)((long)*ppuVar17 + (ulong)bVar27 * 2 + 1) & 8) == 0) {
              __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_user___s___00147551 /* "Error: invalid user \"%s\".\n" */),pbVar26);
              goto switchD_0011d413_caseD_44;
            }
            bVar27 = pbVar18[1];
            pbVar18 = pbVar18 + 1;
          } while (bVar27 != 0);
        }
        lVar19 = __isoc23_strtol((char *)pbVar26,(char **)0x0,10);
        (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 0)) = (int)lVar19;
        pcVar7 = (*(char * *)(__fp - 0x270));
      }
      else {
        (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 0)) = ppVar8->pw_uid;
        pcVar7 = (*(char * *)(__fp - 0x270));
      }
      goto LAB_0011d3d9;
    case 0x80:
      (*(undefined1 (*)[12])(__fp - 0x254))[8] = 1;
      goto LAB_0011d3d9;
    }
    (*(undefined4 *)(__fp - 0x2b8)) = 0;
    goto LAB_0011d44a;
  }
  if (_optind < param_1) {
    __fprintf_chk(_stderr,2,((char *)(long)&s_Error__unsupported_non_option_AR_0014b138 /* "Error: unsupported non-option ARGV-elements:" */));
    while (_optind < param_1) {
      lVar19 = (long)_optind;
      _optind = _optind + 1;
      __fprintf_chk(_stderr,2,((char *)(long)(__sec_rodata + 0x625) /* " %s" */),*(void **)(param_2 + lVar19 * 8));
    }
    __fprintf_chk(_stderr,2,((char *)(long)&DAT_00147506 /* "\n" */));
    goto switchD_0011d413_caseD_44;
  }
  if ((*(undefined1 (*)[12])(__fp - 0x254))[8] != '\0') {
    CHAR____0015c0d9 = '\x01';
  }
  iVar4 = access(((char *)(long)&s__proc_00149a78 /* "/proc" */),4);
  if (iVar4 != 0) {
    __fprintf_chk(_stderr,2,((char *)(long)&s_Error__could_not_read_procfs__co_0014b168 /* "Error: could not read procfs (compiled to look in %s).\n" */),((char *)(long)&s__proc_00149a78 /* "/proc" */));
    goto switchD_0011d413_caseD_44;
  }
  uVar9 = FUN_0013c920();
  if ((char)uVar9 == '\0') goto switchD_0011d413_caseD_44;
  __ptr = malloc(8);
  if (__ptr == (undefined8 *)0x0) goto LAB_0011e0f1;
  puVar10 = Hashtable_new(10,1);
  *__ptr = puVar10;
  puVar10 = Hashtable_new(0,1);
  __ptr_00 = Machine_new(__ptr,(*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 0)),extraout_RDX,(long)puVar11,(long)va1,param_r9);
  puVar11 = ProcessTable_new(__ptr_00,(*(ulong * *)(__fp - 0x278)));
  lVar19 = 0;
  puVar12 = Settings_new(*(uint *)(__ptr_00 + 0xf),0,puVar10,0);
  Machine_populateTablesFromSettings(__ptr_00,(long)puVar12,(long)puVar11);
  lVar23 = 2;
  __ptr_01 = Header_new(__ptr_00,2);
  Header_populateFromSettings(__ptr_01,lVar23,extraout_RDX_00,lVar19,(long)va1,param_r9);
  if ((int)(*(undefined8 *)(__fp - 0x260)) != -1) {
    *(int *)((long)puVar12 + 0x4c) = (int)(*(undefined8 *)(__fp - 0x260));
  }
  if ((*(undefined1 (*)[2])(__fp - 0x258))[0] == '\0') {
    *(undefined4 *)(puVar12 + 9) = 1;
  }
  if ((*(undefined1 (*)[2])(__fp - 0x258))[1] == '\0') {
    *(undefined1 *)((long)puVar12 + 0x6f) = 0;
  }
  if ((*(char *)(__fp - 0x256)) != '\0') {
    *(undefined1 *)(puVar12[8] + 0x34) = 1;
  }
  if ((*(undefined1 (*)[12])(__fp - 0x254))[0] != '\0') {
    *(undefined1 *)((long)puVar12 + 0x61) = 1;
  }
  if ((*(uint *)((char *)&(*(undefined1 (*)[12])(__fp - 0x254)) + 4)) != -1) {
    *(undefined4 *)((long)puVar12 + 100) = (*(uint *)((char *)&(*(undefined1 (*)[12])(__fp - 0x254)) + 4));
  }
  if (0 < (int)(*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 4))) {
    lVar19 = puVar12[8];
    cVar1 = Process_fields[(long)(int)(*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 4)) * 0x20 + 0x1d];
    if ((((*(char *)(__fp - 0x256)) == '\0') || (*(char *)(lVar19 + 0x35) != '\0')) ||
       (*(char *)(lVar19 + 0x34) == '\0')) {
      *(undefined4 *)(lVar19 + 0x2c) = (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 4));
      *(undefined1 *)(lVar19 + 0x34) = 0;
      *(uint *)(lVar19 + 0x24) = (-(uint)(cVar1 == '\0') & 2) - 1;
    }
    else {
      *(undefined4 *)(lVar19 + 0x30) = (*(uint *)((char *)&(*(undefined1 (*)[8])(__fp - 0x268)) + 4));
      *(uint *)(lVar19 + 0x28) = (-(uint)(cVar1 == '\0') & 2) - 1;
    }
  }
  __ptr_00[5] = (long)(*(uint *)((char *)&(*(undefined8 *)(__fp - 0x260)) + 4));
  CRT_init((long)puVar12,(*(char *)(__fp - 0x255)),(*(uint *)((char *)&(*(undefined8 *)(__fp - 0x260)) + 4)) != -1);
  puVar13 = MainPanel_new();
  pcVar7 = (*(char * *)(__fp - 0x270));
  if (__ptr_00[0x13] != 0) {
    plVar14 = (long *)__ptr_00[0x14];
    plVar24 = plVar14 + __ptr_00[0x13];
    do {
      lVar19 = *plVar14;
      plVar14 = plVar14 + 1;
      *(undefined8 **)(lVar19 + 0x38) = puVar13;
    } while (plVar14 != plVar24);
  }
  piVar16 = (int *)puVar13[0xb];
  pcVar21 = ((char *)(long)&s_Tree_0014750f /* "Tree  " */);
  if (*(char *)(puVar12[8] + 0x34) != '\0') {
    pcVar21 = ((char *)(long)&s_List_00147508 /* "List  " */);
  }
  FunctionBar_setLabel(piVar16,0x10d,pcVar21);
  pcVar21 = ((char *)(long)&s_Filter_0014751d /* "Filter" */);
  if (pcVar7 != (char *)0x0) {
    pcVar21 = ((char *)(long)&s_FILTER_00147516 /* "FILTER" */);
  }
  FunctionBar_setLabel(piVar16,0x10c,pcVar21);
  (*(undefined2 *)(__fp - 0x280)) = 0;
  (*(undefined1 *)(__fp - 0x27e)) = 0;
  puVar13[0x4dc] = &(*(long * *)(__fp - 0x298));
  (*(long * *)(__fp - 0x298)) = __ptr_00;
  (*(undefined8 * *)(__fp - 0x290)) = puVar13;
  (*(long * *)(__fp - 0x288)) = __ptr_01;
  if ((*(char * *)(__fp - 0x270)) != (char *)0x0) {
    lVar19 = puVar13[0x4dd];
    lVar23 = __ptr_00[0x15];
    lVar15 = 0;
    param_r9 = lVar19 + 0x98;
    do {
      if ((*(char * *)(__fp - 0x270))[lVar15] == '\0') {
        uVar20 = (undefined4)lVar15;
        goto LAB_0011db09;
      }
      *(char *)(lVar19 + 0x98 + lVar15) = (*(char * *)(__fp - 0x270))[lVar15];
      lVar15 = lVar15 + 1;
    } while (lVar15 != 0x80);
    uVar20 = 0x80;
LAB_0011db09:
    *(undefined1 *)(lVar19 + 0x98 + lVar15) = 0;
    *(undefined4 *)(lVar19 + 0x11c) = uVar20;
    *(undefined1 *)(lVar19 + 0x148) = 1;
    *(long *)(lVar23 + 0x28) = param_r9;
    free((*(char * *)(__fp - 0x270)));
    (*(char * *)(__fp - 0x270)) = (char *)0x0;
  }
  piVar16 = (int *)ScreenManager_new(__ptr_01,__ptr_00,&(*(long * *)(__fp - 0x298)),1);
  uVar25 = (ulong)*(uint *)(*(long *)(piVar16 + 4) + 0x18);
  ScreenManager_insert(piVar16,(long)puVar13,-1,*(uint *)(*(long *)(piVar16 + 4) + 0x18));
  Machine_scan(__ptr_00,(long)puVar13,extraout_RDX_01,uVar25,(long)va1,param_r9);
  Machine_scanTables((long)__ptr_00,(long)puVar13,extraout_RDX_02,uVar25,(long)va1,param_r9);
  (*(timespec *)(__fp - 0x2a8)).tv_sec = 0;
  (*(timespec *)(__fp - 0x2a8)).tv_nsec = 75000000;
  do {
    iVar4 = nanosleep(&(*(timespec *)(__fp - 0x2a8)),&(*(timespec *)(__fp - 0x2a8)));
  } while (iVar4 == -1);
  plVar24 = __ptr_00 + 3;
  Generic_gettime_realtime((undefined1 (*) [16])(__ptr_00 + 1),plVar24);
  Machine_scan(__ptr_00,(long)plVar24,extraout_RDX_03,uVar25,(long)va1,param_r9);
  Machine_scanTables((long)__ptr_00,(long)plVar24,extraout_RDX_04,uVar25,(long)va1,param_r9);
  if (*(char *)(puVar12[8] + 0x36) != '\0') {
    Table_collapseAllBranches((long)puVar11,(long)plVar24,extraout_RDX_05,uVar25,(long)va1,param_r9)
    ;
  }
  va0_00 = (void *)0x0;
  lVar19 = 0;
  a0 = piVar16;
  ScreenManager_run(piVar16,(undefined8 *)0x0,(uint *)0x0,0,(long)va1,param_r9);
  if (PTR_0015c0b8 != (void *)0x0) {
    (*(code *)PTR_0015c0b0)((long)a0,lVar19,a2,(long)va0_00,(long)va1,param_r9);
    dlclose(PTR_0015c0b8);
    PTR_0015c0b8 = (void *)0x0;
  }
  CRT_done();
  if (*(char *)((long)puVar12 + 0x74) != '\0') {
    lVar19 = 0;
    iVar4 = Settings_write(puVar12,'\0');
    if (iVar4 < 0) {
      va1 = (timespec *)strerror(-iVar4);
      va0_00 = (void *)*puVar12;
      lVar19 = 2;
      __fprintf_chk(_stderr,2,((char *)(long)&s_Can_not_save_configuration_to__s_0014b1a0 /* "Can not save configuration to %s: %s\n" */),va0_00,va1);
    }
  }
  uVar25 = 0;
  lVar23 = (long)(int)__ptr_01[2] * 3;
  bVar27 = (&DAT_00155fa0)[(long)(int)__ptr_01[2] * 0x18];
  if ((ulong)bVar27 != 0) {
    do {
      lVar15 = uVar25 * 8;
      uVar25 = uVar25 + 1;
      Vector_delete(*(long **)(*__ptr_01 + lVar15),lVar19,lVar23,(long)va0_00,(long)va1,param_r9);
      lVar23 = extraout_RDX_06;
    } while (bVar27 != uVar25);
  }
  free((void *)*__ptr_01);
  free(__ptr_01);
  (**(code **)(*(long *)__ptr_00[0x16] + 0x10))
            (__ptr_00[0x16],lVar19,a2_00,(long)va0_00,(long)va1,param_r9);
  free((void *)__ptr_00[0x14]);
  free((void *)__ptr_00[0x1c]);
  free(__ptr_00);
  Vector_delete(*(long **)(piVar16 + 4),lVar19,extraout_RDX_07,(long)va0_00,(long)va1,param_r9);
  free(piVar16);
  if (LONG_0015c0c0 != 0) {
    FunctionBar_delete((int *)LONG_0015c0c0);
    LONG_0015c0c0 = 0;
  }
  puVar2 = (ulong *)*__ptr;
  Hashtable_clear(puVar2);
  free((void *)puVar2[1]);
  free(puVar2);
  free(__ptr);
  puVar2 = (*(ulong * *)(__fp - 0x278));
  if ((*(ulong * *)(__fp - 0x278)) != (ulong *)0x0) {
    Hashtable_clear((*(ulong * *)(__fp - 0x278)));
    free((void *)puVar2[1]);
    free(puVar2);
  }
  CRT_resetSignalHandlers();
  Settings_delete(puVar12);
  (*(undefined4 *)(__fp - 0x2b8)) = 0;
  if (puVar10 != (ulong *)0x0) {
    Hashtable_clear(puVar10);
    free((void *)puVar10[1]);
    free(puVar10);
  }
  goto LAB_0011d44a;
code_r0x0011d628:
  pcVar7 = (*(char * *)(__fp - 0x270));
  if ((*(uint *)((char *)&(*(undefined8 *)(__fp - 0x260)) + 4)) < 1) {
    __fprintf_chk(_stderr,2,((char *)(long)&s_Error__maximum_iteration_count_m_0014b0a0 /* "Error: maximum iteration count must be positive.\n" */));
switchD_0011d413_caseD_44:
    (*(undefined4 *)(__fp - 0x2b8)) = 1;
LAB_0011d44a:
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return (*(undefined4 *)(__fp - 0x2b8));
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  goto LAB_0011d3d9;
}


/* FUN_0011e100 @ 0x11e100 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0011e100(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  long *a0;
  long lVar1;
  long *plVar2;
  code *pcVar3;
  ulong *puVar4;
  char cVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  ulong extraout_RDX;
  uint uVar9;
  ulong *puVar10;
  char *a4;
  uint uVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong *puVar11;

  puVar11 = &(*(ulong *)(__fp - 0x68));
  puVar10 = &(*(ulong *)(__fp - 0x68));
  a0 = *(long **)(param_1 + 0x10);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar12 = *(uint *)(a0 + 5);
  if ((int)uVar12 < 0) {
    uVar12 = 0;
  }
  Vector_prune((long *)a0[4],param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  lVar1 = *(long *)(param_1 + 8);
  *(undefined1 *)(a0 + 9) = 1;
  *(undefined4 *)(a0 + 8) = 0;
  plVar2 = *(long **)(lVar1 + 8);
  cVar5 = *(char *)(lVar1 + 0x4d);
  a0[5] = 0;
  if (((cVar5 != '\0') && (*(char *)(*plVar2 + 0x58) != '\0')) ||
     (a4 = *(char **)(lVar1 + 0x118), a4 == (char *)0x0)) {
    a4 = *(char **)(lVar1 + 0x80);
  }
  (*(ulong *)(__fp - 0x68)) = (ulong)(int)(_COLS + 1);
  puVar4 = &(*(ulong *)(__fp - 0x68));
  while (puVar11 != (ulong *)((long)&(*(ulong *)(__fp - 0x68)) - ((*(ulong *)(__fp - 0x68)) + 0xf & 0xfffffffffffff000))) {
    puVar10 = (ulong *)((long)puVar4 + -0x1000);
    *(undefined8 *)((long)puVar4 + -8) = *(undefined8 *)((long)puVar4 + -8);
    puVar11 = (ulong *)((long)puVar4 + -0x1000);
    puVar4 = (ulong *)((long)puVar4 + -0x1000);
  }
  uVar7 = (ulong)((uint)((*(ulong *)(__fp - 0x68)) + 0xf) & 0xff0);
  lVar1 = -uVar7;
  if (uVar7 != 0) {
    *(undefined8 *)((long)puVar10 + -8) = *(undefined8 *)((long)puVar10 + -8);
  }
  cVar5 = *a4;
  uVar7 = 0xffffffff;
  uVar9 = 0;
  if (cVar5 != '\0') {
    do {
      uVar8 = (ulong)_COLS;
      *(char *)((long)puVar10 + (int)uVar9 + lVar1) = cVar5;
      if (cVar5 == ' ') {
        uVar7 = (ulong)uVar9;
      }
      if (uVar9 == _COLS) {
        if ((int)uVar7 == -1) {
          uVar7 = (ulong)uVar9;
          (*(ulong *)(__fp - 0x58)) = 1;
          uVar9 = 1;
          (*(char * *)(__fp - 0x60)) = a4;
        }
        else {
          iVar6 = uVar9 - (int)uVar7;
          uVar9 = iVar6 + 1;
          (*(ulong *)(__fp - 0x58)) = (ulong)(int)uVar9;
          (*(char * *)(__fp - 0x60)) = a4 + -(long)iVar6;
        }
        *(undefined1 *)((long)puVar10 + (int)uVar7 + lVar1) = 0;
        (*(char * *)(__fp - 0x50)) = a4;
        InfoScreen_addLine(param_1,(char *)((long)puVar10 + lVar1),(*(ulong *)(__fp - 0x58)),(long)(int)uVar7,
                           (long)a4,param_r9);
        __memcpy_chk((undefined1 *)((long)puVar10 + lVar1),(*(char * *)(__fp - 0x60)),(*(ulong *)(__fp - 0x58)),(*(ulong *)(__fp - 0x68)));
        uVar7 = 0xffffffff;
        cVar5 = (*(char * *)(__fp - 0x50))[1];
        uVar8 = extraout_RDX;
        a4 = (*(char * *)(__fp - 0x50));
      }
      else {
        cVar5 = a4[1];
        uVar9 = uVar9 + 1;
      }
      a4 = a4 + 1;
    } while (cVar5 != '\0');
    if (0 < (int)uVar9) {
      *(undefined1 *)((long)puVar10 + (int)uVar9 + lVar1) = 0;
      InfoScreen_addLine(param_1,(char *)((long)puVar10 + lVar1),uVar8,uVar7,(long)a4,param_r9);
    }
  }
  uVar9 = *(int *)(a0[4] + 0x18) - 1;
  if (*(int *)(a0[4] + 0x18) <= (int)uVar12) {
    uVar12 = uVar9;
  }
  if ((int)uVar12 < 0) {
    uVar12 = 0;
  }
  pcVar3 = *(code **)(*a0 + 0x20);
  *(uint *)(a0 + 5) = uVar12;
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)((long)a0,0xffffffff,(ulong)uVar9,uVar7,(long)a4,param_r9);
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011e330 @ 0x11e330 */

void FUN_0011e330(void *param_1)

{
  long lVar1;
  void *va1;

  lVar1 = *(long *)((long)param_1 + 8);
  if (((*(char *)(lVar1 + 0x4d) != '\0') && (*(char *)(**(long **)(lVar1 + 8) + 0x58) != '\0')) ||
     (va1 = *(void **)(lVar1 + 0x118), va1 == (void *)0x0)) {
    va1 = *(void **)(lVar1 + 0x80);
  }
  InfoScreen_drawTitled(param_1,((char *)(long)&s_Command_of_process__d____s_0014760e /* "Command of process %d - %s" */),*(int *)(lVar1 + 0x10),va1);
  return;
}


/* FUN_0011e380 @ 0x11e380 */

void FUN_0011e380(void *param_1)

{
  long lVar1;
  void *va1;

  lVar1 = *(long *)((long)param_1 + 8);
  if (((*(char *)(lVar1 + 0x4d) != '\0') && (*(char *)(**(long **)(lVar1 + 8) + 0x58) != '\0')) ||
     (va1 = *(void **)(lVar1 + 0x118), va1 == (void *)0x0)) {
    va1 = *(void **)(lVar1 + 0x80);
  }
  InfoScreen_drawTitled(param_1,((char *)(long)&s_Environment_of_process__d____s_0014b1c8 /* "Environment of process %d - %s" */),*(int *)(lVar1 + 0x10),va1);
  return;
}


/* FUN_0011e3d0 @ 0x11e3d0 */

void FUN_0011e3d0(long param_1)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  undefined1 (*pauVar1) [16];
  long lVar2;
  char *pcVar3;
  undefined *va3;
  undefined *va1;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  pauVar1 = *(undefined1 (**) [16])(param_1 + 0x160);
  *(undefined16 *)(*pauVar1) = (undefined16)0x0;
  *(undefined16 *)(pauVar1[1]) = (undefined16)0x0;
  *(undefined16 *)(pauVar1[2]) = (undefined16)0x0;
  *(undefined16 *)(pauVar1[3]) = (undefined16)0x0;
  *(undefined16 *)(pauVar1[4]) = (undefined16)0x0;
  lVar2 = **(long **)(param_1 + 0x10);
  if (*(uint *)((long)*(long **)(param_1 + 0x10) + 0x7c) < *(uint *)(param_1 + 0x24)) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar3 = ((char *)(long)&s_absent_00147648 /* " absent" */);
LAB_0011e5be:
      xSnprintf((char *)(param_1 + 0x60),0x100,pcVar3 + 1);
      return;
    }
    goto LAB_0011e6cb;
  }
  dVar4 = Platform_setCPUValues(param_1,*(uint *)(param_1 + 0x24));
  if (dVar4 < 0.0) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar3 = ((char *)(long)&s_offline_00147650 /* " offline" */);
      goto LAB_0011e5be;
    }
    goto LAB_0011e6cb;
  }
  (*(char (*)[8])(__fp - 0x70))[0] = '\0';
  (*(char (*)[8])(__fp - 0x70))[1] = '\0';
  (*(char (*)[8])(__fp - 0x70))[2] = '\0';
  (*(char (*)[8])(__fp - 0x70))[3] = '\0';
  (*(char (*)[8])(__fp - 0x70))[4] = '\0';
  (*(char (*)[8])(__fp - 0x70))[5] = '\0';
  (*(char (*)[8])(__fp - 0x70))[6] = '\0';
  (*(char (*)[8])(__fp - 0x70))[7] = '\0';
  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x58)), (undefined16)0x0);
  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x68)), (undefined16)0x0);
  if (*(char *)(lVar2 + 0x52) == '\0') {
    if (*(char *)(lVar2 + 0x53) == '\0') goto LAB_0011e49e;
LAB_0011e469:
    dVar4 = *(double *)(*(long *)(param_1 + 0x160) + 0x40);
    if (0.0 <= dVar4) {
      xSnprintf((*(undefined1 (*)[16])(__fp - 0x58)),0x10,((char *)(long)&s__4uMHz_00147629 /* "%4uMHz" */),(int)(long)dVar4);
      goto LAB_0011e49e;
    }
    xSnprintf((*(undefined1 (*)[16])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474de /* "N/A" */));
    if (*(char *)(lVar2 + 0x54) != '\0') goto LAB_0011e4aa;
LAB_0011e508:
    if ((*(undefined1 (*)[16])(__fp - 0x58))[0] == '\0') goto LAB_0011e578;
LAB_0011e512:
    if ((*(undefined1 (*)[16])(__fp - 0x68))[0] == '\0') {
      va3 = &DAT_00149c0c;
      va1 = &DAT_001470dd;
      if ((*(char (*)[8])(__fp - 0x70))[0] == '\0') {
        va1 = &DAT_00149c0c;
      }
    }
    else {
      va3 = &DAT_001470dd;
      va1 = &DAT_00149c0c;
      if ((*(char (*)[8])(__fp - 0x70))[0] != '\0') {
        va1 = &DAT_001470dd;
      }
    }
  }
  else {
    xSnprintf((*(char (*)[8])(__fp - 0x70)),8,((char *)(long)(__sec_rodata + 0x6eb) /* "%.1f%%" */),dVar4);
    if (*(char *)(lVar2 + 0x53) != '\0') goto LAB_0011e469;
LAB_0011e49e:
    if (*(char *)(lVar2 + 0x54) == '\0') goto LAB_0011e508;
LAB_0011e4aa:
    dVar4 = *(double *)(*(long *)(param_1 + 0x160) + 0x48);
    if (NAN(dVar4)) {
      xSnprintf((*(undefined1 (*)[16])(__fp - 0x68)),0x10,((char *)(long)&DAT_001474de /* "N/A" */));
      goto LAB_0011e508;
    }
    if (*(char *)(lVar2 + 0x55) != '\0') {
      xSnprintf((*(undefined1 (*)[16])(__fp - 0x68)),0x10,((char *)(long)&s__3d_sF_00147630 /* "%3d%sF" */),(int)((dVar4 * 9.0) / 5.0 + 32.0),CRT_degreeSign);
      goto LAB_0011e508;
    }
    xSnprintf((*(undefined1 (*)[16])(__fp - 0x68)),0x10,((char *)(long)&s__d_sC_00147637 /* "%d%sC" */),(int)dVar4,CRT_degreeSign);
    if ((*(undefined1 (*)[16])(__fp - 0x58))[0] != '\0') goto LAB_0011e512;
LAB_0011e578:
    va3 = &DAT_00149c0c;
    va1 = va3;
    if ((*(char (*)[8])(__fp - 0x70))[0] != '\0') {
      va1 = &DAT_001470dd;
      if ((*(undefined1 (*)[16])(__fp - 0x68))[0] == '\0') {
        va1 = &DAT_00149c0c;
      }
    }
  }
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s__s_s_s_s_s_0014763d /* "%s%s%s%s%s" */),(*(char (*)[8])(__fp - 0x70)),va1,(*(undefined1 (*)[16])(__fp - 0x58)),va3,(*(undefined1 (*)[16])(__fp - 0x68)));
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0011e6cb:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011e6d0 @ 0x11e6d0 */

void FUN_0011e6d0(long param_1,int *param_2)

{
  undefined1 __frame[0x100148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x100108;
  long lVar1;
  wint_t wVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  char *fmt;
  undefined1 (*pauVar8) [16];
  undefined1 **ppuVar9;
  undefined1 **ppuVar10;
  undefined1 **ppuVar11;
  undefined1 *puVar12;
  long lVar13;
  long lVar14;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar15;

  ppuVar9 = &(*(undefined1 * *)(__fp - 0xb8));
  ppuVar11 = &(*(undefined1 * *)(__fp - 0xb8));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(long *)(__fp - 0x90)) = **(long **)(param_1 + 0x10);
  if (*(uint *)((long)*(long **)(param_1 + 0x10) + 0x7c) < *(uint *)(param_1 + 0x24)) {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x34),((char *)(long)&s_absent_00147648 /* " absent" */));
    ppuVar11 = &(*(undefined1 * *)(__fp - 0xb8));
  }
  else if (*(char *)(param_1 + 0x50) == '\0') {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x34),((char *)(long)&s_offline_00147650 /* " offline" */));
    ppuVar11 = &(*(undefined1 * *)(__fp - 0xb8));
  }
  else {
    uVar4 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*(double *)(*(long *)(param_1 + 0x160) + 8));
    (*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 0)) = uVar4;
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147583 /* ":" */));
    RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x130),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
    dVar15 = *(double *)(*(long *)(param_1 + 0x160) + 0x10);
    if (*(char *)((*(long *)(__fp - 0x90)) + 0x51) == '\0') {
      (*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 0)) = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),dVar15);
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_0014767e /* "sys:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x134),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
      iVar5 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),**(double **)(param_1 + 0x160));
      (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 4)),iVar5);
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147683 /* "low:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 300),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
      dVar15 = *(double *)(*(long *)(param_1 + 0x160) + 0x18);
      if (0.0 <= dVar15) {
        uVar4 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),dVar15);
        RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147688 /* "vir:" */));
        RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x148),(*(char (*)[56])(__fp - 0x78)),uVar4);
      }
    }
    else {
      (*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 0)) = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),dVar15);
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147662 /* "sy:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x134),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
      (*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 0)) = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),**(double **)(param_1 + 0x160));
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147666 /* "ni:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 300),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
      (*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 0)) =
           xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*(double *)(*(long *)(param_1 + 0x160) + 0x18));
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_0014766a /* "hi:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x13c),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
      iVar5 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*(double *)(*(long *)(param_1 + 0x160) + 0x20));
      (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 4)),iVar5);
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_0014766e /* "si:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x140),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
      lVar13 = *(long *)(param_1 + 0x160);
      if (0.0 <= *(double *)(lVar13 + 0x28)) {
        iVar5 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*(double *)(lVar13 + 0x28));
        (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 4)),iVar5);
        RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147672 /* "st:" */));
        RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x144),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
        lVar13 = *(long *)(param_1 + 0x160);
      }
      if (0.0 <= *(double *)(lVar13 + 0x30)) {
        iVar5 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*(double *)(lVar13 + 0x30));
        (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 4)),iVar5);
        RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_00147676 /* "gu:" */));
        RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x148),(*(char (*)[56])(__fp - 0x78)),(uint)(*(undefined1 * *)(__fp - 0x98)));
        lVar13 = *(long *)(param_1 + 0x160);
      }
      uVar4 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*(double *)(lVar13 + 0x38));
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&DAT_0014767a /* "wa:" */));
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x138),(*(char (*)[56])(__fp - 0x78)),uVar4);
    }
    ppuVar10 = &(*(undefined1 * *)(__fp - 0xb8));
    if (*(char *)((*(long *)(__fp - 0x90)) + 0x53) != '\0') {
      dVar15 = *(double *)(*(long *)(param_1 + 0x160) + 0x40);
      if (0.0 <= dVar15) {
        iVar5 = xSnprintf((*(char (*)[10])(__fp - 0x82)),10,((char *)(long)&s__4uMHz_0014768d /* "%4uMHz " */),(int)(long)dVar15);
      }
      else {
        iVar5 = xSnprintf((*(char (*)[10])(__fp - 0x82)),10,((char *)(long)&s_N_A_00147695 /* "N/A     " */));
      }
      (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 4)),iVar5);
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_freq__0014769e /* "freq: " */));
      iVar6 = *param_2;
      (*(undefined1 * *)(__fp - 0xb8)) = (undefined1 *)&(*(undefined1 * *)(__fp - 0xb8));
      iVar5 = (uint)(*(undefined1 * *)(__fp - 0x98)) + 1;
      (*(undefined1 * *)(__fp - 0xa8)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0xa8)) + 4)),*(undefined4 *)(CRT_colors + 0x3c));
      uVar7 = (long)iVar5 * 4 + 0xf;
      ppuVar10 = &(*(undefined1 * *)(__fp - 0xb8));
      while (ppuVar9 != (undefined1 **)((long)&(*(undefined1 * *)(__fp - 0xb8)) - (uVar7 & 0xfffffffffffff000))) {
        ppuVar11 = (undefined1 **)((long)ppuVar10 + -0x1000);
        *(undefined8 *)((long)ppuVar10 + -8) = *(undefined8 *)((long)ppuVar10 + -8);
        ppuVar9 = (undefined1 **)((long)ppuVar10 + -0x1000);
        ppuVar10 = (undefined1 **)((long)ppuVar10 + -0x1000);
      }
      uVar7 = (ulong)((uint)uVar7 & 0xff0);
      lVar13 = -uVar7;
      if (uVar7 != 0) {
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
      }
      uVar7 = (ulong)(int)(uint)(*(undefined1 * *)(__fp - 0x98));
      (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)((long)ppuVar11 + lVar13);
      uVar7 = __mbstowcs_chk((int *)((long)ppuVar11 + lVar13),(*(char (*)[10])(__fp - 0x82)),uVar7,
                             (long)iVar5 & 0x3fffffffffffffff);
      ppuVar10 = (undefined1 **)(*(undefined1 * *)(__fp - 0xb8));
      if (0 < (int)uVar7) {
        iVar5 = (int)uVar7 + iVar6;
        lVar14 = (long)iVar6;
        (*(undefined1 * *)(__fp - 0xa0)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0xa0)) + 4)),iVar5);
        FUN_00130130(param_2,iVar5);
        (*(uint *)(__fp - 0xac)) = (uint)(*(undefined1 * *)(__fp - 0xa8)) & 0xffffff;
        (*(undefined1 * *)(__fp - 0xa8)) = (*(undefined1 * *)(__fp - 0x98)) + lVar14 * -4;
        pauVar8 = (undefined1 (*) [16])(*(long *)(param_2 + 2) + lVar14 * 0x1c);
        do {
          wVar2 = *(wint_t *)((*(undefined1 * *)(__fp - 0xa8)) + lVar14 * 4);
          (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 * *)(__fp - 0x98)) + 4)),wVar2);
          iVar5 = iswprint(wVar2);
          *(undefined16 *)(*pauVar8) = (undefined16)0x0;
          uVar3 = (uint)(*(undefined1 * *)(__fp - 0x98));
          if (iVar5 == 0) {
            uVar3 = 0xfffd;
          }
          *(undefined16 *)(*(undefined1 (*) [16])(*pauVar8 + 0xc)) = (undefined16)0x0;
          lVar14 = lVar14 + 1;
          *(undefined4 *)(*pauVar8 + 4) = uVar3;
          *(uint *)*pauVar8 = (*(uint *)(__fp - 0xac));
          ppuVar10 = (undefined1 **)(*(undefined1 * *)(__fp - 0xb8));
          pauVar8 = (undefined1 (*) [16])(pauVar8[1] + 0xc);
        } while ((int)lVar14 < (int)(*(undefined1 * *)(__fp - 0xa0)));
      }
    }
    ppuVar11 = ppuVar10;
    if (*(char *)((*(long *)(__fp - 0x90)) + 0x54) != '\0') {
      dVar15 = *(double *)(*(long *)(param_1 + 0x160) + 0x48);
      if (NAN(dVar15)) {
        iVar5 = xSnprintf((*(char (*)[10])(__fp - 0x82)),10,((char *)(long)&DAT_001474de /* "N/A" */));
      }
      else {
        fmt = ((char *)(long)&s__5_1f_sC_001476ae /* "%5.1f%sC" */);
        if (*(char *)((*(long *)(__fp - 0x90)) + 0x55) != '\0') {
          fmt = ((char *)(long)&s__5_1f_sF_001476a5 /* "%5.1f%sF" */);
          dVar15 = (dVar15 * 9.0) / 5.0 + 32.0;
        }
        iVar5 = xSnprintf((*(char (*)[10])(__fp - 0x82)),10,fmt,dVar15,CRT_degreeSign);
      }
      uVar4 = *(uint *)(CRT_colors + 0x38);
      RichString_appendAscii(param_2,uVar4,((char *)(long)&s_temp__001476b7 /* "temp:" */));
      (*(undefined1 * *)(__fp - 0x98)) = (undefined1 *)ppuVar10;
      iVar6 = *param_2;
      lVar13 = (long)iVar6;
      uVar4 = *(uint *)(CRT_colors + 0x3c);
      uVar7 = (long)(iVar5 + 1) * 4 + 0xf;
      puVar12 = (undefined1 *)((long)ppuVar10 + -(uVar7 & 0xfffffffffffff000));
      for (; ppuVar10 != (undefined1 **)puVar12;
          ppuVar10 = (undefined1 **)((long)ppuVar10 + -0x1000)) {
        *(undefined8 *)((long)ppuVar10 + -8) = *(undefined8 *)((long)ppuVar10 + -8);
      }
      uVar7 = (ulong)((uint)uVar7 & 0xff0);
      lVar14 = -uVar7;
      if (uVar7 != 0) {
        *(undefined8 *)((long)ppuVar10 + -8) = *(undefined8 *)((long)ppuVar10 + -8);
      }
      (*(undefined1 * *)(__fp - 0xa0)) = (undefined1 *)((long)ppuVar10 + lVar14);
      uVar7 = __mbstowcs_chk((int *)((long)ppuVar10 + lVar14),(*(char (*)[10])(__fp - 0x82)),(long)iVar5,
                             (long)(iVar5 + 1) & 0x3fffffffffffffff);
      ppuVar11 = (undefined1 **)(*(undefined1 * *)(__fp - 0x98));
      if (0 < (int)uVar7) {
        iVar6 = iVar6 + (int)uVar7;
        (*(long *)(__fp - 0x90)) = CONCAT44((*(uint *)((char *)&(*(long *)(__fp - 0x90)) + 4)),iVar6);
        FUN_00130130(param_2,iVar6);
        puVar12 = (*(undefined1 * *)(__fp - 0xa0));
        lVar1 = lVar13 * -4;
        pauVar8 = (undefined1 (*) [16])(*(long *)(param_2 + 2) + lVar13 * 0x1c);
        do {
          wVar2 = *(wint_t *)(puVar12 + lVar13 * 4 + lVar1);
          iVar5 = iswprint(wVar2);
          *(undefined16 *)(*pauVar8) = (undefined16)0x0;
          if (iVar5 == 0) {
            wVar2 = 0xfffd;
          }
          *(uint *)*pauVar8 = uVar4 & 0xffffff;
          lVar13 = lVar13 + 1;
          *(undefined16 *)(*(undefined1 (*) [16])(*pauVar8 + 0xc)) = (undefined16)0x0;
          *(wint_t *)(*pauVar8 + 4) = wVar2;
          pauVar8 = (undefined1 (*) [16])(pauVar8[1] + 0xc);
          ppuVar11 = (undefined1 **)(*(undefined1 * *)(__fp - 0x98));
        } while ((int)lVar13 < (int)(*(long *)(__fp - 0x90)));
      }
    }
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011ef70 @ 0x11ef70 */

void FUN_0011ef70(long param_1,int *param_2)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  double va0;
  uint uVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (**(double **)(param_1 + 0x160) < 0.0) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)(__sec_rodata + 0x72b) /* "unknown" */));
      return;
    }
  }
  else {
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_used__001476bd /* "used: " */));
    uVar1 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s___0lf_00147749 /* "%.0lf" */),**(double **)(param_1 + 0x160));
    RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x16c),(*(char (*)[56])(__fp - 0x78)),uVar1);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_max__001476c4 /* " max: " */));
    va0 = *(double *)(*(long *)(param_1 + 0x160) + 8);
    if (1073741824.0 < va0) {
      RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x170),((char *)(long)(__sec_rodata + 0x739) /* "unlimited" */));
    }
    else {
      uVar1 = xSnprintf((*(char (*)[56])(__fp - 0x78)),0x32,((char *)(long)&s___0lf_00147749 /* "%.0lf" */),va0);
      RichString_appendnAscii(param_2,*(uint *)(CRT_colors + 0x170),(*(char (*)[56])(__fp - 0x78)),uVar1);
    }
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011f0f0 @ 0x11f0f0 */

void FUN_0011f0f0(long param_1)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char *buf;
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar5;
  double dVar6;

  lVar1 = *(long *)(param_1 + 0x10);
  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar4 = *(long *)(lVar1 + 0x18) - LONG_0015c120;
  if (uVar4 < 0x1f5) {
LAB_0011f139:
    dVar6 = DOUBLE_0015c0f0;
    uVar2 = UINT_0015b248;
    **(double **)(param_1 + 0x160) = DOUBLE_0015c0f0;
    if (uVar2 != 2) {
      buf = (char *)(param_1 + 0x60);
      if (uVar2 == 1) {
        xSnprintf(buf,0x100,((char *)(long)(__sec_rodata + 0x29bf) /* "init" */));
      }
      else if (uVar2 == 3) {
        xSnprintf(buf,0x100,((char *)(long)&s_stale_001476d3 /* "stale" */));
      }
      else {
        xSnprintf(buf,0x100,((char *)(long)&s_r__siB_s_w__siB_s___1f___001476d9 /* "r:%siB/s w:%siB/s %.1f%%" */),&DAT_0015c110,&DAT_0015c100,dVar6);
      }
      goto LAB_0011f187;
    }
  }
  else {
    uVar3 = Platform_getDiskIO((long *)&(*(ulong *)(__fp - 0x48)));
    if ((char)uVar3 != '\0') {
      bVar5 = LONG_0015c120 == 0;
      LONG_0015c120 = *(long *)(lVar1 + 0x18);
      if (bVar5) {
        UINT_0015b248 = 1;
      }
      else {
        dVar6 = 0.0;
        UINT_0015b248 = ~-(uint)(uVar4 < 0x7531) & 3;
        if (ULONG_0015c118 < (*(ulong *)(__fp - 0x48))) {
          dVar6 = (double)((((*(ulong *)(__fp - 0x48)) - ULONG_0015c118) * 1000) / uVar4 >> 10);
        }
        Meter_humanUnit(dVar6,&DAT_0015c110,6);
        dVar6 = 0.0;
        if (ULONG_0015c108 < (*(ulong *)(__fp - 0x40))) {
          dVar6 = (double)((((*(ulong *)(__fp - 0x40)) - ULONG_0015c108) * 1000) / uVar4 >> 10);
        }
        Meter_humanUnit(dVar6,&DAT_0015c100,6);
        if (ULONG_0015c0f8 < (*(ulong *)(__fp - 0x38))) {
          DOUBLE_0015c0f0 = ((double)((*(ulong *)(__fp - 0x38)) - ULONG_0015c0f8) * 100.0) / (double)uVar4;
          if (100.0 <= DOUBLE_0015c0f0) {
            DOUBLE_0015c0f0 = 100.0;
          }
        }
        else {
          DOUBLE_0015c0f0 = 0.0;
        }
      }
      ULONG_0015c118 = (*(ulong *)(__fp - 0x48));
      ULONG_0015c108 = (*(ulong *)(__fp - 0x40));
      ULONG_0015c0f8 = (*(ulong *)(__fp - 0x38));
      goto LAB_0011f139;
    }
    LONG_0015c120 = *(long *)(lVar1 + 0x18);
    UINT_0015b248 = 2;
    **(double **)(param_1 + 0x160) = DOUBLE_0015c0f0;
  }
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s_no_data_001476cb /* "no data" */));
LAB_0011f187:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011f410 @ 0x11f410 */

void FUN_0011f410(undefined8 param_1,int *param_2)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  char *pcVar2;
  long lVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (UINT_0015b248 == 2) {
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar2 = ((char *)(long)&s_no_data_001476cb /* "no data" */);
      uVar1 = *(uint *)(CRT_colors + 0x40);
LAB_0011f573:
      RichString_writeAscii(param_2,uVar1,pcVar2);
      return;
    }
  }
  else if (UINT_0015b248 == 3) {
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar2 = ((char *)(long)&s_stale_data_00147702 /* "stale data" */);
      uVar1 = *(uint *)(CRT_colors + 0x54);
      goto LAB_0011f573;
    }
  }
  else if (UINT_0015b248 == 1) {
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar2 = ((char *)(long)&s_initializing____001476f2 /* "initializing..." */);
      uVar1 = *(uint *)(CRT_colors + 0x3c);
      goto LAB_0011f573;
    }
  }
  else {
    lVar3 = 0x4c;
    if (DOUBLE_0015c0f0 <= 40.0) {
      lVar3 = 0x3c;
    }
    uVar1 = xSnprintf((*(char (*)[24])(__fp - 0x48)),0x10,((char *)(long)(__sec_rodata + 0x6eb) /* "%.1f%%" */),DOUBLE_0015c0f0);
    RichString_appendnAscii(param_2,*(uint *)(CRT_colors + lVar3),(*(char (*)[24])(__fp - 0x48)),uVar1);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_read__0014770d /* " read: " */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x44),&DAT_0015c110);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x44),((char *)(long)&DAT_00147715 /* "iB/s" */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x38),((char *)(long)&s_write__0014771a /* " write: " */));
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x48),&DAT_0015c100);
    RichString_appendAscii(param_2,*(uint *)(CRT_colors + 0x48),((char *)(long)&DAT_00147715 /* "iB/s" */));
    if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0011f5f0 @ 0x11f5f0 */

undefined8
FUN_0011f5f0(long param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  uint uVar1;
  int *piVar2;
  byte *pbVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  undefined4 in_register_00000034;
  ulong uVar7;
  long *plVar8;

  uVar7 = CONCAT44(in_register_00000034,param_2);
  plVar8 = (long *)0x0;
  if (0 < (int)(*(long **)(param_1 + 0x20))[3]) {
    plVar8 = *(long **)(**(long **)(param_1 + 0x20) + (long)*(int *)(param_1 + 0x28) * 8);
  }
  if (param_2 < 0x2e) {
    if (param_2 < 10) {
      return 2;
    }
    uVar7 = (ulong)(param_2 - 10);
    switch(uVar7) {
    case 0:
    case 3:
    case 0x16:
      goto switchD_0011f636_caseD_a;
    default:
      goto LAB_0011f645;
    case 0x21:
      if (*(int *)(*plVar8 + 0x20) != 2) {
        return 2;
      }
      NumberItem_increase((long)plVar8);
      break;
    case 0x23:
      if (*(int *)(*plVar8 + 0x20) != 2) {
        return 2;
      }
      param_rcx = plVar8[3];
      iVar5 = *(int *)((long)plVar8 + 0x2c);
      if ((int *)param_rcx == (int *)0x0) {
        param_rcx = (long)*(uint *)(plVar8 + 4);
        iVar6 = *(uint *)(plVar8 + 4) - 1;
        if ((iVar6 <= iVar5) && (iVar5 = (int)plVar8[5], (int)plVar8[5] <= iVar6)) {
          iVar5 = iVar6;
        }
        *(int *)(plVar8 + 4) = iVar5;
      }
      else {
        iVar6 = *(int *)param_rcx + -1;
        if (iVar5 < iVar6) {
          *(int *)param_rcx = iVar5;
        }
        else {
          iVar5 = (int)plVar8[5];
          if ((int)plVar8[5] <= iVar6) {
            iVar5 = iVar6;
          }
          *(int *)param_rcx = iVar5;
        }
      }
    }
  }
  else {
    if (((param_2 != 0x157) && (param_2 != 0x199)) && (param_2 != 0x128)) {
      return 2;
    }
switchD_0011f636_caseD_a:
    if (*(int *)(*plVar8 + 0x20) == 1) {
      pbVar3 = (byte *)plVar8[2];
      if (pbVar3 == (byte *)0x0) {
        *(byte *)(plVar8 + 3) = *(byte *)(plVar8 + 3) ^ 1;
      }
      else {
        *pbVar3 = *pbVar3 ^ 1;
      }
    }
    else {
      if (*(int *)(*plVar8 + 0x20) != 2) {
LAB_0011f645:
        return 2;
      }
      piVar2 = (int *)plVar8[3];
      uVar1 = *(uint *)((long)plVar8 + 0x2c);
      param_rcx = (long)uVar1;
      if (piVar2 == (int *)0x0) {
        if ((int)plVar8[4] < (int)uVar1) {
          *(int *)(plVar8 + 4) = (int)plVar8[4] + 1;
        }
        else {
          *(int *)(plVar8 + 4) = (int)plVar8[5];
        }
      }
      else if (*piVar2 < (int)uVar1) {
        *piVar2 = *piVar2 + 1;
      }
      else {
        *piVar2 = (int)plVar8[5];
      }
    }
  }
  lVar4 = *(long *)(param_1 + 0x26e0);
  plVar8 = (long *)(lVar4 + 0x78);
  *plVar8 = *plVar8 + 1;
  *(undefined1 *)(lVar4 + 0x74) = 1;
  plVar8 = *(long **)(*(long *)(param_1 + 0x26e8) + 0x28);
  Header_calculateHeight(plVar8);
  Header_reinit(plVar8,uVar7,extraout_RDX,param_rcx,param_r8,param_r9);
  Header_updateData(plVar8,uVar7,extraout_RDX_00,param_rcx,param_r8,param_r9);
  Header_draw(plVar8,uVar7,extraout_RDX_01,param_rcx,param_r8,param_r9);
  ScreenManager_resize(*(int **)(param_1 + 0x26e8));
  return 1;
}


/* FUN_0011f7f0 @ 0x11f7f0 */

void FUN_0011f7f0(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  uint uVar1;
  char *__s;
  char cVar2;
  long *a0;
  code *UNRECOVERED_JUMPTABLE;
  char *__ptr;
  size_t sVar3;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long lVar4;
  long extraout_RDX_02;
  long extraout_RDX_03;
  char *pcVar5;
  uint uVar6;

  a0 = *(long **)(param_1 + 0x10);
  uVar6 = *(uint *)(a0 + 5);
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  Vector_prune((long *)a0[4],param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  lVar4 = *(long *)(param_1 + 8);
  *(undefined1 *)(a0 + 9) = 1;
  a0[5] = 0;
  *(undefined4 *)(a0 + 8) = 0;
  __ptr = Platform_getProcessEnv((ulong)*(uint *)(lVar4 + 0x10));
  if (__ptr == (char *)0x0) {
    pcVar5 = ((char *)(long)&s_Could_not_read_process_environme_0014b1e8 /* "Could not read process environment." */);
    InfoScreen_addLine(param_1,((char *)(long)&s_Could_not_read_process_environme_0014b1e8 /* "Could not read process environment." */),extraout_RDX,param_rcx,param_r8
                       ,param_r9);
    lVar4 = extraout_RDX_03;
  }
  else {
    cVar2 = *__ptr;
    __s = __ptr;
    lVar4 = extraout_RDX;
    pcVar5 = (char *)param_rsi;
    while (cVar2 != '\0') {
      pcVar5 = __s;
      InfoScreen_addLine(param_1,__s,lVar4,param_rcx,param_r8,param_r9);
      sVar3 = strlen(__s);
      __s = __s + sVar3 + 1;
      lVar4 = extraout_RDX_00;
      cVar2 = *__s;
    }
    free(__ptr);
    lVar4 = extraout_RDX_01;
  }
  Vector_insertionSort(*(long **)(param_1 + 0x20),(long)pcVar5,lVar4,param_rcx,param_r8,param_r9);
  Vector_insertionSort((long *)a0[4],(long)pcVar5,extraout_RDX_02,param_rcx,param_r8,param_r9);
  uVar1 = *(int *)(a0[4] + 0x18) - 1;
  if (*(int *)(a0[4] + 0x18) <= (int)uVar6) {
    uVar6 = uVar1;
  }
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*a0 + 0x20);
  *(uint *)(a0 + 5) = uVar6;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011f8d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)a0,0xffffffff,(ulong)uVar1,param_rcx,param_r8,param_r9);
    return;
  }
  return;
}


/* FUN_0011f910 @ 0x11f910 */

void FUN_0011f910(long param_1)

{
  double *pdVar1;
  int iVar2;
  double dVar3;
  double dVar4;

  pdVar1 = *(double **)(param_1 + 0x160);
  *pdVar1 = 0.0;
  pdVar1[1] = 1.0;
  Platform_getFileDescriptors(pdVar1,pdVar1 + 1);
  pdVar1 = *(double **)(param_1 + 0x160);
  *(undefined1 *)(param_1 + 0x50) = 1;
  dVar4 = pdVar1[1];
  if (dVar4 <= 65536.0) {
LAB_0011f9f8:
    *(double *)(param_1 + 0x168) = dVar4;
  }
  else {
    dVar3 = *(double *)(param_1 + 0x168);
    if (*pdVar1 * 16.0 <= dVar3) {
LAB_0011f9d8:
      if (dVar4 < dVar3) {
        *(double *)(param_1 + 0x168) = dVar4;
        dVar3 = dVar4;
      }
      dVar4 = 1073741824.0;
      if (1073741824.0 < dVar3) goto LAB_0011f9f8;
    }
    else {
      *(undefined8 *)(param_1 + 0x168) = 0x40f0000000000000;
      dVar4 = *pdVar1;
      iVar2 = 0xf;
      dVar3 = 65536.0;
      if (65536.0 < dVar4 * 16.0) {
        do {
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            dVar3 = *(double *)(param_1 + 0x168);
            dVar4 = pdVar1[1];
            goto LAB_0011f9d8;
          }
          dVar3 = dVar3 + dVar3;
          *(double *)(param_1 + 0x168) = dVar3;
        } while (dVar3 < *pdVar1 * 16.0);
        dVar4 = pdVar1[1];
        goto LAB_0011f9d8;
      }
      if (65536.0 <= pdVar1[1]) goto LAB_0011fa04;
      *(double *)(param_1 + 0x168) = pdVar1[1];
    }
  }
  dVar4 = *pdVar1;
LAB_0011fa04:
  if (dVar4 < 0.0) {
    xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s_unknown_unknown_00147723 /* "unknown/unknown" */));
    return;
  }
  if (1073741824.0 < pdVar1[1]) {
    xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&s___0lf_unlimited_00147733 /* "%.0lf/unlimited" */),dVar4);
    return;
  }
  xSnprintf((char *)(param_1 + 0x60),0x100,((char *)(long)&DAT_00147743 /* "%.0lf/%.0lf" */),dVar4,pdVar1[1]);
  return;
}

