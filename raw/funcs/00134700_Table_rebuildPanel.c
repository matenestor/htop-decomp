/* Table_rebuildPanel @ 00134700 size 766 */

/* DWARF original prototype: void Table_rebuildPanel(Table * this) */

void Table_rebuildPanel(Table *this)

{
  char cVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  Object *data_;
  Object_Compare p_Var4;
  code *pcVar5;
  HashtableItem *pHVar6;
  wchar_t wVar7;
  wchar_t wVar8;
  wchar_t wVar9;
  Vector *pVVar10;
  ulong a5;
  HashtableItem *pHVar11;
  Hashtable_2 *a3;
  ulong uVar12;
  uint uVar13;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong a2;
  ulong extraout_RDX_02;
  long *a0;
  Panel_ *pPVar14;
  long in_R8;
  wchar_t wVar15;
  long lVar16;
  char local_41;
  wchar_t local_3c;

  Table_updateDisplayList(this);
  pPVar14 = this->panel;
  wVar9 = pPVar14->selected;
  wVar2 = pPVar14->scrollV;
  wVar3 = pPVar14->items->items;
  Vector_prune(pPVar14->items);
  pPVar14->selected = L'\0';
  pPVar14->oldSelected = L'\0';
  wVar15 = this->following;
  a5 = (ulong)(uint)wVar15;
  pPVar14->scrollV = L'\0';
  pPVar14->needsRedraw = true;
  if (wVar15 != L'\xffffffff') {
    a3 = this->table;
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
    uVar12 = a3->size;
    pHVar6 = a3->buckets;
    a2 = (ulong)(uint)wVar15 % uVar12;
    pHVar11 = pHVar6 + a2;
    a0 = pHVar11->value;
    if (a0 != (long *)0x0) {
      a3 = (Hashtable_2 *)0x0;
      do {
        if (wVar15 == pHVar11->key) {
          a5 = (ulong)*(uint *)((long)a0 + 0x14);
          a3 = (Hashtable_2 *)0x0;
          a2 = a5 % uVar12;
          pHVar11 = pHVar6 + a2;
          if (pHVar11->value != (void *)0x0) goto LAB_0013499f;
          break;
        }
        if ((Hashtable_2 *)pHVar11->probe < a3) break;
        a2 = a2 + 1;
        if (uVar12 == a2) {
          a2 = 0;
          pHVar11 = pHVar6;
        }
        else {
          pHVar11 = pHVar6 + a2;
        }
        a0 = pHVar11->value;
        a3 = (Hashtable_2 *)((long)&a3->size + 1);
      } while (a0 != (long *)0x0);
    }
    goto LAB_00134860;
  }
  pVVar10 = this->displayList;
  local_3c = pVVar10->items;
  a3 = (Hashtable_2 *)(ulong)(uint)local_3c;
                    /* Unresolved local var: wchar_t i@[???] */
  a2 = extraout_RDX;
  if (L'\0' < local_3c) goto LAB_0013476f;
  goto LAB_001349c0;
  while( true ) {
    if ((Hashtable_2 *)pHVar11->probe < a3) break;
    a2 = a2 + 1;
    if (uVar12 == a2) {
      a2 = 0;
      pHVar11 = pHVar6;
    }
    else {
      pHVar11 = pHVar6 + a2;
    }
    a3 = (Hashtable_2 *)((long)&a3->size + 1);
    if (pHVar11->value == (void *)0x0) break;
LAB_0013499f:
    if (*(uint *)((long)a0 + 0x14) == pHVar11->key) {
      if (*(code **)(*a0 + 0x28) != (code *)0x0) {
        lVar16 = (**(code **)(*a0 + 0x28))((long)a0,(long)this,a2,(long)a3,in_R8,a5);
        if ((char)lVar16 == '\0') {
          this->following = *(wchar_t *)((long)a0 + 0x14);
        }
        pVVar10 = this->displayList;
        local_3c = pVVar10->items;
        a3 = (Hashtable_2 *)(ulong)(uint)local_3c;
        a2 = extraout_RDX_02;
        if (L'\0' < local_3c) goto LAB_0013476f;
        local_41 = '\0';
        goto LAB_001347dd;
      }
      break;
    }
  }
LAB_00134860:
  pVVar10 = this->displayList;
  local_3c = pVVar10->items;
  if (local_3c < L'\x01') {
LAB_00134878:
    pPVar14 = this->panel;
    this->following = L'\xffffffff';
    pPVar14->selectionColorId = PANEL_SELECTION_FOCUS;
    goto LAB_0013488e;
  }
LAB_0013476f:
  local_41 = '\0';
                    /* Unresolved local var: Row * followed@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  lVar16 = 0;
  wVar15 = L'\0';
  while( true ) {
    data_ = pVVar10->array[lVar16];
    cVar1 = *(char *)((long)&data_[3].klass + 6);
    if ((cVar1 != '\0') &&
       ((p_Var4 = data_->klass[1].compare, p_Var4 == (Object_Compare)0x0 ||
        (wVar7 = (*p_Var4)(data_,this,a2,(long)a3,in_R8,a5), a2 = extraout_RDX_00,
        (char)wVar7 == '\0')))) {
      Vector_set(this->panel->items,wVar15,data_);
      a2 = extraout_RDX_01;
      if ((this->following != L'\xffffffff') && (this->following == *(wchar_t *)&data_[2].klass)) {
        pPVar14 = this->panel;
                    /* Unresolved local var: wchar_t size@[???] */
        wVar7 = pPVar14->items->items;
        wVar8 = wVar7 + L'\xffffffff';
        if (wVar15 < wVar7) {
          wVar8 = wVar15;
        }
        if (wVar8 < L'\0') {
          wVar8 = L'\0';
        }
        pPVar14->selected = wVar8;
        pcVar5 = (pPVar14->super).klass[1].extends;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)((long)pPVar14,0xffffffff,0,(long)a3,in_R8,a5);
          pPVar14 = this->panel;
        }
        uVar13 = wVar9 - wVar2;
        a2 = (ulong)uVar13;
        pPVar14->scrollV = wVar15 - uVar13;
        local_41 = cVar1;
      }
      wVar15 = wVar15 + L'\x01';
    }
    lVar16 = lVar16 + 1;
    if (local_3c <= (wchar_t)lVar16) break;
                    /* Unresolved local var: Row * row@[???] */
    pVVar10 = this->displayList;
  }
