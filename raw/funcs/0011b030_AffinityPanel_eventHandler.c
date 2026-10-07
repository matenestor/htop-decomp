/* AffinityPanel_eventHandler @ 0011b030 size 126 */

HandlerResult AffinityPanel_eventHandler(AffinityPanel_ *super,wchar_t ch)

{
  Vector *pVVar1;
  Object *pOVar2;

  pVVar1 = (super->super).items;
  pOVar2 = (Object *)0x0;
  if (L'\0' < pVVar1->items) {
    pOVar2 = pVVar1->array[(super->super).selected];
  }
  if (ch != L'Ĩ') {
    if (ch < L'ĩ') {
      if (ch == L'\r') {
        return BREAK_LOOP;
      }
      if (ch != L' ') {
        return (ch == L'\n') + 2 + (uint)(ch == L'\n');
      }
    }
    else {
      if (ch == L'ŗ') {
        return BREAK_LOOP;
      }
      if (ch != L'ƙ') {
        return IGNORED;
      }
    }
  }
  *(uint *)&pOVar2[3].klass = (uint)(*(int *)&pOVar2[3].klass == 0) * 2;
  AffinityPanel_update(super,true);
  return HANDLED;
}

