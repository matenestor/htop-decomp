/* SwapMeter_display @ 00131bd0 size 380 */

void SwapMeter_display(Meter_ *cast,RichString *out)

{
  double dVar1;
  long lVar2;
  long in_FS_OFFSET;
  char buffer [50];

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)0x147583 /* ":" */));
  Meter_humanUnit(buffer,cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  Meter_humanUnit(buffer,*cast->values,0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x148889 /* " used:" */));
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  dVar1 = cast->values[1];
  if (0.0 <= dVar1) {
    Meter_humanUnit(buffer,dVar1,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1488b0 /* " cache:" */));
    RichString_appendAscii(out,CRT_colors[0x1b],buffer);
    dVar1 = cast->values[2];
  }
  else {
    dVar1 = cast->values[2];
  }
  if (0.0 <= dVar1) {
    Meter_humanUnit(buffer,dVar1,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149151 /* " frontswap:" */));
    RichString_appendAscii(out,CRT_colors[0x1c],buffer);
  }
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

