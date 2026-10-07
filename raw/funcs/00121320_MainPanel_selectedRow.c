/* MainPanel_selectedRow @ 00121320 size 40 */

/* DWARF original prototype: wchar_t MainPanel_selectedRow(MainPanel * this) */

wchar_t MainPanel_selectedRow(MainPanel *this)

{
  Vector *pVVar1;
  Object *pOVar2;
  wchar_t wVar3;

  pVVar1 = (this->super).items;
  wVar3 = L'\xffffffff';
  if ((L'\0' < pVVar1->items) &&
     (pOVar2 = pVVar1->array[(this->super).selected], pOVar2 != (Object *)0x0)) {
    wVar3 = *(wchar_t *)&pOVar2[2].klass;
  }
  return wVar3;
}

