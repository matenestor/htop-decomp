/* Settings_setHeaderLayout @ 00132900 size 384 */

/* DWARF original prototype: void Settings_setHeaderLayout(Settings * this, HeaderLayout hLayout) */

void Settings_setHeaderLayout(Settings *this,HeaderLayout hLayout)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  MeterColumnSetting *pMVar4;
  long *plVar5;
  MeterColumnSetting *pMVar6;
  ulong *puVar7;
  size_t sVar8;
  void *__ptr;
  ulong uVar9;
  ulong uVar10;

  bVar2 = HeaderLayout_layouts[hLayout].columns;
  uVar9 = (ulong)bVar2;
  bVar3 = HeaderLayout_layouts[this->hLayout].columns;
  uVar10 = (ulong)bVar3;
  if ((uint)bVar3 < (uint)bVar2) {
    pMVar4 = this->hColumns;
    sVar8 = uVar9 * 0x18;
                    /* Unresolved local var: void * data@[???] */
    pMVar6 = realloc(pMVar4,sVar8);
    if (pMVar6 == (MeterColumnSetting *)0x0) {
      free(pMVar4);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->hColumns = pMVar6;
    if (sVar8 <= uVar10 * 0x18) {
      sVar8 = uVar10 * 0x18;
    }
    __memset_chk(pMVar6 + uVar10,0,(ulong)((uint)bVar2 - (uint)bVar3) * 0x18,sVar8 + uVar10 * -0x18)
    ;
  }
  else if ((uint)bVar2 < (uint)bVar3) {
    sVar8 = uVar9 * 0x18;
    do {
      plVar5 = (long *)((long)&this->hColumns->len + sVar8);
      __ptr = (void *)plVar5[1];
      if (__ptr != (void *)0x0) {
                    /* Unresolved local var: size_t j@[???] */
        if (*plVar5 != 0) {
          uVar10 = 0;
          do {
            lVar1 = uVar10 * 8;
            uVar10 = uVar10 + 1;
            free(*(void **)((long)__ptr + lVar1));
            puVar7 = (ulong *)((long)&this->hColumns->len + sVar8);
            __ptr = (void *)puVar7[1];
          } while (uVar10 < *puVar7);
        }
        free(__ptr);
        plVar5 = (long *)((long)&this->hColumns->len + sVar8);
      }
                    /* Unresolved local var: uint i@[???] */
      sVar8 = sVar8 + 0x18;
      free((void *)plVar5[2]);
    } while ((uVar9 + 1 + (ulong)(((uint)bVar3 - (uint)bVar2) - 1)) * 0x18 != sVar8);
    pMVar4 = this->hColumns;
                    /* Unresolved local var: void * data@[???] */
    pMVar6 = realloc(pMVar4,uVar9 * 0x18);
    if (pMVar6 == (MeterColumnSetting *)0x0) {
      free(pMVar4);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->hColumns = pMVar6;
  }
  this->hLayout = hLayout;
  this->changed = true;
  return;
}

