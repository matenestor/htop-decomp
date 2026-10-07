#include "htop.h"

/* Generic_uname @ 0x1402d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Generic_uname(void)

{
  undefined1 __frame[0x458] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x418;
  long lVar1;
  int iVar2;
  int wVar3;
  FILE_2 *__stream;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined *va1;
  ulong uVar8;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
                    /* Unresolved local var: int uname_result@[???] */
  iVar2 = uname(&(*(utsname (*))(__fp - 0x1c8)));
                    /* Unresolved local var: FILE * stream@[???] */
  __stream = fopen(((char *)(long)&s__etc_os_release_00149d90 /* "/etc/os-release" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    xSnprintf((*(char (*) [128])(__fp - 0x348)),0x80,((char *)(long)&s_No_OS_Release_00149da0 /* "No OS Release" */));
  }
  else {
    (*(char (*) [64])(__fp - 0x3c8))[0] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[1] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[2] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[3] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[4] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[5] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[6] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[7] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[8] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[9] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[10] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0xb] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0xc] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0xd] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0xe] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0xf] = '\0';
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * stop@[???] */
    pcVar7 = (*(char (*) [256])(__fp - 0x2c8)) + 0xd;
    (*(char (*) [64])(__fp - 0x3c8))[0x10] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x11] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x12] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x13] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x14] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x15] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x16] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x17] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x18] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x19] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x1a] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x1b] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x1c] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x1d] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x1e] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x1f] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x20] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x21] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x22] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x23] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x24] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x25] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x26] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x27] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x28] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x29] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x2a] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x2b] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x2c] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x2d] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x2e] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x2f] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x30] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x31] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x32] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x33] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x34] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x35] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x36] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x37] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x38] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x39] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x3a] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x3b] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x3c] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x3d] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x3e] = '\0';
    (*(char (*) [64])(__fp - 0x3c8))[0x3f] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0] = '\0';
    (*(char (*) [64])(__fp - 0x388))[1] = '\0';
    (*(char (*) [64])(__fp - 0x388))[2] = '\0';
    (*(char (*) [64])(__fp - 0x388))[3] = '\0';
    (*(char (*) [64])(__fp - 0x388))[4] = '\0';
    (*(char (*) [64])(__fp - 0x388))[5] = '\0';
    (*(char (*) [64])(__fp - 0x388))[6] = '\0';
    (*(char (*) [64])(__fp - 0x388))[7] = '\0';
    (*(char (*) [64])(__fp - 0x388))[8] = '\0';
    (*(char (*) [64])(__fp - 0x388))[9] = '\0';
    (*(char (*) [64])(__fp - 0x388))[10] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0xb] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0xc] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0xd] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0xe] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0xf] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x10] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x11] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x12] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x13] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x14] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x15] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x16] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x17] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x18] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x19] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x1a] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x1b] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x1c] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x1d] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x1e] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x1f] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x20] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x21] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x22] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x23] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x24] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x25] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x26] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x27] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x28] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x29] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x2a] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x2b] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x2c] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x2d] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x2e] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x2f] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x30] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x31] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x32] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x33] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x34] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x35] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x36] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x37] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x38] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x39] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x3a] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x3b] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x3c] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x3d] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x3e] = '\0';
    (*(char (*) [64])(__fp - 0x388))[0x3f] = '\0';
    do {
      while( true ) {
                    /* Unresolved local var: size_t sz@[???] */
        pcVar4 = fgets((*(char (*) [256])(__fp - 0x2c8)),0x100,__stream);
        if (pcVar4 == (char *)0x0) {
          fclose(__stream);
          va1 = &DAT_00149c0c;
          pcVar7 = ((char *)(long)&DAT_00149c0c /* "" */);
          if (((*(char (*) [64])(__fp - 0x3c8))[0] != '\0') && (pcVar7 = (*(char (*) [64])(__fp - 0x3c8)), (*(char (*) [64])(__fp - 0x388))[0] != '\0')) {
            va1 = &DAT_001470dd;
          }
          __snprintf_chk((*(char (*) [128])(__fp - 0x348)),0x80,2,0x80,((char *)(long)(__sec_rodata + 0x641) /* "%s%s%s" */),pcVar7,va1,(*(char (*) [64])(__fp - 0x388)));
          goto LAB_001404b6;
        }
        if ((CONCAT26((*(ushort *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 6)),
                      CONCAT15((*(char (*) [256])(__fp - 0x2c8))[5],CONCAT14((*(char (*) [256])(__fp - 0x2c8))[4],(*(uint *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 0))))) ==
             0x4e5f595454455250) &&
           (CONCAT44((*(uint *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 9)),
                     CONCAT13((*(char (*) [256])(__fp - 0x2c8))[8],CONCAT21((*(ushort *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 6)),(*(char (*) [256])(__fp - 0x2c8))[5]))) ==
            0x223d454d414e5f59)) break;
        if (((*(uint *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 0)) == 0x454d414e) && (CONCAT11((*(char (*) [256])(__fp - 0x2c8))[5],(*(char (*) [256])(__fp - 0x2c8))[4]) == 0x223d)) {
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * stop@[???] */
          pcVar4 = strrchr((*(char (*) [256])(__fp - 0x2c8)),0x22);
          if ((pcVar4 != (char *)0x0) && (pcVar6 = (*(char (*) [256])(__fp - 0x2c8)) + 6, pcVar6 < pcVar4)) {
                    /* Unresolved local var: size_t i@[???] */
            pcVar4 = pcVar4 + (1 - (long)pcVar6);
            if ((char *)0x40 < pcVar4) {
              pcVar4 = (char *)0x40;
            }
            pcVar5 = (char *)0x0;
            do {
              if (pcVar6[(long)pcVar5] == '\0') break;
              (*(char (*) [64])(__fp - 0x3c8))[(long)pcVar5] = pcVar6[(long)pcVar5];
              pcVar5 = pcVar5 + 1;
            } while (pcVar5 < pcVar4 + -1);
            (*(char (*) [64])(__fp - 0x3c8))[(long)pcVar5] = '\0';
          }
        }
        else if ((CONCAT26((*(ushort *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 6)),
                           CONCAT15((*(char (*) [256])(__fp - 0x2c8))[5],CONCAT14((*(char (*) [256])(__fp - 0x2c8))[4],(*(uint *)((char *)&(*(char (*) [256])(__fp - 0x2c8)) + 0))))) ==
                  0x3d4e4f4953524556) && ((*(char (*) [256])(__fp - 0x2c8))[8] == '\"')) {
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * stop@[???] */
          pcVar4 = strrchr((*(char (*) [256])(__fp - 0x2c8)),0x22);
          if ((pcVar4 != (char *)0x0) && (pcVar6 = (*(char (*) [256])(__fp - 0x2c8)) + 9, pcVar6 < pcVar4)) {
                    /* Unresolved local var: size_t i@[???] */
            pcVar4 = pcVar4 + (1 - (long)pcVar6);
            if ((char *)0x40 < pcVar4) {
              pcVar4 = (char *)0x40;
            }
            pcVar5 = (char *)0x0;
            do {
              if (pcVar6[(long)pcVar5] == '\0') break;
              (*(char (*) [64])(__fp - 0x388))[(long)pcVar5] = pcVar6[(long)pcVar5];
              pcVar5 = pcVar5 + 1;
            } while (pcVar5 < pcVar4 + -1);
            (*(char (*) [64])(__fp - 0x388))[(long)pcVar5] = '\0';
          }
        }
      }
      pcVar4 = strrchr((*(char (*) [256])(__fp - 0x2c8)),0x22);
    } while ((pcVar4 == (char *)0x0) || (pcVar4 <= pcVar7));
    pcVar4 = pcVar4 + (1 - (long)pcVar7);
    if ((char *)0x80 < pcVar4) {
      pcVar4 = (char *)0x80;
    }
                    /* Unresolved local var: size_t i@[???] */
    pcVar6 = (char *)0x0;
    do {
      if (pcVar7[(long)pcVar6] == '\0') break;
      (*(char (*) [128])(__fp - 0x348))[(long)pcVar6] = pcVar7[(long)pcVar6];
      pcVar6 = pcVar6 + 1;
    } while (pcVar6 < pcVar4 + -1);
    (*(char (*) [128])(__fp - 0x348))[(long)pcVar6] = '\0';
    fclose(__stream);
  }
