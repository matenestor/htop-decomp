#include "htop.h"

/* ZfsCompressedArcMeter_readStats @ 0x13c360 */

/* DWARF original prototype: void ZfsCompressedArcMeter_readStats(Meter * this, ZfsArcStats * stats)
    */

void ZfsCompressedArcMeter_readStats(Meter *this,ZfsArcStats *stats)

{
  double *pdVar1;
  ulong uVar2;
  double dVar3;

  pdVar1 = this->values;
  if (stats->isCompressed == 0) {
    uVar2 = stats->size;
    this->total = (double)uVar2;
    *pdVar1 = (double)uVar2;
    return;
  }
  if ((long)stats->uncompressed < 0) {
    uVar2 = stats->compressed;
  }
  else {
    uVar2 = stats->compressed;
  }
  dVar3 = (double)stats->uncompressed;
  if (-1 < (long)uVar2) {
    this->total = dVar3;
    *pdVar1 = (double)(long)uVar2;
    return;
  }
  this->total = dVar3;
  *pdVar1 = (double)uVar2;
  return;
}


/* ZfsCompressedArcMeter_updateValues @ 0x13d5c0 */

/* DWARF original prototype: void ZfsCompressedArcMeter_updateValues(Meter * this) */

void ZfsCompressedArcMeter_updateValues(Meter *this)

{
  Machine *pMVar1;
  ulong uVar2;
  double dVar3;
  double dVar4;

                    /* Unresolved local var: LinuxMachine * lhost@[???] */
  pMVar1 = this->host;
  if (*(int *)((long)&pMVar1[2].cachedMem + 4) == 0) {
    dVar4 = (double)pMVar1[2].totalSwap;
    dVar3 = dVar4;
  }
  else {
    if ((long)pMVar1[2].tableCount < 0) {
      (*(uint *)((char *)&uVar2 + 0)) = pMVar1[2].userId;
      (*(uchar *)((char *)&uVar2 + 4)) = pMVar1[2].field_0x94;
      (*(uchar *)((char *)&uVar2 + 5)) = pMVar1[2].field_0x95;
      (*(uchar *)((char *)&uVar2 + 6)) = pMVar1[2].field_0x96;
      (*(uchar *)((char *)&uVar2 + 7)) = pMVar1[2].field_0x97;
    }
    else {
      (*(uint *)((char *)&uVar2 + 0)) = pMVar1[2].userId;
      (*(uchar *)((char *)&uVar2 + 4)) = pMVar1[2].field_0x94;
      (*(uchar *)((char *)&uVar2 + 5)) = pMVar1[2].field_0x95;
      (*(uchar *)((char *)&uVar2 + 6)) = pMVar1[2].field_0x96;
      (*(uchar *)((char *)&uVar2 + 7)) = pMVar1[2].field_0x97;
    }
    dVar3 = (double)pMVar1[2].tableCount;
    if ((long)uVar2 < 0) {
      dVar4 = (double)uVar2;
    }
    else {
      dVar4 = (double)(long)uVar2;
    }
  }
  this->total = dVar3;
  *this->values = dVar4;
  if (0.0 < dVar4) {
    xSnprintf(this->txtBuffer,0x100,((char *)(long)&s___2f_1_00149b79 /* "%.2f:1" */),this->total / dVar4);
    return;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&DAT_001474de /* "N/A" */));
  return;
}


/* ZfsCompressedArcMeter_display @ 0x1446f0 */

void ZfsCompressedArcMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  int len;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (*cast->values <= 0.0) {
    RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_001470dd /* " " */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(out,CRT_colors[5],((char *)(long)&s_Compression_Unavailable_0014a0b2 /* "Compression Unavailable" */));
      return;
    }
  }
  else {
                    /* Unresolved local var: Meter * this@[???]
                       Unresolved local var: int len@[???] */
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->total,0x32);
    RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Uncompressed__0014a08d /* " Uncompressed, " */));
    Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),*cast->values,0x32);
    RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Compressed__0014a09d /* " Compressed, " */));
    if (0.0 < *cast->values) {
      len = xSnprintf((*(char (*) [50])(__fp - 0x68)),0x32,((char *)(long)&s___2f_1_00149b79 /* "%.2f:1" */),cast->total / *cast->values);
    }
    else {
      len = xSnprintf((*(char (*) [50])(__fp - 0x68)),0x32,((char *)(long)&DAT_001474de /* "N/A" */));
    }
    RichString_appendnAscii(out,CRT_colors[99],(*(char (*) [50])(__fp - 0x68)),len);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_Ratio_0014a0ab /* " Ratio" */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

