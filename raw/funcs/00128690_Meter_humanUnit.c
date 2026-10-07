/* Meter_humanUnit @ 00128690 size 189 */

wchar_t Meter_humanUnit(char *buffer,double value,size_t size)

{
  wchar_t wVar1;
  long lVar2;
  long lVar3;
  int va0;
  int va2;
  double dVar4;

  va0 = 0;
  va2 = 0x4b;
  lVar2 = 0;
  dVar4 = value;
  if (1024.0 <= value) {
    do {
      value = value * 0.0009765625;
      lVar3 = lVar2 + 1;
      dVar4 = value;
      if (value < 1024.0) {
        va2 = (int)((char *)0x14db98 /* "KMGTPEZYRQ" */)[lVar2 + 1];
        if (99.9 < value) {
          dVar4 = 100.0;
          va0 = 0;
        }
        else {
          va0 = 2;
          if (value <= 9.99) goto LAB_001286de;
                    /* Unresolved local var: double limit@[???] */
          dVar4 = 10.0;
          va0 = 1;
        }
        if (dVar4 <= value) {
          dVar4 = value;
        }
        goto LAB_001286de;
      }
      lVar2 = lVar3;
    } while (lVar3 != 9);
    va0 = 0;
    va2 = 0x51;
    if (9999.0 < value) {
      wVar1 = xSnprintf(buffer,size,((char *)0x14883c /* "inf" */));
      return wVar1;
    }
  }
LAB_001286de:
  wVar1 = xSnprintf(buffer,size,((char *)0x148840 /* "%.*f%c" */),va0,dVar4,va2);
  return wVar1;
}

