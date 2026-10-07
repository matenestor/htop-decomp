/* InfoScreen_done @ 00126cf0 size 134 */

/* DWARF original prototype: InfoScreen * InfoScreen_done(InfoScreen * this) */

InfoScreen_2 * InfoScreen_done(InfoScreen *this)

{
  Panel *__ptr;
  IncSet *__ptr_00;

  __ptr = this->display;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(__ptr->eventHandlerState);
  Vector_delete(__ptr->items);
  FunctionBar_delete(__ptr->defaultBar);
  if (L'Ş' < (__ptr->header).chlen) {
    free((__ptr->header).chptr);
  }
  free(__ptr);
  __ptr_00 = this->inc;
  FunctionBar_delete(__ptr_00->modes[0].bar);
  FunctionBar_delete(__ptr_00->modes[1].bar);
  free(__ptr_00);
  Vector_delete(this->lines);
  return (InfoScreen_2 *)this;
}

