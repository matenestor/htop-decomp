#include "htop.h"

/* toFieldIndex @ 0x12d610 */

int toFieldIndex(Hashtable_2 *columns,char *str)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  long lVar1;
  char *__s2;
  int iVar2;
  ushort **ppuVar3;
  long lVar4;
  char *pcVar5;
  HashtableItem *pHVar6;
  ulong uVar7;
  ulong uVar8;
  ProcessFieldData *pPVar9;
  HashtableItem *pHVar10;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  ppuVar3 = __ctype_b_loc();
  if ((*(byte *)((long)*ppuVar3 + (long)*str * 2 + 1) & 8) == 0) {
    (*(char (*) [32])(__fp - 0x68))[0] = '\0';
    (*(char (*) [32])(__fp - 0x68))[1] = '\0';
    (*(char (*) [32])(__fp - 0x68))[2] = '\0';
    (*(char (*) [32])(__fp - 0x68))[3] = '\0';
    (*(char (*) [32])(__fp - 0x68))[4] = '\0';
    (*(char (*) [32])(__fp - 0x68))[5] = '\0';
    (*(char (*) [32])(__fp - 0x68))[6] = '\0';
    (*(char (*) [32])(__fp - 0x68))[7] = '\0';
    (*(char (*) [32])(__fp - 0x68))[8] = '\0';
    (*(char (*) [32])(__fp - 0x68))[9] = '\0';
    (*(char (*) [32])(__fp - 0x68))[10] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0xb] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0xc] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0xd] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0xe] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0xf] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x10] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x11] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x12] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x13] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x14] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x15] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x16] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x17] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x18] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x19] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x1a] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x1b] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x1c] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x1d] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x1e] = '\0';
    (*(char (*) [32])(__fp - 0x68))[0x1f] = '\0';
    iVar2 = __isoc23_sscanf(str,((char *)(long)&s_Dynamic__30s__00148bfc /* "Dynamic(%30s)" */),(*(char (*) [32])(__fp - 0x68)));
    if ((iVar2 != 0) && (pcVar5 = strrchr((*(char (*) [32])(__fp - 0x68)),0x29), pcVar5 != (char *)0x0)) {
      *pcVar5 = '\0';
      if ((columns == (Hashtable_2 *)0x0) || (columns->size == 0)) {
        *pcVar5 = ')';
      }
      else {
        pHVar10 = columns->buckets;
        (*(int (*))(__fp - 0x74)) = 0;
        (*(char *(*))(__fp - 0x80)) = (char *)0x0;
        pHVar6 = pHVar10 + columns->size;
        do {
          __s2 = pHVar10->value;
          if ((__s2 != (char *)0x0) && (iVar2 = strcmp((*(char (*) [32])(__fp - 0x68)),__s2), iVar2 == 0)) {
            (*(int (*))(__fp - 0x74)) = pHVar10->key;
            (*(char *(*))(__fp - 0x80)) = __s2;
          }
          pHVar10 = pHVar10 + 1;
        } while (pHVar10 != pHVar6);
        *pcVar5 = ')';
        if ((*(char *(*))(__fp - 0x80)) != (char *)0x0) goto LAB_0012d68a;
      }
    }
                    /* Unresolved local var: int p@[???] */
                    /* Unresolved local var: char * end@[???]
                       Unresolved local var: _Bool success@[???]
                       Unresolved local var: uint key@[???]
                       Unresolved local var: DynamicIterator_conflict iter@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: DynamicIterator_conflict * iter@[???] */
    (*(int (*))(__fp - 0x74)) = 1;
    pPVar9 = Process_fields;
    do {
      pPVar9 = pPVar9 + 1;
                    /* Unresolved local var: char * pName@[???] */
      if ((pPVar9->name != (char *)0x0) && (iVar2 = strcmp(pPVar9->name,str), iVar2 == 0))
      goto LAB_0012d68a;
      (*(int (*))(__fp - 0x74)) = (*(int (*))(__fp - 0x74)) + 1;
    } while ((*(int (*))(__fp - 0x74)) != 132);
  }
  else {
                    /* Unresolved local var: int id@[???] */
    lVar4 = __isoc23_strtol(str,(char **)0x0,10);
    (*(int (*))(__fp - 0x74)) = (int)lVar4 + 1;
    if (-1 < (*(int (*))(__fp - 0x74))) {
      if ((*(int (*))(__fp - 0x74)) < 132) {
        if (Process_fields[(*(int (*))(__fp - 0x74))].name != (char *)0x0) goto LAB_0012d68a;
      }
      else {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pHVar10 = columns->buckets;
        uVar8 = (ulong)(long)(*(int (*))(__fp - 0x74)) % columns->size;
        pHVar6 = pHVar10 + uVar8;
        if (pHVar6->value != (void *)0x0) {
          uVar7 = 0;
          do {
            if ((*(int (*))(__fp - 0x74)) == pHVar6->key) goto LAB_0012d68a;
            if (pHVar6->probe < uVar7) break;
            uVar8 = uVar8 + 1;
            if (columns->size == uVar8) {
              uVar8 = 0;
              pHVar6 = pHVar10;
            }
            else {
              pHVar6 = pHVar10 + uVar8;
            }
            uVar7 = uVar7 + 1;
          } while (pHVar6->value != (void *)0x0);
        }
      }
    }
  }
  (*(int (*))(__fp - 0x74)) = -1;
LAB_0012d68a:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int (*))(__fp - 0x74));
}


/* writeFields @ 0x12d840 */

void writeFields(FILE *fd,ProcessField *fields,Hashtable_2 *columns,_Bool byName,char separator)

{
  ht_key_t hVar1;
  HashtableItem *pHVar2;
  ulong uVar3;
  HashtableItem *pHVar4;
  ulong uVar5;
  undefined *va0;
  ulong uVar6;
  void *va1;
  char *va1_00;

                    /* Unresolved local var: char * sep@[???]
                       Unresolved local var: uint i@[???] */
  hVar1 = *fields;
  if (hVar1 != 0) {
    uVar3 = 0;
    va0 = &DAT_00149c0c;
    do {
      if ((int)hVar1 < 0x84) {
        if (byName) {
                    /* Unresolved local var: char * pName@[???] */
          if ((int)hVar1 < 0) {
            va1_00 = (char *)0x0;
          }
          else {
            va1_00 = Process_fields[(int)hVar1].name;
          }
          __fprintf_chk(fd,2,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),va0,va1_00);
        }
        else {
LAB_0012d891:
          __fprintf_chk(fd,2,((char *)(long)&DAT_00148c18 /* "%s%d" */),va0,hVar1 - 1);
        }
      }
      else {
        if (!byName) goto LAB_0012d891;
                    /* Unresolved local var: _Bool enabled@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pHVar2 = columns->buckets;
        uVar5 = (ulong)(long)(int)hVar1 % columns->size;
        pHVar4 = pHVar2 + uVar5;
        va1 = pHVar4->value;
        if (va1 != (void *)0x0) {
          uVar6 = 0;
          do {
            if (hVar1 == pHVar4->key) {
              if (*(char *)((long)va1 + 0x3c) != '\0') {
                __fprintf_chk(fd,2,((char *)(long)&s__sDynamic__s__00148c0a /* "%sDynamic(%s)" */),va0,va1);
              }
              break;
            }
            if (pHVar4->probe < uVar6) break;
            uVar5 = uVar5 + 1;
            if (columns->size == uVar5) {
              uVar5 = 0;
              pHVar4 = pHVar2;
            }
            else {
              pHVar4 = pHVar2 + uVar5;
            }
            va1 = pHVar4->value;
            uVar6 = uVar6 + 1;
          } while (va1 != (void *)0x0);
        }
      }
      uVar3 = (ulong)((int)uVar3 + 1);
      va0 = &DAT_001470dd;
      hVar1 = fields[uVar3];
    } while (hVar1 != 0);
  }
  fputc((int)separator,(FILE_2 *)fd);
  return;
}


/* ScreenSettings_delete @ 0x12df60 */

/* DWARF original prototype: void ScreenSettings_delete(ScreenSettings * this) */

void ScreenSettings_delete(ScreenSettings *this)

{
  free(this->heading);
  free(this->dynamic);
  free(this->fields);
  free(this);
  return;
}


/* Settings_delete @ 0x12dfd0 */

/* DWARF original prototype: void Settings_delete(Settings * this) */

void Settings_delete(Settings *this)

