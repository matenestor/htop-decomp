/* CRT_resetSignalHandlers @ 001161c0 size 178 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_resetSignalHandlers(void)

{
  sigaction(0xb,(sigaction_2 *)(old_sig_handler + 0xb),(sigaction_2 *)0x0);
  sigaction(8,(sigaction_2 *)(old_sig_handler + 8),(sigaction_2 *)0x0);
  sigaction(4,(sigaction_2 *)(old_sig_handler + 4),(sigaction_2 *)0x0);
  sigaction(7,(sigaction_2 *)(old_sig_handler + 7),(sigaction_2 *)0x0);
  sigaction(0xd,(sigaction_2 *)(old_sig_handler + 0xd),(sigaction_2 *)0x0);
  sigaction(0x1f,(sigaction_2 *)(old_sig_handler + 0x1f),(sigaction_2 *)0x0);
  sigaction(6,(sigaction_2 *)(old_sig_handler + 6),(sigaction_2 *)0x0);
  signal(2,(__sighandler_t_2)0x0);
  signal(0xf,(__sighandler_t_2)0x0);
  signal(3,(__sighandler_t_2)0x0);
  return;
}

