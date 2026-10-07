/* TraceScreen_updateTrace @ 0012fc60 size 419 */

void TraceScreen_updateTrace(TraceScreen_ *super)

{
  char *pcVar1;
  _Bool _Var2;
  long lVar3;
  Panel *a0;
  code *pcVar4;
  int iVar5;
  int iVar6;
  wchar_t wVar7;
  size_t sVar8;
  long lVar9;
  FILE_2 *__stream;
  char *pcVar10;
  char *line;
  fd_set *pfVar11;
  timeval *__timeout;
  long in_R9;
  ulong uVar12;
  long in_FS_OFFSET;
  byte bVar13;
  timeval tv;
  fd_set fds;
  char buffer [1025];

  bVar13 = 0;
                    /* Unresolved local var: uint __i@[???]
                       Unresolved local var: fd_set * __arr@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = fileno((FILE_2 *)super->strace);
  pfVar11 = &fds;
  for (lVar9 = 0x10; lVar9 != 0; lVar9 = lVar9 + -1) {
    pfVar11->fds_bits[0] = 0;
    pfVar11 = (fd_set *)((long)pfVar11 + ((ulong)bVar13 * -2 + 1) * 8);
  }
                    /* Unresolved local var: long __d@[???] */
  lVar9 = __fdelt_chk((long)iVar5);
  uVar12 = 1L << ((byte)iVar5 & 0x3f);
  __timeout = &tv;
  fds.fds_bits[lVar9] = fds.fds_bits[lVar9] | uVar12;
  tv.tv_sec = 0;
  tv.tv_usec = 500;
  iVar6 = select(iVar5 + 1,&fds,(fd_set *)0x0,(fd_set *)0x0,__timeout);
                    /* Unresolved local var: long __d@[???] */
  if ((0 < iVar6) && (lVar9 = __fdelt_chk((long)iVar5), (uVar12 & fds.fds_bits[lVar9]) != 0)) {
                    /* Unresolved local var: size_t sz@[???] */
    __stream = (FILE_2 *)super->strace;
    sVar8 = fread(buffer,1,0x400,__stream);
    if ((sVar8 != 0) && (super->tracing != false)) {
                    /* Unresolved local var: char * line@[???] */
      pcVar10 = buffer + 1;
      buffer[sVar8] = '\0';
                    /* Unresolved local var: size_t i@[???] */
      pcVar1 = pcVar10 + sVar8;
      line = buffer;
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
      if (line < buffer + sVar8) {
        InfoScreen_addLine(&super->super,line);
        super->contLine = true;
        buffer[sVar8] = '\0';
      }
      if (super->follow != false) {
        a0 = (super->super).display;
                    /* Unresolved local var: wchar_t size@[???] */
        wVar7 = a0->items->items + L'\xffffffff';
        if (wVar7 < L'\0') {
          wVar7 = L'\0';
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

