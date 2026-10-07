/* RichString_setLen @ 00130130 size 442 */

/* DWARF original prototype: void RichString_setLen(RichString * this, wchar_t len) */

void RichString_setLen(RichString *this,wchar_t len)

{
  wchar_t wVar1;
  long lVar2;
  cchar_t *pcVar3;
  cchar_t *pcVar4;
  long lVar5;

  wVar1 = this->chlen;
  if (len < L'Ş') {
    lVar5 = (long)len;
    pcVar3 = this->chptr;
    lVar2 = lVar5 * 0x1c;
    if (wVar1 < L'Ş') {
      pcVar4 = pcVar3 + lVar5;
      pcVar4->attr = 0;
      pcVar4->chars[0] = L'\0';
      pcVar4->chars[1] = L'\0';
      pcVar4->chars[2] = L'\0';
      *(undefined1 (*) [16])(pcVar3[lVar5].chars + 2) = (undefined1  [16])0x0;
      goto LAB_00130187;
    }
    if (wVar1 != L'Ş') goto LAB_00130248;
  }
  else {
    if (L'Ş' < wVar1) {
      pcVar3 = this->chptr;
      if (len != L'Ş') {
                    /* Unresolved local var: void * data@[???] */
        lVar5 = (long)(len + L'\x01');
        pcVar4 = realloc(pcVar3,lVar5 * 0x1c);
        if (pcVar4 == (cchar_t *)0x0) {
          free(pcVar3);
          goto LAB_001302f7;
        }
        this->chptr = pcVar4;
        pcVar3 = pcVar4 + lVar5 + -1;
        pcVar3->attr = 0;
        pcVar3->chars[0] = L'\0';
        pcVar3->chars[1] = L'\0';
        pcVar3->chars[2] = L'\0';
        *(undefined1 (*) [16])(pcVar4[lVar5 + -1].chars + 2) = (undefined1  [16])0x0;
        goto LAB_00130187;
      }
      lVar5 = 0x15e;
LAB_00130248:
      pcVar4 = this->chptr;
      pcVar3 = this->chstr;
      memcpy(pcVar3,pcVar4,lVar5 * 0x1c);
      free(pcVar4);
      this->chptr = pcVar3;
      pcVar3 = pcVar3 + lVar5;
      pcVar3->attr = 0;
      pcVar3->chars[0] = L'\0';
      pcVar3->chars[1] = L'\0';
      pcVar3->chars[2] = L'\0';
      *(undefined1 (*) [16])(this->chstr[lVar5].chars + 2) = (undefined1  [16])0x0;
      goto LAB_00130187;
    }
    if (len != L'Ş') {
      lVar5 = (long)(len + L'\x01');
                    /* Unresolved local var: void * data@[???] */
      pcVar3 = malloc(lVar5 * 0x1c);
      if (pcVar3 == (cchar_t *)0x0) {
LAB_001302f7:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      this->chptr = pcVar3;
      __memcpy_chk(pcVar3,this->chstr,(long)wVar1 * 0x1c,lVar5 * 0x1c);
      pcVar4 = pcVar3 + lVar5 + -1;
      pcVar4->attr = 0;
      pcVar4->chars[0] = L'\0';
      pcVar4->chars[1] = L'\0';
      pcVar4->chars[2] = L'\0';
      *(undefined1 (*) [16])(pcVar3[lVar5 + -1].chars + 2) = (undefined1  [16])0x0;
      goto LAB_00130187;
    }
    pcVar3 = this->chptr;
    lVar2 = 0x2648;
  }
  *(undefined1 (*) [16])((long)pcVar3->chars + lVar2 + -4) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])((long)pcVar3->chars + lVar2 + 8) = (undefined1  [16])0x0;
LAB_00130187:
  this->chlen = len;
  return;
}

