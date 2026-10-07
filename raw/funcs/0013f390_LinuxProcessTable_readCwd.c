/* LinuxProcessTable_readCwd @ 0013f390 size 226 */

void LinuxProcessTable_readCwd(LinuxProcess *process,openat_arg_t procFd)

{
  long lVar1;
  int iVar2;
  ssize_t sVar3;
  char *pcVar4;
  long lVar5;
  long in_FS_OFFSET;
  char pathBuffer [4097];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar4 = pathBuffer;
                    /* Unresolved local var: ssize_t r@[???] */
  for (lVar5 = 0x200; lVar5 != 0; lVar5 = lVar5 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  *pcVar4 = '\0';
  sVar3 = readlinkat(procFd,((char *)0x149be0 /* "cwd" */),pathBuffer,0x1000);
  if (sVar3 < 0) {
    free((process->super).procCwd);
    (process->super).procCwd = (char *)0x0;
  }
  else {
    pcVar4 = (process->super).procCwd;
    pathBuffer[sVar3] = '\0';
    if (pcVar4 != (char *)0x0) {
      iVar2 = strcmp(pcVar4,pathBuffer);
      if (iVar2 == 0) goto LAB_0013f432;
    }
    free(pcVar4);
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup(pathBuffer);
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (process->super).procCwd = pcVar4;
  }
LAB_0013f432:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

