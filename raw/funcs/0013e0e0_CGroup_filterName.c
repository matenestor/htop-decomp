/* CGroup_filterName @ 0013e0e0 size 207 */

char * CGroup_filterName(char *cgroup)

{
  long lVar1;
  size_t sVar2;
  _Bool _Var3;
  char *pcVar4;
  long in_FS_OFFSET;
  StrBuf_state s;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  s.buf = (char *)0x0;
  s.size = 0;
  s.pos = 0;
  _Var3 = CGroup_filterName_internal(cgroup,&s,StrBuf_putc_count);
  if (_Var3) {
    sVar2 = s.pos;
                    /* Unresolved local var: void * data@[???] */
    pcVar4 = calloc(s.pos + 1,1);
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    s.pos = 0;
    s.size = sVar2;
    s.buf = pcVar4;
    _Var3 = CGroup_filterName_internal(cgroup,&s,StrBuf_putc_write);
    if (_Var3) {
      s.buf[s.size] = '\0';
      pcVar4 = s.buf;
      goto LAB_0013e177;
    }
    free(s.buf);
  }
  pcVar4 = (char *)0x0;
LAB_0013e177:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

