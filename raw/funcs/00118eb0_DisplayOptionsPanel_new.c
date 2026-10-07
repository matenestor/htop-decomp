/* DisplayOptionsPanel_new @ 00118eb0 size 3049 */

/* WARNING: Removing unreachable block (ram,0x00118f62) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x00118f82 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

DisplayOptionsPanel * DisplayOptionsPanel_new(Settings_4 *settings,ScreenManager_3 *scr)

{
  wchar_t wVar1;
  long lVar2;
  char *p1;
  ScreenSettings_3 *pSVar3;
  wchar_t len;
  int iVar4;
  DisplayOptionsPanel *this;
  FunctionBar *fuBar;
  size_t sVar5;
  Object *pOVar6;
  ObjectClass *pOVar7;
  undefined1 *puVar8;
  cchar_t *pcVar9;
  long in_FS_OFFSET;
  undefined1 local_d8 [48];
  undefined1 auStack_98 [8];
  undefined1 *local_90;
  attr_t local_84;
  Object *local_80;
  char tabheader [47];

                    /* Unresolved local var: void * data@[???] */
  puVar8 = auStack_98;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  this = malloc(0x26f0);
  if (this != (DisplayOptionsPanel *)0x0) {
    (this->super).super.klass = &DisplayOptionsPanel_class.super;
    fuBar = FunctionBar_new(DisplayOptionsFunctions,(char **)0x0,(wchar_t *)0x0);
    Panel_init(&this->super,L'\x01',L'\x01',L'\x01',L'\x01',&OptionItem_class.super,true,fuBar);
    this->scr = scr;
    this->settings = settings;
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[38953] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_90 = auStack_98;
    pOVar6 = (Object *)local_d8;
    local_90 = auStack_98;
    sVar5 = mbstowcs((wchar_t *)local_d8,((char *)0x14724d /* "Display options" */),0xf);
    len = (wchar_t)sVar5;
    if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(this->super).header,len);
      local_84 = wVar1 & 0xffffff;
      local_80 = (Object *)(local_d8 + (ulong)(uint)(len + L'\xffffffff') * 4 + 4);
      pcVar9 = (this->super).header.chptr;
      do {
        wVar1 = *(wchar_t *)&pOVar6->klass;
        iVar4 = iswprint(wVar1);
        pcVar9->attr = 0;
        pcVar9->chars[0] = L'\0';
        pcVar9->chars[1] = L'\0';
        pcVar9->chars[2] = L'\0';
        if (iVar4 == 0) {
          wVar1 = L'�';
        }
        *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
        pOVar6 = (Object *)((long)&pOVar6->klass + 4);
        pcVar9->attr = local_84;
        pcVar9->chars[0] = wVar1;
        pcVar9 = pcVar9 + 1;
      } while (local_80 != pOVar6);
    }
    puVar8 = local_90;
    (this->super).needsRedraw = true;
    builtin_strncpy(tabheader + 0x10,"en tab: ",8);
    builtin_strncpy(tabheader,"For current scre",0x10);
    tabheader[0x18] = '\0';
    tabheader[0x19] = '\0';
    tabheader[0x1a] = '\0';
    tabheader[0x1b] = '\0';
    tabheader[0x1c] = '\0';
    tabheader[0x1d] = '\0';
    tabheader[0x1e] = '\0';
    tabheader[0x1f] = '\0';
    tabheader._32_15_ = SUB1615((undefined1  [16])0x0,1);
    p1 = settings->ss->heading;
    *(undefined8 *)(local_90 + -8) = 0x11905e;
    __strncat_chk(tabheader,p1,0x14,0x2f);
                    /* Unresolved local var: TextItem * this@[???]
                       Unresolved local var: void * data@[???] */
    *(undefined8 *)(puVar8 + -8) = 0x119068;
    pOVar6 = malloc(0x18);
    if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pOVar6->klass = &TextItem_class.super;
      *(undefined8 *)(puVar8 + -8) = 0x119087;
      pOVar7 = (ObjectClass *)strdup(tabheader);
      if (pOVar7 != (ObjectClass *)0x0) {
        pOVar6[1].klass = pOVar7;
        *(undefined8 *)(puVar8 + -8) = 0x11909f;
        Panel_add(&this->super,pOVar6);
        pSVar3 = settings->ss;
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
        *(undefined8 *)(puVar8 + -8) = 0x1190b2;
        pOVar6 = malloc(0x20);
        if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
          pOVar6->klass = &CheckItem_class.super;
          *(undefined8 *)(puVar8 + -8) = 0x1190d4;
          pOVar7 = (ObjectClass *)strdup(((char *)0x14725d /* "Tree view" */));
          if (pOVar7 != (ObjectClass *)0x0) {
            pOVar6[1].klass = pOVar7;
            pOVar6[2].klass = (ObjectClass *)&pSVar3->treeView;
            *(undefined1 *)&pOVar6[3].klass = 0;
            *(undefined8 *)(puVar8 + -8) = 0x1190f5;
            Panel_add(&this->super,pOVar6);
            pSVar3 = settings->ss;
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
            *(undefined8 *)(puVar8 + -8) = 0x119108;
            pOVar6 = malloc(0x20);
            if (pOVar6 != (Object *)0x0) {
              pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
              *(undefined8 *)(puVar8 + -8) = 0x119123;
              pOVar7 = (ObjectClass *)
                       strdup(((char *)0x14a3a8 /* "- Tree view is always sorted by PID (htop 2 behavior)" */));
              if (pOVar7 != (ObjectClass *)0x0) {
                pOVar6[1].klass = pOVar7;
                pOVar6[2].klass = (ObjectClass *)&pSVar3->treeViewAlwaysByPID;
                *(undefined1 *)&pOVar6[3].klass = 0;
                *(undefined8 *)(puVar8 + -8) = 0x119144;
                Panel_add(&this->super,pOVar6);
                pSVar3 = settings->ss;
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                *(undefined8 *)(puVar8 + -8) = 0x119157;
                pOVar6 = malloc(0x20);
                if (pOVar6 != (Object *)0x0) {
                  pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                  *(undefined8 *)(puVar8 + -8) = 0x119172;
                  pOVar7 = (ObjectClass *)strdup(((char *)0x14a3e0 /* "- Tree view is collapsed by default" */));
                  if (pOVar7 != (ObjectClass *)0x0) {
                    pOVar6[1].klass = pOVar7;
                    pOVar6[2].klass = (ObjectClass *)&pSVar3->allBranchesCollapsed;
                    *(undefined1 *)&pOVar6[3].klass = 0;
                    *(undefined8 *)(puVar8 + -8) = 0x119193;
                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: TextItem * this@[???]
                       Unresolved local var: void * data@[???] */
                    *(undefined8 *)(puVar8 + -8) = 0x11919d;
                    pOVar6 = malloc(0x18);
                    if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
                      pOVar6->klass = &TextItem_class.super;
                      *(undefined8 *)(puVar8 + -8) = 0x1191bf;
                      pOVar7 = (ObjectClass *)strdup(((char *)0x147267 /* "Global options:" */));
                      if (pOVar7 != (ObjectClass *)0x0) {
                        pOVar6[1].klass = pOVar7;
                        *(undefined8 *)(puVar8 + -8) = 0x1191dc;
                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                        *(undefined8 *)(puVar8 + -8) = 0x1191e6;
                        pOVar6 = malloc(0x20);
                        if (pOVar6 != (Object *)0x0) {
                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                          *(undefined8 *)(puVar8 + -8) = 0x119201;
                          pOVar7 = (ObjectClass *)strdup(((char *)0x147277 /* "Show tabs for screens" */));
                          if (pOVar7 != (ObjectClass *)0x0) {
                            pOVar6[1].klass = pOVar7;
                            pOVar6[2].klass = (ObjectClass *)&settings->screenTabs;
                            *(undefined1 *)&pOVar6[3].klass = 0;
                            *(undefined8 *)(puVar8 + -8) = 0x119227;
                            Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                            *(undefined8 *)(puVar8 + -8) = 0x119231;
                            pOVar6 = malloc(0x20);
                            if (pOVar6 != (Object *)0x0) {
                              pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                              *(undefined8 *)(puVar8 + -8) = 0x11924c;
                              pOVar7 = (ObjectClass *)strdup(((char *)0x14728d /* "Shadow other users\' processes" */));
                              if (pOVar7 != (ObjectClass *)0x0) {
                                pOVar6[1].klass = pOVar7;
                                pOVar6[2].klass = (ObjectClass *)&settings->shadowOtherUsers;
                                *(undefined1 *)&pOVar6[3].klass = 0;
                                *(undefined8 *)(puVar8 + -8) = 0x119272;
                                Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                *(undefined8 *)(puVar8 + -8) = 0x11927c;
                                pOVar6 = malloc(0x20);
                                if (pOVar6 != (Object *)0x0) {
                                  pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                  *(undefined8 *)(puVar8 + -8) = 0x119297;
                                  pOVar7 = (ObjectClass *)strdup(((char *)0x1472ab /* "Hide kernel threads" */));
                                  if (pOVar7 != (ObjectClass *)0x0) {
                                    pOVar6[1].klass = pOVar7;
                                    pOVar6[2].klass = (ObjectClass *)&settings->hideKernelThreads;
                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                    *(undefined8 *)(puVar8 + -8) = 0x1192bd;
                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                    *(undefined8 *)(puVar8 + -8) = 0x1192c7;
                                    pOVar6 = malloc(0x20);
                                    if (pOVar6 != (Object *)0x0) {
                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                      *(undefined8 *)(puVar8 + -8) = 0x1192e2;
                                      pOVar7 = (ObjectClass *)
                                               strdup(((char *)0x1472bf /* "Hide userland process threads" */));
                                      if (pOVar7 != (ObjectClass *)0x0) {
                                        pOVar6[1].klass = pOVar7;
                                        pOVar6[2].klass =
                                             (ObjectClass *)&settings->hideUserlandThreads;
                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                        *(undefined8 *)(puVar8 + -8) = 0x119308;
                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                        *(undefined8 *)(puVar8 + -8) = 0x119312;
                                        pOVar6 = malloc(0x20);
                                        if (pOVar6 != (Object *)0x0) {
                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                          *(undefined8 *)(puVar8 + -8) = 0x11932d;
                                          pOVar7 = (ObjectClass *)
                                                   strdup(((char *)0x14a408 /* "Hide processes running in containers" */));
                                          if (pOVar7 != (ObjectClass *)0x0) {
                                            pOVar6[1].klass = pOVar7;
                                            pOVar6[2].klass =
                                                 (ObjectClass *)&settings->hideRunningInContainer;
                                            *(undefined1 *)&pOVar6[3].klass = 0;
                                            *(undefined8 *)(puVar8 + -8) = 0x119353;
                                            Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                            *(undefined8 *)(puVar8 + -8) = 0x11935d;
                                            pOVar6 = malloc(0x20);
                                            if (pOVar6 != (Object *)0x0) {
                                              pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                              *(undefined8 *)(puVar8 + -8) = 0x119378;
                                              pOVar7 = (ObjectClass *)
                                                       strdup(((char *)0x14a430 /* "Display threads in a different color" */)
                                                             );
                                              if (pOVar7 != (ObjectClass *)0x0) {
                                                pOVar6[1].klass = pOVar7;
                                                pOVar6[2].klass =
                                                     (ObjectClass *)&settings->highlightThreads;
                                                *(undefined1 *)&pOVar6[3].klass = 0;
                                                *(undefined8 *)(puVar8 + -8) = 0x11939e;
                                                Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                *(undefined8 *)(puVar8 + -8) = 0x1193a8;
                                                pOVar6 = malloc(0x20);
                                                if (pOVar6 != (Object *)0x0) {
                                                  pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                  *(undefined8 *)(puVar8 + -8) = 0x1193c3;
                                                  pOVar7 = (ObjectClass *)
                                                           strdup(((char *)0x1472dd /* "Show custom thread names" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->showThreadNames;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1193e9;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1193f3;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x11940e;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)0x1472f6 /* "Show program path" */));
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[1].klass = pOVar7;
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)
                                                             &settings->showProgramPath;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        *(undefined8 *)(puVar8 + -8) = 0x119434;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        *(undefined8 *)(puVar8 + -8) = 0x11943e;
                                                        pOVar6 = malloc(0x20);
                                                        if (pOVar6 != (Object *)0x0) {
                                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                          *(undefined8 *)(puVar8 + -8) = 0x119459;
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)0x147308 /* "Highlight program \"basename\"" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->highlightBaseName
                                                    ;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x11947f;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x119489;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1194a4;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a458 /* "Highlight out-dated/removed programs (red) / libraries (yellow)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->highlightDeletedExe;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1194ca;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1194d4;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1194ef;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a498 /* "Shadow distribution path prefixes" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->shadowDistPathPrefix;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119515;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x11951f;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x11953a;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a4c0 /* "Merge exe, comm and cmdline in Command" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->showMergedCommand
                                                    ;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119560;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x11956a;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119585;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a4e8 /* "- Try to find comm in cmdline (when Command is merged)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->findCommInCmdline
                                                    ;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1195ab;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1195b5;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1195d0;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a520 /* "- Try to strip exe from cmdline (when Command is merged)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->stripExeFromCmdline;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1195f6;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x119600;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x11961b;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a560 /* "Highlight large numbers in memory counters" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->highlightMegabytes;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119641;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x11964b;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119666;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)0x147325 /* "Leave a margin around header" */)
                                                                     );
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[1].klass = pOVar7;
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)&settings->headerMargin;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        *(undefined8 *)(puVar8 + -8) = 0x11968c;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        *(undefined8 *)(puVar8 + -8) = 0x119696;
                                                        pOVar6 = malloc(0x20);
                                                        if (pOVar6 != (Object *)0x0) {
                                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                          *(undefined8 *)(puVar8 + -8) = 0x1196b1;
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)0x14a590 /* "Detailed CPU time (System/IO-Wait/Hard-IRQ/Soft-IRQ/Steal/Guest)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->detailedCPUTime;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1196d7;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1196e1;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1196fc;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a5d8 /* "Count CPUs from 1 instead of 0" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->countCPUsFromOne;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119722;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x11972c;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119747;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a5f8 /* "Update process names on every refresh" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->updateProcessNames;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x11976d;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x119777;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119792;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a620 /* "Add guest time in CPU meter percentage" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->accountGuestInCPUMeter;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1197b8;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1197c2;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1197dd;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a648 /* "Also show CPU percentage numerically" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->showCPUUsage;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119803;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x11980d;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119828;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)0x147342 /* "Also show CPU frequency" */));
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[1].klass = pOVar7;
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)
                                                             &settings->showCPUFrequency;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        *(undefined8 *)(puVar8 + -8) = 0x11984e;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        *(undefined8 *)(puVar8 + -8) = 0x119858;
                                                        pOVar6 = malloc(0x20);
                                                        if (pOVar6 != (Object *)0x0) {
                                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                          *(undefined8 *)(puVar8 + -8) = 0x119873;
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)0x14a670 /* "Also show CPU temperature (requires libsensors)" */))
                                                  ;
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->showCPUTemperature;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119899;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1198a3;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1198be;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a6a0 /* "- Show temperature in degree Fahrenheit instead of Celsius" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->degreeFahrenheit;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1198e4;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1198ee;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119909;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)0x14735a /* "Enable the mouse" */));
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)&settings->enableMouse;
                                                        pOVar6[1].klass = pOVar7;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        *(undefined8 *)(puVar8 + -8) = 0x11992f;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: NumberItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        *(undefined8 *)(puVar8 + -8) = 0x119939;
                                                        pOVar6 = malloc(0x30);
                                                        if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
                                                          pOVar6->klass = &NumberItem_class.super;
                                                          local_80 = pOVar6;
                                                          *(undefined8 *)(puVar8 + -8) = 0x11995c;
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)0x14736b /* "Update interval (in seconds)" */));
                                                  pOVar6 = local_80;
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    local_80[3].klass =
                                                         (ObjectClass *)&settings->delay;
                                                    local_80[1].klass = pOVar7;
                                                    local_80[4].klass =
                                                         (ObjectClass *)0xffffffff00000000;
                                                    local_80[5].klass = (ObjectClass *)0xff00000001;
                                                    *(undefined8 *)(puVar8 + -8) = 0x11998a;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x119994;
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      local_80 = pOVar6;
                                                      *(undefined8 *)(puVar8 + -8) = 0x1199b0;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a6e0 /* "Highlight new and old processes" */));
                                                  pOVar6 = local_80;
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    local_80[2].klass =
                                                         (ObjectClass *)&settings->highlightChanges;
                                                    local_80[1].klass = pOVar7;
                                                    *(undefined1 *)&local_80[3].klass = 0;
                                                    *(undefined8 *)(puVar8 + -8) = 0x1199d6;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: NumberItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x1199e0;
                                                    pOVar6 = malloc(0x30);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &NumberItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x1199fb;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x147388 /* "- Highlight time (in seconds)" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[3].klass =
                                                         (ObjectClass *)
                                                         &settings->highlightDelaySecs;
                                                    pOVar6[4].klass = (ObjectClass *)0x0;
                                                    pOVar6[5].klass = (ObjectClass *)0x1518000000001
                                                    ;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119a28;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: NumberItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    *(undefined8 *)(puVar8 + -8) = 0x119a32;
                                                    pOVar6 = malloc(0x30);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &NumberItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      *(undefined8 *)(puVar8 + -8) = 0x119a49;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)0x14a700 /* "Hide main function bar (0 - off, 1 - on ESC until next input, 2 - permanently)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[3].klass =
                                                         (ObjectClass *)&settings->hideFunctionBar;
                                                    pOVar6[4].klass = (ObjectClass *)0x0;
                                                    pOVar6[5].klass = (ObjectClass *)0x200000000;
                                                    *(undefined8 *)(puVar8 + -8) = 0x119a6e;
                                                    Panel_add(&this->super,pOVar6);
                                                    if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
                                                      *(undefined **)(puVar8 + -8) = &UNK_00119a99;
                                                      __stack_chk_fail();
                                                    }
                                                    return this;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar8 + -8) = 0x119a94;
  fail();
}