LAB_001347dd:
  if (this->following != L'\xffffffff') {
    if (local_41 == '\0') goto LAB_00134878;
    if (this->following != L'\xffffffff') {
      return;
    }
  }
LAB_001349c0:
  pPVar14 = this->panel;
LAB_0013488e:
                    /* Unresolved local var: wchar_t size@[???] */
  wVar15 = pPVar14->items->items;
  pcVar5 = (pPVar14->super).klass[1].extends;
  if ((wVar9 < L'\x01') || (wVar3 + L'\xffffffff' != wVar9)) {
    wVar3 = wVar15 + L'\xffffffff';
    if (wVar9 < wVar15) {
      wVar3 = wVar9;
    }
    uVar12 = (ulong)(uint)wVar3;
    wVar9 = L'\0';
    if (L'\xffffffff' < wVar3) {
      wVar9 = wVar3;
    }
    pPVar14->selected = wVar9;
  }
  else {
    wVar15 = wVar15 + L'\xffffffff';
    uVar12 = 0;
    if (wVar15 < L'\0') {
      wVar15 = L'\0';
    }
    pPVar14->selected = wVar15;
  }
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)((long)pPVar14,0xffffffff,(long)pcVar5,uVar12,in_R8,a5);
    pPVar14 = this->panel;
  }
  pPVar14->scrollV = wVar2;
  return;
}

