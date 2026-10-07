/* Header_writeBackToSettings @ 00126910 size 710 */

/* DWARF original prototype: void Header_writeBackToSettings(Header * this) */

void Header_writeBackToSettings(Header *this)

{
  MeterColumnSetting *pMVar1;
  wchar_t wVar2;
  uint va1;
  Settings *this_00;
  Vector *pVVar3;
  Object *pOVar4;
  MeterClass_3 *pMVar5;
  HashtableItem *pHVar6;
  ulong uVar7;
  char **ppcVar8;
  wchar_t *pwVar9;
  HashtableItem *pHVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  void *va1_00;
  ulong uVar15;
  long in_FS_OFFSET;
  char *name;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (Settings *)this->host->settings;
  Settings_setHeaderLayout(this_00,this->headerLayout);
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  uVar7 = (ulong)HeaderLayout_layouts[this->headerLayout].columns;
  if (uVar7 != 0) {
    uVar15 = 0;
    do {
      while( true ) {
        pMVar1 = this_00->hColumns + uVar15;
        ppcVar8 = pMVar1->names;
        if (ppcVar8 != (char **)0x0) {
                    /* Unresolved local var: size_t j@[???] */
          if (pMVar1->len != 0) {
            uVar12 = 0;
            do {
              ppcVar8 = ppcVar8 + uVar12;
              uVar12 = uVar12 + 1;
              free(*ppcVar8);
              ppcVar8 = pMVar1->names;
            } while (uVar12 < pMVar1->len);
          }
          free(ppcVar8);
        }
                    /* Unresolved local var: MeterColumnSetting * colSettings@[???]
                       Unresolved local var: Vector * vec@[???]
                       Unresolved local var: wchar_t len@[???] */
        free(pMVar1->modes);
        pVVar3 = this->columns[uVar15];
        wVar2 = pVVar3->items;
        if (wVar2 != L'\0') break;
        pMVar1->len = 0;
        uVar15 = uVar15 + 1;
        pMVar1->names = (char **)0x0;
        pMVar1->modes = (wchar_t *)0x0;
                    /* Unresolved local var: wchar_t i@[???] */
        if (uVar7 == uVar15) goto LAB_00126b00;
      }
                    /* Unresolved local var: void * data@[???] */
      if ((0x1fffffffffffffff < (ulong)(long)(wVar2 + L'\x01')) ||
         (ppcVar8 = calloc((long)(wVar2 + L'\x01'),8), ppcVar8 == (char **)0x0)) {
LAB_00126be5:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      pMVar1->names = ppcVar8;
      uVar12 = (ulong)wVar2;
                    /* Unresolved local var: void * data@[???] */
      if ((0x3fffffffffffffff < uVar12) || (pwVar9 = calloc(uVar12,4), pwVar9 == (wchar_t *)0x0))
      goto LAB_00126be5;
      pMVar1->modes = pwVar9;
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: char * dynamic@[???] */
      pMVar1->len = uVar12;
      lVar13 = 0;
      do {
        pOVar4 = pVVar3->array[lVar13];
        va1 = *(uint *)((long)&pOVar4[4].klass + 4);
        pMVar5 = (MeterClass_3 *)pOVar4->klass;
        if (va1 == 0) {
LAB_00126ab3:
          xAsprintf(&name,((char *)0x147626 /* "%s" */),pMVar5->name);
        }
        else if (pMVar5 == &DynamicMeter_class) {
                    /* Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
          uVar12 = this_00->dynamicMeters->size;
          pHVar6 = this_00->dynamicMeters->buckets;
          uVar11 = (ulong)va1 % uVar12;
          va1_00 = pHVar6[uVar11].value;
          if (va1_00 != (void *)0x0) {
            uVar14 = 0;
            pHVar10 = pHVar6 + uVar11;
            do {
              while( true ) {
                if (va1 == pHVar10->key) goto LAB_00126bb8;
                if (pHVar10->probe < uVar14) {
                  va1_00 = (void *)0x0;
                  goto LAB_00126bb8;
                }
                uVar11 = uVar11 + 1;
                if (uVar12 != uVar11) break;
                uVar11 = 0;
                uVar14 = uVar14 + 1;
                va1_00 = pHVar6->value;
                pHVar10 = pHVar6;
                if (va1_00 == (void *)0x0) goto LAB_00126bb8;
              }
              uVar14 = uVar14 + 1;
              pHVar10 = pHVar6 + uVar11;
              va1_00 = pHVar10->value;
            } while (va1_00 != (void *)0x0);
          }
LAB_00126bb8:
          xAsprintf(&name,((char *)0x148820 /* "%s(%s)" */),((char *)0x147e36 /* "Dynamic" */),va1_00);
        }
        else {
          if (pMVar5 != &CPUMeter_class) goto LAB_00126ab3;
          xAsprintf(&name,((char *)0x148827 /* "%s(%u)" */),((char *)0x147826 /* "CPU" */),va1);
        }
        pMVar1->names[lVar13] = name;
        pMVar1->modes[lVar13] = *(wchar_t *)&pOVar4[4].klass;
        lVar13 = lVar13 + 1;
      } while ((wchar_t)lVar13 < wVar2);
      uVar15 = uVar15 + 1;
    } while (uVar7 != uVar15);
  }
LAB_00126b00:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

