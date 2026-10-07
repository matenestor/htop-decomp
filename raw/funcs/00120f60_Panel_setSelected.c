/* Panel_setSelected @ 00120f60 size 49 */

/* DWARF original prototype: void Panel_setSelected(Panel * this, wchar_t selected) */

void Panel_setSelected(Panel *this,wchar_t selected)

{
  wchar_t wVar1;
  wchar_t wVar2;
  code *UNRECOVERED_JUMPTABLE;
  long in_RCX;
  long in_R8;
  long in_R9;

  wVar2 = this->items->items;
  wVar1 = wVar2 + L'\xffffffff';
  if (wVar2 <= selected) {
    selected = wVar1;
  }
  if (selected < L'\0') {
    selected = L'\0';
  }
  UNRECOVERED_JUMPTABLE = (this->super).klass[1].extends;
  this->selected = selected;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00120f8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)this,0xffffffff,(ulong)(uint)wVar1,in_RCX,in_R8,in_R9);
    return;
  }
  return;
}

