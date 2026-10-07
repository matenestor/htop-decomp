#include "htop.h"

/* Process_rowGetSortKey @ 0x11fbd0 */

char * Process_rowGetSortKey(Process_ *super)

{
  char *pcVar1;

                    /* Unresolved local var: Settings * settings@[???] */
  if (((super->isUserlandThread == false) ||
      (((super->super).host)->settings->showThreadNames == false)) &&
     (pcVar1 = (super->mergedCommand).str, pcVar1 != (char *)0x0)) {
    return pcVar1;
  }
  return super->cmdline;
}


/* Process_rowIsHighlighted @ 0x11fc00 */

_Bool Process_rowIsHighlighted(Process_ *super)

{
  Machine_ *pMVar1;
  _Bool _Var2;

                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???] */
  pMVar1 = (super->super).host;
  _Var2 = false;
  if (pMVar1->settings->shadowOtherUsers != false) {
    _Var2 = super->st_uid != pMVar1->htopUserId;
  }
  return _Var2;
}


/* Process_rowIsVisible @ 0x11fc20 */

_Bool Process_rowIsVisible(Process_ *super,Table_4 *table)

{
  _Bool _Var1;

  _Var1 = true;
                    /* Unresolved local var: Process * this@[???] */
  if ((table->host->settings->hideUserlandThreads != false) &&
     (_Var1 = false, super->isUserlandThread == false)) {
    return (_Bool)(super->isKernelThread ^ 1);
  }
  return _Var1;
}


/* Process_getCommand @ 0x121610 */

/* DWARF original prototype: char * Process_getCommand(Process * this) */

char * Process_getCommand(Process *this)

{
  char *pcVar1;

  if (((this->isUserlandThread == false) ||
      (((this->super).host)->settings->showThreadNames == false)) &&
     (pcVar1 = (this->mergedCommand).str, pcVar1 != (char *)0x0)) {
    return pcVar1;
  }
  return this->cmdline;
}


/* Process_fillStarttimeBuffer @ 0x1224a0 */

/* DWARF original prototype: void Process_fillStarttimeBuffer(Process * this) */

void Process_fillStarttimeBuffer(Process *this)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  long lVar2;
  char *__format;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = (((this->super).host)->realtime).tv_sec;
  localtime_r(&this->starttime_ctime,(tm_2 *)&(*(tm (*))(__fp - 0x68)));
  __format = ((char *)(long)&DAT_0014876e /* "%R " */);
  if ((this->starttime_ctime < lVar2 + -0x1517f) &&
     (__format = ((char *)(long)&DAT_00148778 /* " %Y " */), lVar2 + -0x1dfe1ff <= this->starttime_ctime)) {
    __format = ((char *)(long)&s__b_d_00148772 /* "%b%d " */);
  }
  strftime(this->starttime_show,7,__format,(tm_2 *)&(*(tm (*))(__fp - 0x68)));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Process_writeCommand @ 0x122550 */

/* DWARF original prototype: void Process_writeCommand(Process * this, int attr, int
   baseAttr, RichString * str) */

void Process_writeCommand(Process *this,int attr,int baseAttr,RichString *str)

{
  cchar_t *pcVar1;
  _Bool _Var2;
  _Bool _Var3;
  Settings__2 *pSVar4;
  int wVar5;
  cchar_t *pcVar6;
  cchar_t *pcVar7;
  long lVar8;
  int wVar9;
  ProcessCmdlineHighlight *pPVar10;
  int wVar11;
  int wVar12;
  ulong uVar13;
  char *pcVar14;
  ulong uVar15;
  int wVar16;
  long lVar17;
  int wVar18;

  wVar18 = str->chlen;
  pcVar14 = (this->mergedCommand).str;
  pSVar4 = ((this->super).host)->settings;
  _Var2 = pSVar4->highlightBaseName;
  _Var3 = pSVar4->highlightDeletedExe;
  if (pcVar14 != (char *)0x0) {
    RichString_appendWide(str,attr,pcVar14);
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t hlCount@[???] */
    uVar13 = (this->mergedCommand).highlightCount;
    uVar15 = 8;
    if (uVar13 < 9) {
      uVar15 = uVar13;
    }
    if (uVar13 == 0) {
      return;
    }
    pPVar10 = (this->mergedCommand).highlights;
    uVar13 = 0;
    do {
                    /* Unresolved local var: ProcessCmdlineHighlight * hl@[???] */
      if (((pPVar10->length != 0) &&
          ((wVar11 = pPVar10->flags, (wVar11 & 2U) == 0 || (_Var2 != false)))) &&
         ((((wVar11 & 8U) == 0 && ((wVar11 & 0x10U) == 0)) || (_Var3 != false)))) {
                    /* Unresolved local var: int end@[???] */
        wVar11 = pPVar10->attr;
        wVar16 = (int)pPVar10->offset + wVar18;
        wVar5 = (int)pPVar10->length + wVar16;
        wVar12 = 0;
        if (-1 < wVar5) {
          wVar12 = wVar5;
        }
        wVar9 = str->chlen;
        if (wVar5 <= str->chlen) {
          wVar9 = wVar12;
        }
                    /* Unresolved local var: int i@[???] */
        if (wVar16 < wVar9) {
          pcVar6 = str->chptr + wVar16;
          pcVar1 = str->chptr + (ulong)(uint)(wVar9 - wVar16) + (long)wVar16;
          if (((int)pcVar1 - (int)pcVar6 & 4U) != 0) {
            pcVar6->attr = wVar11;
            pcVar6 = pcVar6 + 1;
            if (pcVar6 == pcVar1) goto LAB_00122670;
          }
          do {
            pcVar6->attr = wVar11;
            pcVar7 = pcVar6 + 2;
            pcVar6[1].attr = wVar11;
            pcVar6 = pcVar7;
          } while (pcVar7 != pcVar1);
        }
      }
LAB_00122670:
      uVar13 = uVar13 + 1;
      pPVar10 = pPVar10 + 1;
      if (uVar15 <= uVar13) {
        return;
      }
    } while( true );
  }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: char * cmdline@[???] */
  pcVar14 = this->cmdline;
  if (_Var2 == false) {
    wVar12 = 0;
    if (pSVar4->showProgramPath != false) goto LAB_0012270c;
                    /* Unresolved local var: int basename@[???]
                       Unresolved local var: int i@[???] */
    wVar11 = this->cmdlineBasenameEnd;
    lVar17 = 0;
    if (0 < wVar11) goto LAB_001226be;
  }
  else {
    wVar11 = this->cmdlineBasenameEnd;
    if (wVar11 < 1) {
      lVar17 = 0;
    }
    else {
LAB_001226be:
      lVar8 = 1;
      lVar17 = 0;
      while( true ) {
        wVar12 = (int)lVar8;
        if (pcVar14[lVar8 + -1] == '/') {
          lVar17 = (long)wVar12;
        }
        else if (pcVar14[lVar8 + -1] == ':') goto LAB_0012270c;
        if (lVar8 == wVar11) break;
        lVar8 = lVar8 + 1;
      }
      wVar11 = wVar11 - (int)lVar17;
    }
    if (pSVar4->showProgramPath != false) {
      wVar18 = wVar18 + (int)lVar17;
      wVar12 = wVar11;
      goto LAB_0012270c;
    }
  }
  pcVar14 = pcVar14 + lVar17;
  wVar12 = wVar11;
LAB_0012270c:
  RichString_appendWide(str,attr,pcVar14);
  if (pSVar4->highlightBaseName != false) {
                    /* Unresolved local var: int end@[???] */
    wVar12 = wVar12 + wVar18;
    wVar11 = 0;
    if (-1 < wVar12) {
      wVar11 = wVar12;
    }
    wVar5 = str->chlen;
    if (wVar12 <= str->chlen) {
      wVar5 = wVar11;
    }
                    /* Unresolved local var: int i@[???] */
    if (wVar18 < wVar5) {
      pcVar6 = str->chptr + wVar18;
      pcVar1 = str->chptr + (ulong)(uint)(wVar5 - wVar18) + (long)wVar18;
      if (((int)pcVar1 - (int)pcVar6 & 4U) != 0) {
        pcVar6->attr = baseAttr;
        pcVar6 = pcVar6 + 1;
        if (pcVar1 == pcVar6) {
          return;
        }
      }
      do {
        pcVar6->attr = baseAttr;
        pcVar6[1].attr = baseAttr;
        if (pcVar1 == pcVar6 + 2) {
          return;
        }
        pcVar6[2].attr = baseAttr;
        pcVar7 = pcVar6 + 4;
        pcVar6[3].attr = baseAttr;
        pcVar6 = pcVar7;
      } while (pcVar1 != pcVar7);
    }
  }
  return;
}


/* Process_done @ 0x1227f0 */

/* DWARF original prototype: void Process_done(Process * this) */

void Process_done(Process *this)

{
  free(this->cmdline);
  free(this->procComm);
  free(this->procExe);
  free(this->procCwd);
  free((this->mergedCommand).str);
  free(this->tty_name);
  return;
}


/* Process_init @ 0x122850 */

/* DWARF original prototype: void Process_init(Process * this, Machine * host) */

void Process_init(Process *this,Machine_3 *host)

{
  (this->super).host = (Machine_ *)host;
  (this->super).tag = false;
  (this->super).show = true;
  (this->super).wasShown = false;
  (this->super).showChildren = true;
  (this->super).updated = false;
  this->cmdlineBasenameEnd = -1;
  this->st_uid = 0xffffffff;
  return;
}


/* Process_rowSendSignal @ 0x1228a0 */

_Bool Process_rowSendSignal(Process_ *super,Arg sgn)

{
  int iVar1;

                    /* Unresolved local var: Process * this@[???] */
  iVar1 = kill((super->super).id,sgn.i);
  return iVar1 == 0;
}


/* Process_compareByKey_Base @ 0x1228c0 */

int Process_compareByKey_Base(Process_3 *p1,Process_3 *p2,ProcessField key)

