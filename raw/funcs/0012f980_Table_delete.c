/* Table_delete @ 0012f980 size 74 */

void Table_delete(Table_ *cast)

{
  Hashtable *this;

  this = cast->table;
  Hashtable_clear(this);
  free(this->buckets);
  free(this);
  Vector_delete(cast->displayList);
  Vector_delete(cast->rows);
  free(cast);
  return;
}

