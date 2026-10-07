/* RichString_setAttrn @ 0012db80 size 112 */

/* DWARF original prototype: void RichString_setAttrn(RichString * this, wchar_t attrs, wchar_t
   start, wchar_t charcount) */

void RichString_setAttrn(RichString *this,wchar_t attrs,wchar_t start,wchar_t charcount)

{
  cchar_t *pcVar1;
  wchar_t wVar2;
  cchar_t *pcVar3;
  cchar_t *pcVar4;
  wchar_t wVar5;
  wchar_t wVar6;

  wVar5 = charcount + start;
  wVar2 = L'\0';
  if (L'\xffffffff' < wVar5) {
    wVar2 = wVar5;
  }
  wVar6 = this->chlen;
  if (wVar5 <= this->chlen) {
    wVar6 = wVar2;
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (start < wVar6) {
    pcVar4 = this->chptr + start;
    pcVar1 = this->chptr + (ulong)(uint)(wVar6 - start) + (long)start;
    pcVar3 = pcVar4;
    if (((int)pcVar1 - (int)pcVar4 & 4U) != 0) {
      pcVar4->attr = attrs;
      pcVar3 = pcVar4 + 1;
      if (pcVar4 + 1 == pcVar1) {
        return;
      }
    }
    do {
      pcVar3->attr = attrs;
      pcVar4 = pcVar3 + 2;
      pcVar3[1].attr = attrs;
      pcVar3 = pcVar4;
    } while (pcVar4 != pcVar1);
  }
  return;
}

