/* FunctionBar_setLabel @ 00118020 size 111 */

/* DWARF original prototype: void FunctionBar_setLabel(FunctionBar * this, wchar_t event, char *
   text) */

void FunctionBar_setLabel(FunctionBar *this,wchar_t event,char *text)

{
  char **ppcVar1;
  long lVar2;
  char *pcVar3;

                    /* Unresolved local var: wchar_t i@[???] */
  if (this->size < L'\x01') {
    return;
  }
  lVar2 = 0;
  do {
    if (this->events[lVar2] == event) {
      free(this->functions[lVar2]);
                    /* Unresolved local var: char * data@[???] */
      ppcVar1 = this->functions;
      pcVar3 = strdup(text);
      if (pcVar3 != (char *)0x0) {
        ppcVar1[lVar2] = pcVar3;
        return;
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
    lVar2 = lVar2 + 1;
  } while (this->size != lVar2);
  return;
}

