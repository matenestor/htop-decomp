#include "htop.h"

/* MemoryMeter_updateValues @ 0x1293a0 */

/* DWARF original prototype: void MemoryMeter_updateValues(Meter * this) */

void MemoryMeter_updateValues(Meter *this)

{
  char *pcVar1;
  double *pdVar2;
  int wVar3;
  ulong uVar4;
  double value;

  pdVar2 = this->values;
  pdVar2[5] = NAN;
  pdVar2[1] = NAN;
  pdVar2[2] = NAN;
  Platform_setMemoryValues(this);
  this->curItems = '\x05';
  value = *pdVar2;
  if (0.0 < pdVar2[1]) {
    value = value + pdVar2[1];
  }
  if (0.0 < pdVar2[2]) {
    value = value + pdVar2[2];
  }
  wVar3 = Meter_humanUnit(this->txtBuffer,value,0x100);
  if (-1 < wVar3) {
    uVar4 = (ulong)wVar3;
    if ((uVar4 < 0x100) && (uVar4 != 0xff)) {
      pcVar1 = this->txtBuffer + uVar4;
      pcVar1[0] = '/';
      pcVar1[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar4 + 1,this->total,0xff - uVar4);
      return;
    }
  }
  return;
}


/* MemoryMeter_display @ 0x129470 */

void MemoryMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  double value;
  long lVar1;
  double *pdVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),*cast->values,0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_used__00148889 /* " used:" */));
  RichString_appendAscii(out,CRT_colors[0x33],(*(char (*) [50])(__fp - 0x68)));
  pdVar2 = cast->values;
  if (0.0 <= pdVar2[1]) {
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),pdVar2[1],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_shared__00148890 /* " shared:" */));
    RichString_appendAscii(out,CRT_colors[0x37],(*(char (*) [50])(__fp - 0x68)));
    pdVar2 = cast->values;
    value = pdVar2[2];
  }
  else {
    value = pdVar2[2];
  }
  if (0.0 <= value) {
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),value,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_compressed__00148899 /* " compressed:" */));
    RichString_appendAscii(out,CRT_colors[0x38],(*(char (*) [50])(__fp - 0x68)));
    pdVar2 = cast->values;
  }
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),pdVar2[3],0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_buffers__001488a6 /* " buffers:" */));
  RichString_appendAscii(out,CRT_colors[0x35],(*(char (*) [50])(__fp - 0x68)));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[4],0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_cache__001488b0 /* " cache:" */));
  RichString_appendAscii(out,CRT_colors[0x36],(*(char (*) [50])(__fp - 0x68)));
  if (0.0 <= cast->values[5]) {
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[5],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_available__001488b8 /* " available:" */));
    RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

