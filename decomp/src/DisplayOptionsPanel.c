#include "htop.h"

/* DisplayOptionsPanel_delete @ 0x117890 */

void DisplayOptionsPanel_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(Vector **)((long)param_1 + 0x20));
  FunctionBar_delete(*(FunctionBar **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}


/* DisplayOptionsPanel_new @ 0x118eb0 */

/* WARNING: Removing unreachable block (ram,0x00118f62) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x00118f82 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

DisplayOptionsPanel * DisplayOptionsPanel_new(Settings_4 *settings,ScreenManager_3 *scr)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  int wVar1;
  long lVar2;
  char *p1;
  ScreenSettings_3 *pSVar3;
  int len;
  int iVar4;
  DisplayOptionsPanel *this;
  FunctionBar *fuBar;
  size_t sVar5;
  Object *pOVar6;
  ObjectClass *pOVar7;
  undefined1 *puVar8;
  cchar_t *pcVar9;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * data@[???] */
  puVar8 = (*(undefined1 (*) [8])(__fp - 0x98));
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  this = malloc(0x26f0);
  if (this != (DisplayOptionsPanel *)0x0) {
    (this->super).super.klass = &DisplayOptionsPanel_class.super;
    fuBar = FunctionBar_new(DisplayOptionsFunctions,(char **)0x0,(int *)0x0);
    Panel_init(&this->super,1,1,1,1,&OptionItem_class.super,true,fuBar);
    this->scr = scr;
    this->settings = settings;
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[38953] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x90)) = (*(undefined1 (*) [8])(__fp - 0x98));
    pOVar6 = (Object *)(*(undefined1 (*) [48])(__fp - 0xd8));
    (*(undefined1 *(*))(__fp - 0x90)) = (*(undefined1 (*) [8])(__fp - 0x98));
    sVar5 = mbstowcs((int *)(*(undefined1 (*) [48])(__fp - 0xd8)),((char *)(long)&s_Display_options_0014724d /* "Display options" */),0xf);
    len = (int)sVar5;
    if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(this->super).header,len);
      (*(attr_t (*))(__fp - 0x84)) = wVar1 & 0xffffff;
      (*(Object *(*))(__fp - 0x80)) = (Object *)((*(undefined1 (*) [48])(__fp - 0xd8)) + (ulong)(uint)(len + -1) * 4 + 4);
      pcVar9 = (this->super).header.chptr;
      do {
        wVar1 = *(int *)&pOVar6->klass;
        iVar4 = iswprint(wVar1);
        pcVar9->attr = 0;
        pcVar9->chars[0] = 0;
        pcVar9->chars[1] = 0;
        pcVar9->chars[2] = 0;
        if (iVar4 == 0) {
          wVar1 = 65533;
        }
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
        pOVar6 = (Object *)((long)&pOVar6->klass + 4);
        pcVar9->attr = (*(attr_t (*))(__fp - 0x84));
        pcVar9->chars[0] = wVar1;
        pcVar9 = pcVar9 + 1;
      } while ((*(Object *(*))(__fp - 0x80)) != pOVar6);
    }
    puVar8 = (*(undefined1 *(*))(__fp - 0x90));
    (this->super).needsRedraw = true;
    builtin_strncpy((*(char (*) [47])(__fp - 0x78)) + 0x10,"en tab: ",8);
    builtin_strncpy((*(char (*) [47])(__fp - 0x78)),"For current scre",0x10);
    (*(char (*) [47])(__fp - 0x78))[0x18] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x19] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x1a] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x1b] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x1c] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x1d] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x1e] = '\0';
    (*(char (*) [47])(__fp - 0x78))[0x1f] = '\0';
    (*(ulong *)((char *)&(*(char (*) [47])(__fp - 0x78)) + 32)) = SUB1615((undefined16)0x0,1);
    p1 = settings->ss->heading;
    __strncat_chk((*(char (*) [47])(__fp - 0x78)),p1,0x14,0x2f);
                    /* Unresolved local var: TextItem * this@[???]
                       Unresolved local var: void * data@[???] */
    pOVar6 = malloc(0x18);
    if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pOVar6->klass = &TextItem_class.super;
      pOVar7 = (ObjectClass *)strdup((*(char (*) [47])(__fp - 0x78)));
      if (pOVar7 != (ObjectClass *)0x0) {
        pOVar6[1].klass = pOVar7;
        Panel_add(&this->super,pOVar6);
        pSVar3 = settings->ss;
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
        pOVar6 = malloc(0x20);
        if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
          pOVar6->klass = &CheckItem_class.super;
          pOVar7 = (ObjectClass *)strdup(((char *)(long)&s_Tree_view_0014725d /* "Tree view" */));
          if (pOVar7 != (ObjectClass *)0x0) {
            pOVar6[1].klass = pOVar7;
            pOVar6[2].klass = (ObjectClass *)&pSVar3->treeView;
            *(undefined1 *)&pOVar6[3].klass = 0;
            Panel_add(&this->super,pOVar6);
            pSVar3 = settings->ss;
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
            pOVar6 = malloc(0x20);
            if (pOVar6 != (Object *)0x0) {
              pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
              pOVar7 = (ObjectClass *)
                       strdup(((char *)(long)&s___Tree_view_is_always_sorted_by_P_0014a3a8 /* "- Tree view is always sorted by PID (htop 2 behavior)" */));
              if (pOVar7 != (ObjectClass *)0x0) {
                pOVar6[1].klass = pOVar7;
                pOVar6[2].klass = (ObjectClass *)&pSVar3->treeViewAlwaysByPID;
                *(undefined1 *)&pOVar6[3].klass = 0;
                Panel_add(&this->super,pOVar6);
                pSVar3 = settings->ss;
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                pOVar6 = malloc(0x20);
                if (pOVar6 != (Object *)0x0) {
                  pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                  pOVar7 = (ObjectClass *)strdup(((char *)(long)&s___Tree_view_is_collapsed_by_defa_0014a3e0 /* "- Tree view is collapsed by default" */));
                  if (pOVar7 != (ObjectClass *)0x0) {
                    pOVar6[1].klass = pOVar7;
                    pOVar6[2].klass = (ObjectClass *)&pSVar3->allBranchesCollapsed;
                    *(undefined1 *)&pOVar6[3].klass = 0;
                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: TextItem * this@[???]
                       Unresolved local var: void * data@[???] */
                    pOVar6 = malloc(0x18);
                    if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
                      pOVar6->klass = &TextItem_class.super;
                      pOVar7 = (ObjectClass *)strdup(((char *)(long)&s_Global_options__00147267 /* "Global options:" */));
                      if (pOVar7 != (ObjectClass *)0x0) {
                        pOVar6[1].klass = pOVar7;
                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                        pOVar6 = malloc(0x20);
                        if (pOVar6 != (Object *)0x0) {
                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                          pOVar7 = (ObjectClass *)strdup(((char *)(long)&s_Show_tabs_for_screens_00147277 /* "Show tabs for screens" */));
                          if (pOVar7 != (ObjectClass *)0x0) {
                            pOVar6[1].klass = pOVar7;
                            pOVar6[2].klass = (ObjectClass *)&settings->screenTabs;
                            *(undefined1 *)&pOVar6[3].klass = 0;
                            Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                            pOVar6 = malloc(0x20);
                            if (pOVar6 != (Object *)0x0) {
                              pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                              pOVar7 = (ObjectClass *)strdup(((char *)(long)&s_Shadow_other_users__processes_0014728d /* "Shadow other users\' processes" */));
                              if (pOVar7 != (ObjectClass *)0x0) {
                                pOVar6[1].klass = pOVar7;
                                pOVar6[2].klass = (ObjectClass *)&settings->shadowOtherUsers;
                                *(undefined1 *)&pOVar6[3].klass = 0;
                                Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                pOVar6 = malloc(0x20);
                                if (pOVar6 != (Object *)0x0) {
                                  pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                  pOVar7 = (ObjectClass *)strdup(((char *)(long)&s_Hide_kernel_threads_001472ab /* "Hide kernel threads" */));
                                  if (pOVar7 != (ObjectClass *)0x0) {
                                    pOVar6[1].klass = pOVar7;
                                    pOVar6[2].klass = (ObjectClass *)&settings->hideKernelThreads;
                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                    pOVar6 = malloc(0x20);
                                    if (pOVar6 != (Object *)0x0) {
                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                      pOVar7 = (ObjectClass *)
                                               strdup(((char *)(long)&s_Hide_userland_process_threads_001472bf /* "Hide userland process threads" */));
                                      if (pOVar7 != (ObjectClass *)0x0) {
                                        pOVar6[1].klass = pOVar7;
                                        pOVar6[2].klass =
                                             (ObjectClass *)&settings->hideUserlandThreads;
                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                        pOVar6 = malloc(0x20);
                                        if (pOVar6 != (Object *)0x0) {
                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                          pOVar7 = (ObjectClass *)
                                                   strdup(((char *)(long)&s_Hide_processes_running_in_contai_0014a408 /* "Hide processes running in containers" */));
                                          if (pOVar7 != (ObjectClass *)0x0) {
                                            pOVar6[1].klass = pOVar7;
                                            pOVar6[2].klass =
                                                 (ObjectClass *)&settings->hideRunningInContainer;
                                            *(undefined1 *)&pOVar6[3].klass = 0;
                                            Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                            pOVar6 = malloc(0x20);
                                            if (pOVar6 != (Object *)0x0) {
                                              pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                              pOVar7 = (ObjectClass *)
                                                       strdup(((char *)(long)&s_Display_threads_in_a_different_c_0014a430 /* "Display threads in a different color" */)
                                                             );
                                              if (pOVar7 != (ObjectClass *)0x0) {
                                                pOVar6[1].klass = pOVar7;
                                                pOVar6[2].klass =
                                                     (ObjectClass *)&settings->highlightThreads;
                                                *(undefined1 *)&pOVar6[3].klass = 0;
                                                Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                pOVar6 = malloc(0x20);
                                                if (pOVar6 != (Object *)0x0) {
                                                  pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                  pOVar7 = (ObjectClass *)
                                                           strdup(((char *)(long)&s_Show_custom_thread_names_001472dd /* "Show custom thread names" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->showThreadNames;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)(long)&s_Show_program_path_001472f6 /* "Show program path" */));
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[1].klass = pOVar7;
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)
                                                             &settings->showProgramPath;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        pOVar6 = malloc(0x20);
                                                        if (pOVar6 != (Object *)0x0) {
                                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)(long)&s_Highlight_program__basename__00147308 /* "Highlight program \"basename\"" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->highlightBaseName
                                                    ;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Highlight_out_dated_removed_prog_0014a458 /* "Highlight out-dated/removed programs (red) / libraries (yellow)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->highlightDeletedExe;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Shadow_distribution_path_prefixe_0014a498 /* "Shadow distribution path prefixes" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->shadowDistPathPrefix;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Merge_exe__comm_and_cmdline_in_C_0014a4c0 /* "Merge exe, comm and cmdline in Command" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->showMergedCommand
                                                    ;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s___Try_to_find_comm_in_cmdline__w_0014a4e8 /* "- Try to find comm in cmdline (when Command is merged)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->findCommInCmdline
                                                    ;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s___Try_to_strip_exe_from_cmdline___0014a520 /* "- Try to strip exe from cmdline (when Command is merged)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->stripExeFromCmdline;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Highlight_large_numbers_in_memor_0014a560 /* "Highlight large numbers in memory counters" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->highlightMegabytes;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)(long)&s_Leave_a_margin_around_header_00147325 /* "Leave a margin around header" */)
                                                                     );
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[1].klass = pOVar7;
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)&settings->headerMargin;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        pOVar6 = malloc(0x20);
                                                        if (pOVar6 != (Object *)0x0) {
                                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)(long)&s_Detailed_CPU_time__System_IO_Wai_0014a590 /* "Detailed CPU time (System/IO-Wait/Hard-IRQ/Soft-IRQ/Steal/Guest)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->detailedCPUTime;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Count_CPUs_from_1_instead_of_0_0014a5d8 /* "Count CPUs from 1 instead of 0" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->countCPUsFromOne;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Update_process_names_on_every_re_0014a5f8 /* "Update process names on every refresh" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->updateProcessNames;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Add_guest_time_in_CPU_meter_perc_0014a620 /* "Add guest time in CPU meter percentage" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->accountGuestInCPUMeter;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Also_show_CPU_percentage_numeric_0014a648 /* "Also show CPU percentage numerically" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->showCPUUsage;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)(long)&s_Also_show_CPU_frequency_00147342 /* "Also show CPU frequency" */));
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[1].klass = pOVar7;
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)
                                                             &settings->showCPUFrequency;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        pOVar6 = malloc(0x20);
                                                        if (pOVar6 != (Object *)0x0) {
                                                          pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)(long)&s_Also_show_CPU_temperature__requi_0014a670 /* "Also show CPU temperature (requires libsensors)" */))
                                                  ;
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)
                                                         &settings->showCPUTemperature;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s___Show_temperature_in_degree_Fah_0014a6a0 /* "- Show temperature in degree Fahrenheit instead of Celsius" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[2].klass =
                                                         (ObjectClass *)&settings->degreeFahrenheit;
                                                    *(undefined1 *)&pOVar6[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(((char *)(long)&s_Enable_the_mouse_0014735a /* "Enable the mouse" */));
                                                      if (pOVar7 != (ObjectClass *)0x0) {
                                                        pOVar6[2].klass =
                                                             (ObjectClass *)&settings->enableMouse;
                                                        pOVar6[1].klass = pOVar7;
                                                        *(undefined1 *)&pOVar6[3].klass = 0;
                                                        Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: NumberItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                        pOVar6 = malloc(0x30);
                                                        if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
                                                          pOVar6->klass = &NumberItem_class.super;
                                                          (*(Object *(*))(__fp - 0x80)) = pOVar6;
                                                          pOVar7 = (ObjectClass *)
                                                                   strdup(
                                                  ((char *)(long)&s_Update_interval__in_seconds__0014736b /* "Update interval (in seconds)" */));
                                                  pOVar6 = (*(Object *(*))(__fp - 0x80));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    (*(Object *(*))(__fp - 0x80))[3].klass =
                                                         (ObjectClass *)&settings->delay;
                                                    (*(Object *(*))(__fp - 0x80))[1].klass = pOVar7;
                                                    (*(Object *(*))(__fp - 0x80))[4].klass =
                                                         (ObjectClass *)0xffffffff00000000;
                                                    (*(Object *(*))(__fp - 0x80))[5].klass = (ObjectClass *)0xff00000001;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: CheckItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x20);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &CheckItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      (*(Object *(*))(__fp - 0x80)) = pOVar6;
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Highlight_new_and_old_processes_0014a6e0 /* "Highlight new and old processes" */));
                                                  pOVar6 = (*(Object *(*))(__fp - 0x80));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    (*(Object *(*))(__fp - 0x80))[2].klass =
                                                         (ObjectClass *)&settings->highlightChanges;
                                                    (*(Object *(*))(__fp - 0x80))[1].klass = pOVar7;
                                                    *(undefined1 *)&(*(Object *(*))(__fp - 0x80))[3].klass = 0;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: NumberItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x30);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &NumberItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s___Highlight_time__in_seconds__00147388 /* "- Highlight time (in seconds)" */));
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[3].klass =
                                                         (ObjectClass *)
                                                         &settings->highlightDelaySecs;
                                                    pOVar6[4].klass = (ObjectClass *)0x0;
                                                    pOVar6[5].klass = (ObjectClass *)0x1518000000001
                                                    ;
                                                    Panel_add(&this->super,pOVar6);
                    /* Unresolved local var: NumberItem * this@[???]
                       Unresolved local var: void * data@[???] */
                                                    pOVar6 = malloc(0x30);
                                                    if (pOVar6 != (Object *)0x0) {
                                                      pOVar6->klass = &NumberItem_class.super;
                    /* Unresolved local var: char * data@[???] */
                                                      pOVar7 = (ObjectClass *)
                                                               strdup(
                                                  ((char *)(long)&s_Hide_main_function_bar__0___off__0014a700 /* "Hide main function bar (0 - off, 1 - on ESC until next input, 2 - permanently)" */)
                                                  );
                                                  if (pOVar7 != (ObjectClass *)0x0) {
                                                    pOVar6[1].klass = pOVar7;
                                                    pOVar6[3].klass =
                                                         (ObjectClass *)&settings->hideFunctionBar;
                                                    pOVar6[4].klass = (ObjectClass *)0x0;
                                                    pOVar6[5].klass = (ObjectClass *)0x200000000;
                                                    Panel_add(&this->super,pOVar6);
                                                    if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
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
  fail();
}


/* DisplayOptionsPanel_eventHandler @ 0x11f5f0 */

HandlerResult DisplayOptionsPanel_eventHandler(DisplayOptionsPanel_ *super,int ch)

{
  uint64_t *puVar1;
  int iVar2;
  Vector *pVVar3;
  int *pwVar4;
  byte *pbVar5;
  Settings_4 *pSVar6;
  Header_4 *this;
  int wVar7;
  int wVar8;
  NumberItem *this_00;

  pVVar3 = (super->super).items;
  this_00 = (NumberItem *)0x0;
  if (0 < pVVar3->items) {
    this_00 = (NumberItem *)pVVar3->array[(super->super).selected];
  }
  if (ch < '.') {
    if (ch < 10) {
      return IGNORED;
    }
    switch(ch) {
    case 10:
    case 13:
    case ' ':
      goto switchD_0011f636_caseD_a;
    default:
      goto LAB_0011f645;
    case '+':
      if (*(int *)&(this_00->super).super.klass[1].extends != 2) {
        return IGNORED;
      }
      NumberItem_increase(this_00);
      break;
    case '-':
      if (*(int *)&(this_00->super).super.klass[1].extends != 2) {
        return IGNORED;
      }
      pwVar4 = this_00->ref;
      wVar7 = this_00->max;
      if (pwVar4 == (int *)0x0) {
        wVar8 = this_00->value + -1;
        if ((wVar8 <= wVar7) && (wVar7 = this_00->min, this_00->min <= wVar8)) {
          wVar7 = wVar8;
        }
        this_00->value = wVar7;
      }
      else {
        wVar8 = *pwVar4 + -1;
        if (wVar7 < wVar8) {
          *pwVar4 = wVar7;
        }
        else {
          wVar7 = this_00->min;
          if (this_00->min <= wVar8) {
            wVar7 = wVar8;
          }
          *pwVar4 = wVar7;
        }
      }
    }
  }
  else {
    if (((ch != 343) && (ch != 409)) && (ch != 296)) {
      return IGNORED;
    }
switchD_0011f636_caseD_a:
    iVar2 = *(int *)&(this_00->super).super.klass[1].extends;
    if (iVar2 == 1) {
      pbVar5 = (byte *)this_00->text;
      if (pbVar5 == (byte *)0x0) {
        *(byte *)&this_00->ref = *(byte *)&this_00->ref ^ 1;
      }
      else {
        *pbVar5 = *pbVar5 ^ 1;
      }
    }
    else {
      if (iVar2 != 2) {
LAB_0011f645:
        return IGNORED;
      }
      pwVar4 = this_00->ref;
      if (pwVar4 == (int *)0x0) {
        if (this_00->value < this_00->max) {
          this_00->value = this_00->value + 1;
        }
        else {
          this_00->value = this_00->min;
        }
      }
      else if (*pwVar4 < this_00->max) {
        *pwVar4 = *pwVar4 + 1;
      }
      else {
        *pwVar4 = this_00->min;
      }
    }
  }
                    /* Unresolved local var: Header * header@[???] */
  pSVar6 = super->settings;
  puVar1 = &pSVar6->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar6->changed = true;
  this = super->scr->header;
  Header_calculateHeight((Header *)this);
  Header_reinit((Header *)this);
  Header_updateData((Header *)this);
  Header_draw((Header *)this);
  ScreenManager_resize((ScreenManager *)super->scr);
  return HANDLED;
}

