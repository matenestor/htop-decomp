#include "htop.h"

/* sortTtyDrivers @ 0x138920 */

int sortTtyDrivers(void *va,void *vb)

{
  int wVar1;

  wVar1 = (uint)(*(uint *)((long)vb + 8) < *(uint *)((long)va + 8)) -
          (uint)(*(uint *)((long)va + 8) < *(uint *)((long)vb + 8));
  if (wVar1 == 0) {
                    /* Unresolved local var: TtyDriver * a@[???]
                       Unresolved local var: TtyDriver * b@[???]
                       Unresolved local var: int r@[???] */
    wVar1 = (uint)(*(uint *)((long)vb + 0xc) < *(uint *)((long)va + 0xc)) -
            (uint)(*(uint *)((long)va + 0xc) < *(uint *)((long)vb + 0xc));
  }
  return wVar1;
}


/* LinuxProcessTable_readStatusFile @ 0x138ca0 */

_Bool LinuxProcessTable_readStatusFile(LinuxProcess_ *process,openat_arg_t procFd)

{
  undefined1 __frame[0x10f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x10b8;
  byte *pbVar1;
  long lVar2;
  ushort *puVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  FILE_2 *__stream;
  char *pcVar7;
  ushort **ppuVar8;
  ulong uVar9;
  ulong uVar10;
  byte *pbVar11;
  long lVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  _Bool _Var13;

                    /* Unresolved local var: LinuxProcess * lp@[???]
                       Unresolved local var: ulong ctxt@[???]
                       Unresolved local var: FILE * statusfile@[???] */
                    /* Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  process->vxid = 0;
  iVar5 = openat(procFd,((char *)(long)&s_status_00149730 /* "status" */),0);
  if (-1 < iVar5) {
    __stream = fdopen(iVar5,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream != (FILE_2 *)0x0) {
      (*(ulong (*))(__fp - 0x1068)) = 0;
LAB_00138d30:
                    /* Unresolved local var: size_t sz@[???] */
      pcVar7 = fgets((*(char (*) [4097])(__fp - 0x1048)),0x1001,__stream);
      bVar4 = (*(char (*) [4097])(__fp - 0x1048))[0];
      if (pcVar7 != (char *)0x0) {
        if ((CONCAT13((*(char (*) [4097])(__fp - 0x1048))[3],CONCAT21((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 1)),(*(char (*) [4097])(__fp - 0x1048))[0])) == 0x6970534e) &&
           (CONCAT11((*(char (*) [4097])(__fp - 0x1048))[5],(*(char (*) [4097])(__fp - 0x1048))[4]) == 0x3a64)) {
          if (((*(char (*) [4097])(__fp - 0x1048))[0] != '\0') && ((*(char (*) [4097])(__fp - 0x1048))[0] != '\n')) {
            ppuVar8 = __ctype_b_loc();
            iVar5 = 0;
            puVar3 = *ppuVar8;
            pbVar11 = (byte *)(*(char (*) [4097])(__fp - 0x1048));
                    /* Unresolved local var: char * ptr@[???]
                       Unresolved local var: int pid_ns_count@[???] */
            while ((*(byte *)((long)puVar3 + (ulong)bVar4 * 2 + 1) & 8) == 0) {
              bVar4 = pbVar11[1];
              pbVar11 = pbVar11 + 1;
              if ((bVar4 == 0) || (bVar4 == 10)) goto LAB_00138d30;
            }
            bVar4 = *pbVar11;
            if ((bVar4 != 0) && (bVar4 != 10)) goto LAB_00138e80;
          }
        }
        else if ((CONCAT13((*(char (*) [4097])(__fp - 0x1048))[3],CONCAT21((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 1)),(*(char (*) [4097])(__fp - 0x1048))[0])) == 0x50706143) &&
                (CONCAT13((*(char (*) [4097])(__fp - 0x1048))[6],CONCAT12((*(char (*) [4097])(__fp - 0x1048))[5],CONCAT11((*(char (*) [4097])(__fp - 0x1048))[4],(*(char (*) [4097])(__fp - 0x1048))[3]))) == 0x3a6d7250
                )) {
                    /* Unresolved local var: char * ptr@[???]
                       Unresolved local var: uint64_t cap_permitted@[???] */
          if (((*(char (*) [4097])(__fp - 0x1048))[7] == ' ') || ((*(char (*) [4097])(__fp - 0x1048))[7] == '\t')) {
            pbVar11 = (byte *)((*(char (*) [4097])(__fp - 0x1048)) + 7);
            do {
              do {
                pbVar1 = pbVar11 + 1;
                pbVar11 = pbVar11 + 1;
              } while (*pbVar1 == 0x20);
            } while (*pbVar1 == 9);
          }
          else {
            pbVar11 = (byte *)((*(char (*) [4097])(__fp - 0x1048)) + 7);
          }
                    /* Unresolved local var: uint64_t result@[???]
                       Unresolved local var: int nibble@[???]
                       Unresolved local var: int letter@[???]
                       Unresolved local var: long valid_mask@[???] */
          pbVar1 = pbVar11 + 0x10;
          lVar12 = 0;
          do {
            bVar4 = *pbVar11;
            if ((((1 << (bVar4 & 0x1f) & 0x3ff007eU) == 0) || (bVar4 < 0x30)) ||
               (uVar6 = bVar4 & 0xffffffdf, 0x46 < uVar6)) break;
            pbVar11 = pbVar11 + 1;
            lVar12 = lVar12 * 0x10 + (ulong)(uVar6 - (-(uint)((bVar4 & 0x40) != 0) & 7) & 0xf);
          } while (pbVar11 != pbVar1);
          _Var13 = false;
          if (lVar12 != 0) {
            _Var13 = (process->super).st_uid != 0;
          }
          (process->super).elevated_priv = _Var13;
        }
        else {
                    /* Unresolved local var: int ok@[???] */
          if ((CONCAT17((*(char (*) [4097])(__fp - 0x1048))[7],
                        CONCAT16((*(char (*) [4097])(__fp - 0x1048))[6],
                                 CONCAT15((*(char (*) [4097])(__fp - 0x1048))[5],
                                          CONCAT14((*(char (*) [4097])(__fp - 0x1048))[4],
                                                   CONCAT13((*(char (*) [4097])(__fp - 0x1048))[3],
                                                            CONCAT21((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 1)),(*(char (*) [4097])(__fp - 0x1048))[0])))))) ==
               0x7261746e756c6f76 && CONCAT53((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 11)),(*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 8))) == 0x735f747874635f79) &&
             (CONCAT53((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 19)),(*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 16))) == 0x3a73656863746977)) {
                    /* Unresolved local var: int ok@[???] */
            iVar5 = __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1048)),((char *)(long)&s_voluntary_ctxt_switches___lu_00149746 /* "voluntary_ctxt_switches:\t%lu" */),&(*(int (*))(__fp - 0x1050)));
joined_r0x0013909e:
            if (0 < iVar5) {
              (*(ulong (*))(__fp - 0x1068)) = (*(ulong (*))(__fp - 0x1068)) + CONCAT44((*(undefined4 (*))(__fp - 0x104c)),(*(int (*))(__fp - 0x1050)));
            }
          }
          else {
            if ((CONCAT17((*(char (*) [4097])(__fp - 0x1048))[7],
                          CONCAT16((*(char (*) [4097])(__fp - 0x1048))[6],
                                   CONCAT15((*(char (*) [4097])(__fp - 0x1048))[5],
                                            CONCAT14((*(char (*) [4097])(__fp - 0x1048))[4],
                                                     CONCAT13((*(char (*) [4097])(__fp - 0x1048))[3],
                                                              CONCAT21((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 1)),(*(char (*) [4097])(__fp - 0x1048))[0]))))))
                 == 0x6e756c6f766e6f6e && CONCAT53((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 11)),(*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 8))) == 0x7874635f79726174
                ) && (CONCAT35((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 16)),(*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 11))) == 0x735f747874635f79 &&
                      CONCAT35((*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 24)),(*(ulong *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 19))) == 0x3a73656863746977)) {
              iVar5 = __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1048)),((char *)(long)&s_nonvoluntary_ctxt_switches___lu_0014ca10 /* "nonvoluntary_ctxt_switches:\t%lu" */),&(*(int (*))(__fp - 0x1050)));
              goto joined_r0x0013909e;
            }
                    /* Unresolved local var: int ok@[???] */
            if (((CONCAT13((*(char (*) [4097])(__fp - 0x1048))[3],CONCAT21((*(ushort *)((char *)&(*(char (*) [4097])(__fp - 0x1048)) + 1)),(*(char (*) [4097])(__fp - 0x1048))[0])) == 0x44497856) &&
                ((*(char (*) [4097])(__fp - 0x1048))[4] == ':')) &&
               (iVar5 = __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1048)),((char *)(long)&DAT_00149785 /* "VxID:\t%32d" */),&(*(int (*))(__fp - 0x1050))), 0 < iVar5)) {
              process->vxid = (*(int (*))(__fp - 0x1050));
            }
          }
        }
        goto LAB_00138d30;
      }
      fclose(__stream);
      uVar9 = process->ctxt_total;
      process->ctxt_total = (*(ulong (*))(__fp - 0x1068));
      uVar10 = (*(ulong (*))(__fp - 0x1068)) - uVar9;
      if ((*(ulong (*))(__fp - 0x1068)) <= uVar9) {
        uVar10 = 0;
      }
      process->ctxt_diff = uVar10;
      _Var13 = true;
      goto LAB_0013903e;
    }
    close(iVar5);
  }
  _Var13 = false;
LAB_0013903e:
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var13;
  while( true ) {
    while ((*(byte *)((long)puVar3 + uVar9 * 2 + 1) & 8) == 0) {
      bVar4 = pbVar11[1];
      uVar9 = (ulong)bVar4;
      pbVar11 = pbVar11 + 1;
      if (bVar4 == 0) goto LAB_00138ec0;
joined_r0x00138ebd:
      if (bVar4 == 10) goto LAB_00138ec0;
    }
    bVar4 = *pbVar11;
    if ((bVar4 == 0) || (bVar4 == 10)) break;
LAB_00138e80:
    uVar9 = (ulong)bVar4;
    iVar5 = (iVar5 + 1) - (uint)((puVar3[(char)bVar4] & 0x800) == 0);
    if ((*(byte *)((long)puVar3 + uVar9 * 2 + 1) & 8) != 0) goto LAB_00138ea8;
  }
