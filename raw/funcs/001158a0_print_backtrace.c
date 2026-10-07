/* print_backtrace @ 001158a0 size 92 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_backtrace(void)

{
  long lVar1;
  int p1;
  long in_FS_OFFSET;
  void *backtraceArray [256];

                    /* Unresolved local var: size_t size@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  p1 = backtrace(backtraceArray,0x100);
  backtrace_symbols_fd(backtraceArray,p1,2);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

