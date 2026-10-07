/* LinuxProcessTable_readStatusFile @ 00138ca0 size 1042 */

_Bool LinuxProcessTable_readStatusFile(LinuxProcess_ *process,openat_arg_t procFd)

{
  byte *pbVar1;
  long lVar2;
  ushort *puVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  FILE_2 *__stream;
  char *pcVar7;
  ushort **ppuVar8;
  ulong uVar9;
  ulong uVar10;
  byte *pbVar11;
  long lVar12;
  long in_FS_OFFSET;
  _Bool _Var13;
  ulong local_1068;
  wchar_t vxid;
  undefined4 uStack_104c;
  char buffer [4097];

                    /* Unresolved local var: LinuxProcess * lp@[???]
                       Unresolved local var: ulong ctxt@[???]
                       Unresolved local var: FILE * statusfile@[???] */
                    /* Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  process->vxid = 0;
  iVar5 = openat(procFd,((char *)0x149730 /* "status" */),0);
  if (-1 < iVar5) {
    __stream = fdopen(iVar5,((char *)0x147760 /* "r" */));
    if (__stream != (FILE_2 *)0x0) {
      local_1068 = 0;
LAB_00138d30:
                    /* Unresolved local var: size_t sz@[???] */
      pcVar7 = fgets(buffer,0x1001,__stream);
      bVar4 = buffer[0];
      if (pcVar7 != (char *)0x0) {
        if ((CONCAT13(buffer[3],CONCAT21(buffer._1_2_,buffer[0])) == 0x6970534e) &&
           (CONCAT11(buffer[5],buffer[4]) == 0x3a64)) {
          if ((buffer[0] != '\0') && (buffer[0] != '\n')) {
            ppuVar8 = __ctype_b_loc();
            iVar5 = 0;
            puVar3 = *ppuVar8;
            pbVar11 = (byte *)buffer;
                    /* Unresolved local var: char * ptr@[???]
                       Unresolved local var: wchar_t pid_ns_count@[???] */
            while ((*(byte *)((long)puVar3 + (ulong)bVar4 * 2 + 1) & 8) == 0) {
              bVar4 = pbVar11[1];
              pbVar11 = pbVar11 + 1;
              if ((bVar4 == 0) || (bVar4 == 10)) goto LAB_00138d30;
            }
            bVar4 = *pbVar11;
            if ((bVar4 != 0) && (bVar4 != 10)) goto LAB_00138e80;
          }
        }
        else if ((CONCAT13(buffer[3],CONCAT21(buffer._1_2_,buffer[0])) == 0x50706143) &&
                (CONCAT13(buffer[6],CONCAT12(buffer[5],CONCAT11(buffer[4],buffer[3]))) == 0x3a6d7250
                )) {
                    /* Unresolved local var: char * ptr@[???]
                       Unresolved local var: uint64_t cap_permitted@[???] */
          if ((buffer[7] == ' ') || (buffer[7] == '\t')) {
            pbVar11 = (byte *)(buffer + 7);
            do {
              do {
                pbVar1 = pbVar11 + 1;
                pbVar11 = pbVar11 + 1;
              } while (*pbVar1 == 0x20);
            } while (*pbVar1 == 9);
          }
          else {
            pbVar11 = (byte *)(buffer + 7);
          }
                    /* Unresolved local var: uint64_t result@[???]
                       Unresolved local var: wchar_t nibble@[???]
                       Unresolved local var: wchar_t letter@[???]
                       Unresolved local var: long valid_mask@[???] */
          pbVar1 = pbVar11 + 0x10;
          lVar12 = 0;
          do {
            bVar4 = *pbVar11;
            if ((((1 << (bVar4 & 0x1f) & 0x3ff007eU) == 0) || (bVar4 < 0x30)) ||
               (uVar6 = bVar4 & 0xffffffdf, 0x46 < uVar6)) break;
            pbVar11 = pbVar11 + 1;
            lVar12 = lVar12 * 0x10 + (ulong)(uVar6 - (-(uint)((bVar4 & 0x40) != 0) & 7) & 0xf);
          } while (pbVar11 != pbVar1);
          _Var13 = false;
          if (lVar12 != 0) {
            _Var13 = (process->super).st_uid != 0;
          }
          (process->super).elevated_priv = _Var13;
        }
        else {
                    /* Unresolved local var: wchar_t ok@[???] */
          if ((CONCAT17(buffer[7],
                        CONCAT16(buffer[6],
                                 CONCAT15(buffer[5],
                                          CONCAT14(buffer[4],
                                                   CONCAT13(buffer[3],
                                                            CONCAT21(buffer._1_2_,buffer[0])))))) ==
               0x7261746e756c6f76 && CONCAT53(buffer._11_5_,buffer._8_3_) == 0x735f747874635f79) &&
             (CONCAT53(buffer._19_5_,buffer._16_3_) == 0x3a73656863746977)) {
                    /* Unresolved local var: wchar_t ok@[???] */
            iVar5 = __isoc23_sscanf(buffer,((char *)0x149746 /* "voluntary_ctxt_switches:\t%lu" */),&vxid);
joined_r0x0013909e:
            if (0 < iVar5) {
              local_1068 = local_1068 + CONCAT44(uStack_104c,vxid);
            }
          }
          else {
            if ((CONCAT17(buffer[7],
                          CONCAT16(buffer[6],
                                   CONCAT15(buffer[5],
                                            CONCAT14(buffer[4],
                                                     CONCAT13(buffer[3],
                                                              CONCAT21(buffer._1_2_,buffer[0]))))))
                 == 0x6e756c6f766e6f6e && CONCAT53(buffer._11_5_,buffer._8_3_) == 0x7874635f79726174
                ) && (CONCAT35(buffer._16_3_,buffer._11_5_) == 0x735f747874635f79 &&
                      CONCAT35(buffer._24_3_,buffer._19_5_) == 0x3a73656863746977)) {
              iVar5 = __isoc23_sscanf(buffer,((char *)0x14ca10 /* "nonvoluntary_ctxt_switches:\t%lu" */),&vxid);
              goto joined_r0x0013909e;
            }
                    /* Unresolved local var: wchar_t ok@[???] */
            if (((CONCAT13(buffer[3],CONCAT21(buffer._1_2_,buffer[0])) == 0x44497856) &&
                (buffer[4] == ':')) &&
               (iVar5 = __isoc23_sscanf(buffer,((char *)0x149785 /* "VxID:\t%32d" */),&vxid), 0 < iVar5)) {
              process->vxid = vxid;
            }
          }
        }
        goto LAB_00138d30;
      }
      fclose(__stream);
      uVar9 = process->ctxt_total;
      process->ctxt_total = local_1068;
      uVar10 = local_1068 - uVar9;
      if (local_1068 <= uVar9) {
        uVar10 = 0;
      }
      process->ctxt_diff = uVar10;
      _Var13 = true;
      goto LAB_0013903e;
    }
    close(iVar5);
  }
  _Var13 = false;
