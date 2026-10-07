/* Settings_initScreenSettings @ 00135b80 size 111 */

ScreenSettings_4 * Settings_initScreenSettings(ScreenSettings_4 *ss,Settings_3 *this,char *columns)

{
  uint uVar1;
  ScreenSettings_4 **__ptr;
  ScreenSettings_4 **ppSVar2;

  ScreenSettings_readFields(ss,this->dynamicColumns,columns);
  uVar1 = this->nScreens;
  __ptr = this->screens;
  __ptr[uVar1] = ss;
                    /* Unresolved local var: void * data@[???] */
  this->nScreens = uVar1 + 1;
  ppSVar2 = realloc(__ptr,(ulong)(uVar1 + 2) << 3);
  if (ppSVar2 != (ScreenSettings_4 **)0x0) {
    this->screens = ppSVar2;
    ppSVar2[this->nScreens] = (ScreenSettings_4 *)0x0;
    return ss;
  }
  free(__ptr);
                    /* WARNING: Subroutine does not return */
  fail();
}

