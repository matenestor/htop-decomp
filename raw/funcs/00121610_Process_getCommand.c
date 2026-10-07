/* Process_getCommand @ 00121610 size 44 */

/* DWARF original prototype: char * Process_getCommand(Process * this) */

char * Process_getCommand(Process *this)

{
  char *pcVar1;

  if (((this->isUserlandThread == false) ||
      (((this->super).host)->settings->showThreadNames == false)) &&
     (pcVar1 = (this->mergedCommand).str, pcVar1 != (char *)0x0)) {
    return pcVar1;
  }
  return this->cmdline;
}

