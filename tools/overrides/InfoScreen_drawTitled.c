void InfoScreen_drawTitled(InfoScreen *this,char *fmt,...)

{
  __builtin_va_list ap;
  int n;
  int len = COLS + 1;
  char title[len];

  __builtin_va_start(ap,fmt);
  n = vsnprintf(title,len,fmt,ap);
  __builtin_va_end(ap);
  if (COLS < n) {
    memset(title + (COLS - 3),'.',3);
  }
  wattrset(stdscr,CRT_colors[METER_TEXT]);
  if (wmove(stdscr,0,0) != -1) {
    whline(stdscr,' ',COLS);
  }
  if (wmove(stdscr,0,0) != -1) {
    waddnstr(stdscr,title,-1);
  }
  wattrset(stdscr,CRT_colors[DEFAULT_COLOR]);
  Panel_draw(this->display,true,true,true,false);
  IncSet_drawBar(this->inc,CRT_colors[FUNCTION_BAR]);
}
