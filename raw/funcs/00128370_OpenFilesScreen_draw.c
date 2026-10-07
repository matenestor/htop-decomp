/* OpenFilesScreen_draw @ 00128370 size 65 */

/* DWARF original prototype: void OpenFilesScreen_draw(InfoScreen * this) */

void OpenFilesScreen_draw(InfoScreen *this)

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
            (this,((char *)0x14c498 /* "Snapshot of files open in process %d - %s" */),*(int *)&this[1].super.klass,va1);
  return;
}

