/* StrBuf_putc_count @ 001388e0 size 15 */

_Bool StrBuf_putc_count(StrBuf_state *p,char c)

{
  p->pos = p->pos + 1;
  return true;
}

