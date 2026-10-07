/* Process_compareByKey_Base @ 001228c0 size 879 */

wchar_t Process_compareByKey_Base(Process_3 *p1,Process_3 *p2,ProcessField key)

{
  float fVar1;
  float fVar2;
  wchar_t wVar3;
  long lVar4;
  long lVar5;
  ProcessState PVar6;
  wchar_t wVar7;
  ulong uVar8;
  ProcessState PVar9;
  ulong uVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;

  switch(key) {
  default:
    goto switchD_001228df_caseD_0;
  case 2:
                    /* Unresolved local var: Settings * settings@[???] */
    if ((((p2->isUserlandThread != false) &&
         (((p2->super).host)->settings->showThreadNames != false)) ||
        (pcVar12 = (p2->mergedCommand).str, pcVar12 == (char *)0x0)) &&
       (pcVar12 = p2->cmdline, pcVar12 == (char *)0x0)) {
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
                    /* Unresolved local var: Settings * settings@[???] */
    if ((((p1->isUserlandThread != false) &&
         (((p1->super).host)->settings->showThreadNames != false)) ||
        (pcVar11 = (p1->mergedCommand).str, pcVar11 == (char *)0x0)) &&
       (pcVar11 = p1->cmdline, pcVar11 == (char *)0x0)) {
      pcVar11 = ((char *)0x149c0c /* "" */);
    }
    goto LAB_001229cf;
  case 3:
    PVar9 = p1->state;
    PVar6 = p2->state;
    goto LAB_00122acc;
  case 4:
    wVar7 = (p2->super).parent;
    wVar3 = (p1->super).parent;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 5:
    wVar7 = p2->pgrp;
    wVar3 = p1->pgrp;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 6:
    wVar7 = p2->session;
    wVar3 = p1->session;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 7:
    pcVar11 = p2->tty_name;
    pcVar12 = p1->tty_name;
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)0x148785 /* "\x7f" */);
    }
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)0x148785 /* "\x7f" */);
    }
    wVar7 = strcmp(pcVar12,pcVar11);
    return wVar7;
  case 8:
    wVar7 = p2->tpgid;
    wVar3 = p1->tpgid;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 10:
    uVar10 = p1->minflt;
    uVar8 = p2->minflt;
    goto LAB_00122a6f;
  case 0xc:
    uVar10 = p1->majflt;
    uVar8 = p2->majflt;
    goto LAB_00122a6f;
  case 0x12:
    lVar4 = p2->priority;
    lVar5 = p1->priority;
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x13:
    lVar4 = p2->nice;
    lVar5 = p1->nice;
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x15:
    wVar7 = (uint)(p2->starttime_ctime < p1->starttime_ctime) -
            (uint)(p1->starttime_ctime < p2->starttime_ctime);
    goto joined_r0x001228ff;
  case 0x26:
    wVar7 = p2->processor;
    wVar3 = p1->processor;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 0x27:
    lVar4 = p2->m_virt;
    lVar5 = p1->m_virt;
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x28:
  case 0x30:
    lVar4 = p2->m_resident;
    lVar5 = p1->m_resident;
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x2e:
    PVar9 = p1->st_uid;
    PVar6 = p2->st_uid;
LAB_00122acc:
    return (uint)(PVar6 < PVar9) - (uint)(PVar9 < PVar6);
  case 0x2f:
  case 0x35:
                    /* Unresolved local var: wchar_t result@[???] */
    fVar1 = p2->percent_cpu;
    fVar2 = p1->percent_cpu;
    wVar7 = (uint)(fVar1 < fVar2) - (uint)(fVar2 < fVar1);
    if (wVar7 != L'\0') {
      return wVar7;
    }
    return (uint)!NAN(fVar2) - (uint)!NAN(fVar1);
  case 0x31:
    pcVar12 = p2->user;
    pcVar11 = p1->user;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)0x149c0c /* "" */);
    }
    goto LAB_001229cf;
  case 0x32:
    uVar10 = p1->time;
    uVar8 = p2->time;
LAB_00122a6f:
    return (uint)(uVar8 < uVar10) - (uint)(uVar10 < uVar8);
  case 0x33:
    lVar4 = p2->nlwp;
    lVar5 = p1->nlwp;
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x34:
    wVar7 = (p2->super).group;
    wVar3 = (p1->super).group;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 0x36:
    wVar7 = (uint)(p1->starttime_ctime < p2->starttime_ctime) -
            (uint)(p2->starttime_ctime < p1->starttime_ctime);
joined_r0x001228ff:
    if (wVar7 != L'\0') {
      return wVar7;
    }
switchD_001228df_caseD_0:
    wVar7 = (p2->super).id;
    wVar3 = (p1->super).id;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 0x37:
    wVar7 = p2->scheduling_policy;
    wVar3 = p1->scheduling_policy;
    bVar15 = SBORROW4(wVar3,wVar7);
    bVar14 = wVar3 - wVar7 < 0;
    bVar13 = wVar3 == wVar7;
    break;
  case 0x7c:
                    /* Unresolved local var: char * comm1@[???]
                       Unresolved local var: char * comm2@[???] */
    pcVar11 = p1->procComm;
    if ((pcVar11 == (char *)0x0) && (pcVar11 = ((char *)0x149c0c /* "" */), p1->isKernelThread != false)) {
      pcVar11 = ((char *)0x14877d /* "KTHREAD" */);
    }
    pcVar12 = p2->procComm;
    if (pcVar12 != (char *)0x0) goto LAB_001229cf;
    goto LAB_001229f0;
  case 0x7d:
                    /* Unresolved local var: char * exe1@[???]
                       Unresolved local var: char * exe2@[???] */
    if (p1->procExe == (char *)0x0) {
      pcVar11 = ((char *)0x149c0c /* "" */);
      if (p1->isKernelThread != false) {
        pcVar11 = ((char *)0x14877d /* "KTHREAD" */);
      }
    }
    else {
      pcVar11 = p1->procExe + p1->procExeBasenameOffset;
    }
    if (p2->procExe != (char *)0x0) {
      pcVar12 = p2->procExe + p2->procExeBasenameOffset;
      goto LAB_001229cf;
    }
LAB_001229f0:
    pcVar12 = ((char *)0x149c0c /* "" */);
    if (p2->isKernelThread != false) {
      pcVar12 = ((char *)0x14877d /* "KTHREAD" */);
    }
LAB_001229cf:
    wVar7 = strcmp(pcVar11,pcVar12);
    return wVar7;
  case 0x7e:
    pcVar11 = p2->procCwd;
    pcVar12 = p1->procCwd;
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)0x149c0c /* "" */);
    }
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)0x149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar12,pcVar11);
    return wVar7;
  }
  return (uint)(!bVar13 && bVar15 == bVar14) - (uint)(bVar15 != bVar14);
}