LAB_00138ec0:
  if (1 < iVar5) {
    (process->super).isRunningInContainer = true;
  }
  goto LAB_00138d30;
LAB_00138ea8:
  do {
    bVar4 = pbVar11[1];
    uVar9 = (ulong)bVar4;
    pbVar11 = pbVar11 + 1;
  } while ((*(byte *)((long)puVar3 + uVar9 * 2 + 1) & 8) != 0);
  if (bVar4 != 0) goto joined_r0x00138ebd;
  goto LAB_00138ec0;
}


/* LinuxProcessTable_readOomData @ 0x1390d0 */

void LinuxProcessTable_readOomData(LinuxProcess *process,openat_arg_t procFd)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  char *pcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: FILE * file@[???] */
                    /* Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = openat(procFd,((char *)(long)&s_oom_score_00149790 /* "oom_score" */),0);
  if (-1 < iVar2) {
    __stream = fdopen(iVar2,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream == (FILE_2 *)0x0) {
      if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
        close(iVar2);
        return;
      }
      goto LAB_00139192;
    }
                    /* Unresolved local var: size_t sz@[???] */
    pcVar3 = fgets((*(char (*) [4097])(__fp - 0x1038)),0x1000,__stream);
    if (pcVar3 != (char *)0x0) {
                    /* Unresolved local var: int ok@[???] */
      iVar2 = __isoc23_sscanf((*(char (*) [4097])(__fp - 0x1038)),((char *)(long)&DAT_001474a2 /* "%u" */),&(*(uint (*))(__fp - 0x103c)));
      if (0 < iVar2) {
        process->oom = (*(uint (*))(__fp - 0x103c));
      }
    }
    fclose(__stream);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00139192:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* handleNetlinkMsg @ 0x13a190 */

int handleNetlinkMsg(nl_msg *nlmsg,void *linuxProcess)

{
  undefined1 __frame[0x2a8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x268;
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  int wVar4;
  void *pvVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  taskstats *ptVar9;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar10;
  float fVar11;
  float fVar12;

  bVar10 = 0;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  pvVar5 = nlmsg_hdr(nlmsg);
  iVar3 = genlmsg_parse(pvVar5,0,(*(nlattr *(*) [7])(__fp - 0x218)),6,(void *)0x0);
  wVar4 = 1;
  if (iVar3 < 0) goto LAB_0013a28c;
  if (((*(nlattr *(*) [7])(__fp - 0x218))[4] != (nlattr *)0x0) || ((*(nlattr *(*) [7])(__fp - 0x218))[4] = (*(nlattr *(*) [7])(__fp - 0x218))[6], (*(nlattr *(*) [7])(__fp - 0x218))[6] != (nlattr *)0x0)) {
                    /* Unresolved local var: ulonglong timeDelta@[???] */
    pvVar5 = nla_data((*(nlattr *(*) [7])(__fp - 0x218))[4]);
    pvVar5 = nla_next(pvVar5,&(*(int (*))(__fp - 0x21c)));
    puVar6 = nla_data(pvVar5);
    ptVar9 = &(*(taskstats (*))(__fp - 0x1d8));
    for (lVar7 = 0x36; lVar7 != 0; lVar7 = lVar7 + -1) {
      uVar1 = *puVar6;
      ptVar9->version = (short)uVar1;
      ptVar9->field_0x2 = (char)((ulong)uVar1 >> 0x10);
      ptVar9->field_0x3 = (char)((ulong)uVar1 >> 0x18);
      ptVar9->ac_exitcode = (int)((ulong)uVar1 >> 0x20);
      puVar6 = puVar6 + (ulong)bVar10 * -2 + 1;
      ptVar9 = (taskstats *)((long)ptVar9 + (ulong)bVar10 * -0x10 + 8);
    }
    uVar8 = (*(taskstats (*))(__fp - 0x1d8)).ac_etime * 1000 - *(long *)((long)linuxProcess + 0x2e8);
    if (uVar8 == 0) {
      fVar12 = NAN;
      *(undefined8 *)((long)linuxProcess + 0x308) = 0x7fc000007fc00000;
    }
    else {
      if ((long)uVar8 < 0) {
        fVar12 = (float)uVar8;
        uVar8 = (*(taskstats (*))(__fp - 0x1d8)).cpu_delay_total - *(long *)((long)linuxProcess + 0x2f0);
        if ((long)uVar8 < 0) goto LAB_0013a399;
LAB_0013a2e6:
        fVar11 = (float)(long)uVar8;
      }
      else {
        fVar12 = (float)(long)uVar8;
        uVar8 = (*(taskstats (*))(__fp - 0x1d8)).cpu_delay_total - *(long *)((long)linuxProcess + 0x2f0);
        if (-1 < (long)uVar8) goto LAB_0013a2e6;
LAB_0013a399:
        fVar11 = (float)uVar8;
      }
      fVar11 = (fVar11 / fVar12) * 100.0;
      if (100.0 <= fVar11) {
        fVar11 = 100.0;
      }
      *(float *)((long)linuxProcess + 0x308) = fVar11;
      fVar11 = ((float)((*(taskstats (*))(__fp - 0x1d8)).blkio_delay_total - *(long *)((long)linuxProcess + 0x2f8)) / fVar12) *
               100.0;
      if (100.0 <= fVar11) {
        fVar11 = 100.0;
      }
      *(float *)((long)linuxProcess + 0x30c) = fVar11;
      fVar12 = ((float)((*(taskstats (*))(__fp - 0x1d8)).swapin_delay_total - *(long *)((long)linuxProcess + 0x300)) / fVar12)
               * 100.0;
      if (100.0 <= fVar12) {
        fVar12 = 100.0;
      }
    }
    *(__u64 *)((long)linuxProcess + 0x300) = (*(taskstats (*))(__fp - 0x1d8)).swapin_delay_total;
    *(__u64 *)((long)linuxProcess + 0x2f8) = (*(taskstats (*))(__fp - 0x1d8)).blkio_delay_total;
    *(__u64 *)((long)linuxProcess + 0x2f0) = (*(taskstats (*))(__fp - 0x1d8)).cpu_delay_total;
    *(__u64 *)((long)linuxProcess + 0x2e8) = (*(taskstats (*))(__fp - 0x1d8)).ac_etime * 1000;
    *(float *)((long)linuxProcess + 0x310) = fVar12;
  }
  wVar4 = 0;
LAB_0013a28c:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return wVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcessTable_readStatFile @ 0x13d700 */

_Bool LinuxProcessTable_readStatFile
                (LinuxProcess *lp,openat_arg_t procFd,LinuxMachine_2 *lhost,_Bool scanMainThread,
                char *command,size_t commLen)

{
  undefined1 __frame[0x8f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x8b8;
  char *__s;
  char cVar1;
  long lVar2;
  undefined16 auVar3;
  undefined16 auVar4;
  _Bool _Var5;
  int fd;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  ulong uVar10;
  int *piVar11;
  long lVar12;
  char *pcVar13;
  ProcessState PVar14;
  int iVar15;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: Process * process@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: char * end@[???] */
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char (*) [22])(__fp - 0x868))[8] = '\0';
  (*(char (*) [22])(__fp - 0x868))[9] = '\0';
  (*(char (*) [22])(__fp - 0x868))[10] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0xb] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0xc] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0xd] = '\0';
  builtin_strncpy((*(char (*) [22])(__fp - 0x868)),"stat",5);
  (*(char (*) [22])(__fp - 0x868))[5] = '\0';
  (*(char (*) [22])(__fp - 0x868))[6] = '\0';
  (*(char (*) [22])(__fp - 0x868))[7] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0xe] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0xf] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0x10] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0x11] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0x12] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0x13] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0x14] = '\0';
  (*(char (*) [22])(__fp - 0x868))[0x15] = '\0';
  if (scanMainThread) {
    xSnprintf((*(char (*) [22])(__fp - 0x868)),0x16,((char *)(long)&s_task__i_stat_00149b80 /* "task/%i/stat" */),(lp->super).super.id);
  }
                    /* Unresolved local var: int fd@[???] */
  fd = openat(procFd,(*(char (*) [22])(__fp - 0x868)),0);
  if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar11 = __errno_location();
    lVar6 = (long)-*piVar11;
  }
  else {
    lVar6 = readfd_internal(fd,(*(char (*) [2049])(__fp - 0x848)),0x801);
  }
  if ((-1 < lVar6) && (pcVar7 = strchr((*(char (*) [2049])(__fp - 0x848)),0x20), pcVar7 != (char *)0x0)) {
    __s = pcVar7 + 2;
    (*(char *(*))(__fp - 0x870)) = __s;
    pcVar8 = strrchr(__s,0x29);
    if (pcVar8 != (char *)0x0) {
      pcVar13 = pcVar8 + (1 - (long)__s);
      if ((char *)0x81 < pcVar13) {
        pcVar13 = (char *)0x81;
      }
                    /* Unresolved local var: size_t i@[???] */
      pcVar9 = (char *)0x0;
      if (__s != pcVar8) {
        do {
          if (pcVar7[(long)(pcVar9 + 2)] == '\0') break;
          command[(long)pcVar9] = pcVar7[(long)(pcVar9 + 2)];
          pcVar9 = pcVar9 + 1;
        } while (pcVar9 < pcVar13 + -1);
        command = command + (long)pcVar9;
      }
      cVar1 = pcVar8[2];
      *command = '\0';
      PVar14 = UNKNOWN;
      if ((byte)(cVar1 + 0xbcU) < 0x31) {
        PVar14 = (ProcessState)(byte)(&CSWTCH_143)[(byte)(cVar1 + 0xbcU)];
      }
      (lp->super).state = PVar14;
      (*(char *(*))(__fp - 0x870)) = pcVar8 + 4;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).super.parent = (int)lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).pgrp = (int)lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).session = (int)lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoul((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).tty_nr = uVar10;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).tpgid = (int)lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoul((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->flags = uVar10;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).minflt = uVar10;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->cminflt = uVar10;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).majflt = uVar10;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->cmajflt = uVar10;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->utime = (uVar10 * 100) / (ulong)lhost->jiffies;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->stime = (uVar10 * 100) / (ulong)lhost->jiffies;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->cutime = (uVar10 * 100) / (ulong)lhost->jiffies;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      uVar10 = __isoc23_strtoull((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      lp->cstime = (uVar10 * 100) / (ulong)lhost->jiffies;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).priority = lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).nice = lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).nlwp = lVar6;
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      pcVar7 = strchr((*(char *(*))(__fp - 0x870)),0x20);
      (*(char *(*))(__fp - 0x870)) = pcVar7 + 1;
      if ((lp->super).starttime_ctime == 0) {
        lVar6 = lhost->boottime;
        lVar12 = __isoc23_strtoll((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
        (*(ulong *)((char *)&auVar3 + 8)) = 0;
        (*(ulong *)((char *)&auVar3 + 0)) = lhost->jiffies;
        (*(ulong *)((char *)&auVar4 + 8)) = 0;
        (*(ulong *)((char *)&auVar4 + 0)) = lVar12 * 100;
        (lp->super).starttime_ctime =
             SUB168((auVar4 / auVar3 >> 2 & (undefined16)0x3fffffffffffffff) /
                    (undefined16)0x19,0) + lVar6;
      }
      else {
        (*(char *(*))(__fp - 0x870)) = strchr((*(char *(*))(__fp - 0x870)),0x20);
      }
      (*(char *(*))(__fp - 0x870)) = (*(char *(*))(__fp - 0x870)) + 1;
      iVar15 = 0x10;
      do {
                    /* Unresolved local var: int i@[???] */
        pcVar7 = strchr((*(char *(*))(__fp - 0x870)),0x20);
        (*(char *(*))(__fp - 0x870)) = pcVar7 + 1;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      lVar6 = __isoc23_strtol((*(char *(*))(__fp - 0x870)),&(*(char *(*))(__fp - 0x870)),10);
      (lp->super).processor = (int)lVar6;
      (lp->super).time = lp->stime + lp->utime;
      _Var5 = true;
      goto LAB_0013dbb2;
    }
  }
  _Var5 = false;
LAB_0013dbb2:
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var5;
}