{
  float fVar1;
  float fVar2;
  int wVar3;
  long lVar4;
  long lVar5;
  ProcessState PVar6;
  int wVar7;
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
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
                    /* Unresolved local var: Settings * settings@[???] */
    if ((((p1->isUserlandThread != false) &&
         (((p1->super).host)->settings->showThreadNames != false)) ||
        (pcVar11 = (p1->mergedCommand).str, pcVar11 == (char *)0x0)) &&
       (pcVar11 = p1->cmdline, pcVar11 == (char *)0x0)) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
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
      pcVar11 = ((char *)(long)&DAT_00148785 /* "\x7f" */);
    }
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00148785 /* "\x7f" */);
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
                    /* Unresolved local var: int result@[???] */
    fVar1 = p2->percent_cpu;
    fVar2 = p1->percent_cpu;
    wVar7 = (uint)(fVar1 < fVar2) - (uint)(fVar2 < fVar1);
    if (wVar7 != 0) {
      return wVar7;
    }
    return (uint)!NAN(fVar2) - (uint)!NAN(fVar1);
  case 0x31:
    pcVar12 = p2->user;
    pcVar11 = p1->user;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
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
    if (wVar7 != 0) {
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
    if ((pcVar11 == (char *)0x0) && (pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */), p1->isKernelThread != false)) {
      pcVar11 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
    }
    pcVar12 = p2->procComm;
    if (pcVar12 != (char *)0x0) goto LAB_001229cf;
    goto LAB_001229f0;
  case 0x7d:
                    /* Unresolved local var: char * exe1@[???]
                       Unresolved local var: char * exe2@[???] */
    if (p1->procExe == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
      if (p1->isKernelThread != false) {
        pcVar11 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
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
    pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    if (p2->isKernelThread != false) {
      pcVar12 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
    }
LAB_001229cf:
    wVar7 = strcmp(pcVar11,pcVar12);
    return wVar7;
  case 0x7e:
    pcVar11 = p2->procCwd;
    pcVar12 = p1->procCwd;
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    wVar7 = strcmp(pcVar12,pcVar11);
    return wVar7;
  }
  return (uint)(!bVar13 && bVar15 == bVar14) - (uint)(bVar15 != bVar14);
}


/* Process_compare @ 0x122c50 */

int Process_compare(void *v1,void *v2)

{
  long lVar1;
  int iVar2;
  int wVar3;
  long lVar4;
  long in_RCX;
  ulong a2;
  long in_R8;
  long in_R9;

  lVar1 = *(long *)(**(long **)((long)v1 + 8) + 0x40);
  if (*(char *)(lVar1 + 0x34) == '\0') {
    a2 = (ulong)*(uint *)(lVar1 + 0x2c);
  }
  else {
    a2 = 1;
    if (*(char *)(lVar1 + 0x35) == '\0') {
      a2 = (ulong)*(uint *)(lVar1 + 0x30);
    }
  }
  if (*(code **)(*(long *)v1 + 0x50) == (code *)0x0) {
    wVar3 = Process_compareByKey_Base(v1,v2,(ProcessField)a2);
  }
  else {
    lVar4 = (**(code **)(*(long *)v1 + 0x50))((long)v1,(long)v2,a2,in_RCX,in_R8,in_R9);
    wVar3 = (int)lVar4;
  }
  if (wVar3 != 0) {
    iVar2 = *(int *)(lVar1 + 0x28);
    if (*(char *)(lVar1 + 0x34) == '\0') {
      iVar2 = *(int *)(lVar1 + 0x24);
    }
    if (iVar2 != 1) {
      wVar3 = -wVar3;
    }
    return wVar3;
  }
  return (uint)(*(int *)((long)v2 + 0x10) < *(int *)((long)v1 + 0x10)) -
         (uint)(*(int *)((long)v1 + 0x10) < *(int *)((long)v2 + 0x10));
}


/* Process_compareByParent @ 0x122d10 */

int Process_compareByParent(Row_3 *r1,Row_3 *r2)

{
  _Bool _Var1;
  uint uVar2;
  int wVar3;
  int wVar4;
  int wVar5;

  _Var1 = r2->isRoot;
  if (r1->isRoot == false) {
    wVar3 = r1->group;
    wVar5 = wVar3;
    if (r1->id == wVar3) {
      wVar5 = r1->parent;
      uVar2 = (uint)(0 < wVar5);
      wVar4 = 0;
      if (_Var1 == false) goto LAB_00122d58;
      goto LAB_00122d37;
    }
    if (_Var1 != false) {
      uVar2 = (uint)(0 < wVar3);
      wVar4 = 0;
      goto LAB_00122d37;
    }
LAB_00122d58:
    wVar4 = r2->group;
    if (wVar4 != r2->id) {
      uVar2 = (uint)(wVar4 < wVar5);
      wVar5 = wVar3;
      if (wVar3 == r1->id) goto LAB_00122d75;
      goto LAB_00122d37;
    }
    uVar2 = (uint)(r2->parent < wVar5);
    if (r1->id == wVar3) {
LAB_00122d75:
      wVar3 = r1->parent;
      wVar5 = wVar3;
      if (wVar4 != r2->id) goto LAB_00122d37;
    }
    wVar3 = uVar2 - (wVar3 < r2->parent);
  }
  else {
    if (_Var1 != false) goto LAB_00122d8c;
    wVar4 = r2->group;
    if (wVar4 == r2->id) {
      wVar4 = r2->parent;
    }
    uVar2 = (uint)wVar4 >> 0x1f;
    wVar5 = 0;
LAB_00122d37:
    wVar3 = uVar2 - (wVar5 < wVar4);
  }
  if (wVar3 != 0) {
    return wVar3;
  }
LAB_00122d8c:
  wVar3 = Process_compare(r1,r2);
  return wVar3;
}


/* Process_updateCPUFieldWidths @ 0x122df0 */

void Process_updateCPUFieldWidths(float percentage)

{
  uint8_t uVar1;
  byte bVar2;
  double dVar3;

  uVar1 = Row_fieldWidths[0x2f];
                    /* Unresolved local var: uint8_t width@[???] */
  if (percentage < 99.9) {
    if (Row_fieldWidths[0x2f] < 4) {
      Row_fieldWidths[0x2f] = '\x04';
    }
    if (Row_fieldWidths[0x35] < 4) {
      Row_fieldWidths[0x35] = '\x04';
      return;
    }
  }
  else {
    dVar3 = log10((double)percentage + 0.1);
    if (ABS(dVar3) < 4503599627370496.0) {
      dVar3 = __builtin_ceil(dVar3);
    }
    bVar2 = (byte)(int)(dVar3 + 2.0);
    if (uVar1 < bVar2) {
      Row_fieldWidths[0x2f] = bVar2;
    }
    if ((uint)Row_fieldWidths[0x35] < ((int)(dVar3 + 2.0) & 0xffU)) {
      Row_fieldWidths[0x35] = bVar2;
    }
  }
  return;
}


/* Process_setPriority @ 0x122f10 */

/* DWARF original prototype: _Bool Process_setPriority(Process * this, int priority) */

_Bool Process_setPriority(Process *this,int priority)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = getpriority(PRIO_PROCESS,(this->super).id);
  iVar2 = setpriority(PRIO_PROCESS,(this->super).id,priority);
  if (iVar2 == 0) {
    iVar3 = getpriority(PRIO_PROCESS,(this->super).id);
    if (iVar1 != iVar3) {
      this->nice = (long)priority;
      return true;
    }
  }
  return iVar2 == 0;
}


/* Process_rowChangePriorityBy @ 0x122f80 */

_Bool Process_rowChangePriorityBy(Process_ *super,Arg delta)

{
  _Bool _Var1;

                    /* Unresolved local var: int old_prio@[???]
                       Unresolved local var: int err@[???] */
  if (readonly) {
    return false;
  }
  _Var1 = Process_setPriority(super,delta.i + (int)super->nice);
  return _Var1;
}


/* Process_rowSetPriority @ 0x122fa0 */

_Bool Process_rowSetPriority(Process_ *super,int priority)

{
  _Bool _Var1;

                    /* Unresolved local var: int old_prio@[???]
                       Unresolved local var: int err@[???] */
  if (readonly) {
    return false;
  }
  _Var1 = Process_setPriority(super,priority);
  return _Var1;
}


/* Process_makeCommandStr @ 0x1243c0 */

/* DWARF original prototype: void Process_makeCommandStr(Process * this, Settings * settings) */

