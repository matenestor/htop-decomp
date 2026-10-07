/* Row_printRate @ 00131650 size 601 */

void Row_printRate(RichString *str,double rate,_Bool coloring)

{
  long lVar1;
  wchar_t attrs;
  wchar_t attrs_00;
  wchar_t wVar2;
  wchar_t wVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  double va0;
  char buffer [16];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = CRT_colors[0x1d];
  wVar3 = CRT_colors[0x1e];
  attrs = wVar2;
  if (coloring) {
    attrs = CRT_colors[0x20];
  }
  attrs_00 = wVar2;
  if (coloring) {
    attrs_00 = CRT_colors[0xc];
  }
  if (rate < 0.0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(str,wVar3,((char *)0x14908c /* "        N/A " */));
      return;
    }
    goto LAB_001318c8;
  }
  if (rate < 0.005) {
                    /* Unresolved local var: wchar_t len@[???] */
    wVar2 = __snprintf_chk(buffer,0x10,2,0x10,((char *)0x1490fb /* "%7.2f B/s " */),rate);
    RichString_appendnAscii(str,wVar3,buffer,wVar2);
  }
  else {
    pcVar4 = ((char *)0x1490fb /* "%7.2f B/s " */);
    if (1024.0 <= rate) {
      if (1048576.0 <= rate) {
        if (rate < 1073741824.0) {
                    /* Unresolved local var: wchar_t len@[???] */
          wVar2 = __snprintf_chk(buffer,0x10,2,0x10,((char *)0x149111 /* "%7.2f M/s " */),rate * 9.5367431640625e-07);
          RichString_appendnAscii(str,attrs,buffer,wVar2);
        }
        else {
          if (rate < 1099511627776.0) {
                    /* Unresolved local var: wchar_t len@[???] */
            va0 = rate * 9.313225746154785e-10;
            pcVar4 = ((char *)0x14911c /* "%7.2f G/s " */);
          }
          else if (rate < 1125899906842624.0) {
                    /* Unresolved local var: wchar_t len@[???] */
            va0 = rate * 9.094947017729282e-13;
            pcVar4 = ((char *)0x149127 /* "%7.2f T/s " */);
          }
          else {
                    /* Unresolved local var: wchar_t len@[???] */
            va0 = rate * 8.881784197001252e-16;
            pcVar4 = ((char *)0x149132 /* "%7.2f P/s " */);
          }
          wVar2 = __snprintf_chk(buffer,0x10,2,0x10,pcVar4,va0);
          RichString_appendnAscii(str,attrs_00,buffer,wVar2);
        }
        goto LAB_0013179f;
      }
                    /* Unresolved local var: wchar_t len@[???] */
      rate = rate * 0.0009765625;
      pcVar4 = ((char *)0x149106 /* "%7.2f K/s " */);
    }
                    /* Unresolved local var: wchar_t len@[???] */
    wVar3 = __snprintf_chk(buffer,0x10,2,0x10,pcVar4,rate);
    RichString_appendnAscii(str,wVar2,buffer,wVar3);
  }
LAB_0013179f:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_001318c8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

