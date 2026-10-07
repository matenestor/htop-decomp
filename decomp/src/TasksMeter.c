#include "htop.h"

/* TasksMeter_updateValues @ 0x12e840 */

/* DWARF original prototype: void TasksMeter_updateValues(Meter * this) */

void TasksMeter_updateValues(Meter *this)

{
  uint va0;
  uint uVar1;
  uint uVar2;
  uint va1;
  uint uVar3;
  double *pdVar4;
  Table *pTVar5;

  pdVar4 = this->values;
  pTVar5 = this->host->processTable;
  va0 = this->host->activeCPUs;
  uVar1 = *(uint *)((long)&pTVar5[1].displayList + 4);
  uVar2 = *(uint *)&pTVar5[1].displayList;
  va1 = *(uint *)&pTVar5[1].rows;
  uVar3 = *(uint *)((long)&pTVar5[1].rows + 4);
  if (uVar3 < va0) {
    va0 = uVar3;
  }
  *pdVar4 = (double)uVar1;
  pdVar4[1] = (double)uVar2;
  pdVar4[2] = (double)(va1 - (uVar1 + uVar2));
  pdVar4[3] = (double)va0;
  this->total = (double)va1;
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&s__u__u_00148c2b /* "%u/%u" */),va0,va1);
  return;
}


/* TasksMeter_display @ 0x1318d0 */

void TasksMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  Settings__2 *pSVar2;
  int wVar3;
  int wVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar2 = cast->host->settings;
  wVar3 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)cast->values[2]);
  RichString_appendnAscii(out,CRT_colors[0xf],(*(char (*) [20])(__fp - 0x58)),wVar3);
  if (pSVar2->hideUserlandThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)(long)&DAT_0014903d /* ", " */));
  wVar3 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)cast->values[1]);
  if (pSVar2->hideUserlandThreads == false) {
    wVar4 = CRT_colors[0x19];
  }
  else {
    wVar4 = CRT_colors[0xd];
  }
  RichString_appendnAscii(out,wVar4,(*(char (*) [20])(__fp - 0x58)),wVar3);
  if (pSVar2->hideUserlandThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)(long)&DAT_0014913d /* " thr" */));
  if (pSVar2->hideKernelThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)(long)&DAT_0014903d /* ", " */));
  wVar3 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)*cast->values);
  if (pSVar2->hideKernelThreads == false) {
    wVar4 = CRT_colors[0x19];
  }
  else {
    wVar4 = CRT_colors[0xd];
  }
  RichString_appendnAscii(out,wVar4,(*(char (*) [20])(__fp - 0x58)),wVar3);
  if (pSVar2->hideKernelThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)(long)&s_kthr_00149142 /* " kthr" */));
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)(__sec_rodata + 0x118) /* "; " */));
  wVar3 = xSnprintf((*(char (*) [20])(__fp - 0x58)),0x14,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),(int)cast->values[3]);
  RichString_appendnAscii(out,CRT_colors[0x19],(*(char (*) [20])(__fp - 0x58)),wVar3);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_running_00149148 /* " running" */));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

