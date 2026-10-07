/* Affinity_get @ 00140160 size 344 */

Affinity_2 * Affinity_get(Process *p,Machine *host)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  Affinity_2 *pAVar4;
  uint *puVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  long in_FS_OFFSET;
  cpu_set_t cpuset;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = sched_getaffinity((__pid_t)p,0x80,&cpuset);
  if (iVar3 != 0) {
    pAVar4 = (Affinity_2 *)0x0;
LAB_00140250:
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
      return pAVar4;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* Unresolved local var: Affinity * this@[???]
                       Unresolved local var: void * data@[???] */
  pAVar4 = calloc(1,0x18);
  if (pAVar4 != (Affinity_2 *)0x0) {
    pAVar4->size = 8;
                    /* Unresolved local var: void * data@[???] */
    puVar5 = calloc(8,4);
    if (puVar5 != (uint *)0x0) {
      pAVar4->cpus = puVar5;
                    /* Unresolved local var: uint i@[???] */
      uVar1 = host->existingCPUs;
      pAVar4->host = host;
      if (uVar1 != 0) {
        uVar7 = 0;
        do {
                    /* Unresolved local var: size_t __cpu@[???] */
          while ((uVar7 < 0x400 && ((cpuset.__bits[uVar7 >> 6] >> (uVar7 & 0x3f) & 1) != 0))) {
            uVar1 = pAVar4->used;
            puVar5 = pAVar4->cpus;
            puVar6 = puVar5;
            if (uVar1 == pAVar4->size) {
                    /* Unresolved local var: void * data@[???] */
              pAVar4->size = uVar1 * 2;
              puVar6 = realloc(puVar5,(ulong)(uVar1 * 2) * 4);
              if (puVar6 == (uint *)0x0) {
                free(puVar5);
                goto LAB_001402bb;
              }
              pAVar4->cpus = puVar6;
            }
            uVar8 = uVar7 + 1;
            puVar6[uVar1] = (uint)uVar7;
            pAVar4->used = uVar1 + 1;
            uVar7 = uVar8;
            if (host->existingCPUs <= (uint)uVar8) goto LAB_00140250;
          }
          uVar7 = uVar7 + 1;
        } while ((uint)uVar7 < host->existingCPUs);
      }
      goto LAB_00140250;
    }
  }
LAB_001402bb:
                    /* WARNING: Subroutine does not return */
  fail();
}

