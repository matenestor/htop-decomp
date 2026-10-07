/* ScreenManager_new @ 00132190 size 209 */

ScreenManager_3 * ScreenManager_new(Header_4 *header,Machine_2 *host,State *state,_Bool owner)

{
  ScreenManager_3 *pSVar1;
  Vector *pVVar2;
  Object **ppOVar3;

                    /* Unresolved local var: void * data@[???] */
  pSVar1 = malloc(0x48);
  if (pSVar1 != (ScreenManager_3 *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    pSVar1->x1 = L'\0';
    pSVar1->y1 = L'\0';
    pSVar1->x2 = L'\0';
    pSVar1->y2 = L'\xffffffff';
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
                    /* Unresolved local var: void * data@[???] */
      pVVar2->growthRate = L'\n';
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pSVar1->panelCount = L'\0';
        pSVar1->header = header;
        pVVar2->array = ppOVar3;
        pVVar2->arraySize = L'\n';
        pVVar2->type = &Panel_class.super;
        pVVar2->owner = owner;
        pVVar2->items = L'\0';
        pVVar2->dirty_index = L'\xffffffff';
        pVVar2->dirty_count = L'\0';
        pSVar1->panels = pVVar2;
        pSVar1->host = host;
        pSVar1->state = state;
        pSVar1->allowFocusChange = true;
        return pSVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

