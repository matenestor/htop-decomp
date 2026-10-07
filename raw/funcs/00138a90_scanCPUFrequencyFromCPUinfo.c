/* scanCPUFrequencyFromCPUinfo @ 00138a90 size 511 */

/* DWARF original prototype: void scanCPUFrequencyFromCPUinfo(LinuxMachine * this) */

void scanCPUFrequencyFromCPUinfo(LinuxMachine *this)

{
  long lVar1;
  int iVar2;
  FILE_2 *__stream;
  char *pcVar3;
  long in_FS_OFFSET;
  int local_1064;
  double local_1060;
  wchar_t cpuid;
  double frequency;
  char buffer [4096];

                    /* Unresolved local var: Machine * super@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: wchar_t numCPUsWithFrequency@[???]
                       Unresolved local var: double totalFrequency@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)0x1496f6 /* "/proc/cpuinfo" */),((char *)0x147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    cpuid = L'\xffffffff';
                    /* Unresolved local var: size_t sz@[???] */
    local_1060 = 0.0;
    local_1064 = 0;
LAB_00138b10:
    iVar2 = feof(__stream);
    if (iVar2 == 0) {
      while( true ) {
        pcVar3 = fgets(buffer,0x1000,__stream);
        if (pcVar3 == (char *)0x0) goto LAB_00138bc0;
        iVar2 = __isoc23_sscanf(buffer,((char *)0x149704 /* "processor : %d" */),&cpuid);
        if (iVar2 == 1) goto LAB_00138b10;
        iVar2 = __isoc23_sscanf(buffer,((char *)0x149713 /* "cpu MHz : %lf" */),&frequency);
        if ((iVar2 == 1) ||
           (iVar2 = __isoc23_sscanf(buffer,((char *)0x149721 /* "clock : %lfMHz" */),&frequency), iVar2 == 1)) break;
        if (buffer[0] != '\n') goto LAB_00138b10;
        cpuid = L'\xffffffff';
        iVar2 = feof(__stream);
        if (iVar2 != 0) goto LAB_00138bc0;
      }
                    /* Unresolved local var: CPUData * cpuData@[???] */
      if ((L'\xffffffff' < cpuid) &&
         ((uint)cpuid <= (uint)((this->super).existingCPUs + L'\xffffffff'))) {
        if (this->cpuData[(long)cpuid + 1].frequency < 0.0) {
          this->cpuData[(long)cpuid + 1].frequency = frequency;
        }
        local_1060 = frequency + local_1060;
        local_1064 = local_1064 + 1;
      }
      goto LAB_00138b10;
    }
LAB_00138bc0:
    fclose(__stream);
    if (0 < local_1064) {
      this->cpuData->frequency = local_1060 / (double)local_1064;
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

