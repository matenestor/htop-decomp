int xSnprintf(char *buf,ulong len,char *fmt,...)

{
  __builtin_va_list ap;
  int n;

  __builtin_va_start(ap,fmt);
  n = vsnprintf(buf,len,fmt,ap);
  __builtin_va_end(ap);
  if ((n < 0) || ((ulong)(long)n >= len)) {
    fail();
  }
  return n;
}
