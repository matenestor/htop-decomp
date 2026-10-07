/* actionShowLocks @ 0011aa60 size 128 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionShowLocks(State_2 *st)

{
  Vector *pVVar1;
  Process_2 *process;
  ProcessLocksScreen *this;

                    /* Unresolved local var: Settings * settings@[???] */
  if (st->host->settings->ss->dynamic == (char *)0x0) {
    pVVar1 = (st->mainPanel->super).items;
    if ((L'\0' < pVVar1->items) &&
       (process = (Process_2 *)pVVar1->array[(st->mainPanel->super).selected],
       process != (Process_2 *)0x0)) {
      this = ProcessLocksScreen_new(process);
      InfoScreen_run(&this->super);
      CommandScreen_delete((Object *)this);
      wclear(_stdscr);
      halfdelay(*CRT_delay);
      return HTOP_REDRAW_BAR|HTOP_REFRESH;
    }
  }
  return HTOP_OK;
}

