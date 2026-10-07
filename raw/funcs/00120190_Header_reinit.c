/* Header_reinit @ 00120190 size 150 */

/* DWARF original prototype: void Header_reinit(Header * this) */

void Header_reinit(Header *this)

{
  byte bVar1;
  code *pcVar2;
  Vector *pVVar3;
  ulong a3;
  Vector **a2;
  long lVar4;
  long in_RSI;
  long in_R8;
  long in_R9;
  ulong uVar5;

                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar1 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar1 != 0) {
    a2 = this->columns;
    uVar5 = 0;
    do {
                    /* Unresolved local var: wchar_t i@[???] */
      pVVar3 = a2[uVar5];
      lVar4 = 0;
      a3 = (ulong)(uint)pVVar3->items;
      if (L'\0' < pVVar3->items) {
        do {
                    /* Unresolved local var: Meter * meter@[???] */
          pcVar2 = pVVar3->array[lVar4]->klass[1].extends;
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)pVVar3->array[lVar4],in_RSI,(long)a2,a3,in_R8,in_R9);
            a2 = this->columns;
          }
          pVVar3 = a2[uVar5];
          lVar4 = lVar4 + 1;
        } while ((wchar_t)lVar4 < pVVar3->items);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != bVar1);
  }
  return;
}

