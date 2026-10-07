#include "htop.h"

/* EnvScreen_new @ 0x11ab90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnvScreen_new(undefined8 param_1)

{
  undefined8 *puVar1;

  puVar1 = malloc(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = EnvScreen_class;
    InfoScreen_init((long)puVar1,param_1,(wint_t *)0x0,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_0011abf0 @ 0x11abf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0011abf0(undefined8 *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
            long param_r9)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar5;
  undefined *puVar6;

  uVar3 = 0;
  if (*(long *)(*(long *)(*(long *)*param_1 + 0x40) + 8) == 0) {
    plVar2 = *(long **)(param_1[1] + 0x20);
    if (0 < (int)plVar2[3]) {
      lVar5 = *(long *)(*plVar2 + (long)*(int *)(param_1[1] + 0x28) * 8);
      if (lVar5 != 0) {
        puVar1 = malloc(0x28);
        if (puVar1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        puVar6 = &DAT_001470dd;
        *puVar1 = EnvScreen_class;
        uVar4 = (ulong)(_LINES - 2U);
        plVar2 = (long *)InfoScreen_init((long)puVar1,lVar5,(wint_t *)0x0,_LINES - 2U,((char *)(long)&DAT_001470dd /* " " */));
        InfoScreen_run(plVar2,lVar5,extraout_RDX,uVar4,(long)puVar6,param_r9);
        CommandScreen_delete(plVar2,lVar5,extraout_RDX_00,uVar4,(long)puVar6,param_r9);
        wclear(_stdscr);
        halfdelay(*PTR_0015c0d0);
        uVar3 = 0x21;
      }
      return uVar3;
    }
  }
  return 0;
}

