/* ZfsCompressedArcMeter_display @ 001446f0 size 447 */

void ZfsCompressedArcMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  wchar_t len;
  long in_FS_OFFSET;
  char buffer [50];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (*cast->values <= 0.0) {
    RichString_writeAscii(out,CRT_colors[0xe],((char *)0x1470dd /* " " */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(out,CRT_colors[5],((char *)0x14a0b2 /* "Compression Unavailable" */));
      return;
    }
  }
  else {
                    /* Unresolved local var: Meter * this@[???]
                       Unresolved local var: wchar_t len@[???] */
    Meter_humanUnit(buffer,cast->total,0x32);
    RichString_appendAscii(out,CRT_colors[0xf],buffer);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14a08d /* " Uncompressed, " */));
    Meter_humanUnit(buffer,*cast->values,0x32);
    RichString_appendAscii(out,CRT_colors[0xf],buffer);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14a09d /* " Compressed, " */));
    if (0.0 < *cast->values) {
      len = xSnprintf(buffer,0x32,((char *)0x149b79 /* "%.2f:1" */),cast->total / *cast->values);
    }
    else {
      len = xSnprintf(buffer,0x32,((char *)0x1474de /* "N/A" */));
    }
    RichString_appendnAscii(out,CRT_colors[99],buffer,len);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14a0ab /* " Ratio" */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

