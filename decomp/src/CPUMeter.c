#include "htop.h"

/* AllCPUsMeter_updateValues @ 0x114070 */

/* DWARF original prototype: void AllCPUsMeter_updateValues(Meter * this) */

void AllCPUsMeter_updateValues(Meter *this)

{
  long *plVar1;
  byte bVar2;
  uint uVar3;
  long *a0;
  ulong uVar4;
  ulong a3;
  ulong a2;
  ulong extraout_RDX;
  long *plVar5;
  long in_RSI;
  long in_R8;
  long in_R9;

  plVar5 = *(long **)((long)this->meterData + 8);
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  uVar3 = *(uint *)this->meterData;
  a3 = (ulong)(int)uVar3;
  bVar2 = (byte)*(uchar *)(this->super).klass[3].delete;
  a2 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar4 = (ulong)(uVar3 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar3 >> 1);
    if (bVar2 != 0x52) {
      uVar4 = a3;
    }
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar4) {
    plVar1 = plVar5 + uVar4;
    do {
      a0 = (long *)*plVar5;
      plVar5 = plVar5 + 1;
      (**(code **)(*a0 + 0x38))((long)a0,in_RSI,a2,a3,in_R8,in_R9);
      a2 = extraout_RDX;
    } while (plVar1 != plVar5);
  }
  return;
}


/* CPUMeterCommonDraw @ 0x1140e0 */

/* DWARF original prototype: void CPUMeterCommonDraw(Meter * this, int x, int y, int w,
   int ncol) */

