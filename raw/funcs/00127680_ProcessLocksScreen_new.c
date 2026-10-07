/* ProcessLocksScreen_new @ 00127680 size 106 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ProcessLocksScreen * ProcessLocksScreen_new(Process_2 *process)

{
  _Bool _Var1;
  wchar_t wVar2;
  InfoScreen *this;
  ProcessLocksScreen *pPVar3;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(0x30);
  if (this != (InfoScreen *)0x0) {
    _Var1 = process->isUserlandThread;
    (this->super).klass = &ProcessLocksScreen_class.super;
    if ((_Var1 == false) && (process->isKernelThread == false)) {
      wVar2 = (process->super).id;
    }
    else {
      wVar2 = (process->super).group;
    }
    *(wchar_t *)&this[1].super.klass = wVar2;
    pPVar3 = (ProcessLocksScreen *)
             InfoScreen_init(this,(Process *)process,(FunctionBar *)0x0,_LINES + L'\xfffffffe',
                             ((char *)0x14c428 /* "   FD TYPE       EXCLUSION  READ/WRITE DEVICE       NODE               START                 END  FILENAME" */)
                            );
    return pPVar3;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

