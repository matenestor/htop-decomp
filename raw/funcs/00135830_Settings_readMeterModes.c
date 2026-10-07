/* Settings_readMeterModes @ 00135830 size 435 */

/* DWARF original prototype: void Settings_readMeterModes(Settings * this, char * line, uint column)
    */

void Settings_readMeterModes(Settings *this,char *line,uint column)

{
  size_t sVar1;
  char *pcVar2;
  char **__ptr;
  size_t __nmemb;
  undefined4 *puVar3;
  long lVar4;
  ulong uVar5;
  undefined4 *puVar6;
  char **ppcVar7;
  long local_48;

                    /* Unresolved local var: char * trim@[???]
                       Unresolved local var: char * * ids@[???]
                       Unresolved local var: wchar_t len@[???]
                       Unresolved local var: wchar_t * modes@[???] */
  pcVar2 = String_trim(line);
  __ptr = String_split(pcVar2,' ',(size_t *)0x0);
  free(pcVar2);
                    /* Unresolved local var: wchar_t i@[???] */
  uVar5 = (ulong)column;
  if (*__ptr == (char *)0x0) {
    puVar3 = (undefined4 *)0x0;
    if (uVar5 < (ulong)HeaderLayout_layouts[this->hLayout].columns - 1) {
      local_48 = uVar5 * 0x18;
      this->hColumns[uVar5].len = 0;
    }
    else {
      uVar5 = (ulong)(HeaderLayout_layouts[this->hLayout].columns - 1);
      local_48 = uVar5 * 0x18;
      this->hColumns[uVar5].len = 0;
    }
  }
  else {
    sVar1 = 1;
    do {
      __nmemb = sVar1;
      sVar1 = __nmemb + 1;
    } while (__ptr[__nmemb] != (char *)0x0);
    if ((ulong)HeaderLayout_layouts[this->hLayout].columns - 1 <= uVar5) {
      uVar5 = (ulong)(HeaderLayout_layouts[this->hLayout].columns - 1);
    }
                    /* Unresolved local var: void * data@[???] */
    local_48 = uVar5 * 0x18;
    this->hColumns[uVar5].len = __nmemb;
    puVar3 = calloc(__nmemb,4);
    if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    puVar6 = puVar3;
    ppcVar7 = __ptr;
    do {
                    /* Unresolved local var: wchar_t i@[???] */
      pcVar2 = *ppcVar7;
      ppcVar7 = ppcVar7 + 1;
      lVar4 = __isoc23_strtol(pcVar2,(char **)0x0,10);
      *puVar6 = (int)lVar4;
      puVar6 = puVar6 + 1;
    } while (ppcVar7 != __ptr + (int)__nmemb);
                    /* Unresolved local var: size_t i@[???] */
    pcVar2 = *__ptr;
    ppcVar7 = __ptr;
    while (pcVar2 != (char *)0x0) {
      ppcVar7 = ppcVar7 + 1;
      free(pcVar2);
      pcVar2 = *ppcVar7;
    }
  }
  free(__ptr);
  *(undefined4 **)((long)&this->hColumns->modes + local_48) = puVar3;
  return;
}

