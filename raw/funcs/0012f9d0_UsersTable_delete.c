/* UsersTable_delete @ 0012f9d0 size 55 */

/* DWARF original prototype: void UsersTable_delete(UsersTable * this) */

void UsersTable_delete(UsersTable *this)

{
  Hashtable *this_00;

  this_00 = this->users;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  free(this);
  return;
}

