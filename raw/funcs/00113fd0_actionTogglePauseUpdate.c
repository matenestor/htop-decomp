/* actionTogglePauseUpdate @ 00113fd0 size 14 */

Htop_Reaction actionTogglePauseUpdate(State_2 *st)

{
  st->pauseUpdate = (_Bool)(st->pauseUpdate ^ 1);
  return HTOP_REDRAW_BAR|HTOP_REFRESH;
}

