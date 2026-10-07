#include "htop.h"

/* Settings_delete @ 0x12dfd0 */

void Settings_delete(undefined8 *param_1)

{
  void *__ptr;
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  long *__ptr_00;
  undefined8 *puVar5;

  lVar3 = 0;
  free((void *)*param_1);
  if ((&DAT_00155fa0)[(long)*(int *)((long)param_1 + 0xc) * 0x18] != '\0') {
    do {
      lVar1 = param_1[2] + lVar3 * 0x18;
      puVar4 = *(undefined8 **)(lVar1 + 8);
      if (puVar4 != (undefined8 *)0x0) {
        __ptr = (void *)*puVar4;
        puVar5 = puVar4;
        while (__ptr != (void *)0x0) {
          puVar5 = puVar5 + 1;
          free(__ptr);
          __ptr = (void *)*puVar5;
        }
        free(puVar4);
        lVar1 = param_1[2] + lVar3 * 0x18;
      }
      lVar3 = lVar3 + 1;
      free(*(void **)(lVar1 + 0x10));
    } while ((uint)lVar3 < (uint)(byte)(&DAT_00155fa0)[(long)*(int *)((long)param_1 + 0xc) * 0x18]);
  }
  free((void *)param_1[2]);
  __ptr_00 = (long *)param_1[6];
  if (__ptr_00 != (long *)0x0) {
    puVar4 = (undefined8 *)*__ptr_00;
    if (puVar4 != (undefined8 *)0x0) {
      uVar2 = 0;
      do {
        free((void *)*puVar4);
        free((void *)puVar4[1]);
        free((void *)puVar4[3]);
        free(puVar4);
        __ptr_00 = (long *)param_1[6];
        uVar2 = (ulong)((int)uVar2 + 1);
        puVar4 = (undefined8 *)__ptr_00[uVar2];
      } while (puVar4 != (undefined8 *)0x0);
    }
    free(__ptr_00);
  }
  free(param_1);
  return;
}


/* Settings_enableReadonly @ 0x12e1f0 */

void Settings_enableReadonly(void)

{
  CHAR____0015c0d9 = '\x01';
  return;
}


/* Settings_isReadonly @ 0x12e200 */

char Settings_isReadonly(void)

{
  return CHAR____0015c0d9;
}