void Process_makeCommandStr(Process *this,Settings_5 *settings)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  ProcessCmdlineHighlight *pPVar1;
  byte bVar2;
  _Bool _Var3;
  _Bool _Var4;
  _Bool _Var5;
  _Bool _Var6;
  int wVar7;
  int wVar8;
  int wVar9;
  char *__s;
  byte bVar10;
  int *pwVar11;
  char cVar12;
  _Bool _Var13;
  int iVar14;
  int iVar15;
  int wVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  size_t sVar20;
  char *pcVar21;
  char *pcVar22;
  size_t sVar23;
  char *pcVar24;
  Object *pOVar25;
  ulong uVar26;
  byte bVar27;
  byte bVar28;
  char *pcVar29;
  undefined8 *puVar30;
  int wVar31;
  char *pcVar32;
  char *__s1;
  char *__s1_00;
  long lVar33;
  int wVar34;
  long lVar35;
  byte bVar36;
  bool bVar37;

  bVar27 = 0;
  _Var13 = settings->showMergedCommand;
  bVar36 = settings->showProgramPath;
  bVar2 = settings->findCommInCmdline;
  _Var3 = settings->stripExeFromCmdline;
  _Var4 = settings->showThreadNames;
  _Var5 = settings->shadowDistPathPrefix;
  if (this->isKernelThread != false) {
    return;
  }
  if (this->state == ZOMBIE) {
    if ((this->mergedCommand).str == (char *)0x0) {
      return;
    }
    uVar26 = (this->mergedCommand).lastUpdate;
  }
  else {
    uVar26 = (this->mergedCommand).lastUpdate;
  }
  if (settings->lastUpdate <= uVar26) {
    return;
  }
  (this->mergedCommand).lastUpdate = settings->lastUpdate;
  pcVar29 = *CRT_treeStr;
  sVar20 = strlen(pcVar29);
  iVar19 = (int)sVar20;
  (*(size_t (*))(__fp - 0x60)) = 8;
  if (this->cmdline != (char *)0x0) {
    (*(size_t (*))(__fp - 0x60)) = strlen(this->cmdline);
  }
  (*(size_t (*))(__fp - 0x60)) = (long)(iVar19 * 2 + 1) + (*(size_t (*))(__fp - 0x60));
  if (this->procComm != (char *)0x0) {
    sVar20 = strlen(this->procComm);
    (*(size_t (*))(__fp - 0x60)) = (*(size_t (*))(__fp - 0x60)) + sVar20;
  }
  if (this->procExe != (char *)0x0) {
    sVar20 = strlen(this->procExe);
    (*(size_t (*))(__fp - 0x60)) = (*(size_t (*))(__fp - 0x60)) + sVar20;
  }
  free((this->mergedCommand).str);
                    /* Unresolved local var: void * data@[???] */
  pcVar21 = calloc(1,(*(size_t (*))(__fp - 0x60)));
  if (pcVar21 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this->mergedCommand).highlights[0].offset = 0;
  (this->mergedCommand).highlights[7].attr = 0;
  (this->mergedCommand).highlights[7].flags = 0;
  puVar30 = (undefined8 *)((ulong)&(this->mergedCommand).highlights[0].length & 0xfffffffffffffff8);
  (this->mergedCommand).str = pcVar21;
  (this->mergedCommand).highlightCount = 0;
  uVar26 = (ulong)(((int)this - (int)puVar30) + 0x1e8U >> 3);
  for (; pwVar11 = CRT_colors, uVar26 != 0; uVar26 = uVar26 - 1) {
    *puVar30 = 0;
    puVar30 = puVar30 + (ulong)bVar27 * -2 + 1;
  }
  _Var6 = this->isUserlandThread;
  if ((_Var6 == false) && (this->isKernelThread == false)) {
    wVar7 = CRT_colors[0x25];
    (*(int (*))(__fp - 0x94)) = CRT_colors[0x2c];
  }
  else {
    wVar7 = CRT_colors[0x2b];
    (*(int (*))(__fp - 0x94)) = CRT_colors[0x2d];
  }
  __s1_00 = this->cmdline;
  pcVar24 = this->procExe;
  wVar34 = this->cmdlineBasenameStart;
  wVar8 = CRT_colors[5];
  wVar9 = CRT_colors[0x1f];
  wVar31 = this->cmdlineBasenameEnd;
  __s = this->procComm;
  if (__s1_00 == (char *)0x0) {
    wVar31 = 0;
    wVar34 = 0;
    __s1_00 = ((char *)(long)&s__zombie__00148787 /* "(zombie)" */);
  }
  if (_Var13 != true || pcVar24 == (char *)0x0) {
    if ((((_Var13 == false) && ((_Var4 == false || (_Var6 == false)))) || (__s == (char *)0x0)) ||
       (*__s == '\0')) {
LAB_001247b0:
      lVar35 = 0;
      pcVar29 = pcVar21;
    }
    else {
      sVar23 = strlen(__s);
      sVar20 = 0xf;
      if (sVar23 < 0x10) {
        sVar20 = sVar23;
      }
      iVar14 = strncmp(__s1_00 + wVar34,__s,sVar20);
      if (iVar14 == 0) goto LAB_001247b0;
      (this->mergedCommand).highlights[0].length = sVar23;
      (this->mergedCommand).highlights[0].flags = 4;
      (this->mergedCommand).highlights[0].attr = (*(int (*))(__fp - 0x94));
      (this->mergedCommand).highlightCount = 1;
      pcVar24 = __stpcpy_chk(pcVar21,__s,(*(size_t (*))(__fp - 0x60)));
      if (_Var13 == false) {
        return;
      }
      (this->mergedCommand).highlights[1].length = 1;
      (this->mergedCommand).highlights[1].offset = (long)pcVar24 - (long)pcVar21;
      wVar16 = pwVar11[5];
      (this->mergedCommand).highlights[1].flags = 1;
      (this->mergedCommand).highlightCount = 2;
      (this->mergedCommand).highlights[1].attr = wVar16;
      lVar35 = (long)(iVar19 + -1);
      pcVar29 = stpcpy(pcVar24,pcVar29);
    }
    if (((_Bool)bVar36 == false) || (_Var5 == false)) {
      if (wVar31 <= wVar34) goto LAB_00124840;
      uVar26 = (this->mergedCommand).highlightCount;
      if (uVar26 < 8) {
        pcVar24 = pcVar29 + -(long)pcVar21;
        if ((_Bool)bVar36 != false) {
          pcVar24 = pcVar29 + -(long)pcVar21 + wVar34;
        }
        goto LAB_001247fc;
      }
LAB_00124a67:
      if (this->procExeDeleted != false) goto LAB_001248b6;
    }
    else {
      if (*__s1_00 == '/') {
        cVar12 = __s1_00[1];
        if (cVar12 == 's') {
          iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
          if (iVar19 == 0) {
            uVar26 = (this->mergedCommand).highlightCount;
            if (uVar26 < 8) {
              pOVar25 = &(this->super).super + uVar26 * 3;
              *(__typeof__((ObjectClass *)0x6) *)&(pOVar25[0x26]) = (ObjectClass *)0x6;
              lVar33 = (long)pcVar29 - (long)pcVar21;
              *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
              goto LAB_001252c4;
            }
            goto LAB_00125810;
          }
        }
        else if (cVar12 < 't') {
          if (cVar12 == 'b') {
            iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5);
            if (iVar19 == 0) {
LAB_00125739:
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                pOVar25 = &(this->super).super + uVar26 * 3;
                *(__typeof__((ObjectClass *)0x5) *)&(pOVar25[0x26]) = (ObjectClass *)0x5;
                lVar33 = (long)pcVar29 - (long)pcVar21;
                *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
LAB_001252c4:
                uVar26 = uVar26 + 1;
                wVar16 = pwVar11[0x1e];
                *(undefined4 *)((long)(pOVar25 + 0x27) + 4) = 0x10;
                *(int *)(pOVar25 + 0x27) = wVar16;
                (this->mergedCommand).highlightCount = uVar26;
                if (wVar34 < wVar31) {
                  if (uVar26 != 8) {
                    pcVar24 = (char *)(wVar34 + lVar33);
                    goto LAB_001247fc;
                  }
                  goto LAB_00124a67;
                }
                goto LAB_00124840;
              }
              goto LAB_00125810;
            }
          }
          else if (cVar12 == 'l') {
            iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17f7) /* "/lib/" */),5);
            if (iVar19 == 0) goto LAB_00125739;
            iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17bc) /* "/lib32/" */),7);
            if ((iVar19 == 0) || (iVar19 = strncmp(__s1_00,((char *)(long)&s__lib64__001487c8 /* "/lib64/" */),7), iVar19 == 0)) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                *(__typeof__((ObjectClass *)0x7) *)&(pOVar25[0x26]) = (ObjectClass *)0x7;
                *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                goto LAB_001252c4;
              }
            }
            else {
              _Var13 = String_startsWith(__s1_00,((char *)(long)(__sec_rodata + 0x17d4) /* "/libx32/" */));
              if (!_Var13) goto LAB_001247d5;
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                *(__typeof__((ObjectClass *)0x8) *)&(pOVar25[0x26]) = (ObjectClass *)0x8;
                *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                goto LAB_001252c4;
              }
            }
LAB_00125810:
            if (wVar31 <= wVar34) goto LAB_00124a67;
            goto LAB_00124840;
          }
        }
        else if ((cVar12 == 'u') && (iVar19 = strncmp(__s1_00,((char *)(long)&s__usr__00148790 /* "/usr/" */),5), iVar19 == 0)) {
          cVar12 = __s1_00[5];
          if (cVar12 == 'l') {
            _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_libexec__001487a0 /* "/usr/libexec/" */));
            if (_Var13) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                *(__typeof__((ObjectClass *)0xd) *)&(pOVar25[0x26]) = (ObjectClass *)0xd;
                *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                goto LAB_001252c4;
              }
            }
            else {
              _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_lib__001487ae /* "/usr/lib/" */));
              if (_Var13) goto LAB_0012566c;
              _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_lib32__001487b8 /* "/usr/lib32/" */));
              if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)(long)&DAT_001487c4 /* "/usr/lib64/" */)), _Var13)) {
                uVar26 = (this->mergedCommand).highlightCount;
                if (uVar26 < 8) {
                  lVar33 = (long)pcVar29 - (long)pcVar21;
                  pOVar25 = &(this->super).super + uVar26 * 3;
                  *(__typeof__((ObjectClass *)0xb) *)&(pOVar25[0x26]) = (ObjectClass *)0xb;
                  *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                  goto LAB_001252c4;
                }
              }
              else {
                _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_libx32__001487d0 /* "/usr/libx32/" */));
                if (_Var13) {
                  uVar26 = (this->mergedCommand).highlightCount;
                  if (uVar26 < 8) {
                    lVar33 = (long)pcVar29 - (long)pcVar21;
                    pOVar25 = &(this->super).super + uVar26 * 3;
                    *(__typeof__((ObjectClass *)0xc) *)&(pOVar25[0x26]) = (ObjectClass *)0xc;
                    *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                    goto LAB_001252c4;
                  }
                }
                else {
                  _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_local_bin__001487dd /* "/usr/local/bin/" */));
                  if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_local_lib__001487ed /* "/usr/local/lib/" */)), _Var13)) {
                    uVar26 = (this->mergedCommand).highlightCount;
                    if (uVar26 < 8) {
                      lVar33 = (long)pcVar29 - (long)pcVar21;
                      pOVar25 = &(this->super).super + uVar26 * 3;
                      *(__typeof__((ObjectClass *)0xf) *)&(pOVar25[0x26]) = (ObjectClass *)0xf;
                      *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                      goto LAB_001252c4;
                    }
                  }
                  else {
                    _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_local_sbin__001487fd /* "/usr/local/sbin/" */));
                    if (!_Var13) goto LAB_001247d5;
                    uVar26 = (this->mergedCommand).highlightCount;
                    if (uVar26 < 8) {
                      lVar33 = (long)pcVar29 - (long)pcVar21;
                      pOVar25 = &(this->super).super + uVar26 * 3;
                      *(__typeof__((ObjectClass *)0x10) *)&(pOVar25[0x26]) = (ObjectClass *)0x10;
                      *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                      goto LAB_001252c4;
                    }
                  }
                }
              }
            }
            goto LAB_00125810;
          }
          if (cVar12 == 's') {
            _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_sbin__0014880e /* "/usr/sbin/" */));
            if (_Var13) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                lVar33 = (long)pcVar29 - (long)pcVar21;
                pOVar25 = &(this->super).super + uVar26 * 3;
                *(__typeof__((ObjectClass *)0xa) *)&(pOVar25[0x26]) = (ObjectClass *)0xa;
                *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
                goto LAB_001252c4;
              }
              goto LAB_00125810;
            }
          }
          else if ((cVar12 == 'b') && (_Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_bin__00148796 /* "/usr/bin/" */)), _Var13)) {
LAB_0012566c:
            uVar26 = (this->mergedCommand).highlightCount;
            if (uVar26 < 8) {
              lVar33 = (long)pcVar29 - (long)pcVar21;
              pOVar25 = &(this->super).super + uVar26 * 3;
              *(__typeof__((ObjectClass *)0x9) *)&(pOVar25[0x26]) = (ObjectClass *)0x9;
              *(__typeof__((lVar33 - lVar35)) *)&(pOVar25[0x25]) = (lVar33 - lVar35);
              goto LAB_001252c4;
            }
            goto LAB_00125810;
          }
        }
      }
LAB_001247d5:
      if (wVar34 < wVar31) {
        uVar26 = (this->mergedCommand).highlightCount;
        if (7 < uVar26) goto LAB_00124a67;
        pcVar24 = pcVar29 + ((long)wVar34 - (long)pcVar21);
LAB_001247fc:
        (this->mergedCommand).highlights[uVar26].offset = (long)pcVar24 - lVar35;
        *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar7;
        pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x5c;
        pcVar24[0] = '\x02';
        pcVar24[1] = '\0';
        pcVar24[2] = '\0';
        pcVar24[3] = '\0';
        *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(wVar31 - wVar34);
        (this->mergedCommand).highlightCount = uVar26 + 1;
      }
