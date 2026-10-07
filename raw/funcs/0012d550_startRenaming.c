/* startRenaming @ 0012d550 size 171 */

void startRenaming(ScreensPanel_ *super)

{
  char *__dest;
  wchar_t wVar1;
  Vector *pVVar2;
  ListItem *pLVar3;
  char *__src;
  size_t sVar4;

                    /* Unresolved local var: ScreensPanel * this@[DW_OP_reg5(RDI)]
                       Unresolved local var: ListItem * item@[???]
                       Unresolved local var: char * name@[???] */
  pVVar2 = (super->super).items;
  if (L'\0' < pVVar2->items) {
    wVar1 = (super->super).selected;
    pLVar3 = (ListItem *)pVVar2->array[wVar1];
    if (pLVar3 != (ListItem *)0x0) {
      __src = pLVar3->value;
      (super->super).cursorOn = true;
      __dest = super->buffer;
      super->renamingItem = pLVar3;
      super->saved = __src;
      strncpy(__dest,__src,0x14);
      super->buffer[0x14] = '\0';
      sVar4 = strlen(__dest);
      super->cursor = (wchar_t)sVar4;
      pLVar3->value = __dest;
      (super->super).selectionColorId = PANEL_EDIT;
      sVar4 = strlen(__dest);
      (super->super).selectedLen = (wchar_t)sVar4;
      (super->super).cursorY = ((wVar1 + (super->super).y) - (super->super).scrollV) + L'\x01';
      (super->super).cursorX = ((wchar_t)sVar4 + (super->super).x) - (super->super).scrollH;
    }
    return;
  }
  return;
}

