#include "htop.h"

/* ProcessLocksScreen_new @ 0x127680 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ProcessLocksScreen_new(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  void *pvVar4;

  puVar3 = malloc(0x30);
  if (puVar3 != (undefined8 *)0x0) {
    cVar1 = *(char *)(param_1 + 0x4d);
    *puVar3 = ProcessLocksScreen_class;
    if ((cVar1 == '\0') && (*(char *)(param_1 + 0x4c) == '\0')) {
      uVar2 = *(undefined4 *)(param_1 + 0x10);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x14);
    }
    *(undefined4 *)(puVar3 + 5) = uVar2;
    pvVar4 = (void *)InfoScreen_init((long)puVar3,param_1,(wint_t *)0x0,_LINES + -2,
                                     ((char *)(long)&s_FD_TYPE_EXCLUSION_READ_WRITE_DEV_0014c428 /* "   FD TYPE       EXCLUSION  READ/WRITE DEVICE       NODE               START                 END  FILENAME" */)
                                    );
    return pvVar4;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

