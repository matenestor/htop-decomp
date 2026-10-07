/* ProcessTable_prepareEntries @ 0011fc50 size 60 */

void ProcessTable_prepareEntries(ProcessTable_ *super)

{
  Object **ppOVar1;
  undefined1 uVar2;
  wchar_t wVar3;
  Vector *pVVar4;
  Object *pOVar5;
  Object **ppOVar6;

                    /* Unresolved local var: wchar_t i@[???] */
  pVVar4 = (super->super).rows;
  super->totalTasks = 0;
  super->runningTasks = 0;
  super->userlandThreads = 0;
  super->kernelThreads = 0;
  wVar3 = pVVar4->items;
  if (L'\0' < wVar3) {
    ppOVar6 = pVVar4->array;
    ppOVar1 = ppOVar6 + wVar3;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar5 = *ppOVar6;
      ppOVar6 = ppOVar6 + 1;
      uVar2 = *(undefined1 *)((long)&pOVar5[3].klass + 6);
      *(undefined1 *)((long)&pOVar5[4].klass + 1) = 0;
      *(undefined1 *)((long)&pOVar5[3].klass + 6) = 1;
      *(undefined1 *)((long)&pOVar5[3].klass + 7) = uVar2;
    } while (ppOVar1 != ppOVar6);
  }
  return;
}

