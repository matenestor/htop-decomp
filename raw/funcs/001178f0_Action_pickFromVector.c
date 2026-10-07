/* Action_pickFromVector @ 001178f0 size 487 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Object * Action_pickFromVector(State_2 *st,MainPanel_ *list,wchar_t x,_Bool follow)

{
  Machine *host;
  MainPanel__2 *item;
  Vector *pVVar1;
  ScreenManager *this;
  Object *pOVar2;
  wchar_t wVar3;
  long in_FS_OFFSET;
  wchar_t local_60;
  wchar_t ch;
  Panel *panelFocus;
  long local_40;

  host = st->host;
  item = st->mainPanel;
  wVar3 = (item->super).y;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this = (ScreenManager *)
         ScreenManager_new((Header_4 *)st->header,(Machine_2 *)host,(State *)st,false);
  this->allowFocusChange = false;
  ScreenManager_insert(this,&list->super,x,this->panels->items);
  ScreenManager_insert(this,&item->super,L'\xffffffff',this->panels->items);
  if (follow) {
                    /* Unresolved local var: Row * row@[???] */
    pVVar1 = (item->super).items;
    local_60 = L'\xffffffff';
    if ((L'\0' < pVVar1->items) &&
       (pOVar2 = pVVar1->array[(item->super).selected], pOVar2 != (Object *)0x0)) {
      local_60 = *(wchar_t *)&pOVar2[2].klass;
    }
    if (((Table_2 *)host->activeTable)->following == L'\xffffffff') {
      ((Table_2 *)host->activeTable)->following = local_60;
      ScreenManager_run(this,&panelFocus,&ch,(char *)0x0);
      ((Table_2 *)host->activeTable)->following = L'\xffffffff';
    }
    else {
      ScreenManager_run(this,&panelFocus,&ch,(char *)0x0);
    }
  }
  else {
    ScreenManager_run(this,&panelFocus,&ch,(char *)0x0);
    local_60 = L'\xffffffff';
  }
  Vector_delete(this->panels);
  free(this);
  (item->super).y = wVar3;
  (item->super).x = L'\0';
  wVar3 = ~wVar3 + _LINES;
  (item->super).needsRedraw = true;
  (item->super).h = wVar3;
  (item->super).w = _COLS;
  if (((MainPanel_ *)panelFocus == list) && (ch == L'\r')) {
                    /* Unresolved local var: Row * selected@[???] */
    if ((follow) &&
       (((pVVar1 = (item->super).items, pVVar1->items < L'\x01' ||
         (pOVar2 = pVVar1->array[(item->super).selected], pOVar2 == (Object *)0x0)) ||
        (*(wchar_t *)&pOVar2[2].klass != local_60)))) {
      beep();
    }
    else {
      pVVar1 = (list->super).items;
      if (L'\0' < pVVar1->items) {
        pOVar2 = pVVar1->array[(list->super).selected];
        goto LAB_00117a1a;
      }
    }
  }
  pOVar2 = (Object *)0x0;
LAB_00117a1a:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pOVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

