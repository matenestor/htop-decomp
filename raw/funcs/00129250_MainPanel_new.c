/* MainPanel_new @ 00129250 size 321 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

MainPanel * MainPanel_new(void)

{
  MainPanel *this;
  FunctionBar *pFVar1;
  Htop_Action *pp_Var2;
  IncSet_3 *pIVar3;
  bool bVar4;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(10000);
  if (this != (MainPanel *)0x0) {
    (this->super).super.klass = &MainPanel_class.super;
    pFVar1 = FunctionBar_new(MainFunctions,(char **)0x0,(wchar_t *)0x0);
    this->processBar = pFVar1;
    pFVar1 = FunctionBar_new(MainFunctions_ro,(char **)0x0,(wchar_t *)0x0);
    bVar4 = readonly == false;
    this->readonlyBar = pFVar1;
    if (bVar4) {
      pFVar1 = this->processBar;
    }
    Panel_init(&this->super,L'\x01',L'\x01',L'\x01',L'\x01',&Row_class.super,false,pFVar1);
                    /* Unresolved local var: void * data@[???] */
    pp_Var2 = calloc(0x1ff,8);
    if (pp_Var2 != (Htop_Action *)0x0) {
      this->keys = pp_Var2;
      pIVar3 = IncSet_new(pFVar1);
      this->inc = (IncSet_2 *)pIVar3;
      Action_setBindings(this->keys);
      pp_Var2 = this->keys;
      pp_Var2[0x69] = Platform_actionSetIOPriority;
      pp_Var2[0x7b] = Platform_actionLowerAutogroupPriority;
      pp_Var2[0x7d] = Platform_actionHigherAutogroupPriority;
      pp_Var2[0x11b] = Platform_actionLowerAutogroupPriority;
      pp_Var2[0x11c] = Platform_actionHigherAutogroupPriority;
      return this;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

