/* ZramMeter_updateValues @ 001408a0 size 409 */

/* DWARF original prototype: void ZramMeter_updateValues(Meter * this) */

void ZramMeter_updateValues(Meter *this)

{
  Machine *pMVar1;
  Table *pTVar2;
  Table *pTVar3;
  double *pdVar4;
  wchar_t wVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;
  long lVar9;
  double value;

                    /* Unresolved local var: LinuxMachine * lhost@[???] */
  pMVar1 = this->host;
  pTVar2 = pMVar1[2].activeTable;
  this->total = (double)pMVar1[2].tables;
  value = (double)pTVar2;
  pTVar3 = pMVar1[2].processTable;
  pdVar4 = this->values;
  *pdVar4 = value;
  pdVar4[1] = (double)(ulong)((long)pTVar3 - (long)pTVar2);
  wVar5 = Meter_humanUnit(this->txtBuffer,value,0x100);
  if (L'\xffffffff' < wVar5) {
    uVar6 = (ulong)wVar5;
    if ((uVar6 < 0x100) && (uVar6 != 0xff)) {
      pcVar8 = this->txtBuffer + uVar6;
      pcVar8[0] = '(';
      pcVar8[1] = '\0';
      uVar6 = 0xff - uVar6;
      wVar5 = Meter_humanUnit(pcVar8 + 1,*this->values + this->values[1],uVar6);
      if ((L'\xffffffff' < wVar5) && (uVar7 = (ulong)wVar5, uVar7 < uVar6)) {
        lVar9 = uVar6 - uVar7;
        pcVar8 = pcVar8 + 1 + uVar7;
        if (lVar9 != 1) {
          *pcVar8 = ')';
          if (lVar9 != 2) {
            pcVar8[1] = '/';
            pcVar8[2] = '\0';
            Meter_humanUnit(pcVar8 + 2,this->total,lVar9 - 2);
            return;
          }
          pcVar8[1] = '\0';
        }
      }
    }
  }
  return;
}

