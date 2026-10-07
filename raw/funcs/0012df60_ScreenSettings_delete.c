/* ScreenSettings_delete @ 0012df60 size 55 */

/* DWARF original prototype: void ScreenSettings_delete(ScreenSettings * this) */

void ScreenSettings_delete(ScreenSettings *this)

{
  free(this->heading);
  free(this->dynamic);
  free(this->fields);
  free(this);
  return;
}

