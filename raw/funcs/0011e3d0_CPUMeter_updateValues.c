/* CPUMeter_updateValues @ 0011e3d0 size 729 */

/* DWARF original prototype: void CPUMeter_updateValues(Meter * this) */

void CPUMeter_updateValues(Meter *this)

{
  long lVar1;
  undefined1 (*pauVar2) [16];
  Settings__2 *pSVar3;
  char *pcVar4;
  undefined *va3;
  undefined *va1;
  long in_FS_OFFSET;
  double dVar5;
  char cpuUsageBuffer [8];
  char cpuTemperatureBuffer [16];
  char cpuFrequencyBuffer [16];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pauVar2 = (undefined1 (*) [16])this->values;
  *pauVar2 = (undefined1  [16])0x0;
  pauVar2[1] = (undefined1  [16])0x0;
  pauVar2[2] = (undefined1  [16])0x0;
  pauVar2[3] = (undefined1  [16])0x0;
  pauVar2[4] = (undefined1  [16])0x0;
  pSVar3 = this->host->settings;
  if (this->host->existingCPUs < this->param) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar4 = ((char *)0x147648 /* " absent" */);
LAB_0011e5be:
      xSnprintf(this->txtBuffer,0x100,pcVar4 + 1);
      return;
    }
    goto LAB_0011e6cb;
  }
  dVar5 = Platform_setCPUValues(this,this->param);
  if (dVar5 < 0.0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar4 = ((char *)0x147650 /* " offline" */);
      goto LAB_0011e5be;
    }
    goto LAB_0011e6cb;
  }
  cpuUsageBuffer[0] = '\0';
  cpuUsageBuffer[1] = '\0';
  cpuUsageBuffer[2] = '\0';
  cpuUsageBuffer[3] = '\0';
  cpuUsageBuffer[4] = '\0';
  cpuUsageBuffer[5] = '\0';
  cpuUsageBuffer[6] = '\0';
  cpuUsageBuffer[7] = '\0';
  cpuFrequencyBuffer[0] = '\0';
  cpuFrequencyBuffer[1] = '\0';
  cpuFrequencyBuffer[2] = '\0';
  cpuFrequencyBuffer[3] = '\0';
  cpuFrequencyBuffer[4] = '\0';
  cpuFrequencyBuffer[5] = '\0';
  cpuFrequencyBuffer[6] = '\0';
  cpuFrequencyBuffer[7] = '\0';
  cpuFrequencyBuffer[8] = '\0';
  cpuFrequencyBuffer[9] = '\0';
  cpuFrequencyBuffer[10] = '\0';
  cpuFrequencyBuffer[0xb] = '\0';
  cpuFrequencyBuffer[0xc] = '\0';
  cpuFrequencyBuffer[0xd] = '\0';
  cpuFrequencyBuffer[0xe] = '\0';
  cpuFrequencyBuffer[0xf] = '\0';
  cpuTemperatureBuffer[0] = '\0';
  cpuTemperatureBuffer[1] = '\0';
  cpuTemperatureBuffer[2] = '\0';
  cpuTemperatureBuffer[3] = '\0';
  cpuTemperatureBuffer[4] = '\0';
  cpuTemperatureBuffer[5] = '\0';
  cpuTemperatureBuffer[6] = '\0';
  cpuTemperatureBuffer[7] = '\0';
  cpuTemperatureBuffer[8] = '\0';
  cpuTemperatureBuffer[9] = '\0';
  cpuTemperatureBuffer[10] = '\0';
  cpuTemperatureBuffer[0xb] = '\0';
  cpuTemperatureBuffer[0xc] = '\0';
  cpuTemperatureBuffer[0xd] = '\0';
  cpuTemperatureBuffer[0xe] = '\0';
  cpuTemperatureBuffer[0xf] = '\0';
  if (pSVar3->showCPUUsage == false) {
    if (pSVar3->showCPUFrequency == false) goto LAB_0011e49e;
LAB_0011e469:
                    /* Unresolved local var: double cpuFrequency@[???] */
    if (0.0 <= this->values[8]) {
      xSnprintf(cpuFrequencyBuffer,0x10,((char *)0x147629 /* "%4uMHz" */),(int)(long)this->values[8]);
      goto LAB_0011e49e;
    }
    xSnprintf(cpuFrequencyBuffer,0x10,((char *)0x1474de /* "N/A" */));
    if (pSVar3->showCPUTemperature != false) goto LAB_0011e4aa;
LAB_0011e508:
    if (cpuFrequencyBuffer[0] == '\0') goto LAB_0011e578;
LAB_0011e512:
    if (cpuTemperatureBuffer[0] == '\0') {
      va3 = &DAT_00149c0c;
      va1 = &DAT_001470dd;
      if (cpuUsageBuffer[0] == '\0') {
        va1 = &DAT_00149c0c;
      }
    }
    else {
      va3 = &DAT_001470dd;
      va1 = &DAT_00149c0c;
      if (cpuUsageBuffer[0] != '\0') {
        va1 = &DAT_001470dd;
      }
    }
  }
  else {
    xSnprintf(cpuUsageBuffer,8,((char *)0x1476eb /* "%.1f%%" */),dVar5);
    if (pSVar3->showCPUFrequency != false) goto LAB_0011e469;
LAB_0011e49e:
    if (pSVar3->showCPUTemperature == false) goto LAB_0011e508;
LAB_0011e4aa:
                    /* Unresolved local var: double cpuTemperature@[???] */
    dVar5 = this->values[9];
    if (NAN(dVar5)) {
      xSnprintf(cpuTemperatureBuffer,0x10,((char *)0x1474de /* "N/A" */));
      goto LAB_0011e508;
    }
    if (pSVar3->degreeFahrenheit != false) {
      xSnprintf(cpuTemperatureBuffer,0x10,((char *)0x147630 /* "%3d%sF" */),(int)((dVar5 * 9.0) / 5.0 + 32.0),CRT_degreeSign)
      ;
      goto LAB_0011e508;
    }
    xSnprintf(cpuTemperatureBuffer,0x10,((char *)0x147637 /* "%d%sC" */),(int)dVar5,CRT_degreeSign);
    if (cpuFrequencyBuffer[0] != '\0') goto LAB_0011e512;
LAB_0011e578:
    va3 = &DAT_00149c0c;
    va1 = va3;
    if (cpuUsageBuffer[0] != '\0') {
      va1 = &DAT_001470dd;
      if (cpuTemperatureBuffer[0] == '\0') {
        va1 = &DAT_00149c0c;
      }
    }
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x14763d /* "%s%s%s%s%s" */),cpuUsageBuffer,va1,cpuFrequencyBuffer,va3,
            cpuTemperatureBuffer);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0011e6cb:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

