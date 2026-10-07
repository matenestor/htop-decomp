/* actionLsof @ 0011a9d0 size 137 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionLsof(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  OpenFilesScreen *this;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  if ((!readonly) && (st->host->settings->ss->dynamic == (char *)0x0)) {
    pVVar1 = (st->mainPanel->super).items;
    if ((L'\0' < pVVar1->items) &&
       (process = (Process *)pVVar1->array[(st->mainPanel->super).selected],
       process != (Process *)0x0)) {
      this = OpenFilesScreen_new(process);
      InfoScreen_run(&this->super);
      CommandScreen_delete((Object *)this);
      wclear(_stdscr);
      halfdelay(*CRT_delay);
      return HTOP_REDRAW_BAR|HTOP_REFRESH;
    }
  }
  return HTOP_OK;
}

