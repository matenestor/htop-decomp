/* LinuxProcessTable_readSecattrData @ 0013f230 size 342 */

void LinuxProcessTable_readSecattrData(LinuxProcess *process,openat_arg_t procFd)

{
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  char *pcVar3;
  size_t sVar4;
  long in_FS_OFFSET;
  char buffer [4097];

                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: char * res@[???]
                       Unresolved local var: char * newline@[???] */
                    /* Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = openat(procFd,((char *)0x149bd3 /* "attr/current" */),0);
  if (-1 < iVar2) {
    __stream = fdopen(iVar2,((char *)0x147760 /* "r" */));
    if (__stream == (FILE_2 *)0x0) {
      close(iVar2);
    }
    else {
                    /* Unresolved local var: size_t sz@[???] */
      pcVar3 = fgets(buffer,0x1001,__stream);
      fclose(__stream);
      if (pcVar3 != (char *)0x0) {
        pcVar3 = strchr(buffer,10);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        sVar4 = strlen(buffer);
        if (sVar4 < 0x100) {
          if (Row_fieldWidths[0x7b] < sVar4) {
            Row_fieldWidths[0x7b] = (uint8_t)sVar4;
          }
        }
        else {
          Row_fieldWidths[0x7b] = 0xff;
        }
        pcVar3 = process->secattr;
        if (pcVar3 != (char *)0x0) {
          iVar2 = strcmp(pcVar3,buffer);
          if (iVar2 == 0) goto LAB_0013f32c;
        }
        free(pcVar3);
                    /* Unresolved local var: char * data@[???] */
        pcVar3 = strdup(buffer);
        if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
          fail();
        }
        process->secattr = pcVar3;
        goto LAB_0013f32c;
      }
    }
  }
  free(process->secattr);
  process->secattr = (char *)0x0;
LAB_0013f32c:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

