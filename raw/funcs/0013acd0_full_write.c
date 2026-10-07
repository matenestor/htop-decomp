/* full_write @ 0013acd0 size 110 */

ssize_t full_write(wchar_t fd,void *buf,size_t count)

{
  ssize_t sVar1;
  int *piVar2;
  ssize_t sVar3;

  if (count == 0) {
    sVar3 = 0;
  }
  else {
    sVar3 = 0;
    do {
      while( true ) {
                    /* Unresolved local var: ssize_t r@[???] */
        sVar1 = write(fd,buf,count);
        if (-1 < sVar1) break;
        piVar2 = __errno_location();
        if (*piVar2 != 4) {
          return sVar1;
        }
      }
      if (sVar1 == 0) {
        return sVar3;
      }
      sVar3 = sVar3 + sVar1;
      buf = (void *)((long)buf + sVar1);
      count = count - sVar1;
    } while (count != 0);
  }
  return sVar3;
}

