/* Process_updateCmdline @ 00126320 size 316 */

/* DWARF original prototype: void Process_updateCmdline(Process * this, char * cmdline, wchar_t
   basenameStart, wchar_t basenameEnd) */

void Process_updateCmdline(Process *this,char *cmdline,wchar_t basenameStart,wchar_t basenameEnd)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  wchar_t wVar4;
  char *pcVar5;

  pcVar5 = this->cmdline;
  if (pcVar5 == (char *)0x0) {
    if (cmdline == (char *)0x0) {
      return;
    }
LAB_00126372:
                    /* Unresolved local var: char * data@[???] */
    pcVar5 = strdup(cmdline);
    if (pcVar5 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->cmdline = pcVar5;
    if (this->isKernelThread == false) {
                    /* Unresolved local var: wchar_t slash@[???] */
                    /* Unresolved local var: wchar_t i@[???] */
      if (((basenameStart == L'\0') && (*cmdline == '/')) && (L'\x01' < basenameEnd)) {
        wVar4 = L'\x02';
        do {
          cVar1 = cmdline[1];
          if (cVar1 == '/') {
            if (cmdline[2] != '\0') {
              basenameStart = wVar4;
            }
          }
          else if (cVar1 == ' ') {
            if (*cmdline != '\\') break;
          }
          else if ((cVar1 == ':') && (cmdline[2] == ' ')) break;
          cmdline = cmdline + 1;
          bVar2 = wVar4 < basenameEnd;
          wVar4 = wVar4 + L'\x01';
        } while (bVar2);
      }
      goto LAB_001263e0;
    }
  }
  else {
    if (cmdline != (char *)0x0) {
      iVar3 = strcmp(pcVar5,cmdline);
      if (iVar3 == 0) {
        return;
      }
      free(pcVar5);
      goto LAB_00126372;
    }
    free(pcVar5);
    this->cmdline = (char *)0x0;
    if (this->isKernelThread == false) goto LAB_001263e0;
  }
  basenameStart = L'\0';
  basenameEnd = L'\0';
LAB_001263e0:
  this->cmdlineBasenameStart = basenameStart;
  this->cmdlineBasenameEnd = basenameEnd;
  (this->mergedCommand).lastUpdate = 0;
  return;
}

