/* Compat_readlinkat @ 00116160 size 18 */

ssize_t Compat_readlinkat(wchar_t dirfd,char *dirpath,char *pathname,char *buf,size_t bufsize)

{
  ssize_t sVar1;

  sVar1 = readlinkat(dirfd,pathname,buf,bufsize);
  return sVar1;
}

