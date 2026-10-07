/* Affinity_add @ 00117b50 size 106 */

/* DWARF original prototype: void Affinity_add(Affinity * this, uint id) */

void Affinity_add(Affinity *this,uint id)

{
  uint uVar1;
  uint *__ptr;
  uint *puVar2;

  uVar1 = this->used;
  __ptr = this->cpus;
  puVar2 = __ptr;
  if (uVar1 == this->size) {
    this->size = uVar1 * 2;
                    /* Unresolved local var: void * data@[???] */
    puVar2 = realloc(__ptr,(ulong)(uVar1 * 2) * 4);
    if (puVar2 == (uint *)0x0) {
      free(__ptr);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->cpus = puVar2;
    uVar1 = this->used;
  }
  puVar2[uVar1] = id;
  this->used = this->used + 1;
  return;
}

