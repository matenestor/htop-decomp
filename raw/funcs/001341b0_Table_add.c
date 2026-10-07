/* Table_add @ 001341b0 size 64 */

/* DWARF original prototype: void Table_add(Table * this, Row * row) */

void Table_add(Table *this,Row_2 *row)

{
  Vector *this_00;

  this_00 = this->rows;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
  row->seenStampMs = this->host->monotonicMs;
  Vector_set(this_00,this_00->items,row);
  Hashtable_put(this->table,row->id,row);
  return;
}

