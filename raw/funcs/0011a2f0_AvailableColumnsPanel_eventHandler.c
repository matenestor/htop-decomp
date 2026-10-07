/* AvailableColumnsPanel_eventHandler @ 0011a2f0 size 396 */

HandlerResult AvailableColumnsPanel_eventHandler(AvailableColumnsPanel_ *super,wchar_t ch)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t wVar3;
  Vector *pVVar4;
  Object *pOVar5;
  Panel *pPVar6;
  code *pcVar7;
  wchar_t wVar8;
  HandlerResult HVar9;
  ushort **ppuVar10;
  undefined8 *data_;
  char *pcVar11;
  ColumnsPanel_ *super_00;
  long in_R8;
  long in_R9;

  if (((ch & 0xfffffeffU) == 0xd) || (ch == L'ŗ')) {
                    /* Unresolved local var: ListItem * selected@[???]
                       Unresolved local var: wchar_t at@[???] */
    pVVar4 = (super->super).items;
    if ((L'\0' < pVVar4->items) &&
       (pOVar5 = pVVar4->array[(super->super).selected], pOVar5 != (Object *)0x0)) {
      iVar2 = *(int *)&pOVar5[2].klass;
                    /* Unresolved local var: char * name@[???] */
      pcVar11 = (char *)0x0;
      wVar8 = super->columns->selected;
      if (iVar2 < 0x84) {
        pcVar11 = Process_fields[iVar2].name;
      }
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      data_ = malloc(0x18);
      if (data_ != (undefined8 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
        *data_ = &ListItem_class;
        pcVar11 = strdup(pcVar11);
        if (pcVar11 != (char *)0x0) {
          *(int *)(data_ + 2) = iVar2;
          pPVar6 = super->columns;
          data_[1] = pcVar11;
          *(undefined1 *)((long)data_ + 0x14) = 0;
          Vector_insert(pPVar6->items,wVar8,data_);
          super_00 = (ColumnsPanel_ *)super->columns;
          wVar8 = wVar8 + L'\x01';
          pPVar6->needsRedraw = true;
                    /* Unresolved local var: wchar_t size@[???] */
          wVar3 = ((super_00->super).items)->items;
          wVar1 = wVar3 + L'\xffffffff';
          if (wVar3 <= wVar8) {
            wVar8 = wVar1;
          }
          if (wVar8 < L'\0') {
            wVar8 = L'\0';
          }
          (super_00->super).selected = wVar8;
          pcVar7 = (super_00->super).super.klass[1].extends;
          if (pcVar7 != (code *)0x0) {
            (*pcVar7)((long)super_00,0xffffffff,0,(ulong)(uint)wVar1,in_R8,in_R9);
            super_00 = (ColumnsPanel_ *)super->columns;
          }
          ColumnsPanel_update(super_00);
          return HANDLED;
        }
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
  }
  else if ((uint)(ch + L'\xffffffff') < 0xfe) {
    ppuVar10 = __ctype_b_loc();
    if (-1 < (short)(*ppuVar10)[ch]) {
      return IGNORED;
    }
    HVar9 = Panel_selectByTyping(&super->super,ch);
    return HVar9;
  }
  return IGNORED;
}

