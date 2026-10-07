/* actionIncFilter @ 00119bd0 size 128 */

Htop_Reaction actionIncFilter(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Machine *pMVar2;
  IncSet *this;
  FunctionBar *pFVar3;
  IncMode *pIVar4;

  pMVar1 = st->mainPanel;
  pMVar2 = st->host;
  this = pMVar1->inc;
  pFVar3 = this->modes[1].bar;
  this->active = this->modes + 1;
  (pMVar1->super).currentBar = pFVar3;
  (pMVar1->super).cursorOn = true;
  this->panel = &pMVar1->super;
  IncSet_drawBar(this,CRT_colors[2]);
  pIVar4 = this->modes + 1;
  if (this->filtering == false) {
    pIVar4 = (IncMode *)0x0;
  }
  pMVar2->activeTable->incFilter = pIVar4->buffer;
  return HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
}

