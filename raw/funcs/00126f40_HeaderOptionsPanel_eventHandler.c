/* HeaderOptionsPanel_eventHandler @ 00126f40 size 248 */

HandlerResult HeaderOptionsPanel_eventHandler(HeaderOptionsPanel_ *super,wchar_t ch)

{
  uint64_t *puVar1;
  wchar_t hLayout;
  Object **ppOVar2;
  Object *pOVar3;
  ObjectClass *pOVar4;
  Settings_4 *pSVar5;
  ScreenManager *this;
  Object **ppOVar6;

  if (ch != L'Ĩ') {
    if (ch < L'ĩ') {
      if ((0x16 < (uint)(ch + L'\xfffffff6')) ||
         ((0x100002400U >> ((ulong)(uint)ch & 0x3f) & 1) == 0)) {
        return IGNORED;
      }
    }
    else if ((ch != L'ŗ') && (ch != L'ƙ')) {
      return IGNORED;
    }
  }
                    /* Unresolved local var: HeaderOptionsPanel * this@[???]
                       Unresolved local var: HandlerResult result@[???]
                       Unresolved local var: wchar_t mark@[???]
                       Unresolved local var: wchar_t i@[???] */
  hLayout = (super->super).selected;
  ppOVar2 = ((super->super).items)->array;
  ppOVar6 = ppOVar2;
  do {
    while( true ) {
      pOVar3 = *ppOVar6;
      pOVar4 = pOVar3[2].klass;
      if (pOVar4 != (ObjectClass *)0x0) break;
      ppOVar6 = ppOVar6 + 1;
      *(undefined1 *)&pOVar3[3].klass = 0;
      if (ppOVar6 == ppOVar2 + 0xc) goto LAB_00126fbd;
    }
    ppOVar6 = ppOVar6 + 1;
    *(undefined1 *)&pOVar4->extends = 0;
  } while (ppOVar6 != ppOVar2 + 0xc);
LAB_00126fbd:
  pOVar4 = ppOVar2[hLayout][2].klass;
  if (pOVar4 == (ObjectClass *)0x0) {
    *(undefined1 *)&ppOVar2[hLayout][3].klass = 1;
  }
  else {
    *(undefined1 *)&pOVar4->extends = 1;
  }
  Header_setLayout((Header *)super->scr->header,hLayout);
  pSVar5 = super->settings;
  this = (ScreenManager *)super->scr;
  puVar1 = &pSVar5->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar5->changed = true;
  ScreenManager_resize(this);
  return HANDLED;
}

