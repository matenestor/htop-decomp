/* Process_updateCPUFieldWidths @ 00122df0 size 205 */

void Process_updateCPUFieldWidths(float percentage)

{
  uint8_t uVar1;
  byte bVar2;
  double dVar3;

  uVar1 = Row_fieldWidths[0x2f];
                    /* Unresolved local var: uint8_t width@[???] */
  if (percentage < 99.9) {
    if (Row_fieldWidths[0x2f] < 4) {
      Row_fieldWidths[0x2f] = '\x04';
    }
    if (Row_fieldWidths[0x35] < 4) {
      Row_fieldWidths[0x35] = '\x04';
      return;
    }
  }
  else {
    dVar3 = log10((double)percentage + 0.1);
    if (ABS(dVar3) < 4503599627370496.0) {
      dVar3 = (double)((ulong)((double)(long)dVar3 +
                              (double)(-(ulong)((double)(long)dVar3 < dVar3) & 0x3ff0000000000000))
                      | (ulong)dVar3 & 0x8000000000000000);
    }
    bVar2 = (byte)(int)(dVar3 + 2.0);
    if (uVar1 < bVar2) {
      Row_fieldWidths[0x2f] = bVar2;
    }
    if ((uint)Row_fieldWidths[0x35] < ((int)(dVar3 + 2.0) & 0xffU)) {
      Row_fieldWidths[0x35] = bVar2;
    }
  }
  return;
}

