/* Header_new @ 001184a0 size 249 */

Header_4 * Header_new(Machine_2 *host,HeaderLayout hLayout)

{
  Header_4 *pHVar1;
  Vector **ppVVar2;
  Vector *pVVar3;
  Object **ppOVar4;
  ulong uVar5;
  ulong uVar6;

                    /* Unresolved local var: void * data@[???] */
  pHVar1 = calloc(1,0x20);
  if (pHVar1 != (Header_4 *)0x0) {
    uVar6 = (ulong)HeaderLayout_layouts[hLayout].columns;
                    /* Unresolved local var: void * data@[???] */
    ppVVar2 = malloc(uVar6 * 8);
    if (ppVVar2 != (Vector **)0x0) {
      pHVar1->columns = ppVVar2;
      pHVar1->headerLayout = hLayout;
      pHVar1->host = host;
                    /* Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
      if (uVar6 != 0) {
                    /* Unresolved local var: Vector * this@[???] */
        uVar5 = 0;
        do {
                    /* Unresolved local var: void * data@[???] */
          pVVar3 = malloc(0x28);
          if (pVVar3 == (Vector *)0x0) goto LAB_00118594;
          pVVar3->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
          ppOVar4 = calloc(10,8);
          if (ppOVar4 == (Object **)0x0) goto LAB_00118594;
          pVVar3->array = ppOVar4;
          ppVVar2[uVar5] = pVVar3;
          uVar5 = uVar5 + 1;
          pVVar3->arraySize = L'\n';
          pVVar3->type = &Meter_class.super;
          pVVar3->owner = true;
          pVVar3->items = L'\0';
          pVVar3->dirty_index = L'\xffffffff';
          pVVar3->dirty_count = L'\0';
        } while (uVar5 != uVar6);
      }
      return pHVar1;
    }
  }
LAB_00118594:
                    /* WARNING: Subroutine does not return */
  fail();
}