void CPUMeterCommonDraw(Meter *this,int x,int y,int w,int ncol)

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
                       Unresolved local var: int start@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int colwidth@[???]
                       Unresolved local var: int diff@[???]
                       Unresolved local var: int nrows@[???] */
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
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar7) {
    uVar11 = 0;
    do {
                    /* Unresolved local var: int d@[???]
                       Unresolved local var: int xpos@[???]
                       Unresolved local var: int ypos@[???] */
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


/* DualColCPUsMeter_draw @ 0x1141b0 */

/* DWARF original prototype: void DualColCPUsMeter_draw(Meter * this, int x, int y, int
   w) */

void DualColCPUsMeter_draw(Meter *this,int x,int y,int w)

{
  CPUMeterCommonDraw(this,x,y,w,2);
  return;
}


/* QuadColCPUsMeter_draw @ 0x1141c0 */

/* DWARF original prototype: void QuadColCPUsMeter_draw(Meter * this, int x, int y, int
   w) */

void QuadColCPUsMeter_draw(Meter *this,int x,int y,int w)

{
  CPUMeterCommonDraw(this,x,y,w,4);
  return;
}


/* OctoColCPUsMeter_draw @ 0x1141d0 */

/* DWARF original prototype: void OctoColCPUsMeter_draw(Meter * this, int x, int y, int
   w) */

void OctoColCPUsMeter_draw(Meter *this,int x,int y,int w)

{
  CPUMeterCommonDraw(this,x,y,w,8);
  return;
}


/* SingleColCPUsMeter_draw @ 0x1141e0 */

/* DWARF original prototype: void SingleColCPUsMeter_draw(Meter * this, int x, int y,
   int w) */

void SingleColCPUsMeter_draw(Meter *this,int x,int y,int w)

{
  char cVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  long in_R8;
  long in_R9;

  plVar3 = *(long **)((long)this->meterData + 8);
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  uVar2 = *(uint *)this->meterData;
  cVar1 = (char)*(uchar *)(this->super).klass[3].delete;
  if (cVar1 == 'L') {
    uVar4 = (ulong)(uVar2 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar2 >> 1);
    if (cVar1 != 'R') {
      uVar4 = (long)(int)uVar2;
    }
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar4) {
    plVar5 = plVar3;
    do {
      plVar6 = plVar5 + 1;
      (**(code **)(*plVar5 + 8))(*plVar5,(ulong)(uint)x,(ulong)(uint)y,(ulong)(uint)w,in_R8,in_R9);
      y = y + *(int *)(*plVar5 + 0x48);
      plVar5 = plVar6;
    } while (plVar6 != plVar3 + uVar4);
  }
  return;
}


/* CPUMeterCommonUpdateMode @ 0x114320 */

/* DWARF original prototype: void CPUMeterCommonUpdateMode(Meter * this, int mode, int ncol)
    */

void CPUMeterCommonUpdateMode(Meter *this,int mode,int ncol)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  undefined8 *puVar1;
  char cVar2;
  int wVar3;
  int wVar4;
  code *a5;
  Meter_Draw_3 p_Var5;
  int wVar6;
  ulong a3;
  undefined8 *extraout_RDX;
  undefined8 *a2;
  undefined8 *extraout_RDX_00;
  long lVar7;
  long in_R8;
  long *a0;
  undefined8 *puVar8;

                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: Meter * * meters@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int count@[???] */
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  (*(int (*))(__fp - 0x3c)) = *(int *)this->meterData;
  a2 = *(undefined8 **)((long)this->meterData + 8);
  this->mode = mode;
  cVar2 = (char)*(uchar *)(this->super).klass[3].delete;
  wVar3 = Meter_modes[mode]->h;
  if (cVar2 == 'L') {
    wVar6 = wVar3;
    (*(int (*))(__fp - 0x3c)) = (uint)((*(int (*))(__fp - 0x3c)) + 1) >> 1;
  }
  else {
    wVar6 = (uint)(*(int (*))(__fp - 0x3c)) >> 1;
    if (cVar2 == 'R') {
      (*(int (*))(__fp - 0x3c)) = wVar6;
    }
  }
  a3 = (ulong)(uint)wVar6;
                    /* Unresolved local var: int i@[???] */
  if (0 < (*(int (*))(__fp - 0x3c))) {
    puVar1 = a2 + (*(int (*))(__fp - 0x3c));
    puVar8 = a2;
    do {
      while( true ) {
        a0 = (long *)*puVar8;
        if (0 < mode) break;
        lVar7 = *a0;
        a3 = 1;
        if (mode != 0) {
          a3 = (ulong)(uint)mode;
        }
        wVar6 = (int)a3;
        if (*(int *)(lVar7 + 0x58) == 0) goto LAB_001143b9;
LAB_00114401:
                    /* Unresolved local var: MeterMode * mode@[???] */
        puVar8 = puVar8 + 1;
        free((void *)a0[8]);
        a0[8] = 0;
        a0[7] = 0;
        p_Var5 = Meter_modes[wVar6]->draw;
        wVar4 = Meter_modes[wVar6]->h;
        *(int *)(a0 + 4) = wVar6;
        a0[1] = (long)p_Var5;
        *(int *)(a0 + 9) = wVar4;
        a2 = extraout_RDX_00;
        if (puVar1 == puVar8) goto LAB_00114449;
      }
      while (mode == *(int *)(a0 + 4)) {
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
      *(int *)(a0 + 4) = wVar6;
    } while (puVar1 != puVar8);
  }
LAB_00114449:
  this->h = (((*(int (*))(__fp - 0x3c)) + -1 + ncol) / ncol) * wVar3;
  return;
}


/* SingleColCPUsMeter_updateMode @ 0x1144a0 */

/* DWARF original prototype: void SingleColCPUsMeter_updateMode(Meter * this, int mode) */

void SingleColCPUsMeter_updateMode(Meter *this,int mode)

{
  CPUMeterCommonUpdateMode(this,mode,1);
  return;
}


/* DualColCPUsMeter_updateMode @ 0x1144b0 */

/* DWARF original prototype: void DualColCPUsMeter_updateMode(Meter * this, int mode) */

void DualColCPUsMeter_updateMode(Meter *this,int mode)

{
  CPUMeterCommonUpdateMode(this,mode,2);
  return;
}


/* QuadColCPUsMeter_updateMode @ 0x1144c0 */

/* DWARF original prototype: void QuadColCPUsMeter_updateMode(Meter * this, int mode) */

void QuadColCPUsMeter_updateMode(Meter *this,int mode)

{
  CPUMeterCommonUpdateMode(this,mode,4);
  return;
}


/* OctoColCPUsMeter_updateMode @ 0x1144d0 */

/* DWARF original prototype: void OctoColCPUsMeter_updateMode(Meter * this, int mode) */

void OctoColCPUsMeter_updateMode(Meter *this,int mode)

{
  CPUMeterCommonUpdateMode(this,mode,8);
  return;
}


/* AllCPUsMeter_done @ 0x1144e0 */

/* DWARF original prototype: void AllCPUsMeter_done(Meter * this) */

void AllCPUsMeter_done(Meter *this)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  uint *__ptr;
  Meter_ *cast;
  ulong uVar4;
  undefined8 *__ptr_00;

                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
  __ptr = this->meterData;
  __ptr_00 = *(undefined8 **)(__ptr + 2);
  uVar3 = *__ptr;
  cVar2 = (char)*(uchar *)(this->super).klass[3].delete;
  if (cVar2 == 'L') {
    uVar4 = (ulong)(uVar3 + 1 >> 1);
  }
  else {
    uVar4 = (ulong)(uVar3 >> 1);
    if (cVar2 != 'R') {
      uVar4 = (long)(int)uVar3;
    }
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar4) {
    puVar1 = __ptr_00 + uVar4;
    do {
      cast = (Meter_ *)*__ptr_00;
      __ptr_00 = __ptr_00 + 1;
      Meter_delete(cast);
    } while (__ptr_00 != puVar1);
    __ptr_00 = *(undefined8 **)(__ptr + 2);
  }
  free(__ptr_00);
  free(__ptr);
  return;
}


/* CPUMeter_init @ 0x11c3e0 */

/* DWARF original prototype: void CPUMeter_init(Meter * this) */

void CPUMeter_init(Meter *this)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int iVar2;
  char *pcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (this->param == 0) {
                    /* Unresolved local var: uint cpu@[???]
                       Unresolved local var: Machine * host@[???] */
    pcVar3 = this->caption;
    if ((pcVar3 != (char *)0x0) && (iVar2 = strcmp(pcVar3,((char *)(long)&DAT_00147497 /* "Avg" */)), iVar2 == 0)) goto LAB_0011c469;
    free(pcVar3);
                    /* Unresolved local var: char * data@[???] */
    pcVar3 = strdup(((char *)(long)&DAT_00147497 /* "Avg" */));
  }
  else {
    if (this->host->activeCPUs < 2) goto LAB_0011c469;
    xSnprintf((*(char (*) [10])(__fp - 0x3a)),10,((char *)(long)&DAT_0014749b /* "%3u" */),this->param - (uint)(this->host->settings->countCPUsFromOne == false)
             );
    pcVar3 = this->caption;
    if ((pcVar3 != (char *)0x0) && (iVar2 = strcmp(pcVar3,(*(char (*) [10])(__fp - 0x3a))), iVar2 == 0)) goto LAB_0011c469;
    free(pcVar3);
                    /* Unresolved local var: char * data@[???] */
    pcVar3 = strdup((*(char (*) [10])(__fp - 0x3a)));
  }
  if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  this->caption = pcVar3;
LAB_0011c469:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* CPUMeter_getUiName @ 0x11c4d0 */

/* DWARF original prototype: void CPUMeter_getUiName(Meter * this, char * buffer, size_t length) */

void CPUMeter_getUiName(Meter *this,char *buffer,size_t length)

{
  Object_Compare va0;

  va0 = (this->super).klass[3].compare;
  if (this->param != 0) {
    xSnprintf(buffer,length,((char *)(long)&DAT_0014749f /* "%s %u" */),va0,this->param);
    return;
  }
  xSnprintf(buffer,length,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),va0);
  return;
}


