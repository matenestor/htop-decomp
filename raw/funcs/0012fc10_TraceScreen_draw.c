/* TraceScreen_draw @ 0012fc10 size 65 */

/* DWARF original prototype: void TraceScreen_draw(InfoScreen * this) */

void TraceScreen_draw(InfoScreen *this)

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
  InfoScreen_drawTitled(this,((char *)0x148ff0 /* "Trace of process %d - %s" */),(pPVar1->super).id,va1);
  return;
}

