#include "htop.h"

/* FileDescriptorMeter_display @ 0x11ef70 */

void FileDescriptorMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  long lVar1;
  int wVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (*cast->values < 0.0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)(__sec_rodata + 0x72b) /* "unknown" */));
      return;
    }
  }
  else {
                    /* Unresolved local var: Meter * this@[???]
                       Unresolved local var: int len@[???] */
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_used__001476bd /* "used: " */));
    wVar2 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s___0lf_00147749 /* "%.0lf" */),*cast->values);
    RichString_appendnAscii(out,CRT_colors[0x5b],(*(char (*) [50])(__fp - 0x78)),wVar2);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_max__001476c4 /* " max: " */));
    if (1073741824.0 < cast->values[1]) {
      RichString_appendAscii(out,CRT_colors[0x5c],((char *)(long)(__sec_rodata + 0x739) /* "unlimited" */));
    }
    else {
      wVar2 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s___0lf_00147749 /* "%.0lf" */),cast->values[1]);
      RichString_appendnAscii(out,CRT_colors[0x5c],(*(char (*) [50])(__fp - 0x78)),wVar2);
    }
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FileDescriptorMeter_updateValues @ 0x11f910 */

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
    xSnprintf(this->txtBuffer,0x100,((char *)(long)&s_unknown_unknown_00147723 /* "unknown/unknown" */));
    return;
  }
  if (1073741824.0 < pdVar1[1]) {
    xSnprintf(this->txtBuffer,0x100,((char *)(long)&s___0lf_unlimited_00147733 /* "%.0lf/unlimited" */),dVar4);
    return;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&DAT_00147743 /* "%.0lf/%.0lf" */),dVar4,pdVar1[1]);
  return;
}

