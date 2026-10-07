#include "htop.h"

/* ScreenListItem_new @ 0x132270 */

undefined8 * ScreenListItem_new(char *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = ScreenListItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined4 *)(puVar1 + 2) = 0;
      *(undefined1 *)((long)puVar1 + 0x14) = 0;
      puVar1[4] = param_2;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

