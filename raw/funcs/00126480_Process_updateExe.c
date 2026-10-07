/* Process_updateExe @ 00126480 size 192 */

/* DWARF original prototype: void Process_updateExe(Process * this, char * exe) */

void Process_updateExe(Process *this,char *exe)

{
  int iVar1;
  char *pcVar2;
  wchar_t wVar3;

  pcVar2 = this->procExe;
  if (pcVar2 == (char *)0x0) {
    if (exe == (char *)0x0) {
      return;
    }
  }
  else {
    if (exe == (char *)0x0) {
      free(pcVar2);
      wVar3 = L'\0';
      this->procExe = (char *)0x0;
      goto LAB_00126515;
    }
    iVar1 = strcmp(pcVar2,exe);
    if (iVar1 == 0) {
      return;
    }
    free(pcVar2);
  }
                    /* Unresolved local var: char * lastSlash@[???]
                       Unresolved local var: char * data@[???] */
  pcVar2 = strdup(exe);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  this->procExe = pcVar2;
  pcVar2 = strrchr(exe,0x2f);
  wVar3 = L'\0';
  if (pcVar2 != (char *)0x0) {
    if ((pcVar2[1] == '\0') || (exe == pcVar2)) {
      wVar3 = L'\0';
    }
    else {
      wVar3 = ((int)pcVar2 - (int)exe) + L'\x01';
    }
  }
LAB_00126515:
  this->procExeBasenameOffset = wVar3;
  (this->mergedCommand).lastUpdate = 0;
  return;
}

