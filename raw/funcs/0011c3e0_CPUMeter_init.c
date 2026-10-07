/* CPUMeter_init @ 0011c3e0 size 225 */

/* DWARF original prototype: void CPUMeter_init(Meter * this) */

void CPUMeter_init(Meter *this)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  char caption [10];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (this->param == 0) {
                    /* Unresolved local var: uint cpu@[???]
                       Unresolved local var: Machine * host@[???] */
    pcVar3 = this->caption;
    if ((pcVar3 != (char *)0x0) && (iVar2 = strcmp(pcVar3,((char *)0x147497 /* "Avg" */)), iVar2 == 0)) goto LAB_0011c469;
    free(pcVar3);
                    /* Unresolved local var: char * data@[???] */
    pcVar3 = strdup(((char *)0x147497 /* "Avg" */));
  }
  else {
    if (this->host->activeCPUs < 2) goto LAB_0011c469;
    xSnprintf(caption,10,((char *)0x14749b /* "%3u" */),this->param - (uint)(this->host->settings->countCPUsFromOne == false)
             );
    pcVar3 = this->caption;
    if ((pcVar3 != (char *)0x0) && (iVar2 = strcmp(pcVar3,caption), iVar2 == 0)) goto LAB_0011c469;
    free(pcVar3);
                    /* Unresolved local var: char * data@[???] */
    pcVar3 = strdup(caption);
  }
  if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  this->caption = pcVar3;
LAB_0011c469:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

