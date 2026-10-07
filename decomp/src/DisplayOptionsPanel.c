#include "htop.h"

/* DisplayOptionsPanel_new @ 0x118eb0 */

/* WARNING: Removing unreachable block (ram,0x00118f62) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x00118f82 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 * DisplayOptionsPanel_new(long param_1,undefined8 param_2)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  uint uVar1;
  wchar_t __wc;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  size_t sVar6;
  undefined8 *puVar7;
  char *pcVar8;
  wchar_t *pwVar9;
  long lVar10;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  long extraout_RDX_06;
  long extraout_RDX_07;
  long extraout_RDX_08;
  long extraout_RDX_09;
  long extraout_RDX_10;
  long extraout_RDX_11;
  long extraout_RDX_12;
  long extraout_RDX_13;
  long extraout_RDX_14;
  long extraout_RDX_15;
  long extraout_RDX_16;
  long extraout_RDX_17;
  long extraout_RDX_18;
  long extraout_RDX_19;
  long extraout_RDX_20;
  long extraout_RDX_21;
  long extraout_RDX_22;
  long extraout_RDX_23;
  long extraout_RDX_24;
  long extraout_RDX_25;
  long extraout_RDX_26;
  long extraout_RDX_27;
  long extraout_RDX_28;
  long extraout_RDX_29;
  long extraout_RDX_30;
  long extraout_RDX_31;
  long extraout_RDX_32;
  undefined1 *puVar11;
  long lVar12;
  undefined1 *puVar13;
  undefined1 (*pauVar14) [16];
  long in_FS_OFFSET = (long)__fake_fs;

  puVar11 = (*(undefined1 (*)[8])(__fp - 0x98));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar4 = malloc(0x26f0);
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = DisplayOptionsPanel_class;
    puVar5 = FunctionBar_new(&PTR_DAT_00155cc0,0,0);
    puVar13 = OptionItem_class;
    lVar12 = 1;
    Panel_init((long)puVar4,1,1,1,1,OptionItem_class,1,puVar5);
    puVar4[0x4dd] = param_2;
    puVar4[0x4dc] = param_1;
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined1 * *)(__fp - 0x90)) = (*(undefined1 (*)[8])(__fp - 0x98));
    pwVar9 = (*(wchar_t (*)[12])(__fp - 0xd8));
    (*(undefined1 * *)(__fp - 0x90)) = (*(undefined1 (*)[8])(__fp - 0x98));
    sVar6 = mbstowcs((*(wchar_t (*)[12])(__fp - 0xd8)),((char *)(long)&s_Display_options_0014724d /* "Display options" */),0xf);
    iVar3 = (int)sVar6;
    if (0 < iVar3) {
      FUN_00130130((int *)(puVar4 + 0xc),iVar3);
      (*(uint *)(__fp - 0x84)) = uVar1 & 0xffffff;
      (*(wchar_t * *)(__fp - 0x80)) = (*(wchar_t (*)[12])(__fp - 0xd8)) + (ulong)(iVar3 - 1) + 1;
      pauVar14 = (undefined1 (*) [16])puVar4[0xd];
      do {
        __wc = *pwVar9;
        iVar3 = iswprint(__wc);
        *(undefined16 *)(*pauVar14) = (undefined16)0x0;
        if (iVar3 == 0) {
          __wc = L'�';
        }
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar14 + 0xc)) = (undefined16)0x0;
        pwVar9 = pwVar9 + 1;
        *(uint *)*pauVar14 = (*(uint *)(__fp - 0x84));
        *(wchar_t *)(*pauVar14 + 4) = __wc;
        pauVar14 = (undefined1 (*) [16])(pauVar14[1] + 0xc);
      } while ((*(wchar_t * *)(__fp - 0x80)) != pwVar9);
    }
    puVar11 = (*(undefined1 * *)(__fp - 0x90));
    lVar10 = 0x2f;
    *(undefined1 *)(puVar4 + 9) = 1;
    builtin_strncpy((*(char (*)[32])(__fp - 0x78)) + 0x10,"en tab: ",8);
    builtin_strncpy((*(char (*)[32])(__fp - 0x78)),"For current scre",0x10);
    (*(char (*)[32])(__fp - 0x78))[0x18] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x19] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x1a] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x1b] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x1c] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x1d] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x1e] = '\0';
    (*(char (*)[32])(__fp - 0x78))[0x1f] = 0;
    ASSIGN_ARR((*(undefined1 (*)[15])(__fp - 0x58)), SUB1615((undefined16)0x0,1));
    pcVar8 = (char *)**(undefined8 **)(param_1 + 0x40);
    __strncat_chk((*(char (*)[32])(__fp - 0x78)),pcVar8,0x14,0x2f);
    puVar7 = malloc(0x18);
    if (puVar7 != (undefined8 *)0x0) {
      *puVar7 = TextItem_class;
      pcVar8 = strdup((*(char (*)[32])(__fp - 0x78)));
      if (pcVar8 != (char *)0x0) {
        puVar7[1] = pcVar8;
        Panel_add((long)puVar4,(long)puVar7,extraout_RDX,lVar10,lVar12,(long)puVar13);
        lVar2 = *(long *)(param_1 + 0x40);
        puVar7 = malloc(0x20);
        if (puVar7 != (undefined8 *)0x0) {
          *puVar7 = CheckItem_class;
          pcVar8 = strdup(((char *)(long)&s_Tree_view_0014725d /* "Tree view" */));
          if (pcVar8 != (char *)0x0) {
            puVar7[1] = pcVar8;
            puVar7[2] = lVar2 + 0x34;
            *(undefined1 *)(puVar7 + 3) = 0;
            Panel_add((long)puVar4,(long)puVar7,extraout_RDX_00,lVar10,lVar12,(long)puVar13);
            lVar2 = *(long *)(param_1 + 0x40);
            puVar7 = malloc(0x20);
            if (puVar7 != (undefined8 *)0x0) {
              *puVar7 = CheckItem_class;
              pcVar8 = strdup(((char *)(long)&s___Tree_view_is_always_sorted_by_P_0014a3a8 /* "- Tree view is always sorted by PID (htop 2 behavior)" */));
              if (pcVar8 != (char *)0x0) {
                puVar7[1] = pcVar8;
                puVar7[2] = lVar2 + 0x35;
                *(undefined1 *)(puVar7 + 3) = 0;
                Panel_add((long)puVar4,(long)puVar7,extraout_RDX_01,lVar10,lVar12,(long)puVar13);
                lVar2 = *(long *)(param_1 + 0x40);
                puVar7 = malloc(0x20);
                if (puVar7 != (undefined8 *)0x0) {
                  *puVar7 = CheckItem_class;
                  pcVar8 = strdup(((char *)(long)&s___Tree_view_is_collapsed_by_defa_0014a3e0 /* "- Tree view is collapsed by default" */));
                  if (pcVar8 != (char *)0x0) {
                    puVar7[1] = pcVar8;
                    puVar7[2] = lVar2 + 0x36;
                    *(undefined1 *)(puVar7 + 3) = 0;
                    Panel_add((long)puVar4,(long)puVar7,extraout_RDX_02,lVar10,lVar12,(long)puVar13)
                    ;
                    puVar7 = malloc(0x18);
                    if (puVar7 != (undefined8 *)0x0) {
                      *puVar7 = TextItem_class;
                      pcVar8 = strdup(((char *)(long)&s_Global_options__00147267 /* "Global options:" */));
                      if (pcVar8 != (char *)0x0) {
                        puVar7[1] = pcVar8;
                        Panel_add((long)puVar4,(long)puVar7,extraout_RDX_03,lVar10,lVar12,
                                  (long)puVar13);
                        puVar7 = malloc(0x20);
                        if (puVar7 != (undefined8 *)0x0) {
                          *puVar7 = CheckItem_class;
                          pcVar8 = strdup(((char *)(long)&s_Show_tabs_for_screens_00147277 /* "Show tabs for screens" */));
                          if (pcVar8 != (char *)0x0) {
                            puVar7[1] = pcVar8;
                            puVar7[2] = param_1 + 0x6e;
                            *(undefined1 *)(puVar7 + 3) = 0;
                            Panel_add((long)puVar4,(long)puVar7,extraout_RDX_04,lVar10,lVar12,
                                      (long)puVar13);
                            puVar7 = malloc(0x20);
                            if (puVar7 != (undefined8 *)0x0) {
                              *puVar7 = CheckItem_class;
                              pcVar8 = strdup(((char *)(long)&s_Shadow_other_users__processes_0014728d /* "Shadow other users\' processes" */));
                              if (pcVar8 != (char *)0x0) {
                                puVar7[1] = pcVar8;
                                puVar7[2] = param_1 + 0x57;
                                *(undefined1 *)(puVar7 + 3) = 0;
                                Panel_add((long)puVar4,(long)puVar7,extraout_RDX_05,lVar10,lVar12,
                                          (long)puVar13);
                                puVar7 = malloc(0x20);
                                if (puVar7 != (undefined8 *)0x0) {
                                  *puVar7 = CheckItem_class;
                                  pcVar8 = strdup(((char *)(long)&s_Hide_kernel_threads_001472ab /* "Hide kernel threads" */));
                                  if (pcVar8 != (char *)0x0) {
                                    puVar7[1] = pcVar8;
                                    puVar7[2] = param_1 + 0x59;
                                    *(undefined1 *)(puVar7 + 3) = 0;
                                    Panel_add((long)puVar4,(long)puVar7,extraout_RDX_06,lVar10,
                                              lVar12,(long)puVar13);
                                    puVar7 = malloc(0x20);
                                    if (puVar7 != (undefined8 *)0x0) {
                                      *puVar7 = CheckItem_class;
                                      pcVar8 = strdup(((char *)(long)&s_Hide_userland_process_threads_001472bf /* "Hide userland process threads" */));
                                      if (pcVar8 != (char *)0x0) {
                                        puVar7[1] = pcVar8;
                                        puVar7[2] = param_1 + 0x5b;
                                        *(undefined1 *)(puVar7 + 3) = 0;
                                        Panel_add((long)puVar4,(long)puVar7,extraout_RDX_07,lVar10,
                                                  lVar12,(long)puVar13);
                                        puVar7 = malloc(0x20);
                                        if (puVar7 != (undefined8 *)0x0) {
                                          *puVar7 = CheckItem_class;
                                          pcVar8 = strdup(((char *)(long)&s_Hide_processes_running_in_contai_0014a408 /* "Hide processes running in containers" */));
                                          if (pcVar8 != (char *)0x0) {
                                            puVar7[1] = pcVar8;
                                            puVar7[2] = param_1 + 0x5a;
                                            *(undefined1 *)(puVar7 + 3) = 0;
                                            Panel_add((long)puVar4,(long)puVar7,extraout_RDX_08,
                                                      lVar10,lVar12,(long)puVar13);
                                            puVar7 = malloc(0x20);
                                            if (puVar7 != (undefined8 *)0x0) {
                                              *puVar7 = CheckItem_class;
                                              pcVar8 = strdup(((char *)(long)&s_Display_threads_in_a_different_c_0014a430 /* "Display threads in a different color" */)
                                                             );
                                              if (pcVar8 != (char *)0x0) {
                                                puVar7[1] = pcVar8;
                                                puVar7[2] = param_1 + 0x60;
                                                *(undefined1 *)(puVar7 + 3) = 0;
                                                Panel_add((long)puVar4,(long)puVar7,extraout_RDX_09,
                                                          lVar10,lVar12,(long)puVar13);
                                                puVar7 = malloc(0x20);
                                                if (puVar7 != (undefined8 *)0x0) {
                                                  *puVar7 = CheckItem_class;
                                                  pcVar8 = strdup(((char *)(long)&s_Show_custom_thread_names_001472dd /* "Show custom thread names" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x58;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_10,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(((char *)(long)&s_Show_program_path_001472f6 /* "Show program path" */));
                                                      if (pcVar8 != (char *)0x0) {
                                                        puVar7[1] = pcVar8;
                                                        puVar7[2] = param_1 + 0x56;
                                                        *(undefined1 *)(puVar7 + 3) = 0;
                                                        Panel_add((long)puVar4,(long)puVar7,
                                                                  extraout_RDX_11,lVar10,lVar12,
                                                                  (long)puVar13);
                                                        puVar7 = malloc(0x20);
                                                        if (puVar7 != (undefined8 *)0x0) {
                                                          *puVar7 = CheckItem_class;
                                                          pcVar8 = strdup(
                                                  ((char *)(long)&s_Highlight_program__basename__00147308 /* "Highlight program \"basename\"" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x5c;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_12,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Highlight_out_dated_removed_prog_0014a458 /* "Highlight out-dated/removed programs (red) / libraries (yellow)" */)
                                                  );
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x5d;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_13,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Shadow_distribution_path_prefixe_0014a498 /* "Shadow distribution path prefixes" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x5e;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_14,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Merge_exe__comm_and_cmdline_in_C_0014a4c0 /* "Merge exe, comm and cmdline in Command" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x6a;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_15,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s___Try_to_find_comm_in_cmdline__w_0014a4e8 /* "- Try to find comm in cmdline (when Command is merged)" */)
                                                  );
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x68;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_16,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s___Try_to_strip_exe_from_cmdline___0014a520 /* "- Try to strip exe from cmdline (when Command is merged)" */)
                                                  );
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x69;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_17,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Highlight_large_numbers_in_memor_0014a560 /* "Highlight large numbers in memory counters" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x5f;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_18,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(((char *)(long)&s_Leave_a_margin_around_header_00147325 /* "Leave a margin around header" */)
                                                                     );
                                                      if (pcVar8 != (char *)0x0) {
                                                        puVar7[1] = pcVar8;
                                                        puVar7[2] = param_1 + 0x6d;
                                                        *(undefined1 *)(puVar7 + 3) = 0;
                                                        Panel_add((long)puVar4,(long)puVar7,
                                                                  extraout_RDX_19,lVar10,lVar12,
                                                                  (long)puVar13);
                                                        puVar7 = malloc(0x20);
                                                        if (puVar7 != (undefined8 *)0x0) {
                                                          *puVar7 = CheckItem_class;
                                                          pcVar8 = strdup(
                                                  ((char *)(long)&s_Detailed_CPU_time__System_IO_Wai_0014a590 /* "Detailed CPU time (System/IO-Wait/Hard-IRQ/Soft-IRQ/Steal/Guest)" */)
                                                  );
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x51;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_20,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Count_CPUs_from_1_instead_of_0_0014a5d8 /* "Count CPUs from 1 instead of 0" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x50;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_21,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Update_process_names_on_every_re_0014a5f8 /* "Update process names on every refresh" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x6b;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_22,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Add_guest_time_in_CPU_meter_perc_0014a620 /* "Add guest time in CPU meter percentage" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x6c;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_23,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Also_show_CPU_percentage_numeric_0014a648 /* "Also show CPU percentage numerically" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x52;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_24,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(((char *)(long)&s_Also_show_CPU_frequency_00147342 /* "Also show CPU frequency" */));
                                                      if (pcVar8 != (char *)0x0) {
                                                        puVar7[1] = pcVar8;
                                                        puVar7[2] = param_1 + 0x53;
                                                        *(undefined1 *)(puVar7 + 3) = 0;
                                                        Panel_add((long)puVar4,(long)puVar7,
                                                                  extraout_RDX_25,lVar10,lVar12,
                                                                  (long)puVar13);
                                                        puVar7 = malloc(0x20);
                                                        if (puVar7 != (undefined8 *)0x0) {
                                                          *puVar7 = CheckItem_class;
                                                          pcVar8 = strdup(
                                                  ((char *)(long)&s_Also_show_CPU_temperature__requi_0014a670 /* "Also show CPU temperature (requires libsensors)" */))
                                                  ;
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x54;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_26,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s___Show_temperature_in_degree_Fah_0014a6a0 /* "- Show temperature in degree Fahrenheit instead of Celsius" */)
                                                  );
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[2] = param_1 + 0x55;
                                                    *(undefined1 *)(puVar7 + 3) = 0;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_27,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x20);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = CheckItem_class;
                                                      pcVar8 = strdup(((char *)(long)&s_Enable_the_mouse_0014735a /* "Enable the mouse" */));
                                                      if (pcVar8 != (char *)0x0) {
                                                        puVar7[2] = param_1 + 0x6f;
                                                        puVar7[1] = pcVar8;
                                                        *(undefined1 *)(puVar7 + 3) = 0;
                                                        Panel_add((long)puVar4,(long)puVar7,
                                                                  extraout_RDX_28,lVar10,lVar12,
                                                                  (long)puVar13);
                                                        pwVar9 = malloc(0x30);
                                                        if (pwVar9 != (wchar_t *)0x0) {
                                                          *(undefined1 **)pwVar9 = NumberItem_class;
                                                          (*(wchar_t * *)(__fp - 0x80)) = pwVar9;
                                                          pcVar8 = strdup(
                                                  ((char *)(long)&s_Update_interval__in_seconds__0014736b /* "Update interval (in seconds)" */));
                                                  pwVar9 = (*(wchar_t * *)(__fp - 0x80));
                                                  if (pcVar8 != (char *)0x0) {
                                                    *(long *)((*(wchar_t * *)(__fp - 0x80)) + 6) = param_1 + 0x4c;
                                                    *(char **)((*(wchar_t * *)(__fp - 0x80)) + 2) = pcVar8;
                                                    (*(wchar_t * *)(__fp - 0x80))[8] = L'\0';
                                                    (*(wchar_t * *)(__fp - 0x80))[9] = L'\xffffffff';
                                                    (*(wchar_t * *)(__fp - 0x80))[10] = L'\x01';
                                                    (*(wchar_t * *)(__fp - 0x80))[0xb] = L'ÿ';
                                                    Panel_add((long)puVar4,(long)pwVar9,
                                                              extraout_RDX_29,lVar10,lVar12,
                                                              (long)puVar13);
                                                    pwVar9 = malloc(0x20);
                                                    if (pwVar9 != (wchar_t *)0x0) {
                                                      *(undefined1 **)pwVar9 = CheckItem_class;
                                                      (*(wchar_t * *)(__fp - 0x80)) = pwVar9;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Highlight_new_and_old_processes_0014a6e0 /* "Highlight new and old processes" */));
                                                  pwVar9 = (*(wchar_t * *)(__fp - 0x80));
                                                  if (pcVar8 != (char *)0x0) {
                                                    *(long *)((*(wchar_t * *)(__fp - 0x80)) + 4) = param_1 + 0x61;
                                                    *(char **)((*(wchar_t * *)(__fp - 0x80)) + 2) = pcVar8;
                                                    *(undefined1 *)((*(wchar_t * *)(__fp - 0x80)) + 6) = 0;
                                                    Panel_add((long)puVar4,(long)pwVar9,
                                                              extraout_RDX_30,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x30);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = NumberItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s___Highlight_time__in_seconds__00147388 /* "- Highlight time (in seconds)" */));
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[3] = param_1 + 100;
                                                    puVar7[4] = 0;
                                                    puVar7[5] = 0x1518000000001;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_31,lVar10,lVar12,
                                                              (long)puVar13);
                                                    puVar7 = malloc(0x30);
                                                    if (puVar7 != (undefined8 *)0x0) {
                                                      *puVar7 = NumberItem_class;
                                                      pcVar8 = strdup(
                                                  ((char *)(long)&s_Hide_main_function_bar__0___off__0014a700 /* "Hide main function bar (0 - off, 1 - on ESC until next input, 2 - permanently)" */)
                                                  );
                                                  if (pcVar8 != (char *)0x0) {
                                                    puVar7[1] = pcVar8;
                                                    puVar7[3] = param_1 + 0x70;
                                                    puVar7[4] = 0;
                                                    puVar7[5] = 0x200000000;
                                                    Panel_add((long)puVar4,(long)puVar7,
                                                              extraout_RDX_32,lVar10,lVar12,
                                                              (long)puVar13);
                                                    if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28))
                                                    {
                    /* WARNING: Subroutine does not return */
                                                      __stack_chk_fail();
                                                    }
                                                    return puVar4;
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


/* FUN_00119aa0 @ 0x119aa0 */

void FUN_00119aa0(long param_1)

{
  undefined8 *puVar1;

  puVar1 = DisplayOptionsPanel_new(**(long **)(param_1 + 0x26e8),*(undefined8 *)(param_1 + 0x26e0));
  ScreenManager_insert
            (*(int **)(param_1 + 0x26e0),(long)puVar1,-1,
             *(int *)(*(long *)(*(int **)(param_1 + 0x26e0) + 4) + 0x18));
  return;
}


/* FUN_00119af0 @ 0x119af0 */

undefined8
FUN_00119af0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  byte *pbVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;

  plVar3 = (long *)*param_1;
  lVar4 = *plVar3;
  pbVar1 = (byte *)(lVar4 + 0x59);
  *pbVar1 = *pbVar1 ^ 1;
  plVar2 = (long *)(lVar4 + 0x78);
  *plVar2 = *plVar2 + 1;
  Machine_scanTables((long)plVar3,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  return 0xf;
}


/* FUN_00119b20 @ 0x119b20 */

undefined8
FUN_00119b20(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  byte *pbVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;

  plVar3 = (long *)*param_1;
  lVar4 = *plVar3;
  pbVar1 = (byte *)(lVar4 + 0x5b);
  *pbVar1 = *pbVar1 ^ 1;
  plVar2 = (long *)(lVar4 + 0x78);
  *plVar2 = *plVar2 + 1;
  Machine_scanTables((long)plVar3,param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  return 0xf;
}


/* FUN_00119b50 @ 0x119b50 */

undefined8
FUN_00119b50(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  char cVar6;
  uint uVar7;

  plVar5 = (long *)*param_1;
  lVar3 = *(long *)(*plVar5 + 0x40);
  if (*(char *)(lVar3 + 0x34) == '\0') {
    return 0;
  }
  lVar4 = plVar5[0x15];
  uVar7 = *(byte *)(lVar3 + 0x36) ^ 1;
  cVar6 = (char)uVar7;
  *(char *)(lVar3 + 0x36) = cVar6;
  if (cVar6 == '\0') {
    plVar5 = *(long **)(lVar4 + 8);
    iVar2 = (int)plVar5[3];
    if (0 < iVar2) {
      plVar5 = (long *)*plVar5;
      plVar1 = plVar5 + iVar2;
      do {
        lVar3 = *plVar5;
        plVar5 = plVar5 + 1;
        *(undefined1 *)(lVar3 + 0x20) = 1;
      } while (plVar5 != plVar1);
    }
    return 5;
  }
  Table_collapseAllBranches(lVar4,param_rsi,(ulong)uVar7,(long)plVar5,param_r8,param_r9);
  return 5;
}


/* FUN_00119bd0 @ 0x119bd0 */

undefined8 FUN_00119bd0(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;

  lVar3 = param_1[1];
  lVar1 = *param_1;
  lVar2 = *(long *)(lVar3 + 0x26e8);
  *(long *)(lVar2 + 0x130) = lVar2 + 0x98;
  *(undefined8 *)(lVar3 + 0x50) = *(undefined8 *)(lVar2 + 0x120);
  *(undefined1 *)(lVar3 + 0x49) = 1;
  *(long *)(lVar2 + 0x138) = lVar3;
  IncSet_drawBar(lVar2,*(int *)(CRT_colors + 8));
  lVar3 = lVar2 + 0x98;
  if (*(char *)(lVar2 + 0x148) == '\0') {
    lVar3 = 0;
  }
  *(long *)(*(long *)(lVar1 + 0xa8) + 0x28) = lVar3;
  return 9;
}


/* FUN_00119c50 @ 0x119c50 */

undefined8 FUN_00119c50(long param_1)

{
  long lVar1;
  undefined1 *puVar2;

  lVar1 = *(long *)(param_1 + 8);
  puVar2 = *(undefined1 **)(lVar1 + 0x26e8);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 0x84) = 0;
  *(undefined1 **)(puVar2 + 0x130) = puVar2;
  *(undefined8 *)(lVar1 + 0x50) = *(undefined8 *)(puVar2 + 0x88);
  *(undefined1 *)(lVar1 + 0x49) = 1;
  *(long *)(puVar2 + 0x138) = lVar1;
  IncSet_drawBar((long)puVar2,*(int *)(CRT_colors + 8));
  return 9;
}


/* FUN_00119cb0 @ 0x119cb0 */

undefined8
FUN_00119cb0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char cVar1;
  uint uVar2;
  char *__s1;
  long lVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  undefined **__ptr;
  long lVar7;
  undefined **ppuVar8;
  long *plVar9;
  undefined **ppuVar10;
  byte bVar11;
  long extraout_RDX;
  long lVar12;
  long extraout_RDX_00;
  uint __policy;
  undefined **ppuVar13;
  uint __policy_00;
  char *pcVar14;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(char *)(__fp - 0x49)) = CHAR____0015c0d9;
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (CHAR____0015c0d9 == '\0') {
    uVar6 = 8;
    if (*(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0) {
      __ptr = (undefined **)Scheduling_newPolicyPanel(UINT_0015d440);
LAB_00119d48:
      ppuVar10 = (undefined **)0x1;
      ppuVar13 = __ptr;
      lVar7 = Action_pickFromVector(param_1,(long)__ptr,0x12,'\x01',param_r8,param_r9);
      if (lVar7 != 0) {
        uVar2 = *(uint *)(lVar7 + 0x10);
        if (uVar2 == 0xffffffff) {
          pcVar14 = ((char *)(long)&s_Reset_on_fork__on_001473a6 /* "Reset on fork: on" */);
          bVar11 = BYTE_0015c0d8 ^ 1;
          if (BYTE_0015c0d8 == 1) {
            pcVar14 = ((char *)(long)&s_Reset_on_fork__off_001473b8 /* "Reset on fork: off" */);
          }
          lVar7 = **(long **)__ptr[4];
          __s1 = *(char **)(lVar7 + 8);
          BYTE_0015c0d8 = bVar11;
          if (__s1 != (char *)0x0) goto code_r0x00119da8;
          goto LAB_00119db7;
        }
        ppuVar13 = (undefined **)(ulong)UINT_0015be90;
        UINT_0015d440 = uVar2;
        ppuVar8 = (undefined **)Scheduling_newPriorityPanel(uVar2,UINT_0015be90);
        if (ppuVar8 != (undefined **)0x0) {
          ppuVar10 = (undefined **)0x1;
          ppuVar13 = ppuVar8;
          lVar7 = Action_pickFromVector(param_1,(long)ppuVar8,0xe,'\x01',param_r8,param_r9);
          if (lVar7 != 0) {
            UINT_0015be90 = *(uint *)(lVar7 + 0x10);
          }
          free(ppuVar8[7]);
          Vector_delete((long *)ppuVar8[4],(long)ppuVar13,extraout_RDX,(long)ppuVar10,param_r8,
                        param_r9);
          FunctionBar_delete((int *)ppuVar8[0xb]);
          if (0x15e < *(int *)(ppuVar8 + 0xc)) {
            free(ppuVar8[0xd]);
          }
          free(ppuVar8);
        }
        __policy_00 = UINT_0015d440;
        uVar2 = UINT_0015be90;
        lVar7 = 0;
        bVar4 = true;
        ppuVar8 = (undefined **)param_1[1];
        plVar9 = (long *)ppuVar8[4];
        if (0 < (int)plVar9[3]) {
          lVar12 = (long)(int)UINT_0015d440;
          ppuVar13 = &PTR_s_Other_00156560;
          ppuVar10 = &PTR_s_Other_00156560 + lVar12 * 2;
          do {
            lVar3 = *(long *)(*plVar9 + lVar7 * 8);
            cVar1 = *(char *)(lVar3 + 0x1d);
            if (cVar1 != '\0') {
              (*(sched_param *)(__fp - 0x44)).__sched_priority = 0;
              if ((&DAT_0015656c)[lVar12 * 0x10] != '\0') {
                (*(sched_param *)(__fp - 0x44)).__sched_priority = uVar2;
              }
              __policy = __policy_00;
              if (BYTE_0015c0d8 != 0) {
                __policy = __policy_00 & 0x40000000;
              }
              ppuVar13 = (undefined **)(ulong)__policy;
              iVar5 = sched_setscheduler(*(__pid_t *)(lVar3 + 0x10),__policy,&(*(sched_param *)(__fp - 0x44)));
              bVar4 = (bool)(bVar4 & iVar5 != -1);
              plVar9 = (long *)ppuVar8[4];
              (*(char *)(__fp - 0x49)) = cVar1;
            }
            lVar7 = lVar7 + 1;
          } while ((int)lVar7 < (int)plVar9[3]);
          if (((*(char *)(__fp - 0x49)) != '\x01') && (0 < (int)plVar9[3])) {
            lVar7 = *(long *)(*plVar9 + (long)*(int *)(ppuVar8 + 5) * 8);
            ppuVar10 = ppuVar8;
            if (lVar7 != 0) {
              (*(sched_param *)(__fp - 0x44)).__sched_priority = 0;
              if ((&DAT_0015656c)[(long)(int)__policy_00 * 0x10] != '\0') {
                (*(sched_param *)(__fp - 0x44)).__sched_priority = uVar2;
              }
              if (BYTE_0015c0d8 != 0) {
                __policy_00 = __policy_00 & 0x40000000;
              }
              ppuVar13 = (undefined **)(ulong)__policy_00;
              iVar5 = sched_setscheduler(*(__pid_t *)(lVar7 + 0x10),__policy_00,&(*(sched_param *)(__fp - 0x44)));
              bVar4 = (bool)(bVar4 & iVar5 != -1);
              ppuVar10 = ppuVar8;
            }
          }
          if (!bVar4) {
            beep();
          }
        }
      }
      free(__ptr[7]);
      Vector_delete((long *)__ptr[4],(long)ppuVar13,extraout_RDX_00,(long)ppuVar10,param_r8,param_r9
                   );
      FunctionBar_delete((int *)__ptr[0xb]);
      if (0x15e < *(int *)(__ptr + 0xc)) {
        free(__ptr[0xd]);
      }
      free(__ptr);
      uVar6 = 0x29;
    }
  }
  else {
    uVar6 = 8;
  }
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x00119da8:
  iVar5 = strcmp(__s1,pcVar14);
  if (iVar5 != 0) {
LAB_00119db7:
    free(__s1);
    pcVar14 = strdup(pcVar14);
    if (pcVar14 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(char **)(lVar7 + 8) = pcVar14;
  }
  goto LAB_00119d48;
}


/* FUN_0011a000 @ 0x11a000 */

/* WARNING: Removing unreachable block (ram,0x0011a109) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x0011a126 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8
FUN_0011a000(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  char cVar1;
  uint uVar2;
  __pid_t _Var3;
  void *pvVar4;
  int *piVar5;
  long lVar6;
  undefined4 uVar7;
  bool bVar8;
  int iVar9;
  long *__ptr;
  long lVar10;
  undefined8 uVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  long extraout_RDX;
  undefined1 (*pauVar15) [16];
  undefined1 **ppuVar16;
  undefined1 (*pauVar17) [16];
  char cVar18;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar11 = 0;
  ppuVar16 = &(*(undefined1 * *)(__fp - 0x78));
  if ((CHAR____0015c0d9 == '\0') &&
     (ppuVar16 = &(*(undefined1 * *)(__fp - 0x78)), *(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0)) {
    __ptr = SignalsPanel_new(INT_0015be8c);
    lVar14 = 1;
    plVar12 = __ptr;
    lVar10 = Action_pickFromVector(param_1,(long)__ptr,0xe,'\x01',param_r8,param_r9);
    ppuVar16 = &(*(undefined1 * *)(__fp - 0x78));
    if ((lVar10 != 0) && (ppuVar16 = &(*(undefined1 * *)(__fp - 0x78)), *(int *)(lVar10 + 0x10) != 0)) {
      (*(long *)(__fp - 0x70)) = param_1[1];
      (*(undefined1 * *)(__fp - 0x78)) = (undefined1 *)&(*(undefined1 * *)(__fp - 0x78));
      uVar2 = *(uint *)(CRT_colors + 0x1c);
      (*(undefined1 (**)[16])(__fp - 0x58)) = (undefined1 (*) [16])(*(wchar_t (*)[12])(__fp - 0xa8));
      INT_0015be8c = *(int *)(lVar10 + 0x10);
      (*(undefined1 * *)(__fp - 0x78)) = (undefined1 *)&(*(undefined1 * *)(__fp - 0x78));
      plVar12 = (long *)mbstowcs((*(wchar_t (*)[12])(__fp - 0xa8)),((char *)(long)&s_Sending____001473cb /* "Sending..." */),10);
      if (0 < (int)plVar12) {
        (*(long * *)(__fp - 0x50)) = plVar12;
        FUN_00130130((int *)((*(long *)(__fp - 0x70)) + 0x60),(int)plVar12);
        pauVar15 = *(undefined1 (**) [16])((*(long *)(__fp - 0x70)) + 0x68);
        (*(undefined1 (**)[16])(__fp - 0x68)) = (undefined1 (*) [16])(*(*(undefined1 (**)[16])(__fp - 0x58)) + (ulong)((int)(*(long * *)(__fp - 0x50)) - 1) * 4 + 4);
        pauVar17 = (*(undefined1 (**)[16])(__fp - 0x58));
        (*(uint *)(__fp - 0x5c)) = uVar2 & 0xffffff;
        do {
          (*(long * *)(__fp - 0x50)) = (long *)CONCAT44((*(uint *)((char *)&(*(long * *)(__fp - 0x50)) + 4)),*(wint_t *)*pauVar17);
          (*(undefined1 (**)[16])(__fp - 0x58)) = pauVar15;
          iVar9 = iswprint(*(wint_t *)*pauVar17);
          uVar7 = (*(uint *)((char *)&(*(long * *)(__fp - 0x50)) + 0));
          if (iVar9 == 0) {
            uVar7 = 0xfffd;
          }
          *(undefined16 *)(*(*(undefined1 (**)[16])(__fp - 0x58))) = (undefined16)0x0;
          pauVar17 = (undefined1 (*) [16])(*pauVar17 + 4);
          *(undefined16 *)(*(undefined1 (*) [16])(*(*(undefined1 (**)[16])(__fp - 0x58)) + 0xc)) = (undefined16)0x0;
          pauVar15 = (undefined1 (*) [16])((*(undefined1 (**)[16])(__fp - 0x58))[1] + 0xc);
          *(uint *)*(*(undefined1 (**)[16])(__fp - 0x58)) = (*(uint *)(__fp - 0x5c));
          *(undefined4 *)(*(*(undefined1 (**)[16])(__fp - 0x58)) + 4) = uVar7;
        } while ((*(undefined1 (**)[16])(__fp - 0x68)) != pauVar17);
      }
      ppuVar16 = (undefined1 **)(*(undefined1 * *)(__fp - 0x78));
      param_r8 = 1;
      *(undefined1 *)((*(long *)(__fp - 0x70)) + 0x48) = 1;
      if ((*(int *)(*(long *)*param_1 + 0x70) != 2) &&
         (param_r8 = 0, *(int *)(*(long *)*param_1 + 0x70) == 1)) {
        param_r8 = (long)*(byte *)((long)param_1 + 0x19);
      }
      plVar13 = (long *)param_1[1];
      lVar14 = 1;
      plVar12 = (long *)0x0;
      Panel_draw(plVar13,'\0','\x01','\x01',(char)param_r8,param_r9);
      wrefresh(_stdscr);
      (*(undefined1 (**)[16])(__fp - 0x58)) = (undefined1 (*) [16])CONCAT44((*(uint *)((char *)&(*(undefined1 (**)[16])(__fp - 0x58)) + 4)),*(undefined4 *)(lVar10 + 0x10));
      (*(long * *)(__fp - 0x50)) = (long *)param_1[1];
      plVar13 = (long *)(*(long * *)(__fp - 0x50))[4];
      if (0 < (int)plVar13[3]) {
        lVar10 = 0;
        bVar8 = true;
        cVar18 = '\0';
        do {
          lVar6 = *(long *)(*plVar13 + lVar10 * 8);
          cVar1 = *(char *)(lVar6 + 0x1d);
          if (cVar1 != '\0') {
            _Var3 = *(__pid_t *)(lVar6 + 0x10);
            iVar9 = (int)(*(undefined1 (**)[16])(__fp - 0x58));
            plVar12 = (long *)((ulong)(*(undefined1 (**)[16])(__fp - 0x58)) & 0xffffffff);
            iVar9 = kill(_Var3,iVar9);
            bVar8 = (bool)(bVar8 & iVar9 == 0);
            plVar13 = (long *)(*(long * *)(__fp - 0x50))[4];
            cVar18 = cVar1;
          }
          lVar10 = lVar10 + 1;
        } while ((int)lVar10 < (int)plVar13[3]);
        if (((cVar18 != '\x01') && (0 < (int)plVar13[3])) &&
           (lVar10 = *(long *)(*plVar13 + (long)(int)(*(long * *)(__fp - 0x50))[5] * 8), plVar12 = (*(long * *)(__fp - 0x50)),
           lVar10 != 0)) {
          _Var3 = *(__pid_t *)(lVar10 + 0x10);
          iVar9 = (int)(*(undefined1 (**)[16])(__fp - 0x58));
          plVar12 = (long *)((ulong)(*(undefined1 (**)[16])(__fp - 0x58)) & 0xffffffff);
          iVar9 = kill(_Var3,iVar9);
          bVar8 = (bool)(bVar8 & iVar9 == 0);
        }
        if (!bVar8) {
          beep();
        }
      }
      napms(500);
    }
    pvVar4 = (void *)__ptr[7];
    free(pvVar4);
    plVar13 = (long *)__ptr[4];
    Vector_delete(plVar13,(long)plVar12,extraout_RDX,lVar14,param_r8,param_r9);
    piVar5 = (int *)__ptr[0xb];
    FunctionBar_delete(piVar5);
    if (0x15e < (int)__ptr[0xc]) {
      pvVar4 = (void *)__ptr[0xd];
      free(pvVar4);
    }
    free(__ptr);
    uVar11 = 0x61;
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}


/* FUN_0011a2f0 @ 0x11a2f0 */

undefined8
FUN_0011a2f0(long *param_1,uint param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  ushort **ppuVar6;
  undefined8 *puVar7;
  char *pcVar8;
  undefined8 uVar9;
  long *a0;

  if (((param_2 & 0xfffffeff) == 0xd) || (param_2 == 0x157)) {
    if ((0 < (int)((long *)param_1[4])[3]) &&
       (lVar4 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8), lVar4 != 0)) {
      iVar2 = *(int *)(lVar4 + 0x10);
      pcVar8 = (char *)0x0;
      iVar3 = *(int *)(param_1[0x4dc] + 0x28);
      if (iVar2 < 0x84) {
        pcVar8 = *(char **)(Process_fields + (long)iVar2 * 0x20);
      }
      puVar7 = malloc(0x18);
      if (puVar7 != (undefined8 *)0x0) {
        *puVar7 = ListItem_class;
        pcVar8 = strdup(pcVar8);
        if (pcVar8 != (char *)0x0) {
          *(int *)(puVar7 + 2) = iVar2;
          lVar4 = param_1[0x4dc];
          puVar7[1] = pcVar8;
          *(undefined1 *)((long)puVar7 + 0x14) = 0;
          Vector_insert(*(undefined8 **)(lVar4 + 0x20),iVar3,puVar7);
          a0 = (long *)param_1[0x4dc];
          uVar5 = iVar3 + 1;
          *(undefined1 *)(lVar4 + 0x48) = 1;
          uVar1 = *(int *)(a0[4] + 0x18) - 1;
          if (*(int *)(a0[4] + 0x18) <= (int)uVar5) {
            uVar5 = uVar1;
          }
          if ((int)uVar5 < 0) {
            uVar5 = 0;
          }
          *(uint *)(a0 + 5) = uVar5;
          if (*(code **)(*a0 + 0x20) != (code *)0x0) {
            (**(code **)(*a0 + 0x20))((long)a0,0xffffffff,0,(ulong)uVar1,param_r8,param_r9);
            a0 = (long *)param_1[0x4dc];
          }
          ColumnsPanel_update((long)a0);
          return 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
  }
  else if (param_2 - 1 < 0xfe) {
    ppuVar6 = __ctype_b_loc();
    if (-1 < (short)(*ppuVar6)[(int)param_2]) {
      return 2;
    }
    uVar9 = Panel_selectByTyping
                      (param_1,param_2,(long)(int)param_2,(long)*ppuVar6,param_r8,param_r9);
    return uVar9;
  }
  return 2;
}


/* FUN_0011a490 @ 0x11a490 */

/* WARNING: Removing unreachable block (ram,0x0011a551) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011a56e */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_0011a490(long *param_1)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  uint uVar1;
  wchar_t __wc;
  ulong *puVar2;
  long *plVar3;
  long *a0;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 *__ptr;
  size_t sVar9;
  undefined8 *puVar10;
  char *pcVar11;
  void *pvVar12;
  long *plVar13;
  undefined8 *puVar14;
  passwd *ppVar15;
  undefined1 *a3;
  long lVar16;
  int iVar17;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong uVar18;
  ulong extraout_RDX_01;
  ulong a2;
  ulong extraout_RDX_02;
  long extraout_RDX_03;
  wchar_t *pwVar19;
  undefined8 *puVar20;
  ulong a1;
  undefined8 *puVar21;
  long a4;
  undefined1 *a5;
  undefined1 (*pauVar22) [16];
  ulong uVar23;
  long lVar24;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar20 = &(*(undefined8 *)(__fp - 0x88));
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(undefined8 *)(__fp - 0x48)) = 0;
  (*(char * *)(__fp - 0x58)) = ((char *)(long)&s_Show_001473d6 /* "Show   " */);
  (*(char * *)(__fp - 0x50)) = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(long * *)(__fp - 0x78)) = param_1;
  puVar8 = FunctionBar_new(&(*(char * *)(__fp - 0x58)),(long)&PTR_s_Enter_001565c0,(long)&DAT_0014d258);
  __ptr = malloc(0x26e0);
  if (__ptr != (undefined8 *)0x0) {
    a4 = 0;
    a5 = ListItem_class;
    a3 = (undefined1 *)0x0;
    *__ptr = Panel_class;
    Panel_init((long)__ptr,0,0,0,0,ListItem_class,1,puVar8);
    uVar1 = *(uint *)(CRT_colors + 0x1c);
    (*(undefined8 * *)(__fp - 0x60)) = &(*(undefined8 *)(__fp - 0x88));
    pwVar19 = (*(wchar_t (*)[16])(__fp - 0xd8));
    (*(undefined8 * *)(__fp - 0x60)) = &(*(undefined8 *)(__fp - 0x88));
    sVar9 = mbstowcs((*(wchar_t (*)[16])(__fp - 0xd8)),((char *)(long)&s_Show_processes_of__001473de /* "Show processes of:" */),0x12);
    iVar6 = (int)sVar9;
    a1 = sVar9 & 0xffffffff;
    uVar18 = extraout_RDX;
    if (0 < iVar6) {
      FUN_00130130((int *)(__ptr + 0xc),iVar6);
      (*(undefined8 * *)(__fp - 0x68)) = __ptr;
      pauVar22 = (undefined1 (*) [16])__ptr[0xd];
      do {
        __wc = *pwVar19;
        iVar7 = iswprint(__wc);
        *(undefined16 *)(*pauVar22) = (undefined16)0x0;
        if (iVar7 == 0) {
          __wc = L'�';
        }
        pwVar19 = pwVar19 + 1;
        *(uint *)*pauVar22 = uVar1 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(*pauVar22 + 0xc)) = (undefined16)0x0;
        *(wchar_t *)(*pauVar22 + 4) = __wc;
        uVar18 = extraout_RDX_00;
        __ptr = (*(undefined8 * *)(__fp - 0x68));
        pauVar22 = (undefined1 (*) [16])(pauVar22[1] + 0xc);
      } while ((*(wchar_t (*)[16])(__fp - 0xd8)) + (ulong)(iVar6 - 1) + 1 != pwVar19);
    }
    puVar20 = (*(undefined8 * *)(__fp - 0x60));
    uVar23 = 0;
    *(undefined1 *)(__ptr + 9) = 1;
    lVar24 = *(*(long * *)(__fp - 0x78));
    puVar2 = (ulong *)**(long **)(lVar24 + 0x80);
    if (*puVar2 != 0) {
      do {
        (*(long *)(__fp - 0x80)) = lVar24;
        uVar18 = puVar2[1];
        puVar8 = (undefined4 *)(uVar18 + uVar23 * 0x18);
        pcVar11 = *(char **)(puVar8 + 4);
        if (pcVar11 != (char *)0x0) {
          (*(undefined8 * *)(__fp - 0x60)) = (undefined8 *)CONCAT44((*(uint *)((char *)&(*(undefined8 * *)(__fp - 0x60)) + 4)),*puVar8);
          puVar10 = malloc(0x18);
          if (puVar10 == (undefined8 *)0x0) goto LAB_0011a84b;
          a3 = ListItem_class;
          *puVar10 = ListItem_class;
          pcVar11 = strdup(pcVar11);
          if (pcVar11 == (char *)0x0) goto LAB_0011a84b;
          plVar3 = (long *)__ptr[4];
          puVar10[1] = pcVar11;
          *(undefined1 *)((long)puVar10 + 0x14) = 0;
          iVar6 = (int)plVar3[3];
          lVar24 = plVar3[2];
          a1 = (ulong)(int)lVar24;
          *(int *)(puVar10 + 2) = (int)(*(undefined8 * *)(__fp - 0x60));
          pvVar12 = (void *)*plVar3;
          iVar7 = iVar6 + 1;
          uVar18 = extraout_RDX_01;
          a5 = (undefined1 *)((long)iVar6 << 3);
          if ((int)lVar24 < iVar7) {
            iVar17 = iVar7 + *(int *)((long)plVar3 + 0x14);
            a3 = (undefined1 *)0x8;
            *(int *)(plVar3 + 2) = iVar17;
            (*(undefined8 * *)(__fp - 0x60)) = (undefined8 *)CONCAT44((*(uint *)((char *)&(*(undefined8 * *)(__fp - 0x60)) + 4)),iVar7);
            (*(int *)(__fp - 0x6c)) = iVar6;
            (*(undefined8 * *)(__fp - 0x68)) = (undefined8 *)((long)iVar6 << 3);
            pvVar12 = xReallocArrayZero(pvVar12,a1,(long)iVar17,8);
            a5 = (undefined1 *)(*(undefined8 * *)(__fp - 0x68));
            *plVar3 = (long)pvVar12;
            uVar18 = a2;
            iVar7 = (int)(*(undefined8 * *)(__fp - 0x60));
            if ((int)plVar3[3] <= (*(int *)(__fp - 0x6c))) goto LAB_0011a630;
            plVar13 = (long *)((long)pvVar12 + (long)(*(undefined8 * *)(__fp - 0x68)));
            (*(undefined8 * *)(__fp - 0x60)) = (*(undefined8 * *)(__fp - 0x68));
            if ((*(char *)((long)plVar3 + 0x24) != '\0') &&
               (a0 = (long *)*plVar13, a0 != (long *)0x0)) {
              pcVar4 = *(code **)(*a0 + 0x10);
              (*pcVar4)((long)a0,a1,a2,(long)a3,a4,(long)a5);
              plVar13 = (long *)((long)(*(undefined8 * *)(__fp - 0x60)) + *plVar3);
              uVar18 = extraout_RDX_02;
            }
          }
          else {
LAB_0011a630:
            *(int *)(plVar3 + 3) = iVar7;
            plVar13 = (long *)((long)pvVar12 + (long)a5);
          }
          *plVar13 = (long)puVar10;
          *(undefined1 *)(__ptr + 9) = 1;
        }
        uVar23 = uVar23 + 1;
        lVar24 = (*(long *)(__fp - 0x80));
      } while (uVar23 < *puVar2);
    }
    plVar3 = (long *)__ptr[4];
    Vector_insertionSort(plVar3,a1,uVar18,(long)a3,a4,(long)a5);
    puVar10 = malloc(0x18);
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = ListItem_class;
      pcVar11 = strdup(((char *)(long)&s_All_users_001473f1 /* "All users" */));
      if (pcVar11 != (char *)0x0) {
        puVar10[1] = pcVar11;
        puVar21 = (undefined8 *)__ptr[4];
        *(undefined4 *)(puVar10 + 2) = 0xffffffff;
        *(undefined1 *)((long)puVar10 + 0x14) = 0;
        Vector_insert(puVar21,0,puVar10);
        plVar3 = (*(long * *)(__fp - 0x78));
        *(undefined1 *)(__ptr + 9) = 1;
        lVar16 = 0;
        puVar21 = __ptr;
        puVar14 = (undefined8 *)Action_pickFromVector(plVar3,(long)__ptr,0x13,'\0',a4,(long)a5);
        if (puVar14 != (undefined8 *)0x0) {
          if (puVar14 != puVar10) {
            pcVar11 = (char *)puVar14[1];
            ppVar15 = getpwnam(pcVar11);
            if (ppVar15 != (passwd *)0x0) {
              *(__uid_t *)(lVar24 + 0x90) = ppVar15->pw_uid;
              goto LAB_0011a7de;
            }
          }
          *(undefined4 *)(lVar24 + 0x90) = 0xffffffff;
        }
LAB_0011a7de:
        pvVar12 = (void *)__ptr[7];
        free(pvVar12);
        plVar3 = (long *)__ptr[4];
        Vector_delete(plVar3,(long)puVar21,extraout_RDX_03,lVar16,a4,(long)a5);
        piVar5 = (int *)__ptr[0xb];
        FunctionBar_delete(piVar5);
        if (0x15e < *(int *)(__ptr + 0xc)) {
          pvVar12 = (void *)__ptr[0xd];
          free(pvVar12);
        }
        free(__ptr);
        if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
          return 0x61;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
    }
  }
LAB_0011a84b:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0011a860 @ 0x11a860 */

undefined8
FUN_0011a860(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  int *__ptr;
  undefined8 *puVar4;
  void *pvVar5;
  char *pcVar6;
  long extraout_RDX;
  long lVar7;

  plVar1 = (long *)*param_1;
  uVar2 = param_1[2];
  lVar3 = *plVar1;
  __ptr = malloc(0x48);
  if (__ptr != (int *)0x0) {
    __ptr[0] = 0;
    __ptr[1] = 0;
    __ptr[2] = 0;
    __ptr[3] = -1;
    puVar4 = malloc(0x28);
    if (puVar4 != (undefined8 *)0x0) {
      *(undefined4 *)((long)puVar4 + 0x14) = 10;
      pvVar5 = calloc(10,8);
      if (pvVar5 != (void *)0x0) {
        *puVar4 = pvVar5;
        *(undefined4 *)(puVar4 + 2) = 10;
        puVar4[1] = Panel_class;
        *(undefined1 *)((long)puVar4 + 0x24) = 1;
        puVar4[3] = 0xffffffff00000000;
        *(undefined4 *)(puVar4 + 4) = 0;
        *(undefined8 **)(__ptr + 4) = puVar4;
        __ptr[8] = 0;
        *(undefined8 **)(__ptr + 0xe) = param_1;
        *(undefined1 *)(__ptr + 0x10) = 1;
        *(undefined8 *)(__ptr + 10) = uVar2;
        *(long **)(__ptr + 0xc) = plVar1;
        CategoriesPanel_new(__ptr,uVar2,plVar1);
        lVar7 = 0;
        pcVar6 = ((char *)(long)&s_Setup_001473fb /* "Setup" */);
        ScreenManager_run(__ptr,(undefined8 *)0x0,(uint *)0x0,((char *)(long)&s_Setup_001473fb /* "Setup" */),param_r8,param_r9);
        Vector_delete(*(long **)(__ptr + 4),lVar7,extraout_RDX,(long)pcVar6,param_r8,param_r9);
        free(__ptr);
        if (*(char *)(lVar3 + 0x74) != '\0') {
          if (*(char *)(lVar3 + 0x6f) == '\0') {
            mousemask(0,(ulong *)0x0);
          }
          else {
            mousemask(0x210001,(ulong *)0x0);
          }
          Header_writeBackToSettings((long *)param_1[2]);
        }
        return 0xe1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0011a9d0 @ 0x11a9d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0011a9d0(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  long extraout_RDX;
  long extraout_RDX_00;
  ulong uVar5;

  if ((CHAR____0015c0d9 == '\0') && (*(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0)) {
    plVar3 = *(long **)(param_1[1] + 0x20);
    uVar1 = *(uint *)(plVar3 + 3);
    uVar5 = (ulong)uVar1;
    if (0 < (int)uVar1) {
      lVar4 = (long)*(int *)(param_1[1] + 0x28);
      lVar2 = *(long *)(*plVar3 + lVar4 * 8);
      if (lVar2 != 0) {
        plVar3 = OpenFilesScreen_new(lVar2);
        InfoScreen_run(plVar3,uVar5,extraout_RDX,lVar4,param_r8,param_r9);
        CommandScreen_delete(plVar3,uVar5,extraout_RDX_00,lVar4,param_r8,param_r9);
        wclear(_stdscr);
        halfdelay(*PTR_0015c0d0);
        return 0x21;
      }
    }
  }
  return 0;
}


/* FUN_0011aa60 @ 0x11aa60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0011aa60(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  long extraout_RDX;
  long extraout_RDX_00;
  ulong uVar5;

  if (*(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0) {
    plVar3 = *(long **)(param_1[1] + 0x20);
    uVar1 = *(uint *)(plVar3 + 3);
    uVar5 = (ulong)uVar1;
    if (0 < (int)uVar1) {
      lVar4 = (long)*(int *)(param_1[1] + 0x28);
      lVar2 = *(long *)(*plVar3 + lVar4 * 8);
      if (lVar2 != 0) {
        plVar3 = ProcessLocksScreen_new(lVar2);
        InfoScreen_run(plVar3,uVar5,extraout_RDX,lVar4,param_r8,param_r9);
        CommandScreen_delete(plVar3,uVar5,extraout_RDX_00,lVar4,param_r8,param_r9);
        wclear(_stdscr);
        halfdelay(*PTR_0015c0d0);
        return 0x21;
      }
    }
  }
  return 0;
}


/* FUN_0011aaf0 @ 0x11aaf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0011aaf0(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  uint uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long extraout_RDX;
  long lVar5;
  long extraout_RDX_00;
  ulong uVar6;

  if ((CHAR____0015c0d9 == '\0') && (*(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0)) {
    plVar2 = *(long **)(param_1[1] + 0x20);
    uVar1 = *(uint *)(plVar2 + 3);
    uVar6 = (ulong)uVar1;
    if (0 < (int)uVar1) {
      lVar4 = (long)*(int *)(param_1[1] + 0x28);
      lVar5 = *(long *)(*plVar2 + lVar4 * 8);
      if (lVar5 != 0) {
        plVar2 = TraceScreen_new(lVar5);
        uVar3 = TraceScreen_forkTracer((long)plVar2);
        lVar5 = extraout_RDX;
        if ((char)uVar3 != '\0') {
          InfoScreen_run(plVar2,uVar6,extraout_RDX,lVar4,param_r8,param_r9);
          lVar5 = extraout_RDX_00;
        }
        TraceScreen_delete(plVar2,uVar6,lVar5,lVar4,param_r8,param_r9);
        wclear(_stdscr);
        halfdelay(*PTR_0015c0d0);
        return 0x21;
      }
    }
  }
  return 0;
}

