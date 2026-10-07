/* AvailableMetersPanel_delete @ 00117670 size 88 */

void AvailableMetersPanel_delete(AvailableMetersPanel_ *object)

{
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if (L'Ş' < (object->super).header.chlen) {
    free((object->super).header.chptr);
  }
  free(object->meterPanels);
  free(object);
  return;
}

