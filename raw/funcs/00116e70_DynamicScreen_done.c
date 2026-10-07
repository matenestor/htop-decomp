/* DynamicScreen_done @ 00116e70 size 66 */

/* DWARF original prototype: void DynamicScreen_done(DynamicScreen * this) */

void DynamicScreen_done(DynamicScreen *this)

{
  free(this->caption);
  free(this->fields);
  free(this->heading);
  free(this->sortKey);
  free(this->columnKeys);
  return;
}

