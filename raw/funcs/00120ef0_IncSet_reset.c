/* IncSet_reset @ 00120ef0 size 32 */

/* DWARF original prototype: void IncSet_reset(IncSet * this, IncType type) */

void IncSet_reset(IncSet *this,IncType type)

{
  this->modes[type].index = L'\0';
  this->modes[type].buffer[0] = '\0';
  return;
}