LAB_00124840:
      if (this->procExeDeleted != false) {
        uVar26 = (this->mergedCommand).highlightCount;
        if (uVar26 < 8) {
          lVar33 = (long)pcVar29 - (long)pcVar21;
          if ((_Bool)bVar36 != false) {
            lVar33 = (long)wVar34 + ((long)pcVar29 - (long)pcVar21);
          }
          *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar8;
          (this->mergedCommand).highlights[uVar26].offset = lVar33 - lVar35;
          *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(wVar31 - wVar34);
          pcVar21 = this->starttime_show + uVar26 * 0x18 + 0x5c;
          pcVar21[0] = '\b';
          pcVar21[1] = '\0';
          pcVar21[2] = '\0';
          pcVar21[3] = '\0';
          (this->mergedCommand).highlightCount = uVar26 + 1;
        }
        goto LAB_001248b6;
      }
    }
    if ((this->usesDeletedLib != false) &&
       (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
      lVar33 = (long)pcVar29 - (long)pcVar21;
      if ((_Bool)bVar36 != false) {
        lVar33 = (long)wVar34 + ((long)pcVar29 - (long)pcVar21);
      }
      *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar9;
      (this->mergedCommand).highlights[uVar26].offset = lVar33 - lVar35;
      pcVar21 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar21[0] = '\b';
      pcVar21[1] = '\0';
      pcVar21[2] = '\0';
      pcVar21[3] = '\0';
      *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(wVar31 - wVar34);
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
LAB_001248b6:
    if ((_Bool)bVar36 == false) {
      __s1_00 = __s1_00 + wVar34;
    }
    cVar12 = *__s1_00;
    if (cVar12 != '\0') {
      pcVar21 = pcVar29;
      do {
        if (cVar12 == '\n') {
          cVar12 = ' ';
        }
        __s1_00 = __s1_00 + 1;
        pcVar29 = pcVar21 + 1;
        *pcVar21 = cVar12;
        cVar12 = *__s1_00;
        pcVar21 = pcVar29;
      } while (cVar12 != '\0');
    }
    *pcVar29 = '\0';
    return;
  }
  if (__s == (char *)0x0) goto LAB_001247b0;
  sVar20 = strlen(pcVar24);
  wVar31 = this->procExeBasenameOffset;
  (*(int (*))(__fp - 0xb8)) = (int)sVar20;
  iVar14 = (*(int (*))(__fp - 0xb8)) - wVar31;
  bVar27 = _Var6 ^ 1U | _Var4;
  if (bVar27 == 0) {
    if ((_Bool)bVar36 == false) {
      lVar35 = 0;
      pcVar22 = pcVar24 + wVar31;
      sVar20 = 1;
      goto LAB_00124b4d;
    }
    if ((_Var5 != false) && (*pcVar24 == '/')) {
      cVar12 = pcVar24[1];
      if (cVar12 == 'l') {
        bVar36 = false;
LAB_0012467a:
        iVar15 = strncmp(pcVar24,((char *)(long)(__sec_rodata + 0x17f7) /* "/lib/" */),5);
        if (iVar15 == 0) {
          (this->mergedCommand).highlights[0].length = 5;
          wVar16 = pwVar11[0x1e];
        }
        else {
          iVar15 = strncmp(pcVar24,((char *)(long)(__sec_rodata + 0x17bc) /* "/lib32/" */),7);
          if ((iVar15 != 0) && (_Var13 = String_startsWith(pcVar24,((char *)(long)&s__lib64__001487c8 /* "/lib64/" */)), !_Var13)) {
            _Var13 = String_startsWith(pcVar24,((char *)(long)(__sec_rodata + 0x17d4) /* "/libx32/" */));
            (*(long (*))(__fp - 0x58)) = 0;
            if (_Var13) {
              (this->mergedCommand).highlights[0].length = 8;
              goto LAB_00125aa0;
            }
            goto LAB_001246cf;
          }
          (this->mergedCommand).highlights[0].length = 7;
          wVar16 = pwVar11[0x1e];
        }
        goto LAB_001246a9;
      }
      if (cVar12 < 'm') {
        if ((cVar12 == 'b') && (iVar15 = strncmp(pcVar24,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5), iVar15 == 0)) {
          (this->mergedCommand).highlights[0].length = 5;
          wVar16 = pwVar11[0x1e];
          (this->mergedCommand).highlights[0].flags = 16;
          (this->mergedCommand).highlights[0].attr = wVar16;
LAB_001260f1:
          lVar35 = 1;
          bVar36 = false;
          goto LAB_001246df;
        }
      }
      else if (cVar12 == 's') {
        iVar15 = strncmp(pcVar24,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
        if (iVar15 == 0) {
          (this->mergedCommand).highlights[0].length = 6;
          wVar16 = pwVar11[0x1e];
          (this->mergedCommand).highlights[0].flags = 16;
          (this->mergedCommand).highlights[0].attr = wVar16;
          goto LAB_001260f1;
        }
      }
      else if (cVar12 == 'u') {
        bVar36 = false;
        goto LAB_00125922;
      }
      lVar35 = 0;
LAB_001246d7:
      bVar36 = false;
      goto LAB_001246df;
    }
    bVar36 = false;
    sVar20 = 1;
    lVar35 = 0;
LAB_001246ee:
    (*(size_t (*))(__fp - 0x80)) = (size_t)iVar14;
    (*(size_t (*))(__fp - 0x90)) = (size_t)wVar31;
    _Var13 = this->procExeDeleted;
    *(size_t *)(this->starttime_show + lVar35 * 0x18 + 0x50) = (*(size_t (*))(__fp - 0x80));
    (this->mergedCommand).highlights[lVar35].offset = (*(size_t (*))(__fp - 0x90));
    *(int *)(this->starttime_show + lVar35 * 0x18 + 0x58) = wVar7;
    pcVar22 = this->starttime_show + lVar35 * 0x18 + 0x5c;
    pcVar22[0] = '\x02';
    pcVar22[1] = '\0';
    pcVar22[2] = '\0';
    pcVar22[3] = '\0';
    (this->mergedCommand).highlightCount = sVar20;
    if (_Var13 == false) {
      if (this->usesDeletedLib != false) {
        (this->mergedCommand).highlights[sVar20].offset = (*(size_t (*))(__fp - 0x90));
        pcVar22 = this->starttime_show + sVar20 * 0x18 + 0x5c;
        pcVar22[0] = '\b';
        pcVar22[1] = '\0';
        pcVar22[2] = '\0';
        pcVar22[3] = '\0';
        *(size_t *)(this->starttime_show + sVar20 * 0x18 + 0x50) = (*(size_t (*))(__fp - 0x80));
        *(int *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar9;
        (this->mergedCommand).highlightCount = sVar20 + 1;
      }
    }
    else {
      pPVar1 = (this->mergedCommand).highlights + sVar20;
      pPVar1->offset = (*(size_t (*))(__fp - 0x90));
      pPVar1->length = (*(size_t (*))(__fp - 0x80));
      *(int *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar8;
      pcVar22 = this->starttime_show + sVar20 * 0x18 + 0x5c;
      pcVar22[0] = '\b';
      pcVar22[1] = '\0';
      pcVar22[2] = '\0';
      pcVar22[3] = '\0';
      (this->mergedCommand).highlightCount = sVar20 + 1;
    }
    pcVar22 = __stpcpy_chk(pcVar21,pcVar24,(*(size_t (*))(__fp - 0x60)));
  }
  else {
    pcVar22 = pcVar24 + wVar31;
    iVar15 = strncmp(pcVar22,__s,0xf);
    if ((_Bool)bVar36 != false) {
      bVar36 = iVar15 == 0;
      (*(long (*))(__fp - 0x58)) = 0;
      if ((_Var5 == false) || (*pcVar24 != '/')) {
LAB_001246cf:
        (*(size_t (*))(__fp - 0x90)) = (size_t)wVar31;
        lVar35 = (*(long (*))(__fp - 0x58));
        if ((bool)bVar36 == false) goto LAB_001246d7;
        lVar35 = (*(long (*))(__fp - 0x58)) + 1;
        (this->mergedCommand).highlights[(*(long (*))(__fp - 0x58))].offset = (*(size_t (*))(__fp - 0x90));
        *(long *)(this->starttime_show + (*(long (*))(__fp - 0x58)) * 0x18 + 0x50) = (long)iVar14;
        *(int *)(this->starttime_show + (*(long (*))(__fp - 0x58)) * 0x18 + 0x58) = (*(int (*))(__fp - 0x94));
        pcVar22 = this->starttime_show + (*(long (*))(__fp - 0x58)) * 0x18 + 0x5c;
        pcVar22[0] = '\x04';
        pcVar22[1] = '\0';
        pcVar22[2] = '\0';
        pcVar22[3] = '\0';
      }
      else {
        cVar12 = pcVar24[1];
        if (cVar12 == 's') {
          iVar15 = strncmp(pcVar24,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
          (*(long (*))(__fp - 0x58)) = 0;
          if (iVar15 == 0) {
            (this->mergedCommand).highlights[0].length = 6;
LAB_00125aa0:
            wVar16 = pwVar11[0x1e];
LAB_001246a9:
            (this->mergedCommand).highlights[0].attr = wVar16;
            (*(long (*))(__fp - 0x58)) = 1;
            (this->mergedCommand).highlights[0].flags = 16;
            (this->mergedCommand).highlightCount = 1;
          }
          goto LAB_001246cf;
        }
        if (cVar12 < 't') {
          if (cVar12 == 'b') {
            (*(long (*))(__fp - 0x58)) = 0;
            iVar15 = strncmp(pcVar24,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5);
            if (iVar15 == 0) {
              (this->mergedCommand).highlights[0].length = 5;
              goto LAB_00125aa0;
            }
            goto LAB_001246cf;
          }
          if (cVar12 == 'l') goto LAB_0012467a;
        }
        else if (cVar12 == 'u') {
LAB_00125922:
          iVar15 = strncmp(pcVar24,((char *)(long)&s__usr__00148790 /* "/usr/" */),5);
          if (iVar15 == 0) {
            cVar12 = pcVar24[5];
            if (cVar12 == 'l') {
              _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_libexec__001487a0 /* "/usr/libexec/" */));
              if (_Var13) {
                (this->mergedCommand).highlights[0].length = 0xd;
                wVar16 = pwVar11[0x1e];
              }
              else {
                _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_lib__001487ae /* "/usr/lib/" */));
                if (_Var13) {
LAB_00125975:
                  (this->mergedCommand).highlights[0].length = 9;
                  wVar16 = pwVar11[0x1e];
                }
                else {
                  _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_lib32__001487b8 /* "/usr/lib32/" */));
                  if ((_Var13) || (_Var13 = String_startsWith(pcVar24,((char *)(long)&DAT_001487c4 /* "/usr/lib64/" */)), _Var13)) {
                    (this->mergedCommand).highlights[0].length = 0xb;
                    wVar16 = pwVar11[0x1e];
                  }
                  else {
                    _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_libx32__001487d0 /* "/usr/libx32/" */));
                    if (_Var13) {
                      (this->mergedCommand).highlights[0].length = 0xc;
                      wVar16 = pwVar11[0x1e];
                    }
                    else {
                      _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_local_bin__001487dd /* "/usr/local/bin/" */));
                      if ((!_Var13) &&
                         (_Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_local_lib__001487ed /* "/usr/local/lib/" */)), !_Var13)) {
                        _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_local_sbin__001487fd /* "/usr/local/sbin/" */));
                        (*(long (*))(__fp - 0x58)) = 0;
                        if (_Var13) {
                          (this->mergedCommand).highlights[0].length = 0x10;
                          goto LAB_00125aa0;
                        }
                        goto LAB_001246cf;
                      }
                      (this->mergedCommand).highlights[0].length = 0xf;
                      wVar16 = pwVar11[0x1e];
                    }
                  }
                }
              }
              goto LAB_001246a9;
            }
            if (cVar12 == 's') {
              _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_sbin__0014880e /* "/usr/sbin/" */));
              (*(long (*))(__fp - 0x58)) = 0;
              if (_Var13) {
                (this->mergedCommand).highlights[0].length = 10;
                goto LAB_00125aa0;
              }
            }
            else {
              if (cVar12 != 'b') goto LAB_00125a1a;
              _Var13 = String_startsWith(pcVar24,((char *)(long)&s__usr_bin__00148796 /* "/usr/bin/" */));
              (*(long (*))(__fp - 0x58)) = 0;
              if (_Var13) goto LAB_00125975;
            }
          }
          else {
            (*(long (*))(__fp - 0x58)) = 0;
          }
          goto LAB_001246cf;
        }
