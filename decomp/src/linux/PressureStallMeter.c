#include "htop.h"

/* PressureStallMeter_updateValues @ 0x13d320 */

/* DWARF original prototype: void PressureStallMeter_updateValues(Meter * this) */

void PressureStallMeter_updateValues(Meter *this)

{
  Object_Delete __haystack;
  double *pdVar1;
  char *pcVar2;
  undefined *va0;
  char *file;

  file = ((char *)(long)(__sec_rodata + 0x2e61) /* "cpu" */);
  __haystack = (this->super).klass[3].delete;
  pcVar2 = strstr((char *)__haystack,((char *)(long)(__sec_rodata + 0x826) /* "CPU" */));
  if (pcVar2 == (char *)0x0) {
    file = ((char *)(long)&DAT_0014a0f3 /* "io" */);
    pcVar2 = strstr((char *)__haystack,((char *)(long)(__sec_rodata + 0x859) /* "IO" */));
    if (pcVar2 == (char *)0x0) {
      file = ((char *)(long)(__sec_rodata + 0x8f5) /* "memory" */);
      pcVar2 = strstr((char *)__haystack,((char *)(long)(__sec_rodata + 0x8be) /* "IRQ" */));
      if (pcVar2 != (char *)0x0) {
        file = ((char *)(long)&DAT_00147051 /* "irq" */);
      }
    }
  }
  pcVar2 = strstr((char *)__haystack,((char *)(long)(__sec_rodata + 0x84b) /* "Some" */));
  pdVar1 = this->values;
  Platform_getPressureStall(file,pcVar2 != (char *)0x0,pdVar1,pdVar1 + 1,pdVar1 + 2);
  this->curItems = '\x01';
  pdVar1 = this->values;
  va0 = &DAT_00149b02;
  if (pcVar2 != (char *)0x0) {
    va0 = &DAT_00149afd;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&s__s__s__5_2lf____5_2lf____5_2lf___0014cb30 /* "%s %s %5.2lf%% %5.2lf%% %5.2lf%%" */),va0,file,*pdVar1,pdVar1[1],
            pdVar1[2]);
  return;
}


/* PressureStallMeter_display @ 0x1445e0 */

void PressureStallMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  int wVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)&s__5_2lf___0014a083 /* "%5.2lf%% " */),*cast->values);
  RichString_appendnAscii(out,CRT_colors[0x58],(*(char (*) [20])(__fp - 0x58)),wVar2);
  wVar2 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)&s__5_2lf___0014a083 /* "%5.2lf%% " */),cast->values[1]);
  RichString_appendnAscii(out,CRT_colors[0x59],(*(char (*) [20])(__fp - 0x58)),wVar2);
  wVar2 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)&s__5_2lf___0014a083 /* "%5.2lf%% " */),cast->values[2]);
  RichString_appendnAscii(out,CRT_colors[0x5a],(*(char (*) [20])(__fp - 0x58)),wVar2);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

