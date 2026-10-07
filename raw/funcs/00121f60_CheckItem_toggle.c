/* CheckItem_toggle @ 00121f60 size 22 */

/* DWARF original prototype: void CheckItem_toggle(CheckItem * this) */

void CheckItem_toggle(CheckItem *this)

{
  _Bool *p_Var1;

  p_Var1 = this->ref;
  if (p_Var1 != (_Bool *)0x0) {
    *p_Var1 = (_Bool)(*p_Var1 ^ 1);
    return;
  }
  this->value = (_Bool)(this->value ^ 1);
  return;
}

