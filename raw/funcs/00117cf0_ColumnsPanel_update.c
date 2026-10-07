/* ColumnsPanel_update @ 00117cf0 size 207 */

void ColumnsPanel_update(ColumnsPanel_ *super)

{
  wchar_t wVar1;
  int iVar2;
  ScreenSettings_3 *pSVar3;
  ScreenSettings_3 *pSVar4;
  Object **ppOVar5;
  RowField *pRVar6;
  long lVar7;
  RowField *pRVar8;

  pSVar3 = super->ss;
  wVar1 = ((super->super).items)->items;
  pRVar8 = pSVar3->fields;
  *super->changed = true;
                    /* Unresolved local var: void * data@[???] */
  pRVar6 = realloc(pRVar8,(long)(wVar1 + L'\x01') * 4);
  if (pRVar6 != (RowField *)0x0) {
    pSVar4 = super->ss;
    pSVar3->fields = pRVar6;
    pSVar4->flags = 0;
                    /* Unresolved local var: wchar_t i@[???] */
    if (wVar1 < L'\x01') {
      pRVar8 = pSVar4->fields;
    }
    else {
                    /* Unresolved local var: wchar_t key@[???] */
      pRVar8 = pSVar4->fields;
      lVar7 = 0;
      ppOVar5 = ((super->super).items)->array;
      do {
        iVar2 = *(int *)&ppOVar5[lVar7][2].klass;
        pRVar8[lVar7] = iVar2;
        if (iVar2 < 0x84) {
          pSVar4->flags = pSVar4->flags | Process_fields[iVar2].flags;
        }
        lVar7 = lVar7 + 1;
      } while (wVar1 != lVar7);
    }
    pRVar8[(long)(wVar1 + L'\x01') + -1] = 0;
    return;
  }
  free(pRVar8);
                    /* WARNING: Subroutine does not return */
  fail();
}

