/* PressureStallMeter_updateValues @ 0013d320 size 265 */

/* DWARF original prototype: void PressureStallMeter_updateValues(Meter * this) */

void PressureStallMeter_updateValues(Meter *this)

{
  Object_Delete __haystack;
  double *pdVar1;
  char *pcVar2;
  undefined *va0;
  char *file;

  file = ((char *)0x149e61 /* "cpu" */);
  __haystack = (this->super).klass[3].delete;
  pcVar2 = strstr((char *)__haystack,((char *)0x147826 /* "CPU" */));
  if (pcVar2 == (char *)0x0) {
    file = ((char *)0x14a0f3 /* "io" */);
    pcVar2 = strstr((char *)__haystack,((char *)0x147859 /* "IO" */));
    if (pcVar2 == (char *)0x0) {
      file = ((char *)0x1478f5 /* "memory" */);
      pcVar2 = strstr((char *)__haystack,((char *)0x1478be /* "IRQ" */));
      if (pcVar2 != (char *)0x0) {
        file = ((char *)0x147051 /* "irq" */);
      }
    }
  }
  pcVar2 = strstr((char *)__haystack,((char *)0x14784b /* "Some" */));
  pdVar1 = this->values;
  Platform_getPressureStall(file,pcVar2 != (char *)0x0,pdVar1,pdVar1 + 1,pdVar1 + 2);
  this->curItems = '\x01';
  pdVar1 = this->values;
  va0 = &DAT_00149b02;
  if (pcVar2 != (char *)0x0) {
    va0 = &DAT_00149afd;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x14cb30 /* "%s %s %5.2lf%% %5.2lf%% %5.2lf%%" */),va0,file,*pdVar1,pdVar1[1],
            pdVar1[2]);
  return;
}

