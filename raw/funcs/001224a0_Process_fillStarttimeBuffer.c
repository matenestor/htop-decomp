/* Process_fillStarttimeBuffer @ 001224a0 size 169 */

/* DWARF original prototype: void Process_fillStarttimeBuffer(Process * this) */

void Process_fillStarttimeBuffer(Process *this)

{
  long lVar1;
  long lVar2;
  char *__format;
  long in_FS_OFFSET;
  tm date;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = (((this->super).host)->realtime).tv_sec;
  localtime_r(&this->starttime_ctime,(tm_2 *)&date);
  __format = ((char *)0x14876e /* "%R " */);
  if ((this->starttime_ctime < lVar2 + -0x1517f) &&
     (__format = ((char *)0x148778 /* " %Y " */), lVar2 + -0x1dfe1ff <= this->starttime_ctime)) {
    __format = ((char *)0x148772 /* "%b%d " */);
  }
  strftime(this->starttime_show,7,__format,(tm_2 *)&date);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

