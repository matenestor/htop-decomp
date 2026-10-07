#include "htop.h"

/* TextItem_new @ 0x123cb0 */

undefined8 * TextItem_new(char *param_1)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x18);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = TextItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

