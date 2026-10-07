/* NetworkIOMeter_display @ 001296f0 size 391 */

void NetworkIOMeter_display(Object *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  char *data;
  long in_FS_OFFSET;
  char buffer [64];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (status_15c060 == RATESTATUS_NODATA) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      wVar2 = CRT_colors[0x10];
      data = ((char *)0x1476cb /* "no data" */);
LAB_00129831:
      RichString_writeAscii(out,wVar2,data);
      return;
    }
  }
  else if (status_15c060 == RATESTATUS_STALE) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      wVar2 = CRT_colors[0x15];
      data = ((char *)0x147702 /* "stale data" */);
      goto LAB_00129831;
    }
  }
  else if (status_15c060 == RATESTATUS_INIT) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      wVar2 = CRT_colors[0xf];
      data = ((char *)0x1476f2 /* "initializing..." */);
      goto LAB_00129831;
    }
  }
  else {
    RichString_writeAscii(out,CRT_colors[0xe],((char *)0x1488c4 /* "rx: " */));
    RichString_appendAscii(out,CRT_colors[0x11],cached_rxb_diff_str);
    RichString_appendAscii(out,CRT_colors[0x11],((char *)0x147715 /* "iB/s" */));
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x1488c9 /* " tx: " */));
    RichString_appendAscii(out,CRT_colors[0x12],cached_txb_diff_str);
    RichString_appendAscii(out,CRT_colors[0x12],((char *)0x147715 /* "iB/s" */));
    wVar2 = xSnprintf(buffer,0x40,((char *)0x1488cf /* " (%u/%u pkts/s) " */),cached_rxp_diff,cached_txp_diff);
    RichString_appendnAscii(out,CRT_colors[0xe],buffer,wVar2);
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

