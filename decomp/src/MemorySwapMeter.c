#include "htop.h"

/* MemorySwapMeter_updateValues @ 0x11fb10 */

/* DWARF original prototype: void MemorySwapMeter_updateValues(Meter * this) */

void MemorySwapMeter_updateValues(Meter *this)

{
  long *plVar1;
  long *a0;
  long in_RCX;
  long in_RDX;
  long a2;
  long in_RSI;
  long in_R8;
  long in_R9;

  plVar1 = this->meterData;
  a0 = (long *)*plVar1;
  (**(code **)(*a0 + 0x38))((long)a0,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
  plVar1 = (long *)plVar1[1];
                    /* WARNING: Could not recover jumptable at 0x0011fb3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar1 + 0x38))((long)plVar1,in_RSI,a2,in_RCX,in_R8,in_R9);
  return;
}


/* MemorySwapMeter_draw @ 0x11fb40 */

/* DWARF original prototype: void MemorySwapMeter_draw(Meter * this, int x, int y, int
   w) */

void MemorySwapMeter_draw(Meter *this,int x,int y,int w)

{
  long *plVar1;
  long lVar2;
  undefined4 in_register_00000014;
  undefined4 in_register_00000034;
  long in_R8;
  long in_R9;
  uint uVar3;

                    /* Unresolved local var: MemorySwapMeterData * data@[???]
                       Unresolved local var: int colwidth@[???]
                       Unresolved local var: int diff@[???] */
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


/* MemorySwapMeter_done @ 0x11fe90 */

/* DWARF original prototype: void MemorySwapMeter_done(Meter * this) */

void MemorySwapMeter_done(Meter *this)

{
  undefined8 *__ptr;

  __ptr = this->meterData;
  Meter_delete((Meter_ *)__ptr[1]);
  Meter_delete((Meter_ *)*__ptr);
  free(__ptr);
  return;
}


/* MemorySwapMeter_updateMode @ 0x121500 */

/* DWARF original prototype: void MemorySwapMeter_updateMode(Meter * this, int mode) */

void MemorySwapMeter_updateMode(Meter *this,int mode)

{
  long *plVar1;
  int wVar2;

  plVar1 = this->meterData;
  this->mode = mode;
  Meter_setMode((Meter *)*plVar1,mode);
  Meter_setMode((Meter *)plVar1[1],mode);
  wVar2 = Meter_modes[*(int *)(plVar1[1] + 0x20)]->h;
  if (Meter_modes[*(int *)(plVar1[1] + 0x20)]->h < Meter_modes[*(int *)(*plVar1 + 0x20)]->h) {
    wVar2 = Meter_modes[*(int *)(*plVar1 + 0x20)]->h;
  }
  this->h = wVar2;
  return;
}


/* MemorySwapMeter_init @ 0x123640 */

/* DWARF original prototype: void MemorySwapMeter_init(Meter * this) */

void MemorySwapMeter_init(Meter *this)

{
  code *pcVar1;
  int wVar2;
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
    *(undefined16 *)(*pauVar4) = (undefined16)0x0;
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
  if (this->mode == 0) {
    this->mode = 1;
  }
  wVar2 = Meter_modes[*(int *)(*(long *)*pauVar4 + 0x20)]->h;
  if (Meter_modes[*(int *)(*(long *)*pauVar4 + 0x20)]->h < Meter_modes[(int)a0[4]]->h) {
    wVar2 = Meter_modes[(int)a0[4]]->h;
  }
  this->h = wVar2;
  return;
}