LAB_0013903e:
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var13;
  while( true ) {
    while ((*(byte *)((long)puVar3 + uVar9 * 2 + 1) & 8) == 0) {
      bVar4 = pbVar11[1];
      uVar9 = (ulong)bVar4;
      pbVar11 = pbVar11 + 1;
      if (bVar4 == 0) goto LAB_00138ec0;
joined_r0x00138ebd:
      if (bVar4 == 10) goto LAB_00138ec0;
    }
    bVar4 = *pbVar11;
    if ((bVar4 == 0) || (bVar4 == 10)) break;
LAB_00138e80:
    uVar9 = (ulong)bVar4;
    iVar5 = (iVar5 + 1) - (uint)((puVar3[(char)bVar4] & 0x800) == 0);
    if ((*(byte *)((long)puVar3 + uVar9 * 2 + 1) & 8) != 0) goto LAB_00138ea8;
  }
LAB_00138ec0:
  if (1 < iVar5) {
    (process->super).isRunningInContainer = true;
  }
  goto LAB_00138d30;
LAB_00138ea8:
  do {
    bVar4 = pbVar11[1];
    uVar9 = (ulong)bVar4;
    pbVar11 = pbVar11 + 1;
  } while ((*(byte *)((long)puVar3 + uVar9 * 2 + 1) & 8) != 0);
  if (bVar4 != 0) goto joined_r0x00138ebd;
  goto LAB_00138ec0;
}

