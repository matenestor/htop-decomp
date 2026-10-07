/* Settings_read @ 001373f0 size 4406 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: _Bool Settings_read(Settings * this, char * fileName, uint
   initialCpuCount) */

_Bool Settings_read(Settings *this,char *fileName,uint initialCpuCount)

{
  byte *p0;
  size_t sVar1;
  bool bVar2;
  bool bVar3;
  _Bool _Var4;
  int iVar5;
  wchar_t wVar6;
  FILE_2 *__stream;
  char *pcVar7;
  char **ppcVar8;
  long lVar9;
  ushort **ppuVar10;
  MeterColumnSetting *pMVar11;
  ScreenSettings_5 *ss;
  ulong uVar12;
  size_t sVar13;
  char **ppcVar14;
  anon_struct_24_4_85c7b288 *paVar15;
  long in_FS_OFFSET;
  HeaderLayout local_80;
  size_t nOptions;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  long local_40;

                    /* Unresolved local var: FILE * fd@[???]
                       Unresolved local var: ScreenSettings * screen@[???]
                       Unresolved local var: _Bool didReadMeters@[???]
                       Unresolved local var: _Bool didReadAny@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(fileName,((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
LAB_001376b2:
    _Var4 = false;
    goto LAB_001376b4;
  }
  bVar2 = false;
  _Var4 = false;
  ss = (ScreenSettings_5 *)0x0;
                    /* Unresolved local var: char * line@[???]
                       Unresolved local var: char * * option@[???] */
  while (pcVar7 = String_readLine((FILE *)__stream), pcVar7 != (char *)0x0) {
    ppcVar8 = String_split(pcVar7,'=',&nOptions);
    free(pcVar7);
    if (1 < nOptions) {
      pcVar7 = *ppcVar8;
      iVar5 = strcmp(pcVar7,((char *)0x1491c7 /* "config_reader_min_version" */));
      ppcVar14 = ppcVar8;
      if (iVar5 != 0) {
        iVar5 = strcmp(pcVar7,((char *)0x1491e1 /* "fields" */));
        if ((iVar5 == 0) && (this->config_version < L'\x03')) {
          if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
            Settings_newScreen(this,Platform_defaultScreens);
            Settings_newScreen(this,Platform_defaultScreens + 1);
            ss = *this->screens;
          }
          else {
            ss = *this->screens;
          }
          ScreenSettings_readFields((ScreenSettings_4 *)ss,this->dynamicColumns,ppcVar8[1]);
LAB_001375c0:
                    /* Unresolved local var: size_t i@[???] */
          pcVar7 = *ppcVar8;
          if (pcVar7 == (char *)0x0) goto LAB_001375e2;
        }
        else {
          iVar5 = strcmp(pcVar7,((char *)0x148f2a /* "sort_key" */));
          if ((iVar5 == 0) && (this->config_version < L'\x03')) {
            if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
              Settings_newScreen(this,Platform_defaultScreens);
              Settings_newScreen(this,Platform_defaultScreens + 1);
              ss = *this->screens;
            }
            else {
              ss = *this->screens;
            }
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            ss->sortKey = (int)lVar9 + 1;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x148f45 /* "tree_sort_key" */));
          if ((iVar5 == 0) && (this->config_version < L'\x03')) {
            if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
              Settings_newScreen(this,Platform_defaultScreens);
              Settings_newScreen(this,Platform_defaultScreens + 1);
              ss = *this->screens;
            }
            else {
              ss = *this->screens;
            }
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            ss->treeSortKey = (int)lVar9 + 1;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494a3 /* "sort_direction" */));
          if ((iVar5 == 0) && (this->config_version < L'\x03')) {
            if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
              Settings_newScreen(this,Platform_defaultScreens);
              Settings_newScreen(this,Platform_defaultScreens + 1);
              ss = *this->screens;
            }
            else {
              ss = *this->screens;
            }
