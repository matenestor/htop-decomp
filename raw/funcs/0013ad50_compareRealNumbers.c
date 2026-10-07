/* compareRealNumbers @ 0013ad50 size 47 */

wchar_t compareRealNumbers(double a,double b)

{
  wchar_t wVar1;

  wVar1 = (uint)(b < a) - (uint)(a < b);
  if (wVar1 == L'\0') {
    wVar1 = (uint)!NAN(a) - (uint)!NAN(b);
  }
  return wVar1;
}

