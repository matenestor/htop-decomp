/* ScreenNamesPanel_delete @ 0012eb70 size 154 */

void ScreenNamesPanel_delete(ScreenNamesPanel_ *object)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Vector *pVVar3;
  Object *pOVar4;
  Object **ppOVar5;

  pVVar3 = (object->super).items;
  wVar2 = pVVar3->items;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < wVar2) {
    ppOVar5 = pVVar3->array;
    ppOVar1 = ppOVar5 + wVar2;
    do {
                    /* Unresolved local var: ScreenNameListItem * item@[???] */
      pOVar4 = *ppOVar5;
      ppOVar5 = ppOVar5 + 1;
      pOVar4[3].klass = (ObjectClass *)0x0;
    } while (ppOVar5 != ppOVar1);
  }
  if (object->renamingItem != (ListItem *)0x0) {
    object->renamingItem->value = object->saved;
  }
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if ((object->super).header.chlen < L'ş') {
    free(object);
    return;
  }
  free((object->super).header.chptr);
  free(object);
  return;
}