{
  char **__ptr;
  char *__ptr_00;
  MeterColumnSetting *pMVar1;
  ulong uVar2;
  long lVar3;
  ScreenSettings_5 *__ptr_01;
  ScreenSettings_5 **__ptr_02;
  char **ppcVar4;

  lVar3 = 0;
  free(this->filename);
                    /* Unresolved local var: uint i@[???] */
  if (HeaderLayout_layouts[this->hLayout].columns != '\0') {
    do {
      pMVar1 = this->hColumns + lVar3;
      __ptr = pMVar1->names;
      if (__ptr != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
        __ptr_00 = *__ptr;
        ppcVar4 = __ptr;
        while (__ptr_00 != (char *)0x0) {
          ppcVar4 = ppcVar4 + 1;
          free(__ptr_00);
          __ptr_00 = *ppcVar4;
        }
        free(__ptr);
        pMVar1 = this->hColumns + lVar3;
      }
      lVar3 = lVar3 + 1;
      free(pMVar1->modes);
    } while ((uint)lVar3 < (uint)HeaderLayout_layouts[this->hLayout].columns);
  }
  free(this->hColumns);
  __ptr_02 = this->screens;
  if (__ptr_02 != (ScreenSettings_5 **)0x0) {
                    /* Unresolved local var: uint i@[???] */
    __ptr_01 = *__ptr_02;
    if (__ptr_01 != (ScreenSettings_5 *)0x0) {
      uVar2 = 0;
      do {
        free(__ptr_01->heading);
        free(__ptr_01->dynamic);
        free(__ptr_01->fields);
        free(__ptr_01);
        __ptr_02 = this->screens;
        uVar2 = (ulong)((int)uVar2 + 1);
        __ptr_01 = __ptr_02[uVar2];
      } while (__ptr_01 != (ScreenSettings_5 *)0x0);
    }
    free(__ptr_02);
  }
  free(this);
  return;
}


/* ScreenSettings_invertSortOrder @ 0x12e150 */

/* DWARF original prototype: void ScreenSettings_invertSortOrder(ScreenSettings * this) */

void ScreenSettings_invertSortOrder(ScreenSettings *this)

{
  bool bVar1;

  if (this->treeView != false) {
    bVar1 = this->treeDirection != 1;
    this->treeDirection = (bVar1 - 1) + (uint)bVar1;
    return;
  }
  bVar1 = this->direction != 1;
  this->direction = (bVar1 - 1) + (uint)bVar1;
  return;
}


/* ScreenSettings_setSortKey @ 0x12e190 */

/* DWARF original prototype: void ScreenSettings_setSortKey(ScreenSettings * this, ProcessField
   sortKey) */

void ScreenSettings_setSortKey(ScreenSettings *this,ProcessField sortKey)

{
  _Bool _Var1;

  _Var1 = Process_fields[sortKey].defaultSortDesc;
  if ((this->treeViewAlwaysByPID == false) && (this->treeView != false)) {
    this->treeSortKey = sortKey;
    this->treeDirection = (-(uint)(_Var1 == false) & 2) + -1;
    return;
  }
  this->sortKey = sortKey;
  this->treeView = false;
  this->direction = (-(uint)(_Var1 == false) & 2) + -1;
  return;
}


/* Settings_enableReadonly @ 0x12e1f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Settings_enableReadonly(void)

{
  readonly = true;
  return;
}


/* Settings_isReadonly @ 0x12e200 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool Settings_isReadonly(void)

{
  return readonly;
}


/* Settings_write @ 0x12ed00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: int Settings_write(Settings * this, _Bool onCrash) */

