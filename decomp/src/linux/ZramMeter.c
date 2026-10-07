#include "htop.h"

/* ZramMeter_updateValues @ 0x1408a0 */

/* DWARF original prototype: void ZramMeter_updateValues(Meter * this) */

void ZramMeter_updateValues(Meter *this)

{
  Machine *pMVar1;
  Table *pTVar2;
  Table *pTVar3;
  double *pdVar4;
  int wVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;
  long lVar9;
  double value;

                    /* Unresolved local var: LinuxMachine * lhost@[???] */
  pMVar1 = this->host;
  pTVar2 = pMVar1[2].activeTable;
  this->total = *(double *)&pMVar1[2].tables;
  value = *(double *)&pTVar2;
  pTVar3 = pMVar1[2].processTable;
  pdVar4 = this->values;
  *pdVar4 = value;
  pdVar4[1] = (double)(ulong)((long)pTVar3 - (long)pTVar2);
  wVar5 = Meter_humanUnit(this->txtBuffer,value,0x100);
  if (-1 < wVar5) {
    uVar6 = (ulong)wVar5;
    if ((uVar6 < 0x100) && (uVar6 != 0xff)) {
      pcVar8 = this->txtBuffer + uVar6;
      pcVar8[0] = '(';
      pcVar8[1] = '\0';
      uVar6 = 0xff - uVar6;
      wVar5 = Meter_humanUnit(pcVar8 + 1,*this->values + this->values[1],uVar6);
      if ((-1 < wVar5) && (uVar7 = (ulong)wVar5, uVar7 < uVar6)) {
        lVar9 = uVar6 - uVar7;
        pcVar8 = pcVar8 + 1 + uVar7;
        if (lVar9 != 1) {
          *pcVar8 = ')';
          if (lVar9 != 2) {
            pcVar8[1] = '/';
            pcVar8[2] = '\0';
            Meter_humanUnit(pcVar8 + 2,this->total,lVar9 - 2);
            return;
          }
          pcVar8[1] = '\0';
        }
      }
    }
  }
  return;
}


/* ZramMeter_display @ 0x140bc0 */

void ZramMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147583 /* ":" */));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),*cast->values,0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_used__00148889 /* " used:" */));
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  Meter_humanUnit((*(char (*) [50])(__fp - 0x68)),*cast->values + cast->values[1],0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_uncompressed__00149dd7 /* " uncompressed:" */));
  RichString_appendAscii(out,CRT_colors[0xf],(*(char (*) [50])(__fp - 0x68)));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