/* Settings_write @ 0x12ed00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Settings_write(undefined8 *param_1,char param_2)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  undefined8 *puVar1;
  uint va0;
  long lVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  int *piVar7;
  FILE *__stream;
  undefined *puVar8;
  ulong uVar9;
  void *pvVar10;
  long lVar11;
  void *va1;
  undefined8 *puVar12;
  ulong uVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(char * *)(__fp - 0x48)) = (char *)0x0;
  if (param_2 == '\0') {
    xAsprintf(&(*(char * *)(__fp - 0x48)),((char *)(long)&s__s_tmp_XXXXXX_00148c3f /* "%s.tmp.XXXXXX" */),(void *)*param_1);
    iVar4 = mkstemp((*(char * *)(__fp - 0x48)));
    if ((iVar4 == -1) || (__stream = fdopen(iVar4,((char *)(long)&DAT_001491b9 /* "w" */)), __stream == (FILE *)0x0)) {
      piVar7 = __errno_location();
      iVar4 = -*piVar7;
      goto LAB_0012f73c;
    }
    __fprintf_chk(__stream,2,
                  ((char *)(long)&s___Beware__This_file_is_rewritten_0014c710 /* "# Beware! This file is rewritten by htop when settings are changed in the interface.\n" */)
                 );
    iVar4 = 10;
    __fprintf_chk(__stream,2,((char *)(long)&s___The_parser_is_also_very_primit_0014c768 /* "# The parser is also very primitive, and not human-friendly.\n" */));
  }
  else {
    iVar4 = 0x3b;
    __stream = _stderr;
  }
  __fprintf_chk(__stream,2,((char *)(long)&s_htop_version__s_c_00148c53 /* "htop_version=%s%c" */),((char *)(long)&s_3_3_0_00148c4d /* "3.3.0" */),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_config_reader_min_version__d_c_0014c7a8 /* "config_reader_min_version=%d%c" */),3,iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_fields__00148c65 /* "fields=" */));
  FUN_0012d840(__stream,*(int **)(*(long *)param_1[6] + 0x18),(ulong *)param_1[3],'\0',(char)iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_kernel_threads__d_c_00148c6d /* "hide_kernel_threads=%d%c" */),(uint)*(byte *)((long)param_1 + 0x59),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_userland_threads__d_c_00148c86 /* "hide_userland_threads=%d%c" */),(uint)*(byte *)((long)param_1 + 0x5b),iVar4)
  ;
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_running_in_container__d_c_0014c7c8 /* "hide_running_in_container=%d%c" */),(uint)*(byte *)((long)param_1 + 0x5a),
                iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_shadow_other_users__d_c_00148ca1 /* "shadow_other_users=%d%c" */),(uint)*(byte *)((long)param_1 + 0x57),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_thread_names__d_c_00148cb9 /* "show_thread_names=%d%c" */),(uint)*(byte *)(param_1 + 0xb),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_program_path__d_c_00148cd0 /* "show_program_path=%d%c" */),(uint)*(byte *)((long)param_1 + 0x56),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_base_name__d_c_00148ce7 /* "highlight_base_name=%d%c" */),(uint)*(byte *)((long)param_1 + 0x5c),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_deleted_exe__d_c_00148d00 /* "highlight_deleted_exe=%d%c" */),(uint)*(byte *)((long)param_1 + 0x5d),iVar4)
  ;
  __fprintf_chk(__stream,2,((char *)(long)&s_shadow_distribution_path_prefix__0014c7e8 /* "shadow_distribution_path_prefix=%d%c" */),
                (uint)*(byte *)((long)param_1 + 0x5e),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_megabytes__d_c_00148d1b /* "highlight_megabytes=%d%c" */),(uint)*(byte *)((long)param_1 + 0x5f),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_threads__d_c_00148d34 /* "highlight_threads=%d%c" */),(uint)*(byte *)(param_1 + 0xc),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_changes__d_c_00148d4b /* "highlight_changes=%d%c" */),(uint)*(byte *)((long)param_1 + 0x61),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_highlight_changes_delay_secs__d__0014c810 /* "highlight_changes_delay_secs=%d%c" */),*(int *)((long)param_1 + 100),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_find_comm_in_cmdline__d_c_00148d62 /* "find_comm_in_cmdline=%d%c" */),(uint)*(byte *)(param_1 + 0xd),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_strip_exe_from_cmdline__d_c_00148d7c /* "strip_exe_from_cmdline=%d%c" */),(uint)*(byte *)((long)param_1 + 0x69),iVar4
               );
  __fprintf_chk(__stream,2,((char *)(long)&s_show_merged_command__d_c_00148d98 /* "show_merged_command=%d%c" */),(uint)*(byte *)((long)param_1 + 0x6a),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_header_margin__d_c_00148db1 /* "header_margin=%d%c" */),(uint)*(byte *)((long)param_1 + 0x6d),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_screen_tabs__d_c_00148dc4 /* "screen_tabs=%d%c" */),(uint)*(byte *)((long)param_1 + 0x6e),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_detailed_cpu_time__d_c_00148dd5 /* "detailed_cpu_time=%d%c" */),(uint)*(byte *)((long)param_1 + 0x51),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_cpu_count_from_one__d_c_00148dec /* "cpu_count_from_one=%d%c" */),(uint)*(byte *)(param_1 + 10),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_cpu_usage__d_c_00148e04 /* "show_cpu_usage=%d%c" */),(uint)*(byte *)((long)param_1 + 0x52),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_cpu_frequency__d_c_00148e18 /* "show_cpu_frequency=%d%c" */),(uint)*(byte *)((long)param_1 + 0x53),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_show_cpu_temperature__d_c_00148e30 /* "show_cpu_temperature=%d%c" */),(uint)*(byte *)((long)param_1 + 0x54),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_degree_fahrenheit__d_c_00148e4a /* "degree_fahrenheit=%d%c" */),(uint)*(byte *)((long)param_1 + 0x55),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_update_process_names__d_c_00148e61 /* "update_process_names=%d%c" */),(uint)*(byte *)((long)param_1 + 0x6b),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_account_guest_in_cpu_meter__d_c_0014c838 /* "account_guest_in_cpu_meter=%d%c" */),(uint)*(byte *)((long)param_1 + 0x6c),
                iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_color_scheme__d_c_00148e7b /* "color_scheme=%d%c" */),*(int *)(param_1 + 9),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_enable_mouse__d_c_00148e8d /* "enable_mouse=%d%c" */),(uint)*(byte *)((long)param_1 + 0x6f),iVar4);
  lVar11 = 0;
  __fprintf_chk(__stream,2,((char *)(long)&s_delay__d_c_00148e9f /* "delay=%d%c" */),*(int *)((long)param_1 + 0x4c),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_hide_function_bar__d_c_00148eaa /* "hide_function_bar=%d%c" */),*(int *)(param_1 + 0xe),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_header_layout__s_c_00148ec1 /* "header_layout=%s%c" */),
                (&PTR_s_two_50_50_00155fa8)[(long)*(int *)((long)param_1 + 0xc) * 3],iVar4);
  if ((&DAT_00155fa0)[(long)*(int *)((long)param_1 + 0xc) * 0x18] != '\0') {
    va0 = 0;
    do {
      __fprintf_chk(__stream,2,((char *)(long)&s_column_meters__u__00148ee7 /* "column_meters_%u=" */),va0);
      lVar2 = *(long *)(param_1[2] + lVar11);
      if (lVar2 == 0) {
        fputc(0x21,__stream);
      }
      else {
        puVar12 = (undefined8 *)((long *)(param_1[2] + lVar11))[1];
        iVar5 = (int)lVar2;
        if (0 < iVar5) {
          puVar8 = &DAT_00149c0c;
          puVar1 = puVar12 + (ulong)(iVar5 - 1) + 1;
          do {
            pvVar10 = (void *)*puVar12;
            puVar12 = puVar12 + 1;
            __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),puVar8,pvVar10);
            puVar8 = &DAT_001470dd;
          } while (puVar1 != puVar12);
        }
      }
      fputc(iVar4,__stream);
      __fprintf_chk(__stream,2,((char *)(long)&s_column_meter_modes__u__00148ef9 /* "column_meter_modes_%u=" */),va0);
      puVar6 = (ulong *)(param_1[2] + lVar11);
      if (*puVar6 == 0) {
        fputc(0x21,__stream);
      }
      else {
        puVar8 = &DAT_00149c0c;
        uVar13 = 0;
        do {
          lVar2 = uVar13 * 4;
          uVar13 = uVar13 + 1;
          __fprintf_chk(__stream,2,((char *)(long)&DAT_00148c18 /* "%s%d" */),puVar8,*(int *)(puVar6[2] + lVar2));
          puVar8 = &DAT_001470dd;
          puVar6 = (ulong *)(param_1[2] + lVar11);
        } while (uVar13 < *puVar6);
      }
      lVar11 = lVar11 + 0x18;
      fputc(iVar4,__stream);
      va0 = va0 + 1;
    } while (va0 < (byte)(&DAT_00155fa0)[(long)*(int *)((long)param_1 + 0xc) * 0x18]);
  }
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1f95) /* "tree_view=%d%c" */),(uint)*(byte *)(*(long *)param_1[6] + 0x34),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1ed9) /* "sort_key=%d%c" */),*(int *)(*(long *)param_1[6] + 0x2c) + -1,iVar4);
  __fprintf_chk(__stream,2,((char *)(long)&s_tree_sort_key__d_c_00148ed4 /* "tree_sort_key=%d%c" */),*(int *)(*(long *)param_1[6] + 0x30) + -1,iVar4);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1fa5) /* "sort_direction=%d%c" */),*(int *)(*(long *)param_1[6] + 0x24),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1fba) /* "tree_sort_direction=%d%c" */),*(int *)(*(long *)param_1[6] + 0x28),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1f77) /* "tree_view_always_by_pid=%d%c" */),
                (uint)*(byte *)(*(long *)param_1[6] + 0x35),iVar4);
  __fprintf_chk(__stream,2,((char *)(long)(__sec_rodata + 0x1fd4) /* "all_branches_collapsed=%d%c" */),(uint)*(byte *)(*(long *)param_1[6] + 0x36)
                ,iVar4);
  if (*(int *)(param_1 + 7) != 0) {
    (*(long *)(__fp - 0x50)) = 0;
    do {
      puVar12 = *(undefined8 **)(param_1[6] + (*(long *)(__fp - 0x50)) * 8);
      puVar6 = (ulong *)param_1[3];
      iVar5 = *(int *)((long)puVar12 + 0x2c);
      if (iVar5 < 0) {
LAB_0012f720:
        pvVar10 = (void *)0x0;
      }
      else if (iVar5 < 0x84) {
        pvVar10 = *(void **)(Process_fields + (long)iVar5 * 0x20);
      }
      else {
        piVar3 = (int *)puVar6[1];
        uVar13 = (ulong)(long)iVar5 % *puVar6;
        piVar7 = piVar3 + uVar13 * 6;
        pvVar10 = *(void **)(piVar7 + 4);
        if (pvVar10 != (void *)0x0) {
          uVar9 = 0;
          do {
            if (iVar5 == *piVar7) break;
            if (*(ulong *)(piVar7 + 2) < uVar9) goto LAB_0012f720;
            uVar13 = uVar13 + 1;
            if (*puVar6 == uVar13) {
              uVar13 = 0;
              piVar7 = piVar3;
            }
            else {
              piVar7 = piVar3 + uVar13 * 6;
            }
            pvVar10 = *(void **)(piVar7 + 4);
            uVar9 = uVar9 + 1;
          } while (pvVar10 != (void *)0x0);
        }
      }
      iVar5 = *(int *)(puVar12 + 6);
      if (iVar5 < 0) {
LAB_0012f710:
        va1 = (void *)0x0;
      }
      else if (iVar5 < 0x84) {
        va1 = *(void **)(Process_fields + (long)iVar5 * 0x20);
      }
      else {
        piVar3 = (int *)puVar6[1];
        uVar13 = (ulong)(long)iVar5 % *puVar6;
        piVar7 = piVar3 + uVar13 * 6;
        va1 = *(void **)(piVar7 + 4);
        if (va1 != (void *)0x0) {
          uVar9 = 0;
          do {
            if (iVar5 == *piVar7) break;
            if (*(ulong *)(piVar7 + 2) < uVar9) goto LAB_0012f710;
            uVar13 = uVar13 + 1;
            if (*puVar6 == uVar13) {
              uVar13 = 0;
              piVar7 = piVar3;
            }
            else {
              piVar7 = piVar3 + uVar13 * 6;
            }
            va1 = *(void **)(piVar7 + 4);
            uVar9 = uVar9 + 1;
          } while (va1 != (void *)0x0);
        }
      }
      __fprintf_chk(__stream,2,((char *)(long)&s_screen__s__00148f10 /* "screen:%s=" */),(void *)*puVar12);
      FUN_0012d840(__stream,(int *)puVar12[3],(ulong *)param_1[3],'\x01',(char)iVar4);
      if ((void *)puVar12[1] == (void *)0x0) {
        __fprintf_chk(__stream,2,((char *)(long)&s__sort_key__s_c_00148f53 /* ".sort_key=%s%c" */),pvVar10,iVar4);
        __fprintf_chk(__stream,2,((char *)(long)&s__tree_sort_key__s_c_00148f62 /* ".tree_sort_key=%s%c" */),va1,iVar4);
        __fprintf_chk(__stream,2,((char *)(long)&s__tree_view_always_by_pid__d_c_00148f76 /* ".tree_view_always_by_pid=%d%c" */),
                      (uint)*(byte *)((long)puVar12 + 0x35),iVar4);
      }
      else {
        __fprintf_chk(__stream,2,((char *)(long)&s__dynamic__s_c_00148f1b /* ".dynamic=%s%c" */),(void *)puVar12[1],iVar4);
        if (1 < *(uint *)((long)puVar12 + 0x2c)) {
          __fprintf_chk(__stream,2,((char *)(long)&s__s_Dynamic__s__c_00148f33 /* "%s=Dynamic(%s)%c" */),((char *)(long)&s__sort_key_00148f29 /* ".sort_key" */),pvVar10,iVar4);
        }
        if (1 < *(uint *)(puVar12 + 6)) {
          __fprintf_chk(__stream,2,((char *)(long)&s__s_Dynamic__s__c_00148f33 /* "%s=Dynamic(%s)%c" */),((char *)(long)&s__tree_sort_key_00148f44 /* ".tree_sort_key" */),va1,iVar4);
        }
      }
      __fprintf_chk(__stream,2,((char *)(long)&s__tree_view__d_c_00148f94 /* ".tree_view=%d%c" */),(uint)*(byte *)((long)puVar12 + 0x34),iVar4);
      __fprintf_chk(__stream,2,((char *)(long)&s__sort_direction__d_c_00148fa4 /* ".sort_direction=%d%c" */),*(int *)((long)puVar12 + 0x24),iVar4);
      __fprintf_chk(__stream,2,((char *)(long)&s__tree_sort_direction__d_c_00148fb9 /* ".tree_sort_direction=%d%c" */),*(int *)(puVar12 + 5),iVar4);
      __fprintf_chk(__stream,2,((char *)(long)&s__all_branches_collapsed__d_c_00148fd3 /* ".all_branches_collapsed=%d%c" */),(uint)*(byte *)((long)puVar12 + 0x36),
                    iVar4);
      (*(long *)(__fp - 0x50)) = (*(long *)(__fp - 0x50)) + 1;
    } while ((uint)(*(long *)(__fp - 0x50)) < *(uint *)(param_1 + 7));
  }
  iVar4 = 0;
  if (param_2 != '\0') goto LAB_0012f73c;
  iVar4 = ferror(__stream);
  if (iVar4 == 0) {
    iVar4 = fclose(__stream);
    if (iVar4 != 0) {
      piVar7 = __errno_location();
      iVar4 = -*piVar7;
      if (iVar4 != 0) goto LAB_0012f828;
    }
    iVar4 = 0;
    iVar5 = rename((*(char * *)(__fp - 0x48)),(char *)*param_1);
    if (iVar5 == -1) {
      piVar7 = __errno_location();
      iVar4 = -*piVar7;
    }
  }
  else {
    piVar7 = __errno_location();
    if (*piVar7 == 0) {
      iVar4 = -9;
      fclose(__stream);
    }
    else {
      iVar4 = -*piVar7;
      fclose(__stream);
    }
  }
