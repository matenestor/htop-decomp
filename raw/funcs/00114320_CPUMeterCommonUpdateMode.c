/* CPUMeterCommonUpdateMode @ 00114320 size 366 */

/* DWARF original prototype: void CPUMeterCommonUpdateMode(Meter * this, wchar_t mode, wchar_t ncol)
    */

void CPUMeterCommonUpdateMode(Meter *this,wchar_t mode,wchar_t ncol)

{
  undefined8 *puVar1;
  char cVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  code *a5;
  Meter_Draw_3 p_Var5;
  wchar_t wVar6;
  ulong a3;
  undefined8 *extraout_RDX;
  undefined8 *a2;
  undefined8 *extraout_RDX_00;
  long lVar7;
  long in_R8;
  long *a0;
  undefined8 *puVar8;
  wchar_t local_3c;

                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: Meter * * meters@[???]
                       Unresolved local var: wchar_t h@[???]
                       Unresolved local var: wchar_t start@[???]
                       Unresolved local var: wchar_t count@[???] */
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  local_3c = *(wchar_t *)this->meterData;
  a2 = *(undefined8 **)((long)this->meterData + 8);
  this->mode = mode;
  cVar2 = (char)*(uchar *)(this->super).klass[3].delete;
  wVar3 = Meter_modes[mode]->h;
  if (cVar2 == 'L') {
    wVar6 = wVar3;
    local_3c = (uint)(local_3c + L'\x01') >> 1;
  }
  else {
    wVar6 = (uint)local_3c >> 1;
    if (cVar2 == 'R') {
      local_3c = wVar6;
    }
  }
  a3 = (ulong)(uint)wVar6;
                    /* Unresolved local var: wchar_t i@[???] */
  if (L'\0' < local_3c) {
    puVar1 = a2 + local_3c;
    puVar8 = a2;
    do {
      while( true ) {
        a0 = (long *)*puVar8;
        if (L'\0' < mode) break;
        lVar7 = *a0;
        a3 = 1;
        if (mode != L'\0') {
          a3 = (ulong)(uint)mode;
        }
        wVar6 = (wchar_t)a3;
        if (*(int *)(lVar7 + 0x58) == 0) goto LAB_001143b9;
LAB_00114401:
                    /* Unresolved local var: MeterMode * mode@[???] */
        puVar8 = puVar8 + 1;
        free((void *)a0[8]);
        a0[8] = 0;
        a0[7] = 0;
        p_Var5 = Meter_modes[wVar6]->draw;
        wVar4 = Meter_modes[wVar6]->h;
        *(wchar_t *)(a0 + 4) = wVar6;
        a0[1] = (long)p_Var5;
        *(wchar_t *)(a0 + 9) = wVar4;
        a2 = extraout_RDX_00;
        if (puVar1 == puVar8) goto LAB_00114449;
      }
      while (mode == *(wchar_t *)(a0 + 4)) {
        puVar8 = puVar8 + 1;
        if (puVar1 == puVar8) goto LAB_00114449;
        a0 = (long *)*puVar8;
      }
      lVar7 = *a0;
      wVar6 = mode;
      if (*(int *)(lVar7 + 0x58) != 0) goto LAB_00114401;
LAB_001143b9:
      a5 = *(code **)(lVar7 + 0x30);
      a0[1] = *(long *)(lVar7 + 0x40);
      if (a5 != (code *)0x0) {
        (*a5)((long)a0,(ulong)(uint)wVar6,(long)a2,a3,in_R8,(long)a5);
        a2 = extraout_RDX;
      }
      puVar8 = puVar8 + 1;
      *(wchar_t *)(a0 + 4) = wVar6;
    } while (puVar1 != puVar8);
  }
LAB_00114449:
  this->h = ((local_3c + L'\xffffffff' + ncol) / ncol) * wVar3;
  return;
}

