#include "htop.h"

/* ClockMeter_updateValues @ 0x115660 */

/* DWARF original prototype: void ClockMeter_updateValues(Meter * this) */

void ClockMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  tm_2 *__tp;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __tp = localtime_r(&(this->host->realtime).tv_sec,(tm_2 *)&(*(tm (*))(__fp - 0x58)));
  *this->values = (double)(__tp->tm_hour * 0x3c + __tp->tm_min);
  strftime(this->txtBuffer,0x100,((char *)(long)&DAT_00147166 /* "%H:%M:%S" */),__tp);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

