/* ZfsArcMeter_display @ 00140ce0 size 629 */

void ZfsArcMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  long in_FS_OFFSET;
  char buffer [50];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (cast->values[5] <= 0.0) {
    RichString_writeAscii(out,CRT_colors[0xe],((char *)0x1470dd /* " " */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(out,CRT_colors[5],((char *)0x14a0be /* "Unavailable" */));
      return;
    }
  }
  else {
                    /* Unresolved local var: Meter * this@[???] */
    Meter_humanUnit(buffer,cast->total,0x32);
    RichString_appendAscii(out,CRT_colors[0xf],buffer);
    Meter_humanUnit(buffer,cast->values[5],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149de6 /* " Used:" */));
    RichString_appendAscii(out,CRT_colors[0xf],buffer);
    Meter_humanUnit(buffer,*cast->values,0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149ded /* " MFU:" */));
    RichString_appendAscii(out,CRT_colors[0x5d],buffer);
    Meter_humanUnit(buffer,cast->values[1],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149df3 /* " MRU:" */));
    RichString_appendAscii(out,CRT_colors[0x5e],buffer);
    Meter_humanUnit(buffer,cast->values[2],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149df9 /* " Anon:" */));
    RichString_appendAscii(out,CRT_colors[0x5f],buffer);
    Meter_humanUnit(buffer,cast->values[3],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149e00 /* " Hdr:" */));
    RichString_appendAscii(out,CRT_colors[0x60],buffer);
    Meter_humanUnit(buffer,cast->values[4],0x32);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x149e06 /* " Oth:" */));
    RichString_appendAscii(out,CRT_colors[0x61],buffer);
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