LAB_00125a1a:
        (*(size_t (*))(__fp - 0x90)) = (size_t)wVar31;
        if ((bool)bVar36 == false) {
          lVar35 = 0;
          bVar36 = false;
        }
        else {
          lVar35 = 1;
          (this->mergedCommand).highlights[0].flags = 4;
          (this->mergedCommand).highlights[0].offset = (*(size_t (*))(__fp - 0x90));
          (this->mergedCommand).highlights[0].length = (long)iVar14;
          (this->mergedCommand).highlights[0].attr = (*(int (*))(__fp - 0x94));
        }
      }
LAB_001246df:
      sVar20 = lVar35 + 1;
      goto LAB_001246ee;
    }
    if (iVar15 == 0) {
      (this->mergedCommand).highlights[0].length = (long)iVar14;
      lVar35 = 1;
      (this->mergedCommand).highlights[0].flags = 4;
      (this->mergedCommand).highlights[0].attr = (*(int (*))(__fp - 0x94));
      sVar20 = 2;
      bVar36 = bVar27;
    }
    else {
      sVar20 = 1;
      lVar35 = 0;
    }
LAB_00124b4d:
    (*(size_t (*))(__fp - 0x80)) = (size_t)iVar14;
    _Var13 = this->procExeDeleted;
    (this->mergedCommand).highlights[lVar35].offset = 0;
    *(size_t *)(this->starttime_show + lVar35 * 0x18 + 0x50) = (*(size_t (*))(__fp - 0x80));
    *(int *)(this->starttime_show + lVar35 * 0x18 + 0x58) = wVar7;
    pcVar32 = this->starttime_show + lVar35 * 0x18 + 0x5c;
    pcVar32[0] = '\x02';
    pcVar32[1] = '\0';
    pcVar32[2] = '\0';
    pcVar32[3] = '\0';
    (this->mergedCommand).highlightCount = sVar20;
    if (_Var13 == false) {
      if (this->usesDeletedLib != false) {
        *(size_t *)(this->starttime_show + sVar20 * 0x18 + 0x50) = (*(size_t (*))(__fp - 0x80));
        (this->mergedCommand).highlights[sVar20].offset = 0;
        *(int *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar9;
        pcVar32 = this->starttime_show + sVar20 * 0x18 + 0x5c;
        pcVar32[0] = '\b';
        pcVar32[1] = '\0';
        pcVar32[2] = '\0';
        pcVar32[3] = '\0';
        (this->mergedCommand).highlightCount = sVar20 + 1;
      }
    }
    else {
      *(size_t *)(this->starttime_show + sVar20 * 0x18 + 0x50) = (*(size_t (*))(__fp - 0x80));
      (this->mergedCommand).highlights[sVar20].offset = 0;
      *(int *)(this->starttime_show + sVar20 * 0x18 + 0x58) = wVar8;
      pcVar32 = this->starttime_show + sVar20 * 0x18 + 0x5c;
      pcVar32[0] = '\b';
      pcVar32[1] = '\0';
      pcVar32[2] = '\0';
      pcVar32[3] = '\0';
      (this->mergedCommand).highlightCount = sVar20 + 1;
    }
    pcVar22 = __stpcpy_chk(pcVar21,pcVar22,(*(size_t (*))(__fp - 0x60)));
  }
  (*(size_t (*))(__fp - 0x80)) = (size_t)iVar14;
  (*(size_t (*))(__fp - 0x90)) = (size_t)wVar31;
  bVar10 = bVar36;
  if ((_Bool)bVar2 == false) {
    bVar2 = 1;
LAB_00124d40:
    (*(int (*))(__fp - 0x98)) = 0;
    iVar15 = 0;
  }
  else {
    if (bVar27 == 0) goto LAB_00124d40;
                    /* Unresolved local var: char * tokenBase@[???]
                       Unresolved local var: size_t tokenLen@[???]
                       Unresolved local var: size_t commLen@[???] */
    if (-1 < wVar34) {
      sVar20 = strlen(__s);
                    /* Unresolved local var: char * token@[???] */
      cVar12 = __s1_00[wVar34];
      pcVar32 = __s1_00 + wVar34;
LAB_00124c40:
      __s1 = pcVar32;
      if (cVar12 != '\0') {
        pcVar32 = __s1;
        if (cVar12 == '\n') {
          if (sVar20 == 0) {
LAB_0012515f:
            (*(int (*))(__fp - 0x98)) = (int)__s1 - (int)__s1_00;
            iVar15 = (int)pcVar32 - (int)__s1_00;
            bVar10 = bVar27;
            bVar2 = bVar36;
            goto LAB_00124d54;
          }
LAB_00124ca6:
          do {
            cVar12 = __s1[1];
            pcVar32 = __s1 + 1;
            if (cVar12 != '\n') break;
            cVar12 = __s1[2];
            __s1 = __s1 + 2;
            pcVar32 = __s1;
          } while (cVar12 == '\n');
        }
        else {
          do {
            pcVar32 = pcVar32 + 1;
            bVar37 = cVar12 == '/';
            cVar12 = *pcVar32;
            if (bVar37) {
              __s1 = pcVar32;
            }
          } while ((cVar12 != '\n') && (cVar12 != '\0'));
          if (((sVar20 == (long)pcVar32 - (long)__s1) ||
              ((sVar20 < (ulong)((long)pcVar32 - (long)__s1) && (sVar20 == 0xf)))) &&
             (iVar15 = strncmp(__s1,__s,sVar20), iVar15 == 0)) goto LAB_0012515f;
          __s1 = pcVar32;
          if (cVar12 != '\0') goto LAB_00124ca6;
          cVar12 = *pcVar32;
        }
        goto LAB_00124c40;
      }
    }
    (*(int (*))(__fp - 0x98)) = 0;
    iVar15 = 0;
    bVar2 = bVar27;
  }
