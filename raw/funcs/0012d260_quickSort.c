/* quickSort @ 0012d260 size 254 */

void quickSort(Object **array,wchar_t left,wchar_t right,Object_Compare compare)

{
  Object **ppOVar1;
  ObjectClass **ppOVar2;
  wchar_t wVar3;
  long lVar4;
  Object *pOVar5;
  ulong a2;
  ulong extraout_RDX;
  wchar_t wVar6;
  long in_R8;
  long in_R9;
  Object *pOVar7;
  Object **ppOVar8;
  wchar_t local_44;

                    /* Unresolved local var: wchar_t pivotIndex@[???]
                       Unresolved local var: wchar_t pivotNewIndex@[???] */
  if (left < right) {
                    /* Unresolved local var: Object * pivotValue@[???]
                       Unresolved local var: wchar_t storeIndex@[???]
                       Unresolved local var: Object * tmp@[???] */
    ppOVar1 = array + right;
    local_44 = left;
    do {
      pOVar7 = array[(right + local_44) / 2];
      array[(right + local_44) / 2] = *ppOVar1;
                    /* Unresolved local var: wchar_t i@[???] */
      a2 = (ulong)(uint)right;
      *ppOVar1 = pOVar7;
      wVar6 = local_44;
      if (local_44 < right) {
        pOVar5 = (Object *)(long)local_44;
        ppOVar8 = array + (long)pOVar5;
        ppOVar2 = &pOVar5->klass;
        do {
          wVar3 = (*compare)(*ppOVar8,pOVar7,a2,(long)pOVar5,in_R8,in_R9);
          if (wVar3 < L'\x01') {
                    /* Unresolved local var: Object * tmp@[???] */
            lVar4 = (long)wVar6;
            pOVar5 = *ppOVar8;
            wVar6 = wVar6 + L'\x01';
            *ppOVar8 = array[lVar4];
            array[lVar4] = pOVar5;
          }
          ppOVar8 = ppOVar8 + 1;
          a2 = extraout_RDX;
        } while (array + (long)ppOVar2 + (ulong)(uint)(right - local_44) != ppOVar8);
                    /* Unresolved local var: Object * tmp@[???] */
        pOVar7 = *ppOVar1;
      }
      pOVar5 = array[wVar6];
      array[wVar6] = pOVar7;
      *ppOVar1 = pOVar5;
      quickSort(array,local_44,wVar6 + L'\xffffffff',compare);
      local_44 = wVar6 + L'\x01';
    } while (local_44 < right);
  }
  return;
}

