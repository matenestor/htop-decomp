/* actionToggleRunningInContainer @ 00113b60 size 25 */

Htop_Reaction actionToggleRunningInContainer(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Settings__2 *pSVar3;

  pSVar3 = st->host->settings;
  p_Var1 = &pSVar3->hideRunningInContainer;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  return HTOP_KEEP_FOLLOWING|HTOP_SAVE_SETTINGS|HTOP_RECALCULATE;
}

