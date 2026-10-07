/* NumberItem_newByVal @ 00123e60 size 162 */

NumberItem * NumberItem_newByVal(char *text,wchar_t value,wchar_t scale,wchar_t min,wchar_t max)

{
  wchar_t wVar1;
  NumberItem *pNVar2;
  char *pcVar3;

                    /* Unresolved local var: void * data@[???] */
  pNVar2 = malloc(0x30);
  if (pNVar2 != (NumberItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pNVar2->super).super.klass = &NumberItem_class.super;
    pcVar3 = strdup(text);
    if (pcVar3 != (char *)0x0) {
      (pNVar2->super).text = pcVar3;
      wVar1 = min;
      if (min <= value) {
        wVar1 = value;
      }
      pNVar2->ref = (wchar_t *)0x0;
      if (max < value) {
        wVar1 = max;
      }
      pNVar2->value = wVar1;
      pNVar2->scale = scale;
      pNVar2->min = min;
      pNVar2->max = max;
      return pNVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

