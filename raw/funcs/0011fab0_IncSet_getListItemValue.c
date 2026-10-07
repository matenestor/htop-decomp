/* IncSet_getListItemValue @ 0011fab0 size 35 */

char * IncSet_getListItemValue(Panel *panel,wchar_t i)

{
  Object *pOVar1;
  ObjectClass *pOVar2;

  pOVar1 = panel->items->array[i];
  pOVar2 = (ObjectClass *)&DAT_00149c0c;
  if (pOVar1 != (Object *)0x0) {
    pOVar2 = pOVar1[1].klass;
  }
  return (char *)pOVar2;
}

