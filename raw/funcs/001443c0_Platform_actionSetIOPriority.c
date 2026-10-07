/* Platform_actionSetIOPriority @ 001443c0 size 502 */

Htop_Reaction Platform_actionSetIOPriority(State_2 *st)

{
  char cVar1;
  MainPanel__2 *pMVar2;
  bool bVar3;
  MainPanel_ *list;
  Object *pOVar4;
  long lVar5;
  Vector *pVVar6;
  long lVar7;
  char cVar8;
  uint uVar9;

  cVar8 = readonly;
  if (!readonly) {
    pVVar6 = (st->mainPanel->super).items;
    if ((L'\0' < pVVar6->items) &&
       (pOVar4 = pVVar6->array[(st->mainPanel->super).selected], pOVar4 != (Object *)0x0)) {
      list = (MainPanel_ *)IOPriorityPanel_new(*(IOPriority *)&pOVar4[0x3d].klass);
      pOVar4 = Action_pickFromVector(st,list,L'\x14',true);
      if (pOVar4 != (Object *)0x0) {
                    /* Unresolved local var: IOPriority ioprio2@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: ListItem * selected@[???] */
        pVVar6 = (list->super).items;
        uVar9 = 0;
        if ((L'\0' < pVVar6->items) &&
           (pOVar4 = pVVar6->array[(list->super).selected], uVar9 = 0, pOVar4 != (Object *)0x0)) {
          uVar9 = *(uint *)&pOVar4[2].klass;
        }
        pMVar2 = st->mainPanel;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: wchar_t i@[???] */
        pVVar6 = (pMVar2->super).items;
        if (L'\0' < pVVar6->items) {
          lVar7 = 0;
          bVar3 = true;
          do {
                    /* Unresolved local var: Row * row@[???] */
            pOVar4 = pVVar6->array[lVar7];
            cVar1 = *(char *)((long)&pOVar4[3].klass + 5);
            if (cVar1 != '\0') {
                    /* Unresolved local var: Process * p@[???] */
              syscall(0xfb,1,(ulong)*(uint *)&pOVar4[2].klass,(ulong)uVar9);
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
              lVar5 = syscall(0xfc,1,(ulong)*(uint *)&pOVar4[2].klass);
              *(uint *)&pOVar4[0x3d].klass = (uint)lVar5;
              bVar3 = (bool)(bVar3 & uVar9 == (uint)lVar5);
              pVVar6 = (pMVar2->super).items;
              cVar8 = cVar1;
            }
            lVar7 = lVar7 + 1;
          } while ((wchar_t)lVar7 < pVVar6->items);
                    /* Unresolved local var: Row * row@[???] */
          if (((cVar8 != '\x01') && (L'\0' < pVVar6->items)) &&
             (pOVar4 = pVVar6->array[(pMVar2->super).selected], pOVar4 != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
            syscall(0xfb,1,(ulong)*(uint *)&pOVar4[2].klass,(ulong)uVar9);
                    /* Unresolved local var: IOPriority ioprio@[???]
                       Unresolved local var: LinuxProcess * this@[???] */
            lVar7 = syscall(0xfc,1,(ulong)*(uint *)&pOVar4[2].klass);
            *(uint *)&pOVar4[0x3d].klass = (uint)lVar7;
            bVar3 = (bool)(bVar3 & uVar9 == (uint)lVar7);
          }
          if (!bVar3) {
            beep();
          }
        }
      }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
      free((list->super).eventHandlerState);
      Vector_delete((list->super).items);
      FunctionBar_delete((list->super).defaultBar);
      if (L'Ş' < (list->super).header.chlen) {
        free((list->super).header.chptr);
      }
      free(list);
      return 0x61;
    }
  }
  return HTOP_OK;
}

