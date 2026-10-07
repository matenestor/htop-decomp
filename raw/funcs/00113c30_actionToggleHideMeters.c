/* actionToggleHideMeters @ 00113c30 size 14 */

Htop_Reaction actionToggleHideMeters(State_2 *st)

{
  st->hideMeters = (_Bool)(st->hideMeters ^ 1);
  return 0xe9;
}

