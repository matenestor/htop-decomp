#include "htop.h"

/* ScreenSettings_delete @ 0x12df60 */

void ScreenSettings_delete(undefined8 *param_1)

{
  free((void *)*param_1);
  free((void *)param_1[1]);
  free((void *)param_1[3]);
  free(param_1);
  return;
}


/* ScreenSettings_invertSortOrder @ 0x12e150 */

void ScreenSettings_invertSortOrder(long param_1)

{
  bool bVar1;

  if (*(char *)(param_1 + 0x34) != '\0') {
    bVar1 = *(int *)(param_1 + 0x28) != 1;
    *(uint *)(param_1 + 0x28) = (bVar1 - 1) + (uint)bVar1;
    return;
  }
  bVar1 = *(int *)(param_1 + 0x24) != 1;
  *(uint *)(param_1 + 0x24) = (bVar1 - 1) + (uint)bVar1;
  return;
}


/* ScreenSettings_setSortKey @ 0x12e190 */

void ScreenSettings_setSortKey(long param_1,int param_2)

{
  char cVar1;

  cVar1 = Process_fields[(long)param_2 * 0x20 + 0x1d];
  if ((*(char *)(param_1 + 0x35) == '\0') && (*(char *)(param_1 + 0x34) != '\0')) {
    *(int *)(param_1 + 0x30) = param_2;
    *(uint *)(param_1 + 0x28) = (-(uint)(cVar1 == '\0') & 2) - 1;
    return;
  }
  *(int *)(param_1 + 0x2c) = param_2;
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(uint *)(param_1 + 0x24) = (-(uint)(cVar1 == '\0') & 2) - 1;
  return;
}

