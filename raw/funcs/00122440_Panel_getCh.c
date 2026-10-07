/* Panel_getCh @ 00122440 size 89 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: wchar_t Panel_getCh(Panel * this) */

wchar_t Panel_getCh(Panel *this)

{
  wchar_t wVar1;

  if (this->cursorOn == false) {
    curs_set(0);
  }
  else {
    wmove(_stdscr,this->cursorY,this->cursorX);
    curs_set(1);
  }
  set_escdelay(0x19);
  wVar1 = wgetch(_stdscr);
  return wVar1;
}

