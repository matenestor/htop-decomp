/* Meter_toListItem @ 00128760 size 347 */

/* DWARF original prototype: ListItem * Meter_toListItem(Meter * this, _Bool moving) */

ListItem * Meter_toListItem(Meter *this,_Bool moving)

{
  long lVar1;
  ObjectClass *pOVar2;
  Object_Delete p_Var3;
  ListItem *pLVar4;
  char *pcVar5;
  char *in_RCX;
  long in_R8;
  long in_R9;
  long in_FS_OFFSET;
  char mode [20];
  char name [32];
  char buffer [50];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (this->mode == L'\0') {
    pOVar2 = (this->super).klass;
    mode[0] = '\0';
    p_Var3 = pOVar2[2].delete;
  }
  else {
    in_RCX = Meter_modes[this->mode]->uiName;
    xSnprintf(mode,0x14,((char *)0x149dcb /* " [%s]" */),in_RCX);
    pOVar2 = (this->super).klass;
    p_Var3 = pOVar2[2].delete;
  }
  if (p_Var3 == (Object_Delete)0x0) {
    xSnprintf(name,0x20,((char *)0x147626 /* "%s" */),pOVar2[3].compare);
  }
  else {
    (*p_Var3)(&this->super,(long)name,0x20,(long)in_RCX,in_R8,in_R9);
  }
  xSnprintf(buffer,0x32,((char *)0x147643 /* "%s%s" */),name,mode);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
  pLVar4 = malloc(0x18);
  if (pLVar4 != (ListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pLVar4->super).klass = &ListItem_class;
    pcVar5 = strdup(buffer);
    if (pcVar5 != (char *)0x0) {
      pLVar4->value = pcVar5;
      pLVar4->key = L'\0';
      pLVar4->moving = moving;
      if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return pLVar4;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

