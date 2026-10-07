/* LoadAverageMeter_display @ 00128ef0 size 257 */

void LoadAverageMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  long in_FS_OFFSET;
  char buffer [20];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = xSnprintf(buffer,0x14,((char *)0x148863 /* "%.2f " */),*cast->values);
  RichString_appendnAscii(out,CRT_colors[0x40],buffer,wVar2);
  wVar2 = xSnprintf(buffer,0x14,((char *)0x148863 /* "%.2f " */),cast->values[1]);
  RichString_appendnAscii(out,CRT_colors[0x3f],buffer,wVar2);
  wVar2 = xSnprintf(buffer,0x14,((char *)0x148863 /* "%.2f " */),cast->values[2]);
  RichString_appendnAscii(out,CRT_colors[0x3e],buffer,wVar2);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

