/* Compat_readlink @ 0011c300 size 221 */

ssize_t Compat_readlink(openat_arg_t dirfd,char *pathname,char *buf,size_t bufsize)

{
  long lVar1;
  ssize_t sVar2;
  long in_FS_OFFSET;
  char fdPath [32];
  char linkPath [4097];
  char dirPath [4097];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  xSnprintf(fdPath,0x20,((char *)0x147480 /* "/proc/self/fd/%d" */),dirfd);
  sVar2 = readlink(fdPath,dirPath,0x1000);
  if (-1 < sVar2) {
    dirPath[sVar2] = '\0';
    xSnprintf(linkPath,0x1001,((char *)0x147491 /* "%s/%s" */),dirPath,pathname);
    sVar2 = readlink(linkPath,buf,bufsize);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return sVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

