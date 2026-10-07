/* NumberItem_newByRef @ 00123dd0 size 130 */

NumberItem * NumberItem_newByRef(char *text,wchar_t *ref,wchar_t scale,wchar_t min,wchar_t max)

{
  NumberItem *pNVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pNVar1 = malloc(0x30);
  if (pNVar1 != (NumberItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pNVar1->super).super.klass = &NumberItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pNVar1->super).text = pcVar2;
      pNVar1->value = L'\0';
      pNVar1->ref = ref;
      pNVar1->scale = scale;
      pNVar1->min = min;
      pNVar1->max = max;
      return pNVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

