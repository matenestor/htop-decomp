/* Panel_moveSelectedUp @ 001215d0 size 52 */

/* DWARF original prototype: void Panel_moveSelectedUp(Panel * this) */

void Panel_moveSelectedUp(Panel *this)

{
  Object **ppOVar1;
  wchar_t wVar2;
  Object **ppOVar3;
  Object *pOVar4;

  wVar2 = this->selected;
                    /* Unresolved local var: Object * temp@[???] */
  if (wVar2 != L'\0') {
    ppOVar3 = this->items->array;
                    /* Unresolved local var: Object * temp@[???] */
    ppOVar1 = ppOVar3 + (long)wVar2 + -1;
    pOVar4 = *ppOVar1;
    ppOVar3 = ppOVar3 + (long)wVar2 + -1;
    *ppOVar3 = ppOVar1[1];
    ppOVar3[1] = pOVar4;
    if (L'\0' < wVar2) {
      this->selected = wVar2 + L'\xffffffff';
    }
  }
  return;
}

