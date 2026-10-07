/* actionSetSchedPolicy @ 00119cb0 size 795 */

Htop_Reaction actionSetSchedPolicy(State_2 *st)

{
  char cVar1;
  wchar_t wVar2;
  long lVar3;
  MainPanel__2 *pMVar4;
  bool bVar5;
  Htop_Reaction HVar6;
  int iVar7;
  MainPanel_ *list;
  Object *pOVar8;
  ObjectClass *pOVar9;
  MainPanel_ *list_00;
  Vector *pVVar10;
  byte bVar11;
  long lVar12;
  wchar_t __policy;
  wchar_t __policy_00;
  char *__s2;
  long lVar13;
  long in_FS_OFFSET;
  char local_49;
  sched_param param;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: _Bool readonly@[???] */
  local_49 = readonly;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  if (readonly) {
    HVar6 = HTOP_KEEP_FOLLOWING;
  }
  else {
    HVar6 = HTOP_KEEP_FOLLOWING;
    if (st->host->settings->ss->dynamic == (char *)0x0) {
                    /* Unresolved local var: Panel * schedPanel@[???]
                       Unresolved local var: ListItem * policy@[???] */
      list = (MainPanel_ *)Scheduling_newPolicyPanel(preSelectedPolicy);
LAB_00119d48:
      pOVar8 = Action_pickFromVector(st,list,L'\x12',true);
      if (pOVar8 != (Object *)0x0) {
        wVar2 = *(wchar_t *)&pOVar8[2].klass;
        if (wVar2 == L'\xffffffff') {
                    /* Unresolved local var: ListItem * item@[???] */
          __s2 = ((char *)0x1473a6 /* "Reset on fork: on" */);
          bVar11 = reset_on_fork ^ 1;
          if (reset_on_fork == true) {
            __s2 = ((char *)0x1473b8 /* "Reset on fork: off" */);
          }
          pOVar8 = *((list->super).items)->array;
          pOVar9 = pOVar8[1].klass;
          reset_on_fork = (_Bool)bVar11;
          if (pOVar9 != (ObjectClass *)0x0) goto code_r0x00119da8;
          goto LAB_00119db7;
        }
        preSelectedPolicy = wVar2;
                    /* Unresolved local var: Panel * prioPanel@[???]
                       Unresolved local var: SchedulingArg v@[???]
                       Unresolved local var: _Bool ok@[???] */
        list_00 = (MainPanel_ *)Scheduling_newPriorityPanel(wVar2,preSelectedPriority);
        if (list_00 != (MainPanel_ *)0x0) {
                    /* Unresolved local var: ListItem * prio@[???] */
          pOVar8 = Action_pickFromVector(st,list_00,L'\x0e',true);
          if (pOVar8 != (Object *)0x0) {
            preSelectedPriority = *(wchar_t *)&pOVar8[2].klass;
          }
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
          free((list_00->super).eventHandlerState);
          Vector_delete((list_00->super).items);
          FunctionBar_delete((list_00->super).defaultBar);
          if (L'Ş' < (list_00->super).header.chlen) {
            free((list_00->super).header.chptr);
          }
          free(list_00);
        }
        __policy_00 = preSelectedPolicy;
        wVar2 = preSelectedPriority;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: wchar_t i@[???] */
        lVar13 = 0;
        bVar5 = true;
        pMVar4 = st->mainPanel;
        pVVar10 = (pMVar4->super).items;
        if (L'\0' < pVVar10->items) {
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: Process * p@[???]
                       Unresolved local var: SchedulingArg * sarg@[???]
                       Unresolved local var: wchar_t policy@[???]
                       Unresolved local var: wchar_t r@[???] */
          lVar12 = (long)preSelectedPolicy;
          do {
            cVar1 = *(char *)((long)&pVVar10->array[lVar13][3].klass + 5);
            if (cVar1 != '\0') {
              param.sched_priority = L'\0';
              if (policies[lVar12].prioritySupport != false) {
                param.sched_priority = wVar2;
              }
              __policy = __policy_00;
              if (reset_on_fork != false) {
                __policy = __policy_00 & 0x40000000;
              }
              iVar7 = sched_setscheduler(*(__pid_t *)&pVVar10->array[lVar13][2].klass,__policy,
                                         (sched_param_2 *)&param);
              bVar5 = (bool)(bVar5 & iVar7 != -1);
              pVVar10 = (pMVar4->super).items;
              local_49 = cVar1;
            }
            lVar13 = lVar13 + 1;
          } while ((wchar_t)lVar13 < pVVar10->items);
                    /* Unresolved local var: Row * row@[???] */
          if (((local_49 != '\x01') && (L'\0' < pVVar10->items)) &&
             (pVVar10->array[(pMVar4->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
                    /* Unresolved local var: SchedulingArg * sarg@[???]
                       Unresolved local var: wchar_t policy@[???]
                       Unresolved local var: wchar_t r@[???] */
            param.sched_priority = L'\0';
            if (policies[__policy_00].prioritySupport != false) {
              param.sched_priority = wVar2;
            }
            if (reset_on_fork != false) {
              __policy_00 = __policy_00 & 0x40000000;
            }
            iVar7 = sched_setscheduler(*(__pid_t *)
                                        &pVVar10->array[(pMVar4->super).selected][2].klass,
                                       __policy_00,(sched_param_2 *)&param);
            bVar5 = (bool)(bVar5 & iVar7 != -1);
          }
          if (!bVar5) {
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
      HVar6 = HTOP_REDRAW_BAR|HTOP_KEEP_FOLLOWING|HTOP_REFRESH;
    }
  }
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x00119da8:
  iVar7 = strcmp((char *)pOVar9,__s2);
  if (iVar7 != 0) {
LAB_00119db7:
    free(pOVar9);
                    /* Unresolved local var: char * data@[???] */
    pOVar9 = (ObjectClass *)strdup(__s2);
    if (pOVar9 == (ObjectClass *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    pOVar8[1].klass = pOVar9;
  }
  goto LAB_00119d48;
}

