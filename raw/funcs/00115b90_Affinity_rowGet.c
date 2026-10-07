/* Affinity_rowGet @ 00115b90 size 12 */

Affinity_2 * Affinity_rowGet(Process_ *row,Machine *host)

{
  Affinity_2 *pAVar1;

  pAVar1 = Affinity_get((Process *)(ulong)(uint)(row->super).id,host);
  return pAVar1;
}

