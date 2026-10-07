int xAsprintf(char **strp,char *fmt,...)

{
  __builtin_va_list ap;
  int n;

  __builtin_va_start(ap,fmt);
  n = vasprintf(strp,fmt,ap);
  __builtin_va_end(ap);
  if ((n < 0) || (*strp == (char *)0x0)) {
    fail();
  }
  return n;
}