int Settings_write(Settings *this,_Bool onCrash)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  undefined8 *puVar1;
  uint va0;
  ht_key_t hVar2;
  long lVar3;
  void *va1;
  ScreenSettings_5 *pSVar4;
  Hashtable_2 *pHVar5;
  HashtableItem *pHVar6;
  int iVar7;
  int iVar8;
  ulong *puVar9;
  HashtableItem *pHVar10;
  int *piVar11;
  FILE_2 *__stream;
  undefined *puVar12;
  long *plVar13;
  ulong uVar14;
  char *va1_00;
  int wVar15;
  long lVar16;
  char *va1_01;
  undefined8 *puVar17;
  ulong uVar18;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*))(__fp - 0x48)) = (char *)0x0;
  if (onCrash) {
    iVar8 = 0x3b;
    __stream = _stderr;
  }
  else {
                    /* Unresolved local var: int fdtmp@[???] */
    xAsprintf(&(*(char *(*))(__fp - 0x48)),((char *)(long)&s__s_tmp_XXXXXX_00148c3f /* "%s.tmp.XXXXXX" */),this->filename);
    iVar8 = mkstemp((*(char *(*))(__fp - 0x48)));
    if ((iVar8 == -1) || (__stream = fdopen(iVar8,((char *)(long)&DAT_001491b9 /* "w" */)), __stream == (FILE_2 *)0x0)) {
      piVar11 = __errno_location();
      wVar15 = -*piVar11;
      goto LAB_0012f73c;
    }
    __fprintf_chk(__stream,2,
                  ((char *)(long)&s___Beware__This_file_is_rewritten_0014c710 /* "# Beware! This file is rewritten by htop when settings are changed in the interface.\n" */)
                 );
    iVar8 = 10;
    __fprintf_chk(__stream,2,((char *)(long)&s___The_parser_is_also_very_primit_0014c768 /* "# The parser is also very primitive, and not human-friendly.\n" */));
  }
  __fprintf_chk(__stream,2,((char *)(long)&s_htop_version__s_c_00148c53 /* "htop_version=%s%c" */),((char *)(long)&s_3_3_0_00148c4d /* "3.3.0" */),iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_config_reader_min_version__d_c_0014c7a8 /* "config_reader_min_version=%d%c" */),3,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_fields__00148c65 /* "fields=" */));
  writeFields((FILE *)__stream,(*this->screens)->fields,this->dynamicColumns,false,(char)iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_kernel_threads__d_c_00148c6d /* "hide_kernel_threads=%d%c" */),(uint)this->hideKernelThreads,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_userland_threads__d_c_00148c86 /* "hide_userland_threads=%d%c" */),(uint)this->hideUserlandThreads,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_running_in_container__d_c_0014c7c8 /* "hide_running_in_container=%d%c" */),(uint)this->hideRunningInContainer,iVar8
               );
  __fprintf_chk(__stream,2,((char *)(long)&s_shadow_other_users__d_c_00148ca1 /* "shadow_other_users=%d%c" */),(uint)this->shadowOtherUsers,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_thread_names__d_c_00148cb9 /* "show_thread_names=%d%c" */),(uint)this->showThreadNames,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_program_path__d_c_00148cd0 /* "show_program_path=%d%c" */),(uint)this->showProgramPath,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_base_name__d_c_00148ce7 /* "highlight_base_name=%d%c" */),(uint)this->highlightBaseName,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_deleted_exe__d_c_00148d00 /* "highlight_deleted_exe=%d%c" */),(uint)this->highlightDeletedExe,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_shadow_distribution_path_prefix__0014c7e8 /* "shadow_distribution_path_prefix=%d%c" */),(uint)this->shadowDistPathPrefix,
                iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_megabytes__d_c_00148d1b /* "highlight_megabytes=%d%c" */),(uint)this->highlightMegabytes,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_threads__d_c_00148d34 /* "highlight_threads=%d%c" */),(uint)this->highlightThreads,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_changes__d_c_00148d4b /* "highlight_changes=%d%c" */),(uint)this->highlightChanges,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_changes_delay_secs__d__0014c810 /* "highlight_changes_delay_secs=%d%c" */),this->highlightDelaySecs,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_find_comm_in_cmdline__d_c_00148d62 /* "find_comm_in_cmdline=%d%c" */),(uint)this->findCommInCmdline,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_strip_exe_from_cmdline__d_c_00148d7c /* "strip_exe_from_cmdline=%d%c" */),(uint)this->stripExeFromCmdline,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_merged_command__d_c_00148d98 /* "show_merged_command=%d%c" */),(uint)this->showMergedCommand,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_header_margin__d_c_00148db1 /* "header_margin=%d%c" */),(uint)this->headerMargin,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_screen_tabs__d_c_00148dc4 /* "screen_tabs=%d%c" */),(uint)this->screenTabs,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_detailed_cpu_time__d_c_00148dd5 /* "detailed_cpu_time=%d%c" */),(uint)this->detailedCPUTime,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_cpu_count_from_one__d_c_00148dec /* "cpu_count_from_one=%d%c" */),(uint)this->countCPUsFromOne,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_cpu_usage__d_c_00148e04 /* "show_cpu_usage=%d%c" */),(uint)this->showCPUUsage,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_cpu_frequency__d_c_00148e18 /* "show_cpu_frequency=%d%c" */),(uint)this->showCPUFrequency,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_cpu_temperature__d_c_00148e30 /* "show_cpu_temperature=%d%c" */),(uint)this->showCPUTemperature,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_degree_fahrenheit__d_c_00148e4a /* "degree_fahrenheit=%d%c" */),(uint)this->degreeFahrenheit,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_update_process_names__d_c_00148e61 /* "update_process_names=%d%c" */),(uint)this->updateProcessNames,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_account_guest_in_cpu_meter__d_c_0014c838 /* "account_guest_in_cpu_meter=%d%c" */),(uint)this->accountGuestInCPUMeter,
                iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_color_scheme__d_c_00148e7b /* "color_scheme=%d%c" */),this->colorScheme,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_enable_mouse__d_c_00148e8d /* "enable_mouse=%d%c" */),(uint)this->enableMouse,iVar8);
                    /* Unresolved local var: uint i@[???] */
  lVar16 = 0;
  __fprintf_chk(__stream,2,((char *)(long)&s_delay__d_c_00148e9f /* "delay=%d%c" */),this->delay,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_function_bar__d_c_00148eaa /* "hide_function_bar=%d%c" */),this->hideFunctionBar,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_header_layout__s_c_00148ec1 /* "header_layout=%s%c" */),HeaderLayout_layouts[this->hLayout].name,iVar8);
  if (HeaderLayout_layouts[this->hLayout].columns != '\0') {
    va0 = 0;
    do {
      __fprintf_chk(__stream,2,((char *)(long)&s_column_meters__u__00148ee7 /* "column_meters_%u=" */),va0);
      plVar13 = (long *)((long)&this->hColumns->len + lVar16);
      lVar3 = *plVar13;
      if (lVar3 == 0) {
        fputc(0x21,__stream);
      }
      else {
        puVar17 = (undefined8 *)plVar13[1];
                    /* Unresolved local var: char * sep@[???]
                       Unresolved local var: int i@[???] */
        iVar7 = (int)lVar3;
        if (0 < iVar7) {
          puVar12 = &DAT_00149c0c;
          puVar1 = puVar17 + (ulong)(iVar7 - 1) + 1;
          do {
            va1 = (void *)*puVar17;
            puVar17 = puVar17 + 1;
            __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),puVar12,va1);
            puVar12 = &DAT_001470dd;
          } while (puVar1 != puVar17);
        }
      }
      fputc(iVar8,__stream);
      __fprintf_chk(__stream,2,((char *)(long)&s_column_meter_modes__u__00148ef9 /* "column_meter_modes_%u=" */),va0);
      puVar9 = (ulong *)((long)&this->hColumns->len + lVar16);
      if (*puVar9 == 0) {
        fputc(0x21,__stream);
      }
      else {
                    /* Unresolved local var: char * sep@[???] */
        puVar12 = &DAT_00149c0c;
                    /* Unresolved local var: size_t i@[???] */
        uVar18 = 0;
        do {
          lVar3 = uVar18 * 4;
          uVar18 = uVar18 + 1;
          __fprintf_chk(__stream,2,((char *)(long)&DAT_00148c18 /* "%s%d" */),puVar12,*(int *)(puVar9[2] + lVar3));
          puVar12 = &DAT_001470dd;
          puVar9 = (ulong *)((long)&this->hColumns->len + lVar16);
        } while (uVar18 < *puVar9);
      }
      lVar16 = lVar16 + 0x18;
      fputc(iVar8,__stream);
      va0 = va0 + 1;
    } while (va0 < HeaderLayout_layouts[this->hLayout].columns);
  }
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1f95) /* "tree_view=%d%c" */),(uint)(*this->screens)->treeView,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1ed9) /* "sort_key=%d%c" */),(*this->screens)->sortKey + -1,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)&s_tree_sort_key__d_c_00148ed4 /* "tree_sort_key=%d%c" */),(*this->screens)->treeSortKey + -1,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1fa5) /* "sort_direction=%d%c" */),(*this->screens)->direction,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1fba) /* "tree_sort_direction=%d%c" */),(*this->screens)->treeDirection,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1f77) /* "tree_view_always_by_pid=%d%c" */),
                (uint)(*this->screens)->treeViewAlwaysByPID,iVar8);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1fd4) /* "all_branches_collapsed=%d%c" */),
                (uint)(*this->screens)->allBranchesCollapsed,iVar8);
                    /* Unresolved local var: uint i@[???] */
  if (this->nScreens != 0) {
    (*(long (*))(__fp - 0x50)) = 0;
    do {
      pSVar4 = this->screens[(*(long (*))(__fp - 0x50))];
      pHVar5 = this->dynamicColumns;
      hVar2 = pSVar4->sortKey;
      if ((int)hVar2 < 0) {
LAB_0012f720:
        va1_00 = (char *)0x0;
      }
      else if ((int)hVar2 < 0x84) {
        va1_00 = Process_fields[(int)hVar2].name;
      }
      else {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pHVar6 = pHVar5->buckets;
        uVar18 = (ulong)(long)(int)hVar2 % pHVar5->size;
        pHVar10 = pHVar6 + uVar18;
        va1_00 = pHVar10->value;
        if (va1_00 != (char *)0x0) {
          uVar14 = 0;
          do {
            if (hVar2 == pHVar10->key) break;
            if (pHVar10->probe < uVar14) goto LAB_0012f720;
            uVar18 = uVar18 + 1;
            if (pHVar5->size == uVar18) {
              uVar18 = 0;
              pHVar10 = pHVar6;
            }
            else {
              pHVar10 = pHVar6 + uVar18;
            }
            va1_00 = pHVar10->value;
            uVar14 = uVar14 + 1;
          } while (va1_00 != (char *)0x0);
        }
      }
      hVar2 = pSVar4->treeSortKey;
      if ((int)hVar2 < 0) {
LAB_0012f710:
        va1_01 = (char *)0x0;
      }
      else if ((int)hVar2 < 0x84) {
        va1_01 = Process_fields[(int)hVar2].name;
      }
      else {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pHVar6 = pHVar5->buckets;
        uVar18 = (ulong)(long)(int)hVar2 % pHVar5->size;
        pHVar10 = pHVar6 + uVar18;
        va1_01 = pHVar10->value;
        if (va1_01 != (char *)0x0) {
          uVar14 = 0;
          do {
            if (hVar2 == pHVar10->key) break;
            if (pHVar10->probe < uVar14) goto LAB_0012f710;
            uVar18 = uVar18 + 1;
            if (pHVar5->size == uVar18) {
              uVar18 = 0;
              pHVar10 = pHVar6;
            }
            else {
              pHVar10 = pHVar6 + uVar18;
            }
            va1_01 = pHVar10->value;
            uVar14 = uVar14 + 1;
          } while (va1_01 != (char *)0x0);
        }
      }
      __fprintf_chk(__stream,2,((char *)(long)&s_screen__s__00148f10 /* "screen:%s=" */),pSVar4->heading);
      writeFields((FILE *)__stream,pSVar4->fields,this->dynamicColumns,true,(char)iVar8);
      if (pSVar4->dynamic == (char *)0x0) {
        __fprintf_chk(__stream,2,((char *)(long)&s__sort_key__s_c_00148f53 /* ".sort_key=%s%c" */),va1_00,iVar8);
        __fprintf_chk(__stream,2,((char *)(long)&s__tree_sort_key__s_c_00148f62 /* ".tree_sort_key=%s%c" */),va1_01,iVar8);
        __fprintf_chk(__stream,2,((char *)(long)&s__tree_view_always_by_pid__d_c_00148f76 /* ".tree_view_always_by_pid=%d%c" */),(uint)pSVar4->treeViewAlwaysByPID,
                      iVar8);
      }
      else {
                    /* Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: char * sortKey@[???]
                       Unresolved local var: char * treeSortKey@[???] */
        __fprintf_chk(__stream,2,((char *)(long)&s__dynamic__s_c_00148f1b /* ".dynamic=%s%c" */),pSVar4->dynamic,iVar8);
        if (1 < (uint)pSVar4->sortKey) {
          __fprintf_chk(__stream,2,((char *)(long)&s__s_Dynamic__s__c_00148f33 /* "%s=Dynamic(%s)%c" */),((char *)(long)&s__sort_key_00148f29 /* ".sort_key" */),va1_00,iVar8);
        }
        if (1 < (uint)pSVar4->treeSortKey) {
          __fprintf_chk(__stream,2,((char *)(long)&s__s_Dynamic__s__c_00148f33 /* "%s=Dynamic(%s)%c" */),((char *)(long)&s__tree_sort_key_00148f44 /* ".tree_sort_key" */),va1_01,iVar8);
        }
      }
      __fprintf_chk(__stream,2,((char *)(long)&s__tree_view__d_c_00148f94 /* ".tree_view=%d%c" */),(uint)pSVar4->treeView,iVar8);
      __fprintf_chk(__stream,2,((char *)(long)&s__sort_direction__d_c_00148fa4 /* ".sort_direction=%d%c" */),pSVar4->direction,iVar8);
      __fprintf_chk(__stream,2,((char *)(long)&s__tree_sort_direction__d_c_00148fb9 /* ".tree_sort_direction=%d%c" */),pSVar4->treeDirection,iVar8);
      __fprintf_chk(__stream,2,((char *)(long)&s__all_branches_collapsed__d_c_00148fd3 /* ".all_branches_collapsed=%d%c" */),(uint)pSVar4->allBranchesCollapsed,
                    iVar8);
      (*(long (*))(__fp - 0x50)) = (*(long (*))(__fp - 0x50)) + 1;
    } while ((uint)(*(long (*))(__fp - 0x50)) < this->nScreens);
  }
  wVar15 = 0;
  if (onCrash) goto LAB_0012f73c;
  iVar8 = ferror(__stream);
  if (iVar8 == 0) {
    iVar8 = fclose(__stream);
    if (iVar8 != 0) {
      piVar11 = __errno_location();
      wVar15 = -*piVar11;
      if (wVar15 != 0) goto LAB_0012f828;
    }
    wVar15 = 0;
    iVar8 = rename((*(char *(*))(__fp - 0x48)),this->filename);
    if (iVar8 == -1) {
      piVar11 = __errno_location();
      wVar15 = -*piVar11;
    }
  }
  else {
    piVar11 = __errno_location();
    if (*piVar11 == 0) {
      wVar15 = -9;
      fclose(__stream);
    }
    else {
      wVar15 = -*piVar11;
      fclose(__stream);
    }
  }
