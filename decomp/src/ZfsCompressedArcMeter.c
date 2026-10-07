#include "htop.h"

/* ZfsCompressedArcMeter_readStats @ 0x13c360 */

void ZfsCompressedArcMeter_readStats(long param_1,long param_2)

{
  double *pdVar1;
  ulong uVar2;
  double dVar3;

  pdVar1 = *(double **)(param_1 + 0x160);
  if (*(int *)(param_2 + 4) == 0) {
    uVar2 = *(ulong *)(param_2 + 0x18);
    *(double *)(param_1 + 0x168) = (double)uVar2;
    *pdVar1 = (double)uVar2;
    return;
  }
  if ((long)*(ulong *)(param_2 + 0x50) < 0) {
    uVar2 = *(ulong *)(param_2 + 0x48);
  }
  else {
    uVar2 = *(ulong *)(param_2 + 0x48);
  }
  dVar3 = (double)*(ulong *)(param_2 + 0x50);
  if (-1 < (long)uVar2) {
    *(double *)(param_1 + 0x168) = dVar3;
    *pdVar1 = (double)(long)uVar2;
    return;
  }
  *(double *)(param_1 + 0x168) = dVar3;
  *pdVar1 = (double)uVar2;
  return;
}

