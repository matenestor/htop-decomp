/* ListItem_init @ 00123310 size 52 */

/* DWARF original prototype: void ListItem_init(ListItem * this, char * value, wchar_t key) */

void ListItem_init(ListItem *this,char *value,wchar_t key)

{
  char *pcVar1;

                    /* Unresolved local var: char * data@[???] */
  pcVar1 = strdup(value);
  if (pcVar1 != (char *)0x0) {
    this->value = pcVar1;
    this->key = key;
    this->moving = false;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

