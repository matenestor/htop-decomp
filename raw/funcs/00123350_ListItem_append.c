/* ListItem_append @ 00123350 size 154 */

/* DWARF original prototype: void ListItem_append(ListItem * this, char * text) */

void ListItem_append(ListItem *this,char *text)

{
  char *__s;
  size_t sVar1;
  size_t p2;
  char *pcVar2;
  ulong __size;

  __s = this->value;
  sVar1 = strlen(__s);
  p2 = strlen(text);
                    /* Unresolved local var: void * data@[???] */
  __size = sVar1 + p2 + 1;
  pcVar2 = realloc(__s,__size);
  if (pcVar2 != (char *)0x0) {
    this->value = pcVar2;
    if (__size < sVar1) {
      __size = sVar1;
    }
    __memcpy_chk(pcVar2 + sVar1,text,p2,__size - sVar1);
    this->value[sVar1 + p2] = '\0';
    return;
  }
  free(__s);
                    /* WARNING: Subroutine does not return */
  fail();
}

