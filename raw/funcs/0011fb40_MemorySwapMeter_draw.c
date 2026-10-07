/* MemorySwapMeter_draw @ 0011fb40 size 110 */

/* DWARF original prototype: void MemorySwapMeter_draw(Meter * this, wchar_t x, wchar_t y, wchar_t
   w) */

void MemorySwapMeter_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  long *plVar1;
  long lVar2;
  undefined4 in_register_00000014;
  undefined4 in_register_00000034;
  long in_R8;
  long in_R9;
  uint uVar3;

                    /* Unresolved local var: MemorySwapMeterData * data@[???]
                       Unresolved local var: wchar_t colwidth@[???]
                       Unresolved local var: wchar_t diff@[???] */
  uVar3 = w / 2;
  plVar1 = this->meterData;
  lVar2 = *plVar1;
  (**(code **)(lVar2 + 8))
            (lVar2,CONCAT44(in_register_00000034,x),CONCAT44(in_register_00000014,y),(ulong)uVar3,
             in_R8,in_R9);
  lVar2 = plVar1[1];
                    /* WARNING: Could not recover jumptable at 0x0011fbac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar2 + 8))
            (lVar2,(ulong)(uint)(uVar3 + x + w % 2),(ulong)(uint)y,(ulong)uVar3,in_R8,in_R9);
  return;
}

