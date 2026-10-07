/* actionTag @ 00113f70 size 84 */

Htop_Reaction actionTag(State_2 *st)

{
  byte *pbVar1;
  wchar_t wVar2;
  MainPanel__2 *pMVar3;
  Vector *pVVar4;
  Object *pOVar5;
  wchar_t wVar6;

  pMVar3 = st->mainPanel;
  pVVar4 = (pMVar3->super).items;
  wVar2 = pVVar4->items;
  if (L'\0' < wVar2) {
    wVar6 = (pMVar3->super).selected;
    pOVar5 = pVVar4->array[wVar6];
    if (pOVar5 != (Object *)0x0) {
      pbVar1 = (byte *)((long)&pOVar5[3].klass + 5);
      *pbVar1 = *pbVar1 ^ 1;
                    /* Unresolved local var: wchar_t size@[???] */
      wVar6 = wVar6 + L'\x01';
      if (wVar6 < L'\0') {
        (pMVar3->super).selected = L'\0';
        (pMVar3->super).needsRedraw = true;
        return HTOP_OK;
      }
      if (wVar6 < wVar2) {
        (pMVar3->super).selected = wVar6;
        return HTOP_OK;
      }
      (pMVar3->super).needsRedraw = true;
      (pMVar3->super).selected = wVar2 + L'\xffffffff';
    }
  }
  return HTOP_OK;
}

