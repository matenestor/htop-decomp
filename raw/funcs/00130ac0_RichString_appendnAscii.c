/* RichString_appendnAscii @ 00130ac0 size 171 */

/* DWARF original prototype: wchar_t RichString_appendnAscii(RichString * this, wchar_t attrs, char
   * data, wchar_t len) */

wchar_t RichString_appendnAscii(RichString *this,wchar_t attrs,char *data,wchar_t len)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  wchar_t wVar4;
  ushort **ppuVar5;
  cchar_t *pcVar6;
  char *pcVar7;

  wVar4 = this->chlen;
                    /* Unresolved local var: wchar_t newLen@[???] */
  RichString_setLen(this,wVar4 + len);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
  if (wVar4 < wVar4 + len) {
    ppuVar5 = __ctype_b_loc();
    puVar3 = *ppuVar5;
    pcVar7 = data + (uint)len;
    pcVar6 = this->chptr + wVar4;
    do {
      cVar1 = *data;
      bVar2 = *(byte *)((long)puVar3 + (long)cVar1 * 2 + 1);
      pcVar6->attr = 0;
      pcVar6->chars[0] = L'\0';
      pcVar6->chars[1] = L'\0';
      pcVar6->chars[2] = L'\0';
      wVar4 = (wchar_t)cVar1;
      if ((bVar2 & 0x40) == 0) {
        wVar4 = L'�';
      }
      data = data + 1;
      pcVar6->attr = attrs & 0xffffff;
      *(undefined1 (*) [16])(pcVar6->chars + 2) = (undefined1  [16])0x0;
      pcVar6->chars[0] = wVar4;
      pcVar6 = pcVar6 + 1;
    } while (data != pcVar7);
  }
  return len;
}

