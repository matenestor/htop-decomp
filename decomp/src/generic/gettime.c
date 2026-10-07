#include "htop.h"

/* Generic_gettime_realtime @ 0x13add0 */

void Generic_gettime_realtime(timeval *tvp,uint64_t *msec)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = clock_gettime(0,(timespec_2 *)&(*(timespec (*))(__fp - 0x38)));
  if (iVar2 == 0) {
    tvp->tv_sec = (*(timespec (*))(__fp - 0x38)).tv_sec;
    tvp->tv_usec = (*(timespec (*))(__fp - 0x38)).tv_nsec / 1000;
    uVar3 = (*(timespec (*))(__fp - 0x38)).tv_sec * 1000 + (ulong)(*(timespec (*))(__fp - 0x38)).tv_nsec / 1000000;
  }
  else {
                    /* Unresolved local var: timespec (*(timespec (*))(__fp - 0x38))@[???] */
    uVar3 = 0;
    tvp->tv_sec = 0;
    tvp->tv_usec = 0;
  }
  *msec = uVar3;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Generic_gettime_monotonic @ 0x13ae90 */

void Generic_gettime_monotonic(uint64_t *msec)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = clock_gettime(1,(timespec_2 *)&(*(timespec (*))(__fp - 0x38)));
  uVar3 = 0;
  if (iVar2 == 0) {
    uVar3 = (ulong)(*(timespec (*))(__fp - 0x38)).tv_nsec / 1000000 + (*(timespec (*))(__fp - 0x38)).tv_sec * 1000;
  }
  *msec = uVar3;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

