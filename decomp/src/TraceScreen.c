#include "htop.h"

/* TraceScreen_forkTracer @ 0x12e8e0 */

/* DWARF original prototype: _Bool TraceScreen_forkTracer(TraceScreen * this) */

_Bool TraceScreen_forkTracer(TraceScreen *this)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  _Bool _Var2;
  int iVar3;
  __pid_t _Var4;
  int wVar5;
  FILE_2 *pFVar6;
  undefined4 extraout_var;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (*(int (*) [2])(__fp - 0x60))[0] = 0;
  (*(int (*) [2])(__fp - 0x60))[1] = 0;
  iVar3 = pipe((*(int (*) [2])(__fp - 0x60)));
  if (iVar3 != -1) {
    iVar3 = fcntl((*(int (*) [2])(__fp - 0x60))[0],4,0x800);
    if (-1 < iVar3) {
      iVar3 = fcntl((*(int (*) [2])(__fp - 0x60))[1],4,0x800);
      if (-1 < iVar3) {
        _Var4 = fork();
        if (_Var4 != -1) {
                    /* Unresolved local var: char * message@[???] */
          if (_Var4 == 0) {
            close((*(int (*) [2])(__fp - 0x60))[0]);
            dup2((*(int (*) [2])(__fp - 0x60))[1],1);
            dup2((*(int (*) [2])(__fp - 0x60))[1],2);
            close((*(int (*) [2])(__fp - 0x60))[1]);
            (*(char (*) [32])(__fp - 0x58))[0] = '\0';
            (*(char (*) [32])(__fp - 0x58))[1] = '\0';
            (*(char (*) [32])(__fp - 0x58))[2] = '\0';
            (*(char (*) [32])(__fp - 0x58))[3] = '\0';
            (*(char (*) [32])(__fp - 0x58))[4] = '\0';
            (*(char (*) [32])(__fp - 0x58))[5] = '\0';
            (*(char (*) [32])(__fp - 0x58))[6] = '\0';
            (*(char (*) [32])(__fp - 0x58))[7] = '\0';
            (*(char (*) [32])(__fp - 0x58))[8] = '\0';
            (*(char (*) [32])(__fp - 0x58))[9] = '\0';
            (*(char (*) [32])(__fp - 0x58))[10] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0xb] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0xc] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0xd] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0xe] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0xf] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x10] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x11] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x12] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x13] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x14] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x15] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x16] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x17] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x18] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x19] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x1a] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x1b] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x1c] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x1d] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x1e] = '\0';
            (*(char (*) [32])(__fp - 0x58))[0x1f] = '\0';
            wVar5 = xSnprintf((*(char (*) [32])(__fp - 0x58)),0x20,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(((this->super).process)->super).id);
            execlp(((char *)(long)(__sec_rodata + 0xff8) /* "strace" */),((char *)(long)(__sec_rodata + 0xff8) /* "strace" */),&DAT_00148c3c,&DAT_00148c38,&DAT_00148c35,&DAT_00148c31,
                   &DAT_001488f5,(*(char (*) [32])(__fp - 0x58)),0,CONCAT44(extraout_var,wVar5));
            write(2,((char *)(long)&s_Could_not_execute__strace___Plea_0014c6c0 /* "Could not execute \'strace\'. Please make sure it is available in your $PATH." */),
                  0x4b);
                    /* WARNING: Subroutine does not return */
            exit(0x7f);
          }
          pFVar6 = fdopen((*(int (*) [2])(__fp - 0x60))[0],((char *)(long)&DAT_00147760 /* "r" */));
          if (pFVar6 != (FILE_2 *)0x0) {
            close((*(int (*) [2])(__fp - 0x60))[1]);
            this->child = _Var4;
            _Var2 = true;
            this->strace = (FILE *)pFVar6;
            goto LAB_0012e9a2;
          }
        }
      }
    }
    close((*(int (*) [2])(__fp - 0x60))[1]);
    close((*(int (*) [2])(__fp - 0x60))[0]);
  }
  _Var2 = false;
LAB_0012e9a2:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* TraceScreen_delete @ 0x12ec10 */

void TraceScreen_delete(TraceScreen_ *cast)

