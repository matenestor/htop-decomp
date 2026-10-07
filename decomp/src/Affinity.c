#include "htop.h"

/* Affinity_delete @ 0x115b60 */

/* DWARF original prototype: void Affinity_delete(Affinity * this) */

void Affinity_delete(Affinity *this)

{
  free(this->cpus);
  free(this);
  return;
}


/* Affinity_rowGet @ 0x115b90 */

Affinity_2 * Affinity_rowGet(Process_ *row,Machine *host)

{
  Affinity_2 *pAVar1;

  pAVar1 = Affinity_get((Process *)(ulong)(uint)(row->super).id,host);
  return pAVar1;
}


/* Affinity_rowSet @ 0x115fc0 */

_Bool Affinity_rowSet(Process_ *row,Arg arg)

{
  undefined1 __frame[0x128] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xe8;
  uint *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  long lVar6;
  __cpu_mask *p_Var7;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
                    /* Unresolved local var: Affinity * this@[???]
                       Unresolved local var: _Bool ok@[???] */
  lVar6 = 0x10;
  p_Var7 = (*(cpu_set_t (*))(__fp - 0x98)).__bits;
  for (; lVar6 != 0; lVar6 = lVar6 + -1) {
    *p_Var7 = 0;
    p_Var7 = p_Var7 + 1;
  }
                    /* Unresolved local var: uint i@[???] */
  if (*(uint *)((long)arg.v + 0xc) != 0) {
    puVar5 = *(uint **)((long)arg.v + 0x10);
                    /* Unresolved local var: size_t __cpu@[???] */
    puVar1 = puVar5 + *(uint *)((long)arg.v + 0xc);
    do {
      uVar2 = *puVar5;
      if (uVar2 < 0x400) {
        p_Var7 = (__cpu_mask *)((long)&(*(cpu_set_t (*))(__fp - 0x98)) + (ulong)(uVar2 >> 6) * 8);
        *p_Var7 = *p_Var7 | 1L << ((byte)uVar2 & 0x3f);
      }
      puVar5 = puVar5 + 1;
    } while (puVar5 != puVar1);
  }
  iVar4 = sched_setaffinity((row->super).id,8,&(*(cpu_set_t (*))(__fp - 0x98)));
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar4 == 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Affinity_new @ 0x117af0 */

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


/* Affinity_add @ 0x117b50 */

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


/* Affinity_get @ 0x140160 */

Affinity_2 * Affinity_get(Process *p,Machine *host)

{
  undefined1 __frame[0x158] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x118;
  uint uVar1;
  long lVar2;
  int iVar3;
  Affinity_2 *pAVar4;
  uint *puVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = sched_getaffinity((__pid_t)p,0x80,&(*(cpu_set_t (*))(__fp - 0xc8)));
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
          while ((uVar7 < 0x400 && (((*(cpu_set_t (*))(__fp - 0xc8)).__bits[uVar7 >> 6] >> (uVar7 & 0x3f) & 1) != 0))) {
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

