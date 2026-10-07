#include "htop.h"

/* ZfsArcMeter_readStats @ 0x13c0c0 */

void ZfsArcMeter_readStats(long param_1,long param_2)

{
  ulong uVar1;
  double *pdVar2;
  ulong uVar3;

  uVar1 = *(ulong *)(param_2 + 0x20);
  pdVar2 = *(double **)(param_1 + 0x160);
  *(double *)(param_1 + 0x168) = (double)*(ulong *)(param_2 + 0x10);
  uVar3 = *(ulong *)(param_2 + 0x28);
  *pdVar2 = (double)uVar1;
  uVar1 = *(ulong *)(param_2 + 0x30);
  pdVar2[1] = (double)uVar3;
  uVar3 = *(ulong *)(param_2 + 0x38);
  pdVar2[2] = (double)uVar1;
  uVar1 = *(ulong *)(param_2 + 0x40);
  pdVar2[3] = (double)uVar3;
  pdVar2[4] = (double)uVar1;
  *(undefined1 *)(param_1 + 0x50) = 5;
  uVar1 = *(ulong *)(param_2 + 0x18);
  if (-1 < (long)uVar1) {
    pdVar2[5] = (double)(long)uVar1;
    return;
  }
  pdVar2[5] = (double)uVar1;
  return;
}

