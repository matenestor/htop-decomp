#include "htop.h"

/* DynamicColumns_delete @ 0x1174a0 */

void DynamicColumns_delete(ulong *param_1)

{
  if (param_1 != (ulong *)0x0) {
    Hashtable_clear(param_1);
    free((void *)param_1[1]);
    free(param_1);
    return;
  }
  return;
}


/* DynamicColumns_new @ 0x117dd0 */

undefined8 * DynamicColumns_new(void)

{
  undefined8 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[2] = 0;
    *puVar1 = 0xd;
    pvVar2 = calloc(0xd,0x18);
    if (pvVar2 != (void *)0x0) {
      puVar1[1] = pvVar2;
      *(undefined1 *)(puVar1 + 3) = 1;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