LAB_0012f828:
  free((*(char * *)(__fp - 0x48)));
LAB_0012f73c:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


/* FUN_0012f890 @ 0x12f890 */

void FUN_0012f890(long param_1)

{
  double *pdVar1;
  int iVar2;
  ulong uVar3;

  pdVar1 = *(double **)(param_1 + 0x160);
  pdVar1[1] = NAN;
  pdVar1[2] = NAN;
  Platform_setSwapValues(param_1);
  iVar2 = Meter_humanUnit(*pdVar1,(char *)(param_1 + 0x60),0x100);
  if (-1 < iVar2) {
    uVar3 = (ulong)iVar2;
    if ((uVar3 < 0x100) && (uVar3 != 0xff)) {
      *(undefined2 *)(param_1 + 0x60 + uVar3) = 0x2f;
      Meter_humanUnit(*(double *)(param_1 + 0x168),(char *)(param_1 + 0x61 + uVar3),0xff - uVar3);
      return;
    }
  }
  return;
}


/* Settings_setHeaderLayout @ 0x132900 */

void Settings_setHeaderLayout(long param_1,int param_2)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  long *plVar4;
  void *pvVar5;
  ulong uVar6;
  ulong *puVar7;
  size_t sVar8;
  void *pvVar9;
  ulong uVar10;

  bVar2 = (&DAT_00155fa0)[(long)param_2 * 0x18];
  uVar6 = (ulong)bVar2;
  bVar3 = (&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18];
  if ((uint)bVar3 < (uint)bVar2) {
    pvVar9 = *(void **)(param_1 + 0x10);
    sVar8 = uVar6 * 0x18;
    pvVar5 = realloc(pvVar9,sVar8);
    if (pvVar5 == (void *)0x0) {
      free(pvVar9);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(void **)(param_1 + 0x10) = pvVar5;
    uVar6 = (ulong)bVar3 * 0x18;
    if (sVar8 <= uVar6) {
      sVar8 = uVar6;
    }
    __memset_chk((void *)((long)pvVar5 + uVar6),0,(ulong)((uint)bVar2 - (uint)bVar3) * 0x18,
                 sVar8 + (ulong)bVar3 * -0x18);
  }
  else if ((uint)bVar2 < (uint)bVar3) {
    sVar8 = uVar6 * 0x18;
    do {
      plVar4 = (long *)(*(long *)(param_1 + 0x10) + sVar8);
      pvVar9 = (void *)plVar4[1];
      if (pvVar9 != (void *)0x0) {
        if (*plVar4 != 0) {
          uVar10 = 0;
          do {
            lVar1 = uVar10 * 8;
            uVar10 = uVar10 + 1;
            free(*(void **)((long)pvVar9 + lVar1));
            puVar7 = (ulong *)(*(long *)(param_1 + 0x10) + sVar8);
            pvVar9 = (void *)puVar7[1];
          } while (uVar10 < *puVar7);
        }
        free(pvVar9);
        plVar4 = (long *)(*(long *)(param_1 + 0x10) + sVar8);
      }
      sVar8 = sVar8 + 0x18;
      free((void *)plVar4[2]);
    } while ((uVar6 + 1 + (ulong)(((uint)bVar3 - (uint)bVar2) - 1)) * 0x18 != sVar8);
    pvVar9 = *(void **)(param_1 + 0x10);
    pvVar5 = realloc(pvVar9,uVar6 * 0x18);
    if (pvVar5 == (void *)0x0) {
      free(pvVar9);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(void **)(param_1 + 0x10) = pvVar5;
  }
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined1 *)(param_1 + 0x74) = 1;
  return;
}


/* Settings_newScreen @ 0x135bf0 */

void * Settings_newScreen(long param_1,undefined8 *param_2)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  uint uVar1;
  undefined8 *puVar2;
  char *pcVar3;
  void *pvVar4;
  char cVar5;

  if ((char *)param_2[2] == (char *)0x0) {
    if ((char *)param_2[3] == (char *)0x0) {
      (*(int *)(__fp - 0x3c)) = 1;
      uVar1 = 1;
    }
    else {
      uVar1 = 1;
      (*(int *)(__fp - 0x3c)) = FUN_0012d610(*(ulong **)(param_1 + 0x18),(char *)param_2[3]);
    }
  }
  else {
    uVar1 = FUN_0012d610(*(ulong **)(param_1 + 0x18),(char *)param_2[2]);
    (*(int *)(__fp - 0x3c)) = 1;
    if ((char *)param_2[3] != (char *)0x0) {
      (*(int *)(__fp - 0x3c)) = FUN_0012d610(*(ulong **)(param_1 + 0x18),(char *)param_2[3]);
    }
    cVar5 = '\x01';
    if (0x83 < uVar1) goto LAB_00135c54;
  }
  cVar5 = Process_fields[(long)(int)uVar1 * 0x20 + 0x1d];
