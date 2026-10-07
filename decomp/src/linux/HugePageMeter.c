#include "htop.h"

/* HugePageMeter_updateValues @ 0x1406e0 */

/* DWARF original prototype: void HugePageMeter_updateValues(Meter * this) */

void HugePageMeter_updateValues(Meter *this)

{
  Machine *pMVar1;
  double *pdVar2;
  char *pcVar3;
  ulong uVar4;
  int wVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;

  pMVar1 = this->host;
  this->total = (double)pMVar1[1].totalMem;
  uVar9 = 0;
  pdVar2 = this->values;
                    /* Unresolved local var: uint i@[???] */
  HugePageMeter_active_labels_1_ = (char *)0x0;
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: memory_t value@[???] */
  HugePageMeter_active_labels[0] = ((char *)(long)&s_used__00148889 /* " used:" */);
  lVar6 = 0;
  *pdVar2 = 0.0;
  pdVar2[1] = NAN;
  HugePageMeter_active_labels_2_ = (char *)0x0;
  HugePageMeter_active_labels_3_ = (char *)0x0;
  pdVar2[2] = NAN;
  pdVar2[3] = NAN;
  uVar8 = 0;
  do {
    uVar4 = *(ulong *)((long)&pMVar1[1].usedMem + lVar6);
    uVar7 = uVar8;
    if (uVar4 != 0xffffffffffffffff) {
      uVar9 = uVar9 + uVar4;
      pcVar3 = *(char **)((long)HugePageMeter_labels + lVar6);
      uVar7 = uVar8 + 1;
      pdVar2[uVar8] = (double)uVar4;
      HugePageMeter_active_labels[uVar8] = pcVar3;
      if (uVar7 == 4) break;
    }
    lVar6 = lVar6 + 8;
    uVar8 = uVar7;
  } while (lVar6 != 0xc0);
  wVar5 = Meter_humanUnit(this->txtBuffer,(double)uVar9,0x100);
  if (-1 < wVar5) {
    uVar9 = (ulong)wVar5;
    if ((uVar9 < 0x100) && (uVar9 != 0xff)) {
      pcVar3 = this->txtBuffer + uVar9;
      pcVar3[0] = '/';
      pcVar3[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar9 + 1,this->total,0xff - uVar9);
      return;
    }
  }
  return;
}


/* HugePageMeter_display @ 0x140ad0 */

void HugePageMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  long lVar1;
  char *data;
  long lVar2;
  long lVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar3 = 0;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x78)),cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x78)));
  do {
                    /* Unresolved local var: uint i@[???] */
    data = *(char **)((long)HugePageMeter_active_labels + lVar3 * 2);
    if (data == (char *)0x0) break;
    RichString_appendAscii(out,CRT_colors[0xe],data);
    Meter_humanUnit((*(char (*) [50])(__fp - 0x78)),*(double *)((long)cast->values + lVar3 * 2),0x32);
    lVar2 = lVar3 + 0xe4;
    lVar3 = lVar3 + 4;
    RichString_appendAscii(out,*(int *)((long)CRT_colors + lVar2),(*(char (*) [50])(__fp - 0x78)));
  } while (lVar3 != 0x10);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