LAB_00124d54:
                    /* Unresolved local var: int matchLen@[???]
                       Unresolved local var: char delim@[???]
                       Unresolved local var: _Bool delimFound@[???] */
  if (*__s1_00 != '/') {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    bVar36 = (byte)((uint)-wVar31 >> 0x1f);
LAB_00124da0:
    if (wVar31 <= wVar34) goto LAB_00124df0;
LAB_00124da6:
    iVar17 = strncmp(__s1_00 + wVar34,pcVar24 + (*(size_t (*))(__fp - 0x90)),(*(size_t (*))(__fp - 0x80)));
    if (iVar17 == 0) {
      (*(int (*))(__fp - 0xb8)) = wVar34 + iVar14;
      if (((byte)__s1_00[(*(int (*))(__fp - 0xb8))] < 0x21) &&
         ((0x100000401U >> ((ulong)(byte)__s1_00[(*(int (*))(__fp - 0xb8))] & 0x3f) & 1) != 0)) {
        lVar35 = (long)(wVar31 + -1);
        iVar17 = wVar34 + -1;
        bVar28 = bVar36;
        if ((-wVar34 < 0) && (-wVar31 < 0)) {
          lVar33 = (long)(wVar31 + -2);
          do {
            if (__s1_00[lVar33 + 1 + ((long)wVar34 - (*(size_t (*))(__fp - 0x90)))] != pcVar24[lVar33 + 1])
            goto LAB_00124df0;
            iVar18 = (int)lVar33;
            lVar35 = (long)iVar18;
            bVar28 = (byte)~(byte)((ulong)lVar33 >> 0x18) >> 7;
            iVar17 = iVar17 + -1;
            if (iVar17 < 0) goto LAB_001250ae;
            lVar33 = lVar33 + -1;
          } while (-1 < iVar18);
        }
        if (iVar17 < 0) {
LAB_001250ae:
          if ((bVar28 != 0) && (pcVar24[lVar35] == '/')) goto LAB_001250d7;
        }
      }
    }
LAB_00124df0:
    wVar34 = wVar34 + -2;
    if (0 < wVar34) goto code_r0x00124df9;
    goto LAB_00124e57;
  }
  iVar14 = strncmp(__s1_00,pcVar24,(long)(*(int (*))(__fp - 0xb8)));
  if (((iVar14 == 0) && ((byte)__s1_00[(*(int (*))(__fp - 0xb8))] < 0x21)) &&
     ((0x100000401U >> ((ulong)(byte)__s1_00[(*(int (*))(__fp - 0xb8))] & 0x3f) & 1) != 0)) {
LAB_001250d7:
    bVar36 = (*(int (*))(__fp - 0xb8)) != 0 & _Var3;
    bVar37 = bVar10 == 0;
    bVar10 = bVar36;
    if (bVar37) {
LAB_00124e72:
      bVar36 = bVar10;
      if (bVar27 != 0) goto LAB_00124e7c;
    }
    if (bVar36 == 0) {
LAB_00125124:
      lVar35 = 0;
      lVar33 = (long)(iVar19 + -1);
      goto LAB_00124f73;
    }
    lVar33 = 0;
    (*(int (*))(__fp - 0x98)) = (*(int (*))(__fp - 0x98)) - (*(int (*))(__fp - 0xb8));
    iVar15 = iVar15 - (*(int (*))(__fp - 0xb8));
    __s1_00 = __s1_00 + (*(int (*))(__fp - 0xb8));
  }
  else {
    if ((bVar10 != 0) || ((*(int (*))(__fp - 0xb8)) = 0, bVar27 == 0)) goto LAB_00125124;
LAB_00124e7c:
    uVar26 = (this->mergedCommand).highlightCount;
    if (uVar26 < 8) {
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x50;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      pcVar24[4] = '\0';
      pcVar24[5] = '\0';
      pcVar24[6] = '\0';
      pcVar24[7] = '\0';
      (this->mergedCommand).highlights[uVar26].offset = (long)pcVar22 - (long)pcVar21;
      wVar7 = pwVar11[5];
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar7;
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
    pcVar24 = stpcpy(pcVar22,pcVar29);
    uVar26 = (this->mergedCommand).highlightCount;
    lVar35 = (long)(iVar19 + -1);
    if (uVar26 < 8) {
      (this->mergedCommand).highlights[uVar26].offset =
           (size_t)(pcVar24 + (-lVar35 - (long)pcVar21));
      sVar20 = strlen(__s);
      *(size_t *)(this->starttime_show + uVar26 * 0x18 + 0x50) = sVar20;
      pcVar22 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar22[0] = '\x04';
      pcVar22[1] = '\0';
      pcVar22[2] = '\0';
      pcVar22[3] = '\0';
      *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = (*(int (*))(__fp - 0x94));
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
    pcVar22 = stpcpy(pcVar24,__s);
    if (bVar10 == 0) {
      lVar33 = lVar35 * 2;
      bVar2 = 1;
    }
    else {
      __s1_00 = __s1_00 + (*(int (*))(__fp - 0xb8));
      if (*__s1_00 == '\0') {
        return;
      }
      (*(int (*))(__fp - 0x98)) = (*(int (*))(__fp - 0x98)) - (*(int (*))(__fp - 0xb8));
      lVar33 = lVar35 * 2;
      iVar15 = iVar15 - (*(int (*))(__fp - 0xb8));
      bVar2 = bVar10;
    }
LAB_00124f73:
    uVar26 = (this->mergedCommand).highlightCount;
    if (uVar26 < 8) {
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x50;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      pcVar24[4] = '\0';
      pcVar24[5] = '\0';
      pcVar24[6] = '\0';
      pcVar24[7] = '\0';
      (this->mergedCommand).highlights[uVar26].offset =
           (size_t)(pcVar22 + (-lVar35 - (long)pcVar21));
      wVar7 = pwVar11[5];
      pcVar24 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar24[0] = '\x01';
      pcVar24[1] = '\0';
      pcVar24[2] = '\0';
      pcVar24[3] = '\0';
      *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = wVar7;
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
    pcVar22 = stpcpy(pcVar22,pcVar29);
  }
  if ((_Var5 == false) || (*__s1_00 != '/')) {
LAB_00124fef:
    if (bVar2 == 0) goto LAB_00125356;
  }
  else {
    cVar12 = __s1_00[1];
    if (cVar12 == 's') {
      iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
      if ((iVar19 != 0) || (uVar26 = (this->mergedCommand).highlightCount, 7 < uVar26))
      goto LAB_0012534c;
      pOVar25 = &(this->super).super + uVar26 * 3;
      *(__typeof__((ObjectClass *)0x6) *)&(pOVar25[0x26]) = (ObjectClass *)0x6;
      *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
LAB_00125873:
      wVar7 = pwVar11[0x1e];
      *(undefined4 *)((long)(pOVar25 + 0x27) + 4) = 0x10;
      *(int *)(pOVar25 + 0x27) = wVar7;
      (this->mergedCommand).highlightCount = uVar26 + 1;
      goto LAB_00124fef;
    }
    if (cVar12 < 't') {
      if (cVar12 == 'b') {
        iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5);
        if (iVar19 == 0) {
LAB_0012583a:
          uVar26 = (this->mergedCommand).highlightCount;
          if (uVar26 < 8) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            *(__typeof__((ObjectClass *)0x5) *)&(pOVar25[0x26]) = (ObjectClass *)0x5;
            *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
            goto LAB_00125873;
          }
        }
      }
      else if (cVar12 == 'l') {
        iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17f7) /* "/lib/" */),5);
        if (iVar19 == 0) goto LAB_0012583a;
        iVar19 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17bc) /* "/lib32/" */),7);
        if ((iVar19 == 0) || (iVar19 = strncmp(__s1_00,((char *)(long)&s__lib64__001487c8 /* "/lib64/" */),7), iVar19 == 0)) {
          uVar26 = (this->mergedCommand).highlightCount;
          if (uVar26 < 8) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
            *(__typeof__((ObjectClass *)0x7) *)&(pOVar25[0x26]) = (ObjectClass *)0x7;
            goto LAB_00125531;
          }
        }
        else {
          _Var13 = String_startsWith(__s1_00,((char *)(long)(__sec_rodata + 0x17d4) /* "/libx32/" */));
          if ((_Var13) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
            *(__typeof__((ObjectClass *)0x8) *)&(pOVar25[0x26]) = (ObjectClass *)0x8;
LAB_00125531:
            wVar7 = pwVar11[0x1e];
            *(undefined4 *)((long)(pOVar25 + 0x27) + 4) = 0x10;
            *(int *)(pOVar25 + 0x27) = wVar7;
            (this->mergedCommand).highlightCount = uVar26 + 1;
            goto LAB_00124fef;
          }
        }
      }
    }
    else if ((cVar12 == 'u') && (iVar19 = strncmp(__s1_00,((char *)(long)&s__usr__00148790 /* "/usr/" */),5), iVar19 == 0)) {
      cVar12 = __s1_00[5];
      if (cVar12 == 'l') {
        _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_libexec__001487a0 /* "/usr/libexec/" */));
        if (_Var13) {
          uVar26 = (this->mergedCommand).highlightCount;
          if (uVar26 < 8) {
            pOVar25 = &(this->super).super + uVar26 * 3;
            *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
            *(__typeof__((ObjectClass *)0xd) *)&(pOVar25[0x26]) = (ObjectClass *)0xd;
            goto LAB_00125531;
          }
        }
        else {
          _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_lib__001487ae /* "/usr/lib/" */));
          if (_Var13) goto LAB_001257d2;
          _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_lib32__001487b8 /* "/usr/lib32/" */));
          if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)(long)&DAT_001487c4 /* "/usr/lib64/" */)), _Var13)) {
            uVar26 = (this->mergedCommand).highlightCount;
            if (uVar26 < 8) {
              pOVar25 = &(this->super).super + uVar26 * 3;
              *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
              *(__typeof__((ObjectClass *)0xb) *)&(pOVar25[0x26]) = (ObjectClass *)0xb;
              goto LAB_00125531;
            }
          }
          else {
            _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_libx32__001487d0 /* "/usr/libx32/" */));
            if (_Var13) {
              uVar26 = (this->mergedCommand).highlightCount;
              if (uVar26 < 8) {
                pOVar25 = &(this->super).super + uVar26 * 3;
                *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
                *(__typeof__((ObjectClass *)0xc) *)&(pOVar25[0x26]) = (ObjectClass *)0xc;
                goto LAB_00125531;
              }
            }
            else {
              _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_local_bin__001487dd /* "/usr/local/bin/" */));
              if ((_Var13) || (_Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_local_lib__001487ed /* "/usr/local/lib/" */)), _Var13)) {
                uVar26 = (this->mergedCommand).highlightCount;
                if (uVar26 < 8) {
                  pOVar25 = &(this->super).super + uVar26 * 3;
                  *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
                  *(__typeof__((ObjectClass *)0xf) *)&(pOVar25[0x26]) = (ObjectClass *)0xf;
                  goto LAB_00125531;
                }
              }
              else {
                _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_local_sbin__001487fd /* "/usr/local/sbin/" */));
                if ((_Var13) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
                  pOVar25 = &(this->super).super + uVar26 * 3;
                  *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
                  *(__typeof__((ObjectClass *)0x10) *)&(pOVar25[0x26]) = (ObjectClass *)0x10;
                  goto LAB_00125531;
                }
              }
            }
          }
        }
      }
      else if (cVar12 == 's') {
        _Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_sbin__0014880e /* "/usr/sbin/" */));
        if ((_Var13) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
          pOVar25 = &(this->super).super + uVar26 * 3;
          *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
          *(__typeof__((ObjectClass *)0xa) *)&(pOVar25[0x26]) = (ObjectClass *)0xa;
          goto LAB_00125531;
        }
      }
      else if ((cVar12 == 'b') && (_Var13 = String_startsWith(__s1_00,((char *)(long)&s__usr_bin__00148796 /* "/usr/bin/" */)), _Var13)) {
LAB_001257d2:
        uVar26 = (this->mergedCommand).highlightCount;
        if (uVar26 < 8) {
          pOVar25 = &(this->super).super + uVar26 * 3;
          *(__typeof__((pcVar22 + (-lVar33 - (long)pcVar21))) *)&(pOVar25[0x25]) = (pcVar22 + (-lVar33 - (long)pcVar21));
          *(__typeof__((ObjectClass *)0x9) *)&(pOVar25[0x26]) = (ObjectClass *)0x9;
          goto LAB_00125531;
        }
      }
    }
LAB_0012534c:
    cVar12 = '/';
    if (bVar2 != 0) goto LAB_00125007;
LAB_00125356:
    if ((bVar27 != 0) && (uVar26 = (this->mergedCommand).highlightCount, uVar26 < 8)) {
      pcVar29 = this->starttime_show + uVar26 * 0x18 + 0x5c;
      pcVar29[0] = '\x04';
      pcVar29[1] = '\0';
      pcVar29[2] = '\0';
      pcVar29[3] = '\0';
      (this->mergedCommand).highlights[uVar26].offset =
           (size_t)(pcVar22 + (((long)(*(int (*))(__fp - 0x98)) - (long)pcVar21) - lVar33));
      *(long *)(this->starttime_show + uVar26 * 0x18 + 0x50) = (long)(iVar15 - (*(int (*))(__fp - 0x98)));
      *(int *)(this->starttime_show + uVar26 * 0x18 + 0x58) = (*(int (*))(__fp - 0x94));
      (this->mergedCommand).highlightCount = uVar26 + 1;
    }
  }
  cVar12 = *__s1_00;
  if (cVar12 == '\0') {
    return;
  }
