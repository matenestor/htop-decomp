/* MetersPanel_setMoving @ 00121570 size 90 */

/* DWARF original prototype: void MetersPanel_setMoving(MetersPanel * this, _Bool moving) */

void MetersPanel_setMoving(MetersPanel *this,_Bool moving)

{
  Vector *pVVar1;
  Object *pOVar2;
  FunctionBar *pFVar3;

  pVVar1 = (this->super).items;
  this->moving = moving;
  if ((L'\0' < pVVar1->items) &&
     (pOVar2 = pVVar1->array[(this->super).selected], pOVar2 != (Object *)0x0)) {
    *(_Bool *)((long)&pOVar2[2].klass + 4) = moving;
  }
  pFVar3 = Meters_movingBar;
  if (!moving) {
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
    (this->super).selectionColorId = PANEL_SELECTION_FOCUS;
    (this->super).currentBar = (this->super).defaultBar;
    return;
  }
  (this->super).selectionColorId = PANEL_SELECTION_FOLLOW;
  (this->super).currentBar = pFVar3;
  return;
}

