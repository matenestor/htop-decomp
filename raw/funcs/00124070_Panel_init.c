/* Panel_init @ 00124070 size 299 */

/* DWARF original prototype: void Panel_init(Panel * this, wchar_t x, wchar_t y, wchar_t w, wchar_t
   h, ObjectClass * type, _Bool owner, FunctionBar * fuBar) */

void Panel_init(Panel *this,wchar_t x,wchar_t y,wchar_t w,wchar_t h,ObjectClass *type,_Bool owner,
               FunctionBar *fuBar)

{
  Vector *pVVar1;
  Object **ppOVar2;

  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->cursorX = L'\0';
  this->cursorY = L'\0';
  this->eventHandlerState = (void *)0x0;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
  pVVar1 = malloc(0x28);
  if (pVVar1 != (Vector *)0x0) {
    pVVar1->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
    ppOVar2 = calloc(10,8);
    if (ppOVar2 != (Object **)0x0) {
      pVVar1->array = ppOVar2;
      (this->header).chstr[0].attr = 0;
      (this->header).chstr[0].chars[0] = L'\0';
      (this->header).chstr[0].chars[1] = L'\0';
      (this->header).chstr[0].chars[2] = L'\0';
      pVVar1->items = L'\0';
      pVVar1->dirty_index = L'\xffffffff';
      this->needsRedraw = true;
      this->cursorOn = false;
      (this->header).chptr = (this->header).chstr;
      pVVar1->arraySize = L'\n';
      pVVar1->type = type;
      pVVar1->owner = owner;
      pVVar1->dirty_count = L'\0';
      this->items = pVVar1;
      this->scrollV = L'\0';
      this->scrollH = L'\0';
      this->selected = L'\0';
      this->oldSelected = L'\0';
      this->selectedLen = L'\0';
      this->wasFocus = false;
      (this->header).chlen = L'\0';
      *(undefined8 *)&(this->header).highlightAttr = 0x900000000;
      *(undefined1 (*) [16])((this->header).chstr[0].chars + 2) = (undefined1  [16])0x0;
      this->currentBar = fuBar;
      this->defaultBar = fuBar;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