LAB_001404b6:
  if (iVar2 == 0) {
                    /* Unresolved local var: size_t written@[???] */
    wVar3 = xSnprintf(&savedString_0_lto_priv_0,0x153,((char *)(long)&s__s__s___s__00149dc6 /* "%s %s [%s]" */),&(*(utsname (*))(__fp - 0x1c8)),(*(utsname (*))(__fp - 0x1c8)).release,
                      (*(utsname (*))(__fp - 0x1c8)).machine);
    uVar8 = (ulong)wVar3;
    pcVar7 = strcasestr(&savedString_0_lto_priv_0,(*(char (*) [128])(__fp - 0x348)));
    if ((pcVar7 == (char *)0x0) && (uVar8 < 0x153)) {
      __snprintf_chk(&savedString_0_lto_priv_0 + uVar8,0x153 - uVar8,2,0x153 - uVar8,((char *)(long)&s____s_00149dd1 /* " @ %s" */),(*(char (*) [128])(__fp - 0x348)))
      ;
    }
  }
  else {
    snprintf(&savedString_0_lto_priv_0,0x153,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),(*(char (*) [128])(__fp - 0x348)));
  }
  loaded_data_1_lto_priv_0 = '\x01';
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (char *)0x0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Generic_uname_1406b0 @ 0x1406b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Generic_uname_1406b0(void)

{
  if (loaded_data_1_lto_priv_0 != '\0') {
    return &savedString_0_lto_priv_0;
  }
  Generic_uname();
  return &savedString_0_lto_priv_0;
}

