/* CRT_readKey @ 00115c40 size 72 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

wchar_t CRT_readKey(void)

{
  wchar_t wVar1;

  nocbreak();
  cbreak();
  nodelay(_stdscr,0);
  wVar1 = wgetch(_stdscr);
  halfdelay(*CRT_delay);
  return wVar1;
}

