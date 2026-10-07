/* Table_done @ 0012f930 size 66 */

/* DWARF original prototype: void Table_done(Table * this) */

void Table_done(Table *this)

{
  Hashtable *this_00;

  this_00 = this->table;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  Vector_delete(this->displayList);
  Vector_delete(this->rows);
  return;
}

