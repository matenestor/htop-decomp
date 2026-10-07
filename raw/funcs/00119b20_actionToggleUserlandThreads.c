/* actionToggleUserlandThreads @ 00119b20 size 35 */

Htop_Reaction actionToggleUserlandThreads(State_2 *st)

{
  _Bool *p_Var1;
  uint64_t *puVar2;
  Machine *this;
  Settings__2 *pSVar3;

  this = st->host;
  pSVar3 = this->settings;
  p_Var1 = &pSVar3->hideUserlandThreads;
  *p_Var1 = (_Bool)(*p_Var1 ^ 1);
  puVar2 = &pSVar3->lastUpdate;
  *puVar2 = *puVar2 + 1;
  Machine_scanTables(this);
  return HTOP_KEEP_FOLLOWING|HTOP_SAVE_SETTINGS|HTOP_RECALCULATE;
}

