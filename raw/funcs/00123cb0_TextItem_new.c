/* TextItem_new @ 00123cb0 size 72 */

TextItem * TextItem_new(char *text)

{
  TextItem *pTVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pTVar1 = malloc(0x18);
  if (pTVar1 != (TextItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pTVar1->super).super.klass = &TextItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pTVar1->super).text = pcVar2;
      return pTVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

