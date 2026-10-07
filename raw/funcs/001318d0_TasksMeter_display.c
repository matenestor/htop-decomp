/* TasksMeter_display @ 001318d0 size 544 */

void TasksMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  Settings__2 *pSVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  long in_FS_OFFSET;
  char buffer [20];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar2 = cast->host->settings;
  wVar3 = xSnprintf(buffer,0x14,((char *)0x149710 /* "%d" */),(int)cast->values[2]);
  RichString_appendnAscii(out,CRT_colors[0xf],buffer,wVar3);
  if (pSVar2->hideUserlandThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)0x14903d /* ", " */));
  wVar3 = xSnprintf(buffer,0x14,((char *)0x149710 /* "%d" */),(int)cast->values[1]);
  if (pSVar2->hideUserlandThreads == false) {
    wVar4 = CRT_colors[0x19];
  }
  else {
    wVar4 = CRT_colors[0xd];
  }
  RichString_appendnAscii(out,wVar4,buffer,wVar3);
  if (pSVar2->hideUserlandThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)0x14913d /* " thr" */));
  if (pSVar2->hideKernelThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)0x14903d /* ", " */));
  wVar3 = xSnprintf(buffer,0x14,((char *)0x149710 /* "%d" */),(int)*cast->values);
  if (pSVar2->hideKernelThreads == false) {
    wVar4 = CRT_colors[0x19];
  }
  else {
    wVar4 = CRT_colors[0xd];
  }
  RichString_appendnAscii(out,wVar4,buffer,wVar3);
  if (pSVar2->hideKernelThreads == false) {
    wVar3 = CRT_colors[0xe];
  }
  else {
    wVar3 = CRT_colors[0xd];
  }
  RichString_appendAscii(out,wVar3,((char *)0x149142 /* " kthr" */));
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147118 /* "; " */));
  wVar3 = xSnprintf(buffer,0x14,((char *)0x149710 /* "%d" */),(int)cast->values[3]);
  RichString_appendnAscii(out,CRT_colors[0x19],buffer,wVar3);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149148 /* " running" */));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

