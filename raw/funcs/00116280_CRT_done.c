/* CRT_done @ 00116280 size 203 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_done(void)

{
  int iVar1;
  wchar_t p1;

  p1 = CRT_colorSchemes[0][0];
  if (CRT_colors != (wchar_t *)0x0) {
    p1 = *CRT_colors;
  }
  wattr_on(_stdscr,p1,(void *)0x0);
  iVar1 = wmove(_stdscr,_LINES + -1,0);
  if (iVar1 != -1) {
    whline(_stdscr,0x20,_COLS);
  }
  wattr_off(_stdscr,p1,(void *)0x0);
  wrefresh(_stdscr);
  if (CRT_retainScreenOnExit != false) {
    mvcur(-1,-1,_LINES + -1,0);
  }
  curs_set(1);
  endwin();
  return;
}

