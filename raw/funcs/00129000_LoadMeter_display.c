/* LoadMeter_display @ 00129000 size 129 */

void LoadMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  wchar_t len;
  long in_FS_OFFSET;
  char buffer [20];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  len = xSnprintf(buffer,0x14,((char *)0x148863 /* "%.2f " */),*cast->values);
  RichString_appendnAscii(out,CRT_colors[0x3d],buffer,len);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

