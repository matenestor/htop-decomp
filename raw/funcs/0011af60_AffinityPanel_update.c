/* AffinityPanel_update @ 0011af60 size 197 */

/* DWARF original prototype: void AffinityPanel_update(AffinityPanel * this, _Bool keepSelected) */

void AffinityPanel_update(AffinityPanel *this,_Bool keepSelected)

{
  wchar_t wVar1;
  wchar_t wVar2;
  Vector *from;
  code *pcVar3;
  long in_RCX;
  char *text;
  long in_R8;
  long in_R9;
  wchar_t wVar4;

                    /* Unresolved local var: Panel * super@[DW_OP_reg5(RDI)]
                       Unresolved local var: wchar_t oldSelected@[???] */
  text = ((char *)0x149c0c /* "" */);
  if (this->topoView != false) {
    text = ((char *)0x147401 /* "Collapse/Expand" */);
  }
  FunctionBar_setLabel((this->super).currentBar,L'ċ',text);
  wVar4 = (this->super).selected;
  Vector_prune((this->super).items);
  (this->super).scrollV = L'\0';
  (this->super).selected = L'\0';
  (this->super).oldSelected = L'\0';
  from = this->cpuids;
  (this->super).needsRedraw = true;
  Vector_splice((this->super).items,from);
  (this->super).needsRedraw = true;
  if (keepSelected) {
                    /* Unresolved local var: wchar_t size@[???] */
    wVar2 = ((this->super).items)->items;
    wVar1 = wVar2 + L'\xffffffff';
    if (wVar2 <= wVar4) {
      wVar4 = wVar1;
    }
    if (wVar4 < L'\0') {
      wVar4 = L'\0';
    }
    pcVar3 = (this->super).super.klass[1].extends;
    (this->super).selected = wVar4;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)((long)this,0xffffffff,(ulong)(uint)wVar1,in_RCX,in_R8,in_R9);
      (this->super).needsRedraw = true;
      return;
    }
  }
  (this->super).needsRedraw = true;
  return;
}

