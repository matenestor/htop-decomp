/* xReadfile @ 0013ac50 size 63 */

ssize_t xReadfile(char *pathname,void *buffer,size_t count)

{
  wchar_t fd;
  ssize_t sVar1;
  int *piVar2;

  fd = open(pathname,0);
  if (L'\xffffffff' < fd) {
    sVar1 = readfd_internal(fd,buffer,count);
    return sVar1;
  }
                    /* Unresolved local var: wchar_t fd@[???] */
  piVar2 = __errno_location();
  return (long)-*piVar2;
}

