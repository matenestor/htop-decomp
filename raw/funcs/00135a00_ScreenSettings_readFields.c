/* ScreenSettings_readFields @ 00135a00 size 359 */

void ScreenSettings_readFields(ScreenSettings_4 *ss,Hashtable_2 *columns,char *line)

{
  ulong uVar1;
  RowField *pRVar2;
  wchar_t wVar3;
  char *pcVar4;
  char **__ptr;
  RowField *pRVar5;
  ulong uVar6;
  size_t __size;
  undefined8 *puVar7;
  char **ppcVar8;
  ulong uVar9;
  byte bVar10;

                    /* Unresolved local var: char * trim@[???]
                       Unresolved local var: char * * ids@[???] */
  bVar10 = 0;
  pcVar4 = String_trim(line);
  __ptr = String_split(pcVar4,' ',(size_t *)0x0);
  free(pcVar4);
  pRVar2 = ss->fields;
  pRVar2[0] = 0;
  pRVar2[1] = 0;
  pRVar2[0x82] = 0;
  pRVar2[0x83] = 0;
  puVar7 = (undefined8 *)((ulong)(pRVar2 + 2) & 0xfffffffffffffff8);
  for (uVar6 = (ulong)(((int)pRVar2 - (int)(undefined8 *)((ulong)(pRVar2 + 2) & 0xfffffffffffffff8))
                       + 0x210U >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
  }
                    /* Unresolved local var: size_t j@[???]
                       Unresolved local var: size_t i@[???] */
  if (*__ptr != (char *)0x0) {
    ppcVar8 = __ptr;
    uVar6 = 0;
    do {
      uVar9 = uVar6;
      if (uVar6 < 0x3fffffff) {
        if (0x83 < uVar6) {
          uVar1 = uVar6 * 4;
          __size = uVar1 + 4;
          pRVar2 = ss->fields;
                    /* Unresolved local var: void * data@[???] */
          pRVar5 = realloc(pRVar2,__size);
          if (pRVar5 == (RowField *)0x0) {
            free(pRVar2);
                    /* WARNING: Subroutine does not return */
            fail();
          }
          ss->fields = pRVar5;
          if (__size < uVar1) {
            __size = uVar1;
          }
          __memset_chk(pRVar5 + uVar6,0,4,__size + uVar6 * -4);
        }
                    /* Unresolved local var: wchar_t id@[???] */
        wVar3 = toFieldIndex(columns,*ppcVar8);
        if (L'\xffffffff' < wVar3) {
          uVar9 = uVar6 + 1;
          ss->fields[uVar6] = wVar3;
          if ((uint)(wVar3 + L'\xffffffff') < 0x83) {
            ss->flags = ss->flags | Process_fields[wVar3].flags;
          }
        }
      }
      ppcVar8 = ppcVar8 + 1;
      uVar6 = uVar9;
    } while (*ppcVar8 != (char *)0x0);
                    /* Unresolved local var: size_t i@[???] */
    pcVar4 = *__ptr;
    ppcVar8 = __ptr;
    while (pcVar4 != (char *)0x0) {
      ppcVar8 = ppcVar8 + 1;
      free(pcVar4);
      pcVar4 = *ppcVar8;
    }
  }
  free(__ptr);
  return;
}

