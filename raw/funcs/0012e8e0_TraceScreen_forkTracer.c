/* TraceScreen_forkTracer @ 0012e8e0 size 398 */

/* DWARF original prototype: _Bool TraceScreen_forkTracer(TraceScreen * this) */

_Bool TraceScreen_forkTracer(TraceScreen *this)

{
  long lVar1;
  _Bool _Var2;
  int iVar3;
  __pid_t _Var4;
  wchar_t wVar5;
  FILE_2 *pFVar6;
  undefined4 extraout_var;
  long in_FS_OFFSET;
  wchar_t fdpair [2];
  char buffer [32];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  fdpair[0] = L'\0';
  fdpair[1] = L'\0';
  iVar3 = pipe(fdpair);
  if (iVar3 != -1) {
    iVar3 = fcntl(fdpair[0],4,0x800);
    if (-1 < iVar3) {
      iVar3 = fcntl(fdpair[1],4,0x800);
      if (-1 < iVar3) {
        _Var4 = fork();
        if (_Var4 != -1) {
                    /* Unresolved local var: char * message@[???] */
          if (_Var4 == 0) {
            close(fdpair[0]);
            dup2(fdpair[1],1);
            dup2(fdpair[1],2);
            close(fdpair[1]);
            buffer[0] = '\0';
            buffer[1] = '\0';
            buffer[2] = '\0';
            buffer[3] = '\0';
            buffer[4] = '\0';
            buffer[5] = '\0';
            buffer[6] = '\0';
            buffer[7] = '\0';
            buffer[8] = '\0';
            buffer[9] = '\0';
            buffer[10] = '\0';
            buffer[0xb] = '\0';
            buffer[0xc] = '\0';
            buffer[0xd] = '\0';
            buffer[0xe] = '\0';
            buffer[0xf] = '\0';
            buffer[0x10] = '\0';
            buffer[0x11] = '\0';
            buffer[0x12] = '\0';
            buffer[0x13] = '\0';
            buffer[0x14] = '\0';
            buffer[0x15] = '\0';
            buffer[0x16] = '\0';
            buffer[0x17] = '\0';
            buffer[0x18] = '\0';
            buffer[0x19] = '\0';
            buffer[0x1a] = '\0';
            buffer[0x1b] = '\0';
            buffer[0x1c] = '\0';
            buffer[0x1d] = '\0';
            buffer[0x1e] = '\0';
            buffer[0x1f] = '\0';
            wVar5 = xSnprintf(buffer,0x20,((char *)0x149710 /* "%d" */),(((this->super).process)->super).id);
            execlp(((char *)0x147ff8 /* "strace" */),((char *)0x147ff8 /* "strace" */),&DAT_00148c3c,&DAT_00148c38,&DAT_00148c35,&DAT_00148c31,
                   &DAT_001488f5,buffer,0,CONCAT44(extraout_var,wVar5));
            write(2,((char *)0x14c6c0 /* "Could not execute \'strace\'. Please make sure it is available in your $PATH." */),
                  0x4b);
                    /* WARNING: Subroutine does not return */
            exit(0x7f);
          }
          pFVar6 = fdopen(fdpair[0],((char *)0x147760 /* "r" */));
          if (pFVar6 != (FILE_2 *)0x0) {
            close(fdpair[1]);
            this->child = _Var4;
            _Var2 = true;
            this->strace = (FILE *)pFVar6;
            goto LAB_0012e9a2;
          }
        }
      }
    }
    close(fdpair[1]);
    close(fdpair[0]);
  }
  _Var2 = false;
LAB_0012e9a2:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

