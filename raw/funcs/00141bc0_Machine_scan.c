/* Machine_scan @ 00141bc0 size 4453 */

void Machine_scan(LinuxMachine_ *super)

{
  ulonglong *puVar1;
  uint uVar2;
  long lVar3;
  Settings__5 *pSVar4;
  int iVar5;
  wchar_t wVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  FILE_2 *pFVar10;
  char *pcVar11;
  ulong uVar12;
  DIR_2 *__dirp;
  dirent *pdVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  FILE_2 *__stream;
  int *piVar17;
  CPUData *pCVar18;
  long in_FS_OFFSET;
  memory_t local_190;
  memory_t local_188;
  memory_t local_180;
  memory_t local_178;
  memory_t local_170;
  memory_t local_168;
  ulong local_160;
  memory_t local_158;
  memory_t local_150;
  memory_t local_148;
  ulong local_140;
  memory_t dbufSize;
  memory_t dnodeSize;
  long local_120;
  memory_t parsed_;
  long local_110;
  char content [64];
  char buffer [128];

                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: memory_t availableMem@[???]
                       Unresolved local var: memory_t freeMem@[???]
                       Unresolved local var: memory_t totalMem@[???]
                       Unresolved local var: memory_t buffersMem@[???]
                       Unresolved local var: memory_t cachedMem@[???]
                       Unresolved local var: memory_t sharedMem@[???]
                       Unresolved local var: memory_t swapTotalMem@[???]
                       Unresolved local var: memory_t swapCacheMem@[???]
                       Unresolved local var: memory_t swapFreeMem@[???]
                       Unresolved local var: memory_t sreclaimableMem@[???]
                       Unresolved local var: memory_t zswapCompMem@[???]
                       Unresolved local var: memory_t zswapOrigMem@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: memory_t usedDiff@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  pFVar10 = fopen(((char *)0x149e96 /* "/proc/meminfo" */),((char *)0x147760 /* "r" */));
  if (pFVar10 == (FILE_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x149e8a /* "Cannot open /proc/meminfo" */));
  }
  local_168 = 0;
  local_158 = 0;
  local_190 = 0;
  local_170 = 0;
  local_188 = 0;
  local_180 = 0;
  local_178 = 0;
  local_150 = 0;
  local_148 = 0;
  local_160 = 0;
  local_140 = 0;
  uVar14 = 0;
                    /* Unresolved local var: size_t sz@[???] */
  while (pcVar11 = fgets(buffer,0x80,pFVar10), pcVar11 != (char *)0x0) {
    switch(buffer[0]) {
    case 'B':
      if ((CONCAT17(buffer[7],
                    CONCAT16(buffer[6],
                             CONCAT15(buffer[5],
                                      CONCAT14(buffer[4],
                                               CONCAT13(buffer[3],
                                                        CONCAT12(buffer[2],
                                                                 CONCAT11(buffer[1],buffer[0])))))))
           == 0x3a73726566667542) &&
         (iVar5 = __isoc23_sscanf(buffer + 8,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)) {
        local_148 = parsed_;
      }
      break;
    case 'C':
      if (((CONCAT13(buffer[3],CONCAT12(buffer[2],CONCAT11(buffer[1],buffer[0]))) == 0x68636143) &&
          (CONCAT13(buffer[6],CONCAT12(buffer[5],CONCAT11(buffer[4],buffer[3]))) == 0x3a646568)) &&
         (iVar5 = __isoc23_sscanf(buffer + 7,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)) {
        local_150 = parsed_;
      }
      break;
    case 'M':
      if ((CONCAT17(buffer[7],
                    CONCAT16(buffer[6],
                             CONCAT15(buffer[5],
                                      CONCAT14(buffer[4],
                                               CONCAT13(buffer[3],
                                                        CONCAT12(buffer[2],
                                                                 CONCAT11(buffer[1],buffer[0])))))))
           == 0x6c696176416d654d) &&
         (CONCAT26(buffer._11_2_,
                   CONCAT15(buffer[10],
                            CONCAT14(buffer[9],
                                     CONCAT13(buffer[8],
                                              CONCAT12(buffer[7],CONCAT11(buffer[6],buffer[5]))))))
          == 0x3a656c62616c6961)) {
        iVar5 = __isoc23_sscanf(buffer + 0xd,((char *)0x149eb2 /* "%llu kB" */),&parsed_);
        if (iVar5 == 1) {
          local_140 = parsed_;
        }
      }
      else if (CONCAT17(buffer[7],
                        CONCAT16(buffer[6],
                                 CONCAT15(buffer[5],
                                          CONCAT14(buffer[4],
                                                   CONCAT13(buffer[3],
                                                            CONCAT12(buffer[2],
                                                                     CONCAT11(buffer[1],buffer[0])))
                                                  )))) == 0x3a656572466d654d) {
        iVar5 = __isoc23_sscanf(buffer + 8,((char *)0x149eb2 /* "%llu kB" */),&parsed_);
        if (iVar5 == 1) {
          local_160 = parsed_;
        }
      }
      else if (((CONCAT17(buffer[7],
                          CONCAT16(buffer[6],
                                   CONCAT15(buffer[5],
                                            CONCAT14(buffer[4],
                                                     CONCAT13(buffer[3],
                                                              CONCAT12(buffer[2],
                                                                       CONCAT11(buffer[1],buffer[0])
                                                                      )))))) == 0x6c61746f546d654d)
               && (buffer[8] == ':')) &&
              (iVar5 = __isoc23_sscanf(buffer + 9,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)) {
        uVar14 = parsed_;
      }
      break;
    case 'S':
      if (buffer[1] == 'h') {
        if (((CONCAT13(buffer[3],CONCAT12(buffer[2],CONCAT11(0x68,buffer[0]))) == 0x656d6853) &&
            (CONCAT11(buffer[5],buffer[4]) == 0x3a6d)) &&
           (iVar5 = __isoc23_sscanf(buffer + 6,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)) {
          local_178 = parsed_;
        }
      }
      else if (buffer[1] == 'w') {
        if ((CONCAT17(buffer[7],
                      CONCAT16(buffer[6],
                               CONCAT15(buffer[5],
                                        CONCAT14(buffer[4],
                                                 CONCAT13(buffer[3],
                                                          CONCAT12(buffer[2],
                                                                   CONCAT11(0x77,buffer[0]))))))) ==
             0x61746f5470617753) && (CONCAT11(buffer[9],buffer[8]) == 0x3a6c)) {
          iVar5 = __isoc23_sscanf(buffer + 10,((char *)0x149eb2 /* "%llu kB" */),&parsed_);
          if (iVar5 == 1) {
            local_180 = parsed_;
          }
        }
        else if ((CONCAT17(buffer[7],
                           CONCAT16(buffer[6],
                                    CONCAT15(buffer[5],
                                             CONCAT14(buffer[4],
                                                      CONCAT13(buffer[3],
                                                               CONCAT12(buffer[2],
                                                                        CONCAT11(0x77,buffer[0])))))
                                   )) == 0x6863614370617753) &&
                (CONCAT13(buffer[10],CONCAT12(buffer[9],CONCAT11(buffer[8],buffer[7]))) ==
                 0x3a646568)) {
          iVar5 = __isoc23_sscanf(buffer + 0xb,((char *)0x149eb2 /* "%llu kB" */),&parsed_);
          if (iVar5 == 1) {
            local_188 = parsed_;
          }
        }
        else if (((CONCAT17(buffer[7],
                            CONCAT16(buffer[6],
                                     CONCAT15(buffer[5],
                                              CONCAT14(buffer[4],
                                                       CONCAT13(buffer[3],
                                                                CONCAT12(buffer[2],
                                                                         CONCAT11(0x77,buffer[0]))))
                                             ))) == 0x6565724670617753) && (buffer[8] == ':')) &&
                (iVar5 = __isoc23_sscanf(buffer + 9,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)) {
          local_170 = parsed_;
        }
      }
      else if ((((buffer[1] == 'R') &&
                (CONCAT17(buffer[7],
                          CONCAT16(buffer[6],
                                   CONCAT15(buffer[5],
                                            CONCAT14(buffer[4],
                                                     CONCAT13(buffer[3],
                                                              CONCAT12(buffer[2],
                                                                       CONCAT11(0x52,buffer[0]))))))
                         ) == 0x6d69616c63655253)) &&
               (CONCAT26(buffer._11_2_,
                         CONCAT15(buffer[10],
                                  CONCAT14(buffer[9],
                                           CONCAT13(buffer[8],
                                                    CONCAT12(buffer[7],CONCAT11(buffer[6],buffer[5])
                                                            ))))) == 0x3a656c62616d6961)) &&
              (iVar5 = __isoc23_sscanf(buffer + 0xd,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)) {
        local_190 = parsed_;
      }
      break;
    case 'Z':
      if ((CONCAT13(buffer[3],CONCAT12(buffer[2],CONCAT11(buffer[1],buffer[0]))) == 0x6177735a) &&
         (CONCAT11(buffer[5],buffer[4]) == 0x3a70)) {
        iVar5 = __isoc23_sscanf(buffer + 6,((char *)0x149eb2 /* "%llu kB" */),&parsed_);
        if (iVar5 == 1) {
          local_158 = parsed_;
        }
      }
      else if ((CONCAT17(buffer[7],
                         CONCAT16(buffer[6],
                                  CONCAT15(buffer[5],
                                           CONCAT14(buffer[4],
                                                    CONCAT13(buffer[3],
                                                             CONCAT12(buffer[2],
                                                                      CONCAT11(buffer[1],buffer[0]))
                                                            ))))) == 0x646570706177735a) &&
              ((buffer[8] == ':' &&
               (iVar5 = __isoc23_sscanf(buffer + 9,((char *)0x149eb2 /* "%llu kB" */),&parsed_), iVar5 == 1)))) {
        local_168 = parsed_;
      }
    }
  }
  fclose(pFVar10);
  (super->super).totalMem = uVar14;
                    /* Unresolved local var: DIR * dir@[???]
                       Unresolved local var: dirent * entry@[???]
                       Unresolved local var: uint i@[???] */
  *(undefined4 *)super->usedHugePageMem = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 4) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 1) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xc) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 2) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x14) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 3) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x1c) = 0xffffffff;
  (super->super).sharedMem = local_178;
  (super->super).buffersMem = local_148;
  (super->super).cachedMem = (local_150 + local_190) - local_178;
  *(undefined4 *)(super->usedHugePageMem + 4) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x24) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 5) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x2c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 6) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x34) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 7) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x3c) = 0xffffffff;
  uVar12 = local_160 + local_148 + local_150 + local_190;
  *(undefined4 *)(super->usedHugePageMem + 8) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x44) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 9) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x4c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 10) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x54) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xb) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x5c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xc) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 100) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xd) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x6c) = 0xffffffff;
  if (uVar14 < uVar12) {
    uVar12 = local_160;
  }
  *(undefined4 *)(super->usedHugePageMem + 0xe) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x74) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0xf) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x7c) = 0xffffffff;
  (super->super).cachedSwap = local_188;
  (super->super).usedMem = uVar14 - uVar12;
  *(undefined4 *)(super->usedHugePageMem + 0x10) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x84) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x11) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x8c) = 0xffffffff;
  super->totalHugePageMem = 0;
  if (local_140 <= uVar14) {
    uVar14 = local_140;
  }
  if (local_140 == 0) {
    uVar14 = local_160;
  }
  (super->super).totalSwap = local_180;
  (super->super).usedSwap = local_180 - (local_170 + local_188);
  (super->super).availableMem = uVar14;
  (super->zswap).usedZswapComp = local_158;
  (super->zswap).usedZswapOrig = local_168;
  *(undefined4 *)(super->usedHugePageMem + 0x12) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x94) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x13) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0x9c) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x14) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xa4) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x15) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xac) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x16) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xb4) = 0xffffffff;
  *(undefined4 *)(super->usedHugePageMem + 0x17) = 0xffffffff;
  *(undefined4 *)((long)super->usedHugePageMem + 0xbc) = 0xffffffff;
  __dirp = opendir(((char *)0x149f1d /* "/sys/kernel/mm/hugepages" */));
  if (__dirp != (DIR_2 *)0x0) {
LAB_00142030:
    pdVar13 = readdir(__dirp);
    if (pdVar13 != (dirent *)0x0) {
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: ulong hugePageSize@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: memory_t total@[???]
                       Unresolved local var: memory_t free@[???]
                       Unresolved local var: wchar_t shift@[???] */
      while ((pdVar13->d_type & 0xfb) == 0) {
        pcVar11 = pdVar13->d_name;
        iVar5 = strncmp(pcVar11,((char *)0x149f36 /* "hugepages-" */),10);
        if (((iVar5 != 0) ||
            (uVar14 = __isoc23_strtoul(pdVar13->d_name + 10,(char **)&parsed_,10), parsed_ == 0)) ||
           (*(char *)parsed_ != 'k')) break;
        xSnprintf(buffer,0x80,((char *)0x14cc50 /* "/sys/kernel/mm/hugepages/%s/nr_hugepages" */),pcVar11);
                    /* Unresolved local var: wchar_t fd@[???] */
        wVar6 = open(buffer,0);
        if (wVar6 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
          piVar17 = __errno_location();
          lVar15 = (long)-*piVar17;
        }
        else {
          lVar15 = readfd_internal(wVar6,content,0x40);
        }
        if ((lVar15 < 1) || (uVar12 = __isoc23_strtoull(content,(char **)0x0,10), uVar12 == 0))
        break;
        xSnprintf(buffer,0x80,((char *)0x14cc80 /* "/sys/kernel/mm/hugepages/%s/free_hugepages" */),pcVar11);
                    /* Unresolved local var: wchar_t fd@[???] */
        wVar6 = open(buffer,0);
        if (wVar6 < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
          piVar17 = __errno_location();
          lVar15 = (long)-*piVar17;
        }
        else {
          lVar15 = readfd_internal(wVar6,content,0x40);
        }
        if (lVar15 < 1) break;
        uVar16 = __isoc23_strtoull(content,(char **)0x0,10);
        iVar5 = ffsl(uVar14);
        super->totalHugePageMem = super->totalHugePageMem + uVar14 * uVar12;
        super->usedHugePageMem[iVar5 + -7] = (uVar12 - uVar16) * uVar14;
        pdVar13 = readdir(__dirp);
        if (pdVar13 == (dirent *)0x0) goto LAB_001421c0;
      }
      goto LAB_00142030;
    }
LAB_001421c0:
    closedir(__dirp);
  }
                    /* Unresolved local var: FILE * file@[???] */
  dbufSize = 0;
  dnodeSize = 0;
  parsed_ = 0;
  pFVar10 = fopen(((char *)0x149f41 /* "/proc/spl/kstat/zfs/arcstats" */),((char *)0x147760 /* "r" */));
  if (pFVar10 == (FILE_2 *)0x0) {
    (super->zfs).enabled = L'\0';
  }
  else {
                    /* Unresolved local var: size_t sz@[???] */
    while (pcVar11 = fgets(buffer,0x80,pFVar10), pcVar11 != (char *)0x0) {
      switch(buffer[0]) {
      case 'a':
        if ((CONCAT17(buffer[7],
                      CONCAT16(buffer[6],
                               CONCAT15(buffer[5],
                                        CONCAT14(buffer[4],
                                                 CONCAT13(buffer[3],
                                                          CONCAT12(buffer[2],
                                                                   CONCAT11(buffer[1],buffer[0])))))
                              )) == 0x7a69735f6e6f6e61) && (buffer[8] == 'e')) {
          __isoc23_sscanf(buffer + 9,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).anon);
        }
        break;
      case 'b':
        if ((CONCAT17(buffer[7],
                      CONCAT16(buffer[6],
                               CONCAT15(buffer[5],
                                        CONCAT14(buffer[4],
                                                 CONCAT13(buffer[3],
                                                          CONCAT12(buffer[2],
                                                                   CONCAT11(buffer[1],buffer[0])))))
                              )) == 0x69735f73756e6f62) && (CONCAT11(buffer[9],buffer[8]) == 0x657a)
           ) {
          __isoc23_sscanf(buffer + 10,((char *)0x149f64 /* " %*2u %32llu" */),&parsed_);
        }
        break;
      case 'c':
        if ((CONCAT13(buffer[3],CONCAT12(buffer[2],CONCAT11(buffer[1],buffer[0]))) == 0x696d5f63) &&
           (buffer[4] == 'n')) {
          __isoc23_sscanf(buffer + 5,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).min);
        }
        else if ((CONCAT13(buffer[3],CONCAT12(buffer[2],CONCAT11(buffer[1],buffer[0]))) ==
                  0x616d5f63) && (buffer[4] == 'x')) {
          __isoc23_sscanf(buffer + 5,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).max);
        }
        else if ((CONCAT17(buffer[7],
                           CONCAT16(buffer[6],
                                    CONCAT15(buffer[5],
                                             CONCAT14(buffer[4],
                                                      CONCAT13(buffer[3],
                                                               CONCAT12(buffer[2],
                                                                        CONCAT11(buffer[1],buffer[0]
                                                                                ))))))) ==
                  0x73736572706d6f63) &&
                (CONCAT26(buffer._13_2_,
                          CONCAT24(buffer._11_2_,
                                   CONCAT13(buffer[10],
                                            CONCAT12(buffer[9],CONCAT11(buffer[8],buffer[7]))))) ==
                 0x657a69735f646573)) {
          wVar6 = __isoc23_sscanf(buffer + 0xf,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).compressed);
          (super->zfs).isCompressed = wVar6;
        }
        break;
      case 'd':
        if ((CONCAT17(buffer[7],
                      CONCAT16(buffer[6],
                               CONCAT15(buffer[5],
                                        CONCAT14(buffer[4],
                                                 CONCAT13(buffer[3],
                                                          CONCAT12(buffer[2],
                                                                   CONCAT11(buffer[1],buffer[0])))))
                              )) == 0x7a69735f66756264) && (buffer[8] == 'e')) {
          __isoc23_sscanf(buffer + 9,((char *)0x149f64 /* " %*2u %32llu" */),&dbufSize);
        }
        else if ((CONCAT17(buffer[7],
                           CONCAT16(buffer[6],
                                    CONCAT15(buffer[5],
                                             CONCAT14(buffer[4],
                                                      CONCAT13(buffer[3],
                                                               CONCAT12(buffer[2],
                                                                        CONCAT11(buffer[1],buffer[0]
                                                                                ))))))) ==
                  0x69735f65646f6e64) && (CONCAT11(buffer[9],buffer[8]) == 0x657a)) {
          __isoc23_sscanf(buffer + 10,((char *)0x149f64 /* " %*2u %32llu" */),&dnodeSize);
        }
        break;
      case 'h':
        if (CONCAT17(buffer[7],
                     CONCAT16(buffer[6],
                              CONCAT15(buffer[5],
                                       CONCAT14(buffer[4],
                                                CONCAT13(buffer[3],
                                                         CONCAT12(buffer[2],
                                                                  CONCAT11(buffer[1],buffer[0]))))))
                    ) == 0x657a69735f726468) {
          __isoc23_sscanf(buffer + 8,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).header);
        }
        break;
      case 'm':
        if (CONCAT17(buffer[7],
                     CONCAT16(buffer[6],
                              CONCAT15(buffer[5],
                                       CONCAT14(buffer[4],
                                                CONCAT13(buffer[3],
                                                         CONCAT12(buffer[2],
                                                                  CONCAT11(buffer[1],buffer[0]))))))
                    ) == 0x657a69735f75666d) {
          __isoc23_sscanf(buffer + 8,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).MFU);
        }
        else if (CONCAT17(buffer[7],
                          CONCAT16(buffer[6],
                                   CONCAT15(buffer[5],
                                            CONCAT14(buffer[4],
                                                     CONCAT13(buffer[3],
                                                              CONCAT12(buffer[2],
                                                                       CONCAT11(buffer[1],buffer[0])
                                                                      )))))) == 0x657a69735f75726d)
        {
          __isoc23_sscanf(buffer + 8,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).MRU);
        }
        break;
      case 's':
        if (CONCAT13(buffer[3],CONCAT12(buffer[2],CONCAT11(buffer[1],buffer[0]))) == 0x657a6973) {
          __isoc23_sscanf(buffer + 4,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).size);
        }
        break;
      case 'u':
        if ((CONCAT17(buffer[7],
                      CONCAT16(buffer[6],
                               CONCAT15(buffer[5],
                                        CONCAT14(buffer[4],
                                                 CONCAT13(buffer[3],
                                                          CONCAT12(buffer[2],
                                                                   CONCAT11(buffer[1],buffer[0])))))
                              )) == 0x6572706d6f636e75 &&
             CONCAT17(buffer[0xf],
                      CONCAT25(buffer._13_2_,
                               CONCAT23(buffer._11_2_,
                                        CONCAT12(buffer[10],CONCAT11(buffer[9],buffer[8]))))) ==
             0x7a69735f64657373) && (buffer[0x10] == 'e')) {
          __isoc23_sscanf(buffer + 0x11,((char *)0x149f64 /* " %*2u %32llu" */),&(super->zfs).uncompressed);
        }
      }
    }
    fclose(pFVar10);
    puVar1 = &(super->zfs).header;
    *puVar1 = *puVar1 >> 10;
    (super->zfs).enabled = (uint)((super->zfs).size != 0);
    (super->zfs).min = (super->zfs).min >> 10;
    (super->zfs).max = (super->zfs).max >> 10;
    (super->zfs).size = (super->zfs).size >> 10;
    (super->zfs).MFU = (super->zfs).MFU >> 10;
    (super->zfs).MRU = (super->zfs).MRU >> 10;
    (super->zfs).anon = (super->zfs).anon >> 10;
    (super->zfs).other = dnodeSize + dbufSize + parsed_ >> 10;
    if ((super->zfs).isCompressed != L'\0') {
      (super->zfs).compressed = (super->zfs).compressed >> 10;
      (super->zfs).uncompressed = (super->zfs).uncompressed >> 10;
    }
  }
                    /* Unresolved local var: memory_t totalZram@[???]
                       Unresolved local var: memory_t usedZramComp@[???]
                       Unresolved local var: memory_t usedZramOrig@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: FILE * disksize_file@[???]
                       Unresolved local var: FILE * mm_stat_file@[???] */
  uVar14 = 0;
  uVar12 = 0;
  local_150 = 0;
  iVar5 = 0;
  while( true ) {
    xSnprintf(content,0x22,((char *)0x149fce /* "/sys/block/zram%u/mm_stat" */),iVar5);
    xSnprintf(buffer,0x22,((char *)0x149fe8 /* "/sys/block/zram%u/disksize" */),iVar5);
    pFVar10 = fopen(buffer,((char *)0x147760 /* "r" */));
    __stream = fopen(content,((char *)0x147760 /* "r" */));
    if (pFVar10 == (FILE_2 *)0x0) break;
    if (__stream == (FILE_2 *)0x0) {
      if (pFVar10 != (FILE_2 *)0x0) {
        fclose(pFVar10);
      }
      break;
    }
    dbufSize = 0;
    dnodeSize = 0;
    parsed_ = 0;
    iVar7 = __isoc23_fscanf(pFVar10,((char *)0x14a003 /* "%llu\n" */),&dbufSize);
    if ((iVar7 == 0) ||
       (iVar7 = __isoc23_fscanf(__stream,((char *)0x14a009 /* "    %llu       %llu" */),&dnodeSize,&parsed_), iVar7 == 0)) {
      fclose(pFVar10);
      goto LAB_001426af;
    }
    uVar12 = uVar12 + dbufSize;
    local_150 = local_150 + parsed_;
    uVar14 = uVar14 + dnodeSize;
    fclose(pFVar10);
    fclose(__stream);
    iVar5 = iVar5 + 1;
  }
  if (__stream != (FILE_2 *)0x0) {
LAB_001426af:
    fclose(__stream);
  }
  (super->zram).totalZram = uVar12 >> 10;
  uVar14 = uVar14 >> 10;
  (super->zram).usedZramOrig = uVar14;
  uVar12 = local_150 >> 10;
  if (uVar14 < local_150 >> 10) {
    uVar12 = uVar14;
  }
  (super->zram).usedZramComp = uVar12;
  LinuxMachine_scanCPUTime(super);
  pSVar4 = (super->super).settings;
  if (pSVar4->showCPUFrequency != false) {
                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: uint i@[???] */
    uVar2 = (super->super).existingCPUs;
    pCVar18 = super->cpuData;
    uVar8 = 0;
    do {
      uVar14 = (ulong)uVar8;
      uVar8 = uVar8 + 1;
      pCVar18[uVar14].frequency = NAN;
    } while (uVar8 <= uVar2);
                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: wchar_t numCPUsWithFrequency@[???]
                       Unresolved local var: ulong totalFrequency@[???] */
    if (timeout_0 < 1) {
                    /* Unresolved local var: uint i@[???] */
      uVar14 = 0;
                    /* Unresolved local var: FILE * file@[???] */
      if (uVar2 != 0) {
        local_150 = 0;
        iVar5 = 0;
        while( true ) {
          iVar7 = (int)uVar14;
                    /* Unresolved local var: LinuxMachine * this@[???] */
          uVar14 = (ulong)(iVar7 + 1U);
          if (pCVar18[uVar14].online != false) {
            xSnprintf(buffer,0x40,((char *)0x14ccb0 /* "/sys/devices/system/cpu/cpu%u/cpufreq/scaling_cur_freq" */),iVar7);
            if (iVar7 == 0) {
              clock_gettime(1,(timespec_2 *)&dnodeSize);
            }
            pFVar10 = fopen(buffer,((char *)0x147760 /* "r" */));
            if (pFVar10 == (FILE_2 *)0x0) {
              piVar17 = __errno_location();
              if (*piVar17 == 0) goto LAB_00142705;
              goto LAB_00142b15;
            }
            iVar9 = __isoc23_fscanf(pFVar10,((char *)0x14975f /* "%lu" */),&dbufSize);
            if (iVar9 == 1) {
              iVar5 = iVar5 + 1;
              dbufSize = dbufSize / 1000;
              local_150 = local_150 + dbufSize;
              super->cpuData[uVar14].frequency = (double)dbufSize;
            }
            fclose(pFVar10);
                    /* Unresolved local var: time_t timeTakenUs@[???] */
            if ((iVar7 == 0) &&
               (clock_gettime(1,(timespec_2 *)&parsed_),
               500 < (long)((parsed_ - dnodeSize) * 1000000 + (local_110 - local_120) / 1000))) {
              timeout_0 = 0x1e;
              goto LAB_00142b15;
            }
          }
          if ((super->super).existingCPUs <= iVar7 + 1U) break;
          pCVar18 = super->cpuData;
        }
        if (0 < iVar5) {
          super->cpuData->frequency = (double)local_150 / (double)iVar5;
        }
      }
    }
    else {
      timeout_0 = timeout_0 + -1;
LAB_00142b15:
      scanCPUFrequencyFromCPUinfo(super);
    }
  }
LAB_00142705:
  if (pSVar4->showCPUTemperature == false) {
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else {
                    /* Unresolved local var: LinuxMachine * this@[???]
                       Unresolved local var: Settings * settings@[???] */
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      LibSensors_getCPUTemperatures
                (super->cpuData,(super->super).existingCPUs,(super->super).activeCPUs);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

