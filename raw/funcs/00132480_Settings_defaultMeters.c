/* Settings_defaultMeters @ 00132480 size 1068 */

/* DWARF original prototype: void Settings_defaultMeters(Settings * this, uint initialCpuCount) */

void Settings_defaultMeters(Settings *this,uint initialCpuCount)

{
  MeterColumnSetting *pMVar1;
  char **ppcVar2;
  wchar_t *pwVar3;
  char *pcVar4;
  ulong uVar5;
  wchar_t *pwVar6;
  long lVar7;
  ulong __nmemb;
  char **ppcVar8;
  MeterColumnSetting *pMVar9;
  long in_FS_OFFSET;
  wchar_t sizes [2];
  long local_40 [2];

                    /* Unresolved local var: wchar_t r@[???] */
                    /* Unresolved local var: size_t i@[???] */
  local_40[0] = *(long *)(in_FS_OFFSET + 0x28);
  sizes[0] = L'\x03';
  uVar5 = 0;
  sizes[1] = (uint)(initialCpuCount - 5 < 0x7c) + L'\x03';
  if (HeaderLayout_layouts[this->hLayout].columns != '\0') {
    do {
      pMVar1 = this->hColumns + uVar5;
      ppcVar2 = pMVar1->names;
      if (ppcVar2 != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
        pcVar4 = *ppcVar2;
        ppcVar8 = ppcVar2;
        while (pcVar4 != (char *)0x0) {
          ppcVar8 = ppcVar8 + 1;
          free(pcVar4);
          pcVar4 = *ppcVar8;
        }
        free(ppcVar2);
        pMVar1 = this->hColumns + uVar5;
      }
      uVar5 = uVar5 + 1;
      free(pMVar1->modes);
    } while (uVar5 < HeaderLayout_layouts[this->hLayout].columns);
  }
  free(this->hColumns);
                    /* Unresolved local var: void * data@[???] */
  this->hLayout = HF_TWO_50_50;
  pMVar1 = calloc(2,0x18);
  if (pMVar1 == (MeterColumnSetting *)0x0) goto LAB_0013266f;
  this->hColumns = pMVar1;
                    /* Unresolved local var: size_t i@[???] */
  pwVar6 = sizes;
  pMVar9 = pMVar1;
  do {
                    /* Unresolved local var: void * data@[???] */
    __nmemb = (ulong)*pwVar6;
    uVar5 = (ulong)(*pwVar6 + L'\x01');
                    /* Unresolved local var: void * data@[???] */
    if ((((0x1fffffffffffffff < uVar5) || (ppcVar2 = calloc(uVar5,8), ppcVar2 == (char **)0x0)) ||
        (pMVar9->names = ppcVar2, 0x3fffffffffffffff < __nmemb)) ||
       (pwVar3 = calloc(__nmemb,4), pwVar3 == (wchar_t *)0x0)) goto LAB_0013266f;
    pMVar9->modes = pwVar3;
    pwVar6 = pwVar6 + 1;
    pMVar9->len = __nmemb;
    pMVar9 = pMVar9 + 1;
  } while (pwVar6 != (wchar_t *)local_40);
  ppcVar2 = pMVar1->names;
  if (initialCpuCount < 0x81) {
    if (initialCpuCount < 0x21) {
      if (initialCpuCount < 0x11) {
        if (initialCpuCount < 9) {
          if (initialCpuCount < 5) {
            pcVar4 = strdup(((char *)0x147a94 /* "AllCPUs" */));
            goto joined_r0x001327ef;
          }
                    /* Unresolved local var: char * data@[???] */
          pcVar4 = strdup(((char *)0x147ad2 /* "LeftCPUs" */));
          if (pcVar4 == (char *)0x0) goto LAB_0013266f;
          *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
          ppcVar2 = this->hColumns[1].names;
          *this->hColumns->modes = L'\x01';
          pcVar4 = strdup(((char *)0x147ae6 /* "RightCPUs" */));
        }
        else {
                    /* Unresolved local var: char * data@[???] */
          pcVar4 = strdup(((char *)0x147afb /* "LeftCPUs2" */));
          if (pcVar4 == (char *)0x0) goto LAB_0013266f;
          *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
          ppcVar2 = this->hColumns[1].names;
          *this->hColumns->modes = L'\x01';
          pcVar4 = strdup(((char *)0x147b12 /* "RightCPUs2" */));
        }
      }
      else {
                    /* Unresolved local var: char * data@[???] */
        pcVar4 = strdup(((char *)0x147b44 /* "LeftCPUs4" */));
        if (pcVar4 == (char *)0x0) goto LAB_0013266f;
        *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
        ppcVar2 = this->hColumns[1].names;
        *this->hColumns->modes = L'\x01';
        pcVar4 = strdup(((char *)0x147b5b /* "RightCPUs4" */));
      }
    }
    else {
                    /* Unresolved local var: char * data@[???] */
      pcVar4 = strdup(((char *)0x147b89 /* "LeftCPUs8" */));
      if (pcVar4 == (char *)0x0) goto LAB_0013266f;
      *ppcVar2 = pcVar4;
                    /* Unresolved local var: char * data@[???] */
      ppcVar2 = this->hColumns[1].names;
      *this->hColumns->modes = L'\x01';
      pcVar4 = strdup(((char *)0x147ba1 /* "RightCPUs8" */));
    }
    if (pcVar4 == (char *)0x0) goto LAB_0013266f;
    *ppcVar2 = pcVar4;
    pMVar1 = this->hColumns;
    lVar7 = 1;
    *pMVar1[1].modes = L'\x01';
  }
  else {
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup(((char *)0x147826 /* "CPU" */));
joined_r0x001327ef:
    if (pcVar4 == (char *)0x0) goto LAB_0013266f;
                    /* Unresolved local var: char * data@[???] */
    *ppcVar2 = pcVar4;
    pMVar1 = this->hColumns;
    lVar7 = 0;
    *pMVar1->modes = L'\x01';
  }
                    /* Unresolved local var: char * data@[???] */
  ppcVar2 = pMVar1->names;
  pcVar4 = strdup(((char *)0x1479d0 /* "Memory" */));
  if (pcVar4 != (char *)0x0) {
    ppcVar2[1] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
    ppcVar2 = this->hColumns->names;
    this->hColumns->modes[1] = L'\x01';
    pcVar4 = strdup(((char *)0x1479c7 /* "Swap" */));
    if (pcVar4 != (char *)0x0) {
      ppcVar2[2] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
      ppcVar2 = this->hColumns[1].names;
      this->hColumns->modes[2] = L'\x01';
      pcVar4 = strdup(((char *)0x147965 /* "Tasks" */));
      if (pcVar4 != (char *)0x0) {
        ppcVar2[lVar7] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
        ppcVar2 = this->hColumns[1].names;
        this->hColumns[1].modes[lVar7] = L'\x02';
        pcVar4 = strdup(((char *)0x1479db /* "LoadAverage" */));
        if (pcVar4 != (char *)0x0) {
          ppcVar2[lVar7 + 1] = pcVar4;
                    /* Unresolved local var: char * data@[???] */
          ppcVar2 = this->hColumns[1].names;
          this->hColumns[1].modes[lVar7 + 1] = L'\x02';
          pcVar4 = strdup(((char *)0x147955 /* "Uptime" */));
          if (pcVar4 != (char *)0x0) {
            ppcVar2[lVar7 + 2] = pcVar4;
            this->hColumns[1].modes[lVar7 + 2] = L'\x02';
            if (local_40[0] != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
            return;
          }
        }
      }
    }
  }
LAB_0013266f:
                    /* WARNING: Subroutine does not return */
  fail();
}

