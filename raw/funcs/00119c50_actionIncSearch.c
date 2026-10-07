/* actionIncSearch @ 00119c50 size 86 */

Htop_Reaction actionIncSearch(State_2 *st)

{
  MainPanel__2 *pMVar1;
  IncSet *this;
  FunctionBar *pFVar2;

  pMVar1 = st->mainPanel;
  this = pMVar1->inc;
  pFVar2 = this->modes[0].bar;
  this->modes[0].buffer[0] = '\0';
  this->modes[0].index = L'\0';
  this->active = this->modes;
  (pMVar1->super).currentBar = pFVar2;
  (pMVar1->super).cursorOn = true;
  this->panel = &pMVar1->super;
  IncSet_drawBar(this,CRT_colors[2]);
  return HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
}

