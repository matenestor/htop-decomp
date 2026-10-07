/* RichString_delete @ 0012dc60 size 48 */

/* DWARF original prototype: void RichString_delete(RichString * this) */

void RichString_delete(RichString *this)

{
  if (this->chlen < L'ş') {
    return;
  }
  free(this->chptr);
  this->chptr = this->chstr;
  return;
}

