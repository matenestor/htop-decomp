/* actionRedraw @ 00114830 size 30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionRedraw(State_2 *st)

{
  wclear(_stdscr);
  return HTOP_REDRAW_BAR|HTOP_RECALCULATE;
}

