#include "htop.h"

/* SwapMeter_updateValues @ 0x12f890 */

/* DWARF original prototype: void SwapMeter_updateValues(Meter * this) */

void SwapMeter_updateValues(Meter *this)

{
  double *pdVar1;
  int wVar2;
  ulong uVar3;

  pdVar1 = this->values;
  pdVar1[1] = NAN;
  pdVar1[2] = NAN;
  Platform_setSwapValues(this);
  wVar2 = Meter_humanUnit(this->txtBuffer,*pdVar1,0x100);
  if (-1 < wVar2) {
    uVar3 = (ulong)wVar2;
    if ((uVar3 < 0x100) && (uVar3 != 0xff)) {
      (this->txtBuffer + uVar3)[0] = '/';
      (this->txtBuffer + uVar3)[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar3 + 1,this->total,0xff - uVar3);
      return;
    }
  }
  return;
}


/* SwapMeter_display @ 0x131bd0 */

void SwapMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  double dVar1;
  long lVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),*cast->values,0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_used__00148889 /* " used:" */));
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  dVar1 = cast->values[1];
  if (0.0 <= dVar1) {
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),dVar1,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_cache__001488b0 /* " cache:" */));
    RichString_appendAscii(out,CRT_colors[0x1b],(*(char (*) [50])(__fp - 0x68)));
    dVar1 = cast->values[2];
  }
  else {
    dVar1 = cast->values[2];
  }
  if (0.0 <= dVar1) {
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),dVar1,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_frontswap__00149151 /* " frontswap:" */));
    RichString_appendAscii(out,CRT_colors[0x1c],(*(char (*) [50])(__fp - 0x68)));
  }
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

