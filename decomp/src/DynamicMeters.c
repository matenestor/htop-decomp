#include "htop.h"

/* DynamicMeters_new @ 0x116070 */

undefined8 DynamicMeters_new(void)

{
  return 0;
}


/* DynamicMeters_delete @ 0x1174e0 */

void DynamicMeters_delete(ulong *param_1)

{
  if (param_1 != (ulong *)0x0) {
    Hashtable_clear(param_1);
    free((void *)param_1[1]);
    free(param_1);
    return;
  }
  return;
}

