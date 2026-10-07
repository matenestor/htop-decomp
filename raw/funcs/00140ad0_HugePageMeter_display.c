/* HugePageMeter_display @ 00140ad0 size 236 */

void HugePageMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  char *data;
  long lVar2;
  long lVar3;
  long in_FS_OFFSET;
  char buffer [50];

  lVar3 = 0;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0xe],((char *)0x147583 /* ":" */));
  Meter_humanUnit(buffer,cast->total,0x32);
  RichString_appendAscii(out,CRT_colors[0xf],buffer);
  do {
                    /* Unresolved local var: uint i@[???] */
    data = *(char **)((long)HugePageMeter_active_labels + lVar3 * 2);
    if (data == (char *)0x0) break;
    RichString_appendAscii(out,CRT_colors[0xe],data);
    Meter_humanUnit(buffer,*(double *)((long)cast->values + lVar3 * 2),0x32);
    lVar2 = lVar3 + 0xe4;
    lVar3 = lVar3 + 4;
    RichString_appendAscii(out,*(wchar_t *)((long)CRT_colors + lVar2),buffer);
  } while (lVar3 != 0x10);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

