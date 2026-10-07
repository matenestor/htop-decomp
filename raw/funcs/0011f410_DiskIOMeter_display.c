/* DiskIOMeter_display @ 0011f410 size 453 */

void DiskIOMeter_display(Object *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  char *data;
  long lVar3;
  long in_FS_OFFSET;
  char buffer [16];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (status == RATESTATUS_NODATA) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      data = ((char *)0x1476cb /* "no data" */);
      wVar2 = CRT_colors[0x10];
LAB_0011f573:
      RichString_writeAscii(out,wVar2,data);
      return;
    }
  }
  else if (status == RATESTATUS_STALE) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      data = ((char *)0x147702 /* "stale data" */);
      wVar2 = CRT_colors[0x15];
      goto LAB_0011f573;
    }
  }
  else if (status == RATESTATUS_INIT) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      data = ((char *)0x1476f2 /* "initializing..." */);
      wVar2 = CRT_colors[0xf];
      goto LAB_0011f573;
    }
  }
  else {
    lVar3 = 0x4c;
    if (cached_utilisation_diff <= 40.0) {
      lVar3 = 0x3c;
    }
    wVar2 = xSnprintf(buffer,0x10,((char *)0x1476eb /* "%.1f%%" */),cached_utilisation_diff);
    RichString_appendnAscii(out,*(wchar_t *)((long)CRT_colors + lVar3),buffer,wVar2);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14770d /* " read: " */));
    RichString_appendAscii(out,CRT_colors[0x11],cached_read_diff_str);
    RichString_appendAscii(out,CRT_colors[0x11],((char *)0x147715 /* "iB/s" */));
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14771a /* " write: " */));
    RichString_appendAscii(out,CRT_colors[0x12],cached_write_diff_str);
    RichString_appendAscii(out,CRT_colors[0x12],((char *)0x147715 /* "iB/s" */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

