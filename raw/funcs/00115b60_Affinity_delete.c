/* Affinity_delete @ 00115b60 size 38 */

/* DWARF original prototype: void Affinity_delete(Affinity * this) */

void Affinity_delete(Affinity *this)

{
  free(this->cpus);
  free(this);
  return;
}

