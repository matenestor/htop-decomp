/* Process_rowGetSortKey @ 0011fbd0 size 44 */

char * Process_rowGetSortKey(Process_ *super)

{
  char *pcVar1;

                    /* Unresolved local var: Settings * settings@[???] */
  if (((super->isUserlandThread == false) ||
      (((super->super).host)->settings->showThreadNames == false)) &&
     (pcVar1 = (super->mergedCommand).str, pcVar1 != (char *)0x0)) {
    return pcVar1;
  }
  return super->cmdline;
}

