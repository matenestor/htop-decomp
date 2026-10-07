/* CategoriesPanel_eventHandler @ 0011cde0 size 324 */

HandlerResult CategoriesPanel_eventHandler(CategoriesPanel_ *super,wchar_t ch)

{
  wchar_t wVar1;
  wchar_t wVar2;
  HandlerResult HVar3;
  ushort **ppuVar4;
  long in_RCX;
  long in_RDX;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  wchar_t wVar5;
  undefined4 in_register_00000034;
  long a1;
  ScreenManager *this;
  long in_R8;
  long in_R9;
  bool bVar6;

                    /* Unresolved local var: CategoriesPanel * this@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: wchar_t selected@[???] */
  a1 = CONCAT44(in_register_00000034,ch);
  wVar1 = (super->super).selected;
  if (ch != L'\x0e') {
    if (ch < L'\x0f') {
      if (ch == L'\xffffffff') goto LAB_0011ce18;
LAB_0011ced0:
      if (0xfd < (uint)(ch + L'\xffffffff')) {
        return IGNORED;
      }
      ppuVar4 = __ctype_b_loc();
      a1 = (long)ch;
      if (-1 < (short)(*ppuVar4)[a1]) {
        return IGNORED;
      }
      HVar3 = Panel_selectByTyping(&super->super,ch);
      if (HVar3 == BREAK_LOOP) {
        return IGNORED;
      }
      in_RDX = extraout_RDX_01;
      if (HVar3 != HANDLED) {
        return HVar3;
      }
      goto LAB_0011ce18;
    }
    if (ch != L'Ć') {
      if (ch < L'ć') {
        if ((ch != L'\x10') && (1 < (uint)(ch + L'\xfffffefe'))) goto LAB_0011ced0;
      }
      else if (ch < L'Ŕ') {
        if (ch < L'Œ') {
          return IGNORED;
        }
      }
      else if (ch != L'Ũ') {
        return IGNORED;
      }
    }
  }
                    /* Unresolved local var: wchar_t previous@[???] */
  Panel_onKey(&super->super,ch);
  wVar2 = (super->super).selected;
  bVar6 = wVar1 == wVar2;
  in_RDX = extraout_RDX_00;
  wVar1 = wVar2;
  if (bVar6) {
    return IGNORED;
  }
LAB_0011ce18:
                    /* Unresolved local var: wchar_t size@[???] */
  this = super->scr;
  wVar2 = this->panelCount;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\x01' < wVar2) {
    wVar5 = L'\x01';
    while( true ) {
      a1 = 1;
      wVar5 = wVar5 + L'\x01';
      ScreenManager_remove(this,L'\x01');
      in_RDX = extraout_RDX;
      if (wVar5 == wVar2) break;
      this = super->scr;
    }
  }
  if ((uint)wVar1 < 5) {
    (*categoriesPanelPages[wVar1].ctor)(super,a1,in_RDX,in_RCX,in_R8,in_R9);
  }
  return HANDLED;
}

