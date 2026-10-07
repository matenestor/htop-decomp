/* Meter_setCaption @ 00123750 size 85 */

/* DWARF original prototype: void Meter_setCaption(Meter * this, char * caption) */

void Meter_setCaption(Meter *this,char *caption)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = this->caption;
  if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,caption), iVar1 == 0)) {
    return;
  }
  free(pcVar2);
                    /* Unresolved local var: char * data@[???] */
  pcVar2 = strdup(caption);
  if (pcVar2 != (char *)0x0) {
    this->caption = pcVar2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

