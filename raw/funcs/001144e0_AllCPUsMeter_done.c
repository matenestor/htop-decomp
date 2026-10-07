/* AllCPUsMeter_done @ 001144e0 size 131 */

/* DWARF original prototype: void AllCPUsMeter_done(Meter * this) */

void AllCPUsMeter_done(Meter *this)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  uint *__ptr;
  Meter_ *cast;
  ulong uVar4;
  undefined8 *__ptr_00;

                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  __ptr = this->meterData;
  __ptr_00 = *(undefined8 **)(__ptr + 2);
  uVar3 = *__ptr;
  cVar2 = (char)*(uchar *)(this->super).klass[3].delete;
  if (cVar2 == 'L') {
    uVar4 = (ulong)(uVar3 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar3 >> 1);
    if (cVar2 != 'R') {
      uVar4 = (long)(int)uVar3;
    }
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (0 < (int)uVar4) {
    puVar1 = __ptr_00 + uVar4;
    do {
      cast = (Meter_ *)*__ptr_00;
      __ptr_00 = __ptr_00 + 1;
      Meter_delete(cast);
    } while (__ptr_00 != puVar1);
    __ptr_00 = *(undefined8 **)(__ptr + 2);
  }
  free(__ptr_00);
  free(__ptr);
  return;
}

