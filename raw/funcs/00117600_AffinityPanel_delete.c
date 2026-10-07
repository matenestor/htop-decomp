/* AffinityPanel_delete @ 00117600 size 96 */

void AffinityPanel_delete(AffinityPanel_ *cast)

{
  free((cast->super).eventHandlerState);
  Vector_delete((cast->super).items);
  FunctionBar_delete((cast->super).defaultBar);
  if (L'Ş' < (cast->super).header.chlen) {
    free((cast->super).header.chptr);
    (cast->super).header.chptr = (cast->super).header.chstr;
  }
  Vector_delete(cast->cpuids);
  free(cast);
  return;
}

