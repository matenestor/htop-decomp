/* IncSet_new @ 00127280 size 206 */

IncSet_3 * IncSet_new(FunctionBar *bar)

{
  IncSet_3 *pIVar1;
  FunctionBar *pFVar2;
  long lVar3;
  IncSet_3 *pIVar4;
  IncMode *pIVar5;
  byte bVar6;

                    /* Unresolved local var: void * data@[???] */
  bVar6 = 0;
  pIVar1 = malloc(0x150);
  if (pIVar1 != (IncSet_3 *)0x0) {
    pIVar4 = pIVar1;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      pIVar4->modes[0].buffer[0] = '\0';
      pIVar4->modes[0].buffer[1] = '\0';
      pIVar4->modes[0].buffer[2] = '\0';
      pIVar4->modes[0].buffer[3] = '\0';
      pIVar4->modes[0].buffer[4] = '\0';
      pIVar4->modes[0].buffer[5] = '\0';
      pIVar4->modes[0].buffer[6] = '\0';
      pIVar4->modes[0].buffer[7] = '\0';
      pIVar4 = (IncSet_3 *)((long)pIVar4 + (ulong)bVar6 * -0x10 + 8);
    }
    pFVar2 = FunctionBar_new(searchFunctions,searchKeys,searchEvents);
    pIVar1->modes[0].isFilter = false;
    pIVar1->modes[0].bar = pFVar2;
    pIVar5 = pIVar1->modes + 1;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      pIVar5->buffer[0] = '\0';
      pIVar5->buffer[1] = '\0';
      pIVar5->buffer[2] = '\0';
      pIVar5->buffer[3] = '\0';
      pIVar5->buffer[4] = '\0';
      pIVar5->buffer[5] = '\0';
      pIVar5->buffer[6] = '\0';
      pIVar5->buffer[7] = '\0';
      pIVar5 = (IncMode *)((long)pIVar5 + (ulong)bVar6 * -0x10 + 8);
    }
    pFVar2 = FunctionBar_new(filterFunctions,filterKeys,filterEvents);
    pIVar1->modes[1].isFilter = true;
    pIVar1->modes[1].bar = pFVar2;
    pIVar1->filtering = false;
    pIVar1->found = false;
    pIVar1->active = (IncMode *)0x0;
    pIVar1->defaultBar = bar;
    return pIVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

