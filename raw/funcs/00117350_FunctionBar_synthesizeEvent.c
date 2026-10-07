/* FunctionBar_synthesizeEvent @ 00117350 size 151 */

/* DWARF original prototype: wchar_t FunctionBar_synthesizeEvent(FunctionBar * this, wchar_t pos) */

wchar_t FunctionBar_synthesizeEvent(FunctionBar *this,wchar_t pos)

{
  wchar_t wVar1;
  char **ppcVar2;
  char **ppcVar3;
  size_t sVar4;
  size_t sVar5;
  wchar_t wVar6;
  long lVar7;

                    /* Unresolved local var: wchar_t i@[???] */
  wVar1 = this->size;
  if (L'\0' < wVar1) {
    ppcVar2 = (this->keys).keys;
    ppcVar3 = this->functions;
    lVar7 = 0;
    wVar6 = L'\0';
    do {
      sVar4 = strlen(ppcVar2[lVar7]);
      sVar5 = strlen(ppcVar3[lVar7]);
      wVar6 = wVar6 + (int)sVar4 + (int)sVar5;
      if (pos < wVar6) {
        return this->events[lVar7];
      }
      lVar7 = lVar7 + 1;
    } while (wVar1 != lVar7);
  }
  return L'\xffffffff';
}

