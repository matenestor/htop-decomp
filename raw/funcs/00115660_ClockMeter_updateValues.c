/* ClockMeter_updateValues @ 00115660 size 124 */

/* DWARF original prototype: void ClockMeter_updateValues(Meter * this) */

void ClockMeter_updateValues(Meter *this)

{
  long lVar1;
  tm_2 *__tp;
  long in_FS_OFFSET;
  tm result;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __tp = localtime_r(&(this->host->realtime).tv_sec,(tm_2 *)&result);
  *this->values = (double)(__tp->tm_hour * 0x3c + __tp->tm_min);
  strftime(this->txtBuffer,0x100,((char *)0x147166 /* "%H:%M:%S" */),__tp);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

