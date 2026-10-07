/* IncSet_delete @ 00126cb0 size 53 */

/* DWARF original prototype: void IncSet_delete(IncSet * this) */

void IncSet_delete(IncSet *this)

{
  FunctionBar_delete(this->modes[0].bar);
  FunctionBar_delete(this->modes[1].bar);
  free(this);
  return;
}