LAB_00125007:
  do {
    if (cVar12 == '\n') {
      cVar12 = ' ';
    }
    __s1_00 = __s1_00 + 1;
    pcVar29 = pcVar22 + 1;
    *pcVar22 = cVar12;
    cVar12 = *__s1_00;
    pcVar22 = pcVar29;
  } while (cVar12 != '\0');
  *pcVar29 = '\0';
  return;
code_r0x00124df9:
  pcVar32 = __s1_00 + wVar34;
  while( true ) {
    cVar12 = *pcVar32;
    pcVar32 = pcVar32 + -1;
    wVar34 = wVar34 + -1;
    if (wVar34 == 0) break;
    if (cVar12 == ' ' || cVar12 == '\n') goto LAB_00124e36;
  }
  if ((cVar12 != ' ' && cVar12 != '\n') || (wVar31 < 1)) {
LAB_00124e57:
    if (bVar10 != 0) goto LAB_00125124;
    (*(int (*))(__fp - 0xb8)) = 0;
    goto LAB_00124e72;
  }
  goto LAB_00124da6;
  while( true ) {
    pcVar32 = pcVar32 + -1;
    wVar34 = wVar34 + -1;
    if (wVar34 == 0) break;
LAB_00124e36:
    if (pcVar32[-1] == '/') break;
  }
  goto LAB_00124da0;
}


/* Process_updateComm @ 0x126290 */

/* DWARF original prototype: void Process_updateComm(Process * this, char * comm) */

void Process_updateComm(Process *this,char *comm)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = this->procComm;
  if (pcVar2 == (char *)0x0) {
    if (comm == (char *)0x0) {
      return;
    }
  }
  else {
    if (comm == (char *)0x0) {
      free(pcVar2);
      pcVar2 = (char *)0x0;
      goto LAB_001262dc;
    }
    iVar1 = strcmp(pcVar2,comm);
    if (iVar1 == 0) {
      return;
    }
    free(pcVar2);
  }
                    /* Unresolved local var: char * data@[???] */
  pcVar2 = strdup(comm);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
LAB_001262dc:
  this->procComm = pcVar2;
  (this->mergedCommand).lastUpdate = 0;
  return;
}


/* Process_updateCmdline @ 0x126320 */

/* DWARF original prototype: void Process_updateCmdline(Process * this, char * cmdline, int
   basenameStart, int basenameEnd) */

void Process_updateCmdline(Process *this,char *cmdline,int basenameStart,int basenameEnd)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int wVar4;
  char *pcVar5;

  pcVar5 = this->cmdline;
  if (pcVar5 == (char *)0x0) {
    if (cmdline == (char *)0x0) {
      return;
    }
LAB_00126372:
                    /* Unresolved local var: char * data@[???] */
    pcVar5 = strdup(cmdline);
    if (pcVar5 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->cmdline = pcVar5;
    if (this->isKernelThread == false) {
                    /* Unresolved local var: int slash@[???] */
                    /* Unresolved local var: int i@[???] */
      if (((basenameStart == 0) && (*cmdline == '/')) && (1 < basenameEnd)) {
        wVar4 = 2;
        do {
          cVar1 = cmdline[1];
          if (cVar1 == '/') {
            if (cmdline[2] != '\0') {
              basenameStart = wVar4;
            }
          }
          else if (cVar1 == ' ') {
            if (*cmdline != '\\') break;
          }
          else if ((cVar1 == ':') && (cmdline[2] == ' ')) break;
          cmdline = cmdline + 1;
          bVar2 = wVar4 < basenameEnd;
          wVar4 = wVar4 + 1;
        } while (bVar2);
      }
      goto LAB_001263e0;
    }
  }
  else {
    if (cmdline != (char *)0x0) {
      iVar3 = strcmp(pcVar5,cmdline);
      if (iVar3 == 0) {
        return;
      }
      free(pcVar5);
      goto LAB_00126372;
    }
    free(pcVar5);
    this->cmdline = (char *)0x0;
    if (this->isKernelThread == false) goto LAB_001263e0;
  }
  basenameStart = 0;
  basenameEnd = 0;
LAB_001263e0:
  this->cmdlineBasenameStart = basenameStart;
  this->cmdlineBasenameEnd = basenameEnd;
  (this->mergedCommand).lastUpdate = 0;
  return;
}


/* Process_updateExe @ 0x126480 */

/* DWARF original prototype: void Process_updateExe(Process * this, char * exe) */

void Process_updateExe(Process *this,char *exe)

{
  int iVar1;
  char *pcVar2;
  int wVar3;

  pcVar2 = this->procExe;
  if (pcVar2 == (char *)0x0) {
    if (exe == (char *)0x0) {
      return;
    }
  }
  else {
    if (exe == (char *)0x0) {
      free(pcVar2);
      wVar3 = 0;
      this->procExe = (char *)0x0;
      goto LAB_00126515;
    }
    iVar1 = strcmp(pcVar2,exe);
    if (iVar1 == 0) {
      return;
    }
    free(pcVar2);
  }
                    /* Unresolved local var: char * lastSlash@[???]
                       Unresolved local var: char * data@[???] */
  pcVar2 = strdup(exe);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  this->procExe = pcVar2;
  pcVar2 = strrchr(exe,0x2f);
  wVar3 = 0;
  if (pcVar2 != (char *)0x0) {
    if ((pcVar2[1] == '\0') || (exe == pcVar2)) {
      wVar3 = 0;
    }
    else {
      wVar3 = ((int)pcVar2 - (int)exe) + 1;
    }
  }
LAB_00126515:
  this->procExeBasenameOffset = wVar3;
  (this->mergedCommand).lastUpdate = 0;
  return;
}


/* Process_rowMatchesFilter @ 0x128410 */

_Bool Process_rowMatchesFilter(Process_ *super,Table_4 *table)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uid_t uVar1;
  int wVar2;
  Machine__4 *pMVar3;
  ObjectClass *pOVar4;
  Object_Display p_Var5;
  _Bool _Var6;
  char *pcVar7;
  char **__ptr;
  char *pcVar8;
  Object_Display p_Var9;
  ulong uVar10;
  void *pvVar11;
  char *__haystack;
  char **ppcVar12;
  size_t sVar13;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: char * incFilter@[???]
                       Unresolved local var: ProcessTable * pt@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  pMVar3 = table->host;
  uVar1 = pMVar3->userId;
  if ((uVar1 == 0xffffffff) || (uVar1 == super->st_uid)) {
    pcVar8 = table->incFilter;
    if (pcVar8 == (char *)0x0) {
LAB_00128538:
      pOVar4 = pMVar3->activeTable[1].super.klass;
      _Var6 = false;
      if (pOVar4 == (ObjectClass *)0x0) goto LAB_00128452;
      wVar2 = (super->super).group;
      p_Var5 = pOVar4->display;
      pvVar11 = (void *)((ulong)(uint)wVar2 % (ulong)pOVar4->extends);
      p_Var9 = p_Var5 + (long)pvVar11 * 0x18;
      if (*(long *)(p_Var9 + 0x10) != 0) {
        uVar10 = 0;
        do {
          if (wVar2 == *(int *)p_Var9) {
            _Var6 = false;
            goto LAB_00128452;
          }
          if (*(ulong *)(p_Var9 + 8) < uVar10) break;
          pvVar11 = (void *)((long)pvVar11 + 1);
          if (pOVar4->extends == pvVar11) {
            pvVar11 = (void *)0x0;
            p_Var9 = p_Var5;
          }
          else {
            p_Var9 = p_Var5 + (long)pvVar11 * 0x18;
          }
          uVar10 = uVar10 + 1;
        } while (*(long *)(p_Var9 + 0x10) != 0);
      }
    }
    else {
                    /* Unresolved local var: Settings * settings@[???] */
      if (((super->isUserlandThread != false) &&
          (((super->super).host)->settings->showThreadNames != false)) ||
         (__haystack = (super->mergedCommand).str, __haystack == (char *)0x0)) {
        __haystack = super->cmdline;
      }
      pcVar7 = strchr(pcVar8,0x7c);
      if (pcVar7 == (char *)0x0) {
        pcVar8 = strcasestr(__haystack,pcVar8);
        if (pcVar8 != (char *)0x0) goto LAB_00128538;
      }
      else {
                    /* Unresolved local var: char * * needles@[???] */
        __ptr = String_split(pcVar8,'|',&(*(size_t (*))(__fp - 0x48)));
                    /* Unresolved local var: size_t i@[???] */
        if ((*(size_t (*))(__fp - 0x48)) != 0) {
          sVar13 = 0;
LAB_001284f5:
          pcVar8 = strcasestr(__haystack,__ptr[sVar13]);
          if (pcVar8 == (char *)0x0) goto LAB_001284e8;
                    /* Unresolved local var: size_t i@[???] */
          pcVar8 = *__ptr;
          ppcVar12 = __ptr;
          while (pcVar8 != (char *)0x0) {
            ppcVar12 = ppcVar12 + 1;
            free(pcVar8);
            pcVar8 = *ppcVar12;
          }
          free(__ptr);
          goto LAB_00128538;
        }
        if (__ptr != (char **)0x0) {
LAB_00128608:
                    /* Unresolved local var: size_t i@[???] */
          pcVar8 = *__ptr;
          ppcVar12 = __ptr;
          while (pcVar8 != (char *)0x0) {
            ppcVar12 = ppcVar12 + 1;
            free(pcVar8);
            pcVar8 = *ppcVar12;
          }
          free(__ptr);
          _Var6 = true;
          goto LAB_00128452;
        }
      }
    }
  }
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  _Var6 = true;
LAB_00128452:
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var6;
LAB_001284e8:
  sVar13 = sVar13 + 1;
  if (sVar13 == (*(size_t (*))(__fp - 0x48))) goto LAB_00128608;
  goto LAB_001284f5;
}


/* Process_writeField @ 0x12c3e0 */

/* DWARF original prototype: void Process_writeField(Process * this, RichString * str, RowField
   field) */

void Process_writeField(Process *this,RichString *str,RowField field)

