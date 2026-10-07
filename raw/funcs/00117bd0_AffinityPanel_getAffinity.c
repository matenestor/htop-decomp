/* AffinityPanel_getAffinity @ 00117bd0 size 264 */

Affinity * AffinityPanel_getAffinity(AffinityPanel_ *super,Machine_2 *host)

{
  uint uVar1;
  uint uVar2;
  Affinity *pAVar3;
  uint *puVar4;
  uint *puVar5;
  Vector *pVVar6;
  long lVar7;

                    /* Unresolved local var: Affinity * this@[???]
                       Unresolved local var: void * data@[???] */
  pAVar3 = calloc(1,0x18);
  if (pAVar3 != (Affinity *)0x0) {
    pAVar3->size = 8;
                    /* Unresolved local var: void * data@[???] */
    puVar4 = calloc(8,4);
    if (puVar4 != (uint *)0x0) {
                    /* Unresolved local var: wchar_t i@[???] */
      pVVar6 = super->cpuids;
      pAVar3->host = host;
      lVar7 = 0;
      pAVar3->cpus = puVar4;
      if (L'\0' < pVVar6->items) {
        do {
                    /* Unresolved local var: MaskItem * item@[???] */
          while (*(int *)&pVVar6->array[lVar7][3].klass == 0) {
            lVar7 = lVar7 + 1;
            if (pVVar6->items <= (wchar_t)lVar7) {
              return pAVar3;
            }
          }
          uVar1 = *(uint *)&pVVar6->array[lVar7][5].klass;
          uVar2 = pAVar3->used;
          puVar4 = pAVar3->cpus;
          puVar5 = puVar4;
          if (uVar2 == pAVar3->size) {
                    /* Unresolved local var: void * data@[???] */
            pAVar3->size = uVar2 * 2;
            puVar5 = realloc(puVar4,(ulong)(uVar2 * 2) * 4);
            if (puVar5 == (uint *)0x0) {
              free(puVar4);
              goto LAB_00117cdd;
            }
            pAVar3->cpus = puVar5;
            pVVar6 = super->cpuids;
          }
          lVar7 = lVar7 + 1;
          puVar5[uVar2] = uVar1;
          pAVar3->used = uVar2 + 1;
        } while ((wchar_t)lVar7 < pVVar6->items);
      }
      return pAVar3;
    }
  }
LAB_00117cdd:
                    /* WARNING: Subroutine does not return */
  fail();
}

