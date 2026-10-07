/* Panel_moveSelectedDown @ 00122170 size 54 */

/* DWARF original prototype: void Panel_moveSelectedDown(Panel * this) */

void Panel_moveSelectedDown(Panel *this)

{
  Object **ppOVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  Object *pOVar4;

  wVar2 = this->selected;
                    /* Unresolved local var: Object * temp@[???] */
  wVar3 = this->items->items;
  if (wVar2 != wVar3 + L'\xffffffff') {
    ppOVar1 = this->items->array + wVar2;
    pOVar4 = *ppOVar1;
    *ppOVar1 = ppOVar1[1];
    ppOVar1[1] = pOVar4;
  }
  if (wVar2 + L'\x01' < wVar3) {
    this->selected = wVar2 + L'\x01';
  }
  return;
}