/* CPUMeterCommonInit @ 0x11c8e0 */

/* DWARF original prototype: void CPUMeterCommonInit(Meter * this, int ncol) */

void CPUMeterCommonInit(Meter *this,int ncol)

{
  long *plVar1;
  byte bVar2;
  Meter_3 *a0;
  uint *puVar3;
  long *a3;
  MeterMode *pMVar4;
  ulong a2;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  uint uVar5;
  undefined4 in_register_00000034;
  ulong a1;
  long in_R8;
  long in_R9;
  uint uVar6;
  long *plVar7;

                    /* Unresolved local var: uint cpus@[???]
                       Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: Meter * * meters@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int h@[???] */
  a1 = CONCAT44(in_register_00000034,ncol);
  puVar3 = this->meterData;
  uVar6 = this->host->existingCPUs;
  if (puVar3 == (uint *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    puVar3 = malloc(0x10);
    if (puVar3 == (uint *)0x0) {
LAB_0011ca3b:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->meterData = puVar3;
                    /* Unresolved local var: void * data@[???] */
    a1 = 8;
    *puVar3 = uVar6;
    a3 = calloc((ulong)uVar6,8);
    if (a3 == (long *)0x0) goto LAB_0011ca3b;
    *(long **)(puVar3 + 2) = a3;
  }
  else {
    a3 = *(long **)(puVar3 + 2);
                    /* Unresolved local var: CPUMeterData * data@[???]
                       Unresolved local var: uint cpus@[???] */
    uVar6 = *puVar3;
  }
  bVar2 = (byte)*(uchar *)(this->super).klass[3].delete;
  a2 = (ulong)bVar2;
  if (bVar2 == 0x4c) {
    uVar6 = uVar6 + 1 >> 1;
  }
  else if (bVar2 == 0x52) {
    uVar5 = uVar6 + 1;
    uVar6 = uVar6 >> 1;
    uVar5 = uVar5 >> 1;
    goto LAB_0011c935;
  }
  uVar5 = 0;
LAB_0011c935:
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar6) {
    plVar1 = a3 + (int)uVar6;
    plVar7 = a3;
    do {
      uVar5 = uVar5 + 1;
      a0 = (Meter_3 *)*plVar7;
      if (a0 == (Meter_3 *)0x0) {
        a1 = (ulong)uVar5;
        a0 = Meter_new((Machine_2 *)this->host,uVar5,&CPUMeter_class);
        *plVar7 = (long)a0;
        a2 = extraout_RDX_00;
      }
      plVar7 = plVar7 + 1;
      (*(code *)((a0->super).klass[1].extends))((long)a0,a1,a2,(long)a3,in_R8,in_R9);
      a2 = extraout_RDX;
    } while (plVar7 != plVar1);
  }
  if (this->mode == 0) {
    this->mode = 1;
    pMVar4 = &BarMeterMode;
  }
  else {
    pMVar4 = Meter_modes[this->mode];
  }
  this->h = (((uVar6 - 1) + ncol) / ncol) * pMVar4->h;
  return;
}


/* SingleColCPUsMeter_init @ 0x11ca40 */

/* DWARF original prototype: void SingleColCPUsMeter_init(Meter * this) */

void SingleColCPUsMeter_init(Meter *this)

{
  CPUMeterCommonInit(this,1);
  return;
}


/* DualColCPUsMeter_init @ 0x11ca50 */

/* DWARF original prototype: void DualColCPUsMeter_init(Meter * this) */

void DualColCPUsMeter_init(Meter *this)

{
  CPUMeterCommonInit(this,2);
  return;
}


/* QuadColCPUsMeter_init @ 0x11ca60 */

/* DWARF original prototype: void QuadColCPUsMeter_init(Meter * this) */

void QuadColCPUsMeter_init(Meter *this)

{
  CPUMeterCommonInit(this,4);
  return;
}


/* OctoColCPUsMeter_init @ 0x11ca70 */

/* DWARF original prototype: void OctoColCPUsMeter_init(Meter * this) */

void OctoColCPUsMeter_init(Meter *this)

{
  CPUMeterCommonInit(this,8);
  return;
}


/* CPUMeter_updateValues @ 0x11e3d0 */

/* DWARF original prototype: void CPUMeter_updateValues(Meter * this) */

void CPUMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  undefined1 (*pauVar2) [16];
  Settings__2 *pSVar3;
  char *pcVar4;
  undefined *va3;
  undefined *va1;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar5;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pauVar2 = (undefined1 (*) [16])this->values;
  *(undefined16 *)(*pauVar2) = (undefined16)0x0;
  *(undefined16 *)(pauVar2[1]) = (undefined16)0x0;
  *(undefined16 *)(pauVar2[2]) = (undefined16)0x0;
  *(undefined16 *)(pauVar2[3]) = (undefined16)0x0;
  *(undefined16 *)(pauVar2[4]) = (undefined16)0x0;
  pSVar3 = this->host->settings;
  if (this->host->existingCPUs < this->param) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar4 = ((char *)(long)&s_absent_00147648 /* " absent" */);
LAB_0011e5be:
      xSnprintf(this->txtBuffer,0x100,pcVar4 + 1);
      return;
    }
    goto LAB_0011e6cb;
  }
  dVar5 = Platform_setCPUValues(this,this->param);
  if (dVar5 < 0.0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar4 = ((char *)(long)&s_offline_00147650 /* " offline" */);
      goto LAB_0011e5be;
    }
    goto LAB_0011e6cb;
  }
  (*(char (*) [8])(__fp - 0x70))[0] = '\0';
  (*(char (*) [8])(__fp - 0x70))[1] = '\0';
  (*(char (*) [8])(__fp - 0x70))[2] = '\0';
  (*(char (*) [8])(__fp - 0x70))[3] = '\0';
  (*(char (*) [8])(__fp - 0x70))[4] = '\0';
  (*(char (*) [8])(__fp - 0x70))[5] = '\0';
  (*(char (*) [8])(__fp - 0x70))[6] = '\0';
  (*(char (*) [8])(__fp - 0x70))[7] = '\0';
  (*(char (*) [16])(__fp - 0x58))[0] = '\0';
  (*(char (*) [16])(__fp - 0x58))[1] = '\0';
  (*(char (*) [16])(__fp - 0x58))[2] = '\0';
  (*(char (*) [16])(__fp - 0x58))[3] = '\0';
  (*(char (*) [16])(__fp - 0x58))[4] = '\0';
  (*(char (*) [16])(__fp - 0x58))[5] = '\0';
  (*(char (*) [16])(__fp - 0x58))[6] = '\0';
  (*(char (*) [16])(__fp - 0x58))[7] = '\0';
  (*(char (*) [16])(__fp - 0x58))[8] = '\0';
  (*(char (*) [16])(__fp - 0x58))[9] = '\0';
  (*(char (*) [16])(__fp - 0x58))[10] = '\0';
  (*(char (*) [16])(__fp - 0x58))[0xb] = '\0';
  (*(char (*) [16])(__fp - 0x58))[0xc] = '\0';
  (*(char (*) [16])(__fp - 0x58))[0xd] = '\0';
  (*(char (*) [16])(__fp - 0x58))[0xe] = '\0';
  (*(char (*) [16])(__fp - 0x58))[0xf] = '\0';
  (*(char (*) [16])(__fp - 0x68))[0] = '\0';
  (*(char (*) [16])(__fp - 0x68))[1] = '\0';
  (*(char (*) [16])(__fp - 0x68))[2] = '\0';
  (*(char (*) [16])(__fp - 0x68))[3] = '\0';
  (*(char (*) [16])(__fp - 0x68))[4] = '\0';
  (*(char (*) [16])(__fp - 0x68))[5] = '\0';
  (*(char (*) [16])(__fp - 0x68))[6] = '\0';
  (*(char (*) [16])(__fp - 0x68))[7] = '\0';
  (*(char (*) [16])(__fp - 0x68))[8] = '\0';
  (*(char (*) [16])(__fp - 0x68))[9] = '\0';
  (*(char (*) [16])(__fp - 0x68))[10] = '\0';
  (*(char (*) [16])(__fp - 0x68))[0xb] = '\0';
  (*(char (*) [16])(__fp - 0x68))[0xc] = '\0';
  (*(char (*) [16])(__fp - 0x68))[0xd] = '\0';
  (*(char (*) [16])(__fp - 0x68))[0xe] = '\0';
  (*(char (*) [16])(__fp - 0x68))[0xf] = '\0';
  if (pSVar3->showCPUUsage == false) {
    if (pSVar3->showCPUFrequency == false) goto LAB_0011e49e;
LAB_0011e469:
                    /* Unresolved local var: double cpuFrequency@[???] */
    if (0.0 <= this->values[8]) {
      xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&s__4uMHz_00147629 /* "%4uMHz" */),(int)(long)this->values[8]);
      goto LAB_0011e49e;
    }
    xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_001474de /* "N/A" */));
    if (pSVar3->showCPUTemperature != false) goto LAB_0011e4aa;
