#include "htop.h"

/* Object_isA @ 0x1207e0 */

undefined8 Object_isA(long *param_1,long *param_2)

{
  long *plVar1;

  if ((param_1 != (long *)0x0) && (plVar1 = (long *)*param_1, plVar1 != (long *)0x0)) {
    do {
      if (plVar1 == param_2) {
        return 1;
      }
      plVar1 = (long *)*plVar1;
    } while (plVar1 != (long *)0x0);
    return 0;
  }
  return 0;
}

