/* actionStrace @ 0011aaf0 size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionStrace(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  _Bool _Var2;
  TraceScreen *this;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  if ((!readonly) && (st->host->settings->ss->dynamic == (char *)0x0)) {
    pVVar1 = (st->mainPanel->super).items;
    if ((L'\0' < pVVar1->items) &&
       (process = (Process *)pVVar1->array[(st->mainPanel->super).selected],
       process != (Process *)0x0)) {
      this = TraceScreen_new(process);
      _Var2 = TraceScreen_forkTracer(this);
      if (_Var2) {
        InfoScreen_run(&this->super);
      }
      TraceScreen_delete(this);
      wclear(_stdscr);
      halfdelay(*CRT_delay);
      return HTOP_REDRAW_BAR|HTOP_REFRESH;
    }
  }
  return HTOP_OK;
}

