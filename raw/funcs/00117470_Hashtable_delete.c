/* Hashtable_delete @ 00117470 size 43 */

/* DWARF original prototype: void Hashtable_delete(Hashtable * this) */

void Hashtable_delete(Hashtable *this)

{
  Hashtable_clear(this);
  free(this->buckets);
  free(this);
  return;
}

