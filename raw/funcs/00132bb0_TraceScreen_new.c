/* TraceScreen_new @ 00132bb0 size 164 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TraceScreen * TraceScreen_new(Process *process)

{
  InfoScreen *this;
  FunctionBar *bar;
  TraceScreen *pTVar1;

                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x40);
  if (this != (InfoScreen *)0x0) {
    *(undefined1 *)&this[1].super.klass = 1;
    (this->super).klass = &TraceScreen_class.super;
    bar = FunctionBar_new(TraceScreenFunctions,TraceScreenKeys,((char *)0x14e140 /* L"ċČĐđ\x1b" */));
    nocbreak();
    cbreak();
    nodelay(_stdscr,1);
    pTVar1 = (TraceScreen *)InfoScreen_init(this,process,bar,_LINES + L'\xfffffffe',((char *)0x1470dd /* " " */));
    return pTVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