/* LinuxProcessTable_initTtyDrivers @ 0x13e910 */

/* DWARF original prototype: void LinuxProcessTable_initTtyDrivers(LinuxProcessTable * this) */

void LinuxProcessTable_initTtyDrivers(LinuxProcessTable *this)

{
  undefined1 __frame[0x1040e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1040a8;
  undefined8 *puVar1;
  char cVar2;
  long lVar3;
  undefined1 *puVar4;
  int fd;
  undefined4 uVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  TtyDriver *__base;
  void *pvVar10;
  int *piVar11;
  int iVar12;
  undefined1 *puVar13;
  size_t __size;
  char *pcVar14;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: TtyDriver * ttyDrivers@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: int numDrivers@[???]
                       Unresolved local var: int allocd@[???]
                       Unresolved local var: char * at@[???] */
  puVar4 = (__fp - 0x30);
  do {
    puVar13 = puVar4;
    *(undefined8 *)(puVar13 + -0x1000) = *(undefined8 *)(puVar13 + -0x1000);
    puVar4 = puVar13 + -0x1000;
  } while (puVar13 + -0x1000 != (*(char (*) [16384])(__fp - 0x4048)) + 0x18);
                    /* Unresolved local var: int fd@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  fd = open(((char *)(long)&s__proc_tty_drivers_00149bba /* "/proc/tty/drivers" */),0);
  if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar11 = __errno_location();
    lVar6 = (long)-*piVar11;
  }
  else {
    lVar6 = readfd_internal(fd,(*(char (*) [16384])(__fp - 0x4048)),0x4000);
  }
  if (lVar6 < 0) {
LAB_0013eba5:
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* Unresolved local var: void * data@[???] */
  (*(void *(*))(__fp - 0x4058)) = malloc(0xf0);
  if ((*(void *(*))(__fp - 0x4058)) != (void *)0x0) {
    iVar12 = 0;
    __size = 0x18;
    if ((*(char (*) [16384])(__fp - 0x4048))[0] != '\0') {
      (*(int (*))(__fp - 0x4050)) = 10;
      lVar6 = 0;
      pcVar7 = (*(char (*) [16384])(__fp - 0x4048));
      (*(int (*))(__fp - 0x404c)) = 0;
      iVar12 = (*(int (*))(__fp - 0x404c));
      do {
                    /* Unresolved local var: char * token@[???] */
        (*(int (*))(__fp - 0x404c)) = iVar12;
        pcVar7 = strchr(pcVar7,0x20);
        cVar2 = *pcVar7;
        while (cVar2 == ' ') {
          pcVar7 = pcVar7 + 1;
          cVar2 = *pcVar7;
        }
        pcVar8 = strchr(pcVar7,0x20);
                    /* Unresolved local var: char * data@[???] */
        *pcVar8 = '\0';
        pcVar14 = pcVar8 + 1;
        puVar1 = (undefined8 *)((long)(*(void *(*))(__fp - 0x4058)) + lVar6);
        pcVar7 = strdup(pcVar7);
        if (pcVar7 == (char *)0x0) goto LAB_0013ec2e;
        cVar2 = pcVar8[1];
        *puVar1 = pcVar7;
        while (cVar2 == ' ') {
          pcVar14 = pcVar14 + 1;
          cVar2 = *pcVar14;
        }
        pcVar7 = strchr(pcVar14,0x20);
        *pcVar7 = '\0';
        lVar9 = __isoc23_strtol(pcVar14,(char **)0x0,10);
        *(int *)(puVar1 + 1) = (int)lVar9;
        cVar2 = pcVar7[1];
        while (pcVar8 = pcVar7 + 1, pcVar14 = pcVar8, cVar2 == ' ') {
          cVar2 = pcVar7[2];
          pcVar7 = pcVar8;
        }
        while ((byte)(cVar2 - 0x30U) < 10) {
          cVar2 = pcVar14[1];
          pcVar14 = pcVar14 + 1;
        }
        *pcVar14 = '\0';
        pcVar14 = pcVar14 + 1;
        if (cVar2 == '-') {
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          *(int *)((long)puVar1 + 0xc) = (int)lVar9;
          pcVar7 = strchr(pcVar14,0x20);
          *pcVar7 = '\0';
          pcVar7 = pcVar7 + 1;
          lVar9 = __isoc23_strtol(pcVar14,(char **)0x0,10);
          uVar5 = (undefined4)lVar9;
        }
        else {
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          *(int *)((long)puVar1 + 0xc) = (int)lVar9;
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          uVar5 = (undefined4)lVar9;
          pcVar7 = pcVar14;
        }
        *(undefined4 *)(puVar1 + 2) = uVar5;
        pcVar14 = strchr(pcVar7,10);
        pcVar7 = pcVar14 + 1;
        iVar12 = (*(int (*))(__fp - 0x404c)) + 1;
        pvVar10 = (*(void *(*))(__fp - 0x4058));
        if (iVar12 == (*(int (*))(__fp - 0x4050))) {
                    /* Unresolved local var: void * data@[???] */
          (*(int (*))(__fp - 0x4050)) = (*(int (*))(__fp - 0x404c)) + 0xb;
          pvVar10 = realloc((*(void *(*))(__fp - 0x4058)),(long)(*(int (*))(__fp - 0x4050)) * 0x18);
          if (pvVar10 == (void *)0x0) goto LAB_0013ec22;
        }
        (*(void *(*))(__fp - 0x4058)) = pvVar10;
        lVar6 = lVar6 + 0x18;
      } while (pcVar14[1] != '\0');
      __size = (long)((*(int (*))(__fp - 0x404c)) + 2) * 0x18;
    }
                    /* Unresolved local var: void * data@[???] */
    __base = realloc((*(void *(*))(__fp - 0x4058)),__size);
    if (__base != (TtyDriver *)0x0) {
      *(undefined8 *)((long)&__base[-1].path + __size) = 0;
      qsort(__base,(long)iVar12,0x18,sortTtyDrivers);
      this->ttyDrivers = __base;
      goto LAB_0013eba5;
    }
LAB_0013ec22:
    free((*(void *(*))(__fp - 0x4058)));
  }
LAB_0013ec2e:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* LinuxProcessTable_readCGroupFile @ 0x13ec40 */

void LinuxProcessTable_readCGroupFile(LinuxProcess *process,openat_arg_t procFd)

{
  undefined1 __frame[0x20e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x20a8;
  long lVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  FILE_2 *__stream;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: char * at@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: _Bool changed@[???]
                       Unresolved local var: char * cgroup_short@[???]
                       Unresolved local var: char * container_short@[???] */
                    /* Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = openat(procFd,((char *)(long)&s_cgroup_00149bcc /* "cgroup" */),0);
  if (iVar3 < 0) {
LAB_0013f1ca:
    if (process->cgroup != (char *)0x0) {
      free(process->cgroup);
      process->cgroup = (char *)0x0;
    }
    if (process->cgroup_short != (char *)0x0) {
      free(process->cgroup_short);
      process->cgroup_short = (char *)0x0;
    }
    pcVar6 = process->container_short;
    if (pcVar6 == (char *)0x0) goto LAB_0013eedb;
  }
  else {
    __stream = fdopen(iVar3,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream == (FILE_2 *)0x0) {
      close(iVar3);
      goto LAB_0013f1ca;
    }
    (*(char (*) [4097])(__fp - 0x2058))[0] = '\0';
    iVar3 = 0x1000;
                    /* Unresolved local var: char * ok@[???]
                       Unresolved local var: char * group@[???]
                       Unresolved local var: char * eol@[???]
                       Unresolved local var: int wrote@[???]
                       Unresolved local var: size_t sz@[???] */
    while (((iVar4 = feof(__stream), 0 < iVar3 && (iVar4 == 0)) &&
           (pcVar6 = fgets((*(char (*) [4097])(__fp - 0x1048)),0x1000,__stream), pcVar6 != (char *)0x0))) {
                    /* Unresolved local var: size_t i@[???] */
      pcVar6 = strchrnul((*(char (*) [4097])(__fp - 0x1048)),0x3a);
      if (*pcVar6 != '\0') {
        pcVar6 = strchrnul(pcVar6 + 1,0x3a);
        pcVar6 = pcVar6 + (*pcVar6 != '\0');
      }
      pcVar7 = strchrnul(pcVar6,10);
      *pcVar7 = '\0';
      iVar4 = __snprintf_chk((*(char (*) [4097])(__fp - 0x2058)),(long)iVar3,2,0x1001,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),pcVar6);
      iVar3 = iVar3 - iVar4;
    }
    fclose(__stream);
    pcVar6 = process->cgroup;
    if (pcVar6 == (char *)0x0) {
      sVar5 = strlen((*(char (*) [4097])(__fp - 0x2058)));
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x71] < sVar5) {
          Row_fieldWidths[0x71] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x71] = 0xff;
      }
      goto LAB_0013efd7;
    }
    iVar3 = strcmp(pcVar6,(*(char (*) [4097])(__fp - 0x2058)));
    sVar5 = strlen((*(char (*) [4097])(__fp - 0x2058)));
    if (iVar3 == 0) {
      bVar2 = false;
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x71] < sVar5) goto LAB_0013f0a7;
      }
      else {
        Row_fieldWidths[0x71] = 0xff;
        iVar3 = strcmp(pcVar6,(*(char (*) [4097])(__fp - 0x2058)));
        if (iVar3 != 0) goto LAB_0013eff9;
      }
