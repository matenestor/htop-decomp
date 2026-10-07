/* Hashtable_clear @ 00117400 size 101 */

/* DWARF original prototype: void Hashtable_clear(Hashtable * this) */

void Hashtable_clear(Hashtable *this)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;

                    /* Unresolved local var: size_t i@[???] */
  uVar1 = this->size;
  if ((this->owner != false) && (uVar1 != 0)) {
    uVar2 = 0;
    do {
      uVar3 = uVar2 + 1;
      free(this->buckets[uVar2].value);
      uVar1 = this->size;
      uVar2 = uVar3;
    } while (uVar3 < uVar1);
  }
  memset(this->buckets,0,uVar1 * 0x18);
  this->items = 0;
  return;
}

