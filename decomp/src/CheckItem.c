#include "htop.h"

/* CheckItem_set @ 0x120860 */

void CheckItem_set(long param_1,undefined1 param_2)

{
  if (*(undefined1 **)(param_1 + 0x10) != (undefined1 *)0x0) {
    **(undefined1 **)(param_1 + 0x10) = param_2;
    return;
  }
  *(undefined1 *)(param_1 + 0x18) = param_2;
  return;
}


/* CheckItem_get @ 0x121f40 */

undefined1 CheckItem_get(long param_1)

{
  if (*(undefined1 **)(param_1 + 0x10) != (undefined1 *)0x0) {
    return **(undefined1 **)(param_1 + 0x10);
  }
  return *(undefined1 *)(param_1 + 0x18);
}


/* CheckItem_toggle @ 0x121f60 */

void CheckItem_toggle(long param_1)

{
  byte *pbVar1;

  pbVar1 = *(byte **)(param_1 + 0x10);
  if (pbVar1 != (byte *)0x0) {
    *pbVar1 = *pbVar1 ^ 1;
    return;
  }
  *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) ^ 1;
  return;
}


/* CheckItem_newByRef @ 0x123d00 */

undefined8 * CheckItem_newByRef(char *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = CheckItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined1 *)(puVar1 + 3) = 0;
      puVar1[2] = param_2;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* CheckItem_newByVal @ 0x123d60 */

undefined8 * CheckItem_newByVal(char *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = CheckItem_class;
    pcVar2 = strdup(param_1);
    if (pcVar2 != (char *)0x0) {
      puVar1[1] = pcVar2;
      *(undefined1 *)(puVar1 + 3) = param_2;
      puVar1[2] = 0;
      return puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

