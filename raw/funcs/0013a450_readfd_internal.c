/* readfd_internal @ 0013a450 size 225 */

ssize_t readfd_internal(wchar_t fd,void *buffer,size_t count)

{
  long lVar1;
  int *piVar2;
  ulong uVar3;
  ulong uVar4;
  size_t p3;
  ulong p2;
  long local_40;

  if (count == 0) {
    close(fd);
    local_40 = -0x16;
  }
  else {
    p2 = count - 1;
    local_40 = 0;
    p3 = count;
    do {
                    /* Unresolved local var: ssize_t res@[???] */
      while (lVar1 = __read_chk(fd,buffer,p2,p3), lVar1 != -1) {
        if (0 < lVar1) {
          uVar3 = p3;
          if (p3 <= count) {
            uVar3 = count;
          }
          uVar4 = (lVar1 + uVar3) - p3;
          if (uVar4 < uVar3) {
            uVar4 = uVar3;
          }
          local_40 = local_40 + lVar1;
          buffer = (void *)((long)buffer + lVar1);
          p2 = p2 - lVar1;
          p3 = (p3 - (lVar1 + uVar3)) + uVar4;
        }
        if ((p2 == 0) || (lVar1 == 0)) {
          close(fd);
          *(undefined1 *)buffer = 0;
          return local_40;
        }
      }
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
    close(fd);
    *(undefined1 *)buffer = 0;
    local_40 = (long)-*piVar2;
  }
  return local_40;
}