LAB_0013ef20:
      pcVar6 = process->cgroup_short;
      if (pcVar6 == (char *)0x0) {
        pcVar6 = process->cgroup;
      }
      sVar5 = strlen(pcVar6);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x81] < sVar5) {
          Row_fieldWidths[0x81] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x81] = 0xff;
      }
      if (process->container_short == (char *)0x0) {
        if (Row_fieldWidths[0x82] < 3) {
          Row_fieldWidths[0x82] = '\x03';
        }
      }
      else {
        sVar5 = strlen(process->container_short);
        if (sVar5 < 0x100) {
          if (Row_fieldWidths[0x82] < sVar5) {
            Row_fieldWidths[0x82] = (uint8_t)sVar5;
          }
        }
        else {
          Row_fieldWidths[0x82] = 0xff;
        }
      }
      goto LAB_0013eedb;
    }
    if (sVar5 < 0x100) {
      if (sVar5 <= Row_fieldWidths[0x71]) goto LAB_0013efd7;
      bVar2 = true;
LAB_0013f0a7:
      Row_fieldWidths[0x71] = (uint8_t)sVar5;
      iVar3 = strcmp(pcVar6,(*(char (*) [4097])(__fp - 0x2058)));
      if (iVar3 != 0) goto LAB_0013eff9;
LAB_0013f020:
      if (!bVar2) goto LAB_0013ef20;
      pcVar6 = CGroup_filterName(process->cgroup);
      if (pcVar6 != (char *)0x0) goto LAB_0013ede0;
LAB_0013f04b:
      sVar5 = strlen(process->cgroup);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x81] < sVar5) {
          Row_fieldWidths[0x81] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x81] = 0xff;
      }
      free(process->cgroup_short);
      process->cgroup_short = (char *)0x0;
    }
    else {
      Row_fieldWidths[0x71] = 0xff;
      iVar3 = strcmp(pcVar6,(*(char (*) [4097])(__fp - 0x2058)));
      if (iVar3 != 0) {
LAB_0013efd7:
        bVar2 = true;
LAB_0013eff9:
        free(pcVar6);
                    /* Unresolved local var: char * data@[???] */
        pcVar6 = strdup((*(char (*) [4097])(__fp - 0x2058)));
        if (pcVar6 == (char *)0x0) goto LAB_0013f1be;
        process->cgroup = pcVar6;
        goto LAB_0013f020;
      }
      pcVar6 = CGroup_filterName(pcVar6);
      if (pcVar6 == (char *)0x0) goto LAB_0013f04b;
LAB_0013ede0:
      sVar5 = strlen(pcVar6);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x81] < sVar5) {
          Row_fieldWidths[0x81] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x81] = 0xff;
      }
      pcVar7 = process->cgroup_short;
      if ((pcVar7 == (char *)0x0) || (iVar3 = strcmp(pcVar7,pcVar6), iVar3 != 0)) {
        free(pcVar7);
                    /* Unresolved local var: char * data@[???] */
        pcVar7 = strdup(pcVar6);
        if (pcVar7 == (char *)0x0) goto LAB_0013f1be;
        process->cgroup_short = pcVar7;
      }
      free(pcVar6);
    }
    pcVar6 = CGroup_filterContainer(process->cgroup);
    if (pcVar6 != (char *)0x0) {
      sVar5 = strlen(pcVar6);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x82] < sVar5) {
          Row_fieldWidths[0x82] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x82] = 0xff;
      }
      pcVar7 = process->container_short;
      if ((pcVar7 == (char *)0x0) || (iVar3 = strcmp(pcVar7,pcVar6), iVar3 != 0)) {
        free(pcVar7);
                    /* Unresolved local var: char * data@[???] */
        pcVar7 = strdup(pcVar6);
        if (pcVar7 == (char *)0x0) {
LAB_0013f1be:
                    /* WARNING: Subroutine does not return */
          fail();
        }
        process->container_short = pcVar7;
      }
      free(pcVar6);
      goto LAB_0013eedb;
    }
    if (Row_fieldWidths[0x82] < 3) {
      Row_fieldWidths[0x82] = '\x03';
    }
    pcVar6 = process->container_short;
  }
  free(pcVar6);
  process->container_short = (char *)0x0;
LAB_0013eedb:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* LinuxProcessTable_readSecattrData @ 0x13f230 */

void LinuxProcessTable_readSecattrData(LinuxProcess *process,openat_arg_t procFd)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  char *pcVar3;
  size_t sVar4;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: char * res@[???]
                       Unresolved local var: char * newline@[???] */
                    /* Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = openat(procFd,((char *)(long)&s_attr_current_00149bd3 /* "attr/current" */),0);
  if (-1 < iVar2) {
    __stream = fdopen(iVar2,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream == (FILE_2 *)0x0) {
      close(iVar2);
    }
    else {
                    /* Unresolved local var: size_t sz@[???] */
      pcVar3 = fgets((*(char (*) [4097])(__fp - 0x1038)),0x1001,__stream);
      fclose(__stream);
      if (pcVar3 != (char *)0x0) {
        pcVar3 = strchr((*(char (*) [4097])(__fp - 0x1038)),10);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        sVar4 = strlen((*(char (*) [4097])(__fp - 0x1038)));
        if (sVar4 < 0x100) {
          if (Row_fieldWidths[0x7b] < sVar4) {
            Row_fieldWidths[0x7b] = (uint8_t)sVar4;
          }
        }
        else {
          Row_fieldWidths[0x7b] = 0xff;
        }
        pcVar3 = process->secattr;
        if (pcVar3 != (char *)0x0) {
          iVar2 = strcmp(pcVar3,(*(char (*) [4097])(__fp - 0x1038)));
          if (iVar2 == 0) goto LAB_0013f32c;
        }
        free(pcVar3);
                    /* Unresolved local var: char * data@[???] */
        pcVar3 = strdup((*(char (*) [4097])(__fp - 0x1038)));
        if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        process->secattr = pcVar3;
        goto LAB_0013f32c;
      }
    }
  }
  free(process->secattr);
  process->secattr = (char *)0x0;
LAB_0013f32c:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcessTable_readCwd @ 0x13f390 */

