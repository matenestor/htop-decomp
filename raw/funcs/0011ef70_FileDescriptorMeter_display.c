/* FileDescriptorMeter_display @ 0011ef70 size 362 */

void FileDescriptorMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  long in_FS_OFFSET;
  char buffer [50];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (*cast->values < 0.0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14772b /* "unknown" */));
      return;
    }
  }
  else {
                    /* Unresolved local var: Meter * this@[???]
                       Unresolved local var: wchar_t len@[???] */
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1476bd /* "used: " */));
    wVar2 = xSnprintf(buffer,0x32,((char *)0x147749 /* "%.0lf" */),*cast->values);
    RichString_appendnAscii(out,CRT_colors[0x5b],buffer,wVar2);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1476c4 /* " max: " */));
    if (1073741824.0 < cast->values[1]) {
      RichString_appendAscii(out,CRT_colors[0x5c],((char *)0x147739 /* "unlimited" */));
    }
    else {
      wVar2 = xSnprintf(buffer,0x32,((char *)0x147749 /* "%.0lf" */),cast->values[1]);
      RichString_appendnAscii(out,CRT_colors[0x5c],buffer,wVar2);
    }
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

