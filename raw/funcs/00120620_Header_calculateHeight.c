/* Header_calculateHeight @ 00120620 size 432 */

/* DWARF original prototype: wchar_t Header_calculateHeight(Header * this) */

wchar_t Header_calculateHeight(Header *this)

{
  Object **ppOVar1;
  Object **ppOVar2;
  _Bool _Var3;
  byte bVar4;
  Settings__5 *pSVar5;
  Vector **ppVVar6;
  Vector *pVVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  wchar_t wVar11;
  Object **ppOVar12;
  Object **ppOVar13;
  wchar_t wVar14;
  MeterClass_3 *pMVar15;
  ulong uVar16;
  wchar_t wVar17;
  wchar_t wVar18;
  ulong uVar19;
  wchar_t local_50;

  pSVar5 = this->host->settings;
  _Var3 = pSVar5->headerMargin;
  local_50 = (uint)_Var3 + (uint)_Var3;
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar4 = HeaderLayout_layouts[this->headerLayout].columns;
  uVar19 = (ulong)bVar4;
  if (uVar19 != 0) {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: wchar_t height@[???]
                       Unresolved local var: wchar_t i@[???]
                       Unresolved local var: Meter * meter@[???] */
    ppVVar6 = this->columns;
    uVar16 = 0;
    wVar11 = local_50;
    do {
      pVVar7 = ppVVar6[uVar16];
      wVar17 = pVVar7->items;
      wVar18 = local_50;
      if (L'\0' < wVar17) {
        ppOVar13 = pVVar7->array;
        iVar8 = (int)uVar16;
                    /* Unresolved local var: size_t i@[???] */
        ppOVar1 = ppOVar13 + wVar17;
        wVar17 = local_50;
        do {
          wVar18 = *(int *)&(*ppOVar13)[9].klass + wVar17;
          for (uVar10 = (ulong)(iVar8 + 1); iVar9 = (uint)bVar4 - iVar8, uVar10 < uVar19;
              uVar10 = uVar10 + 1) {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: wchar_t height@[???] */
            pVVar7 = ppVVar6[uVar10];
                    /* Unresolved local var: wchar_t j@[???] */
            wVar14 = pVVar7->items;
            if (L'\0' < wVar14) {
              ppOVar12 = pVVar7->array;
              ppOVar2 = ppOVar12 + wVar14;
              wVar14 = local_50;
              do {
                    /* Unresolved local var: Meter * meter@[???] */
                if (wVar18 <= wVar14) break;
                wVar14 = wVar14 + *(int *)&(*ppOVar12)[9].klass;
                if (wVar17 < wVar14) {
                    /* Unresolved local var: ObjectClass * type@[???] */
                  pMVar15 = (MeterClass_3 *)(*ppOVar12)->klass;
                  if (pMVar15 == (MeterClass_3 *)0x0) {
LAB_00120735:
                    iVar9 = (int)uVar10 - iVar8;
                    goto LAB_0012073e;
                  }
                  if (pMVar15 != &BlankMeter_class) {
                    do {
                      pMVar15 = (pMVar15->super).extends;
                      if (pMVar15 == (MeterClass_3 *)0x0) goto LAB_00120735;
                    } while (pMVar15 != &BlankMeter_class);
                  }
                }
                ppOVar12 = ppOVar12 + 1;
              } while (ppOVar2 != ppOVar12);
            }
          }
LAB_0012073e:
          *(int *)((long)&(*ppOVar13)[9].klass + 4) = iVar9;
          ppOVar13 = ppOVar13 + 1;
          wVar17 = wVar18;
        } while (ppOVar1 != ppOVar13);
      }
      if (wVar11 < wVar18) {
        wVar11 = wVar18;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 != uVar19);
    if (wVar11 != local_50) goto LAB_00120780;
  }
  local_50 = L'\0';
  wVar11 = L'\0';
LAB_00120780:
  wVar11 = (wVar11 + L'\x01') - (uint)(pSVar5->screenTabs == false);
  this->pad = local_50;
  this->height = wVar11;
  return wVar11;
}

