/* Row_printPercentage @ 0012e760 size 202 */

wchar_t Row_printPercentage(float val,char *buffer,size_t n,uint8_t width,wchar_t *attr)

{
  uint va0;
  wchar_t wVar1;
  int va1;
  double va2;

  va0 = (uint)width;
                    /* Unresolved local var: wchar_t precision@[???] */
  if (val < 0.0) {
    *attr = CRT_colors[0x1e];
    wVar1 = xSnprintf(buffer,n,((char *)0x148c24 /* "%*.*s " */),va0,va0,&DAT_001474de);
    return wVar1;
  }
  if (0.05 <= val) {
    if ((99.9 <= val) && (*attr = CRT_colors[0x20], width == '\x04')) {
      va1 = 0;
      va2 = 100.0;
      if (99.9 < val) goto LAB_0012e79e;
    }
    va1 = 1;
    va2 = (double)val;
  }
  else {
    va1 = 1;
    va2 = (double)val;
    *attr = CRT_colors[0x1e];
  }
LAB_0012e79e:
  wVar1 = xSnprintf(buffer,n,((char *)0x148c1d /* "%*.*f " */),va0,va1,va2);
  return wVar1;
}

