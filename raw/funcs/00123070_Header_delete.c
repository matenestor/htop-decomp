/* Header_delete @ 00123070 size 97 */

/* DWARF original prototype: void Header_delete(Header * this) */

void Header_delete(Header *this)

{
  Vector **ppVVar1;
  byte bVar2;
  ulong uVar3;

                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar2 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar2 != 0) {
    uVar3 = 0;
    do {
      ppVVar1 = this->columns + uVar3;
      uVar3 = uVar3 + 1;
      Vector_delete(*ppVVar1);
    } while (uVar3 != bVar2);
  }
  free(this->columns);
  free(this);
  return;
}

