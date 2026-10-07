/* CPUMeterCommonDraw @ 001140e0 size 202 */

/* DWARF original prototype: void CPUMeterCommonDraw(Meter * this, wchar_t x, wchar_t y, wchar_t w,
   wchar_t ncol) */

void CPUMeterCommonDraw(Meter *this,wchar_t x,wchar_t y,wchar_t w,wchar_t ncol)

{
  char cVar1;
  long *plVar2;
  long a0;
  long lVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 in_register_00000084;
  long in_R9;
  int iVar9;
  int iVar10;
  ulong uVar11;

                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: Meter * * meters@[???]
                       Unresolved local var: wchar_t start@[???]
                       Unresolved local var: wchar_t count@[???]
                       Unresolved local var: wchar_t colwidth@[???]
                       Unresolved local var: wchar_t diff@[???]
                       Unresolved local var: wchar_t nrows@[???] */
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  plVar2 = *(long **)((long)this->meterData + 8);
  uVar7 = *(uint *)this->meterData;
  cVar1 = (char)*(uchar *)(this->super).klass[3].delete;
  if (cVar1 == 'L') {
    uVar7 = uVar7 + 1 >> 1;
  }
  else if (cVar1 == 'R') {
    uVar7 = uVar7 >> 1;
  }
  uVar8 = (w - ncol) / ncol + 1;
  iVar9 = w - ncol * uVar8;
  iVar10 = ((uVar7 - 1) + ncol) / ncol;
                    /* Unresolved local var: wchar_t i@[???] */
  if (0 < (int)uVar7) {
    uVar11 = 0;
    do {
                    /* Unresolved local var: wchar_t d@[???]
                       Unresolved local var: wchar_t xpos@[???]
                       Unresolved local var: wchar_t ypos@[???] */
      a0 = plVar2[uVar11];
      lVar3 = (long)iVar10;
      uVar4 = (ulong)(uint)((int)uVar11 >> 0x1f) << 0x20 | uVar11 & 0xffffffff;
      iVar5 = (int)((long)uVar4 / lVar3);
      iVar6 = iVar5;
      if (iVar9 < iVar5) {
        iVar6 = iVar9;
      }
      uVar11 = uVar11 + 1;
      (**(code **)(a0 + 8))
                (a0,(ulong)(uint)(iVar5 * uVar8 + x + iVar6),
                 (ulong)(uint)((int)((long)uVar4 % lVar3) * *(int *)(*plVar2 + 0x48) + y),
                 (ulong)uVar8,CONCAT44(in_register_00000084,ncol),in_R9);
    } while ((long)(int)uVar7 != uVar11);
  }
  return;
}

