/* MainPanel_updateLabels @ 00129160 size 88 */

/* DWARF original prototype: void MainPanel_updateLabels(MainPanel * this, _Bool list, _Bool filter)
    */

void MainPanel_updateLabels(MainPanel *this,_Bool list,_Bool filter)

{
  FunctionBar *this_00;
  char *pcVar1;

  this_00 = (this->super).defaultBar;
  pcVar1 = ((char *)0x14750f /* "Tree  " */);
  if (list) {
    pcVar1 = ((char *)0x147508 /* "List  " */);
  }
  FunctionBar_setLabel(this_00,L'č',pcVar1);
  pcVar1 = ((char *)0x14751d /* "Filter" */);
  if (filter) {
    pcVar1 = ((char *)0x147516 /* "FILTER" */);
  }
  FunctionBar_setLabel(this_00,L'Č',pcVar1);
  return;
}