LAB_00137cb2:
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            ss->direction = (wchar_t)lVar9;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494b3 /* "tree_sort_direction" */));
          if (iVar5 != 0) {
            iVar5 = strcmp(pcVar7,((char *)0x1494c8 /* "tree_view" */));
            if (iVar5 == 0) {
              if (L'\x02' < this->config_version) goto LAB_00137537;
              if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
                Settings_newScreen(this,Platform_defaultScreens);
                Settings_newScreen(this,Platform_defaultScreens + 1);
                ss = *this->screens;
              }
              else {
                ss = *this->screens;
              }
LAB_00137774:
              lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
              ss->treeView = (int)lVar9 != 0;
            }
            else {
              iVar5 = strcmp(pcVar7,((char *)0x1494d3 /* "tree_view_always_by_pid" */));
              if (iVar5 != 0) goto LAB_0013754e;
              if (L'\x02' < this->config_version) goto LAB_00137790;
              if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
                Settings_newScreen(this,Platform_defaultScreens);
                Settings_newScreen(this,Platform_defaultScreens + 1);
                ss = *this->screens;
              }
              else {
                ss = *this->screens;
              }
LAB_00137c14:
              lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
              ss->treeViewAlwaysByPID = (int)lVar9 != 0;
            }
            goto LAB_001375c0;
          }
          if (this->config_version < L'\x03') {
            if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
              Settings_newScreen(this,Platform_defaultScreens);
              Settings_newScreen(this,Platform_defaultScreens + 1);
              ss = *this->screens;
            }
            else {
              ss = *this->screens;
            }
LAB_00137cfd:
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            ss->treeDirection = (wchar_t)lVar9;
            goto LAB_001375c0;
          }
LAB_00137537:
          iVar5 = strcmp(pcVar7,((char *)0x1494d3 /* "tree_view_always_by_pid" */));
          if (iVar5 != 0) {
LAB_0013754e:
            iVar5 = strcmp(pcVar7,((char *)0x1494ec /* "all_branches_collapsed" */));
            if ((iVar5 != 0) || (L'\x02' < this->config_version)) goto LAB_00137790;
            if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
              Settings_newScreen(this,Platform_defaultScreens);
              Settings_newScreen(this,Platform_defaultScreens + 1);
              ss = *this->screens;
            }
            else {
              ss = *this->screens;
            }
