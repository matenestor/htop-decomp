/* CheckItem_newByRef @ 00123d00 size 95 */

CheckItem * CheckItem_newByRef(char *text,_Bool *ref)

{
  CheckItem *pCVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pCVar1 = malloc(0x20);
  if (pCVar1 != (CheckItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pCVar1->super).super.klass = &CheckItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pCVar1->super).text = pcVar2;
      pCVar1->value = false;
      pCVar1->ref = ref;
      return pCVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

