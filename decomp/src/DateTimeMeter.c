#include "htop.h"

/* DateTimeMeter_updateValues @ 0x1157c0 */

/* DWARF original prototype: void DateTimeMeter_updateValues(Meter * this) */

void DateTimeMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  int iVar1;
  uint uVar2;
  long lVar3;
  tm_2 *__tp;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  __tp = localtime_r(&(this->host->realtime).tv_sec,(tm_2 *)&(*(tm (*))(__fp - 0x58)));
  uVar2 = __tp->tm_year;
  iVar1 = uVar2 + 0x76c;
  if ((((uVar2 & 3) != 0) ||
      (dVar4 = 366.0, (iVar1 * -0x3d70a3d7 + 0x51eb850U >> 2 | uVar2 * 0x40000000) < 0x28f5c29)) &&
     (dVar4 = 366.0, 0xa3d70a < (iVar1 * -0x3d70a3d7 + 0x51eb850U >> 4 | iVar1 * -0x70000000))) {
    dVar4 = 365.0;
  }
  this->total = dVar4;
  *this->values = (double)__tp->tm_yday;
  strftime(this->txtBuffer,0x100,((char *)(long)&DAT_00147163 /* "%F %H:%M:%S" */),__tp);
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

