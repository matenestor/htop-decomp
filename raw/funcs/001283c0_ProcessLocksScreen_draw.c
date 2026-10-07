/* ProcessLocksScreen_draw @ 001283c0 size 65 */

/* DWARF original prototype: void ProcessLocksScreen_draw(InfoScreen * this) */

void ProcessLocksScreen_draw(InfoScreen *this)

{
  Process *pPVar1;
  char *va1;

  pPVar1 = this->process;
                    /* Unresolved local var: Settings * settings@[???] */
  if (((pPVar1->isUserlandThread != false) &&
      (((pPVar1->super).host)->settings->showThreadNames != false)) ||
     (va1 = (pPVar1->mergedCommand).str, va1 == (char *)0x0)) {
    va1 = pPVar1->cmdline;
  }
  InfoScreen_drawTitled
            (this,((char *)0x14c4c8 /* "Snapshot of file locks of process %d - %s" */),*(int *)&this[1].super.klass,va1);
  return;
}

