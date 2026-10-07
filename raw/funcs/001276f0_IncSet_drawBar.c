/* IncSet_drawBar @ 001276f0 size 137 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void IncSet_drawBar(IncSet * this, wchar_t attr) */

void IncSet_drawBar(IncSet *this,wchar_t attr)

{
  IncMode *buffer;
  Panel *pPVar1;
  wchar_t wVar2;

  buffer = this->active;
  if (buffer != (IncMode *)0x0) {
                    /* Unresolved local var: wchar_t cursorX@[???] */
    if ((buffer->isFilter == false) && (this->found == false)) {
      attr = CRT_colors[4];
    }
    wVar2 = FunctionBar_drawExtra(buffer->bar,buffer->buffer,attr,true);
    pPVar1 = this->panel;
    pPVar1->cursorX = wVar2;
    pPVar1->cursorY = _LINES + L'\xffffffff';
    return;
  }
  FunctionBar_drawExtra(this->defaultBar,(char *)0x0,L'\xffffffff',false);
  return;
}

