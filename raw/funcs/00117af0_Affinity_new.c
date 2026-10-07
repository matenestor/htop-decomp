/* Affinity_new @ 00117af0 size 84 */

Affinity_2 * Affinity_new(Machine *host)

{
  Affinity_2 *pAVar1;
  uint *puVar2;

                    /* Unresolved local var: void * data@[???] */
  pAVar1 = calloc(1,0x18);
  if (pAVar1 != (Affinity_2 *)0x0) {
    pAVar1->size = 8;
                    /* Unresolved local var: void * data@[???] */
    puVar2 = calloc(8,4);
    if (puVar2 != (uint *)0x0) {
      pAVar1->cpus = puVar2;
      pAVar1->host = host;
      return pAVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

