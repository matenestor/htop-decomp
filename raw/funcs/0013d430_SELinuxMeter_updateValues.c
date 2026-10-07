/* SELinuxMeter_updateValues @ 0013d430 size 384 */

/* DWARF original prototype: void SELinuxMeter_updateValues(Meter * this) */

void SELinuxMeter_updateValues(Meter *this)

{
  long lVar1;
  _Bool _Var2;
  int iVar3;
  wchar_t fd;
  long lVar4;
  int *piVar5;
  char *va0;
  char *va1;
  long in_FS_OFFSET;
  wchar_t enforce;
  statvfs vfsbuf;
  statfs sfbuf;

                    /* Unresolved local var: wchar_t r@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = statfs(((char *)0x149b3d /* "/sys/fs/selinux" */),(statfs_2 *)&sfbuf);
  if ((iVar3 == 0) && ((int)sfbuf.f_type == -0x6830074)) {
    iVar3 = statvfs(((char *)0x149b3d /* "/sys/fs/selinux" */),(statvfs_2 *)&vfsbuf);
    if ((iVar3 != 0) || (((byte)vfsbuf.f_flag & 1) != 0)) goto LAB_0013d47f;
    iVar3 = access(((char *)0x149b4d /* "/etc/selinux/config" */),0);
    if (iVar3 != 0) goto LAB_0013d47f;
                    /* Unresolved local var: ssize_t r@[???]
                       Unresolved local var: wchar_t fd@[???] */
    enabled = true;
    fd = open(((char *)0x149b61 /* "/sys/fs/selinux/enforce" */),0);
    if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
      piVar5 = __errno_location();
      lVar4 = (long)-*piVar5;
    }
    else {
      lVar4 = readfd_internal(fd,&sfbuf,0x14);
    }
    _Var2 = enabled;
    if (lVar4 < 0) {
LAB_0013d588:
      if (_Var2 != false) {
LAB_0013d591:
        va1 = ((char *)0x149b2a /* "; mode: permissive" */);
        va0 = ((char *)0x149b19 /* "enabled" */);
        goto LAB_0013d494;
      }
    }
    else {
      enforce = L'\0';
      iVar3 = __isoc23_sscanf((char *)&sfbuf,((char *)0x149710 /* "%d" */),&enforce);
      if (iVar3 != 1) goto LAB_0013d588;
      if (_Var2 != false) {
        if (enforce != L'\0') {
          va1 = ((char *)0x149b07 /* "; mode: enforcing" */);
          va0 = ((char *)0x149b19 /* "enabled" */);
          goto LAB_0013d494;
        }
        goto LAB_0013d591;
      }
    }
  }
  else {
LAB_0013d47f:
    enabled = false;
  }
  va1 = ((char *)0x149c0c /* "" */);
  va0 = ((char *)0x149b21 /* "disabled" */);
LAB_0013d494:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    xSnprintf(this->txtBuffer,0x100,((char *)0x147643 /* "%s%s" */),va0,va1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

