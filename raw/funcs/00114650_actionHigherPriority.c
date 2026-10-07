/* actionHigherPriority @ 00114650 size 218 */

Htop_Reaction actionHigherPriority(State_2 *st)

{
  MainPanel__2 *pMVar1;
  Process *pPVar2;
  _Bool _Var3;
  _Bool _Var4;
  Vector *pVVar5;
  Htop_Reaction HVar6;
  long lVar7;
  byte bVar8;
  byte bVar9;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  HVar6 = HTOP_OK;
  if ((!readonly) && (HVar6 = HTOP_OK, st->host->settings->ss->dynamic == (char *)0x0)) {
    pMVar1 = st->mainPanel;
                    /* Unresolved local var: _Bool changed@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: wchar_t i@[???] */
    pVVar5 = (pMVar1->super).items;
    if (L'\0' < pVVar5->items) {
      lVar7 = 0;
      bVar8 = 1;
      bVar9 = readonly;
      do {
                    /* Unresolved local var: Row * row@[???] */
        pPVar2 = (Process *)pVVar5->array[lVar7];
        _Var4 = (pPVar2->super).tag;
        if (_Var4 != false) {
                    /* Unresolved local var: Process * this@[???]
                       Unresolved local var: wchar_t old_prio@[???]
                       Unresolved local var: wchar_t err@[???] */
          _Var3 = Process_setPriority(pPVar2,(int)pPVar2->nice + L'\xffffffff');
          bVar8 = bVar8 & _Var3;
          pVVar5 = (pMVar1->super).items;
          bVar9 = _Var4;
        }
        lVar7 = lVar7 + 1;
      } while ((wchar_t)lVar7 < pVVar5->items);
                    /* Unresolved local var: Row * row@[???] */
      if (((bVar9 != 1) && (L'\0' < pVVar5->items)) &&
         (pPVar2 = (Process *)pVVar5->array[(pMVar1->super).selected], pPVar2 != (Process *)0x0)) {
                    /* Unresolved local var: Process * this@[???]
                       Unresolved local var: wchar_t old_prio@[???]
                       Unresolved local var: wchar_t err@[???] */
        _Var4 = Process_setPriority(pPVar2,(int)pPVar2->nice + L'\xffffffff');
        bVar8 = bVar8 & _Var4;
      }
      if (bVar8 == 0) {
        beep();
      }
      HVar6 = (Htop_Reaction)bVar9;
    }
  }
  return HVar6;
}

