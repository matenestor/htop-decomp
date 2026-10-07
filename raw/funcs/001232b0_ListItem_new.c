/* ListItem_new @ 001232b0 size 95 */

ListItem * ListItem_new(char *value,wchar_t key)

{
  ListItem *pLVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pLVar1 = malloc(0x18);
  if (pLVar1 != (ListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pLVar1->super).klass = &ListItem_class;
    pcVar2 = strdup(value);
    if (pcVar2 != (char *)0x0) {
      pLVar1->value = pcVar2;
      pLVar1->key = key;
      pLVar1->moving = false;
      return pLVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