{
  Panel *__ptr;
  IncSet *__ptr_00;
  __pid_t _Var1;
  int *piVar2;

  if (0 < cast->child) {
    kill(cast->child,0xf);
    do {
      _Var1 = waitpid(cast->child,(int *)0x0,0);
      if (_Var1 != -1) break;
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
  }
  if ((FILE_2 *)cast->strace != (FILE_2 *)0x0) {
    fclose((FILE_2 *)cast->strace);
  }
  halfdelay(*CRT_delay);
  __ptr = (cast->super).display;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(__ptr->eventHandlerState);
  Vector_delete(__ptr->items);
  FunctionBar_delete(__ptr->defaultBar);
  if (350 < (__ptr->header).chlen) {
    free((__ptr->header).chptr);
  }
  free(__ptr);
  __ptr_00 = (cast->super).inc;
  FunctionBar_delete(__ptr_00->modes[0].bar);
  FunctionBar_delete(__ptr_00->modes[1].bar);
  free(__ptr_00);
  Vector_delete((cast->super).lines);
  free(cast);
  return;
}


/* TraceScreen_draw @ 0x12fc10 */

/* DWARF original prototype: void TraceScreen_draw(InfoScreen * this) */

void TraceScreen_draw(InfoScreen *this)

{
  Process *pPVar1;
  char *va1;

  pPVar1 = this->process;
                    /* Unresolved local var: Settings * settings@[???] */
  if (((pPVar1->isUserlandThread != false) &&
      (((pPVar1->super).host)->settings->showThreadNames != false)) ||
     (va1 = (pPVar1->mergedCommand).str, va1 == (char *)0x0)) {
    va1 = pPVar1->cmdline;
  }
  InfoScreen_drawTitled(this,((char *)(long)&s_Trace_of_process__d____s_00148ff0 /* "Trace of process %d - %s" */),(pPVar1->super).id,va1);
  return;
}


/* TraceScreen_updateTrace @ 0x12fc60 */

void TraceScreen_updateTrace(TraceScreen_ *super)

{
  undefined1 __frame[0x568] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x528;
  char *pcVar1;
  _Bool _Var2;
  long lVar3;
  Panel *a0;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int wVar7;
  size_t sVar8;
  long lVar9;
  FILE_2 *__stream;
  char *pcVar10;
  char *line;
  fd_set *pfVar11;
  timeval *__timeout;
  long in_R9;
  ulong uVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar13;

  bVar13 = 0;
                    /* Unresolved local var: uint __i@[???]
                       Unresolved local var: fd_set * __arr@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = fileno((FILE_2 *)super->strace);
  pfVar11 = &(*(fd_set (*))(__fp - 0x4c8));
  for (lVar9 = 0x10; lVar9 != 0; lVar9 = lVar9 + -1) {
    pfVar11->fds_bits[0] = 0;
    pfVar11 = (fd_set *)((long)pfVar11 + ((ulong)bVar13 * -2 + 1) * 8);
  }
                    /* Unresolved local var: long __d@[???] */
  lVar9 = __fdelt_chk((long)iVar5);
  uVar12 = 1L << ((byte)iVar5 & 0x3f);
  __timeout = &(*(timeval (*))(__fp - 0x4d8));
  (*(fd_set (*))(__fp - 0x4c8)).fds_bits[lVar9] = (*(fd_set (*))(__fp - 0x4c8)).fds_bits[lVar9] | uVar12;
  (*(timeval (*))(__fp - 0x4d8)).tv_sec = 0;
  (*(timeval (*))(__fp - 0x4d8)).tv_usec = 500;
  iVar6 = select(iVar5 + 1,&(*(fd_set (*))(__fp - 0x4c8)),(fd_set *)0x0,(fd_set *)0x0,__timeout);
                    /* Unresolved local var: long __d@[???] */
  if ((0 < iVar6) && (lVar9 = __fdelt_chk((long)iVar5), (uVar12 & (*(fd_set (*))(__fp - 0x4c8)).fds_bits[lVar9]) != 0)) {
                    /* Unresolved local var: size_t sz@[???] */
    __stream = (FILE_2 *)super->strace;
    sVar8 = fread((*(char (*) [1025])(__fp - 0x448)),1,0x400,__stream);
    if ((sVar8 != 0) && (super->tracing != false)) {
                    /* Unresolved local var: char * line@[???] */
      pcVar10 = (*(char (*) [1025])(__fp - 0x448)) + 1;
      (*(char (*) [1025])(__fp - 0x448))[sVar8] = '\0';
                    /* Unresolved local var: size_t i@[???] */
      pcVar1 = pcVar10 + sVar8;
      line = (*(char (*) [1025])(__fp - 0x448));
      do {
        if (pcVar10[-1] == '\n') {
          _Var2 = super->contLine;
          pcVar10[-1] = '\0';
          if (_Var2 == false) {
            InfoScreen_addLine(&super->super,line);
            line = pcVar10;
          }
          else {
            InfoScreen_appendLine(&super->super,line);
            super->contLine = false;
            line = pcVar10;
          }
        }
        pcVar10 = pcVar10 + 1;
      } while (pcVar1 != pcVar10);
      if (line < (*(char (*) [1025])(__fp - 0x448)) + sVar8) {
        InfoScreen_addLine(&super->super,line);
        super->contLine = true;
        (*(char (*) [1025])(__fp - 0x448))[sVar8] = '\0';
      }
      if (super->follow != false) {
        a0 = (super->super).display;
                    /* Unresolved local var: int size@[???] */
        wVar7 = a0->items->items + -1;
        if (wVar7 < 0) {
          wVar7 = 0;
        }
        a0->selected = wVar7;
        pcVar4 = (a0->super).klass[1].extends;
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)((long)a0,0xffffffff,0,(long)__stream,(long)__timeout,in_R9);
        }
      }
    }
  }
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* TraceScreen_onKey @ 0x12fe10 */

