/* ScreenManager_resize @ 0012dea0 size 177 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void ScreenManager_resize(ScreenManager * this) */

void ScreenManager_resize(ScreenManager *this)

{
  wchar_t wVar1;
  int iVar2;
  Object **ppOVar3;
  Object *pOVar4;
  int iVar5;
  Object **ppOVar6;
  int iVar7;
  int iVar8;
  wchar_t wVar9;

  wVar9 = this->y1;
  if ((this->state->hideMeters == false) && (this->header != (Header_2 *)0x0)) {
    wVar9 = wVar9 + this->header->height;
  }
  wVar1 = this->panelCount;
                    /* Unresolved local var: wchar_t i@[???] */
  iVar5 = wVar1 + L'\xffffffff';
  ppOVar3 = this->panels->array;
  iVar8 = (_LINES - wVar9) + this->y2;
  if (iVar5 < 1) {
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    ppOVar6 = ppOVar3;
    do {
                    /* Unresolved local var: Panel * panel@[???] */
      pOVar4 = *ppOVar6;
      ppOVar6 = ppOVar6 + 1;
      *(int *)&pOVar4[1].klass = iVar7;
      iVar2 = *(int *)&pOVar4[2].klass;
      *(int *)((long)&pOVar4[2].klass + 4) = iVar8;
      iVar7 = iVar7 + iVar2 + 1;
      *(undefined1 *)&pOVar4[9].klass = 1;
      *(wchar_t *)((long)&pOVar4[1].klass + 4) = wVar9;
    } while (ppOVar3 + (ulong)(uint)(wVar1 + L'\xfffffffe') + 1 != ppOVar6);
  }
  pOVar4 = ppOVar3[iVar5];
  iVar5 = _COLS - this->x1;
  wVar1 = this->x2;
  *(undefined1 *)&pOVar4[9].klass = 1;
  pOVar4[1].klass = (ObjectClass *)CONCAT44(wVar9,iVar7);
  pOVar4[2].klass = (ObjectClass *)CONCAT44(iVar8,(iVar5 + wVar1) - iVar7);
  return;
}