LAB_0012f828:
  free((*(char *(*))(__fp - 0x48)));
LAB_0012f73c:
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return wVar15;
}


/* Settings_defaultMeters @ 0x132480 */

/* DWARF original prototype: void Settings_defaultMeters(Settings * this, uint initialCpuCount) */

void Settings_defaultMeters(Settings *this,uint initialCpuCount)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  MeterColumnSetting *pMVar1;
  char **ppcVar2;
  int *pwVar3;
  char *pcVar4;
  ulong uVar5;
  int *pwVar6;
  long lVar7;
  ulong __nmemb;
  char **ppcVar8;
  MeterColumnSetting *pMVar9;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int r@[???] */
                    /* Unresolved local var: size_t i@[???] */
  (*(long (*) [2])(__fp - 0x40))[0] = *(long *)(in_FS_OFFSET + 0x28);
  (*(int (*) [2])(__fp - 0x48))[0] = 3;
  uVar5 = 0;
  (*(int (*) [2])(__fp - 0x48))[1] = (uint)(initialCpuCount - 5 < 0x7c) + 3;
  if (HeaderLayout_layouts[this->hLayout].columns != '\0') {
    do {
      pMVar1 = this->hColumns + uVar5;
      ppcVar2 = pMVar1->names;
      if (ppcVar2 != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
        pcVar4 = *ppcVar2;
        ppcVar8 = ppcVar2;
        while (pcVar4 != (char *)0x0) {
          ppcVar8 = ppcVar8 + 1;
          free(pcVar4);
          pcVar4 = *ppcVar8;
        }
        free(ppcVar2);
        pMVar1 = this->hColumns + uVar5;
      }
      uVar5 = uVar5 + 1;
      free(pMVar1->modes);
    } while (uVar5 < HeaderLayout_layouts[this->hLayout].columns);
  }
  free(this->hColumns);
                    /* Unresolved local var: void * data@[???] */
  this->hLayout = HF_TWO_50_50;
  pMVar1 = calloc(2,0x18);
  if (pMVar1 == (MeterColumnSetting *)0x0) goto LAB_0013266f;
  this->hColumns = pMVar1;
                    /* Unresolved local var: size_t i@[???] */
  pwVar6 = (*(int (*) [2])(__fp - 0x48));
  pMVar9 = pMVar1;
  do {
                    /* Unresolved local var: void * data@[???] */
    __nmemb = (ulong)*pwVar6;
    uVar5 = (ulong)(*pwVar6 + 1);
                    /* Unresolved local var: void * data@[???] */
    if ((((0x1fffffffffffffff < uVar5) || (ppcVar2 = calloc(uVar5,8), ppcVar2 == (char **)0x0)) ||
        (pMVar9->names = ppcVar2, 0x3fffffffffffffff < __nmemb)) ||
       (pwVar3 = calloc(__nmemb,4), pwVar3 == (int *)0x0)) goto LAB_0013266f;
    pMVar9->modes = pwVar3;
    pwVar6 = pwVar6 + 1;
    pMVar9->len = __nmemb;
    pMVar9 = pMVar9 + 1;
  } while (pwVar6 != (int *)(*(long (*) [2])(__fp - 0x40)));
  ppcVar2 = pMVar1->names;
  if (initialCpuCount < 0x81) {
    if (initialCpuCount < 0x21) {
      if (initialCpuCount < 0x11) {
        if (initialCpuCount < 9) {
          if (initialCpuCount < 5) {
            pcVar4 = strdup(((char *)(long)&s_AllCPUs_00147a94 /* "AllCPUs" */));
            goto joined_r0x001327ef;
          }
                    /* Unresolved local var: char * data@[???] */
          pcVar4 = strdup(((char *)(long)&s_LeftCPUs_00147ad2 /* "LeftCPUs" */));
          if (pcVar4 == (char *)0x0) goto LAB_0013266f;
          *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
          ppcVar2 = this->hColumns[1].names;
          *this->hColumns->modes = 1;
          pcVar4 = strdup(((char *)(long)&s_RightCPUs_00147ae6 /* "RightCPUs" */));
        }
        else {
                    /* Unresolved local var: char * data@[???] */
          pcVar4 = strdup(((char *)(long)&s_LeftCPUs2_00147afb /* "LeftCPUs2" */));
          if (pcVar4 == (char *)0x0) goto LAB_0013266f;
          *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
          ppcVar2 = this->hColumns[1].names;
          *this->hColumns->modes = 1;
          pcVar4 = strdup(((char *)(long)&s_RightCPUs2_00147b12 /* "RightCPUs2" */));
        }
      }
      else {
                    /* Unresolved local var: char * data@[???] */
        pcVar4 = strdup(((char *)(long)&s_LeftCPUs4_00147b44 /* "LeftCPUs4" */));
        if (pcVar4 == (char *)0x0) goto LAB_0013266f;
        *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
        ppcVar2 = this->hColumns[1].names;
        *this->hColumns->modes = 1;
        pcVar4 = strdup(((char *)(long)&s_RightCPUs4_00147b5b /* "RightCPUs4" */));
      }
    }
    else {
                    /* Unresolved local var: char * data@[???] */
      pcVar4 = strdup(((char *)(long)&s_LeftCPUs8_00147b89 /* "LeftCPUs8" */));
      if (pcVar4 == (char *)0x0) goto LAB_0013266f;
      *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
      ppcVar2 = this->hColumns[1].names;
      *this->hColumns->modes = 1;
      pcVar4 = strdup(((char *)(long)&s_RightCPUs8_00147ba1 /* "RightCPUs8" */));
    }
    if (pcVar4 == (char *)0x0) goto LAB_0013266f;
    *ppcVar2 = pcVar4;
    pMVar1 = this->hColumns;
    lVar7 = 1;
    *pMVar1[1].modes = 1;
  }
  else {
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup(((char *)(long)(__sec_rodata + 0x826) /* "CPU" */));
joined_r0x001327ef:
    if (pcVar4 == (char *)0x0) goto LAB_0013266f;
                    /* Unresolved local var: char * data@[???] */
    *ppcVar2 = pcVar4;
    pMVar1 = this->hColumns;
    lVar7 = 0;
    *pMVar1->modes = 1;
  }
                    /* Unresolved local var: char * data@[???] */
  ppcVar2 = pMVar1->names;
  pcVar4 = strdup(((char *)(long)&s_Memory_001479d0 /* "Memory" */));
  if (pcVar4 != (char *)0x0) {
    ppcVar2[1] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
    ppcVar2 = this->hColumns->names;
    this->hColumns->modes[1] = 1;
    pcVar4 = strdup(((char *)(long)(__sec_rodata + 0x9c7) /* "Swap" */));
    if (pcVar4 != (char *)0x0) {
      ppcVar2[2] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
      ppcVar2 = this->hColumns[1].names;
      this->hColumns->modes[2] = 1;
      pcVar4 = strdup(((char *)(long)&s_Tasks_00147965 /* "Tasks" */));
      if (pcVar4 != (char *)0x0) {
        ppcVar2[lVar7] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
        ppcVar2 = this->hColumns[1].names;
        this->hColumns[1].modes[lVar7] = 2;
        pcVar4 = strdup(((char *)(long)&s_LoadAverage_001479db /* "LoadAverage" */));
        if (pcVar4 != (char *)0x0) {
          ppcVar2[lVar7 + 1] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
          ppcVar2 = this->hColumns[1].names;
          this->hColumns[1].modes[lVar7 + 1] = 2;
          pcVar4 = strdup(((char *)(long)&s_Uptime_00147955 /* "Uptime" */));
          if (pcVar4 != (char *)0x0) {
            ppcVar2[lVar7 + 2] = pcVar4;
            this->hColumns[1].modes[lVar7 + 2] = 2;
            if ((*(long (*) [2])(__fp - 0x40))[0] != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
            return;
          }
        }
      }
    }
  }
LAB_0013266f:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Settings_setHeaderLayout @ 0x132900 */

/* DWARF original prototype: void Settings_setHeaderLayout(Settings * this, HeaderLayout hLayout) */

void Settings_setHeaderLayout(Settings *this,HeaderLayout hLayout)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  MeterColumnSetting *pMVar4;
  long *plVar5;
  MeterColumnSetting *pMVar6;
  ulong *puVar7;
  size_t sVar8;
  void *__ptr;
  ulong uVar9;
  ulong uVar10;

  bVar2 = HeaderLayout_layouts[hLayout].columns;
  uVar9 = (ulong)bVar2;
  bVar3 = HeaderLayout_layouts[this->hLayout].columns;
  uVar10 = (ulong)bVar3;
  if ((uint)bVar3 < (uint)bVar2) {
    pMVar4 = this->hColumns;
    sVar8 = uVar9 * 0x18;
                    /* Unresolved local var: void * data@[???] */
    pMVar6 = realloc(pMVar4,sVar8);
    if (pMVar6 == (MeterColumnSetting *)0x0) {
      free(pMVar4);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->hColumns = pMVar6;
    if (sVar8 <= uVar10 * 0x18) {
      sVar8 = uVar10 * 0x18;
    }
    __memset_chk(pMVar6 + uVar10,0,(ulong)((uint)bVar2 - (uint)bVar3) * 0x18,sVar8 + uVar10 * -0x18)
    ;
  }
  else if ((uint)bVar2 < (uint)bVar3) {
    sVar8 = uVar9 * 0x18;
    do {
      plVar5 = (long *)((long)&this->hColumns->len + sVar8);
      __ptr = (void *)plVar5[1];
      if (__ptr != (void *)0x0) {
                    /* Unresolved local var: size_t j@[???] */
        if (*plVar5 != 0) {
          uVar10 = 0;
          do {
            lVar1 = uVar10 * 8;
            uVar10 = uVar10 + 1;
            free(*(void **)((long)__ptr + lVar1));
            puVar7 = (ulong *)((long)&this->hColumns->len + sVar8);
            __ptr = (void *)puVar7[1];
          } while (uVar10 < *puVar7);
        }
        free(__ptr);
        plVar5 = (long *)((long)&this->hColumns->len + sVar8);
      }
                    /* Unresolved local var: uint i@[???] */
      sVar8 = sVar8 + 0x18;
      free((void *)plVar5[2]);
    } while ((uVar9 + 1 + (ulong)(((uint)bVar3 - (uint)bVar2) - 1)) * 0x18 != sVar8);
    pMVar4 = this->hColumns;
                    /* Unresolved local var: void * data@[???] */
    pMVar6 = realloc(pMVar4,uVar9 * 0x18);
    if (pMVar6 == (MeterColumnSetting *)0x0) {
      free(pMVar4);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->hColumns = pMVar6;
  }
  this->hLayout = hLayout;
  this->changed = true;
  return;
}


/* Settings_readMeters @ 0x1357b0 */

/* DWARF original prototype: void Settings_readMeters(Settings * this, char * line, uint column) */

void Settings_readMeters(Settings *this,char *line,uint column)

{
  char *s;
  char **ppcVar1;
  ulong uVar2;

                    /* Unresolved local var: char * trim@[???]
                       Unresolved local var: char * * ids@[???] */
  s = String_trim(line);
  ppcVar1 = String_split(s,' ',(size_t *)0x0);
  free(s);
  uVar2 = (ulong)column;
  if ((ulong)HeaderLayout_layouts[this->hLayout].columns - 1 <= uVar2) {
    uVar2 = (ulong)(HeaderLayout_layouts[this->hLayout].columns - 1);
  }
  this->hColumns[uVar2].names = ppcVar1;
  return;
}


/* Settings_readMeterModes @ 0x135830 */

/* DWARF original prototype: void Settings_readMeterModes(Settings * this, char * line, uint column)
    */

void Settings_readMeterModes(Settings *this,char *line,uint column)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  size_t sVar1;
  char *pcVar2;
  char **__ptr;
  size_t __nmemb;
  undefined4 *puVar3;
  long lVar4;
  ulong uVar5;
  undefined4 *puVar6;
  char **ppcVar7;

                    /* Unresolved local var: char * trim@[???]
                       Unresolved local var: char * * ids@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int * modes@[???] */
  pcVar2 = String_trim(line);
  __ptr = String_split(pcVar2,' ',(size_t *)0x0);
  free(pcVar2);
                    /* Unresolved local var: int i@[???] */
  uVar5 = (ulong)column;
  if (*__ptr == (char *)0x0) {
    puVar3 = (undefined4 *)0x0;
    if (uVar5 < (ulong)HeaderLayout_layouts[this->hLayout].columns - 1) {
      (*(long (*))(__fp - 0x48)) = uVar5 * 0x18;
      this->hColumns[uVar5].len = 0;
    }
    else {
      uVar5 = (ulong)(HeaderLayout_layouts[this->hLayout].columns - 1);
      (*(long (*))(__fp - 0x48)) = uVar5 * 0x18;
      this->hColumns[uVar5].len = 0;
    }
  }
  else {
    sVar1 = 1;
    do {
      __nmemb = sVar1;
      sVar1 = __nmemb + 1;
    } while (__ptr[__nmemb] != (char *)0x0);
    if ((ulong)HeaderLayout_layouts[this->hLayout].columns - 1 <= uVar5) {
      uVar5 = (ulong)(HeaderLayout_layouts[this->hLayout].columns - 1);
    }
                    /* Unresolved local var: void * data@[???] */
    (*(long (*))(__fp - 0x48)) = uVar5 * 0x18;
    this->hColumns[uVar5].len = __nmemb;
    puVar3 = calloc(__nmemb,4);
    if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    puVar6 = puVar3;
    ppcVar7 = __ptr;
    do {
                    /* Unresolved local var: int i@[???] */
      pcVar2 = *ppcVar7;
      ppcVar7 = ppcVar7 + 1;
      lVar4 = __isoc23_strtol(pcVar2,(char **)0x0,10);
      *puVar6 = (int)lVar4;
      puVar6 = puVar6 + 1;
    } while (ppcVar7 != __ptr + (int)__nmemb);
                    /* Unresolved local var: size_t i@[???] */
    pcVar2 = *__ptr;
    ppcVar7 = __ptr;
    while (pcVar2 != (char *)0x0) {
      ppcVar7 = ppcVar7 + 1;
      free(pcVar2);
      pcVar2 = *ppcVar7;
    }
  }
  free(__ptr);
  *(undefined4 **)((long)&this->hColumns->modes + (*(long (*))(__fp - 0x48))) = puVar3;
  return;
}


/* ScreenSettings_readFields @ 0x135a00 */

void ScreenSettings_readFields(ScreenSettings_4 *ss,Hashtable_2 *columns,char *line)

{
  ulong uVar1;
  RowField *pRVar2;
  int wVar3;
  char *pcVar4;
  char **__ptr;
  RowField *pRVar5;
  ulong uVar6;
  size_t __size;
  undefined8 *puVar7;
  char **ppcVar8;
  ulong uVar9;
  byte bVar10;

                    /* Unresolved local var: char * trim@[???]
                       Unresolved local var: char * * ids@[???] */
  bVar10 = 0;
  pcVar4 = String_trim(line);
  __ptr = String_split(pcVar4,' ',(size_t *)0x0);
  free(pcVar4);
  pRVar2 = ss->fields;
  pRVar2[0] = 0;
  pRVar2[1] = 0;
  pRVar2[0x82] = 0;
  pRVar2[0x83] = 0;
  puVar7 = (undefined8 *)((ulong)(pRVar2 + 2) & 0xfffffffffffffff8);
  for (uVar6 = (ulong)(((int)pRVar2 - (int)(undefined8 *)((ulong)(pRVar2 + 2) & 0xfffffffffffffff8))
                       + 0x210U >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
  }
                    /* Unresolved local var: size_t j@[???]
                       Unresolved local var: size_t i@[???] */
  if (*__ptr != (char *)0x0) {
    ppcVar8 = __ptr;
    uVar6 = 0;
    do {
      uVar9 = uVar6;
      if (uVar6 < 0x3fffffff) {
        if (0x83 < uVar6) {
          uVar1 = uVar6 * 4;
          __size = uVar1 + 4;
          pRVar2 = ss->fields;
                    /* Unresolved local var: void * data@[???] */
          pRVar5 = realloc(pRVar2,__size);
          if (pRVar5 == (RowField *)0x0) {
            free(pRVar2);
                    /* WARNING: Subroutine does not return */
            fail();
          }
          ss->fields = pRVar5;
          if (__size < uVar1) {
            __size = uVar1;
          }
          __memset_chk(pRVar5 + uVar6,0,4,__size + uVar6 * -4);
        }
                    /* Unresolved local var: int id@[???] */
        wVar3 = toFieldIndex(columns,*ppcVar8);
        if (-1 < wVar3) {
          uVar9 = uVar6 + 1;
          ss->fields[uVar6] = wVar3;
          if ((uint)(wVar3 + -1) < 0x83) {
            ss->flags = ss->flags | Process_fields[wVar3].flags;
          }
        }
      }
      ppcVar8 = ppcVar8 + 1;
      uVar6 = uVar9;
    } while (*ppcVar8 != (char *)0x0);
                    /* Unresolved local var: size_t i@[???] */
    pcVar4 = *__ptr;
    ppcVar8 = __ptr;
    while (pcVar4 != (char *)0x0) {
      ppcVar8 = ppcVar8 + 1;
      free(pcVar4);
      pcVar4 = *ppcVar8;
    }
  }
  free(__ptr);
  return;
}


/* Settings_initScreenSettings @ 0x135b80 */

ScreenSettings_4 * Settings_initScreenSettings(ScreenSettings_4 *ss,Settings_3 *this,char *columns)

{
  uint uVar1;
  ScreenSettings_4 **__ptr;
  ScreenSettings_4 **ppSVar2;

  ScreenSettings_readFields(ss,this->dynamicColumns,columns);
  uVar1 = this->nScreens;
  __ptr = this->screens;
  __ptr[uVar1] = ss;
                    /* Unresolved local var: void * data@[???] */
  this->nScreens = uVar1 + 1;
  ppSVar2 = realloc(__ptr,(ulong)(uVar1 + 2) << 3);
  if (ppSVar2 != (ScreenSettings_4 **)0x0) {
    this->screens = ppSVar2;
    ppSVar2[this->nScreens] = (ScreenSettings_4 *)0x0;
    return ss;
  }
  free(__ptr);
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Settings_newScreen @ 0x135bf0 */

/* DWARF original prototype: ScreenSettings * Settings_newScreen(Settings * this, ScreenDefaults *
   defaults) */

ScreenSettings_4 * Settings_newScreen(Settings *this,ScreenDefaults *defaults)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  int wVar1;
  ScreenSettings_4 *pSVar2;
  char *pcVar3;
  RowField *pRVar4;
  char cVar5;

  if (defaults->sortKey == (char *)0x0) {
    if (defaults->treeSortKey == (char *)0x0) {
      (*(int (*))(__fp - 0x3c)) = 1;
      wVar1 = 1;
    }
    else {
      wVar1 = 1;
      (*(int (*))(__fp - 0x3c)) = toFieldIndex(this->dynamicColumns,defaults->treeSortKey);
    }
  }
  else {
    wVar1 = toFieldIndex(this->dynamicColumns,defaults->sortKey);
    (*(int (*))(__fp - 0x3c)) = 1;
    if (defaults->treeSortKey != (char *)0x0) {
      (*(int (*))(__fp - 0x3c)) = toFieldIndex(this->dynamicColumns,defaults->treeSortKey);
    }
    cVar5 = '\x01';
    if (0x83 < (uint)wVar1) goto LAB_00135c54;
  }
  cVar5 = Process_fields[wVar1].defaultSortDesc;
LAB_00135c54:
                    /* Unresolved local var: void * data@[???] */
  pSVar2 = malloc(0x38);
  if (pSVar2 != (ScreenSettings_4 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    pcVar3 = strdup(defaults->name);
    if (pcVar3 != (char *)0x0) {
                    /* Unresolved local var: void * data@[???] */
      pRVar4 = calloc(0x84,4);
      if (pRVar4 != (RowField *)0x0) {
        pSVar2->fields = pRVar4;
        pSVar2->dynamic = (char *)0x0;
        pSVar2->treeSortKey = (*(int (*))(__fp - 0x3c));
        pSVar2->heading = pcVar3;
        pcVar3 = defaults->columns;
        pSVar2->direction = -(uint)(cVar5 != '\0') | 1;
        pSVar2->table = (Table__3 *)0x0;
        pSVar2->flags = 0;
        pSVar2->treeDirection = 1;
        pSVar2->sortKey = wVar1;
        pSVar2->treeView = false;
        pSVar2->treeViewAlwaysByPID = false;
        pSVar2->allBranchesCollapsed = false;
        pSVar2 = Settings_initScreenSettings(pSVar2,(Settings_3 *)this,pcVar3);
        return pSVar2;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Settings_newDynamicScreen @ 0x136760 */

/* DWARF original prototype: ScreenSettings * Settings_newDynamicScreen(Settings * this, char * tab,
   DynamicScreen * screen, Table * table) */

ScreenSettings_4 *
Settings_newDynamicScreen(Settings *this,char *tab,DynamicScreen *screen,Table_3 *table)

{
  int wVar1;
  int wVar2;
  ScreenSettings_4 *pSVar3;
  char *pcVar4;
  char *pcVar5;
  RowField *pRVar6;

  wVar2 = toFieldIndex(this->dynamicColumns,screen->columnKeys);
                    /* Unresolved local var: void * data@[???] */
  pSVar3 = malloc(0x38);
  if (pSVar3 != (ScreenSettings_4 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup(tab);
    if (pcVar4 != (char *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pcVar5 = strdup(screen->name);
      if (pcVar5 != (char *)0x0) {
                    /* Unresolved local var: void * data@[???] */
        pRVar6 = calloc(0x84,4);
        if (pRVar6 != (RowField *)0x0) {
          pSVar3->fields = pRVar6;
          wVar1 = screen->direction;
          pSVar3->flags = 0;
          pSVar3->direction = 0;
          pSVar3->treeDirection = 0;
          pSVar3->sortKey = 0;
          pSVar3->treeSortKey = 0;
          pSVar3->treeView = false;
          pSVar3->treeViewAlwaysByPID = false;
          pSVar3->allBranchesCollapsed = false;
          pSVar3->field_0x37 = 0;
          pSVar3->dynamic = pcVar5;
          pcVar5 = screen->columnKeys;
          pSVar3->direction = wVar1;
          pSVar3->heading = pcVar4;
          pSVar3->table = table;
          pSVar3->treeDirection = 1;
          pSVar3->sortKey = wVar2;
          pSVar3 = Settings_initScreenSettings(pSVar3,(Settings_3 *)this,pcVar5);
          return pSVar3;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Settings_read @ 0x1373f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: _Bool Settings_read(Settings * this, char * fileName, uint
   initialCpuCount) */

_Bool Settings_read(Settings *this,char *fileName,uint initialCpuCount)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  byte *p0;
  size_t sVar1;
  bool bVar2;
  bool bVar3;
  _Bool _Var4;
  int iVar5;
  int wVar6;
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
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: FILE * fd@[???]
                       Unresolved local var: ScreenSettings * screen@[???]
                       Unresolved local var: _Bool didReadMeters@[???]
                       Unresolved local var: _Bool didReadAny@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(fileName,((char *)(long)&DAT_00147760 /* "r" */));
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
    ppcVar8 = String_split(pcVar7,'=',&(*(size_t (*))(__fp - 0x70)));
    free(pcVar7);
    if (1 < (*(size_t (*))(__fp - 0x70))) {
      pcVar7 = *ppcVar8;
      iVar5 = strcmp(pcVar7,((char *)(long)&s_config_reader_min_version_001491c7 /* "config_reader_min_version" */));
      ppcVar14 = ppcVar8;
      if (iVar5 != 0) {
        iVar5 = strcmp(pcVar7,((char *)(long)&s_fields_001491e1 /* "fields" */));
        if ((iVar5 == 0) && (this->config_version < 3)) {
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
          iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x1f2a) /* "sort_key" */));
          if ((iVar5 == 0) && (this->config_version < 3)) {
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
          iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x1f45) /* "tree_sort_key" */));
          if ((iVar5 == 0) && (this->config_version < 3)) {
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
          iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24a3) /* "sort_direction" */));
          if ((iVar5 == 0) && (this->config_version < 3)) {
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
            ss->direction = (int)lVar9;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24b3) /* "tree_sort_direction" */));
          if (iVar5 != 0) {
            iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24c8) /* "tree_view" */));
            if (iVar5 == 0) {
              if (2 < this->config_version) goto LAB_00137537;
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
              iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24d3) /* "tree_view_always_by_pid" */));
              if (iVar5 != 0) goto LAB_0013754e;
              if (2 < this->config_version) goto LAB_00137790;
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
          if (this->config_version < 3) {
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
            ss->treeDirection = (int)lVar9;
            goto LAB_001375c0;
          }
LAB_00137537:
          iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24d3) /* "tree_view_always_by_pid" */));
          if (iVar5 != 0) {
LAB_0013754e:
            iVar5 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24ec) /* "all_branches_collapsed" */));
            if ((iVar5 != 0) || (2 < this->config_version)) goto LAB_00137790;
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
          iVar5 = strcmp(pcVar7,((char *)(long)&s_hide_kernel_threads_001491e8 /* "hide_kernel_threads" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideKernelThreads = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_hide_userland_threads_001491fc /* "hide_userland_threads" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideUserlandThreads = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_hide_running_in_container_00149212 /* "hide_running_in_container" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideRunningInContainer = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_shadow_other_users_0014922c /* "shadow_other_users" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->shadowOtherUsers = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_show_thread_names_0014923f /* "show_thread_names" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showThreadNames = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_show_program_path_00149251 /* "show_program_path" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showProgramPath = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_highlight_base_name_00149263 /* "highlight_base_name" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightBaseName = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_highlight_deleted_exe_00149277 /* "highlight_deleted_exe" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightDeletedExe = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_shadow_distribution_path_prefix_0014c928 /* "shadow_distribution_path_prefix" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->shadowDistPathPrefix = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_highlight_megabytes_0014928d /* "highlight_megabytes" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightMegabytes = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_highlight_threads_001492a1 /* "highlight_threads" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightThreads = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_highlight_changes_001492b3 /* "highlight_changes" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->highlightChanges = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_highlight_changes_delay_secs_001492c5 /* "highlight_changes_delay_secs" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            wVar6 = 86400;
            if ((int)lVar9 < 0x15181) {
              lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
              wVar6 = 1;
              if (1 < (int)lVar9) {
                lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
                wVar6 = (int)lVar9;
              }
            }
            this->highlightDelaySecs = wVar6;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_find_comm_in_cmdline_001492e2 /* "find_comm_in_cmdline" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->findCommInCmdline = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_strip_exe_from_cmdline_001492f7 /* "strip_exe_from_cmdline" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->stripExeFromCmdline = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_show_merged_command_0014930e /* "show_merged_command" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showMergedCommand = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_header_margin_00149322 /* "header_margin" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->headerMargin = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_screen_tabs_00149330 /* "screen_tabs" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->screenTabs = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_expand_system_time_0014933c /* "expand_system_time" */));
          if ((iVar5 == 0) || (iVar5 = strcmp(pcVar7,((char *)(long)&s_detailed_cpu_time_0014934f /* "detailed_cpu_time" */)), iVar5 == 0)) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->detailedCPUTime = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_cpu_count_from_one_00149361 /* "cpu_count_from_one" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->countCPUsFromOne = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_cpu_count_from_zero_00149374 /* "cpu_count_from_zero" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->countCPUsFromOne = (int)lVar9 == 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_show_cpu_usage_00149388 /* "show_cpu_usage" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showCPUUsage = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_show_cpu_frequency_00149397 /* "show_cpu_frequency" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showCPUFrequency = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_show_cpu_temperature_001493aa /* "show_cpu_temperature" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->showCPUTemperature = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_degree_fahrenheit_001493bf /* "degree_fahrenheit" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->degreeFahrenheit = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_update_process_names_001493d1 /* "update_process_names" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->updateProcessNames = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_account_guest_in_cpu_meter_001493e6 /* "account_guest_in_cpu_meter" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->accountGuestInCPUMeter = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_delay_001475a2 /* "delay" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            wVar6 = 255;
            if ((int)lVar9 < 0x100) {
              lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
              wVar6 = 1;
              if (1 < (int)lVar9) {
                lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
                wVar6 = (int)lVar9;
              }
            }
            this->delay = wVar6;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_color_scheme_00149401 /* "color_scheme" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            wVar6 = (int)lVar9;
            if (6 < (uint)wVar6) {
              wVar6 = 0;
            }
            this->colorScheme = wVar6;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_enable_mouse_0014940e /* "enable_mouse" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->enableMouse = (int)lVar9 != 0;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_header_layout_0014941b /* "header_layout" */));
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
                  (*(HeaderLayout (*))(__fp - 0x80)) = (HeaderLayout)lVar9;
                  break;
                }
                lVar9 = lVar9 + 1;
                paVar15 = paVar15 + 1;
                (*(HeaderLayout (*))(__fp - 0x80)) = HF_TWO_50_50;
              } while (lVar9 != 0xc);
            }
            else {
              lVar9 = __isoc23_strtol((char *)p0,(char **)0x0,10);
              (*(HeaderLayout (*))(__fp - 0x80)) = (HeaderLayout)lVar9;
              if (0xb < (uint)(HeaderLayout)lVar9) {
                (*(HeaderLayout (*))(__fp - 0x80)) = HF_TWO_50_50;
              }
            }
            this->hLayout = (*(HeaderLayout (*))(__fp - 0x80));
            free(this->hColumns);
            pMVar11 = xCalloc((ulong)HeaderLayout_layouts[this->hLayout].columns,0x18);
            this->hColumns = pMVar11;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_left_meters_00149429 /* "left_meters" */));
          if (iVar5 == 0) {
            Settings_readMeters(this,ppcVar8[1],0);
            goto LAB_001381cd;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_right_meters_00149435 /* "right_meters" */));
          if (iVar5 == 0) {
            Settings_readMeters(this,ppcVar8[1],1);
            bVar2 = true;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_left_meter_modes_00149442 /* "left_meter_modes" */));
          if (iVar5 == 0) {
            Settings_readMeterModes(this,ppcVar8[1],0);
LAB_001381cd:
            bVar2 = true;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_right_meter_modes_00149453 /* "right_meter_modes" */));
          if (iVar5 == 0) {
            Settings_readMeterModes(this,ppcVar8[1],1);
            goto LAB_001381cd;
          }
          _Var4 = String_startsWith(pcVar7,((char *)(long)&s_column_meters__00149465 /* "column_meters_" */));
          if (_Var4) {
            lVar9 = __isoc23_strtol(pcVar7 + 0xe,(char **)0x0,10);
            Settings_readMeters(this,ppcVar8[1],(uint)lVar9);
            goto LAB_001381cd;
          }
          _Var4 = String_startsWith(pcVar7,((char *)(long)&s_column_meter_modes__00149474 /* "column_meter_modes_" */));
          if (_Var4) {
            lVar9 = __isoc23_strtol(pcVar7 + 0x13,(char **)0x0,10);
            Settings_readMeterModes(this,ppcVar8[1],(uint)lVar9);
            goto LAB_001381cd;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s_hide_function_bar_00149488 /* "hide_function_bar" */));
          if (iVar5 == 0) {
            lVar9 = __isoc23_strtol(ppcVar8[1],(char **)0x0,10);
            this->hideFunctionBar = (int)lVar9;
            goto LAB_001375c0;
          }
          iVar5 = strncmp(pcVar7,((char *)(long)&s_screen__0014949a /* "screen:" */),7);
          if (iVar5 == 0) {
            (*(ulong *)((char *)&(*(undefined1 (*) [16])(__fp - 0x68)) + 0)) = pcVar7 + 7;
            ASSIGN_ARR((*(undefined1 (*) [16])(__fp - 0x58)), (undefined16)0x0);
            (*(ulong *)((char *)&(*(undefined1 (*) [16])(__fp - 0x68)) + 8)) = ppcVar8[1];
            ss = (ScreenSettings_5 *)Settings_newScreen(this,(ScreenDefaults *)(*(undefined1 (*) [16])(__fp - 0x68)));
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__sort_key_00148f29 /* ".sort_key" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) {
                    /* Unresolved local var: int key@[???] */
              wVar6 = toFieldIndex(this->dynamicColumns,ppcVar8[1]);
              if (wVar6 < 1) {
                wVar6 = 1;
              }
              ss->sortKey = wVar6;
            }
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__tree_sort_key_00148f44 /* ".tree_sort_key" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) {
                    /* Unresolved local var: int key@[???] */
              wVar6 = toFieldIndex(this->dynamicColumns,ppcVar8[1]);
              if (wVar6 < 1) {
                wVar6 = 1;
              }
              ss->treeSortKey = wVar6;
            }
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__sort_direction_001494a2 /* ".sort_direction" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137cb2;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__tree_sort_direction_001494b2 /* ".tree_sort_direction" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137cfd;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__tree_view_001494c7 /* ".tree_view" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137774;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__tree_view_always_by_pid_001494d2 /* ".tree_view_always_by_pid" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_00137c14;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__all_branches_collapsed_001494eb /* ".all_branches_collapsed" */));
          if (iVar5 == 0) {
            if (ss != (ScreenSettings_5 *)0x0) goto LAB_001375a2;
            goto LAB_001375c0;
          }
          iVar5 = strcmp(pcVar7,((char *)(long)&s__dynamic_00149503 /* ".dynamic" */));
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
      this->config_version = (int)lVar9;
      if ((int)lVar9 < 4) goto LAB_001375c0;
      __fprintf_chk(_stderr,2,((char *)(long)&s_WARNING___s_specifies_configurat_0014c858 /* "WARNING: %s specifies configuration format\n" */),fileName);
      __fprintf_chk(_stderr,2,
                    ((char *)(long)&s_version_v_d__but_this__s_binary_o_0014c888 /* "         version v%d, but this %s binary only supports up to version v%d.\n" */),
                    this->config_version,((char *)(long)(__sec_rodata + 0x254a) /* "htop" */),3);
      __fprintf_chk(_stderr,2,
                    ((char *)(long)&s_The_configuration_file_will_be_d_0014c8d8 /* "         The configuration file will be downgraded to v%d when %s exits.\n" */),3,
                    ((char *)(long)(__sec_rodata + 0x254a) /* "htop" */));
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
                       Unresolved local var: int * modes@[???]
                       Unresolved local var: size_t len@[???] */
      sVar1 = pMVar11->len;
      if (sVar1 != 0) {
        ppcVar8 = pMVar11->names;
        if ((pMVar11->modes == (int *)0x0) || (ppcVar8 == (char **)0x0)) goto LAB_00137f26;
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
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var4;
}


