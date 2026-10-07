/* Process_rowIsVisible @ 0011fc20 size 39 */

_Bool Process_rowIsVisible(Process_ *super,Table_4 *table)

{
  _Bool _Var1;

  _Var1 = true;
                    /* Unresolved local var: Process * this@[???] */
  if ((table->host->settings->hideUserlandThreads != false) &&
     (_Var1 = false, super->isUserlandThread == false)) {
    return (_Bool)(super->isKernelThread ^ 1);
  }
  return _Var1;
}

