/* DynamicColumn_done @ 00116be0 size 48 */

/* DWARF original prototype: void DynamicColumn_done(DynamicColumn * this) */

void DynamicColumn_done(DynamicColumn *this)

{
  free(this->heading);
  free(this->caption);
  free(this->description);
  return;
}

