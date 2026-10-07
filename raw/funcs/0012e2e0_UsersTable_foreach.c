/* UsersTable_foreach @ 0012e2e0 size 79 */

/* DWARF original prototype: void UsersTable_foreach(UsersTable * this, Hashtable_PairFunction f,
   void * userData) */

void UsersTable_foreach(UsersTable *this,Hashtable_PairFunction f,void *userData)

{
  Hashtable_2 *pHVar1;
  void *pvVar2;
  long in_RCX;
  ulong uVar3;
  long in_R8;
  long in_R9;

  pHVar1 = this->users;
                    /* Unresolved local var: size_t i@[???] */
  if (pHVar1->size != 0) {
    uVar3 = 0;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
      pvVar2 = pHVar1->buckets[uVar3].value;
      if (pvVar2 != (void *)0x0) {
        (*f)(pHVar1->buckets[uVar3].key,pvVar2,userData,in_RCX,in_R8,in_R9);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < pHVar1->size);
  }
  return;
}

