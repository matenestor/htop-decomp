/* RichString_rewind @ 00130390 size 15 */

/* DWARF original prototype: void RichString_rewind(RichString * this, wchar_t count) */

void RichString_rewind(RichString *this,wchar_t count)

{
  RichString_setLen(this,this->chlen - count);
  return;
}

