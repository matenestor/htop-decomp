/* Settings_new @ 00138550 size 878 */

Settings_3 *
Settings_new(uint initialCpuCount,Hashtable_2 *dynamicMeters,Hashtable_2 *dynamicColumns,
            Hashtable_2 *dynamicScreens)

{
  long lVar1;
  ScreenSettings_5 *pSVar2;
  _Bool _Var3;
  int iVar4;
  wchar_t wVar5;
  __uid_t __uid;
  Settings *this;
  MeterColumnSetting *pMVar6;
  ScreenSettings_5 **ppSVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  passwd *ppVar11;
  long in_FS_OFFSET;
  stat st;

                    /* Unresolved local var: void * data@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  this = calloc(1,0x80);
  if (this == (Settings *)0x0) {
LAB_001388d5:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  this->dynamicScreens = dynamicScreens;
                    /* Unresolved local var: void * data@[???] */
  this->dynamicColumns = dynamicColumns;
  this->dynamicMeters = dynamicMeters;
  this->hLayout = HF_TWO_50_50;
  pMVar6 = calloc(2,0x18);
  if (pMVar6 == (MeterColumnSetting *)0x0) goto LAB_001388d5;
  this->hColumns = pMVar6;
  this->highlightThreads = true;
  this->highlightChanges = false;
                    /* Unresolved local var: void * data@[???] */
  this->highlightDelaySecs = L'\x05';
  this->findCommInCmdline = true;
  this->stripExeFromCmdline = true;
  this->showMergedCommand = false;
  this->updateProcessNames = false;
  this->hideFunctionBar = L'\0';
  this->headerMargin = true;
  this->countCPUsFromOne = false;
  this->detailedCPUTime = false;
  this->showCPUUsage = true;
  this->showCPUFrequency = false;
  this->showCPUTemperature = false;
  this->degreeFahrenheit = false;
  this->showProgramPath = true;
  this->shadowOtherUsers = false;
  this->showThreadNames = false;
  this->hideKernelThreads = true;
  this->hideRunningInContainer = false;
  this->hideUserlandThreads = false;
  this->highlightBaseName = false;
  this->highlightDeletedExe = true;
  this->shadowDistPathPrefix = false;
  this->highlightMegabytes = true;
  ppSVar7 = calloc(0x10,1);
  if (ppSVar7 == (ScreenSettings_5 **)0x0) goto LAB_001388d5;
  this->screens = ppSVar7;
  this->nScreens = 0;
  pcVar8 = getenv(((char *)0x14950c /* "HTOPRC" */));
  if (pcVar8 == (char *)0x0) {
                    /* Unresolved local var: char * home@[???]
                       Unresolved local var: char * xdgConfigHome@[???]
                       Unresolved local var: char * configDir@[???]
                       Unresolved local var: char * htopDir@[???]
                       Unresolved local var: wchar_t err@[???] */
    pcVar8 = getenv(((char *)0x14951e /* "HOME" */));
    if (pcVar8 == (char *)0x0) {
                    /* Unresolved local var: passwd * pw@[???] */
      __uid = getuid();
      pcVar8 = ((char *)0x149c0c /* "" */);
      ppVar11 = getpwuid(__uid);
      if (ppVar11 != (passwd *)0x0) {
        pcVar8 = ppVar11->pw_dir;
      }
    }
    pcVar9 = getenv(((char *)0x149513 /* "XDG_CONFIG_HOME" */));
    if (pcVar9 == (char *)0x0) {
      pcVar9 = String_cat(pcVar8,((char *)0x149523 /* "/.config/htop/htoprc" */));
      this->filename = pcVar9;
      pcVar10 = String_cat(pcVar8,((char *)0x149538 /* "/.config" */));
      pcVar9 = String_cat(pcVar8,((char *)0x149541 /* "/.config/htop" */));
    }
    else {
      pcVar10 = String_cat(pcVar9,((char *)0x14952b /* "/htop/htoprc" */));
                    /* Unresolved local var: char * data@[???] */
      this->filename = pcVar10;
      pcVar10 = strdup(pcVar9);
      if (pcVar10 == (char *)0x0) goto LAB_001388d5;
      pcVar9 = String_cat(pcVar9,((char *)0x149549 /* "/htop" */));
    }
    pcVar8 = String_cat(pcVar8,((char *)0x14954f /* "/.htoprc" */));
    mkdir(pcVar10,0x1c0);
    mkdir(pcVar9,0x1c0);
    free(pcVar9);
    free(pcVar10);
    iVar4 = lstat(pcVar8,(stat_2 *)&st);
    if ((iVar4 == 0) && ((st.st_mode & 0xf000) != 0xa000)) {
      this->enableMouse = true;
      this->changed = false;
      this->colorScheme = L'\0';
      this->delay = L'\x0f';
      _Var3 = Settings_read(this,pcVar8,initialCpuCount);
      if (_Var3) {
        wVar5 = Settings_write(this,false);
        if (wVar5 == L'\0') {
          unlink(pcVar8);
          free(pcVar8);
        }
        else {
          free(pcVar8);
        }
        goto LAB_0013866c;
      }
      free(pcVar8);
      pcVar8 = this->filename;
    }
    else {
      free(pcVar8);
      pcVar8 = this->filename;
      this->enableMouse = true;
      this->changed = false;
      this->colorScheme = L'\0';
      this->delay = L'\x0f';
    }
  }
  else {
                    /* Unresolved local var: char * data@[???] */
    pcVar8 = strdup(pcVar8);
    if (pcVar8 == (char *)0x0) goto LAB_001388d5;
    this->filename = pcVar8;
    this->enableMouse = true;
    this->changed = false;
    this->colorScheme = L'\0';
    this->delay = L'\x0f';
  }
  _Var3 = Settings_read(this,pcVar8,initialCpuCount);
  if (!_Var3) {
    this->screenTabs = true;
    this->changed = true;
    _Var3 = Settings_read(this,((char *)0x149558 /* "/etc/htoprc" */),initialCpuCount);
    if (!_Var3) {
      Settings_defaultMeters(this,initialCpuCount);
      if (this->nScreens == 0) {
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: ScreenDefaults * defaults@[???] */
        Settings_newScreen(this,Platform_defaultScreens);
        Settings_newScreen(this,Platform_defaultScreens + 1);
      }
    }
  }
LAB_0013866c:
  this->ssIndex = 0;
  pSVar2 = *this->screens;
  this->lastUpdate = 1;
  this->ss = pSVar2;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (Settings_3 *)this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

