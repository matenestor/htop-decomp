/* Panel_new @ 00123f10 size 342 */

Panel * Panel_new(wchar_t x,wchar_t y,wchar_t w,wchar_t h,ObjectClass *type,_Bool owner,
                 FunctionBar *fuBar)

{
  Panel *pPVar1;
  Vector *pVVar2;
  Object **ppOVar3;

                    /* Unresolved local var: void * data@[???] */
  pPVar1 = malloc(0x26e0);
  if (pPVar1 != (Panel *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    pPVar1->cursorX = L'\0';
    pPVar1->cursorY = L'\0';
    (pPVar1->super).klass = &Panel_class.super;
    pPVar1->eventHandlerState = (void *)0x0;
    pPVar1->x = x;
    pPVar1->y = y;
    pPVar1->w = w;
    pPVar1->h = h;
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
      pVVar2->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pVVar2->array = ppOVar3;
        (pPVar1->header).chstr[0].attr = 0;
        (pPVar1->header).chstr[0].chars[0] = L'\0';
        (pPVar1->header).chstr[0].chars[1] = L'\0';
        (pPVar1->header).chstr[0].chars[2] = L'\0';
        pVVar2->items = L'\0';
        pVVar2->dirty_index = L'\xffffffff';
        pPVar1->needsRedraw = true;
        pPVar1->cursorOn = false;
        (pPVar1->header).chptr = (pPVar1->header).chstr;
        *(undefined8 *)&(pPVar1->header).highlightAttr = 0x900000000;
        pVVar2->arraySize = L'\n';
        pVVar2->type = type;
        pVVar2->owner = owner;
        pVVar2->dirty_count = L'\0';
        pPVar1->items = pVVar2;
        pPVar1->scrollV = L'\0';
        pPVar1->scrollH = L'\0';
        pPVar1->selected = L'\0';
        pPVar1->oldSelected = L'\0';
        pPVar1->selectedLen = L'\0';
        pPVar1->wasFocus = false;
        (pPVar1->header).chlen = L'\0';
        *(undefined1 (*) [16])((pPVar1->header).chstr[0].chars + 2) = (undefined1  [16])0x0;
        pPVar1->currentBar = fuBar;
        pPVar1->defaultBar = fuBar;
        return pPVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

