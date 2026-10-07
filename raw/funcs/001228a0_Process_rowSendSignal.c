/* Process_rowSendSignal @ 001228a0 size 23 */

_Bool Process_rowSendSignal(Process_ *super,Arg sgn)

{
  int iVar1;

                    /* Unresolved local var: Process * this@[???] */
  iVar1 = kill((super->super).id,sgn.i);
  return iVar1 == 0;
}

