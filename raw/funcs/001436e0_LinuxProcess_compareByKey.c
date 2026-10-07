/* LinuxProcess_compareByKey @ 001436e0 size 1177 */

wchar_t LinuxProcess_compareByKey(LinuxProcess_ *v1,LinuxProcess_ *v2,ProcessField key)

{
  double dVar1;
  wchar_t wVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  wchar_t wVar7;
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
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)0x149c0c /* "" */);
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
                    /* Unresolved local var: wchar_t result@[???] */
    wVar7 = (uint)(dVar17 < dVar18) - (uint)(dVar18 < dVar17);
    if (wVar7 != L'\0') {
      return wVar7;
    }
    uVar9 = 1;
    goto LAB_00143849;
  case 0x71:
    pcVar12 = v2->cgroup;
    pcVar13 = v1->cgroup;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)0x149c0c /* "" */);
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
                    /* Unresolved local var: wchar_t result@[???] */
    wVar7 = (uint)(dVar17 < dVar18) - (uint)(dVar18 < dVar17);
    if (wVar7 != L'\0') {
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
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)0x149c0c /* "" */);
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
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)0x149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar13,pcVar12);
    return wVar7;
  case 0x82:
    pcVar12 = v2->container_short;
    pcVar13 = v1->container_short;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar13 == (char *)0x0) {
      pcVar13 = ((char *)0x149c0c /* "" */);
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

