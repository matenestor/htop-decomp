#include "htop.h"

/* Process_delete @ 0x138950 */

void Process_delete(LinuxProcess_ *cast)

{
  free((cast->super).cmdline);
  free((cast->super).procComm);
  free((cast->super).procExe);
  free((cast->super).procCwd);
  free((cast->super).mergedCommand.str);
  free((cast->super).tty_name);
  free(cast->container_short);
  free(cast->cgroup_short);
  free(cast->cgroup);
  free(cast->ctid);
  free(cast->secattr);
  free(cast);
  return;
}


/* LinuxProcess_updateIOPriority @ 0x13b240 */

IOPriority LinuxProcess_updateIOPriority(LinuxProcess_ *p)

{
  long lVar1;

  lVar1 = syscall(0xfc,1,(ulong)(uint)(p->super).super.id);
  p->ioPriority = (IOPriority)lVar1;
  return (IOPriority)lVar1;
}


/* LinuxProcess_rowSetIOPriority @ 0x13b270 */

_Bool LinuxProcess_rowSetIOPriority(Process_ *super,Arg ioprio)

{
  long lVar1;

  syscall(0xfb,1,(ulong)(uint)(super->super).id,(ulong)ioprio.v & 0xffffffff);
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
  lVar1 = syscall(0xfc,1,(ulong)(uint)(super->super).id);
  *(int *)&super[1].super.super.klass = (int)lVar1;
  return ioprio.i == (int)lVar1;
}


/* LinuxProcess_isAutogroupEnabled @ 0x13b2c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool LinuxProcess_isAutogroupEnabled(void)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  long lVar1;
  int fd;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int fd@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  fd = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
    piVar3 = __errno_location();
    lVar2 = (long)-*piVar3;
  }
  else {
    lVar2 = readfd_internal(fd,(*(char (*) [16])(__fp - 0x28)),0x10);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return -1 < lVar2 && (*(char (*) [16])(__fp - 0x28))[0] == '1';
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcess_changeAutogroupPriorityBy @ 0x13dc70 */

_Bool LinuxProcess_changeAutogroupPriorityBy(Process_3 *p,Arg delta)

