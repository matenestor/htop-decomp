/* MemorySwapMeter_init @ 00123640 size 244 */

/* DWARF original prototype: void MemorySwapMeter_init(Meter * this) */

void MemorySwapMeter_init(Meter *this)

{
  code *pcVar1;
  wchar_t wVar2;
  Meter_3 *pMVar3;
  undefined1 (*pauVar4) [16];
  long in_RCX;
  long in_RDX;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long in_RSI;
  long *a0;
  long in_R8;
  long in_R9;

  pauVar4 = this->meterData;
  if (pauVar4 == (undefined1 (*) [16])0x0) {
                    /* Unresolved local var: void * data@[???] */
    pauVar4 = malloc(0x10);
    if (pauVar4 == (undefined1 (*) [16])0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->meterData = pauVar4;
    *pauVar4 = (undefined1  [16])0x0;
  }
  else if (*(long *)*pauVar4 != 0) goto LAB_00123668;
  in_RSI = 0;
  pMVar3 = Meter_new((Machine_2 *)this->host,0,&MemoryMeter_class);
  *(Meter_3 **)*pauVar4 = pMVar3;
  in_RDX = extraout_RDX_01;
LAB_00123668:
  if (*(long *)(*pauVar4 + 8) == 0) {
    in_RSI = 0;
    pMVar3 = Meter_new((Machine_2 *)this->host,0,&SwapMeter_class);
    *(Meter_3 **)(*pauVar4 + 8) = pMVar3;
    in_RDX = extraout_RDX_00;
  }
  pcVar1 = *(code **)(**(long **)*pauVar4 + 0x20);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)((long)*(long **)*pauVar4,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    in_RDX = extraout_RDX;
  }
  a0 = *(long **)(*pauVar4 + 8);
  if (*(code **)(*a0 + 0x20) != (code *)0x0) {
    (**(code **)(*a0 + 0x20))((long)a0,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    a0 = *(long **)(*pauVar4 + 8);
  }
  if (this->mode == L'\0') {
    this->mode = L'\x01';
  }
  wVar2 = Meter_modes[*(int *)(*(long *)*pauVar4 + 0x20)]->h;
  if (Meter_modes[*(int *)(*(long *)*pauVar4 + 0x20)]->h < Meter_modes[(int)a0[4]]->h) {
    wVar2 = Meter_modes[(int)a0[4]]->h;
  }
  this->h = wVar2;
  return;
}

