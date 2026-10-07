/* CheckItem_newByVal @ 00123d60 size 99 */

CheckItem * CheckItem_newByVal(char *text,_Bool value)

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
      pCVar1->value = value;
      pCVar1->ref = (_Bool *)0x0;
      return pCVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