LAB_0011e508:
    if ((*(char (*) [16])(__fp - 0x58))[0] == '\0') goto LAB_0011e578;
LAB_0011e512:
    if ((*(char (*) [16])(__fp - 0x68))[0] == '\0') {
      va3 = &DAT_00149c0c;
      va1 = &DAT_001470dd;
      if ((*(char (*) [8])(__fp - 0x70))[0] == '\0') {
        va1 = &DAT_00149c0c;
      }
    }
    else {
      va3 = &DAT_001470dd;
      va1 = &DAT_00149c0c;
      if ((*(char (*) [8])(__fp - 0x70))[0] != '\0') {
        va1 = &DAT_001470dd;
      }
    }
  }
  else {
    xSnprintf((*(char (*) [8])(__fp - 0x70)),8,((char *)(long)(__sec_rodata + 0x6eb) /* "%.1f%%" */),dVar5);
    if (pSVar3->showCPUFrequency != false) goto LAB_0011e469;
LAB_0011e49e:
    if (pSVar3->showCPUTemperature == false) goto LAB_0011e508;
LAB_0011e4aa:
                    /* Unresolved local var: double cpuTemperature@[???] */
    dVar5 = this->values[9];
    if (NAN(dVar5)) {
      xSnprintf((*(char (*) [16])(__fp - 0x68)),0x10,((char *)(long)&DAT_001474de /* "N/A" */));
      goto LAB_0011e508;
    }
    if (pSVar3->degreeFahrenheit != false) {
      xSnprintf((*(char (*) [16])(__fp - 0x68)),0x10,((char *)(long)&s__3d_sF_00147630 /* "%3d%sF" */),(int)((dVar5 * 9.0) / 5.0 + 32.0),CRT_degreeSign)
      ;
      goto LAB_0011e508;
    }
    xSnprintf((*(char (*) [16])(__fp - 0x68)),0x10,((char *)(long)&s__d_sC_00147637 /* "%d%sC" */),(int)dVar5,CRT_degreeSign);
    if ((*(char (*) [16])(__fp - 0x58))[0] != '\0') goto LAB_0011e512;
LAB_0011e578:
    va3 = &DAT_00149c0c;
    va1 = va3;
    if ((*(char (*) [8])(__fp - 0x70))[0] != '\0') {
      va1 = &DAT_001470dd;
      if ((*(char (*) [16])(__fp - 0x68))[0] == '\0') {
        va1 = &DAT_00149c0c;
      }
    }
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&s__s_s_s_s_s_0014763d /* "%s%s%s%s%s" */),(*(char (*) [8])(__fp - 0x70)),va1,(*(char (*) [16])(__fp - 0x58)),va3,
            (*(char (*) [16])(__fp - 0x68)));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0011e6cb:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* CPUMeter_display @ 0x11e6d0 */

