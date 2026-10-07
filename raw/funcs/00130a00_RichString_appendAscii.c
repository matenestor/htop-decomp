/* RichString_appendAscii @ 00130a00 size 187 */

/* DWARF original prototype: wchar_t RichString_appendAscii(RichString * this, wchar_t attrs, char *
   data) */

wchar_t RichString_appendAscii(RichString *this,wchar_t attrs,char *data)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  wchar_t len;
  wchar_t wVar4;
  size_t sVar5;
  ushort **ppuVar6;
  cchar_t *pcVar7;
  char *pcVar8;

  sVar5 = strlen(data);
  wVar4 = this->chlen;
                    /* Unresolved local var: wchar_t newLen@[???] */
  len = (wchar_t)sVar5 + wVar4;
  RichString_setLen(this,len);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
  if (wVar4 < len) {
    ppuVar6 = __ctype_b_loc();
    puVar3 = *ppuVar6;
    pcVar8 = data + (sVar5 & 0xffffffff);
    pcVar7 = this->chptr + wVar4;
    do {
      cVar1 = *data;
      bVar2 = *(byte *)((long)puVar3 + (long)cVar1 * 2 + 1);
      pcVar7->attr = 0;
      pcVar7->chars[0] = L'\0';
      pcVar7->chars[1] = L'\0';
      pcVar7->chars[2] = L'\0';
      wVar4 = (wchar_t)cVar1;
      if ((bVar2 & 0x40) == 0) {
        wVar4 = L'�';
      }
      data = data + 1;
      pcVar7->attr = attrs & 0xffffff;
      *(undefined1 (*) [16])(pcVar7->chars + 2) = (undefined1  [16])0x0;
      pcVar7->chars[0] = wVar4;
      pcVar7 = pcVar7 + 1;
    } while (data != pcVar8);
  }
  return (wchar_t)sVar5;
}

