/* LinuxMachine_scanCPUTime @ 001415f0 size 1477 */

/* DWARF original prototype: void LinuxMachine_scanCPUTime(LinuxMachine * this) */

void LinuxMachine_scanCPUTime(LinuxMachine *this)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  CPUData *pCVar4;
  FILE_2 *__stream;
  char *pcVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  undefined8 *puVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  long in_FS_OFFSET;
  byte bVar20;
  uint local_10b4;
  uint cpuid;
  ulonglong guestnice;
  ulonglong guest;
  ulonglong steal;
  ulonglong softIrq;
  ulonglong irq;
  ulonglong ioWait;
  ulonglong idletime;
  ulonglong systemtime;
  ulonglong nicetime;
  ulonglong usertime;
  char buffer [4097];

                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: uint lastAdjCpuId@[???] */
  bVar20 = 0;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  LinuxMachine_updateCPUcount(this);
  __stream = fopen(((char *)0x149e71 /* "/proc/stat" */),((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)0x149e65 /* "Cannot open /proc/stat" */));
  }
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: char * ok@[???]
                       Unresolved local var: uint adjCpuId@[???]
                       Unresolved local var: ulonglong idlealltime@[???]
                       Unresolved local var: ulonglong systemalltime@[???]
                       Unresolved local var: ulonglong virtalltime@[???]
                       Unresolved local var: ulonglong totaltime@[???]
                       Unresolved local var: CPUData * cpuData@[???] */
  uVar11 = 0;
  local_10b4 = 0;
  do {
                    /* Unresolved local var: size_t sz@[???] */
    ioWait = 0;
    irq = 0;
    softIrq = 0;
    steal = 0;
    guest = 0;
    guestnice = 0;
    pcVar5 = fgets(buffer,0x1001,__stream);
    if (((pcVar5 == (char *)0x0) || (buffer._0_2_ != 0x7063)) || (buffer[2] != 'u')) {
LAB_001416e7:
      uVar6 = this->cpuData->totalPeriod;
      goto code_r0x00141a59;
    }
    if (uVar11 == 0) {
      __isoc23_sscanf(buffer,
                      ((char *)0x14cbb0 /* "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu" */),
                      &usertime,&nicetime,&systemtime,&idletime,&ioWait,&irq,&softIrq,&steal,&guest,
                      &guestnice);
                    /* Unresolved local var: uint j@[???] */
      uVar18 = (this->super).existingCPUs;
      lVar9 = 0;
      local_10b4 = 0;
      uVar1 = local_10b4;
    }
    else {
      __isoc23_sscanf(buffer,
                      ((char *)0x14cc00 /* "cpu%4u %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu" */)
                      ,&cpuid,&usertime,&nicetime,&systemtime,&idletime,&ioWait,&irq,&softIrq,&steal
                      ,&guest,&guestnice);
      uVar18 = (this->super).existingCPUs;
      uVar1 = cpuid + 1;
      if (uVar18 < uVar1) goto LAB_001416e7;
      uVar2 = local_10b4 + 1;
      lVar9 = (ulong)uVar1 * 0xd8;
      if (uVar2 < uVar1) {
        lVar13 = (ulong)uVar2 * 0xd8;
        do {
          puVar15 = (undefined8 *)((long)&this->cpuData->totalTime + lVar13);
          lVar13 = lVar13 + 0xd8;
          *puVar15 = 0;
          puVar15[0x1a] = 0;
          uVar6 = (ulong)(((int)puVar15 -
                          (int)(undefined8 *)((ulong)(puVar15 + 1) & 0xfffffffffffffff8)) + 0xd8U >>
                         3);
          puVar15 = (undefined8 *)((ulong)(puVar15 + 1) & 0xfffffffffffffff8);
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar15 = 0;
            puVar15 = puVar15 + (ulong)bVar20 * -2 + 1;
          }
        } while (((ulong)uVar2 + 1 + (ulong)((cpuid - 1) - local_10b4)) * 0xd8 != lVar13);
        uVar18 = (this->super).existingCPUs;
      }
    }
    local_10b4 = uVar1;
    uVar19 = idletime + ioWait;
    uVar16 = nicetime - guestnice;
    uVar17 = usertime - guest;
    uVar12 = guest + guestnice;
    pCVar4 = this->cpuData;
    puVar7 = (ulong *)((long)&pCVar4->totalTime + lVar9);
    uVar10 = 0;
    uVar14 = systemtime + irq + softIrq;
    uVar8 = uVar17 + uVar16 + steal + uVar19 + uVar12 + uVar14;
    uVar6 = uVar17 - puVar7[1];
    if (uVar17 <= puVar7[1]) {
      uVar6 = uVar10;
    }
    puVar7[0xd] = uVar6;
    uVar6 = uVar16 - puVar7[6];
    if (uVar16 <= puVar7[6]) {
      uVar6 = uVar10;
    }
    puVar7[0x12] = uVar6;
    uVar6 = systemtime - puVar7[2];
    if (systemtime <= puVar7[2]) {
      uVar6 = uVar10;
    }
    puVar7[0xe] = uVar6;
    uVar6 = uVar14 - puVar7[3];
    if (uVar14 <= puVar7[3]) {
      uVar6 = uVar10;
    }
    puVar7[0xf] = uVar6;
    uVar6 = uVar19 - puVar7[4];
    if (uVar19 <= puVar7[4]) {
      uVar6 = uVar10;
    }
    puVar7[0x10] = uVar6;
    uVar6 = idletime - puVar7[5];
    if (idletime <= puVar7[5]) {
      uVar6 = uVar10;
    }
    puVar7[0x11] = uVar6;
    uVar6 = ioWait - puVar7[7];
    if (ioWait <= puVar7[7]) {
      uVar6 = uVar10;
    }
    puVar7[0x13] = uVar6;
    puVar7[1] = uVar17;
    puVar7[6] = uVar16;
    puVar7[3] = uVar14;
    uVar6 = irq - puVar7[8];
    if (irq <= puVar7[8]) {
      uVar6 = uVar10;
    }
    puVar7[4] = uVar19;
    puVar7[0x14] = uVar6;
    uVar6 = softIrq - puVar7[9];
    if (softIrq <= puVar7[9]) {
      uVar6 = uVar10;
    }
    puVar7[0x15] = uVar6;
    uVar6 = steal - puVar7[10];
    if (steal <= puVar7[10]) {
      uVar6 = uVar10;
    }
    puVar7[0x16] = uVar6;
    uVar6 = uVar12 - puVar7[0xb];
    if (uVar12 <= puVar7[0xb]) {
      uVar6 = uVar10;
    }
    puVar7[0x17] = uVar6;
    uVar6 = uVar8 - *puVar7;
    if (uVar8 <= *puVar7) {
      uVar6 = uVar10;
    }
    uVar11 = uVar11 + 1;
    puVar7[2] = systemtime;
    puVar7[0xc] = uVar6;
    puVar7[5] = idletime;
    puVar7[7] = ioWait;
    puVar7[8] = irq;
    puVar7[9] = softIrq;
    puVar7[10] = steal;
    puVar7[0xb] = uVar12;
    *puVar7 = uVar8;
  } while (uVar11 <= uVar18);
  uVar6 = pCVar4->totalPeriod;
code_r0x00141a59:
  this->period = (double)uVar6 / (double)(this->super).activeCPUs;
  do {
                    /* Unresolved local var: size_t sz@[???] */
    pcVar5 = fgets(buffer,0x1001,__stream);
    if (pcVar5 == (char *)0x0) goto LAB_0014177e;
  } while ((CONCAT35(buffer._5_3_,CONCAT23(buffer._3_2_,CONCAT12(buffer[2],buffer._0_2_))) !=
            0x75725f73636f7270) || (CONCAT53(buffer._8_5_,buffer._5_3_) != 0x676e696e6e75725f));
  uVar6 = __isoc23_strtoul(buffer + 0xd,(char **)0x0,10);
  this->runningTasks = (uint)uVar6;
LAB_0014177e:
  fclose(__stream);
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

