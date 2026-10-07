/* Process_rowIsHighlighted @ 0011fc00 size 32 */

_Bool Process_rowIsHighlighted(Process_ *super)

{
  Machine_ *pMVar1;
  _Bool _Var2;

                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???] */
  pMVar1 = (super->super).host;
  _Var2 = false;
  if (pMVar1->settings->shadowOtherUsers != false) {
    _Var2 = super->st_uid != pMVar1->htopUserId;
  }
  return _Var2;
}

