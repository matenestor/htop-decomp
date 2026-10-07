/* MainPanel_foreachRow @ 00121350 size 195 */

/* DWARF original prototype: _Bool MainPanel_foreachRow(MainPanel * this, MainPanel_foreachRowFn fn,
   Arg arg, _Bool * wasAnyTagged) */

_Bool MainPanel_foreachRow(MainPanel *this,MainPanel_foreachRowFn fn,Arg arg,_Bool *wasAnyTagged)

{
  Row_3 *pRVar1;
  _Bool _Var2;
  _Bool _Var3;
  Vector *pVVar4;
  _Bool *a3;
  long lVar5;
  char cVar6;
  long in_R8;
  long in_R9;
  _Bool _Var7;

                    /* Unresolved local var: wchar_t i@[???] */
  pVVar4 = (this->super).items;
  if (pVVar4->items < L'\x01') {
    cVar6 = false;
    _Var7 = true;
  }
  else {
    lVar5 = 0;
    cVar6 = '\0';
    _Var7 = true;
    a3 = wasAnyTagged;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pRVar1 = (Row_3 *)pVVar4->array[lVar5];
      _Var3 = pRVar1->tag;
      if (_Var3 != false) {
        _Var2 = (*fn)(pRVar1,arg,(long)pVVar4->array,(long)a3,in_R8,in_R9);
        _Var7 = (_Bool)(_Var7 & _Var2);
        pVVar4 = (this->super).items;
        cVar6 = _Var3;
      }
      lVar5 = lVar5 + 1;
    } while ((wchar_t)lVar5 < pVVar4->items);
                    /* Unresolved local var: Row * row@[???] */
    if ((cVar6 != '\x01') && (L'\0' < pVVar4->items)) {
      lVar5 = (long)(this->super).selected;
      if ((Row_3 *)pVVar4->array[lVar5] == (Row_3 *)0x0) {
        cVar6 = false;
      }
      else {
        _Var3 = (*fn)((Row_3 *)pVVar4->array[lVar5],arg,lVar5,(long)a3,in_R8,in_R9);
        cVar6 = false;
        _Var7 = (_Bool)(_Var7 & _Var3);
      }
    }
  }
  if (wasAnyTagged != (_Bool *)0x0) {
    *wasAnyTagged = (_Bool)cVar6;
  }
  return _Var7;
}

