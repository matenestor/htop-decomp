/* Compat_faccessat @ 00116080 size 180 */

wchar_t Compat_faccessat(wchar_t dirfd,char *pathname,wchar_t mode,wchar_t flags)

{
  long lVar1;
  wchar_t wVar2;
  int *piVar3;
  long in_FS_OFFSET;
  stat statinfo;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  piVar3 = __errno_location();
  *piVar3 = 0;
  wVar2 = faccessat(dirfd,pathname,mode,flags);
  if ((wVar2 != L'\0') && (*piVar3 == 0x16)) {
    if ((dirfd == L'\xffffff9c') && (mode == L'\0')) {
      if (flags == L'\0') {
        wVar2 = stat(pathname,(stat_2 *)&statinfo);
      }
      else {
        wVar2 = lstat(pathname,(stat_2 *)&statinfo);
      }
    }
    else {
      wVar2 = L'\xffffffff';
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return wVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

