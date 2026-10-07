/* Row_toggleTag @ 0012da70 size 9 */

/* DWARF original prototype: void Row_toggleTag(Row * this) */

void Row_toggleTag(Row *this)

{
  this->tag = (_Bool)(this->tag ^ 1);
  return;
}

