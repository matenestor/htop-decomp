/* ProcessTable_delete @ 00143d00 size 164 */

void ProcessTable_delete(LinuxProcessTable_ *cast)

{
  Hashtable *this;
  TtyDriver *__ptr;
  long lVar1;
  char *__ptr_00;

  this = (cast->super).super.table;
  Hashtable_clear(this);
  free(this->buckets);
  free(this);
  Vector_delete((cast->super).super.displayList);
  Vector_delete((cast->super).super.rows);
  __ptr = cast->ttyDrivers;
  if (__ptr != (TtyDriver *)0x0) {
                    /* Unresolved local var: wchar_t i@[???] */
    __ptr_00 = __ptr->path;
    if (__ptr_00 != (char *)0x0) {
      lVar1 = 0x18;
      do {
        free(__ptr_00);
        __ptr = cast->ttyDrivers;
        __ptr_00 = *(char **)((long)&__ptr->path + lVar1);
        lVar1 = lVar1 + 0x18;
      } while (__ptr_00 != (char *)0x0);
    }
    free(__ptr);
  }
  if (cast->netlink_socket != (nl_sock *)0x0) {
    nl_close(cast->netlink_socket);
    nl_socket_free(cast->netlink_socket);
  }
  free(cast);
  return;
}