LAB_00135c54:
  puVar2 = malloc(0x38);
  if (puVar2 != (undefined8 *)0x0) {
    pcVar3 = strdup((char *)*param_2);
    if (pcVar3 != (char *)0x0) {
      pvVar4 = calloc(0x84,4);
      if (pvVar4 != (void *)0x0) {
        puVar2[3] = pvVar4;
        puVar2[1] = 0;
        *(int *)(puVar2 + 6) = (*(int *)(__fp - 0x3c));
        *puVar2 = pcVar3;
        pcVar3 = (char *)param_2[1];
        *(uint *)((long)puVar2 + 0x24) = -(uint)(cVar5 != '\0') | 1;
        puVar2[2] = 0;
        *(undefined4 *)(puVar2 + 4) = 0;
        *(undefined4 *)(puVar2 + 5) = 1;
        *(uint *)((long)puVar2 + 0x2c) = uVar1;
        *(undefined2 *)((long)puVar2 + 0x34) = 0;
        *(undefined1 *)((long)puVar2 + 0x36) = 0;
        pvVar4 = (void *)FUN_00135b80((long)puVar2,param_1,pcVar3);
        return pvVar4;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00135d60 @ 0x135d60 */

ulong FUN_00135d60(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  uint uVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  bool bVar6;
  long *plVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  size_t sVar11;
  char *pcVar12;
  ushort **ppuVar13;
  undefined8 *puVar14;
  void *pvVar15;
  long lVar16;
  ulong uVar17;
  ushort *a3;
  int iVar18;
  long *a5;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  int iVar19;
  long lVar20;
  long lVar21;
  long *plVar22;
  uint uVar23;
  ulong uVar24;
  ulong *puVar25;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1[0x4e5] != 0) {
    if ((param_2 - 0x20U < 0x5f) && (param_2 != 0x3d)) {
      iVar9 = (int)param_1[0x4e4];
      if (iVar9 < 0x13) {
        *(char *)((long)param_1 + (long)iVar9 + 0x2700) = (char)param_2;
        *(int *)(param_1 + 0x4e4) = iVar9 + 1;
LAB_00135eec:
        sVar11 = strlen((char *)(param_1 + 0x4e0));
        *(int *)(param_1 + 6) = (int)sVar11;
        *(int *)((long)param_1 + 0x1c) =
             (((int)param_1[5] + *(int *)((long)param_1 + 0xc)) - (int)param_1[8]) + 1;
        *(int *)(param_1 + 3) = ((int)sVar11 + (int)param_1[1]) - *(int *)((long)param_1 + 0x44);
      }
    }
    else if (param_2 == 0x1b) {
      if ((0 < (int)((long *)param_1[4])[3]) &&
         (lVar20 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8), lVar20 != 0)) {
        *(long *)(lVar20 + 8) = param_1[0x4e3];
        param_1[0x4e5] = 0;
        *(undefined1 *)((long)param_1 + 0x49) = 0;
        *(undefined4 *)(param_1 + 0x4db) = 9;
      }
    }
    else if (param_2 < 0x1c) {
      if ((param_2 == 10) || (param_2 == 0xd)) {
LAB_00135f30:
        if ((0 < (int)((long *)param_1[4])[3]) &&
           (lVar20 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8), lVar20 != 0)) {
          free((void *)param_1[0x4e3]);
          pcVar12 = strdup((char *)(param_1 + 0x4e0));
          if (pcVar12 == (char *)0x0) goto LAB_00136752;
          *(char **)(lVar20 + 8) = pcVar12;
          param_1[0x4e5] = 0;
          *(undefined1 *)((long)param_1 + 0x49) = 0;
          *(undefined4 *)(param_1 + 0x4db) = 9;
          ScreensPanel_update((long)param_1);
        }
      }
    }
    else {
      if (param_2 != 0x107) {
        if (param_2 == 0x157) goto LAB_00135f30;
        if (param_2 != 0x7f) goto LAB_00135db6;
      }
      if (0 < (int)param_1[0x4e4]) {
        iVar9 = (int)param_1[0x4e4] + -1;
        *(int *)(param_1 + 0x4e4) = iVar9;
        *(undefined1 *)((long)param_1 + (long)iVar9 + 0x2700) = 0;
        goto LAB_00135eec;
      }
    }
    goto LAB_00135db6;
  }
  a5 = (long *)param_1[4];
  iVar9 = (int)param_1[5];
  uVar23 = *(uint *)(a5 + 3);
  a3 = (ushort *)(ulong)uVar23;
  plVar22 = a5;
  iVar19 = iVar9;
  plVar7 = a5;
  if ((int)uVar23 < 1) {
    if (0x168 < param_2) {
      if (param_2 == 0x199) {
switchD_00136039_caseD_128:
        bVar8 = *(byte *)((long)param_1 + 0x2724) ^ 1;
        *(byte *)((long)param_1 + 0x2724) = bVar8;
        *(uint *)(param_1 + 0x4db) = bVar8 + 9;
        goto switchD_00135ed0_caseD_ffffffff;
      }
      goto switchD_00136039_caseD_104;
    }
    lVar20 = 0;
    if (param_2 < 0x102) {
      if (param_2 < 0x2e) {
        if (-2 < param_2) {
          switch(param_2) {
          case 10:
          case 0xd:
            goto switchD_00136039_caseD_128;
          case 0xe:
            goto switchD_00136039_caseD_10d;
          case 0x12:
            goto switchD_00135e98_caseD_10a;
          case 0x2b:
            goto switchD_00136039_caseD_110;
          case 0x2d:
            goto switchD_00136039_caseD_10f;
          case -1:
            goto switchD_00135ed0_caseD_ffffffff;
          }
        }
      }
      else {
        if (param_2 == 0x5b) goto switchD_00136039_caseD_10f;
        if (param_2 == 0x5d) goto switchD_00136039_caseD_110;
        if (0xfe < param_2) goto switchD_00136039_caseD_104;
      }
switchD_00135ed0_caseD_0:
      ppuVar13 = __ctype_b_loc();
      a3 = (ushort *)(ulong)uVar23;
      if ((*(byte *)((long)*ppuVar13 + (long)param_2 * 2 + 1) & 4) == 0) {
joined_r0x0013614f:
        a3 = (ushort *)(ulong)uVar23;
        if (0 < (int)uVar23) goto switchD_00135e98_caseD_104;
        goto switchD_00136039_caseD_104;
      }
LAB_00136650:
      uVar17 = Panel_selectByTyping(param_1,param_2,(long)a5,(long)a3,param_r8,(long)plVar22);
      a5 = (long *)param_1[4];
      uVar24 = uVar17 & 0xffffffff;
      if ((int)uVar17 == 4) {
        if ((int)a5[3] < 1) goto switchD_00136039_caseD_104;
        bVar6 = false;
        uVar24 = 2;
        iVar19 = (int)param_1[5];
        goto LAB_00136068;
      }
      if (0 < (int)a5[3]) {
        bVar6 = false;
        iVar19 = (int)param_1[5];
        goto LAB_00136068;
      }
      goto LAB_00136472;
    }
    switch(param_2) {
    case 0x102:
      lVar20 = 0;
      if (*(char *)((long)param_1 + 0x2724) != '\0') goto switchD_00136039_caseD_110;
LAB_001364ba:
      iVar19 = iVar9 + 1;
      if ((iVar19 < 0) || (uVar23 == 0)) {
        iVar19 = 0;
LAB_001364c5:
        *(int *)(param_1 + 5) = iVar19;
        *(undefined1 *)(param_1 + 9) = 1;
        goto joined_r0x0013614f;
      }
      if ((int)uVar23 <= iVar19) {
        iVar19 = uVar23 - 1;
        goto LAB_001364c5;
      }
LAB_00136699:
      lVar21 = *a5;
      *(int *)(param_1 + 5) = iVar19;
      lVar21 = *(long *)(lVar21 + (long)iVar19 * 8);
      if ((lVar21 == 0) || (lVar21 == lVar20)) goto switchD_00136039_caseD_104;
      lVar20 = *(long *)(lVar21 + 0x20);
      puVar25 = *(ulong **)(param_1[0x4dd] + 0x18);
      ColumnsPanel_fill(param_1[0x4de],lVar20,puVar25,(long)a3,param_r8,(long)a5);
      lVar16 = param_1[0x4df];
      lVar21 = *(long *)(*(long *)(lVar21 + 0x20) + 8);
      Vector_prune(*(long **)(lVar16 + 0x20),lVar20,extraout_RDX_01,(long)a3,param_r8,(long)a5);
      *(undefined4 *)(lVar16 + 0x40) = 0;
      *(undefined8 *)(lVar16 + 0x28) = 0;
      *(undefined1 *)(lVar16 + 0x48) = 1;
      if (lVar21 == 0) {
        FUN_0011ba60(lVar16,lVar20,extraout_RDX_02,(long)a3,param_r8,(long)a5);
        bVar6 = false;
        if (*puVar25 == 0) goto switchD_00135ed0_caseD_ffffffff;
        goto LAB_0013658a;
      }
      goto switchD_00135ed0_caseD_ffffffff;
    case 0x103:
switchD_00135e98_caseD_103:
      if (*(char *)((long)param_1 + 0x2724) == '\0') {
        iVar19 = iVar9 + -1;
        if ((iVar19 < 0) || (uVar23 == 0)) {
          iVar19 = 0;
        }
        else {
          if (iVar19 < (int)uVar23) goto LAB_00136699;
          iVar19 = uVar23 - 1;
        }
        *(int *)(param_1 + 5) = iVar19;
        uVar24 = 2;
        *(undefined1 *)(param_1 + 9) = 1;
        bVar6 = false;
        if (0 < (int)uVar23) goto LAB_00136068;
        goto switchD_00136039_caseD_104;
      }
      if (iVar9 == 0) goto joined_r0x001363b3;
LAB_00136233:
      puVar14 = (undefined8 *)(*a5 + -8 + (long)iVar9 * 8);
      uVar5 = *puVar14;
      puVar3 = (undefined8 *)(*a5 + -8 + (long)iVar9 * 8);
      *puVar3 = puVar14[1];
      puVar3[1] = uVar5;
      if (0 < iVar9) {
        *(int *)(param_1 + 5) = iVar9 + -1;
        goto joined_r0x001363b3;
      }
      bVar6 = true;
      uVar24 = 1;
      if (0 < (int)uVar23) goto LAB_00136068;
      break;
    default:
      goto switchD_00136039_caseD_104;
    case 0x106:
    case 0x152:
    case 0x153:
    case 0x168:
      Panel_onKey((long)param_1,param_2);
      goto switchD_00136039_caseD_104;
    case 0x10a:
      goto switchD_00135e98_caseD_10a;
    case 0x10d:
switchD_00136039_caseD_10d:
      lVar21 = param_1[0x4dd];
      if (*(long *)(lVar21 + 0x28) != 0) goto switchD_00136039_caseD_104;
      lVar20 = 0;
LAB_001362cc:
      (*(undefined8 *)(__fp - 0x50)) = 0;
      (*(undefined * *)(__fp - 0x68)) = &DAT_001491b7;
      (*(char * *)(__fp - 0x60)) = ((char *)(long)&s_PID_Command_001491bb /* "PID Command" */);
      (*(undefined * *)(__fp - 0x58)) = &DAT_0014828e;
      pvVar15 = Settings_newScreen(lVar21,&(*(undefined * *)(__fp - 0x68)));
      puVar14 = malloc(0x28);
      if (puVar14 == (undefined8 *)0x0) goto LAB_00136752;
      *puVar14 = ScreenListItem_class;
      pcVar12 = strdup(((char *)(long)&DAT_001491b7 /* "New" */));
      if (pcVar12 == (char *)0x0) goto LAB_00136752;
      puVar3 = (undefined8 *)param_1[4];
      puVar14[1] = pcVar12;
      lVar21 = param_1[5];
      puVar14[4] = pvVar15;
      *(undefined4 *)(puVar14 + 2) = 0;
      uVar23 = (int)lVar21 + 1;
      *(undefined1 *)((long)puVar14 + 0x14) = 0;
      Vector_insert(puVar3,uVar23,puVar14);
      *(undefined1 *)(param_1 + 9) = 1;
      uVar1 = *(int *)(param_1[4] + 0x18) - 1;
      if (*(int *)(param_1[4] + 0x18) <= (int)uVar23) {
        uVar23 = uVar1;
      }
      if ((int)uVar23 < 0) {
        uVar23 = 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x20);
      *(uint *)(param_1 + 5) = uVar23;
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)((long)param_1,0xffffffff,(ulong)uVar1,(long)a3,param_r8,(long)a5);
      }
      FUN_0012d550((long)param_1);
      uVar23 = *(uint *)((long *)param_1[4] + 3);
      plVar7 = (long *)param_1[4];
      plVar22 = a5;
joined_r0x001363b3:
      a5 = plVar7;
      if (0 < (int)uVar23) {
        bVar6 = true;
        uVar24 = 1;
        iVar19 = (int)param_1[5];
        goto LAB_00136068;
      }
      break;
    case 0x10f:
switchD_00136039_caseD_10f:
      if (iVar9 != 0) goto LAB_00136233;
      break;
    case 0x110:
switchD_00136039_caseD_110:
      Panel_moveSelectedDown((long)param_1);
      goto LAB_00136528;
    case 0x111:
      break;
    case 0x128:
    case 0x157:
      goto switchD_00136039_caseD_128;
    }
    goto switchD_00136039_caseD_111;
  }
  lVar20 = *(long *)(*a5 + (long)iVar9 * 8);
  if (0x168 < param_2) {
    bVar6 = false;
    uVar24 = 2;
    if (param_2 == 0x199) {
switchD_00135e98_caseD_128:
      bVar8 = *(byte *)((long)param_1 + 0x2724) ^ 1;
      *(byte *)((long)param_1 + 0x2724) = bVar8;
      a3 = (ushort *)(ulong)(bVar8 + 9);
      *(uint *)(param_1 + 0x4db) = bVar8 + 9;
      if (lVar20 != 0) {
        *(byte *)(lVar20 + 0x14) = bVar8;
      }
      bVar6 = false;
      uVar24 = 1;
    }
    goto LAB_00136068;
  }
  if (param_2 < 0x102) {
    if (param_2 < 0x2e) {
      if (-2 < param_2) {
        switch(param_2) {
        default:
          goto switchD_00135ed0_caseD_0;
        case 10:
        case 0xd:
          goto switchD_00135e98_caseD_128;
        case 0xe:
          goto switchD_00135e98_caseD_10d;
        case 0x12:
          goto switchD_00135e98_caseD_10a;
        case 0x2b:
          goto switchD_00135e98_caseD_110;
        case 0x2d:
          goto switchD_00135e98_caseD_10f;
        case -1:
          goto switchD_00135ed0_caseD_ffffffff;
        }
      }
      ppuVar13 = __ctype_b_loc();
      a3 = *ppuVar13;
      if ((*(byte *)((long)a3 + (long)param_2 * 2 + 1) & 4) == 0) goto switchD_00135e98_caseD_104;
      goto LAB_00136650;
    }
    if (param_2 == 0x5b) goto joined_r0x001365f2;
    if (param_2 == 0x5d) goto switchD_00135e98_caseD_110;
    if (param_2 < 0xff) goto switchD_00135ed0_caseD_0;
    goto switchD_00135e98_caseD_104;
  }
  switch(param_2) {
  case 0x102:
    if (*(char *)((long)param_1 + 0x2724) == '\0') goto LAB_001364ba;
  case 0x110:
switchD_00135e98_caseD_110:
    Panel_moveSelectedDown((long)param_1);
    iVar19 = (int)param_1[5];
    goto LAB_0013628b;
  case 0x103:
    goto switchD_00135e98_caseD_103;
  default:
    goto switchD_00135e98_caseD_104;
  case 0x106:
  case 0x152:
  case 0x153:
  case 0x168:
    Panel_onKey((long)param_1,param_2);
    iVar19 = (int)param_1[5];
    goto switchD_00135e98_caseD_104;
  case 0x10a:
switchD_00135e98_caseD_10a:
    FUN_0012d550((long)param_1);
    param_r8 = (long)*(uint *)(a5 + 3);
    if ((int)*(uint *)(a5 + 3) < 1) goto switchD_00135ed0_caseD_ffffffff;
    bVar6 = false;
    iVar19 = (int)param_1[5];
    uVar24 = 1;
    break;
  case 0x10d:
switchD_00135e98_caseD_10d:
    lVar21 = param_1[0x4dd];
    bVar6 = false;
    uVar24 = 2;
    if (*(long *)(lVar21 + 0x28) == 0) goto LAB_001362cc;
    break;
  case 0x10f:
switchD_00135e98_caseD_10f:
joined_r0x001365f2:
    if (iVar9 != 0) goto LAB_00136233;
    goto LAB_0013628b;
  case 0x111:
    if (uVar23 != 1) {
      Panel_remove((long)param_1,iVar9,(long)a5,(long)a3,param_r8,(long)a5);
      uVar23 = *(uint *)((long *)param_1[4] + 3);
      a3 = (ushort *)(ulong)uVar23;
      plVar7 = (long *)param_1[4];
      plVar22 = a5;
      goto joined_r0x001363b3;
    }
LAB_0013628b:
    bVar6 = true;
    uVar24 = 1;
    break;
  case 0x128:
  case 0x157:
    goto switchD_00135e98_caseD_128;
  }