{
  undefined1 __frame[0x1d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x198;
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  bool bVar3;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: pid_t pid@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: int ok@[???]
                       Unresolved local var: _Bool success@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf((*(char (*) [256])(__fp - 0x138)),0x100,((char *)(long)&s__proc__d_autogroup_00149b8d /* "/proc/%d/autogroup" */),(int)p);
  __stream = fopen((*(char (*) [256])(__fp - 0x138)),((char *)(long)&DAT_00149ba0 /* "r+" */));
  if (__stream == (FILE_2 *)0x0) {
    bVar3 = false;
    goto LAB_0013dcf9;
  }
  iVar2 = __isoc23_fscanf(__stream,((char *)(long)&s__autogroup__ld_nice__d_00149ba3 /* "/autogroup-%ld (*(int (*))(__fp - 0x144)) %d" */),&(*(long (*))(__fp - 0x140)),&(*(int (*))(__fp - 0x144)));
  if (iVar2 == 2) {
    iVar2 = fseek(__stream,0,0);
    if (iVar2 != 0) goto LAB_0013dcee;
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0x100,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(*(int (*))(__fp - 0x144)) + delta.i);
    iVar2 = fputs((*(char (*) [256])(__fp - 0x138)),__stream);
    bVar3 = 0 < iVar2;
  }
  else {
LAB_0013dcee:
    bVar3 = false;
  }
  fclose(__stream);
LAB_0013dcf9:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcess_rowChangeAutogroupPriorityBy @ 0x13dd70 */

_Bool LinuxProcess_rowChangeAutogroupPriorityBy(Process_ *super,Arg delta)

{
  _Bool _Var1;

  _Var1 = LinuxProcess_changeAutogroupPriorityBy((Process_3 *)(ulong)(uint)(super->super).id,delta);
  return _Var1;
}


/* LinuxProcess_new @ 0x13e8b0 */

Process_3 * LinuxProcess_new(Machine_3 *host)

{
  Process_3 *pPVar1;

                    /* Unresolved local var: void * data@[???] */
  pPVar1 = calloc(1,0x348);
  if (pPVar1 != (Process_3 *)0x0) {
    (pPVar1->super).host = host;
    (pPVar1->super).tag = false;
    (pPVar1->super).show = true;
    (pPVar1->super).wasShown = false;
    (pPVar1->super).showChildren = true;
    (pPVar1->super).super.klass = (ObjectClass *)&LinuxProcess_class;
    (pPVar1->super).updated = false;
    pPVar1->cmdlineBasenameEnd = -1;
    pPVar1->st_uid = 0xffffffff;
    return pPVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* LinuxProcess_rowWriteField @ 0x142f70 */

void LinuxProcess_rowWriteField(LinuxProcess_ *super,RichString *str,ProcessField field)

{
  undefined1 __frame[0x1c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x188;
  double dVar1;
  _Bool coloring;
  Machine__4 *pMVar2;
  long lVar3;
  int iVar4;
  double rate;
  uint uVar5;
  char *fmt;
  char *pcVar6;
  long in_FS_OFFSET = (long)__fake_fs;
  float val;

  pMVar2 = (super->super).super.host;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  coloring = pMVar2->settings->highlightMegabytes;
  (*(char (*) [256])(__fp - 0x138))[0xff] = '\0';
  (*(int (*))(__fp - 0x13c)) = CRT_colors[1];
  switch(field) {
  case 0xb:
    Row_printCount(str,super->cminflt,coloring);
    break;
  default:
    Process_writeField((Process *)super,str,field);
    break;
  case 0xd:
    Row_printCount(str,super->cmajflt,coloring);
    break;
  case 0xe:
    Row_printTime(str,super->utime,coloring);
    break;
  case 0xf:
    Row_printTime(str,super->stime,coloring);
    break;
  case 0x10:
    Row_printTime(str,super->cutime,coloring);
    break;
  case 0x11:
    Row_printTime(str,super->cstime,coloring);
    break;
  case 0x29:
    Row_printBytes(str,(long)(int)pMVar2[1].realtime.tv_sec * super->m_share,coloring);
    break;
  case 0x2a:
    Row_printBytes(str,(long)(int)pMVar2[1].realtime.tv_sec * super->m_trs,coloring);
    break;
  case 0x2b:
    Row_printBytes(str,(long)(int)pMVar2[1].realtime.tv_sec * super->m_drs,coloring);
    break;
  case 0x2c:
    if (super->m_lrs != 0) {
      Row_printBytes(str,(long)(int)pMVar2[1].realtime.tv_sec * super->m_lrs,coloring);
      break;
    }
    (*(int (*))(__fp - 0x13c)) = CRT_colors[0x1e];
    pcVar6 = ((char *)(long)&DAT_00149092 /* "  N/A " */);
    goto LAB_001432b8;
  case 100:
    pcVar6 = super->ctid;
    fmt = ((char *)(long)&s___8s_001489c7 /* "%-8s " */);
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    goto LAB_00143171;
  case 0x65:
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0xff,((char *)(long)&DAT_001489a2 /* "%*d " */),Row_pidDigits,super->vpid);
    goto LAB_00143070;
  case 0x66:
    uVar5 = super->vxid;
    pcVar6 = ((char *)(long)&DAT_00149063 /* "%5u " */);
    goto LAB_001432e6;
  case 0x67:
    Row_printBytes(str,super->io_rchar,coloring);
    break;
  case 0x68:
    Row_printBytes(str,super->io_wchar,coloring);
    break;
  case 0x69:
    Row_printCount(str,super->io_syscr,coloring);
    break;
  case 0x6a:
    Row_printCount(str,super->io_syscw,coloring);
    break;
  case 0x6b:
    Row_printBytes(str,super->io_read_bytes,coloring);
    break;
  case 0x6c:
    Row_printBytes(str,super->io_write_bytes,coloring);
    break;
  case 0x6d:
    Row_printBytes(str,super->io_cancelled_write_bytes,coloring);
    break;
  case 0x6e:
    Row_printRate(str,super->io_rate_read_bps,coloring);
    break;
  case 0x6f:
    Row_printRate(str,super->io_rate_write_bps,coloring);
    break;
  case 0x70:
                    /* Unresolved local var: double totalRate@[???] */
    rate = super->io_rate_read_bps;
    dVar1 = super->io_rate_write_bps;
    if (rate < 0.0) {
      rate = dVar1;
      if (dVar1 < 0.0) {
        rate = NAN;
      }
    }
    else if (0.0 <= dVar1) {
      rate = rate + dVar1;
    }
    Row_printRate(str,rate,coloring);
    break;
  case 0x71:
    pcVar6 = super->cgroup;
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)(long)&DAT_001474de /* "N/A" */);
    }
    uVar5 = (uint)Row_fieldWidths[0x71];
    goto LAB_00143048;
  case 0x72:
    uVar5 = super->oom;
    pcVar6 = ((char *)(long)&DAT_0014a047 /* "%4u " */);
    goto LAB_001432e6;
  case 0x73:
                    /* Unresolved local var: int klass@[???] */
    uVar5 = super->ioPriority;
    iVar4 = (int)uVar5 >> 0xd;
    if (iVar4 == 0) {
      pcVar6 = ((char *)(long)&s_B_1d_0014a04c /* "B%1d " */);
      uVar5 = ((int)(super->super).nice + 0x14) / 5;
    }
    else if (iVar4 == 2) {
      uVar5 = uVar5 & 0x1fff;
      pcVar6 = ((char *)(long)&s_B_1d_0014a04c /* "B%1d " */);
    }
    else {
      if (iVar4 != 1) {
        pcVar6 = ((char *)(long)&DAT_0014a05c /* "?? " */);
        if (iVar4 == 3) {
          (*(int (*))(__fp - 0x13c)) = CRT_colors[0x27];
          pcVar6 = ((char *)(long)&DAT_0014a058 /* "id " */);
        }
        goto LAB_001432b8;
      }
      (*(int (*))(__fp - 0x13c)) = CRT_colors[0x26];
      uVar5 = uVar5 & 0x1fff;
      pcVar6 = ((char *)(long)&s_R_1d_0014a052 /* "R%1d " */);
    }
LAB_001432e6:
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0xff,pcVar6,uVar5);
    goto LAB_00143070;
  case 0x74:
    val = super->cpu_delay_percent;
    goto LAB_00143217;
  case 0x75:
    val = super->blkio_delay_percent;
    goto LAB_00143217;
  case 0x76:
    val = super->swapin_delay_percent;
LAB_00143217:
    Row_printPercentage(val,(*(char (*) [256])(__fp - 0x138)),0xff,'\x05',&(*(int (*))(__fp - 0x13c)));
    goto LAB_00143070;
  case 0x77:
    Row_printKBytes(str,super->m_pss,coloring);
    break;
  case 0x78:
    Row_printKBytes(str,super->m_swap,coloring);
    break;
  case 0x79:
    Row_printKBytes(str,super->m_psswp,coloring);
    break;
  case 0x7a:
    pcVar6 = (char *)super->ctxt_diff;
    if ((char *)0x3e8 < pcVar6) {
      (*(int (*))(__fp - 0x13c)) = (*(int (*))(__fp - 0x13c)) | 0x200000;
    }
    fmt = ((char *)(long)&s__5lu_0014a060 /* "%5lu " */);
LAB_00143171:
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0xff,fmt,(long)pcVar6);
    goto LAB_00143070;
  case 0x7b:
    pcVar6 = super->secattr;
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)(long)&DAT_001474de /* "N/A" */);
    }
    __snprintf_chk((*(char (*) [256])(__fp - 0x138)),0xff,2,0x100,((char *)(long)&s______s_0014884c /* "%-*.*s " */),(uint)Row_fieldWidths[0x7b],
                   (uint)Row_fieldWidths[0x7b],pcVar6);
    goto LAB_00143070;
  case 0x7f:
    pcVar6 = (char *)super->autogroup_id;
    if (pcVar6 != (char *)0xffffffffffffffff) {
      fmt = ((char *)(long)&s__4ld_0014899c /* "%4ld " */);
      goto LAB_00143171;
    }
    (*(int (*))(__fp - 0x13c)) = CRT_colors[0x1e];
    pcVar6 = ((char *)(long)&DAT_00149093 /* " N/A " */);
