/* Hashtable_foreach @ 00115ba0 size 80 */

/* DWARF original prototype: void Hashtable_foreach(Hashtable * this, Hashtable_PairFunction f, void
   * userData) */

void Hashtable_foreach(Hashtable *this,Hashtable_PairFunction f,void *userData)

{
  void *pvVar1;
  long in_RCX;
  ulong uVar2;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: size_t i@[???] */
  if (this->size != 0) {
    uVar2 = 0;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
      pvVar1 = this->buckets[uVar2].value;
      if (pvVar1 != (void *)0x0) {
        (*f)(this->buckets[uVar2].key,pvVar1,userData,in_RCX,in_R8,in_R9);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < this->size);
    return;
  }
  return;
}

