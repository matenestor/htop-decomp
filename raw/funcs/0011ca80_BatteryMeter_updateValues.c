/* BatteryMeter_updateValues @ 0011ca80 size 228 */

/* DWARF original prototype: void BatteryMeter_updateValues(Meter * this) */

void BatteryMeter_updateValues(Meter *this)

{
  char *va1;
  long in_FS_OFFSET;
  ACPresence isOnAC;
  double percent;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  Platform_getBattery(&percent,&isOnAC);
  if (percent < 0.0) {
    *this->values = NAN;
    xSnprintf(this->txtBuffer,0x100,((char *)0x1474de /* "N/A" */));
  }
  else {
    *this->values = percent;
    if (isOnAC == AC_ABSENT) {
      va1 = ((char *)0x1474d8 /* "(bat)" */);
      if (this->mode == L'\x02') {
        va1 = ((char *)0x1474c2 /* " (Running on battery)" */);
      }
    }
    else {
      va1 = ((char *)0x149c0c /* "" */);
      if ((isOnAC == AC_PRESENT) && (va1 = ((char *)0x1474bc /* "(A/C)" */), this->mode == L'\x02')) {
        va1 = ((char *)0x1474aa /* " (Running on A/C)" */);
      }
    }
    xSnprintf(this->txtBuffer,0x100,((char *)0x1474e2 /* "%.1f%%%s" */),percent,va1);
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

