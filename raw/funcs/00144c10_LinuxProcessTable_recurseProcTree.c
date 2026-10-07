/* LinuxProcessTable_recurseProcTree @ 00144c10 size 8149 */

/* DWARF original prototype: _Bool LinuxProcessTable_recurseProcTree(LinuxProcessTable * this,
   openat_arg_t parentFd, LinuxMachine * lhost, char * dirname, Process * parent) */

_Bool LinuxProcessTable_recurseProcTree
                (LinuxProcessTable *this,openat_arg_t parentFd,LinuxMachine_2 *lhost,char *dirname,
                Process_2 *parent)

{
  uint *puVar1;
  char *pcVar2;
  _Bool _Var3;
  _Bool _Var4;
  _Bool _Var5;
  _Bool _Var6;
  _Bool _Var7;
  byte bVar8;
  wchar_t wVar9;
  long lVar10;
  Settings__3 *pSVar11;
  ScreenSettings_3 *pSVar12;
  Hashtable_2 *pHVar13;
  HashtableItem *pHVar14;
  uint64_t uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  Vector *this_00;
  Machine__2 *pMVar18;
  bool bVar19;
  char cVar20;
  _Bool _Var21;
  _Bool _Var22;
  int iVar23;
  int parentFd_00;
  wchar_t wVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  wchar_t wVar28;
  int iVar29;
  DIR_2 *__dirp;
  dirent *pdVar30;
  ulong uVar31;
  HashtableItem *pHVar32;
  long lVar33;
  ulong uVar34;
  char *pcVar35;
  FILE_2 *pFVar36;
  long lVar37;
  ulong uVar38;
  LinuxProcess *lp;
  void *p0;
  void *pvVar39;
  size_t sVar40;
  nl_sock *pnVar41;
  char *pcVar42;
  byte *pbVar43;
  int *piVar44;
  long *plVar45;
  uint uVar46;
  ulong uVar47;
  long lVar48;
  void **ppvVar49;
  TtyDriver *pTVar50;
  byte *pbVar51;
  uint va1;
  long *va3;
  byte bVar52;
  byte *pbVar53;
  uint va1_00;
  long in_FS_OFFSET;
  bool bVar54;
  float percentage;
  double dVar55;
  double dVar56;
  float fVar57;
  uint local_620;
  Hashtable *local_618;
  LinuxProcess *local_608;
  Machine__2 *local_5f8;
  long dummy;
  char *endptr;
  char statCommand [129];
  char path [20];
  ulong local_4b0;
  char buffer [1024];

  lVar10 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar11 = (lhost->super).settings;
  pSVar12 = pSVar11->ss;
  (this->super).runningTasks = lhost->runningTasks;
  iVar23 = openat(parentFd,dirname,0x30000);
  if (iVar23 < 0) {
    if (lVar10 == *(long *)(in_FS_OFFSET + 0x28)) {
      return false;
    }
  }
  else {
    __dirp = fdopendir(iVar23);
    if (__dirp == (DIR_2 *)0x0) {
      if (lVar10 == *(long *)(in_FS_OFFSET + 0x28)) {
        iVar23 = close(iVar23);
        return SUB41(iVar23,0);
      }
    }
    else {
      _Var3 = pSVar11->hideKernelThreads;
      _Var4 = pSVar11->hideUserlandThreads;
      _Var5 = pSVar11->hideRunningInContainer;
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: wchar_t pid@[???]
                       Unresolved local var: wchar_t procFd@[???]
                       Unresolved local var: _Bool preExisting@[???]
                       Unresolved local var: Process * proc@[???]
                       Unresolved local var: LinuxProcess * lp@[???]
                       Unresolved local var: _Bool scanMainThread@[???]
                       Unresolved local var: ulonglong lasttimes@[???]
                       Unresolved local var: ulong tty_nr@[???]
                       Unresolved local var: ulong parsedPid@[???] */
LAB_00144cd6:
      pdVar30 = readdir(__dirp);
      if (pdVar30 != (dirent *)0x0) {
        if ((pdVar30->d_type & 0xfb) == 0) {
          cVar20 = pdVar30->d_name[0];
          pcVar35 = pdVar30->d_name;
          if (cVar20 == '.') {
            cVar20 = pdVar30->d_name[1];
            pcVar35 = pdVar30->d_name + 1;
          }
          if ((((((byte)(cVar20 - 0x30U) < 10) &&
                (uVar31 = __isoc23_strtoul(pcVar35,&endptr,10), uVar31 - 1 < 0xfffffffffffffffe)) &&
               (*endptr == '\0')) &&
              ((wVar28 = (wchar_t)uVar31, parent == (Process_2 *)0x0 ||
               (wVar28 != (parent->super).id)))) &&
             (parentFd_00 = openat(iVar23,pdVar30->d_name,0x30000), -1 < parentFd_00)) {
                    /* Unresolved local var: Table * table@[???]
                       Unresolved local var: Process * proc@[DW_OP_reg14(R14)] */
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
            pHVar13 = (this->super).super.table;
            uVar38 = pHVar13->size;
            pHVar14 = pHVar13->buckets;
            uVar31 = (uVar31 & 0xffffffff) % uVar38;
            pHVar32 = pHVar14 + uVar31;
            lp = pHVar32->value;
            if (lp != (LinuxProcess *)0x0) {
              uVar47 = 0;
              do {
                if (wVar28 == pHVar32->key) {
                  wVar24 = (lp->super).super.id;
                  if (parent == (Process_2 *)0x0) {
                    (lp->super).super.group = wVar28;
                    wVar9 = wVar28;
                  }
                  else {
                    wVar9 = (parent->super).id;
                    (lp->super).super.group = wVar9;
                  }
                  (lp->super).isUserlandThread = wVar9 != wVar24;
                  LinuxProcessTable_recurseProcTree(this,parentFd_00,lhost,((char *)0x14a1aa /* "task" */),(Process_2 *)lp);
                  if ((_Var3 != false) && ((lp->super).isKernelThread != false)) {
                    (lp->super).super.updated = true;
                    (lp->super).super.show = false;
                    puVar1 = &(this->super).kernelThreads;
                    *puVar1 = *puVar1 + 1;
                    puVar1 = &(this->super).totalTasks;
                    *puVar1 = *puVar1 + 1;
                    close(parentFd_00);
                    goto LAB_00144cd6;
                  }
                  local_608 = lp;
                  if (_Var4 == false) {
                    if ((_Var5 == false) || ((lp->super).isRunningInContainer == false)) {
                      uVar26 = pSVar12->flags;
                      goto LAB_00144f02;
                    }
                  }
                  else {
                    if ((lp->super).isUserlandThread != false) {
                      (lp->super).super.updated = true;
                      (lp->super).super.show = false;
                      puVar1 = &(this->super).userlandThreads;
                      *puVar1 = *puVar1 + 1;
                      puVar1 = &(this->super).totalTasks;
                      *puVar1 = *puVar1 + 1;
                      close(parentFd_00);
                      goto LAB_00144cd6;
                    }
                    if ((_Var5 == false) || ((lp->super).isRunningInContainer == false)) {
                      _Var21 = false;
                      if ((pSVar12->flags & 1) == 0) goto LAB_00145140;
                      local_5f8 = (Machine__2 *)(lp->super).super.host;
                      goto LAB_00145a8a;
                    }
                  }
                  (lp->super).super.updated = true;
                  (lp->super).super.show = false;
                  close(parentFd_00);
                  goto LAB_00144cd6;
                }
                if (pHVar32->probe < uVar47) break;
                uVar31 = uVar31 + 1;
                if (uVar38 == uVar31) {
                  uVar31 = 0;
                  pHVar32 = pHVar14;
                }
                else {
                  pHVar32 = pHVar14 + uVar31;
                }
                lp = pHVar32->value;
                uVar47 = uVar47 + 1;
              } while (lp != (LinuxProcess *)0x0);
            }
                    /* Unresolved local var: Table * table@[???]
                       Unresolved local var: Process * proc@[???] */
                    /* Unresolved local var: LinuxProcess * this@[???]
                       Unresolved local var: void * data@[???] */
            pMVar18 = (this->super).super.host;
            lp = calloc(1,0x348);
            if (lp == (LinuxProcess *)0x0) {
LAB_00145b91:
                    /* WARNING: Subroutine does not return */
              fail();
            }
            (lp->super).super.host = (Machine__4 *)pMVar18;
            *(undefined4 *)&(lp->super).super.tag = 0x1000100;
            (lp->super).super.super.klass = (ObjectClass *)&LinuxProcess_class;
            (lp->super).super.updated = false;
            (lp->super).cmdlineBasenameEnd = L'\xffffffff';
            (lp->super).st_uid = 0xffffffff;
            (lp->super).super.id = wVar28;
            if (parent == (Process_2 *)0x0) {
              (lp->super).super.group = wVar28;
              (lp->super).isUserlandThread = false;
            }
            else {
              wVar24 = (parent->super).id;
              (lp->super).super.group = wVar24;
              (lp->super).isUserlandThread = wVar28 != wVar24;
            }
            LinuxProcessTable_recurseProcTree(this,parentFd_00,lhost,((char *)0x14a1aa /* "task" */),(Process_2 *)lp);
            local_608 = (LinuxProcess *)0x0;
            uVar26 = pSVar12->flags;
            if (_Var4 == false) {
LAB_00144f02:
              _Var21 = (_Bool)(((lp->super).isKernelThread ^ 1U) & parent == (Process_2 *)0x0);
              if ((uVar26 & 1) != 0) {
                    /* Unresolved local var: Process * process@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: ulonglong last_read@[???]
                       Unresolved local var: ulonglong last_write@[???]
                       Unresolved local var: ulonglong time_delta@[???]
                       Unresolved local var: char * line@[???] */
                local_5f8 = (Machine__2 *)(lp->super).super.host;
                path[0] = 'i';
                path[1] = 'o';
                path[2] = '\0';
                path[3] = '\0';
                path[4] = '\0';
                path[5] = '\0';
                path[6] = '\0';
                path[7] = '\0';
                path[8] = '\0';
                path[9] = '\0';
                path[10] = '\0';
                path[0xb] = '\0';
                path[0xc] = '\0';
                path[0xd] = '\0';
                path[0xe] = '\0';
                path[0xf] = '\0';
                path[0x10] = '\0';
                path[0x11] = '\0';
                path[0x12] = '\0';
                path[0x13] = '\0';
                if (_Var21 == false) {
                  _Var21 = false;
                }
                else {
                  _Var21 = true;
                  xSnprintf(path,0x14,((char *)0x14a0eb /* "task/%i/io" */),(lp->super).super.id);
                }
                goto LAB_00144f7e;
              }
            }
            else {
              _Var21 = false;
              if ((uVar26 & 1) != 0) {
                local_5f8 = (Machine__2 *)(lp->super).super.host;
LAB_00145a8a:
                _Var21 = false;
                path[0] = 'i';
                path[1] = 'o';
                path[2] = '\0';
                path[3] = '\0';
                path[4] = '\0';
                path[5] = '\0';
                path[6] = '\0';
                path[7] = '\0';
                path[8] = '\0';
                path[9] = '\0';
                path[10] = '\0';
                path[0xb] = '\0';
                path[0xc] = '\0';
                path[0xd] = '\0';
                path[0xe] = '\0';
                path[0xf] = '\0';
                path[0x10] = '\0';
                path[0x11] = '\0';
                path[0x12] = '\0';
                path[0x13] = '\0';
LAB_00144f7e:
                    /* Unresolved local var: wchar_t fd@[???] */
                wVar24 = openat(parentFd_00,path,0);
                if (wVar24 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
                  piVar44 = __errno_location();
                  lVar33 = (long)-*piVar44;
                }
                else {
                  lVar33 = readfd_internal(wVar24,buffer,0x400);
                }
                uVar31 = local_5f8->realtimeMs;
                if (lVar33 < 0) {
                  lp->io_cancelled_write_bytes = 0xffffffffffffffff;
                  lp->io_rate_read_bps = NAN;
                  lp->io_rate_write_bps = NAN;
                  *(undefined4 *)&lp->io_rchar = 0xffffffff;
                  *(undefined4 *)((long)&lp->io_rchar + 4) = 0xffffffff;
                  *(undefined4 *)&lp->io_wchar = 0xffffffff;
                  *(undefined4 *)((long)&lp->io_wchar + 4) = 0xffffffff;
                  *(undefined4 *)&lp->io_syscr = 0xffffffff;
                  *(undefined4 *)((long)&lp->io_syscr + 4) = 0xffffffff;
                  *(undefined4 *)&lp->io_syscw = 0xffffffff;
                  *(undefined4 *)((long)&lp->io_syscw + 4) = 0xffffffff;
                  *(undefined4 *)&lp->io_read_bytes = 0xffffffff;
                  *(undefined4 *)((long)&lp->io_read_bytes + 4) = 0xffffffff;
                  *(undefined4 *)&lp->io_write_bytes = 0xffffffff;
                  *(undefined4 *)((long)&lp->io_write_bytes + 4) = 0xffffffff;
                }
                else {
                  uVar38 = lp->io_read_bytes;
                  uVar47 = lp->io_write_bytes;
                  uVar34 = 0;
                  if (lp->io_last_scan_time_ms < uVar31) {
                    uVar34 = uVar31 - lp->io_last_scan_time_ms;
                  }
                  endptr = buffer;
                  while (pcVar35 = strsep(&endptr,((char *)0x147506 /* "\n" */)), pcVar35 != (char *)0x0) {
                    cVar20 = *pcVar35;
                    if (cVar20 == 's') {
                      if ((pcVar35[4] == 'r') &&
                         (iVar25 = strncmp(pcVar35 + 1,((char *)0x14a108 /* "yscr: " */),6), iVar25 == 0)) {
                        uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                        lp->io_syscr = uVar31;
                      }
                      else {
                        iVar25 = strncmp(pcVar35 + 1,((char *)0x14a10f /* "yscw: " */),6);
                        if (iVar25 == 0) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                          lp->io_syscw = uVar31;
                        }
                      }
                    }
                    else if (cVar20 < 't') {
                      if (cVar20 == 'c') {
                        iVar25 = strncmp(pcVar35 + 1,((char *)0x14a116 /* "ancelled_write_bytes: " */),0x16);
                        if (iVar25 == 0) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 0x17,(char **)0x0,10);
                          lp->io_cancelled_write_bytes = uVar31;
                        }
                      }
                      else if (cVar20 == 'r') {
                        if ((pcVar35[1] == 'c') &&
                           (iVar25 = strncmp(pcVar35 + 2,((char *)0x14a0f6 /* "har: " */),5), iVar25 == 0)) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                          lp->io_rchar = uVar31;
                        }
                        else {
                          iVar25 = strncmp(pcVar35 + 1,((char *)0x14a0fc /* "ead_bytes: " */),0xb);
                          if (iVar25 == 0) {
                            uVar31 = __isoc23_strtoull(pcVar35 + 0xc,(char **)0x0,10);
                            dVar55 = NAN;
                            lp->io_read_bytes = uVar31;
                            if (uVar34 != 0) {
                              dVar55 = 0.0;
                              if (uVar38 < uVar31) {
                                dVar55 = (double)(uVar31 - uVar38) * 1000.0;
                              }
                              dVar55 = dVar55 / (double)uVar34;
                            }
                            lp->io_rate_read_bps = dVar55;
                          }
                        }
                      }
                    }
                    else if (cVar20 == 'w') {
                      if ((pcVar35[1] == 'c') &&
                         (iVar25 = strncmp(pcVar35 + 2,((char *)0x14a0f6 /* "har: " */),5), iVar25 == 0)) {
                        uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                        lp->io_wchar = uVar31;
                      }
                      else {
                        iVar25 = strncmp(pcVar35 + 1,((char *)0x14a120 /* "rite_bytes: " */),0xc);
                        if (iVar25 == 0) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 0xd,(char **)0x0,10);
                          dVar55 = NAN;
                          lp->io_write_bytes = uVar31;
                          if (uVar34 != 0) {
                            dVar55 = 0.0;
                            if (uVar47 < uVar31) {
                              dVar55 = (double)(uVar31 - uVar47) * 1000.0;
                            }
                            dVar55 = dVar55 / (double)uVar34;
                          }
                          lp->io_rate_write_bps = dVar55;
                        }
                      }
                    }
                  }
                  uVar31 = local_5f8->realtimeMs;
                }
                lp->io_last_scan_time_ms = uVar31;
              }
            }
