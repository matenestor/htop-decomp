/* MaskItem_display @ 0011adf0 size 343 */

void MaskItem_display(MaskItem_ *cast,RichString *out)

{
  char *data;

  RichString_appendAscii(out,CRT_colors[0x41],((char *)0x14703c /* "[" */));
  if (cast->value == L'\x02') {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)0x149f75 /* "x" */));
  }
  else if (cast->value == L'\x01') {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)0x1488f9 /* "o" */));
  }
  else {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)0x1470dd /* " " */));
  }
  RichString_appendAscii(out,CRT_colors[0x41],((char *)0x149a61 /* "]" */));
  RichString_appendAscii(out,CRT_colors[0x43],((char *)0x1470dd /* " " */));
  if (cast->indent != (char *)0x0) {
    RichString_appendWide(out,CRT_colors[0x22],cast->indent);
    if (cast->sub_tree == L'\x02') {
      data = CRT_treeStr[4];
    }
    else {
      data = CRT_treeStr[5];
    }
    RichString_appendWide(out,CRT_colors[0x22],data);
    RichString_appendAscii(out,CRT_colors[0x43],((char *)0x1470dd /* " " */));
  }
  RichString_appendWide(out,CRT_colors[0x43],cast->text);
  return;
}

