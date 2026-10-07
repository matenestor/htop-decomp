/* Hashtable_put @ 00118280 size 113 */

/* DWARF original prototype: void Hashtable_put(Hashtable * this, ht_key_t key, void * value) */

void Hashtable_put(Hashtable *this,ht_key_t key,void *value)

{
  size_t sVar1;

  sVar1 = this->size;
  if (sVar1 * 7 < this->items * 10) {
    if ((long)sVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      CRT_fatalError(((char *)0x147202 /* "Hashtable: size overflow" */));
    }
                    /* Unresolved local var: size_t newSize@[???]
                       Unresolved local var: HashtableItem * oldBuckets@[???]
                       Unresolved local var: size_t oldSize@[???] */
    if (this->items < sVar1 * 2) {
      Hashtable_setSize(this,sVar1 * 2);
    }
  }
  insert(this,key,value);
  return;
}

