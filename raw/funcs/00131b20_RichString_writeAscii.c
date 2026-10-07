/* RichString_writeAscii @ 00131b20 size 171 */

/* DWARF original prototype: wchar_t RichString_writeAscii(RichString * this, wchar_t attrs, char *
   data) */

wchar_t RichString_writeAscii(RichString *this,wchar_t attrs,char *data)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  ushort *puVar4;
  wchar_t len;
  wchar_t wVar5;
  size_t sVar6;
  ushort **ppuVar7;
  cchar_t *pcVar8;

  sVar6 = strlen(data);
                    /* Unresolved local var: wchar_t newLen@[???] */
  len = (wchar_t)sVar6;
  RichString_setLen(this,len);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
  if (L'\0' < len) {
    ppuVar7 = __ctype_b_loc();
    puVar4 = *ppuVar7;
    pcVar1 = data + (ulong)(uint)(len + L'\xffffffff') + 1;
    pcVar8 = this->chptr;
    do {
      cVar2 = *data;
      bVar3 = *(byte *)((long)puVar4 + (long)cVar2 * 2 + 1);
      pcVar8->attr = 0;
      pcVar8->chars[0] = L'\0';
      pcVar8->chars[1] = L'\0';
      pcVar8->chars[2] = L'\0';
      wVar5 = (wchar_t)cVar2;
      if ((bVar3 & 0x40) == 0) {
        wVar5 = L'�';
      }
      data = data + 1;
      pcVar8->attr = attrs & 0xffffff;
      *(undefined1 (*) [16])(pcVar8->chars + 2) = (undefined1  [16])0x0;
      pcVar8->chars[0] = wVar5;
      pcVar8 = pcVar8 + 1;
    } while (data != pcVar1);
  }
  return len;
}

