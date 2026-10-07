/* MainPanel_setFunctionBar @ 00121430 size 41 */

/* DWARF original prototype: void MainPanel_setFunctionBar(MainPanel * this, _Bool readonly) */

void MainPanel_setFunctionBar(MainPanel *this,_Bool readonly)

{
  IncSet_2 *pIVar1;
  FunctionBar *pFVar2;

  pIVar1 = this->inc;
  pFVar2 = this->readonlyBar;
  if (!readonly) {
    pFVar2 = this->processBar;
  }
  (this->super).defaultBar = pFVar2;
  pIVar1->defaultBar = pFVar2;
  return;
}

