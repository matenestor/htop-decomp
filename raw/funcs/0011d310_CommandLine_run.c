/* CommandLine_run @ 0011d310 size 3401 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

wchar_t CommandLine_run(wchar_t argc,char **argv)

{
  Table_4 **ppTVar1;
  Vector **ppVVar2;
  long lVar3;
  ScreenSettings_5 *pSVar4;
  size_t sVar5;
  Table_4 *pTVar6;
  FunctionBar *this;
  IncSet_2 *pIVar7;
  Hashtable *this_00;
  undefined1 auVar8 [16];
  Hashtable_2 *__ptr;
  char *__ptr_00;
  _Bool _Var9;
  int iVar10;
  __uid_t _Var11;
  wchar_t wVar12;
  char *pcVar13;
  passwd *ppVar14;
  UsersTable *usersTable;
  Hashtable *pHVar15;
  LinuxMachine_ *super;
  ProcessTable_2 *processTable;
  Settings *settings;
  Header_4 *header;
  MainPanel *item;
  Table_4 **ppTVar16;
  ScreenManager *this_01;
  ushort **ppuVar17;
  byte *pbVar18;
  timespec_2 *va1;
  long lVar19;
  char *pcVar20;
  long a2;
  long a2_00;
  ProcessFieldData *pPVar21;
  undefined **ppuVar22;
  option *poVar23;
  ScreenManager *a0;
  IncMode *in_R9;
  ulong uVar24;
  byte *pbVar25;
  long in_FS_OFFSET;
  byte bVar26;
  wchar_t local_2b8;
  wchar_t opti;
  uint uStack_2a4;
  long lStack_2a0;
  State state;
  CommandLineSettings flags;
  option long_opts [16];

  bVar26 = 0;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar13 = getenv(((char *)0x147524 /* "LC_CTYPE" */));
  if ((pcVar13 == (char *)0x0) && (pcVar13 = getenv(((char *)0x14752d /* "LC_ALL" */)), pcVar13 == (char *)0x0)) {
    pcVar13 = ((char *)0x149c0c /* "" */);
  }
                    /* Unresolved local var: wchar_t opt@[???] */
  setlocale(0,pcVar13);
  ppuVar22 = &PTR_DAT_0015b020;
  poVar23 = long_opts;
  for (lVar19 = 0x40; lVar19 != 0; lVar19 = lVar19 + -1) {
    poVar23->name = *ppuVar22;
    ppuVar22 = ppuVar22 + (ulong)bVar26 * -2 + 1;
    poVar23 = (option *)((long)poVar23 + (ulong)bVar26 * -0x10 + 8);
  }
  flags._20_12_ = SUB1612((undefined1  [16])0x0,4);
  flags.userId = 0xffffffff;
  flags.delay = L'\xffffffff';
  flags.iterationsRemaining = L'\xffffffff';
  flags._36_12_ = SUB1612((undefined1  [16])0x0,4);
  flags.useColors = true;
  flags.enableMouse = true;
  flags.treeView = false;
  flags.allowUnicode = true;
  auVar8 = (undefined1  [16])flags._32_16_;
  flags._32_8_ = auVar8._0_8_;
  flags.highlightDelaySecs = L'\xffffffff';
  _opti = (ulong)uStack_2a4 << 0x20;
  flags.pidMatchList = (Hashtable_2 *)0x0;
  flags.commFilter = (char *)0x0;
  pcVar13 = flags.commFilter;
