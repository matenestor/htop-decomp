/* IncSet_synthesizeEvent @ 00128660 size 40 */

/* DWARF original prototype: wchar_t IncSet_synthesizeEvent(IncSet * this, wchar_t x) */

wchar_t IncSet_synthesizeEvent(IncSet *this,wchar_t x)

{
  wchar_t wVar1;

  if (this->active != (IncMode *)0x0) {
    wVar1 = FunctionBar_synthesizeEvent(this->active->bar,x);
    return wVar1;
  }
  wVar1 = FunctionBar_synthesizeEvent(this->defaultBar,x);
  return wVar1;
}

