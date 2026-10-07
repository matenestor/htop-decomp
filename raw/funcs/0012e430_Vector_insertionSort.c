/* Vector_insertionSort @ 0012e430 size 141 */

/* DWARF original prototype: void Vector_insertionSort(Vector * this) */

void Vector_insertionSort(Vector *this)

{
  Object **ppOVar1;
  Object_Compare p_Var2;
  Object *pOVar3;
  wchar_t wVar4;
  Object **ppOVar5;
  long in_RCX;
  ulong uVar6;
  ulong uVar7;
  ulong extraout_RDX;
  ulong uVar8;
  long in_R8;
  long in_R9;
  ulong uVar9;

  ppOVar1 = this->array;
  p_Var2 = this->type->compare;
  uVar6 = (ulong)(uint)(this->items + L'\xffffffff');
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\x01' < this->items) {
    uVar9 = 0;
    uVar7 = uVar6;
    do {
                    /* Unresolved local var: Object * t@[???]
                       Unresolved local var: wchar_t j@[???] */
      pOVar3 = ppOVar1[uVar9 + 1];
      uVar8 = uVar9;
      do {
        wVar4 = (*p_Var2)(ppOVar1[uVar8],pOVar3,uVar7,in_RCX,in_R8,in_R9);
        uVar7 = extraout_RDX;
        if (wVar4 < L'\x01') {
          ppOVar5 = ppOVar1 + ((int)uVar8 + 1);
          break;
        }
        ppOVar1[uVar8 + 1] = ppOVar1[uVar8];
        uVar8 = uVar8 - 1;
        ppOVar5 = ppOVar1;
      } while ((int)uVar8 != -1);
      *ppOVar5 = pOVar3;
      uVar9 = uVar9 + 1;
    } while (uVar6 != uVar9);
  }
  return;
}

