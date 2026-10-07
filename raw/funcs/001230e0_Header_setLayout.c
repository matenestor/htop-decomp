/* Header_setLayout @ 001230e0 size 435 */

/* DWARF original prototype: void Header_setLayout(Header * this, HeaderLayout hLayout) */

void Header_setLayout(Header *this,HeaderLayout hLayout)

{
  size_t __size;
  HeaderLayout HVar1;
  Vector **ppVVar2;
  Object *data_;
  Vector **ppVVar3;
  Object **ppOVar4;
  Vector *pVVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  wchar_t idx;
  wchar_t wVar9;
  ulong local_40;

  HVar1 = this->headerLayout;
  this->headerLayout = hLayout;
  local_40 = (ulong)HeaderLayout_layouts[HVar1].columns;
  uVar7 = (ulong)HeaderLayout_layouts[hLayout].columns;
  if (uVar7 == local_40) {
    return;
  }
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
  __size = uVar7 * 8;
  ppVVar2 = this->columns;
  sVar6 = __size;
  uVar8 = uVar7;
  if (local_40 < uVar7) {
                    /* Unresolved local var: void * data@[???] */
    ppVVar3 = realloc(ppVVar2,__size);
    if (ppVVar3 == (Vector **)0x0) {
      free(ppVVar2);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->columns = ppVVar3;
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: Vector * this@[???] */
    do {
      pVVar5 = malloc(0x28);
      if (pVVar5 == (Vector *)0x0) goto LAB_00123275;
                    /* Unresolved local var: void * data@[???] */
      pVVar5->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
      ppOVar4 = calloc(10,8);
      if (ppOVar4 == (Object **)0x0) goto LAB_00123275;
      pVVar5->array = ppOVar4;
      pVVar5->arraySize = L'\n';
      pVVar5->type = &Meter_class.super;
      pVVar5->owner = true;
      pVVar5->items = L'\0';
      pVVar5->dirty_index = L'\xffffffff';
      pVVar5->dirty_count = L'\0';
      ppVVar3[local_40] = pVVar5;
      local_40 = local_40 + 1;
    } while (local_40 < uVar7);
  }
  else {
    while( true ) {
      pVVar5 = *(Vector **)((long)this->columns + sVar6);
      idx = pVVar5->items + L'\xffffffff';
      if (L'\xffffffff' < idx) {
        do {
          wVar9 = idx + L'\xffffffff';
          data_ = Vector_take(pVVar5,idx);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
          Vector_set(this->columns[uVar7 - 1],this->columns[uVar7 - 1]->items,data_);
          pVVar5 = *(Vector **)((long)this->columns + sVar6);
          idx = wVar9;
        } while (wVar9 != L'\xffffffff');
      }
      Vector_delete(pVVar5);
      uVar8 = uVar8 + 1;
      if (local_40 <= uVar8) break;
      sVar6 = uVar8 * 8;
    }
    ppVVar2 = this->columns;
                    /* Unresolved local var: void * data@[???] */
    ppVVar3 = realloc(ppVVar2,__size);
    if (ppVVar3 == (Vector **)0x0) {
      free(ppVVar2);
LAB_00123275:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->columns = ppVVar3;
  }
  Header_calculateHeight(this);
  return;
}

