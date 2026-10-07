#include "htop.h"

/* UptimeMeter_updateValues @ 0x12fec0 */

/* DWARF original prototype: void UptimeMeter_updateValues(Meter * this) */

void UptimeMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  int va0;
  int wVar2;
  int iVar3;
  int iVar4;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar5;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = Platform_getUptime();
  if (wVar2 < 1) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      xSnprintf(this->txtBuffer,0x100,((char *)(long)&s__unknown__00149029 /* "(unknown)" */));
      return;
    }
    goto LAB_001300b7;
  }
  iVar4 = wVar2 >> 0x1f;
  iVar3 = wVar2 / 0x3c + iVar4;
  va0 = wVar2 / 0x15180;
  dVar5 = (double)va0;
  *this->values = dVar5;
  if (this->total <= dVar5 && dVar5 != this->total) {
    this->total = dVar5;
    if (8726399 < wVar2) goto LAB_00130018;
LAB_0012ff9d:
    if (wVar2 < 172800) {
      if (va0 == 1) {
        xSnprintf((*(char (*) [32])(__fp - 0x68)),0x20,((char *)(long)&s_1_day__0014904a /* "1 day, " */));
      }
      else {
        (*(char (*) [32])(__fp - 0x68))[0] = '\0';
      }
    }
    else {
      xSnprintf((*(char (*) [32])(__fp - 0x68)),0x20,((char *)(long)&s__d_days__00149040 /* "%d days, " */),va0);
    }
  }
  else {
    if (wVar2 < 8726400) goto LAB_0012ff9d;
LAB_00130018:
    xSnprintf((*(char (*) [32])(__fp - 0x68)),0x20,((char *)(long)&DAT_00149033 /* "%d days(!), " */),va0);
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&s__s_02d__02d__02d_00149052 /* "%s%02d:%02d:%02d" */),(*(char (*) [32])(__fp - 0x68)),(uint)(wVar2 / 0xe10) % 0x18,
            (uint)(iVar3 - iVar4) % 0x3c,wVar2 + (iVar3 - iVar4) * -0x3c);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_001300b7:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

