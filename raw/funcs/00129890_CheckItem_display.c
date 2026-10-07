/* CheckItem_display @ 00129890 size 180 */

void CheckItem_display(CheckItem_ *cast,RichString *out)

{
  char cVar1;

  RichString_writeAscii(out,CRT_colors[0x41],((char *)0x14703c /* "[" */));
  if (cast->ref == (_Bool *)0x0) {
    cVar1 = cast->value;
  }
  else {
    cVar1 = *cast->ref;
  }
  if (cVar1 == '\0') {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)0x1470dd /* " " */));
  }
  else {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)0x149f75 /* "x" */));
  }
  RichString_appendAscii(out,CRT_colors[0x41],((char *)0x1488e0 /* "]    " */));
  RichString_appendWide(out,CRT_colors[0x43],(cast->super).text);
  return;
}

