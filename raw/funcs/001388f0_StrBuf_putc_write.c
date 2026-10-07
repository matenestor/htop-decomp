/* StrBuf_putc_write @ 001388f0 size 34 */

_Bool StrBuf_putc_write(StrBuf_state *p,char c)

{
  ulong uVar1;
  bool bVar2;

  uVar1 = p->pos;
  bVar2 = uVar1 < p->size;
  if (bVar2) {
    p->buf[uVar1] = c;
    p->pos = p->pos + 1;
  }
  return bVar2;
}

