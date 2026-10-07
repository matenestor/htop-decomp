#include "htop.h"

/* LoadAverageMeter_updateValues @ 0x128d50 */

/* DWARF original prototype: void LoadAverageMeter_updateValues(Meter * this) */

void LoadAverageMeter_updateValues(Meter *this)

{
  uint uVar1;
  double *pdVar2;
  int *pwVar3;
  double dVar4;

  pdVar2 = this->values;
  Platform_getLoadAverage(pdVar2,pdVar2 + 1,pdVar2 + 2);
  pdVar2 = this->values;
  this->curItems = '\x01';
  pwVar3 = ((char *)(long)&OK_attributes /* L"\x14" */);
  dVar4 = 1.0;
  if (1.0 <= *pdVar2) {
    uVar1 = this->host->activeCPUs;
    dVar4 = (double)uVar1;
    pwVar3 = ((char *)(long)&Medium_attributes /* L"\x15" */);
    if (dVar4 <= *pdVar2) {
      dVar4 = (double)(uVar1 * 2);
      pwVar3 = ((char *)(long)&High_attributes /* L"\x10" */);
    }
  }
  this->curAttributes = pwVar3;
  this->total = dVar4;
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&DAT_00148854 /* "%.2f/%.2f/%.2f" */),*pdVar2,pdVar2[1],pdVar2[2]);
  return;
}


/* LoadMeter_updateValues @ 0x128e10 */

/* DWARF original prototype: void LoadMeter_updateValues(Meter * this) */

void LoadMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  double dVar1;
  uint uVar2;
  int *pwVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  (*(long (*))(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  Platform_getLoadAverage(this->values,&(*(double (*))(__fp - 0x28)),&(*(double (*))(__fp - 0x30)));
  dVar4 = 1.0;
  pwVar3 = ((char *)(long)&OK_attributes /* L"\x14" */);
  dVar1 = *this->values;
  if (1.0 <= dVar1) {
    uVar2 = this->host->activeCPUs;
    dVar4 = (double)uVar2;
    pwVar3 = ((char *)(long)&Medium_attributes /* L"\x15" */);
    if (dVar4 <= dVar1) {
      dVar4 = (double)(uVar2 * 2);
      pwVar3 = ((char *)(long)&High_attributes /* L"\x10" */);
    }
  }
  this->curAttributes = pwVar3;
  this->total = dVar4;
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&DAT_0014885e /* "%.2f" */),*this->values);
  if ((*(long (*))(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LoadAverageMeter_display @ 0x128ef0 */

void LoadAverageMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  int wVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),*cast->values);
  RichString_appendnAscii(out,CRT_colors[0x40],(*(char (*) [20])(__fp - 0x58)),wVar2);
  wVar2 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),cast->values[1]);
  RichString_appendnAscii(out,CRT_colors[0x3f],(*(char (*) [20])(__fp - 0x58)),wVar2);
  wVar2 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),cast->values[2]);
  RichString_appendnAscii(out,CRT_colors[0x3e],(*(char (*) [20])(__fp - 0x58)),wVar2);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* LoadMeter_display @ 0x129000 */

void LoadMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int len;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  len = xSnprintf((*(char (*) [20])(__fp - 0x38)),0x14,((char *)(long)&s___2f_00148863 /* "%.2f " */),*cast->values);
  RichString_appendnAscii(out,CRT_colors[0x3d],(*(char (*) [20])(__fp - 0x38)),len);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

