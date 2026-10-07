/* CRT_disableDelay @ 001163d0 size 39 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_disableDelay(void)

{
  nocbreak();
  cbreak();
  nodelay(_stdscr,1);
  return;
}

