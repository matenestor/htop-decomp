/* Generic_uname @ 001402d0 size 946 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Generic_uname(void)

{
  long lVar1;
  int iVar2;
  wchar_t wVar3;
  FILE_2 *__stream;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined *va1;
  ulong uVar8;
  long in_FS_OFFSET;
  char name [64];
  char version [64];
  char distro [128];
  char lineBuffer [256];
  utsname uname_info;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
                    /* Unresolved local var: wchar_t uname_result@[???] */
  iVar2 = uname(&uname_info);
                    /* Unresolved local var: FILE * stream@[???] */
  __stream = fopen(((char *)0x149d90 /* "/etc/os-release" */),((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    xSnprintf(distro,0x80,((char *)0x149da0 /* "No OS Release" */));
  }
  else {
    name[0] = '\0';
    name[1] = '\0';
    name[2] = '\0';
    name[3] = '\0';
    name[4] = '\0';
    name[5] = '\0';
    name[6] = '\0';
    name[7] = '\0';
    name[8] = '\0';
    name[9] = '\0';
    name[10] = '\0';
    name[0xb] = '\0';
    name[0xc] = '\0';
    name[0xd] = '\0';
    name[0xe] = '\0';
    name[0xf] = '\0';
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * stop@[???] */
    pcVar7 = lineBuffer + 0xd;
    name[0x10] = '\0';
    name[0x11] = '\0';
    name[0x12] = '\0';
    name[0x13] = '\0';
    name[0x14] = '\0';
    name[0x15] = '\0';
    name[0x16] = '\0';
    name[0x17] = '\0';
    name[0x18] = '\0';
    name[0x19] = '\0';
    name[0x1a] = '\0';
    name[0x1b] = '\0';
    name[0x1c] = '\0';
    name[0x1d] = '\0';
    name[0x1e] = '\0';
    name[0x1f] = '\0';
    name[0x20] = '\0';
    name[0x21] = '\0';
    name[0x22] = '\0';
    name[0x23] = '\0';
    name[0x24] = '\0';
    name[0x25] = '\0';
    name[0x26] = '\0';
    name[0x27] = '\0';
    name[0x28] = '\0';
    name[0x29] = '\0';
    name[0x2a] = '\0';
    name[0x2b] = '\0';
    name[0x2c] = '\0';
    name[0x2d] = '\0';
    name[0x2e] = '\0';
    name[0x2f] = '\0';
    name[0x30] = '\0';
    name[0x31] = '\0';
    name[0x32] = '\0';
    name[0x33] = '\0';
    name[0x34] = '\0';
    name[0x35] = '\0';
    name[0x36] = '\0';
    name[0x37] = '\0';
    name[0x38] = '\0';
    name[0x39] = '\0';
    name[0x3a] = '\0';
    name[0x3b] = '\0';
    name[0x3c] = '\0';
    name[0x3d] = '\0';
    name[0x3e] = '\0';
    name[0x3f] = '\0';
    version[0] = '\0';
    version[1] = '\0';
    version[2] = '\0';
    version[3] = '\0';
    version[4] = '\0';
    version[5] = '\0';
    version[6] = '\0';
    version[7] = '\0';
    version[8] = '\0';
    version[9] = '\0';
    version[10] = '\0';
    version[0xb] = '\0';
    version[0xc] = '\0';
    version[0xd] = '\0';
    version[0xe] = '\0';
    version[0xf] = '\0';
    version[0x10] = '\0';
    version[0x11] = '\0';
    version[0x12] = '\0';
    version[0x13] = '\0';
    version[0x14] = '\0';
    version[0x15] = '\0';
    version[0x16] = '\0';
    version[0x17] = '\0';
    version[0x18] = '\0';
    version[0x19] = '\0';
    version[0x1a] = '\0';
    version[0x1b] = '\0';
    version[0x1c] = '\0';
    version[0x1d] = '\0';
    version[0x1e] = '\0';
    version[0x1f] = '\0';
    version[0x20] = '\0';
    version[0x21] = '\0';
    version[0x22] = '\0';
    version[0x23] = '\0';
    version[0x24] = '\0';
    version[0x25] = '\0';
    version[0x26] = '\0';
    version[0x27] = '\0';
    version[0x28] = '\0';
    version[0x29] = '\0';
    version[0x2a] = '\0';
    version[0x2b] = '\0';
    version[0x2c] = '\0';
    version[0x2d] = '\0';
    version[0x2e] = '\0';
    version[0x2f] = '\0';
    version[0x30] = '\0';
    version[0x31] = '\0';
    version[0x32] = '\0';
    version[0x33] = '\0';
    version[0x34] = '\0';
    version[0x35] = '\0';
    version[0x36] = '\0';
    version[0x37] = '\0';
    version[0x38] = '\0';
    version[0x39] = '\0';
    version[0x3a] = '\0';
    version[0x3b] = '\0';
    version[0x3c] = '\0';
    version[0x3d] = '\0';
    version[0x3e] = '\0';
    version[0x3f] = '\0';
    do {
      while( true ) {
                    /* Unresolved local var: size_t sz@[???] */
        pcVar4 = fgets(lineBuffer,0x100,__stream);
        if (pcVar4 == (char *)0x0) {
          fclose(__stream);
          va1 = &DAT_00149c0c;
          pcVar7 = ((char *)0x149c0c /* "" */);
          if ((name[0] != '\0') && (pcVar7 = name, version[0] != '\0')) {
            va1 = &DAT_001470dd;
          }
          __snprintf_chk(distro,0x80,2,0x80,((char *)0x147641 /* "%s%s%s" */),pcVar7,va1,version);
          goto LAB_001404b6;
        }
        if ((CONCAT26(lineBuffer._6_2_,
                      CONCAT15(lineBuffer[5],CONCAT14(lineBuffer[4],lineBuffer._0_4_))) ==
             0x4e5f595454455250) &&
           (CONCAT44(lineBuffer._9_4_,
                     CONCAT13(lineBuffer[8],CONCAT21(lineBuffer._6_2_,lineBuffer[5]))) ==
            0x223d454d414e5f59)) break;
        if ((lineBuffer._0_4_ == 0x454d414e) && (CONCAT11(lineBuffer[5],lineBuffer[4]) == 0x223d)) {
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * stop@[???] */
          pcVar4 = strrchr(lineBuffer,0x22);
          if ((pcVar4 != (char *)0x0) && (pcVar6 = lineBuffer + 6, pcVar6 < pcVar4)) {
                    /* Unresolved local var: size_t i@[???] */
            pcVar4 = pcVar4 + (1 - (long)pcVar6);
            if ((char *)0x40 < pcVar4) {
              pcVar4 = (char *)0x40;
            }
            pcVar5 = (char *)0x0;
            do {
              if (pcVar6[(long)pcVar5] == '\0') break;
              name[(long)pcVar5] = pcVar6[(long)pcVar5];
              pcVar5 = pcVar5 + 1;
            } while (pcVar5 < pcVar4 + -1);
            name[(long)pcVar5] = '\0';
          }
        }
        else if ((CONCAT26(lineBuffer._6_2_,
                           CONCAT15(lineBuffer[5],CONCAT14(lineBuffer[4],lineBuffer._0_4_))) ==
                  0x3d4e4f4953524556) && (lineBuffer[8] == '\"')) {
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * stop@[???] */
          pcVar4 = strrchr(lineBuffer,0x22);
          if ((pcVar4 != (char *)0x0) && (pcVar6 = lineBuffer + 9, pcVar6 < pcVar4)) {
                    /* Unresolved local var: size_t i@[???] */
            pcVar4 = pcVar4 + (1 - (long)pcVar6);
            if ((char *)0x40 < pcVar4) {
              pcVar4 = (char *)0x40;
            }
            pcVar5 = (char *)0x0;
            do {
              if (pcVar6[(long)pcVar5] == '\0') break;
              version[(long)pcVar5] = pcVar6[(long)pcVar5];
              pcVar5 = pcVar5 + 1;
            } while (pcVar5 < pcVar4 + -1);
            version[(long)pcVar5] = '\0';
          }
        }
      }
      pcVar4 = strrchr(lineBuffer,0x22);
    } while ((pcVar4 == (char *)0x0) || (pcVar4 <= pcVar7));
    pcVar4 = pcVar4 + (1 - (long)pcVar7);
    if ((char *)0x80 < pcVar4) {
      pcVar4 = (char *)0x80;
    }
                    /* Unresolved local var: size_t i@[???] */
    pcVar6 = (char *)0x0;
    do {
      if (pcVar7[(long)pcVar6] == '\0') break;
      distro[(long)pcVar6] = pcVar7[(long)pcVar6];
      pcVar6 = pcVar6 + 1;
    } while (pcVar6 < pcVar4 + -1);
    distro[(long)pcVar6] = '\0';
    fclose(__stream);
  }
LAB_001404b6:
  if (iVar2 == 0) {
                    /* Unresolved local var: size_t written@[???] */
    wVar3 = xSnprintf(&savedString_0_lto_priv_0,0x153,((char *)0x149dc6 /* "%s %s [%s]" */),&uname_info,uname_info.release,
                      uname_info.machine);
    uVar8 = (ulong)wVar3;
    pcVar7 = strcasestr(&savedString_0_lto_priv_0,distro);
    if ((pcVar7 == (char *)0x0) && (uVar8 < 0x153)) {
      __snprintf_chk(&savedString_0_lto_priv_0 + uVar8,0x153 - uVar8,2,0x153 - uVar8,((char *)0x149dd1 /* " @ %s" */),distro)
      ;
    }
  }
  else {
    snprintf(&savedString_0_lto_priv_0,0x153,((char *)0x147626 /* "%s" */),distro);
  }
  loaded_data_1_lto_priv_0 = '\x01';
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (char *)0x0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

