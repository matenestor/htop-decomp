/* Machine_init @ 00129090 size 206 */

/* DWARF original prototype: void Machine_init(Machine * this, UsersTable * usersTable, uid_t
   userId) */

void Machine_init(Machine *this,UsersTable *usersTable,uid_t userId)

{
  __uid_t _Var1;
  wchar_t wVar2;
  FILE_2 *__stream;
  long in_FS_OFFSET;
  double dVar3;
  pid_t maxPid;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  this->usersTable = usersTable;
  this->userId = userId;
  _Var1 = getuid();
                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: wchar_t match@[???] */
  maxPid = 0x3fffff;
  this->htopUserId = _Var1;
  __stream = fopen(((char *)0x148869 /* "/proc/sys/kernel/pid_max" */),((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    __isoc23_fscanf(__stream,((char *)0x14978b /* "%32d" */),&maxPid);
    fclose(__stream);
  }
  wVar2 = L'\x05';
  if (99999 < maxPid) {
    dVar3 = log10((double)maxPid);
    wVar2 = (int)dVar3 + L'\x01';
  }
  Row_pidDigits = wVar2;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    Generic_gettime_realtime(&this->realtime,&this->realtimeMs);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