LAB_00136068:
  lVar21 = *(long *)(*a5 + (long)iVar19 * 8);
  if ((lVar21 == 0) || (lVar21 == lVar20)) {
    if (bVar6) {
      a5 = (long *)param_1[4];
      goto LAB_001363c6;
    }
LAB_00136472:
    if ((int)uVar24 != 1) goto LAB_00135dbc;
  }
  else {
    lVar20 = *(long *)(lVar21 + 0x20);
    puVar25 = *(ulong **)(param_1[0x4dd] + 0x18);
    ColumnsPanel_fill(param_1[0x4de],lVar20,puVar25,(long)a3,param_r8,(long)plVar22);
    lVar16 = param_1[0x4df];
    lVar21 = *(long *)(*(long *)(lVar21 + 0x20) + 8);
    Vector_prune(*(long **)(lVar16 + 0x20),lVar20,extraout_RDX,(long)a3,param_r8,(long)plVar22);
    *(undefined4 *)(lVar16 + 0x40) = 0;
    *(undefined8 *)(lVar16 + 0x28) = 0;
    *(undefined1 *)(lVar16 + 0x48) = 1;
    if ((lVar21 == 0) &&
       (FUN_0011ba60(lVar16,lVar20,extraout_RDX_00,(long)a3,param_r8,(long)plVar22), a5 = plVar22,
       *puVar25 != 0)) {
LAB_0013658a:
      uVar24 = 0;
      do {
        puVar2 = (undefined4 *)(puVar25[1] + uVar24 * 0x18);
        lVar20 = *(long *)(puVar2 + 4);
        if (lVar20 != 0) {
          FUN_0011b960(*puVar2,lVar20,lVar16,(long)a3,param_r8,(long)a5);
        }
        uVar24 = uVar24 + 1;
      } while (uVar24 < *puVar25);
    }
    if (bVar6) {
LAB_00136528:
      a5 = (long *)param_1[4];
switchD_00136039_caseD_111:
      uVar24 = 1;
LAB_001363c6:
      iVar19 = (int)a5[3];
      free(*(void **)(param_1[0x4dd] + 0x30));
      lVar20 = param_1[0x4dd];
      if ((ulong)(long)(iVar19 + 1) >> 0x3d != 0) {
LAB_00136752:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      sVar11 = (long)(iVar19 + 1) * 8;
      pvVar15 = malloc(sVar11);
      if (pvVar15 == (void *)0x0) goto LAB_00136752;
      *(void **)(lVar20 + 0x30) = pvVar15;
      *(undefined8 *)((long)pvVar15 + (sVar11 - 8)) = 0;
      if (0 < iVar19) {
        lVar21 = *(long *)param_1[4];
        lVar16 = 0;
        do {
          *(undefined8 *)((long)pvVar15 + lVar16) =
               *(undefined8 *)(*(long *)(lVar21 + lVar16) + 0x20);
          lVar16 = lVar16 + 8;
        } while (sVar11 - 8 != lVar16);
      }
      *(int *)(lVar20 + 0x38) = iVar19;
      iVar18 = 0;
      if (-1 < iVar9) {
        iVar18 = iVar9;
      }
      iVar10 = iVar19 + -1;
      if (iVar9 < iVar19) {
        iVar10 = iVar18;
      }
      *(int *)(lVar20 + 0x3c) = iVar10;
      *(undefined8 *)(lVar20 + 0x40) = *(undefined8 *)((long)pvVar15 + (long)iVar10 * 8);
      goto LAB_00136472;
    }
  }
switchD_00135ed0_caseD_ffffffff:
  ScreensPanel_update((long)param_1);
LAB_00135db6:
  uVar24 = 1;
LAB_00135dbc:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar24;
switchD_00135e98_caseD_104:
  bVar6 = false;
  uVar24 = 2;
  goto LAB_00136068;
switchD_00136039_caseD_104:
  uVar24 = 2;
  goto LAB_00135dbc;
}