void LinuxProcessTable_readCwd(LinuxProcess *process,openat_arg_t procFd)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  long lVar1;
  int iVar2;
  ssize_t sVar3;
  char *pcVar4;
  long lVar5;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar4 = (*(char (*) [4097])(__fp - 0x1038));
                    /* Unresolved local var: ssize_t r@[???] */
  for (lVar5 = 0x200; lVar5 != 0; lVar5 = lVar5 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  *pcVar4 = '\0';
  sVar3 = readlinkat(procFd,((char *)(long)&DAT_00149be0 /* "cwd" */),(*(char (*) [4097])(__fp - 0x1038)),0x1000);
  if (sVar3 < 0) {
    free((process->super).procCwd);
    (process->super).procCwd = (char *)0x0;
  }
  else {
    pcVar4 = (process->super).procCwd;
    (*(char (*) [4097])(__fp - 0x1038))[sVar3] = '\0';
    if (pcVar4 != (char *)0x0) {
      iVar2 = strcmp(pcVar4,(*(char (*) [4097])(__fp - 0x1038)));
      if (iVar2 == 0) goto LAB_0013f432;
    }
    free(pcVar4);
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup((*(char (*) [4097])(__fp - 0x1038)));
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (process->super).procCwd = pcVar4;
  }
LAB_0013f432:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ProcessTable_new @ 0x143ba0 */

ProcessTable_2 * ProcessTable_new(Machine_2 *host,Hashtable_2 *pidMatchList)

{
  int iVar1;
  LinuxProcessTable *this;
  Vector *pVVar2;
  Object **ppOVar3;
  Hashtable *pHVar4;

                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x78);
  if (this != (LinuxProcessTable *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    (this->super).super.super.klass = &ProcessTable_class.super;
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
      pVVar2->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pVVar2->array = ppOVar3;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
        pVVar2->arraySize = 10;
        pVVar2->owner = true;
        pVVar2->type = (ObjectClass *)&LinuxProcess_class;
        pVVar2->items = 0;
        pVVar2->dirty_index = -1;
        pVVar2->dirty_count = 0;
        (this->super).super.rows = pVVar2;
        pVVar2 = malloc(0x28);
        if (pVVar2 != (Vector *)0x0) {
          pVVar2->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
          ppOVar3 = calloc(10,8);
          if (ppOVar3 != (Object **)0x0) {
            pVVar2->array = ppOVar3;
            pVVar2->items = 0;
            pVVar2->dirty_index = -1;
            (this->super).super.displayList = pVVar2;
            pVVar2->arraySize = 10;
            pVVar2->type = (ObjectClass *)&LinuxProcess_class;
            pVVar2->owner = false;
            pVVar2->dirty_count = 0;
            pHVar4 = Hashtable_new(200,false);
            (this->super).super.host = host;
            (this->super).super.table = pHVar4;
            (this->super).pidMatchList = pidMatchList;
            (this->super).super.needsSort = true;
            (this->super).super.following = -1;
            LinuxProcessTable_initTtyDrivers(this);
            iVar1 = access(((char *)(long)&s__proc_self_smaps_rollup_0014a066 /* "/proc/self/smaps_rollup" */),4);
            this->haveSmapsRollup = iVar1 == 0;
            return &this->super;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ProcessTable_delete @ 0x143d00 */

void ProcessTable_delete(LinuxProcessTable_ *cast)

{
  Hashtable *this;
  TtyDriver *__ptr;
  long lVar1;
  char *__ptr_00;

  this = (cast->super).super.table;
  Hashtable_clear(this);
  free(this->buckets);
  free(this);
  Vector_delete((cast->super).super.displayList);
  Vector_delete((cast->super).super.rows);
  __ptr = cast->ttyDrivers;
  if (__ptr != (TtyDriver *)0x0) {
                    /* Unresolved local var: int i@[???] */
    __ptr_00 = __ptr->path;
    if (__ptr_00 != (char *)0x0) {
      lVar1 = 0x18;
      do {
        free(__ptr_00);
        __ptr = cast->ttyDrivers;
        __ptr_00 = *(char **)((long)&__ptr->path + lVar1);
        lVar1 = lVar1 + 0x18;
      } while (__ptr_00 != (char *)0x0);
    }
    free(__ptr);
  }
  if (cast->netlink_socket != (nl_sock *)0x0) {
    nl_close(cast->netlink_socket);
    nl_socket_free(cast->netlink_socket);
  }
  free(cast);
  return;
}


/* LinuxProcessTable_readCmdlineFile @ 0x143db0 */

_Bool LinuxProcessTable_readCmdlineFile(Process_2 *process,openat_arg_t procFd)

{
  undefined1 __frame[0x1178] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1138;
  long lVar1;
  bool bVar2;
  _Bool _Var3;
  int wVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  ssize_t sVar9;
  size_t sVar10;
  int *piVar11;
  int wVar12;
  ulong uVar13;
  char *pcVar14;
  ulong uVar15;
  int wVar16;
  int wVar17;
  int wVar18;
  char cVar19;
  int wVar20;
  int wVar21;
  int wVar22;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar23;

                    /* Unresolved local var: ssize_t amtRead@[???]
                       Unresolved local var: int tokenEnd@[???]
                       Unresolved local var: int tokenStart@[???]
                       Unresolved local var: int lastChar@[???]
                       Unresolved local var: _Bool argSepNUL@[???]
                       Unresolved local var: _Bool argSepSpace@[???] */
                    /* Unresolved local var: int fd@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar4 = openat(procFd,((char *)(long)(__sec_rodata + 0x2306) /* "cmdline" */),0);
  if (wVar4 < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar11 = __errno_location();
    uVar6 = (ulong)-*piVar11;
  }
  else {
    uVar6 = readfd_internal(wVar4,(*(char (*) [4097])(__fp - 0x1048)),0x1001);
  }
  if (0 < (long)uVar6) {
    uVar13 = 1;
    bVar2 = false;
    bVar23 = false;
    wVar4 = 0;
    uVar15 = 0;
    wVar18 = 0;
    do {
      wVar12 = (int)uVar15;
      wVar16 = (int)uVar13 + -1;
      cVar19 = (*(char (*) [4097])(__fp - 0x1048))[uVar13 - 1];
      if (cVar19 == '\0') {
                    /* Unresolved local var: int i@[???] */
        (*(char (*) [4097])(__fp - 0x1048))[uVar13 - 1] = '\n';
        if (wVar18 == 0) {
          wVar18 = wVar16;
        }
LAB_00143e4a:
        wVar12 = (int)uVar15;
      }
      else {
        if (wVar18 == 0) {
          if (cVar19 < '!') {
            if (cVar19 == '\n') {
              bVar2 = true;
              wVar18 = wVar16;
            }
            else {
              bVar2 = true;
              wVar4 = wVar16;
            }
          }
          else {
            wVar4 = wVar16;
            if (cVar19 == '/') {
              uVar15 = uVar13 & 0xffffffff;
            }
          }
          goto LAB_00143e4a;
        }
        if (cVar19 < '!') {
          bVar2 = true;
          bVar23 = true;
          if (cVar19 != '\n') {
            wVar4 = wVar16;
          }
          goto LAB_00143e4a;
        }
        bVar23 = true;
        wVar4 = wVar16;
      }
      if (uVar6 == uVar13) goto LAB_00143e90;
      uVar13 = uVar13 + 1;
    } while( true );
  }
  _Var3 = false;
  goto LAB_00144138;
LAB_00143e90:
  wVar16 = wVar4 + 1;
  pcVar8 = (*(char (*) [4097])(__fp - 0x1048));
  (*(char (*) [4097])(__fp - 0x1048))[wVar16] = '\0';
  if ((bVar23) || (!bVar2)) {
LAB_00143ff0:
    wVar4 = wVar16;
    if (wVar18 != 0) {
      wVar4 = wVar18;
    }
  }
  else {
    uVar6 = (ulong)(*(undefined8 (*))(__fp - 0x10e8)) >> 0x20;
    (*(undefined8 (*))(__fp - 0x10e8)) = (char *)CONCAT44((int)uVar6,wVar16);
                    /* Unresolved local var: int ret@[???] */
    (*(int *(*))(__fp - 0x10e0)) = __errno_location();
    *(*(int *(*))(__fp - 0x10e0)) = 0;
    iVar5 = faccessat(-100,pcVar8,0,0x100);
    wVar16 = (int)(*(undefined8 (*))(__fp - 0x10e8));
    if (iVar5 != 0) {
      if (*(*(int *(*))(__fp - 0x10e0)) == 0x16) {
        iVar5 = lstat(pcVar8,(stat_2 *)(*(char (*) [129])(__fp - 0x10d8)));
        wVar16 = (int)(*(undefined8 (*))(__fp - 0x10e8));
        if (iVar5 == 0) goto LAB_00143f26;
      }
                    /* Unresolved local var: int i@[???] */
      wVar17 = 0;
      wVar18 = 0;
      pcVar14 = pcVar8;
      wVar21 = 0;
      (*(undefined8 (*))(__fp - 0x10e8)) = pcVar8;
      wVar20 = 0;
      do {
        cVar19 = *pcVar14;
        wVar22 = wVar21 + 1;
        wVar12 = wVar20;
        if (cVar19 < '!') {
                    /* Unresolved local var: char tmpCommandChar@[???] */
          if (wVar18 == 0) {
                    /* Unresolved local var: _Bool found@[???] */
            *pcVar14 = '\0';
                    /* Unresolved local var: int ret@[???] */
            *(*(int *(*))(__fp - 0x10e0)) = 0;
            iVar5 = faccessat(-100,(*(undefined8 (*))(__fp - 0x10e8)),0,0x100);
            if ((iVar5 == 0) ||
               ((*(*(int *(*))(__fp - 0x10e0)) == 0x16 && (iVar5 = lstat((*(undefined8 (*))(__fp - 0x10e8)),(stat_2 *)(*(char (*) [129])(__fp - 0x10d8))), iVar5 == 0)))
               ) {
              cVar19 = '\n';
              wVar18 = wVar21;
            }
            *pcVar14 = cVar19;
            if (wVar17 == 0) {
              wVar17 = wVar20;
            }
          }
          else {
            *pcVar14 = '\n';
          }
        }
        else if ((wVar18 == 0) && (wVar12 = wVar22, cVar19 != '/')) {
          if (cVar19 == '\\') {
            if ((wVar20 != 0) && (wVar12 = wVar20, (*(char (*) [4097])(__fp - 0x1048))[wVar20 + -1] == '\\')) {
              wVar12 = wVar22;
            }
          }
          else {
            wVar12 = wVar20;
            if (((cVar19 == ':') && (pcVar14[1] != '/')) && (pcVar14[1] != '\\')) {
              wVar18 = wVar21;
            }
          }
        }
        pcVar14 = pcVar14 + 1;
        wVar21 = wVar22;
        wVar20 = wVar12;
      } while (wVar22 <= wVar4);
                    /* Unresolved local var: int tokenArg0Start@[???] */
      if (wVar18 == 0) {
                    /* Unresolved local var: int i@[???] */
        wVar12 = 0;
        do {
          if ((*pcVar8 < '!') && (*pcVar8 = '\n', wVar18 == 0)) {
            wVar18 = wVar12;
          }
          wVar12 = wVar12 + 1;
          pcVar8 = pcVar8 + 1;
        } while (wVar12 <= wVar4);
        pcVar8 = (*(undefined8 (*))(__fp - 0x10e8));
        wVar12 = wVar17;
        if (wVar17 < wVar18) goto LAB_00143ff0;
      }
      else {
        pcVar8 = (*(undefined8 (*))(__fp - 0x10e8));
        wVar4 = wVar18;
        if (wVar12 < wVar18) goto LAB_00143ff7;
      }
    }
LAB_00143f26:
    wVar12 = 0;
    wVar4 = wVar16;
  }
LAB_00143ff7:
  Process_updateCmdline((Process *)process,pcVar8,wVar12,wVar4);
                    /* Unresolved local var: int fd@[???] */
  wVar4 = openat(procFd,((char *)(long)&DAT_0014a07e /* "comm" */),0);
  if (wVar4 < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar11 = __errno_location();
    pcVar14 = process->procComm;
    lVar7 = (long)-*piVar11;
    if (lVar7 < 1) goto LAB_0014417b;
LAB_00144041:
    (*(char (*) [4097])(__fp - 0x1048))[lVar7 + -1] = '\0';
    if ((pcVar14 == (char *)0x0) || (iVar5 = strcmp(pcVar14,pcVar8), iVar5 != 0)) {
      free(pcVar14);
                    /* Unresolved local var: char * data@[???] */
      pcVar8 = strdup(pcVar8);
      if (pcVar8 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
        fail();
      }
      process->procComm = pcVar8;
      (process->mergedCommand).lastUpdate = 0;
    }
  }
  else {
    lVar7 = readfd_internal(wVar4,pcVar8,0x1001);
    pcVar14 = process->procComm;
    if (0 < lVar7) goto LAB_00144041;
LAB_0014417b:
    if (pcVar14 != (char *)0x0) {
      free(pcVar14);
      process->procComm = (char *)0x0;
      (process->mergedCommand).lastUpdate = 0;
    }
  }
  sVar9 = readlinkat(procFd,((char *)(long)(__sec_rodata + 0x2289) /* "exe" */),(*(char (*) [129])(__fp - 0x10d8)),0x80);
  if (sVar9 < 1) {
    if (process->procExe != (char *)0x0) {
      free(process->procExe);
      process->procExeDeleted = false;
      process->procExe = (char *)0x0;
      process->procExeBasenameOffset = 0;
      (process->mergedCommand).lastUpdate = 0;
    }
  }
  else {
    pcVar8 = process->procExe;
    (*(char (*) [129])(__fp - 0x10d8))[sVar9] = '\0';
    if (((pcVar8 == (char *)0x0) || (process->procExeDeleted != false)) ||
       (iVar5 = strcmp((*(char (*) [129])(__fp - 0x10d8)),pcVar8), iVar5 != 0)) {
                    /* Unresolved local var: char * deletedMarker@[???]
                       Unresolved local var: size_t markerLen@[???]
                       Unresolved local var: size_t filenameLen@[???] */
      sVar10 = strlen((*(char (*) [129])(__fp - 0x10d8)));
      if (10 < sVar10) {
                    /* Unresolved local var: _Bool oldExeDeleted@[???] */
        _Var3 = process->procExeDeleted;
        iVar5 = strcmp((*(char (*) [129])(__fp - 0x10d8)) + (sVar10 - 10),((char *)(long)&s__deleted__0014898b /* " (deleted)" */));
        bVar23 = iVar5 == 0;
        process->procExeDeleted = bVar23;
        if (bVar23) {
          *(undefined1 *)((long)&(*(undefined8 (*))(__fp - 0x10e8)) + sVar10 + 6) = 0;
        }
        if (_Var3 != bVar23) {
          (process->mergedCommand).lastUpdate = 0;
        }
      }
      Process_updateExe((Process *)process,(*(char (*) [129])(__fp - 0x10d8)));
    }
  }
  _Var3 = true;
LAB_00144138:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcessTable_recurseProcTree @ 0x144c10 */

/* DWARF original prototype: _Bool LinuxProcessTable_recurseProcTree(LinuxProcessTable * this,
   openat_arg_t parentFd, LinuxMachine * lhost, char * dirname, Process * parent) */

_Bool LinuxProcessTable_recurseProcTree
                (LinuxProcessTable *this,openat_arg_t parentFd,LinuxMachine_2 *lhost,char *dirname,
                Process_2 *parent)

{
  undefined1 __frame[0x6a8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x668;
  uint *puVar1;
  char *pcVar2;
  _Bool _Var3;
  _Bool _Var4;
  _Bool _Var5;
  _Bool _Var6;
  _Bool _Var7;
  byte bVar8;
  int wVar9;
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
  int wVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  int wVar28;
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
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar54;
  float percentage;
  double dVar55;
  double dVar56;
  float fVar57;

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
                       Unresolved local var: int pid@[???]
                       Unresolved local var: int procFd@[???]
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
                (uVar31 = __isoc23_strtoul(pcVar35,&(*(char *(*))(__fp - 0x5a8)),10), uVar31 - 1 < 0xfffffffffffffffe)) &&
               (*(*(char *(*))(__fp - 0x5a8)) == '\0')) &&
              ((wVar28 = (int)uVar31, parent == (Process_2 *)0x0 ||
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
                  LinuxProcessTable_recurseProcTree(this,parentFd_00,lhost,((char *)(long)&DAT_0014a1aa /* "task" */),(Process_2 *)lp);
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
                  (*(LinuxProcess *(*))(__fp - 0x608)) = lp;
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
                      (*(Machine__2 *(*))(__fp - 0x5f8)) = (Machine__2 *)(lp->super).super.host;
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
            (lp->super).cmdlineBasenameEnd = -1;
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
            LinuxProcessTable_recurseProcTree(this,parentFd_00,lhost,((char *)(long)&DAT_0014a1aa /* "task" */),(Process_2 *)lp);
            (*(LinuxProcess *(*))(__fp - 0x608)) = (LinuxProcess *)0x0;
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
                (*(Machine__2 *(*))(__fp - 0x5f8)) = (Machine__2 *)(lp->super).super.host;
                (*(char (*) [20])(__fp - 0x4d8))[0] = 'i';
                (*(char (*) [20])(__fp - 0x4d8))[1] = 'o';
                (*(char (*) [20])(__fp - 0x4d8))[2] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[3] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[4] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[5] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[6] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[7] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[8] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[9] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[10] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xb] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xc] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xd] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xe] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xf] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x10] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x11] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x12] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x13] = '\0';
                if (_Var21 == false) {
                  _Var21 = false;
                }
                else {
                  _Var21 = true;
                  xSnprintf((*(char (*) [20])(__fp - 0x4d8)),0x14,((char *)(long)&DAT_0014a0eb /* "task/%i/io" */),(lp->super).super.id);
                }
                goto LAB_00144f7e;
              }
            }
            else {
              _Var21 = false;
              if ((uVar26 & 1) != 0) {
                (*(Machine__2 *(*))(__fp - 0x5f8)) = (Machine__2 *)(lp->super).super.host;
LAB_00145a8a:
                _Var21 = false;
                (*(char (*) [20])(__fp - 0x4d8))[0] = 'i';
                (*(char (*) [20])(__fp - 0x4d8))[1] = 'o';
                (*(char (*) [20])(__fp - 0x4d8))[2] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[3] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[4] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[5] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[6] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[7] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[8] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[9] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[10] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xb] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xc] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xd] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xe] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0xf] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x10] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x11] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x12] = '\0';
                (*(char (*) [20])(__fp - 0x4d8))[0x13] = '\0';
