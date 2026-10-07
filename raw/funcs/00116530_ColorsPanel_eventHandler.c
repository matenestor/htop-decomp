/* ColorsPanel_eventHandler @ 00116530 size 232 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HandlerResult ColorsPanel_eventHandler(ColorsPanel_ *super,wchar_t ch)

{
  wchar_t colorScheme;
  Object **ppOVar1;
  long lVar2;
  undefined1 *puVar3;
  Object *pOVar4;
  ObjectClass *pOVar5;
  Settings_4 *pSVar6;
  long lVar7;

  if (ch != L'Ĩ') {
    if (ch < L'ĩ') {
      if (0x16 < (uint)(ch + L'\xfffffff6')) {
        return IGNORED;
      }
      if ((0x100002400U >> ((ulong)(uint)ch & 0x3f) & 1) == 0) {
        return IGNORED;
      }
    }
    else if ((ch != L'ŗ') && (ch != L'ƙ')) {
      return IGNORED;
    }
  }
                    /* Unresolved local var: ColorsPanel * this@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: wchar_t mark@[???]
                       Unresolved local var: wchar_t i@[???] */
  colorScheme = (super->super).selected;
  ppOVar1 = ((super->super).items)->array;
  lVar7 = 0;
  do {
    while( true ) {
      lVar2 = *(long *)((long)ppOVar1 + lVar7);
      puVar3 = *(undefined1 **)(lVar2 + 0x10);
      if (puVar3 != (undefined1 *)0x0) break;
      *(undefined1 *)(lVar2 + 0x18) = 0;
      lVar2 = lVar7 + 8;
      lVar7 = lVar7 + 8;
      if (*(long *)((long)ColorSchemeNames + lVar2) == 0) goto LAB_001165b2;
    }
    *puVar3 = 0;
    lVar2 = lVar7 + 8;
    lVar7 = lVar7 + 8;
  } while (*(long *)((long)ColorSchemeNames + lVar2) != 0);
LAB_001165b2:
  pOVar4 = ppOVar1[colorScheme];
  pOVar5 = pOVar4[2].klass;
  if (pOVar5 == (ObjectClass *)0x0) {
    *(undefined1 *)&pOVar4[3].klass = 1;
  }
  else {
    *(undefined1 *)&pOVar5->extends = 1;
  }
  pSVar6 = super->settings;
  pSVar6->lastUpdate = pSVar6->lastUpdate + 1;
  pSVar6->colorScheme = colorScheme;
  pSVar6->changed = true;
  CRT_setColors(colorScheme);
  wclear(_stdscr);
  return REDRAW|HANDLED;
}

