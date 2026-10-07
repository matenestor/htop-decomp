/* IncSet_activate @ 00127780 size 136 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void IncSet_activate(IncSet * this, IncType type, Panel * panel) */

void IncSet_activate(IncSet *this,IncType type,Panel *panel)

{
  IncMode *buffer;
  FunctionBar *this_00;
  Panel *pPVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;

  buffer = this->modes + type;
  this->active = buffer;
  this_00 = buffer->bar;
  panel->cursorOn = true;
  pwVar2 = CRT_colors;
  panel->currentBar = this_00;
  this->panel = panel;
                    /* Unresolved local var: wchar_t cursorX@[???] */
  wVar3 = pwVar2[2];
  if ((buffer->isFilter == false) && (this->found == false)) {
    wVar3 = pwVar2[4];
  }
  wVar3 = FunctionBar_drawExtra(this_00,buffer->buffer,wVar3,true);
  pPVar1 = this->panel;
  pPVar1->cursorX = wVar3;
  pPVar1->cursorY = _LINES + L'\xffffffff';
  return;
}