_Bool TraceScreen_onKey(TraceScreen_ *super,int ch)

{
  _Bool *p_Var1;
  Panel *a0;
  code *pcVar2;
  _Bool _Var3;
  int wVar4;
  long in_RCX;
  char *text;
  long a2;
  RichString *pRVar5;
  long in_R8;
  long in_R9;

  if (ch == 272) {
LAB_0012fe80:
    p_Var1 = &super->follow;
    *p_Var1 = (_Bool)(*p_Var1 ^ 1);
    if (*p_Var1 != false) {
      a0 = (super->super).display;
                    /* Unresolved local var: int size@[???] */
      wVar4 = a0->items->items + -1;
      if (wVar4 < 0) {
        wVar4 = 0;
      }
      a0->selected = wVar4;
      pcVar2 = (a0->super).klass[1].extends;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)((long)a0,0xffffffff,0,in_RCX,in_R8,in_R9);
      }
    }
LAB_0012fe79:
    _Var3 = true;
  }
  else {
    if (ch < 273) {
      if (ch == 'f') goto LAB_0012fe80;
      if (ch == 't') goto LAB_0012fe48;
    }
    else if (ch == 273) {
LAB_0012fe48:
      p_Var1 = &super->tracing;
      *p_Var1 = (_Bool)(*p_Var1 ^ 1);
      pRVar5 = (RichString *)0x111;
      text = ((char *)(long)&s_Resume_Tracing_00149019 /* "Resume Tracing " */);
      if (*p_Var1 != false) {
        text = ((char *)(long)&s_Stop_Tracing_00149009 /* "Stop Tracing   " */);
      }
      FunctionBar_setLabel(((super->super).display)->defaultBar,273,text);
      (*(code *)((super->super).super.klass[1].display))((Object *)super,pRVar5,a2,in_RCX,in_R8,in_R9);
      goto LAB_0012fe79;
    }
    super->follow = false;
    _Var3 = false;
  }
  return _Var3;
}


/* TraceScreen_new @ 0x132bb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TraceScreen * TraceScreen_new(Process *process)

{
  InfoScreen *this;
  FunctionBar *bar;
  TraceScreen *pTVar1;

                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x40);
  if (this != (InfoScreen *)0x0) {
    *(undefined1 *)&this[1].super.klass = 1;
    (this->super).klass = &TraceScreen_class.super;
    bar = FunctionBar_new(TraceScreenFunctions,TraceScreenKeys,((char *)(long)&TraceScreenEvents /* L"ċČĐđ\x1b" */));
    nocbreak();
    cbreak();
    nodelay(_stdscr,1);
    pTVar1 = (TraceScreen *)InfoScreen_init(this,process,bar,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
    return pTVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

