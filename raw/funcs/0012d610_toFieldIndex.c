/* toFieldIndex @ 0012d610 size 535 */

wchar_t toFieldIndex(Hashtable_2 *columns,char *str)

{
  long lVar1;
  char *__s2;
  int iVar2;
  ushort **ppuVar3;
  long lVar4;
  char *pcVar5;
  HashtableItem *pHVar6;
  ulong uVar7;
  ulong uVar8;
  ProcessFieldData *pPVar9;
  HashtableItem *pHVar10;
  long in_FS_OFFSET;
  char *local_80;
  wchar_t local_74;
  char dynamic [32];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  ppuVar3 = __ctype_b_loc();
  if ((*(byte *)((long)*ppuVar3 + (long)*str * 2 + 1) & 8) == 0) {
    dynamic[0] = '\0';
    dynamic[1] = '\0';
    dynamic[2] = '\0';
    dynamic[3] = '\0';
    dynamic[4] = '\0';
    dynamic[5] = '\0';
    dynamic[6] = '\0';
    dynamic[7] = '\0';
    dynamic[8] = '\0';
    dynamic[9] = '\0';
    dynamic[10] = '\0';
    dynamic[0xb] = '\0';
    dynamic[0xc] = '\0';
    dynamic[0xd] = '\0';
    dynamic[0xe] = '\0';
    dynamic[0xf] = '\0';
    dynamic[0x10] = '\0';
    dynamic[0x11] = '\0';
    dynamic[0x12] = '\0';
    dynamic[0x13] = '\0';
    dynamic[0x14] = '\0';
    dynamic[0x15] = '\0';
    dynamic[0x16] = '\0';
    dynamic[0x17] = '\0';
    dynamic[0x18] = '\0';
    dynamic[0x19] = '\0';
    dynamic[0x1a] = '\0';
    dynamic[0x1b] = '\0';
    dynamic[0x1c] = '\0';
    dynamic[0x1d] = '\0';
    dynamic[0x1e] = '\0';
    dynamic[0x1f] = '\0';
    iVar2 = __isoc23_sscanf(str,((char *)0x148bfc /* "Dynamic(%30s)" */),dynamic);
    if ((iVar2 != 0) && (pcVar5 = strrchr(dynamic,0x29), pcVar5 != (char *)0x0)) {
      *pcVar5 = '\0';
      if ((columns == (Hashtable_2 *)0x0) || (columns->size == 0)) {
        *pcVar5 = ')';
      }
      else {
        pHVar10 = columns->buckets;
        local_74 = L'\0';
        local_80 = (char *)0x0;
        pHVar6 = pHVar10 + columns->size;
        do {
          __s2 = pHVar10->value;
          if ((__s2 != (char *)0x0) && (iVar2 = strcmp(dynamic,__s2), iVar2 == 0)) {
            local_74 = pHVar10->key;
            local_80 = __s2;
          }
          pHVar10 = pHVar10 + 1;
        } while (pHVar10 != pHVar6);
        *pcVar5 = ')';
        if (local_80 != (char *)0x0) goto LAB_0012d68a;
      }
    }
                    /* Unresolved local var: wchar_t p@[???] */
                    /* Unresolved local var: char * end@[???]
                       Unresolved local var: _Bool success@[???]
                       Unresolved local var: uint key@[???]
                       Unresolved local var: DynamicIterator.conflict iter@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: DynamicIterator.conflict * iter@[???] */
    local_74 = L'\x01';
    pPVar9 = Process_fields;
    do {
      pPVar9 = pPVar9 + 1;
                    /* Unresolved local var: char * pName@[???] */
      if ((pPVar9->name != (char *)0x0) && (iVar2 = strcmp(pPVar9->name,str), iVar2 == 0))
      goto LAB_0012d68a;
      local_74 = local_74 + L'\x01';
    } while (local_74 != L'\x84');
  }
  else {
                    /* Unresolved local var: wchar_t id@[???] */
    lVar4 = __isoc23_strtol(str,(char **)0x0,10);
    local_74 = (int)lVar4 + L'\x01';
    if (L'\xffffffff' < local_74) {
      if (local_74 < L'\x84') {
        if (Process_fields[local_74].name != (char *)0x0) goto LAB_0012d68a;
      }
      else {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pHVar10 = columns->buckets;
        uVar8 = (ulong)(long)local_74 % columns->size;
        pHVar6 = pHVar10 + uVar8;
        if (pHVar6->value != (void *)0x0) {
          uVar7 = 0;
          do {
            if (local_74 == pHVar6->key) goto LAB_0012d68a;
            if (pHVar6->probe < uVar7) break;
            uVar8 = uVar8 + 1;
            if (columns->size == uVar8) {
              uVar8 = 0;
              pHVar6 = pHVar10;
            }
            else {
              pHVar6 = pHVar10 + uVar8;
            }
            uVar7 = uVar7 + 1;
          } while (pHVar6->value != (void *)0x0);
        }
      }
    }
  }
  local_74 = L'\xffffffff';
LAB_0012d68a:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_74;
}

