/* FunctionBar_new @ 00117e30 size 386 */

FunctionBar * FunctionBar_new(char **functions,char **keys,wchar_t *events)

{
  FunctionBar *pFVar1;
  char **ppcVar2;
  char *pcVar3;
  wchar_t *pwVar4;
  long lVar5;
  undefined8 *puVar6;

                    /* Unresolved local var: void * data@[???] */
  pFVar1 = calloc(1,0x28);
  if (pFVar1 != (FunctionBar *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    ppcVar2 = calloc(0x10,8);
    if (ppcVar2 != (char **)0x0) {
      pFVar1->functions = ppcVar2;
      if (functions == (char **)0x0) {
        functions = FunctionBar_FLabels;
      }
                    /* Unresolved local var: wchar_t i@[???] */
      lVar5 = 0;
      do {
        if (*(char **)((long)functions + lVar5) == (char *)0x0) break;
        puVar6 = (undefined8 *)((long)pFVar1->functions + lVar5);
                    /* Unresolved local var: char * data@[???] */
        pcVar3 = strdup(*(char **)((long)functions + lVar5));
        if (pcVar3 == (char *)0x0) goto LAB_00117fb1;
        lVar5 = lVar5 + 8;
        *puVar6 = pcVar3;
      } while (lVar5 != 0x78);
      if ((keys == (char **)0x0) || (events == (wchar_t *)0x0)) {
        pFVar1->staticData = true;
        lVar5 = 10;
        (pFVar1->keys).keys = FunctionBar_FKeys;
        pFVar1->events = FunctionBar_FEvents;
LAB_00117f06:
                    /* Unresolved local var: wchar_t i@[???] */
        pFVar1->size = (wchar_t)lVar5;
        return pFVar1;
      }
      pFVar1->staticData = false;
                    /* Unresolved local var: void * data@[???] */
      ppcVar2 = calloc(0xf,8);
      if (ppcVar2 != (char **)0x0) {
        (pFVar1->keys).keys = ppcVar2;
                    /* Unresolved local var: void * data@[???] */
        pwVar4 = calloc(0xf,4);
        if (pwVar4 != (wchar_t *)0x0) {
          pFVar1->events = pwVar4;
          lVar5 = 0;
          do {
            if (functions[lVar5] == (char *)0x0) goto LAB_00117f06;
                    /* Unresolved local var: char * data@[???] */
            ppcVar2 = (pFVar1->keys).keys;
            pcVar3 = strdup(keys[lVar5]);
            if (pcVar3 == (char *)0x0) goto LAB_00117fb1;
            ppcVar2[lVar5] = pcVar3;
            pFVar1->events[lVar5] = events[lVar5];
            lVar5 = lVar5 + 1;
          } while (lVar5 != 0xf);
          lVar5 = 0xf;
          goto LAB_00117f06;
        }
      }
    }
  }
LAB_00117fb1:
                    /* WARNING: Subroutine does not return */
  fail();
}

