#include "htop.h"

/* UsersTable_foreach @ 0x12e2e0 */

void UsersTable_foreach(long *param_1,undefined *param_2,long param_3,long param_rcx,long param_r8,
                       long param_r9)

{
  uint *puVar1;
  ulong *puVar2;
  long a1;
  ulong uVar3;

  puVar2 = (ulong *)*param_1;
  if (*puVar2 != 0) {
    uVar3 = 0;
    do {
      puVar1 = (uint *)(puVar2[1] + uVar3 * 0x18);
      a1 = *(long *)(puVar1 + 4);
      if (a1 != 0) {
        (*(code *)param_2)((ulong)*puVar1,a1,param_3,param_rcx,param_r8,param_r9);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return;
}


/* UsersTable_delete @ 0x12f9d0 */

void UsersTable_delete(undefined8 *param_1)

{
  ulong *__ptr;

  __ptr = (ulong *)*param_1;
  Hashtable_clear(__ptr);
  free((void *)__ptr[1]);
  free(__ptr);
  free(param_1);
  return;
}


/* UsersTable_new @ 0x132c60 */

undefined8 * UsersTable_new(void)

{
  undefined8 *puVar1;
  ulong *puVar2;

  puVar1 = malloc(8);
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = Hashtable_new(10,1);
    *puVar1 = puVar2;
    return puVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* UsersTable_getRef @ 0x132ca0 */

char * UsersTable_getRef(long *param_1,uint param_2)

{
  ulong uVar1;
  uint *puVar2;
  passwd *ppVar3;
  char *pcVar4;
  uint *puVar5;
  ulong uVar6;
  ulong uVar7;

  uVar1 = *(ulong *)*param_1;
  puVar2 = (uint *)((ulong *)*param_1)[1];
  uVar6 = (ulong)param_2 % uVar1;
  pcVar4 = *(char **)(puVar2 + uVar6 * 6 + 4);
  if (pcVar4 != (char *)0x0) {
    uVar7 = 0;
    puVar5 = puVar2 + uVar6 * 6;
    do {
      while( true ) {
        if (param_2 == *puVar5) {
          return pcVar4;
        }
        if (*(ulong *)(puVar5 + 2) < uVar7) goto LAB_00132d20;
        uVar6 = uVar6 + 1;
        if (uVar1 != uVar6) break;
        uVar6 = 0;
        uVar7 = uVar7 + 1;
        pcVar4 = *(char **)(puVar2 + 4);
        puVar5 = puVar2;
        if (pcVar4 == (char *)0x0) goto LAB_00132d20;
      }
      uVar7 = uVar7 + 1;
      puVar5 = puVar2 + uVar6 * 6;
      pcVar4 = *(char **)(puVar5 + 4);
    } while (pcVar4 != (char *)0x0);
  }
LAB_00132d20:
  ppVar3 = getpwuid(param_2);
  pcVar4 = (char *)0x0;
  if (ppVar3 != (passwd *)0x0) {
    pcVar4 = strdup(ppVar3->pw_name);
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    Hashtable_put((ulong *)*param_1,param_2,pcVar4);
  }
  return pcVar4;
}

