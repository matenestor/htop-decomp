/* OpenFilesScreen_new @ 00127610 size 111 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

OpenFilesScreen * OpenFilesScreen_new(Process *process)

{
  _Bool _Var1;
  wchar_t wVar2;
  InfoScreen *this;
  OpenFilesScreen *pOVar3;

                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x30);
  if (this != (InfoScreen *)0x0) {
    _Var1 = process->isUserlandThread;
    (this->super).klass = &OpenFilesScreen_class.super;
    if ((_Var1 == false) && (process->isKernelThread == false)) {
      wVar2 = (process->super).id;
    }
    else {
      wVar2 = (process->super).group;
    }
    *(wchar_t *)&this[1].super.klass = wVar2;
    pOVar3 = (OpenFilesScreen *)
             InfoScreen_init(this,process,(FunctionBar *)0x0,_LINES + L'\xfffffffe',
                             ((char *)0x14c3e0 /* "   FD TYPE    MODE DEVICE           SIZE     OFFSET       NODE  NAME" */))
    ;
    return pOVar3;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