LAB_00144f7e:
                    /* Unresolved local var: int fd@[???] */
                wVar24 = openat(parentFd_00,(*(char (*) [20])(__fp - 0x4d8)),0);
                if (wVar24 < 0) {
                    /* Unresolved local var: int fd@[???] */
                  piVar44 = __errno_location();
                  lVar33 = (long)-*piVar44;
                }
                else {
                  lVar33 = readfd_internal(wVar24,(*(char (*) [1024])(__fp - 0x448)),0x400);
                }
                uVar31 = (*(Machine__2 *(*))(__fp - 0x5f8))->realtimeMs;
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
                  (*(char *(*))(__fp - 0x5a8)) = (*(char (*) [1024])(__fp - 0x448));
                  while (pcVar35 = strsep(&(*(char *(*))(__fp - 0x5a8)),((char *)(long)&DAT_00147506 /* "\n" */)), pcVar35 != (char *)0x0) {
                    cVar20 = *pcVar35;
                    if (cVar20 == 's') {
                      if ((pcVar35[4] == 'r') &&
                         (iVar25 = strncmp(pcVar35 + 1,((char *)(long)&s_yscr__0014a108 /* "yscr: " */),6), iVar25 == 0)) {
                        uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                        lp->io_syscr = uVar31;
                      }
                      else {
                        iVar25 = strncmp(pcVar35 + 1,((char *)(long)&s_yscw__0014a10f /* "yscw: " */),6);
                        if (iVar25 == 0) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                          lp->io_syscw = uVar31;
                        }
                      }
                    }
                    else if (cVar20 < 't') {
                      if (cVar20 == 'c') {
                        iVar25 = strncmp(pcVar35 + 1,((char *)(long)&s_ancelled_write_bytes__0014a116 /* "ancelled_write_bytes: " */),0x16);
                        if (iVar25 == 0) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 0x17,(char **)0x0,10);
                          lp->io_cancelled_write_bytes = uVar31;
                        }
                      }
                      else if (cVar20 == 'r') {
                        if ((pcVar35[1] == 'c') &&
                           (iVar25 = strncmp(pcVar35 + 2,((char *)(long)&s_har__0014a0f6 /* "har: " */),5), iVar25 == 0)) {
                          uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                          lp->io_rchar = uVar31;
                        }
                        else {
                          iVar25 = strncmp(pcVar35 + 1,((char *)(long)&s_ead_bytes__0014a0fc /* "ead_bytes: " */),0xb);
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
                         (iVar25 = strncmp(pcVar35 + 2,((char *)(long)&s_har__0014a0f6 /* "har: " */),5), iVar25 == 0)) {
                        uVar31 = __isoc23_strtoull(pcVar35 + 7,(char **)0x0,10);
                        lp->io_wchar = uVar31;
                      }
                      else {
                        iVar25 = strncmp(pcVar35 + 1,((char *)(long)(__sec_rodata + 0x3120) /* "rite_bytes: " */),0xc);
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
                  uVar31 = (*(Machine__2 *(*))(__fp - 0x5f8))->realtimeMs;
                }
                lp->io_last_scan_time_ms = uVar31;
              }
            }
