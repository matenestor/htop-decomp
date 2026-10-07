/* Process_rowMatchesFilter @ 00128410 size 543 */

_Bool Process_rowMatchesFilter(Process_ *super,Table_4 *table)

{
  uid_t uVar1;
  wchar_t wVar2;
  Machine__4 *pMVar3;
  ObjectClass *pOVar4;
  Object_Display p_Var5;
  _Bool _Var6;
  char *pcVar7;
  char **__ptr;
  char *pcVar8;
  Object_Display p_Var9;
  ulong uVar10;
  void *pvVar11;
  char *__haystack;
  char **ppcVar12;
  size_t sVar13;
  long in_FS_OFFSET;
  size_t nNeedles;
  long local_40;

                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: char * incFilter@[???]
                       Unresolved local var: ProcessTable * pt@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pMVar3 = table->host;
  uVar1 = pMVar3->userId;
  if ((uVar1 == 0xffffffff) || (uVar1 == super->st_uid)) {
    pcVar8 = table->incFilter;
    if (pcVar8 == (char *)0x0) {
LAB_00128538:
      pOVar4 = pMVar3->activeTable[1].super.klass;
      _Var6 = false;
      if (pOVar4 == (ObjectClass *)0x0) goto LAB_00128452;
      wVar2 = (super->super).group;
      p_Var5 = pOVar4->display;
      pvVar11 = (void *)((ulong)(uint)wVar2 % (ulong)pOVar4->extends);
      p_Var9 = p_Var5 + (long)pvVar11 * 0x18;
      if (*(long *)(p_Var9 + 0x10) != 0) {
        uVar10 = 0;
        do {
          if (wVar2 == *(wchar_t *)p_Var9) {
            _Var6 = false;
            goto LAB_00128452;
          }
          if (*(ulong *)(p_Var9 + 8) < uVar10) break;
          pvVar11 = (void *)((long)pvVar11 + 1);
          if (pOVar4->extends == pvVar11) {
            pvVar11 = (void *)0x0;
            p_Var9 = p_Var5;
          }
          else {
            p_Var9 = p_Var5 + (long)pvVar11 * 0x18;
          }
          uVar10 = uVar10 + 1;
        } while (*(long *)(p_Var9 + 0x10) != 0);
      }
    }
    else {
                    /* Unresolved local var: Settings * settings@[???] */
      if (((super->isUserlandThread != false) &&
          (((super->super).host)->settings->showThreadNames != false)) ||
         (__haystack = (super->mergedCommand).str, __haystack == (char *)0x0)) {
        __haystack = super->cmdline;
      }
      pcVar7 = strchr(pcVar8,0x7c);
      if (pcVar7 == (char *)0x0) {
        pcVar8 = strcasestr(__haystack,pcVar8);
        if (pcVar8 != (char *)0x0) goto LAB_00128538;
      }
      else {
                    /* Unresolved local var: char * * needles@[???] */
        __ptr = String_split(pcVar8,'|',&nNeedles);
                    /* Unresolved local var: size_t i@[???] */
        if (nNeedles != 0) {
          sVar13 = 0;
LAB_001284f5:
          pcVar8 = strcasestr(__haystack,__ptr[sVar13]);
          if (pcVar8 == (char *)0x0) goto LAB_001284e8;
                    /* Unresolved local var: size_t i@[???] */
          pcVar8 = *__ptr;
          ppcVar12 = __ptr;
          while (pcVar8 != (char *)0x0) {
            ppcVar12 = ppcVar12 + 1;
            free(pcVar8);
            pcVar8 = *ppcVar12;
          }
          free(__ptr);
          goto LAB_00128538;
        }
        if (__ptr != (char **)0x0) {
LAB_00128608:
                    /* Unresolved local var: size_t i@[???] */
          pcVar8 = *__ptr;
          ppcVar12 = __ptr;
          while (pcVar8 != (char *)0x0) {
            ppcVar12 = ppcVar12 + 1;
            free(pcVar8);
            pcVar8 = *ppcVar12;
          }
          free(__ptr);
          _Var6 = true;
          goto LAB_00128452;
        }
      }
    }
  }
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  _Var6 = true;
LAB_00128452:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var6;
LAB_001284e8:
  sVar13 = sVar13 + 1;
  if (sVar13 == nNeedles) goto LAB_00128608;
  goto LAB_001284f5;
}

