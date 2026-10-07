/* ZramMeter_display @ 00140bc0 size 279 */

void ZramMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  long in_FS_OFFSET;
  char buffer [50];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)0x147583 /* ":" */));
  Meter_humanUnit(buffer,cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  Meter_humanUnit(buffer,*cast->values,0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x148889 /* " used:" */));
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  Meter_humanUnit(buffer,*cast->values + cast->values[1],0x32);
  RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149dd7 /* " uncompressed:" */));
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

