/* PressureStallMeter_display @ 001445e0 size 257 */

void PressureStallMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  long in_FS_OFFSET;
  char buffer [20];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = xSnprintf(buffer,0x14,((char *)0x14a083 /* "%5.2lf%% " */),*cast->values);
  RichString_appendnAscii(out,CRT_colors[0x58],buffer,wVar2);
  wVar2 = xSnprintf(buffer,0x14,((char *)0x14a083 /* "%5.2lf%% " */),cast->values[1]);
  RichString_appendnAscii(out,CRT_colors[0x59],buffer,wVar2);
  wVar2 = xSnprintf(buffer,0x14,((char *)0x14a083 /* "%5.2lf%% " */),cast->values[2]);
  RichString_appendnAscii(out,CRT_colors[0x5a],buffer,wVar2);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

