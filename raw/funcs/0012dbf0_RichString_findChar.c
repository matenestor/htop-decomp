/* RichString_findChar @ 0012dbf0 size 91 */

/* DWARF original prototype: wchar_t RichString_findChar(RichString * this, char c, wchar_t start)
    */

wchar_t RichString_findChar(RichString *this,char c,wchar_t start)

{
  wchar_t wVar1;
  cchar_t *pcVar2;

  wVar1 = btowc((int)c);
  pcVar2 = this->chptr + start;
                    /* Unresolved local var: wchar_t i@[???] */
  if (start < this->chlen) {
    do {
      if (pcVar2->chars[0] == wVar1) {
        return start;
      }
      start = start + L'\x01';
      pcVar2 = pcVar2 + 1;
    } while (start != this->chlen);
  }
  return L'\xffffffff';
}

