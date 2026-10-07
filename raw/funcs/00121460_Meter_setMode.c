/* Meter_setMode @ 00121460 size 143 */

/* DWARF original prototype: void Meter_setMode(Meter * this, wchar_t modeIndex) */

void Meter_setMode(Meter *this,wchar_t modeIndex)

{
  int iVar1;
  wchar_t wVar2;
  ObjectClass *pOVar3;
  Meter_Draw a2;
  Object_Delete p_Var4;
  long in_RCX;
  long in_R8;
  long in_R9;

  if (modeIndex < L'\x01') {
    if (modeIndex == L'\0') {
      modeIndex = L'\x01';
    }
    pOVar3 = (this->super).klass;
    iVar1 = *(int *)&pOVar3[2].compare;
  }
  else {
    if (this->mode == modeIndex) {
      return;
    }
    pOVar3 = (this->super).klass;
    iVar1 = *(int *)&pOVar3[2].compare;
  }
  if (iVar1 == 0) {
    a2 = pOVar3[2].extends;
    p_Var4 = pOVar3[1].delete;
    this->draw = a2;
    if (p_Var4 != (Object_Delete)0x0) {
      (*p_Var4)(&this->super,(ulong)(uint)modeIndex,(long)a2,in_RCX,in_R8,in_R9);
    }
  }
  else {
                    /* Unresolved local var: MeterMode * mode@[???] */
    free((this->drawData).values);
    (this->drawData).values = (double *)0x0;
    (this->drawData).nValues = 0;
    wVar2 = Meter_modes[modeIndex]->h;
    this->draw = Meter_modes[modeIndex]->draw;
    this->h = wVar2;
  }
  this->mode = modeIndex;
  return;
}

