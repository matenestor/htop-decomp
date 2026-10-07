/* Affinity_rowSet @ 00115fc0 size 157 */

_Bool Affinity_rowSet(Process_ *row,Arg arg)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  long lVar6;
  __cpu_mask *p_Var7;
  long in_FS_OFFSET;
  cpu_set_t cpuset;

  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
                    /* Unresolved local var: Affinity * this@[???]
                       Unresolved local var: _Bool ok@[???] */
  lVar6 = 0x10;
  p_Var7 = cpuset.__bits;
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
        p_Var7 = (__cpu_mask *)((long)&cpuset + (ulong)(uVar2 >> 6) * 8);
        *p_Var7 = *p_Var7 | 1L << ((byte)uVar2 & 0x3f);
      }
      puVar5 = puVar5 + 1;
    } while (puVar5 != puVar1);
  }
  iVar4 = sched_setaffinity((row->super).id,8,&cpuset);
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar4 == 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

