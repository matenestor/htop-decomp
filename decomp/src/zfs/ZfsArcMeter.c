#include "htop.h"

/* ZfsArcMeter_readStats @ 0x13c0c0 */

/* DWARF original prototype: void ZfsArcMeter_readStats(Meter * this, ZfsArcStats * stats) */

void ZfsArcMeter_readStats(Meter *this,ZfsArcStats *stats)

{
  ulong uVar1;
  double *pdVar2;
  ulong uVar3;

  uVar1 = stats->MFU;
  pdVar2 = this->values;
  this->total = (double)stats->max;
  uVar3 = stats->MRU;
  *pdVar2 = (double)uVar1;
  uVar1 = stats->anon;
  pdVar2[1] = (double)uVar3;
  uVar3 = stats->header;
  pdVar2[2] = (double)uVar1;
  uVar1 = stats->other;
  pdVar2[3] = (double)uVar3;
  pdVar2[4] = (double)uVar1;
  this->curItems = '\x05';
  uVar1 = stats->size;
  if (-1 < (long)uVar1) {
    pdVar2[5] = (double)(long)uVar1;
    return;
  }
  pdVar2[5] = (double)uVar1;
  return;
}


/* ZfsArcMeter_updateValues @ 0x140a50 */

/* DWARF original prototype: void ZfsArcMeter_updateValues(Meter * this) */

void ZfsArcMeter_updateValues(Meter *this)

{
  int wVar1;
  ulong uVar2;

                    /* Unresolved local var: LinuxMachine * lhost@[???] */
  ZfsArcMeter_readStats(this,(ZfsArcStats *)&this->host[2].cachedMem);
  wVar1 = Meter_humanUnit(this->txtBuffer,this->values[5],0x100);
  if (-1 < wVar1) {
    uVar2 = (ulong)wVar1;
    if ((uVar2 < 0x100) && (uVar2 != 0xff)) {
      (this->txtBuffer + uVar2)[0] = '/';
      (this->txtBuffer + uVar2)[1] = '\0';
      Meter_humanUnit(this->txtBuffer + uVar2 + 1,this->total,0xff - uVar2);
      return;
    }
  }
  return;
}


/* ZfsArcMeter_display @ 0x140ce0 */

void ZfsArcMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (cast->values[5] <= 0.0) {
    RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_001470dd /* " " */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(out,CRT_colors[5],((char *)(long)(__sec_rodata + 0x30be) /* "Unavailable" */));
      return;
    }
  }
  else {
                    /* Unresolved local var: Meter * this@[???] */
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->total,0x32);
    RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[5],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Used__00149de6 /* " Used:" */));
    RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),*cast->values,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_MFU__00149ded /* " MFU:" */));
    RichString_appendAscii(out,CRT_colors[0x5d],(*(char (*) [50])(__fp - 0x68)));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[1],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_MRU__00149df3 /* " MRU:" */));
    RichString_appendAscii(out,CRT_colors[0x5e],(*(char (*) [50])(__fp - 0x68)));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[2],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Anon__00149df9 /* " Anon:" */));
    RichString_appendAscii(out,CRT_colors[0x5f],(*(char (*) [50])(__fp - 0x68)));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[3],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Hdr__00149e00 /* " Hdr:" */));
    RichString_appendAscii(out,CRT_colors[0x60],(*(char (*) [50])(__fp - 0x68)));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->values[4],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Oth__00149e06 /* " Oth:" */));
    RichString_appendAscii(out,CRT_colors[0x61],(*(char (*) [50])(__fp - 0x68)));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

