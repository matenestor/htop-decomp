#include "htop.h"

/* BatteryMeter_updateValues @ 0x11ca80 */

/* DWARF original prototype: void BatteryMeter_updateValues(Meter * this) */

void BatteryMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  char *va1;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  Platform_getBattery(&(*(double (*))(__fp - 0x28)),&(*(ACPresence (*))(__fp - 0x2c)));
  if ((*(double (*))(__fp - 0x28)) < 0.0) {
    *this->values = NAN;
    xSnprintf(this->txtBuffer,0x100,((char *)(long)&DAT_001474de /* "N/A" */));
  }
  else {
    *this->values = (*(double (*))(__fp - 0x28));
    if ((*(ACPresence (*))(__fp - 0x2c)) == AC_ABSENT) {
      va1 = ((char *)(long)&s__bat__001474d8 /* "(bat)" */);
      if (this->mode == 2) {
        va1 = ((char *)(long)&s__Running_on_battery__001474c2 /* " (Running on battery)" */);
      }
    }
    else {
      va1 = ((char *)(long)&DAT_00149c0c /* "" */);
      if (((*(ACPresence (*))(__fp - 0x2c)) == AC_PRESENT) && (va1 = ((char *)(long)&s__A_C__001474bc /* "(A/C)" */), this->mode == 2)) {
        va1 = ((char *)(long)&s__Running_on_A_C__001474aa /* " (Running on A/C)" */);
      }
    }
    xSnprintf(this->txtBuffer,0x100,((char *)(long)&s___1f___s_001474e2 /* "%.1f%%%s" */),(*(double (*))(__fp - 0x28)),va1);
  }
  if ((*(long (*))(__fp - 0x20)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