LAB_001375a2:
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            ss->allBranchesCollapsed = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
LAB_00137790:
          iVar5 = strcmp(pcVar7,((char *)0x1491e8 /* "hide_kernel_threads" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideKernelThreads = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1491fc /* "hide_userland_threads" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideUserlandThreads = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149212 /* "hide_running_in_container" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideRunningInContainer = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14922c /* "shadow_other_users" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->shadowOtherUsers = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14923f /* "show_thread_names" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showThreadNames = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149251 /* "show_program_path" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showProgramPath = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149263 /* "highlight_base_name" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightBaseName = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149277 /* "highlight_deleted_exe" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightDeletedExe = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14c928 /* "shadow_distribution_path_prefix" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->shadowDistPathPrefix = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14928d /* "highlight_megabytes" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightMegabytes = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1492a1 /* "highlight_threads" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightThreads = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1492b3 /* "highlight_changes" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightChanges = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1492c5 /* "highlight_changes_delay_secs" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            wVar6 = L'𕆀';
            if ((int)lVar9 < 0x15181) {
              lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
              wVar6 = L'\x01';
              if (1 < (int)lVar9) {
                lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
                wVar6 = (wchar_t)lVar9;
              }
            }
            this->highlightDelaySecs = wVar6;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1492e2 /* "find_comm_in_cmdline" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->findCommInCmdline = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1492f7 /* "strip_exe_from_cmdline" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->stripExeFromCmdline = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14930e /* "show_merged_command" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showMergedCommand = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149322 /* "header_margin" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->headerMargin = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149330 /* "screen_tabs" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->screenTabs = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14933c /* "expand_system_time" */));
          if ((iVar5 == 0) || (iVar5 = strcmp(pcVar7,((char *)0x14934f /* "detailed_cpu_time" */)), iVar5 == 0)) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->detailedCPUTime = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149361 /* "cpu_count_from_one" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->countCPUsFromOne = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149374 /* "cpu_count_from_zero" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->countCPUsFromOne = (int)lVar9 == 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149388 /* "show_cpu_usage" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showCPUUsage = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149397 /* "show_cpu_frequency" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showCPUFrequency = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1493aa /* "show_cpu_temperature" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showCPUTemperature = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1493bf /* "degree_fahrenheit" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->degreeFahrenheit = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1493d1 /* "update_process_names" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->updateProcessNames = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1493e6 /* "account_guest_in_cpu_meter" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->accountGuestInCPUMeter = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1475a2 /* "delay" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            wVar6 = L'ÿ';
            if ((int)lVar9 < 0x100) {
              lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
              wVar6 = L'\x01';
              if (1 < (int)lVar9) {
                lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
                wVar6 = (wchar_t)lVar9;
              }
            }
            this->delay = wVar6;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149401 /* "color_scheme" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            wVar6 = (wchar_t)lVar9;
            if (6 < (uint)wVar6) {
              wVar6 = L'\0';
            }
            this->colorScheme = wVar6;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14940e /* "enable_mouse" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->enableMouse = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x14941b /* "header_layout" */));
          if (iVar5 == 0) {
            ppuVar10 = __ctype_b_loc();
            p0 = (byte *)ppcVar8[1];
            if ((*(byte *)((long)*ppuVar10 + (ulong)*p0 * 2 + 1) & 8) == 0) {
              paVar15 = HeaderLayout_layouts;
                    /* Unresolved local var: size_t i@[???] */
              lVar9 = 0;
              do {
                iVar5 = strcmp(paVar15->name,(char *)p0);
                if (iVar5 == 0) {
                  local_80 = (HeaderLayout)lVar9;
                  break;
                }
                lVar9 = lVar9 + 1;
                paVar15 = paVar15 + 1;
                local_80 = HF_TWO_50_50;
              } while (lVar9 != 0xc);
            }
            else {
              lVar9 = __isoc23_strtol((char *)p0,(char **)0x0,10);
              local_80 = (HeaderLayout)lVar9;
              if (0xb < (uint)(HeaderLayout)lVar9) {
                local_80 = HF_TWO_50_50;
              }
            }
            this->hLayout = local_80;
            free(this->hColumns);
            pMVar11 = xCalloc((ulong)HeaderLayout_layouts[this->hLayout].columns,0x18);
            this->hColumns = pMVar11;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149429 /* "left_meters" */));
          if (iVar5 == 0) {
            Settings_readMeters(this,ppcVar8[1],0);
            goto LAB_001381cd;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149435 /* "right_meters" */));
          if (iVar5 == 0) {
            Settings_readMeters(this,ppcVar8[1],1);
            bVar2 = true;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149442 /* "left_meter_modes" */));
          if (iVar5 == 0) {
            Settings_readMeterModes(this,ppcVar8[1],0);
LAB_001381cd:
            bVar2 = true;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149453 /* "right_meter_modes" */));
          if (iVar5 == 0) {
            Settings_readMeterModes(this,ppcVar8[1],1);
            goto LAB_001381cd;
          }
          _Var4 = String_startsWith(pcVar7,((char *)0x149465 /* "column_meters_" */));
          if (_Var4) {
            lVar9 = __isoc23_strtol(pcVar7 + 0xe,(char **)0x0,10);
            Settings_readMeters(this,ppcVar8[1],(uint)lVar9);
            goto LAB_001381cd;
          }
          _Var4 = String_startsWith(pcVar7,((char *)0x149474 /* "column_meter_modes_" */));
          if (_Var4) {
            lVar9 = __isoc23_strtol(pcVar7 + 0x13,(char **)0x0,10);
            Settings_readMeterModes(this,ppcVar8[1],(uint)lVar9);
            goto LAB_001381cd;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149488 /* "hide_function_bar" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideFunctionBar = (wchar_t)lVar9;
            goto LAB_001375c0;
          }
          iVar5 = strncmp(pcVar7,((char *)0x14949a /* "screen:" */),7);
          if (iVar5 == 0) {
            local_68._0_8_ = pcVar7 + 7;
            local_58 = (undefined1  [16])0x0;
            local_68._8_8_ = ppcVar8[1];
            ss = (ScreenSettings_5 *)Settings_newScreen(this,(ScreenDefaults *)local_68);
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x148f29 /* ".sort_key" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) {
                    /* Unresolved local var: wchar_t key@[???] */
              wVar6 = toFieldIndex(this->dynamicColumns,ppcVar8[1]);
              if (wVar6 < L'\x01') {
                wVar6 = L'\x01';
              }
              ss->sortKey = wVar6;
            }
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x148f44 /* ".tree_sort_key" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) {
                    /* Unresolved local var: wchar_t key@[???] */
              wVar6 = toFieldIndex(this->dynamicColumns,ppcVar8[1]);
              if (wVar6 < L'\x01') {
                wVar6 = L'\x01';
              }
              ss->treeSortKey = wVar6;
            }
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494a2 /* ".sort_direction" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137cb2;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494b2 /* ".tree_sort_direction" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137cfd;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494c7 /* ".tree_view" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137774;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494d2 /* ".tree_view_always_by_pid" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137c14;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x1494eb /* ".all_branches_collapsed" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_001375a2;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)0x149503 /* ".dynamic" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) {
              free_and_xStrdup(&ss->dynamic,ppcVar8[1]);
            }
            goto LAB_001375c0;
          }
          pcVar7 = *ppcVar8;
        }
        do {
          free(pcVar7);
          pcVar7 = ppcVar14[1];
          ppcVar14 = ppcVar14 + 1;
        } while (pcVar7 != (char *)0x0);
        goto LAB_001375e2;
      }
      lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
      this->config_version = (wchar_t)lVar9;
      if ((wchar_t)lVar9 < L'\x04') goto LAB_001375c0;
      __fprintf_chk(_stderr,2,((char *)0x14c858 /* "WARNING: %s specifies configuration format\n" */),fileName);
      __fprintf_chk(_stderr,2,
                    ((char *)0x14c888 /* "         version v%d, but this %s binary only supports up to version v%d.\n" */),
                    this->config_version,((char *)0x14954a /* "htop" */),3);
      __fprintf_chk(_stderr,2,
                    ((char *)0x14c8d8 /* "         The configuration file will be downgraded to v%d when %s exits.\n" */),3,
                    ((char *)0x14954a /* "htop" */));
                    /* Unresolved local var: size_t i@[???] */
      pcVar7 = *ppcVar8;
      while (pcVar7 != (char *)0x0) {
        ppcVar14 = ppcVar14 + 1;
        free(pcVar7);
        pcVar7 = *ppcVar14;
      }
      free(ppcVar8);
      fclose(__stream);
      goto LAB_001376b2;
    }
    if (ppcVar8 != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
      pcVar7 = *ppcVar8;
      ppcVar14 = ppcVar8;
      while (pcVar7 != (char *)0x0) {
        ppcVar14 = ppcVar14 + 1;
        free(pcVar7);
        pcVar7 = *ppcVar14;
      }
LAB_001375e2:
      free(ppcVar8);
    }
    _Var4 = true;
  }
  fclose(__stream);
                    /* Unresolved local var: size_t colCount@[???]
                       Unresolved local var: _Bool anyMeter@[???] */
                    /* Unresolved local var: size_t column@[???] */
  if ((bVar2) && ((ulong)HeaderLayout_layouts[this->hLayout].columns != 0)) {
    pMVar11 = this->hColumns;
    bVar3 = false;
    uVar12 = 0;
    do {
                    /* Unresolved local var: char * * names@[???]
                       Unresolved local var: wchar_t * modes@[???]
                       Unresolved local var: size_t len@[???] */
      sVar1 = pMVar11->len;
      if (sVar1 != 0) {
        ppcVar8 = pMVar11->names;
        if ((pMVar11->modes == (wchar_t *)0x0) || (ppcVar8 == (char **)0x0)) goto LAB_00137f26;
                    /* Unresolved local var: size_t meterIdx@[???] */
        sVar13 = 0;
        do {
          if (ppcVar8[sVar13] == (char *)0x0) goto LAB_00137f26;
          sVar13 = sVar13 + 1;
        } while (sVar1 != sVar13);
        bVar3 = bVar2;
        if (ppcVar8[sVar1] != (char *)0x0) goto LAB_00137f26;
      }
      uVar12 = uVar12 + 1;
      pMVar11 = pMVar11 + 1;
    } while (HeaderLayout_layouts[this->hLayout].columns != uVar12);
    if (!bVar3) goto LAB_00137f26;
  }
  else {
LAB_00137f26:
    Settings_defaultMeters(this,initialCpuCount);
  }
  if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
    Settings_newScreen(this,Platform_defaultScreens);
    Settings_newScreen(this,Platform_defaultScreens + 1);
  }
LAB_001376b4:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var4;
}

