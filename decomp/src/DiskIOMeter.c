#include "htop.h"

/* DiskIOMeter_updateValues @ 0x11f0f0 */

/* DWARF original prototype: void DiskIOMeter_updateValues(Meter * this) */

void DiskIOMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char *buf;
  Machine *pMVar1;
  long lVar2;
  MeterRateStatus MVar3;
  _Bool _Var4;
  ulong uVar5;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar6;
  double dVar7;

  pMVar1 = this->host;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = pMVar1->realtimeMs - cached_last_update;
  if (uVar5 < 0x1f5) {
LAB_0011f139:
    dVar7 = cached_utilisation_diff;
    MVar3 = status;
    *this->values = cached_utilisation_diff;
    if (MVar3 != RATESTATUS_NODATA) {
      buf = this->txtBuffer;
      if (MVar3 == RATESTATUS_INIT) {
        xSnprintf(buf,0x100,((char *)(long)(__sec_rodata + 0x29bf) /* "init" */));
      }
      else if (MVar3 == RATESTATUS_STALE) {
        xSnprintf(buf,0x100,((char *)(long)&s_stale_001476d3 /* "stale" */));
      }
      else {
        xSnprintf(buf,0x100,((char *)(long)&s_r__siB_s_w__siB_s___1f___001476d9 /* "r:%siB/s w:%siB/s %.1f%%" */),cached_read_diff_str,cached_write_diff_str,
                  dVar7);
      }
      goto LAB_0011f187;
    }
  }
  else {
    _Var4 = Platform_getDiskIO(&(*(DiskIOData (*))(__fp - 0x48)));
    if (_Var4) {
      bVar6 = cached_last_update == 0;
      cached_last_update = pMVar1->realtimeMs;
      if (bVar6) {
        status = RATESTATUS_INIT;
      }
      else {
                    /* Unresolved local var: uint64_t diff@[???] */
        dVar7 = 0.0;
        status = ~-(uint)(uVar5 < 0x7531) & RATESTATUS_STALE;
        if (cached_read_total < (*(DiskIOData (*))(__fp - 0x48)).totalBytesRead) {
          dVar7 = (double)((((*(DiskIOData (*))(__fp - 0x48)).totalBytesRead - cached_read_total) * 1000) / uVar5 >> 10);
        }
        Meter_humanUnit(cached_read_diff_str,dVar7,6);
        dVar7 = 0.0;
        if (cached_write_total < (*(DiskIOData (*))(__fp - 0x48)).totalBytesWritten) {
          dVar7 = (double)((((*(DiskIOData (*))(__fp - 0x48)).totalBytesWritten - cached_write_total) * 1000) / uVar5 >> 10);
        }
        Meter_humanUnit(cached_write_diff_str,dVar7,6);
        if (cached_msTimeSpend_total < (*(DiskIOData (*))(__fp - 0x48)).totalMsTimeSpend) {
          cached_utilisation_diff =
               ((double)((*(DiskIOData (*))(__fp - 0x48)).totalMsTimeSpend - cached_msTimeSpend_total) * 100.0) / (double)uVar5;
          if (100.0 <= cached_utilisation_diff) {
            cached_utilisation_diff = 100.0;
          }
        }
        else {
          cached_utilisation_diff = 0.0;
        }
      }
      cached_read_total = (*(DiskIOData (*))(__fp - 0x48)).totalBytesRead;
      cached_write_total = (*(DiskIOData (*))(__fp - 0x48)).totalBytesWritten;
      cached_msTimeSpend_total = (*(DiskIOData (*))(__fp - 0x48)).totalMsTimeSpend;
      goto LAB_0011f139;
    }
    cached_last_update = pMVar1->realtimeMs;
    status = RATESTATUS_NODATA;
    *this->values = cached_utilisation_diff;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&s_no_data_001476cb /* "no (*(DiskIOData (*))(__fp - 0x48))" */));
LAB_0011f187:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* DiskIOMeter_display @ 0x11f410 */

void DiskIOMeter_display(Object *cast,RichString *out)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long lVar1;
  int wVar2;
  char *data;
  long lVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (status == RATESTATUS_NODATA) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      data = ((char *)(long)&s_no_data_001476cb /* "no data" */);
      wVar2 = CRT_colors[0x10];
LAB_0011f573:
      RichString_writeAscii(out,wVar2,data);
      return;
    }
  }
  else if (status == RATESTATUS_STALE) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      data = ((char *)(long)&s_stale_data_00147702 /* "stale data" */);
      wVar2 = CRT_colors[0x15];
      goto LAB_0011f573;
    }
  }
  else if (status == RATESTATUS_INIT) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      data = ((char *)(long)&s_initializing____001476f2 /* "initializing..." */);
      wVar2 = CRT_colors[0xf];
      goto LAB_0011f573;
    }
  }
  else {
    lVar3 = 0x4c;
    if (cached_utilisation_diff <= 40.0) {
      lVar3 = 0x3c;
    }
    wVar2 = xSnprintf((*(char (*) [16])(__fp - 0x48)),0x10,((char *)(long)(__sec_rodata + 0x6eb) /* "%.1f%%" */),cached_utilisation_diff);
    RichString_appendnAscii(out,*(int *)((long)CRT_colors + lVar3),(*(char (*) [16])(__fp - 0x48)),wVar2);
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_read__0014770d /* " read: " */));
    RichString_appendAscii(out,CRT_colors[0x11],cached_read_diff_str);
    RichString_appendAscii(out,CRT_colors[0x11],((char *)(long)&DAT_00147715 /* "iB/s" */));
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_write__0014771a /* " write: " */));
    RichString_appendAscii(out,CRT_colors[0x12],cached_write_diff_str);
    RichString_appendAscii(out,CRT_colors[0x12],((char *)(long)&DAT_00147715 /* "iB/s" */));
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

