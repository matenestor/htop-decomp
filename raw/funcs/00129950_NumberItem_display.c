/* NumberItem_display @ 00129950 size 452 */

void NumberItem_display(NumberItem_ *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  long in_FS_OFFSET;
  double dVar4;
  char buffer [12];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0x41],((char *)0x14703c /* "[" */));
  wVar2 = cast->scale;
  if (wVar2 < L'\0') {
    dVar4 = pow(10.0,(double)wVar2);
    if (cast->ref == (wchar_t *)0x0) {
      wVar3 = cast->value;
    }
    else {
      wVar3 = *cast->ref;
    }
    wVar2 = xSnprintf(buffer,0xc,((char *)0x1488e6 /* "%.*f" */),-wVar2,(double)wVar3 * dVar4);
  }
  else {
    if (wVar2 == L'\0') {
      if (cast->ref == (wchar_t *)0x0) {
        wVar2 = cast->value;
      }
      else {
        wVar2 = *cast->ref;
      }
    }
    else {
      dVar4 = pow(10.0,(double)wVar2);
      if (cast->ref == (wchar_t *)0x0) {
        wVar2 = cast->value;
      }
      else {
        wVar2 = *cast->ref;
      }
      wVar2 = (wchar_t)((double)wVar2 * dVar4);
    }
    wVar2 = xSnprintf(buffer,0xc,((char *)0x149710 /* "%d" */),wVar2);
  }
  RichString_appendnAscii(out,CRT_colors[0x42],buffer,wVar2);
  RichString_appendAscii(out,CRT_colors[0x41],((char *)0x149a61 /* "]" */));
                    /* Unresolved local var: wchar_t i@[???] */
  if (wVar2 < L'\x05') {
    do {
      wVar2 = wVar2 + L'\x01';
      RichString_appendAscii(out,CRT_colors[0x41],((char *)0x1470dd /* " " */));
    } while (wVar2 != L'\x05');
  }
  RichString_appendWide(out,CRT_colors[0x43],(cast->super).text);
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

