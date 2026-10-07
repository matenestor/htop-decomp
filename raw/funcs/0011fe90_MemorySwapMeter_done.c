/* MemorySwapMeter_done @ 0011fe90 size 50 */

/* DWARF original prototype: void MemorySwapMeter_done(Meter * this) */

void MemorySwapMeter_done(Meter *this)

{
  undefined8 *__ptr;

  __ptr = this->meterData;
  Meter_delete((Meter_ *)__ptr[1]);
  Meter_delete((Meter_ *)*__ptr);
  free(__ptr);
  return;
}