LAB_001432b8:
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0xff,pcVar6);
    goto LAB_00143070;
  case 0x80:
    if (super->autogroup_id == -1) {
      (*(int (*))(__fp - 0x13c)) = CRT_colors[0x1e];
      pcVar6 = ((char *)(long)&DAT_00149094 /* "N/A " */);
      goto LAB_001432b8;
    }
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0xff,((char *)(long)&DAT_001489ac /* "%3d " */),super->autogroup_nice);
    if (super->autogroup_nice < 0) {
      (*(int (*))(__fp - 0x13c)) = CRT_colors[0x26];
    }
    else if (super->autogroup_nice == 0) {
      (*(int (*))(__fp - 0x13c)) = CRT_colors[0x1e];
    }
    else {
      (*(int (*))(__fp - 0x13c)) = CRT_colors[0x27];
    }
    goto LAB_00143070;
  case 0x81:
    pcVar6 = super->cgroup_short;
    if ((pcVar6 == (char *)0x0) && (pcVar6 = super->cgroup, pcVar6 == (char *)0x0)) {
      pcVar6 = ((char *)(long)&DAT_001474de /* "N/A" */);
    }
    uVar5 = (uint)Row_fieldWidths[0x81];
    goto LAB_00143048;
  case 0x82:
    pcVar6 = super->container_short;
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)(long)&DAT_001474de /* "N/A" */);
    }
    uVar5 = (uint)Row_fieldWidths[0x82];
