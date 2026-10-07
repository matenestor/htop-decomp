/* MemoryMeter_display @ 00129470 size 625 */

void MemoryMeter_display(Meter_ *cast,RichString *out)

{
  double value;
  long lVar1;
  double *pdVar2;
  long in_FS_OFFSET;
  char buffer [50];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)0x147583 /* ":" */));
  Meter_humanUnit(buffer,cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  Meter_humanUnit(buffer,*cast->values,0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x148889 /* " used:" */));
  RichString_appendAscii(out,CRT_colors[0x33],buffer);
  pdVar2 = cast->values;
  if (0.0 <= pdVar2[1]) {
    Meter_humanUnit(buffer,pdVar2[1],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x148890 /* " shared:" */));
    RichString_appendAscii(out,CRT_colors[0x37],buffer);
    pdVar2 = cast->values;
    value = pdVar2[2];
  }
  else {
    value = pdVar2[2];
  }
  if (0.0 <= value) {
    Meter_humanUnit(buffer,value,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x148899 /* " compressed:" */));
    RichString_appendAscii(out,CRT_colors[0x38],buffer);
    pdVar2 = cast->values;
  }
  Meter_humanUnit(buffer,pdVar2[3],0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1488a6 /* " buffers:" */));
  RichString_appendAscii(out,CRT_colors[0x35],buffer);
  Meter_humanUnit(buffer,cast->values[4],0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1488b0 /* " cache:" */));
  RichString_appendAscii(out,CRT_colors[0x36],buffer);
  if (0.0 <= cast->values[5]) {
    Meter_humanUnit(buffer,cast->values[5],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1488b8 /* " available:" */));
    RichString_appendAscii(out,CRT_colors[0xf],buffer);
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

