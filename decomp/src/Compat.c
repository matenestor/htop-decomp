#include "htop.h"

/* Compat_faccessat @ 0x116080 */

int Compat_faccessat(int dirfd,char *pathname,int mode,int flags)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  long lVar1;
  int wVar2;
  int *piVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  piVar3 = __errno_location();
  *piVar3 = 0;
  wVar2 = faccessat(dirfd,pathname,mode,flags);
  if ((wVar2 != 0) && (*piVar3 == 0x16)) {
    if ((dirfd == -100) && (mode == 0)) {
      if (flags == 0) {
        wVar2 = stat(pathname,(stat_2 *)&(*(struct stat (*))(__fp - 0xd8)));
      }
      else {
        wVar2 = lstat(pathname,(stat_2 *)&(*(struct stat (*))(__fp - 0xd8)));
      }
    }
    else {
      wVar2 = -1;
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return wVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Compat_fstatat @ 0x116140 */

int Compat_fstatat(int dirfd,char *dirpath,char *pathname,struct stat *statbuf,int flags)

{
  int wVar1;

  wVar1 = fstatat(dirfd,pathname,(stat_2 *)statbuf,flags);
  return wVar1;
}


/* Compat_readlinkat @ 0x116160 */

ssize_t Compat_readlinkat(int dirfd,char *dirpath,char *pathname,char *buf,size_t bufsize)

{
  ssize_t sVar1;

  sVar1 = readlinkat(dirfd,pathname,buf,bufsize);
  return sVar1;
}


/* Compat_readlink @ 0x11c300 */

ssize_t Compat_readlink(openat_arg_t dirfd,char *pathname,char *buf,size_t bufsize)

{
  undefined1 __frame[0x2108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x20c8;
  long lVar1;
  ssize_t sVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf((*(char (*) [32])(__fp - 0x2078)),0x20,((char *)(long)&s__proc_self_fd__d_00147480 /* "/proc/self/fd/%d" */),dirfd);
  sVar2 = readlink((*(char (*) [32])(__fp - 0x2078)),(*(char (*) [4097])(__fp - 0x1048)),0x1000);
  if (-1 < sVar2) {
    (*(char (*) [4097])(__fp - 0x1048))[sVar2] = '\0';
    xSnprintf((*(char (*) [4097])(__fp - 0x2058)),0x1001,((char *)(long)&s__s__s_00147491 /* "%s/%s" */),(*(char (*) [4097])(__fp - 0x1048)),pathname);
    sVar2 = readlink((*(char (*) [4097])(__fp - 0x2058)),buf,bufsize);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return sVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