LAB_00143048:
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0xff,((char *)(long)&s______s_0014884c /* "%-*.*s " */),uVar5,uVar5,pcVar6);
LAB_00143070:
    RichString_appendAscii(str,(*(int (*))(__fp - 0x13c)),(*(char (*) [256])(__fp - 0x138)));
    break;
  case 0x83:
    Row_printKBytes(str,super->m_priv,coloring);
  }
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LinuxProcess_compareByKey @ 0x1436e0 */

int LinuxProcess_compareByKey(LinuxProcess_ *v1,LinuxProcess_ *v2,ProcessField key)

{
  double dVar1;
  int wVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  int wVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  double dVar17;
  double dVar18;

  switch(key) {
  case 0xe:
    uVar10 = v1->utime;
    uVar11 = v2->utime;
    break;
  case 0xf:
    uVar10 = v1->stime;
    uVar11 = v2->stime;
    break;
  case 0x10:
    uVar10 = v1->cutime;
    uVar11 = v2->cutime;
    break;
  case 0x11:
    uVar10 = v1->cstime;
    uVar11 = v2->cstime;
    break;
  default:
    wVar7 = Process_compareByKey_Base(&v1->super,&v2->super,key);
    return wVar7;
  case 0x29:
    lVar5 = v2->m_share;
    lVar6 = v1->m_share;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x2a:
    lVar5 = v2->m_trs;
    lVar6 = v1->m_trs;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x2b:
    lVar5 = v2->m_drs;
    lVar6 = v1->m_drs;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x2c:
    lVar5 = v2->m_lrs;
    lVar6 = v1->m_lrs;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 100:
    pcVar12 = v2->ctid;
    pcVar13 = v1->ctid;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar13,pcVar12);
    return wVar7;
  case 0x65:
    iVar3 = v2->vpid;
    iVar4 = v1->vpid;
    bVar16 = SBORROW4(iVar4,iVar3);
    bVar15 = iVar4 - iVar3 < 0;
    bVar14 = iVar4 == iVar3;
    goto LAB_00143713;
  case 0x66:
    uVar9 = v1->vxid;
    uVar8 = v2->vxid;
    goto LAB_00143910;
  case 0x67:
    uVar10 = v1->io_rchar;
    uVar11 = v2->io_rchar;
    break;
  case 0x68:
    uVar10 = v1->io_wchar;
    uVar11 = v2->io_wchar;
    break;
  case 0x69:
    uVar10 = v1->io_syscr;
    uVar11 = v2->io_syscr;
    break;
  case 0x6a:
    uVar10 = v1->io_syscw;
    uVar11 = v2->io_syscw;
    break;
  case 0x6b:
    uVar10 = v1->io_read_bytes;
    uVar11 = v2->io_read_bytes;
    break;
  case 0x6c:
    uVar10 = v1->io_write_bytes;
    uVar11 = v2->io_write_bytes;
    break;
  case 0x6d:
    uVar10 = v1->io_cancelled_write_bytes;
    uVar11 = v2->io_cancelled_write_bytes;
    break;
  case 0x6e:
    dVar17 = v2->io_rate_read_bps;
    dVar18 = v1->io_rate_read_bps;
    goto LAB_00143826;
  case 0x6f:
    dVar17 = v2->io_rate_write_bps;
    dVar18 = v1->io_rate_write_bps;
    goto LAB_00143826;
  case 0x70:
                    /* Unresolved local var: double totalRate@[???] */
    dVar17 = v2->io_rate_read_bps;
    dVar18 = v2->io_rate_write_bps;
    if (dVar17 < 0.0) {
      dVar17 = dVar18;
      if (dVar18 < 0.0) {
        dVar17 = NAN;
      }
    }
    else if (0.0 <= dVar18) {
      dVar17 = dVar17 + dVar18;
    }
                    /* Unresolved local var: double totalRate@[???] */
    dVar18 = v1->io_rate_read_bps;
    dVar1 = v1->io_rate_write_bps;
    if (dVar18 < 0.0) {
      dVar18 = dVar1;
      if (dVar1 < 0.0) {
        uVar9 = 0;
        goto LAB_00143849;
      }
    }
    else if (0.0 <= dVar1) {
      dVar18 = dVar18 + dVar1;
    }
                    /* Unresolved local var: int result@[???] */
    wVar7 = (uint)(dVar17 < dVar18) - (uint)(dVar18 < dVar17);
    if (wVar7 != 0) {
      return wVar7;
    }
    uVar9 = 1;
    goto LAB_00143849;
  case 0x71:
    pcVar12 = v2->cgroup;
    pcVar13 = v1->cgroup;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar13,pcVar12);
    return wVar7;
  case 0x72:
    uVar9 = v1->oom;
    uVar8 = v2->oom;