LAB_00145140:
                    /* Unresolved local var: FILE * statmfile@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
            iVar25 = openat(parentFd_00,((char *)(long)&s_statm_0014a12d /* "statm" */),0);
            if (-1 < iVar25) {
              pFVar36 = fdopen(iVar25,((char *)(long)&DAT_00147760 /* "r" */));
              if (pFVar36 == (FILE_2 *)0x0) {
                close(iVar25);
              }
              else {
                va3 = &lp->m_trs;
                iVar25 = __isoc23_fscanf(pFVar36,((char *)(long)&s__ld__ld__ld__ld__ld__ld__ld_0014a133 /* "%ld %ld %ld %ld %ld %ld %ld" */),&(lp->super).m_virt,
                                         &(lp->super).m_resident,&lp->m_share,va3,&(*(long (*))(__fp - 0x5b0)),&lp->m_drs,
                                         (tm_2 *)&(*(char *(*))(__fp - 0x5a8)));
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
                      (*(uchar *)((char *)&lVar33 + 0)) = parent[1].elevated_priv;
                      (*(uchar *)((char *)&lVar33 + 1)) = parent[1].field_0x71;
                      (*(uchar *)((char *)&lVar33 + 2)) = parent[1].field_0x72;
                      (*(uchar *)((char *)&lVar33 + 3)) = parent[1].field_0x73;
                      (*(uchar *)((char *)&lVar33 + 4)) = parent[1].field_0x74;
                      (*(uchar *)((char *)&lVar33 + 5)) = parent[1].field_0x75;
                      (*(uchar *)((char *)&lVar33 + 6)) = parent[1].field_0x76;
                      (*(uchar *)((char *)&lVar33 + 7)) = parent[1].field_0x77;
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
                       Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
                      lp->last_mlrs_calctime = (lhost->super).realtimeMs;
                      _Var7 = pSVar11->highlightDeletedExe;
                      uVar26 = pSVar12->flags;
                      (lp->super).usesDeletedLib = false;
                      (*(uint (*))(__fp - 0x620)) = uVar26 & 0x10000;
                      iVar25 = openat(parentFd_00,((char *)(long)&DAT_0014a0e6 /* "maps" */),0);
                      if (-1 < iVar25) {
                        pFVar36 = fdopen(iVar25,((char *)(long)&DAT_00147760 /* "r" */));
                        if (pFVar36 == (FILE_2 *)0x0) {
                          close(iVar25);
                        }
                        else {
                          va3 = (long *)((ulong)uVar26 & 0x10000);
                          if ((*(uint (*))(__fp - 0x620)) == 0) {
                            (*(Hashtable *(*))(__fp - 0x618)) = (Hashtable *)0x0;
                          }
                          else {
                            (*(Hashtable *(*))(__fp - 0x618)) = Hashtable_new(0x40,true);
                          }
                    /* Unresolved local var: uint64_t map_start@[???]
                       Unresolved local var: uint64_t map_end@[???]
                       Unresolved local var: _Bool map_execute@[???]
                       Unresolved local var: uint map_devmaj@[???]
                       Unresolved local var: uint map_devmin@[???]
                       Unresolved local var: uint64_t map_inode@[???]
                       Unresolved local var: char * readptr@[???]
                       Unresolved local var: uint64_t result@[???]
                       Unresolved local var: int nibble@[???]
                       Unresolved local var: int letter@[???]
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
                                            pcVar35 = fgets((*(char (*) [1024])(__fp - 0x448)),0x400,pFVar36);
                                            if (pcVar35 == (char *)0x0) {
                                              fclose(pFVar36);
                                              if ((*(uint (*))(__fp - 0x620)) != 0) {
                    /* Unresolved local var: uint64_t total_size@[???]
                       Unresolved local var: size_t i@[???] */
                                                uVar31 = 0;
                                                if ((*(Hashtable *(*))(__fp - 0x618))->size != 0) {
                    /* Unresolved local var: HashtableItem * walk@[???] */
                                                  ppvVar49 = &(*(Hashtable *(*))(__fp - 0x618))->buckets->value;
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
                                                           &(*(Hashtable *(*))(__fp - 0x618))->buckets[(*(Hashtable *(*))(__fp - 0x618))->size].
                                                            value);
                                                }
                                                Hashtable_clear((*(Hashtable *(*))(__fp - 0x618)));
                                                free((*(Hashtable *(*))(__fp - 0x618))->buckets);
                                                free((*(Hashtable *(*))(__fp - 0x618)));
                                                lp->m_lrs = uVar31 / (ulong)(long)lhost->pageSize;
                                              }
                                              goto LAB_00145310;
                                            }
                                            pcVar35 = strchr((*(char (*) [1024])(__fp - 0x448)),0x2f);
                                          } while (pcVar35 == (char *)0x0);
                                          lVar33 = 0;
                                          pbVar43 = (byte *)(*(char (*) [1024])(__fp - 0x448));
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
                                          } while (pbVar53 + 1 != (byte *)((*(char (*) [1024])(__fp - 0x448)) + 0x10));
                                          bVar52 = pbVar53[1];
                                          pbVar53 = (byte *)((*(char (*) [1024])(__fp - 0x448)) + 0x10);
