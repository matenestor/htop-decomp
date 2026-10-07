/* ScreenTabsPanel_eventHandler @ 00136d60 size 545 */

HandlerResult ScreenTabsPanel_eventHandler(ScreenTabsPanel_ *super,wchar_t ch)

{
  wchar_t wVar1;
  uint uVar2;
  Vector *pVVar3;
  ScreenNamesPanel *this;
  DynamicScreen *__s1;
  Settings_3 *pSVar4;
  ScreenSettings_4 *pSVar5;
  char *pcVar6;
  int iVar7;
  HandlerResult HVar8;
  ushort **ppuVar9;
  Object *pOVar10;
  ObjectClass *pOVar11;
  long lVar12;

  wVar1 = (super->super).selected;
  if (ch < L'Ą') {
    if (ch < L'Ă') {
      if (ch != L'\xffffffff') {
        if (ch == L'\x0e') goto LAB_00136de0;
        if (L'þ' < ch) {
          return IGNORED;
        }
        ppuVar9 = __ctype_b_loc();
        if ((*(byte *)((long)*ppuVar9 + (long)ch * 2 + 1) & 4) == 0) {
          return IGNORED;
        }
        HVar8 = Panel_selectByTyping(&super->super,ch);
        if (HVar8 == BREAK_LOOP) {
          return IGNORED;
        }
        if (HVar8 != HANDLED) {
          return HVar8;
        }
      }
      goto LAB_00136e30;
    }
  }
  else {
    if (ch == L'č') {
LAB_00136de0:
      HVar8 = ScreenNamesPanel_eventHandlerNormal(super->names,ch);
      return HVar8;
    }
    if (ch < L'Ď') {
      if (ch != L'Ć') {
        return IGNORED;
      }
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
                    /* Unresolved local var: wchar_t previous@[???] */
  Panel_onKey(&super->super,ch);
  if (wVar1 == (super->super).selected) {
    return IGNORED;
  }
LAB_00136e30:
                    /* Unresolved local var: ScreenTabListItem * focus@[???] */
  pVVar3 = (super->super).items;
  if ((L'\0' < pVVar3->items) &&
     (pOVar10 = pVVar3->array[(super->super).selected], pOVar10 != (Object *)0x0)) {
    this = super->names;
    __s1 = (DynamicScreen *)pOVar10[3].klass;
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: uint i@[???] */
    lVar12 = 0;
    pSVar4 = this->settings;
    Vector_prune((this->super).items);
    (this->super).selected = L'\0';
    (this->super).oldSelected = L'\0';
    uVar2 = pSVar4->nScreens;
    (this->super).scrollV = L'\0';
    (this->super).needsRedraw = true;
    if (uVar2 != 0) {
      do {
        while( true ) {
          pSVar5 = pSVar4->screens[lVar12];
          pcVar6 = pSVar5->dynamic;
          if (__s1 == (DynamicScreen *)0x0) break;
                    /* Unresolved local var: ScreenSettings * ss@[???] */
          if ((pcVar6 != (char *)0x0) && (iVar7 = strcmp((char *)__s1,pcVar6), iVar7 == 0)) {
LAB_00136ea9:
            pcVar6 = pSVar5->heading;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
            pOVar10 = malloc(0x18);
            if (pOVar10 == (Object *)0x0) {
LAB_00136f9f:
                    /* WARNING: Subroutine does not return */
              fail();
            }
                    /* Unresolved local var: char * data@[???] */
            pOVar10->klass = &ListItem_class;
            pOVar11 = (ObjectClass *)strdup(pcVar6);
            if (pOVar11 == (ObjectClass *)0x0) goto LAB_00136f9f;
            pOVar10[1].klass = pOVar11;
            *(int *)&pOVar10[2].klass = (int)lVar12;
            *(undefined1 *)((long)&pOVar10[2].klass + 4) = 0;
            Panel_add(&this->super,pOVar10);
          }
          lVar12 = lVar12 + 1;
          if (pSVar4->nScreens <= (uint)lVar12) goto LAB_00136f30;
        }
        if (pcVar6 == (char *)0x0) goto LAB_00136ea9;
        lVar12 = lVar12 + 1;
      } while ((uint)lVar12 < pSVar4->nScreens);
    }
LAB_00136f30:
    this->ds = __s1;
  }
  return HANDLED;
}

