/* ProcessTable_done @ 0012d110 size 66 */

/* DWARF original prototype: void ProcessTable_done(ProcessTable * this) */

void ProcessTable_done(ProcessTable *this)

{
  Hashtable *this_00;

  this_00 = (this->super).table;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  Vector_delete((this->super).displayList);
  Vector_delete((this->super).rows);
  return;
}