LAB_0011d3d9:
  flags.commFilter = pcVar13;
  va1 = (timespec_2 *)&opti;
  iVar10 = getopt_long(argc,argv,((char *)0x14756e /* "hVMCs:td:n:u::Up:F:H::" */),long_opts,(int *)&opti);
  __ptr_00 = flags.commFilter;
  pbVar25 = _optarg;
  pcVar20 = program;
  if (1 < iVar10 + 1U) {
    pcVar13 = flags.commFilter;
    switch(iVar10) {
    case 0x43:
      auVar8[0xf] = 0;
      auVar8[0] = flags.enableMouse;
      auVar8[1] = flags.treeView;
      auVar8[2] = flags.allowUnicode;
      auVar8[3] = flags.highlightChanges;
      auVar8[4] = flags.field_0x25;
      auVar8[5] = flags.field_0x26;
      auVar8[6] = flags.field_0x27;
      auVar8._7_4_ = flags.highlightDelaySecs;
      auVar8[0xb] = flags.readonly;
      auVar8[0xc] = flags.field_0x2d;
      auVar8[0xd] = flags.field_0x2e;
      auVar8[0xe] = flags.field_0x2f;
      flags._32_16_ = auVar8 << 8;
      goto LAB_0011d3d9;
    default:
      goto switchD_0011d413_caseD_44;
    case 0x46:
      if ((flags.commFilter == (char *)0x0) ||
         (iVar10 = strcmp(flags.commFilter,(char *)_optarg), pcVar13 = flags.commFilter, iVar10 != 0
         )) {
        free(__ptr_00);
                    /* Unresolved local var: char * data@[???] */
        pcVar13 = strdup((char *)pbVar25);
        if (pcVar13 == (char *)0x0) goto LAB_0011e0f1;
      }
      goto LAB_0011d3d9;
    case 0x48:
                    /* Unresolved local var: char * delay@[???] */
      if (_optarg == (byte *)0x0) {
        if (((_optind < argc) && (pbVar25 = (byte *)argv[_optind], pbVar25 != (byte *)0x0)) &&
           ((*pbVar25 != 0 && (*pbVar25 != 0x2d)))) {
          _optind = _optind + L'\x01';
          goto LAB_0011d773;
        }
      }
      else {
LAB_0011d773:
        iVar10 = __isoc23_sscanf((char *)pbVar25,((char *)0x14754c /* "%16d" */),&flags.highlightDelaySecs);
        auVar8 = (undefined1  [16])flags._32_16_;
        if (iVar10 != 1) {
          __fprintf_chk(_stderr,2,((char *)0x14b108 /* "Error: invalid highlight delay value \"%s\".\n" */),pbVar25);
          goto switchD_0011d413_caseD_44;
        }
        if (flags.highlightDelaySecs < L'\x01') {
          flags.highlightDelaySecs = L'\x01';
          flags._32_4_ = auVar8._0_4_;
          flags.highlightChanges = true;
          pcVar13 = flags.commFilter;
          goto LAB_0011d3d9;
        }
      }
      flags.highlightChanges = true;
      pcVar13 = flags.commFilter;
      goto LAB_0011d3d9;
    case 0x4d:
      flags.enableMouse = false;
      goto LAB_0011d3d9;
    case 0x55:
      flags.allowUnicode = false;
      goto LAB_0011d3d9;
    case 0x56:
      __printf_chk(2,((char *)0x147534 /* "%s 3.3.0\n" */),program);
      break;
    case 100:
      iVar10 = __isoc23_sscanf((char *)_optarg,((char *)0x14754c /* "%16d" */),&flags.delay);
      if (iVar10 != 1) {
        __fprintf_chk(_stderr,2,((char *)0x14b078 /* "Error: invalid delay value \"%s\".\n" */),_optarg);
        goto switchD_0011d413_caseD_44;
      }
      pcVar13 = flags.commFilter;
      if (flags.delay < L'\x01') {
        flags.delay = L'\x01';
      }
      else if (L'd' < flags.delay) {
        flags.delay = L'd';
      }
      goto LAB_0011d3d9;
    case 0x68:
      __printf_chk(2,
                   ((char *)0x14abe0 /* "%s 3.3.0\n(C) 2004-2019 Hisham Muhammad. (C) 2020-2024 htop dev team.\nReleased under the GNU GPLv2+.\n\n-C --no-color                   Use a monochrome color scheme\n-d --delay=DELAY                Set the delay between updates, in tenths of seconds\n-F --filter=FILTER              Show only the commands matching the given filter\n-h --help                       Print this help screen\n-H --highlight-changes[=DELAY]  Highlight new and old processes\n" */)
                   ,program);
      __printf_chk(2,((char *)0x14ada0 /* "-M --no-mouse                   Disable the mouse\n" */));
      __printf_chk(2,
                   ((char *)0x14add8 /* "-n --max-iterations=NUMBER      Exit htop after NUMBER iterations/frame updates\n-p --pid=PID[,PID,PID...]       Show only the given PIDs\n   --readonly                   Disable all system and process changing features\n-s --sort-key=COLUMN            Sort by COLUMN in list view (try --sort-key=help for a list)\n-t --tree                       Show the tree view (can be combined with -s)\n-u --user[=USERNAME]            Show only processes for a given user (or $USER)\n-U --no-unicode                 Do not use unicode but plain ASCII\n-V --version                    Print version info\n" */)
                  );
      __printf_chk(2,((char *)0x14b028 /* "\nPress F1 inside %s for online help.\nSee \'man %s\' for more information.\n" */)
                   ,pcVar20,pcVar20);
      break;
    case 0x6e:
      iVar10 = __isoc23_sscanf((char *)_optarg,((char *)0x14754c /* "%16d" */),&flags.iterationsRemaining);
      if (iVar10 == 1) goto code_r0x0011d628;
      __fprintf_chk(_stderr,2,((char *)0x14b0d8 /* "Error: invalid maximum iteration count \"%s\".\n" */),_optarg);
      goto switchD_0011d413_caseD_44;
    case 0x70:
                    /* Unresolved local var: char * argCopy@[???]
                       Unresolved local var: char * pid@[???]
                       Unresolved local var: char * data@[???] */
      pcVar13 = strdup((char *)_optarg);
      if (pcVar13 == (char *)0x0) {
LAB_0011e0f1:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      pcVar20 = strtok_r(pcVar13,((char *)0x14756c /* "," */),(char **)&state);
      if (flags.pidMatchList == (Hashtable_2 *)0x0) {
        flags.pidMatchList = Hashtable_new(8,false);
      }
      while (pcVar20 != (char *)0x0) {
                    /* Unresolved local var: uint num_pid@[???] */
        lVar19 = __isoc23_strtol(pcVar20,(char **)0x0,10);
        Hashtable_put(flags.pidMatchList,(ht_key_t)lVar19,(void *)0x1);
        pcVar20 = strtok_r((char *)0x0,((char *)0x14756c /* "," */),(char **)&state);
      }
      free(pcVar13);
      pcVar13 = flags.commFilter;
      goto LAB_0011d3d9;
    case 0x73:
      iVar10 = strcmp((char *)_optarg,((char *)0x14753e /* "help" */));
      if (iVar10 == 0) {
        local_2b8 = L'\0';
                    /* Unresolved local var: wchar_t j@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: char * description@[???] */
        pPVar21 = Process_fields + 1;
        do {
          if (pPVar21->name != (char *)0x0) {
            __printf_chk(2,((char *)0x147543 /* "%19s %s\n" */),pPVar21->name,pPVar21->description);
          }
          pPVar21 = pPVar21 + 1;
        } while (pPVar21 != (ProcessFieldData *)MetersMovingKeys);
        goto LAB_0011d44a;
      }
                    /* Unresolved local var: wchar_t j@[???] */
      wVar12 = L'\x01';
      flags.sortKey = L'\0';
      pPVar21 = Process_fields;
      while ((pPVar21 = pPVar21 + 1, pPVar21->name == (char *)0x0 ||
             (iVar10 = strcmp((char *)pbVar25,pPVar21->name), iVar10 != 0))) {
        wVar12 = wVar12 + L'\x01';
        if (wVar12 == L'\x84') {
          __fprintf_chk(_stderr,2,((char *)0x147585 /* "Error: invalid column \"%s\".\n" */),pbVar25);
          goto switchD_0011d413_caseD_44;
        }
      }
      flags.sortKey = wVar12;
      pcVar13 = flags.commFilter;
      goto LAB_0011d3d9;
    case 0x74:
      flags.treeView = true;
      goto LAB_0011d3d9;
    case 0x75:
                    /* Unresolved local var: char * username@[???] */
      if (_optarg == (byte *)0x0) {
        if ((((argc <= _optind) || (pbVar25 = (byte *)argv[_optind], pbVar25 == (byte *)0x0)) ||
            (*pbVar25 == 0)) || (*pbVar25 == 0x2d)) {
          _Var11 = geteuid();
          flags.userId = _Var11;
          pcVar13 = flags.commFilter;
          goto LAB_0011d3d9;
        }
        _optind = _optind + L'\x01';
      }
                    /* Unresolved local var: passwd * user@[???] */
      ppVar14 = getpwnam((char *)pbVar25);
      if (ppVar14 == (passwd *)0x0) {
        flags.userId = 0xffffffff;
                    /* Unresolved local var: char * itr@[???] */
        bVar26 = *pbVar25;
        if (bVar26 != 0) {
          ppuVar17 = __ctype_b_loc();
          pbVar18 = pbVar25;
          do {
            if ((*(byte *)((long)*ppuVar17 + (ulong)bVar26 * 2 + 1) & 8) == 0) {
              __fprintf_chk(_stderr,2,((char *)0x147551 /* "Error: invalid user \"%s\".\n" */),pbVar25);
              goto switchD_0011d413_caseD_44;
            }
            bVar26 = pbVar18[1];
            pbVar18 = pbVar18 + 1;
          } while (bVar26 != 0);
        }
        lVar19 = __isoc23_strtol((char *)pbVar25,(char **)0x0,10);
        flags.userId = (uid_t)lVar19;
        pcVar13 = flags.commFilter;
      }
      else {
        flags.userId = ppVar14->pw_uid;
        pcVar13 = flags.commFilter;
      }
      goto LAB_0011d3d9;
    case 0x80:
      flags.readonly = true;
      goto LAB_0011d3d9;
    }
    local_2b8 = L'\0';
    goto LAB_0011d44a;
  }
  if (_optind < argc) {
    __fprintf_chk(_stderr,2,((char *)0x14b138 /* "Error: unsupported non-option ARGV-elements:" */));
    while (_optind < argc) {
      lVar19 = (long)_optind;
      _optind = _optind + L'\x01';
      __fprintf_chk(_stderr,2,((char *)0x147625 /* " %s" */),argv[lVar19]);
    }
    __fprintf_chk(_stderr,2,((char *)0x147506 /* "\n" */));
    goto switchD_0011d413_caseD_44;
  }
  if (flags.readonly != false) {
    readonly = true;
  }
  iVar10 = access(((char *)0x149a78 /* "/proc" */),4);
  if (iVar10 != 0) {
                    /* Unresolved local var: char[4096] target@[???]
                       Unresolved local var: ssize_t ret@[???]
                       Unresolved local var: FILE * fd@[???] */
    __fprintf_chk(_stderr,2,((char *)0x14b168 /* "Error: could not read procfs (compiled to look in %s).\n" */),((char *)0x149a78 /* "/proc" */));
    goto switchD_0011d413_caseD_44;
  }
  _Var9 = Platform_init();
  if (!_Var9) goto switchD_0011d413_caseD_44;
                    /* Unresolved local var: UsersTable * this@[???]
                       Unresolved local var: void * data@[???] */
  usersTable = malloc(8);
  if (usersTable == (UsersTable *)0x0) goto LAB_0011e0f1;
  pHVar15 = Hashtable_new(10,true);
                    /* Unresolved local var: Hashtable * dynamics@[???] */
  usersTable->users = pHVar15;
  pHVar15 = Hashtable_new(0,true);
  super = (LinuxMachine_ *)Machine_new(usersTable,flags.userId);
  processTable = ProcessTable_new((Machine_2 *)super,flags.pidMatchList);
  settings = (Settings *)
             Settings_new((super->super).activeCPUs,(Hashtable_2 *)0x0,pHVar15,(Hashtable_2 *)0x0);
  Machine_populateTablesFromSettings((Machine *)super,(Settings_4 *)settings,&processTable->super);
  header = Header_new((Machine_2 *)super,HF_TWO_67_33);
  Header_populateFromSettings((Header *)header);
  if (flags.delay != L'\xffffffff') {
    settings->delay = flags.delay;
  }
  if (flags.useColors == false) {
    settings->colorScheme = L'\x01';
  }
  if (flags.enableMouse == false) {
    settings->enableMouse = false;
  }
  if (flags.treeView != false) {
    settings->ss->treeView = true;
  }
  if (flags.highlightChanges != false) {
    settings->highlightChanges = true;
  }
  if (flags.highlightDelaySecs != L'\xffffffff') {
    settings->highlightDelaySecs = flags.highlightDelaySecs;
  }
  if (L'\0' < flags.sortKey) {
    pSVar4 = settings->ss;
    _Var9 = Process_fields[flags.sortKey].defaultSortDesc;
    if (((flags.treeView == false) || (pSVar4->treeViewAlwaysByPID != false)) ||
       (pSVar4->treeView == false)) {
      pSVar4->sortKey = flags.sortKey;
      pSVar4->treeView = false;
      pSVar4->direction = (-(uint)(_Var9 == false) & 2) + L'\xffffffff';
    }
    else {
      pSVar4->treeSortKey = flags.sortKey;
      pSVar4->treeDirection = (-(uint)(_Var9 == false) & 2) + L'\xffffffff';
    }
  }
  (super->super).iterationsRemaining = (long)flags.iterationsRemaining;
  CRT_init(settings,flags.allowUnicode,flags.iterationsRemaining != L'\xffffffff');
  item = MainPanel_new();
  pcVar13 = flags.commFilter;
                    /* Unresolved local var: size_t i@[???] */
  sVar5 = (super->super).tableCount;
  if (sVar5 != 0) {
    ppTVar16 = (super->super).tables;
    ppTVar1 = ppTVar16 + sVar5;
    do {
      pTVar6 = *ppTVar16;
      ppTVar16 = ppTVar16 + 1;
      pTVar6->panel = &item->super;
    } while (ppTVar16 != ppTVar1);
  }
                    /* Unresolved local var: FunctionBar * bar@[???] */
  this = (item->super).defaultBar;
  pcVar20 = ((char *)0x14750f /* "Tree  " */);
  if (settings->ss->treeView != false) {
    pcVar20 = ((char *)0x147508 /* "List  " */);
  }
  FunctionBar_setLabel(this,L'č',pcVar20);
  pcVar20 = ((char *)0x14751d /* "Filter" */);
  if (pcVar13 != (char *)0x0) {
    pcVar20 = ((char *)0x147516 /* "FILTER" */);
  }
  FunctionBar_setLabel(this,L'Č',pcVar20);
  state.pauseUpdate = false;
  state.hideSelection = false;
  state.hideMeters = false;
  item->state = &state;
  state.host = (Machine_2 *)super;
  state.mainPanel = item;
  state.header = header;
  if (flags.commFilter != (char *)0x0) {
                    /* Unresolved local var: Table * table@[???]
                       Unresolved local var: IncSet * inc@[???] */
    pIVar7 = item->inc;
    pTVar6 = (super->super).activeTable;
                    /* Unresolved local var: IncMode * mode@[???]
                       Unresolved local var: size_t len@[???]
                       Unresolved local var: size_t i@[???] */
    lVar19 = 0;
    in_R9 = pIVar7->modes + 1;
    do {
      if (flags.commFilter[lVar19] == '\0') {
        wVar12 = (wchar_t)lVar19;
        goto LAB_0011db09;
      }
      pIVar7->modes[1].buffer[lVar19] = flags.commFilter[lVar19];
      lVar19 = lVar19 + 1;
    } while (lVar19 != 0x80);
    wVar12 = L'\x80';
LAB_0011db09:
    pIVar7->modes[1].buffer[lVar19] = '\0';
    pIVar7->modes[1].index = wVar12;
    pIVar7->filtering = true;
    pTVar6->incFilter = in_R9->buffer;
    free(flags.commFilter);
    flags.commFilter = (char *)0x0;
  }
  this_01 = (ScreenManager *)ScreenManager_new(header,(Machine_2 *)super,&state,true);
  ScreenManager_insert(this_01,&item->super,L'\xffffffff',this_01->panels->items);
  Machine_scan(super);
  Machine_scanTables((Machine *)super);
  _opti = 0;
  lStack_2a0 = 75000000;
  do {
    iVar10 = nanosleep((timespec_2 *)&opti,(timespec_2 *)&opti);
  } while (iVar10 == -1);
  Generic_gettime_realtime(&(super->super).realtime,&(super->super).realtimeMs);
  Machine_scan(super);
  Machine_scanTables((Machine *)super);
  if (settings->ss->allBranchesCollapsed != false) {
    Table_collapseAllBranches((Table *)processTable);
  }
  pcVar13 = (char *)0x0;
  lVar19 = 0;
  a0 = this_01;
  ScreenManager_run(this_01,(Panel **)0x0,(wchar_t *)0x0,(char *)0x0);
  if (dlopenHandle != (void *)0x0) {
    (*sym_sensors_cleanup)((long)a0,lVar19,a2,(long)pcVar13,(long)va1,(long)in_R9);
    dlclose(dlopenHandle);
    dlopenHandle = (void *)0x0;
  }
  CRT_done();
  if (settings->changed != false) {
                    /* Unresolved local var: wchar_t r@[???] */
    lVar19 = 0;
    wVar12 = Settings_write(settings,false);
    if (wVar12 < L'\0') {
      va1 = (timespec_2 *)strerror(-wVar12);
      pcVar13 = settings->filename;
      lVar19 = 2;
      __fprintf_chk(_stderr,2,((char *)0x14b1a0 /* "Can not save configuration to %s: %s\n" */),pcVar13,va1);
    }
  }
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  uVar24 = 0;
  bVar26 = HeaderLayout_layouts[header->headerLayout].columns;
  if ((ulong)bVar26 != 0) {
    do {
      ppVVar2 = header->columns + uVar24;
      uVar24 = uVar24 + 1;
      Vector_delete(*ppVVar2);
    } while (bVar26 != uVar24);
  }
  free(header->columns);
  free(header);
                    /* Unresolved local var: LinuxMachine * this@[???] */
  pTVar6 = (super->super).processTable;
  (*((pTVar6->super).klass)->delete)
            (&pTVar6->super,lVar19,a2_00,(long)pcVar13,(long)va1,(long)in_R9);
  free((super->super).tables);
  free(super->cpuData);
  free(super);
  Vector_delete(this_01->panels);
  free(this_01);
  if (Meters_movingBar != (FunctionBar *)0x0) {
    FunctionBar_delete(Meters_movingBar);
    Meters_movingBar = (FunctionBar *)0x0;
  }
  this_00 = usersTable->users;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  free(usersTable);
  __ptr = flags.pidMatchList;
  if (flags.pidMatchList != (Hashtable_2 *)0x0) {
    Hashtable_clear(flags.pidMatchList);
    free(__ptr->buckets);
    free(__ptr);
  }
  CRT_resetSignalHandlers();
  Settings_delete(settings);
  local_2b8 = L'\0';
  if (pHVar15 != (Hashtable *)0x0) {
    Hashtable_clear(pHVar15);
    free(pHVar15->buckets);
    free(pHVar15);
  }
  goto LAB_0011d44a;
code_r0x0011d628:
  pcVar13 = flags.commFilter;
  if (flags.iterationsRemaining < L'\x01') {
    __fprintf_chk(_stderr,2,((char *)0x14b0a0 /* "Error: maximum iteration count must be positive.\n" */));
switchD_0011d413_caseD_44:
    local_2b8 = L'\x01';
LAB_0011d44a:
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return local_2b8;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  goto LAB_0011d3d9;
}