LAB_00145140:
                    /* Unresolved local var: FILE * statmfile@[???]
                       Unresolved local var: wchar_t r@[???]
                       Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
            iVar25 = openat(parentFd_00,((char *)0x14a12d /* "statm" */),0);
            if (-1 < iVar25) {
              pFVar36 = fdopen(iVar25,((char *)0x147760 /* "r" */));
              if (pFVar36 == (FILE_2 *)0x0) {
                close(iVar25);
              }
              else {
                va3 = &lp->m_trs;
                iVar25 = __isoc23_fscanf(pFVar36,((char *)0x14a133 /* "%ld %ld %ld %ld %ld %ld %ld" */),&(lp->super).m_virt,
                                         &(lp->super).m_resident,&lp->m_share,va3,&dummy,&lp->m_drs,
                                         (tm_2 *)&endptr);
                fclose(pFVar36);
                if (iVar25 == 7) {
                  lVar37 = (long)lhost->pageSizeKB;
                    /* Unresolved local var: _Bool prev@[???] */
                  _Var6 = (lp->super).usesDeletedLib;
                  (lp->super).m_virt = (lp->super).m_virt * lVar37;
                  lVar48 = (lp->super).m_resident * lVar37;
                  lVar33 = lp->m_share;
                  (lp->super).m_resident = lVar48;
                  _Var7 = (lp->super).isKernelThread;
                  lp->m_priv = lVar48 - lVar37 * lVar33;
                  uVar26 = pSVar12->flags;
                  _Var22 = (lp->super).isUserlandThread;
                  if (_Var7 == false) {
                    if (_Var22 != false) {
LAB_00145ae0:
                      if (parent == (Process_2 *)0x0) goto LAB_00145ac4;
                      cVar20 = parent->usesDeletedLib;
                      lVar33._0_1_ = parent[1].elevated_priv;
                      lVar33._1_1_ = parent[1].field_0x71;
                      lVar33._2_1_ = parent[1].field_0x72;
                      lVar33._3_1_ = parent[1].field_0x73;
                      lVar33._4_1_ = parent[1].field_0x74;
                      lVar33._5_1_ = parent[1].field_0x75;
                      lVar33._6_1_ = parent[1].field_0x76;
                      lVar33._7_1_ = parent[1].field_0x77;
                      (lp->super).usesDeletedLib = (_Bool)cVar20;
                      goto LAB_00145ad0;
                    }
                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: uint64_t realtime@[???] */
                    if (((uVar26 & 0x10000) == 0) &&
                       ((((pSVar11->highlightDeletedExe == false ||
                          ((lp->super).procExeDeleted != false)) ||
                         (uVar31 = (lp->super).starttime_ctime, (long)uVar31 < 1)) ||
                        ((uVar38 = ((lp->super).super.host)->realtimeMs / 1000, uVar38 < uVar31 ||
                         (uVar38 - uVar31 < 0xb)))))) goto LAB_00145ac4;
                    /* Unresolved local var: uint64_t passedTimeInMs@[???]
                       Unresolved local var: uint64_t recheck@[???] */
                    uVar15 = (lhost->super).realtimeMs;
                    uVar16 = lp->last_mlrs_calctime;
                    uVar26 = rand();
                    if ((ulong)(uVar26 & 0x7ff) < uVar15 - uVar16) {
                    /* Unresolved local var: Process * proc@[???]
                       Unresolved local var: FILE * mapsfile@[???]
                       Unresolved local var: Hashtable * ht@[???]
                       Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
                      lp->last_mlrs_calctime = (lhost->super).realtimeMs;
                      _Var7 = pSVar11->highlightDeletedExe;
                      uVar26 = pSVar12->flags;
                      (lp->super).usesDeletedLib = false;
                      local_620 = uVar26 & 0x10000;
                      iVar25 = openat(parentFd_00,((char *)0x14a0e6 /* "maps" */),0);
                      if (-1 < iVar25) {
                        pFVar36 = fdopen(iVar25,((char *)0x147760 /* "r" */));
                        if (pFVar36 == (FILE_2 *)0x0) {
                          close(iVar25);
                        }
                        else {
                          va3 = (long *)((ulong)uVar26 & 0x10000);
                          if (local_620 == 0) {
                            local_618 = (Hashtable *)0x0;
                          }
                          else {
                            local_618 = Hashtable_new(0x40,true);
                          }
                    /* Unresolved local var: uint64_t map_start@[???]
                       Unresolved local var: uint64_t map_end@[???]
                       Unresolved local var: _Bool map_execute@[???]
                       Unresolved local var: uint map_devmaj@[???]
                       Unresolved local var: uint map_devmin@[???]
                       Unresolved local var: uint64_t map_inode@[???]
                       Unresolved local var: char * readptr@[???]
                       Unresolved local var: uint64_t result@[???]
                       Unresolved local var: wchar_t nibble@[???]
                       Unresolved local var: wchar_t letter@[???]
                       Unresolved local var: long valid_mask@[???] */
LAB_0014644c:
                          do {
                            do {
                              do {
                                do {
                                  do {
                                    do {
                                      do {
                                        do {
                                          do {
                    /* Unresolved local var: size_t sz@[???] */
                                            pcVar35 = fgets(buffer,0x400,pFVar36);
                                            if (pcVar35 == (char *)0x0) {
                                              fclose(pFVar36);
                                              if (local_620 != 0) {
                    /* Unresolved local var: uint64_t total_size@[???]
                       Unresolved local var: size_t i@[???] */
                                                uVar31 = 0;
                                                if (local_618->size != 0) {
                    /* Unresolved local var: HashtableItem * walk@[???] */
                                                  ppvVar49 = &local_618->buckets->value;
                                                  uVar31 = 0;
                                                  do {
                                                    plVar45 = *ppvVar49;
                    /* Unresolved local var: LibraryData * v@[???]
                       Unresolved local var: uint64_t * d@[???] */
                                                    if ((plVar45 != (long *)0x0) &&
                                                       ((char)plVar45[1] != '\0')) {
                    /* Unresolved local var: LibraryData * v@[???]
                       Unresolved local var: uint64_t * d@[???] */
                                                      uVar31 = uVar31 + *plVar45;
                                                    }
                                                    ppvVar49 = ppvVar49 + 3;
                                                  } while (ppvVar49 !=
                                                           &local_618->buckets[local_618->size].
                                                            value);
                                                }
                                                Hashtable_clear(local_618);
                                                free(local_618->buckets);
                                                free(local_618);
                                                lp->m_lrs = uVar31 / (ulong)(long)lhost->pageSize;
                                              }
                                              goto LAB_00145310;
                                            }
                                            pcVar35 = strchr(buffer,0x2f);
                                          } while (pcVar35 == (char *)0x0);
                                          lVar33 = 0;
                                          pbVar43 = (byte *)buffer;
                                          do {
                                            pbVar53 = pbVar43;
                                            bVar52 = *pbVar53;
                                            if (((1 << (bVar52 & 0x1f) & 0x3ff007eU) == 0) ||
                                               (bVar52 < 0x30)) goto LAB_001464cd;
                                            uVar26 = bVar52 & 0xffffffdf;
                                            if (0x46 < uVar26) goto LAB_0014644c;
                                            lVar33 = lVar33 * 0x10 +
                                                     (ulong)(uVar26 - (-(uint)((bVar52 & 0x40) != 0)
                                                                      & 7) & 0xf);
                                            pbVar43 = pbVar53 + 1;
                                          } while (pbVar53 + 1 != (byte *)(buffer + 0x10));
                                          bVar52 = pbVar53[1];
                                          pbVar53 = (byte *)(buffer + 0x10);
LAB_001464cd:
                                        } while (bVar52 != 0x2d);
                                        va3 = (long *)0x0;
                                        pbVar43 = pbVar53 + 1;
                    /* Unresolved local var: uint64_t result@[???]
                       Unresolved local var: wchar_t nibble@[???]
                       Unresolved local var: wchar_t letter@[???]
                       Unresolved local var: long valid_mask@[???] */
                                        do {
                                          pbVar51 = pbVar43;
                                          bVar52 = *pbVar51;
                                          if (((1 << (bVar52 & 0x1f) & 0x3ff007eU) == 0) ||
                                             (bVar52 < 0x30)) goto LAB_0014653b;
                                          uVar26 = bVar52 & 0xffffffdf;
                                          if (0x46 < uVar26) goto LAB_0014644c;
                                          va3 = (long *)((long)va3 * 0x10 +
                                                        (ulong)(uVar26 - (-(uint)((bVar52 & 0x40) !=
                                                                                 0) & 7) & 0xf));
                                          pbVar43 = pbVar51 + 1;
                                        } while (pbVar51 + 1 != pbVar53 + 0x11);
                                        bVar52 = pbVar51[1];
                                        pbVar51 = pbVar53 + 0x11;
LAB_0014653b:
                                      } while ((((bVar52 != 0x20) || (pbVar51[1] == 0)) ||
                                               (pbVar51[2] == 0)) ||
                                              (((bVar52 = pbVar51[3], bVar52 == 0 ||
                                                (pbVar51[4] == 0)) || (pbVar51[5] != 0x20))));
                                      pbVar43 = pbVar51 + 6;
                                      bVar8 = pbVar51[6];
                                      while (' ' < (char)bVar8) {
                                        pbVar53 = pbVar43 + 1;
                                        pbVar43 = pbVar43 + 1;
                                        bVar8 = *pbVar53;
                                      }
                                    } while (bVar8 != 0x20);
                                    pbVar53 = pbVar43 + 1;
                                    iVar25 = 0;
                    /* Unresolved local var: uint64_t result@[???]
                       Unresolved local var: wchar_t nibble@[???]
                       Unresolved local var: wchar_t letter@[???]
                       Unresolved local var: long valid_mask@[???] */
                                    do {
                                      bVar8 = *pbVar53;
                                      if ((((1 << (bVar8 & 0x1f) & 0x3ff007eU) == 0) ||
                                          (bVar8 < 0x30)) ||
                                         (uVar26 = bVar8 & 0xffffffdf, 0x46 < uVar26)) break;
                                      pbVar53 = pbVar53 + 1;
                                      iVar25 = iVar25 * 0x10 +
                                               (uVar26 - (-(uint)((bVar8 & 0x40) != 0) & 7) & 0xf);
                                    } while (pbVar53 != pbVar43 + 5);
                                  } while (*pbVar53 != 0x3a);
                                  pbVar43 = pbVar53 + 1;
                    /* Unresolved local var: uint64_t result@[???]
                       Unresolved local var: wchar_t nibble@[???]
                       Unresolved local var: wchar_t letter@[???]
                       Unresolved local var: long valid_mask@[???] */
                                  iVar29 = 0;
                                  do {
                                    bVar8 = *pbVar43;
                                    if ((((1 << (bVar8 & 0x1f) & 0x3ff007eU) == 0) || (bVar8 < 0x30)
                                        ) || (uVar26 = bVar8 & 0xffffffdf, 0x46 < uVar26)) break;
                                    pbVar43 = pbVar43 + 1;
                                    iVar29 = iVar29 * 0x10 +
                                             (uVar26 - (-(uint)((bVar8 & 0x40) != 0) & 7) & 0xf);
                                  } while (pbVar43 != pbVar53 + 5);
                                } while ((*pbVar43 != 0x20) || (iVar29 == 0 && iVar25 == 0));
                                pbVar53 = pbVar43 + 1;
                                lVar37 = 0;
                                do {
                                  bVar8 = *pbVar53;
                                  if (9 < (byte)(bVar8 - 0x30)) break;
                    /* Unresolved local var: uint64_t result@[???] */
                                  pbVar53 = pbVar53 + 1;
                                  lVar37 = lVar37 * 10 + (long)((char)bVar8 + -0x30);
                                } while (pbVar53 != pbVar43 + 0x15);
                              } while (lVar37 == 0);
                              if (local_620 != 0) {
                    /* Unresolved local var: LibraryData * libdata@[???] */
                                plVar45 = Hashtable_get(local_618,(ht_key_t)lVar37);
                                if (plVar45 == (long *)0x0) {
                                  plVar45 = xCalloc(1,0x10);
                                  Hashtable_put(local_618,(ht_key_t)lVar37,plVar45);
                                }
                                va3 = (long *)((long)va3 - lVar33);
                                *(byte *)(plVar45 + 1) = *(byte *)(plVar45 + 1) | bVar52 == 0x78;
                                *plVar45 = *plVar45 + (long)va3;
                              }
                            } while (((_Var7 == false) || (bVar52 != 0x78)) ||
                                    ((lp->super).usesDeletedLib != false));
                            for (; *pbVar53 == 0x20; pbVar53 = pbVar53 + 1) {
                            }
                          } while ((((*pbVar53 != 0x2f) ||
                                    (_Var22 = String_startsWith((char *)pbVar53,((char *)0x14a14f /* "/memfd:" */)), _Var22))
                                   || (iVar25 = strcmp((char *)pbVar53,((char *)0x14a157 /* "/dev/zero (deleted)\n" */)),
                                      iVar25 == 0)) ||
                                  ((pcVar35 = strstr((char *)pbVar53,((char *)0x14a160 /* " (deleted)\n" */)),
                                   pcVar35 == (char *)0x0 ||
                                   ((lp->super).usesDeletedLib = true, local_620 != 0))));
                          fclose(pFVar36);
                        }
                      }
                    }
LAB_00145310:
                    cVar20 = (lp->super).usesDeletedLib;
                    uVar26 = pSVar12->flags;
                  }
                  else {
                    if (_Var22 != false) goto LAB_00145ae0;
LAB_00145ac4:
                    (lp->super).usesDeletedLib = false;
                    cVar20 = '\0';
                    lVar33 = 0;
LAB_00145ad0:
                    lp->m_lrs = lVar33;
                  }
                  if (_Var6 != (_Bool)cVar20) {
                    (lp->super).mergedCommand.lastUpdate = 0;
                  }
                  if (((uVar26 & 0x2000) != 0) && ((lp->super).isKernelThread == false)) {
                    if (parent == (Process_2 *)0x0) {
                      if ((wVar28 & 1U) == smaps_flag_0) {
                    /* Unresolved local var: FILE * f@[???] */
                        pcVar35 = ((char *)0x14a0e5 /* "smaps" */);
                    /* Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
                        if (this->haveSmapsRollup != false) {
                          pcVar35 = ((char *)0x14a071 /* "smaps_rollup" */);
                        }
                        iVar25 = openat(parentFd_00,pcVar35,0);
                        if (-1 < iVar25) {
                          pFVar36 = fdopen(iVar25,((char *)0x147760 /* "r" */));
                          if (pFVar36 == (FILE_2 *)0x0) {
                            close(iVar25);
                          }
                          else {
                            lp->m_psswp = 0;
                            lp->m_pss = 0;
                            lp->m_swap = 0;
LAB_00146a1b:
                    /* Unresolved local var: size_t sz@[???] */
                            pcVar35 = fgets(buffer,0x100,pFVar36);
                            if (pcVar35 != (char *)0x0) {
                              pcVar35 = strchr(buffer,10);
                              if (pcVar35 == (char *)0x0) {
                                do {
                    /* Unresolved local var: size_t sz@[???] */
                                  pcVar35 = fgets(buffer,0x100,pFVar36);
                                  if (pcVar35 == (char *)0x0) break;
                                  pcVar35 = strchr(buffer,10);
                                } while (pcVar35 == (char *)0x0);
                              }
                              else if (buffer._0_4_ == 0x3a737350) {
                                lVar33 = __isoc23_strtol(buffer + 4,(char **)0x0,10);
                                lp->m_pss = lp->m_pss + lVar33;
                              }
                              else if ((buffer._0_4_ == 0x70617753) && (buffer[4] == ':')) {
                                lVar33 = __isoc23_strtol(buffer + 5,(char **)0x0,10);
                                lp->m_swap = lp->m_swap + lVar33;
                              }
                              else if (CONCAT44(buffer._4_4_,buffer._0_4_) == 0x3a73735070617753) {
                                lVar33 = __isoc23_strtol(buffer + 8,(char **)0x0,10);
                                lp->m_psswp = lp->m_psswp + lVar33;
                              }
                              goto LAB_00146a1b;
                            }
                            fclose(pFVar36);
                          }
                        }
                      }
                      if (wVar28 == L'\x01') {
                        smaps_flag_0 = (uint)(smaps_flag_0 == 0);
                      }
                    }
                    else {
                      lp->m_pss = *(long *)&parent[1].tpgid;
                    }
                  }
                  uVar16 = lp->utime;
                  uVar31 = (lp->super).tty_nr;
                  uVar17 = lp->stime;
                  _Var21 = LinuxProcessTable_readStatFile
                                     (lp,parentFd_00,lhost,_Var21,statCommand,(size_t)va3);
                  if (_Var21) {
                    if ((lp->flags & 0x200000) != 0) {
                      (lp->super).isKernelThread = true;
                    }
                    if ((uVar31 != (lp->super).tty_nr) && (this->ttyDrivers != (TtyDriver *)0x0)) {
                      free((lp->super).tty_name);
                      uVar31 = (lp->super).tty_nr;
                      pTVar50 = this->ttyDrivers;
                    /* Unresolved local var: uint maj@[???]
                       Unresolved local var: uint min@[???]
                       Unresolved local var: wchar_t i@[???]
                       Unresolved local var: uint __major@[???] */
                    /* Unresolved local var: uint __minor@[???] */
                      uVar26 = (uint)(uVar31 >> 0x20) & 0xfffff000 | (uint)(uVar31 >> 8) & 0xfff;
                      va1 = (uint)((uVar31 >> 0x14) << 8) | (uint)uVar31 & 0xff;
                    /* Unresolved local var: uint idx@[???]
                       Unresolved local var: wchar_t err@[???] */
                      if (pTVar50->path != (char *)0x0) {
                    /* Unresolved local var: wchar_t err@[???] */
                        do {
                          if (uVar26 < pTVar50->major) break;
                          if (uVar26 <= pTVar50->major) {
                            if (va1 < pTVar50->minorFrom) break;
                            if (va1 <= pTVar50->minorTo) {
                              va1_00 = va1 - pTVar50->minorFrom;
                              do {
                                xAsprintf(&endptr,((char *)0x14a17b /* "%s/%d" */),pTVar50->path,va1_00);
                                iVar25 = stat(endptr,(stat_2 *)path);
                                uVar46 = (uint)(local_4b0 >> 8);
                                uVar27 = (uint)(local_4b0 >> 0x20);
                    /* Unresolved local var: uint __major@[???] */
                    /* Unresolved local var: uint __minor@[???] */
                                if (((iVar25 == 0) &&
                                    (uVar26 == (uVar27 & 0xfffff000 | uVar46 & 0xfff))) &&
                                   (pcVar35 = endptr,
                                   va1 == ((uint)((local_4b0 >> 0x14) << 8) | (uint)local_4b0 & 0xff
                                          ))) goto LAB_001455a5;
                                free(endptr);
                                xAsprintf(&endptr,((char *)0x148c18 /* "%s%d" */),pTVar50->path,va1_00);
                                iVar25 = stat(endptr,(stat_2 *)path);
                    /* Unresolved local var: uint __major@[???] */
                    /* Unresolved local var: uint __minor@[???] */
                                if (((iVar25 == 0) &&
                                    (uVar26 == (uVar27 & 0xfffff000 | uVar46 & 0xfff))) &&
                                   (pcVar35 = endptr,
                                   va1 == ((uint)((local_4b0 >> 0x14) << 8) | (uint)local_4b0 & 0xff
                                          ))) goto LAB_001455a5;
                                free(endptr);
                                bVar54 = va1 != va1_00;
                                va1_00 = va1;
                              } while (bVar54);
                              iVar25 = stat(pTVar50->path,(stat_2 *)path);
                              if ((iVar25 == 0) && (uVar31 == local_4b0)) {
                    /* Unresolved local var: char * data@[???] */
                                pcVar35 = strdup(pTVar50->path);
                                if (pcVar35 != (char *)0x0) goto LAB_001455a5;
                                goto LAB_00145b91;
                              }
                            }
                          }
                          pTVar50 = pTVar50 + 1;
                        } while (pTVar50->path != (char *)0x0);
                      }
                      xAsprintf(&endptr,((char *)0x14a181 /* "/dev/%u:%u" */),uVar26,va1);
                      pcVar35 = endptr;
LAB_001455a5:
                      (lp->super).tty_name = pcVar35;
                    }
                    if ((pSVar12->flags & 0x100) != 0) {
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
                      lVar33 = syscall(0xfc,1,(ulong)(uint)(lp->super).super.id);
                      lp->ioPriority = (IOPriority)lVar33;
                    }
                    dVar55 = lhost->period;
                    dVar56 = 0.0;
                    (lp->super).percent_cpu = NAN;
                    if (dVar55 <= 0.0) {
                      percentage = NAN;
                    }
                    else {
                    /* Unresolved local var: float percent_cpu@[???] */
                      uVar38 = lp->stime + lp->utime;
                      uVar31 = uVar16 + uVar17;
                      if (uVar31 < uVar38) {
                        uVar38 = uVar38 - uVar31;
                        if ((long)uVar38 < 0) {
                          dVar56 = (double)uVar38;
                        }
                        else {
                          dVar56 = (double)(long)uVar38;
                        }
                      }
                      fVar57 = (float)(lhost->super).activeCPUs * 100.0;
                      percentage = (float)((dVar56 / dVar55) * 100.0);
                      if (fVar57 <= percentage) {
                        percentage = fVar57;
                      }
                      (lp->super).percent_cpu = percentage;
                    }
                    (lp->super).percent_mem =
                         (float)(((double)(lp->super).m_resident / (double)(lhost->super).totalMem)
                                * 100.0);
                    Process_updateCPUFieldWidths(percentage);
                    /* Unresolved local var: wchar_t statok@[???] */
                    iVar25 = fstat(parentFd_00,(stat_2 *)buffer);
                    if (iVar25 != -1) {
                      if ((lp->super).st_uid != buffer._28_4_) {
                        (lp->super).st_uid = buffer._28_4_;
                        pcVar35 = UsersTable_getRef((lhost->super).usersTable,buffer._28_4_);
                        (lp->super).user = pcVar35;
                      }
                      _Var21 = LinuxProcessTable_readStatusFile(lp,parentFd_00);
                      if (_Var21) {
                        if (local_608 == (LinuxProcess *)0x0) {
                          if ((pSVar12->flags & 0x200) != 0) {
                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: _Bool foundEnvID@[???]
                       Unresolved local var: _Bool foundVPid@[???] */
                            iVar25 = access(((char *)0x14a18c /* "/proc/vz" */),4);
                    /* Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
                            if ((iVar25 == 0) &&
                               (iVar25 = openat(parentFd_00,((char *)0x149730 /* "status" */),0), -1 < iVar25)) {
                              pFVar36 = fdopen(iVar25,((char *)0x147760 /* "r" */));
                              if (pFVar36 != (FILE_2 *)0x0) {
                                bVar19 = false;
                    /* Unresolved local var: char * name_value_sep@[???]
                       Unresolved local var: wchar_t field@[DW_OP_reg1(RDX)]
                       Unresolved local var: char * value_end@[???] */
                                bVar54 = false;
LAB_0014622f:
                    /* Unresolved local var: size_t sz@[???] */
                                pcVar35 = fgets(buffer,0x100,pFVar36);
                                if (pcVar35 != (char *)0x0) {
                                  pcVar35 = strchr(buffer,10);
                                  if (pcVar35 == (char *)0x0) {
                                    do {
                    /* Unresolved local var: size_t sz@[???] */
                                      pcVar35 = fgets(buffer,0x100,pFVar36);
                                      if (pcVar35 == (char *)0x0) break;
                                      pcVar35 = strchr(buffer,10);
                                    } while (pcVar35 == (char *)0x0);
                                  }
                                  else {
                                    pcVar35 = strchr(buffer,0x3a);
                                    if (pcVar35 != (char *)0x0) {
                                      sVar40 = (long)pcVar35 - (long)buffer;
                                      iVar25 = strncasecmp(buffer,((char *)0x14a195 /* "envID" */),sVar40);
                                      if (iVar25 == 0) {
                                        iVar25 = 1;
                                      }
                                      else {
                                        iVar29 = strncasecmp(buffer,((char *)0x14a19b /* "VPid" */),sVar40);
                                        iVar25 = 2;
                                        if (iVar29 != 0) goto LAB_0014622f;
                                      }
                                      do {
                                        pcVar2 = pcVar35 + 1;
                                        pcVar35 = pcVar35 + 1;
                                        if (*pcVar2 == '\0') goto LAB_0014622f;
                                        pcVar42 = pcVar35;
                                      } while (*pcVar2 < '!');
                                      do {
                                        pcVar42 = pcVar42 + 1;
                                      } while (' ' < *pcVar42);
                                      if (pcVar35 != pcVar42) {
                                        *pcVar42 = '\0';
                                        if (iVar25 == 2) {
                                          uVar31 = __isoc23_strtoul(pcVar35,(char **)0x0,0);
                                          lp->vpid = (pid_t)uVar31;
                                          bVar19 = true;
                                          goto LAB_0014622f;
                                        }
                                        pcVar2 = lp->ctid;
                                        bVar54 = true;
                                        if (pcVar2 == (char *)0x0) {
                                          if (*pcVar35 == '\0') goto LAB_0014622f;
                                        }
                                        else {
                                          iVar25 = strcmp(pcVar35,pcVar2);
                                          if ((iVar25 == 0) ||
                                             (iVar25 = strcmp(pcVar2,pcVar35), iVar25 == 0))
                                          goto LAB_0014622f;
                                        }
                                        free(pcVar2);
                    /* Unresolved local var: char * data@[???] */
                                        pcVar35 = strdup(pcVar35);
                                        if (pcVar35 == (char *)0x0) goto LAB_00145b91;
                                        lp->ctid = pcVar35;
                                      }
                                    }
                                  }
                                  goto LAB_0014622f;
                                }
                                fclose(pFVar36);
                                if (!bVar54) {
                                  free(lp->ctid);
                                  lp->ctid = (char *)0x0;
                                }
                                if (!bVar19) {
                                  lp->vpid = (lp->super).super.id;
                                }
                                goto LAB_00145706;
                              }
                              close(iVar25);
                            }
                            free(lp->ctid);
                            wVar28 = (lp->super).super.id;
                            lp->ctid = (char *)0x0;
                            lp->vpid = wVar28;
                          }
