/* Header_updateData @ 00120590 size 143 */

/* DWARF original prototype: void Header_updateData(Header * this) */

void Header_updateData(Header *this)

{
  byte bVar1;
  wchar_t wVar2;
  Vector *pVVar3;
  long *a0;
  long in_RCX;
  long extraout_RDX;
  long a2;
  long lVar4;
  long in_RSI;
  long in_R8;
  long in_R9;
  ulong uVar5;

                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  a2 = (long)this->headerLayout * 3;
  bVar1 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar1 != 0) {
    uVar5 = 0;
    do {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: wchar_t items@[???] */
      pVVar3 = this->columns[uVar5];
      wVar2 = pVVar3->items;
                    /* Unresolved local var: wchar_t i@[???] */
      if (L'\0' < wVar2) {
        lVar4 = 0;
        do {
                    /* Unresolved local var: Meter * meter@[???] */
          a0 = *(long **)((long)pVVar3->array + lVar4);
          lVar4 = lVar4 + 8;
          (**(code **)(*a0 + 0x38))((long)a0,in_RSI,a2,in_RCX,in_R8,in_R9);
          a2 = extraout_RDX;
        } while ((long)wVar2 * 8 != lVar4);
      }
      uVar5 = uVar5 + 1;
    } while (bVar1 != uVar5);
  }
  return;
}