void CPUMeter_display(Meter_ *cast,RichString *out)

{
  undefined1 __frame[0x100148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x100108;
  long lVar1;
  wint_t __wc;
  int wVar2;
  long lVar3;
  int wVar4;
  int wVar5;
  int iVar6;
  double *pdVar7;
  ulong uVar8;
  char *fmt;
  cchar_t *pcVar9;
  undefined1 **ppuVar10;
  undefined1 **ppuVar11;
  undefined1 **ppuVar12;
  undefined1 *puVar13;
  long lVar14;
  long lVar15;
  long in_FS_OFFSET = (long)__fake_fs;
  double va0;

  ppuVar10 = &(*(undefined1 *(*))(__fp - 0xb8));
  ppuVar12 = &(*(undefined1 *(*))(__fp - 0xb8));
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  (*(Settings__2 *(*))(__fp - 0x90)) = cast->host->settings;
  if (cast->host->existingCPUs < cast->param) {
    RichString_appendAscii(out,CRT_colors[0xd],((char *)(long)&s_absent_00147648 /* " absent" */));
    ppuVar12 = &(*(undefined1 *(*))(__fp - 0xb8));
  }
  else if (cast->curItems == '\0') {
    RichString_appendAscii(out,CRT_colors[0xd],((char *)(long)&s_offline_00147650 /* " offline" */));
    ppuVar12 = &(*(undefined1 *(*))(__fp - 0xb8));
  }
  else {
    wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),cast->values[1]);
    (*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 0)) = wVar4;
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147583 /* ":" */));
    RichString_appendnAscii(out,CRT_colors[0x4c],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
    if ((*(Settings__2 *(*))(__fp - 0x90))->detailedCPUTime == false) {
      (*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 0)) = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),cast->values[2]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_0014767e /* "sys:" */));
      RichString_appendnAscii(out,CRT_colors[0x4d],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
      wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*cast->values);
      (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 4)),wVar4);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147683 /* "low:" */));
      RichString_appendnAscii(out,CRT_colors[0x4b],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
      if (0.0 <= cast->values[3]) {
        wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),cast->values[3]);
        RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147688 /* "vir:" */));
        RichString_appendnAscii(out,CRT_colors[0x52],(*(char (*) [50])(__fp - 0x78)),wVar4);
      }
    }
    else {
      (*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 0)) = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),cast->values[2]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147662 /* "sy:" */));
      RichString_appendnAscii(out,CRT_colors[0x4d],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
      (*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 0)) = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),*cast->values);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147666 /* "ni:" */));
      RichString_appendnAscii(out,CRT_colors[0x4b],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
      (*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 0)) = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),cast->values[3]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_0014766a /* "hi:" */));
      RichString_appendnAscii(out,CRT_colors[0x4f],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
      wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),cast->values[4]);
      (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 4)),wVar4);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_0014766e /* "si:" */));
      RichString_appendnAscii(out,CRT_colors[0x50],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
      pdVar7 = cast->values;
      if (0.0 <= pdVar7[5]) {
        wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),pdVar7[5]);
        (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 4)),wVar4);
        RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147672 /* "st:" */));
        RichString_appendnAscii(out,CRT_colors[0x51],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
        pdVar7 = cast->values;
      }
      if (0.0 <= pdVar7[6]) {
        wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),pdVar7[6]);
        (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 4)),wVar4);
        RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_00147676 /* "gu:" */));
        RichString_appendnAscii(out,CRT_colors[0x52],(*(char (*) [50])(__fp - 0x78)),(int)(*(undefined1 *(*))(__fp - 0x98)));
        pdVar7 = cast->values;
      }
      wVar4 = xSnprintf((*(char (*) [50])(__fp - 0x78)),0x32,((char *)(long)&s__5_1f___00147659 /* "%5.1f%% " */),pdVar7[7]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&DAT_0014767a /* "wa:" */));
      RichString_appendnAscii(out,CRT_colors[0x4e],(*(char (*) [50])(__fp - 0x78)),wVar4);
    }
    ppuVar11 = &(*(undefined1 *(*))(__fp - 0xb8));
    if ((*(Settings__2 *(*))(__fp - 0x90))->showCPUFrequency != false) {
                    /* Unresolved local var: double cpuFrequency@[???] */
      if (0.0 <= cast->values[8]) {
        wVar4 = xSnprintf((*(char (*) [10])(__fp - 0x82)),10,((char *)(long)&s__4uMHz_0014768d /* "%4uMHz " */),(int)(long)cast->values[8]);
      }
      else {
        wVar4 = xSnprintf((*(char (*) [10])(__fp - 0x82)),10,((char *)(long)&s_N_A_00147695 /* "N/A     " */));
      }
      (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 4)),wVar4);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_freq__0014769e /* "freq: " */));
                    /* Unresolved local var: int[88534] data@[???]
                       Unresolved local var: int newLen@[???] */
      wVar4 = out->chlen;
      (*(undefined1 *(*))(__fp - 0xb8)) = (undefined1 *)&(*(undefined1 *(*))(__fp - 0xb8));
      iVar6 = (int)(*(undefined1 *(*))(__fp - 0x98)) + 1;
      (*(undefined1 *(*))(__fp - 0xa8)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0xa8)) + 4)),CRT_colors[0xf]);
      uVar8 = (long)iVar6 * 4 + 0xf;
      ppuVar11 = &(*(undefined1 *(*))(__fp - 0xb8));
      while (ppuVar10 != (undefined1 **)((long)&(*(undefined1 *(*))(__fp - 0xb8)) - (uVar8 & 0xfffffffffffff000))) {
        ppuVar12 = (undefined1 **)((long)ppuVar11 + -0x1000);
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
        ppuVar10 = (undefined1 **)((long)ppuVar11 + -0x1000);
        ppuVar11 = (undefined1 **)((long)ppuVar11 + -0x1000);
      }
      uVar8 = (ulong)((uint)uVar8 & 0xff0);
      lVar14 = -uVar8;
      if (uVar8 != 0) {
        *(undefined8 *)((long)ppuVar12 + -8) = *(undefined8 *)((long)ppuVar12 + -8);
      }
      uVar8 = (ulong)(int)(*(undefined1 *(*))(__fp - 0x98));
      (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)((long)ppuVar12 + lVar14);
      uVar8 = __mbstowcs_chk((int *)((long)ppuVar12 + lVar14),(*(char (*) [10])(__fp - 0x82)),uVar8,
                             (long)iVar6 & 0x3fffffffffffffff);
      ppuVar11 = (undefined1 **)(*(undefined1 *(*))(__fp - 0xb8));
      if (0 < (int)uVar8) {
        wVar5 = (int)uVar8 + wVar4;
        lVar15 = (long)wVar4;
        (*(undefined1 *(*))(__fp - 0xa0)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0xa0)) + 4)),wVar5);
        RichString_setLen(out,wVar5);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
        (*(uint (*))(__fp - 0xac)) = (uint)(*(undefined1 *(*))(__fp - 0xa8)) & 0xffffff;
        (*(undefined1 *(*))(__fp - 0xa8)) = (*(undefined1 *(*))(__fp - 0x98)) + lVar15 * -4;
        pcVar9 = out->chptr + lVar15;
        do {
          __wc = *(wint_t *)((*(undefined1 *(*))(__fp - 0xa8)) + lVar15 * 4);
          (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x98)) + 4)),__wc);
          iVar6 = iswprint(__wc);
          pcVar9->attr = 0;
          pcVar9->chars[0] = 0;
          pcVar9->chars[1] = 0;
          pcVar9->chars[2] = 0;
          wVar4 = (int)(*(undefined1 *(*))(__fp - 0x98));
          if (iVar6 == 0) {
            wVar4 = 65533;
          }
          *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
          lVar15 = lVar15 + 1;
          pcVar9->chars[0] = wVar4;
          pcVar9->attr = (*(uint (*))(__fp - 0xac));
          ppuVar11 = (undefined1 **)(*(undefined1 *(*))(__fp - 0xb8));
          pcVar9 = pcVar9 + 1;
        } while ((int)lVar15 < (int)(*(undefined1 *(*))(__fp - 0xa0)));
      }
    }
    ppuVar12 = ppuVar11;
    if ((*(Settings__2 *(*))(__fp - 0x90))->showCPUTemperature != false) {
                    /* Unresolved local var: double cpuTemperature@[???] */
      va0 = cast->values[9];
      if (NAN(va0)) {
        wVar4 = xSnprintf((*(char (*) [10])(__fp - 0x82)),10,((char *)(long)&DAT_001474de /* "N/A" */));
      }
      else {
        fmt = ((char *)(long)&s__5_1f_sC_001476ae /* "%5.1f%sC" */);
        if ((*(Settings__2 *(*))(__fp - 0x90))->degreeFahrenheit != false) {
          fmt = ((char *)(long)&s__5_1f_sF_001476a5 /* "%5.1f%sF" */);
          va0 = (va0 * 9.0) / 5.0 + 32.0;
        }
        wVar4 = xSnprintf((*(char (*) [10])(__fp - 0x82)),10,fmt,va0,CRT_degreeSign);
      }
      wVar5 = CRT_colors[0xe];
      RichString_appendAscii(out,wVar5,((char *)(long)&s_temp__001476b7 /* "temp:" */));
                    /* Unresolved local var: int[89094] data@[???]
                       Unresolved local var: int newLen@[???] */
      (*(undefined1 *(*))(__fp - 0x98)) = (undefined1 *)ppuVar11;
      wVar5 = out->chlen;
      lVar14 = (long)wVar5;
      wVar2 = CRT_colors[0xf];
      uVar8 = (long)(wVar4 + 1) * 4 + 0xf;
      puVar13 = (undefined1 *)((long)ppuVar11 + -(uVar8 & 0xfffffffffffff000));
      for (; ppuVar11 != (undefined1 **)puVar13;
          ppuVar11 = (undefined1 **)((long)ppuVar11 + -0x1000)) {
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
      }
      uVar8 = (ulong)((uint)uVar8 & 0xff0);
      lVar15 = -uVar8;
      if (uVar8 != 0) {
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
      }
      (*(undefined1 *(*))(__fp - 0xa0)) = (undefined1 *)((long)ppuVar11 + lVar15);
      uVar8 = __mbstowcs_chk((int *)((long)ppuVar11 + lVar15),(*(char (*) [10])(__fp - 0x82)),(long)wVar4,
                             (long)(wVar4 + 1) & 0x3fffffffffffffff);
      ppuVar12 = (undefined1 **)(*(undefined1 *(*))(__fp - 0x98));
      if (0 < (int)uVar8) {
        wVar5 = wVar5 + (int)uVar8;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
        (*(Settings__2 *(*))(__fp - 0x90)) = (Settings__2 *)CONCAT44((*(uint *)((char *)&(*(Settings__2 *(*))(__fp - 0x90)) + 4)),wVar5);
        RichString_setLen(out,wVar5);
        puVar13 = (*(undefined1 *(*))(__fp - 0xa0));
        lVar1 = lVar14 * -4;
        pcVar9 = out->chptr + lVar14;
        do {
          wVar4 = *(int *)(puVar13 + lVar14 * 4 + lVar1);
          iVar6 = iswprint(wVar4);
          pcVar9->attr = 0;
          pcVar9->chars[0] = 0;
          pcVar9->chars[1] = 0;
          pcVar9->chars[2] = 0;
          if (iVar6 == 0) {
            wVar4 = 65533;
          }
          pcVar9->attr = wVar2 & 0xffffff;
          lVar14 = lVar14 + 1;
          *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
          pcVar9->chars[0] = wVar4;
          pcVar9 = pcVar9 + 1;
          ppuVar12 = (undefined1 **)(*(undefined1 *(*))(__fp - 0x98));
        } while ((int)lVar14 < (int)(*(Settings__2 *(*))(__fp - 0x90)));
      }
    }
  }
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

