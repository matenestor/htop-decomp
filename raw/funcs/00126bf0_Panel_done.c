/* Panel_done @ 00126bf0 size 81 */

/* DWARF original prototype: void Panel_done(Panel * this) */

void Panel_done(Panel *this)

{
  free(this->eventHandlerState);
  Vector_delete(this->items);
  FunctionBar_delete(this->defaultBar);
  if ((this->header).chlen < L'ş') {
    return;
  }
  free((this->header).chptr);
  (this->header).chptr = (this->header).chstr;
  return;
}

