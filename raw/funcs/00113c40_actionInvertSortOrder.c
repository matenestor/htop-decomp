/* actionInvertSortOrder @ 00113c40 size 68 */

Htop_Reaction actionInvertSortOrder(State_2 *st)

{
  Machine *pMVar1;
  ScreenSettings_2 *pSVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;

  pMVar1 = st->host;
  pSVar2 = pMVar1->settings->ss;
                    /* Unresolved local var: wchar_t * attr@[???] */
  if (pSVar2->treeView == false) {
    pwVar4 = &pSVar2->direction;
    wVar3 = pSVar2->direction;
  }
  else {
    pwVar4 = &pSVar2->treeDirection;
    wVar3 = pSVar2->treeDirection;
  }
  *pwVar4 = ((wVar3 != L'\x01') - 1) + (uint)(wVar3 != L'\x01');
  pMVar1->activeTable->needsSort = true;
  return 0x4d;
}

