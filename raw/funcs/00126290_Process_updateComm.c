/* Process_updateComm @ 00126290 size 129 */

/* DWARF original prototype: void Process_updateComm(Process * this, char * comm) */

void Process_updateComm(Process *this,char *comm)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = this->procComm;
  if (pcVar2 == (char *)0x0) {
    if (comm == (char *)0x0) {
      return;
    }
  }
  else {
    if (comm == (char *)0x0) {
      free(pcVar2);
      pcVar2 = (char *)0x0;
      goto LAB_001262dc;
    }
    iVar1 = strcmp(pcVar2,comm);
    if (iVar1 == 0) {
      return;
    }
    free(pcVar2);
  }
                    /* Unresolved local var: char * data@[???] */
  pcVar2 = strdup(comm);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
LAB_001262dc:
  this->procComm = pcVar2;
  (this->mergedCommand).lastUpdate = 0;
  return;
}

