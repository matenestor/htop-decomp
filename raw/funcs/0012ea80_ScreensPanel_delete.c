/* ScreensPanel_delete @ 0012ea80 size 131 */

void ScreensPanel_delete(Panel_ *object)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Object *pOVar3;
  Object **ppOVar4;

  wVar2 = object->items->items;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < wVar2) {
    ppOVar4 = object->items->array;
    ppOVar1 = ppOVar4 + wVar2;
    do {
                    /* Unresolved local var: ScreenListItem * item@[???] */
      pOVar3 = *ppOVar4;
      ppOVar4 = ppOVar4 + 1;
      pOVar3[4].klass = (ObjectClass *)0x0;
    } while (ppOVar4 != ppOVar1);
  }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(object->eventHandlerState);
  Vector_delete(object->items);
  FunctionBar_delete(object->defaultBar);
  if ((object->header).chlen < L'ş') {
    free(object);
    return;
  }
  free((object->header).chptr);
  free(object);
  return;
}

