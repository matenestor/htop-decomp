/* Row_printBytes @ 00130f70 size 54 */

void Row_printBytes(RichString *str,ulonglong number,_Bool coloring)

{
  wchar_t attrs;

  if (number != 0xffffffffffffffff) {
    Row_printKBytes(str,number >> 10,coloring);
    return;
  }
                    /* Unresolved local var: char[16] buffer@[???]
                       Unresolved local var: wchar_t len@[???]
                       Unresolved local var: wchar_t color@[???]
                       Unresolved local var: wchar_t nextUnitColor@[???]
                       Unresolved local var: wchar_t[4] colors@[???]
                       Unresolved local var: size_t maxUnitIndex@[???]
                       Unresolved local var: _Bool canOverflow@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: wchar_t prevUnitColor@[???]
                       Unresolved local var: ulonglong hundredths@[???] */
  attrs = CRT_colors[0x1d];
  if (coloring) {
    attrs = CRT_colors[0x1e];
  }
  RichString_appendAscii(str,attrs,((char *)0x149092 /* "  N/A " */));
  return;
}

