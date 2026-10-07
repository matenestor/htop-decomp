/* MainPanel_delete @ 00126d80 size 171 */

void MainPanel_delete(MainPanel_ *object)

{
  FunctionBar *pFVar1;
  IncSet_2 *pIVar2;
  FunctionBar *this;

  pFVar1 = object->processBar;
  pIVar2 = object->inc;
  (object->super).defaultBar = pFVar1;
  this = object->readonlyBar;
  pIVar2->defaultBar = pFVar1;
  FunctionBar_delete(this);
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if (L'Ş' < (object->super).header.chlen) {
    free((object->super).header.chptr);
    (object->super).header.chptr = (object->super).header.chstr;
  }
  pIVar2 = object->inc;
  FunctionBar_delete(pIVar2->modes[0].bar);
  FunctionBar_delete(pIVar2->modes[1].bar);
  free(pIVar2);
  free(object->keys);
  free(object);
  return;
}

