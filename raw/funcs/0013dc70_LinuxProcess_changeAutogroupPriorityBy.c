/* LinuxProcess_changeAutogroupPriorityBy @ 0013dc70 size 243 */

_Bool LinuxProcess_changeAutogroupPriorityBy(Process_3 *p,Arg delta)

{
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  bool bVar3;
  long in_FS_OFFSET;
  wchar_t nice;
  long identity;
  char buffer [256];

                    /* Unresolved local var: pid_t pid@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: wchar_t ok@[???]
                       Unresolved local var: _Bool success@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf(buffer,0x100,((char *)0x149b8d /* "/proc/%d/autogroup" */),(int)p);
  __stream = fopen(buffer,((char *)0x149ba0 /* "r+" */));
  if (__stream == (FILE_2 *)0x0) {
    bVar3 = false;
    goto LAB_0013dcf9;
  }
  iVar2 = __isoc23_fscanf(__stream,((char *)0x149ba3 /* "/autogroup-%ld nice %d" */),&identity,&nice);
  if (iVar2 == 2) {
    iVar2 = fseek(__stream,0,0);
    if (iVar2 != 0) goto LAB_0013dcee;
    xSnprintf(buffer,0x100,((char *)0x149710 /* "%d" */),nice + delta.i);
    iVar2 = fputs(buffer,__stream);
    bVar3 = 0 < iVar2;
  }
  else {
LAB_0013dcee:
    bVar3 = false;
  }
  fclose(__stream);
LAB_0013dcf9:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

