/* Scheduling_togglePolicyPanelResetOnFork @ 001320d0 size 132 */

void Scheduling_togglePolicyPanelResetOnFork(Panel *schedPanel)

{
  Object *pOVar1;
  int iVar2;
  ObjectClass *pOVar3;
  bool bVar4;
  char *__s2;

  __s2 = ((char *)0x1473b8 /* "Reset on fork: off" */);
  bVar4 = !reset_on_fork;
  if (!reset_on_fork) {
    __s2 = ((char *)0x1473a6 /* "Reset on fork: on" */);
  }
  pOVar1 = *schedPanel->items->array;
  pOVar3 = pOVar1[1].klass;
  reset_on_fork = bVar4;
  if ((pOVar3 != (ObjectClass *)0x0) && (iVar2 = strcmp((char *)pOVar3,__s2), iVar2 == 0)) {
    return;
  }
  free(pOVar3);
                    /* Unresolved local var: char * data@[???] */
  pOVar3 = (ObjectClass *)strdup(__s2);
  if (pOVar3 != (ObjectClass *)0x0) {
    pOVar1[1].klass = pOVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

