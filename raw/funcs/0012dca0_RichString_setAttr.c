/* RichString_setAttr @ 0012dca0 size 38 */

/* DWARF original prototype: void RichString_setAttr(RichString * this, wchar_t attrs) */

void RichString_setAttr(RichString *this,wchar_t attrs)

{
  wchar_t wVar1;
  wchar_t wVar2;
  cchar_t *pcVar3;

  wVar1 = this->chlen;
                    /* Unresolved local var: wchar_t end@[???] */
  wVar2 = L'\0';
  if (L'\xffffffff' < wVar1) {
    wVar2 = wVar1;
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < wVar1) {
    pcVar3 = this->chptr;
    wVar1 = L'\0';
    do {
      wVar1 = wVar1 + L'\x01';
      pcVar3->attr = attrs;
      pcVar3 = pcVar3 + 1;
    } while (wVar1 < wVar2);
  }
  return;
}