LAB_00143910:
    return (uint)(uVar8 < uVar9) - (uint)(uVar9 < uVar8);
  case 0x73:
    uVar9 = v1->ioPriority;
    if (uVar9 >> 0xd == 0) {
      uVar9 = (uint)(((v1->super).nice + 0x14) / 5) | 0x4000;
    }
    uVar8 = v2->ioPriority;
    if (uVar8 >> 0xd == 0) {
      uVar8 = (uint)(((v2->super).nice + 0x14) / 5) | 0x4000;
    }
    return (uint)((int)uVar8 < (int)uVar9) - (uint)((int)uVar9 < (int)uVar8);
  case 0x74:
    dVar17 = (double)v2->cpu_delay_percent;
    dVar18 = (double)v1->cpu_delay_percent;
    goto LAB_00143826;
  case 0x75:
    dVar17 = (double)v2->blkio_delay_percent;
    dVar18 = (double)v1->blkio_delay_percent;
    goto LAB_00143826;
  case 0x76:
    dVar17 = (double)v2->swapin_delay_percent;
    dVar18 = (double)v1->swapin_delay_percent;
LAB_00143826:
                    /* Unresolved local var: int result@[???] */
    wVar7 = (uint)(dVar17 < dVar18) - (uint)(dVar18 < dVar17);
    if (wVar7 != 0) {
      return wVar7;
    }
    uVar9 = (uint)!NAN(dVar18);
LAB_00143849:
    return uVar9 - (!NAN(dVar17) && !NAN(dVar17));
  case 0x77:
    lVar5 = v2->m_pss;
    lVar6 = v1->m_pss;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x78:
    lVar5 = v2->m_swap;
    lVar6 = v1->m_swap;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x79:
    lVar5 = v2->m_psswp;
    lVar6 = v1->m_psswp;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x7a:
    uVar10 = v1->ctxt_diff;
    uVar11 = v2->ctxt_diff;
    break;
  case 0x7b:
    pcVar12 = v2->secattr;
    pcVar13 = v1->secattr;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar13,pcVar12);
    return wVar7;
  case 0x7f:
    lVar5 = v2->autogroup_id;
    lVar6 = v1->autogroup_id;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
    goto LAB_00143713;
  case 0x80:
    wVar7 = v2->autogroup_nice;
    wVar2 = v1->autogroup_nice;
    bVar16 = SBORROW4(wVar2,wVar7);
    bVar15 = wVar2 - wVar7 < 0;
    bVar14 = wVar2 == wVar7;
    goto LAB_00143713;
  case 0x81:
    pcVar12 = v2->cgroup_short;
    pcVar13 = v1->cgroup_short;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar13,pcVar12);
    return wVar7;
  case 0x82:
    pcVar12 = v2->container_short;
    pcVar13 = v1->container_short;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar13,pcVar12);
    return wVar7;
  case 0x83:
    lVar5 = v2->m_priv;
    lVar6 = v1->m_priv;
    bVar16 = SBORROW8(lVar6,lVar5);
    bVar15 = lVar6 - lVar5 < 0;
    bVar14 = lVar6 == lVar5;
LAB_00143713:
    return (uint)(!bVar14 && bVar16 == bVar15) - (uint)(bVar16 != bVar15);
  }
  return (uint)(uVar11 < uVar10) - (uint)(uVar10 < uVar11);
}