/* Settings_newDynamicScreen @ 0x136760 */

void * Settings_newDynamicScreen(long param_1,char *param_2,char *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  char *pcVar4;
  char *pcVar5;
  void *pvVar6;

  iVar2 = FUN_0012d610(*(ulong **)(param_1 + 0x18),*(char **)(param_3 + 0x40));
  puVar3 = malloc(0x38);
  if (puVar3 != (undefined8 *)0x0) {
    pcVar4 = strdup(param_2);
    if (pcVar4 != (char *)0x0) {
      pcVar5 = strdup(param_3);
      if (pcVar5 != (char *)0x0) {
        pvVar6 = calloc(0x84,4);
        if (pvVar6 != (void *)0x0) {
          puVar3[3] = pvVar6;
          uVar1 = *(undefined4 *)(param_3 + 0x48);
          *(undefined16 *)(*(undefined1 (*) [16])(puVar3 + 4)) = (undefined16)0x0;
          puVar3[6] = 0;
          puVar3[1] = pcVar5;
          pcVar5 = *(char **)(param_3 + 0x40);
          *(undefined4 *)((long)puVar3 + 0x24) = uVar1;
          *puVar3 = pcVar4;
          puVar3[2] = param_4;
          *(undefined4 *)(puVar3 + 5) = 1;
          *(int *)((long)puVar3 + 0x2c) = iVar2;
          pvVar6 = (void *)FUN_00135b80((long)puVar3,param_1,pcVar5);
          return pvVar6;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_00136840 @ 0x136840 */

undefined8
FUN_00136840(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long *__dest;
  undefined8 *puVar1;
  code *a2;
  int iVar2;
  undefined8 uVar3;
  void *pvVar4;
  undefined8 *puVar5;
  char *pcVar6;
  size_t sVar7;
  ushort **ppuVar8;
  long *a3;
  long lVar9;
  ushort *puVar10;
  long lVar11;
  long lVar12;
  int iVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  a3 = (long *)param_1[4];
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar13 = (int)a3[3];
  if (iVar13 < 1) {
    if (param_2 == 0x106) {
      Panel_onKey((long)param_1,0x106);
LAB_00136ba0:
      uVar3 = 2;
      goto LAB_00136a83;
    }
    if (0x106 < param_2) {
      if (param_2 < 0x154) {
        if (param_2 < 0x152) {
          lVar12 = 0;
          lVar11 = 0;
          if (param_2 == 0x10d) goto LAB_001368fc;
          if (param_2 == 0x128) goto LAB_001368c0;
        }
        else {
LAB_00136cb5:
          Panel_onKey((long)param_1,param_2);
        }
      }
      else {
        if (param_2 == 0x168) {
          param_2 = 0x168;
          goto LAB_00136cb5;
        }
        if ((param_2 == 0x199) || (param_2 == 0x157)) {
LAB_00136ce4:
          lVar11 = 0;
          goto LAB_001368c0;
        }
      }
      goto LAB_00136ba0;
    }
    if (param_2 == -1) goto LAB_00136a7e;
    if (-2 < param_2) {
      if (param_2 == 0xe) {
        lVar12 = 0;
        goto LAB_001368fc;
      }
      if (0xe < param_2) {
        lVar11 = 0;
        if (param_2 < 0xff) goto LAB_00136cfc;
        goto LAB_00136ba0;
      }
      if (param_2 == 10) goto LAB_00136ce4;
      lVar11 = 0;
      if (param_2 == 0xd) goto LAB_001368c0;
    }
    ppuVar8 = __ctype_b_loc();
    puVar10 = *ppuVar8;
    if ((*(byte *)((long)puVar10 + (long)param_2 * 2 + 1) & 4) == 0) goto LAB_00136ba0;
    lVar11 = 0;
LAB_00136b10:
    uVar3 = Panel_selectByTyping(param_1,param_2,(long)puVar10,(long)a3,param_r8,param_r9);
    a3 = (long *)param_1[4];
    iVar13 = (int)a3[3];
    lVar12 = lVar11;
    if ((int)uVar3 == 4) {
      uVar3 = 2;
    }
LAB_00136a64:
    if (iVar13 < 1) goto LAB_00136a83;
    lVar9 = (long)(int)param_1[5];
    lVar11 = lVar12;
LAB_00136a6d:
    lVar12 = *(long *)(*a3 + lVar9 * 8);
    if ((lVar12 == lVar11) || (lVar12 == 0)) goto LAB_00136a83;
  }
  else {
    lVar9 = (long)(int)param_1[5];
    lVar11 = *(long *)(*a3 + lVar9 * 8);
    if (param_2 == 0x106) {
      Panel_onKey((long)param_1,0x106);
      lVar9 = (long)(int)param_1[5];
LAB_00136c50:
      uVar3 = 2;
      goto LAB_00136a6d;
    }
    lVar12 = lVar11;
    if (0x106 < param_2) {
      if (param_2 < 0x154) {
        if (param_2 < 0x152) {
          if (param_2 == 0x10d) goto LAB_001368fc;
          if (param_2 == 0x128) goto LAB_001368c0;
        }
        else {
          Panel_onKey((long)param_1,param_2);
          lVar9 = (long)(int)param_1[5];
        }
      }
      else if (param_2 == 0x168) {
        Panel_onKey((long)param_1,0x168);
        lVar9 = (long)(int)param_1[5];
      }
      else if ((param_2 == 0x199) || (param_2 == 0x157)) {
LAB_001368c0:
        *(undefined4 *)(param_1 + 0x4db) = 9;
        uVar3 = 1;
        lVar12 = lVar11;
        goto LAB_00136a64;
      }
      goto LAB_00136c50;
    }
    if (param_2 != -1) {
      if (-2 < param_2) {
        if (param_2 == 0xe) {
LAB_001368fc:
          if ((char *)param_1[0x4e1] == (char *)0x0) {
            (*(undefined8 *)(__fp - 0x50)) = 0;
            (*(undefined * *)(__fp - 0x58)) = &DAT_0014828e;
            (*(undefined * *)(__fp - 0x68)) = &DAT_001491b7;
            (*(char * *)(__fp - 0x60)) = ((char *)(long)&s_PID_Command_001491bb /* "PID Command" */);
            pvVar4 = Settings_newScreen(param_1[0x4dd],&(*(undefined * *)(__fp - 0x68)));
          }
          else {
            pvVar4 = Settings_newDynamicScreen(param_1[0x4dd],((char *)(long)&DAT_001491b7 /* "New" */),(char *)param_1[0x4e1],0);
          }
          puVar5 = malloc(0x20);
          if (puVar5 == (undefined8 *)0x0) {
LAB_00136d57:
                    /* WARNING: Subroutine does not return */
            fail();
          }
          *puVar5 = ScreenNameListItem_class;
          pcVar6 = strdup(((char *)(long)&DAT_001491b7 /* "New" */));
          if (pcVar6 == (char *)0x0) goto LAB_00136d57;
          puVar5[1] = pcVar6;
          lVar11 = param_1[5];
          puVar5[3] = pvVar4;
          puVar1 = (undefined8 *)param_1[4];
          *(undefined4 *)(puVar5 + 2) = 0;
          iVar13 = (int)lVar11 + 1;
          *(undefined1 *)((long)puVar5 + 0x14) = 0;
          Vector_insert(puVar1,iVar13,puVar5);
          a3 = (long *)param_1[4];
          *(undefined1 *)(param_1 + 9) = 1;
          iVar2 = (int)a3[3];
          if (iVar2 <= iVar13) {
            iVar13 = iVar2 + -1;
          }
          if (iVar13 < 0) {
            iVar13 = 0;
          }
          a2 = *(code **)(*param_1 + 0x20);
          *(int *)(param_1 + 5) = iVar13;
          if (a2 != (code *)0x0) {
            (*a2)((long)param_1,0xffffffff,(long)a2,(long)a3,param_r8,param_r9);
            a3 = (long *)param_1[4];
            iVar2 = (int)a3[3];
          }
          if (0 < iVar2) {
            lVar9 = param_1[5];
            lVar11 = *(long *)(*a3 + (long)(int)lVar9 * 8);
            if (lVar11 != 0) {
              pcVar6 = *(char **)(lVar11 + 8);
              *(undefined1 *)((long)param_1 + 0x49) = 1;
              __dest = param_1 + 0x4de;
              param_1[0x4e4] = lVar11;
              param_1[0x4e2] = (long)pcVar6;
              strncpy((char *)__dest,pcVar6,0x14);
              *(undefined1 *)((long)param_1 + 0x2704) = 0;
              sVar7 = strlen((char *)__dest);
              *(int *)(param_1 + 0x4e3) = (int)sVar7;
              *(long **)(lVar11 + 8) = __dest;
              *(undefined4 *)(param_1 + 0x4db) = 0x53;
              sVar7 = strlen((char *)__dest);
              *(int *)(param_1 + 6) = (int)sVar7;
              *(int *)((long)param_1 + 0x1c) =
                   (((int)lVar9 + *(int *)((long)param_1 + 0xc)) - (int)param_1[8]) + 1;
              iVar13 = (int)a3[3];
              *(int *)(param_1 + 3) =
                   ((int)sVar7 + (int)param_1[1]) - *(int *)((long)param_1 + 0x44);
              uVar3 = 1;
              goto LAB_00136a64;
            }
          }
          goto LAB_00136a7e;
        }
        if (0xe < param_2) {
          if (0xfe < param_2) goto LAB_00136c50;
LAB_00136cfc:
          ppuVar8 = __ctype_b_loc();
          puVar10 = (ushort *)(long)param_2;
          uVar3 = 2;
          lVar12 = lVar11;
          if ((*(byte *)((long)*ppuVar8 + (long)puVar10 * 2 + 1) & 4) != 0) goto LAB_00136b10;
          goto LAB_00136a64;
        }
        if ((param_2 == 10) || (param_2 == 0xd)) goto LAB_001368c0;
      }
      ppuVar8 = __ctype_b_loc();
      puVar10 = *ppuVar8;
      if ((*(byte *)((long)puVar10 + (long)param_2 * 2 + 1) & 4) != 0) goto LAB_00136b10;
      goto LAB_00136c50;
    }
  }
LAB_00136a7e:
  uVar3 = 1;
LAB_00136a83:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


/* FUN_00136d60 @ 0x136d60 */

undefined8
FUN_00136d60(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  long lVar1;
  char *__s1;
  long lVar2;
  int iVar3;
  ushort **ppuVar4;
  long lVar5;
  undefined8 *puVar6;
  char *pcVar7;
  undefined8 uVar8;
  long extraout_RDX;
  undefined4 in_register_00000034;
  long lVar9;

  lVar5 = CONCAT44(in_register_00000034,param_2);
  lVar2 = param_1[5];
  if (param_2 < 0x104) {
    if (param_2 < 0x102) {
      if (param_2 != -1) {
        if (param_2 == 0xe) goto LAB_00136de0;
        if (0xfe < param_2) {
          return 2;
        }
        ppuVar4 = __ctype_b_loc();
        lVar5 = (long)param_2;
        if ((*(byte *)((long)*ppuVar4 + lVar5 * 2 + 1) & 4) == 0) {
          return 2;
        }
        uVar8 = Panel_selectByTyping(param_1,param_2,(long)*ppuVar4,param_rcx,param_r8,param_r9);
        if ((int)uVar8 == 4) {
          return 2;
        }
        if ((int)uVar8 != 1) {
          return uVar8;
        }
      }
      goto LAB_00136e30;
    }
  }
  else {
    if (param_2 == 0x10d) {
LAB_00136de0:
      uVar8 = FUN_00136840((long *)param_1[0x4de],param_2,param_rdx,param_rcx,param_r8,param_r9);
      return uVar8;
    }
    if (param_2 < 0x10e) {
      if (param_2 != 0x106) {
        return 2;
      }
    }
    else if (param_2 < 0x154) {
      if (param_2 < 0x152) {
        return 2;
      }
    }
    else if (param_2 != 0x168) {
      return 2;
    }
  }
  Panel_onKey((long)param_1,param_2);
  if ((int)lVar2 == (int)param_1[5]) {
    return 2;
  }
LAB_00136e30:
  if (0 < (int)((long *)param_1[4])[3]) {
    lVar2 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8);
    if (lVar2 != 0) {
      lVar1 = param_1[0x4de];
      __s1 = *(char **)(lVar2 + 0x18);
      lVar9 = 0;
      lVar2 = *(long *)(lVar1 + 0x26e8);
      Vector_prune(*(long **)(lVar1 + 0x20),lVar5,(long)(int)param_1[5],param_rcx,param_r8,param_r9)
      ;
      *(undefined8 *)(lVar1 + 0x28) = 0;
      iVar3 = *(int *)(lVar2 + 0x38);
      *(undefined4 *)(lVar1 + 0x40) = 0;
      *(undefined1 *)(lVar1 + 0x48) = 1;
      if (iVar3 != 0) {
        do {
          while( true ) {
            puVar6 = *(undefined8 **)(*(long *)(lVar2 + 0x30) + lVar9 * 8);
            pcVar7 = (char *)puVar6[1];
            if (__s1 == (char *)0x0) break;
            if ((pcVar7 != (char *)0x0) && (iVar3 = strcmp(__s1,pcVar7), iVar3 == 0)) {
LAB_00136ea9:
              pcVar7 = (char *)*puVar6;
              puVar6 = malloc(0x18);
              if (puVar6 == (undefined8 *)0x0) {
LAB_00136f9f:
                    /* WARNING: Subroutine does not return */
                fail();
              }
              *puVar6 = ListItem_class;
              pcVar7 = strdup(pcVar7);
              if (pcVar7 == (char *)0x0) goto LAB_00136f9f;
              puVar6[1] = pcVar7;
              *(int *)(puVar6 + 2) = (int)lVar9;
              *(undefined1 *)((long)puVar6 + 0x14) = 0;
              Panel_add(lVar1,(long)puVar6,extraout_RDX,param_rcx,param_r8,param_r9);
            }
            lVar9 = lVar9 + 1;
            if (*(uint *)(lVar2 + 0x38) <= (uint)lVar9) goto LAB_00136f30;
          }
          if (pcVar7 == (char *)0x0) goto LAB_00136ea9;
          lVar9 = lVar9 + 1;
        } while ((uint)lVar9 < *(uint *)(lVar2 + 0x38));
      }
LAB_00136f30:
      *(char **)(lVar1 + 0x2708) = __s1;
    }
  }
  return 1;
}


/* FUN_00136fb0 @ 0x136fb0 */

undefined8
FUN_00136fb0(long *param_1,int param_2,long param_rdx,long param_rcx,long param_r8,long param_r9)

{
  long *plVar1;
  long lVar2;
  undefined8 *puVar3;
  char *__s1;
  int iVar4;
  size_t sVar5;
  undefined8 uVar6;
  char *pcVar7;

  if (param_1[0x4e4] == 0) {
    uVar6 = FUN_00136840(param_1,param_2,param_rdx,param_rcx,param_r8,param_r9);
    return uVar6;
  }
  if ((param_2 - 0x20U < 0x5f) && (param_2 != 0x3d)) {
    iVar4 = (int)param_1[0x4e3];
    if (0x12 < iVar4) {
      return 1;
    }
    *(char *)((long)param_1 + (long)iVar4 + 0x26f0) = (char)param_2;
    *(int *)(param_1 + 0x4e3) = iVar4 + 1;
    goto LAB_00137041;
  }
  if (param_2 == 0x1b) {
    if ((int)((long *)param_1[4])[3] < 1) {
      return 1;
    }
    lVar2 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8);
    if (lVar2 == 0) {
      return 1;
    }
    *(long *)(lVar2 + 8) = param_1[0x4e2];
    param_1[0x4e4] = 0;
    *(undefined1 *)((long)param_1 + 0x49) = 0;
    *(undefined4 *)(param_1 + 0x4db) = 9;
    return 1;
  }
  if (0x1b < param_2) {
    if (param_2 != 0x107) {
      if (param_2 == 0x157) goto LAB_0013710e;
      if (param_2 != 0x7f) {
        return 1;
      }
    }
    if ((int)param_1[0x4e3] < 1) {
      return 1;
    }
    iVar4 = (int)param_1[0x4e3] + -1;
    *(int *)(param_1 + 0x4e3) = iVar4;
    *(undefined1 *)((long)param_1 + (long)iVar4 + 0x26f0) = 0;
LAB_00137041:
    sVar5 = strlen((char *)(param_1 + 0x4de));
    *(int *)(param_1 + 6) = (int)sVar5;
    *(int *)(param_1 + 3) = ((int)sVar5 + (int)param_1[1]) - *(int *)((long)param_1 + 0x44);
    *(int *)((long)param_1 + 0x1c) =
         (((int)param_1[5] + *(int *)((long)param_1 + 0xc)) - (int)param_1[8]) + 1;
    return 1;
  }
  if ((param_2 != 10) && (param_2 != 0xd)) {
    return 1;
  }
LAB_0013710e:
  if ((int)((long *)param_1[4])[3] < 1) {
    return 1;
  }
  lVar2 = *(long *)(*(long *)param_1[4] + (long)(int)param_1[5] * 8);
  if (lVar2 == 0) {
    return 1;
  }
  free((void *)param_1[0x4e2]);
  pcVar7 = strdup((char *)(param_1 + 0x4de));
  if (pcVar7 != (char *)0x0) {
    *(char **)(lVar2 + 8) = pcVar7;
    puVar3 = *(undefined8 **)(lVar2 + 0x18);
    param_1[0x4e4] = 0;
    __s1 = (char *)*puVar3;
    *(undefined1 *)((long)param_1 + 0x49) = 0;
    *(undefined4 *)(param_1 + 0x4db) = 9;
    if ((__s1 == (char *)0x0) || (iVar4 = strcmp(__s1,pcVar7), iVar4 != 0)) {
      free(__s1);
      pcVar7 = strdup(pcVar7);
      if (pcVar7 == (char *)0x0) goto LAB_001371b8;
      *puVar3 = pcVar7;
    }
    lVar2 = param_1[0x4dd];
    plVar1 = (long *)(lVar2 + 0x78);
    *plVar1 = *plVar1 + 1;
    *(undefined1 *)(lVar2 + 0x74) = 1;
    return 1;
  }
LAB_001371b8:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Settings_new @ 0x138550 */

undefined8 * Settings_new(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  int iVar1;
  __uid_t __uid;
  undefined8 *puVar2;
  void *pvVar3;
  char *pcVar4;
  undefined8 uVar5;
  char *pcVar6;
  char *__path;
  passwd *ppVar7;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  puVar2 = calloc(1,0x80);
  if (puVar2 == (undefined8 *)0x0) {
LAB_001388d5:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  puVar2[5] = param_4;
  puVar2[3] = param_3;
  puVar2[4] = param_2;
  *(undefined4 *)((long)puVar2 + 0xc) = 0;
  pvVar3 = calloc(2,0x18);
  if (pvVar3 == (void *)0x0) goto LAB_001388d5;
  puVar2[2] = pvVar3;
  *(undefined2 *)(puVar2 + 0xc) = 1;
  *(undefined8 *)((long)puVar2 + 100) = 0x10100000005;
  *(undefined4 *)(puVar2 + 0xe) = 0;
  *(undefined1 *)((long)puVar2 + 0x6d) = 1;
  puVar2[10] = 0x1000000010000;
  puVar2[0xb] = 0x100010000000100;
  pvVar3 = calloc(0x10,1);
  if (pvVar3 == (void *)0x0) goto LAB_001388d5;
  puVar2[6] = pvVar3;
  *(undefined4 *)(puVar2 + 7) = 0;
  pcVar4 = getenv(((char *)(long)&s_HTOPRC_0014950c /* "HTOPRC" */));
  if (pcVar4 == (char *)0x0) {
    pcVar4 = getenv(((char *)(long)(__sec_rodata + 0x251e) /* "HOME" */));
    if (pcVar4 == (char *)0x0) {
      __uid = getuid();
      pcVar4 = ((char *)(long)&DAT_00149c0c /* "" */);
      ppVar7 = getpwuid(__uid);
      if (ppVar7 != (passwd *)0x0) {
        pcVar4 = ppVar7->pw_dir;
      }
    }
    pcVar6 = getenv(((char *)(long)&s_XDG_CONFIG_HOME_00149513 /* "XDG_CONFIG_HOME" */));
    if (pcVar6 == (char *)0x0) {
      pvVar3 = String_cat(pcVar4,((char *)(long)&s___config_htop_htoprc_00149523 /* "/.config/htop/htoprc" */));
      *puVar2 = pvVar3;
      __path = String_cat(pcVar4,((char *)(long)&s___config_00149538 /* "/.config" */));
      pcVar6 = String_cat(pcVar4,((char *)(long)&s___config_htop_00149541 /* "/.config/htop" */));
    }
    else {
      pvVar3 = String_cat(pcVar6,((char *)(long)(__sec_rodata + 0x252b) /* "/htop/htoprc" */));
      *puVar2 = pvVar3;
      __path = strdup(pcVar6);
      if (__path == (char *)0x0) goto LAB_001388d5;
      pcVar6 = String_cat(pcVar6,((char *)(long)(__sec_rodata + 0x2549) /* "/htop" */));
    }
    pcVar4 = String_cat(pcVar4,((char *)(long)&s___htoprc_0014954f /* "/.htoprc" */));
    mkdir(__path,0x1c0);
    mkdir(pcVar6,0x1c0);
    free(pcVar6);
    free(__path);
    iVar1 = lstat(pcVar4,&(*(struct stat *)(__fp - 0xd8)));
    if ((iVar1 == 0) && (((*(struct stat *)(__fp - 0xd8)).st_mode & 0xf000) != 0xa000)) {
      *(undefined1 *)((long)puVar2 + 0x6f) = 1;
      *(undefined1 *)((long)puVar2 + 0x74) = 0;
      puVar2[9] = 0xf00000000;
      uVar5 = FUN_001373f0((long)puVar2,pcVar4,param_1);
      if ((char)uVar5 != '\0') {
        iVar1 = Settings_write(puVar2,'\0');
        if (iVar1 == 0) {
          unlink(pcVar4);
          free(pcVar4);
        }
        else {
          free(pcVar4);
        }
        goto LAB_0013866c;
      }
      free(pcVar4);
      pcVar4 = (char *)*puVar2;
    }
    else {
      free(pcVar4);
      pcVar4 = (char *)*puVar2;
      *(undefined1 *)((long)puVar2 + 0x6f) = 1;
      *(undefined1 *)((long)puVar2 + 0x74) = 0;
      puVar2[9] = 0xf00000000;
    }
  }
  else {
    pcVar4 = strdup(pcVar4);
    if (pcVar4 == (char *)0x0) goto LAB_001388d5;
    *puVar2 = pcVar4;
    *(undefined1 *)((long)puVar2 + 0x6f) = 1;
    *(undefined1 *)((long)puVar2 + 0x74) = 0;
    puVar2[9] = 0xf00000000;
  }
  uVar5 = FUN_001373f0((long)puVar2,pcVar4,param_1);
  if ((char)uVar5 == '\0') {
    *(undefined1 *)((long)puVar2 + 0x6e) = 1;
    *(undefined1 *)((long)puVar2 + 0x74) = 1;
    uVar5 = FUN_001373f0((long)puVar2,((char *)(long)&s__etc_htoprc_00149558 /* "/etc/htoprc" */),param_1);
    if ((char)uVar5 == '\0') {
      FUN_00132480((long)puVar2,param_1);
      if (*(int *)(puVar2 + 7) == 0) {
        Settings_newScreen((long)puVar2,(undefined8 *)Platform_defaultScreens);
        Settings_newScreen((long)puVar2,(undefined8 *)(Platform_defaultScreens + 0x20));
      }
    }
  }
LAB_0013866c:
  *(undefined4 *)((long)puVar2 + 0x3c) = 0;
  uVar5 = *(undefined8 *)puVar2[6];
  puVar2[0xf] = 1;
  puVar2[8] = uVar5;
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001388e0 @ 0x1388e0 */

undefined8 FUN_001388e0(long param_1)

{
  *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + 1;
  return 1;
}


/* FUN_001388f0 @ 0x1388f0 */

bool FUN_001388f0(long *param_1,undefined1 param_2)

{
  ulong uVar1;
  ulong uVar2;

  uVar1 = param_1[2];
  uVar2 = param_1[1];
  if (uVar1 < uVar2) {
    *(undefined1 *)(*param_1 + uVar1) = param_2;
    param_1[2] = param_1[2] + 1;
  }
  return uVar1 < uVar2;
}


/* FUN_00138920 @ 0x138920 */

int FUN_00138920(long param_1,long param_2)

{
  int iVar1;

  iVar1 = (uint)(*(uint *)(param_2 + 8) < *(uint *)(param_1 + 8)) -
          (uint)(*(uint *)(param_1 + 8) < *(uint *)(param_2 + 8));
  if (iVar1 == 0) {
    iVar1 = (uint)(*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0xc)) -
            (uint)(*(uint *)(param_1 + 0xc) < *(uint *)(param_2 + 0xc));
  }
  return iVar1;
}

