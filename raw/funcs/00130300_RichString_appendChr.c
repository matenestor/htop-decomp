/* RichString_appendChr @ 00130300 size 142 */

/* DWARF original prototype: void RichString_appendChr(RichString * this, wchar_t attrs, char c,
   wchar_t count) */

void RichString_appendChr(RichString *this,wchar_t attrs,char c,wchar_t count)

{
  wchar_t wVar1;
  cchar_t *pcVar2;
  cchar_t *pcVar3;
  cchar_t *pcVar4;

  wVar1 = this->chlen;
  RichString_setLen(this,wVar1 + count);
                    /* Unresolved local var: wchar_t i@[???] */
  if (wVar1 < wVar1 + count) {
    pcVar2 = this->chptr;
    pcVar3 = pcVar2 + wVar1;
    do {
      pcVar3->attr = 0;
      pcVar3->chars[0] = L'\0';
      pcVar3->chars[1] = L'\0';
      pcVar3->chars[2] = L'\0';
      pcVar4 = pcVar3 + 1;
      *(undefined1 (*) [16])(pcVar3->chars + 2) = (undefined1  [16])0x0;
      pcVar3->attr = attrs;
      pcVar3->chars[0] = (int)c;
      pcVar3 = pcVar4;
    } while (pcVar4 != pcVar2 + (ulong)(uint)count + (long)wVar1);
  }
  return;
}

