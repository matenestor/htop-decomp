/* ScreenListItem_new @ 00132270 size 102 */

ScreenListItem * ScreenListItem_new(char *value,ScreenSettings_4 *ss)

{
  ScreenListItem *pSVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pSVar1 = malloc(0x28);
  if (pSVar1 != (ScreenListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pSVar1->super).super.klass = &ScreenListItem_class;
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