/* Settings_new @ 0x138550 */

Settings_3 *
Settings_new(uint initialCpuCount,Hashtable_2 *dynamicMeters,Hashtable_2 *dynamicColumns,
            Hashtable_2 *dynamicScreens)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  long lVar1;
  ScreenSettings_5 *pSVar2;
  _Bool _Var3;
  int iVar4;
  int wVar5;
  __uid_t __uid;
  Settings *this;
  MeterColumnSetting *pMVar6;
  ScreenSettings_5 **ppSVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  passwd *ppVar11;
  long in_FS_OFFSET = (long)__fake_fs;

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
  this->highlightDelaySecs = 5;
  this->findCommInCmdline = true;
  this->stripExeFromCmdline = true;
  this->showMergedCommand = false;
  this->updateProcessNames = false;
  this->hideFunctionBar = 0;
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
  pcVar8 = getenv(((char *)(long)&s_HTOPRC_0014950c /* "HTOPRC" */));
  if (pcVar8 == (char *)0x0) {
                    /* Unresolved local var: char * home@[???]
                       Unresolved local var: char * xdgConfigHome@[???]
                       Unresolved local var: char * configDir@[???]
                       Unresolved local var: char * htopDir@[???]
                       Unresolved local var: int err@[???] */
    pcVar8 = getenv(((char *)(long)(__sec_rodata + 0x251e) /* "HOME" */));
    if (pcVar8 == (char *)0x0) {
                    /* Unresolved local var: passwd * pw@[???] */
      __uid = getuid();
      pcVar8 = ((char *)(long)&DAT_00149c0c /* "" */);
      ppVar11 = getpwuid(__uid);
      if (ppVar11 != (passwd *)0x0) {
        pcVar8 = ppVar11->pw_dir;
      }
    }
    pcVar9 = getenv(((char *)(long)&s_XDG_CONFIG_HOME_00149513 /* "XDG_CONFIG_HOME" */));
    if (pcVar9 == (char *)0x0) {
      pcVar9 = String_cat(pcVar8,((char *)(long)&s___config_htop_htoprc_00149523 /* "/.config/htop/htoprc" */));
      this->filename = pcVar9;
      pcVar10 = String_cat(pcVar8,((char *)(long)&s___config_00149538 /* "/.config" */));
      pcVar9 = String_cat(pcVar8,((char *)(long)&s___config_htop_00149541 /* "/.config/htop" */));
    }
    else {
      pcVar10 = String_cat(pcVar9,((char *)(long)(__sec_rodata + 0x252b) /* "/htop/htoprc" */));
                    /* Unresolved local var: char * data@[???] */
      this->filename = pcVar10;
      pcVar10 = strdup(pcVar9);
      if (pcVar10 == (char *)0x0) goto LAB_001388d5;
      pcVar9 = String_cat(pcVar9,((char *)(long)(__sec_rodata + 0x2549) /* "/htop" */));
    }
    pcVar8 = String_cat(pcVar8,((char *)(long)&s___htoprc_0014954f /* "/.htoprc" */));
    mkdir(pcVar10,0x1c0);
    mkdir(pcVar9,0x1c0);
    free(pcVar9);
    free(pcVar10);
    iVar4 = lstat(pcVar8,(stat_2 *)&(*(struct stat (*))(__fp - 0xd8)));
    if ((iVar4 == 0) && (((*(struct stat (*))(__fp - 0xd8)).st_mode & 0xf000) != 0xa000)) {
      this->enableMouse = true;
      this->changed = false;
      this->colorScheme = 0;
      this->delay = 15;
      _Var3 = Settings_read(this,pcVar8,initialCpuCount);
      if (_Var3) {
        wVar5 = Settings_write(this,false);
        if (wVar5 == 0) {
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
      this->colorScheme = 0;
      this->delay = 15;
    }
  }
  else {
                    /* Unresolved local var: char * data@[???] */
    pcVar8 = strdup(pcVar8);
    if (pcVar8 == (char *)0x0) goto LAB_001388d5;
    this->filename = pcVar8;
    this->enableMouse = true;
    this->changed = false;
    this->colorScheme = 0;
    this->delay = 15;
  }
  _Var3 = Settings_read(this,pcVar8,initialCpuCount);
  if (!_Var3) {
    this->screenTabs = true;
    this->changed = true;
    _Var3 = Settings_read(this,((char *)(long)&s__etc_htoprc_00149558 /* "/etc/htoprc" */),initialCpuCount);
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

