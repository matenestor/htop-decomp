#include "htop.h"

/* SELinuxMeter_updateValues @ 0x13d430 */

/* DWARF original prototype: void SELinuxMeter_updateValues(Meter * this) */

void SELinuxMeter_updateValues(Meter *this)

{
  undefined1 __frame[0x1a8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x168;
  long lVar1;
  _Bool _Var2;
  int iVar3;
  int fd;
  long lVar4;
  int *piVar5;
  char *va0;
  char *va1;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int r@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = statfs(((char *)(long)&s__sys_fs_selinux_00149b3d /* "/sys/fs/selinux" */),(statfs_2 *)&(*(struct statfs (*))(__fp - 0xa8)));
  if ((iVar3 == 0) && ((int)(*(struct statfs (*))(__fp - 0xa8)).f_type == -0x6830074)) {
    iVar3 = statvfs(((char *)(long)&s__sys_fs_selinux_00149b3d /* "/sys/fs/selinux" */),(statvfs_2 *)&(*(struct statvfs (*))(__fp - 0x118)));
    if ((iVar3 != 0) || (((byte)(*(struct statvfs (*))(__fp - 0x118)).f_flag & 1) != 0)) goto LAB_0013d47f;
    iVar3 = access(((char *)(long)&s__etc_selinux_config_00149b4d /* "/etc/selinux/config" */),0);
    if (iVar3 != 0) goto LAB_0013d47f;
                    /* Unresolved local var: ssize_t r@[???]
                       Unresolved local var: int fd@[???] */
    enabled = true;
    fd = open(((char *)(long)&s__sys_fs_selinux_enforce_00149b61 /* "/sys/fs/selinux/(*(int (*))(__fp - 0x11c))" */),0);
    if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
      piVar5 = __errno_location();
      lVar4 = (long)-*piVar5;
    }
    else {
      lVar4 = readfd_internal(fd,&(*(struct statfs (*))(__fp - 0xa8)),0x14);
    }
    _Var2 = enabled;
    if (lVar4 < 0) {
LAB_0013d588:
      if (_Var2 != false) {
LAB_0013d591:
        va1 = ((char *)(long)&s___mode__permissive_00149b2a /* "; mode: permissive" */);
        va0 = ((char *)(long)&s_enabled_00149b19 /* "enabled" */);
        goto LAB_0013d494;
      }
    }
    else {
      (*(int (*))(__fp - 0x11c)) = 0;
      iVar3 = __isoc23_sscanf((char *)&(*(struct statfs (*))(__fp - 0xa8)),((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),&(*(int (*))(__fp - 0x11c)));
      if (iVar3 != 1) goto LAB_0013d588;
      if (_Var2 != false) {
        if ((*(int (*))(__fp - 0x11c)) != 0) {
          va1 = ((char *)(long)&s___mode__enforcing_00149b07 /* "; mode: enforcing" */);
          va0 = ((char *)(long)&s_enabled_00149b19 /* "enabled" */);
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
  va1 = ((char *)(long)&DAT_00149c0c /* "" */);
  va0 = ((char *)(long)&s_disabled_00149b21 /* "disabled" */);
LAB_0013d494:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    xSnprintf(this->txtBuffer,0x100,((char *)(long)(__sec_rodata + 0x643) /* "%s%s" */),va0,va1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

