/* LinuxProcess_rowWriteField @ 00142f70 size 1881 */

void LinuxProcess_rowWriteField(LinuxProcess_ *super,RichString *str,ProcessField field)

{
  double dVar1;
  _Bool coloring;
  Machine__4 *pMVar2;
  long lVar3;
  int iVar4;
  double rate;
  uint uVar5;
  char *fmt;
  char *pcVar6;
  long in_FS_OFFSET;
  float val;
  wchar_t attr;
  char buffer [256];

  pMVar2 = (super->super).super.host;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  coloring = pMVar2->settings->highlightMegabytes;
  buffer[0xff] = '\0';
  attr = CRT_colors[1];
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
    attr = CRT_colors[0x1e];
    pcVar6 = ((char *)0x149092 /* "  N/A " */);
    goto LAB_001432b8;
  case 100:
    pcVar6 = super->ctid;
    fmt = ((char *)0x1489c7 /* "%-8s " */);
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)0x149c0c /* "" */);
    }
    goto LAB_00143171;
  case 0x65:
    xSnprintf(buffer,0xff,((char *)0x1489a2 /* "%*d " */),Row_pidDigits,super->vpid);
    goto LAB_00143070;
  case 0x66:
    uVar5 = super->vxid;
    pcVar6 = ((char *)0x149063 /* "%5u " */);
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
      pcVar6 = ((char *)0x1474de /* "N/A" */);
    }
    uVar5 = (uint)Row_fieldWidths[0x71];
    goto LAB_00143048;
  case 0x72:
    uVar5 = super->oom;
    pcVar6 = ((char *)0x14a047 /* "%4u " */);
    goto LAB_001432e6;
  case 0x73:
                    /* Unresolved local var: wchar_t klass@[???] */
    uVar5 = super->ioPriority;
    iVar4 = (int)uVar5 >> 0xd;
    if (iVar4 == 0) {
      pcVar6 = ((char *)0x14a04c /* "B%1d " */);
      uVar5 = ((int)(super->super).nice + 0x14) / 5;
    }
    else if (iVar4 == 2) {
      uVar5 = uVar5 & 0x1fff;
      pcVar6 = ((char *)0x14a04c /* "B%1d " */);
    }
    else {
      if (iVar4 != 1) {
        pcVar6 = ((char *)0x14a05c /* "?? " */);
        if (iVar4 == 3) {
          attr = CRT_colors[0x27];
          pcVar6 = ((char *)0x14a058 /* "id " */);
        }
        goto LAB_001432b8;
      }
      attr = CRT_colors[0x26];
      uVar5 = uVar5 & 0x1fff;
      pcVar6 = ((char *)0x14a052 /* "R%1d " */);
    }
LAB_001432e6:
    xSnprintf(buffer,0xff,pcVar6,uVar5);
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
    Row_printPercentage(val,buffer,0xff,'\x05',&attr);
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
      attr = attr | 0x200000;
    }
    fmt = ((char *)0x14a060 /* "%5lu " */);
LAB_00143171:
    xSnprintf(buffer,0xff,fmt,(long)pcVar6);
    goto LAB_00143070;
  case 0x7b:
    pcVar6 = super->secattr;
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)0x1474de /* "N/A" */);
    }
    __snprintf_chk(buffer,0xff,2,0x100,((char *)0x14884c /* "%-*.*s " */),(uint)Row_fieldWidths[0x7b],
                   (uint)Row_fieldWidths[0x7b],pcVar6);
    goto LAB_00143070;
  case 0x7f:
    pcVar6 = (char *)super->autogroup_id;
    if (pcVar6 != (char *)0xffffffffffffffff) {
      fmt = ((char *)0x14899c /* "%4ld " */);
      goto LAB_00143171;
    }
    attr = CRT_colors[0x1e];
    pcVar6 = ((char *)0x149093 /* " N/A " */);
LAB_001432b8:
    xSnprintf(buffer,0xff,pcVar6);
    goto LAB_00143070;
  case 0x80:
    if (super->autogroup_id == -1) {
      attr = CRT_colors[0x1e];
      pcVar6 = ((char *)0x149094 /* "N/A " */);
      goto LAB_001432b8;
    }
    xSnprintf(buffer,0xff,((char *)0x1489ac /* "%3d " */),super->autogroup_nice);
    if (super->autogroup_nice < L'\0') {
      attr = CRT_colors[0x26];
    }
    else if (super->autogroup_nice == L'\0') {
      attr = CRT_colors[0x1e];
    }
    else {
      attr = CRT_colors[0x27];
    }
    goto LAB_00143070;
  case 0x81:
    pcVar6 = super->cgroup_short;
    if ((pcVar6 == (char *)0x0) && (pcVar6 = super->cgroup, pcVar6 == (char *)0x0)) {
      pcVar6 = ((char *)0x1474de /* "N/A" */);
    }
    uVar5 = (uint)Row_fieldWidths[0x81];
    goto LAB_00143048;
  case 0x82:
    pcVar6 = super->container_short;
    if (pcVar6 == (char *)0x0) {
      pcVar6 = ((char *)0x1474de /* "N/A" */);
    }
    uVar5 = (uint)Row_fieldWidths[0x82];
LAB_00143048:
    xSnprintf(buffer,0xff,((char *)0x14884c /* "%-*.*s " */),uVar5,uVar5,pcVar6);
LAB_00143070:
    RichString_appendAscii(str,attr,buffer);
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

