/* Settings_write @ 0012ed00 size 2877 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: wchar_t Settings_write(Settings * this, _Bool onCrash) */

wchar_t Settings_write(Settings *this,_Bool onCrash)

{
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
  wchar_t wVar15;
  long lVar16;
  char *va1_01;
  undefined8 *puVar17;
  ulong uVar18;
  long in_FS_OFFSET;
  long local_50;
  char *tmpFilename;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  tmpFilename = (char *)0x0;
  if (onCrash) {
    iVar8 = 0x3b;
    __stream = _stderr;
  }
  else {
                    /* Unresolved local var: wchar_t fdtmp@[???] */
    xAsprintf(&tmpFilename,((char *)0x148c3f /* "%s.tmp.XXXXXX" */),this->filename);
    iVar8 = mkstemp(tmpFilename);
    if ((iVar8 == -1) || (__stream = fdopen(iVar8,((char *)0x1491b9 /* "w" */)), __stream == (FILE_2 *)0x0)) {
      piVar11 = __errno_location();
      wVar15 = -*piVar11;
      goto LAB_0012f73c;
    }
    __fprintf_chk(__stream,2,
                  ((char *)0x14c710 /* "# Beware! This file is rewritten by htop when settings are changed in the interface.\n" */)
                 );
    iVar8 = 10;
    __fprintf_chk(__stream,2,((char *)0x14c768 /* "# The parser is also very primitive, and not human-friendly.\n" */));
  }
  __fprintf_chk(__stream,2,((char *)0x148c53 /* "htop_version=%s%c" */),((char *)0x148c4d /* "3.3.0" */),iVar8);
  __fprintf_chk(__stream,2,((char *)0x14c7a8 /* "config_reader_min_version=%d%c" */),3,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148c65 /* "fields=" */));
  writeFields((FILE *)__stream,(*this->screens)->fields,this->dynamicColumns,false,(char)iVar8);
  __fprintf_chk(__stream,2,((char *)0x148c6d /* "hide_kernel_threads=%d%c" */),(uint)this->hideKernelThreads,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148c86 /* "hide_userland_threads=%d%c" */),(uint)this->hideUserlandThreads,iVar8);
  __fprintf_chk(__stream,2,((char *)0x14c7c8 /* "hide_running_in_container=%d%c" */),(uint)this->hideRunningInContainer,iVar8
               );
  __fprintf_chk(__stream,2,((char *)0x148ca1 /* "shadow_other_users=%d%c" */),(uint)this->shadowOtherUsers,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148cb9 /* "show_thread_names=%d%c" */),(uint)this->showThreadNames,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148cd0 /* "show_program_path=%d%c" */),(uint)this->showProgramPath,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148ce7 /* "highlight_base_name=%d%c" */),(uint)this->highlightBaseName,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d00 /* "highlight_deleted_exe=%d%c" */),(uint)this->highlightDeletedExe,iVar8);
  __fprintf_chk(__stream,2,((char *)0x14c7e8 /* "shadow_distribution_path_prefix=%d%c" */),(uint)this->shadowDistPathPrefix,
                iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d1b /* "highlight_megabytes=%d%c" */),(uint)this->highlightMegabytes,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d34 /* "highlight_threads=%d%c" */),(uint)this->highlightThreads,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d4b /* "highlight_changes=%d%c" */),(uint)this->highlightChanges,iVar8);
  __fprintf_chk(__stream,2,((char *)0x14c810 /* "highlight_changes_delay_secs=%d%c" */),this->highlightDelaySecs,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d62 /* "find_comm_in_cmdline=%d%c" */),(uint)this->findCommInCmdline,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d7c /* "strip_exe_from_cmdline=%d%c" */),(uint)this->stripExeFromCmdline,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148d98 /* "show_merged_command=%d%c" */),(uint)this->showMergedCommand,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148db1 /* "header_margin=%d%c" */),(uint)this->headerMargin,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148dc4 /* "screen_tabs=%d%c" */),(uint)this->screenTabs,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148dd5 /* "detailed_cpu_time=%d%c" */),(uint)this->detailedCPUTime,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148dec /* "cpu_count_from_one=%d%c" */),(uint)this->countCPUsFromOne,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e04 /* "show_cpu_usage=%d%c" */),(uint)this->showCPUUsage,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e18 /* "show_cpu_frequency=%d%c" */),(uint)this->showCPUFrequency,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e30 /* "show_cpu_temperature=%d%c" */),(uint)this->showCPUTemperature,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e4a /* "degree_fahrenheit=%d%c" */),(uint)this->degreeFahrenheit,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e61 /* "update_process_names=%d%c" */),(uint)this->updateProcessNames,iVar8);
  __fprintf_chk(__stream,2,((char *)0x14c838 /* "account_guest_in_cpu_meter=%d%c" */),(uint)this->accountGuestInCPUMeter,
                iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e7b /* "color_scheme=%d%c" */),this->colorScheme,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148e8d /* "enable_mouse=%d%c" */),(uint)this->enableMouse,iVar8);
                    /* Unresolved local var: uint i@[???] */
  lVar16 = 0;
  __fprintf_chk(__stream,2,((char *)0x148e9f /* "delay=%d%c" */),this->delay,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148eaa /* "hide_function_bar=%d%c" */),this->hideFunctionBar,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148ec1 /* "header_layout=%s%c" */),HeaderLayout_layouts[this->hLayout].name,iVar8);
  if (HeaderLayout_layouts[this->hLayout].columns != '\0') {
    va0 = 0;
    do {
      __fprintf_chk(__stream,2,((char *)0x148ee7 /* "column_meters_%u=" */),va0);
      plVar13 = (long *)((long)&this->hColumns->len + lVar16);
      lVar3 = *plVar13;
      if (lVar3 == 0) {
        fputc(0x21,__stream);
      }
      else {
        puVar17 = (undefined8 *)plVar13[1];
                    /* Unresolved local var: char * sep@[???]
                       Unresolved local var: wchar_t i@[???] */
        iVar7 = (int)lVar3;
        if (0 < iVar7) {
          puVar12 = &DAT_00149c0c;
          puVar1 = puVar17 + (ulong)(iVar7 - 1) + 1;
          do {
            va1 = (void *)*puVar17;
            puVar17 = puVar17 + 1;
            __fprintf_chk(__stream,2,((char *)0x147643 /* "%s%s" */),puVar12,va1);
            puVar12 = &DAT_001470dd;
          } while (puVar1 != puVar17);
        }
      }
      fputc(iVar8,__stream);
      __fprintf_chk(__stream,2,((char *)0x148ef9 /* "column_meter_modes_%u=" */),va0);
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
          __fprintf_chk(__stream,2,((char *)0x148c18 /* "%s%d" */),puVar12,*(int *)(puVar9[2] + lVar3));
          puVar12 = &DAT_001470dd;
          puVar9 = (ulong *)((long)&this->hColumns->len + lVar16);
        } while (uVar18 < *puVar9);
      }
      lVar16 = lVar16 + 0x18;
      fputc(iVar8,__stream);
      va0 = va0 + 1;
    } while (va0 < HeaderLayout_layouts[this->hLayout].columns);
  }
  __fprintf_chk(__stream,2,((char *)0x148f95 /* "tree_view=%d%c" */),(uint)(*this->screens)->treeView,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148ed9 /* "sort_key=%d%c" */),(*this->screens)->sortKey + -1,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148ed4 /* "tree_sort_key=%d%c" */),(*this->screens)->treeSortKey + -1,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148fa5 /* "sort_direction=%d%c" */),(*this->screens)->direction,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148fba /* "tree_sort_direction=%d%c" */),(*this->screens)->treeDirection,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148f77 /* "tree_view_always_by_pid=%d%c" */),
                (uint)(*this->screens)->treeViewAlwaysByPID,iVar8);
  __fprintf_chk(__stream,2,((char *)0x148fd4 /* "all_branches_collapsed=%d%c" */),
                (uint)(*this->screens)->allBranchesCollapsed,iVar8);
                    /* Unresolved local var: uint i@[???] */
  if (this->nScreens != 0) {
    local_50 = 0;
    do {
      pSVar4 = this->screens[local_50];
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
      __fprintf_chk(__stream,2,((char *)0x148f10 /* "screen:%s=" */),pSVar4->heading);
      writeFields((FILE *)__stream,pSVar4->fields,this->dynamicColumns,true,(char)iVar8);
      if (pSVar4->dynamic == (char *)0x0) {
        __fprintf_chk(__stream,2,((char *)0x148f53 /* ".sort_key=%s%c" */),va1_00,iVar8);
        __fprintf_chk(__stream,2,((char *)0x148f62 /* ".tree_sort_key=%s%c" */),va1_01,iVar8);
        __fprintf_chk(__stream,2,((char *)0x148f76 /* ".tree_view_always_by_pid=%d%c" */),(uint)pSVar4->treeViewAlwaysByPID,
                      iVar8);
      }
      else {
                    /* Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: char * sortKey@[???]
                       Unresolved local var: char * treeSortKey@[???] */
        __fprintf_chk(__stream,2,((char *)0x148f1b /* ".dynamic=%s%c" */),pSVar4->dynamic,iVar8);
        if (1 < (uint)pSVar4->sortKey) {
          __fprintf_chk(__stream,2,((char *)0x148f33 /* "%s=Dynamic(%s)%c" */),((char *)0x148f29 /* ".sort_key" */),va1_00,iVar8);
        }
        if (1 < (uint)pSVar4->treeSortKey) {
          __fprintf_chk(__stream,2,((char *)0x148f33 /* "%s=Dynamic(%s)%c" */),((char *)0x148f44 /* ".tree_sort_key" */),va1_01,iVar8);
        }
      }
      __fprintf_chk(__stream,2,((char *)0x148f94 /* ".tree_view=%d%c" */),(uint)pSVar4->treeView,iVar8);
      __fprintf_chk(__stream,2,((char *)0x148fa4 /* ".sort_direction=%d%c" */),pSVar4->direction,iVar8);
      __fprintf_chk(__stream,2,((char *)0x148fb9 /* ".tree_sort_direction=%d%c" */),pSVar4->treeDirection,iVar8);
      __fprintf_chk(__stream,2,((char *)0x148fd3 /* ".all_branches_collapsed=%d%c" */),(uint)pSVar4->allBranchesCollapsed,
                    iVar8);
      local_50 = local_50 + 1;
    } while ((uint)local_50 < this->nScreens);
  }
  wVar15 = L'\0';
  if (onCrash) goto LAB_0012f73c;
  iVar8 = ferror(__stream);
  if (iVar8 == 0) {
    iVar8 = fclose(__stream);
    if (iVar8 != 0) {
      piVar11 = __errno_location();
      wVar15 = -*piVar11;
      if (wVar15 != L'\0') goto LAB_0012f828;
    }
    wVar15 = L'\0';
    iVar8 = rename(tmpFilename,this->filename);
    if (iVar8 == -1) {
      piVar11 = __errno_location();
      wVar15 = -*piVar11;
    }
  }
  else {
    piVar11 = __errno_location();
    if (*piVar11 == 0) {
      wVar15 = L'\xfffffff7';
      fclose(__stream);
    }
    else {
      wVar15 = -*piVar11;
      fclose(__stream);
    }
  }
LAB_0012f828:
  free(tmpFilename);
LAB_0012f73c:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return wVar15;
}

