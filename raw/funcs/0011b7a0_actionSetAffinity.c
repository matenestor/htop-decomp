/* actionSetAffinity @ 0011b7a0 size 425 */

Htop_Reaction actionSetAffinity(State_2 *st)

{
  _Bool _Var1;
  _Bool _Var2;
  Htop_Reaction HVar3;
  Affinity *affinity;
  Arg list;
  Object *pOVar4;
  Arg AVar5;
  Vector *pVVar6;
  MainPanel__2 *a3;
  MainPanel__2 *pMVar7;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar8;
  Arg host;
  long in_R8;
  long in_R9;
  char cVar9;
  byte bVar10;
  long in_FS_OFFSET;
  wchar_t width;
  long local_40;

  cVar9 = readonly;
  host = (Arg)st->host;
                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (((!readonly) && (*(long *)(*(long *)(*(long *)host.v + 0x40) + 8) == 0)) &&
     (*(wchar_t *)((long)host.v + 0x78) != L'\x01')) {
    pVVar6 = (st->mainPanel->super).items;
    if ((L'\0' < pVVar6->items) &&
       (pOVar4 = pVVar6->array[(st->mainPanel->super).selected], pOVar4 != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
      affinity = (Affinity *)Affinity_get((Process *)(ulong)*(uint *)&pOVar4[2].klass,host.v);
      if (affinity != (Affinity *)0x0) {
        list.v = AffinityPanel_new(host.v,affinity,&width);
        free(affinity->cpus);
        free(affinity);
        a3 = (MainPanel__2 *)0x1;
        AVar5.v = list.v;
        pOVar4 = Action_pickFromVector(st,list.v,width,true);
        lVar8 = extraout_RDX;
        if (pOVar4 != (Object *)0x0) {
                    /* Unresolved local var: Affinity * affinity2@[???]
                       Unresolved local var: _Bool ok@[???] */
          AVar5.v = AffinityPanel_getAffinity(list.v,host.v);
          pMVar7 = st->mainPanel;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: wchar_t i@[???] */
          pVVar6 = (pMVar7->super).items;
          if (L'\0' < pVVar6->items) {
            lVar8 = 0;
            bVar10 = 1;
            do {
                    /* Unresolved local var: Row * row@[???] */
              _Var2 = (((Process_ *)pVVar6->array[lVar8])->super).tag;
              if (_Var2 != false) {
                host.v = AVar5.v;
                _Var1 = Affinity_rowSet((Process_ *)pVVar6->array[lVar8],AVar5);
                bVar10 = bVar10 & _Var1;
                pVVar6 = (pMVar7->super).items;
                cVar9 = _Var2;
              }
              lVar8 = lVar8 + 1;
            } while ((wchar_t)lVar8 < pVVar6->items);
                    /* Unresolved local var: Row * row@[???] */
            if ((cVar9 != '\x01') && (L'\0' < pVVar6->items)) {
              a3 = pMVar7;
              if ((Process_ *)pVVar6->array[(pMVar7->super).selected] != (Process_ *)0x0) {
                host.v = AVar5.v;
                _Var2 = Affinity_rowSet((Process_ *)pVVar6->array[(pMVar7->super).selected],AVar5);
                bVar10 = bVar10 & _Var2;
                a3 = pMVar7;
              }
            }
            if (bVar10 == 0) {
              beep();
            }
          }
          free(*(void **)((long)AVar5.v + 0x10));
          free(AVar5.v);
          lVar8 = extraout_RDX_00;
          AVar5 = host;
        }
        (**(code **)(*(long *)list.v + 0x10))(list.v,(long)AVar5,lVar8,(long)a3,in_R8,in_R9);
        HVar3 = 0x61;
        goto LAB_0011b7e5;
      }
    }
  }
  HVar3 = HTOP_OK;
LAB_0011b7e5:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

