/* ScreenNamesPanel_eventHandler @ 00136fb0 size 495 */

HandlerResult ScreenNamesPanel_eventHandler(ScreenNamesPanel_ *super,wchar_t ch)

{
  uint64_t *puVar1;
  Vector *pVVar2;
  Object *pOVar3;
  ObjectClass *pOVar4;
  Settings_3 *pSVar5;
  wchar_t wVar6;
  HandlerResult HVar7;
  int iVar8;
  size_t sVar9;
  ObjectClass *__s2;
  char *pcVar10;

  if (super->renamingItem == (ListItem *)0x0) {
    HVar7 = ScreenNamesPanel_eventHandlerNormal(super,ch);
    return HVar7;
  }
                    /* Unresolved local var: ScreenNamesPanel * this@[???] */
  if (((uint)(ch + L'\xffffffe0') < 0x5f) && (ch != L'=')) {
    wVar6 = super->cursor;
    if (L'\x12' < wVar6) {
      return HANDLED;
    }
    super->buffer[wVar6] = (char)ch;
    super->cursor = wVar6 + L'\x01';
    goto LAB_00137041;
  }
  if (ch == L'\x1b') {
                    /* Unresolved local var: ListItem * item@[???] */
    pVVar2 = (super->super).items;
    if (pVVar2->items < L'\x01') {
      return HANDLED;
    }
    pOVar3 = pVVar2->array[(super->super).selected];
    if (pOVar3 == (Object *)0x0) {
      return HANDLED;
    }
    pOVar3[1].klass = (ObjectClass *)super->saved;
    super->renamingItem = (ListItem *)0x0;
    (super->super).cursorOn = false;
    (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
    return HANDLED;
  }
  if (L'\x1b' < ch) {
    if (ch != L'ć') {
      if (ch == L'ŗ') goto LAB_0013710e;
      if (ch != L'\x7f') {
        return HANDLED;
      }
    }
    if (super->cursor < L'\x01') {
      return HANDLED;
    }
    wVar6 = super->cursor + L'\xffffffff';
    super->cursor = wVar6;
    super->buffer[wVar6] = '\0';
LAB_00137041:
    sVar9 = strlen(super->buffer);
    (super->super).selectedLen = (wchar_t)sVar9;
    (super->super).cursorX = ((wchar_t)sVar9 + (super->super).x) - (super->super).scrollH;
    (super->super).cursorY =
         (((super->super).selected + (super->super).y) - (super->super).scrollV) + L'\x01';
    return HANDLED;
  }
  if ((ch != L'\n') && (ch != L'\r')) {
    return HANDLED;
  }
LAB_0013710e:
                    /* Unresolved local var: ListItem * item@[???] */
  pVVar2 = (super->super).items;
  if (pVVar2->items < L'\x01') {
    return HANDLED;
  }
  pOVar3 = pVVar2->array[(super->super).selected];
  if (pOVar3 == (Object *)0x0) {
    return HANDLED;
  }
  free(super->saved);
                    /* Unresolved local var: char * data@[???] */
  __s2 = (ObjectClass *)strdup(super->buffer);
  if (__s2 != (ObjectClass *)0x0) {
    pOVar3[1].klass = __s2;
                    /* Unresolved local var: ScreenNameListItem * nameItem@[???]
                       Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: Settings * settings@[???] */
    pOVar4 = pOVar3[3].klass;
    super->renamingItem = (ListItem *)0x0;
    pcVar10 = pOVar4->extends;
    (super->super).cursorOn = false;
    (super->super).selectionColorId = PANEL_SELECTION_FOCUS;
    if ((pcVar10 == (char *)0x0) || (iVar8 = strcmp(pcVar10,(char *)__s2), iVar8 != 0)) {
      free(pcVar10);
                    /* Unresolved local var: char * data@[???] */
      pcVar10 = strdup((char *)__s2);
      if (pcVar10 == (char *)0x0) goto LAB_001371b8;
      pOVar4->extends = pcVar10;
    }
    pSVar5 = super->settings;
    puVar1 = &pSVar5->lastUpdate;
    *puVar1 = *puVar1 + 1;
    pSVar5->changed = true;
    return HANDLED;
  }
LAB_001371b8:
                    /* WARNING: Subroutine does not return */
  fail();
}

