/* ScreenManager_remove @ 0012e530 size 176 */

/* DWARF original prototype: Panel * ScreenManager_remove(ScreenManager * this, wchar_t idx) */

Panel * ScreenManager_remove(ScreenManager *this,wchar_t idx)

{
  wchar_t wVar1;
  Object *pOVar2;
  int iVar3;
  wchar_t wVar4;
  Vector *this_00;
  Object **ppOVar5;
  Object *pOVar6;
  Panel *pPVar7;
  Object **ppOVar8;
  long in_RCX;
  long a2;
  long lVar9;
  ulong a1;
  long in_R8;
  long in_R9;

  lVar9 = (long)idx;
                    /* Unresolved local var: Object * removed@[???] */
  a1 = (ulong)(uint)idx;
  this_00 = this->panels;
  iVar3 = *(int *)&this_00->array[lVar9][2].klass;
  pPVar7 = (Panel *)Vector_take(this_00,idx);
  if (this_00->owner != false) {
    (*((pPVar7->super).klass)->delete)((Object *)pPVar7,a1,a2,in_RCX,in_R8,in_R9);
    pPVar7 = (Panel *)0x0;
  }
  wVar4 = this->panelCount;
  wVar1 = wVar4 + L'\xffffffff';
  this->panelCount = wVar1;
  if (idx < wVar1) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: Panel * p@[???] */
    ppOVar5 = this->panels->array;
    ppOVar8 = ppOVar5 + lVar9;
    do {
      pOVar6 = *ppOVar8;
      ppOVar8 = ppOVar8 + 1;
      pOVar2 = pOVar6 + 1;
      *(int *)&pOVar2->klass = *(int *)&pOVar2->klass - iVar3;
      *(undefined1 *)&pOVar6[9].klass = 1;
    } while (ppOVar8 != ppOVar5 + (ulong)(uint)((wVar4 - idx) - 2) + lVar9 + 1);
  }
  return pPVar7;
}

