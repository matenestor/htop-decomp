/* AvailableColumnsPanel_delete @ 00117560 size 87 */

void AvailableColumnsPanel_delete(AvailableColumnsPanel_ *object)

{
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

