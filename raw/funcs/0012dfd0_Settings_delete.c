/* Settings_delete @ 0012dfd0 size 290 */

/* DWARF original prototype: void Settings_delete(Settings * this) */

void Settings_delete(Settings *this)

{
  char **__ptr;
  char *__ptr_00;
  MeterColumnSetting *pMVar1;
  ulong uVar2;
  long lVar3;
  ScreenSettings_5 *__ptr_01;
  ScreenSettings_5 **__ptr_02;
  char **ppcVar4;

  lVar3 = 0;
  free(this->filename);
                    /* Unresolved local var: uint i@[???] */
  if (HeaderLayout_layouts[this->hLayout].columns != '\0') {
    do {
      pMVar1 = this->hColumns + lVar3;
      __ptr = pMVar1->names;
      if (__ptr != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
        __ptr_00 = *__ptr;
        ppcVar4 = __ptr;
        while (__ptr_00 != (char *)0x0) {
          ppcVar4 = ppcVar4 + 1;
          free(__ptr_00);
          __ptr_00 = *ppcVar4;
        }
        free(__ptr);
        pMVar1 = this->hColumns + lVar3;
      }
      lVar3 = lVar3 + 1;
      free(pMVar1->modes);
    } while ((uint)lVar3 < (uint)HeaderLayout_layouts[this->hLayout].columns);
  }
  free(this->hColumns);
  __ptr_02 = this->screens;
  if (__ptr_02 != (ScreenSettings_5 **)0x0) {
                    /* Unresolved local var: uint i@[???] */
    __ptr_01 = *__ptr_02;
    if (__ptr_01 != (ScreenSettings_5 *)0x0) {
      uVar2 = 0;
      do {
        free(__ptr_01->heading);
        free(__ptr_01->dynamic);
        free(__ptr_01->fields);
        free(__ptr_01);
        __ptr_02 = this->screens;
        uVar2 = (ulong)((int)uVar2 + 1);
        __ptr_01 = __ptr_02[uVar2];
      } while (__ptr_01 != (ScreenSettings_5 *)0x0);
    }
    free(__ptr_02);
  }
  free(this);
  return;
}

