/* Compat_fstatat @ 00116140 size 18 */

wchar_t Compat_fstatat(wchar_t dirfd,char *dirpath,char *pathname,stat *statbuf,wchar_t flags)

{
  wchar_t wVar1;

  wVar1 = fstatat(dirfd,pathname,(stat_2 *)statbuf,flags);
  return wVar1;
}