LAB_00145706:
                          if ((lp->super).isKernelThread == false) {
                            _Var21 = LinuxProcessTable_readCmdlineFile((Process_2 *)lp,parentFd_00);
                            if (!_Var21) {
                              sVar40 = strlen(statCommand);
                              Process_updateCmdline((Process *)lp,statCommand,L'\0',(wchar_t)sVar40)
                              ;
                            }
                          }
                          else {
                            Process_updateCmdline((Process *)lp,(char *)0x0,L'\0',L'\0');
                          }
                    /* Unresolved local var: time_t now@[???] */
                          lVar33 = (((lp->super).super.host)->realtime).tv_sec;
                          localtime_r(&(lp->super).starttime_ctime,(tm_2 *)&endptr);
                          lVar37 = (lp->super).starttime_ctime;
                          pcVar35 = ((char *)0x14876e /* "%R " */);
                          if ((lVar37 < lVar33 + -0x1517f) &&
                             (pcVar35 = ((char *)0x148778 /* " %Y " */), lVar33 + -0x1dfe1ff <= lVar37)) {
                            pcVar35 = ((char *)0x148772 /* "%b%d " */);
                          }
                          strftime((lp->super).starttime_show,7,pcVar35,(tm_2 *)&endptr);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
                          this_00 = (this->super).super.rows;
                          wVar28 = this_00->items;
                          (lp->super).super.seenStampMs = ((this->super).super.host)->monotonicMs;
                          Vector_set(this_00,wVar28,lp);
                          Hashtable_put((this->super).super.table,(lp->super).super.id,lp);
                        }
                        else if ((pSVar11->updateProcessNames != false) &&
                                ((lp->super).state != ZOMBIE)) {
                          if ((lp->super).isKernelThread == false) {
                            _Var21 = LinuxProcessTable_readCmdlineFile((Process_2 *)lp,parentFd_00);
                            if (!_Var21) {
                              sVar40 = strlen(statCommand);
                              Process_updateCmdline((Process *)lp,statCommand,L'\0',(wchar_t)sVar40)
                              ;
                            }
                          }
                          else {
                            Process_updateCmdline((Process *)lp,(char *)0x0,L'\0',L'\0');
                          }
                        }
                        uVar26 = pSVar12->flags;
                        if ((uVar26 & 0x800) != 0) {
                          LinuxProcessTable_readCGroupFile(lp,parentFd_00);
                          uVar26 = pSVar12->flags;
                        }
                        if ((uVar26 & 0x40000) != 0) {
                    /* Unresolved local var: nl_msg * msg@[???] */
                          pnVar41 = this->netlink_socket;
                          if (pnVar41 == (nl_sock *)0x0) {
                            pnVar41 = nl_socket_alloc();
                            this->netlink_socket = pnVar41;
                            if (pnVar41 != (nl_sock *)0x0) {
                              iVar25 = nl_connect(pnVar41,0x10);
                              if (-1 < iVar25) {
                                wVar28 = genl_ctrl_resolve(this->netlink_socket,((char *)0x14a1a0 /* "TASKSTATS" */));
                                this->netlink_family = wVar28;
                              }
                              pnVar41 = this->netlink_socket;
                              if (pnVar41 != (nl_sock *)0x0) goto LAB_00145ecc;
                            }
LAB_00146074:
                            lp->swapin_delay_percent = NAN;
                            lp->cpu_delay_percent = NAN;
                            lp->blkio_delay_percent = NAN;
                          }
                          else {
LAB_00145ecc:
                            iVar25 = nl_socket_modify_cb(pnVar41,0,3,handleNetlinkMsg,lp);
                            if ((iVar25 < 0) || (p0 = nlmsg_alloc(), p0 == (void *)0x0))
                            goto LAB_00146074;
                            pvVar39 = genlmsg_put(p0,0,0,this->netlink_family,0,1,'\x01','\x0e');
                            if (pvVar39 == (void *)0x0) {
                              nlmsg_free(p0);
                            }
                            iVar25 = nla_put_u32(p0,1,(lp->super).super.id);
                            if (iVar25 < 0) {
                              nlmsg_free(p0);
                            }
                            iVar25 = nl_send_sync(this->netlink_socket,p0);
                            if ((iVar25 < 0) ||
                               (iVar25 = nl_recvmsgs_default(this->netlink_socket), iVar25 < 0))
                            goto LAB_00146074;
                          }
                          uVar26 = pSVar12->flags;
                        }
                        if ((uVar26 & 0x1000) != 0) {
                          LinuxProcessTable_readOomData(lp,parentFd_00);
                          uVar26 = pSVar12->flags;
                        }
                        if ((uVar26 & 0x8000) != 0) {
                          LinuxProcessTable_readSecattrData(lp,parentFd_00);
                          uVar26 = pSVar12->flags;
                        }
                        if ((uVar26 & 2) != 0) {
                          LinuxProcessTable_readCwd(lp,parentFd_00);
                          uVar26 = pSVar12->flags;
                        }
                        if (((uVar26 & 0x80000) != 0) && (this->haveAutogroup != false)) {
                    /* Unresolved local var: ssize_t amtRead@[???]
                       Unresolved local var: wchar_t ok@[???] */
                          lp->autogroup_id = -1;
                    /* Unresolved local var: wchar_t fd@[???] */
                          wVar28 = openat(parentFd_00,((char *)0x149b96 /* "autogroup" */),0);
                          if (wVar28 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
                            piVar44 = __errno_location();
                            lVar33 = (long)-*piVar44;
                          }
                          else {
                            lVar33 = readfd_internal(wVar28,(stat_2 *)buffer,0x40);
                          }
                          if ((-1 < lVar33) &&
                             (iVar25 = __isoc23_sscanf(buffer,((char *)0x149ba3 /* "/autogroup-%ld nice %d" */),
                                                       (tm_2 *)&endptr,&dummy), iVar25 == 2)) {
                            lp->autogroup_id = (long)endptr;
                            lp->autogroup_nice = (wchar_t)dummy;
                          }
                          uVar26 = pSVar12->flags;
                        }
                        if ((uVar26 & 4) != 0) {
                          wVar28 = sched_getscheduler((lp->super).super.id);
                          (lp->super).scheduling_policy = wVar28;
                        }
                        if ((((lp->super).cmdline == (char *)0x0) && (statCommand[0] != '\0')) &&
                           (((lp->super).state == ZOMBIE ||
                            (((lp->super).isKernelThread != false ||
                             (pSVar11->showThreadNames != false)))))) {
                          sVar40 = strlen(statCommand);
                          Process_updateCmdline((Process *)lp,statCommand,L'\0',(wchar_t)sVar40);
                        }
                        (lp->super).super.updated = true;
                        close(parentFd_00);
                        if ((_Var5 == false) || ((lp->super).isRunningInContainer == false)) {
                          if ((lp->super).isKernelThread == false) {
                            if ((lp->super).isUserlandThread != false) {
                              puVar1 = &(this->super).userlandThreads;
                              *puVar1 = *puVar1 + 1;
                            }
LAB_00145d92:
                            bVar52 = true;
                            if (_Var4 != false) {
                              bVar52 = (lp->super).isUserlandThread ^ 1;
                            }
                          }
                          else {
                            puVar1 = &(this->super).kernelThreads;
                            *puVar1 = *puVar1 + 1;
                            if (_Var3 == false) goto LAB_00145d92;
                            bVar52 = false;
                          }
                          (lp->super).super.show = (_Bool)bVar52;
                          puVar1 = &(this->super).totalTasks;
                          *puVar1 = *puVar1 + 1;
                        }
                        else {
                          (lp->super).super.show = false;
                        }
                        goto LAB_00144cd6;
                      }
                    }
                  }
                }
              }
            }
            close(parentFd_00);
            if (local_608 == (LinuxProcess *)0x0) {
              Process_delete(lp);
            }
          }
        }
        goto LAB_00144cd6;
      }
      if (lVar10 == *(long *)(in_FS_OFFSET + 0x28)) {
        iVar23 = closedir(__dirp);
        return SUB41(iVar23,0);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

