/* Machine_new @ 00142dd0 size 401 */

Machine_2 * Machine_new(UsersTable *usersTable,uid_t userId)

{
  long lVar1;
  wchar_t wVar2;
  int iVar3;
  LinuxMachine *this;
  long lVar4;
  FILE_2 *__stream;
  char *pcVar5;
  long in_FS_OFFSET;
  char buffer [4097];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x238);
  if (this == (LinuxMachine *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  Machine_init((Machine *)this,usersTable,userId);
  lVar4 = sysconf(0x1e);
  wVar2 = (wchar_t)lVar4;
  this->pageSize = wVar2;
  if (wVar2 == L'\xffffffff') {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x14cce8 /* "Cannot get pagesize by sysconf(_SC_PAGESIZE)" */));
  }
  this->pageSizeKB = (wchar_t)((ulong)(long)wVar2 >> 10);
  lVar4 = sysconf(2);
  this->jiffies = lVar4;
  if (lVar4 == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x14cd18 /* "Cannot get clock ticks by sysconf(_SC_CLK_TCK)" */));
  }
  __stream = fopen(((char *)0x149e71 /* "/proc/stat" */),((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x149e65 /* "Cannot open /proc/stat" */));
  }
  this->boottime = -1;
  do {
                    /* Unresolved local var: size_t sz@[???] */
    pcVar5 = fgets(buffer,0x1001,__stream);
    if (pcVar5 == (char *)0x0) goto LAB_00142ee1;
  } while ((buffer._0_4_ != 0x6d697462) || (buffer._4_2_ != 0x2065));
  iVar3 = __isoc23_sscanf(buffer,((char *)0x14a024 /* "btime %lld\n" */),&this->boottime);
  if (iVar3 != 1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x14cd48 /* "Failed to parse btime from /proc/stat" */));
  }
LAB_00142ee1:
  fclose(__stream);
  if (this->boottime == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x14a030 /* "No btime in /proc/stat" */));
  }
  LinuxMachine_updateCPUcount(this);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (Machine_2 *)this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

