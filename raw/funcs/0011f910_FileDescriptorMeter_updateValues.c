/* FileDescriptorMeter_updateValues @ 0011f910 size 396 */

/* DWARF original prototype: void FileDescriptorMeter_updateValues(Meter * this) */

void FileDescriptorMeter_updateValues(Meter *this)

{
  double *pdVar1;
  int iVar2;
  double dVar3;
  double dVar4;

  pdVar1 = this->values;
  *pdVar1 = 0.0;
  pdVar1[1] = 1.0;
  Platform_getFileDescriptors(pdVar1,pdVar1 + 1);
  pdVar1 = this->values;
  this->curItems = '\x01';
  dVar4 = pdVar1[1];
  if (dVar4 <= 65536.0) {
LAB_0011f9f8:
    this->total = dVar4;
  }
  else {
    dVar3 = this->total;
    if (*pdVar1 * 16.0 <= dVar3) {
LAB_0011f9d8:
      if (dVar4 < dVar3) {
        this->total = dVar4;
        dVar3 = dVar4;
      }
      dVar4 = 1073741824.0;
      if (1073741824.0 < dVar3) goto LAB_0011f9f8;
    }
    else {
      this->total = 65536.0;
      dVar4 = *pdVar1;
      iVar2 = 0xf;
      dVar3 = 65536.0;
      if (65536.0 < dVar4 * 16.0) {
        do {
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            dVar3 = this->total;
            dVar4 = pdVar1[1];
            goto LAB_0011f9d8;
          }
          dVar3 = dVar3 + dVar3;
          this->total = dVar3;
        } while (dVar3 < *pdVar1 * 16.0);
        dVar4 = pdVar1[1];
        goto LAB_0011f9d8;
      }
      if (65536.0 <= pdVar1[1]) goto LAB_0011fa04;
      this->total = pdVar1[1];
    }
  }
  dVar4 = *pdVar1;
LAB_0011fa04:
  if (dVar4 < 0.0) {
    xSnprintf(this->txtBuffer,0x100,((char *)0x147723 /* "unknown/unknown" */));
    return;
  }
  if (1073741824.0 < pdVar1[1]) {
    xSnprintf(this->txtBuffer,0x100,((char *)0x147733 /* "%.0lf/unlimited" */),dVar4);
    return;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x147743 /* "%.0lf/%.0lf" */),dVar4,pdVar1[1]);
  return;
}

