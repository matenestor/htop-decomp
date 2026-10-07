/* ScreenNameListItem_new @ 00132410 size 102 */

ScreenNameListItem * ScreenNameListItem_new(char *value,ScreenSettings_4 *ss)

{
  ScreenNameListItem *pSVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pSVar1 = malloc(0x20);
  if (pSVar1 != (ScreenNameListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pSVar1->super).super.klass = &ScreenNameListItem_class;
    pcVar2 = strdup(value);
    if (pcVar2 != (char *)0x0) {
      (pSVar1->super).value = pcVar2;
      (pSVar1->super).key = L'\0';
      (pSVar1->super).moving = false;
      pSVar1->ss = ss;
      return pSVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

