/* Process_done @ 001227f0 size 90 */

/* DWARF original prototype: void Process_done(Process * this) */

void Process_done(Process *this)

{
  free(this->cmdline);
  free(this->procComm);
  free(this->procExe);
  free(this->procCwd);
  free((this->mergedCommand).str);
  free(this->tty_name);
  return;
}

