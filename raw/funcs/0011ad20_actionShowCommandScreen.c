/* actionShowCommandScreen @ 0011ad20 size 185 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionShowCommandScreen(State_2 *st)

{
  Vector *pVVar1;
  Process *process;
  Htop_Reaction HVar2;
  InfoScreen *this;
  InfoScreen_2 *this_00;

                    /* Unresolved local var: Settings * settings@[???] */
  HVar2 = HTOP_OK;
  if (st->host->settings->ss->dynamic == (char *)0x0) {
    pVVar1 = (st->mainPanel->super).items;
    if (L'\0' < pVVar1->items) {
      process = (Process *)pVVar1->array[(st->mainPanel->super).selected];
      if (process != (Process *)0x0) {
                    /* Unresolved local var: CommandScreen * this@[???]
                       Unresolved local var: void * data@[???] */
        this = malloc(0x28);
        if (this == (InfoScreen *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        (this->super).klass = &CommandScreen_class.super;
        this_00 = InfoScreen_init(this,process,(FunctionBar *)0x0,_LINES + L'\xfffffffe',((char *)0x1470dd /* " " */));
        InfoScreen_run((InfoScreen *)this_00);
        CommandScreen_delete(&this_00->super);
        wclear(_stdscr);
        halfdelay(*CRT_delay);
        HVar2 = HTOP_REDRAW_BAR|HTOP_REFRESH;
      }
      return HVar2;
    }
  }
  return HTOP_OK;
}

