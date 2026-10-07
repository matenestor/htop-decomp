#include "htop.h"

/* CommandLine_run @ 0x11d310 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CommandLine_run(int argc,char **argv)

{
  undefined1 __frame[0x348] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x308;
  Table_4 **ppTVar1;
  Vector **ppVVar2;
  long lVar3;
  ScreenSettings_5 *pSVar4;
  size_t sVar5;
  Table_4 *pTVar6;
  FunctionBar *this;
  IncSet_2 *pIVar7;
  Hashtable *this_00;
  undefined16 auVar8;
  Hashtable_2 *__ptr;
  char *__ptr_00;
  _Bool _Var9;
  int iVar10;
  __uid_t _Var11;
  int wVar12;
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
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar26;

  bVar26 = 0;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar13 = getenv(((char *)(long)&s_LC_CTYPE_00147524 /* "LC_CTYPE" */));
  if ((pcVar13 == (char *)0x0) && (pcVar13 = getenv(((char *)(long)&s_LC_ALL_0014752d /* "LC_ALL" */)), pcVar13 == (char *)0x0)) {
    pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
  }
                    /* Unresolved local var: int opt@[???] */
  setlocale(0,pcVar13);
  ppuVar22 = &PTR_DAT_0015b020;
  poVar23 = (*(option (*) [16])(__fp - 0x248));
  for (lVar19 = 0x40; lVar19 != 0; lVar19 = lVar19 + -1) {
    poVar23->name = *ppuVar22;
    ppuVar22 = ppuVar22 + (ulong)bVar26 * -2 + 1;
    poVar23 = (option *)((long)poVar23 + (ulong)bVar26 * -0x10 + 8);
  }
  (*(ulong *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 20)) = SUB1612((undefined16)0x0,4);
  (*(CommandLineSettings (*))(__fp - 0x278)).userId = 0xffffffff;
  (*(CommandLineSettings (*))(__fp - 0x278)).delay = -1;
  (*(CommandLineSettings (*))(__fp - 0x278)).iterationsRemaining = -1;
  (*(ulong *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 36)) = SUB1612((undefined16)0x0,4);
  (*(CommandLineSettings (*))(__fp - 0x278)).useColors = true;
  (*(CommandLineSettings (*))(__fp - 0x278)).enableMouse = true;
  (*(CommandLineSettings (*))(__fp - 0x278)).treeView = false;
  (*(CommandLineSettings (*))(__fp - 0x278)).allowUnicode = true;
  auVar8 = (undefined16)(*(undefined16 *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 32));
  (*(ulong *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 32)) = (*(ulong *)((char *)&auVar8 + 0));
  (*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs = -1;
  (*(undefined8 (*))(__fp - 0x2a8)) = (ulong)(*(uint (*))(__fp - 0x2a4)) << 0x20;
  (*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList = (Hashtable_2 *)0x0;
  (*(CommandLineSettings (*))(__fp - 0x278)).commFilter = (char *)0x0;
  pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
LAB_0011d3d9:
  (*(CommandLineSettings (*))(__fp - 0x278)).commFilter = pcVar13;
  va1 = (timespec_2 *)&(*(int (*))(__fp - 0x2a8));
  iVar10 = getopt_long(argc,argv,((char *)(long)&DAT_0014756e /* "hVMCs:td:n:Up:F:H::" */),(*(option (*) [16])(__fp - 0x248)),(int *)&(*(int (*))(__fp - 0x2a8)));
  __ptr_00 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
  pbVar25 = _optarg;
  pcVar20 = program;
  if (1 < iVar10 + 1U) {
    pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
    switch(iVar10) {
    case 0x43:
      (*(uchar *)((char *)&auVar8 + 0xf)) = 0;
      (*(uchar *)((char *)&auVar8 + 0)) = (*(CommandLineSettings (*))(__fp - 0x278)).enableMouse;
      (*(uchar *)((char *)&auVar8 + 1)) = (*(CommandLineSettings (*))(__fp - 0x278)).treeView;
      (*(uchar *)((char *)&auVar8 + 2)) = (*(CommandLineSettings (*))(__fp - 0x278)).allowUnicode;
      (*(uchar *)((char *)&auVar8 + 3)) = (*(CommandLineSettings (*))(__fp - 0x278)).highlightChanges;
      (*(uchar *)((char *)&auVar8 + 4)) = (*(CommandLineSettings (*))(__fp - 0x278)).field_0x25;
      (*(uchar *)((char *)&auVar8 + 5)) = (*(CommandLineSettings (*))(__fp - 0x278)).field_0x26;
      (*(uchar *)((char *)&auVar8 + 6)) = (*(CommandLineSettings (*))(__fp - 0x278)).field_0x27;
      (*(uint *)((char *)&auVar8 + 7)) = (*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs;
      (*(uchar *)((char *)&auVar8 + 0xb)) = (*(CommandLineSettings (*))(__fp - 0x278)).readonly;
      (*(uchar *)((char *)&auVar8 + 0xc)) = (*(CommandLineSettings (*))(__fp - 0x278)).field_0x2d;
      (*(uchar *)((char *)&auVar8 + 0xd)) = (*(CommandLineSettings (*))(__fp - 0x278)).field_0x2e;
      (*(uchar *)((char *)&auVar8 + 0xe)) = (*(CommandLineSettings (*))(__fp - 0x278)).field_0x2f;
      (*(undefined16 *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 32)) = auVar8 << 8;
      goto LAB_0011d3d9;
    default:
      goto switchD_0011d413_caseD_44;
    case 0x46:
      if (((*(CommandLineSettings (*))(__fp - 0x278)).commFilter == (char *)0x0) ||
         (iVar10 = strcmp((*(CommandLineSettings (*))(__fp - 0x278)).commFilter,(char *)_optarg), pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter, iVar10 != 0
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
          _optind = _optind + 1;
          goto LAB_0011d773;
        }
      }
      else {
LAB_0011d773:
        iVar10 = __isoc23_sscanf((char *)pbVar25,((char *)(long)&DAT_0014754c /* "%16d" */),&(*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs);
        auVar8 = (undefined16)(*(undefined16 *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 32));
        if (iVar10 != 1) {
          __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_highlight_delay_v_0014b108 /* "Error: invalid highlight delay value \"%s\".\n" */),pbVar25);
          goto switchD_0011d413_caseD_44;
        }
        if ((*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs < 1) {
          (*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs = 1;
          (*(uint *)((char *)&(*(CommandLineSettings (*))(__fp - 0x278)) + 32)) = (*(uint *)((char *)&auVar8 + 0));
          (*(CommandLineSettings (*))(__fp - 0x278)).highlightChanges = true;
          pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
          goto LAB_0011d3d9;
        }
      }
      (*(CommandLineSettings (*))(__fp - 0x278)).highlightChanges = true;
      pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
      goto LAB_0011d3d9;
    case 0x4d:
      (*(CommandLineSettings (*))(__fp - 0x278)).enableMouse = false;
      goto LAB_0011d3d9;
    case 0x55:
      (*(CommandLineSettings (*))(__fp - 0x278)).allowUnicode = false;
      goto LAB_0011d3d9;
    case 0x56:
      __printf_chk(2,((char *)(long)&s__s_3_3_0_00147534 /* "%s 3.3.0\n" */),program);
      break;
    case 100:
      iVar10 = __isoc23_sscanf((char *)_optarg,((char *)(long)&DAT_0014754c /* "%16d" */),&(*(CommandLineSettings (*))(__fp - 0x278)).delay);
      if (iVar10 != 1) {
        __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_delay_value___s___0014b078 /* "Error: invalid delay value \"%s\".\n" */),_optarg);
        goto switchD_0011d413_caseD_44;
      }
      pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
      if ((*(CommandLineSettings (*))(__fp - 0x278)).delay < 1) {
        (*(CommandLineSettings (*))(__fp - 0x278)).delay = 1;
      }
      else if ('d' < (*(CommandLineSettings (*))(__fp - 0x278)).delay) {
        (*(CommandLineSettings (*))(__fp - 0x278)).delay = 'd';
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
                   ,pcVar20,pcVar20);
      break;
    case 0x6e:
      iVar10 = __isoc23_sscanf((char *)_optarg,((char *)(long)&DAT_0014754c /* "%16d" */),&(*(CommandLineSettings (*))(__fp - 0x278)).iterationsRemaining);
      if (iVar10 == 1) goto code_r0x0011d628;
      __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_maximum_iteration_0014b0d8 /* "Error: invalid maximum iteration count \"%s\".\n" */),_optarg);
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
      pcVar20 = strtok_r(pcVar13,((char *)(long)&DAT_0014756c /* "," */),(char **)&(*(State (*))(__fp - 0x298)));
      if ((*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList == (Hashtable_2 *)0x0) {
        (*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList = Hashtable_new(8,false);
      }
      while (pcVar20 != (char *)0x0) {
                    /* Unresolved local var: uint num_pid@[???] */
        lVar19 = __isoc23_strtol(pcVar20,(char **)0x0,10);
        Hashtable_put((*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList,(ht_key_t)lVar19,(void *)0x1);
        pcVar20 = strtok_r((char *)0x0,((char *)(long)&DAT_0014756c /* "," */),(char **)&(*(State (*))(__fp - 0x298)));
      }
      free(pcVar13);
      pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
      goto LAB_0011d3d9;
    case 0x73:
      iVar10 = strcmp((char *)_optarg,((char *)(long)&DAT_0014753e /* "help" */));
      if (iVar10 == 0) {
        (*(int (*))(__fp - 0x2b8)) = 0;
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: char * description@[???] */
        pPVar21 = Process_fields + 1;
        do {
          if (pPVar21->name != (char *)0x0) {
            __printf_chk(2,((char *)(long)&s__19s__s_00147543 /* "%19s %s\n" */),pPVar21->name,pPVar21->description);
          }
          pPVar21 = pPVar21 + 1;
        } while (pPVar21 != (ProcessFieldData *)MetersMovingKeys);
        goto LAB_0011d44a;
      }
                    /* Unresolved local var: int j@[???] */
      wVar12 = 1;
      (*(CommandLineSettings (*))(__fp - 0x278)).sortKey = 0;
      pPVar21 = Process_fields;
      while ((pPVar21 = pPVar21 + 1, pPVar21->name == (char *)0x0 ||
             (iVar10 = strcmp((char *)pbVar25,pPVar21->name), iVar10 != 0))) {
        wVar12 = wVar12 + 1;
        if (wVar12 == 132) {
          __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_column___s___00147585 /* "Error: invalid column \"%s\".\n" */),pbVar25);
          goto switchD_0011d413_caseD_44;
        }
      }
      (*(CommandLineSettings (*))(__fp - 0x278)).sortKey = wVar12;
      pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
      goto LAB_0011d3d9;
    case 0x74:
      (*(CommandLineSettings (*))(__fp - 0x278)).treeView = true;
      goto LAB_0011d3d9;
    case 0x75:
                    /* Unresolved local var: char * username@[???] */
      if (_optarg == (byte *)0x0) {
        if ((((argc <= _optind) || (pbVar25 = (byte *)argv[_optind], pbVar25 == (byte *)0x0)) ||
            (*pbVar25 == 0)) || (*pbVar25 == 0x2d)) {
          _Var11 = geteuid();
          (*(CommandLineSettings (*))(__fp - 0x278)).userId = _Var11;
          pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
          goto LAB_0011d3d9;
        }
        _optind = _optind + 1;
      }
                    /* Unresolved local var: passwd * user@[???] */
      ppVar14 = getpwnam((char *)pbVar25);
      if (ppVar14 == (passwd *)0x0) {
        (*(CommandLineSettings (*))(__fp - 0x278)).userId = 0xffffffff;
                    /* Unresolved local var: char * itr@[???] */
        bVar26 = *pbVar25;
        if (bVar26 != 0) {
          ppuVar17 = __ctype_b_loc();
          pbVar18 = pbVar25;
          do {
            if ((*(byte *)((long)*ppuVar17 + (ulong)bVar26 * 2 + 1) & 8) == 0) {
              __fprintf_chk(_stderr,2,((char *)(long)&s_Error__invalid_user___s___00147551 /* "Error: invalid user \"%s\".\n" */),pbVar25);
              goto switchD_0011d413_caseD_44;
            }
            bVar26 = pbVar18[1];
            pbVar18 = pbVar18 + 1;
          } while (bVar26 != 0);
        }
        lVar19 = __isoc23_strtol((char *)pbVar25,(char **)0x0,10);
        (*(CommandLineSettings (*))(__fp - 0x278)).userId = (uid_t)lVar19;
        pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
      }
      else {
        (*(CommandLineSettings (*))(__fp - 0x278)).userId = ppVar14->pw_uid;
        pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
      }
      goto LAB_0011d3d9;
    case 0x80:
      (*(CommandLineSettings (*))(__fp - 0x278)).readonly = true;
      goto LAB_0011d3d9;
    }
    (*(int (*))(__fp - 0x2b8)) = 0;
    goto LAB_0011d44a;
  }
  if (_optind < argc) {
    __fprintf_chk(_stderr,2,((char *)(long)&s_Error__unsupported_non_option_AR_0014b138 /* "Error: unsupported non-option ARGV-elements:" */));
    while (_optind < argc) {
      lVar19 = (long)_optind;
      _optind = _optind + 1;
      __fprintf_chk(_stderr,2,((char *)(long)(__sec_rodata + 0x625) /* " %s" */),argv[lVar19]);
    }
    __fprintf_chk(_stderr,2,((char *)(long)&DAT_00147506 /* "\n" */));
    goto switchD_0011d413_caseD_44;
  }
  if ((*(CommandLineSettings (*))(__fp - 0x278)).readonly != false) {
    readonly = true;
  }
  iVar10 = access(((char *)(long)&s__proc_00149a78 /* "/proc" */),4);
  if (iVar10 != 0) {
                    /* Unresolved local var: char[4096] target@[???]
                       Unresolved local var: ssize_t ret@[???]
                       Unresolved local var: FILE * fd@[???] */
    __fprintf_chk(_stderr,2,((char *)(long)&s_Error__could_not_read_procfs__co_0014b168 /* "Error: could not read procfs (compiled to look in %s).\n" */),((char *)(long)&s__proc_00149a78 /* "/proc" */));
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
  super = (LinuxMachine_ *)Machine_new(usersTable,(*(CommandLineSettings (*))(__fp - 0x278)).userId);
  processTable = ProcessTable_new((Machine_2 *)super,(*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList);
  settings = (Settings *)
             Settings_new((super->super).activeCPUs,(Hashtable_2 *)0x0,pHVar15,(Hashtable_2 *)0x0);
  Machine_populateTablesFromSettings((Machine *)super,(Settings_4 *)settings,&processTable->super);
  header = Header_new((Machine_2 *)super,HF_TWO_67_33);
  Header_populateFromSettings((Header *)header);
  if ((*(CommandLineSettings (*))(__fp - 0x278)).delay != -1) {
    settings->delay = (*(CommandLineSettings (*))(__fp - 0x278)).delay;
  }
  if ((*(CommandLineSettings (*))(__fp - 0x278)).useColors == false) {
    settings->colorScheme = 1;
  }
  if ((*(CommandLineSettings (*))(__fp - 0x278)).enableMouse == false) {
    settings->enableMouse = false;
  }
  if ((*(CommandLineSettings (*))(__fp - 0x278)).treeView != false) {
    settings->ss->treeView = true;
  }
  if ((*(CommandLineSettings (*))(__fp - 0x278)).highlightChanges != false) {
    settings->highlightChanges = true;
  }
  if ((*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs != -1) {
    settings->highlightDelaySecs = (*(CommandLineSettings (*))(__fp - 0x278)).highlightDelaySecs;
  }
  if (0 < (*(CommandLineSettings (*))(__fp - 0x278)).sortKey) {
    pSVar4 = settings->ss;
    _Var9 = Process_fields[(*(CommandLineSettings (*))(__fp - 0x278)).sortKey].defaultSortDesc;
    if ((((*(CommandLineSettings (*))(__fp - 0x278)).treeView == false) || (pSVar4->treeViewAlwaysByPID != false)) ||
       (pSVar4->treeView == false)) {
      pSVar4->sortKey = (*(CommandLineSettings (*))(__fp - 0x278)).sortKey;
      pSVar4->treeView = false;
      pSVar4->direction = (-(uint)(_Var9 == false) & 2) + -1;
    }
    else {
      pSVar4->treeSortKey = (*(CommandLineSettings (*))(__fp - 0x278)).sortKey;
      pSVar4->treeDirection = (-(uint)(_Var9 == false) & 2) + -1;
    }
  }
  (super->super).iterationsRemaining = (long)(*(CommandLineSettings (*))(__fp - 0x278)).iterationsRemaining;
  CRT_init(settings,(*(CommandLineSettings (*))(__fp - 0x278)).allowUnicode,(*(CommandLineSettings (*))(__fp - 0x278)).iterationsRemaining != -1);
  item = MainPanel_new();
  pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
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
  pcVar20 = ((char *)(long)&s_Tree_0014750f /* "Tree  " */);
  if (settings->ss->treeView != false) {
    pcVar20 = ((char *)(long)&s_List_00147508 /* "List  " */);
  }
  FunctionBar_setLabel(this,269,pcVar20);
  pcVar20 = ((char *)(long)&s_Filter_0014751d /* "Filter" */);
  if (pcVar13 != (char *)0x0) {
    pcVar20 = ((char *)(long)&s_FILTER_00147516 /* "FILTER" */);
  }
  FunctionBar_setLabel(this,268,pcVar20);
  (*(State (*))(__fp - 0x298)).pauseUpdate = false;
  (*(State (*))(__fp - 0x298)).hideSelection = false;
  (*(State (*))(__fp - 0x298)).hideMeters = false;
  item->state = &(*(State (*))(__fp - 0x298));
  (*(State (*))(__fp - 0x298)).host = (Machine_2 *)super;
  (*(State (*))(__fp - 0x298)).mainPanel = item;
  (*(State (*))(__fp - 0x298)).header = header;
  if ((*(CommandLineSettings (*))(__fp - 0x278)).commFilter != (char *)0x0) {
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
      if ((*(CommandLineSettings (*))(__fp - 0x278)).commFilter[lVar19] == '\0') {
        wVar12 = (int)lVar19;
        goto LAB_0011db09;
      }
      pIVar7->modes[1].buffer[lVar19] = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter[lVar19];
      lVar19 = lVar19 + 1;
    } while (lVar19 != 0x80);
    wVar12 = 128;
LAB_0011db09:
    pIVar7->modes[1].buffer[lVar19] = '\0';
    pIVar7->modes[1].index = wVar12;
    pIVar7->filtering = true;
    pTVar6->incFilter = in_R9->buffer;
    free((*(CommandLineSettings (*))(__fp - 0x278)).commFilter);
    (*(CommandLineSettings (*))(__fp - 0x278)).commFilter = (char *)0x0;
  }
  this_01 = (ScreenManager *)ScreenManager_new(header,(Machine_2 *)super,&(*(State (*))(__fp - 0x298)),true);
  ScreenManager_insert(this_01,&item->super,-1,this_01->panels->items);
  Machine_scan(super);
  Machine_scanTables((Machine *)super);
  (*(undefined8 (*))(__fp - 0x2a8)) = 0;
  (*(long (*))(__fp - 0x2a0)) = 75000000;
  do {
    iVar10 = nanosleep((timespec_2 *)&(*(int (*))(__fp - 0x2a8)),(timespec_2 *)&(*(int (*))(__fp - 0x2a8)));
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
  ScreenManager_run(this_01,(Panel **)0x0,(int *)0x0,(char *)0x0);
  if (dlopenHandle != (void *)0x0) {
    (*(code *)(sym_sensors_cleanup))((long)a0,lVar19,a2,(long)pcVar13,(long)va1,(long)in_R9);
    dlclose(dlopenHandle);
    dlopenHandle = (void *)0x0;
  }
  CRT_done();
  if (settings->changed != false) {
                    /* Unresolved local var: int r@[???] */
    lVar19 = 0;
    wVar12 = Settings_write(settings,false);
    if (wVar12 < 0) {
      va1 = (timespec_2 *)strerror(-wVar12);
      pcVar13 = settings->filename;
      lVar19 = 2;
      __fprintf_chk(_stderr,2,((char *)(long)&s_Can_not_save_configuration_to__s_0014b1a0 /* "Can not save configuration to %s: %s\n" */),pcVar13,va1);
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
  (*(code *)(((pTVar6->super).klass)->delete))
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
  __ptr = (*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList;
  if ((*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList != (Hashtable_2 *)0x0) {
    Hashtable_clear((*(CommandLineSettings (*))(__fp - 0x278)).pidMatchList);
    free(__ptr->buckets);
    free(__ptr);
  }
  CRT_resetSignalHandlers();
  Settings_delete(settings);
  (*(int (*))(__fp - 0x2b8)) = 0;
  if (pHVar15 != (Hashtable *)0x0) {
    Hashtable_clear(pHVar15);
    free(pHVar15->buckets);
    free(pHVar15);
  }
  goto LAB_0011d44a;
code_r0x0011d628:
  pcVar13 = (*(CommandLineSettings (*))(__fp - 0x278)).commFilter;
  if ((*(CommandLineSettings (*))(__fp - 0x278)).iterationsRemaining < 1) {
    __fprintf_chk(_stderr,2,((char *)(long)&s_Error__maximum_iteration_count_m_0014b0a0 /* "Error: maximum iteration count must be positive.\n" */));
switchD_0011d413_caseD_44:
    (*(int (*))(__fp - 0x2b8)) = 1;
LAB_0011d44a:
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return (*(int (*))(__fp - 0x2b8));
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  goto LAB_0011d3d9;
}