{
  undefined1 __frame[0x1d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x198;
  _Bool coloring;
  Machine_ *pMVar1;
  long lVar2;
  Settings__2 *pSVar3;
  int *pwVar4;
  int iVar5;
  uid_t va0;
  uint uVar6;
  int wVar7;
  char *pcVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  ulonglong totalHundredths;
  uint uVar12;
  size_t len;
  int wVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  pwVar4 = CRT_colors;
  pMVar1 = (this->super).host;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar3 = pMVar1->settings;
  coloring = pSVar3->highlightMegabytes;
  (*(char (*) [256])(__fp - 0x148))[0xff] = '\0';
  wVar13 = CRT_colors[1];
  wVar7 = Row_pidDigits;
  (*(int (*))(__fp - 0x14c)) = wVar13;
  switch(field) {
  default:
    pcVar11 = ((char *)(long)&DAT_00147411 /* "- " */);
    goto LAB_0012c45e;
  case 1:
    wVar13 = (this->super).id;
    goto LAB_0012c688;
  case 2:
                    /* Unresolved local var: int baseattr@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: char * buf@[???]
                       Unresolved local var: _Bool lastItem@[???]
                       Unresolved local var: char * draw@[???] */
    wVar13 = CRT_colors[0x25];
    if ((pSVar3->highlightThreads != false) &&
       ((this->isUserlandThread != false || (this->isKernelThread != false)))) {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x2a];
      wVar13 = CRT_colors[0x2b];
    }
    if ((pSVar3->ss->treeView == false) || (uVar6 = (this->super).indent, uVar6 == 0)) {
      Process_writeCommand(this,(*(int (*))(__fp - 0x14c)),wVar13,str);
    }
    else {
                    /* Unresolved local var: uint32_t indent@[???] */
      len = 0xff;
      uVar12 = -uVar6;
      if ((int)-uVar6 < 0) {
        uVar12 = uVar6;
      }
      pcVar11 = (*(char (*) [256])(__fp - 0x148));
      if (uVar12 != 1) {
                    /* Unresolved local var: int written@[???]
                       Unresolved local var: int ret@[???] */
        uVar9 = (ulong)uVar12;
        do {
          if ((uVar9 & 1) == 0) {
            wVar7 = xSnprintf(pcVar11,len,((char *)(long)&DAT_001470db /* "   " */));
          }
          else {
            wVar7 = xSnprintf(pcVar11,len,((char *)(long)&DAT_00148979 /* "%s  " */),*CRT_treeStr);
          }
          if ((wVar7 < 0) || (uVar10 = (ulong)wVar7, len <= uVar10)) {
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
      xSnprintf(pcVar11,len,((char *)(long)&s__s_s_0014897e /* "%s%s " */),*(void **)((long)CRT_treeStr + (ulong)(uVar6 >> 0x1c & 8) + 8),
                pcVar8);
      RichString_appendWide(str,CRT_colors[0x22],(*(char (*) [256])(__fp - 0x148)));
      Process_writeCommand(this,(*(int (*))(__fp - 0x14c)),wVar13,str);
    }
    goto LAB_0012c483;
  case 3:
    iVar5 = 0x21;
    uVar6 = this->state - UNKNOWN;
    if (uVar6 < 0xe) {
      iVar5 = (int)(char)CSWTCH_184[uVar6];
    }
    xSnprintf((*(char (*) [256])(__fp - 0x148)),0xff,((char *)(long)&DAT_00149088 /* "%c " */),iVar5);
    if (this->state < (SLEEPING|UNKNOWN)) {
      uVar9 = 1L << ((byte)this->state & 0x3f);
      if ((uVar9 & 0x1ac0) == 0) {
        if ((uVar9 & 0x6030) == 0) {
          if ((uVar9 & 0x40c) != 0) {
            (*(int (*))(__fp - 0x14c)) = CRT_colors[0x23];
          }
        }
        else {
          (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
        }
      }
      else {
        (*(int (*))(__fp - 0x14c)) = CRT_colors[0x24];
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
      iVar5 = strncmp(pcVar11,((char *)(long)&s__dev__001489c1 /* "/dev/" */),5);
      pcVar8 = ((char *)(long)&s___8s_001489c7 /* "%-8s " */);
      if (iVar5 == 0) {
        pcVar11 = pcVar11 + 5;
      }
      goto LAB_0012c5be;
    }
    (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
    pcVar11 = ((char *)(long)&s__no_tty__001489b7 /* "(no tty) " */);
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
    pcVar11 = ((char *)(long)&DAT_001489a7 /* " RT " */);
    if (-100 < this->priority) {
      pcVar8 = ((char *)(long)&s__3ld_00148996 /* "%3ld " */);
      pcVar11 = (char *)this->priority;
      goto LAB_0012c5be;
    }
LAB_0012c45e:
    xSnprintf((*(char (*) [256])(__fp - 0x148)),0xff,pcVar11);
    break;
  case 0x13:
    xSnprintf((*(char (*) [256])(__fp - 0x148)),0xff,((char *)(long)&s__3ld_00148996 /* "%3ld " */),this->nice);
    if (this->nice < 0) {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x26];
    }
    else if (this->nice == 0) {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
    }
    else {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x27];
    }
    break;
  case 0x15:
    pcVar8 = ((char *)(long)(__sec_rodata + 0x626) /* "%s" */);
    pcVar11 = this->starttime_show;
    goto LAB_0012c5be;
  case 0x26:
    pcVar11 = ((char *)(long)&DAT_001489ac /* "%3d " */);
    va0 = (this->processor + 1) - (uint)(pSVar3->countCPUsFromOne == false);
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
    Row_printPercentage(this->percent_cpu,(*(char (*) [256])(__fp - 0x148)),0xff,Row_fieldWidths[0x2f],&(*(int (*))(__fp - 0x14c)));
    break;
  case 0x30:
    Row_printPercentage(this->percent_mem,(*(char (*) [256])(__fp - 0x148)),0xff,'\x04',&(*(int (*))(__fp - 0x14c)));
    break;
  case 0x31:
    if (this->elevated_priv == false) {
      if (pMVar1->htopUserId != this->st_uid) {
        (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
      }
    }
    else {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x2e];
    }
    if (this->user != (char *)0x0) {
      Row_printLeftAlignedField(str,(*(int (*))(__fp - 0x14c)),this->user,10);
      goto LAB_0012c483;
    }
    va0 = this->st_uid;
    pcVar11 = ((char *)(long)&s___10d_001489cd /* "%-10d " */);
LAB_0012c7f6:
    xSnprintf((*(char (*) [256])(__fp - 0x148)),0xff,pcVar11,va0);
    break;
  case 0x32:
    Row_printTime(str,this->time,coloring);
    goto LAB_0012c483;
  case 0x33:
    if ((char *)this->nlwp == (char *)0x1) {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
    }
    pcVar8 = ((char *)(long)&s__4ld_0014899c /* "%4ld " */);
    pcVar11 = (char *)this->nlwp;
    goto LAB_0012c5be;
  case 0x34:
    wVar13 = (this->super).group;
    if ((this->super).id == wVar13) {
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
    }
LAB_0012c688:
    xSnprintf((*(char (*) [256])(__fp - 0x148)),0xff,((char *)(long)&DAT_001489a2 /* "%*d " */),wVar7,wVar13);
    break;
  case 0x35:
                    /* Unresolved local var: float cpuPercentage@[???] */
    Row_printPercentage(this->percent_cpu / (float)pMVar1->activeCPUs,(*(char (*) [256])(__fp - 0x148)),0xff,
                        Row_fieldWidths[0x2f],&(*(int (*))(__fp - 0x14c)));
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
    pcVar11 = ((char *)(long)&DAT_001474de /* "N/A" */);
    if (-1 < this->scheduling_policy) {
      switch(this->scheduling_policy & 0xbfffffff) {
      case 0:
        pcVar11 = ((char *)(long)&s_OTHER_0014895d /* "OTHER" */);
        break;
      case 1:
        pcVar11 = ((char *)(long)&DAT_00148958 /* "FIFO" */);
        break;
      case 2:
        pcVar11 = ((char *)(long)&DAT_00148976 /* "RR" */);
        break;
      case 3:
        pcVar11 = ((char *)(long)&s_BATCH_00148970 /* "BATCH" */);
        break;
      default:
        pcVar11 = ((char *)(long)&DAT_00148963 /* "???" */);
        break;
      case 5:
        pcVar11 = ((char *)(long)&DAT_0014896b /* "IDLE" */);
        break;
      case 6:
        pcVar11 = ((char *)(long)&DAT_00148967 /* "EDF" */);
      }
    }
    pcVar8 = ((char *)(long)&s___5s_001489b1 /* "%-5s " */);
LAB_0012c5be:
    xSnprintf((*(char (*) [256])(__fp - 0x148)),0xff,pcVar8,pcVar11);
    break;
  case 0x7c:
                    /* Unresolved local var: char * procComm@[???] */
    pcVar11 = this->procComm;
    if (pcVar11 == (char *)0x0) {
LAB_0012cb10:
      (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1e];
      pcVar11 = ((char *)(long)&DAT_001474de /* "N/A" */);
      if (this->isKernelThread != false) {
        pcVar11 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
      }
    }
    else {
      (*(int (*))(__fp - 0x14c)) = *(int *)
              ((long)CRT_colors +
              (-(ulong)(this->isUserlandThread == false) & 0xfffffffffffffffc) + 0xb4);
    }
    goto LAB_0012c55e;
  case 0x7d:
                    /* Unresolved local var: char * procExe@[???] */
    if (this->procExe == (char *)0x0) goto LAB_0012cb10;
    (*(int (*))(__fp - 0x14c)) = *(int *)
            ((long)CRT_colors +
            (-(ulong)(this->isUserlandThread == false) & 0xffffffffffffffe8) + 0xac);
    if (pSVar3->highlightDeletedExe != false) {
      if (this->procExeDeleted == false) {
        if (this->usesDeletedLib != false) {
          (*(int (*))(__fp - 0x14c)) = CRT_colors[0x1f];
        }
      }
      else {
        (*(int (*))(__fp - 0x14c)) = CRT_colors[5];
      }
    }
    pcVar11 = this->procExe + this->procExeBasenameOffset;
LAB_0012c55e:
    Row_printLeftAlignedField(str,(*(int (*))(__fp - 0x14c)),pcVar11,0xf);
    goto LAB_0012c483;
  case 0x7e:
                    /* Unresolved local var: char * cwd@[???] */
    pcVar11 = this->procCwd;
    if (pcVar11 == (char *)0x0) {
      wVar13 = CRT_colors[0x1e];
      pcVar11 = ((char *)(long)&DAT_001474de /* "N/A" */);
      (*(int (*))(__fp - 0x14c)) = wVar13;
    }
    else {
      iVar5 = strncmp(pcVar11,((char *)(long)&s__proc__00148984 /* "/proc/" */),6);
      if ((iVar5 == 0) && (pcVar8 = strstr(pcVar11,((char *)(long)&s__deleted__0014898b /* " (deleted)" */)), pcVar8 != (char *)0x0)) {
        wVar13 = pwVar4[0x1e];
        pcVar11 = ((char *)(long)&s_main_thread_terminated_00148941 /* "main thread terminated" */);
        (*(int (*))(__fp - 0x14c)) = wVar13;
      }
    }
    Row_printLeftAlignedField(str,wVar13,pcVar11,0x19);
    goto LAB_0012c483;
  }
  RichString_appendAscii(str,(*(int (*))(__fp - 0x14c)),(*(char (*) [256])(__fp - 0x148)));
LAB_0012c483:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Process_rowWriteField @ 0x12cd50 */

void Process_rowWriteField(Process_ *super,RichString *str,RowField field)

{
  Process_writeField(super,str,field);
  return;
}

