/* Process_writeField @ 0012c3e0 size 2363 */

/* DWARF original prototype: void Process_writeField(Process * this, RichString * str, RowField
   field) */

void Process_writeField(Process *this,RichString *str,RowField field)

{
  _Bool coloring;
  Machine_ *pMVar1;
  long lVar2;
  Settings__2 *pSVar3;
  wchar_t *pwVar4;
  int iVar5;
  uid_t va0;
  uint uVar6;
  wchar_t wVar7;
  char *pcVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  ulonglong totalHundredths;
  uint uVar12;
  size_t len;
  wchar_t wVar13;
  long in_FS_OFFSET;
  wchar_t attr;
  char buffer [256];

  pwVar4 = CRT_colors;
  pMVar1 = (this->super).host;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar3 = pMVar1->settings;
  coloring = pSVar3->highlightMegabytes;
  buffer[0xff] = '\0';
  wVar13 = CRT_colors[1];
  wVar7 = Row_pidDigits;
  attr = wVar13;
  switch(field) {
  default:
    pcVar11 = ((char *)0x147411 /* "- " */);
    goto LAB_0012c45e;
  case 1:
    wVar13 = (this->super).id;
    goto LAB_0012c688;
  case 2:
                    /* Unresolved local var: wchar_t baseattr@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: char * buf@[???]
                       Unresolved local var: _Bool lastItem@[???]
                       Unresolved local var: char * draw@[???] */
    wVar13 = CRT_colors[0x25];
    if ((pSVar3->highlightThreads != false) &&
       ((this->isUserlandThread != false || (this->isKernelThread != false)))) {
      attr = CRT_colors[0x2a];
      wVar13 = CRT_colors[0x2b];
    }
    if ((pSVar3->ss->treeView == false) || (uVar6 = (this->super).indent, uVar6 == 0)) {
      Process_writeCommand(this,attr,wVar13,str);
    }
    else {
                    /* Unresolved local var: uint32_t indent@[???] */
      len = 0xff;
      uVar12 = -uVar6;
      if ((int)-uVar6 < 0) {
        uVar12 = uVar6;
      }
      pcVar11 = buffer;
      if (uVar12 != 1) {
                    /* Unresolved local var: wchar_t written@[???]
                       Unresolved local var: wchar_t ret@[???] */
        uVar9 = (ulong)uVar12;
        do {
          if ((uVar9 & 1) == 0) {
            wVar7 = xSnprintf(pcVar11,len,((char *)0x1470db /* "   " */));
          }
          else {
            wVar7 = xSnprintf(pcVar11,len,((char *)0x148979 /* "%s  " */),*CRT_treeStr);
          }
          if ((wVar7 < L'\0') || (uVar10 = (ulong)wVar7, len <= uVar10)) {
            uVar10 = (ulong)(int)len;
          }
          uVar9 = uVar9 >> 1;
          pcVar11 = pcVar11 + uVar10;
          len = len - uVar10;
        } while ((int)uVar9 != 1);
      }
      if ((this->super).showChildren == false) {
        pcVar8 = CRT_treeStr[4];
      }
      else {
        pcVar8 = CRT_treeStr[5];
      }
      xSnprintf(pcVar11,len,((char *)0x14897e /* "%s%s " */),*(void **)((long)CRT_treeStr + (ulong)(uVar6 >> 0x1c & 8) + 8),
                pcVar8);
      RichString_appendWide(str,CRT_colors[0x22],buffer);
      Process_writeCommand(this,attr,wVar13,str);
    }
    goto LAB_0012c483;
  case 3:
    iVar5 = 0x21;
    uVar6 = this->state - UNKNOWN;
    if (uVar6 < 0xe) {
      iVar5 = (int)(char)CSWTCH_184[uVar6];
    }
    xSnprintf(buffer,0xff,((char *)0x149088 /* "%c " */),iVar5);
    if (this->state < (SLEEPING|UNKNOWN)) {
      uVar9 = 1L << ((byte)this->state & 0x3f);
      if ((uVar9 & 0x1ac0) == 0) {
        if ((uVar9 & 0x6030) == 0) {
          if ((uVar9 & 0x40c) != 0) {
            attr = CRT_colors[0x23];
          }
        }
        else {
          attr = CRT_colors[0x1e];
        }
      }
      else {
        attr = CRT_colors[0x24];
      }
    }
    break;
  case 4:
    wVar13 = (this->super).parent;
    goto LAB_0012c688;
  case 5:
    wVar13 = this->pgrp;
    goto LAB_0012c688;
  case 6:
    wVar13 = this->session;
    goto LAB_0012c688;
  case 7:
    pcVar11 = this->tty_name;
    if (pcVar11 != (char *)0x0) {
                    /* Unresolved local var: char * name@[???] */
      iVar5 = strncmp(pcVar11,((char *)0x1489c1 /* "/dev/" */),5);
      pcVar8 = ((char *)0x1489c7 /* "%-8s " */);
      if (iVar5 == 0) {
        pcVar11 = pcVar11 + 5;
      }
      goto LAB_0012c5be;
    }
    attr = CRT_colors[0x1e];
    pcVar11 = ((char *)0x1489b7 /* "(no tty) " */);
    goto LAB_0012c45e;
  case 8:
    wVar13 = this->tpgid;
    goto LAB_0012c688;
  case 10:
    Row_printCount(str,this->minflt,coloring);
    goto LAB_0012c483;
  case 0xc:
    Row_printCount(str,this->majflt,coloring);
    goto LAB_0012c483;
  case 0x12:
    pcVar11 = ((char *)0x1489a7 /* " RT " */);
    if (-100 < this->priority) {
      pcVar8 = ((char *)0x148996 /* "%3ld " */);
      pcVar11 = (char *)this->priority;
      goto LAB_0012c5be;
    }
LAB_0012c45e:
    xSnprintf(buffer,0xff,pcVar11);
    break;
  case 0x13:
    xSnprintf(buffer,0xff,((char *)0x148996 /* "%3ld " */),this->nice);
    if (this->nice < 0) {
      attr = CRT_colors[0x26];
    }
    else if (this->nice == 0) {
      attr = CRT_colors[0x1e];
    }
    else {
      attr = CRT_colors[0x27];
    }
    break;
  case 0x15:
    pcVar8 = ((char *)0x147626 /* "%s" */);
    pcVar11 = this->starttime_show;
    goto LAB_0012c5be;
  case 0x26:
    pcVar11 = ((char *)0x1489ac /* "%3d " */);
    va0 = (this->processor + L'\x01') - (uint)(pSVar3->countCPUsFromOne == false);
    goto LAB_0012c7f6;
  case 0x27:
    Row_printKBytes(str,this->m_virt,coloring);
    goto LAB_0012c483;
  case 0x28:
    Row_printKBytes(str,this->m_resident,coloring);
    goto LAB_0012c483;
  case 0x2e:
    wVar13 = this->st_uid;
    wVar7 = Row_uidDigits;
    goto LAB_0012c688;
  case 0x2f:
    Row_printPercentage(this->percent_cpu,buffer,0xff,Row_fieldWidths[0x2f],&attr);
    break;
  case 0x30:
    Row_printPercentage(this->percent_mem,buffer,0xff,'\x04',&attr);
    break;
  case 0x31:
    if (this->elevated_priv == false) {
      if (pMVar1->htopUserId != this->st_uid) {
        attr = CRT_colors[0x1e];
      }
    }
    else {
      attr = CRT_colors[0x2e];
    }
    if (this->user != (char *)0x0) {
      Row_printLeftAlignedField(str,attr,this->user,10);
      goto LAB_0012c483;
    }
    va0 = this->st_uid;
    pcVar11 = ((char *)0x1489cd /* "%-10d " */);
LAB_0012c7f6:
    xSnprintf(buffer,0xff,pcVar11,va0);
    break;
  case 0x32:
    Row_printTime(str,this->time,coloring);
    goto LAB_0012c483;
  case 0x33:
    if ((char *)this->nlwp == (char *)0x1) {
      attr = CRT_colors[0x1e];
    }
    pcVar8 = ((char *)0x14899c /* "%4ld " */);
    pcVar11 = (char *)this->nlwp;
    goto LAB_0012c5be;
  case 0x34:
    wVar13 = (this->super).group;
    if ((this->super).id == wVar13) {
      attr = CRT_colors[0x1e];
    }
LAB_0012c688:
    xSnprintf(buffer,0xff,((char *)0x1489a2 /* "%*d " */),wVar7,wVar13);
    break;
  case 0x35:
                    /* Unresolved local var: float cpuPercentage@[???] */
    Row_printPercentage(this->percent_cpu / (float)pMVar1->activeCPUs,buffer,0xff,
                        Row_fieldWidths[0x2f],&attr);
    break;
  case 0x36:
                    /* Unresolved local var: uint64_t rt@[???]
                       Unresolved local var: uint64_t st@[???]
                       Unresolved local var: uint64_t dt@[???] */
    totalHundredths = 0;
    if ((ulong)(this->starttime_ctime * 1000) <= pMVar1->realtimeMs) {
      totalHundredths = (pMVar1->realtimeMs + this->starttime_ctime * -1000) / 10;
    }
    Row_printTime(str,totalHundredths,coloring);
    goto LAB_0012c483;
  case 0x37:
                    /* Unresolved local var: char * schedPolStr@[???] */
    pcVar11 = ((char *)0x1474de /* "N/A" */);
    if (L'\xffffffff' < this->scheduling_policy) {
      switch(this->scheduling_policy & 0xbfffffff) {
      case L'\0':
        pcVar11 = ((char *)0x14895d /* "OTHER" */);
        break;
      case L'\x01':
        pcVar11 = ((char *)0x148958 /* "FIFO" */);
        break;
      case L'\x02':
        pcVar11 = ((char *)0x148976 /* "RR" */);
        break;
      case L'\x03':
        pcVar11 = ((char *)0x148970 /* "BATCH" */);
        break;
      default:
        pcVar11 = ((char *)0x148963 /* "???" */);
        break;
      case L'\x05':
        pcVar11 = ((char *)0x14896b /* "IDLE" */);
        break;
      case L'\x06':
        pcVar11 = ((char *)0x148967 /* "EDF" */);
      }
    }
    pcVar8 = ((char *)0x1489b1 /* "%-5s " */);
LAB_0012c5be:
    xSnprintf(buffer,0xff,pcVar8,pcVar11);
    break;
  case 0x7c:
                    /* Unresolved local var: char * procComm@[???] */
    pcVar11 = this->procComm;
    if (pcVar11 == (char *)0x0) {
LAB_0012cb10:
      attr = CRT_colors[0x1e];
      pcVar11 = ((char *)0x1474de /* "N/A" */);
      if (this->isKernelThread != false) {
        pcVar11 = ((char *)0x14877d /* "KTHREAD" */);
      }
    }
    else {
      attr = *(wchar_t *)
              ((long)CRT_colors +
              (-(ulong)(this->isUserlandThread == false) & 0xfffffffffffffffc) + 0xb4);
    }
    goto LAB_0012c55e;
  case 0x7d:
                    /* Unresolved local var: char * procExe@[???] */
    if (this->procExe == (char *)0x0) goto LAB_0012cb10;
    attr = *(wchar_t *)
            ((long)CRT_colors +
            (-(ulong)(this->isUserlandThread == false) & 0xffffffffffffffe8) + 0xac);
    if (pSVar3->highlightDeletedExe != false) {
      if (this->procExeDeleted == false) {
        if (this->usesDeletedLib != false) {
          attr = CRT_colors[0x1f];
        }
      }
      else {
        attr = CRT_colors[5];
      }
    }
    pcVar11 = this->procExe + this->procExeBasenameOffset;
LAB_0012c55e:
    Row_printLeftAlignedField(str,attr,pcVar11,0xf);
    goto LAB_0012c483;
  case 0x7e:
                    /* Unresolved local var: char * cwd@[???] */
    pcVar11 = this->procCwd;
    if (pcVar11 == (char *)0x0) {
      wVar13 = CRT_colors[0x1e];
      pcVar11 = ((char *)0x1474de /* "N/A" */);
      attr = wVar13;
    }
    else {
      iVar5 = strncmp(pcVar11,((char *)0x148984 /* "/proc/" */),6);
      if ((iVar5 == 0) && (pcVar8 = strstr(pcVar11,((char *)0x14898b /* " (deleted)" */)), pcVar8 != (char *)0x0)) {
        wVar13 = pwVar4[0x1e];
        pcVar11 = ((char *)0x148941 /* "main thread terminated" */);
        attr = wVar13;
      }
    }
    Row_printLeftAlignedField(str,wVar13,pcVar11,0x19);
    goto LAB_0012c483;
  }
  RichString_appendAscii(str,attr,buffer);
LAB_0012c483:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

