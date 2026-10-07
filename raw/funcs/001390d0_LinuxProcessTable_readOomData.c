/* LinuxProcessTable_readOomData @ 001390d0 size 235 */

void LinuxProcessTable_readOomData(LinuxProcess *process,openat_arg_t procFd)

{
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  char *pcVar3;
  long in_FS_OFFSET;
  uint oom;
  char buffer [4097];

                    /* Unresolved local var: FILE * file@[???] */
                    /* Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = openat(procFd,((char *)0x149790 /* "oom_score" */),0);
  if (-1 < iVar2) {
    __stream = fdopen(iVar2,((char *)0x147760 /* "r" */));
    if (__stream == (FILE_2 *)0x0) {
      if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
        close(iVar2);
        return;
      }
      goto LAB_00139192;
    }
                    /* Unresolved local var: size_t sz@[???] */
    pcVar3 = fgets(buffer,0x1000,__stream);
    if (pcVar3 != (char *)0x0) {
                    /* Unresolved local var: wchar_t ok@[???] */
      iVar2 = __isoc23_sscanf(buffer,((char *)0x1474a2 /* "%u" */),&oom);
      if (0 < iVar2) {
        process->oom = oom;
      }
    }
    fclose(__stream);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00139192:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