LAB_001464cd:
                                        } while (bVar52 != 0x2d);
                                        va3 = (long *)0x0;
                                        pbVar43 = pbVar53 + 1;
                    /* Unresolved local var: uint64_t result@[???]
                       Unresolved local var: int nibble@[???]
                       Unresolved local var: int letter@[???]
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
                       Unresolved local var: int nibble@[???]
                       Unresolved local var: int letter@[???]
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
                       Unresolved local var: int nibble@[???]
                       Unresolved local var: int letter@[???]
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
                              if ((*(uint (*))(__fp - 0x620)) != 0) {
                    /* Unresolved local var: LibraryData * libdata@[???] */
                                plVar45 = Hashtable_get((*(Hashtable *(*))(__fp - 0x618)),(ht_key_t)lVar37);
                                if (plVar45 == (long *)0x0) {
                                  plVar45 = xCalloc(1,0x10);
                                  Hashtable_put((*(Hashtable *(*))(__fp - 0x618)),(ht_key_t)lVar37,plVar45);
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
                                    (_Var22 = String_startsWith((char *)pbVar53,((char *)(long)&s__memfd__0014a14f /* "/memfd:" */)), _Var22))
                                   || (iVar25 = strcmp((char *)pbVar53,((char *)(long)&s__dev_zero__deleted__0014a157 /* "/dev/zero (deleted)\n" */)),
                                      iVar25 == 0)) ||
                                  ((pcVar35 = strstr((char *)pbVar53,((char *)(long)(__sec_rodata + 0x3160) /* " (deleted)\n" */)),
                                   pcVar35 == (char *)0x0 ||
                                   ((lp->super).usesDeletedLib = true, (*(uint (*))(__fp - 0x620)) != 0))));
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
                        pcVar35 = ((char *)(long)&DAT_0014a0e5 /* "smaps" */);
                    /* Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
                        if (this->haveSmapsRollup != false) {
                          pcVar35 = ((char *)(long)(__sec_rodata + 0x3071) /* "smaps_rollup" */);
                        }
                        iVar25 = openat(parentFd_00,pcVar35,0);
                        if (-1 < iVar25) {
                          pFVar36 = fdopen(iVar25,((char *)(long)&DAT_00147760 /* "r" */));
                          if (pFVar36 == (FILE_2 *)0x0) {
                            close(iVar25);
                          }
                          else {
                            lp->m_psswp = 0;
                            lp->m_pss = 0;
                            lp->m_swap = 0;
LAB_00146a1b:
                    /* Unresolved local var: size_t sz@[???] */
                            pcVar35 = fgets((*(char (*) [1024])(__fp - 0x448)),0x100,pFVar36);
                            if (pcVar35 != (char *)0x0) {
                              pcVar35 = strchr((*(char (*) [1024])(__fp - 0x448)),10);
                              if (pcVar35 == (char *)0x0) {
                                do {
                    /* Unresolved local var: size_t sz@[???] */
                                  pcVar35 = fgets((*(char (*) [1024])(__fp - 0x448)),0x100,pFVar36);
                                  if (pcVar35 == (char *)0x0) break;
                                  pcVar35 = strchr((*(char (*) [1024])(__fp - 0x448)),10);
                                } while (pcVar35 == (char *)0x0);
                              }
                              else if ((*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 0)) == 0x3a737350) {
                                lVar33 = __isoc23_strtol((*(char (*) [1024])(__fp - 0x448)) + 4,(char **)0x0,10);
                                lp->m_pss = lp->m_pss + lVar33;
                              }
                              else if (((*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 0)) == 0x70617753) && ((*(char (*) [1024])(__fp - 0x448))[4] == ':')) {
                                lVar33 = __isoc23_strtol((*(char (*) [1024])(__fp - 0x448)) + 5,(char **)0x0,10);
                                lp->m_swap = lp->m_swap + lVar33;
                              }
                              else if (CONCAT44((*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 4)),(*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 0))) == 0x3a73735070617753) {
                                lVar33 = __isoc23_strtol((*(char (*) [1024])(__fp - 0x448)) + 8,(char **)0x0,10);
                                lp->m_psswp = lp->m_psswp + lVar33;
                              }
                              goto LAB_00146a1b;
                            }
                            fclose(pFVar36);
                          }
                        }
                      }
                      if (wVar28 == 1) {
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
                                     (lp,parentFd_00,lhost,_Var21,(*(char (*) [129])(__fp - 0x568)),(size_t)va3);
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
                       Unresolved local var: int i@[???]
                       Unresolved local var: uint __major@[???] */
                    /* Unresolved local var: uint __minor@[???] */
                      uVar26 = (uint)(uVar31 >> 0x20) & 0xfffff000 | (uint)(uVar31 >> 8) & 0xfff;
                      va1 = (uint)((uVar31 >> 0x14) << 8) | (uint)uVar31 & 0xff;
                    /* Unresolved local var: uint idx@[???]
                       Unresolved local var: int err@[???] */
                      if (pTVar50->path != (char *)0x0) {
                    /* Unresolved local var: int err@[???] */
                        do {
                          if (uVar26 < pTVar50->major) break;
                          if (uVar26 <= pTVar50->major) {
                            if (va1 < pTVar50->minorFrom) break;
                            if (va1 <= pTVar50->minorTo) {
                              va1_00 = va1 - pTVar50->minorFrom;
                              do {
                                xAsprintf(&(*(char *(*))(__fp - 0x5a8)),((char *)(long)&s__s__d_0014a17b /* "%s/%d" */),pTVar50->path,va1_00);
                                iVar25 = stat((*(char *(*))(__fp - 0x5a8)),(stat_2 *)(*(char (*) [20])(__fp - 0x4d8)));
                                uVar46 = (uint)((*(ulong (*))(__fp - 0x4b0)) >> 8);
                                uVar27 = (uint)((*(ulong (*))(__fp - 0x4b0)) >> 0x20);
                    /* Unresolved local var: uint __major@[???] */
                    /* Unresolved local var: uint __minor@[???] */
                                if (((iVar25 == 0) &&
                                    (uVar26 == (uVar27 & 0xfffff000 | uVar46 & 0xfff))) &&
                                   (pcVar35 = (*(char *(*))(__fp - 0x5a8)),
                                   va1 == ((uint)(((*(ulong (*))(__fp - 0x4b0)) >> 0x14) << 8) | (uint)(*(ulong (*))(__fp - 0x4b0)) & 0xff
                                          ))) goto LAB_001455a5;
                                free((*(char *(*))(__fp - 0x5a8)));
                                xAsprintf(&(*(char *(*))(__fp - 0x5a8)),((char *)(long)&DAT_00148c18 /* "%s%d" */),pTVar50->path,va1_00);
                                iVar25 = stat((*(char *(*))(__fp - 0x5a8)),(stat_2 *)(*(char (*) [20])(__fp - 0x4d8)));
                    /* Unresolved local var: uint __major@[???] */
                    /* Unresolved local var: uint __minor@[???] */
                                if (((iVar25 == 0) &&
                                    (uVar26 == (uVar27 & 0xfffff000 | uVar46 & 0xfff))) &&
                                   (pcVar35 = (*(char *(*))(__fp - 0x5a8)),
                                   va1 == ((uint)(((*(ulong (*))(__fp - 0x4b0)) >> 0x14) << 8) | (uint)(*(ulong (*))(__fp - 0x4b0)) & 0xff
                                          ))) goto LAB_001455a5;
                                free((*(char *(*))(__fp - 0x5a8)));
                                bVar54 = va1 != va1_00;
                                va1_00 = va1;
                              } while (bVar54);
                              iVar25 = stat(pTVar50->path,(stat_2 *)(*(char (*) [20])(__fp - 0x4d8)));
                              if ((iVar25 == 0) && (uVar31 == (*(ulong (*))(__fp - 0x4b0)))) {
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
                      xAsprintf(&(*(char *(*))(__fp - 0x5a8)),((char *)(long)&s__dev__u__u_0014a181 /* "/dev/%u:%u" */),uVar26,va1);
                      pcVar35 = (*(char *(*))(__fp - 0x5a8));
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
                    /* Unresolved local var: int statok@[???] */
                    iVar25 = fstat(parentFd_00,(stat_2 *)(*(char (*) [1024])(__fp - 0x448)));
                    if (iVar25 != -1) {
                      if ((lp->super).st_uid != (*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 28))) {
                        (lp->super).st_uid = (*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 28));
                        pcVar35 = UsersTable_getRef((lhost->super).usersTable,(*(uint *)((char *)&(*(char (*) [1024])(__fp - 0x448)) + 28)));
                        (lp->super).user = pcVar35;
                      }
                      _Var21 = LinuxProcessTable_readStatusFile(lp,parentFd_00);
                      if (_Var21) {
                        if ((*(LinuxProcess *(*))(__fp - 0x608)) == (LinuxProcess *)0x0) {
                          if ((pSVar12->flags & 0x200) != 0) {
                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: _Bool foundEnvID@[???]
                       Unresolved local var: _Bool foundVPid@[???] */
                            iVar25 = access(((char *)(long)&s__proc_vz_0014a18c /* "/proc/vz" */),4);
                    /* Unresolved local var: int fd@[???]
                       Unresolved local var: FILE * stream@[???] */
                            if ((iVar25 == 0) &&
                               (iVar25 = openat(parentFd_00,((char *)(long)&s_status_00149730 /* "status" */),0), -1 < iVar25)) {
                              pFVar36 = fdopen(iVar25,((char *)(long)&DAT_00147760 /* "r" */));
                              if (pFVar36 != (FILE_2 *)0x0) {
                                bVar19 = false;
                    /* Unresolved local var: char * name_value_sep@[???]
                       Unresolved local var: int field@[DW_OP_reg1(RDX)]
                       Unresolved local var: char * value_end@[???] */
                                bVar54 = false;
LAB_0014622f:
                    /* Unresolved local var: size_t sz@[???] */
                                pcVar35 = fgets((*(char (*) [1024])(__fp - 0x448)),0x100,pFVar36);
                                if (pcVar35 != (char *)0x0) {
                                  pcVar35 = strchr((*(char (*) [1024])(__fp - 0x448)),10);
                                  if (pcVar35 == (char *)0x0) {
                                    do {
                    /* Unresolved local var: size_t sz@[???] */
                                      pcVar35 = fgets((*(char (*) [1024])(__fp - 0x448)),0x100,pFVar36);
                                      if (pcVar35 == (char *)0x0) break;
                                      pcVar35 = strchr((*(char (*) [1024])(__fp - 0x448)),10);
                                    } while (pcVar35 == (char *)0x0);
                                  }
                                  else {
                                    pcVar35 = strchr((*(char (*) [1024])(__fp - 0x448)),0x3a);
                                    if (pcVar35 != (char *)0x0) {
                                      sVar40 = (long)pcVar35 - (long)(*(char (*) [1024])(__fp - 0x448));
                                      iVar25 = strncasecmp((*(char (*) [1024])(__fp - 0x448)),((char *)(long)&s_envID_0014a195 /* "envID" */),sVar40);
                                      if (iVar25 == 0) {
                                        iVar25 = 1;
                                      }
                                      else {
                                        iVar29 = strncasecmp((*(char (*) [1024])(__fp - 0x448)),((char *)(long)&DAT_0014a19b /* "VPid" */),sVar40);
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
                              sVar40 = strlen((*(char (*) [129])(__fp - 0x568)));
                              Process_updateCmdline((Process *)lp,(*(char (*) [129])(__fp - 0x568)),0,(int)sVar40)
                              ;
                            }
                          }
                          else {
                            Process_updateCmdline((Process *)lp,(char *)0x0,0,0);
                          }
                    /* Unresolved local var: time_t now@[???] */
                          lVar33 = (((lp->super).super.host)->realtime).tv_sec;
                          localtime_r(&(lp->super).starttime_ctime,(tm_2 *)&(*(char *(*))(__fp - 0x5a8)));
                          lVar37 = (lp->super).starttime_ctime;
                          pcVar35 = ((char *)(long)&DAT_0014876e /* "%R " */);
                          if ((lVar37 < lVar33 + -0x1517f) &&
                             (pcVar35 = ((char *)(long)&DAT_00148778 /* " %Y " */), lVar33 + -0x1dfe1ff <= lVar37)) {
                            pcVar35 = ((char *)(long)&s__b_d_00148772 /* "%b%d " */);
                          }
                          strftime((lp->super).starttime_show,7,pcVar35,(tm_2 *)&(*(char *(*))(__fp - 0x5a8)));
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
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
                              sVar40 = strlen((*(char (*) [129])(__fp - 0x568)));
                              Process_updateCmdline((Process *)lp,(*(char (*) [129])(__fp - 0x568)),0,(int)sVar40)
                              ;
                            }
                          }
                          else {
                            Process_updateCmdline((Process *)lp,(char *)0x0,0,0);
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
                                wVar28 = genl_ctrl_resolve(this->netlink_socket,((char *)(long)&s_TASKSTATS_0014a1a0 /* "TASKSTATS" */));
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
                       Unresolved local var: int ok@[???] */
                          lp->autogroup_id = -1;
                    /* Unresolved local var: int fd@[???] */
                          wVar28 = openat(parentFd_00,((char *)(long)(__sec_rodata + 0x2b96) /* "autogroup" */),0);
                          if (wVar28 < 0) {
                    /* Unresolved local var: int fd@[???] */
                            piVar44 = __errno_location();
                            lVar33 = (long)-*piVar44;
                          }
                          else {
                            lVar33 = readfd_internal(wVar28,(stat_2 *)(*(char (*) [1024])(__fp - 0x448)),0x40);
                          }
                          if ((-1 < lVar33) &&
                             (iVar25 = __isoc23_sscanf((*(char (*) [1024])(__fp - 0x448)),((char *)(long)&s__autogroup__ld_nice__d_00149ba3 /* "/autogroup-%ld nice %d" */),
                                                       (tm_2 *)&(*(char *(*))(__fp - 0x5a8)),&(*(long (*))(__fp - 0x5b0))), iVar25 == 2)) {
                            lp->autogroup_id = (long)(*(char *(*))(__fp - 0x5a8));
                            lp->autogroup_nice = (int)(*(long (*))(__fp - 0x5b0));
                          }
                          uVar26 = pSVar12->flags;
                        }
                        if ((uVar26 & 4) != 0) {
                          wVar28 = sched_getscheduler((lp->super).super.id);
                          (lp->super).scheduling_policy = wVar28;
                        }
                        if ((((lp->super).cmdline == (char *)0x0) && ((*(char (*) [129])(__fp - 0x568))[0] != '\0')) &&
                           (((lp->super).state == ZOMBIE ||
                            (((lp->super).isKernelThread != false ||
                             (pSVar11->showThreadNames != false)))))) {
                          sVar40 = strlen((*(char (*) [129])(__fp - 0x568)));
                          Process_updateCmdline((Process *)lp,(*(char (*) [129])(__fp - 0x568)),0,(int)sVar40);
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
            if ((*(LinuxProcess *(*))(__fp - 0x608)) == (LinuxProcess *)0x0) {
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


/* ProcessTable_goThroughEntries @ 0x146c70 */

void ProcessTable_goThroughEntries(LinuxProcessTable_ *super)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  LinuxMachine_2 *lhost;
  long lVar1;
  int fd;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  _Bool _Var4;

  _Var4 = false;
  lhost = (LinuxMachine_2 *)(super->super).super.host;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((((lhost->super).settings)->ss->flags & 0x80000) != 0) {
                    /* Unresolved local var: int fd@[???] */
    fd = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
    if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
      piVar3 = __errno_location();
      lVar2 = (long)-*piVar3;
    }
    else {
      lVar2 = readfd_internal(fd,(*(char (*) [16])(__fp - 0x38)),0x10);
    }
    _Var4 = false;
    if (-1 < lVar2) {
      _Var4 = (*(char (*) [16])(__fp - 0x38))[0] == '1';
    }
  }
  super->haveAutogroup = _Var4;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    LinuxProcessTable_recurseProcTree(super,-100,lhost,((char *)(long)&s__proc_00149a78 /* "/proc" */),(Process_2 *)0x0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

