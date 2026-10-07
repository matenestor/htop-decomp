/* Row_printCount @ 00130fb0 size 644 */

void Row_printCount(RichString *str,ulonglong number,_Bool coloring)

{
  wchar_t attrs;
  long lVar1;
  wchar_t attrs_00;
  wchar_t attrs_01;
  wchar_t attrs_02;
  long in_FS_OFFSET;
  char buffer [13];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  attrs = CRT_colors[0x1d];
  attrs_00 = attrs;
  attrs_01 = attrs;
  attrs_02 = attrs;
  if (coloring) {
    attrs_00 = CRT_colors[0xc];
    attrs_01 = CRT_colors[0x20];
    attrs_02 = CRT_colors[0x1e];
  }
  if (number == 0xffffffffffffffff) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(str,CRT_colors[0x1e],((char *)0x14908c /* "        N/A " */));
      return;
    }
  }
  else {
    if (number < 100000000000000000) {
      if (number < 100000000000000) {
        if (number < 10000000000) {
          xSnprintf(buffer,0xd,((char *)0x149099 /* "%11llu " */),number);
          RichString_appendnAscii(str,attrs_00,buffer,L'\x02');
          RichString_appendnAscii(str,attrs_01,buffer + 2,L'\x03');
          RichString_appendnAscii(str,attrs,buffer + 5,L'\x03');
          RichString_appendnAscii(str,attrs_02,buffer + 8,L'\x04');
        }
        else {
          xSnprintf(buffer,0xd,((char *)0x149099 /* "%11llu " */),number / 1000);
          RichString_appendnAscii(str,attrs_00,buffer,L'\x05');
          RichString_appendnAscii(str,attrs_01,buffer + 5,L'\x03');
          RichString_appendnAscii(str,attrs,buffer + 8,L'\x04');
        }
      }
      else {
        xSnprintf(buffer,0xd,((char *)0x149099 /* "%11llu " */),number / 1000000);
        RichString_appendnAscii(str,attrs_00,buffer,L'\b');
        RichString_appendnAscii(str,attrs_01,buffer + 8,L'\x04');
      }
    }
    else {
      xSnprintf(buffer,0xd,((char *)0x149099 /* "%11llu " */),number / 1000000000);
      RichString_appendnAscii(str,attrs_00,buffer,L'\f');
    }
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

